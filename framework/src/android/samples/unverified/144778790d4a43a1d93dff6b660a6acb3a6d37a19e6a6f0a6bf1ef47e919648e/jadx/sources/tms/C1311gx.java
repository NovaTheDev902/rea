package tms;

import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.module.tools.ISingleton;
import java.util.HashMap;

/* JADX INFO: renamed from: tms.gx */
/* JADX INFO: loaded from: classes.dex */
public final class C1311gx extends BaseManager {

    /* JADX INFO: renamed from: a */
    private final HashMap<Class<? extends ISingleton>, ISingleton> f7421a = new HashMap<>();

    /* JADX INFO: renamed from: a */
    public final <T extends ISingleton> T m3436a(Class<T> cls) {
        ISingleton iSingletonNewInstance = this.f7421a.get(cls);
        if (iSingletonNewInstance == null) {
            synchronized (cls) {
                iSingletonNewInstance = this.f7421a.get(cls);
                if (iSingletonNewInstance == null) {
                    try {
                        iSingletonNewInstance = cls.newInstance();
                        if (iSingletonNewInstance != null) {
                            iSingletonNewInstance.onCreate();
                            this.f7421a.put(cls, iSingletonNewInstance);
                        }
                    } catch (Exception e) {
                        ISingleton iSingleton = iSingletonNewInstance;
                        e.printStackTrace();
                        iSingletonNewInstance = iSingleton;
                    }
                }
            }
        }
        return cls.cast(iSingletonNewInstance);
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final int getSingletonType() {
        return 1;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
    }
}
