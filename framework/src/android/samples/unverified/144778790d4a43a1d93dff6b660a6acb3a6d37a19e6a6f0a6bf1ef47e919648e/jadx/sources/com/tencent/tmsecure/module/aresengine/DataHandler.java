package com.tencent.tmsecure.module.aresengine;

import android.os.Handler;
import android.os.HandlerThread;
import android.os.Looper;
import android.os.Message;
import java.util.Iterator;
import java.util.concurrent.ConcurrentLinkedQueue;

/* JADX INFO: loaded from: classes.dex */
public class DataHandler extends Handler {

    /* JADX INFO: renamed from: a */
    protected static final int f6079a = 3456;

    /* JADX INFO: renamed from: b */
    private static final Looper f6080b;

    /* JADX INFO: renamed from: c */
    private ConcurrentLinkedQueue<DataHandlerCallback> f6081c;

    public interface DataHandlerCallback {
        void onCallback(TelephonyEntity telephonyEntity, int i, int i2, Object... objArr);
    }

    static {
        HandlerThread handlerThread = new HandlerThread(DataHandler.class.getName());
        handlerThread.start();
        f6080b = handlerThread.getLooper();
    }

    public DataHandler() {
        super(f6080b);
        this.f6081c = new ConcurrentLinkedQueue<>();
    }

    public final void addCallback(DataHandlerCallback dataHandlerCallback) {
        this.f6081c.add(dataHandlerCallback);
    }

    @Override // android.os.Handler
    public void handleMessage(Message message) {
        if (message.what == f6079a) {
            FilterResult filterResult = (FilterResult) message.obj;
            Iterator<Runnable> it = filterResult.mDotos.iterator();
            while (it.hasNext()) {
                it.next().run();
            }
            TelephonyEntity telephonyEntity = filterResult.mData;
            int i = filterResult.mFilterfiled;
            int i2 = filterResult.mState;
            Object[] objArr = filterResult.mParams;
            Iterator<DataHandlerCallback> it2 = this.f6081c.iterator();
            while (it2.hasNext()) {
                it2.next().onCallback(telephonyEntity, i, i2, objArr);
            }
        }
    }

    public final void removeCallback(DataHandlerCallback dataHandlerCallback) {
        this.f6081c.remove(dataHandlerCallback);
    }

    public synchronized void sendMessage(FilterResult filterResult) {
        if (filterResult != null) {
            Message messageObtainMessage = obtainMessage(f6079a);
            messageObtainMessage.obj = filterResult;
            messageObtainMessage.sendToTarget();
        }
    }
}
