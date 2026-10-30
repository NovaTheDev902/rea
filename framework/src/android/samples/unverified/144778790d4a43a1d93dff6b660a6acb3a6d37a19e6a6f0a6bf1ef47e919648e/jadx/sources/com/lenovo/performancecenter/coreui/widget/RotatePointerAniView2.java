package com.lenovo.performancecenter.coreui.widget;

import android.content.Context;
import android.graphics.Matrix;
import android.util.AttributeSet;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.ViewGroup;
import android.view.animation.Animation;
import android.view.animation.Transformation;
import android.widget.AbsoluteLayout;
import android.widget.ImageView;
import com.lenovo.safecenter.C0415R;

/* JADX INFO: loaded from: classes.dex */
public class RotatePointerAniView2 extends AbsoluteLayout {
    public static final int MAX_DEGREES = 240;

    /* JADX INFO: renamed from: a */
    private ImageView f1618a;

    /* JADX INFO: renamed from: b */
    private ImageView f1619b;

    /* JADX INFO: renamed from: c */
    private int f1620c;

    /* JADX INFO: renamed from: d */
    private int f1621d;

    /* JADX INFO: renamed from: e */
    private int f1622e;

    /* JADX INFO: renamed from: f */
    private RotateAnimation f1623f;

    /* JADX INFO: renamed from: g */
    private RotateAnimation f1624g;

    public RotatePointerAniView2(Context paramContext, AttributeSet paramAttributeSet) {
        super(paramContext, paramAttributeSet);
        this.f1620c = 2000;
        this.f1621d = 0;
        this.f1622e = 0;
        LayoutInflater.from(paramContext).inflate(C0415R.layout.rotate_pointer_ani_view2, (ViewGroup) this, true);
        this.f1618a = (ImageView) findViewById(C0415R.id.img_pointer_big);
        this.f1619b = (ImageView) findViewById(C0415R.id.img_pointer_small);
    }

    public boolean bpRotate(int toDegree) {
        RotateAnimation animation = this.f1623f;
        if (animation == null) {
            int centerX = this.f1618a.getWidth();
            int centerY = this.f1618a.getHeight() * 0;
            animation = new RotateAnimation(centerX, centerY);
            this.f1623f = animation;
            this.f1623f.setFillEnabled(true);
            this.f1623f.setFillAfter(true);
            animation.setAnimationListener(new Animation.AnimationListener() { // from class: com.lenovo.performancecenter.coreui.widget.RotatePointerAniView2.1
                @Override // android.view.animation.Animation.AnimationListener
                public final void onAnimationStart(Animation animation2) {
                    Log.i("rotate", "onAnimationStart");
                }

                @Override // android.view.animation.Animation.AnimationListener
                public final void onAnimationRepeat(Animation animation2) {
                }

                @Override // android.view.animation.Animation.AnimationListener
                public final void onAnimationEnd(Animation animation2) {
                    Log.i("rotate", "onAnimationEnd");
                }
            });
        }
        animation.setDegrees(this.f1621d, toDegree);
        int duration = (Math.abs(toDegree - this.f1621d) * this.f1620c) / MAX_DEGREES;
        this.f1623f.setDuration(duration);
        this.f1618a.startAnimation(this.f1623f);
        this.f1621d = toDegree;
        return true;
    }

    public boolean spRotate(int toDegree) {
        RotateAnimation animation = this.f1624g;
        if (animation == null) {
            int centerX = this.f1619b.getWidth();
            int centerY = this.f1619b.getHeight() * 0;
            animation = new RotateAnimation(centerX, centerY);
            this.f1624g = animation;
            this.f1624g.setFillEnabled(true);
            this.f1624g.setFillAfter(true);
            animation.setAnimationListener(new Animation.AnimationListener() { // from class: com.lenovo.performancecenter.coreui.widget.RotatePointerAniView2.2
                @Override // android.view.animation.Animation.AnimationListener
                public final void onAnimationStart(Animation animation2) {
                    Log.i("rotate", "onAnimationStart");
                }

                @Override // android.view.animation.Animation.AnimationListener
                public final void onAnimationRepeat(Animation animation2) {
                }

                @Override // android.view.animation.Animation.AnimationListener
                public final void onAnimationEnd(Animation animation2) {
                    Log.i("rotate", "onAnimationEnd");
                }
            });
        }
        animation.setDegrees(this.f1622e, toDegree);
        int duration = (Math.abs(toDegree - this.f1622e) * this.f1620c) / MAX_DEGREES;
        this.f1624g.setDuration(duration);
        this.f1619b.startAnimation(this.f1624g);
        this.f1622e = toDegree;
        return true;
    }

    public class RotateAnimation extends Animation {

        /* JADX INFO: renamed from: b */
        private int f1628b;

        /* JADX INFO: renamed from: c */
        private int f1629c;

        /* JADX INFO: renamed from: d */
        private float f1630d;

        /* JADX INFO: renamed from: e */
        private float f1631e;

        public RotateAnimation(int x, int y) {
            this.f1628b = 0;
            this.f1629c = 0;
            this.f1628b = x;
            this.f1629c = y;
        }

        public void setDegrees(int degreeFrom, int degreeTo) {
            this.f1630d = degreeFrom;
            this.f1631e = degreeTo;
        }

        @Override // android.view.animation.Animation
        protected void applyTransformation(float interpolatedTime, Transformation t) {
            float degrees = (this.f1631e - this.f1630d) * interpolatedTime;
            float gradual = this.f1630d + degrees;
            Matrix matrix = t.getMatrix();
            matrix.setRotate(gradual, this.f1628b, this.f1629c);
        }

        @Override // android.view.animation.Animation
        public void setAnimationListener(Animation.AnimationListener paramAnimationListener) {
            super.setAnimationListener(paramAnimationListener);
        }
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.coreui.widget.RotatePointerAniView2$qi */
    public class AnimationAnimationListenerC0155qi implements Animation.AnimationListener {
        public AnimationAnimationListenerC0155qi(RotatePointerAniView2 paramRotatePointerAniView) {
        }

        @Override // android.view.animation.Animation.AnimationListener
        public void onAnimationEnd(Animation paramAnimation) {
        }

        @Override // android.view.animation.Animation.AnimationListener
        public void onAnimationRepeat(Animation paramAnimation) {
        }

        @Override // android.view.animation.Animation.AnimationListener
        public void onAnimationStart(Animation paramAnimation) {
        }
    }
}
