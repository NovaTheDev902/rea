// project.pbxproj - Xcode project for GraphiteExploit iOS framework
// This is a minimal Xcode project that can be opened in Xcode
// and built for iOS devices (arm64) or simulator (x86_64/arm64)

// NOTE: This is a simplified project file. For full functionality,
// open in Xcode and configure signing, provisioning, etc.

// Build settings:
// - Target: iOS 15.0+
// - Architecture: arm64 (device), arm64/x86_64 (simulator)
// - Language: Objective-C
// - Framework: Foundation, UIKit, ImageIO, Security

// To build:
//   xcodebuild -project GraphiteExploit.xcodeproj -scheme GraphiteExploit -sdk iphoneos build
//   xcodebuild -project GraphiteExploit.xcodeproj -scheme GraphiteExploit -sdk iphonesimulator build

// Source files:
//   GraphiteExploit.h
//   GraphiteExploit.m

// The project links against:
//   - Foundation.framework
//   - UIKit.framework
//   - ImageIO.framework
//   - Security.framework
//   - libz.tbd (for compression)
