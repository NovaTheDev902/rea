package com.lenovo.safecenter.broadcast;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.provider.Settings;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.adapter.DaoImpl;
import com.lenovo.safecenter.adapter.DbAdapter;
import com.lenovo.safecenter.database.AppUtil;
import com.lenovo.safecenter.support.SafePaymentApp;
import com.lenovo.safecenter.support.SecurityService;
import com.tencent.tmsecure.utils.Log;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import org.apache.commons.httpclient.cookie.CookieSpec;

/* JADX INFO: loaded from: classes.dex */
public class InputMethodChangeBroadcast extends BroadcastReceiver {

    /* JADX INFO: renamed from: a */
    private DaoImpl f3407a;

    /* JADX INFO: renamed from: b */
    private HashMap<String, Boolean> f3408b;

    /* JADX INFO: renamed from: c */
    private Context f3409c;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1451a(InputMethodChangeBroadcast x0, String x1) {
        try {
            Log.m2634e("ydp", "insterApp pkgName:" + x1);
            ApplicationInfo applicationInfo = x0.f3409c.getPackageManager().getApplicationInfo(x1, 8192);
            String string = applicationInfo.loadLabel(x0.f3409c.getPackageManager()).toString();
            applicationInfo.loadIcon(x0.f3409c.getPackageManager());
            x0.f3407a.insterForUserApp(string, x1, AppUtil.getCretMD5(x0.f3409c, x1), String.valueOf(new File(applicationInfo.sourceDir).length()), "true", "true");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /* JADX WARN: Type inference failed for: r1v28, types: [com.lenovo.safecenter.broadcast.InputMethodChangeBroadcast$1] */
    @Override // android.content.BroadcastReceiver
    public void onReceive(final Context context, Intent intent) {
        if (intent.getAction().equals("com.safecenter.boot.safeinput")) {
            Log.m2636i("ydp", "InputMethodChangeBroadcast ---boot");
        }
        this.f3409c = context;
        if (SecurityService.mSIL().size() == 0) {
            new Thread() { // from class: com.lenovo.safecenter.broadcast.InputMethodChangeBroadcast.1
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    InputStream is = context.getResources().openRawResource(C0415R.raw.si);
                    BufferedReader localBufferedReader = new BufferedReader(new InputStreamReader(is));
                    while (true) {
                        try {
                            String buffer = localBufferedReader.readLine();
                            if (buffer != null) {
                                if (!buffer.equals("")) {
                                    String[] temp = buffer.split(",");
                                    SecurityService.mSIL().put(temp[2], temp);
                                }
                            } else {
                                localBufferedReader.close();
                                is.close();
                                return;
                            }
                        } catch (IOException e) {
                            e.printStackTrace();
                            return;
                        }
                    }
                }
            }.start();
        }
        this.f3407a = new DaoImpl(new DbAdapter(context));
        this.f3408b = new HashMap<>();
        String s = Settings.Secure.getString(context.getContentResolver(), "default_input_method");
        if (s != null) {
            try {
                if (s.equals("com.android.inputmethod.latin/.LatinIME") || s.equals("com.android.inputmethod.pinyin/.PinyinIME") || s.equals("com.google.android.inputmethod.pinyin/.PinyinIME") || !isThirdpartApp(s.substring(0, s.indexOf(CookieSpec.PATH_DELIM)))) {
                    Settings.System.putString(this.f3409c.getContentResolver(), "safe_input_method", s);
                } else if (SecurityService.mSIL().get(s) != null) {
                    m1453a(SecurityService.mSIL().get(s)[0], SecurityService.mSIL().get(s)[1], s);
                }
            } catch (StringIndexOutOfBoundsException e) {
            }
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX WARN: Type inference failed for: r1v9, types: [com.lenovo.safecenter.broadcast.InputMethodChangeBroadcast$2] */
    /* JADX INFO: renamed from: a */
    public void m1453a(final String pkgName, final String md5, final String id) {
        SafePaymentApp userApp = this.f3407a.queryByPackageNameForUserApp(pkgName);
        if (userApp == null) {
            if (this.f3408b.get(pkgName) == null) {
                this.f3408b.put(pkgName, true);
                new Thread() { // from class: com.lenovo.safecenter.broadcast.InputMethodChangeBroadcast.2
                    @Override // java.lang.Thread, java.lang.Runnable
                    public final void run() {
                        Log.m2634e("ydp", "insterApp ---:" + pkgName);
                        InputMethodChangeBroadcast.m1451a(InputMethodChangeBroadcast.this, pkgName);
                        InputMethodChangeBroadcast.this.m1453a(pkgName, md5, id);
                    }
                }.start();
                return;
            }
            return;
        }
        if (userApp.getApp_md5().equals(md5)) {
            Settings.System.putString(this.f3409c.getContentResolver(), "safe_input_method", id);
            Log.m2636i("ydp", "InputMethodChangeBroadcast:" + id + "    " + Settings.System.getString(this.f3409c.getContentResolver(), "safe_input_method"));
        }
    }

    public boolean isThirdpartApp(String pkg) {
        try {
            ApplicationInfo appInfo = this.f3409c.getPackageManager().getApplicationInfo(pkg, 0);
            if ((appInfo.flags & 128) == 0 && (appInfo.flags & 1) != 0) {
                return false;
            }
            return true;
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
            return false;
        }
    }
}
