package tms;

import QQPIM.UploadFile;
import QQPIM.UploadFileInfo;
import QQPIM.uploadPacketInfoReq;
import QQPIM.uploadPacketInfoResp;
import android.content.Context;
import com.lenovo.lps.sus.p003a.p004a.p005a.InterfaceC0079b;
import com.p012qq.jce.wup.UniAttribute;
import com.tencent.tccdb.TccCryptor;
import com.tencent.tmsecure.common.ErrorCode;
import com.tencent.tmsecure.exception.NetWorkException;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Iterator;
import java.util.concurrent.atomic.AtomicReference;

/* JADX INFO: renamed from: tms.aa */
/* JADX INFO: loaded from: classes.dex */
public class C1144aa {

    /* JADX INFO: renamed from: a */
    public static final String f6813a = "http://uploadserver.3g.qq.com";

    /* JADX INFO: renamed from: b */
    private Context f6814b;

    /* JADX INFO: renamed from: c */
    private String f6815c = f6813a;

    public C1144aa(Context context) {
        this.f6814b = context;
    }

    /* JADX INFO: renamed from: a */
    public int m2870a(String str, UploadFileInfo uploadFileInfo) {
        int is_succ;
        C1339y c1339yM3623a;
        Exception exc;
        byte[] bArr;
        uploadPacketInfoResp uploadpacketinforespM2871a;
        File file = new File(str);
        if (!file.exists()) {
            return -1;
        }
        try {
            RandomAccessFile randomAccessFile = new RandomAccessFile(file, "r");
            byte[] bArr2 = new byte[20480];
            C1339y c1339y = null;
            if (uploadFileInfo == null) {
                break;
            }
            try {
                try {
                    if (uploadFileInfo.getVecUploadFile() == null) {
                        break;
                    }
                    Iterator<UploadFile> it = uploadFileInfo.getVecUploadFile().iterator();
                    int i = -2;
                    while (true) {
                        try {
                            byte[] bArr3 = bArr2;
                            if (!it.hasNext()) {
                                break;
                            }
                            UploadFile next = it.next();
                            long pos = next.getPos();
                            int size = next.getSize();
                            randomAccessFile.seek(pos);
                            bArr2 = size != bArr3.length ? new byte[size] : bArr3;
                            int i2 = randomAccessFile.read(bArr2, 0, size);
                            if (i2 == -1 || i2 != size) {
                                try {
                                    randomAccessFile.close();
                                } catch (IOException e) {
                                    e.printStackTrace();
                                }
                                if (c1339y != null) {
                                    c1339y.m3645f();
                                }
                                return -2060;
                            }
                            String id = uploadFileInfo.getId();
                            if (id == null || bArr2.length == 0) {
                                bArr = null;
                            } else {
                                byte[] bArrM2876a = C1148ae.m2876a(bArr2);
                                int length = bArrM2876a.length;
                                uploadPacketInfoReq uploadpacketinforeq = new uploadPacketInfoReq();
                                uploadpacketinforeq.setSoftware_id(id);
                                uploadpacketinforeq.setPacket_pos(pos);
                                uploadpacketinforeq.setPacket_size(size);
                                uploadpacketinforeq.setChecksum_type("MD5");
                                uploadpacketinforeq.setChecksun_len(length);
                                uploadpacketinforeq.setZip_type(0);
                                UniAttribute uniAttribute = new UniAttribute();
                                uniAttribute.setEncodeName(InterfaceC0079b.f1213a);
                                uniAttribute.put("key_UploadPacketInfoReq", uploadpacketinforeq);
                                byte[] bArrEncode = uniAttribute.encode();
                                if (bArrEncode == null) {
                                    bArr = null;
                                } else {
                                    int length2 = bArrEncode.length;
                                    bArr = new byte[length2 + 4 + bArr2.length + bArrM2876a.length];
                                    System.arraycopy(C1148ae.m2874a(bArrEncode.length), 0, bArr, 0, 4);
                                    System.arraycopy(bArrEncode, 0, bArr, 4, length2);
                                    System.arraycopy(bArr2, 0, bArr, length2 + 4, bArr2.length);
                                    System.arraycopy(bArrM2876a, 0, bArr, length2 + 4 + bArr2.length, bArrM2876a.length);
                                }
                            }
                            c1339yM3623a = C1339y.m3623a(this.f6815c);
                            try {
                                try {
                                    try {
                                        c1339yM3623a.m3638b("POST");
                                        c1339yM3623a.m3637a(bArr);
                                        c1339yM3623a.m3641c();
                                        AtomicReference<byte[]> atomicReference = new AtomicReference<>();
                                        int iM3633a = c1339yM3623a.m3633a(false, atomicReference);
                                        try {
                                            c1339yM3623a.m3645f();
                                            if (iM3633a != 0) {
                                                try {
                                                    randomAccessFile.close();
                                                } catch (IOException e2) {
                                                    e2.printStackTrace();
                                                }
                                                if (c1339yM3623a != null) {
                                                    c1339yM3623a.m3645f();
                                                }
                                                return iM3633a;
                                            }
                                            byte[] bArr4 = atomicReference.get();
                                            is_succ = (bArr4 == null || (uploadpacketinforespM2871a = m2871a(bArr4)) == null) ? ErrorCode.ERR_RESPONSE : uploadpacketinforespM2871a.getIs_succ();
                                            if (is_succ != 0) {
                                                try {
                                                    randomAccessFile.close();
                                                } catch (IOException e3) {
                                                    e3.printStackTrace();
                                                }
                                                if (c1339yM3623a == null) {
                                                    return is_succ;
                                                }
                                            } else {
                                                c1339y = c1339yM3623a;
                                                i = is_succ;
                                            }
                                        } catch (Exception e4) {
                                            is_succ = iM3633a;
                                            exc = e4;
                                            exc.printStackTrace();
                                            try {
                                                randomAccessFile.close();
                                            } catch (IOException e5) {
                                                e5.printStackTrace();
                                            }
                                            if (c1339yM3623a == null) {
                                                return is_succ;
                                            }
                                        }
                                    } catch (NetWorkException e6) {
                                        e = e6;
                                        c1339y = c1339yM3623a;
                                        e.printStackTrace();
                                        int errCode = e.getErrCode();
                                        try {
                                            randomAccessFile.close();
                                        } catch (IOException e7) {
                                            e7.printStackTrace();
                                        }
                                        if (c1339y == null) {
                                            return errCode;
                                        }
                                        c1339y.m3645f();
                                        return errCode;
                                    }
                                } catch (Exception e8) {
                                    exc = e8;
                                    is_succ = i;
                                }
                                c1339yM3623a.m3645f();
                                return is_succ;
                            } catch (Throwable th) {
                                th = th;
                                c1339y = c1339yM3623a;
                                try {
                                    randomAccessFile.close();
                                } catch (IOException e9) {
                                    e9.printStackTrace();
                                }
                                if (c1339y == null) {
                                    throw th;
                                }
                                c1339y.m3645f();
                                throw th;
                            }
                        } catch (Exception e10) {
                            c1339yM3623a = c1339y;
                            exc = e10;
                            is_succ = i;
                        }
                    }
                } catch (Exception e11) {
                    is_succ = -2;
                    c1339yM3623a = null;
                    exc = e11;
                }
            } catch (NetWorkException e12) {
                e = e12;
            }
            try {
                randomAccessFile.close();
            } catch (IOException e13) {
                e13.printStackTrace();
            }
            if (c1339y != null) {
                c1339y.m3645f();
            }
            return 0;
        } catch (FileNotFoundException e14) {
            return -1;
        }
    }

    /* JADX INFO: renamed from: a */
    public uploadPacketInfoResp m2871a(byte[] bArr) {
        uploadPacketInfoResp uploadpacketinforesp;
        if (bArr == null) {
            return null;
        }
        UniAttribute uniAttribute = new UniAttribute();
        uniAttribute.setEncodeName(InterfaceC0079b.f1213a);
        try {
            uniAttribute.decode(TccCryptor.decrypt(this.f6814b, bArr, null));
            uploadpacketinforesp = (uploadPacketInfoResp) uniAttribute.get("key_UploadPacketInfoResp");
        } catch (Exception e) {
            e.printStackTrace();
            uploadpacketinforesp = null;
        }
        return uploadpacketinforesp;
    }

    /* JADX INFO: renamed from: a */
    public void m2872a(String str) {
        this.f6815c = str;
    }
}
