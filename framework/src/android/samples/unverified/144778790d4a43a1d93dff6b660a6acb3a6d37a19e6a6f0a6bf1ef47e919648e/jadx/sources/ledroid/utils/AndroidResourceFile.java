package ledroid.utils;

import android.content.res.Resources;
import java.io.File;
import java.io.InputStream;

/* JADX INFO: loaded from: classes.dex */
public final class AndroidResourceFile {

    /* JADX INFO: renamed from: a */
    private int f6370a;

    /* JADX INFO: renamed from: b */
    private Resources f6371b;

    public AndroidResourceFile(Resources resources, int resId) {
        this.f6370a = -1;
        this.f6371b = null;
        this.f6371b = resources;
        this.f6370a = resId;
    }

    public final int getLength() {
        int iAvailable;
        InputStream inStream = null;
        try {
            try {
                inStream = this.f6371b.openRawResource(this.f6370a);
                iAvailable = inStream.available();
                FileUtils.closeIOCloseable(inStream);
            } catch (Exception e) {
                e.printStackTrace();
                FileUtils.closeIOCloseable(inStream);
                iAvailable = -1;
            }
            return iAvailable;
        } catch (Throwable th) {
            FileUtils.closeIOCloseable(inStream);
            throw th;
        }
    }

    public final boolean writeTo(String path) {
        return writeTo(new File(path));
    }

    public final boolean writeTo(File to) {
        InputStream inStream = null;
        try {
            inStream = this.f6371b.openRawResource(this.f6370a);
            return FileUtils.copyToFile(this.f6371b.openRawResource(this.f6370a), to);
        } finally {
            FileUtils.closeIOCloseable(inStream);
        }
    }
}
