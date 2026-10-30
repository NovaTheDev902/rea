package com.lenovo.performancecenter.performance;

import android.R;
import android.app.Activity;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.text.Html;
import android.text.format.Formatter;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.RelativeLayout;
import android.widget.ScrollView;
import android.widget.TextView;
import com.lenovo.performancecenter.coreui.util.RootPassage;
import com.lenovo.performancecenter.coreui.util.Utils;
import com.lenovo.performancecenter.framework.DataLayerManager;
import com.lenovo.performancecenter.service.object.ApplicationDataInfo;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.MainTab.LeSafeMainActivity;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

/* JADX INFO: loaded from: classes.dex */
public class PhoneAccelerateActivity extends Activity implements View.OnClickListener {

    /* JADX INFO: renamed from: a */
    private Context f1777a;

    /* JADX INFO: renamed from: b */
    private CpuAndMemeoryLayout f1778b;

    /* JADX INFO: renamed from: c */
    private TextView f1779c;

    /* JADX INFO: renamed from: d */
    private TextView f1780d;

    /* JADX INFO: renamed from: e */
    private LinearLayout f1781e;

    /* JADX INFO: renamed from: f */
    private ProgressBar f1782f;

    /* JADX INFO: renamed from: g */
    private TextView f1783g;

    /* JADX INFO: renamed from: h */
    private TextView f1784h;

    /* JADX INFO: renamed from: i */
    private ScrollView f1785i;

    /* JADX INFO: renamed from: j */
    private RelativeLayout f1786j;

    /* JADX INFO: renamed from: k */
    private TextView f1787k;

    /* JADX INFO: renamed from: l */
    private TextView f1788l;

    /* JADX INFO: renamed from: m */
    private TextView f1789m;

    /* JADX INFO: renamed from: n */
    private ListView f1790n;

    /* JADX INFO: renamed from: o */
    private ArrayList<String> f1791o;

    /* JADX INFO: renamed from: p */
    private ArrayList<DataLayerManager.CacheInfo> f1792p;

    /* JADX INFO: renamed from: q */
    private ArrayList<C0189a> f1793q;

    /* JADX INFO: renamed from: r */
    private ArrayList<C0189a> f1794r;

    /* JADX INFO: renamed from: s */
    private int f1795s;

    /* JADX INFO: renamed from: t */
    private ProgressDialog f1796t;

    /* JADX INFO: renamed from: u */
    private boolean f1797u = false;

    /* JADX INFO: renamed from: v */
    private boolean f1798v = false;

    /* JADX INFO: renamed from: w */
    private Handler f1799w = new Handler() { // from class: com.lenovo.performancecenter.performance.PhoneAccelerateActivity.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    PhoneAccelerateActivity.this.f1798v = true;
                    PhoneAccelerateActivity.this.f1799w.sendMessage(PhoneAccelerateActivity.this.f1799w.obtainMessage(3));
                    PhoneAccelerateActivity.this.f1786j.setClickable(true);
                    if (PhoneAccelerateActivity.this.f1791o.size() == 0) {
                        PhoneAccelerateActivity.this.f1787k.setText(PhoneAccelerateActivity.this.f1777a.getString(C0415R.string.phone_acc_running_app_none));
                    } else {
                        PhoneAccelerateActivity.this.f1787k.setText(Html.fromHtml(PhoneAccelerateActivity.this.getString(C0415R.string.phone_acc_running_app, new Object[]{Integer.valueOf(PhoneAccelerateActivity.this.f1791o.size())})));
                    }
                    break;
                case 2:
                    PhoneAccelerateActivity.this.f1797u = true;
                    Log.i("HomePage", "handleMessage ---> cacheAppSize == " + PhoneAccelerateActivity.this.f1792p.size());
                    PhoneAccelerateActivity.this.f1799w.sendMessage(PhoneAccelerateActivity.this.f1799w.obtainMessage(3));
                    if (PhoneAccelerateActivity.this.f1792p.size() == 0) {
                        PhoneAccelerateActivity.this.f1788l.setText(PhoneAccelerateActivity.this.getString(C0415R.string.clear_cache_getting));
                    } else {
                        PhoneAccelerateActivity.this.f1788l.setText(Html.fromHtml(PhoneAccelerateActivity.this.f1777a.getString(C0415R.string.title_clear_cache_summery, Integer.valueOf(PhoneAccelerateActivity.this.f1792p.size()))));
                    }
                    break;
                case 3:
                    if (PhoneAccelerateActivity.this.f1798v && PhoneAccelerateActivity.this.f1797u) {
                        PhoneAccelerateActivity.this.m681a(false);
                        Log.i("HomePage", "mRunningCount == " + PhoneAccelerateActivity.this.f1791o.size() + " cacheAppList.size() == " + PhoneAccelerateActivity.this.f1792p.size());
                        if (PhoneAccelerateActivity.this.f1791o.size() != 0 || PhoneAccelerateActivity.this.f1792p.size() != 0) {
                            PhoneAccelerateActivity.this.f1783g.setText(PhoneAccelerateActivity.this.f1777a.getString(C0415R.string.one_key_speed_btn));
                            PhoneAccelerateActivity.this.f1783g.setVisibility(0);
                            PhoneAccelerateActivity.this.f1779c.setText(PhoneAccelerateActivity.this.f1777a.getString(C0415R.string.one_key_speed_notice_1));
                            PhoneAccelerateActivity.this.f1780d.setVisibility(0);
                            PhoneAccelerateActivity.this.f1780d.setText(PhoneAccelerateActivity.this.f1777a.getString(C0415R.string.one_key_speed_title_1));
                            PhoneAccelerateActivity.this.f1780d.setTextColor(PhoneAccelerateActivity.this.f1777a.getResources().getColor(C0415R.color.red_d74b06));
                        } else {
                            PhoneAccelerateActivity.this.f1783g.setVisibility(8);
                            PhoneAccelerateActivity.this.f1779c.setText(PhoneAccelerateActivity.this.f1777a.getString(C0415R.string.one_key_speed_notice_4));
                            PhoneAccelerateActivity.this.f1780d.setVisibility(0);
                            PhoneAccelerateActivity.this.f1780d.setText(PhoneAccelerateActivity.this.f1777a.getString(C0415R.string.one_key_speed_title_4));
                            PhoneAccelerateActivity.this.f1780d.setTextColor(PhoneAccelerateActivity.this.f1777a.getResources().getColor(C0415R.color.green_36a022));
                        }
                        break;
                    }
                    break;
                case 4:
                    if (!WflUtils.isRoot()) {
                        PhoneAccelerateActivity.this.f1789m.setText(PhoneAccelerateActivity.this.f1777a.getString(C0415R.string.notice_no_rooted_for_boot_mainpage));
                    } else if (msg.arg1 == 0) {
                        PhoneAccelerateActivity.this.f1789m.setText(PhoneAccelerateActivity.this.f1777a.getString(C0415R.string.taskmanager_avail_boot_autorun_fine));
                    } else {
                        PhoneAccelerateActivity.this.f1789m.setText(Html.fromHtml(PhoneAccelerateActivity.this.getString(C0415R.string.taskmanager_avail_boot_autorun, new Object[]{Integer.valueOf(msg.arg1)})));
                    }
                    break;
                case 5:
                    Log.i("HomePage", "handler receive, update ui");
                    PhoneAccelerateActivity.m696n(PhoneAccelerateActivity.this);
                    break;
                case 6:
                    PhoneAccelerateActivity.this.f1797u = true;
                    Log.i("HomePage", "Handler.receive ---> totalCacheSize == 0");
                    PhoneAccelerateActivity.this.f1799w.sendMessage(PhoneAccelerateActivity.this.f1799w.obtainMessage(3));
                    PhoneAccelerateActivity.this.f1788l.setText(PhoneAccelerateActivity.this.getString(C0415R.string.clear_cache_getting));
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: n */
    static /* synthetic */ void m696n(PhoneAccelerateActivity x0) {
        long j;
        x0.f1794r = new ArrayList<>();
        x0.f1793q = new ArrayList<>();
        PackageManager packageManager = x0.getPackageManager();
        Iterator<String> it = x0.f1791o.iterator();
        while (it.hasNext()) {
            try {
                ApplicationInfo applicationInfo = packageManager.getApplicationInfo(it.next(), 0);
                x0.f1793q.add(x0.new C0189a(((Object) applicationInfo.loadLabel(packageManager)) + "", DataLayerManager.drawableToBitmap(applicationInfo.loadIcon(packageManager))));
            } catch (PackageManager.NameNotFoundException e) {
                e.printStackTrace();
            }
        }
        if (!x0.f1793q.isEmpty()) {
            x0.f1793q.add(0, x0.new C0189a(x0.f1777a.getString(C0415R.string.you_can_accelerate_2, Integer.valueOf(x0.f1791o.size()), Formatter.formatFileSize(x0.f1777a, x0.f1795s))));
            x0.f1794r.addAll(x0.f1793q);
            x0.f1794r.trimToSize();
        }
        if (!x0.f1792p.isEmpty()) {
            ArrayList arrayList = new ArrayList();
            long j2 = 0;
            Iterator<DataLayerManager.CacheInfo> it2 = x0.f1792p.iterator();
            while (true) {
                j = j2;
                if (!it2.hasNext()) {
                    break;
                }
                DataLayerManager.CacheInfo next = it2.next();
                arrayList.add(x0.new C0189a(next.pkgName, next.appName, next.appIcon, next.cacheSize));
                j2 = next.appCacheSize + j;
            }
            arrayList.trimToSize();
            x0.f1794r.add(x0.f1793q.size(), x0.new C0189a(x0.getString(C0415R.string.rf_cache_clear_size_t) + Formatter.formatFileSize(x0.f1777a, j)));
            x0.f1794r.addAll(arrayList);
            x0.f1794r.trimToSize();
        }
        x0.f1790n.setAdapter((ListAdapter) x0.new TaskManagerAdapter());
        x0.f1785i.setVisibility(8);
        x0.f1783g.setText(x0.f1777a.getString(C0415R.string.one_key_speed_btn_ok));
        x0.f1779c.setText(x0.f1777a.getString(C0415R.string.one_key_speed_notice_3));
        x0.f1780d.setVisibility(0);
        x0.f1780d.setText(C0415R.string.one_key_speed_title_3);
        x0.f1780d.setTextColor(x0.f1777a.getResources().getColor(C0415R.color.green_36a022));
        x0.m681a(false);
        if (x0.f1796t != null) {
            x0.f1796t.cancel();
        }
    }

    /* JADX INFO: renamed from: p */
    static /* synthetic */ void m698p(PhoneAccelerateActivity x0) {
        Log.i("HomePage", System.currentTimeMillis() + "---> loadProcess start");
        long jCurrentTimeMillis = System.currentTimeMillis() - Utils.getLastKillTime(x0.f1777a);
        if (jCurrentTimeMillis > Utils.CLICK_INTERVAL || jCurrentTimeMillis <= 0) {
            x0.f1791o = ScanApplicationInfo.getRunningAppListJustInLauncher(x0.f1777a);
        } else {
            x0.f1791o = new ArrayList<>();
        }
        x0.f1799w.sendEmptyMessage(1);
        Log.i("HomePage", System.currentTimeMillis() + "---> loadProcess end");
    }

    /* JADX INFO: renamed from: q */
    static /* synthetic */ void m699q(PhoneAccelerateActivity x0) {
        boolean z = false;
        Log.i("HomePage", System.currentTimeMillis() + "---> loadCache start");
        long jCurrentTimeMillis = System.currentTimeMillis();
        long j = x0.getSharedPreferences("PERF_RECORD", 0).getLong("CLICKTIME", 0L);
        long j2 = jCurrentTimeMillis - j;
        Log.i("HomePage", "lastClickTime == " + j + " currentEnterTime == " + jCurrentTimeMillis);
        Log.i("HomePage", "substract == " + j2);
        if (j2 <= 20000 && j2 > 0) {
            z = true;
        }
        if (z) {
            x0.f1799w.sendEmptyMessage(6);
            return;
        }
        x0.f1792p = new ApplicationDataInfo(x0.f1777a).getCacheInfo(x0.f1777a, x0.getPackageManager());
        x0.f1799w.sendEmptyMessage(2);
        Log.i("HomePage", System.currentTimeMillis() + "---> loadCache end");
    }

    /* JADX INFO: renamed from: r */
    static /* synthetic */ void m700r(PhoneAccelerateActivity x0) {
        Log.i("HomePage", System.currentTimeMillis() + "---> loadBoot start");
        DataLayerManageBoot dataLayerManageBoot = new DataLayerManageBoot();
        dataLayerManageBoot.getBootMap(x0.f1777a);
        int needChangeToForbidJustCount = dataLayerManageBoot.getNeedChangeToForbidJustCount();
        Log.i("HomePage", System.currentTimeMillis() + "---> loadBoot end");
        Message messageObtainMessage = x0.f1799w.obtainMessage(4);
        messageObtainMessage.arg1 = needChangeToForbidJustCount;
        x0.f1799w.sendMessage(messageObtainMessage);
    }

    /* JADX INFO: renamed from: s */
    static /* synthetic */ void m701s(PhoneAccelerateActivity x0) {
        ArrayList arrayList = new ArrayList();
        HashMap<String, int[]> runningAppInfo = ScanApplicationInfo.getRunningAppInfo(x0.f1777a);
        x0.f1795s = 0;
        for (Map.Entry<String, int[]> entry : runningAppInfo.entrySet()) {
            arrayList.add(entry.getKey());
            x0.f1795s = entry.getValue()[1] + x0.f1795s;
        }
        if (arrayList.size() > 0) {
            RootPassage.execRootCmd(null, arrayList, " -fs ", x0.f1777a);
        }
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(1);
        setContentView(C0415R.layout.rf_phone_accelerate);
        this.f1777a = this;
        findViewById(C0415R.id.title_back).setOnClickListener(this);
        ((TextView) findViewById(C0415R.id.txt_title)).setText(C0415R.string.opti_name);
        ImageView imageView = (ImageView) findViewById(C0415R.id.title_set);
        imageView.setImageResource(C0415R.drawable.rf_perf_title_set);
        imageView.setVisibility(4);
        imageView.setOnClickListener(this);
        this.f1778b = (CpuAndMemeoryLayout) findViewById(C0415R.id.cpu_mem_layout);
        this.f1779c = (TextView) findViewById(C0415R.id.one_key_notice);
        this.f1780d = (TextView) findViewById(C0415R.id.one_key_title);
        this.f1783g = (TextView) findViewById(C0415R.id.one_key_speed_up);
        this.f1782f = (ProgressBar) findViewById(C0415R.id.scanProgressBar);
        this.f1781e = (LinearLayout) findViewById(C0415R.id.scanProgressBarLayout);
        this.f1787k = (TextView) findViewById(C0415R.id.memory_free);
        this.f1788l = (TextView) findViewById(C0415R.id.total_cache);
        this.f1789m = (TextView) findViewById(C0415R.id.boot_count);
        this.f1784h = (TextView) findViewById(C0415R.id.you_can_accelerate);
        this.f1785i = (ScrollView) findViewById(C0415R.id.scrollview);
        this.f1786j = (RelativeLayout) findViewById(C0415R.id.task_manager_layout);
        this.f1786j.setOnClickListener(this);
        findViewById(C0415R.id.clear_cache_layout).setOnClickListener(this);
        findViewById(C0415R.id.boot_speed_layout).setOnClickListener(this);
        findViewById(C0415R.id.whitelist_layout).setOnClickListener(this);
        this.f1783g.setOnClickListener(this);
        this.f1790n = (ListView) findViewById(C0415R.id.listView);
        this.f1790n.setDivider(null);
        Utils.isPerfRoot = WflUtils.isRoot();
    }

    /* JADX WARN: Type inference failed for: r0v12, types: [com.lenovo.performancecenter.performance.PhoneAccelerateActivity$3] */
    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        this.f1787k.setText(getString(C0415R.string.phone_acc_getting_data));
        this.f1788l.setText(getString(C0415R.string.phone_acc_getting_data));
        this.f1789m.setText(getString(C0415R.string.phone_acc_getting_data));
        this.f1785i.setVisibility(0);
        this.f1784h.setText(this.f1777a.getString(C0415R.string.you_can_accelerate_0));
        this.f1786j.setClickable(false);
        this.f1779c.setText(this.f1777a.getString(C0415R.string.one_key_speed_notice_0));
        this.f1780d.setVisibility(4);
        m681a(true);
        this.f1778b.onResume();
        this.f1791o = new ArrayList<>();
        this.f1792p = new ArrayList<>();
        new Thread() { // from class: com.lenovo.performancecenter.performance.PhoneAccelerateActivity.3
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                PhoneAccelerateActivity.this.f1797u = false;
                PhoneAccelerateActivity.this.f1798v = false;
                PhoneAccelerateActivity.m698p(PhoneAccelerateActivity.this);
                PhoneAccelerateActivity.m699q(PhoneAccelerateActivity.this);
                PhoneAccelerateActivity.m700r(PhoneAccelerateActivity.this);
            }
        }.start();
        TrackEvent.trackResume(this);
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public void m681a(boolean bool) {
        if (bool) {
            this.f1781e.setVisibility(0);
            this.f1782f.setVisibility(0);
            this.f1782f.setIndeterminate(true);
            this.f1783g.setVisibility(8);
            return;
        }
        this.f1781e.setVisibility(8);
        this.f1782f.setVisibility(8);
        this.f1782f.setIndeterminate(false);
        this.f1783g.setVisibility(0);
    }

    public static void getAutoClearTimeGap(Context context, TextView textView) {
        SharedPreferences pref1 = context.getSharedPreferences(ScanApplicationInfo.POLICY_SETTINGS, 0);
        long savedVal = pref1.getLong(ScanApplicationInfo.POLICY_TIME, 20L);
        boolean saveState = pref1.getBoolean(ScanApplicationInfo.POLICY_SWITCH, true);
        if (!saveState) {
            textView.setText(context.getString(C0415R.string.time_summary_none));
        } else {
            textView.setText(Html.fromHtml(context.getResources().getString(C0415R.string.time_summary, Long.valueOf(savedVal))));
        }
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        this.f1778b.onPause();
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onStop() {
        super.onStop();
    }

    /* JADX WARN: Type inference failed for: r4v13, types: [com.lenovo.performancecenter.performance.PhoneAccelerateActivity$4] */
    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.one_key_speed_up /* 2131297499 */:
                if (this.f1783g.getText().equals(getString(C0415R.string.one_key_speed_btn))) {
                    Log.i("HomePage", System.currentTimeMillis() + " KillProcessAll");
                    this.f1780d.setVisibility(4);
                    this.f1779c.setText(this.f1777a.getString(C0415R.string.one_key_speed_notice_2));
                    m681a(true);
                    this.f1784h.setText(this.f1777a.getString(C0415R.string.you_can_accelerate_1));
                    ProgressDialog progressDialog = new ProgressDialog(this);
                    this.f1796t = progressDialog;
                    progressDialog.setMessage(getString(C0415R.string.set_auto_is_running_progress_dialog));
                    progressDialog.setIndeterminate(true);
                    progressDialog.setCancelable(true);
                    progressDialog.setCanceledOnTouchOutside(false);
                    progressDialog.setOnKeyListener(new DialogInterface.OnKeyListener() { // from class: com.lenovo.performancecenter.performance.PhoneAccelerateActivity.2
                        @Override // android.content.DialogInterface.OnKeyListener
                        public final boolean onKey(DialogInterface dialog, int keyCode, KeyEvent event) {
                            return true;
                        }
                    });
                    progressDialog.show();
                    new Thread() { // from class: com.lenovo.performancecenter.performance.PhoneAccelerateActivity.4
                        @Override // java.lang.Thread, java.lang.Runnable
                        public final void run() {
                            PhoneAccelerateActivity.m701s(PhoneAccelerateActivity.this);
                            ApplicationDataInfo.clearAllCache(PhoneAccelerateActivity.this.getPackageManager());
                            PhoneAccelerateActivity.this.f1799w.sendEmptyMessage(5);
                        }
                    }.start();
                    long jCurrentTimeMillis = System.currentTimeMillis();
                    SharedPreferences.Editor editorEdit = getSharedPreferences("PERF_RECORD", 0).edit();
                    editorEdit.putLong("CLICKTIME", jCurrentTimeMillis);
                    editorEdit.commit();
                    Utils.recordKillTimeAndPosition(this.f1777a, System.currentTimeMillis(), 1);
                    TrackEvent.reportClickOneKeyEndTask();
                } else {
                    m680a();
                }
                break;
            case C0415R.id.task_manager_layout /* 2131297519 */:
                Intent it = new Intent(this, (Class<?>) TaskManagerActivity.class);
                startActivity(it);
                break;
            case C0415R.id.clear_cache_layout /* 2131297521 */:
                Intent it3 = new Intent(this, (Class<?>) ClearCacheActivity.class);
                startActivity(it3);
                break;
            case C0415R.id.boot_speed_layout /* 2131297525 */:
                Intent it0 = new Intent(this, (Class<?>) BootSpeedActivity.class);
                startActivity(it0);
                break;
            case C0415R.id.whitelist_layout /* 2131297527 */:
                Intent it4 = new Intent(this, (Class<?>) PerfWhitelistActivity.class);
                startActivity(it4);
                break;
            case C0415R.id.title_back /* 2131297709 */:
                m680a();
                break;
        }
    }

    public class TaskManagerAdapter extends BaseAdapter {
        public TaskManagerAdapter() {
        }

        @Override // android.widget.Adapter
        public int getCount() {
            return PhoneAccelerateActivity.this.f1794r.size();
        }

        @Override // android.widget.Adapter
        public Object getItem(int position) {
            return PhoneAccelerateActivity.this.f1794r.get(position);
        }

        @Override // android.widget.Adapter
        public long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            C0190b mTaskManagerViewHolder = PhoneAccelerateActivity.this.new C0190b();
            if (position == 0 || position == PhoneAccelerateActivity.this.f1793q.size()) {
                View convertView2 = View.inflate(PhoneAccelerateActivity.this.f1777a, C0415R.layout.list_checkbox_item_title, null);
                mTaskManagerViewHolder.f1813c = (TextView) convertView2.findViewById(R.id.title);
                mTaskManagerViewHolder.f1813c.setText(((C0189a) PhoneAccelerateActivity.this.f1794r.get(position)).f1810f);
                return convertView2;
            }
            if (position < PhoneAccelerateActivity.this.f1793q.size()) {
                View convertView3 = View.inflate(PhoneAccelerateActivity.this.f1777a, C0415R.layout.rf_perf_phone_accelerate_details, null);
                mTaskManagerViewHolder.f1812b = (ImageView) convertView3.findViewById(C0415R.id.process_icon);
                mTaskManagerViewHolder.f1813c = (TextView) convertView3.findViewById(C0415R.id.process_name);
                C0189a uai = (C0189a) PhoneAccelerateActivity.this.f1794r.get(position);
                convertView3.setTag(new Object[]{mTaskManagerViewHolder, uai});
                mTaskManagerViewHolder.f1812b.setImageBitmap(uai.f1807c);
                mTaskManagerViewHolder.f1813c.setText(uai.f1806b);
                return convertView3;
            }
            if (position > PhoneAccelerateActivity.this.f1793q.size()) {
                View convertView4 = View.inflate(PhoneAccelerateActivity.this.f1777a, C0415R.layout.rf_perf_phone_accelerate_details, null);
                mTaskManagerViewHolder.f1812b = (ImageView) convertView4.findViewById(C0415R.id.process_icon);
                mTaskManagerViewHolder.f1813c = (TextView) convertView4.findViewById(C0415R.id.process_name);
                mTaskManagerViewHolder.f1814d = (TextView) convertView4.findViewById(C0415R.id.process_state);
                C0189a ai = (C0189a) PhoneAccelerateActivity.this.f1794r.get(position);
                convertView4.setTag(new Object[]{mTaskManagerViewHolder, ai});
                mTaskManagerViewHolder.f1812b.setImageBitmap(ai.f1807c);
                mTaskManagerViewHolder.f1813c.setText(ai.f1806b);
                mTaskManagerViewHolder.f1814d.setText(PhoneAccelerateActivity.this.getString(C0415R.string.string_cache) + ai.f1809e);
                return convertView4;
            }
            return convertView;
        }
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.PhoneAccelerateActivity$b */
    class C0190b {

        /* JADX INFO: renamed from: b */
        private ImageView f1812b;

        /* JADX INFO: renamed from: c */
        private TextView f1813c;

        /* JADX INFO: renamed from: d */
        private TextView f1814d;

        C0190b() {
        }
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.PhoneAccelerateActivity$a */
    class C0189a {

        /* JADX INFO: renamed from: b */
        private String f1806b;

        /* JADX INFO: renamed from: c */
        private Bitmap f1807c;

        /* JADX INFO: renamed from: d */
        private String f1808d;

        /* JADX INFO: renamed from: e */
        private String f1809e;

        /* JADX INFO: renamed from: f */
        private String f1810f;

        public C0189a(String title) {
            this.f1810f = title;
        }

        public C0189a(String pkgName, String appName, Bitmap appIcon, String cacheSize) {
            this.f1808d = pkgName;
            this.f1806b = appName;
            this.f1807c = appIcon;
            this.f1809e = cacheSize;
        }

        public C0189a(String appName, Bitmap appIcon) {
            this.f1806b = appName;
            this.f1807c = appIcon;
        }
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == 4) {
            m680a();
        }
        return super.onKeyDown(keyCode, event);
    }

    /* JADX INFO: renamed from: a */
    private void m680a() {
        Intent intent = new Intent(this, (Class<?>) LeSafeMainActivity.class);
        startActivity(intent);
        finish();
    }
}
