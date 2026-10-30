package com.lenovo.performancecenter.performance;

import android.R;
import android.app.Activity;
import android.content.Context;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.PopupWindow;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.performancecenter.coreui.util.RootPassage;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/* JADX INFO: loaded from: classes.dex */
public class BootSpeedActivity extends Activity implements View.OnClickListener, AdapterView.OnItemClickListener {
    public static final String TAG = "BootSpeedActivity";

    /* JADX INFO: renamed from: a */
    private LinearLayout f1651a;

    /* JADX INFO: renamed from: b */
    private TextView f1652b;

    /* JADX INFO: renamed from: c */
    private PopupWindow f1653c;

    /* JADX INFO: renamed from: d */
    private TextView f1654d;

    /* JADX INFO: renamed from: e */
    private LinearLayout f1655e;

    /* JADX INFO: renamed from: f */
    private ListView f1656f;

    /* JADX INFO: renamed from: g */
    private C0163a f1657g;

    /* JADX INFO: renamed from: h */
    private Context f1658h;

    /* JADX INFO: renamed from: i */
    private DataLayerManageBoot f1659i;

    /* JADX INFO: renamed from: j */
    private ArrayList<DataLayerManagerAccelerate.C0173a> f1660j;

    /* JADX INFO: renamed from: m */
    private HashMap<String, int[]> f1663m;

    /* JADX INFO: renamed from: n */
    private boolean f1664n;

    /* JADX INFO: renamed from: o */
    private C0164b f1665o;

    /* JADX INFO: renamed from: k */
    private int f1661k = 0;

    /* JADX INFO: renamed from: l */
    private int f1662l = 0;

    /* JADX INFO: renamed from: p */
    private Handler f1666p = new Handler() { // from class: com.lenovo.performancecenter.performance.BootSpeedActivity.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    BootSpeedActivity.this.f1654d.setText(BootSpeedActivity.this.f1658h.getString(C0415R.string.boot_speed_total_autorun_entries, Integer.valueOf(BootSpeedActivity.this.f1661k), Integer.valueOf(BootSpeedActivity.this.f1661k - BootSpeedActivity.this.f1662l)));
                    BootSpeedActivity.this.f1655e.setVisibility(8);
                    BootSpeedActivity.this.f1657g.notifyDataSetChanged();
                    break;
                case 2:
                    BootSpeedActivity.this.f1654d.setText(BootSpeedActivity.this.f1658h.getString(C0415R.string.boot_speed_total_autorun_entries, Integer.valueOf(BootSpeedActivity.this.f1661k), Integer.valueOf(BootSpeedActivity.this.f1661k - BootSpeedActivity.this.f1662l)));
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: k */
    static /* synthetic */ PopupWindow m599k(BootSpeedActivity x0) {
        x0.f1653c = null;
        return null;
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(1);
        setContentView(C0415R.layout.rf_perf_autorun_manage);
        findViewById(C0415R.id.title_back).setOnClickListener(this);
        ((TextView) findViewById(C0415R.id.txt_title)).setText(C0415R.string.kjjs);
        findViewById(C0415R.id.title_set).setVisibility(0);
        findViewById(C0415R.id.title_set).setOnClickListener(this);
        this.f1651a = (LinearLayout) findViewById(C0415R.id.layout_no_rooted);
        this.f1651a.setVisibility(WflUtils.isRoot() ? 8 : 0);
        this.f1652b = (TextView) findViewById(C0415R.id.textview_no_rooted);
        this.f1654d = (TextView) findViewById(C0415R.id.total_entries);
        this.f1655e = (LinearLayout) findViewById(C0415R.id.progress_bar);
        this.f1656f = (ListView) findViewById(C0415R.id.listView);
        this.f1659i = new DataLayerManageBoot();
        this.f1660j = new ArrayList<>();
        this.f1663m = new HashMap<>();
        this.f1658h = this;
        this.f1655e.setVisibility(0);
        this.f1657g = new C0163a();
        this.f1656f.setAdapter((ListAdapter) this.f1657g);
        this.f1656f.setOnItemClickListener(this);
        if (this.f1665o == null) {
            this.f1664n = true;
            this.f1665o = new C0164b();
            this.f1665o.start();
        }
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.BootSpeedActivity$b */
    class C0164b extends Thread {
        C0164b() {
        }

        @Override // java.lang.Thread, java.lang.Runnable
        public final void run() {
            if (BootSpeedActivity.this.f1664n) {
                BootSpeedActivity.this.f1660j = BootSpeedActivity.this.f1659i.getBootItem(BootSpeedActivity.this.f1658h);
                BootSpeedActivity.this.f1662l = BootSpeedActivity.this.f1659i.getBootAllowCount();
                BootSpeedActivity.this.f1661k = BootSpeedActivity.this.f1660j.size();
                Message msg = BootSpeedActivity.this.f1666p.obtainMessage(1);
                BootSpeedActivity.this.f1666p.sendMessage(msg);
            }
        }
    }

    @Override // android.app.Activity
    public void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        if (!this.f1665o.isInterrupted()) {
            this.f1664n = false;
            this.f1665o.interrupt();
            this.f1665o = null;
        }
        super.onDestroy();
    }

    @Override // android.widget.AdapterView.OnItemClickListener
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        Log.i(TAG, System.currentTimeMillis() + " onItemClick position == " + position);
        if (!WflUtils.isRoot()) {
            m593e();
            return;
        }
        DataLayerManagerAccelerate.C0173a item = this.f1660j.get(position);
        if (item.f1718f == 2) {
            item.f1718f = 1;
            this.f1662l++;
        } else {
            item.f1718f = 2;
            this.f1662l--;
        }
        this.f1657g.notifyDataSetChanged();
        this.f1666p.sendEmptyMessage(2);
        String[] componentName = {item.f1715c, item.f1717e};
        RootPassage.setComponentAbleBoot(this.f1658h, componentName, item.f1718f);
        this.f1663m.put(item.f1715c, new int[]{item.f1718f});
        Log.i(TAG, System.currentTimeMillis() + " onItemClick pkgName == " + componentName[0] + " clsName == " + componentName[1] + " toState == " + item.f1718f);
        TrackEvent.reportDisableBootStartApp(item.f1715c);
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.popwindow_onekey_all_forbid /* 2131297472 */:
                Log.i(TAG, System.currentTimeMillis() + " ALL FORBID start");
                this.f1653c.dismiss();
                if (!WflUtils.isRoot()) {
                    m593e();
                } else {
                    m587b();
                    Log.i(TAG, System.currentTimeMillis() + " ALL FORBID old");
                }
                break;
            case C0415R.id.popwindow_onekey_all_allow /* 2131297473 */:
                Log.i(TAG, System.currentTimeMillis() + " ALL ALLOW start");
                this.f1653c.dismiss();
                if (!WflUtils.isRoot()) {
                    m593e();
                } else {
                    m583a();
                    Log.i(TAG, System.currentTimeMillis() + " ALL ALLOW end");
                }
                break;
            case C0415R.id.popwindow_onekey_speed_up /* 2131297474 */:
                Log.i(TAG, System.currentTimeMillis() + " onClick");
                this.f1653c.dismiss();
                if (!WflUtils.isRoot()) {
                    m593e();
                } else {
                    m589c();
                    TrackEvent.reportClickOneKeyEndTask();
                }
                break;
            case C0415R.id.title_back /* 2131297709 */:
                m591d();
                break;
            case C0415R.id.title_set /* 2131297710 */:
                if (this.f1653c == null) {
                    View viewInflate = LayoutInflater.from(this).inflate(C0415R.layout.rf_perf_bootspeed_poplistview, (ViewGroup) null);
                    ((LinearLayout) viewInflate.findViewById(C0415R.id.popwindow_onekey_all_allow)).setOnClickListener(this);
                    ((LinearLayout) viewInflate.findViewById(C0415R.id.popwindow_onekey_all_forbid)).setOnClickListener(this);
                    ((LinearLayout) viewInflate.findViewById(C0415R.id.popwindow_onekey_speed_up)).setOnClickListener(this);
                    this.f1653c = new PopupWindow(viewInflate, -2, -2, true);
                    this.f1653c.setAnimationStyle(C0415R.style.PopupAnimation);
                    this.f1653c.setBackgroundDrawable(new BitmapDrawable());
                    this.f1653c.setFocusable(true);
                    this.f1653c.setOutsideTouchable(true);
                    this.f1653c.showAsDropDown(findViewById(C0415R.id.title_bar), Const.getScreenWidth(), 0);
                    this.f1653c.update();
                    this.f1653c.setOnDismissListener(new PopupWindow.OnDismissListener() { // from class: com.lenovo.performancecenter.performance.BootSpeedActivity.2
                        @Override // android.widget.PopupWindow.OnDismissListener
                        public final void onDismiss() {
                            BootSpeedActivity.m599k(BootSpeedActivity.this);
                        }
                    });
                } else if (this.f1653c.isShowing()) {
                    this.f1653c.dismiss();
                }
                break;
        }
    }

    /* JADX INFO: renamed from: a */
    private void m583a() {
        HashMap<String[], int[]> map = new HashMap<>();
        for (DataLayerManagerAccelerate.C0173a appItem : this.f1660j) {
            if (appItem.f1718f == 2) {
                appItem.f1718f = 1;
                String[] componentName = {appItem.f1715c, appItem.f1717e};
                map.put(componentName, new int[]{appItem.f1718f});
                this.f1663m.put(appItem.f1715c, new int[]{appItem.f1718f});
            }
        }
        this.f1657g.notifyDataSetChanged();
        Log.i(TAG, System.currentTimeMillis() + " ALL ALLOW invalidateViews()");
        this.f1662l = this.f1660j.size();
        this.f1666p.sendEmptyMessage(2);
        if (map.size() != 0) {
            RootPassage.setComponentAbleBoot(this.f1658h, map);
        }
        Toast.makeText(this.f1658h, getString(C0415R.string.boot_already_setting_all_allow), 0).show();
    }

    /* JADX INFO: renamed from: b */
    private void m587b() {
        HashMap<String[], int[]> map = new HashMap<>();
        for (DataLayerManagerAccelerate.C0173a appItem : this.f1660j) {
            if (appItem.f1718f == 1) {
                appItem.f1718f = 2;
                String[] componentName = {appItem.f1715c, appItem.f1717e};
                map.put(componentName, new int[]{appItem.f1718f});
                this.f1663m.put(appItem.f1715c, new int[]{appItem.f1718f});
            }
        }
        this.f1657g.notifyDataSetChanged();
        Log.i(TAG, System.currentTimeMillis() + " ALL FORBID invalidateViews()");
        this.f1662l = 0;
        this.f1666p.sendEmptyMessage(2);
        if (map.size() != 0) {
            RootPassage.setComponentAbleBoot(this.f1658h, map);
        }
        Toast.makeText(this.f1658h, getString(C0415R.string.boot_already_setting_all_forbid), 0).show();
    }

    /* JADX INFO: renamed from: c */
    private void m589c() {
        HashMap<String[], int[]> bootMap = this.f1659i.getBootMap(this.f1658h, this.f1660j);
        int needChangeToForbid = this.f1659i.getNeedChangeToForbid();
        int needChangeToAllow = this.f1659i.getNeedChangeToAllow();
        if (needChangeToForbid == 0 && needChangeToAllow == 0) {
            Toast.makeText(this.f1658h, C0415R.string.boot_is_optimal_configuration, 0).show();
            return;
        }
        HashMap<String[], int[]> map = new HashMap<>();
        ArrayList<String> listNeedChangeToForbid = new ArrayList<>();
        ArrayList<String> listNeedChangeToAlow = new ArrayList<>();
        for (Map.Entry<String[], int[]> entry : bootMap.entrySet()) {
            if (entry.getValue()[0] != -1) {
                if (entry.getValue()[0] == 1) {
                    listNeedChangeToAlow.add(entry.getKey()[0]);
                } else if (entry.getValue()[0] == 2) {
                    listNeedChangeToForbid.add(entry.getKey()[0]);
                }
            }
        }
        for (DataLayerManagerAccelerate.C0173a item : this.f1660j) {
            if (listNeedChangeToAlow.contains(item.f1715c)) {
                item.f1718f = 1;
                this.f1662l++;
                String[] componentName = {item.f1715c, item.f1717e};
                map.put(componentName, new int[]{item.f1718f});
                this.f1663m.put(item.f1715c, new int[]{item.f1718f});
            }
            if (listNeedChangeToForbid.contains(item.f1715c)) {
                item.f1718f = 2;
                this.f1662l--;
                String[] componentName2 = {item.f1715c, item.f1717e};
                map.put(componentName2, new int[]{item.f1718f});
                this.f1663m.put(item.f1715c, new int[]{item.f1718f});
            }
        }
        this.f1657g.notifyDataSetChanged();
        this.f1666p.sendEmptyMessage(2);
        Toast.makeText(this.f1658h, getString(C0415R.string.boot_speed_expert_one_key_result, new Object[]{Integer.valueOf(needChangeToForbid), Integer.valueOf(needChangeToAllow)}), 0).show();
        if (map.size() != 0) {
            RootPassage.setComponentAbleBoot(this.f1658h, map);
        }
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.BootSpeedActivity$c */
    static class C0165c {

        /* JADX INFO: renamed from: a */
        private ImageView f1672a;

        /* JADX INFO: renamed from: b */
        private TextView f1673b;

        /* JADX INFO: renamed from: c */
        private TextView f1674c;

        /* JADX INFO: renamed from: d */
        private ImageView f1675d;

        C0165c() {
        }
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.BootSpeedActivity$a */
    private class C0163a extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private LayoutInflater f1670b;

        public C0163a() {
            this.f1670b = (LayoutInflater) BootSpeedActivity.this.f1658h.getSystemService("layout_inflater");
        }

        @Override // android.widget.Adapter
        public final int getCount() {
            return BootSpeedActivity.this.f1660j.size();
        }

        @Override // android.widget.Adapter
        public final Object getItem(int position) {
            return BootSpeedActivity.this.f1660j.get(position);
        }

        @Override // android.widget.Adapter
        public final long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public final View getView(int position, View convertView, ViewGroup parent) {
            C0165c holder;
            Drawable drawable;
            Log.i(BootSpeedActivity.TAG, System.currentTimeMillis() + " getView");
            if (convertView == null) {
                convertView = this.f1670b.inflate(C0415R.layout.rf_perf_bootspeed_item, (ViewGroup) null);
                holder = new C0165c();
                holder.f1672a = (ImageView) convertView.findViewById(C0415R.id.app_icon);
                holder.f1673b = (TextView) convertView.findViewById(C0415R.id.app_name);
                holder.f1674c = (TextView) convertView.findViewById(C0415R.id.app_suggest);
                holder.f1675d = (ImageView) convertView.findViewById(C0415R.id.itemcheck);
                convertView.setTag(holder);
            } else {
                holder = (C0165c) convertView.getTag();
            }
            DataLayerManagerAccelerate.C0173a item = (DataLayerManagerAccelerate.C0173a) BootSpeedActivity.this.f1660j.get(position);
            if (item != null) {
                ImageView imageView = holder.f1672a;
                if (item.f1713a == null) {
                    drawable = BootSpeedActivity.this.f1658h.getResources().getDrawable(R.drawable.sym_def_app_icon);
                } else {
                    drawable = item.f1713a;
                }
                imageView.setImageDrawable(drawable);
                holder.f1673b.setText(item.f1714b);
                holder.f1674c.setVisibility(0);
                if (item.f1719g == 1) {
                    holder.f1674c.setText(C0415R.string.boot_speed_suggest_enable);
                    holder.f1674c.setTextColor(BootSpeedActivity.this.f1658h.getResources().getColor(C0415R.color.green_allow));
                } else if (item.f1719g == 2) {
                    holder.f1674c.setText(C0415R.string.boot_speed_suggest_disable);
                    holder.f1674c.setTextColor(BootSpeedActivity.this.f1658h.getResources().getColor(C0415R.color.red_forbid));
                } else {
                    holder.f1674c.setText("");
                }
                if (item.f1718f == 2) {
                    holder.f1675d.setImageResource(C0415R.drawable.perm_deny);
                } else {
                    holder.f1675d.setImageResource(C0415R.drawable.perm_grant);
                }
            }
            return convertView;
        }
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == 4) {
            m591d();
        }
        return super.onKeyDown(keyCode, event);
    }

    /* JADX INFO: renamed from: d */
    private void m591d() {
        for (Map.Entry<String, int[]> entry : this.f1663m.entrySet()) {
            Log.i(TAG, entry.getKey() + " " + entry.getValue()[0]);
        }
        this.f1659i.updatePkgsInBootDB2(this.f1658h, this.f1663m);
        if (this.f1653c != null) {
            this.f1653c.dismiss();
        }
        finish();
    }

    /* JADX INFO: renamed from: e */
    private void m593e() {
        this.f1651a.setBackgroundResource(C0415R.drawable.show_root_info_select);
        this.f1652b.setTextColor(this.f1658h.getResources().getColor(C0415R.color.yellow_884906));
    }
}
