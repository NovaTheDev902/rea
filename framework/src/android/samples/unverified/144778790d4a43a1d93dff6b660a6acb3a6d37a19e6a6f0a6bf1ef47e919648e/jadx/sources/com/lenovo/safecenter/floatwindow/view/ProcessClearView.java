package com.lenovo.safecenter.floatwindow.view;

import android.content.Context;
import android.content.SharedPreferences;
import android.content.res.Resources;
import android.os.Handler;
import android.os.Message;
import android.util.AttributeSet;
import android.view.View;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import com.lenovo.performancecenter.coreui.util.RootPassage;
import com.lenovo.performancecenter.performance.ScanApplicationInfo;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.floatwindow.util.MyRotateAnimations;
import com.lenovo.safecenter.floatwindow.util.Tools;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/* JADX INFO: loaded from: classes.dex */
public class ProcessClearView extends LinearLayout implements View.OnClickListener {
    public static final String PREF_SWITCHER_OR_RUNNING_FLAG = "switcher_or_running_flag";
    public static final String PREF_SWITCHER_SHOW_FLAG = "switcher_windwo_show";
    public static ProcessClearView instanceClearView;

    /* JADX INFO: renamed from: a */
    private Button f3664a;

    /* JADX INFO: renamed from: b */
    private TextView f3665b;

    /* JADX INFO: renamed from: c */
    private TextView f3666c;

    /* JADX INFO: renamed from: d */
    private TextView f3667d;

    /* JADX INFO: renamed from: e */
    private ClearProcessBar f3668e;

    /* JADX INFO: renamed from: f */
    private FrameLayout f3669f;

    /* JADX INFO: renamed from: g */
    private ImageView f3670g;

    /* JADX INFO: renamed from: h */
    private Context f3671h;
    public Handler handler;

    /* JADX INFO: renamed from: i */
    private int f3672i;

    /* JADX INFO: renamed from: j */
    private int f3673j;

    /* JADX INFO: renamed from: k */
    private Resources f3674k;

    /* JADX INFO: renamed from: l */
    private Message f3675l;

    /* JADX INFO: renamed from: m */
    private SharedPreferences f3676m;

    /* JADX INFO: renamed from: n */
    private boolean f3677n;

    /* JADX INFO: renamed from: o */
    private String f3678o;

    /* JADX INFO: renamed from: p */
    private Tools f3679p;

    /* JADX INFO: renamed from: q */
    private int f3680q;

    /* JADX INFO: renamed from: d */
    static /* synthetic */ void m1545d(ProcessClearView x0) {
        HashMap<String, int[]> runningAppInfoJustInLauncher = ScanApplicationInfo.getRunningAppInfoJustInLauncher(x0.f3671h);
        ArrayList arrayList = new ArrayList();
        for (Map.Entry<String, int[]> entry : runningAppInfoJustInLauncher.entrySet()) {
            if (entry.getValue()[2] == 1) {
                x0.f3680q = entry.getValue()[1] + x0.f3680q;
            }
            arrayList.add(entry.getKey());
        }
        x0.f3680q /= 1048576;
        RootPassage.execRootCmd(null, arrayList, " -fs ", x0.f3671h);
        x0.handler.sendEmptyMessage(201);
    }

    public ProcessClearView(Context context, AttributeSet attrs) {
        super(context, attrs);
        this.f3672i = -1;
        this.f3673j = -1;
        this.f3677n = true;
        this.handler = new Handler() { // from class: com.lenovo.safecenter.floatwindow.view.ProcessClearView.2
            @Override // android.os.Handler
            public final void handleMessage(Message msg) {
                super.handleMessage(msg);
                switch (msg.what) {
                    case 200:
                        TrackEvent.reportUserActionClickOneKeyClearInShortcutSwitch();
                        ProcessClearView.m1545d(ProcessClearView.this);
                        break;
                    case 201:
                        int mem_clear_before_size = ProcessClearView.this.f3679p.stringtoInt(ProcessClearView.this.f3666c.getText().toString().replace(ProcessClearView.this.f3674k.getString(C0415R.string.process_usage_size_).toString(), ""));
                        int clear_after_size = mem_clear_before_size - ProcessClearView.this.f3680q;
                        int uate = ProcessClearView.this.f3679p.getUeageRate1(ProcessClearView.this.f3678o, String.valueOf(clear_after_size));
                        ProcessClearView.this.f3665b.setText(ProcessClearView.this.f3674k.getString(C0415R.string.process_clear_info_).toString() + ProcessClearView.this.f3680q + ProcessClearView.this.f3674k.getString(C0415R.string.process_usage_size_m).toString());
                        ProcessClearView.this.f3668e.showClearAnimation(ProcessClearView.this.f3672i, uate, clear_after_size);
                        break;
                }
            }
        };
        this.f3671h = context;
        if (this.f3679p == null) {
            this.f3679p = new Tools(context);
        }
        this.f3674k = getResources();
        this.f3675l = new Message();
        inflate(context, C0415R.layout.assist_process_clear, this);
        this.f3664a = (Button) findViewById(C0415R.id.clear_all);
        this.f3665b = (TextView) findViewById(C0415R.id.process_clear_info);
        this.f3666c = (TextView) findViewById(C0415R.id.process_usage_size);
        this.f3667d = (TextView) findViewById(C0415R.id.process_usage_rate);
        this.f3678o = this.f3679p.getTotalMemory();
        this.f3673j = this.f3679p.getUeageSize(this.f3678o, this.f3679p.getAvailMemory());
        this.f3672i = this.f3679p.getUeageRate(this.f3678o, this.f3679p.getAvailMemory());
        this.f3666c.setText(this.f3674k.getString(C0415R.string.process_usage_size_).toString() + this.f3673j + this.f3674k.getString(C0415R.string.process_usage_size_m).toString());
        this.f3667d.setText(this.f3674k.getString(C0415R.string.process_usage_rate_).toString() + this.f3672i + this.f3674k.getString(C0415R.string.process_usage_rate_bai).toString());
        this.f3664a.setOnClickListener(this);
        this.f3668e = (ClearProcessBar) findViewById(C0415R.id.cpb_memory_usage);
        this.f3668e.showStartAnimation(this.f3672i);
        this.f3669f = (FrameLayout) findViewById(C0415R.id.switch_screem);
        this.f3670g = (ImageView) findViewById(C0415R.id.img_fw_more_rotation_view);
        this.f3676m = context.getSharedPreferences("switcher_or_running_flag", 0);
        this.f3677n = this.f3676m.getBoolean("switcher_windwo_show", true);
        if (this.f3677n) {
            this.f3670g.startAnimation(MyRotateAnimations.getRotateAnimation(-180.0f, 0.0f, 500));
        } else {
            this.f3670g.startAnimation(MyRotateAnimations.getRotateAnimation(0.0f, -180.0f, 500));
        }
        this.f3669f.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.floatwindow.view.ProcessClearView.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (ProcessClearView.this.f3677n) {
                    ProcessClearView.this.f3670g.startAnimation(MyRotateAnimations.getRotateAnimation(0.0f, -180.0f, 500));
                } else {
                    ProcessClearView.this.f3670g.startAnimation(MyRotateAnimations.getRotateAnimation(-180.0f, 0.0f, 500));
                }
                ProcessClearView.this.f3677n = !ProcessClearView.this.f3677n;
                ViewPagerSwitcher.instance.showSwitcherorRunningWindow(ProcessClearView.this.f3677n, true);
                ProcessClearView.this.f3676m.edit().putBoolean("switcher_windwo_show", ProcessClearView.this.f3677n).commit();
            }
        });
        instanceClearView = this;
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.clear_all /* 2131296824 */:
                this.handler.sendEmptyMessage(200);
                break;
        }
    }

    public void showClearOverView(int clear_after_size, int uate) {
        this.f3664a.setVisibility(8);
        this.f3665b.setVisibility(0);
        this.f3666c.setText(this.f3674k.getString(C0415R.string.process_usage_size_).toString() + clear_after_size + this.f3674k.getString(C0415R.string.process_usage_size_m).toString());
        this.f3667d.setText(this.f3674k.getString(C0415R.string.process_usage_rate_).toString() + uate + this.f3674k.getString(C0415R.string.process_usage_rate_bai).toString());
    }

    public void updateRunningView(int memsize) {
        int clear_before_rate = this.f3679p.stringtoInt(this.f3667d.getText().toString().replace(this.f3674k.getString(C0415R.string.process_usage_rate_).toString(), ""));
        String mem_present = this.f3666c.getText().toString().replace(this.f3674k.getString(C0415R.string.process_usage_size_).toString(), "");
        String app_mem = this.f3679p.inttostring(memsize / 1024);
        int clear_after_size = this.f3679p.getUeageSize(mem_present, app_mem);
        int uate = this.f3679p.getUeageRate1(this.f3678o, this.f3679p.inttostring(clear_after_size));
        this.f3666c.setText(this.f3674k.getString(C0415R.string.process_usage_size_).toString() + clear_after_size + this.f3674k.getString(C0415R.string.process_usage_size_m).toString());
        this.f3667d.setText(this.f3674k.getString(C0415R.string.process_usage_rate_).toString() + uate + this.f3674k.getString(C0415R.string.process_usage_rate_bai).toString());
        this.f3668e.showClearAnimation1(clear_before_rate, uate);
    }
}
