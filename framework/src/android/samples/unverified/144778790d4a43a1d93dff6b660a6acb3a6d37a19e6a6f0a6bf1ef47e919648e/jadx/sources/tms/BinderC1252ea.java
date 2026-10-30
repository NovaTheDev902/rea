package tms;

import com.tencent.tmsecure.module.networkload.NetworkLoadTask;
import java.io.File;
import java.util.List;

/* JADX INFO: renamed from: tms.ea */
/* JADX INFO: loaded from: classes.dex */
public class BinderC1252ea<T extends NetworkLoadTask> extends AbstractBinderC1230df<T> {
    public static final String TEMPFILE_SUFFIX = ".tmp";

    /* JADX INFO: renamed from: a */
    private String f7230a;

    /* JADX INFO: renamed from: c */
    private void m3218c(T t) {
        String str = t.mParentPath + File.separator + t.mName;
        File file = new File(str);
        File file2 = new File(str + TEMPFILE_SUFFIX);
        if (file2.exists()) {
            if (file.exists()) {
                file.delete();
            }
            file2.renameTo(file);
        }
    }

    @Override // tms.AbstractBinderC1230df
    protected void doBeforeContinue(T t) {
        String str;
        if (t.mThread != null) {
            ((C1233di) t.mThread).m3132a();
            t.mThread = null;
        }
        String str2 = t.mParentPath + File.separator + t.mName;
        String str3 = str2 + TEMPFILE_SUFFIX;
        File file = new File(str3);
        File file2 = new File(str2);
        if (!t.isSupportRange && file.exists() && !t.isOnChangeRetry) {
            file.delete();
        }
        if (file2.exists() && file2.length() == t.mSize && t.mSize > 0) {
            str = str2;
        } else {
            file2 = file;
            str = str3;
        }
        t.mCurrentSize = file2.length();
        if (t.mSize > 0) {
            t.mProgress = t.mCurrentSize / t.mSize;
        } else {
            t.mProgress = 0.0f;
        }
        C1233di c1233di = ((t.isSupportRange || t.isOnChangeRetry) && t.mCurrentSize != 0) ? new C1233di(t, true, str) : new C1233di(t, false, str);
        c1233di.m3133a(this);
        t.mThread = c1233di;
    }

    @Override // tms.AbstractBinderC1230df
    protected void doBeforeStart(T t) {
        if (t.mThread != null) {
            ((C1233di) t.mThread).m3132a();
            t.mThread = null;
        }
        t.mParentPath = this.f7230a;
        String str = this.f7230a + File.separator + t.mName;
        String str2 = str + TEMPFILE_SUFFIX;
        File file = new File(str);
        if (file.exists()) {
            file.delete();
        }
        File file2 = new File(str2);
        if (file2.exists()) {
            file2.delete();
        }
        t.mCurrentSize = 0L;
        C1233di c1233di = new C1233di(t, false, str2);
        c1233di.m3133a(this);
        t.mThread = c1233di;
    }

    @Override // tms.AbstractBinderC1230df
    protected void doDeleteFile(T t) {
        doPause(t);
        String str = t.mParentPath + File.separator + t.mName;
        File file = new File(str);
        if (file.exists()) {
            file.delete();
        }
        File file2 = new File(str + TEMPFILE_SUFFIX);
        if (file2.exists()) {
            file2.delete();
        }
    }

    @Override // tms.AbstractBinderC1230df
    protected void doDeleteFile(List<T> list) {
        int size = list.size();
        for (int i = 0; i < size; i++) {
            doDeleteFile(list.get(i));
        }
    }

    @Override // tms.AbstractBinderC1230df
    protected void doFinish(T t) {
        m3218c(t);
    }

    @Override // tms.AbstractBinderC1230df
    protected void doPause(T t) {
        if (t.mThread != null) {
            ((C1233di) t.mThread).m3132a();
            t.mThread = null;
        }
        File file = new File(t.mParentPath + File.separator + t.mName);
        if (!file.exists() || file.length() != t.mSize || t.mSize > 0) {
        }
    }

    public void setDownloadDirPath(String str) {
        this.f7230a = str;
        File file = new File(this.f7230a);
        if (file.exists()) {
            return;
        }
        file.mkdirs();
    }
}
