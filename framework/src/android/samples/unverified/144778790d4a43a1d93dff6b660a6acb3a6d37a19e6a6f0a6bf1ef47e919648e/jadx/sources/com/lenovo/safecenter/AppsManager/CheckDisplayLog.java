package com.lenovo.safecenter.AppsManager;

import android.app.ProgressDialog;
import android.content.ContentValues;
import android.content.DialogInterface;
import android.content.pm.PackageManager;
import android.graphics.drawable.Drawable;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
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
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.database.AppUtil;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.mmsutils.PushReceiver;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.support.AppUploadInfo;
import com.lenovo.safecenter.support.HttpUtils;
import com.lenovo.safecenter.support.SafeLog;
import com.lenovo.safecenter.utils.MyUtils;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class CheckDisplayLog extends BaseTitleActivity {

    /* JADX INFO: renamed from: a */
    private TextView f2156a;

    /* JADX INFO: renamed from: b */
    private ArrayList<SafeLog> f2157b;

    /* JADX INFO: renamed from: d */
    private ListView f2159d;

    /* JADX INFO: renamed from: e */
    private PackageManager f2160e;

    /* JADX INFO: renamed from: f */
    private String f2161f;

    /* JADX INFO: renamed from: g */
    private int f2162g;

    /* JADX INFO: renamed from: h */
    private AppDatabase f2163h;

    /* JADX INFO: renamed from: i */
    private BaseAdapter f2164i;

    /* JADX INFO: renamed from: j */
    private ProgressDialog f2165j;

    /* JADX INFO: renamed from: k */
    private int f2166k;

    /* JADX INFO: renamed from: l */
    private Button f2167l;

    /* JADX INFO: renamed from: m */
    private Button f2168m;

    /* JADX INFO: renamed from: n */
    private Button f2169n;

    /* JADX INFO: renamed from: o */
    private Button f2170o;

    /* JADX INFO: renamed from: c */
    private ArrayList<SafeLog> f2158c = new ArrayList<>();

    /* JADX INFO: renamed from: p */
    private Handler f2171p = new Handler() { // from class: com.lenovo.safecenter.AppsManager.CheckDisplayLog.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    CheckDisplayLog.this.setAdapter();
                    break;
                case 1:
                    CheckDisplayLog.this.setAdapter();
                    break;
                case 2:
                    try {
                        if (CheckDisplayLog.this.f2165j != null) {
                            CheckDisplayLog.this.f2165j.dismiss();
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                    if (CheckDisplayLog.this.f2166k == 2) {
                        for (SafeLog log : CheckDisplayLog.this.f2158c) {
                            log.isUpload = 1;
                        }
                        CheckDisplayLog.this.f2163h.updateSafeLogUpload(CheckDisplayLog.this.f2158c, CheckDisplayLog.this.f2161f);
                        Toast.makeText(CheckDisplayLog.this, C0415R.string.upsuccess, 0).show();
                        CheckDisplayLog.this.finish();
                    } else {
                        Toast.makeText(CheckDisplayLog.this, C0415R.string.neterror, 0).show();
                    }
                    break;
                case 3:
                    try {
                        if (CheckDisplayLog.this.f2165j != null) {
                            CheckDisplayLog.this.f2165j.dismiss();
                        }
                    } catch (Exception e2) {
                        e2.printStackTrace();
                    }
                    CheckDisplayLog.this.f2164i.notifyDataSetChanged();
                    CheckDisplayLog.this.f2159d.invalidateViews();
                    break;
                case 4:
                    try {
                        if (CheckDisplayLog.this.f2165j != null) {
                            CheckDisplayLog.this.f2165j.dismiss();
                        }
                    } catch (Exception e3) {
                        e3.printStackTrace();
                    }
                    CheckDisplayLog.this.f2156a.setVisibility(0);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m905a(CheckDisplayLog x0, int x1) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.info).setMessage(x1).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.CheckDisplayLog.2

            /* JADX INFO: renamed from: a */
            final /* synthetic */ boolean f2178a = false;

            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface arg0, int arg1) {
                if (!this.f2178a) {
                    CheckDisplayLog.m918m(CheckDisplayLog.this);
                }
                CheckDisplayLog.this.finish();
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.CheckDisplayLog.13
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface arg0, int arg1) {
            }
        }).show();
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m906a(CheckDisplayLog x0, int x1, final boolean x2) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.info).setMessage(x1).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.CheckDisplayLog.12
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface arg0, int arg1) {
                if (!x2) {
                    CheckDisplayLog.m917l(CheckDisplayLog.this);
                }
                CheckDisplayLog.this.finish();
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.CheckDisplayLog.11
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface arg0, int arg1) {
            }
        }).show();
    }

    /* JADX INFO: renamed from: j */
    static /* synthetic */ boolean m915j(CheckDisplayLog x0) {
        if (x0.f2157b != null) {
            for (int i = 0; i < x0.f2157b.size(); i++) {
                if (x0.f2157b.get(i).logSelected != 0) {
                    return false;
                }
            }
        }
        return true;
    }

    /* JADX INFO: renamed from: k */
    static /* synthetic */ boolean m916k(CheckDisplayLog x0) {
        if (x0.f2157b != null) {
            for (int i = 0; i < x0.f2157b.size(); i++) {
                if (x0.f2157b.get(i).logSelected != 1) {
                    return false;
                }
            }
        }
        return true;
    }

    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.safecenter.AppsManager.CheckDisplayLog$3] */
    /* JADX INFO: renamed from: l */
    static /* synthetic */ void m917l(CheckDisplayLog x0) {
        x0.f2165j = new ProgressDialog(x0);
        x0.f2165j.setProgressStyle(0);
        x0.f2165j.setMessage(x0.getResources().getString(C0415R.string.exec_state));
        x0.f2165j.show();
        new Thread() { // from class: com.lenovo.safecenter.AppsManager.CheckDisplayLog.3
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                AppDatabase appDatabase = new AppDatabase(CheckDisplayLog.this);
                List<SafeLog> selList = new ArrayList<>();
                Iterator it = CheckDisplayLog.this.f2157b.iterator();
                while (it.hasNext()) {
                    SafeLog safelLog = (SafeLog) it.next();
                    if (safelLog.logSelected == 1) {
                        ContentValues values = new ContentValues();
                        values.put("address", safelLog.number);
                        values.put("date", String.valueOf(safelLog.time));
                        values.put(PushReceiver.READ, (Integer) 1);
                        values.put("status", (Integer) (-1));
                        values.put("type", (Integer) 1);
                        values.put(PushReceiver.BODY, safelLog.content);
                        CheckDisplayLog.this.getContentResolver().insert(Uri.parse("content://sms"), values);
                        selList.add(safelLog);
                        it.remove();
                    }
                }
                if (selList.size() > 0) {
                    if (CheckDisplayLog.this.f2162g == 3) {
                        appDatabase.deleteLogItemsforTable(AppDatabase.DB_LOG_HARASS, selList);
                    }
                    Message msg = new Message();
                    msg.what = 3;
                    CheckDisplayLog.this.f2171p.sendMessage(msg);
                }
                if (CheckDisplayLog.this.f2157b.size() == 0) {
                    Message msg2 = new Message();
                    msg2.what = 4;
                    CheckDisplayLog.this.f2171p.sendMessage(msg2);
                }
            }
        }.start();
    }

    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.safecenter.AppsManager.CheckDisplayLog$4] */
    /* JADX INFO: renamed from: m */
    static /* synthetic */ void m918m(CheckDisplayLog x0) {
        x0.f2165j = new ProgressDialog(x0);
        x0.f2165j.setProgressStyle(0);
        x0.f2165j.setMessage(x0.getResources().getString(C0415R.string.exec_state));
        x0.f2165j.show();
        new Thread() { // from class: com.lenovo.safecenter.AppsManager.CheckDisplayLog.4
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                AppDatabase appDatabase = new AppDatabase(CheckDisplayLog.this);
                List<SafeLog> selList = new ArrayList<>();
                Iterator it = CheckDisplayLog.this.f2157b.iterator();
                while (it.hasNext()) {
                    SafeLog safelLog = (SafeLog) it.next();
                    if (safelLog.logSelected == 1) {
                        selList.add(safelLog);
                        it.remove();
                    }
                }
                if (selList.size() > 0) {
                    if (CheckDisplayLog.this.f2162g != 2 && CheckDisplayLog.this.f2162g != 3) {
                        appDatabase.deleteLogItemsforTable(CheckDisplayLog.this.f2161f, selList);
                    } else {
                        appDatabase.deleteLogItemsforTable(AppDatabase.DB_LOG_HARASS, selList);
                    }
                    Message msg = new Message();
                    msg.what = 3;
                    CheckDisplayLog.this.f2171p.sendMessage(msg);
                }
                if (CheckDisplayLog.this.f2157b.size() == 0) {
                    Message msg2 = new Message();
                    msg2.what = 4;
                    CheckDisplayLog.this.f2171p.sendMessage(msg2);
                }
            }
        }.start();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.log_main);
        this.f2170o = (Button) findViewById(C0415R.id.recover_logs);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.clean_log, (Integer) null);
        this.f2156a = (TextView) findViewById(C0415R.id.txt_empty);
        this.f2159d = (ListView) findViewById(C0415R.id.listView_log);
        this.f2167l = (Button) findViewById(C0415R.id.log1_selectall);
        this.f2168m = (Button) findViewById(C0415R.id.log1_cancelall);
        this.f2169n = (Button) findViewById(C0415R.id.delete_logs);
        this.f2160e = getPackageManager();
        this.f2162g = getIntent().getFlags();
        if (this.f2162g == 0) {
            this.f2161f = AppDatabase.DB_LOG_TARIFF;
        }
        if (this.f2162g == 1) {
            this.f2161f = AppDatabase.DB_LOG_PRIVACY;
        }
        if (this.f2162g == 2) {
            this.f2161f = AppDatabase.DB_LOG_HARASS;
        }
        if (this.f2162g == 3) {
            this.f2161f = AppDatabase.DB_LOG_HARASS;
            this.f2170o.setVisibility(0);
        }
        this.f2163h = new AppDatabase(this);
        onBtnClick();
    }

    /* JADX WARN: Type inference failed for: r0v0, types: [com.lenovo.safecenter.AppsManager.CheckDisplayLog$5] */
    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
        new Thread() { // from class: com.lenovo.safecenter.AppsManager.CheckDisplayLog.5
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                if (CheckDisplayLog.this.f2162g != 2) {
                    if (CheckDisplayLog.this.f2162g == 3) {
                        CheckDisplayLog.this.f2157b = CheckDisplayLog.this.f2163h.loadHarassLog("0");
                        Message msg = new Message();
                        msg.what = 1;
                        CheckDisplayLog.this.f2171p.sendMessage(msg);
                        return;
                    }
                    CheckDisplayLog.this.f2157b = CheckDisplayLog.this.f2163h.loadLogs(CheckDisplayLog.this.f2161f, CheckDisplayLog.this.f2160e);
                    Message msg2 = new Message();
                    msg2.what = 0;
                    CheckDisplayLog.this.f2171p.sendMessage(msg2);
                    return;
                }
                CheckDisplayLog.this.f2157b = CheckDisplayLog.this.f2163h.loadHarassLog(DatabaseTables.SYSTEM_MARK);
                Message msg3 = new Message();
                msg3.what = 1;
                CheckDisplayLog.this.f2171p.sendMessage(msg3);
            }
        }.start();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        }
    }

    public void onBtnClick() {
        this.f2159d.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.AppsManager.CheckDisplayLog.6
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                SafeLog log = (SafeLog) CheckDisplayLog.this.f2157b.get(position);
                if (log.logSelected == 1) {
                    log.logSelected = 0;
                } else {
                    log.logSelected = 1;
                }
                CheckDisplayLog.this.f2159d.invalidateViews();
            }
        });
        this.f2167l.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.CheckDisplayLog.7
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                for (int i = 0; i < CheckDisplayLog.this.f2157b.size(); i++) {
                    ((SafeLog) CheckDisplayLog.this.f2157b.get(i)).logSelected = 1;
                    CheckDisplayLog.this.f2159d.invalidateViews();
                }
            }
        });
        this.f2168m.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.CheckDisplayLog.8
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                for (int i = 0; i < CheckDisplayLog.this.f2157b.size(); i++) {
                    ((SafeLog) CheckDisplayLog.this.f2157b.get(i)).logSelected = 0;
                    CheckDisplayLog.this.f2159d.invalidateViews();
                }
            }
        });
        this.f2169n.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.CheckDisplayLog.9
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (CheckDisplayLog.m915j(CheckDisplayLog.this)) {
                    Toast.makeText(CheckDisplayLog.this, C0415R.string.select_log_to_del, 0).show();
                } else if (CheckDisplayLog.m916k(CheckDisplayLog.this)) {
                    CheckDisplayLog.m905a(CheckDisplayLog.this, C0415R.string.del_all_log);
                } else {
                    CheckDisplayLog.m905a(CheckDisplayLog.this, C0415R.string.del_select_log);
                }
            }
        });
        this.f2170o.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.CheckDisplayLog.10
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (CheckDisplayLog.m915j(CheckDisplayLog.this)) {
                    CheckDisplayLog.m906a(CheckDisplayLog.this, C0415R.string.select_log_to_del1, true);
                } else {
                    CheckDisplayLog.m906a(CheckDisplayLog.this, C0415R.string.del_select_log1, false);
                }
            }
        });
    }

    public ArrayList<SafeLog> noSafeLogRepeatList(ArrayList<SafeLog> repeatelist) {
        ArrayList<SafeLog> listnew = new ArrayList<>();
        for (SafeLog con : repeatelist) {
            if (listnew.size() <= 0) {
                listnew.add(con);
            } else {
                boolean isExist = false;
                for (SafeLog log : listnew) {
                    if (con.packageName.equals(log.packageName) && con.permName.equals(log.permName)) {
                        isExist = true;
                        break;
                    }
                }
                if (!isExist) {
                    listnew.add(con);
                }
            }
        }
        return listnew;
    }

    public int reportPermissionLog(ArrayList<SafeLog> logList) {
        StringBuffer type = new StringBuffer();
        StringBuffer stealTime = new StringBuffer();
        StringBuffer appName = new StringBuffer();
        StringBuffer appinstallpath = new StringBuffer();
        StringBuffer appversion = new StringBuffer();
        StringBuffer sha1 = new StringBuffer();
        StringBuffer pkgName = new StringBuffer();
        StringBuffer certmd5 = new StringBuffer();
        for (SafeLog log : logList) {
            String packageName = log.packageName;
            if (packageName == null) {
                pkgName.append("N/A").append(",");
                appinstallpath.append("N/A").append(",");
                appversion.append("N/A").append(",");
                sha1.append("N/A").append(",");
                certmd5.append("N/A").append(",");
            } else {
                AppUploadInfo app = this.f2163h.getAppUploadinfo(packageName);
                appinstallpath.append(app.getPath()).append(",");
                appversion.append(app.getVersion()).append(",");
                sha1.append(app.getPackagesha1()).append(",");
                certmd5.append(app.getCertmd5()).append(",");
                pkgName.append(packageName).append(",");
            }
            type.append(log.type).append(",");
            stealTime.append(MyUtils.formatAllTime(log.time, this)).append(",");
            appName.append(log.appName).append(",");
        }
        int state = HttpUtils.reportaccessunder(this, m903a(type), m903a(stealTime), m903a(appName), m903a(appinstallpath), m903a(appversion), m903a(sha1), m903a(pkgName), m903a(certmd5), "0");
        return state;
    }

    public int reportTariffLog(ArrayList<SafeLog> logList) {
        StringBuffer type = new StringBuffer();
        StringBuffer stealTime = new StringBuffer();
        StringBuffer destination = new StringBuffer();
        StringBuffer stealcontent = new StringBuffer();
        StringBuffer appName = new StringBuffer();
        StringBuffer appinstallpath = new StringBuffer();
        StringBuffer appversion = new StringBuffer();
        StringBuffer sha1 = new StringBuffer();
        StringBuffer pkgName = new StringBuffer();
        StringBuffer certmd5 = new StringBuffer();
        for (SafeLog log : logList) {
            String packageName = log.packageName;
            if (packageName == null) {
                pkgName.append("N/A").append(",");
                appinstallpath.append("N/A").append(",");
                appversion.append("N/A").append(",");
                sha1.append("N/A").append(",");
                certmd5.append("N/A").append(",");
            } else {
                AppUploadInfo app = this.f2163h.getAppUploadinfo(packageName);
                appinstallpath.append(app.getPath()).append(",");
                appversion.append(app.getVersion()).append(",");
                sha1.append(app.getPackagesha1()).append(",");
                certmd5.append(app.getCertmd5()).append(",");
                pkgName.append(packageName).append(",");
            }
            type.append(log.type).append(",");
            stealTime.append(MyUtils.formatAllTime(log.time, this)).append(",");
            destination.append(MyUtils.replaceString(log.number)).append(",");
            stealcontent.append(MyUtils.replaceString(log.content)).append("|");
            appName.append(log.appName).append(",");
        }
        int state = HttpUtils.reportstealfeesoft(this, m903a(type), m903a(stealTime), m903a(stealcontent), m903a(appName), m903a(appinstallpath), m903a(appversion), m903a(destination), m903a(sha1), m903a(pkgName), m903a(certmd5), "0");
        return state;
    }

    public int reportHarssLog(ArrayList<SafeLog> logList) {
        StringBuffer type = new StringBuffer();
        StringBuffer numberlist = new StringBuffer();
        StringBuffer Content = new StringBuffer();
        if (this.f2162g == 2) {
            type.append(DatabaseTables.SYSTEM_MARK).append(",");
        }
        if (this.f2162g == 3) {
            type.append("0").append(",");
        }
        for (SafeLog log : logList) {
            numberlist.append(log.number).append(",");
            Content.append(MyUtils.replaceString(log.content)).append("|");
        }
        int state = HttpUtils.reportHarssLog(this, m903a(numberlist), m903a(type), m903a(Content));
        return state;
    }

    /* JADX INFO: renamed from: a */
    private static String m903a(StringBuffer buffer) {
        return buffer.deleteCharAt(buffer.length() - 1).toString();
    }

    protected void setAdapter() {
        if (this.f2157b.size() == 0) {
            this.f2156a.setVisibility(0);
        } else {
            this.f2156a.setVisibility(8);
        }
        this.f2164i = new CheckLogAdapter();
        this.f2159d.setAdapter((ListAdapter) this.f2164i);
    }

    @Override // android.app.Activity
    public boolean onCreateOptionsMenu(Menu menu) {
        return super.onCreateOptionsMenu(menu);
    }

    @Override // android.app.Activity
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case 0:
                for (int i = 0; i < this.f2157b.size(); i++) {
                    this.f2157b.get(i).logSelected = 1;
                    this.f2159d.invalidateViews();
                }
                break;
            case 1:
                for (int i2 = 0; i2 < this.f2157b.size(); i2++) {
                    this.f2157b.get(i2).logSelected = 0;
                    this.f2159d.invalidateViews();
                }
                break;
        }
        return super.onOptionsItemSelected(item);
    }

    public class CheckLogAdapter extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private LayoutInflater f2188b;

        public CheckLogAdapter() {
            this.f2188b = LayoutInflater.from(CheckDisplayLog.this);
        }

        @Override // android.widget.Adapter
        public int getCount() {
            return CheckDisplayLog.this.f2157b.size();
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
            C0261a holder;
            Drawable appDrawable;
            if (convertView == null) {
                convertView = this.f2188b.inflate(C0415R.layout.check_loglist_item, (ViewGroup) null);
                holder = CheckDisplayLog.this.new C0261a();
                holder.f2189a = (ImageView) convertView.findViewById(C0415R.id.package_icon);
                holder.f2190b = (ImageView) convertView.findViewById(C0415R.id.check_upload_icon);
                holder.f2191c = (TextView) convertView.findViewById(C0415R.id.event_title);
                holder.f2192d = (TextView) convertView.findViewById(C0415R.id.event_action);
                holder.f2193e = (TextView) convertView.findViewById(C0415R.id.event_package);
                holder.f2194f = (TextView) convertView.findViewById(C0415R.id.event_timestamp);
                holder.f2195g = (ImageView) convertView.findViewById(C0415R.id.itemcheck_log);
                convertView.setTag(holder);
            } else {
                holder = (C0261a) convertView.getTag();
            }
            SafeLog safeLog = (SafeLog) CheckDisplayLog.this.f2157b.get(position);
            convertView.setVisibility(0);
            if (CheckDisplayLog.this.f2162g != 2) {
                if (CheckDisplayLog.this.f2162g == 3) {
                    holder.f2189a.setVisibility(8);
                    holder.f2190b.setVisibility(8);
                    holder.f2193e.setText(safeLog.number);
                    holder.f2194f.setText(AppDatabase.formatTime(safeLog.time, CheckDisplayLog.this));
                    holder.f2191c.setText(safeLog.content);
                    holder.f2192d.setVisibility(8);
                    if (safeLog.logSelected == 1) {
                        holder.f2195g.setBackgroundResource(C0415R.drawable.ic_checkbox_select);
                    } else {
                        holder.f2195g.setBackgroundResource(C0415R.drawable.ic_checkbox);
                    }
                } else {
                    if (safeLog.permName.equals("android.permission.SEND_SMS") && safeLog.number != null) {
                        holder.f2191c.setText(CheckDisplayLog.this.getString(C0415R.string.sms_to) + safeLog.number);
                    } else {
                        holder.f2191c.setText(AppUtil.getDescriptionByPid(CheckDisplayLog.this, Integer.valueOf(safeLog.type).intValue()));
                    }
                    String str = safeLog.action == 0 ? CheckDisplayLog.this.getString(C0415R.string.allow) : CheckDisplayLog.this.getString(C0415R.string.forbid);
                    holder.f2192d.setTextColor(safeLog.action == 0 ? -16711936 : -65536);
                    holder.f2190b.setVisibility(8);
                    holder.f2192d.setText(str);
                    holder.f2193e.setText(safeLog.appName);
                    holder.f2194f.setText(AppDatabase.formatTime(safeLog.time, CheckDisplayLog.this));
                    if (safeLog.packageName != null && !"".equals(safeLog.packageName)) {
                        try {
                            appDrawable = CheckDisplayLog.this.f2160e.getApplicationIcon(safeLog.packageName);
                        } catch (PackageManager.NameNotFoundException e) {
                            e.printStackTrace();
                            appDrawable = CheckDisplayLog.this.getResources().getDrawable(C0415R.drawable.icon3);
                        }
                    } else {
                        appDrawable = CheckDisplayLog.this.getResources().getDrawable(C0415R.drawable.icon3);
                    }
                    holder.f2189a.setImageDrawable(appDrawable);
                    if (safeLog.logSelected == 1) {
                        holder.f2195g.setBackgroundResource(C0415R.drawable.ic_checkbox_select);
                    } else {
                        holder.f2195g.setBackgroundResource(C0415R.drawable.ic_checkbox);
                    }
                }
            } else {
                holder.f2189a.setVisibility(8);
                holder.f2190b.setVisibility(8);
                holder.f2193e.setText(C0415R.string.harass_phone);
                holder.f2194f.setText(AppDatabase.formatTime(safeLog.time, CheckDisplayLog.this));
                holder.f2191c.setText(safeLog.number);
                holder.f2192d.setVisibility(8);
                if (safeLog.logSelected == 1) {
                    holder.f2195g.setBackgroundResource(C0415R.drawable.ic_checkbox_select);
                } else {
                    holder.f2195g.setBackgroundResource(C0415R.drawable.ic_checkbox);
                }
            }
            return convertView;
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.AppsManager.CheckDisplayLog$a */
    class C0261a {

        /* JADX INFO: renamed from: a */
        ImageView f2189a;

        /* JADX INFO: renamed from: b */
        ImageView f2190b;

        /* JADX INFO: renamed from: c */
        TextView f2191c;

        /* JADX INFO: renamed from: d */
        TextView f2192d;

        /* JADX INFO: renamed from: e */
        TextView f2193e;

        /* JADX INFO: renamed from: f */
        TextView f2194f;

        /* JADX INFO: renamed from: g */
        ImageView f2195g;

        C0261a() {
        }
    }
}
