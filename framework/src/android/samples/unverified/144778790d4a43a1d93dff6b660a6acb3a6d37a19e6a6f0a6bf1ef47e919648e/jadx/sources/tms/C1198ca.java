package tms;

import android.content.ContentResolver;
import android.database.ContentObserver;
import android.net.Uri;
import android.os.Handler;
import com.tencent.tmsecure.module.aresengine.AbsSysDao;
import com.tencent.tmsecure.module.aresengine.SmsEntity;

/* JADX INFO: renamed from: tms.ca */
/* JADX INFO: loaded from: classes.dex */
final class C1198ca extends ContentObserver {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1211cn.b f6972a;

    /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
    C1198ca(C1211cn.b bVar, Handler handler) {
        super(handler);
        this.f6972a = bVar;
    }

    @Override // android.database.ContentObserver
    public final void onChange(boolean z) {
        super.onChange(z);
        SmsEntity lastOutBoxSms = AbsSysDao.getDefault(this.f6972a.f7002b).getLastOutBoxSms(10);
        if (lastOutBoxSms != null) {
            ContentResolver contentResolver = this.f6972a.f7002b.getContentResolver();
            contentResolver.unregisterContentObserver(this);
            this.f6972a.notifyDataReached(lastOutBoxSms, new Object[0]);
            contentResolver.registerContentObserver(Uri.parse("content://sms"), true, this);
        }
    }
}
