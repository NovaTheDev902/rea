package com.lenovo.safecenter.MainTab;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.tencent.tmsecure.utils.Log;

/* JADX INFO: loaded from: classes.dex */
public class QuestionAndAnswer extends Activity {

    /* JADX INFO: renamed from: a */
    TextView f2783a;

    /* JADX INFO: renamed from: b */
    TextView f2784b;

    /* JADX INFO: renamed from: c */
    TextView f2785c;

    /* JADX INFO: renamed from: d */
    TextView f2786d;

    /* JADX INFO: renamed from: e */
    TextView f2787e;

    /* JADX INFO: renamed from: f */
    TextView f2788f;

    /* JADX INFO: renamed from: g */
    TextView f2789g;

    /* JADX INFO: renamed from: h */
    TextView f2790h;

    /* JADX INFO: renamed from: i */
    TextView f2791i;

    /* JADX INFO: renamed from: j */
    TextView f2792j;

    /* JADX INFO: renamed from: k */
    TextView f2793k;

    /* JADX INFO: renamed from: l */
    TextView f2794l;

    /* JADX INFO: renamed from: m */
    TextView f2795m;

    /* JADX INFO: renamed from: n */
    TextView f2796n;

    /* JADX INFO: renamed from: o */
    LinearLayout f2797o;

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.questionandanswer);
        ((TextView) findViewById(C0415R.id.txt_title)).setText(C0415R.string.help);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.MainTab.QuestionAndAnswer.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                QuestionAndAnswer.this.finish();
            }
        });
        this.f2783a = (TextView) findViewById(C0415R.id.question1);
        this.f2784b = (TextView) findViewById(C0415R.id.question2);
        this.f2785c = (TextView) findViewById(C0415R.id.question3);
        this.f2786d = (TextView) findViewById(C0415R.id.question4);
        this.f2787e = (TextView) findViewById(C0415R.id.question5);
        this.f2788f = (TextView) findViewById(C0415R.id.question6);
        this.f2789g = (TextView) findViewById(C0415R.id.question7);
        this.f2790h = (TextView) findViewById(C0415R.id.answer1);
        this.f2791i = (TextView) findViewById(C0415R.id.answer2);
        this.f2792j = (TextView) findViewById(C0415R.id.answer3);
        this.f2793k = (TextView) findViewById(C0415R.id.answer4);
        this.f2794l = (TextView) findViewById(C0415R.id.answer5);
        this.f2795m = (TextView) findViewById(C0415R.id.answer6);
        this.f2796n = (TextView) findViewById(C0415R.id.answer7);
        this.f2797o = (LinearLayout) findViewById(C0415R.id.line8);
        if (!TrafficStatsService.nacServerIsExist()) {
            Log.m2636i("ydp", "3rd--------.");
            this.f2783a.setText(C0415R.string.question1_3rd);
            this.f2784b.setText(C0415R.string.question2_3rd);
            this.f2785c.setText(C0415R.string.question3_3rd);
            this.f2786d.setText(C0415R.string.question4_3rd);
            this.f2787e.setText(C0415R.string.question5_3rd);
            this.f2788f.setText(C0415R.string.question6_3rd);
            this.f2789g.setVisibility(8);
            this.f2790h.setText(C0415R.string.answer1_3rd);
            this.f2791i.setText(C0415R.string.answer2_3rd);
            this.f2792j.setText(C0415R.string.answer3_3rd);
            this.f2793k.setText(C0415R.string.answer4_3rd);
            this.f2794l.setText(C0415R.string.answer5_3rd);
            this.f2795m.setText(C0415R.string.answer6_3rd);
            this.f2796n.setVisibility(8);
            this.f2797o.setVisibility(8);
        }
    }
}
