# Fingerprint P1 — TLS Certificate C2 Fingerprinting Method

## Summary (Confidence: MEDIUM — 3-0 vote, medium verdict due to source hedging)
**Fingerprint P1** is a TLS certificate fingerprinting technique developed by Citizen Lab to identify Paragon Graphite command-and-control (C2) servers on the internet. It works by identifying anomalous patterns in TLS certificate configurations that are consistent across Paragon's C2 infrastructure.

## What It Detects
Paragon's C2 servers exhibit distinctive TLS certificate characteristics:
- **Anomalous validity periods** (not matching standard CAs or Let's Encrypt patterns)
- **Distinctive SAN/URI structures** (Subject Alternative Names and URI fields in the certificate)

These patterns are consistent enough across Paragon's deployed infrastructure to serve as a passive fingerprint.

## How the Detection Works (Two-Step Process)
1. Citizen Lab scans internet-facing servers using tools like Shodan/Censys/ZMap, collecting TLS certificate data
2. They match server certificates against the Fingerprint P1 template to build a candidate list of Paragon C2 servers
3. Separately, victim device logs are analyzed for network connections
4. If a device connected to a server that **during the same time period** matched Fingerprint P1, this confirms infection

The key phrase from the Citizen Lab report: *"a series of requests to a server that, during the same time period, matched our published Fingerprint P1."*

## Scale of Infrastructure Identified
Using Fingerprint P1, Citizen Lab identified **150+ IP addresses** tied to Paragon clients across multiple countries. This infrastructure mapping was published in the March 2025 report before the June 2025 forensic confirmation.

## Use for Victim Notification
The C2 infrastructure mapping enabled Citizen Lab to:
- Geolocate Paragon operators by country (C2 servers tend to be co-located with clients)
- Identify likely target regions
- Cross-reference device logs against the fingerprint to confirm infections

## Limitation
Fingerprint P1 was first published in March 2025. As of that publication, Paragon can modify their TLS configuration to evade this specific fingerprint. Whether they have done so is not publicly confirmed.

## Sources
- [Citizen Lab Forensic Report, June 2025](https://citizenlab.ca/research/first-forensic-confirmation-of-paragons-ios-mercenary-spyware-finds-journalists-targeted/)
- [Security Affairs, June 2025](https://securityaffairs.com/178940/mobile-2/paragon-graphite-spyware-used-a-zero-day-exploit.html)
- [Citizen Lab, March 2025 (infrastructure report)](https://citizenlab.ca/research/a-first-look-at-paragons-proliferating-spyware-operations/)
