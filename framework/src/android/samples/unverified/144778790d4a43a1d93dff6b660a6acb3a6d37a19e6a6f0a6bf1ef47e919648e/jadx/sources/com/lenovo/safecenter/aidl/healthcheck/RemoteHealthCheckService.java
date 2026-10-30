package com.lenovo.safecenter.aidl.healthcheck;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteCallbackList;
import android.os.RemoteException;
import android.text.TextUtils;
import android.util.Log;
import com.lenovo.safecenter.HealthCheck.HealthCheckCallback;
import com.lenovo.safecenter.HealthCheck.HealthItemResult;
import com.lenovo.safecenter.HealthCheck.HealthManager;
import com.lenovo.safecenter.HealthCheck.util.HealthStatus;
import com.lenovo.safecenter.HealthCheck.util.HealthViewType;
import com.lenovo.safecenter.aidl.JsonUtil;
import com.lenovo.safecenter.floatwindow.util.SettingUtil;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.ArrayList;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import org.json.JSONTokener;

/* JADX INFO: loaded from: classes.dex */
public class RemoteHealthCheckService extends Service {
    public static final String COMMAND_ACTION_HEALTH_CANCEL_OPTIMIZE = "health_canceloptimize";
    public static final String COMMAND_ACTION_HEALTH_CANCEL_SCAN = "health_cancelscan";
    public static final String COMMAND_ACTION_HEALTH_OPTIMIZE = "health_optimize";
    public static final String COMMAND_ACTION_HEALTH_SCAN = "health_scan";

    /* JADX INFO: renamed from: b */
    private HealthManager f2939b;

    /* JADX INFO: renamed from: f */
    private String f2943f;

    /* JADX INFO: renamed from: a */
    final RemoteCallbackList<IRemoteHealthCheckCallback> f2938a = new RemoteCallbackList<>();

    /* JADX INFO: renamed from: c */
    private final IRemoteHealthCheckService.Stub f2940c = new IRemoteHealthCheckService.Stub() { // from class: com.lenovo.safecenter.aidl.healthcheck.RemoteHealthCheckService.1
        @Override // com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckService
        public final void registerCallback(IRemoteHealthCheckCallback cb) {
            if (cb != null) {
                RemoteHealthCheckService.this.f2938a.register(cb);
            }
        }

        @Override // com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckService
        public final void unregisterCallback(IRemoteHealthCheckCallback cb) {
            if (cb != null) {
                RemoteHealthCheckService.this.f2938a.unregister(cb);
            }
        }

        @Override // com.lenovo.safecenter.aidl.healthcheck.IRemoteHealthCheckService
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
                    if (RemoteHealthCheckService.COMMAND_ACTION_HEALTH_SCAN.equals(action)) {
                        RemoteHealthCheckService.m1284a(RemoteHealthCheckService.this, context);
                        return;
                    }
                    if (RemoteHealthCheckService.COMMAND_ACTION_HEALTH_CANCEL_SCAN.equals(action)) {
                        RemoteHealthCheckService.m1283a(RemoteHealthCheckService.this);
                        return;
                    }
                    if (RemoteHealthCheckService.COMMAND_ACTION_HEALTH_OPTIMIZE.equals(action)) {
                        ArrayList<Integer> keysList = new ArrayList<>();
                        if (object.has(SettingUtil.DATA)) {
                            JSONObject data = (JSONObject) object.get(SettingUtil.DATA);
                            if (data.has("keys")) {
                                JSONArray keys = data.getJSONArray("keys");
                                for (int i = 0; i < keys.length(); i++) {
                                    try {
                                        int key = ((Integer) keys.get(i)).intValue();
                                        Log.i("wu0wu", "health_optimize key=" + key);
                                        keysList.add(Integer.valueOf(key));
                                    } catch (Exception e) {
                                    }
                                }
                            }
                        }
                        Log.i("wu0wu", "aidl doOptimize");
                        RemoteHealthCheckService.m1285a(RemoteHealthCheckService.this, context, keysList);
                        return;
                    }
                    if (RemoteHealthCheckService.COMMAND_ACTION_HEALTH_CANCEL_OPTIMIZE.equals(action)) {
                        RemoteHealthCheckService.m1286b(RemoteHealthCheckService.this);
                    }
                }
            } catch (JSONException e2) {
                Log.i("wu0wu", "aidl JSONException");
                e2.printStackTrace();
            }
        }
    };

    /* JADX INFO: renamed from: d */
    private HealthCheckCallback f2941d = new HealthCheckCallback() { // from class: com.lenovo.safecenter.aidl.healthcheck.RemoteHealthCheckService.2
        @Override // com.lenovo.safecenter.HealthCheck.HealthCheckCallback
        public final void setProgressBarIndeterminate(boolean isIndeterminate) {
        }

        @Override // com.lenovo.safecenter.HealthCheck.HealthCheckCallback
        public final void onProgressChanged(int progress) {
            Log.i("wu0wu", "onProgressChanged progress=" + progress);
            String strProgressChanged = JsonUtil.healthProgressChanged(progress, RemoteHealthCheckService.this.f2943f);
            for (int i = 0; i < RemoteHealthCheckService.this.f2942e; i++) {
                try {
                    ((IRemoteHealthCheckCallback) RemoteHealthCheckService.this.f2938a.getBroadcastItem(i)).onResult(strProgressChanged);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }

        @Override // com.lenovo.safecenter.HealthCheck.HealthCheckCallback
        public final void onScoreChanged(int score) {
            Log.i("wu0wu", "onScoreChanged score=" + score);
            String strScoreChanged = JsonUtil.healthScoreChanged(score, RemoteHealthCheckService.this.f2943f);
            for (int i = 0; i < RemoteHealthCheckService.this.f2942e; i++) {
                try {
                    ((IRemoteHealthCheckCallback) RemoteHealthCheckService.this.f2938a.getBroadcastItem(i)).onResult(strScoreChanged);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }

        @Override // com.lenovo.safecenter.HealthCheck.HealthCheckCallback
        public final void onStatusChanged(int statusId) {
            Log.i("wu0wu", "onStatusChanged statusId=" + statusId);
            String strStatusChanged = JsonUtil.healthStatusChanged(statusId, RemoteHealthCheckService.this.f2943f);
            for (int i = 0; i < RemoteHealthCheckService.this.f2942e; i++) {
                try {
                    ((IRemoteHealthCheckCallback) RemoteHealthCheckService.this.f2938a.getBroadcastItem(i)).onResult(strStatusChanged);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }

        @Override // com.lenovo.safecenter.HealthCheck.HealthCheckCallback
        public final void onStarted(int maxProgress, int action) {
            Log.i("wu0wu", "RemoteHealthCheckService onScanStarted....");
            Log.i("wu0wu", "onStarted maxProgress=" + maxProgress);
            try {
                RemoteHealthCheckService.this.f2942e = RemoteHealthCheckService.this.f2938a.beginBroadcast();
                Log.i("wu0wu", "onStarted mCallbacks.beginBroadcast() N=" + RemoteHealthCheckService.this.f2942e);
            } catch (Exception e) {
                e.printStackTrace();
            }
            String strstarted = action == 0 ? JsonUtil.healthScanStarted(RemoteHealthCheckService.this.f2943f, maxProgress, HealthStatus.getStatus(RemoteHealthCheckService.this.getApplicationContext()), HealthViewType.getViewTypes(RemoteHealthCheckService.this.getApplicationContext())) : JsonUtil.healthOptimizesStarted(RemoteHealthCheckService.this.f2943f);
            for (int i = 0; i < RemoteHealthCheckService.this.f2942e; i++) {
                try {
                    ((IRemoteHealthCheckCallback) RemoteHealthCheckService.this.f2938a.getBroadcastItem(i)).onResult(strstarted);
                } catch (Exception e2) {
                    e2.printStackTrace();
                }
            }
        }

        @Override // com.lenovo.safecenter.HealthCheck.HealthCheckCallback
        public final void onOneItemProcess(HealthItemResult result) {
            Log.i("wu0wu", "onOneItemProcess ");
            String strProcessing = JsonUtil.healthProcessing(result, RemoteHealthCheckService.this.f2943f);
            for (int i = 0; i < RemoteHealthCheckService.this.f2942e; i++) {
                try {
                    ((IRemoteHealthCheckCallback) RemoteHealthCheckService.this.f2938a.getBroadcastItem(i)).onResult(strProcessing);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }

        @Override // com.lenovo.safecenter.HealthCheck.HealthCheckCallback
        public final void onResult(HealthItemResult result) {
            Log.i("wu0wu", "onResult ");
            String strScanresult = JsonUtil.healthProcessed(result, RemoteHealthCheckService.this.f2943f);
            for (int i = 0; i < RemoteHealthCheckService.this.f2942e; i++) {
                try {
                    ((IRemoteHealthCheckCallback) RemoteHealthCheckService.this.f2938a.getBroadcastItem(i)).onResult(strScanresult);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }

        @Override // com.lenovo.safecenter.HealthCheck.HealthCheckCallback
        public final void onFinished(int action) {
            Log.i("wu0wu", "RemoteHealthCheckService onScanFinished....");
            String strScanFinished = action == 0 ? JsonUtil.healthScanFinished(RemoteHealthCheckService.this.f2943f) : JsonUtil.healthOptimizeComplete(RemoteHealthCheckService.this.f2943f);
            for (int i = 0; i < RemoteHealthCheckService.this.f2942e; i++) {
                try {
                    ((IRemoteHealthCheckCallback) RemoteHealthCheckService.this.f2938a.getBroadcastItem(i)).onResult(strScanFinished);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
            try {
                RemoteHealthCheckService.this.f2938a.finishBroadcast();
            } catch (Exception e2) {
                e2.printStackTrace();
            }
        }
    };

    /* JADX INFO: renamed from: e */
    private int f2942e = 0;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1283a(RemoteHealthCheckService x0) {
        Log.i("wu0wu", "RemoteScanvirusService doCancelScan....");
        x0.f2939b.exit();
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1284a(RemoteHealthCheckService x0, String x1) {
        x0.f2939b = new HealthManager(x0.getApplicationContext(), true);
        x0.f2943f = x1;
        TrackEvent.reportHealthcheckWithAIDL();
        x0.f2939b.scan(x0.f2941d);
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1285a(RemoteHealthCheckService x0, String x1, ArrayList x2) {
        x0.f2943f = x1;
        x0.f2939b.optimize(x2);
    }

    /* JADX INFO: renamed from: b */
    static /* synthetic */ void m1286b(RemoteHealthCheckService x0) {
        Log.i("wu0wu", "RemoteScanvirusService doCancelOptimize....");
        x0.f2939b.exit();
    }

    @Override // android.app.Service
    public void onCreate() {
        super.onCreate();
    }

    @Override // android.app.Service
    public void onDestroy() {
        Log.i("wu0wu", "RemoteService onDestroy()");
        this.f2938a.kill();
        super.onDestroy();
    }

    @Override // android.app.Service
    public IBinder onBind(Intent intent) {
        Log.i("wu0wu", "RemoteService onBind action=" + intent.getAction());
        return this.f2940c;
    }
}
