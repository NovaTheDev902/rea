package com.lenovo.safecenter.notificationintercept;

import android.app.Activity;
import android.app.NotificationManager;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.graphics.drawable.Drawable;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.os.Parcelable;
import android.preference.PreferenceManager;
import android.support.v4.view.PagerAdapter;
import android.support.v4.view.ViewPager;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseExpandableListAdapter;
import android.widget.Button;
import android.widget.ExpandableListView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.ToggleButton;
import com.lenovo.performancecenter.coreui.util.Utils;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.performancecenter.performance.ScanApplicationInfo;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.notificationintercept.support.InterceptPermission;
import com.lenovo.safecenter.notificationintercept.support.NotiAdBean;
import com.lenovo.safecenter.notificationintercept.support.NotificationDB;
import com.lenovo.safecenter.notificationintercept.support.PermissionDB;
import com.lenovo.safecenter.notificationintercept.support.RecordDB;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class NotificationTabActivity extends Activity implements View.OnClickListener, RadioGroup.OnCheckedChangeListener {

    /* JADX INFO: renamed from: a */
    private RadioGroup f4794a;

    /* JADX INFO: renamed from: b */
    private RadioButton f4795b;

    /* JADX INFO: renamed from: c */
    private RadioButton f4796c;

    /* JADX INFO: renamed from: d */
    private TextView f4797d;

    /* JADX INFO: renamed from: e */
    private ImageView f4798e;

    /* JADX INFO: renamed from: f */
    private ImageView f4799f;

    /* JADX INFO: renamed from: g */
    private LayoutInflater f4800g;

    /* JADX INFO: renamed from: i */
    private PackageManager f4802i;

    /* JADX INFO: renamed from: j */
    private ExpandableListView f4803j;

    /* JADX INFO: renamed from: k */
    private TextView f4804k;

    /* JADX INFO: renamed from: l */
    private TextView f4805l;

    /* JADX INFO: renamed from: n */
    private C0808b f4807n;

    /* JADX INFO: renamed from: o */
    private ProgressDialog f4808o;

    /* JADX INFO: renamed from: p */
    private ToggleButton f4809p;

    /* JADX INFO: renamed from: q */
    private RelativeLayout f4810q;

    /* JADX INFO: renamed from: r */
    private LinearLayout f4811r;

    /* JADX INFO: renamed from: s */
    private TextView f4812s;

    /* JADX INFO: renamed from: t */
    private TextView f4813t;

    /* JADX INFO: renamed from: u */
    private ViewPager f4814u;

    /* JADX INFO: renamed from: v */
    private List<View> f4815v;

    /* JADX INFO: renamed from: h */
    private int f4801h = -1;

    /* JADX INFO: renamed from: m */
    private List<C0809c> f4806m = new ArrayList();

    /* JADX INFO: renamed from: w */
    private Handler f4816w = new Handler() { // from class: com.lenovo.safecenter.notificationintercept.NotificationTabActivity.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    Bundle data = msg.getData();
                    boolean exSuccess = data.getBoolean("replace");
                    if (exSuccess) {
                        NotificationTabActivity.this.f4809p.setChecked(!NotificationTabActivity.this.f4809p.isChecked());
                        UrlOptionUtils.writeSwitch(NotificationTabActivity.this, NotificationTabActivity.this.f4809p.isChecked());
                    }
                    if (NotificationTabActivity.this.f4808o != null) {
                        NotificationTabActivity.this.f4808o.dismiss();
                        NotificationTabActivity.m1986c(NotificationTabActivity.this);
                    }
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: c */
    static /* synthetic */ ProgressDialog m1986c(NotificationTabActivity x0) {
        x0.f4808o = null;
        return null;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.notificationintercept.NotificationTabActivity$e */
    class C0811e extends PagerAdapter {
        C0811e() {
        }

        @Override // android.support.v4.view.PagerAdapter
        public final void destroyItem(View collection, int position, Object view) {
            if (collection instanceof ViewPager) {
                ((ViewPager) collection).removeView((View) NotificationTabActivity.this.f4815v.get(position));
            }
        }

        @Override // android.support.v4.view.PagerAdapter
        public final void finishUpdate(View arg0) {
        }

        @Override // android.support.v4.view.PagerAdapter
        public final int getCount() {
            return NotificationTabActivity.this.f4815v.size();
        }

        @Override // android.support.v4.view.PagerAdapter
        public final Object instantiateItem(View collection, int position) {
            if (collection instanceof ViewPager) {
                ((ViewPager) collection).addView((View) NotificationTabActivity.this.f4815v.get(position), 0);
            }
            return NotificationTabActivity.this.f4815v.get(position);
        }

        @Override // android.support.v4.view.PagerAdapter
        public final boolean isViewFromObject(View view, Object object) {
            return view == object;
        }

        @Override // android.support.v4.view.PagerAdapter
        public final void restoreState(Parcelable arg0, ClassLoader arg1) {
        }

        @Override // android.support.v4.view.PagerAdapter
        public final Parcelable saveState() {
            return null;
        }

        @Override // android.support.v4.view.PagerAdapter
        public final void startUpdate(View arg0) {
        }
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(1);
        setContentView(C0415R.layout.notification_intercept);
        this.f4794a = (RadioGroup) findViewById(C0415R.id.notification_tab_radiogroup);
        this.f4794a.setOnCheckedChangeListener(this);
        this.f4795b = (RadioButton) findViewById(C0415R.id.notification_permission);
        this.f4796c = (RadioButton) findViewById(C0415R.id.ad_inline);
        this.f4814u = (ViewPager) findViewById(C0415R.id.intercept_viewpager);
        this.f4800g = (LayoutInflater) getSystemService("layout_inflater");
        View notiView = this.f4800g.inflate(C0415R.layout.notification_intercept_noti_tab, (ViewGroup) null);
        View adView = this.f4800g.inflate(C0415R.layout.notification_intercept_ad_tab, (ViewGroup) null);
        this.f4815v = new ArrayList();
        this.f4815v.add(notiView);
        this.f4815v.add(adView);
        this.f4814u.setAdapter(new C0811e());
        this.f4814u.setOnPageChangeListener(new ViewPager.SimpleOnPageChangeListener() { // from class: com.lenovo.safecenter.notificationintercept.NotificationTabActivity.2
            @Override // android.support.v4.view.ViewPager.SimpleOnPageChangeListener, android.support.v4.view.ViewPager.OnPageChangeListener
            public final void onPageSelected(int position) {
                if (position == 0) {
                    NotificationTabActivity.this.f4795b.setChecked(true);
                } else {
                    NotificationTabActivity.this.f4796c.setChecked(true);
                }
            }
        });
        this.f4797d = (TextView) findViewById(C0415R.id.txt_title);
        this.f4798e = (ImageView) findViewById(C0415R.id.title_back);
        this.f4799f = (ImageView) findViewById(C0415R.id.title_set);
        this.f4799f.setVisibility(0);
        this.f4798e.setOnClickListener(this);
        this.f4799f.setOnClickListener(this);
        this.f4797d.setText(getString(C0415R.string.adv_setting));
        this.f4804k = (TextView) findViewById(C0415R.id.show_root_info);
        this.f4805l = (TextView) findViewById(C0415R.id.show_root_info_select);
        this.f4803j = (ExpandableListView) notiView.findViewById(C0415R.id.expandListView_intercept);
        this.f4813t = (TextView) notiView.findViewById(C0415R.id.text_record_new);
        notiView.findViewById(C0415R.id.layout_record_skip).setOnClickListener(this);
        this.f4811r = (LinearLayout) notiView.findViewById(C0415R.id.empty_linearlayout);
        this.f4809p = (ToggleButton) adView.findViewById(C0415R.id.intercept_app_add_switch);
        this.f4810q = (RelativeLayout) adView.findViewById(C0415R.id.ad_intercept_switch_layout);
        this.f4810q.setOnClickListener(this);
        this.f4809p.setChecked(UrlOptionUtils.isAdOpen(this));
        this.f4812s = (TextView) adView.findViewById(C0415R.id.show_proxy_tip);
        this.f4802i = getPackageManager();
        Utils.isPerfRoot = WflUtils.isRoot();
        if (!Utils.isPerfRoot) {
            this.f4804k.setVisibility(0);
            this.f4804k.setText(getString(C0415R.string.notification_need_root));
            this.f4811r.setVisibility(0);
            this.f4803j.setVisibility(8);
            this.f4813t.setVisibility(8);
        }
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
        if (Utils.isPerfRoot) {
            Intent intent = getIntent();
            if (intent != null && intent.getStringExtra("tab") != null) {
                NotificationManager manager = (NotificationManager) getSystemService(DatabaseTables.LOG_NOTIFICATION);
                manager.cancel(InterceptUtils.NOTIFY_ID);
            }
            m1984a();
            this.f4807n = new C0808b();
            this.f4803j.setAdapter(this.f4807n);
            this.f4803j.setGroupIndicator(null);
            this.f4803j.setOnGroupExpandListener(new ExpandableListView.OnGroupExpandListener() { // from class: com.lenovo.safecenter.notificationintercept.NotificationTabActivity.3
                @Override // android.widget.ExpandableListView.OnGroupExpandListener
                public final void onGroupExpand(int groupPosition) {
                    if (groupPosition == NotificationTabActivity.this.f4806m.size() - 1) {
                        NotificationTabActivity.this.f4803j.setTranscriptMode(2);
                    } else {
                        NotificationTabActivity.this.f4803j.setTranscriptMode(0);
                    }
                    if (NotificationTabActivity.this.f4801h != -1 && NotificationTabActivity.this.f4801h != groupPosition) {
                        NotificationTabActivity.this.f4803j.collapseGroup(NotificationTabActivity.this.f4801h);
                    }
                    NotificationTabActivity.this.f4801h = groupPosition;
                }
            });
            RecordDB db = new RecordDB(this);
            db.closeDatabase();
            int i = PreferenceManager.getDefaultSharedPreferences(this).getInt(InterceptUtils.INTERCEPT_NEW_COUNT, 0);
            if (i > 0) {
                this.f4813t.setVisibility(0);
                if (i < 100) {
                    this.f4813t.setText(i + "");
                } else {
                    this.f4813t.setText("99+");
                }
            } else {
                this.f4813t.setVisibility(8);
            }
            if (isApnProxySet(this)) {
                this.f4812s.setVisibility(0);
            } else {
                this.f4812s.setVisibility(8);
            }
        }
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    /* JADX INFO: renamed from: a */
    private void m1984a() {
        this.f4806m.clear();
        List<C0809c> allowList = new ArrayList<>();
        List<C0809c> forbidList = new ArrayList<>();
        List<PackageInfo> packages = this.f4802i.getInstalledPackages(0);
        PermissionDB permissionDB = new PermissionDB(this);
        List<InterceptPermission> findAll = permissionDB.findAll();
        permissionDB.closeDatabase();
        NotificationDB db = new NotificationDB(this);
        List<NotiAdBean> adBeans = db.findAll();
        db.closeDatabase();
        for (int i = 0; i < findAll.size(); i++) {
            InterceptPermission interceptPermission = findAll.get(i);
            C0809c bean = new C0809c();
            String pkgname = interceptPermission.pkgname;
            String applicationLabel = "";
            try {
                Drawable applicationIcon = this.f4802i.getApplicationIcon(pkgname);
                try {
                    for (PackageInfo packageInfo : packages) {
                        ApplicationInfo ai = packageInfo.applicationInfo;
                        if (pkgname.equals(ai.packageName)) {
                            applicationLabel = ai.loadLabel(this.f4802i).toString();
                            break;
                        }
                    }
                } catch (Exception e) {
                }
                bean.f4826b = applicationIcon;
                bean.f4828d = applicationLabel;
                bean.f4827c = interceptPermission.permission;
                bean.f4829e = interceptPermission.pkgname;
                bean.f4825a = interceptPermission._id;
                boolean pushAd = false;
                for (NotiAdBean nBean : adBeans) {
                    if (nBean.getPkgName().equals(interceptPermission.pkgname)) {
                        pushAd = true;
                        break;
                    }
                }
                bean.f4830f = pushAd;
                if (bean.f4827c == 1) {
                    allowList.add(bean);
                } else {
                    forbidList.add(bean);
                }
            } catch (PackageManager.NameNotFoundException e2) {
                e2.printStackTrace();
            }
        }
        this.f4806m.addAll(allowList);
        this.f4806m.addAll(forbidList);
        if (this.f4806m.size() == 0) {
            this.f4811r.setVisibility(0);
            this.f4803j.setVisibility(8);
        } else {
            this.f4811r.setVisibility(8);
            this.f4803j.setVisibility(0);
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.notificationintercept.NotificationTabActivity$c */
    class C0809c {

        /* JADX INFO: renamed from: a */
        public int f4825a;

        /* JADX INFO: renamed from: b */
        public Drawable f4826b;

        /* JADX INFO: renamed from: c */
        public int f4827c;

        /* JADX INFO: renamed from: d */
        public String f4828d;

        /* JADX INFO: renamed from: e */
        public String f4829e;

        /* JADX INFO: renamed from: f */
        public boolean f4830f;

        C0809c() {
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.notificationintercept.NotificationTabActivity$b */
    class C0808b extends BaseExpandableListAdapter {
        public C0808b() {
            NotificationTabActivity.this.f4800g = (LayoutInflater) NotificationTabActivity.this.getSystemService("layout_inflater");
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
        public final View getChildView(int groupPosition, int childPosition, boolean isLastChild, View convertView, ViewGroup parent) {
            C0807a childHolder;
            if (convertView == null) {
                childHolder = NotificationTabActivity.this.new C0807a();
                convertView = NotificationTabActivity.this.f4800g.inflate(C0415R.layout.notification_expand_child, (ViewGroup) null);
                childHolder.f4820a = (Button) convertView.findViewById(C0415R.id.notification_slide_left);
                childHolder.f4821b = (Button) convertView.findViewById(C0415R.id.notification_slide_center);
                childHolder.f4822c = (Button) convertView.findViewById(C0415R.id.notification_slide_right);
                convertView.setTag(childHolder);
            } else {
                childHolder = (C0807a) convertView.getTag();
            }
            childHolder.f4820a.setOnClickListener(NotificationTabActivity.this);
            childHolder.f4821b.setOnClickListener(NotificationTabActivity.this);
            childHolder.f4822c.setOnClickListener(NotificationTabActivity.this);
            return convertView;
        }

        @Override // android.widget.ExpandableListAdapter
        public final int getChildrenCount(int groupPosition) {
            return 1;
        }

        @Override // android.widget.ExpandableListAdapter
        public final Object getGroup(int groupPosition) {
            return NotificationTabActivity.this.f4806m.get(groupPosition);
        }

        @Override // android.widget.ExpandableListAdapter
        public final int getGroupCount() {
            return NotificationTabActivity.this.f4806m.size();
        }

        @Override // android.widget.ExpandableListAdapter
        public final long getGroupId(int groupPosition) {
            return groupPosition;
        }

        @Override // android.widget.ExpandableListAdapter
        public final View getGroupView(int groupPosition, boolean isExpanded, View convertView, ViewGroup parent) {
            C0810d groupHolder;
            if (convertView == null) {
                groupHolder = NotificationTabActivity.this.new C0810d();
                convertView = NotificationTabActivity.this.f4800g.inflate(C0415R.layout.notification_expand_group_permission, (ViewGroup) null);
                groupHolder.f4832a = (ImageView) convertView.findViewById(C0415R.id.app_icon);
                groupHolder.f4833b = (TextView) convertView.findViewById(C0415R.id.app_label);
                groupHolder.f4834c = (TextView) convertView.findViewById(C0415R.id.notification_summary);
                groupHolder.f4835d = (TextView) convertView.findViewById(C0415R.id.notification_perm);
                groupHolder.f4836e = (ImageView) convertView.findViewById(C0415R.id.notificaiton_perm_expand);
                convertView.setTag(groupHolder);
            } else {
                groupHolder = (C0810d) convertView.getTag();
            }
            C0809c notiBean = (C0809c) NotificationTabActivity.this.f4806m.get(groupPosition);
            if (notiBean != null) {
                synchronized (notiBean) {
                    groupHolder.f4832a.setImageDrawable(notiBean.f4826b);
                    groupHolder.f4833b.setText(notiBean.f4828d);
                    if (notiBean.f4827c == 1) {
                        groupHolder.f4835d.setText(NotificationTabActivity.this.getString(C0415R.string.notification_string_allow));
                        groupHolder.f4835d.setTextColor(NotificationTabActivity.this.getResources().getColor(C0415R.color.green_allow));
                    } else if (notiBean.f4827c == 2) {
                        groupHolder.f4835d.setText(NotificationTabActivity.this.getString(C0415R.string.notification_string_forbid));
                        groupHolder.f4835d.setTextColor(NotificationTabActivity.this.getResources().getColor(C0415R.color.red_forbid));
                    } else {
                        groupHolder.f4835d.setText(NotificationTabActivity.this.getString(C0415R.string.notification_string_notify));
                        groupHolder.f4835d.setTextColor(NotificationTabActivity.this.getResources().getColor(C0415R.color.orange_msg));
                    }
                    if (notiBean.f4830f) {
                        groupHolder.f4834c.setText(NotificationTabActivity.this.getString(C0415R.string.notfication_push_ad));
                    } else {
                        groupHolder.f4834c.setText(NotificationTabActivity.this.getString(C0415R.string.notification_permission_summary));
                    }
                }
                if (NotificationTabActivity.this.f4801h == groupPosition && NotificationTabActivity.this.f4803j.isGroupExpanded(groupPosition)) {
                    groupHolder.f4836e.setImageResource(C0415R.drawable.arrow_up);
                } else {
                    groupHolder.f4836e.setImageResource(C0415R.drawable.arrow_down);
                }
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
    }

    @Override // android.widget.RadioGroup.OnCheckedChangeListener
    public void onCheckedChanged(RadioGroup group, int checkedId) {
        switch (checkedId) {
            case C0415R.id.notification_permission /* 2131297365 */:
                this.f4814u.setCurrentItem(0);
                break;
            case C0415R.id.ad_inline /* 2131297366 */:
                this.f4814u.setCurrentItem(1);
                break;
        }
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.title_back) {
            finish();
        }
        if (!Utils.isPerfRoot) {
            this.f4805l.setVisibility(0);
            this.f4804k.setVisibility(8);
            this.f4805l.setText(getString(C0415R.string.notification_need_root));
            return;
        }
        switch (v.getId()) {
            case C0415R.id.notification_slide_left /* 2131297354 */:
                C0809c permissionBean = this.f4806m.get(this.f4801h);
                InterceptUtils.notificationForbid(this, permissionBean.f4829e);
                this.f4803j.collapseGroup(this.f4801h);
                m1984a();
                this.f4807n.notifyDataSetChanged();
                ScanApplicationInfo.killProcess(this, permissionBean.f4829e);
                break;
            case C0415R.id.notification_slide_center /* 2131297355 */:
                C0809c permissionBean2 = this.f4806m.get(this.f4801h);
                InterceptUtils.notificationAllow(this, permissionBean2.f4829e);
                this.f4803j.collapseGroup(this.f4801h);
                m1984a();
                this.f4807n.notifyDataSetChanged();
                break;
            case C0415R.id.notification_slide_right /* 2131297356 */:
                C0809c permissionBean3 = this.f4806m.get(this.f4801h);
                Intent intent = new Intent("android.intent.action.DELETE", Uri.parse("package:" + permissionBean3.f4829e));
                startActivity(intent);
                break;
            case C0415R.id.ad_intercept_switch_layout /* 2131297368 */:
                boolean mChecked = this.f4809p.isChecked();
                if (!mChecked) {
                    if (this.f4808o == null) {
                        this.f4808o = new ProgressDialog(this);
                        this.f4808o.setMessage(getString(C0415R.string.ads_wait));
                        this.f4808o.setCanceledOnTouchOutside(false);
                        this.f4808o.setCancelable(false);
                        this.f4808o.show();
                    }
                    UrlOptionUtils.replaceURL(this, this.f4816w);
                } else {
                    UrlOptionUtils.resumeURL(this, this.f4816w);
                }
                break;
            case C0415R.id.layout_record_skip /* 2131297378 */:
                Intent intent2 = new Intent(this, (Class<?>) NotificationRecordActivity.class);
                startActivity(intent2);
                break;
            case C0415R.id.title_set /* 2131297710 */:
                startActivity(new Intent(this, (Class<?>) AdManager.class));
                break;
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.notificationintercept.NotificationTabActivity$d */
    class C0810d {

        /* JADX INFO: renamed from: a */
        public ImageView f4832a;

        /* JADX INFO: renamed from: b */
        public TextView f4833b;

        /* JADX INFO: renamed from: c */
        public TextView f4834c;

        /* JADX INFO: renamed from: d */
        public TextView f4835d;

        /* JADX INFO: renamed from: e */
        public ImageView f4836e;

        C0810d() {
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.notificationintercept.NotificationTabActivity$a */
    class C0807a {

        /* JADX INFO: renamed from: a */
        public Button f4820a;

        /* JADX INFO: renamed from: b */
        public Button f4821b;

        /* JADX INFO: renamed from: c */
        public Button f4822c;

        C0807a() {
        }
    }

    public static boolean isApnProxySet(Context context) {
        boolean result = false;
        try {
            Uri defaultApnUri = Uri.parse("content://telephony/carriers/preferapn");
            String[] projection = {"_id", "name", "proxy"};
            Cursor cursor = context.getContentResolver().query(defaultApnUri, projection, null, null, null);
            if (cursor != null) {
                int nameColumn = cursor.getColumnIndex("name");
                int proxyColumn = cursor.getColumnIndex("proxy");
                if (cursor.moveToFirst()) {
                    String name = cursor.getString(nameColumn);
                    String proxy = cursor.getString(proxyColumn);
                    Log.d("yincc", "APN " + name + " has proxy: " + proxy);
                    if (!proxy.matches("\\s*")) {
                        result = true;
                    }
                }
                cursor.close();
            } else {
                Log.d("yincc", "Could not get APN cursor!");
            }
        } catch (Exception e) {
            Log.e("yincc", "Error on get APN!", e);
        }
        return result;
    }

    @Override // android.app.Activity
    public void onBackPressed() {
        super.onBackPressed();
    }
}
