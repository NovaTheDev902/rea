package com.lenovo.safecenter.floatwindow.view;

import android.app.ActivityManager;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.FrameLayout;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.ListAdapter;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.floatwindow.model.ResolveModel;
import com.lenovo.safecenter.floatwindow.model.ViewHolder;
import com.lenovo.safecenter.net.cache.NetConstant;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.utils.Const;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class RecentTaskView extends FrameLayout {

    /* JADX INFO: renamed from: a */
    private GridView f3693a;

    /* JADX INFO: renamed from: b */
    private RecentTaskAdapter f3694b;

    /* JADX INFO: renamed from: c */
    private List<ResolveModel> f3695c;
    public Context context;

    /* JADX INFO: renamed from: d */
    private ResolveModel f3696d;

    /* JADX INFO: renamed from: e */
    private String f3697e;

    public RecentTaskView(Context _context) {
        super(_context);
        this.f3697e = RecentTaskView.class.getSimpleName();
        this.context = _context;
        this.f3695c = new ArrayList();
        inflate(this.context, C0415R.layout.assist_task_view, this);
        this.f3693a = (GridView) findViewById(C0415R.id.float_grid);
        this.f3694b = new RecentTaskAdapter(_context, getTaskList(this.f3695c));
        this.f3693a.setAdapter((ListAdapter) this.f3694b);
        this.f3693a.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.floatwindow.view.RecentTaskView.1
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                FloatWindow.instanceFloatWindow.delFloatWindow();
                Intent intent = new Intent();
                intent.setAction("android.intent.action.MAIN");
                intent.addCategory("android.intent.category.LAUNCHER");
                intent.setComponent(new ComponentName(((ResolveModel) RecentTaskView.this.f3695c.get(position)).getPackagename(), ((ResolveModel) RecentTaskView.this.f3695c.get(position)).getMainname()));
                intent.setFlags(268435456);
                RecentTaskView.this.context.startActivity(intent);
            }
        });
    }

    public RecentTaskView(Context _context, AttributeSet attrs) {
        super(_context, attrs);
    }

    public List<ResolveModel> getTaskList(List<ResolveModel> lists) {
        Context context = this.context;
        Context context2 = this.context;
        ActivityManager am = (ActivityManager) context.getSystemService("activity");
        PackageManager pm = this.context.getPackageManager();
        try {
            ActivityInfo homeInfo = new Intent("android.intent.action.MAIN").addCategory("android.intent.category.HOME").resolveActivityInfo(pm, 0);
            List<ActivityManager.RecentTaskInfo> recentTaskList = am.getRecentTasks(64, 2);
            for (ActivityManager.RecentTaskInfo recentTaskInfo : recentTaskList) {
                Intent intentRecentTask = new Intent(recentTaskInfo.baseIntent);
                if (recentTaskInfo.origActivity != null) {
                    intentRecentTask.setComponent(recentTaskInfo.origActivity);
                }
                if (homeInfo == null || !homeInfo.packageName.equals(recentTaskInfo.baseIntent.getComponent().getPackageName()) || !homeInfo.name.equals(recentTaskInfo.baseIntent.getComponent().getClassName())) {
                    List<ResolveInfo> apps = pm.queryIntentActivities(intentRecentTask, 0);
                    if (apps != null && apps.size() != 0) {
                        ResolveInfo resolveInfo = apps.iterator().next();
                        if (resolveInfo != null && !Const.PACKAGENAME_KID_MODE.equals(resolveInfo.activityInfo.packageName) && !Const.PACKAGENAME_APP_LOCK.equals(resolveInfo.activityInfo.packageName) && !NetConstant.TRAFFIC_PLUGIN.equals(resolveInfo.activityInfo.packageName)) {
                            this.f3696d = new ResolveModel();
                            if ("com.lenovo.safecenter.floatwindow.shortcut.ShortcutActivity".equals(resolveInfo.activityInfo.name)) {
                                this.f3696d.setName(this.context.getString(C0415R.string.safecenter));
                                this.f3696d.setMainname("com.lenovo.safecenter.MainTab.SplashActivity");
                                this.f3696d.setDrawable(getResources().getDrawable(C0415R.drawable.icon));
                                this.f3696d.setPackagename(TrafficStatsService.PACKAGE_NAME);
                            } else if (resolveInfo.activityInfo.exported) {
                                this.f3696d.setDrawable(resolveInfo.activityInfo.loadIcon(pm));
                                this.f3696d.setName(resolveInfo.activityInfo.loadLabel(pm).toString());
                                this.f3696d.setPackagename(resolveInfo.activityInfo.packageName);
                                this.f3696d.setMainname(resolveInfo.activityInfo.name);
                            } else {
                                Intent exportedTask = new Intent();
                                exportedTask.setAction("android.intent.action.MAIN");
                                exportedTask.addCategory("android.intent.category.LAUNCHER");
                                exportedTask.setPackage(resolveInfo.activityInfo.packageName);
                                List<ResolveInfo> exportedapps = pm.queryIntentActivities(exportedTask, 0);
                                if (exportedapps != null && exportedapps.size() != 0) {
                                    ResolveInfo exportedInfo = exportedapps.iterator().next();
                                    this.f3696d.setDrawable(exportedInfo.activityInfo.loadIcon(pm));
                                    this.f3696d.setName(exportedInfo.activityInfo.loadLabel(pm).toString());
                                    this.f3696d.setPackagename(exportedInfo.activityInfo.packageName);
                                    this.f3696d.setMainname(exportedInfo.activityInfo.name);
                                }
                            }
                        }
                        boolean containFlag = false;
                        if (lists.size() == 0) {
                            lists.add(this.f3696d);
                        } else {
                            for (int i = 0; i < lists.size(); i++) {
                                if (lists.get(i).getPackagename().equals(this.f3696d.getPackagename()) && lists.get(i).getName().equals(this.f3696d.getName())) {
                                    containFlag = true;
                                    break;
                                }
                            }
                            if (!containFlag) {
                                lists.add(this.f3696d);
                            }
                        }
                    }
                }
            }
        } catch (SecurityException se) {
            se.printStackTrace();
        }
        return lists;
    }

    @Override // android.view.ViewGroup, android.view.View
    protected void onAttachedToWindow() {
        super.onAttachedToWindow();
    }

    @Override // android.view.ViewGroup, android.view.View
    protected void onDetachedFromWindow() {
        super.onDetachedFromWindow();
    }

    protected class RecentTaskAdapter extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private List<ResolveModel> f3700b;

        /* JADX INFO: renamed from: c */
        private ViewHolder f3701c;

        /* JADX INFO: renamed from: d */
        private LayoutInflater f3702d;

        RecentTaskAdapter(Context ctx, List<ResolveModel> lists) {
            this.f3700b = lists;
            this.f3702d = LayoutInflater.from(ctx);
        }

        @Override // android.widget.Adapter
        public int getCount() {
            return this.f3700b.size();
        }

        @Override // android.widget.Adapter
        public Object getItem(int position) {
            return Integer.valueOf(position);
        }

        @Override // android.widget.Adapter
        public long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            View view = convertView;
            if (view == null) {
                this.f3701c = new ViewHolder();
                view = this.f3702d.inflate(C0415R.layout.assist_task_item, (ViewGroup) null);
                this.f3701c.img = (ImageView) view.findViewById(C0415R.id.item_icon);
                this.f3701c.text = (TextView) view.findViewById(C0415R.id.item_label);
                view.setTag(this.f3701c);
            } else {
                this.f3701c = (ViewHolder) view.getTag();
            }
            this.f3701c.img.setBackgroundDrawable(this.f3700b.get(position).getDrawable());
            this.f3701c.text.setText(this.f3700b.get(position).getName());
            return view;
        }
    }
}
