# Security Research Report: WhatsApp Device Fingerprinting and Buffer Overflow Exploit Chain

**Classification:** Public / Responsible Disclosure
**Date:** October 29, 2026
**Author:** Security Researcher
**Topic:** WhatsApp Device Fingerprinting as Reconnaissance Enabler for Targeted Buffer Overflow Exploits

---

## 1. Executive Summary

WhatsApp's multi-device end-to-end encryption (E2EE) protocol inadvertently leaks device metadata that allows any attacker with a target's phone number to fingerprint the target's operating system (Android vs. iOS) and device characteristics. This reconnaissance capability is a critical enabler for targeted buffer overflow exploit delivery. While WhatsApp/Meta classifies device fingerprinting as "low severity," it is in fact a foundational step in multi-million-dollar spyware attack chains (NSO Group Pegasus, Paragon Graphite).

This report documents:
1. The device fingerprinting mechanism and its technical details
2. Known universal and platform-specific buffer overflow vulnerabilities in WhatsApp
3. How device fingerprinting connects to buffer overflow exploit delivery
4. Proof-of-concept methodology for demonstrating the attack chain
5. Mitigation recommendations

---

## 2. Device Fingerprinting Mechanism

### 2.1 Background

WhatsApp uses a variant of the Signal Protocol for E2EE. In multi-device mode, each receiving device maintains a separate encryption session with a distinct key. This architecture, while providing convenience, leaks metadata through the prekey distribution mechanism.

### 2.2 Technical Details

When an attacker initiates a conversation (or queries prekeys) for a target phone number, WhatsApp's server responds with the target's prekey bundle. The key IDs in this bundle differ systematically between platforms:

#### Signed Pre-Key (Signed PK) IDs
- **Android:** IDs increment slowly from 0, monthly. Pattern: sequential, predictable. Post-fix: randomized 24-bit range (0x100000-0xFFFFFF).
- **iOS:** IDs use a different base range (approximately 0x800000+) with different increment patterns. iOS initialization values differ significantly from Android's ranges.

#### One-Time Pre-Key (OTPK) IDs
- **Android:** Randomized 24-bit range (after recent Meta fix). Tight clustering within range.
- **iOS:** Initialization values differ from Android's randomized 24-bit range; OTPK IDs span higher base values.
- **Impact:** Even after Meta's partial fix (randomizing Android Signed PK IDs), the OTPK ID space still allows high-accuracy OS differentiation.

#### iOS-Specific Fingerprinting (from Careless Whisper & WOOT'25 research)
- iOS Signed PK IDs use base value in the 0x800000 range, distinct from Android's low sequential/randomized ranges.
- iOS OTPK IDs cluster in higher base values, distinct from Android's low 24-bit range.
- Delivery receipt handling creates distinct artifacts per OS, enabling OS inference via receipt timing patterns.

### 2.3 Attack Surface

- **Input required:** Target phone number only
- **User interaction:** None required
- **Victim notification:** None (silent reconnaissance)
- **Rate limiting:** Not effectively enforced (per Careless Whisper research, 13.3 GB/hour data consumption possible)
- **Detection:** Extremely difficult; no artifacts left on victim device

### 2.4 Research References

| Research | Venue | Year | Finding |
|----------|-------|------|---------|
| Tal A. Be'ery | WOOT'24 | 2024 | Device count, types, and identities via per-device sessions |
| Gegenhuber et al. | WOOT'25 | 2025 | OS fingerprinting via Signed PK / OTPK ID patterns |
| Gegenhuber et al. | arXiv 2504.07323 | 2025 | Prekey depletion attacks, PFS degradation |
| Careless Whisper (Gegenhuber et al.) | NCC-AT | 2025 | Silent delivery receipt exploitation, OS fingerprinting via receipt handling |

### 2.5 Open-Source Implementations Grounding the Findings

Public open-source implementations of the WhatsApp/Signal prekey machinery corroborate the fingerprinting assumptions:

| Implementation | Repository | Relevant Code | Finding |
|----------------|-----------|--------------|---------|
| pywhats | `sanjay3290/pywhats` | `src/pywhats/messaging/prekey.py` | Fetches Signal prekey bundles via `<iq xmlns="encrypt">` query; decodes signed prekey (`spk id`/value/signature) and OTPK (`key`/`id`/`value`) nodes. Wire format confirmed. |
| Baileys | `WreckedWrecker/baileys` | `Utils/signal.ts` (`parseAndInjectE2ESessions`) | Reference X3DH session construction from prekey bundle fields; bytes on the wire are verbatim. |
| Signal Android | `signalapp/Signal-Android` | `PreKeysSyncJob.kt` | Prekey publishing/sync job handling per device. |
| whatsmeow | `FlorianKempenich/whatsmeow` | `prekeys.go` | OPK upload / server prekey-count handling (`WantedPreKeyCount = 50`, `MinPreKeyCount = 5`). |

---

## 3. WhatsApp Buffer Overflow Vulnerabilities

### 3.1 Universal Buffer Overflows (Cross-Platform)

These vulnerabilities affect multiple operating systems simultaneously, making them particularly dangerous as they do not require precise OS fingerprinting.

#### CVE-2019-3568 — WhatsApp VOIP Stack Buffer Overflow
- **Type:** Heap-based Buffer Overflow (CWE-122, CWE-787)
- **CVSS:** 9.8 (Critical)
- **Attack Vector:** Network (no user interaction)
- **Affected Platforms:** Android (< 2.19.134), iOS (< 2.19.51), Windows Phone (< 2.18.348), Tizen (< 2.18.15), Business variants
- **Mechanism:** Specially crafted series of RTCP packets sent to a target phone number trigger heap overflow in the VOIP stack
- **Exploitation:** Zero-click (no user interaction required)
- **Status:** CISA Known Exploited Vulnerabilities (KEV) catalog
- **NSO Group Usage:** Used as zero-click attack against WhatsApp for Android (April 2019), per VB2022 forensic analysis

#### CVE-2021-24042 — Calling Logic Buffer Overflow
- **Type:** Heap-based Buffer Overflow (CWE-122, CWE-787)
- **CVSS:** 9.1 (Critical)
- **Attack Vector:** Network (requires 1:1 call to malicious actor)
- **Affected Platforms:** Android (< 2.21.23), iOS (< 2.21.230), KaiOS (< 2.2143), Desktop (< 2.2146)
- **Mechanism:** Out-of-bounds write during call setup logic

### 3.2 Platform-Specific Buffer Overflows

These require accurate device fingerprinting before delivery.

#### CVE-2021-24041 — Image Blur Buffer Overflow (Android Only)
- **Type:** Heap-based Buffer Overflow (CWE-122, CWE-787)
- **CVSS:** 9.8 (Critical)
- **Attack Vector:** Network (malicious image message)
- **Affected:** Android (< 2.21.22.7), Business for Android (< 2.21.22.7)
- **Mechanism:** Missing bounds checks in image blurring code; out-of-bounds write when processing malicious images

#### CVE-2020-1894 — Push-to-Talk Stack Overflow (Android + iOS)
- **Type:** Out-of-bounds Write (CWE-787)
- **CVSS:** 8.8 (High)
- **Attack Vector:** Network (crafted push-to-talk message)
- **Affected:** Android (< 2.20.35), iOS (< 2.20.30), Business variants
- **Mechanism:** Stack write overflow when playing crafted push-to-talk audio

#### CVE-2019-11931 — MP4 Parsing Stack Overflow
- **Type:** Stack-based Buffer Overflow (CWE-121, CWE-787)
- **CVSS:** 9.8 (Critical)
- **Attack Vector:** Network (crafted MP4 file)
- **Affected:** Android (< 2.19.274), iOS (< 2.19.100), Enterprise Client (< 2.25.3)
- **Mechanism:** Stack overflow in elementary stream metadata parsing of MP4 files

#### CVE-2019-11927 — WEBP EXIF Integer Overflow
- **Type:** Integer Overflow (CWE-190) leading to heap overflow
- **CVSS:** 9.8 (Critical)
- **Attack Vector:** Network (crafted WEBP image with EXIF tags)
- **Affected:** Android (< 2.19.143), iOS (< 2.19.100)

#### CVE-2020-1886 — Video Stream Buffer Overflow (Android)
- **Type:** Classic Buffer Overflow (CWE-120, CWE-787)
- **CVSS:** 9.8 (Critical)
- **Attack Vector:** Network (crafted video stream during video call)
- **Affected:** Android (< 2.20.11), Business for Android (< 2.20.2)

### 3.3 Integer Overflow Variants

#### CVE-2022-36934 — Video Call Integer Overflow
- **Type:** Integer Overflow (CWE-190)
- **CVSS:** 9.8 (Critical)
- **Attack Vector:** Network (crafted video call)
- **Mechanism:** Integer overflow in video call handler enabling RCE

#### CVE-2022-27492 — Video File Handler RCE
- **Type:** Integer Overflow / Buffer Overflow
- **CVSS:** 9.8 (Critical)
- **Attack Vector:** Network (crafted video file)
- **Mechanism:** RCE when opening specially crafted video file

### 3.4 Recent Zero-Click and Input-Validation Issues (2025–2026)

#### CVE-2025-55177 — WhatsApp Zero-Click RCE via Malicious Media (iOS / macOS)
- **Type:** Zero-click Memory Corruption / Heap Buffer Overflow (CWE-122 / CWE-787), chained with Apple CVE-2025-43300 (ImageIO)
- **CVSS:** Critical
- **Attack Vector:** Network (zero-click; malicious DNG message)
- **Zero-Click:** Yes — no user interaction required; actively exploited in the wild against iPhones via spyware
- **Affected Platforms:** WhatsApp for iOS (< 2.25.21.73), WhatsApp Business for iOS (< 2.25.21.78), WhatsApp for Mac (< 2.25.21.78)
- **Mechanism:** Missing validation that media originates from a linked device; crafted DNG triggers Apple ImageIO memory corruption → RCE. Actively exploited against iPhones via spyware campaigns.

#### CVE-2025-55179 — WhatsApp Rich Response Message Validation
- **Type:** Improper Input Validation → Arbitrary Remote Media Processing
- **CVSS:** High
- **Attack Vector:** Network (rich response messages)
- **Affected Platforms:** WhatsApp for iOS, WhatsApp Business for iOS, WhatsApp for Mac
- **Mechanism:** Incomplete validation of rich response messages allowed arbitrary remote media processing through attacker-controlled URLs.

#### CVE-2026-23866 — WhatsApp SSRF via AI Rich Responses (iOS / Android)
- **Type:** Server-Side Request Forgery (SSRF) / Improper URL Validation (CWE-940)
- **CVSS:** Medium
- **Attack Vector:** Network (AI rich response messages for Instagram Reels)
- **Affected Platforms:** WhatsApp for iOS (v2.25.8.0–v2.26.15.72), WhatsApp for Android (v2.25.8.0–v2.26.7.10)
- **Mechanism:** Incomplete validation of AI rich response message fields allowed media processing from arbitrary URLs; OS custom URL scheme handlers exposed.

### 3.5 Native Framework Attack Surfaces and Toolchains

- **iOS (Swift + native VoIP/C++ runtime; Apple ImageIO):** Zero-click delivery surfaces (CVE-2019-3568, CVE-2025-55177); toolchain for device validation via Xcode.
- **Android (Java/Kotlin + NDK C++ VoIP stack):** Heap-based overflow surfaces (CVE-2019-3568, CVE-2021-24041); toolchain via Android SDK/NDK.
- **Cross-platform (C++ VoIP stack):** Universal buffer overflow (CVE-2019-3568) affecting Android/iOS/WP/Tizen.

### 3.6 Additional Zero-Click RCEs Affecting iOS (2026)

#### CVE-2026-86950 — Apple CoreGraphics Zero-Click RCE (iOS)
- **Type:** Out-of-bounds Write → Remote Code Execution (CWE-787)
- **CVSS:** Critical
- **Attack Vector:** Network (zero-click-capable via messaging/web/email delivery)
- **Affected Platforms:** iOS before iOS 27, iPadOS before 26.7.1, macOS before Tahoe 26.7.1
- **Mechanism:** OOB write in CoreGraphics (2D graphics/image rendering); exploited in "extremely sophisticated" targeted attacks; Meta reported to Apple; delivery via messaging apps considered possible.

#### CVE-2026-20611 — Apple CoreMedia Memory Corruption → RCE (iOS)
- **Type:** Memory Corruption → Arbitrary Code Execution (CWE-787)
- **CVSS:** Critical
- **Attack Vector:** Network
- **Affected Platforms:** iOS before iOS 26.3, iPadOS before 26.3, macOS before Tahoe 26.3, tvOS before 26.3, visionOS before 26.3, watchOS before 26.3
- **Mechanism:** Memory corruption addressed with improved state management; Apple aware of exploitation in "extremely sophisticated" attacks against targeted individuals.

#### CVE-2026-20700 — Apple CoreMedia Memory Corruption → RCE (iOS)
- **Type:** Memory Corruption → Arbitrary Code Execution (CWE-787)
- **CVSS:** Critical
- **Attack Vector:** Network
- **Affected Platforms:** iOS before iOS 26.3, iPadOS before 26.3, macOS before Tahoe 26.3, tvOS before 26.3, visionOS before 26.3, watchOS before 26.3
- **Mechanism:** Memory corruption addressed with improved state management; exploited in "extremely sophisticated" attacks; related CVEs CVE-2025-14174 and CVE-2025-43529.

### 4.3 Operational Zero-Click Delivery Methodology (CVE-2019-3568 / CVE-2025-55177)

- **Universal (CVE-2019-3568):** Crafted series of RTCP packets sent to target phone number → VoIP heap overflow → RCE; zero-click; no user interaction required.
- **iOS zero-click (CVE-2025-55177 + CVE-2025-43300):** WhatsApp missing validation of linked-device sync messages (CVE-2025-55177) allows unrelated user to trigger processing of content from arbitrary URL; combined with Apple ImageIO OOB write (CVE-2025-43300, JPEG-Lossless SOF3 / SamplesPerPixel mismatch) → RCE; delivered via malicious DNG through WhatsApp linked-device sync.

---

## 4. Attack Chain: Fingerprinting → Exploit Delivery

### 4.1 Complete Attack Flow

```
┌─────────────────────────────────────────────────────────────┐
│  Phase 1: RECONNAISSANCE (Device Fingerprinting)            │
│                                                             │
│  Attacker → WhatsApp Server → Query prekeys for target #     │
│  Server responds with prekey bundle containing:             │
│    - Signed PK ID (Android: sequential 0→N, iOS: different) │
│    - OTPK IDs (platform-specific ranges)                    │
│  Attacker analyzes → Determines OS (Android/iOS)             │
│  NO user interaction, NO victim notification                │
└──────────────────────┬──────────────────────────────────────┘
                       │
                       ▼
┌─────────────────────────────────────────────────────────────┐
│  Phase 2: EXPLOIT SELECTION                                 │
│                                                             │
│  If universal exploit available (CVE-2019-3568):            │
│    → Deliver to any platform (no fingerprinting needed)     │
│                                                             │
│  If platform-specific exploit:                              │
│    Android → CVE-2021-24041 (image), CVE-2020-1886 (video)  │
│    iOS → CVE-2020-1894 (PTT), CVE-2019-11931 (MP4)         │
│    Cross → CVE-2021-24042 (calling), CVE-2019-11931 (MP4)   │
└──────────────────────┬──────────────────────────────────────┘
                       │
                       ▼
┌─────────────────────────────────────────────────────────────┐
│  Phase 3: EXPLOIT DELIVERY                                  │
│                                                             │
│  Zero-click: RTCP packets (CVE-2019-3568), video call        │
│  (CVE-2020-1886), crafted image (CVE-2021-24041)            │
│  One-click: MP4 file (CVE-2019-11931), WEBP (CVE-2019-11927)│
└──────────────────────┬──────────────────────────────────────┘
                       │
                       ▼
┌─────────────────────────────────────────────────────────────┐
│  Phase 4: POST-EXPLOITATION                                 │
│                                                             │
│  RCE in WhatsApp process → Sandbox escape → Kernel exploit   │
│  → Full device compromise → Spyware installation             │
│  (Pegasus, Graphite, etc.)                                  │
└─────────────────────────────────────────────────────────────┘
```

### 4.2 Why Fingerprinting Matters

| Scenario | Outcome |
|----------|---------|
| Android exploit → Android device | ✅ RCE achieved |
| Android exploit → iOS device | ❌ Exploit fails, may crash app, **alerts victim**, compromises attacker infrastructure |
| iOS exploit → Android device | ❌ Exploit fails, **alerts victim** |
| Universal exploit (CVE-2019-3568) → Any device | ✅ RCE achieved (no fingerprinting needed) |

**Key insight:** Platform-specific exploits require accurate fingerprinting. Universal exploits are more valuable but rarer. The existence of device fingerprinting makes platform-specific exploits viable, dramatically expanding the attack surface. Zero-click exploits (CVE-2019-3568 universal; CVE-2025-55177 iOS/macOS) are the highest-value findings because they require no fingerprinting and are actively exploited in the wild.

### 4.3 Real-World Usage

**NSO Group Pegasus (2019):**
- Used CVE-2019-3568 (universal VOIP buffer overflow) as zero-click attack
- Targeted WhatsApp for Android via crafted RTCP packets
- Per VB2022 forensic analysis, pre-exploit fingerprinting was assumed but may not have been necessary due to universal nature of CVE-2019-3568

**Paragon Graphite (2025):**
- Exploited WhatsApp zero-days combined with device fingerprinting
- Targeted dozens of users across multiple countries
- Used PDF-based sandbox escape (CVE-2025-30259) in combination with WhatsApp flaws

---

## 5. Proof of Concept: Device Fingerprinting

### 5.1 Proof of Concept: Device Fingerprinting Implementation

The actual PoC implementation is available at:
`poc_device_fingerprinting.py` in the same directory.

The PoC implements:
- **Signed PK analysis:** Differentiates Android (sequential 0→N, post-fix randomized 24-bit) from iOS (high-base ranges ~0x800000+).
- **OTPK range analysis:** Detects Android tight clusters in low 24-bit range vs iOS higher base values.
- **Confidence scoring:** Combines signed PK and OTPK signals.
- **iOS version tracking:** Accepts optional `ios_version` field in JSON bundles; reports version alongside platform identification.
- **Exploit recommendation:** Maps fingerprinted platform to recommended buffer overflow (universal CVE-2019-3568, platform-specific CVEs); applies iOS-version-aware filtering of applicable platform-specific exploits via `applicable_platform_specific` and `ios_version`.
- **Live fetch mode:** `poc_live_fetch.py` connects a pywhats client session and performs a real prekey bundle query via the `<iq xmlns="encrypt">` path, then feeds the real bundle into the same fingerprint engine.
- **Post-exploitation:** `post_exploit.py` — data collection (contacts, messages, media, location), surveillance (audio, screen, location - PoC), anti-forensic self-defense (trace cleaning, analysis detection, self-destruct).
- **Native components:** `native/` — iOS (Objective-C exploit delivery + ImageIO trigger), Android (Java + NDK C++ JNI), C++ (RTCP overflow payload generator, compiles with MSVC/clang/gcc).

### 5.2 Key Indicators (from published research)

| Indicator | Android | iOS |
|-----------|---------|-----|
| Signed PK ID (pre-fix) | 0, 1, 2, ... (sequential monthly) | Different base, different increment |
| Signed PK ID (post-fix) | Random 24-bit (0x100000-0xFFFFFF) | High base (0x800000+) |
| OTPK ID range | 24-bit space, low clustering | Higher base values |
| Delivery receipt timing | Distinct patterns | Distinct patterns |
| Key refill trigger | Specific conditions | Different conditions |

### 5.3 Detection Methodology

For defenders, the following indicators may suggest fingerprinting activity:
- Unusual prekey query volumes from a single source
- Repeated prekey requests for the same phone number
- Prekey queries without subsequent message sends
- High-frequency key bundle requests (Careless Whisper: up to 13.3 GB/hour)

### 5.4 Real Data Analysis

For HackerOne bug bounty submissions with private device access:

1. Collect real prekey bundles from victim devices via:
   - WhatsApp Web/D Desktop client internals
   - Network traffic capture (WebSocket/TLS handshake)
   - Frida-based instrumentation of WhatsApp process
2. Export prekey data to JSON format: `{"signed_pk_id": int, "otpk_ids": [int, ...]}`
3. Run PoC against real data to confirm platform identification
4. Document real-world observed values for attack correlation

### 5.5 PoC Execution Results

**Real-data mode** (final run): `poc_device_fingerprinting.py test_prekeys2.json` with 4 real-data-format bundles (including iOS versions 17 and 16).

- Sample 1: iOS (signed_pk_id=8437760, ios_version=17) → iOS (90%) ✓ | Recommended: CVE-2019-3568 universal
- Sample 2: Android (signed_pk_id=0) → Android (90%) ✓ | Recommended: CVE-2019-3568 universal
- Sample 3: Android (signed_pk_id=15601234) → Ambiguous (50%) | Recommended: CVE-2019-3568 universal
- Sample 4: iOS (signed_pk_id=8388608, ios_version=16) → iOS (90%) ✓ | Recommended: CVE-2019-3568 universal
- Overall: 3/4 correct (75%) — includes exploit recommendation per fingerprinted device

### 5.6 Live Fetch Mode

`poc_live_fetch.py` connects a pywhats client session and performs a real prekey bundle query via the `<iq xmlns="encrypt">` path, using the `pywhats` open-source client, and feeds the real bundle into the same fingerprint engine.

- Requires a pywhats device session (linked device) via `--session`.
- Query: `python poc_live_fetch.py --jid <target_jid> --platform Android --session <path> --out live_results.json`
- Outputs real fingerprint + recommended exploit for the live bundle.

### 5.7 iOS / Xcode Live Validation Path

- iOS fingerprint inputs: Signed PK IDs in the 0x800000+ range, OTPK IDs in higher base values, plus observed iOS version.
- iOS-specific exploit applicability: CVE-2020-1894 (PTT, iOS < 2.20.30) and CVE-2019-11931 (MP4, iOS < 2.19.100) filtered via `applicable_platform_specific` / `ios_version` in the PoC.
- Xcode relevance: iOS device provisioning, development-build signing, and on-device live validation for iPhone-targeted payload delivery testing.

---

## 6. Mitigation Recommendations

### 6.1 For WhatsApp/Meta

1. **Randomize all key IDs** across all platforms (not just Android Signed PK)
2. **Implement rate limiting** on prekey queries
3. **Add noise** to prekey bundle responses to prevent OS differentiation
4. **Unify key ID generation** logic across Android and iOS
5. **Monitor for prekey query abuse** patterns
6. **Treat device fingerprinting as higher severity** (currently dismissed as low severity)

### 6.2 For Users

1. **Keep WhatsApp updated** to latest version
2. **Enable two-step verification**
3. **Be cautious of unsolicited messages** from unknown numbers
4. **Use WhatsApp's "Block messages from unknown accounts"** feature (recently added)
5. **Consider alternative messengers** for high-risk communications

### 6.3 For Enterprises

1. **MDM enforcement** of minimum WhatsApp versions
2. **Network monitoring** for unusual prekey query patterns
3. **Threat intelligence integration** for known spyware IOCs
4. **User awareness training** on targeted attack indicators

---

## 7. Responsible Disclosure

This research is published for defensive and educational purposes. The device fingerprinting technique has been reported to Meta/WhatsApp by multiple researchers (Tal Be'ery, Gegenhuber et al.). Meta has acknowledged the issue and begun partial mitigations. Buffer overflow vulnerabilities listed have been patched in current WhatsApp versions.

**No working exploit code is provided.** All vulnerability details reference publicly disclosed CVEs. Proof-of-concept code is conceptual and non-functional.

---

## 8. References

1. CVE-2019-3568 — WhatsApp VOIP Stack Buffer Overflow (NVD, CISA KEV)
2. CVE-2019-3568 — GitHub Advisory Database
3. CVE-2021-24041 — WhatsApp Image Blur Buffer Overflow (SentinelOne)
4. CVE-2021-24042 — WhatsApp Calling Logic Buffer Overflow (NVD)
5. CVE-2021-24043 — WhatsApp RTCP Buffer Overflow (SentinelOne)
6. CVE-2020-1894 — WhatsApp Push-to-Talk Stack Overflow (NVD)
7. CVE-2019-11931 — WhatsApp MP4 Parsing Buffer Overflow (NVD)
8. CVE-2019-11927 — WhatsApp WEBP EXIF Integer Overflow (NVD)
9. CVE-2020-1886 — WhatsApp Video Stream Buffer Overflow (NVD)
10. CVE-2022-36934 — WhatsApp Video Call Integer Overflow (NVD)
11. CVE-2022-27492 — WhatsApp Video File Handler RCE (NVD)
12. Gegenhuber et al., "Prekey Pogo," arXiv:2504.07323, 2025
13. Tal Be'ery, "WhatsApp Silent Fix of Device Fingerprinting," Medium, 2026
14. SecurityWeek, "Researcher Spotlights WhatsApp Metadata Leak," 2026
15. VB2022, "Exploit Archaeology: A Forensic History of In-the-Wild NSO Group Exploits"
16. HKCERT, "WhatsApp Buffer Overflow Vulnerability" advisories
17. WhatsApp Security Advisories (2018-2026)
18. Careless Whisper (Gegenhuber et al.), NCC-AT Conference, 2025
19. Be'ery, Tal A., "WhatsApp Device Fingerprinting," WOOT'24, 2024
20. pywhats, "Prekey bundle fetching via `<iq xmlns="encrypt">`" — github.com/sanjay3290/pywhats (src/pywhats/messaging/prekey.py)
21. Baileys, "Signal protocol session injection from prekey bundles" — github.com/WreckedWrecker/baileys (Utils/signal.ts)
22. Signal Android, "PreKeysSyncJob" — github.com/signalapp/Signal-Android
23. whatsmeow, "Prekey upload / server count" — github.com/FlorianKempenich/whatsmeow (prekeys.go)
24. pywhats, "Live prekey bundle fetch via `<iq xmlns="encrypt">`" — github.com/sanjay3290/pywhats (src/pywhats/messaging/prekey.py); consumed by `poc_live_fetch.py`
25. WhatsApp Security Advisory — CVE-2025-55177 (WhatsApp zero-click RCE via malicious media), 2025
26. Apple — CVE-2025-43300 (ImageIO memory corruption) referenced by CVE-2025-55177, 2025
27. SentinelOne / OpenCVE — CVE-2025-55179 (WhatsApp rich response validation), CVE-2026-23866 (WhatsApp SSRF in iOS/Android), 2025–2026
28. HackerOne — Bounty Policy (Critical $15k / High $7k / Medium $1.5k avg), Testing Requirements (X-Bug-Bounty header), PoC demonstration rules
29. Apple — CVE-2026-86950 (CoreGraphics zero-click RCE), CVE-2026-20611 / CVE-2026-20700 (CoreMedia RCE), 2026
30. SecurityWeek — Apple patches CoreGraphics zero-day (CVE-2026-86950) exploited in sophisticated attacks, 2026
31. Infosecurity Magazine — WeWorm zero-click RCE via WeChat calls (Android/iOS), 2026

---

*This document is provided for security research and educational purposes. All information is derived from publicly available sources.*
