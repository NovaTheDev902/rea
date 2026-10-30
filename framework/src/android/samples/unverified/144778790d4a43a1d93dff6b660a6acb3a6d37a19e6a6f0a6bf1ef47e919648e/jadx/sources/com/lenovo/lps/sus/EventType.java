package com.lenovo.lps.sus;

/* JADX INFO: loaded from: classes.dex */
public enum EventType {
    SUS_FAIL_NETWORKUNAVAILABLE,
    SUS_FAIL_NOWLANCONNECTED,
    SUS_FAIL_INSUFFICIENTSTORAGESPACE,
    SUS_FAIL_DOWNOLADFOLDER_FOLDER_NOTEXIST,
    SUS_FAIL_DOWNLOAD_EXCEPTION,
    SUS_WARNING_PENDING,
    SUS_DOWNLOADSTART,
    SUS_DOWNLOADCOMPLETE,
    SUS_QUERY_RESP,
    SUS_TESTSERVER_RESP,
    SUS_UPDATEPROMPT_USER_CONFIRM,
    SUS_UPDATEPROMPT_USER_CANCEL,
    SUS_ABORTDOWNLOAD_BYUSER,
    SUS_SILENCEINSTALL_FINISH,
    SUS_SILENCEINSTALL_FAIL;

    /* JADX INFO: renamed from: values, reason: to resolve conflict with enum method */
    public static EventType[] valuesCustom() {
        EventType[] eventTypeArrValuesCustom = values();
        int length = eventTypeArrValuesCustom.length;
        EventType[] eventTypeArr = new EventType[length];
        System.arraycopy(eventTypeArrValuesCustom, 0, eventTypeArr, 0, length);
        return eventTypeArr;
    }
}
