package tms;

import android.content.ContentResolver;
import android.net.Uri;
import android.provider.Settings;

/* JADX INFO: renamed from: tms.n */
/* JADX INFO: loaded from: classes.dex */
public class C1328n {
    /* JADX INFO: renamed from: a */
    public static void m3526a(int i, ContentResolver contentResolver) {
        Uri uriFor = Settings.System.getUriFor("screen_brightness");
        Settings.System.putInt(contentResolver, "screen_brightness", i);
        contentResolver.notifyChange(uriFor, null);
    }

    /* JADX INFO: renamed from: a */
    public static boolean m3527a(ContentResolver contentResolver) {
        try {
            return Settings.System.getInt(contentResolver, "screen_brightness_mode") == 1;
        } catch (Settings.SettingNotFoundException e) {
            e.printStackTrace();
            return false;
        }
    }

    /* JADX INFO: renamed from: b */
    public static int m3528b(ContentResolver contentResolver) {
        try {
            return Settings.System.getInt(contentResolver, "screen_brightness");
        } catch (Exception e) {
            e.printStackTrace();
            return 0;
        }
    }

    /* JADX INFO: renamed from: c */
    public static void m3529c(ContentResolver contentResolver) {
        Settings.System.putInt(contentResolver, "screen_brightness_mode", 0);
    }

    /* JADX INFO: renamed from: d */
    public static void m3530d(ContentResolver contentResolver) {
        Settings.System.putInt(contentResolver, "screen_brightness_mode", 1);
    }
}
