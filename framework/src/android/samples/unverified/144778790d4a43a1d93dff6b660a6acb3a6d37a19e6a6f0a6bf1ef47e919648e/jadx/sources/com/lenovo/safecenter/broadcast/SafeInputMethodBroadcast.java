package com.lenovo.safecenter.broadcast;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.res.Configuration;
import android.os.Handler;
import android.os.Message;
import android.preference.PreferenceManager;
import android.provider.Settings;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.view.inputmethod.InputMethodInfo;
import android.view.inputmethod.InputMethodManager;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.support.SecurityService;
import com.lenovo.safecenter.utils.Const;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class SafeInputMethodBroadcast extends BroadcastReceiver {

    /* JADX INFO: renamed from: a */
    private static WindowManager f3434a;

    /* JADX INFO: renamed from: g */
    private static Thread f3439g;

    /* JADX INFO: renamed from: i */
    private static EditText f3441i;

    /* JADX INFO: renamed from: b */
    private WindowManager.LayoutParams f3444b;

    /* JADX INFO: renamed from: l */
    private Context f3445l;

    /* JADX INFO: renamed from: m */
    private InputMethodManager f3446m;

    /* JADX INFO: renamed from: n */
    private SharedPreferences f3447n;

    /* JADX INFO: renamed from: o */
    private Handler f3448o = new Handler() { // from class: com.lenovo.safecenter.broadcast.SafeInputMethodBroadcast.2
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    Log.i("ydp", "in handler");
                    SafeInputMethodBroadcast.f3434a.addView(SafeInputMethodBroadcast.f3441i, SafeInputMethodBroadcast.this.f3444b);
                    SafeInputMethodBroadcast.f3441i.setFocusable(true);
                    SafeInputMethodBroadcast.f3434a.removeView(SafeInputMethodBroadcast.f3441i);
                    SafeInputMethodBroadcast.this.f3446m.toggleSoftInput(0, 2);
                    break;
                case 2:
                    Toast t = new Toast(SafeInputMethodBroadcast.this.f3445l);
                    LayoutInflater inflater = LayoutInflater.from(SafeInputMethodBroadcast.this.f3445l);
                    View layout = inflater.inflate(C0415R.layout.toast, (ViewGroup) null);
                    TextView tv = (TextView) layout.findViewById(C0415R.id.toast_title);
                    tv.setText(C0415R.string.inputmethodswitch);
                    t.setGravity(49, 0, 0);
                    t.setDuration(0);
                    t.setView(layout);
                    t.show();
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: c */
    private static boolean f3435c = false;

    /* JADX INFO: renamed from: d */
    private static String f3436d = "";

    /* JADX INFO: renamed from: e */
    private static long f3437e = 0;

    /* JADX INFO: renamed from: f */
    private static boolean f3438f = false;

    /* JADX INFO: renamed from: h */
    private static String f3440h = "";

    /* JADX INFO: renamed from: j */
    private static boolean f3442j = false;

    /* JADX INFO: renamed from: k */
    private static long f3443k = 0;

    /* JADX INFO: renamed from: c */
    static /* synthetic */ boolean m1466c() {
        f3442j = false;
        return false;
    }

    /* JADX INFO: renamed from: g */
    static /* synthetic */ Thread m1470g() {
        f3439g = null;
        return null;
    }

    @Override // android.content.BroadcastReceiver
    public void onReceive(final Context context, Intent intent) {
        boolean z;
        Configuration config = context.getResources().getConfiguration();
        this.f3445l = context;
        this.f3446m = (InputMethodManager) this.f3445l.getSystemService("input_method");
        List<InputMethodInfo> enabledInputMethodList = ((InputMethodManager) this.f3445l.getSystemService("input_method")).getEnabledInputMethodList();
        int i = 0;
        while (true) {
            if (i >= enabledInputMethodList.size()) {
                z = false;
                break;
            }
            String id = enabledInputMethodList.get(i).getId();
            if (id.equals("com.android.inputmethod.latin/.LatinIME")) {
                Log.i("info", "id:" + id);
                z = true;
                break;
            }
            i++;
        }
        if (!z) {
            Settings.System.putInt(this.f3445l.getContentResolver(), "safeinputmethod_on", 0);
            return;
        }
        f3434a = (WindowManager) context.getSystemService("window");
        this.f3447n = PreferenceManager.getDefaultSharedPreferences(context);
        this.f3447n.edit().putInt(Const.KEY_IS_SAFEINPUT_METHOD_STATE, 1).commit();
        if (this.f3444b == null) {
            this.f3444b = new WindowManager.LayoutParams();
            this.f3444b.width = -2;
            this.f3444b.height = -2;
            this.f3444b.flags = 1280;
            this.f3444b.type = 2002;
        }
        if (f3441i == null) {
            f3441i = new EditText(context);
        }
        f3438f = intent.getBooleanExtra("isPassword", false);
        if (config.orientation == 2 && !f3438f) {
            Log.i("ydp", "orientation return");
            return;
        }
        if (f3438f) {
            this.f3448o.sendEmptyMessage(2);
        }
        Log.w("ydp", "isPwd:" + f3438f);
        f3436d = intent.getStringExtra("oldInputMethod");
        f3435c = intent.getBooleanExtra("onlySend", false);
        Log.i("ydp", "sendonly:" + f3435c);
        if (f3435c) {
            Log.i("ydp", "sendonly return");
            Settings.System.putString(context.getContentResolver(), "old_input", "");
            return;
        }
        String s = Settings.Secure.getString(context.getContentResolver(), "default_input_method");
        if (SecurityService.mSIL().get(s) == null && !s.equals("com.android.inputmethod.pinyin/.PinyinIME") && !s.equals("com.google.android.inputmethod.pinyin/.PinyinIME")) {
            if (f3436d != null && !f3436d.equals("")) {
                f3440h = f3436d;
            }
            if (f3439g == null && System.currentTimeMillis() - f3437e > 2000) {
                if (f3438f) {
                    m1464b("com.android.inputmethod.latin/.LatinIME");
                    Settings.System.putString(context.getContentResolver(), "old_input", f3440h);
                } else {
                    m1464b(f3440h);
                    Settings.System.putString(context.getContentResolver(), "old_input", "");
                    f3440h = "";
                }
                f3437e = System.currentTimeMillis();
                return;
            }
            if (f3439g == null) {
                f3439g = new Thread() { // from class: com.lenovo.safecenter.broadcast.SafeInputMethodBroadcast.1
                    @Override // java.lang.Thread, java.lang.Runnable
                    public final void run() {
                        Log.i("ydp", "in thread");
                        try {
                            Thread.sleep(500L);
                            while (SafeInputMethodBroadcast.f3442j) {
                                Thread.sleep(150L);
                                if (System.currentTimeMillis() - SafeInputMethodBroadcast.f3443k > 1000) {
                                    SafeInputMethodBroadcast.m1466c();
                                }
                                Log.i("ydp", "in the add");
                            }
                            if (!SafeInputMethodBroadcast.f3438f || SafeInputMethodBroadcast.f3435c) {
                                if (!SafeInputMethodBroadcast.f3438f) {
                                    SafeInputMethodBroadcast.this.m1464b(SafeInputMethodBroadcast.f3440h);
                                    Settings.System.putString(context.getContentResolver(), "old_input", "");
                                    String unused = SafeInputMethodBroadcast.f3440h = "";
                                }
                            } else {
                                SafeInputMethodBroadcast.this.m1464b("com.android.inputmethod.latin/.LatinIME");
                                Settings.System.putString(context.getContentResolver(), "old_input", SafeInputMethodBroadcast.f3440h);
                            }
                            Thread.sleep(500L);
                            long unused2 = SafeInputMethodBroadcast.f3437e = System.currentTimeMillis();
                            SafeInputMethodBroadcast.m1470g();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                };
                f3439g.start();
            } else {
                f3442j = true;
                f3443k = System.currentTimeMillis();
            }
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: b */
    public void m1464b(String id) {
        if (id != null) {
            try {
                if (!id.equals("")) {
                    this.f3446m.hideSoftInputFromWindow(null, 2);
                    this.f3446m.setInputMethod(null, id);
                    Settings.System.putString(this.f3445l.getContentResolver(), "safe_input_method", "com.android.inputmethod.latin/.LatinIME");
                }
            } catch (Exception e) {
                Log.e("ydp", "SwitchInputMethod error" + e);
            }
        }
    }
}
