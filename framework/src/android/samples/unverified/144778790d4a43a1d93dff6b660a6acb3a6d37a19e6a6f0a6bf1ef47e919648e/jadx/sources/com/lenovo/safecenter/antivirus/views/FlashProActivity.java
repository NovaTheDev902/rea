package com.lenovo.safecenter.antivirus.views;

import android.app.Activity;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Movie;
import android.graphics.Paint;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.os.SystemClock;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.LinearLayout;
import android.widget.TextView;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.TrackEvent;
import java.io.InputStream;

/* JADX INFO: loaded from: classes.dex */
public class FlashProActivity extends Activity {

    /* JADX INFO: renamed from: a */
    LinearLayout f3111a;
    protected Animation animation;
    protected Animation animation2;

    /* JADX INFO: renamed from: b */
    TextView f3112b;

    /* JADX INFO: renamed from: c */
    TextView f3113c;

    /* JADX INFO: renamed from: d */
    TextView f3114d;

    /* JADX INFO: renamed from: e */
    TextView f3115e;

    /* JADX INFO: renamed from: f */
    private Handler f3116f = new Handler() { // from class: com.lenovo.safecenter.antivirus.views.FlashProActivity.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            FlashProActivity.this.f3112b.setVisibility(8);
        }
    };

    /* JADX WARN: Type inference failed for: r2v23, types: [com.lenovo.safecenter.antivirus.views.FlashProActivity$2] */
    @Override // android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(1);
        getWindow().setFlags(1024, 1024);
        setContentView(C0415R.layout.antivirusgifmain);
        this.f3111a = (LinearLayout) findViewById(C0415R.id.antivirusanim_layout);
        this.f3112b = (TextView) findViewById(C0415R.id.antivirustxt_info1);
        this.f3113c = (TextView) findViewById(C0415R.id.antivirustxt_info3);
        this.f3114d = (TextView) findViewById(C0415R.id.antivirustxt_info4);
        this.f3115e = (TextView) findViewById(C0415R.id.antivirustxt_info5);
        this.animation = AnimationUtils.loadAnimation(this, C0415R.anim.alpha_scale_translate);
        this.animation2 = AnimationUtils.loadAnimation(this, C0415R.anim.my_alpha_action);
        View view = new C0468a(this);
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(480, -2);
        params.gravity = 1;
        this.f3111a.addView(view, params);
        new Thread() { // from class: com.lenovo.safecenter.antivirus.views.FlashProActivity.2
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                FlashProActivity.this.f3112b.startAnimation(FlashProActivity.this.animation);
                FlashProActivity.this.f3113c.startAnimation(FlashProActivity.this.animation2);
                FlashProActivity.this.f3114d.startAnimation(FlashProActivity.this.animation2);
                FlashProActivity.this.f3115e.startAnimation(FlashProActivity.this.animation2);
                try {
                    Thread.sleep(C0092c.f1328ap);
                    FlashProActivity.this.f3116f.sendEmptyMessage(0);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        super.onResume();
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.FlashProActivity$a */
    private class C0468a extends View {

        /* JADX INFO: renamed from: b */
        private Movie f3120b;

        /* JADX INFO: renamed from: c */
        private long f3121c;

        public C0468a(Context context) {
            super(context);
            setFocusable(true);
            InputStream is = context.getResources().openRawResource(C0415R.drawable.antivirussmileface);
            this.f3120b = Movie.decodeStream(is);
        }

        @Override // android.view.View
        protected final void onDraw(Canvas canvas) {
            Paint p = new Paint();
            p.setAntiAlias(true);
            long now = SystemClock.uptimeMillis();
            if (this.f3121c == 0) {
                this.f3121c = now;
            }
            if (this.f3120b != null) {
                int dur = this.f3120b.duration();
                if (dur == 0) {
                    dur = 1000;
                }
                int relTime = (int) ((now - this.f3121c) % ((long) dur));
                if (relTime >= dur) {
                    this.f3120b = null;
                    return;
                }
                this.f3120b.setTime(relTime);
                this.f3120b.draw(canvas, 0.0f, 0.0f);
                invalidate();
            }
        }
    }
}
