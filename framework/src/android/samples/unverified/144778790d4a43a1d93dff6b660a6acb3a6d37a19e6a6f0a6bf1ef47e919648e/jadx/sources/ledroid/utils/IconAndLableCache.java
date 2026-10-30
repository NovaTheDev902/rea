package ledroid.utils;

import android.R;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.drawable.Drawable;
import android.os.Build;
import android.text.TextUtils;
import java.util.HashMap;

/* JADX INFO: loaded from: classes.dex */
public final class IconAndLableCache {

    /* JADX INFO: renamed from: e */
    private static IconAndLableCache f6379e = new IconAndLableCache();

    /* JADX INFO: renamed from: a */
    private final Bitmap f6380a;

    /* JADX INFO: renamed from: b */
    private final HashMap<String, C1107a> f6381b = new HashMap<>(50);

    /* JADX INFO: renamed from: c */
    private Context f6382c;

    /* JADX INFO: renamed from: d */
    private PackageManager f6383d;

    /* JADX INFO: renamed from: ledroid.utils.IconAndLableCache$a */
    private static final class C1107a {

        /* JADX INFO: renamed from: a */
        private Bitmap f6384a;

        /* JADX INFO: renamed from: b */
        private String f6385b;

        /* synthetic */ C1107a(byte b) {
            this();
        }

        private C1107a() {
        }
    }

    private IconAndLableCache() {
        Drawable drawableM2680a = m2680a();
        Bitmap bitmapCreateBitmap = Bitmap.createBitmap(Math.max(drawableM2680a.getIntrinsicWidth(), 1), Math.max(drawableM2680a.getIntrinsicHeight(), 1), Bitmap.Config.ARGB_8888);
        Canvas canvas = new Canvas(bitmapCreateBitmap);
        drawableM2680a.setBounds(0, 0, bitmapCreateBitmap.getWidth(), bitmapCreateBitmap.getHeight());
        drawableM2680a.draw(canvas);
        if (Build.VERSION.SDK_INT > 10) {
            canvas.setBitmap(null);
        }
        this.f6380a = bitmapCreateBitmap;
    }

    public static IconAndLableCache getIconCacheInstance(Context context) {
        if (f6379e.f6382c == null || f6379e.f6383d == null) {
            f6379e.f6382c = context.getApplicationContext();
            f6379e.f6383d = context.getPackageManager();
        }
        return f6379e;
    }

    /* JADX INFO: renamed from: a */
    private Drawable m2680a() {
        return m2683a(Resources.getSystem(), R.drawable.sym_def_app_icon);
    }

    /* JADX INFO: renamed from: a */
    private Drawable m2683a(Resources resources, int iconId) {
        Drawable d;
        try {
            d = resources.getDrawable(iconId);
        } catch (Resources.NotFoundException e) {
            d = null;
        }
        if (d != null) {
            return d;
        }
        Drawable d2 = m2680a();
        return d2;
    }

    public final Drawable getFullResIcon(String packageName, int iconId) {
        Resources resources;
        try {
            resources = this.f6383d.getResourcesForApplication(packageName);
        } catch (PackageManager.NameNotFoundException e) {
            resources = null;
        }
        if (resources != null && iconId != 0) {
            return m2683a(resources, iconId);
        }
        return m2680a();
    }

    /* JADX INFO: renamed from: a */
    private Drawable m2681a(ActivityInfo info) {
        Resources resources;
        int iconId;
        try {
            resources = this.f6383d.getResourcesForApplication(info.applicationInfo);
        } catch (PackageManager.NameNotFoundException e) {
            resources = null;
        }
        if (resources != null && (iconId = info.getIconResource()) != 0) {
            return m2683a(resources, iconId);
        }
        return m2680a();
    }

    /* JADX INFO: renamed from: a */
    private Drawable m2682a(ApplicationInfo applicationInfo) {
        Resources resources;
        int iconId;
        try {
            resources = this.f6383d.getResourcesForApplication(applicationInfo);
        } catch (PackageManager.NameNotFoundException e) {
            resources = null;
        }
        if (resources != null && (iconId = applicationInfo.icon) != 0) {
            return m2683a(resources, iconId);
        }
        return m2680a();
    }

    public final void remove(String packageName) {
        synchronized (this.f6381b) {
            this.f6381b.remove(packageName);
        }
    }

    public final void flush() {
        synchronized (this.f6381b) {
            this.f6381b.clear();
        }
    }

    public final Bitmap getIcon(Intent intent) {
        Bitmap bitmap;
        synchronized (this.f6381b) {
            ResolveInfo resolveInfo = this.f6383d.resolveActivity(intent, 0);
            String packageName = intent.getComponent().getPackageName();
            if (resolveInfo == null || packageName == null) {
                bitmap = this.f6380a;
            } else {
                C1107a entry = m2685a(resolveInfo);
                bitmap = entry.f6384a;
            }
        }
        return bitmap;
    }

    public final String getLable(Intent intent) {
        String str;
        synchronized (this.f6381b) {
            ResolveInfo resolveInfo = this.f6383d.resolveActivity(intent, 0);
            String packageName = intent.getComponent().getPackageName();
            if (resolveInfo == null || packageName == null) {
                str = null;
            } else {
                C1107a entry = m2685a(resolveInfo);
                str = entry.f6385b;
            }
        }
        return str;
    }

    public final Bitmap getIcon(ResolveInfo resolveInfo) {
        Bitmap bitmap;
        synchronized (this.f6381b) {
            if (resolveInfo == null) {
                bitmap = null;
            } else {
                C1107a entry = m2685a(resolveInfo);
                bitmap = entry.f6384a;
            }
        }
        return bitmap;
    }

    public final String getLable(ResolveInfo resolveInfo) {
        String str;
        synchronized (this.f6381b) {
            if (resolveInfo == null) {
                str = null;
            } else {
                C1107a entry = m2685a(resolveInfo);
                str = entry.f6385b;
            }
        }
        return str;
    }

    public final Bitmap getIcon(PackageInfo packageInfo) {
        Bitmap bitmap;
        synchronized (this.f6381b) {
            if (packageInfo == null) {
                bitmap = null;
            } else {
                C1107a entry = m2684a(packageInfo);
                bitmap = entry.f6384a;
            }
        }
        return bitmap;
    }

    public final String getLable(PackageInfo packageInfo) {
        String str;
        synchronized (this.f6381b) {
            if (packageInfo == null) {
                str = null;
            } else {
                C1107a entry = m2684a(packageInfo);
                str = entry.f6385b;
            }
        }
        return str;
    }

    public final Bitmap getIcon(ApplicationInfo applicationInfo) {
        Bitmap bitmap;
        synchronized (this.f6381b) {
            if (applicationInfo == null) {
                bitmap = null;
            } else {
                C1107a entry = m2686b(applicationInfo);
                bitmap = entry.f6384a;
            }
        }
        return bitmap;
    }

    public final String getLable(ApplicationInfo applicationInfo) {
        String str;
        synchronized (this.f6381b) {
            if (applicationInfo == null) {
                str = null;
            } else {
                C1107a entry = m2686b(applicationInfo);
                str = entry.f6385b;
            }
        }
        return str;
    }

    public final Bitmap getIcon(String packageName) {
        Bitmap bitmap;
        synchronized (this.f6381b) {
            if (TextUtils.isEmpty(packageName)) {
                bitmap = null;
            } else {
                try {
                    ApplicationInfo info = this.f6383d.getApplicationInfo(packageName, 0);
                    C1107a entry = m2686b(info);
                    bitmap = entry.f6384a;
                } catch (PackageManager.NameNotFoundException e) {
                    bitmap = this.f6380a;
                }
            }
        }
        return bitmap;
    }

    public final String getLable(String packageName) {
        synchronized (this.f6381b) {
            try {
                if (TextUtils.isEmpty(packageName)) {
                    packageName = null;
                } else {
                    try {
                        ApplicationInfo info = this.f6383d.getApplicationInfo(packageName, 0);
                        C1107a entry = m2686b(info);
                        packageName = entry.f6385b;
                    } catch (PackageManager.NameNotFoundException e) {
                    }
                }
            } catch (Throwable th) {
                throw th;
            }
        }
        return packageName;
    }

    public final boolean isDefaultIcon(Bitmap icon) {
        return this.f6380a.equals(icon);
    }

    /* JADX INFO: renamed from: a */
    private C1107a m2684a(PackageInfo packageInfo) {
        return m2686b(packageInfo.applicationInfo);
    }

    /* JADX INFO: renamed from: b */
    private C1107a m2686b(ApplicationInfo applicationInfo) {
        String packageName = applicationInfo.packageName;
        C1107a entry = this.f6381b.get(packageName);
        if (entry == null) {
            entry = new C1107a((byte) 0);
            entry.f6385b = applicationInfo.loadLabel(this.f6383d).toString();
            if (entry.f6385b == null) {
                entry.f6385b = applicationInfo.name;
            }
            entry.f6384a = IconUtilities.createIconBitmap(m2682a(applicationInfo), this.f6382c);
            this.f6381b.put(packageName, entry);
        }
        return entry;
    }

    /* JADX INFO: renamed from: a */
    private C1107a m2685a(ResolveInfo info) {
        String packageName;
        if (info.resolvePackageName != null) {
            packageName = info.resolvePackageName;
        } else {
            packageName = info.activityInfo != null ? info.activityInfo.packageName : info.serviceInfo.packageName;
        }
        C1107a entry = this.f6381b.get(packageName);
        if (entry == null) {
            entry = new C1107a((byte) 0);
            entry.f6385b = info.loadLabel(this.f6383d).toString();
            if (entry.f6385b == null) {
                entry.f6385b = info.activityInfo != null ? info.activityInfo.name : info.serviceInfo.name;
            }
            entry.f6384a = IconUtilities.createIconBitmap(m2681a(info.activityInfo), this.f6382c);
            this.f6381b.put(packageName, entry);
        }
        return entry;
    }

    public final HashMap<String, Bitmap> getAllIcons() {
        HashMap<String, Bitmap> set;
        synchronized (this.f6381b) {
            set = new HashMap<>();
            for (String key : this.f6381b.keySet()) {
                C1107a e = this.f6381b.get(key);
                set.put(key, e.f6384a);
            }
        }
        return set;
    }
}
