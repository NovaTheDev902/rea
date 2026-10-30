package com.lenovo.safecenter.antivirus.views;

import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.ApplicationInfo;
import android.graphics.drawable.Drawable;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.preference.PreferenceManager;
import android.text.format.Formatter;
import android.util.Log;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.TranslateAnimation;
import android.widget.BaseExpandableListAdapter;
import android.widget.Button;
import android.widget.ExpandableListView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.antivirus.domain.Appinfo;
import com.lenovo.safecenter.antivirus.domain.PermAdapter;
import com.lenovo.safecenter.antivirus.domain.ScanInfo;
import com.lenovo.safecenter.antivirus.domain.Virus;
import com.lenovo.safecenter.antivirus.domain.VirusDemo;
import com.lenovo.safecenter.antivirus.support.AntiVirusDBHelper;
import com.lenovo.safecenter.antivirus.utils.AppUtils;
import com.lenovo.safecenter.antivirus.utils.HttpUtils;
import com.lenovo.safecenter.antivirus.utils.ScanUtils;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.utils.LeSafeObservable;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.qscanner.QScanListener;
import com.tencent.tmsecure.module.qscanner.QScanResultEntity;
import com.tencent.tmsecure.module.qscanner.QScannerManager;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Set;

/* JADX INFO: loaded from: classes.dex */
public class FullSystemScanActivity extends BaseTitleActivity {

    /* JADX INFO: renamed from: C */
    private Button f3124C;

    /* JADX INFO: renamed from: D */
    private Button f3125D;

    /* JADX INFO: renamed from: E */
    private Button f3126E;

    /* JADX INFO: renamed from: F */
    private Button f3127F;

    /* JADX INFO: renamed from: G */
    private Button f3128G;

    /* JADX INFO: renamed from: H */
    private C0490c f3129H;

    /* JADX INFO: renamed from: I */
    private String f3130I;

    /* JADX INFO: renamed from: J */
    private LinearLayout f3131J;

    /* JADX INFO: renamed from: K */
    private LinearLayout f3132K;

    /* JADX INFO: renamed from: L */
    private LinearLayout f3133L;

    /* JADX INFO: renamed from: M */
    private LinearLayout f3134M;

    /* JADX INFO: renamed from: N */
    private LinearLayout f3135N;

    /* JADX INFO: renamed from: P */
    private AntiVirusDBHelper f3137P;

    /* JADX INFO: renamed from: Q */
    private Button f3138Q;

    /* JADX INFO: renamed from: S */
    private ImageView f3140S;

    /* JADX INFO: renamed from: T */
    private long f3141T;

    /* JADX INFO: renamed from: U */
    private long f3142U;

    /* JADX INFO: renamed from: W */
    private TranslateAnimation f3144W;

    /* JADX INFO: renamed from: X */
    private ImageView f3145X;

    /* JADX INFO: renamed from: Y */
    private QScannerManager f3146Y;

    /* JADX INFO: renamed from: a */
    private ProgressBar f3148a;

    /* JADX INFO: renamed from: ab */
    private List<ApplicationInfo> f3150ab;

    /* JADX INFO: renamed from: ad */
    private C0491d f3152ad;

    /* JADX INFO: renamed from: ag */
    private boolean f3155ag;

    /* JADX INFO: renamed from: j */
    private String f3164j;

    /* JADX INFO: renamed from: k */
    private TextView f3165k;

    /* JADX INFO: renamed from: l */
    private TextView f3166l;

    /* JADX INFO: renamed from: m */
    private TextView f3167m;

    /* JADX INFO: renamed from: n */
    private RelativeLayout f3168n;

    /* JADX INFO: renamed from: o */
    private TextView f3169o;

    /* JADX INFO: renamed from: p */
    private TextView f3170p;

    /* JADX INFO: renamed from: q */
    private ListView f3171q;

    /* JADX INFO: renamed from: r */
    private C0489b f3172r;

    /* JADX INFO: renamed from: s */
    private ExpandableListView f3173s;

    /* JADX INFO: renamed from: t */
    private TextView f3174t;

    /* JADX INFO: renamed from: u */
    private List<VirusDemo> f3175u;

    /* JADX INFO: renamed from: v */
    private C0492e f3176v;

    /* JADX INFO: renamed from: w */
    private List<Virus> f3177w;

    /* JADX INFO: renamed from: y */
    private HashMap<String, QScanResultEntity> f3179y;

    /* JADX INFO: renamed from: z */
    private PermAdapter f3180z;

    /* JADX INFO: renamed from: b */
    private int f3156b = 0;

    /* JADX INFO: renamed from: c */
    private int f3157c = 0;

    /* JADX INFO: renamed from: d */
    private int f3158d = 0;

    /* JADX INFO: renamed from: e */
    private boolean f3159e = false;

    /* JADX INFO: renamed from: f */
    private boolean f3160f = true;

    /* JADX INFO: renamed from: g */
    private int f3161g = -1;

    /* JADX INFO: renamed from: h */
    private List<List<Virus>> f3162h = new ArrayList();

    /* JADX INFO: renamed from: i */
    private List<String> f3163i = new ArrayList();

    /* JADX INFO: renamed from: x */
    private List<ScanInfo> f3178x = new ArrayList();

    /* JADX INFO: renamed from: A */
    private boolean f3122A = false;

    /* JADX INFO: renamed from: B */
    private String f3123B = "";

    /* JADX INFO: renamed from: O */
    private List<Appinfo> f3136O = new ArrayList();

    /* JADX INFO: renamed from: R */
    private boolean f3139R = false;

    /* JADX INFO: renamed from: V */
    private int f3143V = 0;

    /* JADX INFO: renamed from: Z */
    private boolean f3147Z = false;

    /* JADX INFO: renamed from: aa */
    private boolean f3149aa = false;

    /* JADX INFO: renamed from: ac */
    private int f3151ac = 0;

    /* JADX INFO: renamed from: ae */
    private Handler f3153ae = new Handler() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.1
        /* JADX WARN: Type inference failed for: r21v101, types: [com.lenovo.safecenter.antivirus.views.FullSystemScanActivity$1$1] */
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            super.handleMessage(msg);
            switch (msg.what) {
                case 0:
                    if (FullSystemScanActivity.this.f3154af) {
                        FullSystemScanActivity.m1372b(FullSystemScanActivity.this);
                        FullSystemScanActivity.m1377c(FullSystemScanActivity.this);
                        QScanResultEntity scanResult = (QScanResultEntity) msg.obj;
                        int progress = msg.arg1;
                        FullSystemScanActivity.this.f3123B = FullSystemScanActivity.this.getResources().getString(C0415R.string.antivirushasScaned);
                        FullSystemScanActivity.this.f3174t.setText(String.format(FullSystemScanActivity.this.f3123B, Integer.valueOf(FullSystemScanActivity.this.f3156b - 1), Integer.valueOf(FullSystemScanActivity.this.f3157c)));
                        FullSystemScanActivity.this.f3148a.setVisibility(0);
                        FullSystemScanActivity.this.f3148a.setProgress(progress);
                        String percentStr = String.format(FullSystemScanActivity.this.f3164j, Integer.valueOf(progress / FullSystemScanActivity.this.f3148a.getMax()));
                        FullSystemScanActivity.this.f3165k.setText(percentStr);
                        if (scanResult.apkType == 1) {
                            FullSystemScanActivity.this.f3178x.add(new ScanInfo(scanResult.packageName, scanResult.softName, false));
                        } else {
                            FullSystemScanActivity.this.f3178x.add(new ScanInfo(scanResult.packageName, scanResult.softName, scanResult.type == 3));
                        }
                        FullSystemScanActivity.this.f3180z.notifyDataSetChanged();
                        FullSystemScanActivity.this.f3171q.setSelectionFromTop(FullSystemScanActivity.this.f3178x.size() - 1, 0);
                    } else {
                        FullSystemScanActivity.m1372b(FullSystemScanActivity.this);
                        FullSystemScanActivity.m1377c(FullSystemScanActivity.this);
                        FullSystemScanActivity.this.f3123B = FullSystemScanActivity.this.getResources().getString(C0415R.string.antivirushasScaned);
                        FullSystemScanActivity.this.f3174t.setText(String.format(FullSystemScanActivity.this.f3123B, Integer.valueOf(FullSystemScanActivity.this.f3156b - 1), Integer.valueOf(FullSystemScanActivity.this.f3157c)));
                        FullSystemScanActivity.this.f3148a.setVisibility(0);
                        int percent = (FullSystemScanActivity.this.f3156b * 100) / FullSystemScanActivity.this.f3151ac;
                        FullSystemScanActivity.this.f3148a.setProgress(percent);
                        String percentStr2 = String.format(FullSystemScanActivity.this.f3164j, Integer.valueOf(percent));
                        FullSystemScanActivity.this.f3165k.setText(percentStr2);
                        FullSystemScanActivity.this.f3178x.add(new ScanInfo((ApplicationInfo) FullSystemScanActivity.this.f3150ab.get(FullSystemScanActivity.this.f3156b - 1), msg.getData().getBoolean("isvirus")));
                        FullSystemScanActivity.this.f3180z.notifyDataSetChanged();
                        FullSystemScanActivity.this.f3171q.setSelectionFromTop(FullSystemScanActivity.this.f3178x.size() - 1, 0);
                    }
                    break;
                case 1:
                    FullSystemScanActivity.this.f3133L.setVisibility(8);
                    FullSystemScanActivity.this.f3135N.setVisibility(8);
                    HttpUtils.UpdateConfig("scantime", String.valueOf(System.currentTimeMillis()), FullSystemScanActivity.this);
                    if (PreferenceManager.getDefaultSharedPreferences(FullSystemScanActivity.this).getInt("netScan_switch", 1) != 1) {
                        FullSystemScanActivity.this.f3153ae.sendEmptyMessage(9);
                    } else if (ScanUtils.isNetworkAvailable(FullSystemScanActivity.this)) {
                        FullSystemScanActivity.this.f3153ae.sendEmptyMessage(7);
                    } else {
                        FullSystemScanActivity.this.f3153ae.sendEmptyMessage(9);
                        try {
                            FullSystemScanActivity.this.openNetworkSettings();
                        } catch (Exception e) {
                            e.printStackTrace();
                            return;
                        }
                    }
                    break;
                case 2:
                    if (FullSystemScanActivity.this.f3160f) {
                        FullSystemScanActivity.this.f3161g = 3;
                        FullSystemScanActivity.this.f3169o.setText(C0415R.string.antivirusvirus_isgoing);
                        FullSystemScanActivity.this.f3153ae.sendEmptyMessage(FullSystemScanActivity.this.f3161g);
                        FullSystemScanActivity.this.f3178x.add(new ScanInfo());
                        FullSystemScanActivity.this.f3180z.notifyDataSetChanged();
                        FullSystemScanActivity.this.f3171q.setSelectionFromTop(0, 0);
                    }
                    break;
                case 3:
                    if (FullSystemScanActivity.this.f3160f) {
                        FullSystemScanActivity.this.f3161g++;
                        FullSystemScanActivity.this.f3153ae.sendEmptyMessage(FullSystemScanActivity.this.f3161g);
                        FullSystemScanActivity.this.f3178x.add(new ScanInfo());
                        FullSystemScanActivity.this.f3180z.notifyDataSetChanged();
                        FullSystemScanActivity.this.f3171q.setSelectionFromTop(1, 0);
                    }
                    break;
                case 4:
                    if (FullSystemScanActivity.this.f3160f) {
                        if (FullSystemScanActivity.this.f3154af) {
                            FullSystemScanActivity.this.f3161g++;
                            FullSystemScanActivity.this.f3153ae.sendEmptyMessage(FullSystemScanActivity.this.f3161g);
                            FullSystemScanActivity.this.f3178x.add(new ScanInfo());
                            FullSystemScanActivity.this.f3180z.notifyDataSetChanged();
                            FullSystemScanActivity.this.f3171q.setSelectionFromTop(2, 0);
                        } else {
                            FullSystemScanActivity.this.f3150ab = AppUtils.getInstalledApps(FullSystemScanActivity.this);
                            FullSystemScanActivity.this.f3151ac = FullSystemScanActivity.this.f3150ab.size();
                            FullSystemScanActivity.this.f3152ad = FullSystemScanActivity.this.new C0491d(0, FullSystemScanActivity.this.f3151ac);
                            FullSystemScanActivity.this.f3161g++;
                            FullSystemScanActivity.this.f3153ae.sendEmptyMessage(FullSystemScanActivity.this.f3161g);
                            FullSystemScanActivity.this.f3178x.add(new ScanInfo());
                            FullSystemScanActivity.this.f3180z.notifyDataSetChanged();
                            FullSystemScanActivity.this.f3171q.setSelectionFromTop(2, 0);
                        }
                    }
                    break;
                case 5:
                    if (FullSystemScanActivity.this.f3160f) {
                        if (FullSystemScanActivity.this.f3154af) {
                            FullSystemScanActivity.this.f3146Y = (QScannerManager) ManagerCreator.getManager(QScannerManager.class);
                            FullSystemScanActivity.this.f3169o.setText(C0415R.string.antivirusscaning);
                            FullSystemScanActivity.this.f3161g++;
                            try {
                                if (FullSystemScanActivity.this.f3129H == null || !FullSystemScanActivity.this.f3129H.isAlive() || !FullSystemScanActivity.this.f3147Z) {
                                    FullSystemScanActivity.this.f3129H = FullSystemScanActivity.this.new C0490c();
                                    FullSystemScanActivity.this.f3129H.start();
                                    FullSystemScanActivity.this.setGoing(true);
                                }
                            } catch (Exception e2) {
                                e2.printStackTrace();
                                return;
                            }
                        } else {
                            String virus_pkgname = HttpUtils.execService("viruspkgname", FullSystemScanActivity.this);
                            if (!virus_pkgname.equals("")) {
                                FullSystemScanActivity.this.f3157c = virus_pkgname.split(",").length;
                                if (!virus_pkgname.equalsIgnoreCase("")) {
                                    String[] arr$ = virus_pkgname.split(",");
                                    for (String vir : arr$) {
                                        FullSystemScanActivity.this.f3179y.put(vir, null);
                                    }
                                }
                            }
                            FullSystemScanActivity.this.f3169o.setText(C0415R.string.antivirusscaning);
                            FullSystemScanActivity.this.f3161g++;
                            try {
                                FullSystemScanActivity.this.f3152ad.m1402a(true);
                                FullSystemScanActivity.this.f3152ad.start();
                            } catch (Exception e3) {
                                e3.printStackTrace();
                                return;
                            }
                        }
                    }
                    break;
                case 7:
                    FullSystemScanActivity.this.f3169o.setText(C0415R.string.netscaning);
                    FullSystemScanActivity.this.findViewById(C0415R.id.antivirusscan_btn).setVisibility(8);
                    FullSystemScanActivity.this.findViewById(C0415R.id.antivirusnetscan_btn).setVisibility(0);
                    new Thread() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.1.1
                        @Override // java.lang.Thread, java.lang.Runnable
                        public final void run() {
                            FullSystemScanActivity.this.f3175u = new ScanUtils().cloudScanGlobal(FullSystemScanActivity.this.f3136O, FullSystemScanActivity.this);
                            if (FullSystemScanActivity.this.f3175u == null) {
                                FullSystemScanActivity.this.f3153ae.sendEmptyMessage(12);
                                FullSystemScanActivity.this.f3153ae.sendEmptyMessage(9);
                            } else {
                                FullSystemScanActivity.this.f3153ae.sendEmptyMessage(8);
                            }
                        }
                    }.start();
                    break;
                case 8:
                    Log.i("msg", "ScanUtils.isNetScan_cancel=" + ScanUtils.isNetScan_cancel + "case 8");
                    if (!ScanUtils.isNetScan_cancel) {
                        FullSystemScanActivity.m1336B(FullSystemScanActivity.this);
                        FullSystemScanActivity.this.f3169o.setText(C0415R.string.antivirussuccess_scan);
                        FullSystemScanActivity.this.f3166l.setVisibility(0);
                        if (FullSystemScanActivity.this.f3175u != null && FullSystemScanActivity.this.f3175u.size() > 0) {
                            for (VirusDemo v_str : FullSystemScanActivity.this.f3175u) {
                                if (!FullSystemScanActivity.this.f3179y.containsKey(v_str.getPkgName())) {
                                    FullSystemScanActivity.this.f3179y.put(v_str.getPkgName(), null);
                                    HttpUtils.UpdateConfig(AppUtils.getVirusDescKey(v_str.getPkgName()), v_str.getVirusDesc(), FullSystemScanActivity.this);
                                }
                            }
                            FullSystemScanActivity.this.f3157c = FullSystemScanActivity.this.f3179y.size();
                        }
                        StringBuilder sb = new StringBuilder();
                        Set<String> pkgs = FullSystemScanActivity.this.f3179y.keySet();
                        for (String pkg : pkgs) {
                            sb.append(pkg);
                            sb.append(",");
                        }
                        HttpUtils.UpdateConfig("viruspkgname", "", FullSystemScanActivity.this);
                        if (sb.length() > 0) {
                            HttpUtils.UpdateConfig("viruspkgname", sb.deleteCharAt(sb.length() - 1).toString(), FullSystemScanActivity.this);
                        }
                        FullSystemScanActivity.m1362a(FullSystemScanActivity.this, System.currentTimeMillis() - FullSystemScanActivity.this.f3141T);
                        FullSystemScanActivity.this.setView();
                        int sumdesc = FullSystemScanActivity.this.f3157c + FullSystemScanActivity.this.f3158d;
                        if (sumdesc == 0) {
                            LeSafeObservable.get(FullSystemScanActivity.this).noticeHasScanedVirus();
                            FullSystemScanActivity.this.f3169o.setText(C0415R.string.detail3_scaned_no_virus_home_page);
                            FullSystemScanActivity.this.f3166l.setVisibility(8);
                            FullSystemScanActivity.this.f3166l.setText(C0415R.string.antivirusscan_reslut1);
                            if (!FullSystemScanActivity.this.f3155ag) {
                                FullSystemScanActivity.this.f3137P.insertLog(FullSystemScanActivity.this.getString(C0415R.string.antiviruslogdescfull4), String.valueOf(System.currentTimeMillis()), "0");
                            }
                        } else {
                            LeSafeObservable.get(FullSystemScanActivity.this).noticeHasVirus();
                            if (!FullSystemScanActivity.this.f3155ag) {
                                FullSystemScanActivity.this.f3137P.insertLog(String.format(FullSystemScanActivity.this.getString(C0415R.string.antiviruslogdescpart5), Integer.valueOf(FullSystemScanActivity.this.f3157c)), String.valueOf(System.currentTimeMillis()), DatabaseTables.SYSTEM_MARK);
                            }
                            FullSystemScanActivity.this.f3166l.setText(String.format(FullSystemScanActivity.this.getString(C0415R.string.antivirusscan_reslut2), Integer.valueOf(sumdesc)));
                        }
                        ScanUtils.isNetScan_cancel = false;
                    }
                    break;
                case 9:
                    FullSystemScanActivity.this.f3169o.setText(C0415R.string.antivirussuccess_scanlocal);
                    FullSystemScanActivity.this.f3166l.setVisibility(0);
                    int sumdesc1 = FullSystemScanActivity.this.f3157c + FullSystemScanActivity.this.f3158d;
                    if (sumdesc1 == 0) {
                        FullSystemScanActivity.this.stopAnimation();
                        LeSafeObservable.get(FullSystemScanActivity.this).noticeKilledVirus();
                        FullSystemScanActivity.this.f3166l.setText(C0415R.string.detail3_scaned_no_virus_netscan);
                        if (!FullSystemScanActivity.this.f3155ag) {
                            FullSystemScanActivity.this.f3137P.insertLog(FullSystemScanActivity.this.getString(C0415R.string.antiviruslogdescfull4), String.valueOf(System.currentTimeMillis()), "0");
                        }
                    } else {
                        LeSafeObservable.get(FullSystemScanActivity.this).noticeHasVirus();
                        if (!FullSystemScanActivity.this.f3155ag) {
                            FullSystemScanActivity.this.f3137P.insertLog(String.format(FullSystemScanActivity.this.getString(C0415R.string.antiviruslogdescpart5), Integer.valueOf(FullSystemScanActivity.this.f3157c)), String.valueOf(System.currentTimeMillis()), DatabaseTables.SYSTEM_MARK);
                        }
                        FullSystemScanActivity.this.f3166l.setText(String.format(FullSystemScanActivity.this.getString(C0415R.string.antivirusscan_reslut2), Integer.valueOf(sumdesc1)));
                    }
                    HttpUtils.UpdateConfig("viruspkgname", "", FullSystemScanActivity.this);
                    if (FullSystemScanActivity.this.f3179y.size() > 0) {
                        StringBuilder sb2 = new StringBuilder();
                        Set<String> pkgs2 = FullSystemScanActivity.this.f3179y.keySet();
                        for (String pkg2 : pkgs2) {
                            sb2.append(pkg2);
                            sb2.append(",");
                        }
                        HttpUtils.UpdateConfig("viruspkgname", sb2.deleteCharAt(sb2.length() - 1).toString(), FullSystemScanActivity.this);
                    }
                    FullSystemScanActivity.this.setView();
                    break;
                case 11:
                    boolean play = Boolean.parseBoolean(msg.obj.toString());
                    if (play) {
                        FullSystemScanActivity.this.startAnimation();
                    } else {
                        FullSystemScanActivity.this.stopAnimation();
                    }
                    break;
                case 12:
                    Toast.makeText(FullSystemScanActivity.this, FullSystemScanActivity.this.getString(C0415R.string.antispamserver_disconnect), 0).show();
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: af */
    private boolean f3154af = false;

    /* JADX INFO: renamed from: B */
    static /* synthetic */ boolean m1336B(FullSystemScanActivity x0) {
        x0.f3139R = true;
        return true;
    }

    /* JADX INFO: renamed from: P */
    static /* synthetic */ int m1350P(FullSystemScanActivity x0) {
        x0.f3156b = 0;
        return 0;
    }

    /* JADX INFO: renamed from: R */
    static /* synthetic */ boolean m1352R(FullSystemScanActivity x0) {
        x0.f3160f = false;
        return false;
    }

    /* JADX INFO: renamed from: T */
    static /* synthetic */ void m1354T(FullSystemScanActivity x0) {
        if (!x0.f3122A) {
            new CustomDialog.Builder(x0).setTitle(C0415R.string.antivirusresulttitle).setMessage(String.format(x0.getResources().getString(C0415R.string.antivirushasScaned), Integer.valueOf(x0.f3156b), Integer.valueOf(x0.f3157c))).setPositiveButton(C0415R.string.sumbit, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.11
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface dialog, int which) {
                    FullSystemScanActivity.m1350P(FullSystemScanActivity.this);
                    LeSafeObservable.get(FullSystemScanActivity.this).noticeKilledVirus();
                    FullSystemScanActivity.this.freeManage();
                    FullSystemScanActivity.this.finish();
                    System.gc();
                }
            }).create().show();
            return;
        }
        if (x0.f3159e) {
            return;
        }
        View viewInflate = LayoutInflater.from(x0).inflate(C0415R.layout.antivirusshowviruwresult, (ViewGroup) null);
        TextView textView = (TextView) viewInflate.findViewById(C0415R.id.antivirusreuslt_total);
        TextView textView2 = (TextView) viewInflate.findViewById(C0415R.id.antivirusresult_viruscount);
        TextView textView3 = (TextView) viewInflate.findViewById(C0415R.id.antivirusreuslt_hitcount);
        String string = x0.getString(C0415R.string.antivirustotalresult);
        String string2 = x0.getString(C0415R.string.antivirusviruscount);
        String string3 = x0.getString(C0415R.string.antivirushitcount);
        String str = String.format(string, Integer.valueOf(x0.f3156b));
        String str2 = String.format(string2, Integer.valueOf(x0.f3157c));
        String str3 = String.format(string3, Integer.valueOf(x0.f3158d));
        textView.setText(str);
        textView2.setText(str2);
        textView3.setText(str3);
        new CustomDialog.Builder(x0).setTitle(C0415R.string.antivirusresulttitle).setContentView(viewInflate).setPositiveButton(x0.getString(C0415R.string.antivirusappvirus_nowdeal), new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.10
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                Intent showVirus = new Intent(FullSystemScanActivity.this, (Class<?>) ScanVirusActivity.class);
                Bundle bundle = new Bundle();
                bundle.putStringArrayList("virusPackageNameList", new ArrayList<>(FullSystemScanActivity.this.f3179y.keySet()));
                showVirus.putExtras(bundle);
                FullSystemScanActivity.this.startActivity(showVirus);
                FullSystemScanActivity.m1350P(FullSystemScanActivity.this);
                LeSafeObservable.get(FullSystemScanActivity.this).noticeHasVirus();
                FullSystemScanActivity.this.freeManage();
                FullSystemScanActivity.this.finish();
                System.gc();
            }
        }).setNegativeButton(C0415R.string.antivirusappvirus_nodeal, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.9
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                FullSystemScanActivity.m1350P(FullSystemScanActivity.this);
                LeSafeObservable.get(FullSystemScanActivity.this).noticeHasVirus();
                FullSystemScanActivity.this.freeManage();
                FullSystemScanActivity.this.finish();
                System.gc();
            }
        }).create().show();
    }

    /* JADX INFO: renamed from: Y */
    static /* synthetic */ boolean m1359Y(FullSystemScanActivity x0) {
        x0.f3122A = true;
        return true;
    }

    /* JADX INFO: renamed from: Z */
    static /* synthetic */ int m1360Z(FullSystemScanActivity x0) {
        int i = x0.f3157c;
        x0.f3157c = i + 1;
        return i;
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ long m1362a(FullSystemScanActivity x0, long x1) {
        long j = x0.f3142U + x1;
        x0.f3142U = j;
        return j;
    }

    /* JADX INFO: renamed from: b */
    static /* synthetic */ int m1372b(FullSystemScanActivity x0) {
        int i = x0.f3143V;
        x0.f3143V = i + 1;
        return i;
    }

    /* JADX INFO: renamed from: c */
    static /* synthetic */ int m1377c(FullSystemScanActivity x0) {
        int i = x0.f3156b;
        x0.f3156b = i + 1;
        return i;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity$b */
    class C0489b extends BroadcastReceiver {

        /* JADX INFO: renamed from: a */
        Context f3202a;

        public C0489b(Context c) {
            this.f3202a = c;
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals("android.intent.action.PACKAGE_REMOVED")) {
                String packageName = intent.getDataString().substring(8);
                for (int i = 0; i < FullSystemScanActivity.this.f3162h.size(); i++) {
                    for (int k = 0; k < ((List) FullSystemScanActivity.this.f3162h.get(i)).size(); k++) {
                        if (((Virus) ((List) FullSystemScanActivity.this.f3162h.get(i)).get(k)).getPackageName().equals(packageName)) {
                            ((Virus) ((List) FullSystemScanActivity.this.f3162h.get(i)).get(k)).setOperate(true);
                            FullSystemScanActivity.this.f3173s.invalidateViews();
                        }
                    }
                }
                FullSystemScanActivity.this.f3179y.remove(packageName);
                if (FullSystemScanActivity.this.f3157c > 0 && FullSystemScanActivity.this.f3179y.size() == 0) {
                    LeSafeObservable.get(FullSystemScanActivity.this).noticeKilledVirus();
                    FullSystemScanActivity.this.f3173s.setVisibility(8);
                    FullSystemScanActivity.this.f3167m.setText(String.format(FullSystemScanActivity.this.getString(C0415R.string.virusdeal_all), Integer.valueOf(FullSystemScanActivity.this.f3157c)));
                    FullSystemScanActivity.this.f3167m.setVisibility(0);
                    FullSystemScanActivity.this.f3168n.setVisibility(0);
                    FullSystemScanActivity.this.f3132K.setVisibility(8);
                    FullSystemScanActivity.this.f3138Q.setText(C0415R.string.virusdeal_txt);
                    FullSystemScanActivity.this.f3134M.setVisibility(0);
                    FullSystemScanActivity.this.f3166l.setText(String.format(FullSystemScanActivity.this.getString(C0415R.string.virusdeal_txtdesc), Integer.valueOf(FullSystemScanActivity.this.f3157c)));
                    FullSystemScanActivity.this.f3140S.setBackgroundResource(C0415R.drawable.virus_status_green1);
                }
                HttpUtils.removeConfig(AppUtils.getVirusDescKey(packageName), context);
            }
        }
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == 4) {
            if (this.f3179y.size() > 0) {
                m1368a();
                return true;
            }
            freeManage();
            finish();
            System.gc();
            return true;
        }
        return true;
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public void m1368a() {
        new CustomDialog.Builder(this).setTitle(C0415R.string.info).setMessage(C0415R.string.hasvirus_back).setColorNegativeButton(true).setColorPositiveButton(false).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.13
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface arg0, int arg1) {
                FullSystemScanActivity.m1350P(FullSystemScanActivity.this);
                FullSystemScanActivity.this.freeManage();
                FullSystemScanActivity.this.finish();
                System.gc();
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.12
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface arg0, int arg1) {
            }
        }).show();
    }

    public void openNetworkSettings() {
        new CustomDialog.Builder(this).setTitle(C0415R.string.set_net_text).setMessage(C0415R.string.notice_no_net_text).setPositiveButton(C0415R.string.set_net_text, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.15
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                WflUtils.startWirelessSettingsActivity(FullSystemScanActivity.this);
                dialog.cancel();
            }
        }).setNegativeButton(C0415R.string.no, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.14
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                dialog.cancel();
            }
        }).show();
    }

    public void openNetScan() {
        new CustomDialog.Builder(this).setTitle(C0415R.string.safecenter).setMessage(C0415R.string.netscaning_desc).setPositiveButton(C0415R.string.netscaning_sure, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.18
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                FullSystemScanActivity.this.f3153ae.sendEmptyMessage(7);
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.17
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                dialog.dismiss();
                ScanUtils.isNetScan_cancel = true;
                FullSystemScanActivity.this.f3153ae.sendEmptyMessage(9);
            }
        }).setOnCancelListener(new DialogInterface.OnCancelListener() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.16
            @Override // android.content.DialogInterface.OnCancelListener
            public final void onCancel(DialogInterface dialog) {
                Log.i("msg", "openNetScan onCancel");
            }
        }).show();
    }

    public void setAnimation() {
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        this.f3172r = new C0489b(this);
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.antivirusfull_system_scan);
        this.f3140S = (ImageView) findViewById(C0415R.id.antivirusfulldisk_icon);
        this.f3140S.setBackgroundResource(C0415R.drawable.virus_status_green1);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.antivirusapp_name, (Integer) null);
        this.f3167m = (TextView) findViewById(C0415R.id.novirus_txt);
        this.f3168n = (RelativeLayout) findViewById(C0415R.id.novirus_layout);
        this.f3173s = (ExpandableListView) findViewById(C0415R.id.viruslistview);
        this.f3137P = new AntiVirusDBHelper(this);
        this.f3135N = (LinearLayout) findViewById(C0415R.id.pro_lin);
        this.f3170p = (TextView) findViewById(C0415R.id.cancel_txt);
        this.f3126E = (Button) findViewById(C0415R.id.antivirusnet_stop);
        this.f3179y = new HashMap<>();
        this.f3127F = (Button) findViewById(C0415R.id.antivirusbutton_pause001);
        this.f3128G = (Button) findViewById(C0415R.id.antivirusbutton_stop002);
        this.f3169o = (TextView) findViewById(C0415R.id.antivirusscaning);
        this.f3166l = (TextView) findViewById(C0415R.id.antivirusscaningapp);
        this.f3148a = (ProgressBar) findViewById(C0415R.id.antivirusprocessbar);
        this.f3124C = (Button) findViewById(C0415R.id.antivirusbutton_stop);
        this.f3125D = (Button) findViewById(C0415R.id.antivirusbutton_pause);
        this.f3164j = getResources().getString(C0415R.string.antivirusscan_percent);
        this.f3165k = (TextView) findViewById(C0415R.id.antiviruspercent);
        this.f3171q = (ListView) findViewById(C0415R.id.scanlistview);
        this.f3174t = (TextView) findViewById(C0415R.id.antivirushasScaned);
        this.f3131J = (LinearLayout) findViewById(C0415R.id.antivirusresult_view);
        this.f3133L = (LinearLayout) findViewById(C0415R.id.antivirusscan_btn);
        this.f3132K = (LinearLayout) findViewById(C0415R.id.antivirusdeal_btn);
        this.f3134M = (LinearLayout) findViewById(C0415R.id.antivirusdeal_novirus);
        this.f3138Q = (Button) findViewById(C0415R.id.antivirusbutton_pause010);
        this.f3131J.setVisibility(8);
        this.f3132K.setVisibility(8);
        this.f3134M.setVisibility(8);
        this.f3166l.setVisibility(8);
        this.f3154af = AppUtils.isNeedScan(this);
        this.f3180z = new PermAdapter(this, this.f3178x, this.f3154af);
        this.f3171q.setAdapter((ListAdapter) this.f3180z);
        ScanUtils.isNetScan_cancel = false;
        this.f3133L.setVisibility(8);
        onBtnClick();
        setAnimation();
        registerAction();
        this.f3155ag = false;
        this.f3130I = getResources().getString(C0415R.string.antivirusgoon_scan);
        this.f3125D.setText(this.f3130I);
        this.f3127F.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.19
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (FullSystemScanActivity.this.f3179y.size() != 0) {
                    Set<String> keys = FullSystemScanActivity.this.f3179y.keySet();
                    for (String name : keys) {
                        FullSystemScanActivity.this.uninstall(name);
                    }
                }
            }
        });
        this.f3128G.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                FullSystemScanActivity.this.m1368a();
            }
        });
        this.f3138Q.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.3
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                FullSystemScanActivity.m1350P(FullSystemScanActivity.this);
                FullSystemScanActivity.this.freeManage();
                FullSystemScanActivity.this.finish();
                System.gc();
            }
        });
        this.f3124C.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.4
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (!FullSystemScanActivity.this.f3154af) {
                    FullSystemScanActivity.this.f3152ad.m1402a(false);
                    FullSystemScanActivity.m1352R(FullSystemScanActivity.this);
                    if (FullSystemScanActivity.this.f3156b != FullSystemScanActivity.this.f3151ac) {
                        FullSystemScanActivity.m1354T(FullSystemScanActivity.this);
                        return;
                    }
                    return;
                }
                FullSystemScanActivity.m1352R(FullSystemScanActivity.this);
                Message message = new Message();
                message.what = 11;
                message.obj = Boolean.valueOf(FullSystemScanActivity.this.f3160f);
                FullSystemScanActivity.this.f3153ae.sendMessage(message);
                if (FullSystemScanActivity.this.f3129H != null && FullSystemScanActivity.this.f3129H.isAlive()) {
                    FullSystemScanActivity.this.f3146Y.cancelScan();
                    try {
                        FullSystemScanActivity.this.f3129H.stop();
                    } catch (RuntimeException e) {
                        e.printStackTrace();
                    }
                    FullSystemScanActivity.this.f3129H = null;
                }
                FullSystemScanActivity.m1354T(FullSystemScanActivity.this);
            }
        });
        this.f3170p.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.5
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (FullSystemScanActivity.this.f3161g > 5) {
                    if (FullSystemScanActivity.this.f3154af) {
                        FullSystemScanActivity.m1362a(FullSystemScanActivity.this, System.currentTimeMillis() - FullSystemScanActivity.this.f3141T);
                        FullSystemScanActivity.this.setGoing(false);
                        if (FullSystemScanActivity.this.f3129H != null && FullSystemScanActivity.this.f3129H.isAlive()) {
                            FullSystemScanActivity.this.f3146Y.pauseScan();
                        }
                        FullSystemScanActivity.this.f3125D.setText(C0415R.string.antivirusgoon_scan);
                        FullSystemScanActivity.this.f3133L.setVisibility(0);
                        FullSystemScanActivity.this.f3135N.setVisibility(8);
                        FullSystemScanActivity.this.f3169o.setText(C0415R.string.antivirusspause);
                        return;
                    }
                    if (FullSystemScanActivity.this.f3156b != FullSystemScanActivity.this.f3151ac) {
                        FullSystemScanActivity.this.f3133L.setVisibility(0);
                        FullSystemScanActivity.this.f3135N.setVisibility(8);
                        FullSystemScanActivity.this.f3125D.setText(C0415R.string.antivirusgoon_scan);
                        FullSystemScanActivity.this.f3152ad.m1402a(false);
                        FullSystemScanActivity.this.f3169o.setText(C0415R.string.antivirusspause);
                    }
                    FullSystemScanActivity.m1362a(FullSystemScanActivity.this, System.currentTimeMillis() - FullSystemScanActivity.this.f3141T);
                }
            }
        });
        this.f3125D.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.6
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (FullSystemScanActivity.this.f3154af) {
                    if (FullSystemScanActivity.this.f3125D.getText().toString().equals(FullSystemScanActivity.this.f3130I)) {
                        FullSystemScanActivity.this.setGoing(true);
                        FullSystemScanActivity.this.f3135N.setVisibility(0);
                        FullSystemScanActivity.this.f3133L.setVisibility(8);
                        FullSystemScanActivity.this.f3169o.setText(C0415R.string.antivirusscaning);
                        FullSystemScanActivity.this.f3141T = System.currentTimeMillis();
                        if (FullSystemScanActivity.this.f3129H != null && FullSystemScanActivity.this.f3129H.isAlive()) {
                            FullSystemScanActivity.this.f3146Y.continueScan();
                            return;
                        }
                        return;
                    }
                    return;
                }
                if (FullSystemScanActivity.this.f3125D.getText().toString().equals(FullSystemScanActivity.this.f3130I) && FullSystemScanActivity.this.f3156b != FullSystemScanActivity.this.f3151ac) {
                    FullSystemScanActivity.this.f3135N.setVisibility(0);
                    FullSystemScanActivity.this.f3133L.setVisibility(8);
                    FullSystemScanActivity.this.f3169o.setText(C0415R.string.antivirusscaning);
                    FullSystemScanActivity.this.f3141T = System.currentTimeMillis();
                    try {
                        FullSystemScanActivity.this.f3152ad = FullSystemScanActivity.this.new C0491d(FullSystemScanActivity.this.f3156b, FullSystemScanActivity.this.f3151ac);
                        FullSystemScanActivity.this.f3152ad.m1402a(true);
                        FullSystemScanActivity.this.f3152ad.start();
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            }
        });
        this.f3126E.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.7
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                ScanUtils.isNetScan_cancel = true;
                if (!FullSystemScanActivity.this.f3139R) {
                    FullSystemScanActivity.this.f3153ae.sendEmptyMessage(9);
                }
            }
        });
        setScanAnimation();
        this.f3141T = System.currentTimeMillis();
        this.f3153ae.sendEmptyMessage(2);
    }

    public void setGoing(boolean isGoing) {
        Message message = new Message();
        message.what = 11;
        message.obj = Boolean.valueOf(isGoing);
        this.f3153ae.sendMessage(message);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            if (this.f3179y.size() > 0) {
                m1368a();
                return;
            }
            freeManage();
            finish();
            System.gc();
        }
    }

    public void uninstall(String pkgname) {
        Uri packageURI = Uri.parse("package:" + pkgname);
        Intent uninstallIntent = new Intent("android.intent.action.DELETE", packageURI);
        startActivity(uninstallIntent);
    }

    public void setView() {
        Log.i("setView", this.f3159e + "");
        this.f3171q.setVisibility(8);
        this.f3131J.setVisibility(8);
        findViewById(C0415R.id.antivirusnetscan_btn).setVisibility(8);
        this.f3133L.setVisibility(8);
        this.f3174t.setVisibility(8);
        if (this.f3179y.size() > 0) {
            this.f3173s.setVisibility(0);
            this.f3173s.setGroupIndicator(null);
            Log.i("msg", "==============" + this.f3179y.size());
            getVirus();
            if (this.f3162h.size() > 0) {
                this.f3176v = new C0492e(this);
                this.f3173s.setAdapter(this.f3176v);
                this.f3173s.expandGroup(0);
            }
        } else {
            this.f3173s.setVisibility(8);
            this.f3167m.setVisibility(8);
            this.f3168n.setVisibility(8);
            this.f3171q.setVisibility(0);
        }
        if (this.f3179y.size() <= 0) {
            this.f3134M.setVisibility(0);
            if (PreferenceManager.getDefaultSharedPreferences(this).getInt("netScan_switch", 1) == 1 && ScanUtils.isNetworkAvailable(this) && !ScanUtils.isNetScan_cancel && this.f3175u != null) {
                stopAnimation();
                this.f3140S.setBackgroundResource(C0415R.drawable.virus_status_green1);
                this.f3171q.setVisibility(8);
                this.f3167m.setVisibility(0);
                this.f3168n.setVisibility(0);
                if (this.f3142U == 0) {
                    this.f3142U = System.currentTimeMillis() - this.f3141T;
                }
                TextView textView = this.f3167m;
                String string = getString(C0415R.string.scanfinish);
                Object[] objArr = new Object[3];
                objArr[0] = Integer.valueOf(this.f3143V);
                objArr[1] = Long.valueOf((this.f3142U / 1000) + 1);
                objArr[2] = this.f3136O.size() > 3 ? HttpUtils.usenet : Formatter.formatFileSize(this, this.f3136O.size() * 40);
                textView.setText(String.format(string, objArr));
                return;
            }
            stopAnimation();
            this.f3140S.setBackgroundResource(C0415R.drawable.virus_status_green1);
            this.f3171q.setVisibility(8);
            this.f3167m.setVisibility(0);
            this.f3168n.setVisibility(0);
            if (this.f3142U == 0) {
                this.f3142U = System.currentTimeMillis() - this.f3141T;
            }
            if (this.f3154af) {
                this.f3167m.setText(String.format(getString(C0415R.string.scanfinish1), Integer.valueOf(this.f3143V), Long.valueOf((this.f3142U / 1000) + 1)));
                return;
            } else {
                this.f3167m.setText(String.format(getString(C0415R.string.scanfinish1), Integer.valueOf(this.f3150ab.size()), Long.valueOf((this.f3142U / 1000) + 1)));
                return;
            }
        }
        stopAnimation();
        this.f3140S.setBackgroundResource(C0415R.drawable.virus_status_red1);
        this.f3132K.setVisibility(0);
    }

    public void registerAction() {
        IntentFilter filter = new IntentFilter();
        filter.addAction("android.intent.action.PACKAGE_REMOVED");
        filter.addDataScheme("package");
        registerReceiver(this.f3172r, filter);
    }

    public List<Virus> getVirus() {
        this.f3177w = new ArrayList();
        List<String> errorList = new ArrayList<>();
        Set<String> names = this.f3179y.keySet();
        for (String virusPackageName : names) {
            try {
                ApplicationInfo mAppInfo = getPackageManager().getApplicationInfo(virusPackageName, 8192);
                Virus virus = new Virus(virusPackageName, mAppInfo.loadLabel(getPackageManager()).toString(), false);
                QScanResultEntity result = this.f3179y.get(virusPackageName);
                if (result != null) {
                    virus.setVirusName(result.name);
                    virus.setType(0);
                    virus.setVirusDesc(result.discription);
                } else {
                    virus.setType(0);
                    virus.setVirusName(mAppInfo.loadLabel(getPackageManager()).toString());
                    if (!HttpUtils.execService(AppUtils.getVirusDescKey(virusPackageName), this).equals("")) {
                        virus.setVirusDesc(HttpUtils.execService(AppUtils.getVirusDescKey(virusPackageName), this));
                    } else {
                        virus.setVirusDesc(getString(C0415R.string.antivirusvirusdesc_default));
                    }
                }
                this.f3177w.add(virus);
            } catch (Exception e) {
                errorList.add(virusPackageName);
                Log.i("p_name", "==============errorListPackageName==" + virusPackageName);
                new ScanUtils().ExecError(virusPackageName, this);
                e.printStackTrace();
            }
        }
        for (String pkg : errorList) {
            this.f3179y.remove(pkg);
        }
        if (this.f3177w.size() > 0) {
            Log.i("msg", "==============" + this.f3177w.size() + "========" + this.f3157c);
            String sureVirus = getString(C0415R.string.antivirusvirus_suredesc);
            this.f3163i.add(String.format(sureVirus, Integer.valueOf(this.f3157c)));
            this.f3166l.setText(String.format(getString(C0415R.string.antivirusscan_reslut2), Integer.valueOf(this.f3157c)));
            this.f3162h.add(this.f3177w);
        }
        return this.f3177w;
    }

    public void onBtnClick() {
        this.f3173s.setOnChildClickListener(new ExpandableListView.OnChildClickListener() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.8
            @Override // android.widget.ExpandableListView.OnChildClickListener
            public final boolean onChildClick(ExpandableListView parent, View v, int groupPosition, int childPosition, long id) {
                Virus vir = (Virus) ((List) FullSystemScanActivity.this.f3162h.get(groupPosition)).get(childPosition);
                if (!vir.isOperate()) {
                    Intent intent = new Intent(FullSystemScanActivity.this, (Class<?>) VirusInfo.class);
                    intent.putExtra(QueryPermissions.PACKAGENAME, vir.getPackageName());
                    intent.putExtra("desc", vir.getVirusDesc());
                    intent.putExtra("type", vir.getType());
                    FullSystemScanActivity.this.startActivity(intent);
                    return false;
                }
                return false;
            }
        });
    }

    @Override // android.app.Activity
    protected void onStart() {
        super.onStart();
        Log.i("mm", "onStart");
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onRestart() {
        super.onRestart();
        Log.i("setView", this.f3159e + "==onRestart");
    }

    @Override // android.app.Activity
    protected void onPause() {
        super.onPause();
        Log.i("mm", "onPause");
        TrackEvent.trackPause(this);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        super.onResume();
    }

    public void freeManage() {
        this.f3155ag = true;
        try {
            if (this.f3152ad != null) {
                this.f3152ad.m1402a(false);
                this.f3152ad = null;
            }
            if (this.f3146Y != null) {
                this.f3146Y.cancelScan();
                this.f3146Y.freeScanner();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override // android.app.Activity
    protected void onStop() {
        super.onStop();
        Log.i("mm", "onStop");
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        setGoing(false);
        unregisterReceiver(this.f3172r);
        try {
            if (this.f3146Y != null) {
                this.f3146Y.freeScanner();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity$c */
    class C0490c extends Thread {
        C0490c() {
        }

        @Override // java.lang.Thread, java.lang.Runnable
        public final void run() {
            FullSystemScanActivity.this.f3146Y.scanInstalledPackages(FullSystemScanActivity.this.new C0488a(), false);
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity$e */
    private class C0492e extends BaseExpandableListAdapter {

        /* JADX INFO: renamed from: b */
        private LayoutInflater f3210b;

        public C0492e(Context context) {
            this.f3210b = LayoutInflater.from(context);
        }

        @Override // android.widget.ExpandableListAdapter
        public final Object getChild(int groupPosition, int childPosition) {
            return ((List) FullSystemScanActivity.this.f3162h.get(groupPosition)).get(childPosition);
        }

        @Override // android.widget.ExpandableListAdapter
        public final long getChildId(int groupPosition, int childPosition) {
            return childPosition;
        }

        @Override // android.widget.ExpandableListAdapter
        public final int getChildrenCount(int groupPosition) {
            return ((List) FullSystemScanActivity.this.f3162h.get(groupPosition)).size();
        }

        @Override // android.widget.ExpandableListAdapter
        public final View getChildView(int groupPosition, int childPosition, boolean isLastChild, View convertView, ViewGroup parent) {
            a holder;
            Drawable drawable;
            if (convertView == null) {
                convertView = this.f3210b.inflate(C0415R.layout.antivirusshowviruwitem, (ViewGroup) null);
                holder = new a();
                holder.f3215a = (TextView) convertView.findViewById(C0415R.id.antivirusappname);
                holder.f3216b = (TextView) convertView.findViewById(C0415R.id.antivirusvirusname);
                holder.f3217c = (ImageView) convertView.findViewById(C0415R.id.antivirusviruscheckbox);
                holder.f3220f = (TextView) convertView.findViewById(C0415R.id.antivirusshowdesc);
                holder.f3218d = (ImageView) convertView.findViewById(C0415R.id.antiviruspkg_icon);
                holder.f3219e = (ImageView) convertView.findViewById(C0415R.id.del_icon);
                convertView.setTag(holder);
            } else {
                holder = (a) convertView.getTag();
            }
            final Virus virus = (Virus) ((List) FullSystemScanActivity.this.f3162h.get(groupPosition)).get(childPosition);
            holder.f3215a.setText(virus.getAppName());
            if (virus.getType() == 0) {
                String virusname = FullSystemScanActivity.this.getString(C0415R.string.antivirusvirusname);
                holder.f3216b.setText(String.format(virusname, virus.getVirusName()));
            } else {
                String virusname2 = FullSystemScanActivity.this.getString(C0415R.string.antivirusvirus_carefuluse);
                holder.f3216b.setText(String.format(virusname2, virus.getVirusName()));
            }
            FullSystemScanActivity.this.getResources().getDrawable(C0415R.drawable.icon3);
            try {
                ApplicationInfo appInfo = FullSystemScanActivity.this.getPackageManager().getApplicationInfo(virus.getPackageName(), 8192);
                drawable = appInfo.loadIcon(FullSystemScanActivity.this.getPackageManager());
            } catch (Exception e) {
                e.printStackTrace();
                drawable = FullSystemScanActivity.this.getResources().getDrawable(C0415R.drawable.icon3);
            }
            holder.f3218d.setImageDrawable(drawable);
            if (virus.isOperate()) {
                holder.f3220f.setText(C0415R.string.uninstall);
                holder.f3219e.setVisibility(0);
                holder.f3220f.setVisibility(8);
                holder.f3220f.setEnabled(false);
            } else {
                holder.f3219e.setVisibility(8);
                holder.f3220f.setVisibility(0);
                holder.f3220f.setEnabled(true);
                Log.i("type", "type==" + virus.getType());
                if (virus.getType() == 0 || virus.getType() == 1) {
                    holder.f3220f.setText(C0415R.string.uninstall);
                    holder.f3220f.setEnabled(true);
                }
            }
            holder.f3217c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.e.1
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    FullSystemScanActivity.this.forwardAppInfo(virus.getPackageName());
                }
            });
            holder.f3220f.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity.e.2
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    FullSystemScanActivity.this.removePackageActivity(virus.getPackageName());
                }
            });
            return convertView;
        }

        @Override // android.widget.ExpandableListAdapter
        public final Object getGroup(int groupPosition) {
            return FullSystemScanActivity.this.f3163i.get(groupPosition);
        }

        @Override // android.widget.ExpandableListAdapter
        public final int getGroupCount() {
            return FullSystemScanActivity.this.f3163i.size();
        }

        @Override // android.widget.ExpandableListAdapter
        public final long getGroupId(int groupPosition) {
            return groupPosition;
        }

        @Override // android.widget.ExpandableListAdapter
        public final View getGroupView(int groupPosition, boolean isExpanded, View convertView, ViewGroup parent) {
            b holder;
            if (convertView == null) {
                convertView = this.f3210b.inflate(C0415R.layout.antivirusshowviruwparent, (ViewGroup) null);
                holder = new b();
                holder.f3222a = (TextView) convertView.findViewById(C0415R.id.antivirusvirus_type);
                convertView.setTag(holder);
            } else {
                holder = (b) convertView.getTag();
            }
            holder.f3222a.setText((CharSequence) FullSystemScanActivity.this.f3163i.get(groupPosition));
            return convertView;
        }

        @Override // android.widget.ExpandableListAdapter
        public final boolean hasStableIds() {
            return false;
        }

        @Override // android.widget.ExpandableListAdapter
        public final boolean isChildSelectable(int groupPosition, int childPosition) {
            return true;
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity$e$b */
        class b {

            /* JADX INFO: renamed from: a */
            TextView f3222a;

            b() {
            }
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity$e$a */
        class a {

            /* JADX INFO: renamed from: a */
            TextView f3215a;

            /* JADX INFO: renamed from: b */
            TextView f3216b;

            /* JADX INFO: renamed from: c */
            ImageView f3217c;

            /* JADX INFO: renamed from: d */
            ImageView f3218d;

            /* JADX INFO: renamed from: e */
            ImageView f3219e;

            /* JADX INFO: renamed from: f */
            TextView f3220f;

            a() {
            }
        }
    }

    public void forwardAppInfo(String pkgName) {
        ComponentName comp = new ComponentName("com.android.settings", "com.android.settings.InstalledAppDetails");
        Intent intent = new Intent();
        intent.setAction("android.intent.action.VIEW");
        intent.setComponent(comp);
        intent.putExtra("pkg", pkgName);
        startActivity(intent);
    }

    public void removePackageActivity(String pkgName) {
        Uri packageURI = Uri.parse("package:" + pkgName);
        Intent uninstallIntent = new Intent("android.intent.action.DELETE", packageURI);
        startActivity(uninstallIntent);
    }

    public void setScanAnimation() {
        this.f3145X = (ImageView) findViewById(C0415R.id.zoom_icon1);
        this.f3144W = new TranslateAnimation(20.0f, 20.0f, 0.0f, 70.0f);
        this.f3144W.setDuration(1500L);
        this.f3144W.setRepeatCount(-1);
        this.f3144W.setRepeatMode(2);
        this.f3144W.setFillAfter(true);
    }

    public void startAnimation() {
        this.f3145X.setAnimation(this.f3144W);
        this.f3145X.setVisibility(0);
        this.f3144W.start();
    }

    public void stopAnimation() {
        this.f3145X.clearAnimation();
        this.f3145X.setVisibility(8);
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity$a */
    class C0488a extends QScanListener {
        C0488a() {
        }

        @Override // com.tencent.tmsecure.module.qscanner.QScanListener
        public final void onScanStarted() {
        }

        @Override // com.tencent.tmsecure.module.qscanner.QScanListener
        public final void onPackageScanProgress(int progress, QScanResultEntity result) {
            if (!result.packageName.equals(TrafficStatsService.PACKAGE_NAME)) {
                Log.i("demo", progress + ">>" + result.softName);
                Message message = new Message();
                message.what = 0;
                message.arg1 = progress;
                message.obj = result;
                FullSystemScanActivity.this.f3153ae.sendMessage(message);
            }
            try {
                if (result.apkType != 1) {
                    if (result.type != 3) {
                        Appinfo info = FullSystemScanActivity.this.f3137P.getAppInfo(result.packageName);
                        if (info != null) {
                            FullSystemScanActivity.this.f3136O.add(info);
                            return;
                        }
                        return;
                    }
                    FullSystemScanActivity.m1359Y(FullSystemScanActivity.this);
                    FullSystemScanActivity.m1360Z(FullSystemScanActivity.this);
                    FullSystemScanActivity.this.f3179y.put(result.packageName, result);
                    HttpUtils.UpdateConfig(AppUtils.getVirusDescKey(result.packageName), result.discription, FullSystemScanActivity.this);
                }
            } catch (Exception e1) {
                e1.printStackTrace();
            }
        }

        @Override // com.tencent.tmsecure.module.qscanner.QScanListener
        public final void onSdcardScanProgress(int progress, QScanResultEntity result) {
        }

        @Override // com.tencent.tmsecure.module.qscanner.QScanListener
        public final void onCloudScan() {
            FullSystemScanActivity.this.f3147Z = true;
        }

        @Override // com.tencent.tmsecure.module.qscanner.QScanListener
        public final void onCloudScanError(int errCode) {
            FullSystemScanActivity.this.f3147Z = false;
        }

        @Override // com.tencent.tmsecure.module.qscanner.QScanListener
        public final void onScanPaused() {
            FullSystemScanActivity.this.f3147Z = false;
        }

        @Override // com.tencent.tmsecure.module.qscanner.QScanListener
        public final void onScanContinue() {
            FullSystemScanActivity.this.f3149aa = false;
        }

        @Override // com.tencent.tmsecure.module.qscanner.QScanListener
        public final void onScanCanceled() {
            FullSystemScanActivity.this.f3147Z = false;
            FullSystemScanActivity.this.f3149aa = true;
        }

        @Override // com.tencent.tmsecure.module.qscanner.QScanListener
        public final void onScanFinished(ArrayList<QScanResultEntity> arg0) {
            if (!FullSystemScanActivity.this.f3149aa) {
                AppUtils.isNeedScan(FullSystemScanActivity.this);
                Log.i("mes", "onScanFinished====");
                Message msg = new Message();
                msg.what = 1;
                FullSystemScanActivity.this.f3153ae.sendMessage(msg);
                FullSystemScanActivity.this.f3147Z = false;
            }
            FullSystemScanActivity.this.f3149aa = false;
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.FullSystemScanActivity$d */
    class C0491d extends Thread {

        /* JADX INFO: renamed from: a */
        int f3205a;

        /* JADX INFO: renamed from: b */
        int f3206b;

        /* JADX INFO: renamed from: c */
        boolean f3207c;

        public C0491d(int pos, int totalapp) {
            this.f3205a = pos;
            this.f3206b = totalapp;
        }

        /* JADX INFO: renamed from: a */
        public final void m1402a(boolean isGoing) {
            this.f3207c = isGoing;
            Message message = new Message();
            message.what = 11;
            message.obj = Boolean.valueOf(isGoing);
            FullSystemScanActivity.this.f3153ae.sendMessage(message);
        }

        @Override // java.lang.Thread, java.lang.Runnable
        public final void run() {
            while (this.f3207c && this.f3205a < this.f3206b) {
                ApplicationInfo packageInfo = (ApplicationInfo) FullSystemScanActivity.this.f3150ab.get(this.f3205a);
                this.f3205a++;
                Message message = new Message();
                message.what = 0;
                message.getData().putString(AppDatabase.DB_APP, packageInfo.sourceDir);
                message.getData().putBoolean("isvirus", FullSystemScanActivity.this.f3179y.containsKey(packageInfo.packageName));
                try {
                    Appinfo info = FullSystemScanActivity.this.f3137P.getAppInfo(packageInfo.packageName);
                    Log.i("info", info + "==" + packageInfo.packageName);
                    if (info != null) {
                        FullSystemScanActivity.this.f3136O.add(info);
                    }
                    Thread.sleep(10L);
                    FullSystemScanActivity.this.f3153ae.sendMessage(message);
                } catch (Exception e1) {
                    e1.printStackTrace();
                }
            }
            Log.i("mm", "pos==" + this.f3205a + "toal==" + this.f3206b);
            if (this.f3205a == this.f3206b) {
                Message msg = new Message();
                msg.what = 1;
                FullSystemScanActivity.this.f3153ae.sendMessage(msg);
            }
        }
    }
}
