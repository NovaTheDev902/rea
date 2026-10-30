package tms;

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.res.Resources;
import android.util.DisplayMetrics;
import java.io.File;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: renamed from: tms.m */
/* JADX INFO: loaded from: classes.dex */
public class C1327m {
    /* JADX INFO: renamed from: a */
    public static List<Object> m3525a(Context context, String str, boolean z) {
        ArrayList arrayList = new ArrayList();
        try {
            Class<?> cls = Class.forName("android.content.pm.PackageParser");
            Object objNewInstance = cls.getConstructor(String.class).newInstance(str);
            DisplayMetrics displayMetrics = new DisplayMetrics();
            displayMetrics.setToDefaults();
            Object objInvoke = cls.getDeclaredMethod("parsePackage", File.class, String.class, DisplayMetrics.class, Integer.TYPE).invoke(objNewInstance, new File(str), str, displayMetrics, 0);
            ApplicationInfo applicationInfo = (ApplicationInfo) objInvoke.getClass().getDeclaredField("applicationInfo").get(objInvoke);
            Class<?> cls2 = Class.forName("android.content.res.AssetManager");
            Object objNewInstance2 = cls2.getConstructor(null).newInstance(null);
            cls2.getDeclaredMethod("addAssetPath", String.class).invoke(objNewInstance2, str);
            Resources resources = context.getResources();
            Resources resources2 = (Resources) Resources.class.getConstructor(objNewInstance2.getClass(), resources.getDisplayMetrics().getClass(), resources.getConfiguration().getClass()).newInstance(objNewInstance2, resources.getDisplayMetrics(), resources.getConfiguration());
            CharSequence text = applicationInfo.labelRes != 0 ? resources2.getText(applicationInfo.labelRes) : null;
            arrayList.add(text != null ? text.toString() : null);
            if (z) {
                arrayList.add(applicationInfo.icon != 0 ? resources2.getDrawable(applicationInfo.icon) : null);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } catch (OutOfMemoryError e2) {
            System.gc();
        }
        return arrayList;
    }
}
