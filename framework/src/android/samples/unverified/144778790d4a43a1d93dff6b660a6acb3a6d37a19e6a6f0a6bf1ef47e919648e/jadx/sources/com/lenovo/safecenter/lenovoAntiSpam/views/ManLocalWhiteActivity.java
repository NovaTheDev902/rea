package com.lenovo.safecenter.lenovoAntiSpam.views;

import android.app.Activity;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.provider.Settings;
import android.text.TextUtils;
import android.util.Patterns;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseExpandableListAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ExpandableListView;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase;
import com.lenovo.safecenter.lenovoAntiSpam.domain.BlackInfo;
import com.lenovo.safecenter.lenovoAntiSpam.domain.ContractHelpUtils;
import com.lenovo.safecenter.safemode.SofeModeMain;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class ManLocalWhiteActivity extends Activity {

    /* JADX INFO: renamed from: a */
    AppDatabase f4209a;

    /* JADX INFO: renamed from: b */
    Button f4210b;

    /* JADX INFO: renamed from: c */
    private ExpandableListView f4211c;

    /* JADX INFO: renamed from: d */
    private List<BlackInfo> f4212d;

    /* JADX INFO: renamed from: e */
    private ProgressDialog f4213e;

    /* JADX INFO: renamed from: f */
    private TextView f4214f;

    /* JADX INFO: renamed from: g */
    private ContractHelpUtils f4215g;

    /* JADX INFO: renamed from: h */
    private C0708a f4216h;

    /* JADX INFO: renamed from: i */
    private Handler f4217i = new HandlerC0709b(this, 0);

    /* JADX INFO: renamed from: j */
    private int f4218j;

    /* JADX INFO: renamed from: i */
    static /* synthetic */ void m1749i(ManLocalWhiteActivity x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.notify).setMessage(C0415R.string.del_info).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalWhiteActivity.9
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                ManLocalWhiteActivity.this.deleteWhite();
                Toast.makeText(ManLocalWhiteActivity.this, C0415R.string.del_sucess, 0).show();
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalWhiteActivity.8
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalWhiteActivity$b */
    private class HandlerC0709b extends Handler {
        private HandlerC0709b() {
        }

        /* synthetic */ HandlerC0709b(ManLocalWhiteActivity x0, byte b) {
            this();
        }

        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    ContractHelpUtils.sendBraodcast(ManLocalWhiteActivity.this, "com.lenovo.antispam.whiteperson.change");
                    if (ManLocalWhiteActivity.this.f4212d.size() != 0) {
                        ManLocalWhiteActivity.this.f4216h.notifyDataSetChanged();
                        ManLocalWhiteActivity.this.f4211c.invalidateViews();
                    } else {
                        ManLocalWhiteActivity.this.initViewSys();
                    }
                    break;
                case 2:
                    if (ManLocalWhiteActivity.this.f4213e != null) {
                        try {
                            ManLocalWhiteActivity.this.f4213e.dismiss();
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                    if (ManLocalWhiteActivity.this.f4212d != null) {
                        ManLocalWhiteActivity.this.f4214f.setVisibility(8);
                        ManLocalWhiteActivity.this.f4211c.setAdapter(ManLocalWhiteActivity.this.f4216h);
                    } else {
                        ManLocalWhiteActivity.this.f4214f.setVisibility(0);
                    }
                    break;
                case 3:
                    ManLocalWhiteActivity.this.f4211c.invalidateViews();
                    break;
                case 4:
                    ContractHelpUtils.sendBraodcast(ManLocalWhiteActivity.this, "com.lenovo.antispam.whiteperson.change");
                    ManLocalWhiteActivity.this.initViewSys();
                    break;
            }
        }
    }

    @Override // android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.antispamlocalblack_view);
        this.f4211c = (ExpandableListView) findViewById(C0415R.id.addblacklist);
        this.f4211c.setGroupIndicator(null);
        this.f4211c.setDivider(getResources().getDrawable(C0415R.drawable.space_line));
        this.f4214f = (TextView) findViewById(C0415R.id.antispamcallempty);
        this.f4214f.setText(C0415R.string.antispamnowhiteperson);
        this.f4210b = (Button) findViewById(C0415R.id.sigleadd_btn);
        this.f4215g = new ContractHelpUtils();
        this.f4209a = new AppDatabase(this);
        this.f4211c.setEmptyView(this.f4214f);
        if (Settings.System.getInt(getContentResolver(), "guest_mode_on", 0) == 1) {
            this.f4210b.setEnabled(false);
        }
        setOnClick();
    }

    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        }
    }

    public void initDate() {
        this.f4212d = this.f4209a.getWhitePersonList();
        if (Settings.System.getInt(getContentResolver(), "guest_mode_on", 0) == 1) {
            this.f4212d = new ArrayList();
        }
        this.f4216h = new C0708a(this);
        this.f4211c.setAdapter(this.f4216h);
    }

    public void initViewSys() {
        initDate();
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        initViewSys();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    public void setOnClick() {
        this.f4211c.setOnGroupExpandListener(new ExpandableListView.OnGroupExpandListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalWhiteActivity.1
            @Override // android.widget.ExpandableListView.OnGroupExpandListener
            public final void onGroupExpand(int groupPosition) {
                ManLocalWhiteActivity.this.f4218j = groupPosition;
                if (groupPosition == ManLocalWhiteActivity.this.f4212d.size() - 1) {
                    ManLocalWhiteActivity.this.f4211c.setTranscriptMode(2);
                } else {
                    ManLocalWhiteActivity.this.f4211c.setTranscriptMode(1);
                }
                for (int i = 0; i < ManLocalWhiteActivity.this.f4216h.getGroupCount(); i++) {
                    if (groupPosition != i) {
                        ManLocalWhiteActivity.this.f4211c.collapseGroup(i);
                    }
                }
            }
        });
        this.f4210b.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalWhiteActivity.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (ManLocalWhiteActivity.this.f4212d != null && ManLocalWhiteActivity.this.f4212d.size() >= 500) {
                    Toast.makeText(ManLocalWhiteActivity.this, C0415R.string.antispamdata_limit1, 0).show();
                } else {
                    ManLocalWhiteActivity.this.showDialog(1);
                }
            }
        });
    }

    @Override // android.app.Activity
    public Dialog onCreateDialog(int id, Bundle args) {
        switch (id) {
            case 1:
                return new CustomDialog.Builder(this).setTitle(getString(C0415R.string.antispamquick_operation)).setItems(C0415R.array.antispamadd_whitephone, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalWhiteActivity.3
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                        switch (which) {
                            case 0:
                                Intent intentContract = new Intent(ManLocalWhiteActivity.this, (Class<?>) ManAddWhiteContract.class);
                                intentContract.putExtra("from", SofeModeMain.TS_CALL);
                                ManLocalWhiteActivity.this.startActivity(intentContract);
                                break;
                            case 1:
                                Intent intentSMS = new Intent(ManLocalWhiteActivity.this, (Class<?>) ManAddWhiteContract.class);
                                intentSMS.putExtra("from", SofeModeMain.TS_SMS);
                                ManLocalWhiteActivity.this.startActivity(intentSMS);
                                break;
                            case 2:
                                Intent intent = new Intent(ManLocalWhiteActivity.this, (Class<?>) ManAddWhiteContract.class);
                                intent.putExtra("from", "phone");
                                ManLocalWhiteActivity.this.startActivity(intent);
                                break;
                            case 3:
                                ManLocalWhiteActivity.this.showAddDialog();
                                break;
                        }
                    }
                }).create();
            default:
                return null;
        }
    }

    public void showAddDialog() {
        View view = LayoutInflater.from(this).inflate(C0415R.layout.safemode_input_password, (ViewGroup) null);
        final EditText pwd = (EditText) view.findViewById(C0415R.id.safemode_input_pwd);
        final EditText pwd2 = (EditText) view.findViewById(C0415R.id.safemode_input_pwd_again);
        TextView txt1 = (TextView) view.findViewById(C0415R.id.safemode_dailog_title1);
        TextView txt2 = (TextView) view.findViewById(C0415R.id.safemode_dailog_title2);
        txt1.setText(C0415R.string.hand_number);
        txt2.setText(C0415R.string.antispamhand_name);
        pwd.setInputType(2);
        pwd2.setInputType(144);
        new CustomDialog.Builder(this).setTitle(C0415R.string.antispamaddfromphone).setContentView(view).setPositiveButton(C0415R.string.save, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalWhiteActivity.5
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                if (pwd.getText() != null && !pwd.getText().toString().trim().equals("")) {
                    if (TextUtils.isDigitsOnly(pwd.getText().toString()) || Patterns.PHONE.matcher(pwd.getText().toString()).matches()) {
                        String checknumber = pwd.getText().toString().trim().toString();
                        if (!ManLocalWhiteActivity.this.iswhite(checknumber)) {
                            if (!ManLocalWhiteActivity.this.isBlack(pwd.getText().toString().trim())) {
                                if (!TextUtils.isEmpty(pwd2.getText())) {
                                    ManLocalWhiteActivity.this.f4209a.insertWritePerson(checknumber, ManLocalWhiteActivity.this.f4215g.getRealPhoneNumber(checknumber), pwd2.getText().toString().trim());
                                } else {
                                    ManLocalWhiteActivity.this.f4209a.insertWritePerson(checknumber, ManLocalWhiteActivity.this.f4215g.getRealPhoneNumber(checknumber), null);
                                }
                                ManLocalWhiteActivity.this.f4217i.sendEmptyMessage(4);
                                return;
                            }
                            Toast.makeText(ManLocalWhiteActivity.this, C0415R.string.antispamhand_number_error1, 0).show();
                            return;
                        }
                        Toast.makeText(ManLocalWhiteActivity.this, C0415R.string.antispamhand_number_error3, 0).show();
                        return;
                    }
                    Toast.makeText(ManLocalWhiteActivity.this, C0415R.string.hand_number_error, 0).show();
                    return;
                }
                Toast.makeText(ManLocalWhiteActivity.this, C0415R.string.hand_number_null, 0).show();
            }
        }).setNegativeButton(C0415R.string.safemode_cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalWhiteActivity.4
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }

    public void showEditDialog() {
        View view = LayoutInflater.from(this).inflate(C0415R.layout.safemode_input_password, (ViewGroup) null);
        final EditText pwd = (EditText) view.findViewById(C0415R.id.safemode_input_pwd);
        final EditText pwd2 = (EditText) view.findViewById(C0415R.id.safemode_input_pwd_again);
        TextView txt1 = (TextView) view.findViewById(C0415R.id.safemode_dailog_title1);
        TextView txt2 = (TextView) view.findViewById(C0415R.id.safemode_dailog_title2);
        txt1.setText(C0415R.string.hand_number);
        txt2.setText(C0415R.string.hand_name);
        pwd.setInputType(2);
        pwd2.setInputType(144);
        pwd.setText(this.f4212d.get(this.f4218j).getPhoneNumber());
        pwd2.setText(TextUtils.isEmpty(this.f4212d.get(this.f4218j).getName()) ? "" : this.f4212d.get(this.f4218j).getName());
        new CustomDialog.Builder(this).setTitle(C0415R.string.antispamaddfromphone).setContentView(view).setPositiveButton(C0415R.string.sumbit, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalWhiteActivity.7
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                if (!TextUtils.isEmpty(pwd.getText())) {
                    if (TextUtils.isDigitsOnly(pwd.getText().toString()) || Patterns.PHONE.matcher(pwd.getText().toString()).matches()) {
                        String checknumber = pwd.getText().toString();
                        if (!ManLocalWhiteActivity.this.iswhiteEdit(checknumber, ((BlackInfo) ManLocalWhiteActivity.this.f4212d.get(ManLocalWhiteActivity.this.f4218j)).getId())) {
                            if (!ManLocalWhiteActivity.this.isBlack(pwd.getText().toString().trim())) {
                                if (!TextUtils.isEmpty(pwd2.getText())) {
                                    ManLocalWhiteActivity.this.f4209a.updateWritePerson(checknumber, ManLocalWhiteActivity.this.f4215g.getRealPhoneNumber(checknumber), pwd2.getText().toString().trim(), ((BlackInfo) ManLocalWhiteActivity.this.f4212d.get(ManLocalWhiteActivity.this.f4218j)).getId());
                                    ((BlackInfo) ManLocalWhiteActivity.this.f4212d.get(ManLocalWhiteActivity.this.f4218j)).setName(pwd2.getText().toString());
                                    ((BlackInfo) ManLocalWhiteActivity.this.f4212d.get(ManLocalWhiteActivity.this.f4218j)).setPhoneNumber(checknumber);
                                    ManLocalWhiteActivity.this.f4216h.notifyDataSetChanged();
                                } else {
                                    ManLocalWhiteActivity.this.f4209a.updateWritePerson(checknumber, ManLocalWhiteActivity.this.f4215g.getRealPhoneNumber(checknumber), null, ((BlackInfo) ManLocalWhiteActivity.this.f4212d.get(ManLocalWhiteActivity.this.f4218j)).getId());
                                    ((BlackInfo) ManLocalWhiteActivity.this.f4212d.get(ManLocalWhiteActivity.this.f4218j)).setName(null);
                                    ((BlackInfo) ManLocalWhiteActivity.this.f4212d.get(ManLocalWhiteActivity.this.f4218j)).setPhoneNumber(checknumber);
                                    ManLocalWhiteActivity.this.f4216h.notifyDataSetChanged();
                                }
                                ContractHelpUtils.sendBraodcast(ManLocalWhiteActivity.this, "com.lenovo.antispam.whiteperson.change");
                                return;
                            }
                            Toast.makeText(ManLocalWhiteActivity.this, C0415R.string.antispamhand_number_error1, 0).show();
                            return;
                        }
                        Toast.makeText(ManLocalWhiteActivity.this, C0415R.string.antispamhand_number_error3, 0).show();
                        return;
                    }
                    Toast.makeText(ManLocalWhiteActivity.this, C0415R.string.hand_number_error, 0).show();
                    return;
                }
                Toast.makeText(ManLocalWhiteActivity.this, C0415R.string.hand_number_null, 0).show();
            }
        }).setNegativeButton(C0415R.string.safemode_cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalWhiteActivity.6
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }

    public boolean iswhiteEdit(String number, int id) {
        Uri uri1 = Uri.parse("content://com.lenovo.safecenter.WhitePersonProvider/whiteperson");
        Cursor phoneCursor = getContentResolver().query(uri1, null, "PHONE_NUMBERS_EQUAL(phonenumber,'" + number + "',0) and _id<>?", new String[]{String.valueOf(id)}, null);
        boolean isWhite = false;
        if (phoneCursor.getCount() > 0) {
            isWhite = true;
        }
        phoneCursor.close();
        return isWhite;
    }

    public boolean iswhite(String number) {
        Uri uri1 = Uri.parse("content://com.lenovo.safecenter.WhitePersonProvider/whiteperson");
        Cursor phoneCursor = getContentResolver().query(uri1, null, "PHONE_NUMBERS_EQUAL(phonenumber,'" + number + "',0)", null, null);
        boolean isWhite = false;
        if (phoneCursor.getCount() > 0) {
            isWhite = true;
        }
        phoneCursor.close();
        return isWhite;
    }

    public boolean isBlack(String phoneNumber) {
        Uri uri1 = Uri.parse("content://com.lenovo.safecenter.LocalBlackProvider/localblack");
        Cursor phoneCursor = getContentResolver().query(uri1, null, "PHONE_NUMBERS_EQUAL(phonenumber,'" + phoneNumber + "',0)", null, null);
        boolean isBlack = false;
        if (phoneCursor.getCount() > 0) {
            isBlack = true;
        }
        phoneCursor.close();
        return isBlack;
    }

    public void deleteWhite() {
        this.f4209a.deleteWhite(this.f4212d.get(this.f4218j).getId());
        this.f4212d.remove(this.f4218j);
        this.f4216h.notifyDataSetChanged();
        if (this.f4218j < this.f4212d.size()) {
            this.f4211c.collapseGroup(this.f4218j);
        }
        ContractHelpUtils.sendBraodcast(this, "com.lenovo.antispam.whiteperson.change");
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalWhiteActivity$a */
    class C0708a extends BaseExpandableListAdapter {

        /* JADX INFO: renamed from: a */
        Context f4232a;

        /* JADX INFO: renamed from: b */
        b f4233b;

        /* JADX INFO: renamed from: c */
        a f4234c;

        /* JADX INFO: renamed from: e */
        private LayoutInflater f4236e;

        public C0708a(Context context) {
            this.f4236e = LayoutInflater.from(context);
            this.f4232a = context;
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
                convertView = this.f4236e.inflate(C0415R.layout.dealitemequal, (ViewGroup) null);
                this.f4234c = new a();
                this.f4234c.f4239a = (TextView) convertView.findViewById(C0415R.id.deal1);
                this.f4234c.f4240b = (TextView) convertView.findViewById(C0415R.id.deal2);
                this.f4234c.f4241c = (TextView) convertView.findViewById(C0415R.id.deal3);
                convertView.setTag(this.f4234c);
            } else {
                this.f4234c = (a) convertView.getTag();
            }
            this.f4234c.f4239a.setText(C0415R.string.mutil_edit);
            this.f4234c.f4240b.setVisibility(8);
            this.f4234c.f4241c.setText(C0415R.string.delete);
            this.f4234c.f4239a.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalWhiteActivity.a.1
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    ManLocalWhiteActivity.this.showEditDialog();
                }
            });
            this.f4234c.f4241c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalWhiteActivity.a.2
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    ManLocalWhiteActivity.m1749i(ManLocalWhiteActivity.this);
                }
            });
            return convertView;
        }

        @Override // android.widget.ExpandableListAdapter
        public final Object getGroup(int groupPosition) {
            return ManLocalWhiteActivity.this.f4212d.get(groupPosition);
        }

        @Override // android.widget.ExpandableListAdapter
        public final int getGroupCount() {
            return ManLocalWhiteActivity.this.f4212d.size();
        }

        @Override // android.widget.ExpandableListAdapter
        public final long getGroupId(int groupPosition) {
            return groupPosition;
        }

        @Override // android.widget.ExpandableListAdapter
        public final View getGroupView(int groupPosition, boolean isExpanded, View convertView, ViewGroup parent) {
            if (convertView == null) {
                convertView = LayoutInflater.from(this.f4232a).inflate(C0415R.layout.antispamblackinfo_item1, (ViewGroup) null);
                this.f4233b = new b();
                this.f4233b.f4243a = (ImageView) convertView.findViewById(C0415R.id.antispamblack_image);
                this.f4233b.f4246d = (TextView) convertView.findViewById(C0415R.id.antispamlocalblack_name);
                this.f4233b.f4247e = (TextView) convertView.findViewById(C0415R.id.antispamlocalblack_number);
                this.f4233b.f4245c = (ImageView) convertView.findViewById(C0415R.id.antispamisupload);
                this.f4233b.f4244b = (ImageView) convertView.findViewById(C0415R.id.antispamblack_check);
                convertView.setTag(this.f4233b);
            } else {
                this.f4233b = (b) convertView.getTag();
            }
            BlackInfo info = (BlackInfo) ManLocalWhiteActivity.this.f4212d.get(groupPosition);
            this.f4233b.f4244b.setVisibility(8);
            this.f4233b.f4243a.setImageResource(C0415R.drawable.antispamwhite);
            this.f4233b.f4245c.setVisibility(8);
            this.f4233b.f4247e.setText(info.getPhoneNumber());
            if (info.getName() == null || info.getName().equals("")) {
                this.f4233b.f4246d.setText(C0415R.string.antispamlocalblack_noName);
            } else {
                this.f4233b.f4246d.setText(info.getName());
            }
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

        /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalWhiteActivity$a$b */
        class b {

            /* JADX INFO: renamed from: a */
            ImageView f4243a;

            /* JADX INFO: renamed from: b */
            ImageView f4244b;

            /* JADX INFO: renamed from: c */
            ImageView f4245c;

            /* JADX INFO: renamed from: d */
            TextView f4246d;

            /* JADX INFO: renamed from: e */
            TextView f4247e;

            b() {
            }
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalWhiteActivity$a$a */
        class a {

            /* JADX INFO: renamed from: a */
            TextView f4239a;

            /* JADX INFO: renamed from: b */
            TextView f4240b;

            /* JADX INFO: renamed from: c */
            TextView f4241c;

            a() {
            }
        }
    }
}
