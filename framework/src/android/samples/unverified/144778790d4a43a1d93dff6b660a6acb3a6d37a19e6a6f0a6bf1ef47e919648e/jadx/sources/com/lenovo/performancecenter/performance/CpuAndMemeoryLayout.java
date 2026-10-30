package com.lenovo.performancecenter.performance;

import android.content.Context;
import android.os.Handler;
import android.os.Message;
import android.util.AttributeSet;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;
import com.lenovo.performancecenter.coreui.util.MemoryTools;
import com.lenovo.performancecenter.coreui.util.Utils;
import com.lenovo.performancecenter.coreui.widget.RotatePointerAniView2;
import com.lenovo.safecenter.C0415R;

/* JADX INFO: loaded from: classes.dex */
public class CpuAndMemeoryLayout extends LinearLayout {

    /* JADX INFO: renamed from: a */
    private Context f1699a;

    /* JADX INFO: renamed from: b */
    private HandlerC0172a f1700b;

    /* JADX INFO: renamed from: c */
    private Thread f1701c;

    /* JADX INFO: renamed from: d */
    private boolean f1702d;

    /* JADX INFO: renamed from: e */
    private int f1703e;

    /* JADX INFO: renamed from: f */
    private RotatePointerAniView2 f1704f;

    /* JADX INFO: renamed from: g */
    private TextView f1705g;

    /* JADX INFO: renamed from: h */
    private TextView f1706h;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m626a(CpuAndMemeoryLayout x0, int x1, int x2) {
        if (x2 < 10) {
            x0.f1705g.setText(" " + x2 + "%");
        } else {
            x0.f1705g.setText(x2 + "%");
        }
        if (x1 < 10) {
            x0.f1706h.setText(" " + x1 + "%");
        } else {
            x0.f1706h.setText(x1 + "%");
        }
        x0.f1704f.bpRotate((x2 * RotatePointerAniView2.MAX_DEGREES) / 100);
        x0.f1704f.spRotate((x1 * RotatePointerAniView2.MAX_DEGREES) / 100);
    }

    /* JADX INFO: renamed from: e */
    static /* synthetic */ int m631e(CpuAndMemeoryLayout x0) {
        int i = x0.f1703e;
        x0.f1703e = i + 1;
        return i;
    }

    public CpuAndMemeoryLayout(Context context) {
        super(context);
        this.f1702d = true;
        this.f1703e = 3;
        m625a(context);
    }

    public CpuAndMemeoryLayout(Context context, int i, AttributeSet as) {
        super(context, as);
        this.f1702d = true;
        this.f1703e = 3;
        m625a(context);
    }

    public CpuAndMemeoryLayout(Context context, AttributeSet as) {
        super(context, as);
        this.f1702d = true;
        this.f1703e = 3;
        Log.i("CpuAndMemeoryLayout", "three...");
        m625a(context);
    }

    /* JADX INFO: renamed from: a */
    private void m625a(Context context) {
        if (context == null) {
            context = getContext();
        }
        this.f1699a = context;
        this.f1700b = new HandlerC0172a();
        LayoutInflater.from(context).inflate(C0415R.layout.rf_perf_taskmanager_cpumemeory_new, (ViewGroup) this, true);
        this.f1704f = (RotatePointerAniView2) findViewById(C0415R.id.systemLayout);
        this.f1705g = (TextView) findViewById(C0415R.id.memoryUsage);
        this.f1706h = (TextView) findViewById(C0415R.id.cpuUsage);
    }

    public void startThread() {
        this.f1702d = true;
        this.f1703e = 0;
        this.f1701c = new Thread(new Runnable() { // from class: com.lenovo.performancecenter.performance.CpuAndMemeoryLayout.1
            @Override // java.lang.Runnable
            public final void run() throws Throwable {
                Log.i("CpuAndMemeoryLayout", "---> run()");
                while (CpuAndMemeoryLayout.this.f1702d) {
                    Log.i("CpuAndMemeoryLayout", System.currentTimeMillis() + " ---> run() content");
                    MemoryTools mt = new MemoryTools();
                    Message msg = new Message();
                    int cpuUseReal = Utils.readCpuUsage();
                    int cpuUse = (int) (((double) cpuUseReal) * 0.4d);
                    Log.i("CpuAndMemeoryLayout", "cpuUse == " + cpuUse);
                    if (cpuUse > 100) {
                        cpuUse = 100;
                    } else if (cpuUse < 0) {
                        cpuUse = 1;
                    }
                    msg.what = 0;
                    msg.arg1 = cpuUse;
                    int memoryUse = mt.getSystemMeminfo();
                    Log.i("CpuAndMemeoryLayout", "memoryUse == " + memoryUse);
                    if (memoryUse > 100) {
                        memoryUse = 100;
                    } else if (memoryUse < 0) {
                        memoryUse = 1;
                    }
                    msg.arg2 = memoryUse;
                    CpuAndMemeoryLayout.this.f1700b.sendMessageDelayed(msg, 200L);
                    try {
                        if (CpuAndMemeoryLayout.this.f1703e <= 3) {
                            Thread unused = CpuAndMemeoryLayout.this.f1701c;
                            Thread.sleep(1500L);
                            CpuAndMemeoryLayout.m631e(CpuAndMemeoryLayout.this);
                        } else {
                            Thread unused2 = CpuAndMemeoryLayout.this.f1701c;
                            Thread.sleep(5000L);
                        }
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        });
        this.f1701c.start();
    }

    public void onResume() {
        Log.i("CpuAndMemeoryLayout", "---> onResume");
        startThread();
    }

    public void onPause() {
        Log.i("CpuAndMemeoryLayout", "---> onPause");
        this.f1702d = false;
    }

    public void onStop() {
        this.f1701c = null;
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.CpuAndMemeoryLayout$a */
    class HandlerC0172a extends Handler {
        HandlerC0172a() {
        }

        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    CpuAndMemeoryLayout.m626a(CpuAndMemeoryLayout.this, msg.arg1, msg.arg2);
                    break;
            }
        }
    }

    @Override // android.view.ViewGroup
    public void addView(View child) {
        Log.i("CpuAndMemeoryLayout", "addView()...view=" + child);
        super.addView(child);
    }

    @Override // android.view.ViewGroup
    public void addView(View child, int index) {
        super.addView(child, index);
    }

    @Override // android.view.ViewGroup
    public void addView(View child, int width, int height) {
        super.addView(child, width, height);
    }

    @Override // android.view.ViewGroup, android.view.ViewManager
    public void addView(View child, ViewGroup.LayoutParams params) {
        super.addView(child, params);
    }

    @Override // android.view.ViewGroup
    public void addView(View child, int index, ViewGroup.LayoutParams params) {
        super.addView(child, index, params);
    }

    @Override // android.view.View
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        super.onSizeChanged(w, h, oldw, oldh);
    }
}
