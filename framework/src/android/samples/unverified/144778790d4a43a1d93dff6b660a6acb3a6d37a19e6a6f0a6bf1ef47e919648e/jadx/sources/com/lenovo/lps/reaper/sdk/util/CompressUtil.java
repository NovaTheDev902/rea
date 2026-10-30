package com.lenovo.lps.reaper.sdk.util;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.zip.Deflater;

/* JADX INFO: loaded from: classes.dex */
public class CompressUtil {

    /* JADX INFO: renamed from: a */
    private static final String f1190a = CompressUtil.class.getName();

    public static final byte[] compress(byte[] data) {
        if (data == null) {
            return null;
        }
        if (data.length == 0) {
            return new byte[0];
        }
        Deflater compressor = new Deflater();
        compressor.setLevel(9);
        compressor.setInput(data);
        compressor.finish();
        ByteArrayOutputStream bos = new ByteArrayOutputStream(data.length);
        byte[] buf = new byte[1024];
        while (!compressor.finished()) {
            int count = compressor.deflate(buf);
            bos.write(buf, 0, count);
        }
        try {
            bos.close();
        } catch (IOException e) {
            TLog.m241e(f1190a, "exception when close output stream. " + e.getMessage());
        }
        compressor.end();
        return bos.toByteArray();
    }
}
