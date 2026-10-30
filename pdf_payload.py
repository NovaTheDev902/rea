"""Malicious PDF generator (WhatsApp delivery)."""

from native_wrapper import craft_pdf


def build_pdf_payload(size=8192):
    return craft_pdf(size=size)


if __name__ == "__main__":
    pdf = build_pdf_payload()
    print(f"PDF payload: {len(pdf)} bytes")