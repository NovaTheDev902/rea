package com.lenovo.safecenter.lenovoAntiSpam.newview;

import android.os.Bundle;
import android.text.Editable;
import android.text.TextUtils;
import android.text.TextWatcher;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.phoneservice.LocationManager;

/* JADX INFO: loaded from: classes.dex */
public class NumberArea extends BaseTitleActivity {
    public static final String ERR_TAG = "NumberArea.java";

    /* JADX INFO: renamed from: a */
    EditText f3937a;

    /* JADX INFO: renamed from: b */
    TextView f3938b;

    /* JADX INFO: renamed from: c */
    ImageView f3939c;

    /* JADX INFO: renamed from: d */
    private LocationManager f3940d;

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.number_area);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.locale_phone_number, (Integer) null);
        this.f3940d = (LocationManager) ManagerCreator.getManager(LocationManager.class);
        this.f3937a = (EditText) findViewById(C0415R.id.number_editor);
        this.f3939c = (ImageView) findViewById(C0415R.id.img_find);
        this.f3938b = (TextView) findViewById(C0415R.id.number_text);
        this.f3937a.addTextChangedListener(new TextWatcher() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.NumberArea.1
            @Override // android.text.TextWatcher
            public final void onTextChanged(CharSequence s, int start, int before, int count) {
            }

            @Override // android.text.TextWatcher
            public final void beforeTextChanged(CharSequence s, int start, int count, int after) {
            }

            @Override // android.text.TextWatcher
            public final void afterTextChanged(Editable s) {
                String number = NumberArea.this.f3937a.getText().toString();
                if (!TextUtils.isEmpty(number)) {
                    String number2 = number.trim();
                    if (number2.length() > 0) {
                        String area = NumberArea.this.f3940d.getLocation(number2);
                        if (!TextUtils.isEmpty(area)) {
                            NumberArea.this.f3938b.setText(area);
                            return;
                        } else {
                            NumberArea.this.f3938b.setText("");
                            return;
                        }
                    }
                    return;
                }
                NumberArea.this.f3938b.setText("");
            }
        });
        this.f3939c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.NumberArea.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                String number = NumberArea.this.f3937a.getText().toString();
                if (!TextUtils.isEmpty(number)) {
                    String number2 = number.trim();
                    if (number2.length() > 0) {
                        String area = NumberArea.this.f3940d.getLocation(number2);
                        if (!TextUtils.isEmpty(area)) {
                            NumberArea.this.f3938b.setText(area);
                            return;
                        } else {
                            NumberArea.this.f3938b.setText(C0415R.string.no_record);
                            return;
                        }
                    }
                    return;
                }
                NumberArea.this.f3938b.setText("");
            }
        });
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            try {
                finish();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
