package com.lenovo.safecenter.net;

import android.R;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.os.Process;
import android.text.format.Formatter;
import android.util.Log;
import android.util.SparseArray;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.TextView;
import com.google.android.collect.Lists;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.net.doublemode.NetSetting;
import com.lenovo.safecenter.net.support.AppInfo;
import com.lenovo.safecenter.net.support.Logger;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.net.support.UidDetail;
import com.lenovo.safecenter.net.support.UidDetailProvider;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.MyUtils;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;

/* JADX INFO: loaded from: classes.dex */
public class LowLevelNetFilter extends Activity implements View.OnClickListener {
    public static final String NETSETTING = "com.lenovo.leos.nac_preferences";
    public static final String RESUIDS = "reserved uids";
    public static final String SELECTED = "selected uids";
    public static final String SYSENABLED = "system enabled";
    public static final String SYSINFO = "system info";
    public static final String WLAN_SYSINFO = "wlan info";

    /* JADX INFO: renamed from: e */
    private static Context f4384e;

    /* JADX INFO: renamed from: b */
    private TrafficStatsService f4386b;

    /* JADX INFO: renamed from: c */
    private TextView f4387c;

    /* JADX INFO: renamed from: d */
    private TextView f4388d;

    /* JADX INFO: renamed from: f */
    private DataUsageAdapter f4389f;

    /* JADX INFO: renamed from: g */
    private ListView f4390g;

    /* JADX INFO: renamed from: h */
    private UidDetailProvider f4391h;

    /* JADX INFO: renamed from: k */
    private ArrayList<AppInfo> f4394k;

    /* JADX INFO: renamed from: l */
    private TextView f4395l;

    /* JADX INFO: renamed from: m */
    private TextView f4396m;

    /* JADX INFO: renamed from: n */
    private ProgressBar f4397n;

    /* JADX INFO: renamed from: p */
    private ImageView f4399p;

    /* JADX INFO: renamed from: q */
    private ImageView f4400q;

    /* JADX INFO: renamed from: r */
    private boolean f4401r;

    /* JADX INFO: renamed from: s */
    private boolean f4402s;
    public static String SOCKET = "socketclient";
    public static final HashSet<Integer> netBlackUids = new HashSet<>();
    public static final HashSet<Integer> netBlackUidsWlan = new HashSet<>();

    /* JADX INFO: renamed from: a */
    private boolean f4385a = false;

    /* JADX INFO: renamed from: i */
    private int f4392i = 0;

    /* JADX INFO: renamed from: j */
    private HashSet<Integer> f4393j = new HashSet<>();

    /* JADX INFO: renamed from: o */
    private Handler f4398o = new Handler() { // from class: com.lenovo.safecenter.net.LowLevelNetFilter.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    if (!LowLevelNetFilter.this.f4385a) {
                        TrafficStatsService.alert(LowLevelNetFilter.this, LowLevelNetFilter.this.getText(C0415R.string.info_failed));
                    }
                    break;
                case 1:
                    String conn_count = String.format(LowLevelNetFilter.this.getString(C0415R.string.app_can_conn_net), Integer.valueOf(LowLevelNetFilter.this.f4389f.getCount()));
                    LowLevelNetFilter.this.f4388d.setText(conn_count);
                    if (LowLevelNetFilter.netBlackUids.size() == LowLevelNetFilter.this.f4403t.size() - 2) {
                        LowLevelNetFilter.this.m1793a(false);
                        LowLevelNetFilter.this.m1796b();
                    }
                    if (LowLevelNetFilter.netBlackUidsWlan.size() == LowLevelNetFilter.this.f4403t.size() - 2) {
                        LowLevelNetFilter.this.m1798b(false);
                        LowLevelNetFilter.this.m1800c();
                    }
                    break;
                case 3:
                    LowLevelNetFilter.this.f4397n.setVisibility(8);
                    LowLevelNetFilter.this.f4389f.bindStats(LowLevelNetFilter.this.f4394k);
                    LowLevelNetFilter.m1808i(LowLevelNetFilter.this);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: t */
    private ArrayList<C0728a> f4403t = Lists.newArrayList();

    /* JADX INFO: renamed from: u */
    private boolean f4404u = false;

    /* JADX INFO: renamed from: i */
    static /* synthetic */ void m1808i(LowLevelNetFilter x0) {
        x0.f4387c.setVisibility(x0.f4389f.isEmpty() ? 0 : 8);
    }

    /* JADX INFO: renamed from: m */
    static /* synthetic */ void m1812m(LowLevelNetFilter x0) {
        try {
            StringBuilder sb = new StringBuilder();
            SharedPreferences sharedPreferences = x0.getSharedPreferences("system info", 0);
            Iterator<Integer> it = netBlackUids.iterator();
            while (it.hasNext()) {
                sb.append(it.next() + C0092c.f1284O);
            }
            SharedPreferences.Editor editorEdit = sharedPreferences.edit();
            editorEdit.putString("selected uids", sb.toString());
            editorEdit.commit();
        } catch (Exception e) {
            Log.v("Filter", e.toString());
        }
    }

    /* JADX INFO: renamed from: n */
    static /* synthetic */ void m1813n(LowLevelNetFilter x0) {
        try {
            Log.i("nac", "touch saveWlanList");
            String str = "";
            SharedPreferences sharedPreferences = x0.getSharedPreferences("wlan info", 0);
            Iterator<Integer> it = netBlackUidsWlan.iterator();
            while (it.hasNext()) {
                str = str + it.next() + C0092c.f1284O;
            }
            SharedPreferences.Editor editorEdit = sharedPreferences.edit();
            editorEdit.putString("selected uids", str);
            editorEdit.commit();
            Log.i("nac", "wlan uids string =" + str);
        } catch (Exception e) {
            Log.v("nac", e.toString());
        }
    }

    /* JADX INFO: renamed from: o */
    static /* synthetic */ boolean m1814o(LowLevelNetFilter x0) {
        x0.f4404u = true;
        return true;
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public void m1793a(boolean enabled) {
        TrafficStatsService.setMobileDataButtonValue(f4384e, enabled);
        this.f4401r = enabled;
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: b */
    public void m1798b(boolean enabled) {
        TrafficStatsService.setWlanDataButtonValue(f4384e, enabled);
        this.f4402s = enabled;
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: b */
    public void m1796b() {
        this.f4399p.setBackgroundResource(this.f4401r ? C0415R.drawable.net_mobile_all_on : C0415R.drawable.net_mobile_all_off);
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: c */
    public void m1800c() {
        this.f4400q.setBackgroundResource(this.f4402s ? C0415R.drawable.net_wifi_all_on : C0415R.drawable.net_wifi_all_off);
    }

    @Override // android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.activity_layout_netfilter);
        f4384e = this;
        TextView textView = (TextView) findViewById(C0415R.id.txt_title);
        ImageView imageView = (ImageView) findViewById(C0415R.id.title_back);
        ImageView imageView2 = (ImageView) findViewById(C0415R.id.title_set);
        imageView.setOnClickListener(this);
        imageView2.setOnClickListener(this);
        imageView2.setVisibility(4);
        textView.setText(C0415R.string.net_app_title);
        this.f4395l = (TextView) findViewById(C0415R.id.show_root_info);
        this.f4396m = (TextView) findViewById(C0415R.id.show_root_info_select);
        this.f4397n = (ProgressBar) findViewById(C0415R.id.progress_bar);
        this.f4388d = (TextView) findViewById(C0415R.id.can_conn);
        this.f4386b = TrafficStatsService.getInstance(this);
        this.f4387c = (TextView) findViewById(R.id.empty);
        this.f4391h = new UidDetailProvider(f4384e);
        this.f4390g = (ListView) findViewById(C0415R.id.list);
        this.f4390g.setItemsCanFocus(true);
        this.f4399p = (ImageView) findViewById(C0415R.id.net_app_check_mobile_all);
        this.f4400q = (ImageView) findViewById(C0415R.id.net_app_check_wlan_all);
        this.f4401r = TrafficStatsService.getMobileDataButtonValue(f4384e);
        this.f4402s = TrafficStatsService.getWlanDataButtonValue(f4384e);
        this.f4399p.setOnClickListener(this);
        this.f4400q.setOnClickListener(this);
        Log.i("4.2.5", "mMobileDataEnabled = " + this.f4401r + ",mWlanDataEnabled = " + this.f4402s);
        m1796b();
        m1800c();
        this.f4389f = new DataUsageAdapter(this.f4391h, this.f4392i);
        this.f4390g.setAdapter((ListAdapter) this.f4389f);
        this.f4397n.setVisibility(0);
        TrafficStatsService.getExecutorService().execute(new Thread() { // from class: com.lenovo.safecenter.net.LowLevelNetFilter.2
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                TrafficStatsService.addNetWhiteList(LowLevelNetFilter.f4384e);
                if (LowLevelNetFilter.netBlackUids == null || LowLevelNetFilter.netBlackUids.size() == 0) {
                    SharedPreferences prefs = LowLevelNetFilter.f4384e.getSharedPreferences("system info", 0);
                    String allUid = prefs.getString("selected uids", "");
                    String[] uidString = allUid.split(C0092c.f1284O);
                    if (!allUid.equals("") && uidString.length > 0) {
                        for (String uid : uidString) {
                            LowLevelNetFilter.netBlackUids.add(Integer.valueOf(Integer.parseInt(uid)));
                        }
                    }
                }
                if (LowLevelNetFilter.netBlackUidsWlan == null || LowLevelNetFilter.netBlackUidsWlan.size() == 0) {
                    SharedPreferences prefsWlan = LowLevelNetFilter.f4384e.getSharedPreferences("wlan info", 0);
                    String allUid2 = prefsWlan.getString("selected uids", "");
                    String[] uidString2 = allUid2.split(C0092c.f1284O);
                    if (!allUid2.equals("") && uidString2.length > 0) {
                        for (String uid2 : uidString2) {
                            LowLevelNetFilter.netBlackUidsWlan.add(Integer.valueOf(Integer.parseInt(uid2)));
                        }
                    }
                }
                LowLevelNetFilter.this.f4386b.refreshUid();
                LowLevelNetFilter.this.f4394k = TrafficStatsService.getAppInfos(LowLevelNetFilter.f4384e, LowLevelNetFilter.this.f4393j);
                ArrayList<AppInfo> apps = TrafficStatsService.getApps(LowLevelNetFilter.f4384e);
                for (AppInfo appInfo : apps) {
                    if (!LowLevelNetFilter.this.f4393j.contains(Integer.valueOf(appInfo.uid)) && appInfo.uid != 10001 && appInfo.uid != 10013 && appInfo.uid != 1001 && appInfo.uid != 1013 && appInfo.uid > 10000 && appInfo.uid != Process.getUidForName("media")) {
                        LowLevelNetFilter.this.f4394k.add(appInfo);
                    }
                }
                LowLevelNetFilter.this.f4398o.sendEmptyMessage(3);
            }
        });
    }

    @Override // android.app.Activity
    protected void onStart() {
        super.onStart();
        if (!WflUtils.isRoot()) {
            this.f4395l.setVisibility(0);
        }
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
    }

    /* JADX WARN: Type inference failed for: r0v3, types: [com.lenovo.safecenter.net.LowLevelNetFilter$3] */
    @Override // android.app.Activity
    protected void onPause() {
        super.onPause();
        Log.i("nac", "touch onPause and isUserClick " + this.f4404u);
        if (this.f4404u) {
            new Thread() { // from class: com.lenovo.safecenter.net.LowLevelNetFilter.3
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    LowLevelNetFilter.m1812m(LowLevelNetFilter.this);
                    LowLevelNetFilter.m1813n(LowLevelNetFilter.this);
                    LowLevelNetFilter.this.f4385a = TrafficStatsService.createShell(LowLevelNetFilter.this);
                    Log.i("nac", "touch applyRules");
                    LowLevelNetFilter.this.f4398o.sendEmptyMessage(0);
                }
            }.start();
            boolean z = this.f4385a;
        }
        sendBroadcast(new Intent("com.lenovo.safecenter.refreshAppsManager"));
        TrackEvent.trackPause(this);
    }

    public class DataUsageAdapter extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private final UidDetailProvider f4409b;

        /* JADX INFO: renamed from: c */
        private final int f4410c;

        public DataUsageAdapter(UidDetailProvider provider, int insetSide) {
            this.f4409b = provider;
            this.f4410c = insetSide;
        }

        public void bindStats(ArrayList<AppInfo> stats) {
            LowLevelNetFilter.this.f4403t.clear();
            SparseArray<C0728a> knownUids = new SparseArray<>();
            int size = stats != null ? stats.size() : 0;
            if (size > 0) {
                for (AppInfo app : stats) {
                    int uid = app.uid;
                    if (!Const.mNetWhiteApps2.contains(Integer.valueOf(uid))) {
                        C0728a item = knownUids.get(uid);
                        if (item == null) {
                            item = new C0728a(uid);
                            knownUids.put(uid, item);
                            LowLevelNetFilter.this.f4403t.add(item);
                        }
                        item.f4418b = app.item_3g;
                    }
                }
            }
            Collections.sort(LowLevelNetFilter.this.f4403t);
            LowLevelNetFilter.this.f4398o.sendMessage(LowLevelNetFilter.this.f4398o.obtainMessage(1));
            notifyDataSetChanged();
        }

        @Override // android.widget.Adapter
        public int getCount() {
            return LowLevelNetFilter.this.f4403t.size();
        }

        @Override // android.widget.Adapter
        public Object getItem(int position) {
            return LowLevelNetFilter.this.f4403t.get(position);
        }

        @Override // android.widget.Adapter
        public long getItemId(int position) {
            return ((C0728a) LowLevelNetFilter.this.f4403t.get(position)).f4417a[0];
        }

        @Override // android.widget.Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            if (convertView == null) {
                convertView = LayoutInflater.from(parent.getContext()).inflate(C0415R.layout.data_usage_item, parent, false);
                if (this.f4410c > 0) {
                    convertView.setPadding(this.f4410c, 0, this.f4410c, 0);
                }
            }
            Context context = parent.getContext();
            final ImageView mCheck = (ImageView) convertView.findViewById(C0415R.id.net_app_check);
            TextView mTotalTextView = (TextView) convertView.findViewById(C0415R.id.net_app_total);
            final ImageView mCheckWlan = (ImageView) convertView.findViewById(C0415R.id.net_app_check_wlan);
            final C0728a item = (C0728a) LowLevelNetFilter.this.f4403t.get(position);
            AsyncTaskC0729b.m1817a(this.f4409b, item, convertView);
            mTotalTextView.setText(Formatter.formatFileSize(context, item.f4418b));
            mCheck.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.net.LowLevelNetFilter.DataUsageAdapter.1
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    if (!Const.isObtainRoot() && !TrafficStatsService.nacServerIsExist()) {
                        LowLevelNetFilter.this.m1803d();
                        return;
                    }
                    int uid = item.f4417a[0];
                    Logger.m1950i("8.1", "cilck uid = " + uid);
                    item.f4419c = !item.f4419c;
                    if (item.f4419c) {
                        LowLevelNetFilter.netBlackUids.add(Integer.valueOf(uid));
                        mCheck.setBackgroundResource(NetFilter.drawable_mobile_off);
                    } else {
                        LowLevelNetFilter.netBlackUids.remove(Integer.valueOf(uid));
                        mCheck.setBackgroundResource(NetFilter.drawable_mobile_on);
                    }
                    if (LowLevelNetFilter.netBlackUids.size() < LowLevelNetFilter.this.f4403t.size() - 2) {
                        LowLevelNetFilter.this.m1793a(true);
                    } else {
                        LowLevelNetFilter.this.m1793a(false);
                    }
                    LowLevelNetFilter.this.m1796b();
                    LowLevelNetFilter.m1814o(LowLevelNetFilter.this);
                }
            });
            mCheckWlan.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.net.LowLevelNetFilter.DataUsageAdapter.2
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    if (!Const.isObtainRoot() && !TrafficStatsService.nacServerIsExist()) {
                        LowLevelNetFilter.this.m1803d();
                        return;
                    }
                    int uid = item.f4417a[0];
                    item.f4420d = !item.f4420d;
                    if (item.f4420d) {
                        LowLevelNetFilter.netBlackUidsWlan.add(Integer.valueOf(uid));
                        mCheckWlan.setBackgroundResource(NetFilter.drawable_wifi_off);
                    } else {
                        LowLevelNetFilter.netBlackUidsWlan.remove(Integer.valueOf(uid));
                        mCheckWlan.setBackgroundResource(NetFilter.drawable_wifi_on);
                    }
                    if (LowLevelNetFilter.netBlackUidsWlan.size() < LowLevelNetFilter.this.f4403t.size() - 2) {
                        LowLevelNetFilter.this.m1798b(true);
                    } else {
                        LowLevelNetFilter.this.m1798b(false);
                    }
                    LowLevelNetFilter.this.m1800c();
                    LowLevelNetFilter.m1814o(LowLevelNetFilter.this);
                    Log.i("nac", "wlan uid size =" + LowLevelNetFilter.netBlackUidsWlan.size());
                }
            });
            if (item.f4417a[0] == -4 || item.f4417a[0] == 1000 || Const.mNetWhiteApps.contains(Integer.valueOf(item.f4417a[0]))) {
                mCheck.setBackgroundResource(C0415R.drawable.net_transparent);
                mCheckWlan.setBackgroundResource(C0415R.drawable.net_transparent);
            } else {
                mCheck.setBackgroundResource(item.f4419c ? NetFilter.drawable_mobile_off : NetFilter.drawable_mobile_on);
                mCheckWlan.setBackgroundResource(item.f4420d ? NetFilter.drawable_wifi_off : NetFilter.drawable_wifi_on);
            }
            if (item.f4417a[0] == -4 || item.f4417a[0] == 1000 || Const.mNetWhiteApps.contains(Integer.valueOf(item.f4417a[0]))) {
                mCheck.setClickable(false);
                mCheckWlan.setClickable(false);
            }
            return convertView;
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.net.LowLevelNetFilter$a */
    private static class C0728a implements Comparable<C0728a> {

        /* JADX INFO: renamed from: a */
        public int[] f4417a;

        /* JADX INFO: renamed from: b */
        public long f4418b;

        /* JADX INFO: renamed from: c */
        public boolean f4419c;

        /* JADX INFO: renamed from: d */
        public boolean f4420d;

        @Override // java.lang.Comparable
        public final /* synthetic */ int compareTo(C0728a c0728a) {
            C0728a c0728a2 = c0728a;
            if (c0728a2.f4417a[0] == -4 || c0728a2.f4417a[0] == 1000 || Const.mNetWhiteApps.contains(Integer.valueOf(c0728a2.f4417a[0]))) {
                if ((this.f4417a[0] == -4 || this.f4417a[0] == 1000 || Const.mNetWhiteApps.contains(Integer.valueOf(this.f4417a[0]))) && c0728a2.f4418b >= this.f4418b) {
                    return c0728a2.f4418b == this.f4418b ? 0 : 1;
                }
                return -1;
            }
            if (this.f4417a[0] == -4 || this.f4417a[0] == 1000 || Const.mNetWhiteApps.contains(Integer.valueOf(this.f4417a[0]))) {
                return 1;
            }
            if (c0728a2.f4418b >= this.f4418b) {
                return c0728a2.f4418b == this.f4418b ? 0 : 1;
            }
            return -1;
        }

        public C0728a(int uid) {
            this.f4417a = new int[]{uid};
            this.f4419c = LowLevelNetFilter.netBlackUids.contains(Integer.valueOf(uid));
            this.f4420d = LowLevelNetFilter.netBlackUidsWlan.contains(Integer.valueOf(uid));
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.net.LowLevelNetFilter$b */
    private static class AsyncTaskC0729b extends AsyncTask<Void, Void, UidDetail> {

        /* JADX INFO: renamed from: a */
        private final UidDetailProvider f4421a;

        /* JADX INFO: renamed from: b */
        private final C0728a f4422b;

        /* JADX INFO: renamed from: c */
        private final View f4423c;

        @Override // android.os.AsyncTask
        protected final /* synthetic */ UidDetail doInBackground(Void[] voidArr) {
            return this.f4421a.getUidDetail(this.f4422b.f4417a[0], true);
        }

        @Override // android.os.AsyncTask
        protected final /* synthetic */ void onPostExecute(UidDetail uidDetail) {
            m1816a(uidDetail, this.f4423c, this.f4422b.f4417a[0]);
        }

        private AsyncTaskC0729b(UidDetailProvider provider, C0728a item, View target) {
            this.f4421a = provider;
            this.f4422b = item;
            this.f4423c = target;
        }

        /* JADX INFO: renamed from: a */
        public static void m1817a(UidDetailProvider provider, C0728a item, View target) {
            AsyncTaskC0729b existing = (AsyncTaskC0729b) target.getTag();
            if (existing != null) {
                existing.cancel(false);
            }
            UidDetail cachedDetail = provider.getUidDetail(item.f4417a[0], false);
            try {
                m1816a(cachedDetail, target, item.f4417a[0]);
            } catch (Exception e) {
                target.setTag(new AsyncTaskC0729b(provider, item, target).executeOnExecutor(AsyncTask.THREAD_POOL_EXECUTOR, new Void[0]));
            }
        }

        /* JADX INFO: renamed from: a */
        private static void m1816a(UidDetail detail, View target, int uid) {
            ImageView icon = (ImageView) target.findViewById(C0415R.id.net_app_icon);
            TextView title = (TextView) target.findViewById(C0415R.id.net_app_name);
            if (detail != null) {
                icon.setImageDrawable(detail.icon);
                if (uid == 1000) {
                    String colorText = "(" + LowLevelNetFilter.f4384e.getString(C0415R.string.net_sys_app) + ")";
                    String allText = ((Object) detail.label) + colorText;
                    title.setText(allText);
                    MyUtils.setSpannableString(title, allText, detail.label.length(), allText.length(), LowLevelNetFilter.f4384e.getResources().getColor(C0415R.color.blue_btn));
                    return;
                }
                if (Const.mNetWhiteApps.contains(Integer.valueOf(uid))) {
                    String colorText2 = "(" + LowLevelNetFilter.f4384e.getString(C0415R.string.net_trust_app) + ")";
                    String allText2 = ((Object) detail.label) + colorText2;
                    title.setText(allText2);
                    MyUtils.setSpannableString(title, allText2, detail.label.length(), allText2.length(), LowLevelNetFilter.f4384e.getResources().getColor(C0415R.color.blue_btn));
                    return;
                }
                title.setText(detail.label);
                return;
            }
            icon.setImageDrawable(null);
            title.setText((CharSequence) null);
        }

        @Override // android.os.AsyncTask
        protected final void onPreExecute() {
            m1816a((UidDetail) null, this.f4423c, this.f4422b.f4417a[0]);
        }
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.net_app_check_mobile_all /* 2131296341 */:
                if (Const.isObtainRoot() || TrafficStatsService.nacServerIsExist()) {
                    this.f4401r = this.f4401r ? false : true;
                    m1793a(this.f4401r);
                    m1796b();
                    m1791a(C0415R.id.net_app_check_mobile_all);
                    this.f4404u = true;
                    Log.i("4.2.5", "mMobileDataEnabled@ = " + this.f4401r + ",mWlanDataEnabled@ = " + this.f4402s);
                } else {
                    m1803d();
                }
                break;
            case C0415R.id.net_app_check_wlan_all /* 2131296342 */:
                if (Const.isObtainRoot() || TrafficStatsService.nacServerIsExist()) {
                    this.f4402s = this.f4402s ? false : true;
                    m1798b(this.f4402s);
                    m1800c();
                    m1791a(C0415R.id.net_app_check_wlan_all);
                    this.f4404u = true;
                } else {
                    m1803d();
                }
                break;
            case C0415R.id.title_back /* 2131297709 */:
                finish();
                break;
            case C0415R.id.title_set /* 2131297710 */:
                startActivity(new Intent(this, (Class<?>) NetSetting.class));
                break;
        }
    }

    /* JADX INFO: renamed from: a */
    private void m1791a(int type) {
        if (type == C0415R.id.net_app_check_mobile_all) {
            if (this.f4401r) {
                Iterator<C0728a> it = this.f4403t.iterator();
                while (it.hasNext()) {
                    it.next().f4419c = false;
                }
                netBlackUids.clear();
            } else {
                for (C0728a item : this.f4403t) {
                    item.f4419c = true;
                    if (!Const.mNetWhiteApps.contains(Integer.valueOf(item.f4417a[0]))) {
                        netBlackUids.add(Integer.valueOf(item.f4417a[0]));
                    }
                }
            }
        } else if (this.f4402s) {
            Iterator<C0728a> it2 = this.f4403t.iterator();
            while (it2.hasNext()) {
                it2.next().f4420d = false;
            }
            netBlackUidsWlan.clear();
        } else {
            for (C0728a item2 : this.f4403t) {
                item2.f4420d = true;
                if (!Const.mNetWhiteApps.contains(Integer.valueOf(item2.f4417a[0]))) {
                    netBlackUidsWlan.add(Integer.valueOf(item2.f4417a[0]));
                }
            }
        }
        this.f4390g.invalidateViews();
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: d */
    public void m1803d() {
        this.f4395l.setVisibility(8);
        this.f4396m.setVisibility(0);
    }
}
