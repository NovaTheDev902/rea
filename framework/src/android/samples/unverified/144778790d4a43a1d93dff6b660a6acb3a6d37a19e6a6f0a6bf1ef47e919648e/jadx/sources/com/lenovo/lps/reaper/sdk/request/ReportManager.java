package com.lenovo.lps.reaper.sdk.request;

import com.lenovo.lps.reaper.sdk.api.Event;
import com.lenovo.lps.reaper.sdk.util.TLog;

/* JADX INFO: loaded from: classes.dex */
public class ReportManager {

    /* JADX INFO: renamed from: a */
    private HttpRequestHandler f1145a;

    public Event[] postEvents(Event[] events) {
        if (events == null || events.length == 0) {
            return null;
        }
        TLog.m243i("ReportManager", "start postEvents");
        return this.f1145a.postEvents(events);
    }

    public void setHttpRequestHandler(HttpRequestHandler httpRequestHandler) {
        this.f1145a = httpRequestHandler;
    }
}
