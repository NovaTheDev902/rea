package com.lenovo.safecenter.floatwindow.view;

import android.content.Context;
import android.content.res.TypedArray;
import android.util.AttributeSet;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;

/* JADX INFO: loaded from: classes.dex */
public class SwitcherItemView extends LinearLayout {

    /* JADX INFO: renamed from: a */
    private ImageView f3740a;

    /* JADX INFO: renamed from: b */
    private TextView f3741b;

    /* JADX INFO: renamed from: c */
    private Context f3742c;

    public SwitcherItemView(Context context, AttributeSet paramAttributeSet) {
        super(context, paramAttributeSet);
        this.f3742c = context;
        inflate(context, C0415R.layout.assist_switcher_item, this);
        setBackgroundResource(C0415R.drawable.assist_selector_switcher_item_bg);
        setDuplicateParentStateEnabled(false);
        setOrientation(1);
        setGravity(17);
        setClickable(true);
        this.f3740a = (ImageView) findViewById(C0415R.id.switch_icon);
        this.f3741b = (TextView) findViewById(C0415R.id.switch_label);
        if (paramAttributeSet != null) {
            TypedArray typedArray = context.obtainStyledAttributes(paramAttributeSet, C0415R.styleable.switcher);
            this.f3741b.setText(typedArray.getString(1));
            this.f3740a.setImageResource(typedArray.getResourceId(0, -1));
            typedArray.recycle();
        }
    }

    public void setImage(int drawableId) {
        this.f3740a.setImageResource(drawableId);
    }

    public void setLabelColor(int drawableId) {
        this.f3741b.setTextColor(drawableId);
    }
}
