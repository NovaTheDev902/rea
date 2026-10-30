package com.lenovo.safecenter.net;

import android.R;
import android.app.Activity;
import android.app.LoaderManager;
import android.content.Context;
import android.content.Intent;
import android.content.Loader;
import android.content.SharedPreferences;
import android.net.NetworkStats;
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
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.RelativeLayout;
import android.widget.TextView;
import com.google.android.collect.Lists;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.net.doublemode.NetSetting;
import com.lenovo.safecenter.net.support.Logger;
import com.lenovo.safecenter.net.support.PhoneSimInfo;
import com.lenovo.safecenter.net.support.SummaryForAllUidLoader;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.net.support.UidDetail;
import com.lenovo.safecenter.net.support.UidDetailProvider;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.MyUtils;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;

/* JADX INFO: loaded from: classes.dex */
public class NetFilter extends Activity implements View.OnClickListener {
    public static final String NETSETTING = "com.lenovo.leos.nac_preferences";
    public static final String RESUIDS = "reserved uids";
    public static final String SELECTED = "selected uids";
    public static final String SYSENABLED = "system enabled";
    public static final String SYSINFO = "system info";
    public static final int WHITE_LIST_SIZE = 2;
    public static final String WLAN_SYSINFO = "wlan info";

    /* JADX INFO: renamed from: e */
    private static Context f4424e;

    /* JADX INFO: renamed from: b */
    private TextView f4426b;

    /* JADX INFO: renamed from: c */
    private TextView f4427c;

    /* JADX INFO: renamed from: f */
    private Object f4429f;

    /* JADX INFO: renamed from: g */
    private DataUsageAdapter f4430g;

    /* JADX INFO: renamed from: h */
    private ListView f4431h;

    /* JADX INFO: renamed from: i */
    private UidDetailProvider f4432i;

    /* JADX INFO: renamed from: l */
    private C0736a f4435l;

    /* JADX INFO: renamed from: n */
    private ProgressBar f4437n;

    /* JADX INFO: renamed from: o */
    private ImageView f4438o;

    /* JADX INFO: renamed from: p */
    private ImageView f4439p;

    /* JADX INFO: renamed from: q */
    private boolean f4440q;

    /* JADX INFO: renamed from: r */
    private boolean f4441r;
    public static final HashSet<Integer> netBlackUids = new HashSet<>();
    public static final HashSet<Integer> netBlackUidsWlan = new HashSet<>();
    public static int drawable_wifi_on = C0415R.drawable.net_wifi_single_on;
    public static int drawable_wifi_off = C0415R.drawable.net_wifi_single_off;
    public static int drawable_mobile_on = C0415R.drawable.net_mobile_single_on;
    public static int drawable_mobile_off = C0415R.drawable.net_mobile_single_off;

    /* JADX INFO: renamed from: a */
    private boolean f4425a = false;

    /* JADX INFO: renamed from: d */
    private ArrayList<C0736a> f4428d = Lists.newArrayList();

    /* JADX INFO: renamed from: j */
    private int f4433j = 0;

    /* JADX INFO: renamed from: k */
    private int f4434k = 0;

    /* JADX INFO: renamed from: m */
    private Handler f4436m = new Handler() { // from class: com.lenovo.safecenter.net.NetFilter.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    if (!NetFilter.this.f4425a) {
                        TrafficStatsService.alert(NetFilter.this, NetFilter.this.getText(C0415R.string.info_failed));
                    }
                    break;
                case 1:
                    String conn_count = String.format(NetFilter.this.getString(C0415R.string.app_can_conn_net), Integer.valueOf(NetFilter.this.f4428d.size()));
                    NetFilter.this.f4427c.setText(conn_count);
                    if (NetFilter.netBlackUids.size() == NetFilter.this.f4428d.size() - 2) {
                        NetFilter.this.m1823a(false);
                        NetFilter.this.m1827b();
                    }
                    if (NetFilter.netBlackUidsWlan.size() == NetFilter.this.f4428d.size() - 2) {
                        NetFilter.this.m1829b(false);
                        NetFilter.this.m1831c();
                    }
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: s */
    private boolean f4442s = false;

    /* JADX INFO: renamed from: t */
    private AdapterView.OnItemClickListener f4443t = new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.net.NetFilter.2
        @Override // android.widget.AdapterView.OnItemClickListener
        public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
            NetFilter.this.f4435l = (C0736a) NetFilter.this.f4428d.get(position);
            NetFilter.this.f4435l.f4466g = !NetFilter.this.f4435l.f4466g;
            if (NetFilter.this.f4434k != position) {
                ((C0736a) NetFilter.this.f4428d.get(NetFilter.this.f4434k)).f4466g = false;
                NetFilter.this.f4434k = position;
            }
            NetFilter.this.f4431h.invalidateViews();
        }
    };

    /* JADX INFO: renamed from: u */
    private final LoaderManager.LoaderCallbacks<PhoneSimInfo> f4444u = new LoaderManager.LoaderCallbacks<PhoneSimInfo>() { // from class: com.lenovo.safecenter.net.NetFilter.4
        @Override // android.app.LoaderManager.LoaderCallbacks
        public final /* synthetic */ void onLoadFinished(Loader<PhoneSimInfo> loader, PhoneSimInfo phoneSimInfo) {
            NetFilter.this.f4437n.setVisibility(8);
            NetFilter.this.f4430g.bindStats(phoneSimInfo);
            m1846a();
        }

        @Override // android.app.LoaderManager.LoaderCallbacks
        public final Loader<PhoneSimInfo> onCreateLoader(int id, Bundle args) {
            NetFilter.this.f4437n.setVisibility(0);
            return new SummaryForAllUidLoader(NetFilter.f4424e, NetFilter.this.f4429f, args);
        }

        @Override // android.app.LoaderManager.LoaderCallbacks
        public final void onLoaderReset(Loader<PhoneSimInfo> loader) {
            NetFilter.this.f4430g.bindStats(null);
            m1846a();
        }

        /* JADX INFO: renamed from: a */
        private void m1846a() {
            boolean isEmpty = NetFilter.this.f4430g.isEmpty();
            NetFilter.this.f4426b.setVisibility(isEmpty ? 0 : 8);
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ boolean m1825a(int[] x0, int x1) {
        for (int i : x0) {
            if (i == x1) {
                return true;
            }
        }
        return false;
    }

    /* JADX INFO: renamed from: i */
    static /* synthetic */ void m1838i(NetFilter x0) {
        try {
            String str = "";
            SharedPreferences sharedPreferences = x0.getSharedPreferences("system info", 0);
            Iterator<Integer> it = netBlackUids.iterator();
            while (it.hasNext()) {
                str = str + it.next() + C0092c.f1284O;
            }
            SharedPreferences.Editor editorEdit = sharedPreferences.edit();
            editorEdit.putString("selected uids", str);
            editorEdit.commit();
        } catch (Exception e) {
            Log.v("Filter", e.toString());
        }
    }

    /* JADX INFO: renamed from: j */
    static /* synthetic */ void m1839j(NetFilter x0) {
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

    /* JADX INFO: renamed from: l */
    static /* synthetic */ boolean m1841l(NetFilter x0) {
        x0.f4442s = true;
        return true;
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public void m1823a(boolean enabled) {
        TrafficStatsService.setMobileDataButtonValue(f4424e, enabled);
        this.f4440q = enabled;
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: b */
    public void m1829b(boolean enabled) {
        TrafficStatsService.setWlanDataButtonValue(f4424e, enabled);
        this.f4441r = enabled;
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: b */
    public void m1827b() {
        this.f4438o.setBackgroundResource(this.f4440q ? C0415R.drawable.net_mobile_all_on : C0415R.drawable.net_mobile_all_off);
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: c */
    public void m1831c() {
        this.f4439p.setBackgroundResource(this.f4441r ? C0415R.drawable.net_wifi_all_on : C0415R.drawable.net_wifi_all_off);
    }

    @Override // android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.activity_layout_netfilter);
        f4424e = this;
        TextView textView = (TextView) findViewById(C0415R.id.txt_title);
        ImageView imageView = (ImageView) findViewById(C0415R.id.title_back);
        ImageView imageView2 = (ImageView) findViewById(C0415R.id.title_set);
        imageView.setOnClickListener(this);
        imageView2.setOnClickListener(this);
        textView.setText(C0415R.string.net_app_title);
        this.f4429f = TrafficStatsService.getNetWorkStatsService();
        this.f4427c = (TextView) findViewById(C0415R.id.can_conn);
        this.f4437n = (ProgressBar) findViewById(C0415R.id.progress_bar);
        this.f4426b = (TextView) findViewById(R.id.empty);
        this.f4432i = new UidDetailProvider(f4424e);
        this.f4431h = (ListView) findViewById(C0415R.id.list);
        this.f4431h.setItemsCanFocus(true);
        this.f4430g = new DataUsageAdapter(this.f4432i, this.f4433j);
        this.f4431h.setAdapter((ListAdapter) this.f4430g);
        this.f4431h.setOnItemClickListener(this.f4443t);
        this.f4438o = (ImageView) findViewById(C0415R.id.net_app_check_mobile_all);
        this.f4439p = (ImageView) findViewById(C0415R.id.net_app_check_wlan_all);
        this.f4440q = TrafficStatsService.getMobileDataButtonValue(f4424e);
        this.f4441r = TrafficStatsService.getWlanDataButtonValue(f4424e);
        this.f4438o.setOnClickListener(this);
        this.f4439p.setOnClickListener(this);
        m1827b();
        m1831c();
        long start = WflUtils.parseMonthStartTime(Long.valueOf(System.currentTimeMillis())).longValue();
        long end = System.currentTimeMillis();
        getLoaderManager().restartLoader(3, SummaryForAllUidLoader.buildArgs(TrafficStatsService.getImsiInfo(this), start, end), this.f4444u);
        Log.i("nac", "oncreate  = " + this.f4442s);
    }

    @Override // android.app.Activity
    protected void onStart() {
        super.onStart();
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        f4424e = null;
    }

    /* JADX WARN: Type inference failed for: r0v2, types: [com.lenovo.safecenter.net.NetFilter$3] */
    @Override // android.app.Activity
    protected void onPause() {
        super.onPause();
        TrackEvent.trackPause(this);
        if (this.f4442s) {
            new Thread() { // from class: com.lenovo.safecenter.net.NetFilter.3
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    NetFilter.m1838i(NetFilter.this);
                    NetFilter.m1839j(NetFilter.this);
                    NetFilter.this.f4425a = TrafficStatsService.createShell(NetFilter.this);
                    NetFilter.this.f4436m.sendEmptyMessage(0);
                }
            }.start();
            boolean z = this.f4425a;
        }
        sendBroadcast(new Intent("com.lenovo.safecenter.refreshAppsManager"));
    }

    public class DataUsageAdapter extends BaseAdapter {

        /* JADX INFO: renamed from: a */
        final SparseArray<C0736a> f4449a = new SparseArray<>();

        /* JADX INFO: renamed from: b */
        final C0736a f4450b = new C0736a(1000);

        /* JADX INFO: renamed from: d */
        private final UidDetailProvider f4452d;

        /* JADX INFO: renamed from: e */
        private final int f4453e;

        public DataUsageAdapter(UidDetailProvider provider, int insetSide) {
            this.f4452d = (UidDetailProvider) NetFilter.checkNotNull(provider);
            this.f4453e = insetSide;
        }

        public void bindStats(PhoneSimInfo info) {
            NetFilter.this.f4428d.clear();
            if (info != null) {
                if (info.networkInfo1 != null) {
                    m1847a(info.networkInfo1);
                }
                if (info.networkInfo2 != null) {
                    m1847a(info.networkInfo2);
                }
                if (info.getNetworkInfoWlan() != null) {
                    NetworkStats networkInfoWlan = info.getNetworkInfoWlan();
                    C0736a c0736a = new C0736a(1000);
                    int size = networkInfoWlan != null ? networkInfoWlan.size() : 0;
                    NetworkStats.Entry entry = null;
                    int i = 0;
                    while (i < size) {
                        NetworkStats.Entry values = networkInfoWlan.getValues(i, entry);
                        Logger.m1950i("4.3", "entry set=" + values.set);
                        int i2 = values.uid;
                        if ((i2 >= 10000 && i2 <= 99999 && !Const.mNetWhiteApps2.contains(Integer.valueOf(i2))) || i2 == -5) {
                            C0736a c0736a2 = this.f4449a.get(i2);
                            if (c0736a2 == null) {
                                c0736a2 = new C0736a(i2);
                                this.f4449a.put(i2, c0736a2);
                                NetFilter.this.f4428d.add(c0736a2);
                            }
                            if (values.set == 0) {
                                c0736a2.f4468i += values.rxBytes + values.txBytes;
                            } else {
                                c0736a2.f4467h += values.rxBytes + values.txBytes;
                            }
                            c0736a2.f4469j += values.rxBytes + values.txBytes;
                        } else {
                            if (c0736a.f4468i == 0) {
                                c0736a.f4468i += values.rxBytes + values.txBytes;
                            } else {
                                c0736a.f4467h += values.rxBytes + values.txBytes;
                            }
                            c0736a.f4469j += values.rxBytes + values.txBytes;
                            c0736a.m1849a(i2);
                        }
                        i++;
                        entry = values;
                    }
                }
            }
            if (info != null) {
                m1848a(info);
            }
            Collections.sort(NetFilter.this.f4428d);
            Logger.m1950i("4.0", "mItems.size =" + NetFilter.this.f4428d.size());
            NetFilter.this.f4436m.sendMessage(NetFilter.this.f4436m.obtainMessage(1));
            notifyDataSetChanged();
        }

        /* JADX INFO: renamed from: a */
        private void m1848a(PhoneSimInfo info) {
            HashSet<Integer> apps = info.networkList;
            if (apps.size() > 0) {
                Iterator<Integer> it = apps.iterator();
                while (it.hasNext()) {
                    int uid = it.next().intValue();
                    if (uid != 10001 && uid != 10013 && uid != 1001 && uid != Process.getUidForName("media") && uid > 10000 && !Const.mNetWhiteApps2.contains(Integer.valueOf(uid))) {
                        C0736a item = new C0736a(uid);
                        item.f4463d = 0L;
                        item.f4462c = 0L;
                        item.f4461b = 0L;
                        NetFilter.this.f4428d.add(item);
                    }
                }
            }
        }

        /* JADX INFO: renamed from: a */
        private void m1847a(NetworkStats stats) {
            NetworkStats.Entry entry = null;
            int size = stats != null ? stats.size() : 0;
            for (int i = 0; i < size; i++) {
                entry = stats.getValues(i, entry);
                Logger.m1950i("4.3", "entry set=" + entry.set);
                int uid = entry.uid;
                boolean isHidden = Const.mNetWhiteApps2.contains(Integer.valueOf(uid));
                boolean isApp = uid >= 10000 && uid <= 99999 && !isHidden;
                if (isApp || uid == -5) {
                    C0736a item = this.f4449a.get(uid);
                    if (item == null) {
                        item = new C0736a(uid);
                        this.f4449a.put(uid, item);
                        NetFilter.this.f4428d.add(item);
                    }
                    if (entry.set == 0) {
                        item.f4463d += entry.rxBytes + entry.txBytes;
                    } else {
                        item.f4462c += entry.rxBytes + entry.txBytes;
                    }
                    item.f4461b += entry.rxBytes + entry.txBytes;
                } else {
                    if (this.f4450b.f4463d == 0) {
                        this.f4450b.f4463d += entry.rxBytes + entry.txBytes;
                    } else {
                        this.f4450b.f4462c += entry.rxBytes + entry.txBytes;
                    }
                    this.f4450b.f4461b += entry.rxBytes + entry.txBytes;
                    this.f4450b.m1849a(uid);
                }
            }
        }

        @Override // android.widget.Adapter
        public int getCount() {
            return NetFilter.this.f4428d.size();
        }

        @Override // android.widget.Adapter
        public Object getItem(int position) {
            return NetFilter.this.f4428d.get(position);
        }

        @Override // android.widget.Adapter
        public long getItemId(int position) {
            return ((C0736a) NetFilter.this.f4428d.get(position)).f4460a[0];
        }

        @Override // android.widget.Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            if (convertView == null) {
                convertView = LayoutInflater.from(parent.getContext()).inflate(C0415R.layout.data_usage_item, parent, false);
                if (this.f4453e > 0) {
                    convertView.setPadding(this.f4453e, 0, this.f4453e, 0);
                }
            }
            Context context = parent.getContext();
            final ImageView mCheck = (ImageView) convertView.findViewById(C0415R.id.net_app_check);
            final ImageView mCheckWlan = (ImageView) convertView.findViewById(C0415R.id.net_app_check_wlan);
            TextView mTotalTextView = (TextView) convertView.findViewById(C0415R.id.net_app_total);
            TextView mTotalWlanTextView = (TextView) convertView.findViewById(C0415R.id.net_app_total_wlan);
            RelativeLayout chooseLayout = (RelativeLayout) convertView.findViewById(C0415R.id.item_choose_layout);
            TextView mForeTextView = (TextView) convertView.findViewById(C0415R.id.net_fore_traffic);
            TextView mBackTextView = (TextView) convertView.findViewById(C0415R.id.net_back_traffic);
            TextView mForeTextWlanView = (TextView) convertView.findViewById(C0415R.id.net_fore_traffic_wlan);
            TextView mBackTextWlanView = (TextView) convertView.findViewById(C0415R.id.net_back_traffic_wlan);
            final C0736a item = (C0736a) NetFilter.this.f4428d.get(position);
            AsyncTaskC0737b.m1851a(this.f4452d, item, convertView);
            if (item.f4466g) {
                chooseLayout.setVisibility(0);
            } else {
                chooseLayout.setVisibility(8);
            }
            String formatMobileTotalDetail = String.format(NetFilter.this.getString(C0415R.string.net_traffic_mobile_app_useage), TrafficStatsService.getDataString(item.f4461b));
            mTotalTextView.setText(formatMobileTotalDetail);
            String formatWlanTotalDetail = String.format(NetFilter.this.getString(C0415R.string.net_traffic_wlan_app_useage), TrafficStatsService.getDataString(item.f4469j));
            mTotalWlanTextView.setText(formatWlanTotalDetail);
            mForeTextView.setText(Formatter.formatFileSize(context, item.f4462c));
            mBackTextView.setText(Formatter.formatFileSize(context, item.f4463d));
            mForeTextWlanView.setText(Formatter.formatFileSize(context, item.f4467h));
            mBackTextWlanView.setText(Formatter.formatFileSize(context, item.f4468i));
            mCheck.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.net.NetFilter.DataUsageAdapter.1
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    int uid = item.f4460a[0];
                    item.f4464e = !item.f4464e;
                    if (item.f4464e) {
                        NetFilter.netBlackUids.add(Integer.valueOf(uid));
                        mCheck.setBackgroundResource(NetFilter.drawable_mobile_off);
                    } else {
                        NetFilter.netBlackUids.remove(Integer.valueOf(uid));
                        mCheck.setBackgroundResource(NetFilter.drawable_mobile_on);
                    }
                    if (NetFilter.netBlackUids.size() < NetFilter.this.f4428d.size() - 2) {
                        NetFilter.this.m1823a(true);
                    } else {
                        NetFilter.this.m1823a(false);
                    }
                    NetFilter.this.m1827b();
                    NetFilter.m1841l(NetFilter.this);
                    Log.i("nac", "2g uid size =" + NetFilter.netBlackUids.size());
                }
            });
            mCheckWlan.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.net.NetFilter.DataUsageAdapter.2
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    int uid = item.f4460a[0];
                    item.f4465f = !item.f4465f;
                    if (item.f4465f) {
                        NetFilter.netBlackUidsWlan.add(Integer.valueOf(uid));
                        mCheckWlan.setBackgroundResource(NetFilter.drawable_wifi_off);
                    } else {
                        NetFilter.netBlackUidsWlan.remove(Integer.valueOf(uid));
                        mCheckWlan.setBackgroundResource(NetFilter.drawable_wifi_on);
                    }
                    if (NetFilter.netBlackUidsWlan.size() < NetFilter.this.f4428d.size() - 2) {
                        NetFilter.this.m1829b(true);
                    } else {
                        NetFilter.this.m1829b(false);
                    }
                    NetFilter.this.m1831c();
                    NetFilter.m1841l(NetFilter.this);
                }
            });
            if (item.f4460a[0] == -4 || Const.mNetWhiteApps.contains(Integer.valueOf(item.f4460a[0]))) {
                mCheck.setBackgroundResource(C0415R.drawable.net_transparent);
                mCheckWlan.setBackgroundResource(C0415R.drawable.net_transparent);
            } else {
                mCheck.setBackgroundResource(item.f4464e ? NetFilter.drawable_mobile_off : NetFilter.drawable_mobile_on);
                mCheckWlan.setBackgroundResource(item.f4465f ? NetFilter.drawable_wifi_off : NetFilter.drawable_wifi_on);
            }
            if (item.f4460a[0] == -4 || Const.mNetWhiteApps.contains(Integer.valueOf(item.f4460a[0]))) {
                mCheck.setClickable(false);
                mCheckWlan.setClickable(false);
            }
            return convertView;
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.net.NetFilter$a */
    private static class C0736a implements Comparable<C0736a> {

        /* JADX INFO: renamed from: a */
        public int[] f4460a;

        /* JADX INFO: renamed from: b */
        public long f4461b;

        /* JADX INFO: renamed from: c */
        public long f4462c;

        /* JADX INFO: renamed from: d */
        public long f4463d;

        /* JADX INFO: renamed from: e */
        public boolean f4464e;

        /* JADX INFO: renamed from: f */
        public boolean f4465f;

        /* JADX INFO: renamed from: g */
        public boolean f4466g = false;

        /* JADX INFO: renamed from: h */
        public long f4467h;

        /* JADX INFO: renamed from: i */
        public long f4468i;

        /* JADX INFO: renamed from: j */
        public long f4469j;

        @Override // java.lang.Comparable
        public final /* synthetic */ int compareTo(C0736a c0736a) {
            C0736a c0736a2 = c0736a;
            if (c0736a2.f4460a[0] == -4 || c0736a2.f4460a[0] == 1000 || Const.mNetWhiteApps.contains(Integer.valueOf(c0736a2.f4460a[0]))) {
                if ((this.f4460a[0] == -4 || this.f4460a[0] == 1000 || Const.mNetWhiteApps.contains(Integer.valueOf(this.f4460a[0]))) && c0736a2.f4461b >= this.f4461b) {
                    return c0736a2.f4461b == this.f4461b ? 0 : 1;
                }
                return -1;
            }
            if (this.f4460a[0] == -4 || this.f4460a[0] == 1000 || Const.mNetWhiteApps.contains(Integer.valueOf(this.f4460a[0]))) {
                return 1;
            }
            if (c0736a2.f4461b >= this.f4461b) {
                return c0736a2.f4461b == this.f4461b ? 0 : 1;
            }
            return -1;
        }

        public C0736a(int uid) {
            this.f4460a = new int[]{uid};
            this.f4464e = NetFilter.netBlackUids.contains(Integer.valueOf(uid));
            this.f4465f = NetFilter.netBlackUidsWlan.contains(Integer.valueOf(uid));
        }

        /* JADX INFO: renamed from: a */
        public final void m1849a(int uid) {
            if (!NetFilter.m1825a(this.f4460a, uid)) {
                int length = this.f4460a.length;
                this.f4460a = Arrays.copyOf(this.f4460a, length + 1);
                this.f4460a[length] = uid;
            }
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.net.NetFilter$b */
    private static class AsyncTaskC0737b extends AsyncTask<Void, Void, UidDetail> {

        /* JADX INFO: renamed from: a */
        private final UidDetailProvider f4470a;

        /* JADX INFO: renamed from: b */
        private final C0736a f4471b;

        /* JADX INFO: renamed from: c */
        private final View f4472c;

        @Override // android.os.AsyncTask
        protected final /* synthetic */ UidDetail doInBackground(Void[] voidArr) {
            return this.f4470a.getUidDetail(this.f4471b.f4460a[0], true);
        }

        @Override // android.os.AsyncTask
        protected final /* synthetic */ void onPostExecute(UidDetail uidDetail) {
            m1850a(uidDetail, this.f4472c, this.f4471b.f4460a[0]);
        }

        /* JADX INFO: renamed from: a */
        public static void m1851a(UidDetailProvider provider, C0736a item, View target) {
            AsyncTaskC0737b existing = (AsyncTaskC0737b) target.getTag();
            if (existing != null) {
                existing.cancel(false);
            }
            UidDetail cachedDetail = provider.getUidDetail(item.f4460a[0], false);
            m1850a(cachedDetail, target, item.f4460a[0]);
        }

        /* JADX INFO: renamed from: a */
        private static void m1850a(UidDetail detail, View target, int uid) {
            ImageView icon = (ImageView) target.findViewById(C0415R.id.net_app_icon);
            TextView title = (TextView) target.findViewById(C0415R.id.net_app_name);
            if (detail != null) {
                icon.setImageDrawable(detail.icon);
                if (uid == 1000) {
                    String colorText = "(" + NetFilter.f4424e.getString(C0415R.string.net_sys_app) + ")";
                    String allText = ((Object) detail.label) + colorText;
                    title.setText(allText);
                    MyUtils.setSpannableString(title, allText, detail.label.length(), allText.length(), NetFilter.f4424e.getResources().getColor(C0415R.color.blue_btn));
                    return;
                }
                if (Const.mNetWhiteApps.contains(Integer.valueOf(uid))) {
                    String colorText2 = "(" + NetFilter.f4424e.getString(C0415R.string.net_trust_app) + ")";
                    String allText2 = ((Object) detail.label) + colorText2;
                    title.setText(allText2);
                    MyUtils.setSpannableString(title, allText2, detail.label.length(), allText2.length(), NetFilter.f4424e.getResources().getColor(C0415R.color.blue_btn));
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
            m1850a((UidDetail) null, this.f4472c, this.f4471b.f4460a[0]);
        }
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.net_app_check_mobile_all /* 2131296341 */:
                this.f4440q = this.f4440q ? false : true;
                m1823a(this.f4440q);
                m1827b();
                m1821a(C0415R.id.net_app_check_mobile_all);
                this.f4442s = true;
                break;
            case C0415R.id.net_app_check_wlan_all /* 2131296342 */:
                this.f4441r = this.f4441r ? false : true;
                m1829b(this.f4441r);
                m1831c();
                m1821a(C0415R.id.net_app_check_wlan_all);
                this.f4442s = true;
                break;
            case C0415R.id.title_back /* 2131297709 */:
                finish();
                break;
            case C0415R.id.title_set /* 2131297710 */:
                startActivity(new Intent(this, (Class<?>) NetSetting.class));
                break;
        }
    }

    public static <T> T checkNotNull(T reference) {
        if (reference == null) {
            throw new NullPointerException();
        }
        return reference;
    }

    /* JADX INFO: renamed from: a */
    private void m1821a(int type) {
        if (type == C0415R.id.net_app_check_mobile_all) {
            if (this.f4440q) {
                Iterator<C0736a> it = this.f4428d.iterator();
                while (it.hasNext()) {
                    it.next().f4464e = false;
                }
                netBlackUids.clear();
            } else {
                for (C0736a item : this.f4428d) {
                    item.f4464e = true;
                    if (!Const.mNetWhiteApps.contains(Integer.valueOf(item.f4460a[0]))) {
                        netBlackUids.add(Integer.valueOf(item.f4460a[0]));
                    }
                }
            }
        } else if (this.f4441r) {
            Iterator<C0736a> it2 = this.f4428d.iterator();
            while (it2.hasNext()) {
                it2.next().f4465f = false;
            }
            netBlackUidsWlan.clear();
        } else {
            for (C0736a item2 : this.f4428d) {
                item2.f4465f = true;
                if (!Const.mNetWhiteApps.contains(Integer.valueOf(item2.f4460a[0]))) {
                    netBlackUidsWlan.add(Integer.valueOf(item2.f4460a[0]));
                }
            }
        }
        this.f4431h.invalidateViews();
    }
}
