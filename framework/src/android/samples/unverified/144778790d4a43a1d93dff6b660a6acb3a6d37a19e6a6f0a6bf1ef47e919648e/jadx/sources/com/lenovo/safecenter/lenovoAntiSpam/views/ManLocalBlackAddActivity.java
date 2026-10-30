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
public class ManLocalBlackAddActivity extends BaseTitleActivity {

    /* JADX INFO: renamed from: a */
    AppDatabase f4121a;

    /* JADX INFO: renamed from: b */
    private ListView f4122b;

    /* JADX INFO: renamed from: c */
    private Button f4123c;

    /* JADX INFO: renamed from: d */
    private Button f4124d;

    /* JADX INFO: renamed from: e */
    private Button f4125e;

    /* JADX INFO: renamed from: f */
    private View f4126f;

    /* JADX INFO: renamed from: g */
    private int f4127g;

    /* JADX INFO: renamed from: h */
    private BaseAdapter f4128h;

    /* JADX INFO: renamed from: i */
    private List<Contract> f4129i;

    /* JADX INFO: renamed from: j */
    private TextView f4130j;

    /* JADX INFO: renamed from: m */
    private ProgressDialog f4133m;

    /* JADX INFO: renamed from: n */
    private ContractHelpUtils f4134n;

    /* JADX INFO: renamed from: k */
    private boolean f4131k = false;

    /* JADX INFO: renamed from: l */
    private int f4132l = 0;

    /* JADX INFO: renamed from: o */
    private Handler f4135o = new HandlerC0686a(this, 0);

    /* JADX INFO: renamed from: l */
    static /* synthetic */ int m1722l(ManLocalBlackAddActivity x0) {
        int i = x0.f4132l;
        x0.f4132l = i - 1;
        return i;
    }

    /* JADX INFO: renamed from: m */
    static /* synthetic */ int m1723m(ManLocalBlackAddActivity x0) {
        int i = x0.f4132l;
        x0.f4132l = i + 1;
        return i;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddActivity$a */
    private class HandlerC0686a extends Handler {
        private HandlerC0686a() {
        }

        /* synthetic */ HandlerC0686a(ManLocalBlackAddActivity x0, byte b) {
            this();
        }

        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    boolean isCheckAll = ManLocalBlackAddActivity.this.checkSelAll();
                    boolean cancelAll = ManLocalBlackAddActivity.this.checkCancelAll();
                    if (isCheckAll) {
                        ManLocalBlackAddActivity.this.f4123c.setEnabled(false);
                        ManLocalBlackAddActivity.this.f4124d.setEnabled(true);
                        ManLocalBlackAddActivity.this.changeBtn(true, C0415R.drawable.antispamadd);
                    } else if (cancelAll) {
                        ManLocalBlackAddActivity.this.f4123c.setEnabled(true);
                        ManLocalBlackAddActivity.this.f4124d.setEnabled(false);
                        ManLocalBlackAddActivity.this.changeBtn(true, C0415R.drawable.antispamadd);
                    } else {
                        ManLocalBlackAddActivity.this.f4123c.setEnabled(true);
                        ManLocalBlackAddActivity.this.f4124d.setEnabled(true);
                        ManLocalBlackAddActivity.this.changeBtn(true, C0415R.drawable.antispamadd);
                    }
                    break;
                case 2:
                    ManLocalBlackAddActivity.this.f4131k = false;
                    if (ManLocalBlackAddActivity.this.f4133m != null) {
                        try {
                            ManLocalBlackAddActivity.this.f4133m.dismiss();
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                    Toast.makeText(ManLocalBlackAddActivity.this, C0415R.string.antispamlocalblack_successNotice, 0).show();
                    ContractHelpUtils.sendBraodcast(ManLocalBlackAddActivity.this, "com.lenovo.antispam.blackperson.change");
                    ManLocalBlackAddActivity.this.finish();
                    break;
                case 3:
                    ManLocalBlackAddActivity.this.f4131k = false;
                    if (ManLocalBlackAddActivity.this.f4133m != null) {
                        try {
                            ManLocalBlackAddActivity.this.f4133m.dismiss();
                        } catch (Exception e2) {
                            e2.printStackTrace();
                        }
                    }
                    if (ManLocalBlackAddActivity.this.f4129i != null) {
                        ManLocalBlackAddActivity.this.f4130j.setVisibility(8);
                        ManLocalBlackAddActivity.this.f4126f.setVisibility(0);
                        if (ManLocalBlackAddActivity.this.f4127g != 1) {
                            if (ManLocalBlackAddActivity.this.f4127g == 0) {
                                ManLocalBlackAddActivity.this.f4128h = ManLocalBlackAddActivity.this.new SmsAdapter(ManLocalBlackAddActivity.this, ManLocalBlackAddActivity.this.f4129i);
                            } else {
                                ManLocalBlackAddActivity.this.f4128h = ManLocalBlackAddActivity.this.new CallAdapter(ManLocalBlackAddActivity.this, ManLocalBlackAddActivity.this.f4129i);
                            }
                        } else {
                            ManLocalBlackAddActivity.this.f4128h = ManLocalBlackAddActivity.this.new CallAdapter(ManLocalBlackAddActivity.this, ManLocalBlackAddActivity.this.f4129i);
                        }
                        ManLocalBlackAddActivity.this.f4122b.setAdapter((ListAdapter) ManLocalBlackAddActivity.this.f4128h);
                    } else {
                        ManLocalBlackAddActivity.this.f4126f.setVisibility(8);
                        ManLocalBlackAddActivity.this.f4130j.setVisibility(0);
                        if (ManLocalBlackAddActivity.this.f4127g == 4) {
                            ManLocalBlackAddActivity.this.f4130j.setText(C0415R.string.localblack_hasNoData1);
                        }
                    }
                    ManLocalBlackAddActivity.this.f4123c.setEnabled(true);
                    ManLocalBlackAddActivity.this.f4124d.setEnabled(false);
                    ManLocalBlackAddActivity.this.changeBtn(true, C0415R.drawable.antispamadd);
                    break;
                case 4:
                    ManLocalBlackAddActivity.this.f4131k = false;
                    if (ManLocalBlackAddActivity.this.f4133m != null) {
                        try {
                            ManLocalBlackAddActivity.this.f4133m.dismiss();
                        } catch (Exception e3) {
                            e3.printStackTrace();
                        }
                    }
                    ManLocalBlackAddActivity.this.finish();
                    break;
            }
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        this.f4127g = getIntent().getExtras().getInt("type");
        setContentView(C0415R.layout.antispamlocalblack_add_view);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.antispamaddcall, (Integer) null);
        this.f4121a = new AppDatabase(this);
        this.f4122b = (ListView) findViewById(C0415R.id.listadd_white);
        this.f4125e = (Button) findViewById(C0415R.id.antispamadd_AppraiseLinearLayout);
        this.f4126f = findViewById(C0415R.id.antispamtableadd_header);
        this.f4123c = (Button) this.f4126f.findViewById(C0415R.id.antispamall_select);
        this.f4124d = (Button) this.f4126f.findViewById(C0415R.id.antispamcancel_select);
        this.f4130j = (TextView) findViewById(C0415R.id.antispamaddempty);
        this.f4134n = new ContractHelpUtils();
        onBtnClick();
        initView();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        }
    }

    /* JADX WARN: Type inference failed for: r0v7, types: [com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddActivity$1] */
    public void initView() {
        this.f4130j.setVisibility(8);
        this.f4126f.setVisibility(8);
        this.f4133m = new ProgressDialog(this);
        this.f4133m.setProgressStyle(0);
        this.f4133m.setMessage(getResources().getString(C0415R.string.antispamupload_desc));
        this.f4133m.setCanceledOnTouchOutside(false);
        this.f4133m.show();
        new Thread() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddActivity.1
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    ManLocalBlackAddActivity.this.f4131k = true;
                    if (ManLocalBlackAddActivity.this.f4127g != 1) {
                        if (ManLocalBlackAddActivity.this.f4127g == 0) {
                            ManLocalBlackAddActivity.this.f4129i = ManLocalBlackAddActivity.this.f4134n.getSmsContractList(ManLocalBlackAddActivity.this);
                        } else {
                            ManLocalBlackAddActivity.this.f4129i = ManLocalBlackAddActivity.this.f4134n.GetMyContacts(ManLocalBlackAddActivity.this);
                        }
                    } else {
                        ManLocalBlackAddActivity.this.f4129i = ManLocalBlackAddActivity.this.f4134n.getcallContractList_calling(ManLocalBlackAddActivity.this);
                    }
                    long time1 = System.currentTimeMillis();
                    ManLocalBlackAddActivity.this.f4129i = ManLocalBlackAddActivity.this.f4134n.getConNotInBlackList(ManLocalBlackAddActivity.this.f4129i, ManLocalBlackAddActivity.this, ManLocalBlackAddActivity.this.f4127g);
                    long time2 = System.currentTimeMillis();
                    long timeexec = time2 - time1;
                    Log.i("exectime", "timeexec==" + timeexec);
                    ManLocalBlackAddActivity.this.f4135o.sendEmptyMessage(3);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    public void changeBtn(boolean bool, int resourceId) {
        this.f4125e.setEnabled(bool);
    }

    public void setAddBtnText() {
        if (this.f4132l > 0) {
            this.f4125e.setText(String.format(getString(C0415R.string.add_count), Integer.valueOf(this.f4132l)));
        } else {
            this.f4125e.setText(C0415R.string.antispamlocalblack_add);
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

    public boolean checkSelAll() {
        for (int i = 0; i < this.f4129i.size(); i++) {
            if (!this.f4129i.get(i).isSelect()) {
                return false;
            }
        }
        return true;
    }

    public boolean checkCancelAll() {
        for (int i = 0; i < this.f4129i.size(); i++) {
            if (this.f4129i.get(i).isSelect()) {
                return false;
            }
        }
        return true;
    }

    public void onBtnClick() {
        this.f4122b.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddActivity.3
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Contract con = (Contract) ManLocalBlackAddActivity.this.f4129i.get(position);
                boolean flag = con.isSelect();
                if (flag) {
                    con.setSelect(false);
                    ManLocalBlackAddActivity.m1722l(ManLocalBlackAddActivity.this);
                } else {
                    con.setSelect(true);
                    ManLocalBlackAddActivity.m1723m(ManLocalBlackAddActivity.this);
                }
                ManLocalBlackAddActivity.this.setAddBtnText();
                ManLocalBlackAddActivity.this.f4122b.invalidateViews();
                ManLocalBlackAddActivity.this.f4135o.sendEmptyMessage(1);
            }
        });
        this.f4123c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddActivity.4
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                ManLocalBlackAddActivity.this.f4132l = 0;
                int size = ManLocalBlackAddActivity.this.f4129i.size();
                ManLocalBlackAddActivity.this.f4132l = ManLocalBlackAddActivity.this.f4129i.size();
                for (int i = 0; i < size; i++) {
                    Contract conCall = (Contract) ManLocalBlackAddActivity.this.f4129i.get(i);
                    conCall.setSelect(true);
                }
                ManLocalBlackAddActivity.this.setAddBtnText();
                ManLocalBlackAddActivity.this.f4128h.notifyDataSetChanged();
                ManLocalBlackAddActivity.this.f4122b.invalidateViews();
                ManLocalBlackAddActivity.this.f4135o.sendEmptyMessage(1);
            }
        });
        this.f4124d.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddActivity.5
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                ManLocalBlackAddActivity.this.f4132l = 0;
                int size = ManLocalBlackAddActivity.this.f4129i.size();
                for (int i = 0; i < size; i++) {
                    Contract conCall = (Contract) ManLocalBlackAddActivity.this.f4129i.get(i);
                    conCall.setSelect(false);
                }
                ManLocalBlackAddActivity.this.setAddBtnText();
                ManLocalBlackAddActivity.this.f4128h.notifyDataSetChanged();
                ManLocalBlackAddActivity.this.f4122b.invalidateViews();
                ManLocalBlackAddActivity.this.f4135o.sendEmptyMessage(1);
            }
        });
        this.f4125e.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddActivity.6
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (!ManLocalBlackAddActivity.this.f4131k) {
                    if (ManLocalBlackAddActivity.this.f4129i == null) {
                        Toast.makeText(ManLocalBlackAddActivity.this, C0415R.string.antispamlocalblack_hasNoData, 0).show();
                        return;
                    }
                    if (!ManLocalBlackAddActivity.this.checkCancelAll()) {
                        int size = ManLocalBlackAddActivity.this.f4129i.size();
                        List<Contract> selList = new ArrayList<>();
                        for (int i = 0; i < size; i++) {
                            Contract con = (Contract) ManLocalBlackAddActivity.this.f4122b.getItemAtPosition(i);
                            if (con.isSelect()) {
                                selList.add(con);
                            }
                        }
                        int count = ManLocalBlackAddActivity.this.f4121a.getBlackListcount(ManLocalBlackAddActivity.this.f4127g);
                        if (selList.size() <= 500 - count) {
                            if (ManLocalBlackAddActivity.this.f4134n.hasWhite(selList, ManLocalBlackAddActivity.this)) {
                                ManLocalBlackAddActivity.this.showDialog(selList);
                                return;
                            } else {
                                ManLocalBlackAddActivity.this.initApps(selList);
                                return;
                            }
                        }
                        Toast.makeText(ManLocalBlackAddActivity.this, C0415R.string.antispamdata_limit1, 0).show();
                        return;
                    }
                    Toast.makeText(ManLocalBlackAddActivity.this, C0415R.string.antispamlocalblack_nullNotice, 0).show();
                    return;
                }
                Toast.makeText(ManLocalBlackAddActivity.this, C0415R.string.antispamupload_state, 0).show();
            }
        });
    }

    public void showDialog(final List<Contract> selectlist) {
        new CustomDialog.Builder(this).setTitle(C0415R.string.antispamnotice).setMessage(C0415R.string.antispamnoticecontent).setPositiveButton(C0415R.string.antispamyes, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddActivity.8
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                ManLocalBlackAddActivity.this.initApp_deleteWhite(selectlist);
            }
        }).setNegativeButton(C0415R.string.antispamno, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddActivity.7
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                if (selectlist.size() > 1) {
                    ManLocalBlackAddActivity.this.initApp_expectWhite(selectlist);
                } else {
                    ManLocalBlackAddActivity.this.finish();
                }
            }
        }).create().show();
    }

    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddActivity$9] */
    public void initApps(final List<Contract> selList) {
        this.f4133m = new ProgressDialog(this);
        this.f4133m.setProgressStyle(0);
        this.f4133m.setMessage(getResources().getString(C0415R.string.antispamupload_state));
        this.f4133m.show();
        new Thread() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddActivity.9
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    ManLocalBlackAddActivity.this.f4131k = true;
                    List<Contract> list_help = ManLocalBlackAddActivity.this.f4134n.noContractRepeatList(selList);
                    ManLocalBlackAddActivity.this.f4121a.insertLocalBlack(list_help, 2);
                    ManLocalBlackAddActivity.this.f4135o.sendEmptyMessage(2);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddActivity$10] */
    public void initApp_deleteWhite(final List<Contract> selList) {
        this.f4133m = new ProgressDialog(this);
        this.f4133m.setProgressStyle(0);
        this.f4133m.setMessage(getResources().getString(C0415R.string.antispamupload_state));
        this.f4133m.show();
        new Thread() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddActivity.10
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    ManLocalBlackAddActivity.this.f4131k = true;
                    List<Contract> list_help = ManLocalBlackAddActivity.this.f4134n.noContractRepeatList(selList);
                    List<Contract> list_w = ManLocalBlackAddActivity.this.f4134n.getWhiteFromadd(list_help, ManLocalBlackAddActivity.this);
                    ManLocalBlackAddActivity.this.f4121a.deleteWhitebyrealnumber(list_w);
                    ManLocalBlackAddActivity.this.f4121a.insertLocalBlack(list_help, 2);
                    ManLocalBlackAddActivity.this.f4135o.sendEmptyMessage(2);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddActivity$2] */
    public void initApp_expectWhite(final List<Contract> selList) {
        this.f4133m = new ProgressDialog(this);
        this.f4133m.setProgressStyle(0);
        this.f4133m.setMessage(getResources().getString(C0415R.string.antispamupload_state));
        this.f4133m.show();
        new Thread() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddActivity.2
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    ManLocalBlackAddActivity.this.f4131k = true;
                    List<Contract> list_help = ManLocalBlackAddActivity.this.f4134n.noContractRepeatList(selList);
                    List<Contract> list_w = ManLocalBlackAddActivity.this.f4134n.getWhiteFromadd(list_help, ManLocalBlackAddActivity.this);
                    List<Contract> list_help2 = ManLocalBlackAddActivity.this.f4134n.getAddlist(list_help, list_w);
                    ManLocalBlackAddActivity.this.f4121a.insertLocalBlack(list_help2, 2);
                    if (list_help2.size() == 0) {
                        ManLocalBlackAddActivity.this.f4135o.sendEmptyMessage(4);
                    } else {
                        ManLocalBlackAddActivity.this.f4135o.sendEmptyMessage(2);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    public class CallAdapter extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private Context f4152b;

        /* JADX INFO: renamed from: c */
        private List<Contract> f4153c;

        public CallAdapter(Context context, List<Contract> list) {
            this.f4152b = context;
            this.f4153c = list;
        }

        @Override // android.widget.Adapter
        public int getCount() {
            return this.f4153c.size();
        }

        @Override // android.widget.Adapter
        public Object getItem(int position) {
            return this.f4153c.get(position);
        }

        @Override // android.widget.Adapter
        public long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            C0684a holder;
            if (convertView == null) {
                convertView = LayoutInflater.from(this.f4152b).inflate(C0415R.layout.antispamcallcontract, (ViewGroup) null);
                holder = new C0684a(this, (byte) 0);
                holder.f4154a = (TextView) convertView.findViewById(C0415R.id.antispamcallname);
                holder.f4155b = (TextView) convertView.findViewById(C0415R.id.antispamcallnumber);
                holder.f4156c = (TextView) convertView.findViewById(C0415R.id.antispamcalldate);
                holder.f4157d = (TextView) convertView.findViewById(C0415R.id.antispamcalltype);
                holder.f4158e = (ImageView) convertView.findViewById(C0415R.id.antispamcall_check);
                convertView.setTag(holder);
            } else {
                holder = (C0684a) convertView.getTag();
            }
            Contract con = this.f4153c.get(position);
            if (con.getName() == null || con.getName().equals("")) {
                holder.f4154a.setText(C0415R.string.antispamlocalblack_noName);
            } else {
                holder.f4154a.setText(con.getName());
            }
            ImageView tButton = holder.f4158e;
            if (con.isSelect()) {
                tButton.setBackgroundResource(C0415R.drawable.ic_checkbox_select);
            } else {
                tButton.setBackgroundResource(C0415R.drawable.ic_checkbox);
            }
            if (ManLocalBlackAddActivity.this.f4127g == 1) {
                holder.f4155b.setText(con.getPhoneNumber());
                holder.f4157d.setText(ContractHelpUtils.getType(ManLocalBlackAddActivity.this, con.getCallType()));
                holder.f4156c.setText(ContractHelpUtils.getDate(con.getDate()));
            } else {
                holder.f4155b.setVisibility(8);
                holder.f4157d.setVisibility(8);
                holder.f4156c.setText(con.getPhoneNumber());
            }
            return convertView;
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddActivity$CallAdapter$a */
        private class C0684a {

            /* JADX INFO: renamed from: a */
            TextView f4154a;

            /* JADX INFO: renamed from: b */
            TextView f4155b;

            /* JADX INFO: renamed from: c */
            TextView f4156c;

            /* JADX INFO: renamed from: d */
            TextView f4157d;

            /* JADX INFO: renamed from: e */
            ImageView f4158e;

            private C0684a() {
            }

            /* synthetic */ C0684a(CallAdapter x0, byte b) {
                this();
            }
        }
    }

    public class SmsAdapter extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private Context f4161b;

        /* JADX INFO: renamed from: c */
        private List<Contract> f4162c;

        public SmsAdapter(Context context, List<Contract> list) {
            this.f4161b = context;
            this.f4162c = list;
        }

        @Override // android.widget.Adapter
        public int getCount() {
            return this.f4162c.size();
        }

        @Override // android.widget.Adapter
        public Object getItem(int position) {
            return this.f4162c.get(position);
        }

        @Override // android.widget.Adapter
        public long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            C0685a holder;
            if (convertView == null) {
                convertView = LayoutInflater.from(this.f4161b).inflate(C0415R.layout.antispamsms, (ViewGroup) null);
                holder = new C0685a(this, (byte) 0);
                holder.f4163a = (TextView) convertView.findViewById(C0415R.id.antispamsmsname);
                holder.f4164b = (TextView) convertView.findViewById(C0415R.id.antispamsmsnumber);
                holder.f4165c = (TextView) convertView.findViewById(C0415R.id.antispamsmscontent);
                holder.f4166d = (ImageView) convertView.findViewById(C0415R.id.antispamsmscheck);
                convertView.setTag(holder);
            } else {
                holder = (C0685a) convertView.getTag();
            }
            Contract con = this.f4162c.get(position);
            if (con.getName() == null || con.getName().equals("")) {
                holder.f4163a.setText(C0415R.string.antispamlocalblack_noName);
            } else {
                holder.f4163a.setText(con.getName());
            }
            holder.f4164b.setText(con.getPhoneNumber());
            if (con.getSmsContent() != null && !con.getSmsContent().equals("")) {
                holder.f4165c.setText(con.getSmsContent());
            } else {
                holder.f4165c.setText(C0415R.string.antispamno_content);
            }
            if (con.isSelect()) {
                holder.f4166d.setBackgroundResource(C0415R.drawable.ic_checkbox_select);
            } else {
                holder.f4166d.setBackgroundResource(C0415R.drawable.ic_checkbox);
            }
            return convertView;
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackAddActivity$SmsAdapter$a */
        private class C0685a {

            /* JADX INFO: renamed from: a */
            TextView f4163a;

            /* JADX INFO: renamed from: b */
            TextView f4164b;

            /* JADX INFO: renamed from: c */
            TextView f4165c;

            /* JADX INFO: renamed from: d */
            ImageView f4166d;

            private C0685a() {
            }

            /* synthetic */ C0685a(SmsAdapter x0, byte b) {
                this();
            }
        }
    }
}
