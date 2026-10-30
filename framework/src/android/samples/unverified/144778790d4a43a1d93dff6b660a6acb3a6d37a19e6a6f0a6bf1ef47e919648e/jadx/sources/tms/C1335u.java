package tms;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

/* JADX INFO: renamed from: tms.u */
/* JADX INFO: loaded from: classes.dex */
public class C1335u {
    /* JADX INFO: renamed from: a */
    public static int m3571a(byte[] bArr) {
        if (bArr.length != 4) {
            return 0;
        }
        return (bArr[0] & 255) | ((bArr[1] & 255) << 8) | ((bArr[2] & 255) << 16) | ((bArr[3] & 255) << 24);
    }

    /* JADX INFO: renamed from: a */
    public static C1334t m3572a(InputStream inputStream) {
        C1334t c1334t = new C1334t();
        byte[] bArr = new byte[4];
        try {
            inputStream.read(bArr);
            c1334t.m3566a(m3571a(bArr));
            inputStream.read(bArr);
            c1334t.m3569b(m3571a(bArr));
            byte[] bArr2 = new byte[16];
            inputStream.read(bArr2);
            c1334t.m3567a(bArr2);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return c1334t;
    }

    /* JADX INFO: renamed from: a */
    public static void m3573a(C1334t c1334t, OutputStream outputStream) {
        try {
            outputStream.write(m3574a(c1334t.m3565a()));
            outputStream.write(m3574a(c1334t.m3568b()));
            outputStream.write(c1334t.m3570c());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /* JADX INFO: renamed from: a */
    public static byte[] m3574a(int i) {
        return new byte[]{(byte) (i & 255), (byte) ((i >> 8) & 255), (byte) ((i >> 16) & 255), (byte) ((i >> 24) & 255)};
    }
}
