package com.lenovo.safecenter.floatwindow.view;

import android.content.Context;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.os.Handler;
import android.os.Message;
import android.util.DisplayMetrics;
import android.view.MotionEvent;
import android.view.View;
import android.view.WindowManager;
import android.widget.FrameLayout;
import com.lenovo.safecenter.floatwindow.data.SaveData;

/* JADX INFO: loaded from: classes.dex */
public class FlowIcon extends FrameLayout implements View.OnTouchListener {

    /* JADX INFO: renamed from: g */
    private static int f3619g = 400;

    /* JADX INFO: renamed from: h */
    private static int f3620h = 400;

    /* JADX INFO: renamed from: a */
    private Context f3621a;

    /* JADX INFO: renamed from: b */
    private FlowView f3622b;

    /* JADX INFO: renamed from: c */
    private float f3623c;

    /* JADX INFO: renamed from: d */
    private float f3624d;

    /* JADX INFO: renamed from: e */
    private WindowManager.LayoutParams f3625e;

    /* JADX INFO: renamed from: f */
    private WindowManager f3626f;

    /* JADX INFO: renamed from: i */
    private int[] f3627i;

    /* JADX INFO: renamed from: j */
    private float f3628j;

    /* JADX INFO: renamed from: k */
    private float f3629k;

    /* JADX INFO: renamed from: l */
    private float f3630l;

    /* JADX INFO: renamed from: m */
    private float f3631m;

    /* JADX INFO: renamed from: n */
    private float f3632n;

    /* JADX INFO: renamed from: o */
    private float f3633o;

    /* JADX INFO: renamed from: p */
    private boolean f3634p;

    /* JADX INFO: renamed from: q */
    private int f3635q;

    /* JADX INFO: renamed from: r */
    private boolean f3636r;

    /* JADX INFO: renamed from: s */
    private ConnectivityManager f3637s;

    /* JADX INFO: renamed from: t */
    private Handler f3638t;

    /* JADX INFO: renamed from: b */
    static /* synthetic */ int m1522b(FlowIcon x0) {
        int i = x0.f3635q;
        x0.f3635q = i + 1;
        return i;
    }

    /* JADX WARN: Type inference failed for: r0v0, types: [com.lenovo.safecenter.floatwindow.view.FlowIcon$1] */
    /* JADX INFO: renamed from: c */
    static /* synthetic */ void m1523c(FlowIcon x0) {
        new Thread() { // from class: com.lenovo.safecenter.floatwindow.view.FlowIcon.1
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                super.run();
                while (FlowIcon.this.f3634p) {
                    try {
                        sleep(200L);
                        FlowIcon.m1522b(FlowIcon.this);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        }.start();
    }

    /* JADX INFO: renamed from: f */
    static /* synthetic */ int m1526f(FlowIcon x0) {
        x0.f3635q = 0;
        return 0;
    }

    public FlowIcon(Context context) {
        super(context);
        this.f3627i = new int[0];
        this.f3634p = false;
        this.f3635q = 0;
        this.f3638t = new Handler() { // from class: com.lenovo.safecenter.floatwindow.view.FlowIcon.2
            @Override // android.os.Handler
            public final void handleMessage(Message msg) {
                switch (msg.what) {
                    case 0:
                        FlowIcon.this.f3634p = true;
                        FlowIcon.m1523c(FlowIcon.this);
                        break;
                    case 1:
                        FlowIcon.this.f3634p = false;
                        if (FlowIcon.this.f3635q <= 1) {
                            FlowIcon.this.f3622b.setOnclickContent();
                        }
                        FlowIcon.m1526f(FlowIcon.this);
                        break;
                }
            }
        };
        this.f3621a = context;
        if (this.f3626f == null) {
            Context context2 = this.f3621a;
            Context context3 = this.f3621a;
            this.f3626f = (WindowManager) context2.getSystemService("window");
        }
        this.f3625e = new WindowManager.LayoutParams();
        this.f3627i = SaveData.getFlowViewOptions(this.f3621a);
        WindowManager.LayoutParams layoutParams = this.f3625e;
        int i = this.f3627i[0];
        f3619g = i;
        layoutParams.x = i;
        WindowManager.LayoutParams layoutParams2 = this.f3625e;
        int i2 = this.f3627i[1];
        f3620h = i2;
        layoutParams2.y = i2;
        WindowManager.LayoutParams layoutParams3 = this.f3625e;
        layoutParams3.type = 2003;
        layoutParams3.flags |= 8;
        layoutParams3.width = -2;
        layoutParams3.height = -2;
        layoutParams3.format = -2;
        layoutParams3.gravity = 51;
        layoutParams3.x = f3619g;
        layoutParams3.y = f3620h;
        this.f3626f.getDefaultDisplay().getMetrics(new DisplayMetrics());
        this.f3622b = new FlowView(this.f3621a);
        addView(this.f3622b);
        setOnTouchListener(this);
        this.f3637s = (ConnectivityManager) context.getSystemService("connectivity");
    }

    public void addView_iconBase() {
        try {
            if (this.f3637s.getActiveNetworkInfo() != null && this.f3637s.getActiveNetworkInfo().getState() == NetworkInfo.State.CONNECTED) {
                int type = this.f3637s.getActiveNetworkInfo().getType();
                this.f3622b.setFlowDrawable(type);
                this.f3626f.addView(this, this.f3625e);
                this.f3622b.sendHanderMessage();
            }
        } catch (Exception e) {
        }
    }

    public void delView_iconBase() {
        try {
            this.f3622b.setViewGone();
            this.f3626f.removeView(this);
            this.f3622b.removeHanderMessage();
        } catch (Exception e) {
        }
    }

    public void setFlowWindowFixed(boolean isFixed, View viewFlow) {
        if (isFixed) {
            this.f3625e.flags = 56;
        } else {
            this.f3625e.flags = 8;
        }
        try {
            if (this.f3637s != null && this.f3637s.getActiveNetworkInfo() != null && this.f3637s.getActiveNetworkInfo().getState() == NetworkInfo.State.CONNECTED) {
                this.f3626f.updateViewLayout(viewFlow, this.f3625e);
            }
        } catch (Exception e) {
        }
    }

    /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
    @Override // android.view.View.OnTouchListener
    public boolean onTouch(View view, MotionEvent event) {
        this.f3623c = event.getRawX();
        this.f3624d = event.getRawY() - 25.0f;
        if (!this.f3636r) {
            this.f3628j = this.f3623c;
            this.f3629k = this.f3624d;
            this.f3636r = true;
        }
        switch (event.getAction()) {
            case 0:
                this.f3632n = event.getX();
                this.f3633o = event.getY();
                this.f3638t.sendEmptyMessage(0);
                return true;
            case 1:
                this.f3626f.updateViewLayout(view, this.f3625e);
                SaveData.savaFlowViewOptions(this.f3621a, this.f3625e.x, this.f3625e.y);
                this.f3636r = false;
                this.f3638t.sendEmptyMessage(1);
                return true;
            case 2:
                this.f3630l = event.getRawX();
                this.f3631m = event.getRawY();
                try {
                    if (Math.abs(this.f3628j - this.f3630l) > 40.0f || Math.abs(this.f3629k - this.f3631m) > 40.0f) {
                        this.f3625e.x = (int) (this.f3623c - this.f3632n);
                        this.f3625e.y = (int) (this.f3624d - this.f3633o);
                        this.f3626f.updateViewLayout(view, this.f3625e);
                    }
                    break;
                } catch (IllegalArgumentException e) {
                }
                return true;
            default:
                return true;
        }
    }
}
