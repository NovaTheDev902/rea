package com.lenovo.safecenter.floatwindow.listener;

import android.content.Context;
import android.content.Intent;
import android.util.Log;
import android.view.animation.Animation;
import android.view.animation.ScaleAnimation;
import com.lenovo.safecenter.floatwindow.view.ClearProcessBar;
import com.lenovo.safecenter.floatwindow.view.ProcessClearView;
import com.lenovo.safecenter.floatwindow.view.ProcessRunningView;

/* JADX INFO: loaded from: classes.dex */
public class ClearProcessListener implements Animation.AnimationListener {

    /* JADX INFO: renamed from: a */
    private ClearProcessBar f3566a;

    /* JADX INFO: renamed from: b */
    private float f3567b;

    /* JADX INFO: renamed from: c */
    private int f3568c;

    /* JADX INFO: renamed from: d */
    private int f3569d;

    /* JADX INFO: renamed from: e */
    private Context f3570e;

    public ClearProcessListener(ClearProcessBar _clProcessBar, Context context, int overRate, int clearAfterSize) {
        this.f3566a = _clProcessBar;
        this.f3570e = context;
        this.f3567b = overRate / 100.0f;
        this.f3568c = clearAfterSize;
        this.f3569d = overRate;
    }

    @Override // android.view.animation.Animation.AnimationListener
    public void onAnimationEnd(Animation animation) {
        Log.d("onAnimationEnd", "onAnimationEnd");
        ScaleAnimation localScaleAnimation = new ScaleAnimation(0.0f, this.f3567b, 1.0f, 1.0f, 1, 0.0f, 1, 0.0f);
        localScaleAnimation.setDuration(1000L);
        localScaleAnimation.setFillAfter(true);
        this.f3566a.move_img.startAnimation(localScaleAnimation);
        localScaleAnimation.setAnimationListener(new AnimationAnimationListenerC0558a(this, (byte) 0));
    }

    @Override // android.view.animation.Animation.AnimationListener
    public void onAnimationRepeat(Animation animation) {
    }

    @Override // android.view.animation.Animation.AnimationListener
    public void onAnimationStart(Animation animation) {
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.floatwindow.listener.ClearProcessListener$a */
    private class AnimationAnimationListenerC0558a implements Animation.AnimationListener {
        private AnimationAnimationListenerC0558a() {
        }

        /* synthetic */ AnimationAnimationListenerC0558a(ClearProcessListener x0, byte b) {
            this();
        }

        /* JADX WARN: Type inference failed for: r0v2, types: [com.lenovo.safecenter.floatwindow.listener.ClearProcessListener$a$1] */
        @Override // android.view.animation.Animation.AnimationListener
        public final void onAnimationEnd(Animation animation) {
            ProcessClearView.instanceClearView.showClearOverView(ClearProcessListener.this.f3568c, ClearProcessListener.this.f3569d);
            ProcessRunningView.processrunning.clear_view();
            new Thread() { // from class: com.lenovo.safecenter.floatwindow.listener.ClearProcessListener.a.1
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    try {
                        Thread.sleep(2000L);
                        Intent intent = new Intent();
                        intent.setAction("com.lenovo.safecenter.floatwindow.delwindow");
                        ClearProcessListener.this.f3570e.sendBroadcast(intent);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }.start();
        }

        @Override // android.view.animation.Animation.AnimationListener
        public final void onAnimationRepeat(Animation animation) {
        }

        @Override // android.view.animation.Animation.AnimationListener
        public final void onAnimationStart(Animation animation) {
        }
    }
}
