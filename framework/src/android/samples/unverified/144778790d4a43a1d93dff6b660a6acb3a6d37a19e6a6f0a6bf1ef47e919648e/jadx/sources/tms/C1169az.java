package tms;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.media.AudioManager;
import android.os.Process;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.module.aresengine.AresEngineManager;
import com.tencent.tmsecure.module.aresengine.IPhoneDeviceController;
import com.tencent.tmsecure.module.aresengine.SmsEntity;
import com.tencent.tmsecure.module.tools.RunableTaskManager;
import com.tencent.tmsecure.utils.SDKUtil;
import com.tencent.tmsecure.utils.ScriptHelper;

/* JADX INFO: renamed from: tms.az */
/* JADX INFO: loaded from: classes.dex */
public final class C1169az implements IPhoneDeviceController {

    /* JADX INFO: renamed from: a */
    private C1153aj f6876a;

    /* JADX INFO: renamed from: b */
    private AudioManager f6877b;

    /* JADX INFO: renamed from: c */
    private boolean f6878c = false;

    /* JADX INFO: renamed from: d */
    private boolean f6879d;

    /* JADX INFO: renamed from: tms.az$a */
    final class a implements Runnable {

        /* JADX INFO: renamed from: b */
        private int f6881b;

        /* JADX INFO: renamed from: c */
        private int f6882c;

        /* JADX INFO: renamed from: d */
        private int f6883d;

        public a(int i, int i2, int i3) {
            this.f6881b = i;
            this.f6882c = i2;
            this.f6883d = i3;
        }

        @Override // java.lang.Runnable
        public final void run() {
            try {
                Thread.currentThread();
                Thread.sleep(this.f6883d * 1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            int ringerMode = C1169az.this.f6877b.getRingerMode();
            int vibrateSetting = C1169az.this.f6877b.getVibrateSetting(0);
            if (this.f6881b != -1 && ringerMode != this.f6881b) {
                C1169az.this.f6877b.setRingerMode(this.f6881b);
            }
            if (this.f6882c != -1 && vibrateSetting != this.f6882c) {
                C1169az.this.f6877b.setVibrateSetting(0, this.f6882c);
            }
            C1169az.m2970b(C1169az.this);
        }
    }

    public C1169az(Context context) {
        this.f6879d = SDKUtil.getSDKVersion() < 9;
        this.f6876a = C1153aj.m2912a();
        this.f6877b = (AudioManager) context.getSystemService("audio");
    }

    /* JADX INFO: renamed from: b */
    static /* synthetic */ boolean m2970b(C1169az c1169az) {
        c1169az.f6878c = false;
        return false;
    }

    @Override // com.tencent.tmsecure.module.aresengine.IPhoneDeviceController
    public final void blockSms(Object... objArr) {
        if (objArr == null || objArr.length < 2 || !(objArr[1] instanceof BroadcastReceiver)) {
            return;
        }
        ((BroadcastReceiver) objArr[1]).abortBroadcast();
    }

    @Override // com.tencent.tmsecure.module.aresengine.IPhoneDeviceController
    public final void cancelMissCall() {
        if (ScriptHelper.providerSupportCancelMissCall()) {
            ScriptHelper.provider().m3517d();
            return;
        }
        if (this.f6879d) {
            this.f6876a.m2915b();
        } else if (ScriptHelper.isRootGot() || Process.myUid() == 1000) {
            ScriptHelper.runScript("service call notification 2 s16 com.android.phone i32 1");
        }
    }

    @Override // com.tencent.tmsecure.module.aresengine.IPhoneDeviceController
    public final void disableRingVibration(int i) {
        if (this.f6878c) {
            return;
        }
        this.f6878c = true;
        int ringerMode = this.f6877b.getRingerMode();
        int vibrateSetting = this.f6877b.getVibrateSetting(0);
        if (ringerMode != 0) {
            this.f6877b.setRingerMode(0);
        } else {
            ringerMode = -1;
        }
        if (vibrateSetting != 0) {
            this.f6877b.setVibrateSetting(0, 0);
        } else {
            vibrateSetting = -1;
        }
        new Thread(new a(ringerMode, vibrateSetting, i)).start();
    }

    @Override // com.tencent.tmsecure.module.aresengine.IPhoneDeviceController
    public final void hangup() {
        disableRingVibration(3);
        this.f6876a.m2916c();
        ((RunableTaskManager) ManagerCreator.getManager(RunableTaskManager.class)).addTask(new RunnableC1156am(this), 1000L);
    }

    @Override // com.tencent.tmsecure.module.aresengine.IPhoneDeviceController
    public final void unBlockSms(SmsEntity smsEntity, Object... objArr) {
        if (objArr == null || objArr.length < 2) {
            return;
        }
        switch (((Integer) objArr[0]).intValue()) {
            case 2:
                if (TMSApplication.getApplicaionContext().getPackageName().equals((String) objArr[1])) {
                    ((AresEngineManager) ManagerCreator.getManager(AresEngineManager.class)).getAresEngineFactor().getSysDao().insert(smsEntity);
                }
                break;
        }
    }
}
