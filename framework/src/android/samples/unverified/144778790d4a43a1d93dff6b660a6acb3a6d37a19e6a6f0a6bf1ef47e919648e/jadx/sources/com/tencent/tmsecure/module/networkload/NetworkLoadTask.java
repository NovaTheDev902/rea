package com.tencent.tmsecure.module.networkload;

import QQPIM.ConnectType;

/* JADX INFO: loaded from: classes.dex */
public class NetworkLoadTask {
    public static final int STATE_DELETED = 4;
    public static final int STATE_FAILED = 2;
    public static final int STATE_FINISHED = 3;
    public static final int STATE_PAUSED = 1;
    public static final int STATE_PRE = -2;
    public static final int STATE_RUNNING = 0;
    public static final int STATE_WAITING = -1;
    public String mChangeUrl;
    public long mCurrentSize;
    public String mName;
    public String mParentPath;
    public float mProgress;
    public int mSpeed;
    public Thread mThread;
    public String mUrl;
    public boolean isSupportRange = false;
    public int mState = -2;
    public long mSize = -1;
    public boolean isWaitingToPaused = false;
    public int mErrorCode = 0;
    public ConnectType mNetworkType = ConnectType.CT_NONE;
    public String mNetworkName = "";
    public String mErrorMsg = "";
    public int mErrorRssi = -1;
    public String mHostAddress = "";
    public boolean isOnChangeRetry = false;
}
