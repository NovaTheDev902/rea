package tms;

import android.os.Binder;
import com.tencent.tmsecure.module.networkload.INetworkLoadTaskDao;
import com.tencent.tmsecure.module.networkload.NetworkLoadTask;
import com.tencent.tmsecure.module.networkload.NetworkLoadTaskListener;
import java.lang.ref.WeakReference;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: Access modifiers changed from: package-private */
/* JADX INFO: renamed from: tms.df */
/* JADX INFO: loaded from: classes.dex */
public abstract class AbstractBinderC1230df<T extends NetworkLoadTask> extends Binder {

    /* JADX INFO: renamed from: a */
    private List<T> f7096a;

    /* JADX INFO: renamed from: b */
    private List<T> f7097b;

    /* JADX INFO: renamed from: c */
    private List<T> f7098c;

    /* JADX INFO: renamed from: d */
    private List<T> f7099d;

    /* JADX INFO: renamed from: e */
    private List<T> f7100e;

    /* JADX INFO: renamed from: h */
    private INetworkLoadTaskDao<T> f7103h;

    /* JADX INFO: renamed from: f */
    private byte f7101f = 3;

    /* JADX INFO: renamed from: g */
    private List<WeakReference<NetworkLoadTaskListener<T>>> f7102g = new ArrayList(this.f7101f);

    /* JADX INFO: renamed from: i */
    private byte[] f7104i = new byte[0];

    AbstractBinderC1230df() {
    }

    /* JADX INFO: renamed from: a */
    private void m3106a() {
        this.f7096a = new ArrayList();
        this.f7097b = new ArrayList();
        this.f7098c = new ArrayList();
        this.f7100e = new ArrayList();
        this.f7099d = new ArrayList();
        List<T> all = this.f7103h.getAll();
        if (all == null || all.size() == 0) {
            return;
        }
        for (T t : all) {
            switch (t.mState) {
                case 1:
                    if (!this.f7098c.contains(t)) {
                        this.f7098c.add(t);
                    }
                    break;
                case 2:
                    if (!this.f7099d.contains(t)) {
                        this.f7099d.add(t);
                    }
                    break;
                case 3:
                    if (!this.f7100e.contains(t)) {
                        this.f7100e.add(t);
                    }
                    break;
                default:
                    t.mState = 1;
                    if (!this.f7098c.contains(t)) {
                        this.f7098c.add(t);
                    }
                    break;
            }
        }
    }

    /* JADX INFO: renamed from: b */
    private synchronized void m3107b() {
        int i = 0;
        while (i < this.f7096a.size()) {
            T t = this.f7096a.get(i);
            if (t.mState == 3) {
                if (!this.f7100e.contains(t)) {
                    this.f7100e.add(t);
                }
                this.f7096a.remove(i);
            } else if (t.isOnChangeRetry) {
                if (t.mState != 0) {
                    i++;
                } else if (t.mThread.isAlive()) {
                    i++;
                } else {
                    try {
                        t.mThread.start();
                    } catch (IllegalThreadStateException e) {
                    }
                }
            } else if (t.mState == 2) {
                if (!this.f7099d.contains(t)) {
                    this.f7099d.add(t);
                }
                this.f7096a.remove(i);
            } else {
                i++;
            }
        }
        while (this.f7096a.size() < this.f7101f && this.f7097b.size() > 0) {
            T t2 = this.f7097b.get(0);
            this.f7097b.remove(0);
            if (!this.f7096a.contains(t2)) {
                this.f7096a.add(t2);
                if (t2.mThread != null) {
                    t2.mThread.start();
                }
            }
        }
    }

    /* JADX INFO: renamed from: a */
    void m3108a(T t) {
        ArrayList arrayList = new ArrayList(1);
        arrayList.add(t);
        m3109a(arrayList);
    }

    /* JADX INFO: renamed from: a */
    void m3109a(List<T> list) {
        boolean z = list.size() > 1;
        if (this.f7102g == null || this.f7102g.size() == 0) {
            return;
        }
        ArrayList arrayList = new ArrayList(this.f7102g);
        switch (list.get(0).mState) {
            case -1:
                Iterator it = arrayList.iterator();
                while (it.hasNext()) {
                    NetworkLoadTaskListener networkLoadTaskListener = (NetworkLoadTaskListener) ((WeakReference) it.next()).get();
                    if (networkLoadTaskListener != null) {
                        if (z) {
                            networkLoadTaskListener.onWaiting(list);
                        } else {
                            networkLoadTaskListener.onWaiting(list.get(0));
                        }
                    }
                }
                break;
            case 0:
                this.f7103h.update(list.get(0));
                Iterator it2 = arrayList.iterator();
                while (it2.hasNext()) {
                    NetworkLoadTaskListener networkLoadTaskListener2 = (NetworkLoadTaskListener) ((WeakReference) it2.next()).get();
                    if (networkLoadTaskListener2 != null) {
                        networkLoadTaskListener2.onRunning(list.get(0));
                    }
                }
                break;
            case 1:
                if (z) {
                    this.f7103h.update(list, 1);
                } else {
                    this.f7103h.update(list.get(0));
                }
                Iterator it3 = arrayList.iterator();
                while (it3.hasNext()) {
                    NetworkLoadTaskListener networkLoadTaskListener3 = (NetworkLoadTaskListener) ((WeakReference) it3.next()).get();
                    if (networkLoadTaskListener3 != null) {
                        if (z) {
                            networkLoadTaskListener3.onPaused(list);
                        } else {
                            networkLoadTaskListener3.onPaused(list.get(0));
                        }
                    }
                }
                break;
            case 2:
                this.f7103h.update(list.get(0));
                Iterator it4 = arrayList.iterator();
                while (it4.hasNext()) {
                    NetworkLoadTaskListener networkLoadTaskListener4 = (NetworkLoadTaskListener) ((WeakReference) it4.next()).get();
                    if (networkLoadTaskListener4 != null) {
                        networkLoadTaskListener4.onFailed(list.get(0));
                    }
                }
                m3107b();
                break;
            case 3:
                this.f7103h.update(list.get(0));
                doFinish(list.get(0));
                Iterator it5 = arrayList.iterator();
                while (it5.hasNext()) {
                    NetworkLoadTaskListener networkLoadTaskListener5 = (NetworkLoadTaskListener) ((WeakReference) it5.next()).get();
                    if (networkLoadTaskListener5 != null) {
                        networkLoadTaskListener5.onFinished(list.get(0));
                    }
                }
                m3107b();
                break;
            case 4:
                Iterator it6 = arrayList.iterator();
                while (it6.hasNext()) {
                    NetworkLoadTaskListener networkLoadTaskListener6 = (NetworkLoadTaskListener) ((WeakReference) it6.next()).get();
                    if (networkLoadTaskListener6 != null) {
                        if (z) {
                            networkLoadTaskListener6.onDeleted(list);
                        } else {
                            networkLoadTaskListener6.onDeleted(list.get(0));
                        }
                    }
                }
                break;
        }
    }

    /* JADX INFO: renamed from: b */
    void m3110b(T t) {
        this.f7103h.update(t);
        if (this.f7102g == null || this.f7102g.size() == 0) {
            return;
        }
        Iterator it = new ArrayList(this.f7102g).iterator();
        while (it.hasNext()) {
            NetworkLoadTaskListener networkLoadTaskListener = (NetworkLoadTaskListener) ((WeakReference) it.next()).get();
            if (networkLoadTaskListener != null) {
                networkLoadTaskListener.onProgressChanged(t);
            }
        }
    }

    public final void clearData() {
        if (this.f7097b != null) {
            this.f7097b.clear();
        }
        if (this.f7096a != null) {
            this.f7096a.clear();
        }
        if (this.f7098c != null) {
            this.f7098c.clear();
        }
        if (this.f7100e != null) {
            this.f7100e.clear();
        }
        if (this.f7099d != null) {
            this.f7099d.clear();
        }
    }

    public final void continueTask(T t) {
        synchronized (this.f7104i) {
            ArrayList arrayList = new ArrayList(1);
            arrayList.add(t);
            continueTask(arrayList);
        }
    }

    public final void continueTask(List<T> list) {
        synchronized (this.f7104i) {
            if (list != null) {
                if (list.size() != 0) {
                    for (T t : list) {
                        doBeforeContinue(t);
                        if (!this.f7098c.remove(t)) {
                            this.f7099d.remove(t);
                        }
                        if (this.f7097b.contains(t)) {
                            t.mState = -1;
                        } else if (this.f7096a.contains(t)) {
                            t.mState = 0;
                        } else {
                            this.f7097b.add(t);
                            t.mState = -1;
                        }
                    }
                    m3107b();
                    ArrayList arrayList = new ArrayList();
                    for (T t2 : list) {
                        if (t2.mState == -1 && !this.f7096a.contains(t2)) {
                            arrayList.add(t2);
                        }
                    }
                    if (arrayList.size() > 0) {
                        m3109a(arrayList);
                    }
                }
            }
        }
    }

    public final void deleteTask(T t, boolean z) {
        synchronized (this.f7104i) {
            this.f7103h.delete(t);
            if (!this.f7097b.remove(t) && !this.f7096a.remove(t) && !this.f7098c.remove(t) && !this.f7100e.remove(t)) {
                this.f7099d.remove(t);
            }
            t.mState = 4;
            t.mProgress = 0.0f;
            t.mCurrentSize = 0L;
            m3108a(t);
            m3107b();
            if (z) {
                doDeleteFile(t);
            }
        }
    }

    public final void deleteTask(List<T> list, boolean z) {
        synchronized (this.f7104i) {
            this.f7103h.delete(list);
            for (T t : list) {
                if (!this.f7096a.remove(t) && !this.f7097b.remove(t) && !this.f7098c.remove(t) && !this.f7100e.remove(t)) {
                    this.f7099d.remove(t);
                }
                t.mProgress = 0.0f;
                t.mCurrentSize = 0L;
                t.mState = 4;
            }
            m3109a(list);
            m3107b();
            if (z) {
                doDeleteFile(list);
            }
        }
    }

    protected abstract void doBeforeContinue(T t);

    protected abstract void doBeforeStart(T t);

    protected void doDeleteFile(T t) {
    }

    protected void doDeleteFile(List<T> list) {
    }

    protected void doFinish(T t) {
    }

    protected abstract void doPause(T t);

    public List<T> getAllTasks() {
        ArrayList arrayList = new ArrayList(this.f7096a);
        arrayList.addAll(this.f7097b);
        arrayList.addAll(this.f7098c);
        arrayList.addAll(this.f7100e);
        arrayList.addAll(this.f7099d);
        return arrayList;
    }

    public List<T> getFailedTasks() {
        return this.f7099d;
    }

    public List<T> getFinishedTasks() {
        return this.f7100e;
    }

    public List<T> getPausedTasks() {
        return this.f7098c;
    }

    public List<T> getRunningTasks() {
        return this.f7096a;
    }

    public List<T> getWaitingTasks() {
        return this.f7097b;
    }

    public final void pauseTask(T t) {
        synchronized (this.f7104i) {
            ArrayList arrayList = new ArrayList(1);
            arrayList.add(t);
            pauseTask(arrayList);
        }
    }

    public final void pauseTask(List<T> list) {
        synchronized (this.f7104i) {
            if (list != null) {
                if (list.size() != 0) {
                    for (T t : list) {
                        doPause(t);
                        if (this.f7096a.remove(t)) {
                            t.isWaitingToPaused = false;
                        } else {
                            this.f7097b.remove(t);
                            t.isWaitingToPaused = true;
                        }
                        if (!this.f7098c.contains(t)) {
                            this.f7098c.add(t);
                        }
                        t.mState = 1;
                    }
                    m3109a(list);
                    m3107b();
                }
            }
        }
    }

    public void registListener(NetworkLoadTaskListener<T> networkLoadTaskListener) {
        this.f7102g.add(0, new WeakReference<>(networkLoadTaskListener));
    }

    public void setNetworkLoadTaskDao(INetworkLoadTaskDao<T> iNetworkLoadTaskDao) {
        this.f7103h = iNetworkLoadTaskDao;
        m3106a();
    }

    public synchronized void setRunningTaskCountLimit(byte b) {
        this.f7101f = b;
    }

    public final void startTask(T t) {
        synchronized (this.f7104i) {
            ArrayList arrayList = new ArrayList(1);
            arrayList.add(t);
            startTask(arrayList);
        }
    }

    public final void startTask(List<T> list) {
        synchronized (this.f7104i) {
            if (list != null) {
                if (list.size() != 0) {
                    this.f7103h.delete(list);
                    for (T t : list) {
                        doBeforeStart(t);
                        if (!this.f7098c.remove(t)) {
                            this.f7099d.remove(t);
                        }
                        if (!this.f7097b.contains(t) && !this.f7096a.contains(t)) {
                            this.f7097b.add(t);
                            t.mState = -1;
                        }
                    }
                    m3107b();
                    ArrayList arrayList = new ArrayList();
                    for (T t2 : list) {
                        if (t2.mState == -1 && !this.f7096a.contains(t2)) {
                            arrayList.add(t2);
                        }
                    }
                    if (arrayList.size() > 0) {
                        m3109a(arrayList);
                    }
                    this.f7103h.insert(list);
                }
            }
        }
    }

    public void unregistListener(NetworkLoadTaskListener<T> networkLoadTaskListener) {
        if (networkLoadTaskListener == null) {
            return;
        }
        int i = 0;
        while (true) {
            int i2 = i;
            if (i2 >= this.f7102g.size()) {
                return;
            }
            WeakReference<NetworkLoadTaskListener<T>> weakReference = this.f7102g.get(i2);
            if (weakReference.get() == networkLoadTaskListener) {
                this.f7102g.remove(weakReference);
                return;
            }
            i = i2 + 1;
        }
    }
}
