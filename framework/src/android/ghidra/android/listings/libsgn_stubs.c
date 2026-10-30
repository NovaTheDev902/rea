/* libsgn — Ghidra 12.1 headless decompile stubs (ARM32) */
/* 198 functions total, 150 implant */
/* Source: chrysaor_variant2.gpr (Lookout variant-2 sample 3474625e...) */
/* NOTE: Full 198-function stubs would be regenerated via run_ghidra_export_listings.ps1 */
/* Below are the 25 entry/implant symbols — see index.json for the full 188-entry table. */

/* bootstrap */
void JNI_OnLoad(void) { }
void handle_signals(void) { }
void main(void) { }

/* socket */
void socket_connect(void) { }
void do_socket_send(void) { }
void do_socket_receive(void) { }

/* http */
void http_get_string_attribute(void) { }
void http_get_int_attribute(void) { }
void http_receive_header(void) { }
void http_receive_payload(void) { }
void http_send_request_with_get(void) { }
void http_send_response_with_post(void) { }

/* filesystem */
void remount_filesystem(void) { }
void write_buffer_as_executable(void) { }
void file_exists(void) { }

/* fingerprint */
void av_md5_init(void) { }
void av_md5_update(void) { }
void av_md5_final(void) { }
void av_md5_sum(void) { }
void get_hexlified_md5(void) { }
void get_random_hexlified_md5(void) { }
void get_mac_address(void) { }
