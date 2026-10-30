package com.lenovo.safecenter.AppsManager;

import android.R;
import android.app.Activity;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseExpandableListAdapter;
import android.widget.ExpandableListView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.adapter.PermAdapter;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.support.AppInfo;
import com.lenovo.safecenter.support.SafeCenterService;
import com.lenovo.safecenter.utils.MyUtils;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class MessageBlackList extends Activity {

    /* JADX INFO: renamed from: a */
    private PackageManager f2266a;

    /* JADX INFO: renamed from: c */
    private ArrayList<AppInfo> f2268c;

    /* JADX INFO: renamed from: d */
    private TextView f2269d;

    /* JADX INFO: renamed from: e */
    private TextView f2270e;

    /* JADX INFO: renamed from: f */
    private TextView f2271f;

    /* JADX INFO: renamed from: g */
    private TextView f2272g;

    /* JADX INFO: renamed from: h */
    private TextView f2273h;

    /* JADX INFO: renamed from: i */
    private ProgressBar f2274i;

    /* JADX INFO: renamed from: j */
    private TextView f2275j;

    /* JADX INFO: renamed from: k */
    private TextView f2276k;

    /* JADX INFO: renamed from: l */
    private TextView f2277l;

    /* JADX INFO: renamed from: m */
    private TextView f2278m;

    /* JADX INFO: renamed from: n */
    private ExpandableListView f2279n;

    /* JADX INFO: renamed from: o */
    private ListView f2280o;

    /* JADX INFO: renamed from: p */
    private C0289a f2281p;

    /* JADX INFO: renamed from: q */
    private String f2282q;

    /* JADX INFO: renamed from: r */
    private int f2283r;

    /* JADX INFO: renamed from: s */
    private int f2284s;

    /* JADX INFO: renamed from: t */
    private boolean f2285t;

    /* JADX INFO: renamed from: u */
    private boolean f2286u;

    /* JADX INFO: renamed from: v */
    private Context f2287v;

    /* JADX INFO: renamed from: b */
    private AppDatabase f2267b = null;

    /* JADX INFO: renamed from: w */
    private Handler f2288w = new Handler() { // from class: com.lenovo.safecenter.AppsManager.MessageBlackList.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    MessageBlackList.this.f2271f.setText(String.format(MessageBlackList.this.getString(C0415R.string.deny_apps_count), Integer.valueOf(MessageBlackList.this.f2283r), MessageBlackList.this.getString(C0415R.string.to_sms_back), Integer.valueOf(MessageBlackList.this.f2284s)));
                    if (MessageBlackList.this.f2284s == 0) {
                        MyUtils.showToast(MessageBlackList.this.f2287v, MessageBlackList.this.getString(C0415R.string.toast_allow_all));
                    } else if (MessageBlackList.this.f2284s == MessageBlackList.this.f2283r) {
                        MyUtils.showToast(MessageBlackList.this.f2287v, MessageBlackList.this.getString(C0415R.string.toast_deny_all));
                    }
                    break;
                case 1:
                    MessageBlackList.this.f2272g.setVisibility(8);
                    MessageBlackList.this.f2273h.setVisibility(0);
                    break;
                case 2:
                    MessageBlackList.this.f2271f.setText(String.format(MessageBlackList.this.getString(C0415R.string.deny_apps_count), Integer.valueOf(MessageBlackList.this.f2283r), MessageBlackList.this.getString(C0415R.string.to_sms_back), Integer.valueOf(MessageBlackList.this.f2284s)));
                    MyUtils.showToast(MessageBlackList.this.f2287v, String.format(MessageBlackList.this.getString(C0415R.string.toast_deny_num), Integer.valueOf(MessageBlackList.this.f2284s), MessageBlackList.this.getString(C0415R.string.to_sms_back)));
                    break;
                case 3:
                    MessageBlackList.this.f2271f.setText(String.format(MessageBlackList.this.getString(C0415R.string.deny_apps_count), Integer.valueOf(MessageBlackList.this.f2283r), MessageBlackList.this.getString(C0415R.string.to_sms_back), Integer.valueOf(MessageBlackList.this.f2284s)));
                    MyUtils.showToast(MessageBlackList.this.f2287v, MessageBlackList.this.getString(C0415R.string.toast_tip_all));
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m949a(MessageBlackList x0, AppInfo x1, int x2) {
        x1.selected = x2;
        x0.f2267b.updateApp(x1, x0.f2282q);
    }

    /* JADX INFO: renamed from: h */
    static /* synthetic */ void m957h(MessageBlackList x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.info).setIcon(R.drawable.ic_dialog_alert).setMessage(C0415R.string.allow_all_tip).setColorPositiveButton(false).setColorNegativeButton(true).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.MessageBlackList.2
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                try {
                    MessageBlackList.this.f2286u = true;
                    MessageBlackList.this.f2267b.updateApp(MessageBlackList.this.f2268c, 0);
                    MessageBlackList.this.f2284s = 0;
                    MessageBlackList.this.f2288w.sendMessage(MessageBlackList.this.f2288w.obtainMessage(0));
                    for (int i = 0; i < MessageBlackList.this.f2281p.getGroupCount(); i++) {
                        if (MessageBlackList.this.f2279n.expandGroup(i)) {
                            MessageBlackList.this.f2279n.collapseGroup(i);
                        }
                    }
                    MessageBlackList.this.f2279n.setTranscriptMode(1);
                    MessageBlackList.this.f2279n.invalidateViews();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.MessageBlackList.12
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }

    /* JADX INFO: renamed from: n */
    static /* synthetic */ int m963n(MessageBlackList x0) {
        int i = x0.f2284s;
        x0.f2284s = i + 1;
        return i;
    }

    /* JADX INFO: renamed from: q */
    static /* synthetic */ void m966q(MessageBlackList x0) {
        if (x0.f2285t) {
            x0.f2281p = x0.new C0289a(x0);
            x0.f2279n.setAdapter(x0.f2281p);
        } else {
            x0.f2280o.setAdapter((ListAdapter) new PermAdapter(x0, x0.f2268c));
        }
    }

    /* JADX INFO: renamed from: w */
    static /* synthetic */ void m972w(MessageBlackList x0) {
        x0.f2282q = AppDatabase.DB_APP_SENDMESSAGE;
        x0.f2268c = x0.f2267b.loadApps(x0, x0.f2282q, x0.f2285t);
        x0.f2283r = x0.f2268c.size();
        int i = 0;
        while (true) {
            int i2 = i;
            if (i2 >= x0.f2283r) {
                return;
            }
            if (x0.f2268c.get(i2).selected == 1) {
                x0.f2284s++;
            }
            i = i2 + 1;
        }
    }

    /* JADX INFO: renamed from: x */
    static /* synthetic */ int m973x(MessageBlackList x0) {
        int i = x0.f2284s;
        x0.f2284s = i - 1;
        return i;
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.second_main);
        this.f2287v = this;
        this.f2285t = WflUtils.isRoot();
        this.f2269d = (TextView) findViewById(C0415R.id.txt_title);
        this.f2269d.setText(C0415R.string.sms_background);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.MessageBlackList.5
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                MessageBlackList.this.finish();
            }
        });
        this.f2271f = (TextView) findViewById(C0415R.id.deny_apps_des);
        if (this.f2285t) {
            ((LinearLayout) findViewById(C0415R.id.expandablelistview_layout)).setVisibility(0);
            this.f2279n = (ExpandableListView) findViewById(C0415R.id.expandListView);
            this.f2279n.setGroupIndicator(null);
        } else {
            ((LinearLayout) findViewById(C0415R.id.listView_layout)).setVisibility(0);
            this.f2280o = (ListView) findViewById(C0415R.id.listView);
        }
        setOnclick();
        this.f2270e = (TextView) findViewById(C0415R.id.txt_empty);
        this.f2274i = (ProgressBar) findViewById(C0415R.id.progress_bar);
        this.f2275j = (TextView) findViewById(C0415R.id.selectall);
        this.f2276k = (TextView) findViewById(C0415R.id.offall);
        this.f2277l = (TextView) findViewById(C0415R.id.infoall);
        this.f2278m = (TextView) findViewById(C0415R.id.suggest);
        this.f2272g = (TextView) findViewById(C0415R.id.show_root_info);
        this.f2273h = (TextView) findViewById(C0415R.id.show_root_info_select);
        this.f2275j.setEnabled(false);
        this.f2276k.setEnabled(false);
        this.f2277l.setEnabled(false);
        this.f2278m.setEnabled(false);
        this.f2275j.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.MessageBlackList.6
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (MessageBlackList.this.f2284s == 0 && MessageBlackList.this.f2286u) {
                    MessageBlackList.this.f2288w.sendMessage(MessageBlackList.this.f2288w.obtainMessage(0));
                } else {
                    MessageBlackList.m957h(MessageBlackList.this);
                }
            }
        });
        this.f2276k.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.MessageBlackList.7
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                try {
                    if (MessageBlackList.this.f2284s != MessageBlackList.this.f2283r) {
                        MessageBlackList.this.f2286u = false;
                        MessageBlackList.this.f2267b.updateApp(MessageBlackList.this.f2268c, 1);
                        for (int i = 0; i < MessageBlackList.this.f2281p.getGroupCount(); i++) {
                            if (MessageBlackList.this.f2279n.expandGroup(i)) {
                                MessageBlackList.this.f2279n.collapseGroup(i);
                            }
                        }
                        MessageBlackList.this.f2279n.setTranscriptMode(1);
                        MessageBlackList.this.f2279n.invalidateViews();
                        MessageBlackList.this.f2284s = MessageBlackList.this.f2283r;
                    }
                    MessageBlackList.this.f2288w.sendMessage(MessageBlackList.this.f2288w.obtainMessage(0));
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
        this.f2277l.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.MessageBlackList.8
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                try {
                    MessageBlackList.this.f2286u = false;
                    MessageBlackList.this.f2267b.updateApp(MessageBlackList.this.f2268c, 2);
                    for (int i = 0; i < MessageBlackList.this.f2281p.getGroupCount(); i++) {
                        if (MessageBlackList.this.f2279n.expandGroup(i)) {
                            MessageBlackList.this.f2279n.collapseGroup(i);
                        }
                    }
                    MessageBlackList.this.f2279n.setTranscriptMode(1);
                    MessageBlackList.this.f2279n.invalidateViews();
                    MessageBlackList.this.f2284s = 0;
                    MessageBlackList.this.f2288w.sendMessage(MessageBlackList.this.f2288w.obtainMessage(3));
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
        this.f2278m.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.MessageBlackList.9
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                MessageBlackList.this.f2284s = 0;
                MessageBlackList.this.f2286u = false;
                MessageBlackList.this.f2267b.expertSuggest(MessageBlackList.this.f2287v, MessageBlackList.this.f2268c, true);
                for (int i = 0; i < MessageBlackList.this.f2281p.getGroupCount(); i++) {
                    if (MessageBlackList.this.f2279n.expandGroup(i)) {
                        MessageBlackList.this.f2279n.collapseGroup(i);
                    }
                }
                MessageBlackList.this.f2279n.setTranscriptMode(1);
                MessageBlackList.this.f2279n.invalidateViews();
                for (int i2 = 0; i2 < MessageBlackList.this.f2283r; i2++) {
                    if (((AppInfo) MessageBlackList.this.f2268c.get(i2)).selected == 1) {
                        MessageBlackList.m963n(MessageBlackList.this);
                    }
                }
                MessageBlackList.this.f2288w.sendMessage(MessageBlackList.this.f2288w.obtainMessage(2));
            }
        });
        this.f2266a = getPackageManager();
        this.f2267b = new AppDatabase(this);
        initApps();
    }

    @Override // android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        super.onResume();
    }

    @Override // android.app.Activity
    protected void onPause() {
        super.onPause();
        if (this.f2285t) {
            startService(new Intent(this, (Class<?>) SafeCenterService.class));
        }
        sendBroadcast(new Intent("com.lenovo.safecenter.refreshAppsManager"));
        TrackEvent.trackPause(this);
    }

    /* JADX WARN: Type inference failed for: r1v1, types: [com.lenovo.safecenter.AppsManager.MessageBlackList$11] */
    public void initApps() {
        this.f2274i.setVisibility(0);
        final Handler handler = new Handler() { // from class: com.lenovo.safecenter.AppsManager.MessageBlackList.10
            @Override // android.os.Handler
            public final void handleMessage(Message msg) {
                MessageBlackList.this.f2274i.setVisibility(8);
                MessageBlackList.this.f2271f.setText(String.format(MessageBlackList.this.getString(C0415R.string.deny_apps_count), Integer.valueOf(MessageBlackList.this.f2283r), MessageBlackList.this.getString(C0415R.string.to_sms_back), Integer.valueOf(MessageBlackList.this.f2284s)));
                if (MessageBlackList.this.f2268c.size() == 0) {
                    MessageBlackList.this.f2270e.setVisibility(0);
                    return;
                }
                MessageBlackList.this.f2270e.setVisibility(8);
                MessageBlackList.m966q(MessageBlackList.this);
                if (MessageBlackList.this.f2285t) {
                    MessageBlackList.this.f2272g.setVisibility(8);
                    MessageBlackList.this.f2275j.setEnabled(true);
                    MessageBlackList.this.f2276k.setEnabled(true);
                    MessageBlackList.this.f2277l.setEnabled(true);
                    MessageBlackList.this.f2278m.setEnabled(true);
                    return;
                }
                MessageBlackList.this.f2272g.setVisibility(0);
            }
        };
        new Thread() { // from class: com.lenovo.safecenter.AppsManager.MessageBlackList.11
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                MessageBlackList.m972w(MessageBlackList.this);
                Message msg = new Message();
                msg.what = 0;
                handler.sendMessage(msg);
            }
        }.start();
    }

    public void setOnclick() {
        if (!this.f2285t) {
            this.f2280o.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.AppsManager.MessageBlackList.3
                @Override // android.widget.AdapterView.OnItemClickListener
                public final void onItemClick(AdapterView<?> arg0, View arg1, int arg2, long arg3) {
                    MessageBlackList.this.f2288w.sendMessage(MessageBlackList.this.f2288w.obtainMessage(1));
                }
            });
        } else {
            this.f2279n.setOnGroupExpandListener(new ExpandableListView.OnGroupExpandListener() { // from class: com.lenovo.safecenter.AppsManager.MessageBlackList.4
                @Override // android.widget.ExpandableListView.OnGroupExpandListener
                public final void onGroupExpand(int groupPosition) {
                    if (groupPosition == MessageBlackList.this.f2268c.size() - 1) {
                        MessageBlackList.this.f2279n.setTranscriptMode(2);
                    } else {
                        MessageBlackList.this.f2279n.setTranscriptMode(1);
                    }
                    for (int i = 0; i < MessageBlackList.this.f2281p.getGroupCount(); i++) {
                        if (groupPosition != i) {
                            MessageBlackList.this.f2279n.collapseGroup(i);
                        }
                    }
                }
            });
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.AppsManager.MessageBlackList$a */
    private class C0289a extends BaseExpandableListAdapter {

        /* JADX INFO: renamed from: b */
        private Context f2303b;

        /* JADX INFO: renamed from: c */
        private LayoutInflater f2304c;

        /* JADX INFO: renamed from: d */
        private b f2305d;

        /* JADX INFO: renamed from: e */
        private a f2306e;

        public C0289a(Context context) {
            this.f2304c = LayoutInflater.from(context);
            this.f2303b = context;
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
        public final View getChildView(final int groupPosition, int childPosition, boolean isLastChild, View convertView, ViewGroup parent) {
            if (convertView == null) {
                convertView = this.f2304c.inflate(C0415R.layout.changeitemxml, (ViewGroup) null);
                this.f2306e = new a();
                this.f2306e.f2316a = (LinearLayout) convertView.findViewById(C0415R.id.allow);
                this.f2306e.f2317b = (LinearLayout) convertView.findViewById(C0415R.id.tip);
                this.f2306e.f2318c = (LinearLayout) convertView.findViewById(C0415R.id.deny);
                convertView.setTag(this.f2306e);
            } else {
                this.f2306e = (a) convertView.getTag();
            }
            final AppInfo aInfo = (AppInfo) MessageBlackList.this.f2268c.get(groupPosition);
            this.f2306e.f2316a.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.MessageBlackList.a.1
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    if (aInfo.selected == 1) {
                        MessageBlackList.m973x(MessageBlackList.this);
                        MessageBlackList.this.f2288w.sendMessage(MessageBlackList.this.f2288w.obtainMessage(0));
                    }
                    aInfo.selected = 0;
                    MessageBlackList.this.f2279n.invalidateViews();
                    MessageBlackList.this.f2279n.collapseGroup(groupPosition);
                    MessageBlackList.m949a(MessageBlackList.this, aInfo, aInfo.selected);
                }
            });
            this.f2306e.f2317b.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.MessageBlackList.a.2
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    if (aInfo.selected == 1) {
                        MessageBlackList.m973x(MessageBlackList.this);
                        MessageBlackList.this.f2288w.sendMessage(MessageBlackList.this.f2288w.obtainMessage(0));
                    }
                    aInfo.selected = 2;
                    MessageBlackList.this.f2279n.invalidateViews();
                    MessageBlackList.this.f2279n.collapseGroup(groupPosition);
                    MessageBlackList.m949a(MessageBlackList.this, aInfo, aInfo.selected);
                }
            });
            this.f2306e.f2318c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.MessageBlackList.a.3
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    if (aInfo.selected != 1) {
                        MessageBlackList.m963n(MessageBlackList.this);
                        MessageBlackList.this.f2288w.sendMessage(MessageBlackList.this.f2288w.obtainMessage(0));
                    }
                    aInfo.selected = 1;
                    MessageBlackList.this.f2279n.invalidateViews();
                    MessageBlackList.this.f2279n.collapseGroup(groupPosition);
                    MessageBlackList.m949a(MessageBlackList.this, aInfo, aInfo.selected);
                }
            });
            return convertView;
        }

        @Override // android.widget.ExpandableListAdapter
        public final Object getGroup(int groupPosition) {
            return MessageBlackList.this.f2268c.get(groupPosition);
        }

        @Override // android.widget.ExpandableListAdapter
        public final int getGroupCount() {
            return MessageBlackList.this.f2268c.size();
        }

        @Override // android.widget.ExpandableListAdapter
        public final long getGroupId(int groupPosition) {
            return groupPosition;
        }

        @Override // android.widget.ExpandableListAdapter
        public final View getGroupView(int groupPosition, boolean isExpanded, View convertView, ViewGroup parent) {
            if (convertView == null) {
                convertView = this.f2304c.inflate(C0415R.layout.second_item, (ViewGroup) null);
                this.f2305d = new b();
                this.f2305d.f2320a = (ImageView) convertView.findViewById(C0415R.id.app_icon);
                this.f2305d.f2321b = (TextView) convertView.findViewById(C0415R.id.app_name);
                this.f2305d.f2322c = (TextView) convertView.findViewById(C0415R.id.app_suggest);
                this.f2305d.f2323d = (ImageView) convertView.findViewById(C0415R.id.itemcheck);
                convertView.setTag(this.f2305d);
            } else {
                this.f2305d = (b) convertView.getTag();
            }
            AppInfo appInfo = (AppInfo) MessageBlackList.this.f2268c.get(groupPosition);
            convertView.setVisibility(0);
            try {
                String cmd = appInfo.applicationInfo.loadLabel(MessageBlackList.this.f2266a).toString();
                this.f2305d.f2321b.setText(cmd);
                this.f2305d.f2320a.setImageDrawable(appInfo.applicationInfo.loadIcon(MessageBlackList.this.f2266a));
            } catch (Exception e) {
                e.printStackTrace();
                this.f2305d.f2321b.setText(appInfo.name);
                this.f2305d.f2320a.setImageResource(C0415R.drawable.icon3);
            }
            ImageView tButton = this.f2305d.f2323d;
            tButton.setTag(appInfo);
            if (appInfo.selected == 0) {
                tButton.setBackgroundResource(C0415R.drawable.perm_grant);
            } else if (appInfo.selected == 2) {
                tButton.setBackgroundResource(C0415R.drawable.perm_prompt);
            } else if (appInfo.selected == 1) {
                tButton.setBackgroundResource(C0415R.drawable.perm_deny);
            }
            if (appInfo.suggest == 0) {
                this.f2305d.f2322c.setVisibility(0);
                this.f2305d.f2322c.setTextColor(this.f2303b.getResources().getColor(C0415R.color.green_allow));
                this.f2305d.f2322c.setText(C0415R.string.suggest_allow);
            } else if (appInfo.suggest == 1) {
                this.f2305d.f2322c.setVisibility(0);
                this.f2305d.f2322c.setTextColor(this.f2303b.getResources().getColor(C0415R.color.red_forbid));
                this.f2305d.f2322c.setText(C0415R.string.suggest_forbid);
            } else if (appInfo.suggest == 2 || appInfo.suggest == -1) {
                this.f2305d.f2322c.setVisibility(4);
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

        /* JADX INFO: renamed from: com.lenovo.safecenter.AppsManager.MessageBlackList$a$b */
        class b {

            /* JADX INFO: renamed from: a */
            ImageView f2320a;

            /* JADX INFO: renamed from: b */
            TextView f2321b;

            /* JADX INFO: renamed from: c */
            TextView f2322c;

            /* JADX INFO: renamed from: d */
            ImageView f2323d;

            b() {
            }
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.AppsManager.MessageBlackList$a$a */
        class a {

            /* JADX INFO: renamed from: a */
            LinearLayout f2316a;

            /* JADX INFO: renamed from: b */
            LinearLayout f2317b;

            /* JADX INFO: renamed from: c */
            LinearLayout f2318c;

            a() {
            }
        }
    }
}
