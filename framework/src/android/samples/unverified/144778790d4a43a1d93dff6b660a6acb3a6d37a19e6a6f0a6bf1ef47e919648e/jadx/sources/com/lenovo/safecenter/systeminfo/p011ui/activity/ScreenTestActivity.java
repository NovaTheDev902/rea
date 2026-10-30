package com.lenovo.safecenter.systeminfo.p011ui.activity;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import com.lenovo.safecenter.C0415R;

/* JADX INFO: loaded from: classes.dex */
public class ScreenTestActivity extends Activity {

    /* JADX INFO: renamed from: a */
    int f5665a = 0;

    /* JADX INFO: renamed from: b */
    private Button f5666b;

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        requestWindowFeature(1);
        getWindow().setFlags(1024, 1024);
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.screen_test);
        this.f5666b = (Button) findViewById(C0415R.id.btn_screen_test);
        this.f5666b.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.systeminfo.ui.activity.ScreenTestActivity.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                ScreenTestActivity.this.f5665a++;
                switch (ScreenTestActivity.this.f5665a) {
                    case 1:
                        ScreenTestActivity.this.f5666b.setBackgroundColor(-65536);
                        break;
                    case 2:
                        ScreenTestActivity.this.f5666b.setBackgroundColor(-16711936);
                        break;
                    case 3:
                        ScreenTestActivity.this.f5666b.setBackgroundColor(-16776961);
                        break;
                    case 4:
                        ScreenTestActivity.this.f5666b.setBackgroundColor(C0415R.color.screen_test_fianl);
                        break;
                    case 5:
                        ScreenTestActivity.this.finish();
                        break;
                }
            }
        });
    }
}
