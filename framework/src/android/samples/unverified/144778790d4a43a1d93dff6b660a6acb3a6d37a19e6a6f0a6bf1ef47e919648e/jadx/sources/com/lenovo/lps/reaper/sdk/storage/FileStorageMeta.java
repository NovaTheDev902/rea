package com.lenovo.lps.reaper.sdk.storage;

import com.lenovo.lps.reaper.sdk.util.TLog;
import java.nio.ByteBuffer;

/* JADX INFO: loaded from: classes.dex */
public class FileStorageMeta {
    public static final int META_BLOCK_SIZE = 4096;

    /* JADX INFO: renamed from: k */
    private static final char[] f1162k = "ReaperSDK".toCharArray();

    /* JADX INFO: renamed from: a */
    private long f1163a;

    /* JADX INFO: renamed from: b */
    private int f1164b;

    /* JADX INFO: renamed from: c */
    private int f1165c;

    /* JADX INFO: renamed from: d */
    private int f1166d;

    /* JADX INFO: renamed from: e */
    private ByteBuffer f1167e;

    /* JADX INFO: renamed from: f */
    private long f1168f;

    /* JADX INFO: renamed from: g */
    private long f1169g;

    /* JADX INFO: renamed from: h */
    private long f1170h;

    /* JADX INFO: renamed from: i */
    private int f1171i;

    /* JADX INFO: renamed from: j */
    private int f1172j;

    public FileStorageMeta(int capability) {
        this.f1163a = 0L;
        this.f1165c = 0;
        this.f1166d = 0;
        this.f1167e = ByteBuffer.allocate(4096);
        this.f1164b = capability;
    }

    public FileStorageMeta(int capability, int head, int tail, long sequence) {
        this.f1163a = 0L;
        this.f1165c = 0;
        this.f1166d = 0;
        this.f1167e = ByteBuffer.allocate(4096);
        this.f1164b = capability;
        this.f1165c = head;
        this.f1166d = tail;
        this.f1163a = sequence;
    }

    public int tail() {
        return this.f1166d;
    }

    public int head() {
        return this.f1165c;
    }

    public int offer() {
        this.f1165c = next(this.f1165c);
        if (this.f1165c == this.f1166d) {
            TLog.m243i("FileStorageMeta", "Drop record at " + this.f1166d);
            this.f1166d = next(this.f1166d);
        }
        return this.f1165c;
    }

    public int pull() {
        if (empty()) {
            return -1;
        }
        int result = this.f1166d;
        this.f1166d = next(this.f1166d);
        return result;
    }

    public ByteBuffer byteBuffer() {
        this.f1167e.clear();
        char[] arr$ = f1162k;
        for (char c : arr$) {
            Character c2 = Character.valueOf(c);
            this.f1167e.putChar(c2.charValue());
        }
        this.f1167e.putInt(1);
        this.f1167e.putInt(this.f1165c);
        this.f1167e.putInt(this.f1166d);
        this.f1167e.putInt(this.f1164b);
        this.f1167e.putLong(this.f1163a);
        this.f1167e.putInt(this.f1171i);
        this.f1167e.putLong(this.f1168f);
        this.f1167e.putLong(this.f1169g);
        this.f1167e.putLong(this.f1170h);
        this.f1167e.putInt(this.f1172j);
        this.f1167e.flip();
        return this.f1167e;
    }

    public boolean load(ByteBuffer buffer) {
        char[] cArr = new char[f1162k.length];
        for (int i = 0; i < f1162k.length; i++) {
            if (buffer.hasRemaining()) {
                cArr[i] = buffer.getChar();
            }
        }
        String flag = new String(cArr);
        if (!"ReaperSDK".equals(flag)) {
            reset();
            return false;
        }
        int version = buffer.getInt();
        if (version < 1) {
            upgrade(buffer, version, 1);
        }
        if (version == 1) {
            this.f1165c = buffer.getInt();
            this.f1166d = buffer.getInt();
            this.f1164b = buffer.getInt();
            this.f1163a = buffer.getLong();
            this.f1171i = buffer.getInt();
            this.f1168f = buffer.getLong();
            this.f1169g = buffer.getLong();
            this.f1170h = buffer.getLong();
            this.f1172j = buffer.getInt();
            TLog.m244v("FileStorageMeta", "CurrentTime:" + this.f1170h);
            TLog.m243i("FileStorageMeta", "Loading DB...");
            TLog.m244v("FileStorageMeta", "Head:" + this.f1165c);
            TLog.m244v("FileStorageMeta", "Tail:" + this.f1166d);
            TLog.m244v("FileStorageMeta", "Capability:" + this.f1164b);
            TLog.m244v("FileStorageMeta", "Sequence:" + this.f1163a);
            TLog.m244v("FileStorageMeta", "SessionID:" + this.f1171i);
            TLog.m244v("FileStorageMeta", "FirstView:" + this.f1168f);
            TLog.m244v("FileStorageMeta", "PreviousView:" + this.f1169g);
            TLog.m244v("FileStorageMeta", "visits:" + this.f1172j);
        }
        return true;
    }

    protected void upgrade(ByteBuffer buf, int fromVersion, int toVersion) {
    }

    public void reset() {
        this.f1163a = 0L;
        this.f1165c = 0;
        this.f1166d = 0;
    }

    public boolean empty() {
        return this.f1165c == this.f1166d;
    }

    public boolean full() {
        return next(this.f1165c) == this.f1166d;
    }

    public int next(int pointer) {
        int p = pointer + 1;
        if (p > this.f1164b) {
            return 0;
        }
        return p;
    }

    public int size() {
        return this.f1165c >= this.f1166d ? this.f1165c - this.f1166d : ((this.f1165c + this.f1164b) - this.f1166d) + 1;
    }

    public long nextId() {
        long j = this.f1163a + 1;
        this.f1163a = j;
        return j;
    }

    public long getFirstView() {
        return this.f1168f;
    }

    public void setFirstView(long firstView) {
        this.f1168f = firstView;
    }

    public long getPreviousView() {
        return this.f1169g;
    }

    public void setPreviousView(long previousView) {
        this.f1169g = previousView;
    }

    public long getCurrentTime() {
        return this.f1170h;
    }

    public void setCurrentTime(long currentTime) {
        this.f1170h = currentTime;
    }

    public int getSessionId() {
        return this.f1171i;
    }

    public void setSessionId(int sessionId) {
        this.f1171i = sessionId;
    }

    public int getSessionCounter() {
        return this.f1172j;
    }

    public void setSessionCounter(int sessionCounter) {
        this.f1172j = sessionCounter;
    }
}
