package com.lenovo.safecenter.safemode;

import android.app.Activity;
import android.app.Dialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.util.Patterns;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.EditText;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.adapter.whiteContractAdapter;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.support.Contract;
import com.lenovo.safecenter.utils.ContractHelpUtils;
import com.lenovo.safecenter.utils.DataHelpUtils;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class ErrorWhiteContract extends Activity {
    public static List<Contract> list = new ArrayList();

    /* JADX INFO: renamed from: a */
    ContractHelpUtils f5125a;

    /* JADX INFO: renamed from: b */
    private ListView f5126b;

    /* JADX INFO: renamed from: c */
    private TextView f5127c;

    /* JADX INFO: renamed from: d */
    private TextView f5128d;

    /* JADX INFO: renamed from: e */
    private BaseAdapter f5129e;

    /* JADX INFO: renamed from: f */
    private boolean f5130f = false;

    /* JADX INFO: renamed from: g */
    private int f5131g = 0;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ boolean m2123a(ErrorWhiteContract x0) {
        x0.f5130f = false;
        return false;
    }

    /* JADX INFO: renamed from: d */
    static /* synthetic */ void m2126d(ErrorWhiteContract x0) {
        final Contract contract = list.get(x0.f5131g);
        String name = contract.getName();
        if (contract.getName() == null) {
            name = contract.getPhoneNumber();
        }
        new CustomDialog.Builder(x0).setTitle(name).setItems(new String[]{x0.getString(C0415R.string.delete), x0.getString(C0415R.string.safemode_callto), x0.getString(C0415R.string.replay_sms), x0.getString(C0415R.string.mutil_edit)}, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ErrorWhiteContract.7
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                switch (which) {
                    case 0:
                        ErrorWhiteContract.list.remove(ErrorWhiteContract.this.f5131g);
                        ErrorWhiteContract.this.f5126b.invalidateViews();
                        ContractHelpUtils.sendBraodcast(ErrorWhiteContract.this, "com.lenovo.securityperson.change");
                        break;
                    case 1:
                        try {
                            Intent callIntent = new Intent("android.intent.action.DIAL", Uri.parse("tel:" + contract.getPhoneNumber()));
                            ErrorWhiteContract.this.startActivity(callIntent);
                        } catch (Exception e) {
                            Toast.makeText(ErrorWhiteContract.this, C0415R.string.opensms_error, 0).show();
                            return;
                        }
                        break;
                    case 2:
                        try {
                            Uri smsToUri = Uri.parse("smsto:" + contract.getPhoneNumber());
                            Intent smsIntent = new Intent("android.intent.action.SENDTO", smsToUri);
                            ErrorWhiteContract.this.startActivity(smsIntent);
                        } catch (Exception e2) {
                            Toast.makeText(ErrorWhiteContract.this, C0415R.string.opensms_error, 0).show();
                            return;
                        }
                        break;
                    case 3:
                        ErrorWhiteContract.this.showChangeContract();
                        break;
                    case 4:
                        ErrorWhiteContract errorWhiteContract = ErrorWhiteContract.this;
                        Contract contract2 = contract;
                        ErrorWhiteContract.m2128f(errorWhiteContract);
                        break;
                }
            }
        }).create().show();
    }

    /* JADX INFO: renamed from: f */
    static /* synthetic */ void m2128f(ErrorWhiteContract x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.notify).setMessage(C0415R.string.notifycopy).setPositiveButton(C0415R.string.sumbit, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ErrorWhiteContract.9
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                Toast.makeText(ErrorWhiteContract.this, C0415R.string.waitting_background, 0).show();
                Log.i(AppDatabase.CONTENT, ErrorWhiteContract.this.getString(C0415R.string.waitting_background));
            }
        }).setNegativeButton(C0415R.string.safemode_cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ErrorWhiteContract.8
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).create().show();
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.whitecontract);
        ((TextView) findViewById(C0415R.id.txt_title)).setText(C0415R.string.privacy_safe);
        this.f5126b = (ListView) findViewById(C0415R.id.safemode_whitecontractlist);
        this.f5128d = (TextView) findViewById(C0415R.id.private_empty_textview);
        this.f5127c = (TextView) findViewById(C0415R.id.safemode_whitecontract_count);
        this.f5125a = new ContractHelpUtils();
        DataHelpUtils.allActivity.add(this);
        this.f5126b.setEmptyView(this.f5128d);
        onClick();
    }

    public String getWhiteCount(int count) {
        String str = getString(C0415R.string.whitecount);
        return String.format(str, Integer.valueOf(count));
    }

    @Override // android.app.Activity
    public Dialog onCreateDialog(int id, Bundle args) {
        switch (id) {
            case 1:
                return new CustomDialog.Builder(this).setTitle(getString(C0415R.string.quick_addtitle)).setItems(C0415R.array.private_quick_add, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ErrorWhiteContract.1
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                        switch (which) {
                            case 0:
                                Intent callIntent = new Intent(ErrorWhiteContract.this, (Class<?>) ErrorAddContract.class);
                                callIntent.putExtra("fromtype", 1);
                                ErrorWhiteContract.this.startActivity(callIntent);
                                break;
                            case 1:
                                Intent smsIntent = new Intent(ErrorWhiteContract.this, (Class<?>) ErrorAddContract.class);
                                smsIntent.putExtra("fromtype", 2);
                                ErrorWhiteContract.this.startActivity(smsIntent);
                                break;
                            case 2:
                                Intent contractIntent = new Intent(ErrorWhiteContract.this, (Class<?>) ErrorAddContract.class);
                                contractIntent.putExtra("fromtype", 0);
                                ErrorWhiteContract.this.startActivity(contractIntent);
                                break;
                            case 3:
                                ErrorWhiteContract.this.showAddDialog();
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
        txt2.setText(C0415R.string.hand_name);
        pwd.setInputType(144);
        pwd2.setInputType(144);
        new CustomDialog.Builder(this).setTitle(C0415R.string.privacy_mode_set).setContentView(view).setPositiveButton(C0415R.string.sumbit, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ErrorWhiteContract.4
            /* JADX WARN: Type inference failed for: r2v25, types: [com.lenovo.safecenter.safemode.ErrorWhiteContract$4$1] */
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                if (pwd.getText() != null && !pwd.getText().toString().trim().equals("")) {
                    if (Patterns.PHONE.matcher(pwd.getText().toString()).matches()) {
                        String name = null;
                        if (pwd2.getText() != null && !pwd2.getText().toString().trim().equalsIgnoreCase("")) {
                            name = pwd2.getText().toString();
                        }
                        Contract conAdd = new Contract();
                        conAdd.setName(name);
                        conAdd.setPhoneNumber(pwd.getText().toString());
                        conAdd.setRealnumber(ErrorWhiteContract.this.f5125a.getRealPhoneNumber(pwd.getText().toString()));
                        ContractHelpUtils.sendBraodcast(ErrorWhiteContract.this, "com.lenovo.securityperson.change");
                        ErrorWhiteContract.list.add(conAdd);
                        ErrorWhiteContract.this.initDate();
                        new Thread() { // from class: com.lenovo.safecenter.safemode.ErrorWhiteContract.4.1
                            @Override // java.lang.Thread, java.lang.Runnable
                            public final void run() {
                            }
                        }.start();
                        return;
                    }
                    Toast.makeText(ErrorWhiteContract.this, C0415R.string.hand_number_error, 0).show();
                    return;
                }
                Toast.makeText(ErrorWhiteContract.this, C0415R.string.hand_number_null, 0).show();
            }
        }).setNegativeButton(C0415R.string.safemode_cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ErrorWhiteContract.3
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }

    public void onClick() {
        this.f5127c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ErrorWhiteContract.5
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                ErrorWhiteContract.m2123a(ErrorWhiteContract.this);
                ErrorWhiteContract.this.showDialog(1);
            }
        });
        this.f5126b.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.safemode.ErrorWhiteContract.6
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Contract con = (Contract) ErrorWhiteContract.this.f5126b.getItemAtPosition(position);
                if (!ErrorWhiteContract.this.f5130f) {
                    ErrorWhiteContract.this.f5131g = position;
                    ErrorWhiteContract.m2126d(ErrorWhiteContract.this);
                }
                if (ErrorWhiteContract.this.f5130f) {
                    if (con.isSelect()) {
                        con.setSelect(false);
                    } else {
                        con.setSelect(true);
                    }
                    ErrorWhiteContract.this.f5126b.invalidateViews();
                }
            }
        });
    }

    public void showChangeContract() {
        View view = LayoutInflater.from(this).inflate(C0415R.layout.safemode_input_password, (ViewGroup) null);
        final EditText pwd = (EditText) view.findViewById(C0415R.id.safemode_input_pwd);
        final EditText pwd2 = (EditText) view.findViewById(C0415R.id.safemode_input_pwd_again);
        TextView txt1 = (TextView) view.findViewById(C0415R.id.safemode_dailog_title1);
        TextView txt2 = (TextView) view.findViewById(C0415R.id.safemode_dailog_title2);
        txt1.setText(C0415R.string.hand_name);
        txt2.setText(C0415R.string.hand_number);
        pwd.setInputType(144);
        pwd2.setInputType(144);
        Contract con = list.get(this.f5131g);
        if (con.getName() == null || con.getName().equals("")) {
            pwd.setText("");
        } else {
            pwd.setText(con.getName());
        }
        pwd2.setText(con.getPhoneNumber());
        new CustomDialog.Builder(this).setTitle(C0415R.string.mutil_edit).setContentView(view).setPositiveButton(C0415R.string.sumbit, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ErrorWhiteContract.2
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                if (!pwd2.getText().toString().equals("") && Patterns.PHONE.matcher(pwd2.getText().toString()).matches()) {
                    String number = pwd2.getText().toString();
                    String name = pwd.getText().toString();
                    if (pwd.getText().toString().equals("")) {
                        name = null;
                    }
                    ErrorWhiteContract.list.get(ErrorWhiteContract.this.f5131g).setPhoneNumber(number);
                    ErrorWhiteContract.list.get(ErrorWhiteContract.this.f5131g).setName(name);
                    ErrorWhiteContract.this.f5126b.invalidateViews();
                    Toast.makeText(ErrorWhiteContract.this, C0415R.string.setting_pwdok, 0).show();
                    return;
                }
                Toast.makeText(ErrorWhiteContract.this, C0415R.string.setting_pwdfail, 0).show();
            }
        }).setNegativeButton(C0415R.string.safemode_cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ErrorWhiteContract.10
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }

    public void initDate() {
        this.f5129e = new whiteContractAdapter(this, list, this.f5130f);
        this.f5126b.setAdapter((ListAdapter) this.f5129e);
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

    @Override // android.app.Activity
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case 0:
                List<Contract> select_list = new ArrayList<>();
                for (int i = list.size() - 1; i >= 0; i--) {
                    if (list.get(i).isSelect()) {
                        select_list.add(list.get(i));
                        list.remove(i);
                    }
                }
                if (select_list.size() > 0) {
                    ContractHelpUtils.sendBraodcast(this, "com.lenovo.securityperson.change");
                    this.f5130f = false;
                    this.f5129e = new whiteContractAdapter(this, list, false);
                    this.f5126b.setAdapter((ListAdapter) this.f5129e);
                }
                break;
            case 4:
                this.f5130f = true;
                this.f5129e = new whiteContractAdapter(this, list, this.f5130f);
                this.f5126b.setAdapter((ListAdapter) this.f5129e);
                break;
            case 5:
                for (Contract con : list) {
                    con.setSelect(true);
                }
                this.f5126b.invalidateViews();
                break;
            case 6:
                for (Contract con2 : list) {
                    con2.setSelect(false);
                }
                this.f5126b.invalidateViews();
                break;
        }
        return super.onOptionsItemSelected(item);
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode != 4 || !this.f5130f) {
            return false;
        }
        for (Contract con : list) {
            con.setSelect(false);
        }
        this.f5130f = false;
        this.f5129e = new whiteContractAdapter(this, list, this.f5130f);
        this.f5126b.setAdapter((ListAdapter) this.f5129e);
        return true;
    }
}
