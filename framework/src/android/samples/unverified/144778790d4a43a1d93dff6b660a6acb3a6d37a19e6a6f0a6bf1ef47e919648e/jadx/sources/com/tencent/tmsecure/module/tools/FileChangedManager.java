package com.tencent.tmsecure.module.tools;

import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import tms.C1308gm;

/* JADX INFO: loaded from: classes.dex */
public final class FileChangedManager extends BaseManager {
    public static final int ACCESS = 1;
    public static final int ALL_EVENTS = 4095;
    public static final int ATTRIB = 4;
    public static final int CLOSE_NOWRITE = 16;
    public static final int CLOSE_WRITE = 8;
    public static final int CREATE = 256;
    public static final int DELETE = 512;
    public static final int DELETE_SELF = 1024;
    public static final int MODIFY = 2;
    public static final int MOVED_FROM = 64;
    public static final int MOVED_TO = 128;
    public static final int MOVE_SELF = 2048;
    public static final int OPEN = 32;

    /* JADX INFO: renamed from: a */
    private C1308gm f6231a;

    public final void addListener(String str, int i, IFileChangedListener iFileChangedListener) {
        if (isExpired()) {
            return;
        }
        this.f6231a.m3423a(str, i, iFileChangedListener);
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6231a = new C1308gm();
        this.f6231a.onCreate(context);
        setImpl(this.f6231a);
    }

    public final void removeListener(String str) {
        if (isExpired()) {
            return;
        }
        this.f6231a.m3422a(str);
    }
}
