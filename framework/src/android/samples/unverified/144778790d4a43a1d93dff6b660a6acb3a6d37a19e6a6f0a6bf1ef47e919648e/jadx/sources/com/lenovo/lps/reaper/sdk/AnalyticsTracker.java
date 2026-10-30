package com.lenovo.lps.reaper.sdk;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageInfo;
import com.lenovo.lps.reaper.sdk.api.Event;
import com.lenovo.lps.reaper.sdk.config.Configuration;
import com.lenovo.lps.reaper.sdk.request.ConfigurationUpdateTask;
import com.lenovo.lps.reaper.sdk.request.ReportManager;
import com.lenovo.lps.reaper.sdk.request.TaskHandler;
import com.lenovo.lps.reaper.sdk.storage.EventStorage;
import com.lenovo.lps.reaper.sdk.storage.ServerConfigStorage;
import com.lenovo.lps.reaper.sdk.util.AnalyticsTrackerUtils;
import com.lenovo.lps.reaper.sdk.util.Constants;
import com.lenovo.lps.reaper.sdk.util.Messages;
import com.lenovo.lps.reaper.sdk.util.PlusUtil;
import com.lenovo.lps.reaper.sdk.util.ReaperAppManager;
import com.lenovo.lps.reaper.sdk.util.TLog;
import com.lenovo.lps.sus.p008c.C0092c;
import java.net.URL;
import java.util.List;
import org.apache.commons.httpclient.cookie.CookieSpec;

/* JADX INFO: loaded from: classes.dex */
public final class AnalyticsTracker {
    protected static AnalyticsTracker tracker;

    /* JADX INFO: renamed from: b */
    private Configuration f1075b;

    /* JADX INFO: renamed from: c */
    private ReportManager f1076c;

    /* JADX INFO: renamed from: d */
    private EventStorage f1077d;

    /* JADX INFO: renamed from: h */
    private String f1081h;

    /* JADX INFO: renamed from: i */
    private Context f1082i;

    /* JADX INFO: renamed from: j */
    private String f1083j;

    /* JADX INFO: renamed from: k */
    private String f1084k;

    /* JADX INFO: renamed from: e */
    private boolean f1078e = true;

    /* JADX INFO: renamed from: f */
    private String f1079f = "1.0";

    /* JADX INFO: renamed from: g */
    private int f1080g = 1;

    /* JADX INFO: renamed from: l */
    private byte[] f1085l = new byte[0];

    /* JADX INFO: renamed from: m */
    private BroadcastReceiver f1086m = new BroadcastReceiver() { // from class: com.lenovo.lps.reaper.sdk.AnalyticsTracker.1
        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            PlusUtil.NetworkStatus.setNetworkStatus(context);
        }
    };

    /* JADX INFO: renamed from: a */
    private final AnalyticsTrackerBuilder f1074a = AnalyticsTrackerBuilder.getInstance();

    /* JADX INFO: renamed from: a */
    static /* synthetic */ String m200a(PackageInfo x1) {
        if (x1.requestedPermissions == null) {
            return null;
        }
        String[] strArr = x1.requestedPermissions;
        StringBuilder sb = new StringBuilder(400);
        int length = 20 >= strArr.length ? strArr.length : 20;
        for (int i = 0; i < length; i++) {
            sb.append(strArr[i]).append(",");
        }
        return sb.substring(0, sb.length() - 1);
    }

    /* JADX INFO: renamed from: c */
    static /* synthetic */ void m208c(AnalyticsTracker x0) {
        synchronized (x0.f1085l) {
            try {
                if (ServerConfigStorage.DispatchStrategy.readyForReport(Constants.DispatchMode.FORCE_DISPATCH)) {
                    x0.m203a(Constants.DispatchMode.FORCE_DISPATCH);
                } else {
                    TLog.m243i("AnalyticsTracker", "not ready for reporting.");
                }
            } catch (Exception e) {
                TLog.m241e("AnalyticsTracker", "some error occured when dispatch. " + e.getMessage());
            }
        }
    }

    private AnalyticsTracker() {
    }

    public static synchronized AnalyticsTracker getInstance() {
        if (tracker == null) {
            tracker = new AnalyticsTracker();
        }
        return tracker;
    }

    public final synchronized void initialize(Context context) {
        try {
            if (this.f1078e) {
                TLog.m244v("AnalyticsTracker", "AnalyticsTracker is Initializing.................");
                this.f1082i = context.getApplicationContext();
                this.f1074a.setContext(this.f1082i);
                this.f1074a.setOnNetworkListener(this.f1086m);
                this.f1074a.readConfigFromPreferences();
                this.f1074a.initialize();
                if (!ReaperAppManager.getInstance().isTrackerInitialized()) {
                    m210d();
                }
                m201a();
                ReaperAppManager.getInstance().resetCurrentActivitySeqNumber();
                ReaperAppManager.getInstance().resetCurrentUserActionSeqNumber();
                ReaperAppManager.getInstance().setTrackerInitialized(true);
                m206b();
            }
        } catch (Exception e) {
            TLog.m241e("AnalyticsTracker", "some error occured when initital AnalyticsTracker. " + e.getMessage());
            disableReport();
        }
    }

    public final synchronized void initialize(Context context, String applicationToken, int reportIntervalInSeconds) {
        try {
            if (this.f1078e) {
                if (applicationToken == null || applicationToken.length() == 0) {
                    TLog.m241e("AnalyticsTracker", Messages.APPLICATION_TOKER_MESSAGE);
                } else {
                    TLog.m244v("AnalyticsTracker", "AnalyticsTracker is Initializing.................");
                    this.f1082i = context.getApplicationContext();
                    this.f1074a.setContext(this.f1082i);
                    this.f1074a.setOnNetworkListener(this.f1086m);
                    this.f1074a.readConfigFromPreferences();
                    this.f1074a.initialize(applicationToken, reportIntervalInSeconds);
                    if (!ReaperAppManager.getInstance().isTrackerInitialized()) {
                        m210d();
                    }
                    m201a();
                    ReaperAppManager.getInstance().resetCurrentActivitySeqNumber();
                    ReaperAppManager.getInstance().resetCurrentUserActionSeqNumber();
                    ReaperAppManager.getInstance().setTrackerInitialized(true);
                    m206b();
                }
            }
        } catch (Exception e) {
            TLog.m241e("AnalyticsTracker", "some error occured when initital AnalyticsTracker. " + e.getMessage());
            disableReport();
        }
    }

    /* JADX INFO: renamed from: a */
    private void m201a() {
        this.f1076c = this.f1074a.getReportManager();
        this.f1075b = this.f1074a.getConfiguration();
        this.f1077d = this.f1074a.getEventStorage();
    }

    public final boolean needReport(String category, String action) {
        try {
            if (this.f1078e && isTrackerInitialized()) {
                return this.f1075b.needReport(category, action);
            }
            return false;
        } catch (Exception e) {
            TLog.m245w("AnalyticsTracker", e.getClass() + " " + e.getMessage());
            TLog.m241e("AnalyticsTracker", "some error occured in needReport.");
            return false;
        }
    }

    public final void setParam(int index, String name, String value) {
        try {
            if (this.f1078e && isTrackerInitialized()) {
                this.f1077d.setParam(index, name, value);
            }
        } catch (Exception e) {
            TLog.m241e("AnalyticsTracker", "error in setParam. " + e.getMessage());
        }
    }

    public final void trackEvent(final String category, String action, String label, int value) {
        if (isTrackerInitialized()) {
            if (category == null || category.length() == 0) {
                TLog.m241e("AnalyticsTracker", Messages.EVENT_CATEGORY_MESSAGE);
                m207c();
                return;
            }
            if (action == null || action.length() == 0) {
                TLog.m241e("AnalyticsTracker", Messages.EVENT_ACTION_MESSAGE);
                m207c();
            } else if (!needReport(category, action)) {
                TLog.m243i("AnalyticsTracker", Messages.EVENT_NEED_NOT_SEND);
                m207c();
            } else {
                final Event event = new Event(this.f1075b.getApplicationToken(), category, action, label, value);
                event.setCustomParameters(this.f1077d.getCustomParamManager().getAllCustomParameters());
                m207c();
                TaskHandler.getInstance().addTask(new Runnable() { // from class: com.lenovo.lps.reaper.sdk.AnalyticsTracker.2
                    @Override // java.lang.Runnable
                    public final void run() {
                        try {
                            if (AnalyticsTracker.this.f1075b.checkTimestamp()) {
                                TLog.m243i("AnalyticsTracker", "add configuration update task.");
                                new ConfigurationUpdateTask(AnalyticsTracker.this.f1075b).run();
                            }
                            if (ServerConfigStorage.DeviceSendFlag.needSend()) {
                                AnalyticsTracker.this.f1077d.addEvent(event);
                                if (Constants.Event.EVENT_TYPE_INITIAL.equals(category)) {
                                    AnalyticsTracker.m208c(AnalyticsTracker.this);
                                } else {
                                    AnalyticsTracker.this.dispatch();
                                }
                            }
                        } catch (Exception e) {
                            TLog.m241e("AnalyticsTracker", "some error occurd in trackEvent.addTask" + e.getMessage());
                        }
                    }
                });
            }
        }
    }

    @Deprecated
    public final void trackActivity(String activity) {
        if (activity == null || activity.length() == 0) {
            TLog.m241e("AnalyticsTracker", Messages.ACTIVITY_EVENT_ACTION_MESSAGE);
        } else if (activity.startsWith(CookieSpec.PATH_DELIM)) {
            trackEvent(Constants.Event.EVENT_TYPE_VIEW, activity, null, 1);
        } else {
            trackEvent(Constants.Event.EVENT_TYPE_VIEW, CookieSpec.PATH_DELIM + activity, null, 1);
        }
    }

    public final void trackResume(Context context) {
        try {
            if (isTrackerInitialized()) {
                if (context == null) {
                    TLog.m241e("AnalyticsTracker", Messages.ACTIVITY_CONTEXT_MESSAGE);
                } else {
                    trackPageResume(CookieSpec.PATH_DELIM + context.getClass().getSimpleName());
                }
            }
        } catch (Exception e) {
            TLog.m241e("AnalyticsTracker", "some error occured in trackResume.");
        }
    }

    public final void trackPageResume(String pageName) {
        trackPageResume(pageName, null);
    }

    public final void trackPageResume(String pageName, String framePageName) {
        try {
            if (isTrackerInitialized()) {
                ReaperAppManager manager = ReaperAppManager.getInstance();
                manager.setRecentTrackedPageview(pageName);
                manager.addCurrentActivitySeqNumber();
                manager.addCurrentUserActionSeqNumber();
                setParam(2, Constants.Event.PAGE_QUEUE_PREFIX_IN_PARAM, String.valueOf(manager.getCurrentActivitySeqNumber()));
                if (framePageName != null) {
                    setParam(3, Constants.Event.PARAM_FRAME_PAGE, framePageName);
                }
                setParam(4, Constants.Event.USER_ACTION_QUEUE_PREFIX_IN_PARAM, String.valueOf(manager.getCurrentUserActionSeqNumber()));
                trackEvent(Constants.Event.EVENT_TYPE_VIEW, pageName, null, 2);
            }
        } catch (Exception e) {
            TLog.m241e("AnalyticsTracker", "some error occured in trackPageResume.");
        }
    }

    public final void trackPause(Context context) {
        try {
            if (isTrackerInitialized()) {
                if (context == null) {
                    TLog.m241e("AnalyticsTracker", Messages.ACTIVITY_CONTEXT_MESSAGE);
                } else {
                    trackPagePause(CookieSpec.PATH_DELIM + context.getClass().getSimpleName());
                }
            }
        } catch (Exception e) {
            TLog.m241e("AnalyticsTracker", "some error occured in trackPause.");
        }
    }

    public final void trackPagePause(String pageName) {
        trackPagePause(pageName, null);
    }

    public final void trackPagePause(String pageName, String framePageName) {
        try {
            if (isTrackerInitialized()) {
                long currentTime = System.currentTimeMillis();
                ReaperAppManager manager = ReaperAppManager.getInstance();
                if (manager.getPageViewTimeMap().containsKey(pageName)) {
                    setParam(1, pageName, String.valueOf(currentTime - manager.getPageViewTimeMap().get(pageName).longValue()));
                }
                setParam(2, Constants.Event.PAGE_QUEUE_PREFIX_IN_PARAM, String.valueOf(manager.getCurrentActivitySeqNumber()));
                if (framePageName != null) {
                    setParam(3, Constants.Event.PARAM_FRAME_PAGE, framePageName);
                }
                trackEvent(Constants.Event.EVENT_TYPE_VIEW, pageName, null, 3);
            }
        } catch (Exception e) {
            TLog.m241e("AnalyticsTracker", "some error occured in trackPagePause.");
        }
    }

    @Deprecated
    public final void trackUserAction(String userActionName) {
    }

    public final void trackUserAction(String userActionName, String pageName) {
        try {
            if (isTrackerInitialized()) {
                ReaperAppManager manager = ReaperAppManager.getInstance();
                manager.addCurrentUserActionSeqNumber();
                setParam(4, Constants.Event.USER_ACTION_QUEUE_PREFIX_IN_PARAM, String.valueOf(manager.getCurrentUserActionSeqNumber()));
                trackEvent(Constants.Event.EVENT_TYPE_USER_ACTION_NEW, userActionName, pageName, 4);
            }
        } catch (Exception e) {
            TLog.m241e("AnalyticsTracker", "some error occured in trackUserAction.");
        }
    }

    public final void trackThrowable(Throwable throwable) {
        try {
            m204a(throwable, 1);
        } catch (Exception e) {
            TLog.m241e("AnalyticsTracker", "some error occured in trackThrowable. " + e.getMessage());
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public void m204a(Throwable throwable, int flag) {
        if (throwable == null || (flag != 0 && flag != 1)) {
            TLog.m241e("AnalyticsTracker", Messages.THROWABLE_EVENT_ACTION_MESSAGE);
            m207c();
            return;
        }
        Throwable thr = throwable;
        while (thr.getCause() != null) {
            thr = thr.getCause();
        }
        String thrName = thr.getClass().getName();
        String thrMsg = thr.getMessage();
        if (thrName != null && thrName.length() != 0) {
            StringBuilder stack = new StringBuilder(4096);
            stack.append(thrMsg).append("\n");
            StackTraceElement[] arr$ = thr.getStackTrace();
            for (StackTraceElement e : arr$) {
                stack.append(e.getClassName()).append(".").append(e.getMethodName()).append("() ").append(e.getFileName()).append(C0092c.f1283N).append(e.getLineNumber()).append("\n");
            }
            String thrStack = stack.length() >= 3600 ? stack.toString().substring(0, 3600) : stack.toString();
            trackEvent(Constants.Event.EVENT_TYPE_THROWABLE, thrName, thrStack, flag);
        }
    }

    public final void trackFeedback(String contents) {
        try {
            if (isTrackerInitialized()) {
                if (contents == null || contents.length() == 0) {
                    m207c();
                } else {
                    trackEvent(Constants.Event.EVENT_TYPE_FEEDBACK, contents, this.f1075b.getPhoneNumber(), 1);
                }
            }
        } catch (Exception e) {
            TLog.m241e("AnalyticsTracker", "some error occured in trackFeedback. " + e.getMessage());
        }
    }

    /* JADX INFO: renamed from: b */
    private void m206b() {
        trackEvent(Constants.Event.EVENT_TYPE_INITIAL, "initial", "", 0);
    }

    /* JADX INFO: renamed from: c */
    private void m207c() {
        if (this.f1077d != null) {
            this.f1077d.clearCustomParameter();
        }
    }

    /* JADX WARN: Type inference failed for: r0v1, types: [com.lenovo.lps.reaper.sdk.AnalyticsTracker$3] */
    public final void trackInstalledApps(final boolean includeSystemApp) {
        if (this.f1082i == null) {
            TLog.m245w("AnalyticsTracker", "Context is Null in trackInstalledApps");
        } else {
            new Thread() { // from class: com.lenovo.lps.reaper.sdk.AnalyticsTracker.3
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    List<PackageInfo> packageInfos = AnalyticsTracker.this.f1082i.getPackageManager().getInstalledPackages(4096);
                    for (PackageInfo info : packageInfos) {
                        try {
                            AnalyticsTracker analyticsTracker = AnalyticsTracker.this;
                            String permissionString = AnalyticsTracker.m200a(info);
                            boolean isSystemApp = true;
                            if ((info.applicationInfo.flags & 128) != 0 || (info.applicationInfo.flags & 1) == 0) {
                                isSystemApp = false;
                            }
                            if (isSystemApp && includeSystemApp) {
                                AnalyticsTracker.this.setParam(1, "appVersionCode", String.valueOf(info.versionCode));
                                AnalyticsTracker.this.trackEvent(Constants.Event.EVENT_TYPE_APPINFO, info.packageName, permissionString, 0);
                            } else if (!isSystemApp) {
                                AnalyticsTracker.this.setParam(1, "appVersionCode", String.valueOf(info.versionCode));
                                AnalyticsTracker.this.trackEvent(Constants.Event.EVENT_TYPE_APPINFO, info.packageName, permissionString, 1);
                            }
                        } catch (Exception e) {
                            TLog.m241e("AnalyticsTracker", "TrackApp is Error. " + e.getMessage());
                        }
                    }
                }
            }.start();
        }
    }

    public final void setUserId(String userId) {
        if (isTrackerInitialized()) {
            if (userId == null) {
                this.f1083j = null;
                this.f1084k = null;
            } else {
                this.f1083j = AnalyticsTrackerUtils.encode(userId.trim());
                this.f1084k = "LenovoID";
            }
        }
    }

    public final void setUserId(String userId, String userIdClass) {
        if (isTrackerInitialized()) {
            if (userId == null) {
                this.f1083j = null;
                this.f1084k = null;
            } else {
                this.f1083j = AnalyticsTrackerUtils.encode(userId.trim());
                this.f1084k = userIdClass == null ? "" : AnalyticsTrackerUtils.encode(userIdClass.trim());
            }
        }
    }

    public final String getUserId() {
        return this.f1083j;
    }

    public final String getUserIdClass() {
        return this.f1084k;
    }

    public final String getVersionName() {
        return this.f1079f;
    }

    public final void setVersionName(String versionName) {
        if (versionName == null || versionName.length() == 0) {
            TLog.m241e("AnalyticsTracker", Messages.APPLICATION_VERSION_NAME_MESSAGE);
        } else {
            this.f1079f = versionName;
        }
    }

    public final int getVersionCode() {
        return this.f1080g;
    }

    public final void setVersionCode(int versionCode) {
        this.f1080g = versionCode;
    }

    public final String getReaperServerUrl() {
        return this.f1081h;
    }

    /* JADX WARN: Code duplicated, block: B:5:0x0008 A[Catch: Exception -> 0x0021, TryCatch #0 {Exception -> 0x0021, blocks: (B:3:0x0002, B:7:0x0010, B:9:0x001b, B:5:0x0008), top: B:14:0x0002 }] */
    public final void setReaperServerUrl(String reaperServerUrl) {
        if (reaperServerUrl == null) {
            TLog.m241e("AnalyticsTracker", Messages.REAPER_SERVER_URL_MESSAGE);
        } else {
            try {
                if (reaperServerUrl.length() == 0) {
                    TLog.m241e("AnalyticsTracker", Messages.REAPER_SERVER_URL_MESSAGE);
                } else {
                    new URL(reaperServerUrl);
                    this.f1081h = reaperServerUrl;
                    if (this.f1075b != null) {
                        this.f1075b.initReportAndConfigurationUrl(reaperServerUrl);
                    }
                }
            } catch (Exception e) {
                TLog.m241e("AnalyticsTracker", "some error occured when setReaperServerUrl. " + e.getMessage());
            }
        }
    }

    public final void dispatch() {
        synchronized (this.f1085l) {
            try {
                if (isTrackerInitialized()) {
                    if (ServerConfigStorage.DispatchStrategy.readyForReport(Constants.DispatchMode.NORMAL_DISPATCH)) {
                        m203a(Constants.DispatchMode.NORMAL_DISPATCH);
                    } else {
                        TLog.m243i("AnalyticsTracker", "not ready for reporting.");
                    }
                }
            } catch (Exception e) {
                TLog.m241e("AnalyticsTracker", "some error occured when dispatch. " + e.getMessage());
            }
        }
    }

    public final boolean isTrackerInitialized() {
        if (ReaperAppManager.getInstance().isTrackerInitialized()) {
            return true;
        }
        TLog.m241e("AnalyticsTracker", Messages.NOT_INITIAL_MESSAGE);
        return false;
    }

    @Deprecated
    public final void shutdown() {
    }

    public final void disableReport() {
        boolean z = this.f1074a.initialized;
        this.f1078e = false;
    }

    public final int countEvent() {
        if (ReaperAppManager.getInstance().isTrackerInitialized()) {
            return this.f1077d.countEvent();
        }
        TLog.m241e("AnalyticsTracker", Messages.NOT_INITIAL_MESSAGE);
        return 0;
    }

    /* JADX INFO: renamed from: d */
    private void m210d() {
        final Thread.UncaughtExceptionHandler defaultHandler = Thread.getDefaultUncaughtExceptionHandler();
        Thread.setDefaultUncaughtExceptionHandler(new Thread.UncaughtExceptionHandler() { // from class: com.lenovo.lps.reaper.sdk.AnalyticsTracker.4
            @Override // java.lang.Thread.UncaughtExceptionHandler
            public final void uncaughtException(Thread thread, Throwable e) {
                AnalyticsTracker.tracker.m204a(e, 0);
                defaultHandler.uncaughtException(thread, e);
            }
        });
    }

    /* JADX INFO: renamed from: a */
    private void m203a(Constants.DispatchMode dispatchMode) {
        Event[] events;
        switch (dispatchMode) {
            case NORMAL_DISPATCH:
                if (this.f1077d.countEvent() < ServerConfigStorage.DispatchStrategy.getThreshold()) {
                    TLog.m243i("AnalyticsTracker", "current number of events is not enough.");
                    return;
                }
                events = this.f1077d.fetchEvents();
                break;
            case FORCE_DISPATCH:
                events = this.f1077d.fetchEvents(200);
                break;
            default:
                return;
        }
        Event[] postedEvents = this.f1076c.postEvents(events);
        this.f1077d.deleteEvents(postedEvents);
        if (postedEvents == null || postedEvents.length == 0) {
            TLog.m243i("AnalyticsTracker", "no reported event.");
        }
    }
}
