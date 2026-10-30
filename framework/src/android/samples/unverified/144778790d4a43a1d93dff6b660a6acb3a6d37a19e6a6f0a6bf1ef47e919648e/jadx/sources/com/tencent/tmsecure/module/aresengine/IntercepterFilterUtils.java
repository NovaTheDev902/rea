package com.tencent.tmsecure.module.aresengine;

import com.tencent.tmsecure.common.ManagerCreator;

/* JADX INFO: loaded from: classes.dex */
public final class IntercepterFilterUtils {
    public static final int INTERCEPTER_MODE_ACCEPTED_ONLY_WHITELIST = 2;
    public static final int INTERCEPTER_MODE_REJECTED_ONLY_BLACKLIST = 1;
    public static final int INTERCEPTER_MODE_STANDARD = 0;

    private IntercepterFilterUtils() {
    }

    /* JADX INFO: renamed from: a */
    private static void m2602a() {
        AresEngineManager aresEngineManager = (AresEngineManager) ManagerCreator.getManager(AresEngineManager.class);
        DataFilter<T> dataFilter = aresEngineManager.findIntercepter(DataIntercepterBuilder.TYPE_INCOMING_SMS).dataFilter();
        FilterConfig config = dataFilter.getConfig();
        FilterConfig filterConfigDefalutFilterConfig = dataFilter.defalutFilterConfig();
        if (config != null) {
            filterConfigDefalutFilterConfig.set(1, config.get(1));
        }
        dataFilter.setConfig(filterConfigDefalutFilterConfig);
        DataFilter<T> dataFilter2 = aresEngineManager.findIntercepter(DataIntercepterBuilder.TYPE_OUTGOING_SMS).dataFilter();
        FilterConfig config2 = dataFilter2.getConfig();
        FilterConfig filterConfigDefalutFilterConfig2 = dataFilter2.defalutFilterConfig();
        if (config2 != null) {
            filterConfigDefalutFilterConfig2.set(1, config2.get(1));
        }
        dataFilter2.setConfig(filterConfigDefalutFilterConfig2);
        DataFilter<T> dataFilter3 = aresEngineManager.findIntercepter(DataIntercepterBuilder.TYPE_INCOMING_CALL).dataFilter();
        FilterConfig config3 = dataFilter3.getConfig();
        FilterConfig filterConfigDefalutFilterConfig3 = dataFilter3.defalutFilterConfig();
        if (config3 != null) {
            filterConfigDefalutFilterConfig3.set(1, config3.get(1));
        }
        dataFilter3.setConfig(filterConfigDefalutFilterConfig3);
        DataFilter<T> dataFilter4 = aresEngineManager.findIntercepter(DataIntercepterBuilder.TYPE_SYSTEM_CALL).dataFilter();
        FilterConfig config4 = dataFilter4.getConfig();
        FilterConfig filterConfigDefalutFilterConfig4 = dataFilter4.defalutFilterConfig();
        if (config4 != null) {
            filterConfigDefalutFilterConfig4.set(1, config4.get(1));
        }
        dataFilter4.setConfig(filterConfigDefalutFilterConfig4);
    }

    /* JADX INFO: renamed from: b */
    private static void m2603b() {
        AresEngineManager aresEngineManager = (AresEngineManager) ManagerCreator.getManager(AresEngineManager.class);
        DataFilter<T> dataFilter = aresEngineManager.findIntercepter(DataIntercepterBuilder.TYPE_INCOMING_SMS).dataFilter();
        FilterConfig config = dataFilter.getConfig();
        FilterConfig filterConfigDefalutFilterConfig = dataFilter.defalutFilterConfig();
        if (config != null) {
            filterConfigDefalutFilterConfig.set(1, config.get(1));
        }
        filterConfigDefalutFilterConfig.set(2, 3);
        filterConfigDefalutFilterConfig.set(4, 1);
        filterConfigDefalutFilterConfig.set(8, 3);
        filterConfigDefalutFilterConfig.set(16, 3);
        filterConfigDefalutFilterConfig.set(32, 2);
        filterConfigDefalutFilterConfig.set(64, 3);
        filterConfigDefalutFilterConfig.set(128, 3);
        dataFilter.setConfig(filterConfigDefalutFilterConfig);
        DataFilter<T> dataFilter2 = aresEngineManager.findIntercepter(DataIntercepterBuilder.TYPE_OUTGOING_SMS).dataFilter();
        FilterConfig config2 = dataFilter2.getConfig();
        FilterConfig filterConfigDefalutFilterConfig2 = dataFilter2.defalutFilterConfig();
        if (config2 != null) {
            filterConfigDefalutFilterConfig2.set(1, config2.get(1));
        }
        dataFilter2.setConfig(filterConfigDefalutFilterConfig2);
        DataFilter<T> dataFilter3 = aresEngineManager.findIntercepter(DataIntercepterBuilder.TYPE_INCOMING_CALL).dataFilter();
        FilterConfig config3 = dataFilter3.getConfig();
        FilterConfig filterConfigDefalutFilterConfig3 = dataFilter3.defalutFilterConfig();
        if (config3 != null) {
            filterConfigDefalutFilterConfig3.set(1, config3.get(1));
        }
        filterConfigDefalutFilterConfig3.set(2, 3);
        filterConfigDefalutFilterConfig3.set(4, 1);
        filterConfigDefalutFilterConfig3.set(8, 3);
        filterConfigDefalutFilterConfig3.set(16, 3);
        filterConfigDefalutFilterConfig3.set(32, 3);
        dataFilter3.setConfig(filterConfigDefalutFilterConfig3);
        DataFilter<T> dataFilter4 = aresEngineManager.findIntercepter(DataIntercepterBuilder.TYPE_SYSTEM_CALL).dataFilter();
        FilterConfig config4 = dataFilter4.getConfig();
        FilterConfig filterConfigDefalutFilterConfig4 = dataFilter4.defalutFilterConfig();
        if (config4 != null) {
            filterConfigDefalutFilterConfig4.set(1, config4.get(1));
        }
        filterConfigDefalutFilterConfig4.set(2, 3);
        filterConfigDefalutFilterConfig4.set(4, 1);
        filterConfigDefalutFilterConfig4.set(8, 3);
        filterConfigDefalutFilterConfig4.set(16, 3);
        filterConfigDefalutFilterConfig4.set(32, 0);
        filterConfigDefalutFilterConfig4.set(64, 3);
        filterConfigDefalutFilterConfig4.set(128, 3);
        filterConfigDefalutFilterConfig4.set(256, 2);
        dataFilter4.setConfig(filterConfigDefalutFilterConfig4);
    }

    /* JADX INFO: renamed from: c */
    private static void m2604c() {
        AresEngineManager aresEngineManager = (AresEngineManager) ManagerCreator.getManager(AresEngineManager.class);
        DataFilter<T> dataFilter = aresEngineManager.findIntercepter(DataIntercepterBuilder.TYPE_INCOMING_SMS).dataFilter();
        FilterConfig config = dataFilter.getConfig();
        FilterConfig filterConfigDefalutFilterConfig = dataFilter.defalutFilterConfig();
        if (config != null) {
            filterConfigDefalutFilterConfig.set(1, config.get(1));
        }
        filterConfigDefalutFilterConfig.set(2, 0);
        filterConfigDefalutFilterConfig.set(4, 3);
        filterConfigDefalutFilterConfig.set(8, 3);
        filterConfigDefalutFilterConfig.set(16, 3);
        filterConfigDefalutFilterConfig.set(32, 3);
        filterConfigDefalutFilterConfig.set(64, 3);
        filterConfigDefalutFilterConfig.set(128, 1);
        dataFilter.setConfig(filterConfigDefalutFilterConfig);
        DataFilter<T> dataFilter2 = aresEngineManager.findIntercepter(DataIntercepterBuilder.TYPE_OUTGOING_SMS).dataFilter();
        FilterConfig config2 = dataFilter2.getConfig();
        FilterConfig filterConfigDefalutFilterConfig2 = dataFilter2.defalutFilterConfig();
        if (config2 != null) {
            filterConfigDefalutFilterConfig2.set(1, config2.get(1));
        }
        dataFilter2.setConfig(filterConfigDefalutFilterConfig2);
        DataFilter<T> dataFilter3 = aresEngineManager.findIntercepter(DataIntercepterBuilder.TYPE_INCOMING_CALL).dataFilter();
        FilterConfig config3 = dataFilter3.getConfig();
        FilterConfig filterConfigDefalutFilterConfig3 = dataFilter3.defalutFilterConfig();
        if (config3 != null) {
            filterConfigDefalutFilterConfig3.set(1, config3.get(1));
        }
        filterConfigDefalutFilterConfig3.set(2, 0);
        filterConfigDefalutFilterConfig3.set(4, 3);
        filterConfigDefalutFilterConfig3.set(8, 3);
        filterConfigDefalutFilterConfig3.set(16, 3);
        filterConfigDefalutFilterConfig3.set(32, 1);
        dataFilter3.setConfig(filterConfigDefalutFilterConfig3);
        DataFilter<T> dataFilter4 = aresEngineManager.findIntercepter(DataIntercepterBuilder.TYPE_SYSTEM_CALL).dataFilter();
        FilterConfig config4 = dataFilter4.getConfig();
        FilterConfig filterConfigDefalutFilterConfig4 = dataFilter4.defalutFilterConfig();
        if (config4 != null) {
            filterConfigDefalutFilterConfig4.set(1, config4.get(1));
        }
        filterConfigDefalutFilterConfig4.set(2, 0);
        filterConfigDefalutFilterConfig4.set(4, 3);
        filterConfigDefalutFilterConfig4.set(8, 3);
        filterConfigDefalutFilterConfig4.set(16, 3);
        filterConfigDefalutFilterConfig4.set(32, 1);
        filterConfigDefalutFilterConfig4.set(64, 3);
        filterConfigDefalutFilterConfig4.set(128, 3);
        filterConfigDefalutFilterConfig4.set(256, 2);
        dataFilter4.setConfig(filterConfigDefalutFilterConfig4);
    }

    public static void setIntercepterMode(int i) {
        switch (i) {
            case 0:
                m2602a();
                break;
            case 1:
                m2603b();
                break;
            case 2:
                m2604c();
                break;
        }
    }
}
