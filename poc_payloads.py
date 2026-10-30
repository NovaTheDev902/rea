"""Payload builders (RTCP, MP4, PTT, WEBP)."""

from native_wrapper import craft_rtcp, craft_mp4, craft_ptt, craft_webp


def craft_rtcp_payload(ssrc=0xDEADBEEF, size=8192):
    return craft_rtcp(ssrc=ssrc, size=size)


def craft_mp4_payload(size=1024):
    return craft_mp4(size=size)


def craft_ptt_payload(size=1024):
    return craft_ptt(size=size)


def craft_webp_payload(size=1024):
    return craft_webp(size=size)


if __name__ == "__main__":
    rtcp = craft_rtcp_payload()
    mp4 = craft_mp4_payload()
    ptt = craft_ptt_payload()
    webp = craft_webp_payload()
    print(f"RTCP: {len(rtcp)} bytes")
    print(f"MP4: {len(mp4)} bytes")
    print(f"PTT: {len(ptt)} bytes")
    print(f"WEBP: {len(webp)} bytes")