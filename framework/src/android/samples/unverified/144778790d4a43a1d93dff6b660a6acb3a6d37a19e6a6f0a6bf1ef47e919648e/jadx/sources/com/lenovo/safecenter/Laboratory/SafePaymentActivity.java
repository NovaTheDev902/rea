package com.lenovo.safecenter.Laboratory;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.preference.PreferenceManager;
import android.provider.Settings;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.inputmethod.InputMethodInfo;
import android.view.inputmethod.InputMethodManager;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.adapter.DaoImpl;
import com.lenovo.safecenter.adapter.DbAdapter;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class SafePaymentActivity extends Activity {

    /* JADX INFO: renamed from: a */
    ImageView f2638a;

    /* JADX INFO: renamed from: b */
    ImageView f2639b;

    /* JADX INFO: renamed from: c */
    TextView f2640c;

    /* JADX INFO: renamed from: d */
    TextView f2641d;

    /* JADX INFO: renamed from: e */
    TextView f2642e;

    /* JADX INFO: renamed from: f */
    DaoImpl f2643f;

    /* JADX INFO: renamed from: g */
    PackageManager f2644g;

    /* JADX INFO: renamed from: h */
    ActivityManager f2645h;

    /* JADX INFO: renamed from: i */
    MyProcessObserver f2646i;

    /* JADX INFO: renamed from: j */
    SharedPreferences f2647j;

    /* JADX INFO: renamed from: k */
    CustomDialog f2648k;

    /* JADX INFO: renamed from: l */
    RelativeLayout f2649l;

    /* JADX INFO: renamed from: m */
    RelativeLayout f2650m;

    /* JADX INFO: renamed from: n */
    private Handler f2651n = new Handler() { // from class: com.lenovo.safecenter.Laboratory.SafePaymentActivity.4
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    InputMethodManager m = (InputMethodManager) SafePaymentActivity.this.getSystemService("input_method");
                    m.toggleSoftInput(0, 2);
                    SafePaymentActivity.this.f2651n.sendEmptyMessageDelayed(2, 1000L);
                    break;
                case 2:
                    SafePaymentActivity.this.f2648k.dismiss();
                    int i = SafePaymentActivity.this.f2647j.getInt(Const.KEY_IS_SAFEINPUT_METHOD_STATE, -1);
                    if (i != 1) {
                        Settings.System.putInt(SafePaymentActivity.this.getContentResolver(), "safeinputmethod_on", 0);
                        SafePaymentActivity.this.f2647j.edit().putInt(Const.KEY_IS_SAFEINPUT_METHOD_STATE, 0).commit();
                        SafePaymentActivity.this.f2642e.setText(SafePaymentActivity.this.getString(C0415R.string.inputmethodapp) + SafePaymentActivity.this.getString(C0415R.string.not_support_safeinput));
                        new CustomDialog.Builder(SafePaymentActivity.this).setTitle(C0415R.string.info).setMessage(C0415R.string.safeinput_test_over_no).setPositiveButton(C0415R.string.ok, (DialogInterface.OnClickListener) null).show();
                    } else {
                        Settings.System.putInt(SafePaymentActivity.this.getContentResolver(), "safeinputmethod_on", 1);
                        SafePaymentActivity.this.f2641d.setText(C0415R.string.opend);
                        SafePaymentActivity.this.f2641d.setTextColor(C0415R.color.gray2);
                        SafePaymentActivity.this.f2639b.setImageResource(C0415R.drawable.btn_on);
                        Toast.makeText(SafePaymentActivity.this, C0415R.string.safeinput_test_over_ok, 1).show();
                    }
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1226a(SafePaymentActivity x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.info).setMessage(C0415R.string.disable_safepayment_tip).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.SafePaymentActivity.5
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                SafePaymentActivity.this.f2646i.unRegister();
                SafePaymentActivity.this.f2640c.setText(C0415R.string.closed);
                SafePaymentActivity.this.f2640c.setTextColor(-65536);
                SafePaymentActivity.this.f2638a.setImageResource(C0415R.drawable.btn_off);
                TrackEvent.reportsafePay(false);
            }
        }).setNegativeButton(C0415R.string.cancel, (DialogInterface.OnClickListener) null).setColorPositiveButton(false).setColorNegativeButton(true).show();
    }

    /* JADX INFO: renamed from: b */
    static /* synthetic */ void m1228b(SafePaymentActivity x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.info).setMessage(C0415R.string.disable_safeinput_tip).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.SafePaymentActivity.6
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                Settings.System.putInt(SafePaymentActivity.this.getContentResolver(), "safeinputmethod_on", 0);
                SafePaymentActivity.this.f2641d.setText(C0415R.string.closed);
                SafePaymentActivity.this.f2641d.setTextColor(-65536);
                SafePaymentActivity.this.f2639b.setImageResource(C0415R.drawable.btn_off);
                try {
                    String oldInput = Settings.System.getString(SafePaymentActivity.this.getContentResolver(), "old_input");
                    if (Settings.Secure.getString(SafePaymentActivity.this.getContentResolver(), "default_input_method").equals("com.android.inputmethod.latin/.LatinIME") && oldInput != null && !oldInput.equals("")) {
                        Settings.Secure.putString(SafePaymentActivity.this.getContentResolver(), "default_input_method", oldInput);
                    }
                } catch (Exception e) {
                    Log.e("ydp", "safeinput error" + e);
                }
                TrackEvent.reportSafeInputMethod(false);
            }
        }).setNegativeButton(C0415R.string.cancel, (DialogInterface.OnClickListener) null).setColorPositiveButton(false).setColorNegativeButton(true).show();
    }

    @Override // android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.safepayment_main);
        Settings.System.putString(getContentResolver(), "safe_input_method", "com.android.inputmethod.latin/.LatinIME");
        Settings.System.putString(getContentResolver(), "safe_input_broadcast", "com.lenovo.safecenter.safeinputmethod");
        this.f2647j = PreferenceManager.getDefaultSharedPreferences(this);
        TextView topBar = (TextView) findViewById(C0415R.id.txt_title);
        topBar.setText(C0415R.string.safepayment);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.SafePaymentActivity.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                SafePaymentActivity.this.finish();
            }
        });
        m1227a();
        this.f2644g = getPackageManager();
        this.f2645h = (ActivityManager) getSystemService("activity");
        this.f2646i = MyProcessObserver.getDefault(this);
        this.f2643f = new DaoImpl(new DbAdapter(getApplicationContext()));
        this.f2649l = (RelativeLayout) findViewById(C0415R.id.safeinputmethod_parent);
        this.f2642e = (TextView) findViewById(C0415R.id.safeinput_title);
        this.f2640c = (TextView) findViewById(C0415R.id.detail_paymentapp);
        this.f2641d = (TextView) findViewById(C0415R.id.detail_safeinputmethod);
        this.f2638a = (ImageView) findViewById(C0415R.id.checkBox_paymentapp);
        this.f2639b = (ImageView) findViewById(C0415R.id.checkBox_safeinputmethod);
        this.f2650m = (RelativeLayout) findViewById(C0415R.id.safeinput_img);
        if (this.f2647j.getBoolean(Const.KEY_IS_SAFEPAYMEN_ON, true)) {
            this.f2638a.setImageResource(C0415R.drawable.btn_on);
            this.f2640c.setText(C0415R.string.payment_open);
            this.f2640c.setTextColor(C0415R.color.gray2);
        } else {
            this.f2638a.setImageResource(C0415R.drawable.btn_off);
            this.f2640c.setText(C0415R.string.closed);
            this.f2640c.setTextColor(-65536);
        }
        if (Settings.System.getInt(getContentResolver(), "safeinputmethod_on", 0) == 1) {
            this.f2639b.setImageResource(C0415R.drawable.btn_on);
            this.f2641d.setText(C0415R.string.opend);
            this.f2641d.setTextColor(C0415R.color.gray2);
        } else {
            this.f2639b.setImageResource(C0415R.drawable.btn_off);
            this.f2641d.setText(C0415R.string.closed);
            this.f2641d.setTextColor(-65536);
        }
        if (this.f2647j.getInt(Const.KEY_IS_SAFEINPUT_METHOD_STATE, -1) == 0) {
            this.f2642e.setText(getString(C0415R.string.inputmethodapp) + getString(C0415R.string.not_support_safeinput));
        }
        this.f2638a.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.SafePaymentActivity.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (!SafePaymentActivity.this.f2647j.getBoolean(Const.KEY_IS_SAFEPAYMEN_ON, true)) {
                    SafePaymentActivity.this.f2646i.register();
                    SafePaymentActivity.this.f2640c.setText(C0415R.string.payment_open);
                    SafePaymentActivity.this.f2640c.setTextColor(C0415R.color.gray2);
                    SafePaymentActivity.this.f2638a.setImageResource(C0415R.drawable.btn_on);
                    TrackEvent.reportsafePay(true);
                    return;
                }
                SafePaymentActivity.m1226a(SafePaymentActivity.this);
            }
        });
        this.f2639b.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.SafePaymentActivity.3
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (Settings.System.getInt(SafePaymentActivity.this.getContentResolver(), "safeinputmethod_on", 0) != 1) {
                    if (SafePaymentActivity.this.m1227a()) {
                        int i = SafePaymentActivity.this.f2647j.getInt(Const.KEY_IS_SAFEINPUT_METHOD_STATE, -1);
                        if (i == -1) {
                            Settings.System.putInt(SafePaymentActivity.this.getContentResolver(), "safeinputmethod_on", 1);
                            View view = LayoutInflater.from(SafePaymentActivity.this).inflate(C0415R.layout.safeinput_testdialog_layout, (ViewGroup) null);
                            CustomDialog.Builder cd = new CustomDialog.Builder(SafePaymentActivity.this).setTitle(C0415R.string.safeinput_test).setContentView(view);
                            SafePaymentActivity.this.f2648k = cd.show();
                            cd.setButtonVisible(false);
                            Toast.makeText(SafePaymentActivity.this, C0415R.string.safeinput_test_, 1).show();
                            SafePaymentActivity.this.f2651n.sendEmptyMessageDelayed(1, 500L);
                            return;
                        }
                        if (i == 0) {
                            new CustomDialog.Builder(SafePaymentActivity.this).setTitle(C0415R.string.info).setMessage(C0415R.string.safeinput_test_over_no).setPositiveButton(C0415R.string.ok, (DialogInterface.OnClickListener) null).show();
                            return;
                        }
                        Settings.System.putInt(SafePaymentActivity.this.getContentResolver(), "safeinputmethod_on", 1);
                        SafePaymentActivity.this.f2641d.setText(C0415R.string.opend);
                        SafePaymentActivity.this.f2641d.setTextColor(C0415R.color.gray2);
                        SafePaymentActivity.this.f2639b.setImageResource(C0415R.drawable.btn_on);
                        TrackEvent.reportSafeInputMethod(true);
                        return;
                    }
                    Toast.makeText(SafePaymentActivity.this, C0415R.string.no_safeinputmethod, 1).show();
                    return;
                }
                SafePaymentActivity.m1228b(SafePaymentActivity.this);
            }
        });
        if (!TrafficStatsService.nacServerIsExist()) {
            this.f2642e.setVisibility(8);
            this.f2649l.setVisibility(8);
            this.f2650m.setVisibility(8);
        }
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        super.onResume();
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public boolean m1227a() {
        List<InputMethodInfo> InputMethods = ((InputMethodManager) getSystemService("input_method")).getEnabledInputMethodList();
        for (int i = 0; i < InputMethods.size(); i++) {
            String NewInputMethodName = InputMethods.get(i).getId();
            if (NewInputMethodName.equals("com.android.inputmethod.latin/.LatinIME")) {
                Log.i("info", "id:" + NewInputMethodName);
                return true;
            }
        }
        return false;
    }
}
