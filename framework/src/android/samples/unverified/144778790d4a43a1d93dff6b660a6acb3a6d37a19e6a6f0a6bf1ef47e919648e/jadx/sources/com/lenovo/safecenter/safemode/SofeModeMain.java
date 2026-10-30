package com.lenovo.safecenter.safemode;

import android.app.TabActivity;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.GestureDetector;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TabHost;
import android.widget.TextView;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.net.correct.TrafficCorrectSetting;
import com.lenovo.safecenter.support.HttpUtils;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.DataHelpUtils;
import com.lenovo.safecenter.utils.PwdUtil;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class SofeModeMain extends TabActivity implements View.OnClickListener {
    public static final String TS_CALL = "call";
    public static final String TS_CONTRACT = "contract";
    public static final String TS_SETTINGT = "setting";
    public static final String TS_SMS = "sms";

    /* JADX INFO: renamed from: a */
    private TabHost f5209a;

    /* JADX INFO: renamed from: b */
    private C0930b f5210b;

    /* JADX INFO: renamed from: d */
    private GestureDetector f5212d;

    /* JADX INFO: renamed from: e */
    private View.OnTouchListener f5213e;
    public Handler hand = new Handler() { // from class: com.lenovo.safecenter.safemode.SofeModeMain.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            int i = msg.what;
        }
    };

    /* JADX INFO: renamed from: c */
    private long f5211c = 0;

    /* JADX INFO: renamed from: com.lenovo.safecenter.safemode.SofeModeMain$b */
    private class C0930b extends BroadcastReceiver {
        private C0930b() {
        }

        /* synthetic */ C0930b(SofeModeMain x0, byte b) {
            this();
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals("android.intent.action.SCREEN_OFF")) {
                SofeModeMain.this.finish();
            }
        }
    }

    public void setTitle(Integer leftImgId, int titleStrId, Integer rightImgId) {
        getWindow().setFeatureInt(7, C0415R.layout.rf_perf_basetitle);
        ((TextView) findViewById(C0415R.id.base_title_center)).setText(titleStrId);
        findViewById(C0415R.id.base_title_center).setOnClickListener(this);
        if (leftImgId != null) {
            findViewById(C0415R.id.base_title_left).setOnClickListener(this);
        } else {
            setLeftImgGone(8);
        }
        if (rightImgId != null) {
            findViewById(C0415R.id.base_title_right).setOnClickListener(this);
        } else {
            setRightImgGone(8);
        }
    }

    public void setLeftImgGone(int gone) {
        findViewById(C0415R.id.base_title_left).setVisibility(gone);
    }

    public void setRightImgGone(int gone) {
        findViewById(C0415R.id.base_title_right).setVisibility(gone);
    }

    @Override // android.app.ActivityGroup, android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(7);
        Const.addEntryPrivacySpaceCount();
        setContentView(C0415R.layout.common_tab);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.changedes_title, null);
        DataHelpUtils.allActivity.add(this);
        this.f5210b = new C0930b(this, (byte) 0);
        IntentFilter filter = new IntentFilter("android.intent.action.SCREEN_OFF");
        registerReceiver(this.f5210b, filter);
        this.f5209a = getTabHost();
        if (getIntent().getStringExtra("pwd") != null) {
            if (DataHelpUtils.execService("pwd", this).equals(getIntent().getStringExtra("pwd")) && !PwdUtil.checkPassword(getApplicationContext(), getIntent().getStringExtra("pwd"), false)) {
                View view = getView(getString(C0415R.string.safemode_sms), 0, C0415R.drawable.filter_sms_click_img);
                TabHost.TabSpec filterMsgSpec = this.f5209a.newTabSpec("0");
                filterMsgSpec.setIndicator(view);
                Intent filterMsgIntent = new Intent(this, (Class<?>) ErrorWhiteSms.class);
                filterMsgSpec.setContent(filterMsgIntent);
                View view2 = getView(getString(C0415R.string.safemode_call), 1, C0415R.drawable.filter_call_click_img);
                TabHost.TabSpec filterCallSpec = this.f5209a.newTabSpec(DatabaseTables.SYSTEM_MARK);
                filterCallSpec.setIndicator(view2);
                Intent filterCallIntent = new Intent(this, (Class<?>) ErrorWhiteSms.class);
                filterCallSpec.setContent(filterCallIntent);
                View view3 = getView(getString(C0415R.string.contract), 2, C0415R.drawable.filter_contract_click_img);
                TabHost.TabSpec filterListSpec = this.f5209a.newTabSpec(DatabaseTables.USER_MARK);
                filterListSpec.setIndicator(view3);
                Intent filterListIntent = new Intent(this, (Class<?>) ErrorWhiteContract.class);
                filterListSpec.setContent(filterListIntent);
                this.f5209a.addTab(filterMsgSpec);
                this.f5209a.addTab(filterCallSpec);
                this.f5209a.addTab(filterListSpec);
            } else if (PwdUtil.checkPassword(getApplicationContext(), getIntent().getStringExtra("pwd"), false)) {
                View view4 = getView(getString(C0415R.string.safemode_sms), 0, C0415R.drawable.filter_sms_click_img);
                TabHost.TabSpec filterMsgSpec2 = this.f5209a.newTabSpec("0");
                filterMsgSpec2.setIndicator(view4);
                Intent filterMsgIntent2 = new Intent(this, (Class<?>) WhiteSms.class);
                filterMsgSpec2.setContent(filterMsgIntent2);
                View view5 = getView(getString(C0415R.string.safemode_call), 1, C0415R.drawable.filter_call_click_img);
                TabHost.TabSpec filterCallSpec2 = this.f5209a.newTabSpec(DatabaseTables.SYSTEM_MARK);
                filterCallSpec2.setIndicator(view5);
                Intent filterCallIntent2 = new Intent(this, (Class<?>) WhiteCall.class);
                filterCallSpec2.setContent(filterCallIntent2);
                View view6 = getView(getString(C0415R.string.contract), 2, C0415R.drawable.filter_contract_click_img);
                TabHost.TabSpec filterListSpec2 = this.f5209a.newTabSpec(DatabaseTables.USER_MARK);
                filterListSpec2.setIndicator(view6);
                Intent filterListIntent2 = new Intent(this, (Class<?>) WhiteContract.class);
                filterListSpec2.setContent(filterListIntent2);
                this.f5209a.addTab(filterMsgSpec2);
                this.f5209a.addTab(filterCallSpec2);
                this.f5209a.addTab(filterListSpec2);
            }
            this.f5209a.setOnTabChangedListener(new TabHost.OnTabChangeListener() { // from class: com.lenovo.safecenter.safemode.SofeModeMain.2
                @Override // android.widget.TabHost.OnTabChangeListener
                public final void onTabChanged(String tabId) {
                    int tabID = Integer.valueOf(tabId).intValue();
                    for (int i = 0; i < 3; i++) {
                        if (i == tabID) {
                            SofeModeMain.this.f5209a.getChildAt(Integer.valueOf(i).intValue());
                            TextView textView = (TextView) SofeModeMain.this.f5209a.getTabWidget().getChildAt(Integer.valueOf(i).intValue()).findViewById(C0415R.id.tab_name);
                            textView.setTextColor(SofeModeMain.this.getResources().getColor(C0415R.color.blue));
                        } else {
                            SofeModeMain.this.f5209a.getChildAt(Integer.valueOf(i).intValue());
                            TextView textView2 = (TextView) SofeModeMain.this.f5209a.getTabWidget().getChildAt(Integer.valueOf(i).intValue()).findViewById(C0415R.id.tab_name);
                            textView2.setTextColor(SofeModeMain.this.getResources().getColor(C0415R.color.black4));
                        }
                    }
                }
            });
            Integer num = 0;
            TextView textView = (TextView) this.f5209a.getTabWidget().getChildAt(num.intValue()).findViewById(C0415R.id.tab_name);
            textView.setTextColor(getResources().getColor(C0415R.color.black4));
            String type = getIntent().getStringExtra("Type");
            if (type != null) {
                if (type.equals(TS_CALL)) {
                    this.f5209a.setCurrentTab(1);
                } else if (type.equals(TS_SMS)) {
                    this.f5209a.setCurrentTab(0);
                }
            } else {
                this.f5209a.setCurrentTab(0);
            }
            this.f5212d = new GestureDetector(new C0929a());
            this.f5213e = new View.OnTouchListener() { // from class: com.lenovo.safecenter.safemode.SofeModeMain.3
                @Override // android.view.View.OnTouchListener
                public final boolean onTouch(View v, MotionEvent event) {
                    return SofeModeMain.this.f5212d.onTouchEvent(event);
                }
            };
        }
    }

    @Override // android.app.ActivityGroup, android.app.Activity
    protected void onResume() {
        super.onResume();
        if (this.f5211c != 0 && System.currentTimeMillis() - this.f5211c > TrafficCorrectSetting.TIME && !HttpUtils.private_isOpenSec) {
            finish();
        }
        TrackEvent.trackResume(this);
    }

    @Override // android.app.ActivityGroup, android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.app.ActivityGroup, android.app.Activity
    protected void onStop() {
        super.onStop();
        this.f5211c = System.currentTimeMillis();
    }

    @Override // android.app.ActivityGroup, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        if (DataHelpUtils.getActivityByName("SofeModeMain") != null) {
            DataHelpUtils.allActivity.clear();
        }
        unregisterReceiver(this.f5210b);
        this.f5211c = 0L;
    }

    public View getView(String str, int pos, int drawID) {
        View view1 = LayoutInflater.from(this).inflate(C0415R.layout.tadview, (ViewGroup) null);
        TextView txtnumber = (TextView) view1.findViewById(C0415R.id.tab_name);
        ImageView tab_img = (ImageView) view1.findViewById(C0415R.id.tab_img);
        View img = view1.findViewById(C0415R.id.div1);
        Log.i("ss", "img==" + img);
        if (pos == 2) {
            img.setVisibility(8);
        } else {
            img.setVisibility(0);
        }
        txtnumber.setText(str);
        tab_img.setBackgroundResource(drawID);
        return view1;
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        } else if (v.getId() == C0415R.id.base_title_right) {
            HttpUtils.private_isOpenSec = true;
            startActivity(new Intent(this, (Class<?>) ContractSetting.class));
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.safemode.SofeModeMain$a */
    class C0929a extends GestureDetector.SimpleOnGestureListener {
        C0929a() {
        }

        @Override // android.view.GestureDetector.SimpleOnGestureListener, android.view.GestureDetector.OnGestureListener
        public final boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX, float velocityY) {
            try {
                if (Math.abs(e1.getY() - e2.getY()) <= 250.0f) {
                    if (e1.getX() - e2.getX() <= 120.0f || Math.abs(velocityX) <= 200.0f || SofeModeMain.this.f5209a.getCurrentTab() == 2) {
                        if (e2.getX() - e1.getX() > 120.0f && Math.abs(velocityX) > 200.0f && SofeModeMain.this.f5209a.getCurrentTab() != 0) {
                            Log.i("test ", "left");
                            SofeModeMain.this.f5209a.setCurrentTab(SofeModeMain.this.f5209a.getCurrentTab() - 1);
                        }
                    } else {
                        Log.i("test ", "right");
                        SofeModeMain.this.f5209a.setCurrentTab(SofeModeMain.this.f5209a.getCurrentTab() + 1);
                    }
                }
            } catch (Exception e) {
            }
            return false;
        }
    }

    @Override // android.app.Activity, android.view.Window.Callback
    public boolean dispatchTouchEvent(MotionEvent event) {
        if (this.f5212d.onTouchEvent(event)) {
            event.setAction(3);
        }
        return super.dispatchTouchEvent(event);
    }
}
