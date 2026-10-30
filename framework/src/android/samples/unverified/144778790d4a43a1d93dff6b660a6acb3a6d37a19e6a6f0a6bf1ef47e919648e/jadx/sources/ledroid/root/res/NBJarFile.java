package ledroid.root.res;

import android.content.Context;
import android.util.Log;
import java.io.File;
import java.io.FileFilter;
import ledroid.utils.AndroidResourceFile;

/* JADX INFO: loaded from: classes.dex */
public final class NBJarFile {

    /* JADX INFO: renamed from: a */
    private int f6347a = -1;

    /* JADX INFO: renamed from: b */
    private String f6348b = null;

    /* JADX INFO: renamed from: c */
    private File f6349c;

    /* JADX INFO: renamed from: d */
    private AndroidResourceFile f6350d;

    public NBJarFile(Context ctx, int nbResid, File placedDir) {
        this.f6350d = null;
        this.f6350d = new AndroidResourceFile(ctx.getResources(), nbResid);
        this.f6349c = placedDir;
        updateIfNeed();
    }

    public final String getDexPath(Context ctx, int version) {
        String ver = version == 0 ? "" : "." + version;
        return "/data/dalvik-cache/data@data@" + ctx.getPackageName() + "@files@nb" + ver + ".jar@classes.dex";
    }

    public final int getNbJarFileVersion(File f) {
        return getNbJarFileVersion(f.getName());
    }

    public final int getNbJarFileVersion(String name) {
        if (name.endsWith(".jar") && name.startsWith("nb")) {
            String[] split = name.split("\\.");
            if (split.length == 3) {
                return Integer.valueOf(split[1]).intValue();
            }
        }
        return -1;
    }

    public final void updateIfNeed() {
        File[] listNbJars = this.f6349c.listFiles(new FileFilter() { // from class: ledroid.root.res.NBJarFile.1
            @Override // java.io.FileFilter
            public final boolean accept(File pathname) {
                String name = pathname.getName();
                if (!name.startsWith("nb") || !name.endsWith(".jar")) {
                    return false;
                }
                String[] nameParts = name.split("\\.");
                if (nameParts.length < 3) {
                    return false;
                }
                int version = Integer.valueOf(name.split("\\.")[1]).intValue();
                if (version >= 8) {
                    return version == 8 ? true : true;
                }
                pathname.delete();
                return false;
            }
        });
        if (listNbJars == null || listNbJars.length == 0) {
            this.f6347a = 8;
            this.f6348b = this.f6349c.getAbsolutePath() + "/nb" + (".8") + ".jar";
            if (this.f6350d.writeTo(this.f6348b)) {
                Log.w("Ledroid", "Place ledroid service file to " + this.f6349c.getAbsolutePath() + " fialed.");
                return;
            }
            return;
        }
        if (listNbJars.length == 1) {
            this.f6347a = getNbJarFileVersion(listNbJars[0]);
            this.f6348b = listNbJars[0].getAbsolutePath();
            return;
        }
        if (listNbJars.length > 1) {
            File newFile = listNbJars[0];
            this.f6347a = getNbJarFileVersion(newFile);
            for (int i = 1; i < listNbJars.length; i++) {
                int rVersion = getNbJarFileVersion(listNbJars[i]);
                if (this.f6347a < rVersion) {
                    this.f6347a = rVersion;
                    newFile.delete();
                    newFile = listNbJars[i];
                } else if (this.f6347a > rVersion) {
                    listNbJars[i].delete();
                }
            }
            this.f6348b = newFile.getAbsolutePath();
        }
    }

    public final int getNewVersionCode() {
        return this.f6347a;
    }

    public final String getAbsolutePath() {
        return this.f6348b;
    }
}
