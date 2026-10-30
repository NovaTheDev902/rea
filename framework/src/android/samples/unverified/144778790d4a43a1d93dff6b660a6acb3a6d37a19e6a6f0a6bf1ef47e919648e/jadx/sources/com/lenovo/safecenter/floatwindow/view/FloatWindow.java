package com.lenovo.safecenter.floatwindow.view;

import android.content.Context;
import android.content.Intent;
import android.graphics.Rect;
import android.os.Parcelable;
import android.support.v4.view.PagerAdapter;
import android.support.v4.view.ViewPager;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.ImageView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.MainTab.LeSafeMainActivity;
import com.lenovo.safecenter.floatwindow.data.SaveData;
import com.lenovo.safecenter.support.SecurityService;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class FloatWindow extends FrameLayout implements View.OnClickListener {

    /* JADX INFO: renamed from: a */
    private static int f3598a = -1;

    /* JADX INFO: renamed from: b */
    private static int f3599b = -1;
    public static FloatWindow instanceFloatWindow;

    /* JADX INFO: renamed from: c */
    private Context f3600c;

    /* JADX INFO: renamed from: d */
    private View f3601d;

    /* JADX INFO: renamed from: e */
    private WindowManager f3602e;

    /* JADX INFO: renamed from: f */
    private WindowManager.LayoutParams f3603f;

    /* JADX INFO: renamed from: g */
    private Button f3604g;

    /* JADX INFO: renamed from: h */
    private int f3605h;

    /* JADX INFO: renamed from: i */
    private ViewPager f3606i;

    /* JADX INFO: renamed from: j */
    private List<View> f3607j;

    /* JADX INFO: renamed from: k */
    private ImageView[] f3608k;

    /* JADX INFO: renamed from: l */
    private ImageView f3609l;

    /* JADX INFO: renamed from: m */
    private float f3610m;

    /* JADX INFO: renamed from: n */
    private float f3611n;

    /* JADX INFO: renamed from: o */
    private float f3612o;

    /* JADX INFO: renamed from: p */
    private float f3613p;

    /* JADX INFO: renamed from: q */
    private boolean f3614q;

    /* JADX INFO: renamed from: r */
    private boolean f3615r;

    /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
    public FloatWindow(Context _context) {
        super(_context);
        byte b = 0;
        this.f3600c = null;
        this.f3602e = null;
        this.f3603f = null;
        this.f3604g = null;
        this.f3605h = -1;
        this.f3600c = _context;
        if (this.f3602e == null) {
            Context context = this.f3600c;
            Context context2 = this.f3600c;
            this.f3602e = (WindowManager) context.getSystemService("window");
        }
        instanceFloatWindow = this;
        WindowManager.LayoutParams layoutParams = new WindowManager.LayoutParams();
        layoutParams.type = 2003;
        layoutParams.format = -2;
        layoutParams.gravity = 51;
        layoutParams.x = f3598a;
        layoutParams.y = f3599b;
        this.f3603f = layoutParams;
        inflate(this.f3600c, C0415R.layout.assist_float_window, this);
        this.f3601d = findViewById(C0415R.id.root_view);
        setFocusableInTouchMode(true);
        setFocusable(true);
        setOnClickListener(this);
        this.f3604g = (Button) findViewById(C0415R.id.setting);
        this.f3604g.setOnClickListener(this);
        this.f3609l = (ImageView) findViewById(C0415R.id.assist_title);
        this.f3609l.setOnClickListener(this);
        ImageView imageView = (ImageView) findViewById(C0415R.id.assist_indicator_one);
        ImageView imageView2 = (ImageView) findViewById(C0415R.id.assist_indicator_two);
        this.f3608k = new ImageView[]{imageView, imageView2};
        imageView.setSelected(true);
        imageView2.setSelected(false);
        this.f3607j = new ArrayList();
        this.f3606i = (ViewPager) findViewById(C0415R.id.assist_viewpager);
        this.f3606i.setAdapter(new C0563b());
        this.f3606i.removeAllViews();
        ViewPagerSwitcher viewPagerSwitcher = new ViewPagerSwitcher(_context);
        RecentTaskView recentTaskView = new RecentTaskView(_context);
        recentTaskView.setBackgroundResource(C0415R.drawable.assist_pager_bg);
        this.f3607j.add(viewPagerSwitcher);
        this.f3607j.add(recentTaskView);
        this.f3606i.setOnPageChangeListener(new C0562a(this, b));
    }

    public void changeWindowView(int _paramInt) {
        if (this.f3605h != _paramInt) {
            this.f3605h = _paramInt;
            DisplayMetrics localDisplayMetrics = new DisplayMetrics();
            this.f3602e.getDefaultDisplay().getMetrics(localDisplayMetrics);
            ViewGroup.LayoutParams localLayoutParams = this.f3601d.getLayoutParams();
            this.f3601d.setLayoutParams(localLayoutParams);
            Log.d("windowview", "高：" + this.f3601d.getHeight() + "宽：" + this.f3601d.getWidth());
            SaveData.save_FloatView_width(this.f3600c, this.f3601d.getWidth());
            SaveData.save_FloatView_height(this.f3600c, this.f3601d.getHeight());
            this.f3601d.invalidate();
        }
    }

    public void showFloatWindow() {
        try {
            this.f3602e.addView(this, this.f3603f);
            this.f3615r = SaveData.get_flow_immove_state(this.f3600c);
            if (SecurityService.instance != null) {
                SecurityService.instance.setFlowIsFixed(true);
            }
        } catch (Exception e) {
            Log.d("animation", "启动动画错误" + e);
        }
    }

    public void delFloatWindow() {
        try {
            this.f3602e.removeView(this);
            if (SecurityService.instance != null) {
                SecurityService.instance.setFlowIsFixed(this.f3615r);
            }
            if (SwitcherContainerView.receiver != null) {
                SwitcherContainerView.unregisterReceiver();
            }
            Intent intent = new Intent();
            intent.setAction("com.lenovo.safecenter.floatwindow.closewindow");
            this.f3600c.sendBroadcast(intent);
        } catch (Exception e) {
            Log.d("windowException", "移除窗口时错误");
        }
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.assist_title /* 2131296847 */:
                delFloatWindow();
                Intent intent = new Intent();
                intent.setClass(this.f3600c, LeSafeMainActivity.class);
                intent.setFlags(268435456);
                this.f3600c.startActivity(intent);
                break;
            case C0415R.id.setting /* 2131296848 */:
                delFloatWindow();
                changeWindowView(this.f3600c.getResources().getConfiguration().orientation);
                break;
        }
    }

    @Override // android.view.ViewGroup, android.view.View
    protected void onAttachedToWindow() {
        super.onAttachedToWindow();
    }

    @Override // android.view.ViewGroup, android.view.View
    protected void onDetachedFromWindow() {
        super.onDetachedFromWindow();
    }

    @Override // android.view.View
    public void onWindowFocusChanged(boolean hasWindowFocus) {
        super.onWindowFocusChanged(hasWindowFocus);
    }

    @Override // android.view.View, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        switch (event.getKeyCode()) {
            case 3:
                delFloatWindow();
                break;
            case 4:
                delFloatWindow();
                break;
        }
        return super.onKeyDown(keyCode, event);
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.floatwindow.view.FloatWindow$b */
    class C0563b extends PagerAdapter {
        C0563b() {
        }

        @Override // android.support.v4.view.PagerAdapter
        public final void destroyItem(View arg0, int arg1, Object arg2) {
            ((ViewPager) arg0).removeView((View) FloatWindow.this.f3607j.get(arg1));
        }

        @Override // android.support.v4.view.PagerAdapter
        public final void finishUpdate(View arg0) {
        }

        @Override // android.support.v4.view.PagerAdapter
        public final int getCount() {
            return FloatWindow.this.f3607j.size();
        }

        @Override // android.support.v4.view.PagerAdapter
        public final Object instantiateItem(View arg0, int arg1) {
            ((ViewPager) arg0).addView((View) FloatWindow.this.f3607j.get(arg1), 0);
            return FloatWindow.this.f3607j.get(arg1);
        }

        @Override // android.support.v4.view.PagerAdapter
        public final boolean isViewFromObject(View arg0, Object arg1) {
            return arg0 == arg1;
        }

        @Override // android.support.v4.view.PagerAdapter
        public final void restoreState(Parcelable arg0, ClassLoader arg1) {
        }

        @Override // android.support.v4.view.PagerAdapter
        public final Parcelable saveState() {
            return null;
        }

        @Override // android.support.v4.view.PagerAdapter
        public final void startUpdate(View arg0) {
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.floatwindow.view.FloatWindow$a */
    private class C0562a implements ViewPager.OnPageChangeListener {
        private C0562a() {
        }

        /* synthetic */ C0562a(FloatWindow x0, byte b) {
            this();
        }

        @Override // android.support.v4.view.ViewPager.OnPageChangeListener
        public final void onPageScrollStateChanged(int arg0) {
        }

        @Override // android.support.v4.view.ViewPager.OnPageChangeListener
        public final void onPageScrolled(int arg0, float arg1, int arg2) {
        }

        @Override // android.support.v4.view.ViewPager.OnPageChangeListener
        public final void onPageSelected(int arg0) {
            for (int i = 0; i < FloatWindow.this.f3608k.length; i++) {
                FloatWindow.this.f3608k[i].setSelected(false);
            }
            FloatWindow.this.f3608k[arg0].setSelected(true);
        }
    }

    @Override // android.view.View
    public boolean onTouchEvent(MotionEvent event) {
        this.f3612o = event.getRawX();
        this.f3613p = event.getRawY() - 25.0f;
        if (!this.f3614q) {
            this.f3610m = this.f3612o;
            this.f3611n = this.f3613p;
            this.f3614q = true;
        }
        switch (event.getAction()) {
            case 1:
                this.f3614q = false;
                float f = this.f3610m;
                float f2 = this.f3611n;
                Rect rect = new Rect();
                rect.top = this.f3601d.getTop();
                rect.left = this.f3601d.getLeft();
                rect.right = this.f3601d.getRight();
                rect.bottom = this.f3601d.getBottom();
                if (!rect.contains((int) event.getX(), (int) event.getY())) {
                    delFloatWindow();
                    break;
                }
            case 0:
            default:
                return true;
        }
    }

    protected void onFocusLost() {
        super.onFocusLost();
        if (SwitcherContainerView.screenWindowDel) {
            delFloatWindow();
        }
        SwitcherContainerView.screenWindowDel = true;
    }
}
