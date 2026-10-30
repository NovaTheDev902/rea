package com.lenovo.safecenter.floatwindow.view;

import android.content.Context;
import android.os.Handler;
import android.os.Message;
import android.util.AttributeSet;
import android.widget.LinearLayout;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;

/* JADX INFO: loaded from: classes.dex */
public class CommonLoadingAnim extends LinearLayout {
    public static final int CONTINUE_ANIM = 1;
    public static final int START_ANIM = 0;

    /* JADX INFO: renamed from: a */
    private Context f3593a;

    /* JADX INFO: renamed from: b */
    private Handler f3594b;

    /* JADX INFO: renamed from: c */
    private TextView f3595c;

    /* JADX INFO: renamed from: d */
    private TextView f3596d;

    public CommonLoadingAnim(Context context, AttributeSet attrs) {
        super(context, attrs);
        this.f3593a = context;
        inflate(this.f3593a, C0415R.layout.common_loading_anim, this);
        setOrientation(1);
        setGravity(17);
        this.f3594b = new HandlerC0561a(this, (byte) 0);
        this.f3595c = (TextView) findViewById(C0415R.id.loading_text);
        this.f3596d = (TextView) findViewById(C0415R.id.loading_symbol);
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.floatwindow.view.CommonLoadingAnim$a */
    private class HandlerC0561a extends Handler {
        private HandlerC0561a() {
        }

        /* synthetic */ HandlerC0561a(CommonLoadingAnim x0, byte b) {
            this();
        }

        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            super.handleMessage(msg);
            StringBuffer buffer = new StringBuffer();
            switch (msg.what) {
                case 0:
                    CommonLoadingAnim.this.f3595c.setText(CommonLoadingAnim.this.getResources().getString(C0415R.string.common_loading_text));
                    buffer.append(".");
                    int intSym = msg.arg1 % 3;
                    for (int i = 0; i < intSym; i++) {
                        buffer.append(".");
                    }
                    CommonLoadingAnim.this.f3596d.setText(buffer.toString());
                    CommonLoadingAnim.this.f3594b.sendMessageDelayed(CommonLoadingAnim.this.f3594b.obtainMessage(0, intSym + 1, 0), 300L);
                    break;
            }
        }
    }

    @Override // android.view.View
    protected void onWindowVisibilityChanged(int visibility) {
        super.onWindowVisibilityChanged(visibility);
        if (visibility == 0) {
            this.f3594b.sendMessage(this.f3594b.obtainMessage(0, 0, 0));
        }
    }
}
