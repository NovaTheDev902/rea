package com.lenovo.safecenter.Laboratory;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;

/* JADX INFO: loaded from: classes.dex */
public class RootIntroduction extends Activity {
    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.rootintroduction_layout);
        ((TextView) findViewById(C0415R.id.txt_title)).setText(C0415R.string.root);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.RootIntroduction.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                RootIntroduction.this.finish();
            }
        });
    }
}
