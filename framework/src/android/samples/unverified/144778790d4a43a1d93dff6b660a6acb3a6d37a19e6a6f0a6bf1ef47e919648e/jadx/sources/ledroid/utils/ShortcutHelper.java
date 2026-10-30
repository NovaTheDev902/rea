package ledroid.utils;

import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.net.Uri;
import android.os.Parcelable;

/* JADX INFO: loaded from: classes.dex */
public final class ShortcutHelper {

    /* JADX INFO: renamed from: a */
    private Intent f6404a;

    public ShortcutHelper() {
        this.f6404a = new Intent();
        setDuplicate(false);
    }

    public ShortcutHelper(String shortcutName) {
        this();
        setShortcutName(shortcutName);
    }

    public ShortcutHelper(String shortcutName, Intent launchIntent) {
        this(shortcutName);
        setLaunchIntent(launchIntent);
    }

    public ShortcutHelper(String shortcutName, Parcelable shortIcon) {
        this(shortcutName);
        setShortcutIcon(shortIcon);
    }

    public ShortcutHelper(String shortcutName, Parcelable shortIcon, Intent launchIntent) {
        this(shortcutName, shortIcon);
        setLaunchIntent(launchIntent);
    }

    public final ShortcutHelper setDuplicate(boolean allowed) {
        this.f6404a.putExtra("duplicate", allowed);
        return this;
    }

    public final ShortcutHelper setShortcutName(String name) {
        this.f6404a.putExtra("android.intent.extra.shortcut.NAME", name);
        return this;
    }

    public final ShortcutHelper setShortcutIcon(Parcelable shortIcon) {
        this.f6404a.putExtra("android.intent.extra.shortcut.ICON_RESOURCE", shortIcon);
        return this;
    }

    public final ShortcutHelper setLaunchIntent(Intent launchIntent) {
        this.f6404a.putExtra("android.intent.extra.shortcut.INTENT", launchIntent);
        return this;
    }

    public final ShortcutHelper installTheShortcut(Context ctx) throws ShortcutCreatorInstallException {
        if (ctx == null) {
            throw new ShortcutCreatorInstallException("Shortcut installation need a Context, but it is null!");
        }
        m2696a();
        this.f6404a.setAction("com.android.launcher.action.INSTALL_SHORTCUT");
        ctx.sendBroadcast(this.f6404a);
        return this;
    }

    /* JADX INFO: renamed from: a */
    private void m2696a() throws ShortcutCreatorInstallException {
        if (!this.f6404a.getExtras().containsKey("android.intent.extra.shortcut.INTENT")) {
            throw new ShortcutCreatorInstallException("Didnot set Intent.EXTRA_SHORTCUT_INTENT yet!");
        }
    }

    public final ShortcutHelper uninstallTheShortcut(Context ctx) throws ShortcutCreatorInstallException {
        if (ctx == null) {
            throw new ShortcutCreatorInstallException("Shortcut installation need a Context, but it is null!");
        }
        m2696a();
        this.f6404a.setAction("com.android.launcher.action.UNINSTALL_SHORTCUT");
        ctx.sendBroadcast(this.f6404a);
        return this;
    }

    public final boolean isExistShortcut(Context ctx) {
        boolean isInstallShortcut = false;
        String[] AUTHORITY = {"com.android.launcher.settings", "com.android.launcher2.settings", "com.lenovo.launcher2.settings"};
        Uri[] CONTENT_URIs = {Uri.parse("content://" + AUTHORITY[0] + "/favorites?notify=true"), Uri.parse("content://" + AUTHORITY[1] + "/favorites?notify=true"), Uri.parse("content://" + AUTHORITY[2] + "/favorites?notify=true")};
        Cursor c = null;
        for (Uri uri : CONTENT_URIs) {
            try {
                c = ctx.getContentResolver().query(uri, new String[]{"iconPackage"}, "iconPackage=?", new String[]{ctx.getPackageName()}, null);
                if (c != null && c.moveToFirst()) {
                    isInstallShortcut = true;
                }
                if (c != null) {
                    c.close();
                }
            } catch (Throwable th) {
                if (c != null) {
                    c.close();
                }
                throw th;
            }
        }
        return isInstallShortcut;
    }

    public static class ShortcutCreatorInstallException extends Exception {
        public ShortcutCreatorInstallException(String msg) {
            super(msg);
        }
    }
}
