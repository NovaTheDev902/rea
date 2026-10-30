package com.lenovo.safecenter.lenovoAntiSpam.views;

import android.app.ProgressDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase;
import com.lenovo.safecenter.lenovoAntiSpam.domain.Contract;
import com.lenovo.safecenter.lenovoAntiSpam.domain.ContractHelpUtils;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.safemode.SofeModeMain;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class ManAddWhiteContract extends BaseTitleActivity {

    /* JADX INFO: renamed from: a */
    AppDatabase f4025a;

    /* JADX INFO: renamed from: b */
    private ListView f4026b;

    /* JADX INFO: renamed from: c */
    private Button f4027c;

    /* JADX INFO: renamed from: d */
    private Button f4028d;

    /* JADX INFO: renamed from: e */
    private Button f4029e;

    /* JADX INFO: renamed from: f */
    private View f4030f;

    /* JADX INFO: renamed from: g */
    private String f4031g;

    /* JADX INFO: renamed from: h */
    private BaseAdapter f4032h;

    /* JADX INFO: renamed from: i */
    private ContractHelpUtils f4033i;

    /* JADX INFO: renamed from: j */
    private List<Contract> f4034j;

    /* JADX INFO: renamed from: k */
    private TextView f4035k;

    /* JADX INFO: renamed from: l */
    private ProgressDialog f4036l;

    /* JADX INFO: renamed from: m */
    private int f4037m;

    /* JADX INFO: renamed from: n */
    private boolean f4038n = false;

    /* JADX INFO: renamed from: o */
    private Handler f4039o = new HandlerC0663a(this, 0);

    /* JADX INFO: renamed from: k */
    static /* synthetic */ int m1691k(ManAddWhiteContract x0) {
        int i = x0.f4037m;
        x0.f4037m = i - 1;
        return i;
    }

    /* JADX INFO: renamed from: l */
    static /* synthetic */ int m1692l(ManAddWhiteContract x0) {
        int i = x0.f4037m;
        x0.f4037m = i + 1;
        return i;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.views.ManAddWhiteContract$a */
    private class HandlerC0663a extends Handler {
        private HandlerC0663a() {
        }

        /* synthetic */ HandlerC0663a(ManAddWhiteContract x0, byte b) {
            this();
        }

        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    boolean isCheckAll = ManAddWhiteContract.this.checkSelAll();
                    boolean cancelAll = ManAddWhiteContract.this.checkCancelAll();
                    if (isCheckAll) {
                        ManAddWhiteContract.this.f4027c.setEnabled(false);
                        ManAddWhiteContract.this.f4028d.setEnabled(true);
                        ManAddWhiteContract.this.changeBtn(true, C0415R.drawable.antispamadd);
                    } else if (cancelAll) {
                        ManAddWhiteContract.this.f4027c.setEnabled(true);
                        ManAddWhiteContract.this.f4028d.setEnabled(false);
                        ManAddWhiteContract.this.changeBtn(true, C0415R.drawable.antispamadd);
                    } else {
                        ManAddWhiteContract.this.f4027c.setEnabled(true);
                        ManAddWhiteContract.this.f4028d.setEnabled(true);
                        ManAddWhiteContract.this.changeBtn(true, C0415R.drawable.antispamadd);
                    }
                    break;
                case 2:
                    ManAddWhiteContract.this.f4038n = false;
                    if (ManAddWhiteContract.this.f4036l != null) {
                        try {
                            ManAddWhiteContract.this.f4036l.dismiss();
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                    Toast.makeText(ManAddWhiteContract.this, C0415R.string.antispamlocalblack_successNotice, 0).show();
                    ContractHelpUtils.sendBraodcast(ManAddWhiteContract.this, "com.lenovo.antispam.whiteperson.change");
                    ManAddWhiteContract.this.finish();
                    break;
                case 3:
                    ManAddWhiteContract.this.f4038n = false;
                    if (ManAddWhiteContract.this.f4036l != null) {
                        try {
                            ManAddWhiteContract.this.f4036l.dismiss();
                        } catch (Exception e2) {
                            e2.printStackTrace();
                        }
                    }
                    if (ManAddWhiteContract.this.f4034j != null) {
                        ManAddWhiteContract.this.f4030f.setVisibility(0);
                        ManAddWhiteContract.this.f4035k.setVisibility(8);
                        if (!ManAddWhiteContract.this.f4031g.equals("phone")) {
                            if (!ManAddWhiteContract.this.f4031g.equals(SofeModeMain.TS_CALL)) {
                                if (ManAddWhiteContract.this.f4031g.equals(SofeModeMain.TS_SMS)) {
                                    ManAddWhiteContract.this.f4032h = ManAddWhiteContract.this.new SmsAdapter(ManAddWhiteContract.this, ManAddWhiteContract.this.f4034j);
                                }
                            } else {
                                ManAddWhiteContract.this.f4032h = ManAddWhiteContract.this.new CallAdapter(ManAddWhiteContract.this, ManAddWhiteContract.this.f4034j);
                            }
                        } else {
                            ManAddWhiteContract.this.f4032h = ManAddWhiteContract.this.new PhoneAdapter(ManAddWhiteContract.this, ManAddWhiteContract.this.f4034j);
                        }
                        ManAddWhiteContract.this.f4026b.setAdapter((ListAdapter) ManAddWhiteContract.this.f4032h);
                    } else {
                        ManAddWhiteContract.this.f4030f.setVisibility(8);
                        ManAddWhiteContract.this.f4035k.setVisibility(0);
                        if (ManAddWhiteContract.this.f4031g.equals("phone")) {
                            ManAddWhiteContract.this.f4035k.setText(C0415R.string.localblack_hasNoData1);
                        }
                    }
                    ManAddWhiteContract.this.f4027c.setEnabled(true);
                    ManAddWhiteContract.this.f4028d.setEnabled(false);
                    ManAddWhiteContract.this.changeBtn(true, C0415R.drawable.antispamadd);
                    break;
                case 4:
                    ManAddWhiteContract.this.f4038n = false;
                    if (ManAddWhiteContract.this.f4036l != null) {
                        try {
                            ManAddWhiteContract.this.f4036l.dismiss();
                        } catch (Exception e3) {
                            e3.printStackTrace();
                        }
                    }
                    ManAddWhiteContract.this.finish();
                    break;
            }
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        this.f4031g = getIntent().getExtras().getString("from");
        this.f4033i = new ContractHelpUtils();
        setContentView(C0415R.layout.antispamlocalblack_add_view);
        this.f4025a = new AppDatabase(this);
        this.f4026b = (ListView) findViewById(C0415R.id.listadd_white);
        this.f4029e = (Button) findViewById(C0415R.id.antispamadd_AppraiseLinearLayout);
        this.f4030f = findViewById(C0415R.id.antispamtableadd_header);
        this.f4027c = (Button) this.f4030f.findViewById(C0415R.id.antispamall_select);
        this.f4028d = (Button) this.f4030f.findViewById(C0415R.id.antispamcancel_select);
        this.f4035k = (TextView) findViewById(C0415R.id.antispamaddempty);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.antispamaddfromphone, (Integer) null);
        this.f4030f.setVisibility(8);
        this.f4035k.setVisibility(8);
        onBtn_Click();
        initView();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        }
    }

    /* JADX WARN: Type inference failed for: r0v5, types: [com.lenovo.safecenter.lenovoAntiSpam.views.ManAddWhiteContract$1] */
    public void initView() {
        this.f4036l = new ProgressDialog(this);
        this.f4036l.setProgressStyle(0);
        this.f4036l.setMessage(getResources().getString(C0415R.string.antispamupload_desc));
        this.f4036l.setCanceledOnTouchOutside(false);
        this.f4036l.show();
        new Thread() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManAddWhiteContract.1
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    ManAddWhiteContract.this.f4038n = true;
                    ContractHelpUtils utils = new ContractHelpUtils();
                    if (!ManAddWhiteContract.this.f4031g.equals("phone")) {
                        if (ManAddWhiteContract.this.f4031g.equals(SofeModeMain.TS_CALL)) {
                            ManAddWhiteContract.this.f4034j = utils.getcallContractList(ManAddWhiteContract.this);
                        } else {
                            ManAddWhiteContract.this.f4034j = utils.getSmsContractList(ManAddWhiteContract.this);
                        }
                    } else {
                        ManAddWhiteContract.this.f4034j = utils.GetMyContacts(ManAddWhiteContract.this);
                    }
                    ManAddWhiteContract.this.f4034j = utils.getConNotInWhiteList(ManAddWhiteContract.this.f4034j, ManAddWhiteContract.this);
                    ManAddWhiteContract.this.f4039o.sendEmptyMessage(3);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    public void changeBtn(boolean bool, int resourceId) {
        this.f4029e.setEnabled(bool);
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

    public boolean checkSelAll() {
        for (int i = 0; i < this.f4034j.size(); i++) {
            if (!this.f4034j.get(i).isSelect()) {
                return false;
            }
        }
        return true;
    }

    public boolean checkCancelAll() {
        for (int i = 0; i < this.f4034j.size(); i++) {
            if (this.f4034j.get(i).isSelect()) {
                return false;
            }
        }
        return true;
    }

    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.safecenter.lenovoAntiSpam.views.ManAddWhiteContract$3] */
    public void initApps(final List<Contract> selList) {
        this.f4036l = new ProgressDialog(this);
        this.f4036l.setProgressStyle(0);
        this.f4036l.setMessage(getResources().getString(C0415R.string.antispamupload_state));
        this.f4036l.show();
        new Thread() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManAddWhiteContract.3
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    ManAddWhiteContract.this.f4038n = true;
                    List<Contract> list_help = new ContractHelpUtils().noContractRepeatList(selList);
                    ManAddWhiteContract.this.f4025a.insertWhite(list_help);
                    ManAddWhiteContract.this.f4039o.sendEmptyMessage(2);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    public void setAddBtnText() {
        if (this.f4037m > 0) {
            this.f4029e.setText(String.format(getString(C0415R.string.add_count), Integer.valueOf(this.f4037m)));
        } else {
            this.f4029e.setText(C0415R.string.antispamlocalblack_add);
        }
    }

    public void onBtn_Click() {
        this.f4026b.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManAddWhiteContract.4
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Contract con = (Contract) ManAddWhiteContract.this.f4034j.get(position);
                boolean flag = con.isSelect();
                if (flag) {
                    con.setSelect(false);
                    ManAddWhiteContract.m1691k(ManAddWhiteContract.this);
                } else {
                    con.setSelect(true);
                    ManAddWhiteContract.m1692l(ManAddWhiteContract.this);
                }
                ManAddWhiteContract.this.setAddBtnText();
                ManAddWhiteContract.this.f4026b.invalidateViews();
                ManAddWhiteContract.this.f4039o.sendEmptyMessage(1);
            }
        });
        this.f4027c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManAddWhiteContract.5
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                ManAddWhiteContract.this.f4037m = 0;
                int size = ManAddWhiteContract.this.f4034j.size();
                ManAddWhiteContract.this.f4037m = size;
                for (int i = 0; i < size; i++) {
                    Contract conCall = (Contract) ManAddWhiteContract.this.f4034j.get(i);
                    conCall.setSelect(true);
                }
                ManAddWhiteContract.this.setAddBtnText();
                ManAddWhiteContract.this.f4032h.notifyDataSetChanged();
                ManAddWhiteContract.this.f4026b.invalidateViews();
                ManAddWhiteContract.this.f4039o.sendEmptyMessage(1);
            }
        });
        this.f4028d.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManAddWhiteContract.6
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                ManAddWhiteContract.this.f4037m = 0;
                int size = ManAddWhiteContract.this.f4034j.size();
                for (int i = 0; i < size; i++) {
                    Contract conCall = (Contract) ManAddWhiteContract.this.f4034j.get(i);
                    conCall.setSelect(false);
                }
                ManAddWhiteContract.this.setAddBtnText();
                ManAddWhiteContract.this.f4032h.notifyDataSetChanged();
                ManAddWhiteContract.this.f4026b.invalidateViews();
                ManAddWhiteContract.this.f4039o.sendEmptyMessage(1);
            }
        });
        this.f4029e.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManAddWhiteContract.7
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (!ManAddWhiteContract.this.f4038n) {
                    if (ManAddWhiteContract.this.f4034j == null) {
                        Toast.makeText(ManAddWhiteContract.this, C0415R.string.antispamlocalblack_hasNoData, 0).show();
                        return;
                    }
                    if (!ManAddWhiteContract.this.checkCancelAll()) {
                        int size = ManAddWhiteContract.this.f4034j.size();
                        List<Contract> selList = new ArrayList<>();
                        for (int i = 0; i < size; i++) {
                            Contract con = (Contract) ManAddWhiteContract.this.f4026b.getItemAtPosition(i);
                            if (con.isSelect()) {
                                selList.add(con);
                            }
                        }
                        Log.i("count", selList.size() + "===");
                        if (selList.size() <= 500 - ManAddWhiteContract.this.f4025a.getWhitePersonCount()) {
                            if (ManAddWhiteContract.this.f4033i.hasblack(selList, ManAddWhiteContract.this)) {
                                ManAddWhiteContract.this.showDialog(selList);
                                return;
                            } else {
                                ManAddWhiteContract.this.initApps(selList);
                                return;
                            }
                        }
                        Toast.makeText(ManAddWhiteContract.this, C0415R.string.antispamdata_limit1, 0).show();
                        return;
                    }
                    Toast.makeText(ManAddWhiteContract.this, C0415R.string.antispamlocalblack_nullNotice, 0).show();
                    return;
                }
                Toast.makeText(ManAddWhiteContract.this, C0415R.string.antispamupload_state, 0).show();
            }
        });
    }

    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.safecenter.lenovoAntiSpam.views.ManAddWhiteContract$8] */
    public void initApp_expectWhite(final List<Contract> selList) {
        this.f4036l = new ProgressDialog(this);
        this.f4036l.setProgressStyle(0);
        this.f4036l.setMessage(getResources().getString(C0415R.string.antispamupload_state));
        this.f4036l.show();
        new Thread() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManAddWhiteContract.8
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    ManAddWhiteContract.this.f4038n = true;
                    List<Contract> list_help = ManAddWhiteContract.this.f4033i.noContractRepeatList(selList);
                    List<Contract> list_w = ManAddWhiteContract.this.f4033i.getBlackFromadd(list_help, ManAddWhiteContract.this);
                    List<Contract> list_help2 = ManAddWhiteContract.this.f4033i.getAddlist(list_help, list_w);
                    ManAddWhiteContract.this.f4025a.insertWhite(list_help2);
                    if (list_help2.size() == 0) {
                        ManAddWhiteContract.this.f4039o.sendEmptyMessage(4);
                    } else {
                        ManAddWhiteContract.this.f4039o.sendEmptyMessage(2);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.safecenter.lenovoAntiSpam.views.ManAddWhiteContract$9] */
    public void initApp_deleteWhite(final List<Contract> selList) {
        this.f4036l = new ProgressDialog(this);
        this.f4036l.setProgressStyle(0);
        this.f4036l.setMessage(getResources().getString(C0415R.string.antispamupload_state));
        this.f4036l.show();
        new Thread() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManAddWhiteContract.9
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    ManAddWhiteContract.this.f4038n = true;
                    List<Contract> list_help = ManAddWhiteContract.this.f4033i.noContractRepeatList(selList);
                    List<Contract> list_w = ManAddWhiteContract.this.f4033i.getBlackFromadd(list_help, ManAddWhiteContract.this);
                    ManAddWhiteContract.this.f4025a.deleteBlackbyrealnumber(list_w);
                    ManAddWhiteContract.this.f4025a.insertWhite(list_help);
                    ManAddWhiteContract.this.f4039o.sendEmptyMessage(2);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    public void showDialog(final List<Contract> selectlist) {
        new CustomDialog.Builder(this).setTitle(C0415R.string.antispamnotice).setMessage(C0415R.string.noticecontent).setPositiveButton(C0415R.string.antispamyes, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManAddWhiteContract.2
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                ManAddWhiteContract.this.initApp_deleteWhite(selectlist);
            }
        }).setNegativeButton(C0415R.string.antispamno, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManAddWhiteContract.10
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                if (selectlist.size() > 1) {
                    ManAddWhiteContract.this.initApp_expectWhite(selectlist);
                } else {
                    ManAddWhiteContract.this.finish();
                }
            }
        }).create().show();
    }

    public class PhoneAdapter extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private Context f4065b;

        /* JADX INFO: renamed from: c */
        private List<Contract> f4066c;

        public PhoneAdapter(Context context, List<Contract> list) {
            this.f4065b = context;
            this.f4066c = list;
        }

        @Override // android.widget.Adapter
        public int getCount() {
            return this.f4066c.size();
        }

        @Override // android.widget.Adapter
        public Object getItem(int position) {
            return this.f4066c.get(position);
        }

        @Override // android.widget.Adapter
        public long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            C0661a holder;
            if (convertView == null) {
                convertView = LayoutInflater.from(this.f4065b).inflate(C0415R.layout.antispamcallcontract, (ViewGroup) null);
                holder = new C0661a(this, (byte) 0);
                holder.f4067a = (TextView) convertView.findViewById(C0415R.id.antispamcallname);
                holder.f4068b = (TextView) convertView.findViewById(C0415R.id.antispamcallnumber);
                holder.f4069c = (TextView) convertView.findViewById(C0415R.id.antispamcalldate);
                holder.f4070d = (TextView) convertView.findViewById(C0415R.id.antispamcalltype);
                holder.f4071e = (ImageView) convertView.findViewById(C0415R.id.antispamcall_check);
                convertView.setTag(holder);
            } else {
                holder = (C0661a) convertView.getTag();
            }
            Contract con = this.f4066c.get(position);
            if (con.getName() == null || con.getName().equals("")) {
                holder.f4067a.setText(C0415R.string.antispamlocalblack_noName);
            } else {
                holder.f4067a.setText(con.getName());
            }
            ImageView tButton = holder.f4071e;
            if (con.isSelect()) {
                tButton.setBackgroundResource(C0415R.drawable.ic_checkbox_select);
            } else {
                tButton.setBackgroundResource(C0415R.drawable.ic_checkbox);
            }
            holder.f4068b.setVisibility(8);
            holder.f4070d.setVisibility(8);
            holder.f4069c.setText(con.getPhoneNumber());
            return convertView;
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.views.ManAddWhiteContract$PhoneAdapter$a */
        private class C0661a {

            /* JADX INFO: renamed from: a */
            TextView f4067a;

            /* JADX INFO: renamed from: b */
            TextView f4068b;

            /* JADX INFO: renamed from: c */
            TextView f4069c;

            /* JADX INFO: renamed from: d */
            TextView f4070d;

            /* JADX INFO: renamed from: e */
            ImageView f4071e;

            private C0661a() {
            }

            /* synthetic */ C0661a(PhoneAdapter x0, byte b) {
                this();
            }
        }
    }

    public class CallAdapter extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private Context f4056b;

        /* JADX INFO: renamed from: c */
        private List<Contract> f4057c;

        public CallAdapter(Context context, List<Contract> list) {
            this.f4056b = context;
            this.f4057c = list;
        }

        @Override // android.widget.Adapter
        public int getCount() {
            return this.f4057c.size();
        }

        @Override // android.widget.Adapter
        public Object getItem(int position) {
            return this.f4057c.get(position);
        }

        @Override // android.widget.Adapter
        public long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            C0660a holder;
            if (convertView == null) {
                convertView = LayoutInflater.from(this.f4056b).inflate(C0415R.layout.antispamcallcontract, (ViewGroup) null);
                holder = new C0660a(this, (byte) 0);
                holder.f4058a = (TextView) convertView.findViewById(C0415R.id.antispamcallname);
                holder.f4059b = (TextView) convertView.findViewById(C0415R.id.antispamcallnumber);
                holder.f4060c = (TextView) convertView.findViewById(C0415R.id.antispamcalldate);
                holder.f4061d = (TextView) convertView.findViewById(C0415R.id.antispamcalltype);
                holder.f4062e = (ImageView) convertView.findViewById(C0415R.id.antispamcall_check);
                convertView.setTag(holder);
            } else {
                holder = (C0660a) convertView.getTag();
            }
            Contract con = this.f4057c.get(position);
            if (con.getName() == null || con.getName().equals("")) {
                holder.f4058a.setText(C0415R.string.antispamlocalblack_noName);
            } else {
                holder.f4058a.setText(con.getName());
            }
            ImageView tButton = holder.f4062e;
            if (con.isSelect()) {
                tButton.setBackgroundResource(C0415R.drawable.ic_checkbox_select);
            } else {
                tButton.setBackgroundResource(C0415R.drawable.ic_checkbox);
            }
            holder.f4059b.setText(con.getPhoneNumber());
            holder.f4061d.setText(ContractHelpUtils.getType(ManAddWhiteContract.this, con.getCallType()));
            holder.f4060c.setText(ContractHelpUtils.getDate(con.getDate()));
            return convertView;
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.views.ManAddWhiteContract$CallAdapter$a */
        private class C0660a {

            /* JADX INFO: renamed from: a */
            TextView f4058a;

            /* JADX INFO: renamed from: b */
            TextView f4059b;

            /* JADX INFO: renamed from: c */
            TextView f4060c;

            /* JADX INFO: renamed from: d */
            TextView f4061d;

            /* JADX INFO: renamed from: e */
            ImageView f4062e;

            private C0660a() {
            }

            /* synthetic */ C0660a(CallAdapter x0, byte b) {
                this();
            }
        }
    }

    public class SmsAdapter extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private Context f4074b;

        /* JADX INFO: renamed from: c */
        private List<Contract> f4075c;

        public SmsAdapter(Context context, List<Contract> list) {
            this.f4074b = context;
            this.f4075c = list;
        }

        @Override // android.widget.Adapter
        public int getCount() {
            return this.f4075c.size();
        }

        @Override // android.widget.Adapter
        public Object getItem(int position) {
            return this.f4075c.get(position);
        }

        @Override // android.widget.Adapter
        public long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            C0662a holder;
            if (convertView == null) {
                convertView = LayoutInflater.from(this.f4074b).inflate(C0415R.layout.antispamsms, (ViewGroup) null);
                holder = new C0662a(this, (byte) 0);
                holder.f4076a = (TextView) convertView.findViewById(C0415R.id.antispamsmsname);
                holder.f4077b = (TextView) convertView.findViewById(C0415R.id.antispamsmsnumber);
                holder.f4078c = (TextView) convertView.findViewById(C0415R.id.antispamsmscontent);
                holder.f4079d = (ImageView) convertView.findViewById(C0415R.id.antispamsmscheck);
                convertView.setTag(holder);
            } else {
                holder = (C0662a) convertView.getTag();
            }
            Contract con = this.f4075c.get(position);
            if (con.getName() == null || con.getName().equals("")) {
                holder.f4076a.setText(C0415R.string.antispamlocalblack_noName);
            } else {
                holder.f4076a.setText(con.getName());
            }
            holder.f4077b.setText(con.getPhoneNumber());
            if (con.getSmsContent() != null && !con.getSmsContent().equals("")) {
                holder.f4078c.setText(con.getSmsContent());
            } else {
                holder.f4078c.setText(C0415R.string.antispamno_content);
            }
            if (con.isSelect()) {
                holder.f4079d.setBackgroundResource(C0415R.drawable.ic_checkbox_select);
            } else {
                holder.f4079d.setBackgroundResource(C0415R.drawable.ic_checkbox);
            }
            return convertView;
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.views.ManAddWhiteContract$SmsAdapter$a */
        private class C0662a {

            /* JADX INFO: renamed from: a */
            TextView f4076a;

            /* JADX INFO: renamed from: b */
            TextView f4077b;

            /* JADX INFO: renamed from: c */
            TextView f4078c;

            /* JADX INFO: renamed from: d */
            ImageView f4079d;

            private C0662a() {
            }

            /* synthetic */ C0662a(SmsAdapter x0, byte b) {
                this();
            }
        }
    }
}
