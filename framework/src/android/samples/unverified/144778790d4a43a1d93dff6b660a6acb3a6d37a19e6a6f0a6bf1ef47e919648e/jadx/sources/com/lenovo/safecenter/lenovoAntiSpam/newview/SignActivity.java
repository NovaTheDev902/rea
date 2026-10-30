package com.lenovo.safecenter.lenovoAntiSpam.newview;

import android.content.Context;
import android.content.DialogInterface;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.provider.CallLog;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase;
import com.lenovo.safecenter.lenovoAntiSpam.database.NetAppDatabase;
import com.lenovo.safecenter.lenovoAntiSpam.domain.SignCall;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.support.SecurityService;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.Untils;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class SignActivity extends BaseTitleActivity {

    /* JADX INFO: renamed from: a */
    private LinearLayout f3943a;

    /* JADX INFO: renamed from: b */
    private LinearLayout f3944b;

    /* JADX INFO: renamed from: c */
    private TextView f3945c;

    /* JADX INFO: renamed from: d */
    private TextView f3946d;

    /* JADX INFO: renamed from: e */
    private TextView f3947e;

    /* JADX INFO: renamed from: f */
    private TextView f3948f;

    /* JADX INFO: renamed from: g */
    private TextView f3949g;

    /* JADX INFO: renamed from: h */
    private ListView f3950h;

    /* JADX INFO: renamed from: j */
    private AppDatabase f3952j;

    /* JADX INFO: renamed from: k */
    private SignCallBlackApater f3953k;

    /* JADX INFO: renamed from: l */
    private List<SignCall> f3954l;

    /* JADX INFO: renamed from: m */
    private NetAppDatabase f3955m;

    /* JADX INFO: renamed from: n */
    private List<SignCall> f3956n;

    /* JADX INFO: renamed from: i */
    private int f3951i = 0;

    /* JADX INFO: renamed from: o */
    private Handler f3957o = new Handler() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.SignActivity.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 5:
                    if (SignActivity.this.f3956n != null && SignActivity.this.f3956n.size() > 0) {
                        SignCall ss = new SignCall();
                        ss.setId(-8);
                        SignActivity.this.f3956n.add(0, ss);
                        SignActivity.this.f3954l.addAll(SignActivity.this.f3956n);
                        SignActivity.this.f3953k.notifyDataSetChanged();
                        SignActivity.this.f3950h.invalidateViews();
                    }
                    TextView textView = SignActivity.this.f3949g;
                    String string = SignActivity.this.getString(C0415R.string.strange_income_count);
                    Object[] objArr = new Object[1];
                    objArr[0] = Integer.valueOf(SignActivity.this.f3956n.size() > 1 ? SignActivity.this.f3956n.size() - 1 : 0);
                    textView.setText(String.format(string, objArr));
                    break;
            }
        }
    };

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.signmain);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.harsssign_lin, (Integer) null);
        findViews();
        this.f3950h.setDivider(null);
        this.f3952j = new AppDatabase(this);
        this.f3953k = new SignCallBlackApater();
        this.f3955m = new NetAppDatabase(this);
        try {
            initData(this.f3951i);
        } catch (Exception e) {
            e.printStackTrace();
            finish();
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        } else if (v.getId() == C0415R.id.signcalled_lin) {
            initData(1);
        } else if (v.getId() == C0415R.id.tagcall_lin) {
            initData(0);
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    /* JADX WARN: Type inference failed for: r1v11, types: [com.lenovo.safecenter.lenovoAntiSpam.newview.SignActivity$2] */
    public void initData(int type) {
        if (type == 0) {
            this.f3954l = this.f3952j.getSignList();
            if (this.f3954l.size() > 0) {
                SignCall ss = new SignCall();
                ss.setId(-5);
                this.f3954l.add(0, ss);
            }
            this.f3953k = new SignCallBlackApater();
            this.f3943a.setBackgroundResource(C0415R.drawable.tab_select);
            this.f3944b.setBackgroundResource(C0415R.drawable.tab_normal);
            this.f3946d.setText(C0415R.string.sign_tagnull);
            this.f3947e.setTextColor(getResources().getColor(C0415R.color.blue));
            this.f3948f.setTextColor(getResources().getColor(C0415R.color.black4));
            this.f3951i = 0;
            this.f3950h.setAdapter((ListAdapter) this.f3953k);
            this.f3945c.setText(String.format(getString(C0415R.string.sign_totalshow), Integer.valueOf(this.f3952j.getSignCount())));
        } else if (type == 1) {
            this.f3954l = this.f3952j.getSignList();
            this.f3953k = new SignCallBlackApater();
            this.f3943a.setBackgroundResource(C0415R.drawable.tab_select);
            this.f3944b.setBackgroundResource(C0415R.drawable.tab_normal);
            this.f3946d.setText(C0415R.string.sign_tagnull);
            this.f3947e.setTextColor(getResources().getColor(C0415R.color.blue));
            this.f3948f.setTextColor(getResources().getColor(C0415R.color.black4));
            this.f3951i = 0;
            this.f3950h.setAdapter((ListAdapter) this.f3953k);
            this.f3945c.setText(String.format(getString(C0415R.string.sign_totalshow), Integer.valueOf(this.f3952j.getSignCount())));
        }
        if (this.f3956n == null) {
            new Thread() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.SignActivity.2
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    try {
                        SignActivity.this.getSignCallList();
                        SignActivity.this.f3957o.sendEmptyMessage(5);
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            }.start();
        }
    }

    public void findViews() {
        this.f3943a = (LinearLayout) findViewById(C0415R.id.tagcall_lin);
        this.f3944b = (LinearLayout) findViewById(C0415R.id.signcalled_lin);
        this.f3945c = (TextView) findViewById(C0415R.id.signmain_title);
        this.f3950h = (ListView) findViewById(C0415R.id.signmain_list);
        this.f3946d = (TextView) findViewById(C0415R.id.signmain_empty);
        this.f3950h.setItemsCanFocus(false);
        this.f3950h.setEmptyView(this.f3946d);
        this.f3947e = (TextView) findViewById(C0415R.id.taglist_btn);
        this.f3948f = (TextView) findViewById(C0415R.id.calling_btn);
        this.f3949g = (TextView) findViewById(C0415R.id.signstr_title);
        this.f3943a.setOnClickListener(this);
        this.f3944b.setOnClickListener(this);
        this.f3950h.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.SignActivity.3
            @Override // android.widget.AdapterView.OnItemLongClickListener
            public final boolean onItemLongClick(AdapterView<?> parent, View view, int position, long id) {
                return false;
            }
        });
    }

    public void getSignCallList() {
        SignCall signCall;
        String[] projection = {com.lenovo.safecenter.database.AppDatabase.NUMBER, "date", "type", "duration"};
        Cursor cursor = getContentResolver().query(CallLog.Calls.CONTENT_URI, projection, "type=? or type=?", new String[]{String.valueOf(1), String.valueOf(3)}, "number,date desc ");
        this.f3956n = new ArrayList();
        Object preNum = "";
        while (cursor.moveToNext()) {
            String number = cursor.getString(cursor.getColumnIndex(com.lenovo.safecenter.database.AppDatabase.NUMBER));
            if (Untils.isPhoneNUmber(number) && !number.equals(preNum)) {
                preNum = number;
                if (isStangerPhoneNumber(number) && (signCall = getStrange_sign(number)) != null) {
                    signCall.setAddTime(cursor.getString(cursor.getColumnIndex("date")));
                    if (cursor.getInt(cursor.getColumnIndex("type")) == 3) {
                        signCall.setCallDur(1000);
                    } else {
                        signCall.setCallDur(cursor.getInt(cursor.getColumnIndex("duration")));
                    }
                    signCall.setNumber(number);
                    this.f3956n.add(signCall);
                }
            }
        }
        cursor.close();
        if (this.f3956n.size() > 0) {
            C0637a comp = new C0637a();
            Collections.sort(this.f3956n, comp);
        }
    }

    public SignCall getStrange_sign(String number) {
        try {
            SignCall sign = this.f3955m.local_netSign(number);
            if (sign == null) {
                return this.f3955m.get_netSign(number);
            }
            return sign;
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    public boolean isStangerPhoneNumber(String number) {
        return (SecurityService.secutityPerson.contains(number) || SecurityService.localBlackPerson.contains(number) || SecurityService.netBlackPerson.contains(number) || SecurityService.whitePerson.contains(number) || isInContactsdia(this, number) || isSign(number)) ? false : true;
    }

    public boolean isSign(String number) {
        SignCall info = this.f3952j.getSignCall(number);
        return info != null;
    }

    public boolean isInContactsdia(Context act, String number) {
        Uri uri1 = Uri.parse("content://com.android.contacts/data/phones");
        Cursor phoneCursor = act.getContentResolver().query(uri1, null, "PHONE_NUMBERS_EQUAL(data1,'" + number + "',0)", null, null);
        int count = phoneCursor.getCount();
        phoneCursor.close();
        return count > 0;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.newview.SignActivity$a */
    class C0637a implements Comparator {
        public C0637a() {
        }

        @Override // java.util.Comparator
        public final int compare(Object o1, Object o2) {
            SignCall c1 = (SignCall) o1;
            SignCall c2 = (SignCall) o2;
            long installed1 = Long.parseLong(c1.getAddTime());
            long installed2 = Long.parseLong(c2.getAddTime());
            if (installed1 > installed2) {
                return -1;
            }
            if (installed1 == installed2) {
                return 0;
            }
            return 1;
        }
    }

    public String getDescFromType(int stype) {
        if (stype == 1) {
            return getString(C0415R.string.signtype1);
        }
        if (stype == 2) {
            return getString(C0415R.string.signtype2);
        }
        if (stype == 3) {
            return getString(C0415R.string.signtype3);
        }
        if (stype == 11) {
            return getString(C0415R.string.signtype4);
        }
        if (stype == 12) {
            return getString(C0415R.string.signtype5);
        }
        if (stype == 13) {
            return getString(C0415R.string.signtype6);
        }
        return getString(C0415R.string.signtype1);
    }

    public String getStr(int time) {
        if (time < 60) {
            return time + getString(C0415R.string.seconds);
        }
        int minite = time / 60;
        if (minite < 60) {
            return minite + getString(C0415R.string.minute) + (time - (minite * 60)) + getString(C0415R.string.seconds);
        }
        int hour = time / 3600;
        int min = (time - ((hour * 60) * 60)) / 60;
        int second = (time - ((hour * 60) * 60)) - (min * 60);
        return hour + getString(C0415R.string.hour_text) + min + getString(C0415R.string.minute) + second + getString(C0415R.string.seconds);
    }

    public void deleteSign(SignCall sing_call) {
        this.f3952j.delSignCall(sing_call);
        for (int i = 0; i < this.f3954l.size(); i++) {
            if (sing_call.getNumber().equals(this.f3954l.get(i).getNumber())) {
                this.f3954l.remove(i);
                break;
            }
        }
        if (this.f3952j.getSignCount() == 0) {
            this.f3954l.remove(0);
        }
        this.f3953k.notifyDataSetChanged();
        this.f3950h.invalidateViews();
        this.f3945c.setText(String.format(getString(C0415R.string.sign_totalshow), Integer.valueOf(this.f3952j.getSignCount())));
    }

    public void showReport_fail(final SignCall sing_call) {
        new CustomDialog.Builder(this).setTitle(getString(C0415R.string.signcancel) + sing_call.getNumber()).setMessage(C0415R.string.signcancel_dialog).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.SignActivity.5
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                SignActivity.this.deleteSign(sing_call);
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.SignActivity.4
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                dialog.cancel();
            }
        }).show();
    }

    public class SignCallBlackApater extends BaseAdapter {
        public SignCallBlackApater() {
        }

        @Override // android.widget.Adapter
        public int getCount() {
            return SignActivity.this.f3954l.size();
        }

        @Override // android.widget.Adapter
        public Object getItem(int position) {
            return SignActivity.this.f3954l.get(position);
        }

        @Override // android.widget.Adapter
        public long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            View convertView2;
            C0636a holder;
            byte b = 0;
            SignCall tag = (SignCall) SignActivity.this.f3954l.get(position);
            if (tag.getId() == -5 || tag.getId() == -8) {
                convertView2 = LayoutInflater.from(SignActivity.this).inflate(C0415R.layout.health_list_title, (ViewGroup) null);
                holder = new C0636a(this, b);
                convertView2.setBackgroundDrawable(SignActivity.this.getResources().getDrawable(C0415R.drawable.notification_text));
                holder.f3966a = (TextView) convertView2.findViewById(C0415R.id.title);
            } else {
                convertView2 = LayoutInflater.from(SignActivity.this).inflate(C0415R.layout.signmain_item, (ViewGroup) null);
                holder = new C0636a(this, b);
                holder.f3966a = (TextView) convertView2.findViewById(C0415R.id.sign_number);
                holder.f3967b = (TextView) convertView2.findViewById(C0415R.id.sign_time);
                holder.f3968c = (TextView) convertView2.findViewById(C0415R.id.sign_tag);
                holder.f3969d = (TextView) convertView2.findViewById(C0415R.id.sign_type);
            }
            if (tag.getId() == -8) {
                holder.f3966a.setText(C0415R.string.strange_income);
            } else if (tag.getId() == -5) {
                holder.f3966a.setText(C0415R.string.hadsign_title);
            } else {
                holder.f3968c.setTag(tag);
                if (tag.getCallDur() >= 0) {
                    holder.f3966a.setText(tag.getNumber());
                    if (tag.getCallDur() == 1000) {
                        holder.f3967b.setText(C0415R.string.misscall);
                    } else {
                        holder.f3967b.setText(String.format(SignActivity.this.getString(C0415R.string.sign_timedesc), SignActivity.this.getStr(tag.getCallDur())));
                    }
                    holder.f3968c.setVisibility(8);
                    holder.f3969d.setVisibility(0);
                    holder.f3969d.setText(String.format(SignActivity.this.getString(C0415R.string.netsign_showtype), SignActivity.this.getDescFromType(tag.getsType())));
                } else {
                    holder.f3968c.setVisibility(0);
                    holder.f3969d.setVisibility(8);
                    holder.f3966a.setText(tag.getNumber() + " " + SignActivity.this.getDescFromType(tag.getsType()));
                    holder.f3967b.setText(String.format(SignActivity.this.getString(C0415R.string.sign_timedesc), SignActivity.this.getStr(tag.getTotalCall())));
                }
                holder.f3968c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.SignActivity.SignCallBlackApater.1
                    @Override // android.view.View.OnClickListener
                    public final void onClick(View v) {
                        SignCall vv = (SignCall) v.getTag();
                        SignActivity.this.showReport_fail(vv);
                    }
                });
            }
            return convertView2;
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.newview.SignActivity$SignCallBlackApater$a */
        private class C0636a {

            /* JADX INFO: renamed from: a */
            TextView f3966a;

            /* JADX INFO: renamed from: b */
            TextView f3967b;

            /* JADX INFO: renamed from: c */
            TextView f3968c;

            /* JADX INFO: renamed from: d */
            TextView f3969d;

            private C0636a() {
            }

            /* synthetic */ C0636a(SignCallBlackApater x0, byte b) {
                this();
            }
        }
    }
}
