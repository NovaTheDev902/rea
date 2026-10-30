package ledroid.utils;

import android.content.res.Resources;

/* JADX INFO: loaded from: classes.dex */
public class AndroidResources {

    /* JADX INFO: renamed from: a */
    private Resources f6372a;

    /* JADX INFO: renamed from: b */
    private String f6373b;

    public AndroidResources(Resources resources) {
        this.f6372a = resources;
        this.f6373b = null;
    }

    public AndroidResources(Resources resources, String packageName) {
        this(resources);
        this.f6373b = packageName;
    }

    public int getIdentifier(String defPackage, String defType, String name) {
        return this.f6372a.getIdentifier(name, defType, defPackage);
    }

    public int getIdentifier(String defType, String name) {
        return getIdentifier(this.f6373b, defType, name);
    }

    public int getIdentifier(String name) {
        return getIdentifier(this.f6373b, null, name);
    }
}
