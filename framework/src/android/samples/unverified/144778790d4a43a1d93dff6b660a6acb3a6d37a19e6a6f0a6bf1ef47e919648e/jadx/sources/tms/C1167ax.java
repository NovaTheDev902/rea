package tms;

import com.tencent.tmsecure.module.aresengine.FilterConfig;
import com.tencent.tmsecure.module.aresengine.FilterResult;
import com.tencent.tmsecure.module.aresengine.TelephonyEntity;

/* JADX INFO: renamed from: tms.ax */
/* JADX INFO: loaded from: classes.dex */
final class C1167ax {

    /* JADX INFO: renamed from: a */
    private Object f6864a = new Object();

    /* JADX INFO: renamed from: b */
    private int[] f6865b;

    /* JADX INFO: renamed from: c */
    private a[] f6866c;

    /* JADX INFO: renamed from: tms.ax$a */
    static abstract class a {

        /* JADX INFO: renamed from: a */
        private TelephonyEntity f6867a;

        /* JADX INFO: renamed from: b */
        private int f6868b;

        /* JADX INFO: renamed from: c */
        private FilterResult f6869c;

        /* JADX INFO: renamed from: d */
        private Object[] f6870d;

        /* JADX INFO: renamed from: e */
        private int f6871e;

        /* JADX INFO: renamed from: f */
        private Object f6872f;

        a() {
        }

        /* JADX INFO: renamed from: b */
        static /* synthetic */ Object m2959b(a aVar) {
            aVar.f6872f = null;
            return null;
        }

        /* JADX INFO: renamed from: a */
        public final TelephonyEntity m2960a() {
            return this.f6867a;
        }

        /* JADX INFO: renamed from: a */
        public final void m2961a(FilterResult filterResult) {
            this.f6869c = filterResult;
        }

        /* JADX INFO: renamed from: a */
        public final void m2962a(Object obj) {
            this.f6872f = obj;
        }

        /* JADX INFO: renamed from: b */
        public final int m2963b() {
            return this.f6868b;
        }

        /* JADX INFO: renamed from: c */
        public final Object[] m2964c() {
            return this.f6870d;
        }

        /* JADX INFO: renamed from: d */
        public final int m2965d() {
            return this.f6871e;
        }

        /* JADX INFO: renamed from: e */
        public final Object m2966e() {
            return this.f6872f;
        }

        /* JADX INFO: renamed from: f */
        abstract boolean mo2967f();

        /* JADX INFO: renamed from: g */
        abstract void mo2968g();
    }

    C1167ax() {
    }

    /* JADX INFO: renamed from: a */
    private FilterResult m2950a(int i, int i2, TelephonyEntity telephonyEntity, Object... objArr) {
        FilterResult filterResult = null;
        a aVar = this.f6866c[i];
        if (aVar != null) {
            synchronized (this.f6866c) {
                aVar.f6867a = telephonyEntity;
                aVar.f6868b = i2;
                aVar.f6870d = objArr;
                aVar.f6871e = this.f6865b[i];
                if (aVar.mo2967f()) {
                    aVar.mo2968g();
                }
                filterResult = aVar.f6869c;
                a.m2959b(aVar);
                aVar.f6867a = null;
                aVar.m2961a((FilterResult) null);
                aVar.f6870d = null;
            }
        }
        return filterResult;
    }

    /* JADX INFO: renamed from: a */
    public final FilterResult m2951a(TelephonyEntity telephonyEntity, FilterConfig filterConfig, Object... objArr) {
        FilterResult filterResultM2950a = null;
        if (this.f6865b != null && this.f6866c != null && filterConfig != null) {
            synchronized (this.f6864a) {
                for (int i = 0; i < this.f6865b.length; i++) {
                    int i2 = filterConfig.get(this.f6865b[i]);
                    if (i2 != 4 && i2 != 3) {
                        filterResultM2950a = m2950a(i, i2, telephonyEntity, objArr);
                    }
                    if (filterResultM2950a != null) {
                        break;
                    }
                }
            }
        }
        return filterResultM2950a;
    }

    /* JADX INFO: renamed from: a */
    public final void m2952a(int i, a aVar) {
        int i2 = 0;
        while (true) {
            if (i2 >= this.f6865b.length) {
                i2 = -1;
                break;
            } else if (this.f6865b[i2] == i) {
                break;
            } else {
                i2++;
            }
        }
        if (i2 < 0) {
            throw new IndexOutOfBoundsException("the filed " + i + "is not define from setOrderedFileds method.");
        }
        this.f6866c[i2] = aVar;
    }

    /* JADX INFO: renamed from: a */
    public final void m2953a(int... iArr) {
        this.f6865b = iArr;
        this.f6866c = new a[this.f6865b.length];
    }
}
