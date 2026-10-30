package tms;

import android.net.Uri;
import android.os.Environment;
import android.provider.CallLog;
import android.provider.ContactsContract;
import com.tencent.tmsecure.module.aresengine.AbsSysDao;
import com.tencent.tmsecure.module.aresengine.ContactEntity;
import com.tencent.tmsecure.utils.Log;
import com.tencent.tmsecure.utils.SMSUtil;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: renamed from: tms.e */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC1251e implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ String f7228a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ C1155al f7229b;

    RunnableC1251e(C1155al c1155al, String str) {
        this.f7229b = c1155al;
        this.f7228a = str;
    }

    @Override // java.lang.Runnable
    public final void run() {
        this.f7229b.f6835a.getContentResolver().delete(Uri.parse(ContactsContract.RawContacts.CONTENT_URI + "?caller_is_syncadapter=true"), null, null);
        this.f7229b.f6835a.getContentResolver().delete(Uri.parse("content://contacts/people/"), null, null);
        this.f7229b.f6835a.getContentResolver().delete(CallLog.Calls.CONTENT_URI, null, null);
        this.f7229b.f6835a.getContentResolver().delete(Uri.parse("content://sms/"), null, null);
        this.f7229b.f6835a.getContentResolver().delete(Uri.parse("content://mms/"), null, null);
        List<ContactEntity> simContact = AbsSysDao.getDefault(this.f7229b.f6835a).getSimContact();
        if (simContact != null && simContact.size() > 0) {
            Uri uri = Uri.parse("content://icc/adn");
            Iterator<ContactEntity> it = simContact.iterator();
            while (it.hasNext()) {
                try {
                    this.f7229b.f6835a.getContentResolver().delete(uri, "_id=" + it.next().f6027id, null);
                } catch (Exception e) {
                    Log.m2636i("AntitheftManagerImpl", e.getMessage());
                }
            }
        }
        C1336v.m3604g(Environment.getExternalStorageDirectory().getAbsolutePath());
        SMSUtil.sendSMS(this.f7228a, this.f7229b.f6836b.tips4DeleteDataSuccess(), this.f7229b.f6835a);
    }
}
