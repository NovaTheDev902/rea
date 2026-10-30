package tms;

import android.content.Context;
import android.os.Bundle;
import android.os.FileObserver;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.Looper;
import android.os.Message;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.module.tools.IFileChangedListener;
import java.util.HashMap;
import org.apache.commons.httpclient.cookie.Cookie2;

/* JADX INFO: renamed from: tms.gm */
/* JADX INFO: loaded from: classes.dex */
public final class C1308gm extends BaseManager {

    /* JADX INFO: renamed from: a */
    private a f7402a;

    /* JADX INFO: renamed from: b */
    private Handler f7403b;

    /* JADX INFO: renamed from: tms.gm$a */
    final class a {

        /* JADX INFO: renamed from: b */
        private HashMap<String, FileObserver> f7405b = new HashMap<>();

        a() {
        }

        /* JADX INFO: renamed from: a */
        public final int m3424a() {
            return this.f7405b.size();
        }

        /* JADX INFO: renamed from: a */
        public final boolean m3425a(String str) {
            FileObserver fileObserver = this.f7405b.get(str);
            if (fileObserver == null) {
                return true;
            }
            fileObserver.stopWatching();
            this.f7405b.remove(str);
            return true;
        }

        /* JADX INFO: renamed from: a */
        public final boolean m3426a(String str, int i, IFileChangedListener iFileChangedListener) {
            if (iFileChangedListener == null) {
                throw new NullPointerException("the listener is null");
            }
            c cVar = C1308gm.this.new c(str, i, iFileChangedListener);
            FileObserver fileObserver = this.f7405b.get(str);
            this.f7405b.put(str, cVar);
            if (fileObserver != null) {
                fileObserver.stopWatching();
            }
            cVar.startWatching();
            return true;
        }
    }

    /* JADX INFO: renamed from: tms.gm$b */
    final class b extends Handler {

        /* JADX INFO: renamed from: b */
        private Looper f7407b;

        public b(Looper looper) {
            super(looper);
        }

        protected final void finalize() throws Throwable {
            if (this.f7407b != null) {
                this.f7407b.quit();
            }
            super.finalize();
        }

        @Override // android.os.Handler
        public final void handleMessage(Message message) {
            Bundle data = message.getData();
            ((IFileChangedListener) message.obj).onChanage(data.getInt("event"), data.getString(Cookie2.PATH));
        }
    }

    /* JADX INFO: renamed from: tms.gm$c */
    final class c extends FileObserver {

        /* JADX INFO: renamed from: b */
        private IFileChangedListener f7409b;

        public c(String str, int i, IFileChangedListener iFileChangedListener) {
            super(str, i);
            this.f7409b = iFileChangedListener;
        }

        @Override // android.os.FileObserver
        public final void onEvent(int i, String str) {
            if (this.f7409b == null || C1308gm.this.f7403b == null) {
                return;
            }
            Message messageObtainMessage = C1308gm.this.f7403b.obtainMessage(0);
            messageObtainMessage.obj = this.f7409b;
            Bundle bundle = new Bundle();
            bundle.putInt("event", i);
            bundle.putString(Cookie2.PATH, str);
            messageObtainMessage.setData(bundle);
            messageObtainMessage.sendToTarget();
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m3422a(String str) {
        this.f7402a.m3425a(str);
        if (this.f7402a.m3424a() == 0) {
            synchronized (b.class) {
                this.f7403b.removeMessages(0);
                this.f7403b = null;
            }
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m3423a(String str, int i, IFileChangedListener iFileChangedListener) {
        this.f7402a.m3426a(str, i, iFileChangedListener);
        synchronized (b.class) {
            if (this.f7403b == null) {
                HandlerThread handlerThread = new HandlerThread(C1308gm.class.getName());
                handlerThread.start();
                this.f7403b = new b(handlerThread.getLooper());
            }
        }
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final int getSingletonType() {
        return 1;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f7402a = new a();
    }
}
