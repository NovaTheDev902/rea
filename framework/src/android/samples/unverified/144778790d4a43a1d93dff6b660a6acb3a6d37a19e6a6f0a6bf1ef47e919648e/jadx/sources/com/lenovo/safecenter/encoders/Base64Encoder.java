package com.lenovo.safecenter.encoders;

import java.io.IOException;
import java.io.OutputStream;

/* JADX INFO: loaded from: classes.dex */
public class Base64Encoder implements Encoder {
    protected final byte[] encodingTable = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 43, 47};
    protected byte padding = 61;
    protected final byte[] decodingTable = new byte[128];

    protected final void initialiseDecodingTable() {
        for (int i = 0; i < this.encodingTable.length; i++) {
            this.decodingTable[this.encodingTable[i]] = (byte) i;
        }
    }

    public Base64Encoder() {
        initialiseDecodingTable();
    }

    @Override // com.lenovo.safecenter.encoders.Encoder
    public int encode(byte[] data, int off, int length, OutputStream out) throws IOException {
        int modulus = length % 3;
        int dataLength = length - modulus;
        for (int i = off; i < off + dataLength; i += 3) {
            int a1 = data[i] & 255;
            int a2 = data[i + 1] & 255;
            int a3 = data[i + 2] & 255;
            out.write(this.encodingTable[(a1 >>> 2) & 63]);
            out.write(this.encodingTable[((a1 << 4) | (a2 >>> 4)) & 63]);
            out.write(this.encodingTable[((a2 << 2) | (a3 >>> 6)) & 63]);
            out.write(this.encodingTable[a3 & 63]);
        }
        switch (modulus) {
            case 1:
                int d1 = data[off + dataLength] & 255;
                int b1 = (d1 >>> 2) & 63;
                int b2 = (d1 << 4) & 63;
                out.write(this.encodingTable[b1]);
                out.write(this.encodingTable[b2]);
                out.write(this.padding);
                out.write(this.padding);
                break;
            case 2:
                int d2 = data[off + dataLength] & 255;
                int d3 = data[off + dataLength + 1] & 255;
                int b3 = (d2 >>> 2) & 63;
                int b4 = ((d2 << 4) | (d3 >>> 4)) & 63;
                int b5 = (d3 << 2) & 63;
                out.write(this.encodingTable[b3]);
                out.write(this.encodingTable[b4]);
                out.write(this.encodingTable[b5]);
                out.write(this.padding);
                break;
        }
        return (modulus == 0 ? 0 : 4) + ((dataLength / 3) * 4);
    }

    /* JADX INFO: renamed from: a */
    private static boolean m1500a(char c) {
        return c == '\n' || c == '\r' || c == '\t' || c == ' ';
    }

    @Override // com.lenovo.safecenter.encoders.Encoder
    public int decode(byte[] data, int off, int length, OutputStream out) throws IOException {
        int outLen = 0;
        int end = off + length;
        while (end > off && m1500a((char) data[end - 1])) {
            end--;
        }
        int finish = end - 4;
        int i = m1499a(data, off, finish);
        int i2 = i;
        while (i2 < finish) {
            byte b1 = this.decodingTable[data[i2]];
            int i3 = m1499a(data, i2 + 1, finish);
            byte b2 = this.decodingTable[data[i3]];
            int i4 = m1499a(data, i3 + 1, finish);
            byte b3 = this.decodingTable[data[i4]];
            int i5 = m1499a(data, i4 + 1, finish);
            byte b4 = this.decodingTable[data[i5]];
            out.write((b1 << 2) | (b2 >> 4));
            out.write((b2 << 4) | (b3 >> 2));
            out.write((b3 << 6) | b4);
            outLen += 3;
            i2 = m1499a(data, i5 + 1, finish);
        }
        return outLen + m1497a(out, (char) data[end - 4], (char) data[end - 3], (char) data[end - 2], (char) data[end - 1]);
    }

    /* JADX INFO: renamed from: a */
    private static int m1499a(byte[] data, int i, int finish) {
        while (i < finish && m1500a((char) data[i])) {
            i++;
        }
        return i;
    }

    @Override // com.lenovo.safecenter.encoders.Encoder
    public int decode(String data, OutputStream out) throws IOException {
        int length = 0;
        int end = data.length();
        while (end > 0 && m1500a(data.charAt(end - 1))) {
            end--;
        }
        int finish = end - 4;
        int i = m1498a(data, 0, finish);
        int i2 = i;
        while (i2 < finish) {
            byte b1 = this.decodingTable[data.charAt(i2)];
            int i3 = m1498a(data, i2 + 1, finish);
            byte b2 = this.decodingTable[data.charAt(i3)];
            int i4 = m1498a(data, i3 + 1, finish);
            byte b3 = this.decodingTable[data.charAt(i4)];
            int i5 = m1498a(data, i4 + 1, finish);
            byte b4 = this.decodingTable[data.charAt(i5)];
            out.write((b1 << 2) | (b2 >> 4));
            out.write((b2 << 4) | (b3 >> 2));
            out.write((b3 << 6) | b4);
            length += 3;
            i2 = m1498a(data, i5 + 1, finish);
        }
        return length + m1497a(out, data.charAt(end - 4), data.charAt(end - 3), data.charAt(end - 2), data.charAt(end - 1));
    }

    /* JADX INFO: renamed from: a */
    private int m1497a(OutputStream out, char c1, char c2, char c3, char c4) throws IOException {
        if (c3 == this.padding) {
            byte b1 = this.decodingTable[c1];
            out.write((b1 << 2) | (this.decodingTable[c2] >> 4));
            return 1;
        }
        if (c4 == this.padding) {
            byte b2 = this.decodingTable[c1];
            byte b3 = this.decodingTable[c2];
            byte b4 = this.decodingTable[c3];
            out.write((b2 << 2) | (b3 >> 4));
            out.write((b3 << 4) | (b4 >> 2));
            return 2;
        }
        byte b5 = this.decodingTable[c1];
        byte b6 = this.decodingTable[c2];
        byte b7 = this.decodingTable[c3];
        byte b8 = this.decodingTable[c4];
        out.write((b5 << 2) | (b6 >> 4));
        out.write((b6 << 4) | (b7 >> 2));
        out.write((b7 << 6) | b8);
        return 3;
    }

    /* JADX INFO: renamed from: a */
    private static int m1498a(String data, int i, int finish) {
        while (i < finish && m1500a(data.charAt(i))) {
            i++;
        }
        return i;
    }
}
