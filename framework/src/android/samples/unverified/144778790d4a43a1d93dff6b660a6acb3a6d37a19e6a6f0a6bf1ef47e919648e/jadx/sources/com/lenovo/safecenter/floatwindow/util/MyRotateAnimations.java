package com.lenovo.safecenter.floatwindow.util;

import android.content.Context;
import android.view.ViewGroup;
import android.view.animation.Animation;
import android.view.animation.AnticipateInterpolator;
import android.view.animation.OvershootInterpolator;
import android.view.animation.RotateAnimation;
import android.view.animation.TranslateAnimation;
import android.widget.ImageButton;

/* JADX INFO: loaded from: classes.dex */
public class MyRotateAnimations {

    /* JADX INFO: renamed from: a */
    private static int f3580a = 15;

    /* JADX INFO: renamed from: b */
    private static int f3581b = -13;

    public static void initOffset(Context context) {
        f3580a = (int) (10.667d * ((double) context.getResources().getDisplayMetrics().density));
        f3581b = -((int) (8.667d * ((double) context.getResources().getDisplayMetrics().density)));
    }

    public static Animation getRotateAnimation(float fromDegrees, float toDegrees, int durationMillis) {
        RotateAnimation rotate = new RotateAnimation(fromDegrees, toDegrees, 1, 0.5f, 1, 0.5f);
        rotate.setDuration(durationMillis);
        rotate.setFillAfter(true);
        return rotate;
    }

    public static void startAnimationsIn(ViewGroup viewgroup, int durationMillis) {
        for (int i = 0; i < viewgroup.getChildCount(); i++) {
            ImageButton inoutimagebutton = (ImageButton) viewgroup.getChildAt(i);
            inoutimagebutton.setVisibility(0);
            ViewGroup.MarginLayoutParams mlp = (ViewGroup.MarginLayoutParams) inoutimagebutton.getLayoutParams();
            Animation animation = new TranslateAnimation(mlp.rightMargin - f3580a, 0.0f, f3581b + mlp.bottomMargin, 0.0f);
            animation.setFillAfter(true);
            animation.setDuration(durationMillis);
            animation.setStartOffset((i * 100) / (viewgroup.getChildCount() - 1));
            animation.setInterpolator(new OvershootInterpolator(2.0f));
            inoutimagebutton.startAnimation(animation);
        }
    }

    public static void startAnimationsOut(ViewGroup viewgroup, int durationMillis) {
        for (int i = 0; i < viewgroup.getChildCount(); i++) {
            final ImageButton inoutimagebutton = (ImageButton) viewgroup.getChildAt(i);
            ViewGroup.MarginLayoutParams mlp = (ViewGroup.MarginLayoutParams) inoutimagebutton.getLayoutParams();
            Animation animation = new TranslateAnimation(0.0f, mlp.rightMargin - f3580a, 0.0f, f3581b + mlp.bottomMargin);
            animation.setFillAfter(true);
            animation.setDuration(durationMillis);
            animation.setStartOffset(((viewgroup.getChildCount() - i) * 100) / (viewgroup.getChildCount() - 1));
            animation.setInterpolator(new AnticipateInterpolator(2.0f));
            animation.setAnimationListener(new Animation.AnimationListener() { // from class: com.lenovo.safecenter.floatwindow.util.MyRotateAnimations.1
                @Override // android.view.animation.Animation.AnimationListener
                public final void onAnimationStart(Animation arg0) {
                }

                @Override // android.view.animation.Animation.AnimationListener
                public final void onAnimationRepeat(Animation arg0) {
                }

                @Override // android.view.animation.Animation.AnimationListener
                public final void onAnimationEnd(Animation arg0) {
                    inoutimagebutton.setVisibility(8);
                }
            });
            inoutimagebutton.startAnimation(animation);
        }
    }
}
