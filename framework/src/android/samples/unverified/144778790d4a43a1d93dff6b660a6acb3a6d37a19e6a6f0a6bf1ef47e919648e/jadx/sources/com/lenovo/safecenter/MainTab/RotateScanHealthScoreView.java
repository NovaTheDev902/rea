package com.lenovo.safecenter.MainTab;

import android.content.Context;
import android.os.Handler;
import android.os.Message;
import android.util.AttributeSet;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.ViewGroup;
import android.view.animation.LinearInterpolator;
import android.view.animation.RotateAnimation;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;

/* JADX INFO: loaded from: classes.dex */
public class RotateScanHealthScoreView extends FrameLayout {

    /* JADX INFO: renamed from: a */
    private ImageView f2799a;

    /* JADX INFO: renamed from: b */
    private RotateAnimation f2800b;

    /* JADX INFO: renamed from: c */
    private Handler f2801c;

    /* JADX INFO: renamed from: d */
    private int f2802d;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1264a(RotateScanHealthScoreView x0) {
        float width = x0.f2799a.getWidth() / 2.0f;
        float height = x0.f2799a.getHeight() / 2.0f;
        Log.i("wu0wu", "f1=" + width + ",f2=" + height);
        RotateAnimation rotateAnimation = new RotateAnimation(0.0f, -360.0f, width, height);
        x0.f2800b = rotateAnimation;
        x0.f2800b.setFillEnabled(true);
        x0.f2800b.setFillAfter(true);
        x0.f2800b.setDuration(500L);
        x0.f2800b.setRepeatCount(-1);
        x0.f2800b.setInterpolator(new LinearInterpolator());
        x0.f2799a.setVisibility(0);
        x0.f2799a.startAnimation(rotateAnimation);
        x0.f2799a.setImageResource(C0415R.drawable.healthcheckup_score_ring);
    }

    /* JADX INFO: renamed from: b */
    static /* synthetic */ void m1265b(RotateScanHealthScoreView x0) {
        if (x0.f2802d < 0) {
            x0.f2802d = 0;
        }
        TextView textView = (TextView) x0.findViewById(C0415R.id.health_score);
        textView.setText(String.valueOf(x0.f2802d));
        if (x0.f2802d >= 100) {
            textView.setTextColor(x0.getResources().getColor(C0415R.color.green3));
            return;
        }
        if (x0.f2802d >= 85 && x0.f2802d <= 99) {
            textView.setTextColor(x0.getResources().getColor(C0415R.color.green3));
        } else if (x0.f2802d < 60 || x0.f2802d > 84) {
            textView.setTextColor(x0.getResources().getColor(C0415R.color.red1));
        } else {
            textView.setTextColor(x0.getResources().getColor(C0415R.color.orange1));
        }
    }

    public RotateScanHealthScoreView(Context paramContext, AttributeSet paramAttributeSet) {
        super(paramContext, paramAttributeSet);
        aja localaja = new aja(this);
        this.f2801c = localaja;
        ImageView localImageView = (ImageView) ((FrameLayout) LayoutInflater.from(paramContext).inflate(C0415R.layout.health_score_rotate_scan_view, (ViewGroup) this, true)).findViewById(C0415R.id.img_healthcheckup_score_ring);
        localImageView.setImageResource(C0415R.drawable.healthcheckup_score_ring);
        this.f2799a = localImageView;
    }

    public void stopAnim() {
        this.f2799a.clearAnimation();
        this.f2799a.setImageResource(C0415R.drawable.healthcheckup_score_ring_stop);
    }

    public void beginAnim() {
        if (this.f2800b == null) {
            this.f2801c.sendEmptyMessageDelayed(0, 200L);
            return;
        }
        RotateAnimation localRotateAnimation = this.f2800b;
        this.f2799a.startAnimation(localRotateAnimation);
        this.f2799a.setImageResource(C0415R.drawable.healthcheckup_score_ring);
    }

    public class aja extends Handler {
        public aja(RotateScanHealthScoreView paramRotateScanAniView) {
        }

        @Override // android.os.Handler
        public void handleMessage(Message paramMessage) {
            super.handleMessage(paramMessage);
            switch (paramMessage.what) {
                case 0:
                    RotateScanHealthScoreView.m1264a(RotateScanHealthScoreView.this);
                    break;
                case 1:
                    RotateScanHealthScoreView.m1265b(RotateScanHealthScoreView.this);
                    break;
            }
        }
    }

    public void refreshHealthScore(int score) {
        this.f2802d = score;
        this.f2801c.sendEmptyMessage(1);
    }
}
