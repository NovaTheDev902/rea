# Detection and Forensics — Tools and Methods

## Overview
Detecting Graphite requires institutional-grade forensic tools. No commercial antivirus or consumer-grade security app detects it. Citizen Lab's forensic methodology established the gold standard for Graphite detection.

## Citizen Lab's Three-Indicator Framework

### 1. BIGPRETZEL (Android)
- **Description:** Forensic artifact left by Graphite on Android devices
- **Location:** System or app logs (exact locations depend on device state)
- **Authority:** Confirmed by WhatsApp as uniquely tied to Paragon Graphite
- **Indicators:** Specific log entry patterns, timestamps across multiple dates (multi-session marker)
- **Reliability:** HIGH — confirmed in published forensic reports
- **Reference folder:** `BIGPRETZEL_Android_Forensic_Indicator/`

**What it tells you:**
- Device was infected with Graphite
- Time window of infection (from log timestamps)
- Persistence likely (if timestamps span reboots)

### 2. Fingerprint P1 (Network / iOS & Android)
- **Description:** TLS certificate fingerprint of Paragon C2 servers
- **Method:** Cross-reference device network logs (DNS, TLS handshakes) with known P1 fingerprints
- **Authority:** Fingerprints published by Citizen Lab after forensic confirmation
- **Detection scope:** Both iOS and Android (C2 is platform-agnostic)
- **Reliability:** HIGH — specific to Paragon infrastructure
- **Reference folder:** `Fingerprint_P1_TLS_C2_Fingerprint/`

**What it tells you:**
- Device connected to Paragon-controlled server
- Timing of C2 communication
- Operator's infrastructure footprint

### 3. ATTACKER1 (iOS — iMessage sender)
- **Description:** Specific iMessage sender ID/account used in delivery
- **Location:** iOS diagnostic logs (iMessage database)
- **Method:** Forensic extraction of message headers showing sender
- **Authority:** Confirmed by Citizen Lab across multiple journalist victims
- **Reliability:** HIGH — links multiple victims to same operator
- **Reference folder:** `ATTACKER1_iMessage_Delivery_Account/`

**What it tells you:**
- Device was targeted by iMessage vector
- Operator used consistent sender account across campaigns
- Timeline of attack delivery

## Tools for Forensic Analysis

### MVT — Mobile Verification Toolkit (Primary)
- **GitHub:** https://github.com/mvt-project/mvt
- **Developer:** Amnesty International Security Lab
- **Initial Release:** July 2021 (created for Pegasus Project investigations)
- **Current Status:** Active development, maintained
- **License:** Open source (GPLv3)

**What it does:**
- Scans iOS and Android device backups/extractions
- Compares against public IOC (Indicator of Compromise) files in STIX 2.1 format
- Generates detailed forensic report with timeline
- Automates detection of multiple spyware families

**IOC Coverage:**
- **iOS IOCs:** Pegasus, Graphite, Spyware families
- **Android IOCs:** BIGPRETZEL (Graphite), NSO Pegasus, others
- **Source:** Amnesty International's IOC GitHub repository (https://github.com/AmnestyTech/stixindicators)
- **Update frequency:** Ongoing as new spyware is discovered/confirmed

**Installation:**
```bash
pip3 install mvt-ios mvt-android
```

**Usage (basic):**
```bash
# Android backup analysis
mvt-android --iocs stixindicators.json backup.ab

# iOS backup analysis
mvt-ios --iocs stixindicators.json backup.tar
```

**Detailed guide:** https://docs.mvt.re/

### iMazing Spyware Analyzer (GUI Alternative)
- **Website:** https://imazing.com/spyware-analyzer
- **Type:** Consumer-friendly GUI wrapper around MVT
- **Cost:** Free
- **Platforms:** macOS, Windows

**Features:**
- Graphical interface (no CLI required)
- Automatic IOC file updates from Amnesty International
- One-click device backup and scan
- Report generation with visual indicators
- No technical knowledge required

**Advantages over raw MVT:**
- Easier for journalists/non-technical users
- Automatic IOC updates
- Visual results presentation
- Device backup handled within app

### Citizen Lab Forensic Reports (Reference Material)
- **Primary report:** https://citizenlab.ca/research/first-forensic-confirmation-of-paragons-ios-mercenary-spyware-finds-journalists-targeted/ (June 2025)
- **IOC specifications:** Published as appendices/supplementary materials
- **Methodology:** Detailed forensic process described in full technical report

### Amnesty International Security Lab Resources
- **GitHub:** https://github.com/AmnestyTech
- **STIX Indicators:** https://github.com/AmnestyTech/stixindicators (IOC database)
- **Spyware tracking:** https://amnesty.org/en/tech/ (public archive)

## Forensic Process (Step-by-Step)

### For iOS Users
1. **Extract device backup:**
   - Connect to Mac (Finder) or Windows (iTunes)
   - Create unencrypted backup
   - Export backup to folder

2. **Run MVT or iMazing:**
   ```bash
   mvt-ios --iocs stixindicators.json /path/to/backup.tar
   ```

3. **Check for indicators:**
   - ATTACKER1 in iMessage logs
   - Fingerprint P1 in network connections
   - Timeline of suspicious activity

### For Android Users
1. **Extract device backup:**
   ```bash
   adb backup -apk -all -f backup.ab
   ```
   Or use iMazing to automate

2. **Run MVT:**
   ```bash
   mvt-android --iocs stixindicators.json /path/to/backup.ab
   ```

3. **Check for indicators:**
   - BIGPRETZEL in app logs
   - Fingerprint P1 in network logs
   - Timestamp anomalies (multi-date activity = likely persistence)

4. **Review results:**
   - Extract HTML report from MVT output
   - Cross-reference findings with known Paragon activity windows (Jan-Jun 2025)

## Why Detection Is Difficult

### For End Users
- **No UI indicator:** Graphite runs without app icon, notification, or visible process
- **AV blind:** No commercial antivirus detects it (zero-day/closed-source)
- **Network encrypted:** C2 traffic is TLS-encrypted, indistinguishable from normal HTTPS
- **No behavioral trigger:** Doesn't cause crashes, battery drain, or performance impact

### For Network Defenders
- **TLS fingerprint unique:** Difficult to detect without baseline C2 fingerprints
- **Low-volume traffic:** Exfiltration designed to be stealthy (likely on-demand or batched)
- **Trusted platforms:** Exploits via iMessage/WhatsApp (trusted apps, not malware vectors)

### For Mobile OS Vendors
- **Zero-day window:** Vulnerabilities existed for months before public disclosure
- **Post-compromise:** Only detectable after infection via forensic analysis, not preventive

## False Positives & Refuted Claims

### SMALLPRETZEL (iOS) — REFUTED
Multiple secondary sources claimed an "iOS forensic artifact" called SMALLPRETZEL (described as anomalous CloudKit activity). This was **refuted 0-3** by adversarial verification:
- Does not appear in Citizen Lab's primary forensic reports
- Not confirmed by Apple or iOS security researchers
- Origin: unverified secondary source, likely misattribution
- **Action:** Do NOT treat SMALLPRETZEL as a confirmed IOC

### "Photo/Video processing component" — PARTIALLY REFUTED
Reporting claimed CVE-2025-43200 specifically targeted "Apple's photo/video processing component." Citizen Lab's report confirms **iCloud Link media processing**, but specific sub-component (ImageIO, MobileAsset daemon, etc.) remains unspecified. Do not assume specific component from media processing description.

## Recommended Forensic Service Providers
- **Citizen Lab (Academic):** https://citizenlab.ca/ - Free forensic analysis for journalists/activists at risk
- **Amnesty International:** https://amnesty.org/en/tech/ - Technical security services
- **Freedom of the Press Foundation:** https://freedom.press/ - Journalist-focused security support

## IOC File Locations & Updates
- **MVT IOC database:** https://github.com/AmnestyTech/stixindicators
- **Citizen Lab indicators:** Available in research reports
- **Update frequency:** Check weekly for new Graphite indicators as research evolves

## Timeline of Detection Capability
| Date | Event |
|------|-------|
| Jan 31, 2025 | WhatsApp notifies ~90 users; BIGPRETZEL artifact first detected |
| Feb-Mar 2025 | Citizen Lab begins forensic analysis |
| March 2025 | Citizen Lab publishes preliminary findings on Paragon operations |
| June 2025 | Citizen Lab publishes full forensic report with IOCs |
| June 2025+ | MVT updated with Graphite-specific IOC patterns |

## Sources
- [Citizen Lab Forensic Report, June 2025](https://citizenlab.ca/research/first-forensic-confirmation-of-paragons-ios-mercenary-spyware-finds-journalists-targeted/)
- [MVT GitHub — Mobile Verification Toolkit](https://github.com/mvt-project/mvt)
- [Amnesty International STIX Indicators](https://github.com/AmnestyTech/stixindicators)
- [iMazing Spyware Analyzer](https://imazing.com/spyware-analyzer)
- [Amnesty International Security Lab](https://amnesty.org/en/tech/)
- [CyberInsider](https://cyberinsider.com/paragons-spyware-graphite-used-in-whatsapp-attacks-uncovered/)
