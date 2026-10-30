package com.lenovo.safecenter.safemode;

import android.app.Activity;
import android.content.ContentValues;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.provider.CallLog;
import android.text.TextUtils;
import android.util.Log;
import android.util.Patterns;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseExpandableListAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ExpandableListView;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.mmsutils.PushReceiver;
import com.lenovo.safecenter.support.Contract;
import com.lenovo.safecenter.support.HttpUtils;
import com.lenovo.safecenter.utils.ContractHelpUtils;
import com.lenovo.safecenter.utils.DataHelpUtils;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.Untils;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class WhiteContract extends Activity {

    /* JADX INFO: renamed from: a */
    ContractHelpUtils f5238a;

    /* JADX INFO: renamed from: b */
    private ExpandableListView f5239b;

    /* JADX INFO: renamed from: c */
    private Button f5240c;

    /* JADX INFO: renamed from: d */
    private TextView f5241d;

    /* JADX INFO: renamed from: e */
    private C0950a f5242e;

    /* JADX INFO: renamed from: f */
    private AppDatabase f5243f;

    /* JADX INFO: renamed from: g */
    private List<Contract> f5244g;

    /* JADX INFO: renamed from: h */
    private int f5245h = 0;
    public Handler hand = new Handler() { // from class: com.lenovo.safecenter.safemode.WhiteContract.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    String number = msg.getData().getString(AppDatabase.NUMBER);
                    List<Contract> smslist = WhiteContract.this.f5243f.getwhiteSmsInfo(number);
                    List<Contract> calllist = WhiteContract.this.f5243f.getCallByNumber(number);
                    if (smslist.size() > 0 || calllist.size() > 0) {
                        WhiteContract.m2167a(WhiteContract.this, smslist, calllist, number);
                    }
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m2165a(WhiteContract x0, final int x1, final String x2) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.info).setMessage(C0415R.string.del_confirm).setColorPositiveButton(false).setColorNegativeButton(false).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteContract.9
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                WhiteContract.this.f5243f.deleteWhite(x1);
                WhiteContract.this.f5244g.remove(WhiteContract.this.f5245h);
                WhiteContract.this.f5242e.notifyDataSetChanged();
                WhiteContract.this.f5239b.invalidateViews();
                if (WhiteContract.this.f5245h < WhiteContract.this.f5244g.size()) {
                    WhiteContract.this.f5239b.collapseGroup(WhiteContract.this.f5245h);
                }
                ContractHelpUtils.sendBraodcast(WhiteContract.this, "com.lenovo.securityperson.change");
                Message msg = new Message();
                msg.what = 1;
                msg.getData().putString(AppDatabase.NUMBER, x2);
                WhiteContract.this.hand.sendMessage(msg);
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteContract.8
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m2166a(WhiteContract x0, Contract x1) {
        ContentValues contentValues = new ContentValues();
        contentValues.put("address", x1.getPhoneNumber());
        contentValues.put("date", x1.getDate());
        contentValues.put(PushReceiver.READ, Integer.valueOf(x1.getIsRead()));
        contentValues.put("status", (Integer) (-1));
        contentValues.put("type", Integer.valueOf(x1.getSmstype()));
        contentValues.put(PushReceiver.BODY, x1.getSmsContent());
        x0.getContentResolver().insert(Uri.parse("content://sms"), contentValues);
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m2167a(WhiteContract x0, final List x1, final List x2, final String x3) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.info).setMessage(String.format(x0.getString(C0415R.string.recover_tolocal), x3)).setColorPositiveButton(true).setColorNegativeButton(false).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteContract.7
            /* JADX WARN: Type inference failed for: r0v0, types: [com.lenovo.safecenter.safemode.WhiteContract$7$1] */
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                new Thread() { // from class: com.lenovo.safecenter.safemode.WhiteContract.7.1
                    @Override // java.lang.Thread, java.lang.Runnable
                    public final void run() {
                        for (Contract con : x1) {
                            WhiteContract.m2166a(WhiteContract.this, con);
                        }
                        for (Contract con2 : x2) {
                            WhiteContract.m2169b(WhiteContract.this, con2);
                        }
                        WhiteContract.this.f5243f.delinfo(x3);
                    }
                }.start();
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteContract.6
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }

    /* JADX INFO: renamed from: b */
    static /* synthetic */ void m2169b(WhiteContract x0, Contract x1) {
        ContentValues contentValues = new ContentValues();
        contentValues.put(AppDatabase.NUMBER, x1.getPhoneNumber());
        contentValues.put("date", x1.getDate());
        contentValues.put("type", Integer.valueOf(x1.getCallType()));
        contentValues.put("new", (Integer) 0);
        contentValues.put("duration", (Integer) 0);
        x0.getContentResolver().insert(CallLog.Calls.CONTENT_URI, contentValues);
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.antispamlocalblack_view);
        ((TextView) findViewById(C0415R.id.txt_title)).setText(C0415R.string.changedes_title);
        this.f5243f = new AppDatabase(this);
        this.f5238a = new ContractHelpUtils();
        DataHelpUtils.allActivity.add(this);
        this.f5239b = (ExpandableListView) findViewById(C0415R.id.addblacklist);
        this.f5239b.setDivider(getResources().getDrawable(C0415R.drawable.space_line));
        this.f5239b.setGroupIndicator(null);
        this.f5240c = (Button) findViewById(C0415R.id.sigleadd_btn);
        this.f5241d = (TextView) findViewById(C0415R.id.antispamcallempty);
        this.f5241d.setText(C0415R.string.pri_adddesc);
        this.f5239b.setEmptyView(this.f5241d);
        onClick();
    }

    public void showAddMethod() {
        new CustomDialog.Builder(this).setTitle(getString(C0415R.string.quick_addtitle)).setItems(C0415R.array.private_quick_add, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteContract.10
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                switch (which) {
                    case 0:
                        HttpUtils.private_isOpenSec = true;
                        Intent callIntent = new Intent(WhiteContract.this, (Class<?>) AddContract.class);
                        callIntent.putExtra("fromtype", 1);
                        WhiteContract.this.startActivity(callIntent);
                        break;
                    case 1:
                        HttpUtils.private_isOpenSec = true;
                        Intent smsIntent = new Intent(WhiteContract.this, (Class<?>) AddContract.class);
                        smsIntent.putExtra("fromtype", 2);
                        WhiteContract.this.startActivity(smsIntent);
                        break;
                    case 2:
                        HttpUtils.private_isOpenSec = true;
                        Intent contractIntent = new Intent(WhiteContract.this, (Class<?>) AddContract.class);
                        contractIntent.putExtra("fromtype", 0);
                        WhiteContract.this.startActivity(contractIntent);
                        break;
                    case 3:
                        WhiteContract.this.showAddDialog();
                        break;
                }
            }
        }).show();
    }

    public void showAddDialog() {
        View view = LayoutInflater.from(this).inflate(C0415R.layout.safemode_input_password, (ViewGroup) null);
        final EditText pwd = (EditText) view.findViewById(C0415R.id.safemode_input_pwd);
        final EditText pwd2 = (EditText) view.findViewById(C0415R.id.safemode_input_pwd_again);
        TextView txt1 = (TextView) view.findViewById(C0415R.id.safemode_dailog_title1);
        TextView txt2 = (TextView) view.findViewById(C0415R.id.safemode_dailog_title2);
        txt1.setText(C0415R.string.hand_number);
        txt2.setText(C0415R.string.hand_name);
        pwd.setInputType(144);
        pwd2.setInputType(144);
        new CustomDialog.Builder(this).setTitle(C0415R.string.privacy_mode_set).setContentView(view).setPositiveButton(C0415R.string.sumbit, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteContract.12
            /* JADX WARN: Type inference failed for: r2v30, types: [com.lenovo.safecenter.safemode.WhiteContract$12$1] */
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                if (pwd.getText() != null && !pwd.getText().toString().trim().equals("")) {
                    if (TextUtils.isDigitsOnly(pwd.getText().toString()) || Patterns.PHONE.matcher(pwd.getText().toString()).matches()) {
                        if (WhiteContract.this.f5243f.getWhiteContract(pwd.getText().toString()) == null) {
                            String name = null;
                            if (pwd2.getText() != null && !pwd2.getText().toString().trim().equalsIgnoreCase("")) {
                                name = pwd2.getText().toString();
                            }
                            final Contract conAdd = new Contract();
                            conAdd.setName(name);
                            conAdd.setPhoneNumber(pwd.getText().toString());
                            conAdd.setRealnumber(WhiteContract.this.f5238a.getRealPhoneNumber(pwd.getText().toString()));
                            WhiteContract.this.f5243f.insertContract(conAdd);
                            ContractHelpUtils.sendBraodcast(WhiteContract.this, "com.lenovo.securityperson.change");
                            WhiteContract.this.initDate();
                            new Thread() { // from class: com.lenovo.safecenter.safemode.WhiteContract.12.1
                                @Override // java.lang.Thread, java.lang.Runnable
                                public final void run() {
                                    WhiteContract.this.initCopyDel(conAdd);
                                }
                            }.start();
                            return;
                        }
                        Toast.makeText(WhiteContract.this, C0415R.string.hand_number_error1, 0).show();
                        return;
                    }
                    Toast.makeText(WhiteContract.this, C0415R.string.hand_number_error, 0).show();
                    return;
                }
                Toast.makeText(WhiteContract.this, C0415R.string.hand_number_null, 0).show();
            }
        }).setNegativeButton(C0415R.string.safemode_cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteContract.11
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }

    public void onClick() {
        this.f5240c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteContract.13
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                WhiteContract.this.showAddMethod();
            }
        });
        this.f5239b.setOnGroupExpandListener(new ExpandableListView.OnGroupExpandListener() { // from class: com.lenovo.safecenter.safemode.WhiteContract.2
            @Override // android.widget.ExpandableListView.OnGroupExpandListener
            public final void onGroupExpand(int groupPosition) {
                WhiteContract.this.f5245h = groupPosition;
                if (groupPosition == WhiteContract.this.f5244g.size() - 1) {
                    WhiteContract.this.f5239b.setTranscriptMode(2);
                } else {
                    WhiteContract.this.f5239b.setTranscriptMode(1);
                }
                for (int i = 0; i < WhiteContract.this.f5242e.getGroupCount(); i++) {
                    if (groupPosition != i) {
                        WhiteContract.this.f5239b.collapseGroup(i);
                    }
                }
            }
        });
    }

    /* JADX WARN: Type inference failed for: r0v0, types: [com.lenovo.safecenter.safemode.WhiteContract$3] */
    public void initCopyDel(final Contract con) {
        new Thread() { // from class: com.lenovo.safecenter.safemode.WhiteContract.3
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    String optNumber = con.getPhoneNumber();
                    if (WhiteContract.this.f5238a.isMobileNO(optNumber)) {
                        optNumber = WhiteContract.this.f5238a.optNUmber(optNumber);
                    }
                    List<Contract> call = WhiteContract.this.f5238a.getCallContractByNUmber(WhiteContract.this, optNumber, con.getPhoneNumber());
                    List<Contract> sms = WhiteContract.this.f5238a.getSmsByNUmber(WhiteContract.this, optNumber, con.getPhoneNumber(), con.getName());
                    Log.i("sms_size", "smssize==" + sms.size() + call.size());
                    WhiteContract.this.f5243f.insertCall(call);
                    WhiteContract.this.f5243f.insertSms(sms);
                    if (call.size() > 0 || sms.size() > 0) {
                        WhiteContract.this.f5238a.operateNumber(optNumber, WhiteContract.this, sms.size() > 0);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    public void showChangeContract(final Contract con) {
        for (int i = 0; i < this.f5242e.getGroupCount(); i++) {
            this.f5239b.collapseGroup(i);
        }
        View view = LayoutInflater.from(this).inflate(C0415R.layout.safemode_input_password, (ViewGroup) null);
        final EditText pwd = (EditText) view.findViewById(C0415R.id.safemode_input_pwd);
        final EditText pwd2 = (EditText) view.findViewById(C0415R.id.safemode_input_pwd_again);
        TextView txt1 = (TextView) view.findViewById(C0415R.id.safemode_dailog_title1);
        TextView txt2 = (TextView) view.findViewById(C0415R.id.safemode_dailog_title2);
        txt1.setText(C0415R.string.hand_number);
        txt2.setText(C0415R.string.hand_name);
        pwd.setInputType(144);
        pwd2.setInputType(144);
        if (con.getName() == null || con.getName().equals("")) {
            pwd2.setText("");
        } else {
            pwd2.setText(con.getName());
        }
        pwd.setText(con.getPhoneNumber());
        new CustomDialog.Builder(this).setTitle(C0415R.string.mutil_edit).setContentView(view).setPositiveButton(C0415R.string.sumbit, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteContract.5
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                if (!pwd.getText().toString().equals("") && (TextUtils.isDigitsOnly(pwd.getText().toString()) || Patterns.PHONE.matcher(pwd.getText().toString()).matches())) {
                    String number = pwd.getText().toString();
                    String name = pwd2.getText().toString();
                    if (WhiteContract.this.isWhiteEdit(number, con.getId())) {
                        Toast.makeText(WhiteContract.this, C0415R.string.hand_number_error1, 0).show();
                        return;
                    }
                    if (pwd2.getText().toString().equals("")) {
                        name = null;
                    }
                    WhiteContract.this.f5243f.updateContract(con.getId(), number, name, WhiteContract.this.f5238a.getRealPhoneNumber(number));
                    WhiteContract.this.f5243f.updateName(name, number);
                    if (!con.getPhoneNumber().equals(number)) {
                        if (Untils.compare(con.getPhoneNumber(), number, false)) {
                            WhiteContract.this.f5243f.updateName(name, con.getPhoneNumber());
                            WhiteContract.this.f5243f.updateNUmber(number, con.getPhoneNumber());
                        } else {
                            WhiteContract.this.f5243f.updateName(con.getPhoneNumber(), con.getPhoneNumber());
                        }
                    }
                    for (int i2 = 0; i2 < WhiteContract.this.f5244g.size(); i2++) {
                        if (((Contract) WhiteContract.this.f5244g.get(i2)).getId() == con.getId()) {
                            ((Contract) WhiteContract.this.f5244g.get(i2)).setPhoneNumber(number);
                            ((Contract) WhiteContract.this.f5244g.get(i2)).setName(name);
                            break;
                        }
                    }
                    WhiteContract.this.f5239b.invalidateViews();
                    ContractHelpUtils.sendBraodcast(WhiteContract.this, "com.lenovo.securityperson.change");
                    Toast.makeText(WhiteContract.this, C0415R.string.setting_pwdok, 0).show();
                    return;
                }
                Toast.makeText(WhiteContract.this, C0415R.string.setting_pwdfail, 0).show();
            }
        }).setNegativeButton(C0415R.string.safemode_cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteContract.4
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }

    public boolean isWhiteEdit(String number, int id) {
        try {
            Uri uri = Uri.parse("content://com.lenovo.safecenter.whiteperson/whiteperson");
            Cursor cursor = getContentResolver().query(uri, null, "PHONE_NUMBERS_EQUAL(phonenumber,'" + number + "',0) and _id<>?", new String[]{String.valueOf(id)}, null);
            int count = cursor.getCount();
            cursor.close();
            return count > 0;
        } catch (Exception e) {
            return false;
        }
    }

    public void initDate() {
        this.f5244g = this.f5243f.getAllWhiteContract();
        this.f5242e = new C0950a(this);
        this.f5239b.setAdapter(this.f5242e);
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        initDate();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.safemode.WhiteContract$a */
    class C0950a extends BaseExpandableListAdapter {

        /* JADX INFO: renamed from: a */
        Context f5273a;

        /* JADX INFO: renamed from: b */
        b f5274b;

        /* JADX INFO: renamed from: c */
        a f5275c;

        /* JADX INFO: renamed from: e */
        private LayoutInflater f5277e;

        public C0950a(Context context) {
            this.f5277e = LayoutInflater.from(context);
            this.f5273a = context;
        }

        @Override // android.widget.ExpandableListAdapter
        public final Object getChild(int groupPosition, int childPosition) {
            return null;
        }

        @Override // android.widget.ExpandableListAdapter
        public final long getChildId(int groupPosition, int childPosition) {
            return childPosition;
        }

        @Override // android.widget.ExpandableListAdapter
        public final int getChildrenCount(int groupPosition) {
            return 1;
        }

        @Override // android.widget.ExpandableListAdapter
        public final View getChildView(int groupPosition, int childPosition, boolean isLastChild, View convertView, ViewGroup parent) {
            if (convertView == null) {
                convertView = this.f5277e.inflate(C0415R.layout.dealitemequal, (ViewGroup) null);
                this.f5275c = new a();
                this.f5275c.f5282a = (TextView) convertView.findViewById(C0415R.id.deal1);
                this.f5275c.f5283b = (TextView) convertView.findViewById(C0415R.id.deal2);
                this.f5275c.f5284c = (TextView) convertView.findViewById(C0415R.id.deal3);
                convertView.setTag(this.f5275c);
            } else {
                this.f5275c = (a) convertView.getTag();
            }
            this.f5275c.f5282a.setText(C0415R.string.safemode_callto);
            this.f5275c.f5283b.setText(C0415R.string.replay_sms);
            this.f5275c.f5284c.setText(C0415R.string.delete);
            this.f5275c.f5282a.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteContract.a.1
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    try {
                        Intent callIntent = new Intent("android.intent.action.CALL", Uri.parse("tel:" + ((Contract) WhiteContract.this.f5244g.get(WhiteContract.this.f5245h)).getPhoneNumber()));
                        WhiteContract.this.startActivity(callIntent);
                    } catch (Exception e) {
                        Toast.makeText(WhiteContract.this, C0415R.string.opensms_error, 0).show();
                    }
                }
            });
            this.f5275c.f5283b.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteContract.a.2
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    Intent smsIntent = new Intent(WhiteContract.this, (Class<?>) WhiteSmsShowByNumber.class);
                    smsIntent.putExtra(AppDatabase.NUMBER, ((Contract) WhiteContract.this.f5244g.get(WhiteContract.this.f5245h)).getPhoneNumber());
                    WhiteContract.this.startActivity(smsIntent);
                }
            });
            this.f5275c.f5284c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteContract.a.3
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    WhiteContract.m2165a(WhiteContract.this, ((Contract) WhiteContract.this.f5244g.get(WhiteContract.this.f5245h)).getId(), ((Contract) WhiteContract.this.f5244g.get(WhiteContract.this.f5245h)).getPhoneNumber());
                }
            });
            return convertView;
        }

        @Override // android.widget.ExpandableListAdapter
        public final Object getGroup(int groupPosition) {
            return WhiteContract.this.f5244g.get(groupPosition);
        }

        @Override // android.widget.ExpandableListAdapter
        public final int getGroupCount() {
            return WhiteContract.this.f5244g.size();
        }

        @Override // android.widget.ExpandableListAdapter
        public final long getGroupId(int groupPosition) {
            return groupPosition;
        }

        @Override // android.widget.ExpandableListAdapter
        public final View getGroupView(int groupPosition, boolean isExpanded, View convertView, ViewGroup parent) {
            if (convertView == null) {
                convertView = LayoutInflater.from(this.f5273a).inflate(C0415R.layout.whitecontractinfo, (ViewGroup) null);
                this.f5274b = new b();
                this.f5274b.f5287b = (TextView) convertView.findViewById(C0415R.id.txt_number);
                this.f5274b.f5286a = (TextView) convertView.findViewById(C0415R.id.txt_edit);
                convertView.setTag(this.f5274b);
            } else {
                this.f5274b = (b) convertView.getTag();
            }
            Contract con = (Contract) WhiteContract.this.f5244g.get(groupPosition);
            String name = con.getName();
            if (TextUtils.isEmpty(name)) {
                this.f5274b.f5287b.setText(con.getPhoneNumber());
            } else {
                this.f5274b.f5287b.setText(name);
            }
            this.f5274b.f5286a.setTag(con);
            this.f5274b.f5286a.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteContract.a.4
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    Contract edit_con = (Contract) v.getTag();
                    WhiteContract.this.showChangeContract(edit_con);
                }
            });
            return convertView;
        }

        @Override // android.widget.ExpandableListAdapter
        public final boolean hasStableIds() {
            return false;
        }

        @Override // android.widget.ExpandableListAdapter
        public final boolean isChildSelectable(int groupPosition, int childPosition) {
            return false;
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.safemode.WhiteContract$a$b */
        class b {

            /* JADX INFO: renamed from: a */
            TextView f5286a;

            /* JADX INFO: renamed from: b */
            TextView f5287b;

            b() {
            }
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.safemode.WhiteContract$a$a */
        class a {

            /* JADX INFO: renamed from: a */
            TextView f5282a;

            /* JADX INFO: renamed from: b */
            TextView f5283b;

            /* JADX INFO: renamed from: c */
            TextView f5284c;

            a() {
            }
        }
    }
}
