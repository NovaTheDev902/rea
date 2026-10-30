"""Device fingerprinting engine."""

import argparse
import json
import sys

from native_wrapper import fingerprint


def _platform_hint(value):
    if isinstance(value, int):
        return value
    if isinstance(value, str):
        v = value.lower()
        if v == "ios":
            return 2
        if v == "android":
            return 1
    return 0


def analyze_bundle(bundle):
    signed_pk_id = bundle.get("signed_pk_id", 0)
    otpk_ids = bundle.get("otpk_ids", [])
    platform_hint = _platform_hint(bundle.get("platform_hint", 0))
    ios_version = bundle.get("ios_version")
    if ios_version is None:
        ios_version = 0
    return fingerprint(signed_pk_id, otpk_ids, platform_hint=platform_hint, ios_version=ios_version)


def main():
    parser = argparse.ArgumentParser(description="Device fingerprinting PoC")
    parser.add_argument("input", help="JSON file with prekey bundles")
    args = parser.parse_args()

    with open(args.input) as f:
        data = json.load(f)

    bundles = data.get("bundles", [data] if isinstance(data, dict) and "signed_pk_id" in data else [])
    if not bundles:
        print("No bundles found in input")
        sys.exit(1)

    correct = 0
    total = len(bundles)
    for i, bundle in enumerate(bundles, 1):
        result = analyze_bundle(bundle)
        hint = bundle.get("platform_hint")
        status = "OK" if (hint is None or str(hint).lower() == result["platform_name"].lower()) else "MISMATCH"
        if status == "OK":
            correct += 1
        print(
            f"Sample {i}: {result['platform_name']} "
            f"(signed_pk_id={bundle.get('signed_pk_id')}) -> "
            f"{result['platform_name']} ({result['confidence']}%) {status} | "
            f"Recommended: {result['exploit_cve']}"
        )

    print(f"Overall: {correct}/{total} correct ({int(100*correct/total)}%)")


if __name__ == "__main__":
    main()
