package com.lenovo.feedback2.message.protocol;

/* JADX INFO: loaded from: classes.dex */
public enum V_1 implements HeaderNames {
    AppName,
    PackageName,
    VersionCode,
    VersionName,
    Pic,
    StackTrace,
    BroadCastId,
    ResponseCode;

    public static final int protocolVersion = 1;

    /* JADX INFO: renamed from: values, reason: to resolve conflict with enum method */
    public static V_1[] valuesCustom() {
        V_1[] v_1ArrValuesCustom = values();
        int length = v_1ArrValuesCustom.length;
        V_1[] v_1Arr = new V_1[length];
        System.arraycopy(v_1ArrValuesCustom, 0, v_1Arr, 0, length);
        return v_1Arr;
    }

    @Override // com.lenovo.feedback2.message.protocol.HeaderNames
    public final int getProtocolVersion() {
        return 1;
    }
}
