package com.lenovo.safecenter.aidl.killvirus;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteCallbackList;
import android.os.RemoteException;
import android.text.TextUtils;
import android.util.Log;
import com.lenovo.safecenter.aidl.JsonUtil;
import com.lenovo.safecenter.utils.TrackEvent;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.qscanner.QScanListener;
import com.tencent.tmsecure.module.qscanner.QScanResultEntity;
import com.tencent.tmsecure.module.qscanner.QScannerManager;
import java.util.ArrayList;
import org.json.JSONException;
import org.json.JSONObject;
import org.json.JSONTokener;

/* JADX INFO: loaded from: classes.dex */
public class RemoteScanVirusService extends Service {
    public static final String COMMAND_ACTION_KILLVIRUS_CANCEL_SCAN = "killVirus_cancelscan";
    public static final String COMMAND_ACTION_KILLVIRUS_SCAN = "killVirus_scan";

    /* JADX INFO: renamed from: b */
    private QScannerManager f2949b;

    /* JADX INFO: renamed from: a */
    final RemoteCallbackList<IRemoteScanVirusCallback> f2948a = new RemoteCallbackList<>();

    /* JADX INFO: renamed from: c */
    private final IRemoteScanVirusService.Stub f2950c = new IRemoteScanVirusService.Stub() { // from class: com.lenovo.safecenter.aidl.killvirus.RemoteScanVirusService.1
        @Override // com.lenovo.safecenter.aidl.killvirus.IRemoteScanVirusService
        public final void registerCallback(IRemoteScanVirusCallback cb) {
            if (cb != null) {
                RemoteScanVirusService.this.f2948a.register(cb);
            }
        }

        @Override // com.lenovo.safecenter.aidl.killvirus.IRemoteScanVirusService
        public final void unregisterCallback(IRemoteScanVirusCallback cb) {
            if (cb != null) {
                RemoteScanVirusService.this.f2948a.unregister(cb);
            }
        }

        @Override // com.lenovo.safecenter.aidl.killvirus.IRemoteScanVirusService
        public final void receiveCommand(String command) throws RemoteException {
            try {
                Log.i("wu0wu", "command=" + command);
                JSONTokener jsonParser = new JSONTokener(command);
                JSONObject object = (JSONObject) jsonParser.nextValue();
                String action = null;
                if (object.has("action")) {
                    action = object.getString("action");
                }
                String context = null;
                if (object.has("context")) {
                    context = object.getString("context");
                }
                Log.i("wu0wu", "action=" + action);
                Log.i("wu0wu", "context=" + context);
                if (!TextUtils.isEmpty(action)) {
                    if (RemoteScanVirusService.COMMAND_ACTION_KILLVIRUS_SCAN.equals(action)) {
                        RemoteScanVirusService.m1291a(RemoteScanVirusService.this, context);
                    } else if (RemoteScanVirusService.COMMAND_ACTION_KILLVIRUS_CANCEL_SCAN.equals(action)) {
                        RemoteScanVirusService.m1290a(RemoteScanVirusService.this);
                    }
                }
            } catch (JSONException e) {
                e.printStackTrace();
            }
        }
    };

    /* JADX INFO: renamed from: d */
    private int f2951d = 0;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1290a(RemoteScanVirusService x0) {
        Log.i("wu0wu", "RemoteScanvirusService doCancelScan....");
        x0.f2949b.cancelScan();
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1291a(RemoteScanVirusService x0, final String x1) {
        new Thread(new Runnable() { // from class: com.lenovo.safecenter.aidl.killvirus.RemoteScanVirusService.2
            @Override // java.lang.Runnable
            public final void run() {
                if (RemoteScanVirusService.this.f2949b != null) {
                    RemoteScanVirusService.this.f2949b.scanInstalledPackages(new QScanListener() { // from class: com.lenovo.safecenter.aidl.killvirus.RemoteScanVirusService.2.1
                        @Override // com.tencent.tmsecure.module.qscanner.QScanListener
                        public final void onScanStarted() {
                            Log.i("wu0wu", "RemoteScanvirusService onScanStarted....");
                            try {
                                RemoteScanVirusService.this.f2951d = RemoteScanVirusService.this.f2948a.beginBroadcast();
                                Log.i("wu0wu", "onStarted mCallbacks.beginBroadcast() N=" + RemoteScanVirusService.this.f2951d);
                            } catch (Exception e) {
                                e.printStackTrace();
                            }
                            String strScanstarted = JsonUtil.killVirusScanStarted(x1);
                            for (int i = 0; i < RemoteScanVirusService.this.f2951d; i++) {
                                try {
                                    ((IRemoteScanVirusCallback) RemoteScanVirusService.this.f2948a.getBroadcastItem(i)).onResult(strScanstarted);
                                } catch (Exception e2) {
                                    e2.printStackTrace();
                                }
                            }
                        }

                        @Override // com.tencent.tmsecure.module.qscanner.QScanListener
                        public final void onPackageScanProgress(int progress, QScanResultEntity result) {
                            ScanVirusResult iscanResult = new ScanVirusResult();
                            iscanResult.type = result.type;
                            iscanResult.packageName = result.packageName;
                            iscanResult.softName = result.softName;
                            iscanResult.discription = result.discription;
                            iscanResult.version = result.version;
                            iscanResult.versionCode = result.versionCode;
                            iscanResult.apkType = result.apkType;
                            iscanResult.path = result.path;
                            iscanResult.certMd5 = result.certMd5;
                            iscanResult.size = result.size;
                            iscanResult.advice = result.advice;
                            iscanResult.malwareid = result.malwareid;
                            iscanResult.name = result.name;
                            iscanResult.label = result.label;
                            iscanResult.url = result.url;
                            String strScanresult = JsonUtil.killViruScanResult(x1, progress, iscanResult);
                            for (int i = 0; i < RemoteScanVirusService.this.f2951d; i++) {
                                try {
                                    ((IRemoteScanVirusCallback) RemoteScanVirusService.this.f2948a.getBroadcastItem(i)).onResult(strScanresult);
                                } catch (Exception e) {
                                    e.printStackTrace();
                                }
                            }
                        }

                        @Override // com.tencent.tmsecure.module.qscanner.QScanListener
                        public final void onScanFinished(ArrayList<QScanResultEntity> arg0) {
                            Log.i("wu0wu", "RemoteScanvirusService onScanFinished....");
                            TrackEvent.reportScanVirusWithAIDL();
                            String strScanFinished = JsonUtil.killVirusonScanFinished(x1);
                            for (int i = 0; i < RemoteScanVirusService.this.f2951d; i++) {
                                try {
                                    ((IRemoteScanVirusCallback) RemoteScanVirusService.this.f2948a.getBroadcastItem(i)).onResult(strScanFinished);
                                } catch (Exception e) {
                                    e.printStackTrace();
                                }
                            }
                            try {
                                RemoteScanVirusService.this.f2948a.finishBroadcast();
                            } catch (Exception e2) {
                                e2.printStackTrace();
                            }
                        }
                    }, false);
                }
            }
        }).start();
    }

    @Override // android.app.Service
    public void onCreate() {
        super.onCreate();
        this.f2949b = (QScannerManager) ManagerCreator.getManager(QScannerManager.class);
    }

    @Override // android.app.Service
    public void onDestroy() {
        Log.i("wu0wu", "RemoteService onDestroy()");
        if (this.f2949b != null) {
            this.f2949b.freeScanner();
        }
        this.f2948a.kill();
        super.onDestroy();
    }

    @Override // android.app.Service
    public IBinder onBind(Intent intent) {
        Log.i("wu0wu", "RemoteService onBind action=" + intent.getAction());
        return this.f2950c;
    }
}
