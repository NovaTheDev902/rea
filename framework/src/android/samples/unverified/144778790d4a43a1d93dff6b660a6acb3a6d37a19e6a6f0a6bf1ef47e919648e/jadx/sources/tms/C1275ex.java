package tms;

import QQPIM.VirusClientInfo;
import android.content.Context;
import android.os.Bundle;
import android.os.Parcel;
import com.tencent.tccdb.TccCryptor;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.module.qscanner.AmScanner;
import com.tencent.tmsecure.module.qscanner.ApkKey;
import com.tencent.tmsecure.module.qscanner.QScanResultEntity;
import com.tencent.tmsecure.module.update.UpdateConfig;
import com.tencent.tmsecure.utils.Log;
import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

/* JADX INFO: renamed from: tms.ex */
/* JADX INFO: loaded from: classes.dex */
final class C1275ex {

    /* JADX INFO: renamed from: e */
    private static C1275ex f7291e;

    /* JADX INFO: renamed from: a */
    private int f7292a;

    /* JADX INFO: renamed from: b */
    private int f7293b;

    /* JADX INFO: renamed from: c */
    private Bundle f7294c;

    /* JADX INFO: renamed from: d */
    private boolean f7295d = false;

    /* JADX INFO: renamed from: f */
    private Context f7296f = TMSApplication.getApplicaionContext();

    private C1275ex() throws Throwable {
        m3274c();
        VirusClientInfo virusClientInfoLoadAmfHeader = AmScanner.loadAmfHeader(this.f7296f, C1336v.m3577a(this.f7296f, UpdateConfig.VIRUS_BASE_NAME, (String) null));
        if (virusClientInfoLoadAmfHeader != null && (virusClientInfoLoadAmfHeader.getTimestamp() != this.f7293b || virusClientInfoLoadAmfHeader.getVersion() != this.f7292a)) {
            this.f7293b = virusClientInfoLoadAmfHeader.getTimestamp();
            this.f7292a = virusClientInfoLoadAmfHeader.getVersion();
            this.f7294c = new Bundle();
        }
        if (this.f7294c == null) {
            this.f7294c = new Bundle();
        }
    }

    /* JADX INFO: renamed from: a */
    public static synchronized C1275ex m3272a() {
        if (f7291e == null) {
            f7291e = new C1275ex();
        }
        return f7291e;
    }

    /* JADX WARN: Code duplicated, block: B:34:0x0064 A[Catch: all -> 0x0048, TRY_ENTER, TryCatch #3 {, blocks: (B:4:0x0004, B:6:0x0008, B:8:0x000e, B:14:0x003f, B:16:0x0044, B:41:0x0073, B:32:0x005f, B:34:0x0064, B:35:0x0067, B:37:0x0069, B:25:0x0052, B:27:0x0057, B:39:0x006e), top: B:52:0x0004, inners: #1, #4, #6 }] */
    /* JADX WARN: Code duplicated, block: B:49:0x005f A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX INFO: renamed from: b */
    public static synchronized void m3273b() {
        FileOutputStream fileOutputStreamOpenFileOutput;
        Parcel parcelObtain = null;
        synchronized (C1275ex.class) {
            if (f7291e != null) {
                C1275ex c1275ex = f7291e;
                if (c1275ex.f7295d) {
                    try {
                        fileOutputStreamOpenFileOutput = c1275ex.f7296f.openFileOutput("qscan.cache", 0);
                        try {
                            try {
                                parcelObtain = Parcel.obtain();
                                parcelObtain.writeInt(c1275ex.f7292a);
                                parcelObtain.writeInt(c1275ex.f7293b);
                                parcelObtain.writeBundle(c1275ex.f7294c);
                                fileOutputStreamOpenFileOutput.write(TccCryptor.encrypt(c1275ex.f7296f, parcelObtain.marshall(), (byte[]) null));
                                if (fileOutputStreamOpenFileOutput != null) {
                                    try {
                                        fileOutputStreamOpenFileOutput.close();
                                    } catch (IOException e) {
                                        e.printStackTrace();
                                    }
                                }
                                if (parcelObtain != null) {
                                    parcelObtain.recycle();
                                }
                            } catch (IOException e2) {
                                e = e2;
                                e.printStackTrace();
                                if (fileOutputStreamOpenFileOutput != null) {
                                    try {
                                        fileOutputStreamOpenFileOutput.close();
                                    } catch (IOException e3) {
                                        e3.printStackTrace();
                                    }
                                }
                                if (parcelObtain != null) {
                                    parcelObtain.recycle();
                                }
                            }
                        } catch (Throwable th) {
                            th = th;
                            if (fileOutputStreamOpenFileOutput != null) {
                                try {
                                    fileOutputStreamOpenFileOutput.close();
                                } catch (IOException e4) {
                                    e4.printStackTrace();
                                }
                            }
                            if (parcelObtain != null) {
                                parcelObtain.recycle();
                            }
                            throw th;
                        }
                    } catch (IOException e5) {
                        e = e5;
                        fileOutputStreamOpenFileOutput = null;
                    } catch (Throwable th2) {
                        th = th2;
                        fileOutputStreamOpenFileOutput = null;
                        if (fileOutputStreamOpenFileOutput != null) {
                            fileOutputStreamOpenFileOutput.close();
                        }
                        if (parcelObtain != null) {
                            parcelObtain.recycle();
                        }
                        throw th;
                    }
                }
                f7291e = null;
            }
        }
    }

    /* JADX WARN: Code duplicated, block: B:34:0x0084  */
    /* JADX WARN: Code duplicated, block: B:60:0x007a A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:67:0x007f A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:78:? A[SYNTHETIC] */
    /* JADX INFO: renamed from: c */
    private void m3274c() throws Throwable {
        ByteArrayOutputStream byteArrayOutputStream;
        FileInputStream fileInputStreamOpenFileInput;
        Parcel parcelObtain = null;
        try {
            fileInputStreamOpenFileInput = this.f7296f.openFileInput("qscan.cache");
            try {
                byteArrayOutputStream = new ByteArrayOutputStream();
                try {
                    try {
                        byte[] bArr = new byte[1024];
                        while (true) {
                            int i = fileInputStreamOpenFileInput.read(bArr);
                            if (i == -1) {
                                break;
                            } else {
                                byteArrayOutputStream.write(bArr, 0, i);
                            }
                        }
                        byte[] bArrDecrypt = TccCryptor.decrypt(this.f7296f, byteArrayOutputStream.toByteArray(), null);
                        parcelObtain = Parcel.obtain();
                        parcelObtain.unmarshall(bArrDecrypt, 0, bArrDecrypt.length);
                        parcelObtain.setDataPosition(0);
                        this.f7292a = parcelObtain.readInt();
                        this.f7293b = parcelObtain.readInt();
                        this.f7294c = parcelObtain.readBundle(this.f7296f.getClassLoader());
                        if (fileInputStreamOpenFileInput != null) {
                            try {
                                fileInputStreamOpenFileInput.close();
                            } catch (IOException e) {
                                e.printStackTrace();
                            }
                        }
                        if (byteArrayOutputStream != null) {
                            try {
                                byteArrayOutputStream.close();
                            } catch (IOException e2) {
                                e2.printStackTrace();
                            }
                        }
                        if (parcelObtain == null) {
                            return;
                        }
                    } catch (Exception e3) {
                        e = e3;
                        Log.m2634e("QScanCacheManager", e.getMessage());
                        if (fileInputStreamOpenFileInput != null) {
                            try {
                                fileInputStreamOpenFileInput.close();
                            } catch (IOException e4) {
                                e4.printStackTrace();
                            }
                        }
                        if (byteArrayOutputStream != null) {
                            try {
                                byteArrayOutputStream.close();
                            } catch (IOException e5) {
                                e5.printStackTrace();
                            }
                        }
                        if (parcelObtain == null) {
                            return;
                        }
                    }
                } catch (Throwable th) {
                    th = th;
                    if (fileInputStreamOpenFileInput != null) {
                        try {
                            fileInputStreamOpenFileInput.close();
                        } catch (IOException e6) {
                            e6.printStackTrace();
                        }
                    }
                    if (byteArrayOutputStream != null) {
                        try {
                            byteArrayOutputStream.close();
                        } catch (IOException e7) {
                            e7.printStackTrace();
                        }
                    }
                    if (parcelObtain != null) {
                        throw th;
                    }
                    parcelObtain.recycle();
                    throw th;
                }
            } catch (Exception e8) {
                e = e8;
                byteArrayOutputStream = null;
            } catch (Throwable th2) {
                th = th2;
                byteArrayOutputStream = null;
                if (fileInputStreamOpenFileInput != null) {
                    fileInputStreamOpenFileInput.close();
                }
                if (byteArrayOutputStream != null) {
                    byteArrayOutputStream.close();
                }
                if (parcelObtain != null) {
                    throw th;
                }
                parcelObtain.recycle();
                throw th;
            }
        } catch (Exception e9) {
            e = e9;
            byteArrayOutputStream = null;
            fileInputStreamOpenFileInput = null;
        } catch (Throwable th3) {
            th = th3;
            byteArrayOutputStream = null;
            fileInputStreamOpenFileInput = null;
        }
        parcelObtain.recycle();
    }

    /* JADX INFO: renamed from: a */
    public final QScanResultEntity m3275a(String str, String str2, long j, int i) {
        if (str == null) {
            return null;
        }
        QScanResultEntity qScanResultEntity = (QScanResultEntity) this.f7294c.getParcelable(str + j);
        if (str2 == null || qScanResultEntity == null) {
            return null;
        }
        QScanResultEntity qScanResultEntity2 = new QScanResultEntity();
        qScanResultEntity2.packageName = qScanResultEntity.packageName;
        qScanResultEntity2.softName = qScanResultEntity.softName;
        qScanResultEntity2.version = qScanResultEntity.version;
        qScanResultEntity2.versionCode = qScanResultEntity.versionCode;
        qScanResultEntity2.certMd5 = qScanResultEntity.certMd5;
        qScanResultEntity2.size = qScanResultEntity.size;
        qScanResultEntity2.apkType = i;
        qScanResultEntity2.path = str2;
        qScanResultEntity2.type = qScanResultEntity.type;
        qScanResultEntity2.advice = qScanResultEntity.advice;
        qScanResultEntity2.malwareid = qScanResultEntity.malwareid;
        qScanResultEntity2.name = qScanResultEntity.name;
        qScanResultEntity2.label = qScanResultEntity.name;
        qScanResultEntity2.discription = qScanResultEntity.discription;
        qScanResultEntity2.url = qScanResultEntity.url;
        return qScanResultEntity2;
    }

    /* JADX INFO: renamed from: a */
    public final void m3276a(ApkKey apkKey, QScanResultEntity qScanResultEntity) {
        if (apkKey == null || this.f7294c.get(apkKey.pkgName + apkKey.size) != null) {
            return;
        }
        this.f7294c.putParcelable(apkKey.pkgName + apkKey.size, qScanResultEntity);
        this.f7295d = true;
    }
}
