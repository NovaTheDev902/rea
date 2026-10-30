package com.lenovo.safecenter.utils;

import android.content.Context;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.util.Log;
import java.util.Observable;

/* JADX INFO: loaded from: classes.dex */
public class LeSafeObservable extends Observable {
    public static final int LOAD_FINISH = 22;
    public static final int LOAD_PERMISSION = 20;
    public static final int LOAD_VIRUSDB = 21;
    public static final int OBSERVER_CHANGE_CHILD_MODE_FAIL = 6;
    public static final int OBSERVER_CHANGE_GUEST_MODE_SUCCESS = 5;
    public static final int OBSERVER_CHANGE_PASSWORD = 10;
    public static final int OBSERVER_FLOAT_WINDOW_CHANGE = 20;
    public static final int OBSERVER_NEW_CHARGE_LOGS = 7;
    public static final int OBSERVER_NEW_HARASS_LOGS = 9;
    public static final int OBSERVER_NEW_PRIVACY_LOGS = 8;
    public static final int OBSERVER_PROTECT_VIRUS_HAS_VIRUS = 18;
    public static final int OBSERVER_PROTECT_VIRUS_KILLED_VIRUS = 19;
    public static final int OBSERVER_PROTECT_VIRUS_SCANED = 17;
    public static final int OBSERVER_QUERY_LAB = 1;
    public static final int OBSERVER_REFRESH_CALL_DURATION_CURR_MONTH = 4;
    public static final int OBSERVER_REFRESH_PROTECT_HARASS_DETAIL = 14;
    public static final int OBSERVER_REFRESH_PROTECT_PEEP_DETAIL = 13;
    public static final int OBSERVER_REFRESH_PROTECT_THIEF_DETAIL = 16;
    public static final int OBSERVER_REFRESH_PROTECT_TRAFFIC_DETAIL = 12;
    public static final int OBSERVER_REFRESH_PROTECT_VIRUS_DETAIL = 15;
    public static final int OBSERVER_REFRESH_SMS_SENT_NUM_CURR_MONTH = 3;
    public static final int OBSERVER_REFRESH_TRAFFIC_INFO = 2;
    public static final int OBSERVER_UPDATED_LAB = 0;
    public static final int OBSERVER_UPDATING_LAB = 11;

    /* JADX INFO: renamed from: a */
    private static LeSafeObservable f5749a;

    /* JADX INFO: renamed from: b */
    private Handler f5750b;

    private LeSafeObservable() {
        boolean z = Looper.getMainLooper().getThread() != Thread.currentThread();
        this.f5750b = new Handler(Looper.getMainLooper()) { // from class: com.lenovo.safecenter.utils.LeSafeObservable.1
            @Override // android.os.Handler
            public final void handleMessage(Message msg) {
                switch (msg.what) {
                    case 0:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(0);
                        break;
                    case 1:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(1);
                        break;
                    case 2:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(2);
                        break;
                    case 3:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(3);
                        break;
                    case 4:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(4);
                        break;
                    case 5:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(5);
                        break;
                    case 6:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(6);
                        break;
                    case 7:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(7);
                        break;
                    case 8:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(8);
                        break;
                    case 9:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(9);
                        break;
                    case 10:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(10);
                        break;
                    case 11:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(11);
                        break;
                    case 12:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(12);
                        break;
                    case 13:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(13);
                        break;
                    case 14:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(14);
                        break;
                    case 15:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(15);
                        break;
                    case 16:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(16);
                        break;
                    case 17:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(17);
                        break;
                    case 18:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(18);
                        break;
                    case 19:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(19);
                        break;
                    case 20:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(20);
                        break;
                    case 21:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(21);
                        break;
                    case 22:
                        LeSafeObservable.this.setChanged();
                        LeSafeObservable.this.notifyObservers(22);
                        break;
                }
            }
        };
        if (!z) {
            Log.i("wu0wu", "===============isInUiThread");
        } else {
            Log.i("wu0wu", "===============isNotInUiThread");
        }
    }

    public static synchronized LeSafeObservable get(Context context) {
        if (f5749a == null) {
            f5749a = new LeSafeObservable();
        }
        return f5749a;
    }

    public void close() {
        synchronized (this) {
            f5749a = null;
        }
    }

    public void noticeUpdatedLab() {
        this.f5750b.sendEmptyMessage(0);
    }

    public void noticeQueryedLab() {
        Log.i("wu0wu", "noticeQueryedLab()-->");
        this.f5750b.sendEmptyMessage(1);
    }

    public void noticeRefreshProtectTrafficDetail() {
        Log.i("wu0wu", "noticeRefreshProtectTrafficDetail()-->");
        this.f5750b.sendEmptyMessage(12);
    }

    public void noticeRefreshProtectPeepDetail() {
        Log.i("wu0wu", "noticeRefreshProtectPeepDetail()-->");
        this.f5750b.sendEmptyMessage(13);
    }

    public void noticeRefreshProtectHarassDetail() {
        Log.i("wu0wu", "noticeRefreshProtectHarassDetail()-->");
        this.f5750b.sendEmptyMessage(14);
    }

    public void noticeRefreshProtectVirusDetail() {
        Log.i("wu0wu", "noticeRefreshProtectVirusDetail()-->");
        this.f5750b.sendEmptyMessage(15);
    }

    public void noticeRefreshProtectThiefDetail() {
        Log.i("wu0wu", "noticeRefreshProtectThiefDetail()-->");
        this.f5750b.sendEmptyMessage(16);
    }

    public void noticeRefreshTrafficInfo() {
        Log.i("wu0wu", "noticeRefreshTrafficInfo()-->");
        this.f5750b.sendEmptyMessage(2);
    }

    public void noticeRefreshSmsSentNumCurrMonth() {
        this.f5750b.sendEmptyMessage(3);
    }

    public void noticeRefreshCallDurationCurrMonth() {
        this.f5750b.sendEmptyMessage(4);
    }

    public void noticeChangeGuestModeSuccess() {
        this.f5750b.sendEmptyMessage(5);
    }

    public void noticeChangeChildModeFail() {
        this.f5750b.sendEmptyMessage(6);
    }

    public void noticeRefreshPrivacyLogs() {
        this.f5750b.sendEmptyMessage(8);
    }

    public void noticeRefreshChargeLogs() {
        this.f5750b.sendEmptyMessage(7);
    }

    public void noticeRefreshHarassLogs() {
        this.f5750b.sendEmptyMessage(9);
    }

    public void noticeChangePassword() {
        WflUtils.Log("i", "wu0wu", "LeSafeObservable noticeChangePassword()-->");
        this.f5750b.sendEmptyMessage(10);
    }

    public void noticeUpdatingLab() {
        this.f5750b.sendEmptyMessage(11);
    }

    public void noticeHasScanedVirus() {
        this.f5750b.sendEmptyMessage(17);
    }

    public void noticeHasVirus() {
        this.f5750b.sendEmptyMessage(18);
    }

    public void noticeKilledVirus() {
        this.f5750b.sendEmptyMessage(19);
    }

    public void noticeLoadPermissions() {
        this.f5750b.sendEmptyMessage(20);
    }

    public void noticeLoadVirusDB() {
        this.f5750b.sendEmptyMessage(21);
    }

    public void noticeLoadFinish() {
        this.f5750b.sendEmptyMessage(22);
    }
}
