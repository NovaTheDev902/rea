# Command and Control (C2) Infrastructure

## Overview
Graphite operators communicate with infected devices through a C2 server network. Citizen Lab mapped this infrastructure using TLS certificate fingerprinting (Fingerprint P1) and identified over 150 IP addresses across multiple countries.

## C2 Architecture Observations
- Servers exhibit consistent **anomalous TLS certificate patterns** (see Fingerprint_P1_TLS_C2_Fingerprint folder)
- C2 servers appear to be co-located with or geographically proximate to the government clients operating them
- Country-level clustering allowed Citizen Lab to attribute Paragon customers to at least 7 countries

## Identified Operator Countries (Infrastructure-based)
Based on C2 server geographic distribution and clustering patterns (Citizen Lab, March 2025):
- Australia
- Canada
- Cyprus
- Denmark
- Israel
- Italy (independently confirmed by Italian government officials)
- Singapore

Italy is the only country to have officially confirmed its use of Graphite, and the Italian government's deployment against activists Casarini and Caccia is forensically verified.

## How C2 Communication Works (Inferred)
The exact protocol is not publicly documented. From the forensic artifacts:
1. Infected device connects to a Paragon C2 server
2. C2 server issues tasking (what data to collect, when to activate microphone/camera)
3. Device sends collected data back to C2
4. All communication occurs over HTTPS (TLS-encrypted), making content interception impractical without device-level access

## Detection via Fingerprint P1
Network-level detection is possible if you have access to the device's network connection logs and can compare them to the Fingerprint P1 template published by Citizen Lab. This is how forensic confirmation was achieved for the journalist victims.

## Infrastructure Stability
Since Fingerprint P1 was published publicly in March 2025, Paragon could modify their TLS configuration to evade this specific fingerprint. Whether they have rotated their infrastructure in response is not publicly known.

## Sources
- [Citizen Lab March 2025 Report](https://citizenlab.ca/research/a-first-look-at-paragons-proliferating-spyware-operations/)
- [Citizen Lab Forensic Report, June 2025](https://citizenlab.ca/research/first-forensic-confirmation-of-paragons-ios-mercenary-spyware-finds-journalists-targeted/)
- [Deibert/Citizen Lab Blog, March 2025](https://deibert.citizenlab.ca/2025/03/paragons-spyware-a-first-look-at-infrastructure-customers-and-victims/)
