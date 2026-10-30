package com.lenovo.safecenter.shortcut;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.graphics.drawable.ClipDrawable;
import android.os.Handler;
import android.os.Message;
import android.text.Html;
import android.text.format.Formatter;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.view.animation.Transformation;
import android.widget.AbsoluteLayout;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.TextView;
import com.lenovo.performancecenter.coreui.util.MemoryTools;
import com.lenovo.performancecenter.coreui.util.RootPassage;
import com.lenovo.performancecenter.coreui.util.Utils;
import com.lenovo.performancecenter.performance.PerfWhitelistActivity;
import com.lenovo.performancecenter.performance.ScanApplicationInfo;
import com.lenovo.performancecenter.service.object.KillAllPackageReceiver;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.MainTab.SplashActivity;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/* JADX INFO: loaded from: classes.dex */
public class ClearnView extends LinearLayout {
    public static final String ONEKEY_LAUNCHER = "onekey_launcher";
    public static final String ONEKEY_SHORTCUT = "shortcut";
    public static final String ONEKEY_WIDGET = "widget";

    /* JADX INFO: renamed from: A */
    private RelativeLayout f5333A;

    /* JADX INFO: renamed from: B */
    private int f5334B;

    /* JADX INFO: renamed from: C */
    private int[] f5335C;

    /* JADX INFO: renamed from: a */
    private boolean f5336a;

    /* JADX INFO: renamed from: b */
    private long f5337b;

    /* JADX INFO: renamed from: c */
    private int f5338c;

    /* JADX INFO: renamed from: d */
    private Handler f5339d;

    /* JADX INFO: renamed from: e */
    private Animation.AnimationListener f5340e;

    /* JADX INFO: renamed from: f */
    private View.OnClickListener f5341f;

    /* JADX INFO: renamed from: g */
    private Context f5342g;

    /* JADX INFO: renamed from: h */
    private Animation f5343h;

    /* JADX INFO: renamed from: i */
    private Animation f5344i;

    /* JADX INFO: renamed from: j */
    private Animation f5345j;

    /* JADX INFO: renamed from: k */
    private C0969a f5346k;

    /* JADX INFO: renamed from: l */
    private ImageView f5347l;

    /* JADX INFO: renamed from: m */
    private TextView f5348m;

    /* JADX INFO: renamed from: n */
    private ImageView f5349n;

    /* JADX INFO: renamed from: o */
    private ClipDrawable f5350o;

    /* JADX INFO: renamed from: p */
    private ViewGroup f5351p;

    /* JADX INFO: renamed from: q */
    private ViewGroup f5352q;

    /* JADX INFO: renamed from: r */
    private TextView f5353r;

    /* JADX INFO: renamed from: s */
    private TextView f5354s;

    /* JADX INFO: renamed from: t */
    private TextView f5355t;

    /* JADX INFO: renamed from: u */
    private TextView f5356u;

    /* JADX INFO: renamed from: v */
    private boolean f5357v;

    /* JADX INFO: renamed from: w */
    private HandlerC0970b f5358w;

    /* JADX INFO: renamed from: x */
    private Button f5359x;

    /* JADX INFO: renamed from: y */
    private Button f5360y;

    /* JADX INFO: renamed from: z */
    private RelativeLayout f5361z;

    public interface WriteText {
        /* JADX INFO: renamed from: a */
        void m2223a(TextView textView);
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m2191a(ClearnView x0, TextView x1, TextView x2, Button x3) {
        int i = x0.f5335C[0];
        int i2 = x0.f5335C[1];
        x3.setOnClickListener(x0.f5341f);
        if (x0.f5337b <= Utils.CLICK_INTERVAL && x0.f5337b >= 0) {
            x1.setText(x0.f5342g.getString(C0415R.string.one_key_widget_clear_just_done1));
            x2.setText(x0.f5342g.getString(C0415R.string.one_key_widget_clear_just_done2));
        } else if (i == 0) {
            x1.setText(x0.f5342g.getString(C0415R.string.one_key_widget_clear_just_done1));
            x2.setText(x0.f5342g.getString(C0415R.string.one_key_widget_clear_just_done2));
        } else {
            x1.setText(Html.fromHtml(x0.f5342g.getString(C0415R.string.one_key_widget_clear_app_count, Integer.valueOf(i))));
            x2.setText(Html.fromHtml(x0.f5342g.getString(C0415R.string.one_key_widget_clear_app_size, Formatter.formatFileSize(x0.f5342g, i2))));
        }
    }

    /* JADX INFO: renamed from: d */
    static /* synthetic */ void m2200d(ClearnView x0) {
        final int i;
        Log.i("OPTI", System.currentTimeMillis() + " ---> start");
        MemoryTools memoryTools = new MemoryTools();
        if (x0.f5337b > Utils.CLICK_INTERVAL || x0.f5337b < 0 || x0.f5338c != 3) {
            x0.f5334B = memoryTools.getSystemMeminfo();
        } else {
            x0.f5334B = Utils.getEndMemory(x0.f5342g);
        }
        x0.f5348m.setText(x0.f5334B + "%");
        x0.f5335C = x0.m2195a(x0.f5358w);
        long totalMemory = ((long) ((x0.f5335C[1] / 1024) * 100)) / memoryTools.getTotalMemory();
        if (x0.f5337b > Utils.CLICK_INTERVAL || x0.f5337b < 0) {
            i = x0.f5334B - ((int) totalMemory);
            if (i < 0) {
                i = 0;
            }
        } else {
            i = x0.f5334B;
        }
        Utils.recordEndMemory(x0.f5342g, i);
        Log.i("CleanView", "mScale == " + x0.f5334B + " ----  endScale == " + i);
        final int i2 = 800 / (x0.f5334B + i);
        new Thread(new Runnable() { // from class: com.lenovo.safecenter.shortcut.ClearnView.4
            @Override // java.lang.Runnable
            public final void run() {
                Message msg1 = new Message();
                msg1.what = 1;
                msg1.arg1 = ClearnView.this.f5334B * 100;
                msg1.arg2 = ClearnView.this.f5334B;
                ClearnView.this.f5358w.sendMessage(msg1);
                try {
                    Thread.sleep(500L);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                while (ClearnView.this.f5334B > 0) {
                    ClearnView.m2217u(ClearnView.this);
                    Message msg = new Message();
                    msg.what = 1;
                    msg.arg1 = ClearnView.this.f5334B * 100;
                    msg.arg2 = ClearnView.this.f5334B;
                    ClearnView.this.f5358w.sendMessage(msg);
                    try {
                        Thread.sleep(i2);
                    } catch (InterruptedException e2) {
                        e2.printStackTrace();
                    }
                }
                while (ClearnView.this.f5334B < i) {
                    ClearnView.m2218v(ClearnView.this);
                    Message msg2 = new Message();
                    msg2.what = 1;
                    msg2.arg1 = ClearnView.this.f5334B * 100;
                    msg2.arg2 = ClearnView.this.f5334B;
                    ClearnView.this.f5358w.sendMessage(msg2);
                    try {
                        Thread.sleep(i2);
                    } catch (InterruptedException e3) {
                        e3.printStackTrace();
                    }
                }
            }
        }).start();
        x0.f5347l.setAnimation(x0.f5344i);
        x0.f5344i.start();
    }

    /* JADX INFO: renamed from: u */
    static /* synthetic */ int m2217u(ClearnView x0) {
        int i = x0.f5334B - 1;
        x0.f5334B = i;
        return i;
    }

    /* JADX INFO: renamed from: v */
    static /* synthetic */ int m2218v(ClearnView x0) {
        int i = x0.f5334B + 1;
        x0.f5334B = i;
        return i;
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: b */
    public static boolean m2197b(Context context) {
        SharedPreferences sp = context.getSharedPreferences("antitheft", 0);
        try {
            boolean isFirst = sp.getBoolean("help" + context.getPackageManager().getPackageInfo(context.getPackageName(), 0).versionCode, true);
            return isFirst;
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
            return true;
        }
    }

    public ClearnView(Context context) {
        super(context);
        this.f5336a = false;
        this.f5338c = 0;
        this.f5339d = new Handler() { // from class: com.lenovo.safecenter.shortcut.ClearnView.1
            @Override // android.os.Handler
            public final void handleMessage(Message msg) {
                super.handleMessage(msg);
                if (msg.what == 0 && !ClearnView.this.f5336a) {
                    ViewManager.removeView(ClearnView.this.f5342g, ClearnView.this);
                }
            }
        };
        this.f5340e = new Animation.AnimationListener() { // from class: com.lenovo.safecenter.shortcut.ClearnView.2
            @Override // android.view.animation.Animation.AnimationListener
            public final void onAnimationStart(Animation animation) {
            }

            @Override // android.view.animation.Animation.AnimationListener
            public final void onAnimationRepeat(Animation animation) {
            }

            @Override // android.view.animation.Animation.AnimationListener
            public final void onAnimationEnd(Animation animation) {
                if (animation.hashCode() != ClearnView.this.f5343h.hashCode()) {
                    if (animation.hashCode() == ClearnView.this.f5344i.hashCode()) {
                        ClearnView.this.f5347l.setVisibility(4);
                        ClearnView.this.startDiyAnim();
                        ClearnView.this.f5336a = false;
                        ClearnView.this.f5339d.sendEmptyMessageDelayed(0, 800L);
                        return;
                    }
                    if (animation.hashCode() == ClearnView.this.f5346k.hashCode()) {
                        ClearnView.this.f5336a = true;
                        if (ClearnView.this.f5357v) {
                            ClearnView.m2191a(ClearnView.this, ClearnView.this.f5353r, ClearnView.this.f5354s, ClearnView.this.f5360y);
                            ClearnView.this.f5333A.setVisibility(0);
                        } else {
                            ClearnView.m2191a(ClearnView.this, ClearnView.this.f5355t, ClearnView.this.f5356u, ClearnView.this.f5359x);
                            ClearnView.this.f5361z.setVisibility(0);
                        }
                        KillAllPackageReceiver.sendBroadcastAboutExeClearShortcut(ClearnView.this.f5342g, Utils.getEndMemory(ClearnView.this.f5342g));
                        ClearnView.this.doFade();
                        return;
                    }
                    if (animation.hashCode() == ClearnView.this.f5345j.hashCode()) {
                        ViewManager.removeView(ClearnView.this.f5342g, ClearnView.this);
                        return;
                    }
                    return;
                }
                ClearnView.m2200d(ClearnView.this);
            }
        };
        this.f5341f = new View.OnClickListener() { // from class: com.lenovo.safecenter.shortcut.ClearnView.3
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                ClearnView clearnView = ClearnView.this;
                if (ClearnView.m2197b(ClearnView.this.f5342g)) {
                    Intent intent = new Intent(ClearnView.this.f5342g, (Class<?>) SplashActivity.class);
                    intent.setFlags(268468224);
                    ClearnView.this.f5342g.startActivity(intent);
                } else {
                    Intent intent2 = new Intent(ClearnView.this.f5342g, (Class<?>) PerfWhitelistActivity.class);
                    intent2.setFlags(268468224);
                    ClearnView.this.f5342g.startActivity(intent2);
                }
                ViewManager.removeView(ClearnView.this.f5342g, ClearnView.this);
            }
        };
        this.f5334B = 100;
        this.f5342g = context;
        addView(inflate(context, C0415R.layout.shortcut_clear, null));
        this.f5358w = new HandlerC0970b();
        this.f5347l = (ImageView) findViewById(C0415R.id.clean_light_Image);
        this.f5348m = (TextView) findViewById(C0415R.id.clean_Value_Text);
        this.f5349n = (ImageView) findViewById(C0415R.id.clean_schedule_ImageView);
        this.f5350o = (ClipDrawable) this.f5349n.getDrawable();
        this.f5351p = (ViewGroup) findViewById(C0415R.id.toast_layout_left);
        this.f5352q = (ViewGroup) findViewById(C0415R.id.toast_layout_right);
        this.f5353r = (TextView) findViewById(C0415R.id.txt_toast_right1);
        this.f5354s = (TextView) findViewById(C0415R.id.txt_toast_right2);
        this.f5355t = (TextView) findViewById(C0415R.id.txt_toast_left1);
        this.f5356u = (TextView) findViewById(C0415R.id.txt_toast_left2);
        this.f5343h = AnimationUtils.loadAnimation(context, C0415R.anim.shortcard_process_clear_enlarge);
        this.f5344i = AnimationUtils.loadAnimation(context, C0415R.anim.shortcard_process_clear_rotate);
        this.f5345j = AnimationUtils.loadAnimation(context, C0415R.anim.shortcard_process_clear_fade);
        this.f5346k = new C0969a();
        this.f5346k.setDuration(600L);
        this.f5343h.setAnimationListener(this.f5340e);
        this.f5344i.setAnimationListener(this.f5340e);
        this.f5345j.setAnimationListener(this.f5340e);
        this.f5346k.setAnimationListener(this.f5340e);
        this.f5359x = (Button) findViewById(C0415R.id.txt_button_left);
        this.f5360y = (Button) findViewById(C0415R.id.txt_button_right);
        this.f5361z = (RelativeLayout) findViewById(C0415R.id.left);
        this.f5333A = (RelativeLayout) findViewById(C0415R.id.right);
    }

    public void startDiyAnim() {
        setAnimation(this.f5346k);
        this.f5346k.start();
    }

    public void doFade() {
        setAnimation(this.f5345j);
        this.f5345j.start();
    }

    @Override // android.view.ViewGroup, android.view.View
    protected void onAttachedToWindow() {
        super.onAttachedToWindow();
        Log.i("CleanView", System.currentTimeMillis() + "---> onAttachedToWindow");
        long lastClickTime = Utils.getLastKillTime(this.f5342g);
        long nowClickTime = System.currentTimeMillis();
        this.f5337b = nowClickTime - lastClickTime;
        this.f5338c = Utils.getLastClickPosition(this.f5342g);
        Log.i("CleanView", "lastClick == " + lastClickTime + " nowClick == " + nowClickTime + " interval == " + this.f5337b + " position == " + this.f5338c);
        Utils.recordKillTimeAndPosition(this.f5342g, nowClickTime, 3);
        setAnimation(this.f5343h);
        this.f5343h.start();
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.shortcut.ClearnView$a */
    class C0969a extends Animation {

        /* JADX INFO: renamed from: b */
        private int f5372b = 0;

        /* JADX INFO: renamed from: c */
        private View f5373c = null;

        /* JADX INFO: renamed from: d */
        private int f5374d = 0;

        /* JADX INFO: renamed from: e */
        private int f5375e = 0;

        C0969a() {
        }

        @Override // android.view.animation.Animation
        protected final void applyTransformation(float interpolatedTime, Transformation t) {
            super.applyTransformation(interpolatedTime, t);
            if (this.f5373c == null) {
                Log.i("CleanView", " view == null");
                this.f5373c = (View) ClearnView.this.getParent();
                this.f5372b = ((AbsoluteLayout.LayoutParams) ClearnView.this.getLayoutParams()).x;
                Log.i("CleanView", " view == null this.mX == " + this.f5372b);
                if (this.f5372b + (ClearnView.this.getWidth() / 2) >= this.f5373c.getWidth() / 2) {
                    ClearnView.this.f5357v = false;
                    this.f5374d = ClearnView.this.f5342g.getResources().getDimensionPixelSize(C0415R.dimen.clear_shortcute_toast_right_length);
                    return;
                } else {
                    Log.i("CleanView", " this.mX + getWidth() / 2 < this.c.getWidth() / 2 ");
                    ClearnView.this.f5357v = true;
                    this.f5374d = ClearnView.this.f5342g.getResources().getDimensionPixelSize(C0415R.dimen.clear_shortcute_toast_left_length);
                    return;
                }
            }
            int i = (int) (this.f5374d * interpolatedTime);
            if (i != this.f5375e) {
                this.f5375e = i;
            }
            Log.i("CleanView", " i == " + i);
            if (ClearnView.this.f5357v) {
                ClearnView.this.f5352q.getLayoutParams().width = i;
                ClearnView.this.f5352q.requestLayout();
                return;
            }
            ClearnView.this.f5351p.getLayoutParams().width = i;
            ClearnView.this.f5351p.requestLayout();
            ((AbsoluteLayout.LayoutParams) ClearnView.this.getLayoutParams()).x = this.f5372b - i;
            ClearnView.this.requestLayout();
        }
    }

    /* JADX INFO: renamed from: a */
    private int[] m2195a(final Handler handler) {
        Log.i("OPTI", System.currentTimeMillis() + " ---> start Read App List");
        HashMap<String, int[]> readRunningAppCount = ScanApplicationInfo.getRunningAppInfo(this.f5342g);
        Log.i("OPTI", System.currentTimeMillis() + " ---> ok Read App List " + readRunningAppCount.size());
        int killedCount = 0;
        int clearedMemory = 0;
        final ArrayList<String> pkgList = new ArrayList<>();
        for (Map.Entry<String, int[]> element : readRunningAppCount.entrySet()) {
            pkgList.add(element.getKey());
            clearedMemory += element.getValue()[1];
            if (element.getValue()[2] == 1) {
                killedCount++;
            }
        }
        Log.i("OPTI", System.currentTimeMillis() + " ---> start Thread to kill");
        new Thread(new Runnable() { // from class: com.lenovo.safecenter.shortcut.ClearnView.5
            @Override // java.lang.Runnable
            public final void run() {
                RootPassage.execRootCmd(handler, pkgList, " -fs ", ClearnView.this.f5342g);
                Log.i("OPTI", System.currentTimeMillis() + " ---> ok Thread to kill");
            }
        }).start();
        return new int[]{killedCount, clearedMemory};
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.shortcut.ClearnView$b */
    class HandlerC0970b extends Handler {
        HandlerC0970b() {
        }

        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    ClearnView.this.f5350o.setLevel(msg.arg1);
                    ClearnView.this.f5348m.setText(msg.arg2 + "%");
                    break;
            }
        }
    }
}
