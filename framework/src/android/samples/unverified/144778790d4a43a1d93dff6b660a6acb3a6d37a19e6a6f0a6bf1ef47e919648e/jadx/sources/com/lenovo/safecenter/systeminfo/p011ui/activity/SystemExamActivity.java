package com.lenovo.safecenter.systeminfo.p011ui.activity;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.GestureDetector;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.systeminfo.adapter.PhoneInfoListAdapter;
import com.lenovo.safecenter.systeminfo.entity.PhoneInfoItem;
import com.lenovo.safecenter.systeminfo.service.CpuInfoService;
import com.lenovo.safecenter.systeminfo.service.MemoryInfoService;
import com.lenovo.safecenter.systeminfo.service.NetworkInfoService;
import com.lenovo.safecenter.systeminfo.service.PhoneInfoService;
import com.lenovo.safecenter.systeminfo.service.ScreenInfoService;
import com.lenovo.safecenter.systeminfo.service.SensorInfoService;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class SystemExamActivity extends BaseTitleActivity {

    /* JADX INFO: renamed from: a */
    private LinearLayout f5668a;

    /* JADX INFO: renamed from: b */
    private LinearLayout f5669b;

    /* JADX INFO: renamed from: c */
    private LinearLayout f5670c;

    /* JADX INFO: renamed from: d */
    private LinearLayout f5671d;

    /* JADX INFO: renamed from: e */
    private TextView f5672e;

    /* JADX INFO: renamed from: f */
    private TextView f5673f;

    /* JADX INFO: renamed from: g */
    private ImageView f5674g;

    /* JADX INFO: renamed from: h */
    private ImageView f5675h;

    /* JADX INFO: renamed from: i */
    private TextView f5676i;

    /* JADX INFO: renamed from: j */
    private ListView f5677j;

    /* JADX INFO: renamed from: k */
    private Button f5678k;

    /* JADX INFO: renamed from: l */
    private List<PhoneInfoItem> f5679l;

    /* JADX INFO: renamed from: m */
    private PhoneInfoListAdapter f5680m;

    /* JADX INFO: renamed from: n */
    private int f5681n;

    /* JADX INFO: renamed from: o */
    private double f5682o;

    /* JADX INFO: renamed from: p */
    private double f5683p;

    /* JADX INFO: renamed from: q */
    private String f5684q;

    /* JADX INFO: renamed from: r */
    private boolean f5685r = false;

    /* JADX INFO: renamed from: s */
    private Handler f5686s = new Handler() { // from class: com.lenovo.safecenter.systeminfo.ui.activity.SystemExamActivity.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            if (!SystemExamActivity.this.f5685r) {
                SystemExamActivity.this.f5679l.add(3, (PhoneInfoItem) msg.obj);
                SystemExamActivity.this.f5680m.notifyDataSetChanged();
                SystemExamActivity.m2329d(SystemExamActivity.this);
            }
        }
    };

    /* JADX INFO: renamed from: t */
    private BroadcastReceiver f5687t = new BroadcastReceiver() { // from class: com.lenovo.safecenter.systeminfo.ui.activity.SystemExamActivity.2
        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            String action = intent.getAction();
            if ("android.intent.action.BATTERY_CHANGED".equals(action)) {
                ArrayList<String> batteryInfoList = new ArrayList<>();
                SystemExamActivity.this.f5681n = intent.getIntExtra("level", 0);
                batteryInfoList.add(SystemExamActivity.this.getString(C0415R.string.sysinfo_battery_power, new Object[]{Integer.valueOf(SystemExamActivity.this.f5681n)}));
                int bVoltage = intent.getIntExtra("voltage", 0);
                if (bVoltage < 10) {
                    bVoltage *= 1000;
                }
                SystemExamActivity.this.f5682o = bVoltage / 1000.0f;
                batteryInfoList.add(SystemExamActivity.this.getString(C0415R.string.sysinfo_battery_voltage, new Object[]{Double.valueOf(SystemExamActivity.this.f5682o)}));
                int bTemperature = intent.getIntExtra("temperature", 0);
                SystemExamActivity.this.f5683p = bTemperature / 10.0f;
                batteryInfoList.add(SystemExamActivity.this.getString(C0415R.string.sysinfo_battery_temperature, new Object[]{new DecimalFormat("####.0").format(SystemExamActivity.this.f5683p)}));
                SystemExamActivity.this.f5684q = intent.getStringExtra("technology");
                batteryInfoList.add(SystemExamActivity.this.getString(C0415R.string.sysinfo_battery_type, new Object[]{SystemExamActivity.this.f5684q}));
                PhoneInfoItem item = new PhoneInfoItem();
                item.setIconRes(C0415R.drawable.phoneinfo_battary);
                item.setInfo(SystemExamActivity.this.getString(C0415R.string.sysinfo_battery_power, new Object[]{Integer.valueOf(SystemExamActivity.this.f5681n)}) + "%\n" + SystemExamActivity.this.getString(C0415R.string.sysinfo_battery_voltage, new Object[]{Double.valueOf(SystemExamActivity.this.f5682o)}) + "\n" + (SystemExamActivity.this.f5683p >= 8.0d ? SystemExamActivity.this.getString(C0415R.string.sysinfo_battery_temperature, new Object[]{Double.valueOf(SystemExamActivity.this.f5683p)}) : SystemExamActivity.this.getString(C0415R.string.sysinfo_battery_temperature1, new Object[]{SystemExamActivity.this.getString(C0415R.string.localblack_noName)})) + "\n" + SystemExamActivity.this.getString(C0415R.string.sysinfo_battery_type, new Object[]{SystemExamActivity.this.f5684q}));
                Message msg = new Message();
                msg.obj = item;
                SystemExamActivity.this.f5686s.sendMessage(msg);
            }
        }
    };

    /* JADX INFO: renamed from: u */
    private GestureDetector f5688u;

    /* JADX INFO: renamed from: v */
    private View.OnTouchListener f5689v;

    /* JADX INFO: renamed from: d */
    static /* synthetic */ boolean m2329d(SystemExamActivity x0) {
        x0.f5685r = true;
        return true;
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.phoneinfo_main);
        registerReceiver(this.f5687t, new IntentFilter("android.intent.action.BATTERY_CHANGED"));
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.opti_main_sys_exam, (Integer) null);
        this.f5668a = (LinearLayout) findViewById(C0415R.id.phone_tab_btn_info);
        this.f5669b = (LinearLayout) findViewById(C0415R.id.phone_tab_btn_test);
        this.f5672e = (TextView) findViewById(C0415R.id.phone_tab_btn_info_text);
        this.f5673f = (TextView) findViewById(C0415R.id.phone_tab_btn_test_text);
        this.f5674g = (ImageView) findViewById(C0415R.id.phone_tab_btn_info_image);
        this.f5675h = (ImageView) findViewById(C0415R.id.phone_tab_btn_test_image);
        this.f5670c = (LinearLayout) findViewById(C0415R.id.layout_phoneinfo_infoshow);
        this.f5671d = (LinearLayout) findViewById(C0415R.id.layout_phoneinfo_phonetest);
        this.f5671d.setVisibility(8);
        this.f5676i = (TextView) findViewById(C0415R.id.tv_phoninfo_summary1);
        this.f5677j = (ListView) findViewById(C0415R.id.list_phoneinfo_detail);
        this.f5678k = (Button) findViewById(C0415R.id.phoneinfo_btn_screen);
        this.f5668a.setBackgroundResource(C0415R.drawable.tab_select);
        this.f5669b.setBackgroundResource(C0415R.drawable.tab_normal);
        this.f5672e.setTextColor(getResources().getColor(C0415R.color.blue));
        this.f5673f.setTextColor(getResources().getColor(C0415R.color.black4));
        this.f5674g.setBackgroundResource(C0415R.drawable.phoneinfo_rb_info_up_blue);
        this.f5675h.setBackgroundResource(C0415R.drawable.phoneinfo_rb_test_up);
        ViewOnClickListenerC1017b viewOnClickListenerC1017b = new ViewOnClickListenerC1017b(this, (byte) 0);
        this.f5668a.setOnClickListener(viewOnClickListenerC1017b);
        this.f5669b.setOnClickListener(viewOnClickListenerC1017b);
        this.f5678k.setOnClickListener(viewOnClickListenerC1017b);
        this.f5676i.setText(PhoneInfoService.getInstance().getPhoneInfo());
        this.f5679l = new ArrayList();
        PhoneInfoItem phoneInfoItem = new PhoneInfoItem();
        phoneInfoItem.setIconRes(C0415R.drawable.phoneinfo_cpu);
        phoneInfoItem.setInfo(CpuInfoService.getInstance().getCpuInfo(this));
        this.f5679l.add(phoneInfoItem);
        PhoneInfoItem phoneInfoItem2 = new PhoneInfoItem();
        phoneInfoItem2.setIconRes(C0415R.drawable.phoneinfo_memory);
        phoneInfoItem2.setInfo(MemoryInfoService.getInstance().getMemeryInfo() + '\n' + MemoryInfoService.getInstance().getRomAndSDcardSizeInfo(this));
        this.f5679l.add(phoneInfoItem2);
        PhoneInfoItem phoneInfoItem3 = new PhoneInfoItem();
        phoneInfoItem3.setIconRes(C0415R.drawable.phoneinfo_screen);
        phoneInfoItem3.setInfo(ScreenInfoService.getInstance().getDisplayMetrics());
        this.f5679l.add(phoneInfoItem3);
        PhoneInfoItem phoneInfoItem4 = new PhoneInfoItem();
        phoneInfoItem4.setIconRes(C0415R.drawable.phoneinfo_wireless);
        phoneInfoItem4.setInfo(NetworkInfoService.getInstance().getWifiInfo());
        this.f5679l.add(phoneInfoItem4);
        PhoneInfoItem phoneInfoItem5 = new PhoneInfoItem();
        phoneInfoItem5.setIconRes(C0415R.drawable.phoneinfo_other);
        phoneInfoItem5.setInfo(NetworkInfoService.getInstance().getNetworkInfo() + '\n' + SensorInfoService.getInstance().sensorInfo());
        this.f5679l.add(phoneInfoItem5);
        this.f5680m = new PhoneInfoListAdapter(this.f5679l);
        this.f5677j.setAdapter((ListAdapter) this.f5680m);
        this.f5688u = new GestureDetector(new C1016a());
        this.f5689v = new View.OnTouchListener() { // from class: com.lenovo.safecenter.systeminfo.ui.activity.SystemExamActivity.3
            @Override // android.view.View.OnTouchListener
            public final boolean onTouch(View v, MotionEvent event) {
                return SystemExamActivity.this.f5688u.onTouchEvent(event);
            }
        };
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        super.onClick(v);
        switch (v.getId()) {
            case C0415R.id.base_title_left /* 2131297465 */:
                finish();
                break;
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.systeminfo.ui.activity.SystemExamActivity$b */
    private final class ViewOnClickListenerC1017b implements View.OnClickListener {
        private ViewOnClickListenerC1017b() {
        }

        /* synthetic */ ViewOnClickListenerC1017b(SystemExamActivity x0, byte b) {
            this();
        }

        @Override // android.view.View.OnClickListener
        public final void onClick(View v) {
            int id = v.getId();
            switch (id) {
                case C0415R.id.phone_tab_btn_info /* 2131297413 */:
                    SystemExamActivity.this.f5672e.setTextColor(SystemExamActivity.this.getResources().getColor(C0415R.color.blue));
                    SystemExamActivity.this.f5673f.setTextColor(SystemExamActivity.this.getResources().getColor(C0415R.color.black4));
                    SystemExamActivity.this.f5668a.setBackgroundResource(C0415R.drawable.tab_select);
                    SystemExamActivity.this.f5669b.setBackgroundResource(C0415R.drawable.tab_normal);
                    SystemExamActivity.this.f5674g.setBackgroundResource(C0415R.drawable.phoneinfo_rb_info_up_blue);
                    SystemExamActivity.this.f5675h.setBackgroundResource(C0415R.drawable.phoneinfo_rb_test_up);
                    SystemExamActivity.this.f5670c.setVisibility(0);
                    SystemExamActivity.this.f5671d.setVisibility(8);
                    break;
                case C0415R.id.phone_tab_btn_test /* 2131297416 */:
                    SystemExamActivity.this.f5672e.setTextColor(SystemExamActivity.this.getResources().getColor(C0415R.color.black4));
                    SystemExamActivity.this.f5673f.setTextColor(SystemExamActivity.this.getResources().getColor(C0415R.color.blue));
                    SystemExamActivity.this.f5669b.setBackgroundResource(C0415R.drawable.tab_select);
                    SystemExamActivity.this.f5668a.setBackgroundResource(C0415R.drawable.tab_normal);
                    SystemExamActivity.this.f5674g.setBackgroundResource(C0415R.drawable.phoneinfo_rb_info_up);
                    SystemExamActivity.this.f5675h.setBackgroundResource(C0415R.drawable.phoneinfo_rb_test_up_blue);
                    SystemExamActivity.this.f5670c.setVisibility(8);
                    SystemExamActivity.this.f5671d.setVisibility(0);
                    break;
                case C0415R.id.phoneinfo_btn_screen /* 2131297423 */:
                    new CustomDialog.Builder(SystemExamActivity.this).setTitle(C0415R.string.notify).setMessage(C0415R.string.phoneinfo_check_screen).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.systeminfo.ui.activity.SystemExamActivity.b.2
                        @Override // android.content.DialogInterface.OnClickListener
                        public final void onClick(DialogInterface dialog, int which) {
                            Intent intent = new Intent(SystemExamActivity.this, (Class<?>) ScreenTestActivity.class);
                            SystemExamActivity.this.startActivity(intent);
                        }
                    }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.systeminfo.ui.activity.SystemExamActivity.b.1
                        @Override // android.content.DialogInterface.OnClickListener
                        public final void onClick(DialogInterface dialog, int which) {
                            dialog.cancel();
                        }
                    }).show();
                    break;
            }
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        unregisterReceiver(this.f5687t);
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.systeminfo.ui.activity.SystemExamActivity$a */
    class C1016a extends GestureDetector.SimpleOnGestureListener {
        C1016a() {
        }

        @Override // android.view.GestureDetector.SimpleOnGestureListener, android.view.GestureDetector.OnGestureListener
        public final boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX, float velocityY) {
            try {
                if (Math.abs(e1.getY() - e2.getY()) <= 250.0f) {
                    if (e1.getX() - e2.getX() <= 120.0f || Math.abs(velocityX) <= 200.0f || SystemExamActivity.this.f5671d.getVisibility() != 8) {
                        if (e2.getX() - e1.getX() > 120.0f && Math.abs(velocityX) > 200.0f && SystemExamActivity.this.f5671d.getVisibility() != 8) {
                            Log.i("test ", "left");
                            SystemExamActivity.this.f5672e.setTextColor(SystemExamActivity.this.getResources().getColor(C0415R.color.blue));
                            SystemExamActivity.this.f5673f.setTextColor(SystemExamActivity.this.getResources().getColor(C0415R.color.black4));
                            SystemExamActivity.this.f5668a.setBackgroundResource(C0415R.drawable.tab_select);
                            SystemExamActivity.this.f5669b.setBackgroundResource(C0415R.drawable.tab_normal);
                            SystemExamActivity.this.f5674g.setBackgroundResource(C0415R.drawable.phoneinfo_rb_info_up_blue);
                            SystemExamActivity.this.f5675h.setBackgroundResource(C0415R.drawable.phoneinfo_rb_test_up);
                            SystemExamActivity.this.f5670c.setVisibility(0);
                            SystemExamActivity.this.f5671d.setVisibility(8);
                        }
                    } else {
                        Log.i("test ", "right");
                        SystemExamActivity.this.f5672e.setTextColor(SystemExamActivity.this.getResources().getColor(C0415R.color.black4));
                        SystemExamActivity.this.f5673f.setTextColor(SystemExamActivity.this.getResources().getColor(C0415R.color.blue));
                        SystemExamActivity.this.f5669b.setBackgroundResource(C0415R.drawable.tab_select);
                        SystemExamActivity.this.f5668a.setBackgroundResource(C0415R.drawable.tab_normal);
                        SystemExamActivity.this.f5674g.setBackgroundResource(C0415R.drawable.phoneinfo_rb_info_up);
                        SystemExamActivity.this.f5675h.setBackgroundResource(C0415R.drawable.phoneinfo_rb_test_up_blue);
                        SystemExamActivity.this.f5670c.setVisibility(8);
                        SystemExamActivity.this.f5671d.setVisibility(0);
                    }
                }
            } catch (Exception e) {
            }
            return false;
        }
    }

    @Override // android.app.Activity, android.view.Window.Callback
    public boolean dispatchTouchEvent(MotionEvent event) {
        if (this.f5688u.onTouchEvent(event)) {
            event.setAction(3);
        }
        return super.dispatchTouchEvent(event);
    }
}
