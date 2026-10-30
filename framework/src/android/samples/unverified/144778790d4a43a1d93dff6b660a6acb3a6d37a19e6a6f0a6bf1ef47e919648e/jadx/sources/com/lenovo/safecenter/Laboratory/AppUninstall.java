package com.lenovo.safecenter.Laboratory;

import android.app.Activity;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.p001pm.IPackageDeleteObserver;
import android.content.p001pm.IPackageMoveObserver;
import android.content.pm.ApplicationInfo;
import android.content.pm.IPackageManager;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.os.Message;
import android.os.Parcel;
import android.os.RemoteException;
import android.os.ServiceManager;
import android.os.StatFs;
import android.text.format.Formatter;
import android.util.Log;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.performancecenter.service.object.PolicyAppInfo;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppUtil;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.support.AppInfo;
import com.lenovo.safecenter.support.CMDHelper;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import org.apache.commons.httpclient.cookie.CookieSpec;

/* JADX INFO: loaded from: classes.dex */
public class AppUninstall extends Activity {
    public static final int UNINSTALL_COMPLETE = 10;
    public static String[] md5s = {"5ABDF9B649C2B8AC6026B88313C3C332", "EBAA529685AAE3A1D299AC15F7710AEA", "B78A0EE7E80045B4F9A0C425703D0CA4", "388CF508552BC50ED26A8715D33312BA", "6B861FD954CE40EE4C560992DCCB35F0", "49FF2FEA9A214DCC2F7EF229488B1A54", "56B44C8B44C3A4064FE0667DC91E01AA", "CEA942B20A36347B3BF793BFF50F737D"};

    /* JADX INFO: renamed from: a */
    private ListView f2454a;

    /* JADX INFO: renamed from: b */
    private List<AppInfo> f2455b;

    /* JADX INFO: renamed from: c */
    private List<AppInfo> f2456c;

    /* JADX INFO: renamed from: d */
    private List<AppInfo> f2457d;

    /* JADX INFO: renamed from: e */
    private List<AppInfo> f2458e;

    /* JADX INFO: renamed from: f */
    private C0324b f2459f;

    /* JADX INFO: renamed from: g */
    private ProgressBar f2460g;

    /* JADX INFO: renamed from: h */
    private ProgressBar f2461h;

    /* JADX INFO: renamed from: i */
    private TextView f2462i;

    /* JADX INFO: renamed from: j */
    private TextView f2463j;

    /* JADX INFO: renamed from: k */
    private TextView f2464k;

    /* JADX INFO: renamed from: l */
    private TextView f2465l;

    /* JADX INFO: renamed from: m */
    private CustomDialog.Builder f2466m;

    /* JADX INFO: renamed from: n */
    private RelativeLayout f2467n;

    /* JADX INFO: renamed from: o */
    private RelativeLayout f2468o;

    /* JADX INFO: renamed from: p */
    private Map<String, String> f2469p;

    /* JADX INFO: renamed from: q */
    private PackageDeleteObserver f2470q;

    /* JADX INFO: renamed from: r */
    private BinderC0325c f2471r;

    /* JADX INFO: renamed from: s */
    private String f2472s;
    public List safePkgs;

    /* JADX INFO: renamed from: t */
    private C0323a f2473t;

    /* JADX INFO: renamed from: v */
    private Context f2475v;

    /* JADX INFO: renamed from: u */
    private boolean f2474u = false;

    /* JADX INFO: renamed from: w */
    private Handler f2476w = new Handler() { // from class: com.lenovo.safecenter.Laboratory.AppUninstall.2
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    AppUninstall.this.f2459f = AppUninstall.this.new C0324b();
                    AppUninstall.this.f2454a.setAdapter((ListAdapter) AppUninstall.this.f2459f);
                    AppUninstall.this.f2468o.setVisibility(8);
                    AppUninstall.this.f2454a.setVisibility(0);
                    break;
                case 2:
                    AppUninstall.this.f2472s = ((AppInfo) msg.obj).name;
                    AppUninstall.m1146a(AppUninstall.this, msg.arg1, (AppInfo) msg.obj, msg.arg2);
                    break;
                case 4:
                    if (AppUninstall.this.f2461h != null) {
                        if (AppUninstall.this.f2466m.getDialog() != null) {
                            AppUninstall.this.f2466m.getDialog().dismiss();
                        }
                        int result = msg.arg1;
                        if (result == 1) {
                            Toast.makeText(AppUninstall.this, AppUninstall.this.f2472s + AppUninstall.this.getString(C0415R.string.movetosd_succeeded), 1).show();
                        } else {
                            Toast.makeText(AppUninstall.this, AppUninstall.this.f2472s + AppUninstall.this.getString(C0415R.string.movetosd_failed), 1).show();
                        }
                    }
                    break;
                case 5:
                    Uri packageURI = Uri.parse("package:" + ((String) msg.obj));
                    Intent uninstallIntent = new Intent("android.intent.action.DELETE", packageURI);
                    AppUninstall.this.startActivity(uninstallIntent);
                    break;
                case 10:
                    Log.i("ydp", "delthird over :" + msg.arg1);
                    if (AppUninstall.this.f2461h != null) {
                        if (AppUninstall.this.f2466m.getDialog() != null) {
                            AppUninstall.this.f2466m.getDialog().dismiss();
                        }
                        switch (msg.arg1) {
                            case -2:
                                Toast.makeText(AppUninstall.this, AppUninstall.this.f2472s + AppUninstall.this.getString(C0415R.string.uninstall) + AppUninstall.this.getString(C0415R.string.fail), 1).show();
                                break;
                            case -1:
                                Toast.makeText(AppUninstall.this, AppUninstall.this.f2472s + AppUninstall.this.getString(C0415R.string.uninstall) + AppUninstall.this.getString(C0415R.string.fail), 1).show();
                                break;
                            case 1:
                                Toast.makeText(AppUninstall.this, AppUninstall.this.f2472s + AppUninstall.this.getString(C0415R.string.uninstall) + AppUninstall.this.getString(C0415R.string.success), 1).show();
                                break;
                        }
                    }
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1146a(AppUninstall x0, int x1, final AppInfo x2, int x3) {
        String string;
        String string2;
        if (x1 == 1) {
            new CustomDialog.Builder(x0).setTitle(C0415R.string.info).setMessage(C0415R.string.uninstall_system_sure).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.AppUninstall.4
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface dialog, int which) {
                    LayoutInflater li = LayoutInflater.from(AppUninstall.this);
                    View v = li.inflate(C0415R.layout.appmag_dialog, (ViewGroup) null);
                    AppUninstall.this.f2467n = (RelativeLayout) v.findViewById(C0415R.id.appmag_rl2);
                    AppUninstall.this.f2464k = (TextView) v.findViewById(C0415R.id.appmag_text_succeeded);
                    AppUninstall.this.f2461h = (ProgressBar) v.findViewById(C0415R.id.appmag_dialog_progressBar);
                    AppUninstall.this.f2463j = (TextView) v.findViewById(C0415R.id.appmag_dialog_textView_appname);
                    AppUninstall.this.f2463j.setText(AppUninstall.this.getString(C0415R.string.uninstalling) + x2.name);
                    AppUninstall.this.f2466m = new CustomDialog.Builder(AppUninstall.this).setTitle(C0415R.string.uninstall_more).setContentView(v).setNeutralButton(C0415R.string.ok, (DialogInterface.OnClickListener) null);
                    CustomDialog cd = AppUninstall.this.f2466m.show();
                    AppUninstall.this.f2466m.setButtonVisible(false);
                    cd.setOnDismissListener(new DialogInterface.OnDismissListener() { // from class: com.lenovo.safecenter.Laboratory.AppUninstall.4.1
                        @Override // android.content.DialogInterface.OnDismissListener
                        public final void onDismiss(DialogInterface dialog2) {
                            AppUninstall.this.getLauncherApp();
                        }
                    });
                    cd.setOnKeyListener(new DialogInterface.OnKeyListener() { // from class: com.lenovo.safecenter.Laboratory.AppUninstall.4.2
                        @Override // android.content.DialogInterface.OnKeyListener
                        public final boolean onKey(DialogInterface dialog2, int keyCode, KeyEvent event) {
                            if (keyCode != 4) {
                                return false;
                            }
                            Log.i("ydp", "dialog back " + event.getRepeatCount());
                            return true;
                        }
                    });
                    CMDHelper.delApp(AppUninstall.this, x2.packageName, AppUninstall.this.f2476w);
                }
            }).setNegativeButton(C0415R.string.cancel, (DialogInterface.OnClickListener) null).show();
            return;
        }
        if (x1 == 2) {
            View viewInflate = LayoutInflater.from(x0).inflate(C0415R.layout.appmag_dialog, (ViewGroup) null);
            x0.f2467n = (RelativeLayout) viewInflate.findViewById(C0415R.id.appmag_rl2);
            x0.f2464k = (TextView) viewInflate.findViewById(C0415R.id.appmag_text_succeeded);
            x0.f2461h = (ProgressBar) viewInflate.findViewById(C0415R.id.appmag_dialog_progressBar);
            x0.f2463j = (TextView) viewInflate.findViewById(C0415R.id.appmag_dialog_textView_appname);
            if (x3 == 1) {
                string = x0.getString(C0415R.string.uninstalling);
                string2 = x0.getString(C0415R.string.uninstall_more);
            } else {
                string = x0.getString(C0415R.string.movetosd_);
                string2 = x0.getString(C0415R.string.appmovetosd);
            }
            x0.f2463j.setText(string + x2.name);
            x0.f2466m = new CustomDialog.Builder(x0).setTitle(string2).setContentView(viewInflate).setNeutralButton(C0415R.string.ok, (DialogInterface.OnClickListener) null);
            CustomDialog customDialogShow = x0.f2466m.show();
            x0.f2466m.setButtonVisible(false);
            customDialogShow.setOnDismissListener(new DialogInterface.OnDismissListener() { // from class: com.lenovo.safecenter.Laboratory.AppUninstall.5
                @Override // android.content.DialogInterface.OnDismissListener
                public final void onDismiss(DialogInterface dialog) {
                    AppUninstall.this.getLauncherApp();
                }
            });
            customDialogShow.setOnKeyListener(new DialogInterface.OnKeyListener() { // from class: com.lenovo.safecenter.Laboratory.AppUninstall.6
                @Override // android.content.DialogInterface.OnKeyListener
                public final boolean onKey(DialogInterface dialog, int keyCode, KeyEvent event) {
                    if (keyCode != 4) {
                        return false;
                    }
                    Log.i("ydp", "dialog back " + event.getRepeatCount());
                    return true;
                }
            });
        }
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.appmanager_layout);
        TextView topBar = (TextView) findViewById(C0415R.id.txt_title);
        topBar.setText(C0415R.string.uninstlal_title);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.AppUninstall.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                AppUninstall.this.finish();
            }
        });
        this.f2475v = this;
        this.f2474u = TrafficStatsService.nacServerIsExist() || Const.isObtainRoot();
        this.f2465l = (TextView) findViewById(C0415R.id.show_root_info);
        this.f2454a = (ListView) findViewById(C0415R.id.appmag_listView);
        this.f2460g = (ProgressBar) findViewById(C0415R.id.appmag_progressBar);
        this.f2462i = (TextView) findViewById(C0415R.id.appmag_textview);
        this.f2468o = (RelativeLayout) findViewById(C0415R.id.loadrl);
        if (this.f2474u) {
            this.f2465l.setVisibility(8);
        }
        this.f2473t = new C0323a();
        C0323a c0323a = this.f2473t;
        try {
            c0323a.f2488b = c0323a.f2487a.getInstallLocation();
        } catch (RemoteException e) {
            Log.e("CanBeOnSdCardChecker", "Is Package Manager running?");
        }
        this.f2469p = new HashMap();
        this.f2457d = new ArrayList();
        this.f2455b = new ArrayList();
        this.f2456c = new ArrayList();
        this.f2458e = new ArrayList();
        this.safePkgs = new ArrayList();
        this.safePkgs.add("com.android.settings");
        this.safePkgs.add("com.android.camera");
        this.safePkgs.add("com.android.contacts");
        this.safePkgs.add("com.android.phone");
        this.safePkgs.add("com.android.mms");
        this.safePkgs.add("com.android.music");
        this.safePkgs.add(SafeHomePageBroadcast.BROWSER_PKG);
        this.safePkgs.add("com.android.gallery3d");
        this.safePkgs.add("com.android.deskclock");
        this.safePkgs.add("com.android.filebrowser");
        this.safePkgs.add(TrafficStatsService.PACKAGE_NAME);
        this.f2470q = new PackageDeleteObserver();
        this.f2471r = new BinderC0325c();
    }

    /* JADX WARN: Type inference failed for: r0v13, types: [com.lenovo.safecenter.Laboratory.AppUninstall$3] */
    public void getLauncherApp() {
        StatFs statFs = new StatFs(Environment.getDataDirectory().getPath());
        float blockSize = statFs.getBlockSize();
        float blockCount = statFs.getBlockCount();
        float availableBlocks = statFs.getAvailableBlocks();
        this.f2460g.setMax(100);
        int i = (int) ((availableBlocks / blockCount) * 100.0f);
        Log.i("ydp", "" + i);
        Log.i("ydp", "" + (availableBlocks / blockCount));
        this.f2460g.setProgress(100 - i);
        String fileSize = Formatter.formatFileSize(this, (long) (blockCount * blockSize));
        Log.d("ydp", fileSize);
        String fileSize2 = Formatter.formatFileSize(this, (long) ((blockCount - availableBlocks) * blockSize));
        Log.d("ydp", fileSize2);
        this.f2462i.setText(getString(C0415R.string.storage_space) + fileSize2 + CookieSpec.PATH_DELIM + fileSize);
        this.f2454a.setVisibility(8);
        this.f2468o.setVisibility(0);
        new Thread() { // from class: com.lenovo.safecenter.Laboratory.AppUninstall.3
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                AppUninstall.this.f2456c.clear();
                AppUninstall.this.f2455b.clear();
                AppUninstall.this.f2469p.clear();
                PackageManager pm = AppUninstall.this.getPackageManager();
                Intent it = new Intent("android.intent.action.MAIN");
                it.addCategory("android.intent.category.LAUNCHER");
                List<ResolveInfo> resolveList = pm.queryIntentActivities(it, 0);
                for (ResolveInfo resolveInfo : resolveList) {
                    try {
                        if (!resolveInfo.activityInfo.packageName.equals(AppUninstall.this.getPackageName()) && !AppUninstall.this.f2469p.containsKey(resolveInfo.activityInfo.packageName)) {
                            AppUninstall.this.f2469p.put(resolveInfo.activityInfo.packageName, "");
                            ApplicationInfo appInfo = pm.getApplicationInfo(resolveInfo.activityInfo.packageName, 0);
                            Log.i("ydp", "pkg:" + resolveInfo.activityInfo.packageName);
                            if (AppUninstall.this.isThirdpartApp(appInfo)) {
                                if ((appInfo.installLocation == 0 || appInfo.installLocation == 2) && (appInfo.flags & 262144) == 0) {
                                    C0323a c0323a = AppUninstall.this.f2473t;
                                    if ((appInfo.flags & 262144) == 0 && (appInfo.flags & 536870912) == 0 && (appInfo.flags & 1) == 0 && appInfo.installLocation != 2 && appInfo.installLocation != 0 && appInfo.installLocation == -1) {
                                        int i2 = c0323a.f2488b;
                                    }
                                }
                                AppUninstall.this.f2456c.add(new AppInfo(appInfo.uid, appInfo.loadLabel(AppUninstall.this.getPackageManager()).toString(), 0, appInfo.packageName, appInfo, "third", "", false));
                            } else {
                                int i3 = 0;
                                while (i3 < AppUninstall.md5s.length) {
                                    if (!AppUtil.getCretMD5(AppUninstall.this, appInfo.packageName).equals(AppUninstall.md5s[i3])) {
                                        i3++;
                                    } else {
                                        Log.i("ydp", "lenovo App:" + appInfo.loadLabel(pm).toString());
                                        break;
                                    }
                                }
                                Log.i("ydp", "i:" + i3);
                                if (i3 == AppUninstall.md5s.length && AppUninstall.this.safePkgs.indexOf(appInfo.packageName) == -1) {
                                    AppUninstall.this.f2455b.add(new AppInfo(appInfo.uid, appInfo.loadLabel(AppUninstall.this.getPackageManager()).toString(), 0, appInfo.packageName, appInfo, PolicyAppInfo.APP_TYPE_SYSTEM, ""));
                                }
                            }
                        }
                    } catch (PackageManager.NameNotFoundException e) {
                        e.printStackTrace();
                    }
                }
                AppUninstall.this.f2457d.clear();
                AppUninstall.this.f2457d.add(null);
                AppUninstall.this.f2457d.addAll(AppUninstall.this.f2455b);
                AppUninstall.this.f2457d.add(null);
                AppUninstall.this.f2457d.addAll(AppUninstall.this.f2456c);
                try {
                    Thread.sleep(1500L);
                } catch (InterruptedException e2) {
                    e2.printStackTrace();
                }
                AppUninstall.this.f2476w.sendEmptyMessage(1);
            }
        }.start();
    }

    public boolean isThirdpartApp(ApplicationInfo appInfo) {
        if ((appInfo.flags & 128) == 0 && (appInfo.flags & 1) != 0) {
            return false;
        }
        return true;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.Laboratory.AppUninstall$b */
    class C0324b extends BaseAdapter {

        /* JADX INFO: renamed from: a */
        PackageManager f2490a;

        /* JADX INFO: renamed from: b */
        LayoutInflater f2491b;

        /* JADX INFO: renamed from: c */
        C0326d f2492c;

        /* JADX INFO: renamed from: e */
        private List<Boolean> f2494e = new ArrayList();

        public C0324b() {
            this.f2490a = AppUninstall.this.getPackageManager();
            this.f2491b = LayoutInflater.from(AppUninstall.this);
            for (int i = 0; i < AppUninstall.this.f2457d.size(); i++) {
                this.f2494e.add(false);
            }
        }

        @Override // android.widget.Adapter
        public final int getCount() {
            Log.i("ydp", "appsize" + AppUninstall.this.f2457d.size());
            return AppUninstall.this.f2457d.size();
        }

        @Override // android.widget.Adapter
        public final Object getItem(int position) {
            return AppUninstall.this.f2457d.get(position);
        }

        @Override // android.widget.Adapter
        public final long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public final View getView(final int position, View convertView, ViewGroup parent) {
            if (this.f2491b == null) {
                this.f2491b = LayoutInflater.from(AppUninstall.this);
            }
            if (AppUninstall.this.f2457d.get(position) == null) {
                TextView tv = (TextView) this.f2491b.inflate(C0415R.layout.appitem_text, (ViewGroup) null);
                if (position == 0) {
                    tv.setText(AppUninstall.this.getString(C0415R.string.system_app) + "(" + AppUninstall.this.f2455b.size() + ")");
                    return tv;
                }
                tv.setText(AppUninstall.this.getString(C0415R.string.other_app) + "(" + AppUninstall.this.f2456c.size() + ")");
                return tv;
            }
            this.f2492c = null;
            if (convertView == null) {
                convertView = this.f2491b.inflate(C0415R.layout.appitem, (ViewGroup) null);
                this.f2492c = AppUninstall.this.new C0326d();
                this.f2492c.f2502a = (ImageView) convertView.findViewById(C0415R.id.appmag_icon);
                this.f2492c.f2503b = (TextView) convertView.findViewById(C0415R.id.appname);
                this.f2492c.f2504c = (TextView) convertView.findViewById(C0415R.id.appmag_button);
                this.f2492c.f2505d = (TextView) convertView.findViewById(C0415R.id.appmove_button);
                convertView.setTag(this.f2492c);
            } else {
                this.f2492c = (C0326d) convertView.getTag();
                if (this.f2492c == null) {
                    convertView = this.f2491b.inflate(C0415R.layout.appitem, (ViewGroup) null);
                    this.f2492c = AppUninstall.this.new C0326d();
                    this.f2492c.f2502a = (ImageView) convertView.findViewById(C0415R.id.appmag_icon);
                    this.f2492c.f2503b = (TextView) convertView.findViewById(C0415R.id.appname);
                    this.f2492c.f2504c = (TextView) convertView.findViewById(C0415R.id.appmag_button);
                    this.f2492c.f2505d = (TextView) convertView.findViewById(C0415R.id.appmove_button);
                    convertView.setTag(this.f2492c);
                }
            }
            this.f2492c.f2503b.setText(((AppInfo) AppUninstall.this.f2457d.get(position)).name);
            this.f2492c.f2502a.setImageDrawable(((AppInfo) AppUninstall.this.f2457d.get(position)).applicationInfo.loadIcon(this.f2490a));
            if (!((AppInfo) AppUninstall.this.f2457d.get(position)).appType.equals("third")) {
                if (((AppInfo) AppUninstall.this.f2457d.get(position)).appType.equals(PolicyAppInfo.APP_TYPE_SYSTEM)) {
                    this.f2492c.f2504c.setText(C0415R.string.powerfull_uninstall);
                    this.f2494e.add(position, false);
                }
            } else {
                this.f2492c.f2504c.setText(C0415R.string.uninstall);
                if (((AppInfo) AppUninstall.this.f2457d.get(position)).movetoSDcrad) {
                    this.f2494e.add(position, true);
                } else {
                    this.f2494e.add(position, false);
                }
            }
            this.f2492c.f2505d.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.AppUninstall.b.1
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    AppUninstall.showInstalledAppDetails(AppUninstall.this, ((AppInfo) AppUninstall.this.f2457d.get(position)).packageName);
                }
            });
            if (this.f2494e.get(position).booleanValue()) {
                this.f2492c.f2505d.setText(C0415R.string.movetosd);
                this.f2492c.f2505d.setVisibility(0);
            } else {
                this.f2492c.f2505d.setVisibility(8);
            }
            this.f2492c.f2504c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.AppUninstall.b.2
                /* JADX WARN: Type inference failed for: r0v21, types: [com.lenovo.safecenter.Laboratory.AppUninstall$b$2$2] */
                /* JADX WARN: Type inference failed for: r0v22, types: [com.lenovo.safecenter.Laboratory.AppUninstall$b$2$1] */
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    if (!((AppInfo) AppUninstall.this.f2457d.get(position)).appType.equals("third")) {
                        if (((AppInfo) AppUninstall.this.f2457d.get(position)).appType.equals(PolicyAppInfo.APP_TYPE_SYSTEM)) {
                            if (!AppUninstall.this.f2474u) {
                                Toast.makeText(AppUninstall.this.f2475v, C0415R.string.not_root_uninstall_toast, 1).show();
                                return;
                            } else {
                                new Thread() { // from class: com.lenovo.safecenter.Laboratory.AppUninstall.b.2.2
                                    @Override // java.lang.Thread, java.lang.Runnable
                                    public final void run() {
                                        Message msg = new Message();
                                        msg.obj = AppUninstall.this.f2457d.get(position);
                                        msg.arg1 = 1;
                                        msg.what = 2;
                                        msg.arg2 = 1;
                                        AppUninstall.this.f2476w.sendMessage(msg);
                                    }
                                }.start();
                                return;
                            }
                        }
                        return;
                    }
                    new Thread() { // from class: com.lenovo.safecenter.Laboratory.AppUninstall.b.2.1
                        @Override // java.lang.Thread, java.lang.Runnable
                        public final void run() {
                            if (AppUninstall.this.f2474u) {
                                CMDHelper.unInstall(AppUninstall.this.f2475v, ((AppInfo) AppUninstall.this.f2457d.get(position)).packageName, AppUninstall.this.f2476w);
                                Message msg = new Message();
                                msg.obj = AppUninstall.this.f2457d.get(position);
                                msg.arg1 = 2;
                                msg.what = 2;
                                msg.arg2 = 1;
                                AppUninstall.this.f2476w.sendMessage(msg);
                                return;
                            }
                            AppUninstall.this.f2476w.sendMessage(AppUninstall.this.f2476w.obtainMessage(5, ((AppInfo) AppUninstall.this.f2457d.get(position)).packageName));
                        }
                    }.start();
                }
            });
            return convertView;
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.Laboratory.AppUninstall$d */
    class C0326d {

        /* JADX INFO: renamed from: a */
        ImageView f2502a;

        /* JADX INFO: renamed from: b */
        TextView f2503b;

        /* JADX INFO: renamed from: c */
        TextView f2504c;

        /* JADX INFO: renamed from: d */
        TextView f2505d;

        C0326d() {
        }
    }

    public static void showInstalledAppDetails(Context context, String packageName) {
        Intent intent = new Intent();
        int apiLevel = Build.VERSION.SDK_INT;
        if (apiLevel >= 9) {
            intent.setAction("android.settings.APPLICATION_DETAILS_SETTINGS");
            Uri uri = Uri.fromParts("package", packageName, null);
            intent.setData(uri);
        } else {
            String appPkgName = apiLevel == 8 ? "pkg" : "com.android.settings.ApplicationPkgName";
            intent.setAction("android.intent.action.VIEW");
            intent.setClassName("com.android.settings", "com.android.settings.InstalledAppDetails");
            intent.putExtra(appPkgName, packageName);
        }
        context.startActivity(intent);
    }

    public class PackageDeleteObserver extends IPackageDeleteObserver.Stub {
        public PackageDeleteObserver() {
        }

        public void packageDeleted(String packageName, int returnCode) {
            Message msg = AppUninstall.this.f2476w.obtainMessage(10);
            msg.arg1 = returnCode;
            msg.obj = packageName;
            AppUninstall.this.f2476w.sendMessage(msg);
        }

        @Override // android.content.p001pm.IPackageDeleteObserver
        public void packageDeleted(boolean succeeded) {
            Message msg = AppUninstall.this.f2476w.obtainMessage(10);
            msg.arg1 = succeeded ? 1 : 0;
            AppUninstall.this.f2476w.sendMessage(msg);
        }

        @Override // android.content.pm.IPackageDeleteObserver.Stub, android.os.Binder
        public boolean onTransact(int arg0, Parcel arg1, Parcel arg2, int arg3) throws RemoteException {
            try {
                return super.onTransact(arg0, arg1, arg2, arg3);
            } catch (Exception e) {
                e.printStackTrace();
                return false;
            }
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.Laboratory.AppUninstall$c */
    class BinderC0325c extends IPackageMoveObserver.Stub {
        BinderC0325c() {
        }

        @Override // android.content.p001pm.IPackageMoveObserver
        public final void packageMoved(String packageName, int returnCode) throws RemoteException {
            Message msg = AppUninstall.this.f2476w.obtainMessage(4);
            msg.arg1 = returnCode;
            AppUninstall.this.f2476w.sendMessage(msg);
        }
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
    }

    @Override // android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        getLauncherApp();
        super.onResume();
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        if (this.f2466m != null && this.f2466m.getDialog() != null && this.f2466m.getDialog().isShowing()) {
            this.f2466m.getDialog().dismiss();
        }
        super.onPause();
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.Laboratory.AppUninstall$a */
    final class C0323a {

        /* JADX INFO: renamed from: a */
        final IPackageManager f2487a = IPackageManager.Stub.asInterface(ServiceManager.getService("package"));

        /* JADX INFO: renamed from: b */
        int f2488b;

        C0323a() {
        }
    }
}
