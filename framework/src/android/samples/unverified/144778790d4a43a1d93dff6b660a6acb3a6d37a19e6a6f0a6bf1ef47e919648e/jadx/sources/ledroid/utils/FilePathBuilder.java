package ledroid.utils;

import java.io.File;

/* JADX INFO: loaded from: classes.dex */
public final class FilePathBuilder {

    /* JADX INFO: renamed from: a */
    private String f6378a;

    public FilePathBuilder(String dirPath) {
        this.f6378a = dirPath;
    }

    public FilePathBuilder(File dir) {
        this(dir.getPath());
    }

    public final FilePathBuilder getSubFile(String name) {
        return new FilePathBuilder(new File(this.f6378a, name));
    }

    public final File getFile() {
        return new File(this.f6378a);
    }

    public final String getPath() {
        return this.f6378a;
    }
}
