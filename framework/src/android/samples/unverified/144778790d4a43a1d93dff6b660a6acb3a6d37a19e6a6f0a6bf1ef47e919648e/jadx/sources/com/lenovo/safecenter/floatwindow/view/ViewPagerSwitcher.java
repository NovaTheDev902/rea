package com.lenovo.safecenter.floatwindow.view;

import android.content.Context;
import android.content.SharedPreferences;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.LinearLayout;
import com.lenovo.safecenter.C0415R;

/* JADX INFO: loaded from: classes.dex */
public class ViewPagerSwitcher extends LinearLayout {
    public static final String PREF_SWITCHER_OR_RUNNING_FLAG = "switcher_or_running_flag";
    public static final String PREF_SWITCHER_SHOW_FLAG = "switcher_windwo_show";
    public static ViewPagerSwitcher instance;

    /* JADX INFO: renamed from: a */
    private View f3743a;

    /* JADX INFO: renamed from: b */
    private View f3744b;

    /* JADX INFO: renamed from: c */
    private View f3745c;

    /* JADX INFO: renamed from: d */
    private View f3746d;

    /* JADX INFO: renamed from: e */
    private SharedPreferences f3747e;

    /* JADX INFO: renamed from: f */
    private Context f3748f;

    /* JADX INFO: renamed from: g */
    private boolean f3749g;

    /* JADX INFO: renamed from: h */
    private Animation f3750h;

    /* JADX INFO: renamed from: i */
    private Animation f3751i;

    /* JADX INFO: renamed from: j */
    private Animation f3752j;

    /* JADX INFO: renamed from: k */
    private Animation f3753k;

    public ViewPagerSwitcher(Context context) {
        super(context);
        this.f3749g = true;
        this.f3750h = null;
        this.f3751i = null;
        instance = this;
        this.f3748f = context;
        setGravity(17);
        setOrientation(1);
        inflate(context, C0415R.layout.assist_page_process, this);
        this.f3743a = findViewById(C0415R.id.running_process_view);
        this.f3744b = findViewById(C0415R.id.switcher_view);
        this.f3745c = findViewById(C0415R.id.process_clear_view);
        this.f3746d = findViewById(C0415R.id.main_container);
        this.f3750h = AnimationUtils.loadAnimation(this.f3748f, C0415R.anim.assist_move_down_in);
        this.f3751i = AnimationUtils.loadAnimation(this.f3748f, C0415R.anim.assist_move_down);
        this.f3752j = AnimationUtils.loadAnimation(this.f3748f, C0415R.anim.assist_move_up_out);
        this.f3753k = AnimationUtils.loadAnimation(this.f3748f, C0415R.anim.assist_move_up);
        this.f3747e = this.f3748f.getSharedPreferences("switcher_or_running_flag", 0);
        this.f3749g = this.f3747e.getBoolean("switcher_windwo_show", true);
        showSwitcherorRunningWindow(this.f3749g, false);
    }

    public void showSwitcherorRunningWindow(boolean SwitcherwindowFlag, boolean fromClick) {
        if (SwitcherwindowFlag) {
            this.f3744b.setVisibility(0);
            this.f3743a.setVisibility(8);
            if (fromClick) {
                this.f3744b.startAnimation(this.f3750h);
                this.f3743a.startAnimation(this.f3751i);
                return;
            }
            return;
        }
        this.f3743a.setVisibility(0);
        this.f3744b.setVisibility(8);
        if (fromClick) {
            this.f3744b.startAnimation(this.f3752j);
            this.f3743a.startAnimation(this.f3753k);
        }
    }
}
