package com.lenovo.install;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageParser;
import android.content.pm.PermissionInfo;
import android.graphics.drawable.BitmapDrawable;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.text.TextUtils;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.PopupWindow;
import android.widget.RelativeLayout;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.support.AppInfo;
import com.lenovo.safecenter.support.WhiteAppsList;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.qscanner.QScanResultEntity;
import com.tencent.tmsecure.module.qscanner.QScannerManager;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

/* JADX INFO: loaded from: classes.dex */
public class InstallActivity extends Activity implements View.OnClickListener {

    /* JADX INFO: renamed from: A */
    private TextView f967A;

    /* JADX INFO: renamed from: B */
    private RelativeLayout f968B;

    /* JADX INFO: renamed from: C */
    private ImageView f969C;

    /* JADX INFO: renamed from: D */
    private ImageView f970D;

    /* JADX INFO: renamed from: E */
    private RelativeLayout[] f971E;

    /* JADX INFO: renamed from: F */
    private LinearLayout[] f972F;

    /* JADX INFO: renamed from: G */
    private ImageView[] f973G;

    /* JADX INFO: renamed from: H */
    private TextView[] f974H;

    /* JADX INFO: renamed from: J */
    private View f976J;

    /* JADX INFO: renamed from: K */
    private LinearLayout f977K;

    /* JADX INFO: renamed from: L */
    private LinearLayout f978L;

    /* JADX INFO: renamed from: M */
    private LinearLayout f979M;

    /* JADX INFO: renamed from: N */
    private TextView f980N;

    /* JADX INFO: renamed from: O */
    private QScannerManager f981O;

    /* JADX INFO: renamed from: P */
    private int f982P;

    /* JADX INFO: renamed from: Q */
    private boolean f983Q;

    /* JADX INFO: renamed from: R */
    private boolean f984R;

    /* JADX INFO: renamed from: S */
    private String f985S;

    /* JADX INFO: renamed from: T */
    private FrameLayout f986T;

    /* JADX INFO: renamed from: U */
    private ImageView f987U;

    /* JADX INFO: renamed from: V */
    private boolean f988V;

    /* JADX INFO: renamed from: W */
    private boolean f989W;

    /* JADX INFO: renamed from: X */
    private String f990X;

    /* JADX INFO: renamed from: Y */
    private String f991Y;

    /* JADX INFO: renamed from: a */
    PackageManager f993a;

    /* JADX INFO: renamed from: ab */
    private PopupWindow f995ab;

    /* JADX INFO: renamed from: b */
    PackageParser.Package f996b;

    /* JADX INFO: renamed from: c */
    PackageUtil.AppSnippet f997c;

    /* JADX INFO: renamed from: m */
    private SharedPreferences f1007m;

    /* JADX INFO: renamed from: n */
    private PopupWindow f1008n;

    /* JADX INFO: renamed from: o */
    private Context f1009o;

    /* JADX INFO: renamed from: p */
    private AppDatabase f1010p;

    /* JADX INFO: renamed from: q */
    private String f1011q;

    /* JADX INFO: renamed from: r */
    private List<PermissionInfo> f1012r;

    /* JADX INFO: renamed from: s */
    private ImageView f1013s;

    /* JADX INFO: renamed from: t */
    private ImageView f1014t;

    /* JADX INFO: renamed from: u */
    private TextView f1015u;

    /* JADX INFO: renamed from: v */
    private TextView f1016v;

    /* JADX INFO: renamed from: w */
    private TextView f1017w;

    /* JADX INFO: renamed from: x */
    private TextView f1018x;

    /* JADX INFO: renamed from: y */
    private TextView f1019y;

    /* JADX INFO: renamed from: z */
    private TextView f1020z;

    /* JADX INFO: renamed from: f */
    private final int f1000f = 0;

    /* JADX INFO: renamed from: g */
    private final int f1001g = 1;

    /* JADX INFO: renamed from: h */
    private final int f1002h = 2;

    /* JADX INFO: renamed from: i */
    private final int f1003i = 3;

    /* JADX INFO: renamed from: j */
    private final int f1004j = 4;

    /* JADX INFO: renamed from: k */
    private final int f1005k = 5;

    /* JADX INFO: renamed from: l */
    private final int f1006l = 6;

    /* JADX INFO: renamed from: d */
    boolean f998d = false;

    /* JADX INFO: renamed from: I */
    private List<AppInfo> f975I = new ArrayList();

    /* JADX INFO: renamed from: Z */
    private Handler f992Z = new Handler() { // from class: com.lenovo.install.InstallActivity.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    InstallActivity.this.f988V = false;
                    InstallActivity.this.f987U.clearAnimation();
                    InstallActivity.this.f986T.setVisibility(8);
                    InstallActivity.this.f978L.setVisibility(0);
                    InstallActivity.this.f1014t.setBackgroundResource(C0415R.drawable.safe_state);
                    InstallActivity.this.f1016v.setText(C0415R.string.pass_antivirus);
                    InstallActivity.this.f1016v.setTextColor(InstallActivity.this.getResources().getColor(C0415R.color.white));
                    InstallActivity.this.f976J.setVisibility(8);
                    InstallActivity.this.initAfterScan();
                    break;
                case 1:
                    InstallActivity.this.f988V = true;
                    InstallActivity.this.f987U.clearAnimation();
                    InstallActivity.this.f986T.setVisibility(8);
                    InstallActivity.this.f978L.setVisibility(0);
                    InstallActivity.this.f1014t.setBackgroundResource(C0415R.drawable.warning);
                    InstallActivity.this.f1016v.setText(C0415R.string.find_antivirus);
                    InstallActivity.this.f1016v.setTextColor(InstallActivity.this.getResources().getColor(C0415R.color.red));
                    InstallActivity.this.f976J.setVisibility(0);
                    InstallActivity.this.showVirusDesc((QScanResultEntity) msg.obj);
                    InstallActivity.this.initAfterScan();
                    break;
                case 2:
                    InstallActivity.this.f968B.setVisibility(0);
                    InstallActivity.this.f1018x.setEnabled(true);
                    InstallActivity.this.f1019y.setEnabled(true);
                    InstallActivity.this.f1018x.setTextColor(InstallActivity.this.getResources().getColor(C0415R.color.white));
                    InstallActivity.this.f1019y.setTextColor(InstallActivity.this.getResources().getColor(C0415R.color.white));
                    for (int i = 0; i < InstallActivity.this.f975I.size(); i++) {
                        if (!((AppInfo) InstallActivity.this.f975I.get(i)).appType.equals(AppDatabase.PERM_TYPE_PRIVCY)) {
                            if (!((AppInfo) InstallActivity.this.f975I.get(i)).appType.equals("location")) {
                                if (!((AppInfo) InstallActivity.this.f975I.get(i)).appType.equals(AppDatabase.PERM_TYPE_DEVICE)) {
                                    if (!((AppInfo) InstallActivity.this.f975I.get(i)).appType.equals(AppDatabase.DB_APP_CALL)) {
                                        if (((AppInfo) InstallActivity.this.f975I.get(i)).appType.equals(AppDatabase.DB_APP_SENDMESSAGE)) {
                                            InstallActivity.m149a(InstallActivity.this, i, C0415R.id.sendmsg_layout, C0415R.id.changemsg_layout, C0415R.id.sendmsg_img);
                                            InstallActivity.this.f1020z.setVisibility(0);
                                            if (((AppInfo) InstallActivity.this.f975I.get(i)).selected == 0) {
                                                InstallActivity.this.f1020z.setText(C0415R.string.allow);
                                                InstallActivity.this.f973G[i].setBackgroundResource(C0415R.drawable.perm_grant1);
                                            } else if (((AppInfo) InstallActivity.this.f975I.get(i)).selected == 1) {
                                                InstallActivity.this.f1020z.setText(C0415R.string.forbid);
                                                InstallActivity.this.f973G[i].setBackgroundResource(C0415R.drawable.perm_deny1);
                                            } else if (((AppInfo) InstallActivity.this.f975I.get(i)).selected == 2) {
                                                InstallActivity.this.f1020z.setText(C0415R.string.notify);
                                                InstallActivity.this.f973G[i].setBackgroundResource(C0415R.drawable.perm_prompt1);
                                            }
                                        }
                                    } else {
                                        InstallActivity.m149a(InstallActivity.this, i, C0415R.id.call_layout, C0415R.id.changecall_layout, C0415R.id.call_img);
                                        if (((AppInfo) InstallActivity.this.f975I.get(i)).selected == 0) {
                                            InstallActivity.this.f973G[i].setBackgroundResource(C0415R.drawable.dark_on);
                                        } else if (((AppInfo) InstallActivity.this.f975I.get(i)).selected == 1) {
                                            InstallActivity.this.f973G[i].setBackgroundResource(C0415R.drawable.dark_off);
                                        }
                                    }
                                } else {
                                    InstallActivity.m149a(InstallActivity.this, i, C0415R.id.record_layout, C0415R.id.changerecord_layout, C0415R.id.record_img);
                                    if (((AppInfo) InstallActivity.this.f975I.get(i)).selected == 0) {
                                        InstallActivity.this.f973G[i].setBackgroundResource(C0415R.drawable.dark_on);
                                    } else if (((AppInfo) InstallActivity.this.f975I.get(i)).selected == 1) {
                                        InstallActivity.this.f973G[i].setBackgroundResource(C0415R.drawable.dark_off);
                                    }
                                }
                            } else {
                                InstallActivity.m149a(InstallActivity.this, i, C0415R.id.location_layout, C0415R.id.changeloc_layout, C0415R.id.location_img);
                                if (((AppInfo) InstallActivity.this.f975I.get(i)).selected == 0) {
                                    InstallActivity.this.f973G[i].setBackgroundResource(C0415R.drawable.dark_on);
                                } else if (((AppInfo) InstallActivity.this.f975I.get(i)).selected == 1) {
                                    InstallActivity.this.f973G[i].setBackgroundResource(C0415R.drawable.dark_off);
                                }
                            }
                        } else {
                            InstallActivity.m149a(InstallActivity.this, i, C0415R.id.privacy_layout, C0415R.id.changepri_layout, C0415R.id.privacy_img);
                            if (((AppInfo) InstallActivity.this.f975I.get(i)).selected == 0) {
                                InstallActivity.this.f973G[i].setBackgroundResource(C0415R.drawable.dark_on);
                            } else if (((AppInfo) InstallActivity.this.f975I.get(i)).selected == 1) {
                                InstallActivity.this.f973G[i].setBackgroundResource(C0415R.drawable.dark_off);
                            }
                            InstallActivity.this.f985S = InstallActivity.m171l(InstallActivity.this);
                            ((TextView) InstallActivity.this.findViewById(C0415R.id.privacy_perm_detail)).setText(InstallActivity.this.f985S);
                        }
                    }
                    break;
                case 3:
                    if (((AppInfo) InstallActivity.this.f975I.get(InstallActivity.this.f982P)).appType.equals(AppDatabase.DB_APP_SENDMESSAGE)) {
                        if (((AppInfo) InstallActivity.this.f975I.get(InstallActivity.this.f982P)).selected == 0) {
                            InstallActivity.this.f1020z.setText(C0415R.string.allow);
                            InstallActivity.this.f973G[InstallActivity.this.f982P].setBackgroundResource(C0415R.drawable.perm_grant1);
                        } else if (((AppInfo) InstallActivity.this.f975I.get(InstallActivity.this.f982P)).selected == 1) {
                            InstallActivity.this.f1020z.setText(C0415R.string.forbid);
                            InstallActivity.this.f973G[InstallActivity.this.f982P].setBackgroundResource(C0415R.drawable.perm_deny1);
                            if (!InstallActivity.this.f1007m.getBoolean("next_notip", false)) {
                                InstallActivity.this.changePopState(((AppInfo) InstallActivity.this.f975I.get(InstallActivity.this.f982P)).appType);
                            }
                        } else if (((AppInfo) InstallActivity.this.f975I.get(InstallActivity.this.f982P)).selected == 2) {
                            InstallActivity.this.f1020z.setText(C0415R.string.notify);
                            InstallActivity.this.f973G[InstallActivity.this.f982P].setBackgroundResource(C0415R.drawable.perm_prompt1);
                        }
                    } else if (((AppInfo) InstallActivity.this.f975I.get(InstallActivity.this.f982P)).selected == 0) {
                        InstallActivity.this.f973G[InstallActivity.this.f982P].setBackgroundResource(C0415R.drawable.dark_on);
                    } else if (((AppInfo) InstallActivity.this.f975I.get(InstallActivity.this.f982P)).selected == 1) {
                        InstallActivity.this.f973G[InstallActivity.this.f982P].setBackgroundResource(C0415R.drawable.dark_off);
                        if (!InstallActivity.this.f1007m.getBoolean("next_notip", false)) {
                            InstallActivity.this.changePopState(((AppInfo) InstallActivity.this.f975I.get(InstallActivity.this.f982P)).appType);
                        }
                    }
                    break;
                case 7:
                    InstallActivity.this.f968B.setVisibility(0);
                    InstallActivity.this.f1019y.setEnabled(true);
                    InstallActivity.this.f1018x.setEnabled(true);
                    InstallActivity.this.f1018x.setTextColor(InstallActivity.this.getResources().getColor(C0415R.color.white));
                    InstallActivity.this.f1019y.setTextColor(InstallActivity.this.getResources().getColor(C0415R.color.white));
                    if (InstallActivity.this.f984R) {
                        InstallActivity.this.f967A.setText(C0415R.string.detail_perm2);
                        InstallActivity.this.f1017w.setVisibility(0);
                    } else {
                        InstallActivity.this.f967A.setText(C0415R.string.detail_perm3);
                        InstallActivity.this.f1017w.setVisibility(8);
                        InstallActivity.m179t(InstallActivity.this);
                    }
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: aa */
    private int f994aa = 0;

    /* JADX INFO: renamed from: e */
    boolean f999e = false;

    /* JADX INFO: renamed from: A */
    static /* synthetic */ boolean m141A(InstallActivity x0) {
        x0.f989W = true;
        return true;
    }

    /* JADX INFO: renamed from: D */
    static /* synthetic */ PopupWindow m144D(InstallActivity x0) {
        x0.f1008n = null;
        return null;
    }

    /* JADX INFO: renamed from: E */
    static /* synthetic */ PopupWindow m145E(InstallActivity x0) {
        x0.f995ab = null;
        return null;
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m149a(InstallActivity x0, int x1, int x2, int x3, int x4) {
        x0.f971E[x1] = (RelativeLayout) x0.findViewById(x2);
        x0.f972F[x1] = (LinearLayout) x0.findViewById(x3);
        x0.f973G[x1] = (ImageView) x0.findViewById(x4);
        x0.f971E[x1].setVisibility(0);
        x0.f972F[x1].setOnClickListener(x0);
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ boolean m151a(String x1) {
        ArrayList arrayList = new ArrayList();
        arrayList.add("android.permission.READ_SMS");
        arrayList.add("android.permission.WRITE_SMS");
        arrayList.add("android.permission.RECEIVE_SMS");
        arrayList.add("android.permission.READ_CONTACTS");
        arrayList.add("android.permission.WRITE_CONTACTS");
        arrayList.add("android.permission.READ_CALENDAR");
        arrayList.add("com.android.browser.permission.READ_HISTORY_BOOKMARKS");
        return arrayList.contains(x1);
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ boolean m152a(List x1, String x2) {
        for (int i = 0; i < x1.size(); i++) {
            if (((AppInfo) x1.get(i)).appType.equals(x2)) {
                return true;
            }
        }
        return false;
    }

    /* JADX INFO: renamed from: b */
    static /* synthetic */ boolean m159b(String x1) {
        ArrayList arrayList = new ArrayList();
        arrayList.add("android.permission.ACCESS_COARSE_LOCATION");
        arrayList.add("android.permission.ACCESS_FINE_LOCATION");
        arrayList.add("android.permission.ACCESS_LOCATION_EXTRA_COMMANDS");
        return arrayList.contains(x1);
    }

    /* JADX INFO: renamed from: l */
    static /* synthetic */ String m171l(InstallActivity x0) {
        String str = "";
        for (PermissionInfo permissionInfo : x0.f1012r) {
            if (permissionInfo.name.equals("android.permission.READ_CONTACTS")) {
                str = str + x0.getString(C0415R.string.privacy_contact);
            }
            if (permissionInfo.name.equals("android.permission.READ_SMS")) {
                str = str + x0.getString(C0415R.string.privacy_sms);
            }
            if (permissionInfo.name.equals("android.permission.READ_CALENDAR")) {
                str = str + x0.getString(C0415R.string.privacy_schedule);
            }
            if (permissionInfo.name.equals("com.android.browser.permission.READ_HISTORY_BOOKMARKS")) {
                str = str + x0.getString(C0415R.string.privacy_history);
            }
        }
        return str.length() > 0 ? str.substring(0, str.length() - 1) : str;
    }

    /* JADX INFO: renamed from: t */
    static /* synthetic */ void m179t(InstallActivity x0) {
        x0.f968B.setVisibility(0);
        x0.findViewById(C0415R.id.btn_detail).setVisibility(8);
        if (x0.f1012r.size() <= 0) {
            x0.f968B.setVisibility(8);
            x0.f977K.removeAllViews();
            x0.f977K.addView(x0.m160c(x0.getString(C0415R.string.no_premit)));
            return;
        }
        x0.f977K.removeAllViews();
        for (PermissionInfo permissionInfo : x0.f1012r) {
            LinearLayout linearLayout = x0.f977K;
            String string = permissionInfo.loadLabel(x0.getPackageManager()).toString();
            permissionInfo.loadLogo(x0.getPackageManager());
            linearLayout.addView(x0.m160c(string));
        }
    }

    /* JADX INFO: renamed from: z */
    static /* synthetic */ boolean m185z(InstallActivity x0) {
        x0.f983Q = true;
        return true;
    }

    /* JADX WARN: Type inference failed for: r0v85, types: [com.lenovo.install.InstallActivity$4] */
    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        this.f1007m = getSharedPreferences("isFirst", 0);
        this.f993a = getPackageManager();
        this.f996b = PackageUtil.getPackageInfo(getIntent().getData());
        if (this.f996b == null) {
            startActivity(new Intent(this, (Class<?>) InstallErrorActivity.class).putExtra("uri", getIntent().getData().toString()));
            finish();
            return;
        }
        this.f981O = (QScannerManager) ManagerCreator.getManager(QScannerManager.class);
        setContentView(C0415R.layout.installing);
        this.f1013s = (ImageView) findViewById(C0415R.id.app_icon);
        this.f1015u = (TextView) findViewById(C0415R.id.app_name);
        this.f1014t = (ImageView) findViewById(C0415R.id.checkresult_icon);
        this.f1016v = (TextView) findViewById(C0415R.id.checkresult_text);
        this.f1017w = (TextView) findViewById(C0415R.id.btn_detail);
        this.f1018x = (TextView) findViewById(C0415R.id.btn_cancel);
        this.f1019y = (TextView) findViewById(C0415R.id.btn_install);
        this.f1018x.setEnabled(false);
        this.f1019y.setEnabled(false);
        this.f968B = (RelativeLayout) findViewById(C0415R.id.layout3);
        this.f979M = (LinearLayout) findViewById(C0415R.id.install_replace);
        this.f970D = (ImageView) findViewById(C0415R.id.bottom_img);
        this.f976J = findViewById(C0415R.id.virus_detail_view);
        this.f977K = (LinearLayout) findViewById(C0415R.id.perm_detail_view);
        this.f969C = (ImageView) findViewById(C0415R.id.sendmsg_img_arrow);
        this.f980N = (TextView) findViewById(C0415R.id.repalce_warning);
        this.f1020z = (TextView) findViewById(C0415R.id.sendmsg_txt);
        this.f967A = (TextView) findViewById(C0415R.id.txt_detail);
        this.f1017w.setOnClickListener(this);
        this.f1018x.setOnClickListener(this);
        this.f1019y.setOnClickListener(this);
        this.f976J.setOnClickListener(this);
        this.f986T = (FrameLayout) findViewById(C0415R.id.frameLayout_scan);
        this.f987U = (ImageView) findViewById(C0415R.id.checkresult_scan);
        this.f978L = (LinearLayout) findViewById(C0415R.id.layout_scan);
        this.f1009o = this;
        this.f1010p = new AppDatabase(this);
        this.f984R = WflUtils.isRoot();
        this.f1011q = this.f996b.packageName;
        this.f1012r = PackageUtil.getPerssions(this.f996b, this.f1009o);
        this.f997c = PackageUtil.getAppSnippet(this, this.f996b.applicationInfo, getIntent().getData());
        this.f1013s.setImageDrawable(this.f997c.f1061b);
        this.f1015u.setText(this.f997c.f1060a);
        translate(this.f987U);
        new Thread() { // from class: com.lenovo.install.InstallActivity.4
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                List<String> strs = new ArrayList<>();
                strs.add(InstallActivity.this.getIntent().getData().getPath());
                ArrayList<QScanResultEntity> results = InstallActivity.this.f981O.scanApks(strs, null, false);
                InstallActivity.this.f990X = results.get(0).certMd5;
                if (results.get(0).type != 3) {
                    InstallActivity.this.f992Z.sendEmptyMessageDelayed(0, 1000L);
                    return;
                }
                Message msg = new Message();
                msg.what = 1;
                msg.obj = results.get(0);
                Log.i("ww", results.get(0).discription);
                InstallActivity.this.f992Z.sendMessageDelayed(msg, 1000L);
            }
        }.start();
        TrackEvent.reportUseLeSafeAppInstallManager(this.f1011q);
    }

    public void translate(ImageView view) {
        Animation animation = AnimationUtils.loadAnimation(this, C0415R.anim.scanvirus_in_install);
        animation.setDuration(1000L);
        animation.setRepeatCount(-1);
        view.startAnimation(animation);
    }

    public void showVirusDesc(QScanResultEntity entity) {
        TextView txt_name = (TextView) findViewById(C0415R.id.virus_name);
        TextView virus_risk = (TextView) findViewById(C0415R.id.virus_risk);
        TextView virus_detail = (TextView) findViewById(C0415R.id.virus_detail);
        txt_name.setText(String.format(getString(C0415R.string.virus_name), entity.name));
        virus_risk.setText(C0415R.string.antivirusvirus_notifyadvice);
        virus_detail.setText(entity.discription);
        virus_detail.setOnClickListener(this);
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this.f1009o);
    }

    /* JADX WARN: Type inference failed for: r0v13, types: [com.lenovo.install.InstallActivity$5] */
    /* JADX WARN: Type inference failed for: r0v22, types: [com.lenovo.install.InstallActivity$6] */
    public void initAfterScan() {
        boolean z;
        Iterator<ApplicationInfo> it = this.f993a.getInstalledApplications(0).iterator();
        while (true) {
            if (!it.hasNext()) {
                z = false;
                break;
            }
            ApplicationInfo next = it.next();
            if (next.packageName.equals(this.f1011q)) {
                final ArrayList arrayList = new ArrayList();
                arrayList.add(next.sourceDir);
                new Thread() { // from class: com.lenovo.install.InstallActivity.6
                    @Override // java.lang.Thread, java.lang.Runnable
                    public final void run() {
                        ArrayList<QScanResultEntity> results = InstallActivity.this.f981O.scanApks(arrayList, null, false);
                        InstallActivity.this.f991Y = results.get(0).certMd5;
                    }
                }.start();
                z = true;
                break;
            }
        }
        if (z) {
            this.f980N.setVisibility(0);
        }
        if (WhiteAppsList.contains(WhiteAppsList.md5s, this.f990X)) {
            this.f992Z.sendMessage(this.f992Z.obtainMessage(7));
            return;
        }
        if (TextUtils.isEmpty(Const.LENOVO_APKS)) {
            Const.LENOVO_APKS = WhiteAppsList.getWhiteList(this, "lenovoapks");
        }
        if (Const.LENOVO_APKS.contains(this.f1011q + "\n")) {
            this.f992Z.sendMessage(this.f992Z.obtainMessage(7));
        } else if (this.f984R) {
            new Thread() { // from class: com.lenovo.install.InstallActivity.5
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    Map<String, Integer> map = InstallActivity.this.f1010p.getAppperms(InstallActivity.this.f1011q);
                    for (PermissionInfo perm : InstallActivity.this.f1012r) {
                        InstallActivity installActivity = InstallActivity.this;
                        if (!InstallActivity.m152a(InstallActivity.this.f975I, AppDatabase.PERM_TYPE_PRIVCY)) {
                            InstallActivity installActivity2 = InstallActivity.this;
                            if (InstallActivity.m151a(perm.name)) {
                                InstallActivity.m185z(InstallActivity.this);
                                AppInfo app = new AppInfo();
                                app.appType = AppDatabase.PERM_TYPE_PRIVCY;
                                if (map.get(AppDatabase.PERM_TYPE_PRIVCY) == null) {
                                    app.selected = 0;
                                } else {
                                    app.selected = map.get(AppDatabase.PERM_TYPE_PRIVCY).intValue();
                                }
                                InstallActivity.this.f975I.add(app);
                            }
                        }
                        InstallActivity installActivity3 = InstallActivity.this;
                        if (!InstallActivity.m152a(InstallActivity.this.f975I, "location")) {
                            InstallActivity installActivity4 = InstallActivity.this;
                            if (InstallActivity.m159b(perm.name)) {
                                InstallActivity.m185z(InstallActivity.this);
                                AppInfo app2 = new AppInfo();
                                app2.appType = "location";
                                if (map.get("location") == null) {
                                    app2.selected = 0;
                                } else {
                                    app2.selected = map.get("location").intValue();
                                }
                                InstallActivity.this.f975I.add(app2);
                            }
                        }
                        InstallActivity installActivity5 = InstallActivity.this;
                        if (!InstallActivity.m152a(InstallActivity.this.f975I, AppDatabase.PERM_TYPE_DEVICE) && (perm.name.equals("android.permission.RECORD_AUDIO") || perm.name.equals("android.permission.CAMERA"))) {
                            InstallActivity.m185z(InstallActivity.this);
                            AppInfo app3 = new AppInfo();
                            app3.appType = AppDatabase.PERM_TYPE_DEVICE;
                            if (map.get(AppDatabase.PERM_TYPE_DEVICE) == null) {
                                app3.selected = 0;
                            } else {
                                app3.selected = map.get(AppDatabase.PERM_TYPE_DEVICE).intValue();
                            }
                            InstallActivity.this.f975I.add(app3);
                        }
                        InstallActivity installActivity6 = InstallActivity.this;
                        if (!InstallActivity.m152a(InstallActivity.this.f975I, AppDatabase.DB_APP_CALL) && (perm.name.equals("android.permission.CALL_PHONE") || perm.name.equals("android.permission.CALL_PRIVILEGED"))) {
                            InstallActivity.m185z(InstallActivity.this);
                            AppInfo app4 = new AppInfo();
                            app4.appType = AppDatabase.DB_APP_CALL;
                            if (map.get(AppDatabase.DB_APP_CALL) == null) {
                                app4.selected = 0;
                            } else {
                                app4.selected = map.get(AppDatabase.DB_APP_CALL).intValue();
                            }
                            InstallActivity.this.f975I.add(app4);
                        }
                        if (perm.name.equals("android.permission.SEND_SMS")) {
                            InstallActivity.m185z(InstallActivity.this);
                            AppInfo app5 = new AppInfo();
                            app5.appType = AppDatabase.DB_APP_SENDMESSAGE;
                            if (map.get(AppDatabase.DB_APP_SENDMESSAGE) == null) {
                                app5.selected = 0;
                            } else {
                                app5.selected = map.get(AppDatabase.DB_APP_SENDMESSAGE).intValue();
                            }
                            InstallActivity.this.f975I.add(app5);
                        }
                        if (perm.name.equals("android.permission.RECEIVE_BOOT_COMPLETED")) {
                            InstallActivity.m141A(InstallActivity.this);
                        }
                    }
                    if (InstallActivity.this.f983Q) {
                        int len = InstallActivity.this.f975I.size();
                        InstallActivity.this.f971E = new RelativeLayout[len];
                        InstallActivity.this.f972F = new LinearLayout[len];
                        InstallActivity.this.f973G = new ImageView[len];
                        InstallActivity.this.f974H = new TextView[len];
                        InstallActivity.this.f992Z.sendMessage(InstallActivity.this.f992Z.obtainMessage(2));
                        return;
                    }
                    InstallActivity.this.f992Z.sendMessage(InstallActivity.this.f992Z.obtainMessage(7));
                }
            }.start();
        } else {
            this.f992Z.sendMessage(this.f992Z.obtainMessage(7));
        }
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        if (this.f981O != null) {
            try {
                this.f981O.freeScanner();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.allow /* 2131296869 */:
                this.f995ab.dismiss();
                this.f975I.get(this.f982P).selected = 0;
                this.f992Z.sendMessage(this.f992Z.obtainMessage(3));
                break;
            case C0415R.id.tip /* 2131296871 */:
                this.f995ab.dismiss();
                this.f975I.get(this.f982P).selected = 2;
                this.f992Z.sendMessage(this.f992Z.obtainMessage(3));
                break;
            case C0415R.id.deny /* 2131296873 */:
                this.f995ab.dismiss();
                this.f975I.get(this.f982P).selected = 1;
                this.f992Z.sendMessage(this.f992Z.obtainMessage(3));
                break;
            case C0415R.id.btn_cancel /* 2131296947 */:
                finish();
                break;
            case C0415R.id.virus_detail_view /* 2131297112 */:
                if (this.f994aa == 0) {
                    this.f994aa = 1;
                    ((TextView) findViewById(C0415R.id.virus_detail)).setSingleLine(false);
                    ((ImageView) findViewById(C0415R.id.virus_detail_img)).setBackgroundResource(C0415R.drawable.arrow_up);
                } else {
                    this.f994aa = 0;
                    ((TextView) findViewById(C0415R.id.virus_detail)).setSingleLine(true);
                    ((ImageView) findViewById(C0415R.id.virus_detail_img)).setBackgroundResource(C0415R.drawable.arrow_down);
                }
                break;
            case C0415R.id.btn_install /* 2131297135 */:
                if (this.f984R) {
                    if (!TextUtils.isEmpty(this.f991Y) && !this.f991Y.equals(this.f990X)) {
                        startActivity(new Intent(this, (Class<?>) InstallErrorActivity.class).putExtra("uri", getIntent().getData().toString()));
                        finish();
                    } else if (this.f1011q.equals(TrafficStatsService.PACKAGE_NAME)) {
                        Uri uri = Uri.parse("file://" + getIntent().getData().getPath());
                        Intent it = new Intent("android.intent.action.VIEW", uri);
                        it.setData(uri);
                        it.addFlags(1);
                        it.setClassName("com.android.packageinstaller", "com.android.packageinstaller.PackageInstallerActivity");
                        startActivity(it);
                        finish();
                    } else {
                        startActivity(new Intent(this, (Class<?>) InstallProgress.class).putExtra("uri", getIntent().getData().toString()).putExtra("has_virus", this.f988V).putExtra("has_boot", this.f989W));
                        finish();
                    }
                } else {
                    Uri uri2 = Uri.parse("file://" + getIntent().getData().getPath());
                    Intent it2 = new Intent("android.intent.action.VIEW", uri2);
                    it2.setData(uri2);
                    it2.addFlags(1);
                    it2.setClassName("com.android.packageinstaller", "com.android.packageinstaller.PackageInstallerActivity");
                    startActivity(it2);
                    finish();
                }
                break;
            case C0415R.id.btn_detail /* 2131297138 */:
                startActivity(new Intent(this, (Class<?>) ShowPkgInfoActivity.class).putExtra("uri", getIntent().getData().toString()));
                break;
            default:
                for (int i = 0; i < this.f975I.size(); i++) {
                    if (v == this.f972F[i]) {
                        this.f982P = i;
                        String type = this.f975I.get(i).appType;
                        if (type.equals(AppDatabase.DB_APP_SENDMESSAGE)) {
                            showPopupMenu();
                        } else {
                            if (this.f975I.get(i).selected == 1) {
                                this.f975I.get(i).selected = 0;
                            } else {
                                this.f975I.get(i).selected = 1;
                            }
                            this.f992Z.sendMessage(this.f992Z.obtainMessage(3));
                        }
                    }
                }
                break;
        }
    }

    /* JADX WARN: Type inference failed for: r0v0, types: [com.lenovo.install.InstallActivity$7] */
    @Override // android.app.Activity
    protected void onPause() {
        super.onPause();
        new Thread() { // from class: com.lenovo.install.InstallActivity.7
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                int appTrust = InstallActivity.this.f1010p.getAppTrusted(InstallActivity.this.f1011q);
                if (appTrust == 1) {
                    for (int i = 0; i < InstallActivity.this.f975I.size(); i++) {
                        if (((AppInfo) InstallActivity.this.f975I.get(i)).selected > 0) {
                            appTrust = 0;
                            break;
                        }
                    }
                }
                HashMap map = new HashMap();
                for (int i2 = 0; i2 < InstallActivity.this.f975I.size(); i2++) {
                    ((AppInfo) InstallActivity.this.f975I.get(i2)).trusted = appTrust;
                    if (!((AppInfo) InstallActivity.this.f975I.get(i2)).appType.equals(AppDatabase.PERM_TYPE_PRIVCY)) {
                        if (!((AppInfo) InstallActivity.this.f975I.get(i2)).appType.equals("location")) {
                            if (!((AppInfo) InstallActivity.this.f975I.get(i2)).appType.equals(AppDatabase.PERM_TYPE_DEVICE)) {
                                if (!((AppInfo) InstallActivity.this.f975I.get(i2)).appType.equals(AppDatabase.DB_APP_CALL)) {
                                    if (((AppInfo) InstallActivity.this.f975I.get(i2)).appType.equals(AppDatabase.DB_APP_SENDMESSAGE)) {
                                        map.put(AppDatabase.DB_APP_SENDMESSAGE, InstallActivity.this.f975I.get(i2));
                                    }
                                } else {
                                    map.put(AppDatabase.DB_APP_CALL, InstallActivity.this.f975I.get(i2));
                                }
                            } else {
                                map.put(AppDatabase.PERM_TYPE_DEVICE, InstallActivity.this.f975I.get(i2));
                            }
                        } else {
                            map.put("location", InstallActivity.this.f975I.get(i2));
                        }
                    } else {
                        map.put(AppDatabase.PERM_TYPE_PRIVCY, InstallActivity.this.f975I.get(i2));
                    }
                }
                PackageUtil.newAppMap.put(InstallActivity.this.f1011q, map);
            }
        }.start();
        TrackEvent.trackPause(this.f1009o);
    }

    /* JADX INFO: renamed from: c */
    private View m160c(String str) {
        View view1 = LayoutInflater.from(this).inflate(C0415R.layout.permission_detail_item, (ViewGroup) null);
        TextView txtnumber = (TextView) view1.findViewById(C0415R.id.tab_name);
        txtnumber.setText(str);
        return view1;
    }

    public void changePopState(String appType) {
        this.f998d = !this.f998d;
        if (this.f998d) {
            popAwindow(appType);
        } else if (this.f1008n != null) {
            this.f1008n.dismiss();
        }
    }

    public void popAwindow(String appType) {
        this.f999e = !this.f1007m.getBoolean("next_notip", false);
        View v = ((LayoutInflater) getSystemService("layout_inflater")).inflate(C0415R.layout.install_popup, (ViewGroup) null);
        TextView text1 = (TextView) v.findViewById(C0415R.id.content1);
        String str = "";
        if (appType.equals(AppDatabase.PERM_TYPE_PRIVCY)) {
            str = String.format(getString(C0415R.string.safe_tip), this.f997c.f1060a, String.format(getString(C0415R.string.privacy_detail2), this.f985S), getString(C0415R.string.permission_control));
        } else if (appType.equals("location")) {
            str = String.format(getString(C0415R.string.safe_tip), this.f997c.f1060a, getString(C0415R.string.get_phoneloc), getString(C0415R.string.permission_control));
        } else if (appType.equals(AppDatabase.PERM_TYPE_DEVICE)) {
            str = String.format(getString(C0415R.string.safe_tip), this.f997c.f1060a, getString(C0415R.string.perm_tap_calling), getString(C0415R.string.permission_control));
        } else if (appType.equals(AppDatabase.DB_APP_CALL)) {
            str = String.format(getString(C0415R.string.safe_tip), this.f997c.f1060a, getString(C0415R.string.perm_call), getString(C0415R.string.charge_safe));
        } else if (appType.equals(AppDatabase.DB_APP_SENDMESSAGE)) {
            str = String.format(getString(C0415R.string.safe_tip), this.f997c.f1060a, getString(C0415R.string.perm_send_sms), getString(C0415R.string.charge_safe));
        }
        text1.setText(str);
        final ImageView imageView = (ImageView) v.findViewById(C0415R.id.img_checkbox);
        imageView.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.install.InstallActivity.8
            @Override // android.view.View.OnClickListener
            public final void onClick(View v2) {
                InstallActivity.this.f999e = !InstallActivity.this.f999e;
                if (InstallActivity.this.f999e) {
                    imageView.setBackgroundResource(C0415R.drawable.checkbox_check);
                } else {
                    imageView.setBackgroundResource(C0415R.drawable.checkbox_nocheck);
                }
            }
        });
        ((TextView) v.findViewById(C0415R.id.neutralButton)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.install.InstallActivity.9
            @Override // android.view.View.OnClickListener
            public final void onClick(View v2) {
                InstallActivity.this.f1007m.edit().putBoolean("next_notip", InstallActivity.this.f999e).commit();
                InstallActivity.this.f1008n.dismiss();
            }
        });
        this.f1008n = new PopupWindow(v, -2, -2, true);
        this.f1008n.setBackgroundDrawable(new BitmapDrawable());
        this.f1008n.setFocusable(true);
        this.f1008n.setOutsideTouchable(true);
        this.f1008n.setOnDismissListener(new PopupWindow.OnDismissListener() { // from class: com.lenovo.install.InstallActivity.2
            @Override // android.widget.PopupWindow.OnDismissListener
            public final void onDismiss() {
                InstallActivity.m144D(InstallActivity.this);
                InstallActivity.this.f998d = false;
            }
        });
        this.f1008n.showAtLocation(findViewById(C0415R.id.layout_bottom), 80, 0, 70);
        this.f1008n.update();
    }

    public void showPopupMenu() {
        this.f998d = !this.f998d;
        if (this.f998d) {
            this.f969C.setBackgroundResource(C0415R.drawable.arrow_up);
            View viewInflate = ((LayoutInflater) getSystemService("layout_inflater")).inflate(C0415R.layout.changeitemxml, (ViewGroup) null);
            ((ImageView) viewInflate.findViewById(C0415R.id.grant_img)).setBackgroundResource(C0415R.drawable.perm_grant1);
            ((ImageView) viewInflate.findViewById(C0415R.id.prompt_img)).setBackgroundResource(C0415R.drawable.perm_prompt1);
            ((ImageView) viewInflate.findViewById(C0415R.id.deny_img)).setBackgroundResource(C0415R.drawable.perm_deny1);
            LinearLayout linearLayout = (LinearLayout) viewInflate.findViewById(C0415R.id.allow);
            LinearLayout linearLayout2 = (LinearLayout) viewInflate.findViewById(C0415R.id.tip);
            LinearLayout linearLayout3 = (LinearLayout) viewInflate.findViewById(C0415R.id.deny);
            linearLayout.setBackgroundResource(C0415R.drawable.msg_btn_bg);
            linearLayout2.setBackgroundResource(C0415R.drawable.msg_btn_bg);
            linearLayout3.setBackgroundResource(C0415R.drawable.msg_btn_bg);
            linearLayout.setOnClickListener(this);
            linearLayout2.setOnClickListener(this);
            linearLayout3.setOnClickListener(this);
            this.f995ab = new PopupWindow(viewInflate, -1, -2, true);
            this.f995ab.setAnimationStyle(C0415R.style.PopupAnimation);
            this.f995ab.setBackgroundDrawable(new BitmapDrawable());
            this.f995ab.setFocusable(true);
            this.f995ab.setOutsideTouchable(true);
            this.f995ab.setOnDismissListener(new PopupWindow.OnDismissListener() { // from class: com.lenovo.install.InstallActivity.3
                @Override // android.widget.PopupWindow.OnDismissListener
                public final void onDismiss() {
                    InstallActivity.m145E(InstallActivity.this);
                    InstallActivity.this.f998d = false;
                    InstallActivity.this.f969C.setBackgroundResource(C0415R.drawable.arrow_down);
                }
            });
            this.f995ab.showAsDropDown(findViewById(C0415R.id.sendmsg_layout));
            this.f995ab.update();
            return;
        }
        if (this.f1008n != null) {
            this.f1008n.dismiss();
        }
    }
}
