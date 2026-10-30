package com.lenovo.lps.sus.p009d;

import android.os.Message;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;

/* JADX INFO: renamed from: com.lenovo.lps.sus.d.e */
/* JADX INFO: loaded from: classes.dex */
final class C0143e implements InterfaceC0139a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C0141c f1583a;

    C0143e(C0141c c0141c) {
        this.f1583a = c0141c;
    }

    @Override // com.lenovo.lps.sus.p009d.InterfaceC0139a
    /* JADX INFO: renamed from: a */
    public final void mo533a(long j, long j2) {
        if (0 == j2) {
            return;
        }
        this.f1583a.f1580i = System.currentTimeMillis();
        this.f1583a.f1575d = 100 * j;
        if (this.f1583a.f1575d <= ((long) this.f1583a.f1576e) * j2 || this.f1583a.f1580i < this.f1583a.f1579h + 400) {
            return;
        }
        this.f1583a.f1577f = (int) (this.f1583a.f1575d / j2);
        this.f1583a.f1578g = this.f1583a.f1577f;
        if (this.f1583a.f1577f > 100) {
            this.f1583a.f1578g = 100;
            C0098i.m411b(C0092c.f1339b, "progressNum error!!! downloadSize =" + j + "   fileSize=" + j2 + "   progressNum=" + this.f1583a.f1577f + "   tempProgressNums=" + this.f1583a.f1578g);
        }
        Message message = new Message();
        if (this.f1583a.f1581j != null) {
            message.what = 1;
            message.getData().putInt("progressId", 1);
            message.getData().putInt("progress", this.f1583a.f1578g);
            C0098i.m409a(C0092c.f1339b, "downloadSize =" + j + "   fileSize=" + j2 + "   progressNum=" + this.f1583a.f1577f);
            this.f1583a.f1581j.sendMessage(message);
        }
        this.f1583a.f1576e = this.f1583a.f1577f;
        this.f1583a.f1579h = this.f1583a.f1580i;
    }

    @Override // com.lenovo.lps.sus.p009d.InterfaceC0139a
    /* JADX INFO: renamed from: a */
    public final void mo534a(String str) {
        this.f1583a.f1576e = 0;
        Message message = new Message();
        if (this.f1583a.f1581j != null) {
            message.what = 2;
            message.obj = str;
            this.f1583a.f1581j.sendMessage(message);
        }
    }

    @Override // com.lenovo.lps.sus.p009d.InterfaceC0139a
    /* JADX INFO: renamed from: a */
    public final void mo535a(boolean z) {
        this.f1583a.f1576e = 0;
        Message message = new Message();
        if (this.f1583a.f1581j != null) {
            message.what = 3;
            message.obj = Boolean.valueOf(z);
            this.f1583a.f1581j.sendMessage(message);
        }
    }
}
