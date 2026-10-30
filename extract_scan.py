import re, os
ROOT = "C:/Users/Brayd/OneDrive/Desktop/Security research report/framework/src/android/samples"
ips = set(); urls = set()
for root,_,fs in os.walk(ROOT):
    for f in fs:
        if not f.endswith(".java"): continue
        p = os.path.join(root,f)
        try:
            t = open(p, errors="ignore").read()
        except Exception:
            continue
        for m in re.findall(r"\b(?:\d{1,3}\.){3}\d{1,3}\b", t):
            ips.add(m)
        for m in re.findall(r"https?://[^\s\"']+", t):
            urls.add(m)
print("IP count:", len(ips))
for ip in sorted(ips): print("  IP:", ip)
print("URL count:", len(urls))
for u in sorted(urls)[:60]: print("  URL:", u)
