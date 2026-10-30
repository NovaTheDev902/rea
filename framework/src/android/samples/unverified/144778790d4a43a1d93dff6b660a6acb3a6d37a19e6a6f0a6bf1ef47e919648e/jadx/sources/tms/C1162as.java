package tms;

import QQPIM.SoftElementInfo;
import QQPIM.SoftList;
import QQPIM.SoftListType;
import android.content.Context;
import com.p012qq.jce.wup.UniAttribute;
import com.tencent.tccdb.TccCryptor;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.module.software.AppEntity;
import com.tencent.tmsecure.module.software.SoftwareManager;
import com.tencent.tmsecure.module.update.IUpdateObserver;
import com.tencent.tmsecure.module.update.UpdateConfig;
import com.tencent.tmsecure.module.update.UpdateManager;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.HashMap;
import java.util.Iterator;

/* JADX INFO: renamed from: tms.as */
/* JADX INFO: loaded from: classes.dex */
public final class C1162as extends BaseManager {

    /* JADX INFO: renamed from: b */
    private SoftwareManager f6852b;

    /* JADX INFO: renamed from: a */
    private HashMap<String, SoftList> f6851a = new HashMap<>(1);

    /* JADX INFO: renamed from: c */
    private IUpdateObserver f6853c = new C1324j(this);

    /* JADX INFO: renamed from: a */
    private static String m2935a(SoftListType softListType) {
        switch (softListType.value()) {
            case 0:
                return UpdateConfig.WHITELIST_COMMON_NAME;
            case 1:
                return UpdateConfig.WHITELIST_UNUSUAL_NAME;
            case 2:
                return UpdateConfig.BLACKLIST_ROM_NAME;
            case 3:
                return UpdateConfig.BLACKLIST_WITHPLUGIN_NAME;
            case 4:
                return UpdateConfig.ROM_THIRDPART_NAME;
            case 5:
                return UpdateConfig.WHITELIST_ROM_NAME;
            default:
                return "";
        }
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m2936a(C1162as c1162as, SoftListType softListType) {
        if (softListType == null) {
            return;
        }
        synchronized (c1162as.f6851a) {
            String string = softListType.toString();
            if (c1162as.f6851a.containsKey(string)) {
                c1162as.f6851a.put(string, m2939b(string, m2935a(softListType)));
            }
        }
    }

    /* JADX INFO: renamed from: a */
    private boolean m2937a(String str, SoftList softList) {
        SoftElementInfo next;
        Iterator<SoftElementInfo> it = softList.vctSofts.iterator();
        while (true) {
            if (!it.hasNext()) {
                next = null;
                break;
            }
            next = it.next();
            if (next.pkgname.equals(str) || (next.pkgname.length() == 0 && m2938a(str, next.cert))) {
                break;
            }
        }
        if (next == null) {
            return false;
        }
        if (next.cert.length() == 0 || next.pkgname.length() == 0) {
            return true;
        }
        return m2938a(str, next.cert);
    }

    /* JADX INFO: renamed from: a */
    private boolean m2938a(String str, String str2) {
        AppEntity appInfo = this.f6852b.getAppInfo(str, 16);
        return (appInfo == null || appInfo.get(AppEntity.KEY_SIGNATURE_MD5_STR) == null || !appInfo.get(AppEntity.KEY_SIGNATURE_MD5_STR).equals(str2)) ? false : true;
    }

    /* JADX WARN: Code duplicated, block: B:54:0x008b A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX INFO: renamed from: b */
    private static SoftList m2939b(String str, String str2) throws Throwable {
        String strM3577a;
        FileInputStream fileInputStream;
        SoftList softList;
        if (str2 == null || str2.length() == 0 || (strM3577a = C1336v.m3577a(TMSApplication.getApplicaionContext(), str2, (String) null)) == null || strM3577a.length() == 0) {
            return null;
        }
        File file = new File(strM3577a);
        if (!file.exists()) {
            return null;
        }
        try {
            fileInputStream = new FileInputStream(file);
            try {
                try {
                    C1334t c1334tM3572a = C1335u.m3572a(fileInputStream);
                    byte[] bArr = new byte[fileInputStream.available()];
                    fileInputStream.read(bArr);
                    if (!C1332r.m3548a(C1148ae.m2876a(bArr)).equals(C1332r.m3548a(c1334tM3572a.m3570c()))) {
                        if (fileInputStream == null) {
                            return null;
                        }
                        try {
                            fileInputStream.close();
                            return null;
                        } catch (IOException e) {
                            e.printStackTrace();
                            return null;
                        }
                    }
                    byte[] bArrDecrypt = TccCryptor.decrypt(TMSApplication.getApplicaionContext(), bArr, null);
                    UniAttribute uniAttribute = new UniAttribute();
                    uniAttribute.decode(bArrDecrypt);
                    softList = (SoftList) uniAttribute.get(str, new SoftList());
                    if (fileInputStream != null) {
                        try {
                            fileInputStream.close();
                        } catch (IOException e2) {
                            e2.printStackTrace();
                        }
                    }
                } catch (Exception e3) {
                    e = e3;
                    e.printStackTrace();
                    if (fileInputStream != null) {
                        try {
                            fileInputStream.close();
                        } catch (IOException e4) {
                            e4.printStackTrace();
                        }
                    }
                    softList = null;
                }
            } catch (Throwable th) {
                th = th;
                if (fileInputStream != null) {
                    try {
                        fileInputStream.close();
                    } catch (IOException e5) {
                        e5.printStackTrace();
                    }
                }
                throw th;
            }
        } catch (Exception e6) {
            e = e6;
            fileInputStream = null;
        } catch (Throwable th2) {
            th = th2;
            fileInputStream = null;
            if (fileInputStream != null) {
                fileInputStream.close();
            }
            throw th;
        }
        return softList;
    }

    /* JADX WARN: Code duplicated, block: B:26:0x007e  */
    /*  JADX ERROR: JadxRuntimeException in pass: IfRegionVisitor
        jadx.core.utils.exceptions.JadxRuntimeException: Can't remove SSA var: r0v17 QQPIM.SoftElementInfo, still in use, count: 2, list:
          (r0v17 QQPIM.SoftElementInfo) from 0x0065: IGET (r0v17 QQPIM.SoftElementInfo) A[WRAPPED] QQPIM.SoftElementInfo.softsize int
          (r0v17 QQPIM.SoftElementInfo) from 0x006c: PHI (r0 I:??) = (r0v11 QQPIM.SoftElementInfo), (r0v17 QQPIM.SoftElementInfo) binds: [B:28:0x0087, B:30:0x006c] A[DONT_GENERATE, DONT_INLINE]
        	at jadx.core.utils.InsnRemover.removeSsaVar(InsnRemover.java:164)
        	at jadx.core.utils.InsnRemover.unbindResult(InsnRemover.java:129)
        	at jadx.core.utils.InsnRemover.unbindInsn(InsnRemover.java:93)
        	at jadx.core.dex.visitors.regions.TernaryMod.makeTernaryInsn(TernaryMod.java:132)
        	at jadx.core.dex.visitors.regions.TernaryMod.processRegion(TernaryMod.java:67)
        	at jadx.core.dex.visitors.regions.TernaryMod.enterRegion(TernaryMod.java:50)
        	at jadx.core.dex.visitors.regions.DepthRegionTraversal.traverseInternal(DepthRegionTraversal.java:96)
        	at jadx.core.dex.visitors.regions.DepthRegionTraversal.traverse(DepthRegionTraversal.java:27)
        	at jadx.core.dex.visitors.regions.TernaryMod.process(TernaryMod.java:36)
        	at jadx.core.dex.visitors.regions.IfRegionVisitor.process(IfRegionVisitor.java:44)
        	at jadx.core.dex.visitors.regions.IfRegionVisitor.visit(IfRegionVisitor.java:30)
        */
    /* JADX INFO: renamed from: a */
    public final boolean m2940a(java.lang.String r9, QQPIM.SoftListType r10) {
        /*
            r8 = this;
            r2 = 0
            java.util.HashMap<java.lang.String, QQPIM.SoftList> r0 = r8.f6851a
            java.lang.String r1 = r10.toString()
            java.lang.Object r0 = r0.get(r1)
            QQPIM.SoftList r0 = (QQPIM.SoftList) r0
            if (r0 != 0) goto L27
            java.lang.String r0 = r10.toString()
            java.lang.String r1 = m2935a(r10)
            QQPIM.SoftList r0 = m2939b(r0, r1)
            if (r0 != 0) goto L1e
        L1d:
            return r2
        L1e:
            java.util.HashMap<java.lang.String, QQPIM.SoftList> r1 = r8.f6851a
            java.lang.String r3 = r10.toString()
            r1.put(r3, r0)
        L27:
            r1 = r0
            int r0 = r10.value()
            switch(r0) {
                case 0: goto L34;
                case 1: goto L34;
                case 2: goto L34;
                case 3: goto L39;
                case 4: goto L34;
                case 5: goto L34;
                default: goto L2f;
            }
        L2f:
            boolean r2 = r8.m2937a(r9, r1)
            goto L1d
        L34:
            boolean r2 = r8.m2937a(r9, r1)
            goto L1d
        L39:
            com.tencent.tmsecure.module.software.SoftwareManager r0 = r8.f6852b
            r3 = 8
            com.tencent.tmsecure.module.software.AppEntity r0 = r0.getAppInfo(r9, r3)
            if (r0 != 0) goto L46
            r0 = r2
        L44:
            r2 = r0
            goto L1d
        L46:
            r3 = 0
            java.lang.String r4 = "size"
            java.lang.Object r0 = r0.get(r4)
            java.lang.Long r0 = (java.lang.Long) r0
            long r4 = r0.longValue()
            java.util.ArrayList<QQPIM.SoftElementInfo> r0 = r1.vctSofts
            java.util.Iterator r1 = r0.iterator()
        L59:
            boolean r0 = r1.hasNext()
            if (r0 == 0) goto L87
            java.lang.Object r0 = r1.next()
            QQPIM.SoftElementInfo r0 = (QQPIM.SoftElementInfo) r0
            int r6 = r0.softsize
            long r6 = (long) r6
            int r6 = (r6 > r4 ? 1 : (r6 == r4 ? 0 : -1))
            if (r6 != 0) goto L59
        L6c:
            if (r0 == 0) goto L7e
            java.lang.String r1 = r0.pkgname
            int r1 = r1.length()
            if (r1 == 0) goto L80
            java.lang.String r1 = r0.pkgname
            boolean r1 = r1.equals(r9)
            if (r1 != 0) goto L80
        L7e:
            r0 = r2
            goto L44
        L80:
            java.lang.String r0 = r0.cert
            boolean r0 = r8.m2938a(r9, r0)
            goto L44
        L87:
            r0 = r3
            goto L6c
        */
        throw new UnsupportedOperationException("Method not decompiled: tms.C1162as.m2940a(java.lang.String, QQPIM.SoftListType):boolean");
    }

    protected final void finalize() throws Throwable {
        ((UpdateManager) ManagerCreator.getManager(UpdateManager.class)).removeObserver(4032);
        super.finalize();
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final int getSingletonType() {
        return 0;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6852b = (SoftwareManager) ManagerCreator.getManager(SoftwareManager.class);
        ((UpdateManager) ManagerCreator.getManager(UpdateManager.class)).addObserver(4032, this.f6853c);
    }
}
