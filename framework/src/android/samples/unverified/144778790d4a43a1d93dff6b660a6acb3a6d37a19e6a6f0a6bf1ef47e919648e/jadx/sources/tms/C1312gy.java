package tms;

import QQPIM.ConfInfo;
import QQPIM.ConfSrc;
import QQPIM.TipInfo;
import QQPIM.VirusClientInfo;
import QQPIM.VirusInfo;
import QQPIM.VirusServerInfo;
import android.content.Context;
import com.tencent.tccdb.TelNumberLocator;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.qscanner.AmScanner;
import com.tencent.tmsecure.module.update.CheckResult;
import com.tencent.tmsecure.module.update.ICheckListener;
import com.tencent.tmsecure.module.update.IUpdateListener;
import com.tencent.tmsecure.module.update.IUpdateObserver;
import com.tencent.tmsecure.module.update.UpdateConfig;
import com.tencent.tmsecure.module.update.UpdateInfo;
import com.tencent.tmsecure.module.wupsession.WupSessionManager;
import com.tencent.tmsecure.utils.Log;
import com.tencent.tmsecure.utils.UpdateUtil;
import java.io.File;
import java.lang.ref.SoftReference;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicReference;
import org.apache.commons.httpclient.cookie.CookieSpec;

/* JADX INFO: renamed from: tms.gy */
/* JADX INFO: loaded from: classes.dex */
public final class C1312gy extends BaseManager {

    /* JADX INFO: renamed from: a */
    public static final String f7422a = "UpdateManagerImpl";

    /* JADX INFO: renamed from: b */
    private Context f7423b;

    /* JADX INFO: renamed from: e */
    private WupSessionManager f7426e;

    /* JADX INFO: renamed from: c */
    private String f7424c = null;

    /* JADX INFO: renamed from: d */
    private AtomicBoolean f7425d = new AtomicBoolean(false);

    /* JADX INFO: renamed from: f */
    private HashMap<Integer, SoftReference<IUpdateObserver>> f7427f = new HashMap<>();

    /* JADX INFO: renamed from: a */
    private void m3437a(UpdateInfo updateInfo) {
        IUpdateObserver iUpdateObserver;
        synchronized (this.f7427f) {
            for (Map.Entry<Integer, SoftReference<IUpdateObserver>> entry : this.f7427f.entrySet()) {
                if (entry.getKey().intValue() == updateInfo.flag && (iUpdateObserver = entry.getValue().get()) != null) {
                    iUpdateObserver.onChanged(updateInfo);
                }
            }
        }
    }

    /* JADX INFO: renamed from: b */
    private String m3438b(int i) {
        String fileNameByFlag = UpdateConfig.getFileNameByFlag(i);
        String str = this.f7424c + File.separator + fileNameByFlag;
        if (!new File(str).exists()) {
            C1336v.m3577a(this.f7423b, fileNameByFlag, this.f7424c);
        }
        return str;
    }

    /* JADX INFO: renamed from: b */
    private static void m3439b(int i, ICheckListener iCheckListener) {
        if (i != 0) {
            iCheckListener.onCheckEvent(i);
        }
        iCheckListener.onCheckFinished(null);
    }

    /* JADX INFO: renamed from: a */
    public final void m3440a() {
        this.f7425d.set(true);
    }

    /* JADX INFO: renamed from: a */
    public final void m3441a(int i) {
        synchronized (this.f7427f) {
            this.f7427f.remove(Integer.valueOf(i));
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m3442a(int i, ICheckListener iCheckListener) {
        ConfInfo locationConfInfo;
        this.f7425d.set(false);
        ICheckListener.Proxy proxy = new ICheckListener.Proxy(iCheckListener);
        proxy.onCheckStarted();
        int iPrepareCheckFlag = UpdateConfig.prepareCheckFlag(i);
        ArrayList arrayList = new ArrayList();
        if (!C1278f.m3286a().m3294b()) {
            CheckResult checkResult = new CheckResult();
            checkResult.mTitle = "提示";
            checkResult.mMessage = "TMS模块已经过期，请联系供应商";
            checkResult.mUpdateInfoList = arrayList;
            proxy.onCheckFinished(checkResult);
            return;
        }
        if (this.f7425d.get()) {
            proxy.onCheckCanceled();
            m3439b(0, proxy);
            return;
        }
        ArrayList<ConfInfo> arrayList2 = new ArrayList<>();
        int[] iArr = UpdateConfig.UPDATE_FLAGS;
        int length = iArr.length;
        for (int i2 = 0; i2 < length; i2++) {
            int i3 = iArr[i2];
            if ((i3 & iPrepareCheckFlag) != 0) {
                if (i3 == 4) {
                    locationConfInfo = UpdateUtil.getSmsCheckerConfInfo(this.f7423b, m3438b(i3));
                } else if (i3 == 8) {
                    locationConfInfo = UpdateUtil.getVirusConfInfo(this.f7423b, m3438b(i3));
                } else {
                    locationConfInfo = i3 == 2 ? UpdateUtil.getLocationConfInfo(m3438b(i3)) : UpdateUtil.getFileConfInfo(m3438b(i3));
                }
                if (locationConfInfo == null) {
                    locationConfInfo = new ConfInfo();
                    locationConfInfo.filename = UpdateConfig.getFileNameByFlag(i3);
                    locationConfInfo.checksum = "";
                    locationConfInfo.timestamp = 0;
                }
                arrayList2.add(locationConfInfo);
            }
        }
        ArrayList<ConfSrc> arrayList3 = new ArrayList<>();
        AtomicReference<TipInfo> atomicReference = new AtomicReference<>();
        int configV3CPT = this.f7426e.getConfigV3CPT(arrayList2, arrayList3, atomicReference);
        if (configV3CPT != 0) {
            m3439b(configV3CPT, proxy);
            return;
        }
        if (arrayList3.size() > 0) {
            for (ConfSrc confSrc : arrayList3) {
                if (confSrc != null) {
                    UpdateInfo updateInfo = new UpdateInfo();
                    if (confSrc.isincreupdate == 0) {
                        updateInfo.fileName = confSrc.getFilename();
                    } else {
                        updateInfo.fileName = confSrc.getFilename() + UpdateConfig.PATCH_SUFIX;
                    }
                    updateInfo.flag = UpdateConfig.getFlagByFileName(confSrc.getFilename());
                    updateInfo.type = 0;
                    updateInfo.url = confSrc.getUrl();
                    updateInfo.data1 = confSrc;
                    arrayList.add(updateInfo);
                }
            }
        }
        CheckResult checkResult2 = new CheckResult();
        TipInfo tipInfo = atomicReference.get();
        checkResult2.mTitle = tipInfo != null ? tipInfo.strTitle : "";
        checkResult2.mMessage = tipInfo != null ? tipInfo.strTips : "";
        checkResult2.mUpdateInfoList = arrayList;
        Log.m2636i("update_test", "message :" + checkResult2.mMessage + " count: " + checkResult2.mUpdateInfoList.size());
        proxy.onCheckFinished(checkResult2);
    }

    /* JADX INFO: renamed from: a */
    public final void m3443a(int i, IUpdateObserver iUpdateObserver) {
        synchronized (this.f7427f) {
            if (iUpdateObserver != null) {
                this.f7427f.put(Integer.valueOf(i), new SoftReference<>(iUpdateObserver));
            }
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m3444a(List<UpdateInfo> list, IUpdateListener iUpdateListener) {
        int i;
        VirusServerInfo virusServerInfo;
        this.f7425d.set(false);
        IUpdateListener.UpdateListener updateListener = new IUpdateListener.UpdateListener(iUpdateListener);
        updateListener.onUpdateStarted();
        if (!C1278f.m3286a().m3294b()) {
            updateListener.onUpdateFinished();
            return;
        }
        if (this.f7425d.get()) {
            updateListener.onUpdateCanceled();
            updateListener.onUpdateFinished();
            return;
        }
        AtomicBoolean atomicBoolean = new AtomicBoolean(false);
        for (int i2 = 0; i2 < list.size(); i2++) {
            UpdateInfo updateInfo = list.get(i2);
            if (updateInfo != null) {
                if (list.size() == 1) {
                    updateListener.onProgressChanged(updateInfo, 50);
                } else {
                    updateListener.onProgressChanged(updateInfo, (int) (i2 / list.size()));
                }
                if (updateInfo.flag == 8) {
                    VirusClientInfo virusClientInfo = UpdateUtil.getVirusClientInfo(this.f7423b, m3438b(8));
                    if (virusClientInfo != null) {
                        virusClientInfo.setEngine_version(3);
                        AtomicReference<VirusServerInfo> atomicReference = new AtomicReference<>();
                        ArrayList<VirusInfo> arrayList = new ArrayList<>();
                        int virusInfos = this.f7426e.getVirusInfos(virusClientInfo, atomicReference, arrayList);
                        if (virusInfos == 0 && (virusServerInfo = atomicReference.get()) != null && !virusServerInfo.getBUpdate() && arrayList.size() > 0) {
                            AmScanner.updateBase(this.f7423b, m3438b(8), virusServerInfo, arrayList);
                        }
                        i = virusInfos;
                    } else {
                        i = 0;
                    }
                    if (i != 0) {
                        atomicBoolean.set(true);
                    }
                } else if (updateInfo != null && updateInfo.url != null) {
                    C1340z c1340z = new C1340z(this.f7423b);
                    c1340z.m3657a(this.f7424c + CookieSpec.PATH_DELIM);
                    c1340z.m3659b(updateInfo.fileName);
                    c1340z.m3621a(new C1294fp(this, updateListener, updateInfo, atomicBoolean));
                    c1340z.m3658a(updateInfo.url + "?m=def", true);
                    if (!atomicBoolean.get() && updateInfo.flag == 2) {
                        TelNumberLocator telNumberLocator = TelNumberLocator.getDefault(this.f7423b);
                        ConfSrc confSrc = (ConfSrc) updateInfo.data1;
                        if (confSrc.isincreupdate != 0) {
                            telNumberLocator.patchLocation(this.f7424c + File.separator + updateInfo.fileName, confSrc.getIuchecksum());
                        }
                        telNumberLocator.reload();
                    }
                }
                if (atomicBoolean.get()) {
                    break;
                }
                m3437a(updateInfo);
                if (this.f7425d.get()) {
                    updateListener.onUpdateCanceled();
                    break;
                }
            }
        }
        updateListener.onUpdateFinished();
    }

    /* JADX INFO: renamed from: b */
    public final String m3445b() {
        return this.f7424c;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final int getSingletonType() {
        return 1;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f7423b = context;
        this.f7424c = context.getFilesDir().getAbsolutePath();
        this.f7426e = (WupSessionManager) ManagerCreator.getManager(WupSessionManager.class);
    }
}
