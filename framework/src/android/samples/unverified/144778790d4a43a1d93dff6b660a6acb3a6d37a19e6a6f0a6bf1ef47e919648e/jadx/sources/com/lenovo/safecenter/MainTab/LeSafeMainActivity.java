package com.lenovo.safecenter.MainTab;

import android.app.Activity;
import android.app.ActivityManager;
import android.app.ActivityManagerNative;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.graphics.drawable.BitmapDrawable;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.os.RemoteException;
import android.preference.PreferenceManager;
import android.telephony.TelephonyManager;
import android.text.SpannableString;
import android.text.TextUtils;
import android.text.style.AbsoluteSizeSpan;
import android.text.style.ForegroundColorSpan;
import android.util.Log;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.view.inputmethod.InputMethodManager;
import android.widget.EditText;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.PopupWindow;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.AppsManager.SettingsActivity;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.HealthCheck.HealthCheckupActivity;
import com.lenovo.safecenter.Laboratory.MyProcessObserver;
import com.lenovo.safecenter.adapter.DaoImpl;
import com.lenovo.safecenter.adapter.DbAdapter;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.encoders.UrlBase64;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.support.CMDHelper;
import com.lenovo.safecenter.support.SafeCenterService;
import com.lenovo.safecenter.support.SecurityService;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.DialogUtil;
import com.lenovo.safecenter.utils.LeSafeObservable;
import com.lenovo.safecenter.utils.Panel;
import com.lenovo.safecenter.utils.PwdUtil;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import com.lenovo.safecenter.utils.homepageUtil.DrawerAdapter;
import com.lenovo.safecenter.utils.homepageUtil.FourBoxAdapter;
import com.lenovo.safecenter.utils.httpApi.HttpApiAsyncTask;
import com.lenovo.safecenter.utils.httpApi.LeSafeAPI;
import com.lenovo.safecenter.utils.update.LeSafeUpdate;
import com.lenovo.safecenter.utils.update.LeSafeUpdateInfo;
import com.lenovo.safecenter.utils.updateLab.AutoUpdateLabManager;
import com.lenovo.safecenter.utils.updateLab.UpdateLabManager;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.UnsupportedEncodingException;
import java.util.HashMap;
import java.util.List;
import java.util.Observable;
import java.util.Observer;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import org.apache.commons.httpclient.HttpClient;
import org.apache.commons.httpclient.HttpException;
import org.apache.commons.httpclient.methods.PostMethod;

/* JADX INFO: loaded from: classes.dex */
public class LeSafeMainActivity extends Activity implements View.OnClickListener, HttpApiAsyncTask.ApiRequestListener, Observer {

    /* JADX INFO: renamed from: a */
    private ImageView f2741a;

    /* JADX INFO: renamed from: b */
    private ImageView f2742b;

    /* JADX INFO: renamed from: c */
    private LeSafeObservable f2743c;

    /* JADX INFO: renamed from: d */
    private Context f2744d;

    /* JADX INFO: renamed from: e */
    private String f2745e;

    /* JADX INFO: renamed from: f */
    private boolean f2746f;

    /* JADX INFO: renamed from: g */
    private boolean f2747g;

    /* JADX INFO: renamed from: h */
    private PopupWindow f2748h;

    /* JADX INFO: renamed from: i */
    private Panel f2749i;

    /* JADX INFO: renamed from: j */
    private SharedPreferences f2750j;

    /* JADX INFO: renamed from: k */
    private CustomDialog f2751k;

    /* JADX INFO: renamed from: l */
    private ProgressDialog f2752l;

    /* JADX INFO: renamed from: m */
    private LeSafeUpdate f2753m;

    /* JADX INFO: renamed from: n */
    private Handler f2754n = new Handler() { // from class: com.lenovo.safecenter.MainTab.LeSafeMainActivity.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    InputMethodManager m = (InputMethodManager) LeSafeMainActivity.this.getSystemService("input_method");
                    m.toggleSoftInput(0, 2);
                    break;
                case 2:
                    if (LeSafeMainActivity.this.f2752l != null) {
                        LeSafeMainActivity.this.f2752l.dismiss();
                        LeSafeMainActivity.m1250b(LeSafeMainActivity.this);
                    }
                    if (LeSafeMainActivity.this.f2751k != null) {
                        LeSafeMainActivity.this.f2751k.dismiss();
                        LeSafeMainActivity.m1252d(LeSafeMainActivity.this);
                    }
                    Toast.makeText(LeSafeMainActivity.this.f2744d, C0415R.string.feedback_upload_done, 1).show();
                    break;
                case 3:
                    if (LeSafeMainActivity.this.f2752l != null) {
                        LeSafeMainActivity.this.f2752l.dismiss();
                        LeSafeMainActivity.m1250b(LeSafeMainActivity.this);
                    }
                    if (LeSafeMainActivity.this.f2751k != null) {
                        LeSafeMainActivity.this.f2751k.dismiss();
                        LeSafeMainActivity.m1252d(LeSafeMainActivity.this);
                    }
                    Toast.makeText(LeSafeMainActivity.this.f2744d, C0415R.string.feedback_error, 1).show();
                    break;
                case 4:
                    Toast.makeText(LeSafeMainActivity.this.f2744d, C0415R.string.install_succeeded, 1).show();
                    break;
                case 5:
                    Intent intent = new Intent("android.intent.action.VIEW");
                    intent.setDataAndType(Uri.parse("file://" + ((String) msg.obj)), "application/vnd.android.package-archive");
                    intent.setFlags(268435456);
                    LeSafeMainActivity.this.f2744d.startActivity(intent);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: o */
    private SharedPreferences f2755o;

    /* JADX INFO: renamed from: p */
    private FourBoxAdapter f2756p;

    /* JADX INFO: renamed from: q */
    private DrawerAdapter f2757q;

    /* JADX INFO: renamed from: r */
    private DrawerAdapter f2758r;

    /* JADX INFO: renamed from: b */
    static /* synthetic */ ProgressDialog m1250b(LeSafeMainActivity x0) {
        x0.f2752l = null;
        return null;
    }

    /* JADX INFO: renamed from: d */
    static /* synthetic */ CustomDialog m1252d(LeSafeMainActivity x0) {
        x0.f2751k = null;
        return null;
    }

    /* JADX INFO: renamed from: f */
    static /* synthetic */ void m1254f(LeSafeMainActivity x0) {
        List<ActivityManager.RunningServiceInfo> runningServices;
        int i;
        try {
            x0.f2745e = ActivityManagerNative.getDefault().getConfiguration().locale.getCountry();
            while (true) {
                int i2 = i;
                if (i2 >= runningServices.size()) {
                    break;
                }
                ActivityManager.RunningServiceInfo runningServiceInfo = runningServices.get(i2);
                if (runningServiceInfo.service.getClassName().equals("com.lenovo.safecenter.support.SecurtyService")) {
                    x0.f2746f = true;
                } else if (runningServiceInfo.service.getClassName().equals("com.lenovo.safecenter.support.SafeCenterService")) {
                    x0.f2747g = true;
                }
                i = i2 + 1;
            }
        } catch (RemoteException e) {
            e.printStackTrace();
        }
        runningServices = ((ActivityManager) x0.getSystemService("activity")).getRunningServices(50);
        i = 0;
        if (!x0.f2746f) {
            x0.startService(new Intent(x0.f2744d, (Class<?>) SecurityService.class));
        }
        if (x0.f2747g || !WflUtils.isRoot()) {
            return;
        }
        x0.startService(new Intent(x0, (Class<?>) SafeCenterService.class));
    }

    /* JADX INFO: renamed from: h */
    static /* synthetic */ void m1256h(LeSafeMainActivity x0) {
        ((LinearLayout) x0.findViewById(C0415R.id.close_header_layout)).setVisibility(4);
        ((LinearLayout) x0.findViewById(C0415R.id.open_header_layout)).setVisibility(0);
        x0.f2741a.setVisibility(0);
    }

    /* JADX INFO: renamed from: i */
    static /* synthetic */ void m1257i(LeSafeMainActivity x0) {
        ((LinearLayout) x0.findViewById(C0415R.id.close_header_layout)).setVisibility(0);
        ((LinearLayout) x0.findViewById(C0415R.id.open_header_layout)).setVisibility(4);
        x0.f2741a.setVisibility(8);
    }

    /* JADX INFO: renamed from: j */
    static /* synthetic */ PopupWindow m1258j(LeSafeMainActivity x0) {
        x0.f2748h = null;
        return null;
    }

    /* JADX INFO: renamed from: n */
    static /* synthetic */ void m1262n(LeSafeMainActivity x0) {
        x0.f2752l = new ProgressDialog(x0);
        x0.f2752l.setOnDismissListener(new DialogInterface.OnDismissListener() { // from class: com.lenovo.safecenter.MainTab.LeSafeMainActivity.5
            @Override // android.content.DialogInterface.OnDismissListener
            public final void onDismiss(DialogInterface dialog) {
                LeSafeMainActivity.m1250b(LeSafeMainActivity.this);
            }
        });
        x0.f2752l.setProgressStyle(0);
        x0.f2752l.setMessage(x0.getString(C0415R.string.feedback_progress));
        x0.f2752l.show();
    }

    /* JADX WARN: Type inference failed for: r0v15, types: [com.lenovo.safecenter.MainTab.LeSafeMainActivity$13] */
    /* JADX WARN: Type inference failed for: r0v29, types: [com.lenovo.safecenter.MainTab.LeSafeMainActivity$7] */
    @Override // android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        int i;
        super.onCreate(savedInstanceState);
        Log.i("wu0wu", "LeSafeMainActivity  onCreate() start.....");
        setContentView(C0415R.layout.main);
        ((TextView) findViewById(C0415R.id.txt_title)).setText(C0415R.string.safecenter);
        ((ImageView) findViewById(C0415R.id.title_back)).setVisibility(4);
        this.f2742b = (ImageView) findViewById(C0415R.id.title_set);
        this.f2742b.setImageResource(C0415R.drawable.menu);
        this.f2742b.setVisibility(0);
        this.f2742b.setOnClickListener(this);
        Const.initIsRootThePhone();
        this.f2755o = PreferenceManager.getDefaultSharedPreferences(this);
        this.f2744d = this;
        new Thread() { // from class: com.lenovo.safecenter.MainTab.LeSafeMainActivity.13
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                DbAdapter db = new DbAdapter(LeSafeMainActivity.this.getApplicationContext());
                try {
                    db.open();
                    db.close();
                    DaoImpl di = new DaoImpl(new DbAdapter(LeSafeMainActivity.this.getApplicationContext()));
                    if (di.queryCount() <= 0) {
                        Log.e("ydp", "create sayment database!!");
                        InputStream is = LeSafeMainActivity.this.getApplicationContext().getResources().openRawResource(C0415R.raw.data_1);
                        try {
                            FileOutputStream fos = new FileOutputStream("/data/data/com.lenovo.safecenter/databases/safepayment.db", false);
                            byte[] buffer = new byte[is.available()];
                            is.read(buffer);
                            fos.write(buffer);
                            fos.close();
                            is.close();
                        } catch (FileNotFoundException e) {
                            e.printStackTrace();
                        } catch (IOException e2) {
                            e2.printStackTrace();
                        }
                    }
                } catch (Exception e3) {
                    try {
                        Log.e("ydp", "sqlite version error:" + e3);
                        File safepayment = new File("/data/data/com.lenovo.safecenter/databases", DbAdapter.DB_NAME);
                        safepayment.delete();
                        InputStream is2 = LeSafeMainActivity.this.getApplicationContext().getResources().openRawResource(C0415R.raw.data_1);
                        Log.i("ydp", "database copy");
                        FileOutputStream fos2 = new FileOutputStream("/data/data/com.lenovo.safecenter/databases/safepayment.db", false);
                        byte[] buffer2 = new byte[is2.available()];
                        is2.read(buffer2);
                        fos2.write(buffer2);
                        fos2.close();
                        is2.close();
                        Log.i("ydp", "database copy  end");
                    } catch (Exception e1) {
                        e1.printStackTrace();
                        Log.i("ydp", "database copy  error");
                    }
                }
            }
        }.start();
        this.f2750j = PreferenceManager.getDefaultSharedPreferences(this);
        this.f2743c = LeSafeObservable.get(getApplicationContext());
        this.f2743c.addObserver(this);
        if (Build.VERSION.SDK_INT >= 14 && PreferenceManager.getDefaultSharedPreferences(getApplicationContext()).getBoolean(Const.KEY_IS_SAFEPAYMEN_ON, true)) {
            MyProcessObserver.getDefault(getApplicationContext()).register();
        }
        PwdUtil.judgeUpdateAppLockPatch(this.f2744d);
        if (this.f2753m == null) {
            try {
                i = getPackageManager().getPackageInfo(getPackageName(), 0).versionCode;
            } catch (PackageManager.NameNotFoundException e) {
                e.printStackTrace();
                i = 0;
            }
            this.f2753m = new LeSafeUpdate(this.f2744d, getPackageName(), i, Const.SUS_CHANNEL, false, false, true, new LeSafeUpdate.LeSafeUpdateListenser() { // from class: com.lenovo.safecenter.MainTab.LeSafeMainActivity.14
                @Override // com.lenovo.safecenter.utils.update.LeSafeUpdate.LeSafeUpdateListenser
                public final void onQueryResp(String resultion, LeSafeUpdateInfo lfui) {
                    if (!resultion.equals(C0092c.f1288S)) {
                        UpdateLabManager.startServiceQueryLab(LeSafeMainActivity.this.getApplicationContext());
                    }
                }

                @Override // com.lenovo.safecenter.utils.update.LeSafeUpdate.LeSafeUpdateListenser
                public final void onInstallComplete(boolean succeed) {
                }

                @Override // com.lenovo.safecenter.utils.update.LeSafeUpdate.LeSafeUpdateListenser
                public final void onDownLoadException(int errorCode) {
                    UpdateLabManager.startServiceQueryLab(LeSafeMainActivity.this.getApplicationContext());
                }

                @Override // com.lenovo.safecenter.utils.update.LeSafeUpdate.LeSafeUpdateListenser
                public final void onDownLoadComplete(String path) {
                }
            });
        }
        if (Const.updateAPK && new File(this.f2750j.getString("update_apk_path", "")).exists()) {
            new CustomDialog.Builder(this).setTitle(C0415R.string.dialog_update_title).setMessage(C0415R.string.dialog_update_msg).setPositiveButton(C0415R.string.install_now, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.MainTab.LeSafeMainActivity.3
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface dialog, int which) {
                    if (!CMDHelper.installAPK(LeSafeMainActivity.this.f2744d, LeSafeMainActivity.this.f2750j.getString("update_apk_path", ""), LeSafeMainActivity.this.getPackageName())) {
                        LeSafeMainActivity.this.f2754n.sendMessage(LeSafeMainActivity.this.f2754n.obtainMessage(5, LeSafeMainActivity.this.f2750j.getString("update_apk_path", "")));
                    }
                }
            }).setNegativeButton(C0415R.string.last_time_do, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.MainTab.LeSafeMainActivity.2
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface dialog, int which) {
                }
            }).setColorPositiveButton(true).setColorNegativeButton(false).show();
        } else {
            this.f2753m.upDate(false);
        }
        this.f2746f = false;
        new Thread() { // from class: com.lenovo.safecenter.MainTab.LeSafeMainActivity.7
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                LeSafeMainActivity.m1254f(LeSafeMainActivity.this);
            }
        }.start();
        TrafficStatsService.getExecutorService().execute(new Thread() { // from class: com.lenovo.safecenter.MainTab.LeSafeMainActivity.8
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                TrafficStatsService.trafficForceUpdate(LeSafeMainActivity.this.f2744d);
            }
        });
        ((LinearLayout) findViewById(C0415R.id.close_header_layout)).setVisibility(0);
        ImageView imageView = (ImageView) findViewById(C0415R.id.drawer_up_header);
        ImageView imageView2 = (ImageView) findViewById(C0415R.id.drawer_down_header);
        Animation animationLoadAnimation = AnimationUtils.loadAnimation(getApplicationContext(), C0415R.anim.fade_in);
        Animation animationLoadAnimation2 = AnimationUtils.loadAnimation(getApplicationContext(), C0415R.anim.fade_out);
        animationLoadAnimation.setRepeatMode(2);
        animationLoadAnimation.setDuration(500L);
        animationLoadAnimation.setRepeatCount(-1);
        animationLoadAnimation2.setRepeatMode(2);
        animationLoadAnimation2.setDuration(500L);
        animationLoadAnimation2.setRepeatCount(-1);
        imageView.setAnimation(animationLoadAnimation);
        imageView.startAnimation(animationLoadAnimation);
        imageView2.setAnimation(animationLoadAnimation2);
        imageView2.startAnimation(animationLoadAnimation2);
        ((TextView) findViewById(C0415R.id.button_healthCheckup_home_page)).setOnClickListener(this);
        this.f2749i = (Panel) findViewById(C0415R.id.bottomDrawer);
        this.f2741a = (ImageView) findViewById(C0415R.id.black_layout);
        this.f2741a.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.MainTab.LeSafeMainActivity.10
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                LeSafeMainActivity.this.f2749i.setOpen(false, true);
            }
        });
        this.f2749i.setOnPanelListener(new Panel.OnPanelListener() { // from class: com.lenovo.safecenter.MainTab.LeSafeMainActivity.11
            @Override // com.lenovo.safecenter.utils.Panel.OnPanelListener
            public final void onPanelOpened(Panel panel) {
                LeSafeMainActivity.m1256h(LeSafeMainActivity.this);
            }

            @Override // com.lenovo.safecenter.utils.Panel.OnPanelListener
            public final void onPanelClosed(Panel panel) {
                LeSafeMainActivity.m1257i(LeSafeMainActivity.this);
            }
        });
        GridView gridView = (GridView) findViewById(C0415R.id.home_page_four_box);
        this.f2756p = new FourBoxAdapter(this.f2744d);
        gridView.setAdapter((ListAdapter) this.f2756p);
        this.f2757q = new DrawerAdapter(this.f2744d, true);
        this.f2758r = new DrawerAdapter(this.f2744d, false);
        ((GridView) findViewById(C0415R.id.drawer_up_GridView)).setAdapter((ListAdapter) this.f2757q);
        GridView gridView2 = (GridView) findViewById(C0415R.id.panelHideContent);
        gridView2.setAdapter((ListAdapter) this.f2758r);
        gridView2.setOnTouchListener(new View.OnTouchListener() { // from class: com.lenovo.safecenter.MainTab.LeSafeMainActivity.9
            @Override // android.view.View.OnTouchListener
            public final boolean onTouch(View v, MotionEvent event) {
                int action = event.getAction();
                return 2 == action;
            }
        });
        LeSafeAPI.getHolidayImgSync(this.f2744d, this);
        LeSafeAPI.getSafePayList(this.f2744d, this);
        Log.i("wu0wu", "LeSafeMainActivity  onCreate() end.....");
    }

    /* JADX INFO: renamed from: a */
    private void m1247a(String detail, int score, int color) {
        TextView detailCheckup = (TextView) findViewById(C0415R.id.detail_healthCheckup_home_page);
        if (Const.getIsHealthCheckNoOptimiza().booleanValue() && score != 100) {
            String detail2 = getString(C0415R.string.health_check_wording_lastcheck) + String.format(getString(C0415R.string.health_check_but_no_optimiza), Integer.valueOf(score));
            m1246a(detailCheckup, detail2, getString(C0415R.string.health_check_wording_lastcheck).length(), String.valueOf(score).length() + getString(C0415R.string.health_check_wording_lastcheck).length(), getResources().getColor(color));
        } else {
            m1246a(detailCheckup, detail, 0, String.valueOf(score).length(), getResources().getColor(color));
        }
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == 82) {
            if (this.f2748h == null) {
                showpopupWindow();
            } else if (this.f2748h.isShowing()) {
                this.f2748h.dismiss();
            }
        } else if (keyCode == 4) {
            if (this.f2748h != null) {
                this.f2748h.dismiss();
            }
            if (this.f2749i.isOpen()) {
                m1248a(true);
                return true;
            }
            finish();
        }
        return super.onKeyDown(keyCode, event);
    }

    protected void exit() {
        if (this.f2743c != null) {
            this.f2743c.deleteObservers();
            this.f2743c.close();
        }
        TrackEvent.shutdown();
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.button_healthCheckup_home_page /* 2131297240 */:
                startActivity(new Intent(this, (Class<?>) HealthCheckupActivity.class));
                TrackEvent.reportOneKeyHealthCheckup();
                break;
            case C0415R.id.popwindow_update /* 2131297250 */:
                startActivity(new Intent(getApplicationContext(), (Class<?>) UpdateVersionActivity.class));
                this.f2748h.dismiss();
                break;
            case C0415R.id.popwindow_set /* 2131297251 */:
                startActivity(new Intent(this, (Class<?>) SettingsActivity.class));
                this.f2748h.dismiss();
                break;
            case C0415R.id.popwindow_feedback /* 2131297252 */:
                View viewInflate = LayoutInflater.from(this.f2744d).inflate(C0415R.layout.feedback_dialog_layout, (ViewGroup) null);
                final EditText editText = (EditText) viewInflate.findViewById(C0415R.id.feedback_content_et);
                final EditText editText2 = (EditText) viewInflate.findViewById(C0415R.id.feedback_mail_et);
                editText.setText(this.f2750j.getString("feedback_msg", ""));
                editText2.setText(this.f2750j.getString("feedback_mail", ""));
                this.f2751k = new CustomDialog.Builder(this.f2744d).setTitle(C0415R.string.feedback).setContentView(viewInflate).setPositiveButton(C0415R.string.feedback_upload, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.MainTab.LeSafeMainActivity.4
                    /* JADX WARN: Type inference failed for: r0v14, types: [com.lenovo.safecenter.MainTab.LeSafeMainActivity$4$1] */
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                        if (editText.getText().toString().length() == 0) {
                            Toast.makeText(LeSafeMainActivity.this.f2744d, C0415R.string.feedback_content_, 1).show();
                            return;
                        }
                        if (editText2.getText().toString().length() == 0) {
                            Toast.makeText(LeSafeMainActivity.this.f2744d, C0415R.string.feedback_mail_null, 1).show();
                            return;
                        }
                        if (!LeSafeMainActivity.this.isMailNO(editText2.getText().toString()) && editText2.getText().toString().length() != 0) {
                            Toast.makeText(LeSafeMainActivity.this.f2744d, C0415R.string.feedback_mail_, 1).show();
                            return;
                        }
                        LeSafeMainActivity.m1262n(LeSafeMainActivity.this);
                        if (!WflUtils.isNetworkAvailable(LeSafeMainActivity.this.f2744d)) {
                            LeSafeMainActivity.this.f2754n.sendEmptyMessage(3);
                            LeSafeMainActivity.this.f2750j.edit().putString("feedback_msg", editText.getText().toString()).commit();
                            LeSafeMainActivity.this.f2750j.edit().putString("feedback_mail", editText2.getText().toString()).commit();
                            return;
                        }
                        new Thread() { // from class: com.lenovo.safecenter.MainTab.LeSafeMainActivity.4.1
                            @Override // java.lang.Thread, java.lang.Runnable
                            public final void run() {
                                if (LeSafeMainActivity.this.feedback(editText.getText().toString(), editText2.getText().toString()) == 200) {
                                    try {
                                        Thread.sleep(500L);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                    }
                                    LeSafeMainActivity.this.f2754n.sendEmptyMessage(2);
                                    LeSafeMainActivity.this.f2750j.edit().putString("feedback_msg", "").commit();
                                    LeSafeMainActivity.this.f2750j.edit().putString("feedback_mail", "").commit();
                                    return;
                                }
                                try {
                                    Thread.sleep(500L);
                                } catch (InterruptedException e2) {
                                    e2.printStackTrace();
                                }
                                LeSafeMainActivity.this.f2754n.sendEmptyMessage(3);
                                LeSafeMainActivity.this.f2750j.edit().putString("feedback_msg", editText.getText().toString()).commit();
                                LeSafeMainActivity.this.f2750j.edit().putString("feedback_mail", editText2.getText().toString()).commit();
                            }
                        }.start();
                    }
                }, false).setNegativeButton(C0415R.string.cancel, (DialogInterface.OnClickListener) null).create();
                this.f2751k.show();
                this.f2748h.dismiss();
                break;
            case C0415R.id.popwindow_help /* 2131297253 */:
                Intent intent = new Intent(getApplicationContext(), (Class<?>) QuestionAndAnswer.class);
                intent.putExtra("frommain", true);
                startActivity(intent);
                this.f2748h.dismiss();
                break;
            case C0415R.id.popwindow_about /* 2131297255 */:
                startActivity(new Intent(this, (Class<?>) AboutActivity.class));
                this.f2748h.dismiss();
                break;
            case C0415R.id.title_set /* 2131297710 */:
                if (this.f2748h == null) {
                    showpopupWindow();
                } else if (this.f2748h.isShowing()) {
                    this.f2748h.dismiss();
                }
                break;
        }
    }

    /* JADX INFO: renamed from: a */
    private static void m1246a(TextView tv, String source, int start, int end, int color) {
        SpannableString spannable = new SpannableString(source);
        spannable.setSpan(new AbsoluteSizeSpan(26, true), start, end, 33);
        spannable.setSpan(new ForegroundColorSpan(color), start, end, 0);
        tv.setText(spannable);
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        exit();
        super.onDestroy();
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        ImageView imageView = (ImageView) findViewById(C0415R.id.drawer_up_header);
        ImageView imageView2 = (ImageView) findViewById(C0415R.id.drawer_down_header);
        imageView.clearAnimation();
        imageView2.clearAnimation();
        DialogUtil.dismissShowPwdDialog();
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        if (this.f2749i.isOpen()) {
            m1248a(false);
        }
        int healthCheckupScore = Const.getHealthCheckupScore();
        int daysNumFromToday = WflUtils.getDaysNumFromToday(Const.getHealthCheckupTime());
        TextView textView = (TextView) findViewById(C0415R.id.detail_healthCheckup_home_page);
        TextView textView2 = (TextView) findViewById(C0415R.id.score_healthCheckup_home_page);
        if (Const.isFirstHealthCheckup()) {
            String string = getString(C0415R.string.do_health_check);
            textView2.setBackgroundResource(C0415R.drawable.home_page_health_state_1);
            textView.setText(string);
        } else if (daysNumFromToday < 0) {
            String string2 = getString(C0415R.string.do_health_check);
            textView2.setBackgroundResource(C0415R.drawable.home_page_health_state_1);
            textView.setText(string2);
        } else if (daysNumFromToday <= 1) {
            if (healthCheckupScore >= 100) {
                String str = String.format(getString(C0415R.string.health_can_optimization100), Integer.valueOf(healthCheckupScore));
                textView2.setBackgroundResource(C0415R.drawable.home_page_health_state_4);
                m1247a(str, healthCheckupScore, C0415R.color.green3);
            } else if (healthCheckupScore < 60 || healthCheckupScore > 99) {
                String str2 = String.format(getString(C0415R.string.health_can_optimization59), Integer.valueOf(healthCheckupScore));
                textView2.setBackgroundResource(C0415R.drawable.home_page_health_state_6);
                m1247a(str2, healthCheckupScore, C0415R.color.red1);
            } else {
                String str3 = String.format(getString(C0415R.string.health_can_optimization60_99), Integer.valueOf(healthCheckupScore));
                textView2.setBackgroundResource(C0415R.drawable.home_page_health_state_5);
                m1247a(str3, healthCheckupScore, C0415R.color.green3);
            }
        } else if (daysNumFromToday >= 2 && daysNumFromToday <= 6) {
            m1246a(textView, String.format(getString(C0415R.string.home_page_health_score2to7day), Integer.valueOf(daysNumFromToday)), 0, String.valueOf(daysNumFromToday).length(), getResources().getColor(C0415R.color.red1));
            textView2.setBackgroundResource(C0415R.drawable.virus_status_green0);
        } else if (daysNumFromToday >= 7) {
            textView.setText(getString(C0415R.string.home_page_health_score7day));
            textView2.setBackgroundResource(C0415R.drawable.home_page_health_state_3);
        }
        this.f2756p.refresh();
        this.f2757q.refresh();
        this.f2758r.refresh();
        if (UpdateLabManager.hasNewVersionLab() && !UpdateLabManager.isUpdateingLab() && WflUtils.isNetworkAvailable(this.f2744d)) {
            WflUtils.Log("i", "wu0wu", "hasNewVersionLab");
            if (!WflUtils.isInTheSameDay(Const.getDialogNoticeUpdateTime(), System.currentTimeMillis())) {
                WflUtils.Log("i", "wu0wu", "!isInTheSameDay");
                if (WflUtils.isTopActivity(this)) {
                    WflUtils.Log("i", "wu0wu", getClass().getCanonicalName() + "  isTopActivity");
                    if (!AutoUpdateLabManager.isAutoUpdate(this.f2744d)) {
                        startActivity(new Intent(this, (Class<?>) LabUpdateDialogActivity.class));
                        Const.setDialogNoticeUpdateTime(System.currentTimeMillis());
                    }
                }
            }
        }
        TrackEvent.trackResume(this);
    }

    /* JADX INFO: renamed from: a */
    private void m1248a(boolean animate) {
        this.f2749i.setOpen(false, animate);
    }

    @Override // java.util.Observer
    public void update(Observable observable, Object data) {
        if (data instanceof Integer) {
            switch (((Integer) data).intValue()) {
                case 0:
                    this.f2756p.refresh();
                    break;
                case 1:
                    WflUtils.Log("i", "wu0wu", "LeSafeActivity LeSafeObservable.OBSERVER_QUERY_LAB");
                    this.f2756p.refresh();
                    break;
                case 2:
                    this.f2756p.refresh();
                    break;
                case 3:
                    this.f2756p.refresh();
                    break;
                case 7:
                    this.f2756p.refresh();
                    break;
                case 8:
                    this.f2756p.refresh();
                    break;
                case 9:
                    this.f2756p.refresh();
                    break;
            }
        }
    }

    public void showpopupWindow() {
        View view = LayoutInflater.from(this).inflate(C0415R.layout.main_poplistview, (ViewGroup) null);
        ((LinearLayout) view.findViewById(C0415R.id.popwindow_update)).setOnClickListener(this);
        ((LinearLayout) view.findViewById(C0415R.id.popwindow_set)).setOnClickListener(this);
        ((LinearLayout) view.findViewById(C0415R.id.popwindow_feedback)).setOnClickListener(this);
        ((LinearLayout) view.findViewById(C0415R.id.popwindow_help)).setOnClickListener(this);
        ((LinearLayout) view.findViewById(C0415R.id.popwindow_about)).setOnClickListener(this);
        this.f2748h = new PopupWindow(view, -2, -2, true);
        this.f2748h.setAnimationStyle(C0415R.style.PopupAnimation);
        this.f2748h.setBackgroundDrawable(new BitmapDrawable());
        this.f2748h.setFocusable(true);
        this.f2748h.setOutsideTouchable(true);
        this.f2748h.showAsDropDown(findViewById(C0415R.id.title_bar), Const.getScreenWidth(), 0);
        this.f2748h.update();
        this.f2742b.setImageResource(C0415R.drawable.menu_up);
        this.f2748h.setOnDismissListener(new PopupWindow.OnDismissListener() { // from class: com.lenovo.safecenter.MainTab.LeSafeMainActivity.12
            @Override // android.widget.PopupWindow.OnDismissListener
            public final void onDismiss() {
                LeSafeMainActivity.m1258j(LeSafeMainActivity.this);
                LeSafeMainActivity.this.f2742b.setImageResource(C0415R.drawable.menu);
            }
        });
    }

    public boolean isMailNO(String mail) {
        Pattern p = Pattern.compile("^(\\w)+(\\.\\w+)*@(\\w)+((\\.\\w+)+)$");
        Matcher m = p.matcher(mail);
        return m.matches();
    }

    public int feedback(String content, String mail) {
        TelephonyManager manager = (TelephonyManager) getSystemService("phone");
        String idea = "";
        try {
            String idea2 = new String(UrlBase64.encode(content.getBytes("utf-8")));
            idea = idea2;
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        String versionName = null;
        try {
            PackageInfo pInfo = getApplicationContext().getPackageManager().getPackageInfo(getApplicationInfo().packageName, 32768);
            versionName = pInfo.versionName;
        } catch (PackageManager.NameNotFoundException e2) {
            e2.printStackTrace();
        }
        HttpClient httpClient = new HttpClient();
        PostMethod post = new PostMethod("http://sss.lenovomm.com/sss/1.0/idea");
        post.setParameter(AppDatabase.CONTENT, idea);
        post.setParameter("lang", "zh-cn");
        if (!mail.equals("")) {
            post.setParameter("email", mail);
        }
        post.setParameter("revision", versionName);
        post.setParameter("devicefamily", Build.MODEL);
        post.setParameter("deviceidtype", "imei");
        if (manager.getDeviceId() == null) {
            post.setParameter("deviceid", "N/A");
        } else {
            post.setParameter("deviceid", manager.getDeviceId());
        }
        post.setParameter("devicevendor", Build.MANUFACTURER);
        try {
            int i = httpClient.executeMethod(post);
            if (post.getResponseBodyAsString().equals("") || i != 200) {
                return i;
            }
            return -1;
        } catch (HttpException e3) {
            e3.printStackTrace();
            return -1;
        } catch (IOException e4) {
            e4.printStackTrace();
            return -1;
        }
    }

    public boolean canExecute(String path) {
        File file = new File(path);
        for (int i = 0; i < 3; i++) {
            if (file.canExecute()) {
                Log.i("ydp", "canExecute()...true");
                return true;
            }
            Log.i("ydp", "canExecute()...false");
            try {
                Thread.sleep(1500L);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        return false;
    }

    @Override // com.lenovo.safecenter.utils.httpApi.HttpApiAsyncTask.ApiRequestListener
    public void onSuccess(int method, final Object obj) {
        switch (method) {
            case 0:
                if (obj != null) {
                    if (!(obj instanceof Integer)) {
                        SharedPreferences.Editor editorEdit = this.f2755o.edit();
                        HashMap map = (HashMap) obj;
                        if (map.containsKey("expiredId") && ((String) map.get("expiredId")).equals(Const.getHolidayImgId())) {
                            editorEdit.remove(Const.KEY_HOLIDAY_IMG_ID);
                            editorEdit.remove(Const.KEY_HOLIDAY_IMG_URL);
                            editorEdit.remove(Const.KEY_HOLIDAY_IMG_STARTTIME);
                            editorEdit.remove(Const.KEY_HOLIDAY_IMG_ENDTIME);
                            editorEdit.remove(Const.KEY_HOLIDAY_IMG_VERSION);
                            editorEdit.commit();
                            WflUtils.Log("d", "wu0wu", "handleHolidayImgSync onSuccess =remove data...");
                            File file = new File(getFilesDir(), Const.FILENAME_HOLIDAY_IMG);
                            if (file.exists()) {
                                file.delete();
                            }
                        }
                        if (map.containsKey(QueryPermissions.f1958ID)) {
                            editorEdit.putString(Const.KEY_HOLIDAY_IMG_ID, (String) map.get(QueryPermissions.f1958ID));
                            editorEdit.commit();
                        }
                        if (map.containsKey("imageurl")) {
                            editorEdit.putString(Const.KEY_HOLIDAY_IMG_URL, (String) map.get("imageurl"));
                            editorEdit.commit();
                        }
                        if (map.containsKey("starttime")) {
                            editorEdit.putString(Const.KEY_HOLIDAY_IMG_STARTTIME, (String) map.get("starttime"));
                            editorEdit.commit();
                        }
                        if (map.containsKey("endtime")) {
                            editorEdit.putString(Const.KEY_HOLIDAY_IMG_ENDTIME, (String) map.get("endtime"));
                            editorEdit.commit();
                        }
                        if (map.containsKey("version")) {
                            editorEdit.putString(Const.KEY_HOLIDAY_IMG_VERSION, (String) map.get("version"));
                            editorEdit.commit();
                        }
                        if (!TextUtils.isEmpty(Const.getHolidayImgUrl())) {
                            LeSafeAPI.downloadHolidayImg(this, this);
                        }
                        WflUtils.Log("d", "wu0wu", "handleHolidayImgSync onSuccess =end...");
                    } else if (((Integer) obj).intValue() == 304) {
                        if (m1249a()) {
                            LeSafeAPI.downloadHolidayImg(this, this);
                        }
                        WflUtils.Log("d", "wu0wu", "handleHolidayImgSync onSuccess =304...");
                    }
                }
                break;
            case 1:
                new Thread(new Runnable() { // from class: com.lenovo.safecenter.MainTab.LeSafeMainActivity.6
                    @Override // java.lang.Runnable
                    public final void run() {
                        if (obj != null) {
                            InputStream result = (InputStream) obj;
                            byte[] buffer = new byte[1024];
                            ByteArrayOutputStream ostream = new ByteArrayOutputStream();
                            while (true) {
                                try {
                                    int len = result.read(buffer);
                                    if (len != -1) {
                                        ostream.write(buffer, 0, len);
                                    } else {
                                        FileOutputStream fos = LeSafeMainActivity.this.openFileOutput(Const.FILENAME_HOLIDAY_IMG, 0);
                                        fos.write(ostream.toByteArray());
                                        fos.close();
                                        result.close();
                                        ostream.close();
                                        WflUtils.Log("d", "wu0wu", "handleHolidayImgDownload onSuccess...");
                                        return;
                                    }
                                } catch (IOException e) {
                                    e.printStackTrace();
                                    Log.i("wu0wu", "IOException");
                                    return;
                                }
                            }
                        }
                    }
                }).start();
                break;
        }
    }

    @Override // com.lenovo.safecenter.utils.httpApi.HttpApiAsyncTask.ApiRequestListener
    public void onError(int method, int statusCode) {
    }

    /* JADX INFO: renamed from: a */
    private boolean m1249a() {
        String id = this.f2755o.getString(Const.KEY_HOLIDAY_IMG_ID, null);
        String url = this.f2755o.getString(Const.KEY_HOLIDAY_IMG_URL, null);
        String endtime = this.f2755o.getString(Const.KEY_HOLIDAY_IMG_ENDTIME, null);
        long lEndTime = 0;
        try {
            lEndTime = Long.valueOf(endtime).longValue();
        } catch (Exception e) {
        }
        File file = new File(getFilesDir(), Const.FILENAME_HOLIDAY_IMG);
        boolean isFileExists = file.exists();
        boolean isShow = System.currentTimeMillis() < lEndTime;
        return (id == null || url == null || !isShow || isFileExists) ? false : true;
    }
}
