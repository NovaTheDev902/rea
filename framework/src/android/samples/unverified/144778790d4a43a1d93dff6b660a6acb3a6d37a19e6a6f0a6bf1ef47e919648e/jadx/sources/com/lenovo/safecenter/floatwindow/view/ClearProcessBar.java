package com.lenovo.safecenter.floatwindow.view;

import android.content.Context;
import android.util.AttributeSet;
import android.view.animation.ScaleAnimation;
import android.widget.ImageView;
import android.widget.LinearLayout;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.floatwindow.listener.ClearProcessListener;

/* JADX INFO: loaded from: classes.dex */
public class ClearProcessBar extends LinearLayout {

    /* JADX INFO: renamed from: a */
    private ImageView f3591a;

    /* JADX INFO: renamed from: b */
    private Context f3592b;
    public ImageView move_img;

    public ClearProcessBar(Context context) {
        super(context);
        this.move_img = null;
    }

    public ClearProcessBar(Context context, AttributeSet attrs) {
        super(context, attrs);
        this.move_img = null;
        inflate(context, C0415R.layout.assist_clear_process_bar, this);
        this.f3592b = context;
        this.move_img = (ImageView) findViewById(C0415R.id.progress_bar);
        this.f3591a = (ImageView) findViewById(C0415R.id.progress_bar_top);
    }

    public void changeBar() {
        this.f3591a.setBackgroundResource(C0415R.drawable.assist_ani_progressbar_top_red);
        this.move_img.setBackgroundResource(C0415R.drawable.assist_ani_progressbar_bottom_red);
    }

    public void showStartAnimation(int paramInt) {
        float k = paramInt / 100.0f;
        if (paramInt >= 80) {
            this.f3591a.setBackgroundResource(C0415R.drawable.assist_ani_progressbar_top_red);
            this.move_img.setBackgroundResource(C0415R.drawable.assist_ani_progressbar_bottom_red);
        } else {
            this.move_img.setBackgroundResource(C0415R.drawable.assist_ani_progressbar_bottom_green);
            this.f3591a.setBackgroundResource(C0415R.drawable.assist_ani_progressbar_top_green);
        }
        ScaleAnimation localScaleAnimation1 = new ScaleAnimation(k, k, 1.0f, 1.0f, 1, 0.0f, 1, 0.0f);
        localScaleAnimation1.setFillAfter(true);
        localScaleAnimation1.setDuration(1000L);
        this.move_img.setAnimation(localScaleAnimation1);
    }

    public void showClearAnimation(int start, int over, int clearAfterSize) {
        float k = start / 100.0f;
        if (start >= over) {
            if (over > 80) {
                this.f3591a.setBackgroundResource(C0415R.drawable.assist_ani_progressbar_top_red);
                this.move_img.setBackgroundResource(C0415R.drawable.assist_ani_progressbar_bottom_red);
            } else {
                this.move_img.setBackgroundResource(C0415R.drawable.assist_ani_progressbar_bottom_green);
                this.f3591a.setBackgroundResource(C0415R.drawable.assist_ani_progressbar_top_green);
            }
        }
        ScaleAnimation localScaleAnimation1 = new ScaleAnimation(k, 0.0f, 1.0f, 1.0f, 1, 0.0f, 1, 0.0f);
        localScaleAnimation1.setFillAfter(true);
        localScaleAnimation1.setDuration(1000L);
        this.move_img.setAnimation(localScaleAnimation1);
        this.move_img.startAnimation(localScaleAnimation1);
        ClearProcessListener lClearProcessListener = new ClearProcessListener(this, this.f3592b, over, clearAfterSize);
        localScaleAnimation1.setAnimationListener(lClearProcessListener);
    }

    public void showClearAnimation1(int start, int over) {
        float k = start / 100.0f;
        float m = over / 100.0f;
        if (start >= over) {
            if (over > 80) {
                this.f3591a.setBackgroundResource(C0415R.drawable.assist_ani_progressbar_top_red);
                this.move_img.setBackgroundResource(C0415R.drawable.assist_ani_progressbar_bottom_red);
            } else {
                this.move_img.setBackgroundResource(C0415R.drawable.assist_ani_progressbar_bottom_green);
                this.f3591a.setBackgroundResource(C0415R.drawable.assist_ani_progressbar_top_green);
            }
        }
        ScaleAnimation localScaleAnimation1 = new ScaleAnimation(k, m, 1.0f, 1.0f, 1, 0.0f, 1, 0.0f);
        localScaleAnimation1.setFillAfter(true);
        localScaleAnimation1.setDuration(1000L);
        this.move_img.startAnimation(localScaleAnimation1);
    }
}
