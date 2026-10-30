package com.lenovo.safecenter.AppsManager;

import android.app.Activity;
import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.MotionEvent;
import android.view.View;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.RelativeLayout;
import android.widget.TextView;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.adapter.NewLogsAdapter;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.support.SafeLog;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class PermissionControlNew extends Activity implements View.OnClickListener {

    /* JADX INFO: renamed from: a */
    private List<SafeLog> f2325a;

    /* JADX INFO: renamed from: b */
    private TextView f2326b;

    /* JADX INFO: renamed from: c */
    private TextView f2327c;

    /* JADX INFO: renamed from: d */
    private TextView f2328d;

    /* JADX INFO: renamed from: e */
    private TextView f2329e;

    /* JADX INFO: renamed from: f */
    private TextView f2330f;

    /* JADX INFO: renamed from: g */
    private ListView f2331g;

    /* JADX INFO: renamed from: h */
    private ImageView f2332h;

    /* JADX INFO: renamed from: i */
    private LinearLayout f2333i;

    /* JADX INFO: renamed from: j */
    private RelativeLayout f2334j;

    /* JADX INFO: renamed from: k */
    private RelativeLayout f2335k;

    /* JADX INFO: renamed from: l */
    private RelativeLayout f2336l;

    /* JADX INFO: renamed from: m */
    private RelativeLayout f2337m;

    /* JADX INFO: renamed from: o */
    private boolean f2339o;

    /* JADX INFO: renamed from: n */
    private int f2338n = 0;

    /* JADX INFO: renamed from: p */
    private Handler f2340p = new Handler() { // from class: com.lenovo.safecenter.AppsManager.PermissionControlNew.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    PermissionControlNew.this.f2330f.setText(String.format(PermissionControlNew.this.getString(C0415R.string.trust_app_num), Integer.valueOf(PermissionControlNew.this.f2338n)));
                    if (PermissionControlNew.this.f2325a.size() == 0) {
                        PermissionControlNew.this.f2327c.setVisibility(0);
                        PermissionControlNew.this.f2334j.setVisibility(8);
                    } else {
                        PermissionControlNew.this.f2327c.setVisibility(8);
                        PermissionControlNew.this.f2334j.setVisibility(0);
                        PermissionControlNew.this.f2331g.setAdapter((ListAdapter) new NewLogsAdapter(PermissionControlNew.this, PermissionControlNew.this.f2325a));
                    }
                    break;
                case 1:
                    PermissionControlNew.this.f2330f.setText(String.format(PermissionControlNew.this.getString(C0415R.string.trust_app_num), Integer.valueOf(PermissionControlNew.this.f2338n)));
                    break;
            }
        }
    };

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.permissioncontrol);
        this.f2339o = WflUtils.isRoot();
        this.f2328d = (TextView) findViewById(C0415R.id.txt_what);
        this.f2329e = (TextView) findViewById(C0415R.id.txt_answer);
        this.f2330f = (TextView) findViewById(C0415R.id.txt_trust);
        this.f2330f.setOnTouchListener(new View.OnTouchListener() { // from class: com.lenovo.safecenter.AppsManager.PermissionControlNew.2
            @Override // android.view.View.OnTouchListener
            public final boolean onTouch(View v, MotionEvent event) {
                if (event.getAction() == 1) {
                    PermissionControlNew.this.f2330f.setTextColor(Color.parseColor("#29b1ef"));
                    return false;
                }
                if (event.getAction() == 0) {
                    PermissionControlNew.this.f2330f.setTextColor(Color.parseColor("#6600ff"));
                    return false;
                }
                if (event.getAction() == 3 || event.getAction() == 4) {
                    PermissionControlNew.this.f2330f.setTextColor(Color.parseColor("#29b1ef"));
                    return false;
                }
                return false;
            }
        });
        this.f2326b = (TextView) findViewById(C0415R.id.txt_title);
        this.f2326b.setText(C0415R.string.permission_control);
        this.f2327c = (TextView) findViewById(C0415R.id.txt_empty);
        this.f2331g = (ListView) findViewById(C0415R.id.listView);
        this.f2331g.setEnabled(false);
        this.f2332h = (ImageView) findViewById(C0415R.id.title_back);
        this.f2333i = (LinearLayout) findViewById(C0415R.id.more_logs);
        this.f2334j = (RelativeLayout) findViewById(C0415R.id.logs_layout);
        this.f2335k = (RelativeLayout) findViewById(C0415R.id.privacy_layout);
        this.f2336l = (RelativeLayout) findViewById(C0415R.id.location_layout);
        this.f2337m = (RelativeLayout) findViewById(C0415R.id.record_layout);
        this.f2336l.setVisibility(0);
        this.f2336l.setOnClickListener(this);
        this.f2332h.setOnClickListener(this);
        this.f2330f.setOnClickListener(this);
        this.f2333i.setOnClickListener(this);
        this.f2335k.setOnClickListener(this);
        this.f2337m.setOnClickListener(this);
    }

    /* JADX WARN: Type inference failed for: r0v6, types: [com.lenovo.safecenter.AppsManager.PermissionControlNew$3] */
    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
        if (Const.mDefaultPreference.getBoolean("privacy_first", true)) {
            this.f2328d.setText(C0415R.string.what_privacy);
            this.f2329e.setVisibility(0);
            this.f2330f.setVisibility(8);
            findViewById(C0415R.id.trust_arrow).setVisibility(8);
            Const.mDefaultPreference.edit().putBoolean("privacy_first", false).commit();
        } else {
            this.f2328d.setText(C0415R.string.privacy_protect);
            this.f2329e.setVisibility(8);
            this.f2330f.setVisibility(0);
            findViewById(C0415R.id.trust_arrow).setVisibility(0);
        }
        new Thread() { // from class: com.lenovo.safecenter.AppsManager.PermissionControlNew.3
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                AppDatabase database = new AppDatabase(PermissionControlNew.this);
                if (Const.getScreenHeight() > 800) {
                    PermissionControlNew.this.f2325a = database.getTopThreeLogs(AppDatabase.DB_LOG_PRIVACY, 4);
                } else {
                    PermissionControlNew.this.f2325a = database.getTopThreeLogs(AppDatabase.DB_LOG_PRIVACY, 3);
                }
                if (PermissionControlNew.this.f2339o) {
                    PermissionControlNew.this.f2338n = database.getTrustedApps(AppDatabase.PERM_TYPE_PRIVCY);
                }
                PermissionControlNew.this.f2340p.sendMessage(PermissionControlNew.this.f2340p.obtainMessage(0));
            }
        }.start();
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.privacy_layout /* 2131296772 */:
                Intent it1 = new Intent(this, (Class<?>) ApplicationList.class);
                it1.putExtra("permType", AppDatabase.PERM_TYPE_PRIVCY);
                startActivityForResult(it1, 0);
                break;
            case C0415R.id.location_layout /* 2131296778 */:
                Intent it2 = new Intent(this, (Class<?>) ApplicationList.class);
                it2.putExtra("permType", "location");
                startActivityForResult(it2, 0);
                break;
            case C0415R.id.more_logs /* 2131296887 */:
                Intent it0 = new Intent(this, (Class<?>) DisplayLog.class);
                it0.putExtra("from", DatabaseTables.SYSTEM_MARK);
                startActivityForResult(it0, 1);
                break;
            case C0415R.id.record_layout /* 2131297147 */:
                Intent it3 = new Intent(this, (Class<?>) ApplicationList.class);
                it3.putExtra("permType", AppDatabase.PERM_TYPE_DEVICE);
                startActivityForResult(it3, 0);
                break;
            case C0415R.id.txt_trust /* 2131297407 */:
                Intent it = new Intent(this, (Class<?>) AppsManager.class);
                it.putExtra("permType", AppDatabase.PERM_TYPE_PRIVCY);
                startActivityForResult(it, 0);
                break;
            case C0415R.id.title_back /* 2131297709 */:
                finish();
                break;
        }
    }

    @Override // android.app.Activity
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        switch (resultCode) {
            case 1:
                this.f2325a.clear();
                this.f2340p.sendMessage(this.f2340p.obtainMessage(0));
                break;
        }
    }
}
