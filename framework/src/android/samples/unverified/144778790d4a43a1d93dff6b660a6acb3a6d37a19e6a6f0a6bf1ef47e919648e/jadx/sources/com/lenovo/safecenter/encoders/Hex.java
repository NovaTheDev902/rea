package com.lenovo.safecenter.encoders;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.OutputStream;

/* JADX INFO: loaded from: classes.dex */
public class Hex {

    /* JADX INFO: renamed from: a */
    private static final Encoder f3553a = new HexEncoder();

    public static byte[] encode(byte[] data) {
        return encode(data, 0, data.length);
    }

    public static byte[] encode(byte[] data, int off, int length) {
        ByteArrayOutputStream bOut = new ByteArrayOutputStream();
        try {
            f3553a.encode(data, off, length, bOut);
            return bOut.toByteArray();
        } catch (IOException e) {
            throw new RuntimeException("exception encoding Hex string: " + e);
        }
    }

    public static int encode(byte[] data, OutputStream out) throws IOException {
        return f3553a.encode(data, 0, data.length, out);
    }

    public static int encode(byte[] data, int off, int length, OutputStream out) throws IOException {
        return f3553a.encode(data, off, length, out);
    }

    public static byte[] decode(byte[] data) {
        ByteArrayOutputStream bOut = new ByteArrayOutputStream();
        try {
            f3553a.decode(data, 0, data.length, bOut);
            return bOut.toByteArray();
        } catch (IOException e) {
            throw new RuntimeException("exception decoding Hex string: " + e);
        }
    }

    public static byte[] decode(String data) {
        ByteArrayOutputStream bOut = new ByteArrayOutputStream();
        try {
            f3553a.decode(data, bOut);
            return bOut.toByteArray();
        } catch (IOException e) {
            throw new RuntimeException("exception decoding Hex string: " + e);
        }
    }

    public static int decode(String data, OutputStream out) throws IOException {
        return f3553a.decode(data, out);
    }
}
