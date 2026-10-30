package com.lenovo.safecenter.lenovoAntiSpam.newview;

import android.app.TabActivity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.GestureDetector;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TabHost;
import android.widget.TextView;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackActivity;
import com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalWhiteActivity;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.DataHelpUtils;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class WhiteABlackMain extends TabActivity implements View.OnClickListener {

    /* JADX INFO: renamed from: a */
    private TabHost f3972a;

    /* JADX INFO: renamed from: b */
    private GestureDetector f3973b;

    /* JADX INFO: renamed from: c */
    private View.OnTouchListener f3974c;

    public void setTitle(Integer leftImgId, int titleStrId, Integer rightImgId) {
        getWindow().setFeatureInt(7, C0415R.layout.rf_perf_basetitle);
        ((TextView) findViewById(C0415R.id.base_title_center)).setText(titleStrId);
        findViewById(C0415R.id.base_title_center).setOnClickListener(this);
        if (leftImgId != null) {
            findViewById(C0415R.id.base_title_left).setOnClickListener(this);
        } else {
            setLeftImgGone(8);
        }
        if (rightImgId != null) {
            findViewById(C0415R.id.base_title_right).setOnClickListener(this);
        } else {
            setRightImgGone(8);
        }
    }

    public void setLeftImgGone(int gone) {
        findViewById(C0415R.id.base_title_left).setVisibility(gone);
    }

    public void setRightImgGone(int gone) {
        findViewById(C0415R.id.base_title_right).setVisibility(gone);
    }

    @Override // android.app.ActivityGroup, android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(7);
        Const.addEntryPrivacySpaceCount();
        setContentView(C0415R.layout.common_tab);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.antispammancall, null);
        DataHelpUtils.allActivity.add(this);
        this.f3972a = getTabHost();
        View view = getView(getString(C0415R.string.tab_black), 0, C0415R.drawable.filter_sms_click_img);
        TabHost.TabSpec filterMsgSpec = this.f3972a.newTabSpec("0");
        filterMsgSpec.setIndicator(view);
        Intent filterMsgIntent = new Intent(this, (Class<?>) ManLocalBlackActivity.class);
        filterMsgIntent.putExtra("type", 1);
        filterMsgSpec.setContent(filterMsgIntent);
        View view2 = getView(getString(C0415R.string.tab_white), 1, C0415R.drawable.filter_call_click_img);
        TabHost.TabSpec filterCallSpec = this.f3972a.newTabSpec(DatabaseTables.SYSTEM_MARK);
        filterCallSpec.setIndicator(view2);
        Intent filterCallIntent = new Intent(this, (Class<?>) ManLocalWhiteActivity.class);
        filterCallSpec.setContent(filterCallIntent);
        this.f3972a.addTab(filterMsgSpec);
        this.f3972a.addTab(filterCallSpec);
        this.f3972a.setOnTabChangedListener(new TabHost.OnTabChangeListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.WhiteABlackMain.1
            @Override // android.widget.TabHost.OnTabChangeListener
            public final void onTabChanged(String tabId) {
                int tabID = Integer.valueOf(tabId).intValue();
                for (int i = 0; i < 2; i++) {
                    if (i == tabID) {
                        WhiteABlackMain.this.f3972a.getChildAt(Integer.valueOf(i).intValue());
                        TextView textView = (TextView) WhiteABlackMain.this.f3972a.getTabWidget().getChildAt(Integer.valueOf(i).intValue()).findViewById(C0415R.id.tab_name);
                        textView.setTextColor(WhiteABlackMain.this.getResources().getColor(C0415R.color.blue));
                    } else {
                        WhiteABlackMain.this.f3972a.getChildAt(Integer.valueOf(i).intValue());
                        TextView textView2 = (TextView) WhiteABlackMain.this.f3972a.getTabWidget().getChildAt(Integer.valueOf(i).intValue()).findViewById(C0415R.id.tab_name);
                        textView2.setTextColor(WhiteABlackMain.this.getResources().getColor(C0415R.color.black4));
                    }
                }
            }
        });
        Integer num = 0;
        TextView textView = (TextView) this.f3972a.getTabWidget().getChildAt(num.intValue()).findViewById(C0415R.id.tab_name);
        textView.setTextColor(getResources().getColor(C0415R.color.black4));
        this.f3972a.setCurrentTab(0);
        this.f3973b = new GestureDetector(new C0640a());
        this.f3974c = new View.OnTouchListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.WhiteABlackMain.2
            @Override // android.view.View.OnTouchListener
            public final boolean onTouch(View v, MotionEvent event) {
                return WhiteABlackMain.this.f3973b.onTouchEvent(event);
            }
        };
    }

    @Override // android.app.ActivityGroup, android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.ActivityGroup, android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.app.ActivityGroup, android.app.Activity
    protected void onStop() {
        super.onStop();
    }

    public View getView(String str, int pos, int drawID) {
        View view1 = LayoutInflater.from(this).inflate(C0415R.layout.tadview, (ViewGroup) null);
        TextView txtnumber = (TextView) view1.findViewById(C0415R.id.tab_name);
        ImageView tab_img = (ImageView) view1.findViewById(C0415R.id.tab_img);
        View img = view1.findViewById(C0415R.id.div1);
        Log.i("ss", "img==" + img);
        img.setVisibility(8);
        if (pos == 1) {
            img.setVisibility(8);
        } else {
            img.setVisibility(0);
        }
        txtnumber.setText(str);
        tab_img.setVisibility(8);
        return view1;
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.newview.WhiteABlackMain$a */
    class C0640a extends GestureDetector.SimpleOnGestureListener {
        C0640a() {
        }

        @Override // android.view.GestureDetector.SimpleOnGestureListener, android.view.GestureDetector.OnGestureListener
        public final boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX, float velocityY) {
            try {
                if (Math.abs(e1.getY() - e2.getY()) <= 250.0f) {
                    if (e1.getX() - e2.getX() <= 120.0f || Math.abs(velocityX) <= 200.0f || WhiteABlackMain.this.f3972a.getCurrentTab() != 0) {
                        if (e2.getX() - e1.getX() > 120.0f && Math.abs(velocityX) > 200.0f && WhiteABlackMain.this.f3972a.getCurrentTab() == 1) {
                            Log.i("test ", "left");
                            WhiteABlackMain.this.f3972a.setCurrentTab(0);
                        }
                    } else {
                        Log.i("test ", "right");
                        WhiteABlackMain.this.f3972a.setCurrentTab(1);
                    }
                }
            } catch (Exception e) {
            }
            return false;
        }
    }

    @Override // android.app.Activity, android.view.Window.Callback
    public boolean dispatchTouchEvent(MotionEvent event) {
        if (this.f3973b.onTouchEvent(event)) {
            event.setAction(3);
        }
        return super.dispatchTouchEvent(event);
    }
}
