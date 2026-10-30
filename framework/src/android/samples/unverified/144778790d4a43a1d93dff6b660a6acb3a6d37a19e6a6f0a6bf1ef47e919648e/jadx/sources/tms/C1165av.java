package tms;

import com.tencent.tmsecure.module.aresengine.ContactEntity;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: renamed from: tms.av */
/* JADX INFO: loaded from: classes.dex */
final class C1165av extends Thread {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1172bb.c f6862a;

    C1165av(C1172bb.c cVar) {
        this.f6862a = cVar;
    }

    @Override // java.lang.Thread, java.lang.Runnable
    public final void run() {
        int i = 0;
        List<ContactEntity> allContact = C1172bb.this.getAllContact();
        ArrayList arrayList = new ArrayList();
        ArrayList arrayList2 = new ArrayList();
        for (ContactEntity contactEntity : allContact) {
            int iM2894b = C1150ag.m2894b(contactEntity.phonenum);
            if (!arrayList2.contains(Integer.valueOf(iM2894b))) {
                arrayList.add(contactEntity);
                arrayList2.add(Integer.valueOf(iM2894b));
            }
        }
        synchronized (this.f6862a.f6903b) {
            this.f6862a.f6904c = new C1172bb.d[arrayList.size()];
            Iterator it = arrayList.iterator();
            while (it.hasNext()) {
                int iM2894b2 = C1150ag.m2894b(((ContactEntity) it.next()).phonenum);
                C1172bb.d dVar = new C1172bb.d((byte) 0);
                dVar.f6907a = iM2894b2;
                this.f6862a.f6904c[i] = dVar;
                i++;
            }
            C1172bb.c cVar = this.f6862a;
            C1172bb.c cVar2 = this.f6862a;
            C1172bb.d[] dVarArr = this.f6862a.f6904c;
            if (dVarArr.length > 1) {
                Arrays.sort(dVarArr, new C1166aw(cVar2));
            }
            cVar.f6904c = dVarArr;
            C1172bb.c.m2994e(this.f6862a);
        }
    }
}
