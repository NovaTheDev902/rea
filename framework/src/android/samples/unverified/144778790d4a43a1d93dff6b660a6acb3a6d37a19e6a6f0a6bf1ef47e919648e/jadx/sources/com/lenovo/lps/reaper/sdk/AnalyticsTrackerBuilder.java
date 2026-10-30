package com.lenovo.lps.reaper.sdk;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.net.ConnectivityManager;
import com.lenovo.lps.reaper.sdk.api.EventDao;
import com.lenovo.lps.reaper.sdk.config.Configuration;
import com.lenovo.lps.reaper.sdk.request.HttpRequestHandler;
import com.lenovo.lps.reaper.sdk.request.ReaperServerAddressQueryTask;
import com.lenovo.lps.reaper.sdk.request.ReportManager;
import com.lenovo.lps.reaper.sdk.request.TaskHandler;
import com.lenovo.lps.reaper.sdk.storage.EventStorage;
import com.lenovo.lps.reaper.sdk.storage.FileEventDaoImpl;
import com.lenovo.lps.reaper.sdk.storage.FileStorage;
import com.lenovo.lps.reaper.sdk.storage.FileStorageMeta;
import com.lenovo.lps.reaper.sdk.storage.ServerConfigStorage;
import com.lenovo.lps.reaper.sdk.util.Constants;
import com.lenovo.lps.reaper.sdk.util.PlusUtil;
import com.lenovo.lps.reaper.sdk.util.TLog;
import java.util.Map;

/* JADX INFO: loaded from: classes.dex */
public class AnalyticsTrackerBuilder {

    /* JADX INFO: renamed from: a */
    private static AnalyticsTrackerBuilder f1096a = new AnalyticsTrackerBuilder();
    protected Configuration configuration;
    protected ConnectivityManager connectivityManager;
    protected Context context;
    protected EventStorage eventStorage;
    protected FileStorageMeta fileStorageMeta;
    protected boolean initialized;
    protected ReportManager reportManager;
    protected Runnable rescheduleTask;

    public static AnalyticsTrackerBuilder getInstance() {
        return f1096a;
    }

    public void setContext(Context context) {
        this.context = context;
    }

    public void initialize() throws Throwable {
        if (this.initialized) {
            TLog.m244v("AnalyticsTrackerBuilder", "reinitialize");
            reinitialize();
        } else {
            TLog.m244v("AnalyticsTrackerBuilder", "internalInitialize");
            this.initialized = true;
            internalInitialize();
        }
        TLog.m243i("AnalyticsTrackerBuilder", "AnalyticsTrackerBuilder initialized");
    }

    public void initialize(String applicationToken, int reportIntervalInSeconds) throws Throwable {
        if (this.initialized) {
            reinitialize();
        } else {
            this.initialized = true;
            internalInitialize(applicationToken, reportIntervalInSeconds);
        }
        TLog.m243i("AnalyticsTrackerBuilder", "AnalyticsTrackerBuilder initialized");
    }

    protected void internalInitialize() throws Throwable {
        initializeConfiguration();
        initializeOthers();
    }

    protected void internalInitialize(String applicationToken, int reportIntervalInSeconds) throws Throwable {
        initializeConfiguration(applicationToken, reportIntervalInSeconds);
        initializeOthers();
    }

    protected void initializeOthers() {
        initializeReportManager();
        initializeEventStorage();
        TaskHandler.getInstance().addTask(new Runnable() { // from class: com.lenovo.lps.reaper.sdk.AnalyticsTrackerBuilder.1
            @Override // java.lang.Runnable
            public final void run() {
                new ReaperServerAddressQueryTask(AnalyticsTrackerBuilder.this.configuration).run();
            }
        });
    }

    protected void initializeEventStorage() {
        this.eventStorage = new EventStorage();
        EventDao eventDao = createEventDao();
        this.eventStorage.setEventDao(eventDao);
        this.eventStorage.initialize();
    }

    protected EventDao createEventDao() {
        FileEventDaoImpl eventDao = new FileEventDaoImpl();
        FileStorage fileStorage = new FileStorage("lenovo_reaper.db6", this.context);
        this.fileStorageMeta = new FileStorageMeta(1000);
        eventDao.setMeta(this.fileStorageMeta);
        eventDao.setFileStorage(fileStorage);
        return eventDao;
    }

    protected void initializeConfiguration() throws Throwable {
        this.configuration = createConfiguration();
        this.configuration.initialize();
    }

    protected void initializeConfiguration(String applicationToken, int reportIntervalInSeconds) throws Throwable {
        this.configuration = createConfiguration();
        this.configuration.initialize(applicationToken, reportIntervalInSeconds);
    }

    protected Configuration createConfiguration() {
        return new Configuration(this.context);
    }

    protected void initializeReportManager() {
        this.reportManager = createReportManager();
        this.connectivityManager = (ConnectivityManager) this.context.getSystemService("connectivity");
        HttpRequestHandler httpRequestHandler = createHttpRequestHandler();
        httpRequestHandler.setConfiguration(this.configuration);
        this.reportManager.setHttpRequestHandler(httpRequestHandler);
    }

    protected HttpRequestHandler createHttpRequestHandler() {
        HttpRequestHandler httpRequestHandler = new HttpRequestHandler();
        return httpRequestHandler;
    }

    protected ReportManager createReportManager() {
        return new ReportManager();
    }

    public ReportManager getReportManager() {
        return this.reportManager;
    }

    public Configuration getConfiguration() {
        return this.configuration;
    }

    public EventStorage getEventStorage() {
        return this.eventStorage;
    }

    public void reinitialize() {
        this.eventStorage.initialize();
    }

    public boolean isInitialized() {
        return this.initialized;
    }

    public void readConfigFromPreferences() {
        try {
            TLog.m244v("AnalyticsTrackerBuilder", "Reading Configuration From Preferences...");
            SharedPreferences sharedPreferences = this.context.getSharedPreferences(Constants.SharedPreference.COMMON, 0);
            Map<String, ?> map = sharedPreferences.getAll();
            for (Map.Entry<String, ?> entry : map.entrySet()) {
                ServerConfigStorage.put(entry.getKey(), ((Boolean) entry.getValue()).booleanValue());
            }
            SharedPreferences sharedPreferences2 = this.context.getSharedPreferences(Constants.SharedPreference.CONFIGUPDATE, 0);
            long timestampMills = sharedPreferences2.getLong(Constants.ServerConfig.UpdateStrategy.CATEGORY_UPDATE, 0L);
            ServerConfigStorage.setTimestampMills(timestampMills);
        } catch (Exception e) {
            TLog.m241e("AnalyticsTrackerBuilder", "read config from preferences error. " + e.getMessage());
        }
    }

    public void setOnNetworkListener(BroadcastReceiver networkReceiver) {
        TLog.m244v("AnalyticsTrackerBuilder", "Setting On Network Listener...");
        IntentFilter mIntenFilter = new IntentFilter("android.net.conn.CONNECTIVITY_CHANGE");
        PlusUtil.NetworkStatus.setNetworkStatus(this.context);
        this.context.registerReceiver(networkReceiver, mIntenFilter);
    }
}
