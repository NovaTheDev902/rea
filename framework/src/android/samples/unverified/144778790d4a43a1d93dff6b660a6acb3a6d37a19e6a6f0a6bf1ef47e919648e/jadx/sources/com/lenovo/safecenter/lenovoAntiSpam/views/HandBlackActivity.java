package com.lenovo.safecenter.lenovoAntiSpam.views;

import android.content.ContentResolver;
import android.content.Context;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.util.Patterns;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Toast;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase;
import com.lenovo.safecenter.lenovoAntiSpam.domain.BlackInfo;
import com.lenovo.safecenter.lenovoAntiSpam.domain.ContractHelpUtils;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class HandBlackActivity extends BaseTitleActivity {

    /* JADX INFO: renamed from: a */
    private int f4013a;

    /* JADX INFO: renamed from: b */
    private EditText f4014b;

    /* JADX INFO: renamed from: c */
    private EditText f4015c;

    /* JADX INFO: renamed from: d */
    private Button f4016d;

    /* JADX INFO: renamed from: e */
    private Button f4017e;

    /* JADX INFO: renamed from: f */
    private ContractHelpUtils f4018f;

    /* JADX INFO: renamed from: g */
    private CheckBox f4019g;

    /* JADX INFO: renamed from: h */
    private CheckBox f4020h;

    /* JADX INFO: renamed from: i */
    private AppDatabase f4021i;

    /* JADX INFO: renamed from: j */
    private String f4022j;

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        this.f4022j = getIntent().getStringExtra("method");
        this.f4013a = getIntent().getIntExtra("type", 0);
        setContentView(C0415R.layout.antispamhandblack);
        this.f4021i = new AppDatabase(this);
        this.f4019g = (CheckBox) findViewById(C0415R.id.harass_call);
        this.f4020h = (CheckBox) findViewById(C0415R.id.harass_sms);
        this.f4014b = (EditText) findViewById(C0415R.id.antispamhand_number_value);
        this.f4015c = (EditText) findViewById(C0415R.id.antispamhand_name_value);
        this.f4016d = (Button) findViewById(C0415R.id.antispamhand_numbre_add);
        this.f4017e = (Button) findViewById(C0415R.id.antispamhand_numbre_back);
        this.f4018f = new ContractHelpUtils();
        onBtnClick();
        if (this.f4022j.equals("add")) {
            this.f4014b.setEnabled(true);
            setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.antispamaddcall, (Integer) null);
            this.f4019g.setChecked(true);
            this.f4020h.setChecked(true);
            return;
        }
        if (this.f4022j.equals("modify")) {
            this.f4016d.setBackgroundResource(C0415R.drawable.signbtn_bg);
            BlackInfo info = this.f4021i.getLocalBlackDemo(getIntent().getIntExtra(QueryPermissions.f1958ID, 0));
            Log.i("info", info + "==" + getIntent().getIntExtra(QueryPermissions.f1958ID, 0));
            if (info != null) {
                this.f4016d.setText(C0415R.string.change);
                setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.modify_black, (Integer) null);
                if (info.getType() == 2) {
                    this.f4019g.setChecked(true);
                    this.f4020h.setChecked(true);
                } else if (info.getType() == 1) {
                    this.f4019g.setChecked(true);
                    this.f4020h.setChecked(false);
                } else if (info.getType() == 0) {
                    this.f4019g.setChecked(false);
                    this.f4020h.setChecked(true);
                } else {
                    this.f4019g.setChecked(false);
                    this.f4020h.setChecked(false);
                }
                this.f4014b.setText(info.getPhoneNumber());
                if (info.getIsUpload() == 1) {
                    this.f4014b.setEnabled(false);
                } else {
                    this.f4014b.setEnabled(true);
                }
                if (info.getName() != null && !info.getName().equals("")) {
                    this.f4015c.setText(info.getName());
                }
            }
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        }
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        super.onResume();
    }

    public void onBtnClick() {
        this.f4016d.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.HandBlackActivity.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                String name;
                if (HandBlackActivity.this.f4014b.getText() != null && !HandBlackActivity.this.f4014b.getText().toString().trim().equalsIgnoreCase("")) {
                    String number = HandBlackActivity.this.f4014b.getText().toString();
                    if (TextUtils.isDigitsOnly(number.trim()) || Patterns.PHONE.matcher(number.trim()).matches()) {
                        String checknumber = HandBlackActivity.this.f4018f.getRealPhoneNumber(number);
                        Uri uri1 = Uri.parse("content://com.lenovo.safecenter.WhitePersonProvider/whiteperson");
                        Cursor phoneCursor = HandBlackActivity.this.getContentResolver().query(uri1, new String[]{"_id"}, "realnumber=?", new String[]{checknumber}, null);
                        int count = phoneCursor.getCount();
                        phoneCursor.close();
                        if (count <= 0) {
                            if (HandBlackActivity.this.f4015c.getText() != null && !HandBlackActivity.this.f4015c.getText().toString().equalsIgnoreCase("")) {
                                name = HandBlackActivity.this.f4015c.getText().toString();
                            } else {
                                Uri uri2 = Uri.parse("content://com.android.contacts/data/phones");
                                Cursor contract_Cursor = HandBlackActivity.this.getContentResolver().query(uri2, new String[]{"display_name"}, "PHONE_NUMBERS_EQUAL(data1,'" + checknumber + "',0)", null, null);
                                if (!contract_Cursor.moveToFirst()) {
                                    name = null;
                                } else {
                                    name = contract_Cursor.getString(contract_Cursor.getColumnIndex("display_name"));
                                }
                                if (name == null || name.equals("")) {
                                    name = null;
                                }
                                contract_Cursor.close();
                            }
                            if (HandBlackActivity.this.f4019g.isChecked() && HandBlackActivity.this.f4020h.isChecked()) {
                                HandBlackActivity.this.f4013a = 2;
                            }
                            if (HandBlackActivity.this.f4019g.isChecked() && !HandBlackActivity.this.f4020h.isChecked()) {
                                HandBlackActivity.this.f4013a = 1;
                            }
                            if (!HandBlackActivity.this.f4019g.isChecked() && HandBlackActivity.this.f4020h.isChecked()) {
                                HandBlackActivity.this.f4013a = 0;
                            }
                            if (!HandBlackActivity.this.f4019g.isChecked() && !HandBlackActivity.this.f4020h.isChecked()) {
                                HandBlackActivity.this.f4013a = 4;
                            }
                            if (HandBlackActivity.this.f4022j.equals("modify")) {
                                if (!HandBlackActivity.this.isLocalBlackEdit(number, HandBlackActivity.this.getIntent().getIntExtra(QueryPermissions.f1958ID, 0))) {
                                    HandBlackActivity.this.f4021i.updateLocalBlack_Demo(HandBlackActivity.this.getIntent().getIntExtra(QueryPermissions.f1958ID, 0), name, number, checknumber, HandBlackActivity.this.f4013a, 0);
                                    ContractHelpUtils.sendBraodcast(HandBlackActivity.this, "com.lenovo.antispam.blackperson.change");
                                    HandBlackActivity.this.finish();
                                    return;
                                }
                                Toast.makeText(HandBlackActivity.this, C0415R.string.antispamhand_number_error1, 0).show();
                                return;
                            }
                            if (!HandBlackActivity.isLocalBlack(HandBlackActivity.this, number)) {
                                BlackInfo newinfo = new BlackInfo(name, number, HandBlackActivity.this.f4013a, 0);
                                newinfo.setRealnumber(HandBlackActivity.this.f4018f.getRealPhoneNumber(number));
                                HandBlackActivity.this.f4021i.insertLocalBlack(newinfo);
                                ContractHelpUtils.sendBraodcast(HandBlackActivity.this, "com.lenovo.antispam.blackperson.change");
                                Toast.makeText(HandBlackActivity.this, C0415R.string.info_success, 0).show();
                                HandBlackActivity.this.finish();
                                return;
                            }
                            Toast.makeText(HandBlackActivity.this, C0415R.string.antispamhand_number_error1, 0).show();
                            return;
                        }
                        Toast.makeText(HandBlackActivity.this, C0415R.string.antispamhand_number_error3, 0).show();
                        return;
                    }
                    Toast.makeText(HandBlackActivity.this, C0415R.string.hand_number_error, 0).show();
                    return;
                }
                Toast.makeText(HandBlackActivity.this, C0415R.string.antispamhand_number_null, 0).show();
            }
        });
        this.f4017e.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.HandBlackActivity.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                HandBlackActivity.this.finish();
            }
        });
    }

    public static boolean isLocalBlack(Context context, String number) {
        try {
            ContentResolver resolver = context.getContentResolver();
            ContractHelpUtils help = new ContractHelpUtils();
            if (help.isMobileNO(number)) {
                number = help.optNUmber(number);
            }
            Uri uri = Uri.parse("content://com.lenovo.safecenter.LocalBlackProvider/localblack");
            Cursor cursor = resolver.query(uri, null, "PHONE_NUMBERS_EQUAL(phonenumber,'" + number + "',0)", null, null);
            int count = cursor.getCount();
            cursor.close();
            return count > 0;
        } catch (Exception e) {
            return false;
        }
    }

    public boolean isLocalBlackEdit(String number, int id) {
        try {
            Uri uri = Uri.parse("content://com.lenovo.safecenter.LocalBlackProvider/localblack");
            Cursor cursor = getContentResolver().query(uri, null, "PHONE_NUMBERS_EQUAL(phonenumber,'" + number + "',0) and _id<>?", new String[]{String.valueOf(id)}, null);
            int count = cursor.getCount();
            cursor.close();
            return count > 0;
        } catch (Exception e) {
            return false;
        }
    }
}
