package tms;

import android.content.SharedPreferences;
import com.tencent.tmsecure.common.TMSApplication;

/* JADX INFO: renamed from: tms.af */
/* JADX INFO: loaded from: classes.dex */
public final class C1149af {

    /* JADX INFO: renamed from: a */
    private String f6822a;

    /* JADX INFO: renamed from: c */
    private SharedPreferences f6824c = TMSApplication.getApplicaionContext().getSharedPreferences("TMSProperties", 0);

    /* JADX INFO: renamed from: b */
    private SharedPreferences.Editor f6823b = this.f6824c.edit();

    public C1149af(String str) {
        this.f6822a = str;
    }

    /* JADX INFO: renamed from: a */
    private String m2879a(String str) {
        return this.f6822a + "." + str;
    }

    /* JADX INFO: renamed from: a */
    public final float m2880a(String str, float f) {
        return this.f6824c.getFloat(m2879a(str), f);
    }

    /* JADX INFO: renamed from: a */
    public final int m2881a(String str, int i) {
        return this.f6824c.getInt(m2879a(str), i);
    }

    /* JADX INFO: renamed from: a */
    public final long m2882a(String str, long j) {
        return this.f6824c.getLong(m2879a(str), j);
    }

    /* JADX INFO: renamed from: a */
    public final String m2883a(String str, String str2) {
        return this.f6824c.getString(m2879a(str), str2);
    }

    /* JADX INFO: renamed from: a */
    public final void m2884a() {
        this.f6823b.commit();
    }

    /* JADX INFO: renamed from: a */
    public final void m2885a(String str, float f, boolean z) {
        this.f6823b.putFloat(m2879a(str), f);
        if (z) {
            m2884a();
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m2886a(String str, int i, boolean z) {
        this.f6823b.putInt(m2879a(str), i);
        if (z) {
            m2884a();
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m2887a(String str, long j, boolean z) {
        this.f6823b.putLong(m2879a(str), j);
        if (z) {
            m2884a();
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m2888a(String str, String str2, boolean z) {
        this.f6823b.putString(m2879a(str), str2);
        if (z) {
            m2884a();
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m2889a(String str, boolean z, boolean z2) {
        this.f6823b.putBoolean(m2879a(str), z);
        if (z2) {
            m2884a();
        }
    }

    /* JADX INFO: renamed from: a */
    public final boolean m2890a(String str, boolean z) {
        return this.f6824c.getBoolean(m2879a(str), z);
    }
}
