package com.lenovo.lps.reaper.sdk.storage;

import android.content.Context;
import android.os.Environment;
import com.lenovo.lps.reaper.sdk.util.TLog;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;

/* JADX INFO: loaded from: classes.dex */
public class FileStorage {

    /* JADX INFO: renamed from: a */
    private String f1158a;

    /* JADX INFO: renamed from: b */
    private Context f1159b;

    /* JADX INFO: renamed from: c */
    private RandomAccessFile f1160c;

    /* JADX INFO: renamed from: d */
    private FileChannel f1161d;

    public FileStorage(String fileName, Context context) {
        this.f1158a = fileName;
        this.f1159b = context;
    }

    public void initialize() throws FileNotFoundException {
        String dir = Environment.getDataDirectory() + "/data/" + this.f1159b.getPackageName() + "/files/";
        File file = new File(dir);
        if (!file.exists()) {
            file.mkdirs();
        }
        try {
            destroy();
            this.f1160c = new RandomAccessFile(new File(dir + this.f1158a), "rw");
        } catch (IOException e) {
            TLog.m241e("FileStorage", "Error to Close or Create DataFile. " + e.getMessage());
        }
        this.f1161d = this.f1160c.getChannel();
    }

    public void truncate(long size) throws IOException {
        this.f1161d.truncate(size);
    }

    public void destroy() {
        if (this.f1161d != null) {
            try {
                this.f1161d.close();
            } catch (IOException e) {
            }
        }
        if (this.f1160c != null) {
            try {
                this.f1160c.close();
            } catch (IOException e2) {
            }
        }
    }

    public void position(Long offset) throws IOException {
        this.f1161d.position(offset.longValue());
    }

    public int writeRecord(ByteBuffer buffer) throws IOException {
        int result = this.f1161d.write(buffer);
        return result;
    }

    public void readRecord(ByteBuffer buffer) throws IOException {
        buffer.clear();
        this.f1161d.read(buffer);
        buffer.flip();
    }

    public void flush() throws IOException {
        this.f1161d.force(true);
    }
}
