package com.lenovo.lps.sus.control;

import android.R;
import android.app.AlertDialog;
import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.os.Handler;
import android.os.Message;
import android.text.method.ScrollingMovementMethod;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.RemoteViews;
import android.widget.TextView;
import com.lenovo.lps.sus.p003a.p004a.p005a.C0080c;
import com.lenovo.lps.sus.p007b.C0085a;
import com.lenovo.lps.sus.p007b.C0087c;
import com.lenovo.lps.sus.p007b.EnumC0086b;
import com.lenovo.lps.sus.p007b.EnumC0088d;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;
import com.lenovo.lps.sus.p009d.C0141c;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.providers.querypermissions.QueryPermissions;
import java.net.URLDecoder;
import java.net.URLEncoder;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.am */
/* JADX INFO: loaded from: classes.dex */
public class C0111am implements CompoundButton.OnCheckedChangeListener {

    /* JADX INFO: renamed from: A */
    private Notification f1457A = null;

    /* JADX INFO: renamed from: B */
    private NotificationManager f1458B = null;

    /* JADX INFO: renamed from: a */
    private static String f1431a = "SUS_VERSIONUPDATE";

    /* JADX INFO: renamed from: b */
    private static String f1432b = "layout";

    /* JADX INFO: renamed from: c */
    private static String f1433c = "sus_updateinfo_dialog";

    /* JADX INFO: renamed from: d */
    private static String f1434d = QueryPermissions.f1958ID;

    /* JADX INFO: renamed from: e */
    private static String f1435e = "SUS_newversioninfo";

    /* JADX INFO: renamed from: f */
    private static String f1436f = "SUS_versiondescribe";

    /* JADX INFO: renamed from: g */
    private static String f1437g = "versioninfo";

    /* JADX INFO: renamed from: h */
    private static String f1438h = "newversioncode";

    /* JADX INFO: renamed from: i */
    private static String f1439i = "SUS_NOTIFICATION_TITLE";

    /* JADX INFO: renamed from: j */
    private static String f1440j = "layout";

    /* JADX INFO: renamed from: k */
    private static String f1441k = "sus_notification_dialog";

    /* JADX INFO: renamed from: l */
    private static String f1442l = QueryPermissions.f1958ID;

    /* JADX INFO: renamed from: m */
    private static AlertDialog f1443m = null;

    /* JADX INFO: renamed from: n */
    private static AlertDialog f1444n = null;

    /* JADX INFO: renamed from: o */
    private static boolean f1445o = true;

    /* JADX INFO: renamed from: p */
    private static boolean f1446p = false;

    /* JADX INFO: renamed from: q */
    private static Integer f1447q = 3;

    /* JADX INFO: renamed from: r */
    private static Handler f1448r = new Handler();

    /* JADX INFO: renamed from: s */
    private static boolean f1449s = false;

    /* JADX INFO: renamed from: t */
    private static int f1450t = 0;

    /* JADX INFO: renamed from: u */
    private static String f1451u = null;

    /* JADX INFO: renamed from: v */
    private static String f1452v = null;

    /* JADX INFO: renamed from: w */
    private static String f1453w = null;

    /* JADX INFO: renamed from: x */
    private static boolean f1454x = false;

    /* JADX INFO: renamed from: y */
    private static Context f1455y = null;

    /* JADX INFO: renamed from: z */
    private static Handler f1456z = null;

    /* JADX INFO: renamed from: C */
    private static C0141c f1429C = null;

    /* JADX INFO: renamed from: D */
    private static Runnable f1430D = new RunnableC0124l();

    public C0111am(Context context, Handler handler) {
        f1455y = context;
        f1456z = handler;
        C0098i.m409a(C0092c.f1339b, "SUSUIHandler create!");
        SUSReceiver.m438a(f1456z);
    }

    /* JADX INFO: renamed from: a */
    public static void m469a(int i, String str, String str2, String str3, boolean z) {
        TextView textView;
        TextView textView2;
        if (str3 != null && str3.length() > 0) {
            str3 = URLDecoder.decode(str3);
        }
        f1450t = i;
        f1451u = str;
        f1452v = str2;
        f1453w = str3;
        f1454x = z;
        int iIntValue = Integer.valueOf(str2).intValue();
        EnumC0088d enumC0088dM299c = C0087c.m299c(i);
        View viewInflate = LayoutInflater.from(f1455y).inflate(C0092c.m323a(f1455y, f1432b, f1433c), (ViewGroup) null);
        AlertDialog.Builder builder = new AlertDialog.Builder(f1455y);
        builder.setTitle(C0092c.m343b(f1455y, f1431a));
        builder.setView(viewInflate);
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity popupPromptionDialog create");
        C0098i.m409a(C0092c.f1339b, "popupPromptionDialog, Stoneage1 debug1");
        builder.setPositiveButton(C0092c.m343b(f1455y, "SUS_UPDATE"), new DialogInterfaceOnClickListenerC0123k());
        builder.setNegativeButton(C0092c.m343b(f1455y, "SUS_CANCEL"), new DialogInterfaceOnClickListenerC0126n());
        C0098i.m409a(C0092c.f1339b, "popupPromptionDialog, Stoneage1 debug2");
        builder.setOnKeyListener(new DialogInterfaceOnKeyListenerC0125m());
        f1443m = builder.create();
        f1443m.setCancelable(false);
        C0098i.m409a(C0092c.f1339b, "popupPromptionDialog, Stoneage1 debug3");
        f1443m.setOnCancelListener(new DialogInterfaceOnCancelListenerC0130r());
        C0098i.m409a(C0092c.f1339b, "popupPromptionDialog, Stoneage1 debug4");
        f1443m.setOnDismissListener(new DialogInterfaceOnDismissListenerC0128p());
        if (f1443m == null) {
            C0098i.m409a(C0092c.f1339b, "null == myUpdateInfoAlertDialog!!!");
            C0104ae.m447b();
            return;
        }
        C0098i.m409a(C0092c.f1339b, "popupPromptionDialog, Stoneage1 debug5");
        f1443m.show();
        if (str != null && str.length() > 0 && (textView2 = (TextView) f1443m.findViewById(C0092c.m323a(f1455y, f1434d, f1435e))) != null) {
            textView2.setText(str);
        }
        if (!C0104ae.m461h() && str3 != null && str3.length() > 0 && (textView = (TextView) f1443m.findViewById(C0092c.m323a(f1455y, f1434d, f1436f))) != null) {
            textView.setText(str3);
            textView.setMovementMethod(ScrollingMovementMethod.getInstance());
        }
        C0098i.m409a(C0092c.f1339b, "popupPromptionDialog, Stoneage1 debug6");
        if (!z) {
            CheckBox checkBox = (CheckBox) f1443m.findViewById(C0092c.m323a(f1455y, QueryPermissions.f1958ID, "usersettings_newverprompt_checkbox"));
            C0098i.m409a(C0092c.f1339b, "popupPromptionDialog, Stoneage1 debug8");
            if (checkBox != null) {
                checkBox.setVisibility(8);
                return;
            }
            return;
        }
        if (C0092c.m355d()) {
            CheckBox checkBox2 = (CheckBox) f1443m.findViewById(C0092c.m323a(f1455y, QueryPermissions.f1958ID, "usersettings_newverprompt_checkbox"));
            C0098i.m409a(C0092c.f1339b, "popupPromptionDialog, Stoneage1 debug7");
            if (checkBox2 != null) {
                checkBox2.setText("  " + C0092c.m343b(f1455y, "SUS_SETTINGS_NEWVERPROMPT"));
                if (EnumC0088d.UPDATEACTION_NEWVERPROMPT == enumC0088dM299c) {
                    checkBox2.setChecked(true);
                } else {
                    checkBox2.setChecked(false);
                }
                checkBox2.setOnCheckedChangeListener(new C0135w(iIntValue));
            }
        }
    }

    /* JADX INFO: renamed from: a */
    public static void m470a(Context context, boolean z) {
        TextView textView;
        TextView textView2;
        TextView textView3;
        TextView textView4;
        View viewInflate = LayoutInflater.from(context).inflate(C0092c.m323a(context, "layout", f1441k), (ViewGroup) null);
        f1449s = z;
        if (f1444n != null) {
            f1444n.dismiss();
            f1444n = null;
        }
        C0092c.m354d(true);
        AlertDialog.Builder builder = new AlertDialog.Builder(context);
        builder.setTitle(C0092c.m343b(context, f1439i));
        builder.setView(viewInflate);
        if (f1447q.intValue() == 0) {
            f1447q = 3;
        }
        C0098i.m409a(C0092c.f1339b, "SUSNotificationActivity popupPromptionDialog create");
        builder.setPositiveButton(C0092c.m343b(context, "SUS_NOTIFICATION_HIDE_BUTTONTEXT"), new DialogInterfaceOnClickListenerC0132t());
        builder.setNegativeButton(C0092c.m343b(context, "SUS_NOTIFICATION_ABORTUPDATE_BUTTONTEXT"), new DialogInterfaceOnClickListenerC0100aa());
        builder.setOnKeyListener(new DialogInterfaceOnKeyListenerC0115c());
        f1444n = builder.create();
        f1444n.setCancelable(false);
        f1444n.setOnCancelListener(new DialogInterfaceOnCancelListenerC0114b());
        f1444n.setOnDismissListener(new DialogInterfaceOnDismissListenerC0116d(context));
        if (f1444n == null) {
            C0098i.m409a(C0092c.f1339b, "null == myPromptionInfoAlertDialog!!!");
            C0104ae.m447b();
            return;
        }
        f1444n.show();
        String strM343b = z ? C0092c.m343b(context, "SUS_NOTIFICATION_TIMEOUTPROMPT") : C0092c.m343b(context, "SUS_NOTIFICATION_UPDATINGPROMPT");
        if (strM343b != null && strM343b.length() > 0 && (textView4 = (TextView) f1444n.findViewById(C0092c.m323a(context, f1442l, "SUS_NOTIFICATION_PROMPTINFO"))) != null) {
            textView4.setText(strM343b);
        }
        String strM343b2 = C0092c.m343b(context, "SUS_NOTIFICATION_AUTOHIDPROMPTINFO_1");
        String strM343b3 = C0092c.m343b(context, "SUS_NOTIFICATION_AUTOHIDPROMPTINFO_2");
        String string = f1447q.toString();
        if (strM343b2 != null && strM343b2.length() > 0 && (textView3 = (TextView) f1444n.findViewById(C0092c.m323a(context, f1442l, "SUS_NOTIFICATION_AUTOHIDPROMPTINFOTEXTVIEW_1"))) != null) {
            textView3.setText(strM343b2);
        }
        if (strM343b3 != null && strM343b3.length() > 0 && (textView2 = (TextView) f1444n.findViewById(C0092c.m323a(context, f1442l, "SUS_NOTIFICATION_AUTOHIDPROMPTINFOTEXTVIEW_2"))) != null) {
            textView2.setText(strM343b3);
        }
        if (string != null && string.length() > 0 && (textView = (TextView) f1444n.findViewById(C0092c.m323a(context, f1442l, "SUS_NOTIFICATION_AUTOHIDPROMPTINFOTEXTVIEW_TIME"))) != null) {
            textView.setText(string);
        }
        if (f1448r == null || f1430D == null) {
            return;
        }
        f1448r.removeCallbacks(f1430D);
        f1448r.postDelayed(f1430D, 1500L);
    }

    /* JADX INFO: renamed from: a */
    public static void m471a(C0141c c0141c) {
        f1429C = c0141c;
    }

    /* JADX INFO: renamed from: c */
    public static void m474c() {
        if (f1444n != null) {
            f1447q = 3;
            f1444n.dismiss();
            f1444n = null;
        }
    }

    /* JADX INFO: renamed from: a */
    public void m487a() {
        C0098i.m409a(C0092c.f1339b, "susuihandler finish entry");
        if (this.f1458B != null) {
            C0098i.m409a(C0092c.f1339b, "susuihandler call clearNotification");
            if (!C0092c.m398x() && !C0104ae.m459g()) {
                C0098i.m409a(C0092c.f1339b, "clearNotification");
                m492b();
            }
            this.f1458B = null;
        }
        if (f1429C != null) {
            f1429C.m553a();
            f1429C = null;
        }
        f1455y = null;
        f1456z = null;
        C0098i.m409a(C0092c.f1339b, "susuihandler finish end");
    }

    /* JADX INFO: renamed from: a */
    public void m488a(int i) {
        if (this.f1457A == null || this.f1457A.contentView == null || this.f1458B == null) {
            return;
        }
        this.f1457A.contentView.setProgressBar(C0092c.m347c(f1455y, "SUS_progress_bar"), 100, i, false);
        this.f1457A.contentView.setTextViewText(C0092c.m347c(f1455y, "SUS_progress_text"), String.valueOf(String.valueOf(i)) + "%");
        this.f1458B.notify(93, this.f1457A);
    }

    /* JADX INFO: renamed from: a */
    public void m489a(int i, String str, String str2, String str3, long j, EnumC0108ai enumC0108ai) {
        if (str == null || str2 == null) {
            return;
        }
        try {
            C0098i.m409a(C0092c.f1339b, "downloadMode=" + enumC0108ai);
            String strM343b = C0092c.m343b(f1455y, "SUS_DOWNLOAD_TITLE");
            if (!C0092c.m398x() && !C0104ae.m459g()) {
                C0098i.m409a(C0092c.f1339b, "addDownLoadProgressAtNotification");
                Context context = f1455y;
                int iM323a = C0092c.m323a(f1455y, "drawable", "sus_downloadicon");
                if (iM323a == 0) {
                    iM323a = R.drawable.stat_sys_download;
                }
                this.f1457A = new Notification(iM323a, "", System.currentTimeMillis());
                this.f1457A.flags = 10;
                RemoteViews remoteViews = new RemoteViews(f1455y.getPackageName(), C0092c.m323a(f1455y, "layout", "sus_download_notification"));
                remoteViews.setProgressBar(C0092c.m347c(f1455y, "SUS_progress_bar"), 100, 0, false);
                remoteViews.setTextViewText(C0092c.m347c(f1455y, "SUS_progress_text"), "0%");
                if (str3 == null || str3.length() <= 0) {
                    remoteViews.setTextViewText(C0092c.m347c(f1455y, "SUS_title"), strM343b);
                } else {
                    remoteViews.setTextViewText(C0092c.m347c(f1455y, "SUS_title"), str3);
                }
                this.f1457A.contentView = remoteViews;
                this.f1457A.contentIntent = PendingIntent.getActivity(f1455y, 0, new Intent(), 134217728);
                this.f1458B = (NotificationManager) f1455y.getSystemService(DatabaseTables.LOG_NOTIFICATION);
            }
            String strM253a = C0080c.m253a(str);
            f1429C = new C0141c();
            if (f1429C == null || f1429C.m554a(i, 1, f1455y, this, str2, str3, strM253a, j)) {
                return;
            }
            C0104ae.m447b();
        } catch (Exception e) {
            C0098i.m411b(C0092c.f1339b, e.getMessage());
            C0104ae.m447b();
        }
    }

    /* JADX INFO: renamed from: a */
    public void m490a(C0085a c0085a, EnumC0088d enumC0088d, boolean z) {
        String strM343b;
        if (f1455y == null || c0085a == null) {
            C0098i.m411b(C0092c.f1339b, "null == myApplicationContext || null == susVerInfo!!!");
            return;
        }
        C0098i.m409a(C0092c.f1339b, "showUpdatePromptActivity entry");
        String strM282g = c0085a.m282g();
        String strM276d = c0085a.m276d();
        String strM272b = c0085a.m272b();
        if (strM272b == null || strM272b.length() <= 0) {
            strM272b = strM276d;
        }
        String str = String.valueOf(C0092c.m343b(f1455y, "SUS_UPDATEVERPROMPT_VERNAME")) + strM272b + "\n" + C0092c.m343b(f1455y, "SUS_UPDATEVERPROMPT_VERSIZE") + C0092c.m341b(c0085a.m280f().longValue()) + "\n" + C0092c.m343b(f1455y, "SUS_UPDATESIZEPROMPT_WLAN");
        C0098i.m409a(C0092c.f1339b, "SUSUIHandler.showUpdatePromptActivity(), start UpdateActivity");
        if (strM282g != null && C0092c.f1297aA.equals(strM282g)) {
            strM282g = null;
        }
        if (strM282g != null && strM282g.length() > 0 && (strM343b = C0092c.m343b(f1455y, "SUS_UPDATEDESC")) != null && strM343b.length() > 0) {
            strM282g = URLEncoder.encode(String.valueOf(strM343b) + "\n" + strM282g);
            C0098i.m409a(C0092c.f1339b, "SUSUIHandler.showUpdatePromptActivity(), Stoneage1 debug3");
        }
        if (C0092c.m397w()) {
            m469a(enumC0088d.ordinal(), str, c0085a.m276d(), strM282g, z);
        } else {
            m493b(enumC0088d.ordinal(), str, c0085a.m276d(), strM282g, z);
        }
    }

    /* JADX INFO: renamed from: a */
    public void m491a(boolean z) {
        if (f1456z != null) {
            Message message = new Message();
            message.what = EnumC0086b.m293a(EnumC0086b.SUS_DOWNLOAD_EXCEPTION_EVENT);
            message.obj = Boolean.valueOf(z);
            f1456z.sendMessage(message);
        }
    }

    /* JADX INFO: renamed from: b */
    public void m492b() {
        if (this.f1458B != null) {
            this.f1458B.cancel(93);
        }
        this.f1457A = null;
    }

    /* JADX INFO: renamed from: b */
    public void m493b(int i, String str, String str2, String str3, boolean z) {
        Intent intent = new Intent();
        intent.setClass(f1455y, SUSPromptActivity.class);
        intent.putExtra("actiontype", "UPDATEPROMPT");
        intent.putExtra("versioninfo", str);
        C0098i.m409a(C0092c.f1339b, "SUSUIHandler.showUpdatePromptActivity(), Stoneage1 debug0");
        intent.putExtra("showUserSettingsEnable", z);
        intent.putExtra("usersettings", i);
        C0098i.m409a(C0092c.f1339b, "SUSUIHandler.showUpdatePromptActivity(), Stoneage1 debug01");
        intent.putExtra("newversioncode", Integer.valueOf(str2));
        C0098i.m409a(C0092c.f1339b, "SUSUIHandler.showUpdatePromptActivity(), Stoneage1 debug1");
        if (str3 != null && str3.length() > 0) {
            intent.putExtra("UPDATE_DESC", str3);
            C0098i.m409a(C0092c.f1339b, "SUSUIHandler.showUpdatePromptActivity(), Stoneage1 debug2");
        }
        intent.setFlags(268435456);
        SUSPromptActivity.m432a(f1456z);
        f1455y.startActivity(intent);
    }

    @Override // android.widget.CompoundButton.OnCheckedChangeListener
    public void onCheckedChanged(CompoundButton compoundButton, boolean z) {
    }
}
