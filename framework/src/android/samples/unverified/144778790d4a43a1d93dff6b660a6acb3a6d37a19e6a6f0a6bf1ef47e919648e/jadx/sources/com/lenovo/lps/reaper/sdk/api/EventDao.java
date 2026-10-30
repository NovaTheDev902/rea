package com.lenovo.lps.reaper.sdk.api;

/* JADX INFO: loaded from: classes.dex */
public interface EventDao {
    void activeSession();

    int countEvent();

    boolean deleteEvents(Event[] eventArr);

    Event[] getEvents();

    Event[] getEvents(int i);

    void saveEvent(Event event);

    void truncate(long j);
}
