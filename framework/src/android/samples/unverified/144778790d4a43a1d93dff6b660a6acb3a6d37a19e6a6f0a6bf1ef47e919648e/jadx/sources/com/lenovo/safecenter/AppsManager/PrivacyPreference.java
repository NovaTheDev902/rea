package com.lenovo.safecenter.AppsManager;

import android.content.Context;
import android.preference.Preference;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;

/* JADX INFO: loaded from: classes.dex */
public class PrivacyPreference extends Preference {

    /* JADX INFO: renamed from: a */
    private Context f2344a;

    public PrivacyPreference(Context context, AttributeSet attrs) {
        super(context, attrs);
        this.f2344a = context;
    }

    public PrivacyPreference(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
        this.f2344a = context;
    }

    public PrivacyPreference(Context context) {
        super(context);
        this.f2344a = context;
    }

    @Override // android.preference.Preference
    protected View onCreateView(ViewGroup parent) {
        super.onCreateView(parent);
        View view = LayoutInflater.from(this.f2344a).inflate(C0415R.layout.title, (ViewGroup) null);
        TextView name = (TextView) view.findViewById(C0415R.id.txt_title);
        name.setText(C0415R.string.safemode_settings);
        return view;
    }
}
