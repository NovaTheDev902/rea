package tms;

import android.content.ContentResolver;
import android.content.ContentValues;
import android.content.Context;
import android.database.ContentObserver;
import android.database.Cursor;
import android.net.Uri;
import android.os.Build;
import android.os.Handler;
import android.provider.CallLog;
import android.provider.Contacts;
import android.provider.ContactsContract;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.mmsutils.PushReceiver;
import com.tencent.tmsecure.module.aresengine.AbsSysDao;
import com.tencent.tmsecure.module.aresengine.CallLogEntity;
import com.tencent.tmsecure.module.aresengine.ContactEntity;
import com.tencent.tmsecure.module.aresengine.SmsEntity;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/* JADX INFO: renamed from: tms.bb */
/* JADX INFO: loaded from: classes.dex */
public final class C1172bb extends AbsSysDao {

    /* JADX INFO: renamed from: a */
    private static volatile AbsSysDao f6890a;

    /* JADX INFO: renamed from: b */
    private e f6891b;

    /* JADX INFO: renamed from: c */
    private ContentResolver f6892c;

    /* JADX INFO: renamed from: d */
    private c f6893d;

    /* JADX INFO: renamed from: e */
    private Context f6894e;

    /* JADX INFO: renamed from: f */
    private final String[] f6895f = {"_id", AppDatabase.NUMBER, "name", "type", "duration", "date"};

    /* JADX INFO: renamed from: g */
    private final String[] f6896g = {"_id", "address", "type", PushReceiver.BODY, "date", "person", "thread_id"};

    /* JADX INFO: renamed from: tms.bb$a */
    final class a implements e {

        /* JADX INFO: renamed from: b */
        private final Uri f6898b = Contacts.People.CONTENT_URI;

        /* JADX INFO: renamed from: c */
        private final Uri f6899c = Contacts.Phones.CONTENT_URI;

        a() {
        }

        @Override // tms.C1172bb.e
        /* JADX INFO: renamed from: a */
        public final Uri mo2985a() {
            return this.f6898b;
        }

        @Override // tms.C1172bb.e
        /* JADX INFO: renamed from: b */
        public final List<ContactEntity> mo2986b() {
            ArrayList arrayList = new ArrayList();
            Cursor cursorQuery = C1172bb.this.f6892c.query(this.f6898b, new String[]{"_id", AppDatabase.NUMBER, "display_name"}, null, null, "name asc");
            C1172bb c1172bb = C1172bb.this;
            if (C1172bb.m2983e(cursorQuery)) {
                while (!cursorQuery.isAfterLast()) {
                    try {
                        String string = cursorQuery.getString(1);
                        if (C1150ag.m2891a(string)) {
                            ContactEntity contactEntity = new ContactEntity();
                            contactEntity.f6027id = cursorQuery.getInt(0);
                            contactEntity.phonenum = string.replaceAll("[ -]+", "");
                            contactEntity.name = cursorQuery.getString(2);
                            arrayList.add(contactEntity);
                        }
                        cursorQuery.moveToNext();
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            }
            C1172bb c1172bb2 = C1172bb.this;
            C1172bb.m2984f(cursorQuery);
            return arrayList;
        }
    }

    /* JADX INFO: renamed from: tms.bb$b */
    final class b implements e {

        /* JADX INFO: renamed from: b */
        private Uri f6901b = ContactsContract.Contacts.CONTENT_URI;

        b() {
        }

        @Override // tms.C1172bb.e
        /* JADX INFO: renamed from: a */
        public final Uri mo2985a() {
            return this.f6901b;
        }

        @Override // tms.C1172bb.e
        /* JADX INFO: renamed from: b */
        public final List<ContactEntity> mo2986b() {
            HashMap map = new HashMap();
            HashMap map2 = new HashMap();
            ArrayList arrayList = new ArrayList();
            Cursor cursorQuery = C1172bb.this.f6892c.query(this.f6901b, null, "has_phone_number=1", null, null);
            C1172bb c1172bb = C1172bb.this;
            if (C1172bb.m2983e(cursorQuery)) {
                int columnIndex = cursorQuery.getColumnIndex("_id");
                int columnIndex2 = cursorQuery.getColumnIndex("display_name");
                while (!cursorQuery.isAfterLast()) {
                    try {
                        map.put(Integer.valueOf(cursorQuery.getInt(columnIndex)), cursorQuery.getString(columnIndex2));
                        cursorQuery.moveToNext();
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            }
            C1172bb c1172bb2 = C1172bb.this;
            C1172bb.m2984f(cursorQuery);
            Cursor cursorQuery2 = C1172bb.this.f6892c.query(ContactsContract.CommonDataKinds.Phone.CONTENT_URI, null, null, null, null);
            C1172bb c1172bb3 = C1172bb.this;
            if (C1172bb.m2983e(cursorQuery2)) {
                int columnIndex3 = cursorQuery2.getColumnIndex("data1");
                int columnIndex4 = cursorQuery2.getColumnIndex("contact_id");
                while (!cursorQuery2.isAfterLast()) {
                    try {
                        map2.put(cursorQuery2.getString(columnIndex3), Integer.valueOf(cursorQuery2.getInt(columnIndex4)));
                        cursorQuery2.moveToNext();
                    } catch (Exception e2) {
                        e2.printStackTrace();
                    }
                }
            }
            C1172bb c1172bb4 = C1172bb.this;
            C1172bb.m2984f(cursorQuery2);
            for (Map.Entry entry : map2.entrySet()) {
                String str = (String) entry.getKey();
                int iIntValue = ((Integer) entry.getValue()).intValue();
                String str2 = (String) map.get(Integer.valueOf(iIntValue));
                if (C1150ag.m2891a(str) && str != null && str.trim().length() > 0) {
                    ContactEntity contactEntity = new ContactEntity();
                    contactEntity.f6027id = iIntValue;
                    contactEntity.name = str2;
                    contactEntity.phonenum = str.replaceAll("[ -]+", "");
                    arrayList.add(contactEntity);
                }
            }
            return arrayList;
        }
    }

    /* JADX INFO: renamed from: tms.bb$c */
    final class c {

        /* JADX INFO: renamed from: b */
        private byte[] f6903b = new byte[0];

        /* JADX INFO: renamed from: c */
        private d[] f6904c = new d[0];

        /* JADX INFO: renamed from: d */
        private ContentObserver f6905d;

        /* JADX INFO: renamed from: e */
        private boolean f6906e;

        public c() {
            m2988a();
            this.f6905d = new C1157an(this, new Handler(C1172bb.this.f6894e.getMainLooper()), C1172bb.this);
            C1172bb.this.f6892c.registerContentObserver(C1172bb.this.f6891b.mo2985a(), true, this.f6905d);
        }

        /* JADX INFO: renamed from: a */
        private int m2987a(int i) {
            int i2;
            synchronized (this.f6903b) {
                int length = this.f6904c.length - 1;
                int i3 = 0;
                while (length >= i3) {
                    int i4 = (length + i3) / 2;
                    int i5 = this.f6904c[i4].f6907a;
                    if (i == i5) {
                        i2 = i4;
                    } else if (i > i5) {
                        i3 = i4 + 1;
                    } else {
                        length = i4 - 1;
                    }
                }
                i2 = -1;
            }
            return i2;
        }

        /* JADX INFO: Access modifiers changed from: private */
        /* JADX INFO: renamed from: a */
        public void m2988a() {
            new C1165av(this).start();
        }

        /* JADX INFO: renamed from: e */
        static /* synthetic */ boolean m2994e(c cVar) {
            cVar.f6906e = true;
            return true;
        }

        /* JADX INFO: renamed from: a */
        public final boolean m2995a(String str) {
            return C1150ag.m2891a(str) && m2987a(C1150ag.m2894b(str)) != -1;
        }

        protected final void finalize() throws Throwable {
            if (this.f6905d != null) {
                C1172bb.this.f6892c.unregisterContentObserver(this.f6905d);
            }
            super.finalize();
        }
    }

    /* JADX INFO: renamed from: tms.bb$d */
    static final class d {

        /* JADX INFO: renamed from: a */
        int f6907a;

        private d() {
        }

        /* synthetic */ d(byte b) {
            this();
        }
    }

    /* JADX INFO: renamed from: tms.bb$e */
    interface e {
        /* JADX INFO: renamed from: a */
        Uri mo2985a();

        /* JADX INFO: renamed from: b */
        List<ContactEntity> mo2986b();
    }

    private C1172bb(Context context) {
        this.f6894e = context;
        this.f6892c = context.getContentResolver();
        this.f6891b = new Integer(Build.VERSION.SDK).intValue() > 5 ? new b() : new a();
        this.f6893d = new c();
    }

    /* JADX INFO: renamed from: a */
    public static AbsSysDao m2976a(Context context) {
        if (f6890a == null) {
            synchronized (C1172bb.class) {
                if (f6890a == null) {
                    f6890a = new C1172bb(context);
                }
            }
        }
        return f6890a;
    }

    /* JADX INFO: renamed from: c */
    private static SmsEntity m2980c(Cursor cursor) {
        SmsEntity smsEntity = new SmsEntity();
        smsEntity.f6027id = cursor.getInt(0);
        smsEntity.phonenum = cursor.getString(1);
        smsEntity.type = cursor.getInt(2);
        smsEntity.body = cursor.getString(3);
        smsEntity.date = cursor.getLong(4);
        return smsEntity;
    }

    /* JADX INFO: renamed from: d */
    private static CallLogEntity m2982d(Cursor cursor) {
        CallLogEntity callLogEntity = new CallLogEntity();
        callLogEntity.f6027id = cursor.getInt(0);
        callLogEntity.phonenum = cursor.getString(1).replaceAll("[ -]+", "");
        callLogEntity.type = cursor.getInt(3);
        callLogEntity.duration = cursor.getLong(4);
        callLogEntity.date = cursor.getLong(5);
        return callLogEntity;
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: e */
    public static boolean m2983e(Cursor cursor) {
        return cursor != null && cursor.moveToFirst();
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: f */
    public static void m2984f(Cursor cursor) {
        if (cursor == null || cursor.isClosed()) {
            return;
        }
        cursor.close();
    }

    @Override // com.tencent.tmsecure.module.aresengine.AbsSysDao
    public final boolean contains(String str) {
        new d((byte) 0);
        return this.f6893d.m2995a(str);
    }

    @Override // com.tencent.tmsecure.module.aresengine.AbsSysDao
    public final List<CallLogEntity> getAllCallLog() {
        ArrayList arrayList = new ArrayList();
        Cursor cursorQuery = this.f6892c.query(CallLog.Calls.CONTENT_URI, this.f6895f, null, null, "date DESC");
        if (m2983e(cursorQuery)) {
            while (!cursorQuery.isAfterLast()) {
                if (C1150ag.m2891a(cursorQuery.getString(1))) {
                    arrayList.add(m2982d(cursorQuery));
                }
                cursorQuery.moveToNext();
            }
        }
        m2984f(cursorQuery);
        return arrayList;
    }

    @Override // com.tencent.tmsecure.module.aresengine.AbsSysDao
    public final List<ContactEntity> getAllContact() {
        return this.f6891b.mo2986b();
    }

    /* JADX WARN: Code duplicated, block: B:10:0x0020  */
    /* JADX WARN: Code duplicated, block: B:12:0x0029  */
    /* JADX WARN: Code duplicated, block: B:19:0x0035  */
    @Override // com.tencent.tmsecure.module.aresengine.AbsSysDao
    public final CallLogEntity getLastCallLog() throws Throwable {
        Cursor cursorQuery;
        String str;
        Cursor cursor = null;
        callLogEntityM2982d = null;
        CallLogEntity callLogEntityM2982d = null;
        try {
            cursorQuery = this.f6892c.query(CallLog.Calls.CONTENT_URI, this.f6895f, null, null, "_id DESC");
            try {
                callLogEntityM2982d = m2983e(cursorQuery) ? m2982d(cursorQuery) : null;
                if (cursorQuery != null) {
                    m2984f(cursorQuery);
                }
            } catch (Exception e2) {
                if (cursorQuery != null) {
                }
                if (callLogEntityM2982d != null) {
                    if (callLogEntityM2982d.phonenum.length() == 1) {
                        str = "null";
                    } else {
                        str = callLogEntityM2982d.phonenum;
                    }
                    callLogEntityM2982d.phonenum = str;
                }
                return callLogEntityM2982d;
            } catch (Throwable th) {
                cursor = cursorQuery;
                th = th;
                if (cursor != null) {
                    m2984f(cursor);
                }
                throw th;
            }
        } catch (Exception e3) {
            cursorQuery = null;
        } catch (Throwable th2) {
            th = th2;
        }
        if (callLogEntityM2982d != null) {
            if (callLogEntityM2982d.phonenum.length() == 1) {
                str = "null";
            } else {
                str = callLogEntityM2982d.phonenum;
            }
            callLogEntityM2982d.phonenum = str;
        }
        return callLogEntityM2982d;
    }

    @Override // com.tencent.tmsecure.module.aresengine.AbsSysDao
    public final SmsEntity getLastInBoxSms(int i, int i2) {
        SmsEntity smsEntity = null;
        Cursor cursorQuery = this.f6892c.query(Uri.parse("content://sms"), this.f6896g, "type=1 AND read=" + i2, null, "_id DESC");
        if (m2983e(cursorQuery)) {
            SmsEntity smsEntityM2980c = m2980c(cursorQuery);
            long jCurrentTimeMillis = System.currentTimeMillis() - smsEntityM2980c.date;
            if (i < 0) {
                smsEntity = smsEntityM2980c;
            } else if (jCurrentTimeMillis <= i * 1000 && jCurrentTimeMillis >= 0) {
                smsEntity = smsEntityM2980c;
            }
        }
        m2984f(cursorQuery);
        return smsEntity;
    }

    @Override // com.tencent.tmsecure.module.aresengine.AbsSysDao
    public final SmsEntity getLastOutBoxSms(int i) {
        SmsEntity smsEntity = null;
        Cursor cursorQuery = this.f6892c.query(Uri.parse("content://sms"), this.f6896g, "type=2", null, "_id DESC");
        if (m2983e(cursorQuery)) {
            SmsEntity smsEntityM2980c = m2980c(cursorQuery);
            if (smsEntityM2980c.date + ((long) (i * 1000)) >= System.currentTimeMillis()) {
                smsEntity = smsEntityM2980c;
            }
        }
        m2984f(cursorQuery);
        return smsEntity;
    }

    @Override // com.tencent.tmsecure.module.aresengine.AbsSysDao
    public final List<ContactEntity> getSimContact() {
        String[] strArr = {"_id", "name", AppDatabase.NUMBER};
        ArrayList arrayList = new ArrayList();
        try {
            Cursor cursorQuery = this.f6892c.query(Uri.parse("content://icc/adn"), strArr, null, null, null);
            if (cursorQuery != null && m2983e(cursorQuery)) {
                while (!cursorQuery.isAfterLast()) {
                    ContactEntity contactEntity = new ContactEntity();
                    contactEntity.f6027id = cursorQuery.getInt(cursorQuery.getColumnIndex("_id"));
                    contactEntity.name = cursorQuery.getString(cursorQuery.getColumnIndex("name"));
                    contactEntity.phonenum = cursorQuery.getString(cursorQuery.getColumnIndex(AppDatabase.NUMBER));
                    contactEntity.isSimContact = true;
                    if (contactEntity.phonenum != null) {
                        arrayList.add(contactEntity);
                    }
                    cursorQuery.moveToNext();
                }
            }
            m2984f(cursorQuery);
            return arrayList;
        } catch (Exception e2) {
            e2.printStackTrace();
            return arrayList;
        }
    }

    @Override // com.tencent.tmsecure.module.aresengine.AbsSysDao
    public final boolean insert(SmsEntity smsEntity) {
        Uri uri = Uri.parse("content://sms");
        SmsEntity lastInBoxSms = getLastInBoxSms(5, 0);
        if (lastInBoxSms != null && lastInBoxSms.phonenum.equals(smsEntity.phonenum) && lastInBoxSms.body.equals(smsEntity.body)) {
            return false;
        }
        ContentValues contentValues = new ContentValues();
        contentValues.put("address", smsEntity.phonenum);
        contentValues.put(PushReceiver.BODY, smsEntity.body);
        contentValues.put("date", Long.valueOf(smsEntity.date));
        contentValues.put(PushReceiver.READ, Integer.valueOf(smsEntity.read));
        contentValues.put("type", Integer.valueOf(smsEntity.type));
        return this.f6892c.insert(uri, contentValues) != null;
    }

    @Override // com.tencent.tmsecure.module.aresengine.AbsSysDao
    public final boolean remove(CallLogEntity callLogEntity) {
        return this.f6892c.delete(CallLog.Calls.CONTENT_URI, new StringBuilder().append("_id=").append(callLogEntity.f6027id).toString(), null) > 0;
    }

    @Override // com.tencent.tmsecure.module.aresengine.AbsSysDao
    public final boolean remove(SmsEntity smsEntity) {
        return this.f6892c.delete(Uri.parse("content://sms"), new StringBuilder().append("_id=").append(smsEntity.f6027id).toString(), null) > 0;
    }
}
