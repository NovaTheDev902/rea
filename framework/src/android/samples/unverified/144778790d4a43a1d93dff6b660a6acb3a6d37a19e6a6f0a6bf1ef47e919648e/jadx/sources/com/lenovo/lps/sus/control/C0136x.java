package com.lenovo.lps.sus.control;

import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Handler;
import com.lenovo.lps.sus.EventType;
import com.lenovo.lps.sus.SUSListener;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;
import java.io.File;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.x */
/* JADX INFO: loaded from: classes.dex */
public class C0136x extends Thread {

    /* JADX INFO: renamed from: a */
    private SUSListener f1539a;

    /* JADX INFO: renamed from: b */
    private Handler f1540b;

    /* JADX INFO: renamed from: e */
    private Context f1543e;

    /* JADX INFO: renamed from: f */
    private String f1544f;

    /* JADX INFO: renamed from: g */
    private String f1545g;

    /* JADX INFO: renamed from: j */
    private int f1548j;

    /* JADX INFO: renamed from: k */
    private boolean f1549k;

    /* JADX INFO: renamed from: c */
    private boolean f1541c = false;

    /* JADX INFO: renamed from: d */
    private boolean f1542d = false;

    /* JADX INFO: renamed from: h */
    private boolean f1546h = false;

    /* JADX INFO: renamed from: i */
    private Integer f1547i = -100;

    public C0136x(Context context, String str, String str2, Handler handler, SUSListener sUSListener, int i, boolean z) {
        this.f1539a = null;
        this.f1540b = null;
        this.f1543e = null;
        this.f1544f = null;
        this.f1545g = null;
        this.f1548j = 0;
        this.f1549k = false;
        this.f1543e = context;
        this.f1544f = str;
        this.f1545g = str2;
        this.f1540b = handler;
        this.f1539a = sUSListener;
        this.f1548j = i;
        this.f1549k = z;
        C0098i.m409a(C0092c.f1339b, "InstallThread, myContext=" + this.f1543e + "; myFilePath=" + this.f1544f + "; myInstallerPackageName=" + this.f1545g + "; myMSGHandler=" + this.f1540b + "; mySUSListener=" + this.f1539a + "; myInstallType=" + this.f1548j + "; myOnlySilentInstallFlag=" + this.f1549k);
    }

    /* JADX WARN: Code duplicated, block: B:53:0x018b  */
    @Override // java.lang.Thread, java.lang.Runnable
    public void run() {
        String str;
        String str2;
        int i = 0;
        C0098i.m409a(C0092c.f1339b, "InstallThread run myInstallType=" + this.f1548j);
        switch (this.f1548j) {
            case 0:
                File file = new File(this.f1544f);
                if (file.exists() && (str2 = "file://" + file.getAbsolutePath()) != null && this.f1543e != null) {
                    Intent intent = new Intent("android.intent.action.VIEW");
                    intent.setFlags(268435456);
                    intent.putExtra("apk_from", "com.lenovo.appstore");
                    C0098i.m409a(C0092c.f1339b, "InstallThread 0 apk_from=com.lenovo.appstore");
                    intent.setDataAndType(Uri.parse(str2), "application/vnd.android.package-archive");
                    this.f1543e.startActivity(intent);
                    this.f1542d = true;
                    C0098i.m409a(C0092c.f1339b, "InstallThread 0 isInstalledFlag=" + this.f1542d);
                }
                break;
            case 1:
                this.f1546h = true;
                if (this.f1543e.checkCallingOrSelfPermission("android.permission.INSTALL_PACKAGES") == 0) {
                    Uri uriFromFile = Uri.fromFile(new File(this.f1544f));
                    PackageManager packageManager = this.f1543e.getPackageManager();
                    C0120h c0120h = new C0120h(this);
                    if (packageManager != null) {
                        try {
                            packageManager.installPackage(uriFromFile, c0120h, 2, this.f1545g);
                            C0098i.m409a(C0092c.f1339b, "InstallThread 1 execute pm.installPackage");
                        } catch (SecurityException e) {
                            this.f1541c = true;
                            this.f1547i = -100;
                            C0098i.m409a(C0092c.f1339b, "InstallThread 1 SecurityException=" + e.getMessage());
                        }
                        while (!this.f1541c && !this.f1542d) {
                            i++;
                            if (i >= 300) {
                                break;
                            } else {
                                try {
                                    C0098i.m409a(C0092c.f1339b, "InstallThread 1 sleep 200ms");
                                    sleep(200L);
                                } catch (InterruptedException e2) {
                                    C0098i.m409a(C0092c.f1339b, "InstallThread 1 sleep InterruptedException e=" + e2.getMessage());
                                }
                            }
                        }
                    }
                }
                break;
            case 2:
                Uri uriFromFile2 = Uri.fromFile(new File(this.f1544f));
                PackageManager packageManager2 = this.f1543e.getPackageManager();
                this.f1541c = false;
                this.f1546h = true;
                C0119g c0119g = new C0119g(this);
                if (packageManager2 != null) {
                    try {
                        packageManager2.installPackage(uriFromFile2, c0119g, 2, this.f1545g);
                        C0098i.m409a(C0092c.f1339b, "InstallThread 1 execute pm.installPackage");
                    } catch (SecurityException e3) {
                        this.f1541c = true;
                        this.f1547i = -100;
                        C0098i.m409a(C0092c.f1339b, "InstallThread 1 SecurityException=" + e3.getMessage());
                    }
                    while (!this.f1541c && !this.f1542d) {
                        i++;
                        if (i >= 300) {
                            if (this.f1541c) {
                                C0092c.m352d(this.f1543e, this.f1544f);
                            }
                            break;
                        } else {
                            try {
                                C0098i.m409a(C0092c.f1339b, "InstallThread 1 sleep 200ms");
                                sleep(200L);
                            } catch (InterruptedException e4) {
                                C0098i.m409a(C0092c.f1339b, "InstallThread 1 sleep InterruptedException e=" + e4.getMessage());
                            }
                        }
                    }
                    if (this.f1541c) {
                        C0092c.m352d(this.f1543e, this.f1544f);
                    }
                }
                break;
            case 3:
                Uri uriFromFile3 = Uri.fromFile(new File(this.f1544f));
                PackageManager packageManager3 = this.f1543e.getPackageManager();
                this.f1546h = true;
                C0121i c0121i = new C0121i(this);
                if (packageManager3 != null) {
                    try {
                        packageManager3.installPackage(uriFromFile3, c0121i, 2, this.f1545g);
                        C0098i.m409a(C0092c.f1339b, "InstallThread 2 execute pm.installPackage");
                    } catch (SecurityException e5) {
                        this.f1541c = true;
                        this.f1547i = -100;
                        C0098i.m409a(C0092c.f1339b, "InstallThread 2 SecurityException=" + e5.getMessage());
                        File file2 = new File(this.f1544f);
                        if (file2.exists() && (str = "file://" + file2.getAbsolutePath()) != null && this.f1543e != null) {
                            Intent intent2 = new Intent("android.intent.action.VIEW");
                            intent2.setFlags(268435456);
                            intent2.putExtra("apk_from", "com.lenovo.appstore");
                            intent2.setDataAndType(Uri.parse(str), "application/vnd.android.package-archive");
                            this.f1543e.startActivity(intent2);
                            this.f1542d = true;
                        }
                    }
                    while (!this.f1541c && !this.f1542d) {
                        i++;
                        if (i >= 300) {
                            break;
                        } else {
                            try {
                                C0098i.m409a(C0092c.f1339b, "InstallThread 2 sleep 200ms");
                                sleep(200L);
                            } catch (InterruptedException e6) {
                                C0098i.m409a(C0092c.f1339b, "InstallThread 2 sleep InterruptedException e=" + e6.getMessage());
                            }
                        }
                    }
                }
                break;
        }
        if (this.f1539a != null && this.f1546h) {
            if (1 == this.f1547i.intValue()) {
                this.f1539a.onUpdateNotification(EventType.SUS_SILENCEINSTALL_FINISH, C0092c.f1288S);
            } else {
                this.f1539a.onUpdateNotification(EventType.SUS_SILENCEINSTALL_FAIL, String.valueOf(this.f1547i));
            }
        }
        C0098i.m409a(C0092c.f1339b, "InstallThread exit,isInstalledFlag=" + this.f1542d + "; mySilenceInstallResultCode=" + this.f1547i);
    }
}
