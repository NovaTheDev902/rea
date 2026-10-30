package com.tencent.tmsecure.utils;

import QQPIM.ConfInfo;
import QQPIM.VirusClientInfo;
import android.content.Context;
import com.tencent.tccdb.RuleFileHeader;
import com.tencent.tccdb.SmsChecker;
import com.tencent.tmsecure.module.qscanner.AmScanner;
import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.concurrent.atomic.AtomicReference;
import tms.C1332r;

/* JADX INFO: loaded from: classes.dex */
public class UpdateUtil {

    /* JADX INFO: renamed from: a */
    private static final String f6298a = "UpdateUtil";

    /* JADX INFO: renamed from: a */
    private static byte[] m2644a(String str, int i, int i2) throws IOException {
        byte[] bArr = new byte[i2];
        RandomAccessFile randomAccessFile = new RandomAccessFile(str, "r");
        randomAccessFile.skipBytes(i);
        randomAccessFile.read(bArr);
        randomAccessFile.close();
        return bArr;
    }

    public static ConfInfo getFileConfInfo(String str) {
        try {
            byte[] bArrM2644a = m2644a(str, 0, 24);
            ConfInfo confInfo = new ConfInfo();
            byte[] bArr = new byte[4];
            System.arraycopy(bArrM2644a, 4, bArr, 0, 4);
            confInfo.setTimestamp(C1332r.m3552b(bArr));
            byte[] bArr2 = new byte[16];
            System.arraycopy(bArrM2644a, 8, bArr2, 0, 16);
            confInfo.setChecksum(C1332r.m3548a(bArr2));
            confInfo.setFilename(new File(str).getName());
            return confInfo;
        } catch (IOException e) {
            Log.m2636i(f6298a, e.getMessage());
            return null;
        }
    }

    public static ConfInfo getLocationConfInfo(String str) {
        try {
            byte[] bArrM2644a = m2644a(str, 0, 48);
            ConfInfo confInfo = new ConfInfo();
            confInfo.setVersion(bArrM2644a[0]);
            byte[] bArr = new byte[4];
            System.arraycopy(bArrM2644a, 4, bArr, 0, 4);
            confInfo.setTimestamp(C1332r.m3552b(bArr));
            byte[] bArr2 = new byte[16];
            System.arraycopy(bArrM2644a, 8, bArr2, 0, 16);
            confInfo.setChecksum(C1332r.m3548a(bArr2));
            byte[] bArr3 = new byte[4];
            System.arraycopy(bArrM2644a, 44, bArr3, 0, 4);
            confInfo.setPfutimestamp(C1332r.m3552b(bArr3));
            confInfo.setFilename(new File(str).getName());
            return confInfo;
        } catch (IOException e) {
            Log.m2636i(f6298a, e.getMessage());
            return null;
        }
    }

    public static ConfInfo getSmsCheckerConfInfo(Context context, String str) {
        File file = new File(str);
        if (file.exists()) {
            AtomicReference atomicReference = new AtomicReference();
            SmsChecker.getRuleFileHeader(context, atomicReference, str);
            RuleFileHeader ruleFileHeader = (RuleFileHeader) atomicReference.get();
            if (ruleFileHeader != null) {
                ConfInfo confInfo = new ConfInfo();
                confInfo.setFilename(file.getName());
                confInfo.setChecksum(ruleFileHeader.md5str);
                confInfo.setTimestamp(ruleFileHeader.time);
                return confInfo;
            }
        }
        return null;
    }

    public static VirusClientInfo getVirusClientInfo(Context context, String str) {
        if (new File(str).exists()) {
            return AmScanner.loadAmfHeader(context, str);
        }
        return null;
    }

    public static ConfInfo getVirusConfInfo(Context context, String str) {
        VirusClientInfo virusClientInfoLoadAmfHeader;
        File file = new File(str);
        if (!file.exists() || (virusClientInfoLoadAmfHeader = AmScanner.loadAmfHeader(context, str)) == null) {
            return null;
        }
        ConfInfo confInfo = new ConfInfo();
        confInfo.setFilename(file.getName());
        confInfo.setTimestamp(virusClientInfoLoadAmfHeader.timestamp);
        confInfo.setVersion(virusClientInfoLoadAmfHeader.version);
        return confInfo;
    }
}
