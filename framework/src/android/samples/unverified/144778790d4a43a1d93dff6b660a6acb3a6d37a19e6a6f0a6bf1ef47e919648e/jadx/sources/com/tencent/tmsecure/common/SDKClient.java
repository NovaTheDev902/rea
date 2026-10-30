package com.tencent.tmsecure.common;

import android.os.IBinder;
import android.os.RemoteException;
import java.util.concurrent.ConcurrentLinkedQueue;

/* JADX INFO: loaded from: classes.dex */
public final class SDKClient extends ISDKClient.Stub {

    /* JADX INFO: renamed from: a */
    private static ConcurrentLinkedQueue<MessageHandler> f6039a = new ConcurrentLinkedQueue<>();

    /* JADX INFO: renamed from: b */
    private static volatile SDKClient f6040b = null;

    private SDKClient() {
    }

    public static boolean addMessageHandler(MessageHandler messageHandler) {
        return f6039a.add(messageHandler);
    }

    public static SDKClient getInstance() {
        if (f6040b == null) {
            synchronized (SDKClient.class) {
                if (f6040b == null) {
                    f6040b = new SDKClient();
                }
            }
        }
        return f6040b;
    }

    public static boolean removeMessageHandler(MessageHandler messageHandler) {
        return f6039a.remove(messageHandler);
    }

    @Override // com.tencent.tmsecure.common.ISDKClient.Stub, android.os.IInterface
    public final IBinder asBinder() {
        return this;
    }

    @Override // com.tencent.tmsecure.common.ISDKClient
    public final DataEntity sendMessage(DataEntity dataEntity) throws RemoteException {
        int iWhat = dataEntity.what();
        for (MessageHandler messageHandler : f6039a) {
            if (messageHandler.isMatch(iWhat)) {
                return messageHandler.onProcessing(dataEntity);
            }
        }
        return null;
    }
}
