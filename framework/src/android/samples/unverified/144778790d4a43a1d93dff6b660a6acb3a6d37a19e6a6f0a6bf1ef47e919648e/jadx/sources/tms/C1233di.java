package tms;

import QQPIM.ConnectType;
import com.tencent.tmsecure.common.ErrorCode;
import com.tencent.tmsecure.exception.NetWorkException;
import com.tencent.tmsecure.module.networkload.NetworkLoadTask;
import com.tencent.tmsecure.module.networkload.NetworkloadProperties;
import com.tencent.tmsecure.utils.NetworkUtil;
import com.tencent.tmsecure.utils.WifiUtil;
import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.nio.channels.FileChannel;

/* JADX INFO: renamed from: tms.di */
/* JADX INFO: loaded from: classes.dex */
final class C1233di<T extends NetworkLoadTask> extends Thread {

    /* JADX INFO: renamed from: a */
    private static final short[] f7110a = {8, 64, 128};

    /* JADX INFO: renamed from: b */
    private T f7111b;

    /* JADX INFO: renamed from: f */
    private BinderC1252ea<T> f7115f;

    /* JADX INFO: renamed from: g */
    private String f7116g;

    /* JADX INFO: renamed from: i */
    private boolean f7118i;

    /* JADX INFO: renamed from: c */
    private int f7112c = 307200;

    /* JADX INFO: renamed from: d */
    private boolean f7113d = true;

    /* JADX INFO: renamed from: e */
    private C1339y f7114e = null;

    /* JADX INFO: renamed from: h */
    private byte[] f7117h = new byte[0];

    /* JADX INFO: renamed from: j */
    private byte f7119j = 0;

    public C1233di(T t, boolean z, String str) {
        this.f7111b = t;
        this.f7116g = str;
        this.f7118i = z;
    }

    /* JADX WARN: Code duplicated, block: B:117:0x0080 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:25:0x0089  */
    /* JADX INFO: renamed from: a */
    private void m3130a(FileOutputStream fileOutputStream) throws Throwable {
        BufferedInputStream bufferedInputStream;
        BufferedInputStream bufferedInputStream2 = null;
        long j = 0;
        try {
            try {
                byte[] bArr = new byte[f7110a[1] << 10];
                if (this.f7114e == null) {
                    this.f7114e = C1339y.m3623a((this.f7111b.mCurrentSize == 0 && this.f7111b.isOnChangeRetry && this.f7111b.mChangeUrl != null) ? this.f7111b.mChangeUrl : this.f7111b.mUrl);
                    this.f7114e.m3641c();
                }
                if (this.f7114e.m3644e() != 200) {
                    throw new NetWorkException(this.f7114e.m3644e() + ErrorCode.ERR_GET, "unbreakable download response code is not 200 error, but " + this.f7114e.m3644e());
                }
                BufferedInputStream bufferedInputStream3 = new BufferedInputStream(this.f7114e.m3643d(), bArr.length);
                try {
                    long jCurrentTimeMillis = System.currentTimeMillis();
                    long j2 = this.f7111b.mCurrentSize;
                    boolean z = NetworkUtil.getNetworkType() != ConnectType.CT_WIFI;
                    byte[] bArr2 = bArr;
                    int i = 0;
                    while (this.f7113d) {
                        int i2 = bufferedInputStream3.read(bArr2);
                        if (i2 <= 0) {
                            if (this.f7111b.mCurrentSize <= this.f7111b.mSize || this.f7111b.mSize <= 0) {
                                break;
                                break;
                            } else {
                                this.f7111b.mSize = this.f7111b.mCurrentSize;
                                break;
                            }
                        }
                        fileOutputStream.write(bArr2, 0, i2);
                        this.f7111b.mCurrentSize += (long) i2;
                        i += i2;
                        if (z) {
                            j += (long) i2;
                        }
                        if (this.f7111b.mSize == this.f7111b.mCurrentSize) {
                            this.f7111b.mProgress = 1.0f;
                            break;
                        }
                        if (this.f7111b.mSize > 0) {
                            this.f7111b.mProgress = this.f7111b.mCurrentSize / this.f7111b.mSize;
                            this.f7115f.m3110b(this.f7111b);
                        }
                        if (i > this.f7112c) {
                            long jCurrentTimeMillis2 = System.currentTimeMillis() - jCurrentTimeMillis;
                            if (jCurrentTimeMillis2 <= 0) {
                                jCurrentTimeMillis2 = 1;
                            }
                            int i3 = (int) ((this.f7111b.mCurrentSize - j2) / jCurrentTimeMillis2);
                            if (this.f7111b.mSpeed == 0) {
                                this.f7111b.mSpeed = i3;
                            } else {
                                this.f7111b.mSpeed = (this.f7111b.mSpeed + this.f7111b.mSpeed) / 2;
                            }
                            if (i3 < 33) {
                                if (bArr2.length != (f7110a[0] << 10)) {
                                    bArr2 = new byte[f7110a[0] << 10];
                                }
                            } else if (i3 < 65) {
                                if (bArr2.length != (f7110a[1] << 10)) {
                                    bArr2 = new byte[f7110a[1] << 10];
                                }
                            } else if (bArr2.length != (f7110a[2] << 10)) {
                                bArr2 = new byte[f7110a[2] << 10];
                            }
                            if (j > 0) {
                                NetworkloadProperties.updateSelfMobileDownloadBytes(NetworkloadProperties.getSelfMobileDownloadBytes() + j);
                                j = 0;
                            }
                            i = 0;
                        }
                    }
                    if (bufferedInputStream3 != null) {
                        try {
                            bufferedInputStream3.close();
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                    if (j > 0) {
                        NetworkloadProperties.updateSelfMobileDownloadBytes(NetworkloadProperties.getSelfMobileDownloadBytes() + j);
                    }
                } catch (NetWorkException e2) {
                    e = e2;
                    bufferedInputStream2 = bufferedInputStream3;
                    try {
                        throw e;
                    } catch (Throwable th) {
                        th = th;
                        bufferedInputStream = bufferedInputStream2;
                        if (bufferedInputStream != null) {
                            try {
                                bufferedInputStream.close();
                            } catch (Exception e3) {
                                e3.printStackTrace();
                            }
                        }
                        if (0 > 0) {
                            NetworkloadProperties.updateSelfMobileDownloadBytes(0 + NetworkloadProperties.getSelfMobileDownloadBytes());
                        }
                        throw th;
                    }
                } catch (UnsupportedEncodingException e4) {
                    e = e4;
                    throw new NetWorkException(-59, "unbreakable download unsupported encoding: " + e.getMessage());
                } catch (IOException e5) {
                    e = e5;
                    throw new NetWorkException(-7056, "unbreakable download IOException: " + e.getMessage());
                } catch (Exception e6) {
                    e = e6;
                    throw new NetWorkException(-2, "unbreakable download Exception: " + e.getMessage());
                }
            } catch (Throwable th2) {
                th = th2;
                if (bufferedInputStream != null) {
                    bufferedInputStream.close();
                }
                if (0 > 0) {
                    NetworkloadProperties.updateSelfMobileDownloadBytes(0 + NetworkloadProperties.getSelfMobileDownloadBytes());
                }
                throw th;
            }
        } catch (NetWorkException e7) {
            e = e7;
        } catch (UnsupportedEncodingException e8) {
            e = e8;
        } catch (IOException e9) {
            e = e9;
        } catch (Exception e10) {
            e = e10;
        } catch (Throwable th3) {
            th = th3;
            bufferedInputStream = null;
            if (bufferedInputStream != null) {
                bufferedInputStream.close();
            }
            if (0 > 0) {
                NetworkloadProperties.updateSelfMobileDownloadBytes(0 + NetworkloadProperties.getSelfMobileDownloadBytes());
            }
            throw th;
        }
    }

    /* JADX WARN: Code duplicated, block: B:142:0x036b  */
    /* JADX WARN: Code duplicated, block: B:146:0x03a2 A[Catch: all -> 0x00f6, TryCatch #13 {all -> 0x00f6, blocks: (B:3:0x0004, B:4:0x0010, B:6:0x0016, B:8:0x0022, B:10:0x0045, B:25:0x0072, B:27:0x008b, B:29:0x0093, B:31:0x009b, B:32:0x00a1, B:33:0x00bd, B:35:0x00c9, B:36:0x00f3, B:59:0x016c, B:62:0x0175, B:38:0x00f5, B:149:0x03c2, B:150:0x03f1, B:129:0x0305, B:132:0x0314, B:144:0x0372, B:145:0x03a1, B:146:0x03a2, B:147:0x03c0, B:55:0x0149, B:56:0x0167, B:50:0x0116, B:52:0x011f), top: B:201:0x0004 }] */
    /* JADX WARN: Code duplicated, block: B:190:0x047d A[PHI: r5
  0x047d: PHI (r5v42 int) = (r5v40 int), (r5v41 int), (r5v44 int) binds: [B:125:0x02f6, B:122:0x02df, B:86:0x01fe] A[DONT_GENERATE, DONT_INLINE]] */
    /* JADX WARN: Code duplicated, block: B:195:0x0314 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:199:0x00f9 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:214:0x0357 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:231:? A[RETURN, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:235:? A[SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:44:0x0102 A[ADDED_TO_REGION] */
    /* JADX WARN: Code duplicated, block: B:48:0x010d  */
    /* JADX INFO: renamed from: b */
    private void m3131b(FileOutputStream fileOutputStream) throws Throwable {
        long selfMobileDownloadBytes;
        byte b;
        FileOutputStream fileOutputStream2;
        long j;
        byte[] bArr;
        BufferedInputStream bufferedInputStream = null;
        long j2 = 0;
        try {
            try {
                boolean z = true;
                byte[] bArr2 = new byte[f7110a[1] << 10];
                int i = 1;
                while (this.f7113d && this.f7111b.mProgress != 1.0f) {
                    StringBuffer stringBuffer = new StringBuffer();
                    long j3 = this.f7111b.mCurrentSize;
                    long j4 = ((((long) i) * (1 * ((long) this.f7112c))) + j3) - 1;
                    if (j4 >= this.f7111b.mSize) {
                        j4 = this.f7111b.mSize - 1;
                    }
                    if (j3 >= j4) {
                        break;
                    }
                    stringBuffer.append("bytes=").append(j3).append('-').append(j4);
                    if (this.f7114e == null) {
                        this.f7114e = C1339y.m3623a((!this.f7111b.isOnChangeRetry || this.f7111b.mChangeUrl == null) ? this.f7111b.mUrl : this.f7111b.mChangeUrl);
                        this.f7114e.m3635a("Range", stringBuffer.toString());
                        this.f7114e.m3641c();
                    } else if (!z) {
                        this.f7114e.m3645f();
                        this.f7114e = C1339y.m3624a(this.f7114e);
                        this.f7114e.m3635a("Range", stringBuffer.toString());
                        this.f7114e.m3641c();
                    }
                    if (this.f7114e.m3644e() != 206) {
                        throw new NetWorkException(this.f7114e.m3644e() + ErrorCode.ERR_GET, "breakable download response code is not 206 error, but " + this.f7114e.m3644e());
                    }
                    boolean z2 = z ? false : z;
                    boolean z3 = NetworkUtil.getNetworkType() != ConnectType.CT_WIFI;
                    BufferedInputStream bufferedInputStream2 = new BufferedInputStream(this.f7114e.m3643d(), bArr2.length);
                    try {
                        try {
                            long jCurrentTimeMillis = System.currentTimeMillis();
                            while (true) {
                                if (this.f7113d) {
                                    int i2 = bufferedInputStream2.read(bArr2);
                                    if (i2 <= 0) {
                                        if (this.f7111b.mCurrentSize > this.f7111b.mSize && this.f7111b.mSize > 0) {
                                            this.f7111b.mSize = this.f7111b.mCurrentSize;
                                            this.f7111b.mProgress = 1.0f;
                                            j = j2;
                                            break;
                                        }
                                        break;
                                    }
                                    try {
                                        fileOutputStream.write(bArr2, 0, i2);
                                        fileOutputStream.flush();
                                        this.f7111b.mCurrentSize += (long) i2;
                                        if (z3) {
                                            j2 += (long) i2;
                                        }
                                        if (this.f7111b.mSize == this.f7111b.mCurrentSize) {
                                            this.f7111b.mProgress = 1.0f;
                                            j = j2;
                                            break;
                                        } else {
                                            this.f7111b.mProgress = this.f7111b.mCurrentSize / this.f7111b.mSize;
                                            this.f7115f.m3110b(this.f7111b);
                                        }
                                    } catch (IOException e) {
                                        throw new NetWorkException(-7056, "breakable download write file IOException:" + e.getMessage());
                                    }
                                }
                                j = j2;
                                break;
                            }
                            if (bufferedInputStream2 != null) {
                                try {
                                    try {
                                        bufferedInputStream2.close();
                                    } catch (Exception e2) {
                                        try {
                                            e2.printStackTrace();
                                        } catch (Exception e3) {
                                            e = e3;
                                            throw new NetWorkException(-2, "breakable download Exception " + e.getClass().getName() + " :" + e.getMessage());
                                        }
                                    }
                                    bufferedInputStream = null;
                                } catch (NetWorkException e4) {
                                    throw e4;
                                } catch (UnsupportedEncodingException e5) {
                                    e = e5;
                                    throw new NetWorkException(-59, "breakable download UnsupportedEncodingException encoding: " + e.getMessage());
                                } catch (IOException e6) {
                                    bufferedInputStream = bufferedInputStream2;
                                    long j5 = j;
                                    e = e6;
                                    j2 = j5;
                                    b = this.f7119j;
                                    this.f7119j = (byte) (b + 1);
                                    if (b < 10) {
                                        throw new NetWorkException(-7056, "breakable download IOException: " + e.getMessage());
                                    }
                                    try {
                                        fileOutputStream.flush();
                                        fileOutputStream.close();
                                        this.f7114e.m3645f();
                                        this.f7114e = null;
                                        this.f7111b.mCurrentSize = new File(this.f7116g).length();
                                        fileOutputStream2 = new FileOutputStream(this.f7116g, true);
                                        try {
                                            fileOutputStream2.getChannel().position(this.f7111b.mCurrentSize);
                                            m3131b(fileOutputStream2);
                                            if (bufferedInputStream != null) {
                                                try {
                                                    bufferedInputStream.close();
                                                } catch (Exception e7) {
                                                    e7.printStackTrace();
                                                }
                                            }
                                            if (this.f7119j > 0 && fileOutputStream2 != null) {
                                                try {
                                                    fileOutputStream2.close();
                                                } catch (IOException e8) {
                                                    e8.printStackTrace();
                                                }
                                            }
                                            if (j2 > 0) {
                                                selfMobileDownloadBytes = NetworkloadProperties.getSelfMobileDownloadBytes();
                                                NetworkloadProperties.updateSelfMobileDownloadBytes(selfMobileDownloadBytes + j2);
                                            }
                                            return;
                                        } catch (IOException e9) {
                                            e = e9;
                                            e.printStackTrace();
                                            throw new NetWorkException(-7056, "breakable download IOException on try " + ((int) this.f7119j) + " IOException:" + e.getMessage());
                                        } catch (Throwable th) {
                                            th = th;
                                            fileOutputStream = fileOutputStream2;
                                            if (bufferedInputStream != null) {
                                                try {
                                                    bufferedInputStream.close();
                                                } catch (Exception e10) {
                                                    e10.printStackTrace();
                                                }
                                            }
                                            if (this.f7119j > 0 && fileOutputStream != null) {
                                                try {
                                                    fileOutputStream.close();
                                                } catch (IOException e11) {
                                                    e11.printStackTrace();
                                                }
                                            }
                                            if (j2 <= 0) {
                                                throw th;
                                            }
                                            NetworkloadProperties.updateSelfMobileDownloadBytes(j2 + NetworkloadProperties.getSelfMobileDownloadBytes());
                                            throw th;
                                        }
                                    } catch (IOException e12) {
                                        e = e12;
                                    }
                                } catch (Throwable th2) {
                                    bufferedInputStream = bufferedInputStream2;
                                    long j6 = j;
                                    th = th2;
                                    j2 = j6;
                                    if (bufferedInputStream != null) {
                                        bufferedInputStream.close();
                                    }
                                    if (this.f7119j > 0) {
                                        fileOutputStream.close();
                                    }
                                    if (j2 <= 0) {
                                        throw th;
                                    }
                                    NetworkloadProperties.updateSelfMobileDownloadBytes(j2 + NetworkloadProperties.getSelfMobileDownloadBytes());
                                    throw th;
                                }
                            } else {
                                bufferedInputStream = bufferedInputStream2;
                            }
                            try {
                                long jCurrentTimeMillis2 = System.currentTimeMillis() - jCurrentTimeMillis;
                                if (jCurrentTimeMillis2 <= 0) {
                                    jCurrentTimeMillis2 = 1;
                                }
                                int i3 = (int) ((this.f7111b.mCurrentSize - j3) / jCurrentTimeMillis2);
                                if (this.f7111b.mSpeed == 0) {
                                    this.f7111b.mSpeed = i3;
                                } else {
                                    this.f7111b.mSpeed = (this.f7111b.mSpeed + this.f7111b.mSpeed) / 2;
                                }
                                if (i3 < 33) {
                                    i = 1;
                                    if (bArr2.length != (f7110a[0] << 10)) {
                                        bArr = new byte[f7110a[0] << 10];
                                    } else {
                                        bArr = bArr2;
                                    }
                                } else if (i3 < 65) {
                                    i = 2;
                                    if (bArr2.length != (f7110a[1] << 10)) {
                                        bArr = new byte[f7110a[1] << 10];
                                    } else {
                                        bArr = bArr2;
                                    }
                                } else {
                                    i = 3;
                                    if (bArr2.length != (f7110a[2] << 10)) {
                                        bArr = new byte[f7110a[2] << 10];
                                    } else {
                                        bArr = bArr2;
                                    }
                                }
                                if (j > 0) {
                                    NetworkloadProperties.updateSelfMobileDownloadBytes(NetworkloadProperties.getSelfMobileDownloadBytes() + j);
                                    j = 0;
                                }
                                bArr2 = bArr;
                                j2 = j;
                                z = z2;
                            } catch (NetWorkException e13) {
                                throw e13;
                            } catch (UnsupportedEncodingException e14) {
                                e = e14;
                                throw new NetWorkException(-59, "breakable download UnsupportedEncodingException encoding: " + e.getMessage());
                            } catch (IOException e15) {
                                j2 = j;
                                e = e15;
                                b = this.f7119j;
                                this.f7119j = (byte) (b + 1);
                                if (b < 10) {
                                    throw new NetWorkException(-7056, "breakable download IOException: " + e.getMessage());
                                }
                                fileOutputStream.flush();
                                fileOutputStream.close();
                                this.f7114e.m3645f();
                                this.f7114e = null;
                                this.f7111b.mCurrentSize = new File(this.f7116g).length();
                                fileOutputStream2 = new FileOutputStream(this.f7116g, true);
                                fileOutputStream2.getChannel().position(this.f7111b.mCurrentSize);
                                m3131b(fileOutputStream2);
                                if (bufferedInputStream != null) {
                                    bufferedInputStream.close();
                                }
                                if (this.f7119j > 0) {
                                    fileOutputStream2.close();
                                }
                                if (j2 > 0) {
                                    selfMobileDownloadBytes = NetworkloadProperties.getSelfMobileDownloadBytes();
                                    NetworkloadProperties.updateSelfMobileDownloadBytes(selfMobileDownloadBytes + j2);
                                }
                                return;
                            } catch (Exception e16) {
                                e = e16;
                                throw new NetWorkException(-2, "breakable download Exception " + e.getClass().getName() + " :" + e.getMessage());
                            } catch (Throwable th3) {
                                j2 = j;
                                th = th3;
                                if (bufferedInputStream != null) {
                                    bufferedInputStream.close();
                                }
                                if (this.f7119j > 0) {
                                    fileOutputStream.close();
                                }
                                if (j2 <= 0) {
                                    throw th;
                                }
                                NetworkloadProperties.updateSelfMobileDownloadBytes(j2 + NetworkloadProperties.getSelfMobileDownloadBytes());
                                throw th;
                            }
                        } catch (IOException e17) {
                            e = e17;
                            bufferedInputStream = bufferedInputStream2;
                        }
                    } catch (NetWorkException e18) {
                        throw e18;
                    } catch (UnsupportedEncodingException e19) {
                        e = e19;
                    } catch (Exception e20) {
                        e = e20;
                    } catch (Throwable th4) {
                        th = th4;
                        bufferedInputStream = bufferedInputStream2;
                    }
                }
                if (bufferedInputStream != null) {
                    try {
                        bufferedInputStream.close();
                    } catch (Exception e21) {
                        e21.printStackTrace();
                    }
                }
                if (this.f7119j > 0 && fileOutputStream != null) {
                    try {
                        fileOutputStream.close();
                    } catch (IOException e22) {
                        e22.printStackTrace();
                    }
                }
                if (j2 > 0) {
                    selfMobileDownloadBytes = NetworkloadProperties.getSelfMobileDownloadBytes();
                    NetworkloadProperties.updateSelfMobileDownloadBytes(selfMobileDownloadBytes + j2);
                }
            } catch (Throwable th5) {
                th = th5;
            }
        } catch (NetWorkException e23) {
            throw e23;
        } catch (UnsupportedEncodingException e24) {
            e = e24;
        } catch (IOException e25) {
            e = e25;
        } catch (Exception e26) {
            e = e26;
        }
    }

    /* JADX INFO: renamed from: a */
    final void m3132a() {
        this.f7113d = false;
        interrupt();
        if (this.f7114e != null) {
            try {
                this.f7114e.m3645f();
                this.f7114e = null;
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    /* JADX INFO: renamed from: a */
    final void m3133a(BinderC1252ea<T> binderC1252ea) {
        this.f7115f = binderC1252ea;
    }

    /* JADX WARN: Code duplicated, block: B:167:0x03d1 A[DONT_INVERT] */
    /* JADX WARN: Code duplicated, block: B:171:0x03dd A[Catch: all -> 0x021b, TryCatch #18 {, blocks: (B:4:0x0006, B:12:0x0050, B:14:0x0055, B:15:0x005b, B:17:0x005f, B:19:0x0069, B:21:0x0075, B:23:0x007d, B:25:0x0096, B:26:0x00a0, B:240:0x0562, B:27:0x00a7, B:29:0x00ab, B:30:0x00b3, B:239:0x055d, B:237:0x0557, B:66:0x01b5, B:68:0x01ba, B:69:0x01c0, B:71:0x01c4, B:73:0x01ce, B:75:0x01da, B:77:0x01e2, B:79:0x01fb, B:80:0x0205, B:245:0x0576, B:81:0x020c, B:83:0x0210, B:84:0x0218, B:244:0x0571, B:242:0x056b, B:105:0x0279, B:107:0x027e, B:108:0x0284, B:110:0x0288, B:112:0x0292, B:114:0x029e, B:116:0x02a6, B:118:0x02bf, B:119:0x02c9, B:225:0x0527, B:120:0x02d0, B:122:0x02d4, B:224:0x0522, B:222:0x051c, B:136:0x034b, B:138:0x0350, B:139:0x0356, B:141:0x035a, B:143:0x0364, B:145:0x0370, B:147:0x0378, B:149:0x0391, B:150:0x039b, B:230:0x053b, B:151:0x03a2, B:153:0x03a6, B:229:0x0536, B:227:0x0530, B:166:0x03ce, B:168:0x03d3, B:169:0x03d9, B:171:0x03dd, B:173:0x03e7, B:175:0x03f3, B:177:0x03fb, B:179:0x0414, B:180:0x041e, B:220:0x0513, B:181:0x0425, B:183:0x0429, B:184:0x0431, B:219:0x050e, B:217:0x0508, B:195:0x049b, B:197:0x04a0, B:198:0x04a6, B:200:0x04aa, B:202:0x04b4, B:204:0x04c0, B:206:0x04c8, B:208:0x04e1, B:209:0x04eb, B:235:0x054f, B:210:0x04f2, B:212:0x04f6, B:234:0x054a, B:232:0x0544), top: B:272:0x0006, inners: #1, #2, #3, #4, #6, #8, #9, #10, #15, #17, #19, #22 }] */
    /* JADX WARN: Code duplicated, block: B:179:0x0414 A[Catch: all -> 0x021b, TryCatch #18 {, blocks: (B:4:0x0006, B:12:0x0050, B:14:0x0055, B:15:0x005b, B:17:0x005f, B:19:0x0069, B:21:0x0075, B:23:0x007d, B:25:0x0096, B:26:0x00a0, B:240:0x0562, B:27:0x00a7, B:29:0x00ab, B:30:0x00b3, B:239:0x055d, B:237:0x0557, B:66:0x01b5, B:68:0x01ba, B:69:0x01c0, B:71:0x01c4, B:73:0x01ce, B:75:0x01da, B:77:0x01e2, B:79:0x01fb, B:80:0x0205, B:245:0x0576, B:81:0x020c, B:83:0x0210, B:84:0x0218, B:244:0x0571, B:242:0x056b, B:105:0x0279, B:107:0x027e, B:108:0x0284, B:110:0x0288, B:112:0x0292, B:114:0x029e, B:116:0x02a6, B:118:0x02bf, B:119:0x02c9, B:225:0x0527, B:120:0x02d0, B:122:0x02d4, B:224:0x0522, B:222:0x051c, B:136:0x034b, B:138:0x0350, B:139:0x0356, B:141:0x035a, B:143:0x0364, B:145:0x0370, B:147:0x0378, B:149:0x0391, B:150:0x039b, B:230:0x053b, B:151:0x03a2, B:153:0x03a6, B:229:0x0536, B:227:0x0530, B:166:0x03ce, B:168:0x03d3, B:169:0x03d9, B:171:0x03dd, B:173:0x03e7, B:175:0x03f3, B:177:0x03fb, B:179:0x0414, B:180:0x041e, B:220:0x0513, B:181:0x0425, B:183:0x0429, B:184:0x0431, B:219:0x050e, B:217:0x0508, B:195:0x049b, B:197:0x04a0, B:198:0x04a6, B:200:0x04aa, B:202:0x04b4, B:204:0x04c0, B:206:0x04c8, B:208:0x04e1, B:209:0x04eb, B:235:0x054f, B:210:0x04f2, B:212:0x04f6, B:234:0x054a, B:232:0x0544), top: B:272:0x0006, inners: #1, #2, #3, #4, #6, #8, #9, #10, #15, #17, #19, #22 }] */
    /* JADX WARN: Code duplicated, block: B:183:0x0429 A[Catch: all -> 0x021b, TryCatch #18 {, blocks: (B:4:0x0006, B:12:0x0050, B:14:0x0055, B:15:0x005b, B:17:0x005f, B:19:0x0069, B:21:0x0075, B:23:0x007d, B:25:0x0096, B:26:0x00a0, B:240:0x0562, B:27:0x00a7, B:29:0x00ab, B:30:0x00b3, B:239:0x055d, B:237:0x0557, B:66:0x01b5, B:68:0x01ba, B:69:0x01c0, B:71:0x01c4, B:73:0x01ce, B:75:0x01da, B:77:0x01e2, B:79:0x01fb, B:80:0x0205, B:245:0x0576, B:81:0x020c, B:83:0x0210, B:84:0x0218, B:244:0x0571, B:242:0x056b, B:105:0x0279, B:107:0x027e, B:108:0x0284, B:110:0x0288, B:112:0x0292, B:114:0x029e, B:116:0x02a6, B:118:0x02bf, B:119:0x02c9, B:225:0x0527, B:120:0x02d0, B:122:0x02d4, B:224:0x0522, B:222:0x051c, B:136:0x034b, B:138:0x0350, B:139:0x0356, B:141:0x035a, B:143:0x0364, B:145:0x0370, B:147:0x0378, B:149:0x0391, B:150:0x039b, B:230:0x053b, B:151:0x03a2, B:153:0x03a6, B:229:0x0536, B:227:0x0530, B:166:0x03ce, B:168:0x03d3, B:169:0x03d9, B:171:0x03dd, B:173:0x03e7, B:175:0x03f3, B:177:0x03fb, B:179:0x0414, B:180:0x041e, B:220:0x0513, B:181:0x0425, B:183:0x0429, B:184:0x0431, B:219:0x050e, B:217:0x0508, B:195:0x049b, B:197:0x04a0, B:198:0x04a6, B:200:0x04aa, B:202:0x04b4, B:204:0x04c0, B:206:0x04c8, B:208:0x04e1, B:209:0x04eb, B:235:0x054f, B:210:0x04f2, B:212:0x04f6, B:234:0x054a, B:232:0x0544), top: B:272:0x0006, inners: #1, #2, #3, #4, #6, #8, #9, #10, #15, #17, #19, #22 }] */
    /* JADX WARN: Code duplicated, block: B:220:0x0513 A[Catch: all -> 0x021b, TryCatch #18 {, blocks: (B:4:0x0006, B:12:0x0050, B:14:0x0055, B:15:0x005b, B:17:0x005f, B:19:0x0069, B:21:0x0075, B:23:0x007d, B:25:0x0096, B:26:0x00a0, B:240:0x0562, B:27:0x00a7, B:29:0x00ab, B:30:0x00b3, B:239:0x055d, B:237:0x0557, B:66:0x01b5, B:68:0x01ba, B:69:0x01c0, B:71:0x01c4, B:73:0x01ce, B:75:0x01da, B:77:0x01e2, B:79:0x01fb, B:80:0x0205, B:245:0x0576, B:81:0x020c, B:83:0x0210, B:84:0x0218, B:244:0x0571, B:242:0x056b, B:105:0x0279, B:107:0x027e, B:108:0x0284, B:110:0x0288, B:112:0x0292, B:114:0x029e, B:116:0x02a6, B:118:0x02bf, B:119:0x02c9, B:225:0x0527, B:120:0x02d0, B:122:0x02d4, B:224:0x0522, B:222:0x051c, B:136:0x034b, B:138:0x0350, B:139:0x0356, B:141:0x035a, B:143:0x0364, B:145:0x0370, B:147:0x0378, B:149:0x0391, B:150:0x039b, B:230:0x053b, B:151:0x03a2, B:153:0x03a6, B:229:0x0536, B:227:0x0530, B:166:0x03ce, B:168:0x03d3, B:169:0x03d9, B:171:0x03dd, B:173:0x03e7, B:175:0x03f3, B:177:0x03fb, B:179:0x0414, B:180:0x041e, B:220:0x0513, B:181:0x0425, B:183:0x0429, B:184:0x0431, B:219:0x050e, B:217:0x0508, B:195:0x049b, B:197:0x04a0, B:198:0x04a6, B:200:0x04aa, B:202:0x04b4, B:204:0x04c0, B:206:0x04c8, B:208:0x04e1, B:209:0x04eb, B:235:0x054f, B:210:0x04f2, B:212:0x04f6, B:234:0x054a, B:232:0x0544), top: B:272:0x0006, inners: #1, #2, #3, #4, #6, #8, #9, #10, #15, #17, #19, #22 }] */
    /* JADX WARN: Code duplicated, block: B:240:0x0562 A[Catch: all -> 0x021b, TryCatch #18 {, blocks: (B:4:0x0006, B:12:0x0050, B:14:0x0055, B:15:0x005b, B:17:0x005f, B:19:0x0069, B:21:0x0075, B:23:0x007d, B:25:0x0096, B:26:0x00a0, B:240:0x0562, B:27:0x00a7, B:29:0x00ab, B:30:0x00b3, B:239:0x055d, B:237:0x0557, B:66:0x01b5, B:68:0x01ba, B:69:0x01c0, B:71:0x01c4, B:73:0x01ce, B:75:0x01da, B:77:0x01e2, B:79:0x01fb, B:80:0x0205, B:245:0x0576, B:81:0x020c, B:83:0x0210, B:84:0x0218, B:244:0x0571, B:242:0x056b, B:105:0x0279, B:107:0x027e, B:108:0x0284, B:110:0x0288, B:112:0x0292, B:114:0x029e, B:116:0x02a6, B:118:0x02bf, B:119:0x02c9, B:225:0x0527, B:120:0x02d0, B:122:0x02d4, B:224:0x0522, B:222:0x051c, B:136:0x034b, B:138:0x0350, B:139:0x0356, B:141:0x035a, B:143:0x0364, B:145:0x0370, B:147:0x0378, B:149:0x0391, B:150:0x039b, B:230:0x053b, B:151:0x03a2, B:153:0x03a6, B:229:0x0536, B:227:0x0530, B:166:0x03ce, B:168:0x03d3, B:169:0x03d9, B:171:0x03dd, B:173:0x03e7, B:175:0x03f3, B:177:0x03fb, B:179:0x0414, B:180:0x041e, B:220:0x0513, B:181:0x0425, B:183:0x0429, B:184:0x0431, B:219:0x050e, B:217:0x0508, B:195:0x049b, B:197:0x04a0, B:198:0x04a6, B:200:0x04aa, B:202:0x04b4, B:204:0x04c0, B:206:0x04c8, B:208:0x04e1, B:209:0x04eb, B:235:0x054f, B:210:0x04f2, B:212:0x04f6, B:234:0x054a, B:232:0x0544), top: B:272:0x0006, inners: #1, #2, #3, #4, #6, #8, #9, #10, #15, #17, #19, #22 }] */
    /* JADX WARN: Code duplicated, block: B:25:0x0096 A[Catch: all -> 0x021b, TryCatch #18 {, blocks: (B:4:0x0006, B:12:0x0050, B:14:0x0055, B:15:0x005b, B:17:0x005f, B:19:0x0069, B:21:0x0075, B:23:0x007d, B:25:0x0096, B:26:0x00a0, B:240:0x0562, B:27:0x00a7, B:29:0x00ab, B:30:0x00b3, B:239:0x055d, B:237:0x0557, B:66:0x01b5, B:68:0x01ba, B:69:0x01c0, B:71:0x01c4, B:73:0x01ce, B:75:0x01da, B:77:0x01e2, B:79:0x01fb, B:80:0x0205, B:245:0x0576, B:81:0x020c, B:83:0x0210, B:84:0x0218, B:244:0x0571, B:242:0x056b, B:105:0x0279, B:107:0x027e, B:108:0x0284, B:110:0x0288, B:112:0x0292, B:114:0x029e, B:116:0x02a6, B:118:0x02bf, B:119:0x02c9, B:225:0x0527, B:120:0x02d0, B:122:0x02d4, B:224:0x0522, B:222:0x051c, B:136:0x034b, B:138:0x0350, B:139:0x0356, B:141:0x035a, B:143:0x0364, B:145:0x0370, B:147:0x0378, B:149:0x0391, B:150:0x039b, B:230:0x053b, B:151:0x03a2, B:153:0x03a6, B:229:0x0536, B:227:0x0530, B:166:0x03ce, B:168:0x03d3, B:169:0x03d9, B:171:0x03dd, B:173:0x03e7, B:175:0x03f3, B:177:0x03fb, B:179:0x0414, B:180:0x041e, B:220:0x0513, B:181:0x0425, B:183:0x0429, B:184:0x0431, B:219:0x050e, B:217:0x0508, B:195:0x049b, B:197:0x04a0, B:198:0x04a6, B:200:0x04aa, B:202:0x04b4, B:204:0x04c0, B:206:0x04c8, B:208:0x04e1, B:209:0x04eb, B:235:0x054f, B:210:0x04f2, B:212:0x04f6, B:234:0x054a, B:232:0x0544), top: B:272:0x0006, inners: #1, #2, #3, #4, #6, #8, #9, #10, #15, #17, #19, #22 }] */
    /* JADX WARN: Code duplicated, block: B:260:0x03d3 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:266:0x03ce A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:275:0x0055 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:281:? A[Catch: all -> 0x021b, SYNTHETIC, TRY_LEAVE, TryCatch #18 {, blocks: (B:4:0x0006, B:12:0x0050, B:14:0x0055, B:15:0x005b, B:17:0x005f, B:19:0x0069, B:21:0x0075, B:23:0x007d, B:25:0x0096, B:26:0x00a0, B:240:0x0562, B:27:0x00a7, B:29:0x00ab, B:30:0x00b3, B:239:0x055d, B:237:0x0557, B:66:0x01b5, B:68:0x01ba, B:69:0x01c0, B:71:0x01c4, B:73:0x01ce, B:75:0x01da, B:77:0x01e2, B:79:0x01fb, B:80:0x0205, B:245:0x0576, B:81:0x020c, B:83:0x0210, B:84:0x0218, B:244:0x0571, B:242:0x056b, B:105:0x0279, B:107:0x027e, B:108:0x0284, B:110:0x0288, B:112:0x0292, B:114:0x029e, B:116:0x02a6, B:118:0x02bf, B:119:0x02c9, B:225:0x0527, B:120:0x02d0, B:122:0x02d4, B:224:0x0522, B:222:0x051c, B:136:0x034b, B:138:0x0350, B:139:0x0356, B:141:0x035a, B:143:0x0364, B:145:0x0370, B:147:0x0378, B:149:0x0391, B:150:0x039b, B:230:0x053b, B:151:0x03a2, B:153:0x03a6, B:229:0x0536, B:227:0x0530, B:166:0x03ce, B:168:0x03d3, B:169:0x03d9, B:171:0x03dd, B:173:0x03e7, B:175:0x03f3, B:177:0x03fb, B:179:0x0414, B:180:0x041e, B:220:0x0513, B:181:0x0425, B:183:0x0429, B:184:0x0431, B:219:0x050e, B:217:0x0508, B:195:0x049b, B:197:0x04a0, B:198:0x04a6, B:200:0x04aa, B:202:0x04b4, B:204:0x04c0, B:206:0x04c8, B:208:0x04e1, B:209:0x04eb, B:235:0x054f, B:210:0x04f2, B:212:0x04f6, B:234:0x054a, B:232:0x0544), top: B:272:0x0006, inners: #1, #2, #3, #4, #6, #8, #9, #10, #15, #17, #19, #22 }] */
    /* JADX WARN: Code duplicated, block: B:29:0x00ab A[Catch: all -> 0x021b, TryCatch #18 {, blocks: (B:4:0x0006, B:12:0x0050, B:14:0x0055, B:15:0x005b, B:17:0x005f, B:19:0x0069, B:21:0x0075, B:23:0x007d, B:25:0x0096, B:26:0x00a0, B:240:0x0562, B:27:0x00a7, B:29:0x00ab, B:30:0x00b3, B:239:0x055d, B:237:0x0557, B:66:0x01b5, B:68:0x01ba, B:69:0x01c0, B:71:0x01c4, B:73:0x01ce, B:75:0x01da, B:77:0x01e2, B:79:0x01fb, B:80:0x0205, B:245:0x0576, B:81:0x020c, B:83:0x0210, B:84:0x0218, B:244:0x0571, B:242:0x056b, B:105:0x0279, B:107:0x027e, B:108:0x0284, B:110:0x0288, B:112:0x0292, B:114:0x029e, B:116:0x02a6, B:118:0x02bf, B:119:0x02c9, B:225:0x0527, B:120:0x02d0, B:122:0x02d4, B:224:0x0522, B:222:0x051c, B:136:0x034b, B:138:0x0350, B:139:0x0356, B:141:0x035a, B:143:0x0364, B:145:0x0370, B:147:0x0378, B:149:0x0391, B:150:0x039b, B:230:0x053b, B:151:0x03a2, B:153:0x03a6, B:229:0x0536, B:227:0x0530, B:166:0x03ce, B:168:0x03d3, B:169:0x03d9, B:171:0x03dd, B:173:0x03e7, B:175:0x03f3, B:177:0x03fb, B:179:0x0414, B:180:0x041e, B:220:0x0513, B:181:0x0425, B:183:0x0429, B:184:0x0431, B:219:0x050e, B:217:0x0508, B:195:0x049b, B:197:0x04a0, B:198:0x04a6, B:200:0x04aa, B:202:0x04b4, B:204:0x04c0, B:206:0x04c8, B:208:0x04e1, B:209:0x04eb, B:235:0x054f, B:210:0x04f2, B:212:0x04f6, B:234:0x054a, B:232:0x0544), top: B:272:0x0006, inners: #1, #2, #3, #4, #6, #8, #9, #10, #15, #17, #19, #22 }] */
    /* JADX WARN: Multi-variable type inference failed */
    @Override // java.lang.Thread, java.lang.Runnable
    public final void run() {
        FileOutputStream fileOutputStream;
        FileChannel channel = null;
        synchronized (this.f7117h) {
            this.f7111b.mNetworkType = NetworkUtil.getNetworkType();
            this.f7111b.mNetworkName = NetworkUtil.getNetworkName();
            FileOutputStream fileOutputStream2 = null;
            FileOutputStream fileOutputStream3 = null;
            Object[] objArr = 0;
            try {
                try {
                    try {
                        if (this.f7111b.mCurrentSize == this.f7111b.mSize && this.f7111b.mCurrentSize > 0) {
                            this.f7111b.mState = 3;
                            this.f7111b.mErrorCode = 0;
                            this.f7111b.mErrorMsg = "";
                            this.f7111b.mErrorRssi = -1;
                            this.f7111b.mProgress = 1.0f;
                            this.f7115f.m3108a(this.f7111b);
                            if (0 == 0) {
                                if (0 != 0) {
                                    fileOutputStream2.flush();
                                    fileOutputStream2.close();
                                }
                                if (!this.f7113d) {
                                    this.f7111b.mState = 3;
                                    this.f7111b.mErrorCode = 0;
                                    this.f7111b.mErrorMsg = "";
                                    this.f7111b.mErrorRssi = -1;
                                    if (this.f7114e != null) {
                                        this.f7111b.mHostAddress = this.f7114e.m3652m();
                                    } else {
                                        this.f7111b.mHostAddress = "";
                                    }
                                    this.f7115f.m3108a(this.f7111b);
                                }
                                if (this.f7114e != null) {
                                    this.f7114e.m3645f();
                                    this.f7114e = null;
                                }
                                return;
                            }
                            try {
                                (objArr == true ? 1 : 0).close();
                            } catch (IOException e) {
                                e.printStackTrace();
                            }
                            if (0 != 0) {
                                try {
                                    fileOutputStream2.flush();
                                    fileOutputStream2.close();
                                } catch (IOException e2) {
                                    e2.printStackTrace();
                                }
                            }
                            if (!this.f7113d && (this.f7111b.mProgress == 1.0f || (this.f7111b.mCurrentSize == this.f7111b.mSize && this.f7111b.mCurrentSize > 0))) {
                                this.f7111b.mState = 3;
                                this.f7111b.mErrorCode = 0;
                                this.f7111b.mErrorMsg = "";
                                this.f7111b.mErrorRssi = -1;
                                if (this.f7114e != null) {
                                    this.f7111b.mHostAddress = this.f7114e.m3652m();
                                } else {
                                    this.f7111b.mHostAddress = "";
                                }
                                this.f7115f.m3108a(this.f7111b);
                            }
                            if (this.f7114e != null) {
                                this.f7114e.m3645f();
                                this.f7114e = null;
                            }
                            return;
                        }
                        this.f7111b.mState = 0;
                        this.f7115f.m3108a(this.f7111b);
                        if (!this.f7118i) {
                            try {
                                this.f7114e = C1339y.m3623a((!this.f7111b.isOnChangeRetry || this.f7111b.mChangeUrl == null) ? this.f7111b.mUrl : this.f7111b.mChangeUrl);
                                this.f7114e.m3635a("Range", "bytes=0-" + (this.f7112c - 1));
                                if (this.f7114e.m3641c() != 206) {
                                    this.f7114e.m3645f();
                                    this.f7114e = C1339y.m3623a(this.f7111b.mUrl);
                                    this.f7114e.m3641c();
                                }
                                int iM3644e = this.f7114e.m3644e();
                                if (iM3644e == 206) {
                                    this.f7111b.isSupportRange = true;
                                    this.f7111b.mSize = this.f7114e.m3646g();
                                } else if (iM3644e == 200) {
                                    this.f7111b.isSupportRange = false;
                                    this.f7111b.mSize = this.f7114e.m3647h();
                                }
                            } catch (NetWorkException e3) {
                                throw e3;
                            } catch (Exception e4) {
                                throw new NetWorkException(-2, "init download task exception " + e4.getClass().getName() + " errormsg:" + e4.getMessage());
                            }
                        }
                        fileOutputStream = new FileOutputStream(this.f7116g, true);
                        try {
                            channel = fileOutputStream.getChannel();
                            channel.position(this.f7111b.mCurrentSize);
                            if (this.f7111b.isSupportRange) {
                                m3131b(fileOutputStream);
                            } else {
                                m3130a(fileOutputStream);
                            }
                            fileOutputStream.flush();
                            if ((this.f7111b.mCurrentSize == this.f7111b.mSize && this.f7111b.mCurrentSize > 0) || (this.f7113d && !this.f7111b.isSupportRange && this.f7111b.mSize <= 0 && this.f7111b.mCurrentSize > 0)) {
                                this.f7111b.mState = 3;
                                this.f7111b.mErrorCode = 0;
                                this.f7111b.mErrorMsg = "";
                                this.f7111b.mErrorRssi = -1;
                                if (this.f7114e != null) {
                                    this.f7111b.mHostAddress = this.f7114e.m3652m();
                                } else {
                                    this.f7111b.mHostAddress = "";
                                }
                                this.f7115f.m3108a(this.f7111b);
                            }
                            if (channel != null) {
                                try {
                                    channel.close();
                                } catch (IOException e5) {
                                    e5.printStackTrace();
                                }
                            }
                            if (fileOutputStream != null) {
                                try {
                                    fileOutputStream.flush();
                                    fileOutputStream.close();
                                } catch (IOException e6) {
                                    e6.printStackTrace();
                                }
                            }
                            if (!this.f7113d && (this.f7111b.mProgress == 1.0f || (this.f7111b.mCurrentSize == this.f7111b.mSize && this.f7111b.mCurrentSize > 0))) {
                                this.f7111b.mState = 3;
                                this.f7111b.mErrorCode = 0;
                                this.f7111b.mErrorMsg = "";
                                this.f7111b.mErrorRssi = -1;
                                if (this.f7114e != null) {
                                    this.f7111b.mHostAddress = this.f7114e.m3652m();
                                } else {
                                    this.f7111b.mHostAddress = "";
                                }
                                this.f7115f.m3108a(this.f7111b);
                            }
                            if (this.f7114e != null) {
                                this.f7114e.m3645f();
                                this.f7114e = null;
                            }
                        } catch (NetWorkException e7) {
                            e = e7;
                            e.printStackTrace();
                            if (this.f7113d) {
                                this.f7111b.mState = 2;
                                this.f7111b.mErrorCode = e.getErrCode();
                                this.f7111b.mErrorMsg = e.getErrMsg();
                                this.f7111b.mErrorRssi = WifiUtil.calculateSignalLevel(5);
                                if (this.f7114e != null) {
                                    this.f7111b.mHostAddress = this.f7114e.m3652m();
                                } else {
                                    this.f7111b.mHostAddress = "";
                                }
                                this.f7115f.m3108a(this.f7111b);
                            }
                            if (channel != null) {
                                try {
                                    channel.close();
                                } catch (IOException e8) {
                                    e8.printStackTrace();
                                }
                            }
                            if (fileOutputStream != null) {
                                try {
                                    fileOutputStream.flush();
                                    fileOutputStream.close();
                                } catch (IOException e9) {
                                    e9.printStackTrace();
                                }
                            }
                            if (!this.f7113d && (this.f7111b.mProgress == 1.0f || (this.f7111b.mCurrentSize == this.f7111b.mSize && this.f7111b.mCurrentSize > 0))) {
                                this.f7111b.mState = 3;
                                this.f7111b.mErrorCode = 0;
                                this.f7111b.mErrorMsg = "";
                                this.f7111b.mErrorRssi = -1;
                                if (this.f7114e != null) {
                                    this.f7111b.mHostAddress = this.f7114e.m3652m();
                                } else {
                                    this.f7111b.mHostAddress = "";
                                }
                                this.f7115f.m3108a(this.f7111b);
                            }
                            if (this.f7114e != null) {
                                this.f7114e.m3645f();
                                this.f7114e = null;
                            }
                        } catch (FileNotFoundException e10) {
                            e = e10;
                            e.printStackTrace();
                            if (this.f7113d) {
                                this.f7111b.mState = 2;
                                this.f7111b.mErrorCode = -7001;
                                this.f7111b.mErrorMsg = e.getMessage();
                                this.f7111b.mErrorRssi = WifiUtil.calculateSignalLevel(5);
                                if (this.f7114e != null) {
                                    this.f7111b.mHostAddress = this.f7114e.m3652m();
                                } else {
                                    this.f7111b.mHostAddress = "";
                                }
                                this.f7115f.m3108a(this.f7111b);
                            }
                            if (channel != null) {
                                try {
                                    channel.close();
                                } catch (IOException e11) {
                                    e11.printStackTrace();
                                }
                            }
                            if (fileOutputStream != null) {
                                try {
                                    fileOutputStream.flush();
                                    fileOutputStream.close();
                                } catch (IOException e12) {
                                    e12.printStackTrace();
                                }
                            }
                            if (!this.f7113d && (this.f7111b.mProgress == 1.0f || (this.f7111b.mCurrentSize == this.f7111b.mSize && this.f7111b.mCurrentSize > 0))) {
                                this.f7111b.mState = 3;
                                this.f7111b.mErrorCode = 0;
                                this.f7111b.mErrorMsg = "";
                                this.f7111b.mErrorRssi = -1;
                                if (this.f7114e != null) {
                                    this.f7111b.mHostAddress = this.f7114e.m3652m();
                                } else {
                                    this.f7111b.mHostAddress = "";
                                }
                                this.f7115f.m3108a(this.f7111b);
                            }
                            if (this.f7114e != null) {
                                this.f7114e.m3645f();
                                this.f7114e = null;
                            }
                        } catch (Exception e13) {
                            e = e13;
                            e.printStackTrace();
                            if (this.f7113d) {
                                this.f7111b.mState = 2;
                                this.f7111b.mErrorCode = -7002;
                                this.f7111b.mErrorMsg = "final exception " + e.getClass().getName() + " :" + e.getMessage();
                                this.f7111b.mErrorRssi = WifiUtil.calculateSignalLevel(5);
                                if (this.f7114e != null) {
                                    this.f7111b.mHostAddress = this.f7114e.m3652m();
                                } else {
                                    this.f7111b.mHostAddress = "";
                                }
                                this.f7115f.m3108a(this.f7111b);
                            }
                            if (channel != null) {
                                try {
                                    channel.close();
                                } catch (IOException e14) {
                                    e14.printStackTrace();
                                }
                            }
                            if (fileOutputStream != null) {
                                try {
                                    fileOutputStream.flush();
                                    fileOutputStream.close();
                                } catch (IOException e15) {
                                    e15.printStackTrace();
                                }
                            }
                            if (!this.f7113d && (this.f7111b.mProgress == 1.0f || (this.f7111b.mCurrentSize == this.f7111b.mSize && this.f7111b.mCurrentSize > 0))) {
                                this.f7111b.mState = 3;
                                this.f7111b.mErrorCode = 0;
                                this.f7111b.mErrorMsg = "";
                                this.f7111b.mErrorRssi = -1;
                                if (this.f7114e != null) {
                                    this.f7111b.mHostAddress = this.f7114e.m3652m();
                                } else {
                                    this.f7111b.mHostAddress = "";
                                }
                                this.f7115f.m3108a(this.f7111b);
                            }
                            if (this.f7114e != null) {
                                this.f7114e.m3645f();
                                this.f7114e = null;
                            }
                        }
                        return;
                    } catch (Throwable th) {
                        th = th;
                        if (0 != 0) {
                            if (fileOutputStream3 != null) {
                                fileOutputStream3.flush();
                                fileOutputStream3.close();
                            }
                            if (!this.f7113d) {
                                this.f7111b.mState = 3;
                                this.f7111b.mErrorCode = 0;
                                this.f7111b.mErrorMsg = "";
                                this.f7111b.mErrorRssi = -1;
                                if (this.f7114e != null) {
                                    this.f7111b.mHostAddress = this.f7114e.m3652m();
                                } else {
                                    this.f7111b.mHostAddress = "";
                                }
                                this.f7115f.m3108a(this.f7111b);
                            }
                            if (this.f7114e != null) {
                                throw th;
                            }
                            this.f7114e.m3645f();
                            this.f7114e = null;
                            throw th;
                        }
                        try {
                            channel.close();
                        } catch (IOException e16) {
                            e16.printStackTrace();
                        }
                        if (fileOutputStream3 != null) {
                            try {
                                fileOutputStream3.flush();
                                fileOutputStream3.close();
                            } catch (IOException e17) {
                                e17.printStackTrace();
                            }
                        }
                        if (!this.f7113d && (this.f7111b.mProgress == 1.0f || (this.f7111b.mCurrentSize == this.f7111b.mSize && this.f7111b.mCurrentSize > 0))) {
                            this.f7111b.mState = 3;
                            this.f7111b.mErrorCode = 0;
                            this.f7111b.mErrorMsg = "";
                            this.f7111b.mErrorRssi = -1;
                            if (this.f7114e != null) {
                                this.f7111b.mHostAddress = this.f7114e.m3652m();
                            } else {
                                this.f7111b.mHostAddress = "";
                            }
                            this.f7115f.m3108a(this.f7111b);
                        }
                        if (this.f7114e != null) {
                            throw th;
                        }
                        this.f7114e.m3645f();
                        this.f7114e = null;
                        throw th;
                    }
                } catch (FileNotFoundException e18) {
                    e = e18;
                    fileOutputStream = null;
                } catch (Throwable th2) {
                    th = th2;
                    fileOutputStream3 = null;
                    if (0 != 0) {
                        if (fileOutputStream3 != null) {
                            fileOutputStream3.flush();
                            fileOutputStream3.close();
                        }
                        if (!this.f7113d) {
                            this.f7111b.mState = 3;
                            this.f7111b.mErrorCode = 0;
                            this.f7111b.mErrorMsg = "";
                            this.f7111b.mErrorRssi = -1;
                            if (this.f7114e != null) {
                                this.f7111b.mHostAddress = this.f7114e.m3652m();
                            } else {
                                this.f7111b.mHostAddress = "";
                            }
                            this.f7115f.m3108a(this.f7111b);
                        }
                        if (this.f7114e != null) {
                            throw th;
                        }
                        this.f7114e.m3645f();
                        this.f7114e = null;
                        throw th;
                    }
                    channel.close();
                    if (fileOutputStream3 != null) {
                        fileOutputStream3.flush();
                        fileOutputStream3.close();
                    }
                    if (!this.f7113d) {
                        this.f7111b.mState = 3;
                        this.f7111b.mErrorCode = 0;
                        this.f7111b.mErrorMsg = "";
                        this.f7111b.mErrorRssi = -1;
                        if (this.f7114e != null) {
                            this.f7111b.mHostAddress = this.f7114e.m3652m();
                        } else {
                            this.f7111b.mHostAddress = "";
                        }
                        this.f7115f.m3108a(this.f7111b);
                    }
                    if (this.f7114e != null) {
                        throw th;
                    }
                    this.f7114e.m3645f();
                    this.f7114e = null;
                    throw th;
                }
            } catch (NetWorkException e19) {
                e = e19;
                fileOutputStream = null;
            } catch (Exception e20) {
                e = e20;
                fileOutputStream = null;
            }
            throw th;
        }
    }
}
