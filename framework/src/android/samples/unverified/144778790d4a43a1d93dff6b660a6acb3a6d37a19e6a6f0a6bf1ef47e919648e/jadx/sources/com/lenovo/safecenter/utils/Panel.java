package com.lenovo.safecenter.utils;

import android.content.Context;
import android.content.res.TypedArray;
import android.graphics.Canvas;
import android.graphics.drawable.Drawable;
import android.os.Handler;
import android.os.Message;
import android.os.SystemClock;
import android.util.AttributeSet;
import android.util.Log;
import android.view.GestureDetector;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewParent;
import android.view.animation.Interpolator;
import android.widget.FrameLayout;
import android.widget.LinearLayout;
import com.lenovo.safecenter.C0415R;

/* JADX INFO: loaded from: classes.dex */
public class Panel extends LinearLayout {
    public static final int BOTTOM = 1;
    public static final int LEFT = 2;
    public static final int RIGHT = 3;
    public static final int TOP = 0;

    /* JADX INFO: renamed from: A */
    private float f5753A;

    /* JADX INFO: renamed from: B */
    private float f5754B;

    /* JADX INFO: renamed from: C */
    private OnPanelListener f5755C;

    /* JADX INFO: renamed from: D */
    private EnumC1042c f5756D;

    /* JADX INFO: renamed from: E */
    private Interpolator f5757E;

    /* JADX INFO: renamed from: F */
    private GestureDetector f5758F;

    /* JADX INFO: renamed from: G */
    private int f5759G;

    /* JADX INFO: renamed from: H */
    private int f5760H;

    /* JADX INFO: renamed from: I */
    private int f5761I;

    /* JADX INFO: renamed from: J */
    private float f5762J;

    /* JADX INFO: renamed from: K */
    private GestureDetectorOnGestureListenerC1040a f5763K;

    /* JADX INFO: renamed from: L */
    private boolean f5764L;

    /* JADX INFO: renamed from: M */
    private View f5765M;

    /* JADX INFO: renamed from: a */
    View.OnTouchListener f5766a;

    /* JADX INFO: renamed from: b */
    private final Handler f5767b;

    /* JADX INFO: renamed from: c */
    private float f5768c;

    /* JADX INFO: renamed from: d */
    private long f5769d;

    /* JADX INFO: renamed from: e */
    private long f5770e;

    /* JADX INFO: renamed from: f */
    private boolean f5771f;

    /* JADX INFO: renamed from: g */
    private final int f5772g;

    /* JADX INFO: renamed from: h */
    private final int f5773h;

    /* JADX INFO: renamed from: i */
    private float f5774i;

    /* JADX INFO: renamed from: j */
    private float f5775j;

    /* JADX INFO: renamed from: k */
    private float f5776k;

    /* JADX INFO: renamed from: l */
    private float f5777l;

    /* JADX INFO: renamed from: m */
    private float f5778m;

    /* JADX INFO: renamed from: n */
    private float f5779n;

    /* JADX INFO: renamed from: o */
    private boolean f5780o;

    /* JADX INFO: renamed from: p */
    private int f5781p;

    /* JADX INFO: renamed from: q */
    private int f5782q;

    /* JADX INFO: renamed from: r */
    private boolean f5783r;

    /* JADX INFO: renamed from: s */
    private int f5784s;

    /* JADX INFO: renamed from: t */
    private int f5785t;

    /* JADX INFO: renamed from: u */
    private int f5786u;

    /* JADX INFO: renamed from: v */
    private View f5787v;

    /* JADX INFO: renamed from: w */
    private View f5788w;

    /* JADX INFO: renamed from: x */
    private Drawable f5789x;

    /* JADX INFO: renamed from: y */
    private Drawable f5790y;

    /* JADX INFO: renamed from: z */
    private float f5791z;

    public interface OnPanelListener {
        void onPanelClosed(Panel panel);

        void onPanelOpened(Panel panel);
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.utils.Panel$c */
    private enum EnumC1042c {
        ABOUT_TO_ANIMATE,
        ANIMATING,
        READY,
        TRACKING,
        FLYING,
        CLICK
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ float m2395a(float x1, int x2, int x3) {
        return Math.min(Math.max(x1, x2), x3);
    }

    /* JADX INFO: renamed from: d */
    static /* synthetic */ boolean m2408d(Panel x0) {
        x0.f5771f = true;
        return true;
    }

    /* JADX INFO: renamed from: u */
    static /* synthetic */ void m2431u(Panel x0) {
        if (x0.f5771f) {
            long jUptimeMillis = SystemClock.uptimeMillis();
            float f = (jUptimeMillis - x0.f5769d) / 1000.0f;
            float f2 = x0.f5754B;
            float f3 = x0.f5768c;
            x0.f5754B = (f3 * f) + f2;
            x0.f5769d = jUptimeMillis;
            switch (x0.f5781p) {
                case 0:
                    x0.f5753A = x0.f5753A + (f2 * f) + (0.5f * f3 * f * f);
                    if (x0.f5753A > 0.0f) {
                        x0.f5753A = 0.0f;
                        x0.f5756D = EnumC1042c.READY;
                        x0.f5771f = false;
                    } else if (x0.f5753A < (-x0.f5759G)) {
                        x0.f5753A = -x0.f5759G;
                        if (x0.m2399a()) {
                            x0.f5788w.setVisibility(8);
                        } else {
                            x0.f5765M.setVisibility(8);
                        }
                        x0.f5756D = EnumC1042c.READY;
                        x0.f5771f = false;
                    }
                    break;
                case 1:
                    x0.f5753A = x0.f5753A + (f2 * f) + (0.5f * f3 * f * f);
                    if (x0.f5753A < 0.0f) {
                        x0.f5753A = 0.0f;
                        x0.f5756D = EnumC1042c.READY;
                        x0.f5771f = false;
                    } else if (x0.f5753A > x0.f5759G) {
                        x0.f5753A = x0.f5759G;
                        if (x0.m2399a()) {
                            x0.f5788w.setVisibility(8);
                        } else {
                            x0.f5765M.setVisibility(8);
                        }
                        x0.f5756D = EnumC1042c.READY;
                        x0.f5771f = false;
                    }
                    break;
                case 2:
                    x0.f5791z = x0.f5791z + (f2 * f) + (0.5f * f3 * f * f);
                    if (x0.f5791z > 0.0f) {
                        x0.f5791z = 0.0f;
                        x0.f5756D = EnumC1042c.READY;
                        x0.f5771f = false;
                    } else if (x0.f5791z < (-x0.f5760H)) {
                        x0.f5791z = -x0.f5760H;
                        x0.f5765M.setVisibility(8);
                        x0.f5756D = EnumC1042c.READY;
                        x0.f5771f = false;
                    }
                    break;
                case 3:
                    x0.f5791z = x0.f5791z + (f2 * f) + (0.5f * f3 * f * f);
                    if (x0.f5791z < 0.0f) {
                        x0.f5791z = 0.0f;
                        x0.f5756D = EnumC1042c.READY;
                        x0.f5771f = false;
                    } else if (x0.f5791z > x0.f5760H) {
                        x0.f5791z = x0.f5760H;
                        if (x0.m2399a()) {
                            x0.f5788w.setVisibility(8);
                        } else {
                            x0.f5765M.setVisibility(8);
                        }
                        x0.f5756D = EnumC1042c.READY;
                        x0.f5771f = false;
                    }
                    break;
            }
            x0.invalidate();
            if (!x0.f5771f) {
                x0.m2403b();
            } else {
                x0.f5770e += 16;
                x0.f5767b.sendMessageAtTime(x0.f5767b.obtainMessage(1000), x0.f5770e);
            }
        }
    }

    /* JADX INFO: renamed from: v */
    static /* synthetic */ void m2432v(Panel x0) {
        switch (x0.f5781p) {
            case 0:
                if (!x0.f5780o) {
                    x0.f5754B = x0.f5772g;
                    x0.f5768c = x0.f5773h;
                    if (x0.f5791z == 0.0f && x0.f5756D == EnumC1042c.ABOUT_TO_ANIMATE) {
                        x0.f5753A = -x0.f5759G;
                    }
                } else {
                    x0.f5754B = -x0.f5772g;
                    x0.f5768c = -x0.f5773h;
                }
                break;
            case 1:
                if (!x0.f5780o) {
                    x0.f5754B = -x0.f5772g;
                    x0.f5768c = -x0.f5773h;
                    if (x0.f5791z == 0.0f && x0.f5756D == EnumC1042c.ABOUT_TO_ANIMATE) {
                        x0.f5753A = x0.f5759G;
                    }
                } else {
                    x0.f5754B = x0.f5772g;
                    x0.f5768c = x0.f5773h;
                }
                break;
            case 2:
                if (!x0.f5780o) {
                    x0.f5754B = x0.f5772g;
                    x0.f5768c = x0.f5773h;
                    if (x0.f5791z == 0.0f && x0.f5756D == EnumC1042c.ABOUT_TO_ANIMATE) {
                        x0.f5791z = -x0.f5760H;
                    }
                } else {
                    x0.f5754B = -x0.f5772g;
                    x0.f5768c = -x0.f5773h;
                }
                break;
            case 3:
                if (!x0.f5780o) {
                    x0.f5754B = -x0.f5772g;
                    x0.f5768c = -x0.f5773h;
                    if (x0.f5791z == 0.0f && x0.f5756D == EnumC1042c.ABOUT_TO_ANIMATE) {
                        x0.f5791z = x0.f5760H;
                    }
                } else {
                    x0.f5754B = x0.f5772g;
                    x0.f5768c = x0.f5773h;
                }
                break;
        }
        if (x0.f5756D == EnumC1042c.TRACKING) {
            if (x0.isOpen()) {
                if ((x0.f5761I == 1 && Math.abs(x0.f5753A) < x0.f5759G / 2.0f) || (x0.f5761I == 0 && Math.abs(x0.f5791z) < x0.f5760H / 2.0f)) {
                    x0.f5754B = -x0.f5754B;
                    x0.f5768c = -x0.f5768c;
                    x0.f5780o = x0.f5780o ? false : true;
                }
            } else if ((x0.f5761I == 1 && Math.abs(x0.f5753A) > x0.f5759G / 2.0f) || (x0.f5761I == 0 && Math.abs(x0.f5791z) > x0.f5760H / 2.0f)) {
                x0.f5754B = -x0.f5754B;
                x0.f5768c = -x0.f5768c;
                x0.f5780o = x0.f5780o ? false : true;
            }
        }
        if (x0.f5756D == EnumC1042c.FLYING || x0.f5756D == EnumC1042c.TRACKING) {
            return;
        }
        x0.f5756D = EnumC1042c.CLICK;
    }

    /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
    public Panel(Context context, AttributeSet attrs) {
        super(context, attrs);
        int i = 1;
        this.f5767b = new HandlerC1041b(this, (byte) 0);
        this.f5766a = new View.OnTouchListener() { // from class: com.lenovo.safecenter.utils.Panel.1
            @Override // android.view.View.OnTouchListener
            public final boolean onTouch(View v, MotionEvent event) {
                if (Panel.this.f5771f) {
                    return true;
                }
                int action = event.getAction();
                if (action == 0 && Panel.this.f5764L) {
                    Panel.this.bringToFront();
                }
                if (!Panel.this.f5758F.onTouchEvent(event) && action == 1) {
                    long now = SystemClock.uptimeMillis();
                    Panel.this.f5769d = now;
                    Panel.this.f5770e = 16 + now;
                    Panel.m2408d(Panel.this);
                    Panel.this.f5767b.removeMessages(1000);
                    Panel.this.f5767b.removeMessages(2000);
                    Panel.this.f5767b.sendMessageAtTime(Panel.this.f5767b.obtainMessage(2000), Panel.this.f5770e);
                }
                return false;
            }
        };
        TypedArray a = context.obtainStyledAttributes(attrs, C0415R.styleable.Panel);
        this.f5782q = a.getInteger(0, 750);
        this.f5781p = a.getInteger(1, 1);
        this.f5783r = a.getBoolean(6, false);
        this.f5762J = a.getFraction(7, 0, 1, 0.0f);
        if (this.f5762J < 0.0f || this.f5762J > 1.0f) {
            this.f5762J = 0.0f;
            Log.w("Panel", a.getPositionDescription() + ": weight must be > 0 and <= 1");
        }
        this.f5789x = a.getDrawable(8);
        this.f5790y = a.getDrawable(9);
        this.f5784s = a.getResourceId(2, 0);
        RuntimeException e = this.f5784s == 0 ? new IllegalArgumentException(a.getPositionDescription() + ": The handle attribute is required and must refer to a valid child.") : null;
        this.f5785t = a.getResourceId(4, 0);
        e = this.f5785t == 0 ? new IllegalArgumentException(a.getPositionDescription() + ": The content attribute is required and must refer to a valid child.") : e;
        this.f5786u = a.getResourceId(5, 0);
        a.recycle();
        float density = getResources().getDisplayMetrics().density;
        this.f5772g = (int) ((200.0f * density) + 0.5f);
        this.f5773h = (int) ((2000.0f * density) + 0.5f);
        if (e != null) {
            throw e;
        }
        if (this.f5781p != 0 && this.f5781p != 1) {
            i = 0;
        }
        this.f5761I = i;
        setOrientation(this.f5761I);
        this.f5756D = EnumC1042c.READY;
        this.f5763K = new GestureDetectorOnGestureListenerC1040a();
        this.f5758F = new GestureDetector(this.f5763K);
        this.f5758F.setIsLongpressEnabled(false);
        setBaselineAligned(false);
    }

    public void setOnPanelListener(OnPanelListener onPanelListener) {
        this.f5755C = onPanelListener;
    }

    public View getHandle() {
        return this.f5787v;
    }

    public View getContent() {
        return this.f5788w;
    }

    public void setInterpolator(Interpolator i) {
        this.f5757E = i;
    }

    public boolean setOpen(boolean open, boolean animate) {
        if (this.f5756D != EnumC1042c.READY || !(isOpen() ^ open)) {
            return false;
        }
        this.f5780o = !open;
        if (animate) {
            this.f5756D = EnumC1042c.ABOUT_TO_ANIMATE;
            if (!this.f5780o) {
                this.f5765M.setVisibility(0);
            }
            long now = SystemClock.uptimeMillis();
            this.f5769d = now;
            this.f5770e = 16 + now;
            this.f5771f = true;
            this.f5767b.removeMessages(1000);
            this.f5767b.removeMessages(2000);
            this.f5767b.sendMessageAtTime(this.f5767b.obtainMessage(2000), this.f5770e);
            return true;
        }
        this.f5765M.setVisibility(open ? 0 : 8);
        m2403b();
        return true;
    }

    public boolean isOpen() {
        if (m2399a()) {
            return this.f5788w.getVisibility() == 0;
        }
        return this.f5765M.getVisibility() == 0;
    }

    @Override // android.view.View
    protected void onFinishInflate() {
        ViewGroup.LayoutParams params;
        super.onFinishInflate();
        this.f5787v = findViewById(this.f5784s);
        if (this.f5787v == null) {
            String name = getResources().getResourceEntryName(this.f5784s);
            throw new RuntimeException("Your Panel must have a child View whose id attribute is 'R.id." + name + "'");
        }
        this.f5787v.setClickable(true);
        this.f5787v.setOnTouchListener(this.f5766a);
        this.f5788w = findViewById(this.f5785t);
        if (this.f5788w == null) {
            String name2 = getResources().getResourceEntryName(this.f5784s);
            throw new RuntimeException("Your Panel must have a child View whose id attribute is 'R.id." + name2 + "'");
        }
        this.f5765M = findViewById(this.f5786u);
        removeView(this.f5787v);
        removeView(this.f5788w);
        if (this.f5781p == 0 || this.f5781p == 2) {
            addView(this.f5788w);
            addView(this.f5787v);
        } else {
            addView(this.f5787v);
            addView(this.f5788w);
        }
        if (this.f5790y != null) {
            this.f5787v.setBackgroundDrawable(this.f5790y);
        }
        this.f5788w.setClickable(true);
        if (m2399a()) {
            this.f5788w.setVisibility(8);
        } else {
            this.f5765M.setVisibility(8);
        }
        if (this.f5762J > 0.0f) {
            if (m2399a()) {
                params = this.f5788w.getLayoutParams();
            } else {
                params = this.f5765M.getLayoutParams();
            }
            if (this.f5761I == 1) {
                params.height = -1;
            } else {
                params.width = -1;
            }
            if (m2399a()) {
                this.f5788w.setLayoutParams(params);
            } else {
                this.f5765M.setLayoutParams(params);
            }
        }
    }

    /* JADX INFO: renamed from: a */
    private boolean m2399a() {
        return this.f5765M == null;
    }

    @Override // android.view.ViewGroup, android.view.View
    protected void onAttachedToWindow() {
        super.onAttachedToWindow();
        ViewParent parent = getParent();
        if (parent != null && (parent instanceof FrameLayout)) {
            this.f5764L = true;
        }
    }

    @Override // android.widget.LinearLayout, android.view.View
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
        View parent;
        if (this.f5762J > 0.0f && isOpen() && (parent = (View) getParent()) != null) {
            if (this.f5761I == 1) {
                heightMeasureSpec = View.MeasureSpec.makeMeasureSpec((int) (parent.getHeight() * this.f5762J), 1073741824);
            } else {
                widthMeasureSpec = View.MeasureSpec.makeMeasureSpec((int) (parent.getWidth() * this.f5762J), 1073741824);
            }
        }
        super.onMeasure(widthMeasureSpec, heightMeasureSpec);
    }

    @Override // android.widget.LinearLayout, android.view.ViewGroup, android.view.View
    protected void onLayout(boolean changed, int l, int t, int r, int b) {
        super.onLayout(changed, l, t, r, b);
        if (m2399a()) {
            this.f5760H = this.f5788w.getWidth();
            this.f5759G = this.f5788w.getHeight();
        } else {
            this.f5760H = this.f5765M.getWidth();
            this.f5759G = this.f5765M.getHeight();
        }
    }

    @Override // android.view.ViewGroup, android.view.View
    protected void dispatchDraw(Canvas canvas) {
        if (this.f5756D == EnumC1042c.ABOUT_TO_ANIMATE && !this.f5780o) {
            int delta = this.f5761I == 1 ? this.f5759G : this.f5760H;
            if (this.f5781p == 2 || this.f5781p == 0) {
                delta = -delta;
            }
            if (this.f5761I == 1) {
                canvas.translate(0.0f, delta);
            } else {
                canvas.translate(delta, 0.0f);
            }
        }
        if (this.f5756D == EnumC1042c.TRACKING || this.f5756D == EnumC1042c.FLYING || this.f5756D == EnumC1042c.CLICK) {
            canvas.translate(this.f5791z, this.f5753A);
        }
        super.dispatchDraw(canvas);
    }

    public boolean initChange() {
        if (this.f5756D != EnumC1042c.READY) {
            return false;
        }
        this.f5756D = EnumC1042c.ABOUT_TO_ANIMATE;
        this.f5780o = isOpen();
        if (!this.f5780o) {
            if (m2399a()) {
                this.f5788w.setVisibility(0);
            } else {
                this.f5765M.setVisibility(0);
            }
        }
        return true;
    }

    /* JADX INFO: renamed from: b */
    private void m2403b() {
        if (!isOpen() && this.f5780o && this.f5790y != null) {
            this.f5787v.setBackgroundDrawable(this.f5790y);
        } else if (isOpen() && !this.f5780o && this.f5789x != null) {
            this.f5787v.setBackgroundDrawable(this.f5789x);
        }
        if (this.f5755C != null) {
            if (!isOpen()) {
                this.f5755C.onPanelClosed(this);
            } else {
                this.f5755C.onPanelOpened(this);
            }
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.utils.Panel$a */
    class GestureDetectorOnGestureListenerC1040a implements GestureDetector.OnGestureListener {

        /* JADX INFO: renamed from: a */
        float f5793a;

        /* JADX INFO: renamed from: b */
        float f5794b;

        GestureDetectorOnGestureListenerC1040a() {
        }

        @Override // android.view.GestureDetector.OnGestureListener
        public final boolean onDown(MotionEvent e) {
            this.f5793a = 0.0f;
            this.f5794b = 0.0f;
            Panel.this.f5774i = Panel.this.f5776k = Panel.this.f5775j = Panel.this.f5777l = -1.0f;
            Panel.this.f5778m = Panel.this.f5779n = -1.0f;
            Panel.this.initChange();
            return true;
        }

        @Override // android.view.GestureDetector.OnGestureListener
        public final boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX, float velocityY) {
            float velocityX2;
            float velocityY2;
            Panel.this.f5756D = EnumC1042c.FLYING;
            if (Panel.this.f5774i != -1.0f || Panel.this.f5775j != -1.0f) {
                velocityX2 = ((Panel.this.f5776k - Panel.this.f5774i) / (Panel.this.f5779n - Panel.this.f5778m)) * 1000.0f;
                velocityY2 = ((Panel.this.f5777l - Panel.this.f5775j) / (Panel.this.f5779n - Panel.this.f5778m)) * 1000.0f;
            } else {
                velocityX2 = ((Panel.this.f5776k - e1.getRawX()) / (Panel.this.f5779n - e1.getEventTime())) * 1000.0f;
                velocityY2 = ((Panel.this.f5777l - e1.getRawY()) / (Panel.this.f5779n - e1.getEventTime())) * 1000.0f;
            }
            Panel panel = Panel.this;
            if (Panel.this.f5761I != 1) {
                velocityY2 = velocityX2;
            }
            panel.f5754B = velocityY2;
            if (Math.abs(Panel.this.f5754B) > 50.0f) {
                if (Panel.this.f5754B > 0.0f) {
                    Panel.this.f5768c = Panel.this.f5773h;
                } else {
                    Panel.this.f5768c = -Panel.this.f5773h;
                }
                long now = SystemClock.uptimeMillis();
                Panel.this.f5769d = now;
                Panel.this.f5770e = 16 + now;
                Panel.m2408d(Panel.this);
                Panel.this.f5767b.removeMessages(1000);
                Panel.this.f5767b.removeMessages(2000);
                Panel.this.f5767b.sendMessageAtTime(Panel.this.f5767b.obtainMessage(1000), Panel.this.f5770e);
                return true;
            }
            return false;
        }

        @Override // android.view.GestureDetector.OnGestureListener
        public final void onLongPress(MotionEvent e) {
        }

        @Override // android.view.GestureDetector.OnGestureListener
        public final boolean onScroll(MotionEvent e1, MotionEvent e2, float distanceX, float distanceY) {
            Panel.this.f5756D = EnumC1042c.TRACKING;
            float tmpY = 0.0f;
            float tmpX = 0.0f;
            if (Panel.this.f5761I == 1) {
                this.f5793a -= distanceY;
                if (Panel.this.f5781p == 0) {
                    Panel panel = Panel.this;
                    tmpY = Panel.m2395a(this.f5793a, -Panel.this.f5759G, 0);
                } else {
                    Panel panel2 = Panel.this;
                    tmpY = Panel.m2395a(this.f5793a, 0, Panel.this.f5759G);
                }
            } else {
                this.f5794b -= distanceX;
                if (Panel.this.f5781p == 2) {
                    Panel panel3 = Panel.this;
                    tmpX = Panel.m2395a(this.f5794b, -Panel.this.f5760H, 0);
                } else {
                    Panel panel4 = Panel.this;
                    tmpX = Panel.m2395a(this.f5794b, 0, Panel.this.f5760H);
                }
            }
            if (tmpX != Panel.this.f5791z || tmpY != Panel.this.f5753A) {
                Panel.this.f5791z = tmpX;
                Panel.this.f5753A = tmpY;
            }
            Panel.this.invalidate();
            Panel.this.f5774i = Panel.this.f5776k;
            Panel.this.f5775j = Panel.this.f5777l;
            Panel.this.f5778m = Panel.this.f5779n;
            Panel.this.f5776k = e2.getRawX();
            Panel.this.f5777l = e2.getRawY();
            Panel.this.f5779n = e2.getEventTime();
            return true;
        }

        @Override // android.view.GestureDetector.OnGestureListener
        public final void onShowPress(MotionEvent e) {
        }

        @Override // android.view.GestureDetector.OnGestureListener
        public final boolean onSingleTapUp(MotionEvent e) {
            return false;
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.utils.Panel$b */
    private class HandlerC1041b extends Handler {
        private HandlerC1041b() {
        }

        /* synthetic */ HandlerC1041b(Panel x0, byte b) {
            this();
        }

        @Override // android.os.Handler
        public final void handleMessage(Message m) {
            switch (m.what) {
                case 1000:
                    Panel.m2431u(Panel.this);
                    break;
                case 2000:
                    Panel.m2432v(Panel.this);
                    Panel.m2431u(Panel.this);
                    break;
            }
        }
    }
}
