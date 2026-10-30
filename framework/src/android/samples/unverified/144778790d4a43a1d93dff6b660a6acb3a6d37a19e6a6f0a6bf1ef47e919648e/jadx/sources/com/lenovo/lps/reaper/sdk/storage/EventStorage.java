package com.lenovo.lps.reaper.sdk.storage;

import com.lenovo.lps.reaper.sdk.api.CustomParameterManager;
import com.lenovo.lps.reaper.sdk.api.Event;
import com.lenovo.lps.reaper.sdk.api.EventDao;

/* JADX INFO: loaded from: classes.dex */
public final class EventStorage {

    /* JADX INFO: renamed from: a */
    private EventDao f1152a;

    /* JADX INFO: renamed from: b */
    private CustomParameterManager f1153b = new CustomParameterManager();

    public final Event[] fetchEvents() {
        return this.f1152a.getEvents();
    }

    public final Event[] fetchEvents(int count) {
        return this.f1152a.getEvents(count);
    }

    public final void addEvent(Event event) {
        this.f1152a.saveEvent(event);
    }

    public final void clearCustomParameter() {
        this.f1153b.clear();
    }

    public final void initialize() {
        this.f1152a.activeSession();
    }

    public final void setParam(int index, String name, String value) {
        this.f1153b.setCustomParameter(index, name, value);
    }

    public final void setEventDao(EventDao eventDao) {
        this.f1152a = eventDao;
    }

    public final void deleteEvents(Event[] events) {
        if (events != null && events.length > 0) {
            this.f1152a.deleteEvents(events);
        }
    }

    public final int countEvent() {
        return this.f1152a.countEvent();
    }

    public final boolean isEmpty() {
        return this.f1152a.countEvent() == 0;
    }

    public final void truncate(long size) {
        try {
            this.f1152a.truncate(size);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public final CustomParameterManager getCustomParamManager() {
        return this.f1153b;
    }
}
