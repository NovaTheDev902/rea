package com.lenovo.safecenter.safemode;

import android.content.ActivityNotFoundException;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageInfo;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.view.inputmethod.InputMethodManager;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.MainTab.AppDownloadActivity;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.net.correct.TrafficCorrectSetting;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.DataHelpUtils;
import com.lenovo.safecenter.utils.DialogUtil;
import com.lenovo.safecenter.utils.PwdUtil;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import com.lenovo.safecenter.utils.update.LeSafeUpdate;
import java.util.HashMap;

/* JADX INFO: loaded from: classes.dex */
public class PrivateMainActivity extends BaseTitleActivity {

    /* JADX INFO: renamed from: a */
    private PrivateItemApater f5184a;

    /* JADX INFO: renamed from: b */
    private TextView f5185b;

    /* JADX INFO: renamed from: c */
    private ListView f5186c;

    /* JADX INFO: renamed from: d */
    private ImageView f5187d;

    /* JADX INFO: renamed from: e */
    private CustomDialog f5188e;

    /* JADX INFO: renamed from: g */
    private C0925a f5190g;

    /* JADX INFO: renamed from: h */
    private LeSafeUpdate f5191h;

    /* JADX INFO: renamed from: i */
    private boolean f5192i;

    /* JADX INFO: renamed from: f */
    private HashMap<String, Long> f5189f = new HashMap<>();

    /* JADX INFO: renamed from: j */
    private Handler f5193j = new Handler() { // from class: com.lenovo.safecenter.safemode.PrivateMainActivity.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    InputMethodManager m = (InputMethodManager) PrivateMainActivity.this.getSystemService("input_method");
                    m.toggleSoftInput(0, 2);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m2146a(PrivateMainActivity x0, final String x1) {
        if (PwdUtil.hasPassword(x0)) {
            View viewInflate = LayoutInflater.from(x0).inflate(C0415R.layout.input_password_content, (ViewGroup) null);
            final TextView textView = (TextView) viewInflate.findViewById(C0415R.id.txt_message);
            textView.setText(C0415R.string.input_privacy_pwd);
            final EditText editText = (EditText) viewInflate.findViewById(C0415R.id.edt_input_pwd);
            if (x0.f5188e == null) {
                x0.f5188e = new CustomDialog.Builder(x0).setTitle(C0415R.string.input_pwd).setContentView(viewInflate).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.PrivateMainActivity.5
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                        String newPwd = editText.getText().toString();
                        if (PwdUtil.checkPassword(PrivateMainActivity.this.getApplicationContext(), newPwd)) {
                            try {
                                PrivateMainActivity.m2150e(PrivateMainActivity.this);
                                Intent i = new Intent(x1);
                                i.putExtra("pwd", PwdUtil.getPassword(PrivateMainActivity.this));
                                PrivateMainActivity.this.startActivity(i);
                            } catch (Exception e) {
                                Toast.makeText(PrivateMainActivity.this, C0415R.string.no_app, 0).show();
                            }
                            PrivateMainActivity.this.f5188e.dismiss();
                            return;
                        }
                        if (newPwd.length() == 0) {
                            textView.setText(C0415R.string.error_tips_null);
                            Animation shake = AnimationUtils.loadAnimation(PrivateMainActivity.this, C0415R.anim.shake);
                            editText.startAnimation(shake);
                        } else {
                            Animation shake2 = AnimationUtils.loadAnimation(PrivateMainActivity.this, C0415R.anim.shake);
                            editText.startAnimation(shake2);
                            editText.setText("");
                            textView.setText(C0415R.string.pwd_error_tips);
                        }
                    }
                }, false).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.PrivateMainActivity.4
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                        PrivateMainActivity.m2149d(PrivateMainActivity.this);
                    }
                }).create();
            }
            x0.f5188e.setOnDismissListener(new DialogInterface.OnDismissListener() { // from class: com.lenovo.safecenter.safemode.PrivateMainActivity.6
                @Override // android.content.DialogInterface.OnDismissListener
                public final void onDismiss(DialogInterface dialog) {
                    PrivateMainActivity.m2149d(PrivateMainActivity.this);
                }
            });
            if (!x0.f5188e.isShowing()) {
                x0.f5188e.show();
            }
            x0.f5193j.sendEmptyMessageDelayed(1, 500L);
        }
    }

    /* JADX INFO: renamed from: c */
    static /* synthetic */ void m2148c(PrivateMainActivity x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.down_info).setMessage(C0415R.string.down_safebox).setPositiveButton(C0415R.string.down_now, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.PrivateMainActivity.2
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                if (WflUtils.isNetworkAvailable(PrivateMainActivity.this)) {
                    if (PrivateMainActivity.this.f5191h == null) {
                        PrivateMainActivity.this.f5191h = new LeSafeUpdate(PrivateMainActivity.this, Const.PACKAGENAME_APP_LOCK, 0, AppDownloadActivity.CHANNEL_KEY_SELF, true, false, false, null);
                    }
                    PrivateMainActivity.this.f5191h.upDate(true);
                    return;
                }
                DialogUtil.createManualUpdateDialog(PrivateMainActivity.this, 4, null);
            }
        }).setNegativeButton(C0415R.string.last_time_do, (DialogInterface.OnClickListener) null).show();
    }

    /* JADX INFO: renamed from: d */
    static /* synthetic */ CustomDialog m2149d(PrivateMainActivity x0) {
        x0.f5188e = null;
        return null;
    }

    /* JADX INFO: renamed from: e */
    static /* synthetic */ boolean m2150e(PrivateMainActivity x0) {
        x0.f5192i = false;
        return false;
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        byte b = 0;
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.privatemain);
        this.f5192i = false;
        if (getIntent().getStringExtra("pwd") != null) {
            if (getIntent().getStringExtra("pwd").equals(DataHelpUtils.execService("pwd", this)) && !PwdUtil.checkPassword(getApplicationContext(), getIntent().getStringExtra("pwd"), false)) {
                setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.privacy_safe, (Integer) null);
            } else if (PwdUtil.checkPassword(getApplicationContext(), getIntent().getStringExtra("pwd"), false)) {
                setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.privacy_safe, Integer.valueOf(C0415R.drawable.rf_perf_title_right));
            }
            findViews();
            this.f5190g = new C0925a(this, b);
            IntentFilter filter = new IntentFilter("android.intent.action.SCREEN_OFF");
            registerReceiver(this.f5190g, filter);
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        } else if (v.getId() == C0415R.id.base_title_right) {
            startActivity(new Intent(this, (Class<?>) ContractSetting.class));
        }
    }

    @Override // android.app.Activity
    protected void onStop() {
        super.onStop();
        this.f5189f.put("timespace", Long.valueOf(System.currentTimeMillis()));
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
        this.f5184a = new PrivateItemApater();
        this.f5186c.setAdapter((ListAdapter) this.f5184a);
        if (this.f5189f.get("timespace") != null && this.f5189f.get("timespace").longValue() + TrafficCorrectSetting.TIME < System.currentTimeMillis()) {
            this.f5192i = true;
        }
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.safemode.PrivateMainActivity$a */
    private class C0925a extends BroadcastReceiver {
        private C0925a() {
        }

        /* synthetic */ C0925a(PrivateMainActivity x0, byte b) {
            this();
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals("android.intent.action.SCREEN_OFF")) {
                PrivateMainActivity.this.finish();
            }
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        this.f5192i = false;
        unregisterReceiver(this.f5190g);
        this.f5189f = null;
        try {
            ErrorWhiteContract.list.clear();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void findViews() {
        this.f5186c = (ListView) findViewById(C0415R.id.signmain_list);
        this.f5185b = (TextView) findViewById(C0415R.id.signmain_empty);
        this.f5186c.setItemsCanFocus(false);
        this.f5186c.setEmptyView(this.f5185b);
        this.f5187d = (ImageView) findViewById(C0415R.id.signmain_icon);
        this.f5187d.setImageResource(C0415R.drawable.privatemain_icon);
        this.f5186c.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.safemode.PrivateMainActivity.3
            /* JADX INFO: Removed unreachable split cross block B:51:0x0011 */
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> arg0, View arg1, int arg2, long arg3) {
                try {
                    if (arg2 == 0) {
                        try {
                            if (PrivateMainActivity.this.f5192i) {
                                PrivateMainActivity.m2146a(PrivateMainActivity.this, "com.lenovo.safecenter.safemode.SofeModeMain");
                            } else {
                                Intent i = new Intent("com.lenovo.safecenter.safemode.SofeModeMain");
                                i.putExtra("pwd", PrivateMainActivity.this.getIntent().getStringExtra("pwd"));
                                i.addFlags(8388608);
                                PrivateMainActivity.this.startActivity(i);
                            }
                        } catch (Exception e) {
                            PrivateMainActivity.m2148c(PrivateMainActivity.this);
                        }
                    } else if (arg2 == 1) {
                        try {
                            if (PrivateMainActivity.this.f5192i) {
                                PrivateMainActivity.m2146a(PrivateMainActivity.this, "com.lenovo.safecenter.LENOVO_SAFEBOX");
                            } else if (PwdUtil.checkPassword(PrivateMainActivity.this.getApplicationContext(), PrivateMainActivity.this.getIntent().getStringExtra("pwd"), false)) {
                                Intent i2 = new Intent("com.lenovo.safecenter.LENOVO_SAFEBOX");
                                i2.putExtra("pwd", PrivateMainActivity.this.getIntent().getStringExtra("pwd"));
                                i2.addFlags(8388608);
                                PrivateMainActivity.this.startActivity(i2);
                            } else {
                                PrivateMainActivity.m2148c(PrivateMainActivity.this);
                            }
                        } catch (Exception e2) {
                            PrivateMainActivity.m2148c(PrivateMainActivity.this);
                        }
                    } else if (arg2 == 2) {
                        try {
                            if (PrivateMainActivity.this.f5192i) {
                                PrivateMainActivity.m2146a(PrivateMainActivity.this, Const.ACTION_JUMP_APP_LOCK);
                            } else if (PwdUtil.checkPassword(PrivateMainActivity.this.getApplicationContext(), PrivateMainActivity.this.getIntent().getStringExtra("pwd"), false)) {
                                Intent i3 = new Intent(Const.ACTION_JUMP_APP_LOCK);
                                i3.putExtra("pwd", PrivateMainActivity.this.getIntent().getStringExtra("pwd"));
                                i3.addFlags(8388608);
                                PrivateMainActivity.this.startActivity(i3);
                            } else {
                                PrivateMainActivity.m2148c(PrivateMainActivity.this);
                            }
                        } catch (Exception e3) {
                            PrivateMainActivity.m2148c(PrivateMainActivity.this);
                        }
                    }
                } catch (ActivityNotFoundException e4) {
                    PrivateMainActivity.m2148c(PrivateMainActivity.this);
                    e4.printStackTrace();
                }
            }
        });
    }

    public class PrivateItemApater extends BaseAdapter {
        public PrivateItemApater() {
        }

        @Override // android.widget.Adapter
        public int getCount() {
            try {
                if (!TrafficStatsService.nacServerIsExist()) {
                    PackageInfo info = PrivateMainActivity.this.getPackageManager().getPackageInfo(Const.PACKAGENAME_APP_LOCK, 8192);
                    if (info.versionName.startsWith("1.0")) {
                    }
                }
            } catch (Exception e) {
            }
            return 3;
        }

        @Override // android.widget.Adapter
        public Object getItem(int position) {
            return null;
        }

        @Override // android.widget.Adapter
        public long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            C0924a holder;
            if (convertView == null) {
                convertView = LayoutInflater.from(PrivateMainActivity.this).inflate(C0415R.layout.privatezone_itempage, (ViewGroup) null);
                holder = new C0924a(this, (byte) 0);
                holder.f5204a = (TextView) convertView.findViewById(C0415R.id.private_btitle);
                holder.f5205b = (TextView) convertView.findViewById(C0415R.id.private_stitle);
                holder.f5206c = (ImageView) convertView.findViewById(C0415R.id.private_cion);
                convertView.setTag(holder);
            } else {
                holder = (C0924a) convertView.getTag();
            }
            if (position == 0) {
                holder.f5204a.setText(C0415R.string.private_onebig);
                holder.f5205b.setText(C0415R.string.private_onesmall);
                holder.f5206c.setImageResource(C0415R.drawable.private1);
            } else if (position == 1) {
                holder.f5204a.setText(C0415R.string.private_twobig);
                holder.f5205b.setText(C0415R.string.private_twosmall);
                holder.f5206c.setImageResource(C0415R.drawable.private2);
            } else if (position == 2) {
                holder.f5204a.setText(C0415R.string.private_threebig);
                holder.f5205b.setText(C0415R.string.private_threesmall);
                holder.f5206c.setImageResource(C0415R.drawable.private3);
            }
            return convertView;
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.safemode.PrivateMainActivity$PrivateItemApater$a */
        private class C0924a {

            /* JADX INFO: renamed from: a */
            TextView f5204a;

            /* JADX INFO: renamed from: b */
            TextView f5205b;

            /* JADX INFO: renamed from: c */
            ImageView f5206c;

            private C0924a() {
            }

            /* synthetic */ C0924a(PrivateItemApater x0, byte b) {
                this();
            }
        }
    }
}
