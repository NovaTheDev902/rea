# Android Sandbox Escape & Cross-App Compromise

## Summary (Confidence: HIGH — 3-0 adversarial vote)
After initial delivery via the WhatsApp zero-click exploit, Graphite **escapes the Android application sandbox** to compromise other apps on the same device. This is a privilege escalation step that turns a WhatsApp-scoped exploit into a device-wide implant.

## Why Sandboxes Exist
Android isolates each app in its own sandbox (separate UID, process space, file permissions). An exploit that compromises WhatsApp is, by default, confined to WhatsApp's data. Escaping the sandbox means gaining access to other apps' data and processes.

## What Graphite Does
1. Initial code execution occurs within WhatsApp's process (via the PDF zero-day)
2. Graphite leverages an undisclosed privilege escalation technique to escape WhatsApp's sandbox
3. The implant propagates to at least two other apps on the device, including messaging applications
4. From those app contexts, it can read decrypted message content, access stored files, and activate device hardware (microphone, camera)

## What Is NOT Publicly Known
The specific kernel CVE or process-level mechanism used for the sandbox escape has **not been publicly disclosed**. The research community characterizes it as:
- "Graphite escapes the Android sandbox" (BleepingComputer, Citizen Lab)
- Implemented via the **BIGPRETZEL** artifact trail (see BIGPRETZEL folder)

No kernel CVE has been assigned to this component as of June 2025.

## Forensic Evidence
The BIGPRETZEL artifact (a forensic indicator uniquely identified with Paragon Graphite) was found across **multiple app contexts** on victim devices, confirming cross-app propagation:
- Found in WhatsApp-related process logs
- Found in at least one other messaging app's forensic artifacts on same device

## Competing Technical Descriptions
Two characterizations appear in source materials:
- "Graphite *escapes the sandbox*" — describes the privilege mechanism
- "Graphite *silently loads into legitimate apps as hosts*" — describes the outcome/post-escape state

Both describe the same event at different abstraction levels. The "silently loads into apps" claim was refuted (1-2) as an imprecise standalone description, but the sandbox escape capability itself survived 3-0 verification.

## Open Question
Does the sandbox escape exploit a specific kernel CVE? Has that mechanism been patched in any Android security update independent of the WhatsApp fix? This remains publicly unconfirmed as of the research cutoff.

## Sources
- [BleepingComputer, Jan 2025](https://www.bleepingcomputer.com/news/security/whatsapp-patched-zero-day-flaw-used-in-paragon-spyware-attacks/)
- [Citizen Lab Forensic Report, June 2025](https://citizenlab.ca/research/first-forensic-confirmation-of-paragons-ios-mercenary-spyware-finds-journalists-targeted/)
