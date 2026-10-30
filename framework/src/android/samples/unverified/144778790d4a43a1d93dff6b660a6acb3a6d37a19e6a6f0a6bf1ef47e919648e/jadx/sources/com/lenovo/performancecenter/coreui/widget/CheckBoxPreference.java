package com.lenovo.performancecenter.coreui.widget;

import android.content.Context;
import android.content.res.TypedArray;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.LinearLayout;
import com.lenovo.safecenter.C0415R;

/* JADX INFO: loaded from: classes.dex */
public class CheckBoxPreference extends LinearLayout {

    /* JADX INFO: renamed from: a */
    private boolean f1614a;

    /* JADX INFO: renamed from: b */
    private ImageView f1615b;

    /* JADX INFO: renamed from: c */
    private OnCheckedChangeListener f1616c;

    public interface OnCheckedChangeListener {
        void onCheckedChanged(CheckBoxPreference checkBoxPreference, boolean z);
    }

    public CheckBoxPreference(Context paramContext, AttributeSet paramAttributeSet) {
        super(paramContext, paramAttributeSet);
        LinearLayout layout = (LinearLayout) LayoutInflater.from(paramContext).inflate(C0415R.layout.preference_checkbox, (ViewGroup) this, true);
        this.f1615b = (ImageView) findViewById(C0415R.id.preference_child_icon);
        TypedArray localTypedArray = paramContext.obtainStyledAttributes(paramAttributeSet, C0415R.styleable.buttonCheck);
        this.f1614a = localTypedArray.getBoolean(0, true);
        m571a();
        layout.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.performancecenter.coreui.widget.CheckBoxPreference.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (CheckBoxPreference.this.f1614a) {
                    CheckBoxPreference.this.f1614a = false;
                    CheckBoxPreference.this.f1615b.setBackgroundResource(C0415R.drawable.btn_off);
                } else {
                    CheckBoxPreference.this.f1614a = true;
                    CheckBoxPreference.this.f1615b.setBackgroundResource(C0415R.drawable.btn_on);
                }
                CheckBoxPreference.this.f1616c.onCheckedChanged(CheckBoxPreference.this, CheckBoxPreference.this.f1614a);
            }
        });
    }

    public void setEnableed(boolean flag) {
        this.f1614a = flag;
        m571a();
    }

    /* JADX INFO: renamed from: a */
    private void m571a() {
        if (this.f1614a) {
            this.f1615b.setBackgroundResource(C0415R.drawable.btn_on);
        } else {
            this.f1615b.setBackgroundResource(C0415R.drawable.btn_off);
        }
    }

    public void setOnCheckedChangeListener(OnCheckedChangeListener listener) {
        this.f1616c = listener;
    }
}
