# Infection Vectors — How Targets Are Reached

## Overview
Graphite operators reach targets through two legitimate communication platforms: **WhatsApp** (Android) and **iMessage** (iOS). Both are high-trust, always-running apps that auto-process incoming content — the exact surface area the exploits target.

## Vector 1: iMessage (iOS)

| Property | Details |
|----------|---------|
| **Operator needs** | Target's iMessage address (Apple ID email or phone number) |
| **Action** | Send a crafted iCloud Link to the target's iMessage |
| **Device behavior** | iOS automatically fetches and processes the linked media |
| **User notification** | None |
| **Forensic artifact** | ATTACKER1 sender ID in iOS diagnostic logs |
| **Exploit used** | CVE-2025-43200 (iCloud Link media processing flaw) |
| **Confirmed victims** | 2+ European journalists |

**Attack flow:**
```
Operator → iMessage (ATTACKER1 account) → iCloud Link
→ iOS auto-fetches media → CVE-2025-43200 triggers
→ Code execution → Graphite implant installed
```

## Vector 2: WhatsApp (Android)

| Property | Details |
|----------|---------|
| **Operator needs** | Target's WhatsApp phone number |
| **Action** | Add target to a WhatsApp group, send malicious PDF |
| **Device behavior** | WhatsApp automatically processes the PDF |
| **User notification** | None |
| **Forensic artifact** | BIGPRETZEL marker in system/app logs |
| **Exploit used** | WhatsApp PDF zero-day (unpatched as of research cutoff) |
| **Confirmed victims** | ~90 individuals notified by WhatsApp (Jan 31, 2025) |

**Attack flow:**
```
Operator → WhatsApp group → Malicious PDF sent
→ WhatsApp auto-processes → Zero-day triggers
→ Code execution → Sandbox escape
→ Graphite loads across apps (WhatsApp, Signal, iMessage, etc.)
```

## Why These Platforms?
Both iMessage and WhatsApp are:
1. **Always running** in background — they process content without user opening the app
2. **Trusted** — users don't treat iMessage/WhatsApp notifications as suspicious
3. **Auto-processing** — both apps preview/process rich media and documents automatically, creating the attack surface
4. **Ubiquitous** — covers the two largest smartphone platforms (iOS 18%+ market share, Android 70%+ global)
5. **Accessible** — operator needs only public contact info (phone/email), no social engineering required

## Prerequisites for Operator
To use either vector, the Paragon operator needs:
- The target's phone number (WhatsApp) or Apple ID/phone number (iMessage)
- No physical access to the device
- No prior relationship or interaction with the target
- Valid deployment infrastructure (C2 servers, implant hosting)

This makes Graphite a **fully remote, no-prior-contact, hands-off** surveillance tool — perfect for targeted campaigns against journalists, activists, and political figures.

## Attack Scope
- **WhatsApp vector**: ~90 individuals notified by WhatsApp (January 2025)
- **iMessage vector**: Scope beyond 2 confirmed journalist victims is publicly unknown; forensic evidence suggests broader use

## Operator Infrastructure
No public disclosure of Paragon's C2 infrastructure or deployment servers. Infrastructure fingerprint P1 (TLS certificate) used for detection post-compromise but C2 origin/hosting not attributed.

## Defensive Measures
1. **iOS:** Enable Lockdown Mode → hardens iMessage processing
2. **Android:** Update WhatsApp immediately to patched version
3. **Both:** Enable automatic security updates
4. **Both:** Periodic device reboots (unknown if Graphite persists across reboot)

## Related Resources
- **WhatsApp Security Updates:** https://www.whatsapp.com/security/
- **Apple Lockdown Mode:** https://support.apple.com/en-us/HT212650
- **CISA Mobile Security:** https://www.cisa.gov/mobile-device-security

## Sources
- [Citizen Lab, March 2025](https://citizenlab.ca/2025/03/a-first-look-at-paragons-proliferating-spyware-operations/)
- [Citizen Lab Forensic Report, June 2025](https://citizenlab.ca/research/first-forensic-confirmation-of-paragons-ios-mercenary-spyware-finds-journalists-targeted/)
- [BleepingComputer, Jan 2025](https://www.bleepingcomputer.com/news/security/whatsapp-patched-zero-day-flaw-used-in-paragon-spyware-attacks/)
- [The Hacker News, Feb 2025](https://thehackernews.com/2025/02/meta-confirms-zero-click-whatsapp.html)
- [SecurityWeek, June 2025](https://www.securityweek.com/paragon-graphite-spyware-linked-to-zero-click-hacks-on-newest-iphones/)
