package com.lenovo.lps.sus;

import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import com.lenovo.lps.sus.control.C0104ae;
import com.lenovo.lps.sus.control.EnumC0113ap;
import com.lenovo.lps.sus.p007b.C0089e;
import com.lenovo.lps.sus.p008c.C0092c;
import java.io.File;

/* JADX INFO: loaded from: classes.dex */
public final class SUS {
    public static void AsyncQueryLatestVersionByPackageName(Context context, String str, int i, String str2) {
        C0092c.m346b(true);
        C0104ae.m446a(context, EnumC0113ap.SUS_UPDATETRANSATION_TYPE_BYPACKAGENAME_CUSTINPUT_QUERYLATESTVER, new C0089e(str, String.valueOf(i), str2, true, true));
    }

    public static void AsyncStartVersionUpdate(Context context) {
        C0104ae.m454e();
        C0092c.m344b(0);
        C0092c.m346b(false);
        C0104ae.m446a(context, EnumC0113ap.SUS_UPDATETRANSATION_TYPE_BYPACKAGENAME_USERSETTINGS, (C0089e) null);
    }

    public static void AsyncStartVersionUpdateByAppKey(Context context, String str, int i, String str2) {
        C0104ae.m454e();
        C0092c.m344b(0);
        C0092c.m346b(true);
        C0104ae.m446a(context, EnumC0113ap.SUS_UPDATETRANSATION_TYPE_BYAPPKEY_CUSTINPUT_NOUSERSETTINGS, new C0089e(str, String.valueOf(i), str2, true, true));
    }

    public static void AsyncStartVersionUpdateByCustDM2Activity_NoUserSettings(Context context) {
        C0104ae.m454e();
        C0092c.m344b(0);
        C0092c.m346b(true);
        C0104ae.m446a(context, EnumC0113ap.SUS_UPDATETRANSATION_TYPE_BYPACKAGENAME_CUSTDM2ACTIVITY__NOUSERSETTINGS, (C0089e) null);
    }

    public static void AsyncStartVersionUpdateByPackageName(Context context, String str, int i, String str2) {
        C0104ae.m454e();
        C0092c.m344b(0);
        C0092c.m346b(true);
        C0104ae.m446a(context, EnumC0113ap.SUS_UPDATETRANSATION_TYPE_BYPACKAGENAME_CUSTINPUT_NOUSERSETTINGS, new C0089e(str, String.valueOf(i), str2, true, true));
    }

    public static void AsyncStartVersionUpdateByPackageNameExt(Context context, String str, int i, String str2, int i2) {
        if (i2 != 0) {
            C0104ae.m452d();
        } else {
            C0104ae.m454e();
        }
        C0092c.m344b(i2);
        C0104ae.m446a(context, EnumC0113ap.SUS_UPDATETRANSATION_TYPE_BYPACKAGENAME_CUSTINPUT_NOUSERSETTINGS, new C0089e(str, String.valueOf(i), str2, true, true));
    }

    public static void AsyncStartVersionUpdate_IgnoreUserSettings(Context context) {
        C0104ae.m454e();
        C0092c.m344b(0);
        C0092c.m346b(true);
        C0104ae.m446a(context, EnumC0113ap.SUS_UPDATETRANSATION_TYPE_BYPACKAGENAME_IGNOREUSERSETTINGS, (C0089e) null);
    }

    public static void downloadApp(Context context, String str, String str2, Long l) {
        C0092c.m346b(true);
        C0104ae.m446a(context, EnumC0113ap.SUS_UPDATETRANSATION_TYPE_DOWNLOAD_BYURL, new C0089e(str, str2, String.valueOf(l), true, false));
    }

    public static void finish() {
        C0104ae.m447b();
    }

    public static boolean getAllPromptDisableFlag() {
        return C0104ae.m459g();
    }

    public static void installApp(Context context, String str) {
        C0092c.m346b(false);
        if (context == null || str == null) {
            return;
        }
        if (str == null || str.length() > 0) {
            File file = new File(str);
            if (file.exists()) {
                Intent intent = new Intent("android.intent.action.VIEW");
                String str2 = "file://" + file.getAbsolutePath();
                if (str2 != null) {
                    intent.setFlags(268435456);
                    intent.putExtra("apk_from", "com.lenovo.appstore");
                    intent.setDataAndType(Uri.parse(str2), "application/vnd.android.package-archive");
                    context.startActivity(intent);
                }
            }
        }
    }

    public static void installAppExt(Context context, String str, String str2, SUSListener sUSListener, int i) {
        C0092c.m331a(context, str, str2, null, sUSListener, i, false);
    }

    public static boolean isVersionUpdateStarted() {
        boolean zM445a = C0104ae.m445a();
        if (zM445a && !C0092c.m395u() && !C0104ae.m457f() && !C0104ae.m459g()) {
            C0092c.m360e(false);
        }
        return zM445a;
    }

    public static void setAllPromptDisableFlag(boolean z) {
        C0104ae.m453d(z);
        C0104ae.m455e(z);
    }

    public static void setCustDefActivityContextEnableFlag(boolean z) {
        C0104ae.m460h(z);
    }

    public static void setCustomDefNotificationActivityFlag(boolean z) {
        C0104ae.m458g(z);
    }

    public static void setDebugModeFlag(boolean z) {
        C0104ae.m449b(z);
    }

    public static void setDevMode(int i) {
        C0104ae.m439a(i);
    }

    public static void setDownloadPath(String str, long j, long j2) {
        C0092c.m346b(true);
        C0104ae.m443a(str, j, j2);
    }

    public static void setDownloadURLHead(String str) {
        C0104ae.m448b(str);
    }

    public static void setInnerDevFlag(boolean z) {
        C0104ae.m450c(z);
    }

    public static void setInstallType(int i) {
        C0092c.m344b(i);
    }

    public static void setQueryURLHead(String str) {
        C0104ae.m442a(str);
    }

    public static void setSDKPromptDisableFlag(boolean z) {
        C0104ae.m453d(z);
    }

    public static void setSUSListener(SUSListener sUSListener) {
        C0104ae.m441a(sUSListener);
    }

    public static void setUpdateDescribeDisableFlag(boolean z) {
        C0104ae.m456f(z);
    }

    public static void setUpdateOnlyWLAN(boolean z) {
        C0104ae.m444a(z);
    }

    public static void setUserSettingsEnableFlag(boolean z) {
        C0104ae.m462i(z);
    }

    public static void silentUpdateEnable() {
        C0104ae.m452d();
    }

    public static void testSUSServer(Context context) {
        C0092c.m346b(false);
        C0104ae.m446a(context, EnumC0113ap.SUS_UPDATETRANSATION_TYPE_TESTSUSSERVER, (C0089e) null);
    }
}
