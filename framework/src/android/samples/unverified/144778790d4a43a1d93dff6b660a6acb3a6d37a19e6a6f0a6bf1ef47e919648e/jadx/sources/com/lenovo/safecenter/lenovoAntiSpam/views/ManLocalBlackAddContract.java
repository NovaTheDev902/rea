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
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class ManLocalBlackAddContract extends BaseTitleActivity {

    /* JADX INFO: renamed from: b */
    ContractHelpUtils f4170b;

    /* JADX INFO: renamed from: c */
    private ListView f4171c;

    /* JADX INFO: renamed from: d */
    private Button f4172d;

    /* JADX INFO: renamed from: e */
    private Button f4173e;

    /* JADX INFO: renamed from: f */
    private Button f4174f;

    /* JADX INFO: renamed from: g */
    private View f4175g;

    /* JADX INFO: renamed from: h */
    private int f4176h;

    /* JADX INFO: renamed from: i */
    private BaseAdapter f4177i;

    /* JADX INFO: renamed from: j */
    private List<Contract> f4178j;

    /* JADX INFO: renamed from: k */
    private TextView f4179k;

    /* JADX INFO: renamed from: l */
    private ProgressDialog f4180l;

    /* JADX INFO: renamed from: n */
    private AppDatabase f4182n;

    /* JADX INFO: renamed from: a */
    Thread f4169a = null;

    /* JADX INFO: renamed from: m */
    private boolean f4181m = false;

    /* JADX INFO: renamed from: o */
    private Handler f4183o = new HandlerC0698a(this, 0);

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddContract$a */
    private class HandlerC0698a extends Handler {
        private HandlerC0698a() {
        }

        /* synthetic */ HandlerC0698a(ManLocalBlackAddContract x0, byte b) {
            this();
        }

        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    boolean isCheckAll = ManLocalBlackAddContract.this.checkSelAll();
                    boolean cancelAll = ManLocalBlackAddContract.this.checkCancelAll();
                    if (isCheckAll) {
                        ManLocalBlackAddContract.this.f4172d.setEnabled(false);
                        ManLocalBlackAddContract.this.f4173e.setEnabled(true);
                        ManLocalBlackAddContract.this.changeBtn(true, C0415R.drawable.antispamadd);
                    } else if (cancelAll) {
                        ManLocalBlackAddContract.this.f4172d.setEnabled(true);
                        ManLocalBlackAddContract.this.f4173e.setEnabled(false);
                        ManLocalBlackAddContract.this.changeBtn(true, C0415R.drawable.antispamadd);
                    } else {
                        ManLocalBlackAddContract.this.f4172d.setEnabled(true);
                        ManLocalBlackAddContract.this.f4173e.setEnabled(true);
                        ManLocalBlackAddContract.this.changeBtn(true, C0415R.drawable.antispamadd);
                    }
                    break;
                case 2:
                    ManLocalBlackAddContract.this.f4181m = false;
                    if (ManLocalBlackAddContract.this.f4180l != null) {
                        try {
                            ManLocalBlackAddContract.this.f4180l.dismiss();
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                    Toast.makeText(ManLocalBlackAddContract.this, C0415R.string.antispamlocalblack_successNotice, 0).show();
                    if (ManLocalBlackAddContract.this.f4176h == 1) {
                        ContractHelpUtils.sendBraodcast(ManLocalBlackAddContract.this, "com.lenovo.antispam.blackperson.change");
                    }
                    ManLocalBlackAddContract.this.finish();
                    break;
                case 3:
                    ManLocalBlackAddContract.this.f4181m = false;
                    if (ManLocalBlackAddContract.this.f4180l != null) {
                        try {
                            ManLocalBlackAddContract.this.f4180l.dismiss();
                        } catch (Exception e2) {
                            e2.printStackTrace();
                        }
                    }
                    if (ManLocalBlackAddContract.this.f4178j != null) {
                        ManLocalBlackAddContract.this.f4175g.setVisibility(0);
                        ManLocalBlackAddContract.this.f4179k.setVisibility(8);
                        ManLocalBlackAddContract.this.f4177i = ManLocalBlackAddContract.this.new CallAdapter(ManLocalBlackAddContract.this, ManLocalBlackAddContract.this.f4178j);
                        ManLocalBlackAddContract.this.f4171c.setAdapter((ListAdapter) ManLocalBlackAddContract.this.f4177i);
                    } else {
                        ManLocalBlackAddContract.this.f4175g.setVisibility(8);
                        ManLocalBlackAddContract.this.f4179k.setVisibility(0);
                    }
                    ManLocalBlackAddContract.this.f4172d.setEnabled(true);
                    ManLocalBlackAddContract.this.f4173e.setEnabled(false);
                    ManLocalBlackAddContract.this.changeBtn(true, C0415R.drawable.antispamadd);
                    break;
                case 4:
                    ManLocalBlackAddContract.this.finish();
                    break;
            }
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        this.f4176h = getIntent().getExtras().getInt("type");
        setContentView(C0415R.layout.antispamlocalblack_add_view);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.antispamaddcall, (Integer) null);
        this.f4182n = new AppDatabase(this);
        this.f4171c = (ListView) findViewById(C0415R.id.listadd_white);
        this.f4174f = (Button) findViewById(C0415R.id.antispamadd_AppraiseLinearLayout);
        this.f4175g = findViewById(C0415R.id.antispamtableadd_header);
        this.f4172d = (Button) this.f4175g.findViewById(C0415R.id.antispamall_select);
        this.f4173e = (Button) this.f4175g.findViewById(C0415R.id.antispamcancel_select);
        this.f4179k = (TextView) findViewById(C0415R.id.antispamaddempty);
        this.f4170b = new ContractHelpUtils();
        onBtnClick();
        initView();
    }

    public void initView() {
        this.f4175g.setVisibility(8);
        this.f4179k.setVisibility(8);
        this.f4180l = new ProgressDialog(this);
        this.f4180l.setProgressStyle(0);
        this.f4180l.setMessage(getResources().getString(C0415R.string.antispamupload_desc));
        this.f4180l.show();
        this.f4169a = new Thread() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddContract.1
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    ManLocalBlackAddContract.this.f4181m = true;
                    long timeall1 = System.currentTimeMillis();
                    ManLocalBlackAddContract.this.f4178j = ManLocalBlackAddContract.this.f4170b.GetMyContacts(ManLocalBlackAddContract.this);
                    long timemc = System.currentTimeMillis();
                    long tinmmcend = timemc - timeall1;
                    Log.i("timespare", "GetMyContacts====" + tinmmcend);
                    long timeall2 = System.currentTimeMillis();
                    long timemc2 = System.currentTimeMillis();
                    long tinmmcend2 = timemc2 - timeall2;
                    Log.i("timespare", "noContractRepeatList====" + tinmmcend2);
                    long timeall3 = System.currentTimeMillis();
                    ManLocalBlackAddContract.this.f4178j = ManLocalBlackAddContract.this.f4170b.getConNotInBlackList(ManLocalBlackAddContract.this.f4178j, ManLocalBlackAddContract.this, ManLocalBlackAddContract.this.f4176h);
                    long timeall4 = System.currentTimeMillis();
                    long tinm13 = timeall4 - timeall3;
                    Log.i("timespare", "getConNotInBlackList====" + tinm13 + "");
                    ManLocalBlackAddContract.this.f4183o.sendEmptyMessage(3);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        };
        this.f4169a.start();
        Log.d("thread", "loadDataThread: " + this.f4169a.isAlive());
    }

    public void changeBtn(boolean bool, int resourceId) {
        this.f4174f.setEnabled(bool);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        Log.i("onkey", "onKeyDown");
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

    public boolean checkSelAll() {
        for (int i = 0; i < this.f4178j.size(); i++) {
            if (!this.f4178j.get(i).isSelect()) {
                return false;
            }
        }
        return true;
    }

    public boolean checkCancelAll() {
        for (int i = 0; i < this.f4178j.size(); i++) {
            if (this.f4178j.get(i).isSelect()) {
                return false;
            }
        }
        return true;
    }

    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddContract$3] */
    public void initApps(final List<Contract> selList) {
        this.f4180l = new ProgressDialog(this);
        this.f4180l.setProgressStyle(0);
        this.f4180l.setMessage(getResources().getString(C0415R.string.antispamupload_state));
        this.f4180l.show();
        new Thread() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddContract.3
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    ManLocalBlackAddContract.this.f4181m = true;
                    long timemc = System.currentTimeMillis();
                    List<Contract> list_help = ManLocalBlackAddContract.this.f4170b.noContractRepeatList(selList);
                    ManLocalBlackAddContract.this.f4182n.insertLocalBlack(list_help, ManLocalBlackAddContract.this.f4176h);
                    long timeall2 = System.currentTimeMillis();
                    long tinm13 = timeall2 - timemc;
                    Log.i("timespare", "getConNotInBlackList====" + tinm13);
                    ManLocalBlackAddContract.this.f4183o.sendEmptyMessage(2);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    public void onBtnClick() {
        this.f4171c.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddContract.4
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Contract con = (Contract) ManLocalBlackAddContract.this.f4178j.get(position);
                boolean flag = con.isSelect();
                if (flag) {
                    con.setSelect(false);
                } else {
                    con.setSelect(true);
                }
                ManLocalBlackAddContract.this.f4171c.invalidateViews();
                ManLocalBlackAddContract.this.f4183o.sendEmptyMessage(1);
            }
        });
        this.f4172d.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddContract.5
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                int size = ManLocalBlackAddContract.this.f4178j.size();
                for (int i = 0; i < size; i++) {
                    Contract conCall = (Contract) ManLocalBlackAddContract.this.f4178j.get(i);
                    conCall.setSelect(true);
                }
                ManLocalBlackAddContract.this.f4177i.notifyDataSetChanged();
                ManLocalBlackAddContract.this.f4171c.invalidateViews();
                ManLocalBlackAddContract.this.f4183o.sendEmptyMessage(1);
            }
        });
        this.f4173e.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddContract.6
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                int size = ManLocalBlackAddContract.this.f4178j.size();
                for (int i = 0; i < size; i++) {
                    Contract conCall = (Contract) ManLocalBlackAddContract.this.f4178j.get(i);
                    conCall.setSelect(false);
                }
                ManLocalBlackAddContract.this.f4177i.notifyDataSetChanged();
                ManLocalBlackAddContract.this.f4171c.invalidateViews();
                ManLocalBlackAddContract.this.f4183o.sendEmptyMessage(1);
            }
        });
        this.f4174f.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddContract.7
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (!ManLocalBlackAddContract.this.f4181m) {
                    if (ManLocalBlackAddContract.this.f4178j == null) {
                        Toast.makeText(ManLocalBlackAddContract.this, C0415R.string.antispamlocalblack_hasNoData, 0).show();
                        return;
                    }
                    if (!ManLocalBlackAddContract.this.checkCancelAll()) {
                        int size = ManLocalBlackAddContract.this.f4178j.size();
                        List<Contract> selList = new ArrayList<>();
                        for (int i = 0; i < size; i++) {
                            Contract con = (Contract) ManLocalBlackAddContract.this.f4171c.getItemAtPosition(i);
                            if (con.isSelect()) {
                                selList.add(con);
                            }
                        }
                        int count = ManLocalBlackAddContract.this.f4182n.getBlackListcount(ManLocalBlackAddContract.this.f4176h);
                        if (selList.size() >= 500 - count) {
                            Toast.makeText(ManLocalBlackAddContract.this, C0415R.string.antispamdata_limit1, 0).show();
                            return;
                        } else if (ManLocalBlackAddContract.this.f4170b.hasWhite(selList, ManLocalBlackAddContract.this)) {
                            ManLocalBlackAddContract.this.showDialog(selList);
                            return;
                        } else {
                            ManLocalBlackAddContract.this.initApps(selList);
                            return;
                        }
                    }
                    Toast.makeText(ManLocalBlackAddContract.this, C0415R.string.antispamlocalblack_nullNotice, 0).show();
                    return;
                }
                Toast.makeText(ManLocalBlackAddContract.this, C0415R.string.antispamupload_state, 0).show();
            }
        });
    }

    public void showDialog(final List<Contract> selectlist) {
        new CustomDialog.Builder(this).setTitle(C0415R.string.antispamnotice).setMessage(C0415R.string.antispamnoticecontent).setPositiveButton(C0415R.string.antispamyes, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddContract.9
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                ManLocalBlackAddContract.this.initApp_deleteWhite(selectlist);
            }
        }).setNegativeButton(C0415R.string.antispamno, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddContract.8
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                ManLocalBlackAddContract.this.initApp_expectWhite(selectlist);
            }
        }).create().show();
    }

    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddContract$10] */
    public void initApp_deleteWhite(final List<Contract> selList) {
        this.f4180l = new ProgressDialog(this);
        this.f4180l.setProgressStyle(0);
        this.f4180l.setMessage(getResources().getString(C0415R.string.antispamupload_state));
        this.f4180l.show();
        new Thread() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddContract.10
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    ManLocalBlackAddContract.this.f4181m = true;
                    List<Contract> list_help = ManLocalBlackAddContract.this.f4170b.noContractRepeatList(selList);
                    List<Contract> list_w = ManLocalBlackAddContract.this.f4170b.getWhiteFromadd(list_help, ManLocalBlackAddContract.this);
                    ManLocalBlackAddContract.this.f4170b.deleteWhite(ManLocalBlackAddContract.this, list_w);
                    ManLocalBlackAddContract.this.f4182n.insertLocalBlack(list_help, ManLocalBlackAddContract.this.f4176h);
                    ManLocalBlackAddContract.this.f4183o.sendEmptyMessage(2);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddContract$2] */
    public void initApp_expectWhite(final List<Contract> selList) {
        this.f4180l = new ProgressDialog(this);
        this.f4180l.setProgressStyle(0);
        this.f4180l.setMessage(getResources().getString(C0415R.string.antispamupload_state));
        this.f4180l.show();
        new Thread() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddContract.2
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    ManLocalBlackAddContract.this.f4181m = true;
                    List<Contract> list_help = ManLocalBlackAddContract.this.f4170b.noContractRepeatList(selList);
                    List<Contract> list_w = ManLocalBlackAddContract.this.f4170b.getWhiteFromadd(list_help, ManLocalBlackAddContract.this);
                    List<Contract> list_help2 = ManLocalBlackAddContract.this.f4170b.getAddlist(list_help, list_w);
                    ManLocalBlackAddContract.this.f4182n.insertLocalBlack(list_help2, ManLocalBlackAddContract.this.f4176h);
                    if (list_help2.size() == 0) {
                        ManLocalBlackAddContract.this.f4183o.sendEmptyMessage(4);
                    } else {
                        ManLocalBlackAddContract.this.f4183o.sendEmptyMessage(2);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    public class CallAdapter extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private Context f4200b;

        /* JADX INFO: renamed from: c */
        private List<Contract> f4201c;

        public CallAdapter(Context context, List<Contract> list) {
            this.f4200b = context;
            this.f4201c = list;
        }

        @Override // android.widget.Adapter
        public int getCount() {
            return this.f4201c.size();
        }

        @Override // android.widget.Adapter
        public Object getItem(int position) {
            return this.f4201c.get(position);
        }

        @Override // android.widget.Adapter
        public long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            C0697a holder;
            if (convertView == null) {
                convertView = LayoutInflater.from(this.f4200b).inflate(C0415R.layout.antispamcallcontract, (ViewGroup) null);
                holder = new C0697a(this, (byte) 0);
                holder.f4202a = (TextView) convertView.findViewById(C0415R.id.antispamcallname);
                holder.f4203b = (TextView) convertView.findViewById(C0415R.id.antispamcallnumber);
                holder.f4204c = (TextView) convertView.findViewById(C0415R.id.antispamcalldate);
                holder.f4205d = (TextView) convertView.findViewById(C0415R.id.antispamcalltype);
                holder.f4206e = (ImageView) convertView.findViewById(C0415R.id.antispamcall_check);
                convertView.setTag(holder);
            } else {
                holder = (C0697a) convertView.getTag();
            }
            Contract con = this.f4201c.get(position);
            if (con.getName() == null || con.getName().equals("")) {
                holder.f4202a.setText(C0415R.string.antispamlocalblack_noName);
            } else {
                holder.f4202a.setText(con.getName());
            }
            ImageView tButton = holder.f4206e;
            if (con.isSelect()) {
                tButton.setBackgroundResource(C0415R.drawable.ic_checkbox_select);
            } else {
                tButton.setBackgroundResource(C0415R.drawable.ic_checkbox);
            }
            holder.f4203b.setVisibility(8);
            holder.f4205d.setVisibility(8);
            holder.f4204c.setText(con.getPhoneNumber());
            return convertView;
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddContract$CallAdapter$a */
        private class C0697a {

            /* JADX INFO: renamed from: a */
            TextView f4202a;

            /* JADX INFO: renamed from: b */
            TextView f4203b;

            /* JADX INFO: renamed from: c */
            TextView f4204c;

            /* JADX INFO: renamed from: d */
            TextView f4205d;

            /* JADX INFO: renamed from: e */
            ImageView f4206e;

            private C0697a() {
            }

            /* synthetic */ C0697a(CallAdapter x0, byte b) {
                this();
            }
        }
    }
}
