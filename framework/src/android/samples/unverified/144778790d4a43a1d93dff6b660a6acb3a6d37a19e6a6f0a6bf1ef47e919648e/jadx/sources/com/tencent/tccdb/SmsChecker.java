package com.tencent.tccdb;

import android.content.Context;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.module.update.IUpdateObserver;
import com.tencent.tmsecure.module.update.UpdateConfig;
import com.tencent.tmsecure.module.update.UpdateManager;
import java.util.concurrent.atomic.AtomicReference;
import tms.C1147ad;
import tms.C1336v;

/* JADX INFO: loaded from: classes.dex */
public class SmsChecker {
    public static final int EM_MOD_CHARGE = 8;
    public static final int EM_MOD_KEYWORD = 2;
    public static final int EM_MOD_PATTERN = 4;
    public static final int EM_MOD_SENDER = 1;

    /* JADX INFO: renamed from: a */
    private static volatile SmsChecker f6013a = null;

    /* JADX INFO: renamed from: b */
    private int f6014b;

    /* JADX INFO: renamed from: c */
    private String f6015c;

    /* JADX INFO: renamed from: d */
    private boolean f6016d;

    /* JADX INFO: renamed from: e */
    private final int f6017e = 3;

    /* JADX INFO: renamed from: f */
    private final int f6018f = 8;

    /* JADX INFO: renamed from: g */
    private IUpdateObserver f6019g = new C1073a(this);

    static {
        C1147ad.m2873a(TMSApplication.getApplicaionContext(), TMSApplication.getStrFromEnvMap(TMSApplication.CON_ARESENGINE_LIBNAME));
    }

    private SmsChecker(Context context) {
        this.f6016d = false;
        this.f6014b = newObject(context);
        if (this.f6014b == 0) {
            throw new OutOfMemoryError();
        }
        this.f6015c = C1336v.m3577a(context, UpdateConfig.SMS_CHECKER_NAME, (String) null);
        if (this.f6015c != null && initSmsChecker(this.f6014b, 3, this.f6015c) == 0 && initChargeChecker(this.f6014b, 8, this.f6015c) == 0) {
            this.f6016d = true;
        }
        ((UpdateManager) ManagerCreator.getManager(UpdateManager.class)).addObserver(4, this.f6019g);
    }

    public static void DestoryInstance() {
        f6013a = null;
    }

    /* JADX INFO: renamed from: a */
    private static void m2579a(int i) {
        switch (i) {
            case 0:
                return;
            default:
                throw new SmsCheckerException(i);
        }
    }

    private static native int checkChargeSms(int i, MCheckInput mCheckInput, AtomicReference<MMatchSysResult> atomicReference);

    private static native int checkSmsSys(int i, MCheckInput mCheckInput, AtomicReference<MMatchSysResult> atomicReference);

    private static native void deleteObject(int i);

    private static native void finishChargeChecker(int i);

    private static native void finishSmsChecker(int i);

    public static int getFinalAction(Context context, MMatchSysResult mMatchSysResult) {
        return nativeGetFinalAction(context, mMatchSysResult);
    }

    public static SmsChecker getInstance(Context context) {
        if (f6013a == null) {
            synchronized (SmsChecker.class) {
                if (f6013a == null) {
                    f6013a = new SmsChecker(context);
                }
            }
        }
        return f6013a;
    }

    public static void getRuleFileHeader(Context context, AtomicReference<RuleFileHeader> atomicReference, String str) {
        nativeGetRuleFileInfo(context, str, atomicReference);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static native int initChargeChecker(int i, int i2, String str);

    /* JADX INFO: Access modifiers changed from: private */
    public static native int initSmsChecker(int i, int i2, String str);

    private static native int nativeGetFinalAction(Context context, MMatchSysResult mMatchSysResult);

    private static native int nativeGetRuleFileInfo(Context context, String str, AtomicReference<RuleFileHeader> atomicReference);

    private static native int newObject(Context context);

    private static native int reloadChargeRule(int i, int i2, String str);

    private static native int reloadModRule(int i, int i2, String str);

    public boolean checkChargeSms(MCheckInput mCheckInput, AtomicReference<MMatchSysResult> atomicReference) {
        if (!this.f6016d) {
            if (!reloadModRule()) {
                atomicReference.set(new MMatchSysResult(0, 0, 0, 0, 0, null));
                return false;
            }
            this.f6016d = true;
        }
        int iCheckChargeSms = checkChargeSms(this.f6014b, mCheckInput, atomicReference);
        if (iCheckChargeSms == 0) {
            return true;
        }
        if (iCheckChargeSms > 0) {
            return false;
        }
        m2579a(iCheckChargeSms);
        return false;
    }

    public boolean checkSmsSys(MCheckInput mCheckInput, AtomicReference<MMatchSysResult> atomicReference) {
        if (!this.f6016d) {
            if (!reloadModRule()) {
                atomicReference.set(new MMatchSysResult(0, 0, 0, 0, 0, null));
                return false;
            }
            this.f6016d = true;
        }
        int iCheckSmsSys = checkSmsSys(this.f6014b, mCheckInput, atomicReference);
        if (iCheckSmsSys == 0) {
            return true;
        }
        if (iCheckSmsSys == -3) {
            return false;
        }
        m2579a(iCheckSmsSys);
        return false;
    }

    protected void finalize() {
        if (this.f6014b == 0 || !this.f6016d) {
            return;
        }
        finishSmsChecker(this.f6014b);
        finishChargeChecker(this.f6014b);
        deleteObject(this.f6014b);
        this.f6014b = 0;
    }

    public void finishChargeChecker() {
        if (this.f6016d) {
            finishChargeChecker(this.f6014b);
        }
    }

    public void finishSmsChecker() {
        if (this.f6016d) {
            finishSmsChecker(this.f6014b);
        }
    }

    public int initChargeChecker(int i, String str) {
        if (this.f6016d) {
            return initChargeChecker(this.f6014b, i, str);
        }
        return -1;
    }

    public int initSmsChecker(int i, String str) {
        if (this.f6016d) {
            return initSmsChecker(this.f6014b, i, str);
        }
        return -1;
    }

    public int reloadChargeRule(int i, String str) {
        if (this.f6016d) {
            return reloadChargeRule(this.f6014b, i, str);
        }
        return -1;
    }

    public synchronized boolean reloadModRule() {
        boolean z;
        if (this.f6016d) {
            int iReloadModRule = reloadModRule(this.f6014b, 3, this.f6015c) | reloadChargeRule(this.f6014b, 8, this.f6015c);
            if (iReloadModRule == 0) {
                z = true;
            } else {
                m2579a(iReloadModRule);
                z = false;
            }
        } else {
            z = false;
        }
        return z;
    }
}
