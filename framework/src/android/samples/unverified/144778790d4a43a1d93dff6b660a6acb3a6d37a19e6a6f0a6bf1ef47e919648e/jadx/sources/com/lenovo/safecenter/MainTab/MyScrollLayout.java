package com.lenovo.safecenter.MainTab;

import android.content.Context;
import android.util.AttributeSet;
import android.util.Log;
import android.view.MotionEvent;
import android.view.VelocityTracker;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Scroller;

/* JADX INFO: loaded from: classes.dex */
public class MyScrollLayout extends ViewGroup {

    /* JADX INFO: renamed from: a */
    private VelocityTracker f2777a;

    /* JADX INFO: renamed from: b */
    private Scroller f2778b;

    /* JADX INFO: renamed from: c */
    private int f2779c;

    /* JADX INFO: renamed from: d */
    private float f2780d;

    /* JADX INFO: renamed from: e */
    private OnViewChangeListener f2781e;
    public int mCurScreen;

    public MyScrollLayout(Context context) {
        super(context);
        this.f2779c = 0;
        m1263a(context);
    }

    public MyScrollLayout(Context context, AttributeSet attrs) {
        super(context, attrs);
        this.f2779c = 0;
        m1263a(context);
    }

    public MyScrollLayout(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
        this.f2779c = 0;
        m1263a(context);
    }

    /* JADX INFO: renamed from: a */
    private void m1263a(Context context) {
        this.mCurScreen = this.f2779c;
        this.f2778b = new Scroller(context);
    }

    @Override // android.view.ViewGroup, android.view.View
    protected void onLayout(boolean changed, int l, int t, int r, int b) {
        if (changed) {
            int childLeft = 0;
            int childCount = getChildCount();
            for (int i = 0; i < childCount; i++) {
                View childView = getChildAt(i);
                if (childView.getVisibility() != 8) {
                    int childWidth = childView.getMeasuredWidth();
                    childView.layout(childLeft, 0, childLeft + childWidth, childView.getMeasuredHeight());
                    childLeft += childWidth;
                }
            }
        }
    }

    @Override // android.view.View
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
        super.onMeasure(widthMeasureSpec, heightMeasureSpec);
        int width = View.MeasureSpec.getSize(widthMeasureSpec);
        int count = getChildCount();
        for (int i = 0; i < count; i++) {
            getChildAt(i).measure(widthMeasureSpec, heightMeasureSpec);
        }
        scrollTo(this.mCurScreen * width, 0);
    }

    public void snapToDestination() {
        int screenWidth = getWidth();
        int destScreen = (getScrollX() + (screenWidth / 2)) / screenWidth;
        snapToScreen(destScreen);
    }

    public void snapToScreen(int whichScreen) {
        int whichScreen2 = Math.max(0, Math.min(whichScreen, getChildCount() - 1));
        if (getScrollX() != getWidth() * whichScreen2) {
            int delta = (getWidth() * whichScreen2) - getScrollX();
            this.f2778b.startScroll(getScrollX(), 0, delta, 0, Math.abs(delta) * 2);
            this.mCurScreen = whichScreen2;
            invalidate();
            if (this.f2781e != null) {
                this.f2781e.OnViewChange(this.mCurScreen);
            }
        }
    }

    @Override // android.view.View
    public void computeScroll() {
        if (this.f2778b.computeScrollOffset()) {
            scrollTo(this.f2778b.getCurrX(), this.f2778b.getCurrY());
            postInvalidate();
        }
    }

    /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
    @Override // android.view.View
    public boolean onTouchEvent(MotionEvent event) {
        boolean z;
        int action = event.getAction();
        float x = event.getX();
        switch (action) {
            case 0:
                Log.i("", "onTouchEvent  ACTION_DOWN");
                if (this.f2777a == null) {
                    this.f2777a = VelocityTracker.obtain();
                    this.f2777a.addMovement(event);
                }
                if (!this.f2778b.isFinished()) {
                    this.f2778b.abortAnimation();
                }
                this.f2780d = x;
                return true;
            case 1:
                int velocityX = 0;
                if (this.f2777a != null) {
                    this.f2777a.addMovement(event);
                    this.f2777a.computeCurrentVelocity(1000);
                    velocityX = (int) this.f2777a.getXVelocity();
                }
                if (velocityX > 600 && this.mCurScreen > 0) {
                    Log.e("ScrollLayout", "snap left");
                    snapToScreen(this.mCurScreen - 1);
                } else if (velocityX < -600 && this.mCurScreen < getChildCount() - 1) {
                    Log.e("ScrollLayout", "snap right");
                    snapToScreen(this.mCurScreen + 1);
                } else {
                    snapToDestination();
                }
                if (this.f2777a != null) {
                    this.f2777a.recycle();
                    this.f2777a = null;
                }
                return true;
            case 2:
                int deltaX = (int) (this.f2780d - x);
                if (getScrollX() > 0 || deltaX >= 0) {
                    z = getScrollX() < (getChildCount() + (-1)) * getWidth() || deltaX <= 0;
                } else {
                    z = false;
                }
                if (z) {
                    if (this.f2777a != null) {
                        this.f2777a.addMovement(event);
                    }
                    this.f2780d = x;
                    scrollBy(deltaX, 0);
                }
                return true;
            default:
                return true;
        }
    }

    public void SetOnViewChangeListener(OnViewChangeListener listener) {
        this.f2781e = listener;
    }
}
