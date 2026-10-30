package com.lenovo.safecenter.MainTab;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.net.Uri;
import android.os.Bundle;
import android.text.Layout;
import android.text.Selection;
import android.text.Spannable;
import android.text.SpannableString;
import android.text.method.LinkMovementMethod;
import android.text.style.ClickableSpan;
import android.text.style.ForegroundColorSpan;
import android.text.style.URLSpan;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.notificationintercept.InterceptUtils;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;

/* JADX INFO: loaded from: classes.dex */
public class HelpActivity extends Activity implements OnViewChangeListener {

    /* JADX INFO: renamed from: a */
    static boolean f2725a = false;

    /* JADX INFO: renamed from: b */
    private MyScrollLayout f2726b;

    /* JADX INFO: renamed from: c */
    private TextView f2727c;

    /* JADX INFO: renamed from: d */
    private TextView f2728d;

    /* JADX INFO: renamed from: e */
    private TextView f2729e;

    /* JADX INFO: renamed from: f */
    private SharedPreferences f2730f;

    /* JADX INFO: renamed from: g */
    private ImageView[] f2731g;

    /* JADX INFO: renamed from: h */
    private ImageView[] f2732h;

    /* JADX INFO: renamed from: i */
    private Bitmap[] f2733i;

    /* JADX INFO: renamed from: j */
    private int f2734j;

    /* JADX INFO: renamed from: k */
    private int f2735k;

    /* JADX INFO: renamed from: l */
    private LinearLayout f2736l;

    /* JADX INFO: renamed from: m */
    private boolean f2737m = false;

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.help_layout);
        this.f2730f = getSharedPreferences("antitheft", 0);
        this.f2737m = this.f2730f.getBoolean("frommain", false);
        try {
            this.f2726b = (MyScrollLayout) findViewById(C0415R.id.ScrollLayout);
            this.f2734j = this.f2726b.getChildCount();
            this.f2733i = new Bitmap[this.f2734j];
            this.f2732h = new ImageView[this.f2734j];
            this.f2733i[0] = WflUtils.readBitmap(this, C0415R.drawable.help1);
            this.f2732h[0] = (ImageView) findViewById(C0415R.id.help1_img);
            this.f2732h[0].setImageBitmap(this.f2733i[0]);
            this.f2736l = (LinearLayout) findViewById(C0415R.id.llayout);
            this.f2727c = (TextView) findViewById(C0415R.id.startBtn);
            this.f2728d = (TextView) findViewById(C0415R.id.skip_Btn);
            this.f2729e = (TextView) findViewById(C0415R.id.help5_text3);
            String help5 = getString(C0415R.string.help5_tv3) + getString(C0415R.string.permission_server) + getString(C0415R.string.help5_tv4) + getString(C0415R.string.permission_contract) + getString(C0415R.string.help5_tv5);
            SpannableString ss = new SpannableString(help5);
            Log.i("ydp", " " + getString(C0415R.string.help5_tv3).length() + " " + (getString(C0415R.string.help5_tv3).length() + getString(C0415R.string.permission_server).length()) + "  " + help5.indexOf(getString(C0415R.string.permission_contract)) + "  " + (help5.indexOf(getString(C0415R.string.permission_contract)) + getString(C0415R.string.permission_contract).length()));
            ss.setSpan(new URLSpan("http://safe.lenovo.com/new/safeMobile/permission.html"), getString(C0415R.string.help5_tv3).length(), getString(C0415R.string.help5_tv3).length() + getString(C0415R.string.permission_server).length(), 33);
            ss.setSpan(new ForegroundColorSpan(-16150038), getString(C0415R.string.help5_tv3).length(), getString(C0415R.string.help5_tv3).length() + getString(C0415R.string.permission_server).length(), 33);
            ss.setSpan(new URLSpan("http://safe.lenovo.com/new/safeMobile/contract.html"), help5.indexOf(getString(C0415R.string.permission_contract)), help5.indexOf(getString(C0415R.string.permission_contract)) + getString(C0415R.string.permission_contract).length(), 33);
            ss.setSpan(new ForegroundColorSpan(-16150038), help5.indexOf(getString(C0415R.string.permission_contract)), help5.indexOf(getString(C0415R.string.permission_contract)) + getString(C0415R.string.permission_contract).length(), 33);
            Log.i("ydp", "help5:" + this.f2729e + "  ss:" + ((Object) ss));
            this.f2729e.setText(ss);
            this.f2729e.setMovementMethod(new LinkMovementMethod() { // from class: com.lenovo.safecenter.MainTab.HelpActivity.1
                @Override // android.text.method.LinkMovementMethod, android.text.method.ScrollingMovementMethod, android.text.method.BaseMovementMethod, android.text.method.MovementMethod
                public final boolean onTouchEvent(TextView widget, Spannable buffer, MotionEvent event) {
                    int action = event.getAction();
                    if (action == 1 || action == 0) {
                        int x = (int) event.getX();
                        int y = (int) event.getY();
                        int x2 = x - widget.getTotalPaddingLeft();
                        int y2 = y - widget.getTotalPaddingTop();
                        int x3 = x2 + widget.getScrollX();
                        int y3 = y2 + widget.getScrollY();
                        Layout layout = widget.getLayout();
                        int line = layout.getLineForVertical(y3);
                        int off = layout.getOffsetForHorizontal(line, x3);
                        ClickableSpan[] link = (ClickableSpan[]) buffer.getSpans(off, off, ClickableSpan.class);
                        if (link.length != 0) {
                            if (action == 1) {
                                try {
                                    Uri uri = Uri.parse(((URLSpan) link[0]).getURL());
                                    Context context = widget.getContext();
                                    Intent intent = new Intent("android.intent.action.VIEW", uri);
                                    intent.putExtra("com.android.browser.application_id", context.getPackageName());
                                    context.startActivity(intent);
                                } catch (Exception e) {
                                    Toast.makeText(HelpActivity.this, C0415R.string.no_browser, 1).show();
                                }
                            } else if (action == 0) {
                                Selection.setSelection(buffer, buffer.getSpanStart(link[0]), buffer.getSpanEnd(link[0]));
                            }
                            return true;
                        }
                        Selection.removeSelection(buffer);
                    }
                    return super.onTouchEvent(widget, buffer, event);
                }
            });
            this.f2731g = new ImageView[this.f2734j];
            for (int i = 0; i < this.f2734j; i++) {
                this.f2731g[i] = (ImageView) this.f2736l.getChildAt(i);
                this.f2731g[i].setEnabled(true);
                this.f2731g[i].setTag(Integer.valueOf(i));
            }
            this.f2735k = 0;
            this.f2731g[this.f2735k].setEnabled(false);
            this.f2726b.SetOnViewChangeListener(this);
            this.f2727c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.MainTab.HelpActivity.2
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    try {
                        if (HelpActivity.this.f2730f.getBoolean("help" + HelpActivity.this.getPackageManager().getPackageInfo(HelpActivity.this.getPackageName(), 0).versionCode, true)) {
                            HelpActivity.this.f2730f.edit().putBoolean("help" + HelpActivity.this.getPackageManager().getPackageInfo(HelpActivity.this.getPackageName(), 0).versionCode, false).commit();
                            Intent intent = new Intent(HelpActivity.this, (Class<?>) LeSafeMainActivity.class);
                            HelpActivity.this.startActivity(intent);
                        }
                    } catch (PackageManager.NameNotFoundException e) {
                        e.printStackTrace();
                    }
                    InterceptUtils.appInit(HelpActivity.this);
                    HelpActivity.this.finish();
                }
            });
            this.f2728d.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.MainTab.HelpActivity.3
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    if (!HelpActivity.this.f2737m && HelpActivity.this.f2726b.mCurScreen + 1 < HelpActivity.this.f2734j) {
                        HelpActivity.this.f2726b.snapToScreen(HelpActivity.this.f2726b.mCurScreen + 1);
                    }
                }
            });
        } catch (Exception e) {
            Log.e("ydp", "load new app error!!!!!");
            Toast.makeText(this, C0415R.string.loading_error, 1).show();
            finish();
        }
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        super.onResume();
    }

    @Override // com.lenovo.safecenter.MainTab.OnViewChangeListener
    public void OnViewChange(int position) {
        if (position >= 0 && position <= this.f2734j - 1 && this.f2735k != position) {
            this.f2731g[this.f2735k].setEnabled(true);
            this.f2731g[position].setEnabled(false);
            this.f2735k = position;
            if (position == this.f2734j - 1) {
                this.f2728d.setVisibility(8);
            } else {
                this.f2728d.setVisibility(0);
            }
        }
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        this.f2733i[0].recycle();
        super.onDestroy();
    }
}
