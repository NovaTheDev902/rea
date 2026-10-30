package com.lenovo.safecenter.systeminfo.p011ui.activity;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.provider.Settings;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.inputmethod.InputMethodManager;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.Laboratory.AppUninstall;
import com.lenovo.safecenter.lenovoAntiSpam.newview.NumberArea;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.DialogUtil;
import com.lenovo.safecenter.utils.NewFunctionNoticeManager;
import com.lenovo.safecenter.utils.PwdUtil;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class DailyTools extends BaseTitleActivity {

    /* JADX INFO: renamed from: a */
    private ArrayList<C1011a> f5640a;

    /* JADX INFO: renamed from: b */
    private ListView f5641b;

    /* JADX INFO: renamed from: c */
    private ToolsApater f5642c;

    /* JADX INFO: renamed from: d */
    private boolean f5643d = false;

    /* JADX INFO: renamed from: e */
    private Handler f5644e = new Handler() { // from class: com.lenovo.safecenter.systeminfo.ui.activity.DailyTools.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    InputMethodManager m = (InputMethodManager) DailyTools.this.getSystemService("input_method");
                    m.toggleSoftInput(0, 2);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: c */
    static /* synthetic */ void m2309c(DailyTools x0) {
        if (PwdUtil.hasPassword(x0)) {
            DialogUtil.showPwdDialog(Const.ACTION_JUMP_KID_MODE, x0);
            x0.f5644e.sendEmptyMessageDelayed(1, 500L);
        } else {
            WflUtils.startSettingPasswordActivity(x0.getApplicationContext(), Const.ACTION_JUMP_KID_MODE);
        }
    }

    /* JADX INFO: renamed from: e */
    static /* synthetic */ void m2311e(DailyTools x0) {
        if (PwdUtil.hasPassword(x0)) {
            DialogUtil.showPwdDialog(Const.ACTION_JUMP_CHILD_MODE, x0);
            x0.f5644e.sendEmptyMessageDelayed(1, 500L);
        } else {
            WflUtils.startSettingPasswordActivity(x0.getApplicationContext(), Const.ACTION_JUMP_CHILD_MODE);
        }
    }

    /* JADX INFO: renamed from: f */
    static /* synthetic */ void m2312f(DailyTools x0) {
        Intent intent = new Intent();
        intent.setAction("com.lenovo.safecenter.SafePaymentActivity");
        x0.startActivity(intent);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        this.f5641b = new ListView(this);
        this.f5641b.setItemsCanFocus(true);
        setContentView(this.f5641b);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.dayly_tools, (Integer) null);
        this.f5641b.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.systeminfo.ui.activity.DailyTools.2
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> arg0, View arg1, int position, long arg3) {
                int idIcon = ((C1011a) DailyTools.this.f5640a.get(position)).f5664f;
                switch (idIcon) {
                    case C0415R.drawable.antivirus_upicon /* 2130837559 */:
                        DailyTools.this.startActivity(new Intent(DailyTools.this, (Class<?>) AppUninstall.class));
                        break;
                    case C0415R.drawable.dayly_tools_child_mode /* 2130837775 */:
                        if (DailyTools.this.f5643d) {
                            DailyTools.m2309c(DailyTools.this);
                            NewFunctionNoticeManager.removeActionToType(DailyTools.this, NewFunctionNoticeManager.TYPE_TOOLS, NewFunctionNoticeManager.ACTION_KIDMODE);
                            ((C1011a) DailyTools.this.f5640a.get(position)).f5659a = false;
                            DailyTools.this.f5642c.notifyDataSetChanged();
                        } else {
                            DailyTools.m2311e(DailyTools.this);
                        }
                        break;
                    case C0415R.drawable.dayly_tools_guest_mode /* 2130837776 */:
                        Intent it = new Intent("com.lenovo.safecenter.view.DialogActivity");
                        if (Settings.System.getInt(DailyTools.this.getContentResolver(), "guest_mode_on", 0) == 0) {
                            it.putExtra("style", 4);
                        } else {
                            it.putExtra("style", 5);
                        }
                        DailyTools.this.startActivity(it);
                        NewFunctionNoticeManager.removeActionToType(DailyTools.this, NewFunctionNoticeManager.TYPE_TOOLS, NewFunctionNoticeManager.ACTION_GUESTMODE);
                        ((C1011a) DailyTools.this.f5640a.get(position)).f5659a = false;
                        DailyTools.this.f5642c.notifyDataSetChanged();
                        break;
                    case C0415R.drawable.dayly_tools_safepayment /* 2130837777 */:
                        DailyTools.m2312f(DailyTools.this);
                        break;
                    case C0415R.drawable.feeprotection_tab_btn_numberspace_icon_normal /* 2130837799 */:
                        DailyTools.this.startActivity(new Intent(DailyTools.this, (Class<?>) CommonNumberActivity.class));
                        break;
                    case C0415R.drawable.numberara /* 2130838033 */:
                        DailyTools.this.startActivity(new Intent(DailyTools.this, (Class<?>) NumberArea.class));
                        break;
                    case C0415R.drawable.tool_box_system_exam /* 2130838299 */:
                        DailyTools.this.startActivity(new Intent(DailyTools.this, (Class<?>) SystemExamActivity.class));
                        break;
                }
            }
        });
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
        this.f5640a = new ArrayList<>();
        if (TrafficStatsService.nacServerIsExist()) {
            C1011a c1011a = new C1011a();
            c1011a.f5661c = C0415R.string.guest_mode;
            c1011a.f5662d = C0415R.string.guest_mode_message;
            if (NewFunctionNoticeManager.hasActionInType(this, NewFunctionNoticeManager.TYPE_TOOLS, NewFunctionNoticeManager.ACTION_GUESTMODE)) {
                c1011a.f5659a = true;
            }
            c1011a.f5664f = C0415R.drawable.dayly_tools_guest_mode;
            if (Settings.System.getInt(getContentResolver(), "guest_mode_on", 0) == 0) {
                c1011a.f5663e = C0415R.drawable.btn_off;
            } else {
                c1011a.f5663e = C0415R.drawable.btn_on;
            }
            this.f5640a.add(c1011a);
            if (Settings.System.getInt(getContentResolver(), "child_mode_on", 0) == 1 || Const.SDK_VERSION < 14) {
                this.f5643d = false;
                C1011a c1011a2 = new C1011a();
                c1011a2.f5661c = C0415R.string.child_mode;
                c1011a2.f5662d = C0415R.string.child_mode_message;
                c1011a2.f5664f = C0415R.drawable.dayly_tools_child_mode;
                c1011a2.f5663e = C0415R.drawable.arrow1;
                this.f5640a.add(c1011a2);
            } else {
                this.f5643d = true;
                C1011a c1011a3 = new C1011a();
                if (NewFunctionNoticeManager.hasActionInType(this, NewFunctionNoticeManager.TYPE_TOOLS, NewFunctionNoticeManager.ACTION_KIDMODE)) {
                    c1011a3.f5659a = true;
                }
                c1011a3.f5661c = C0415R.string.kid_mode;
                c1011a3.f5662d = C0415R.string.kid_mode_detail;
                c1011a3.f5664f = C0415R.drawable.dayly_tools_child_mode;
                c1011a3.f5663e = C0415R.drawable.arrow1;
                this.f5640a.add(c1011a3);
            }
        }
        C1011a c1011a4 = new C1011a();
        c1011a4.f5661c = C0415R.string.opti_main_sys_exam;
        c1011a4.f5662d = C0415R.string.tool_box_systemexam_summary;
        c1011a4.f5664f = C0415R.drawable.tool_box_system_exam;
        c1011a4.f5663e = C0415R.drawable.arrow1;
        this.f5640a.add(c1011a4);
        C1011a c1011a5 = new C1011a();
        c1011a5.f5661c = C0415R.string.number_space;
        c1011a5.f5662d = C0415R.string.call_protection_yellowpage_summary;
        c1011a5.f5664f = C0415R.drawable.feeprotection_tab_btn_numberspace_icon_normal;
        c1011a5.f5663e = C0415R.drawable.arrow1;
        this.f5640a.add(c1011a5);
        C1011a c1011a6 = new C1011a();
        c1011a6.f5661c = C0415R.string.phoneinfo_number_search;
        c1011a6.f5662d = C0415R.string.phoneinfo_number_search_small;
        c1011a6.f5664f = C0415R.drawable.numberara;
        c1011a6.f5663e = C0415R.drawable.arrow1;
        this.f5640a.add(c1011a6);
        C1011a c1011a7 = new C1011a();
        c1011a7.f5661c = C0415R.string.text_safepayment;
        c1011a7.f5662d = C0415R.string.safepayment_message;
        c1011a7.f5664f = C0415R.drawable.dayly_tools_safepayment;
        c1011a7.f5663e = C0415R.drawable.arrow1;
        this.f5640a.add(c1011a7);
        this.f5642c = new ToolsApater(this);
        this.f5641b.setAdapter((ListAdapter) this.f5642c);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
    }

    public static boolean isShowKidmode(Context context) {
        if (TrafficStatsService.nacServerIsExist()) {
            return Settings.System.getInt(context.getContentResolver(), "child_mode_on", 0) != 1 && Const.SDK_VERSION >= 14;
        }
        return false;
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        super.onClick(v);
        switch (v.getId()) {
            case C0415R.id.base_title_left /* 2131297465 */:
                finish();
                break;
        }
    }

    public class ToolsApater extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private Context f5648b;

        public ToolsApater(Context context) {
            this.f5648b = context;
        }

        @Override // android.widget.Adapter
        public int getCount() {
            return DailyTools.this.f5640a.size();
        }

        @Override // android.widget.Adapter
        public Object getItem(int position) {
            return null;
        }

        @Override // android.widget.Adapter
        public long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            View v;
            byte b = 0;
            if (convertView == null) {
                v = LayoutInflater.from(this.f5648b).inflate(C0415R.layout.antivirusmainitempage, (ViewGroup) null);
                C1010a holder = new C1010a(this, b);
                holder.f5649a = (ImageView) v.findViewById(C0415R.id.antivirusmain_icon);
                holder.f5650b = (ImageView) v.findViewById(C0415R.id.antiviruslenovo);
                holder.f5651c = (ImageView) v.findViewById(C0415R.id.antivirusqq);
                holder.f5652d = (ImageView) v.findViewById(C0415R.id.antivirusidefend);
                holder.f5655g = (TextView) v.findViewById(C0415R.id.antivirusbigtitle);
                holder.f5656h = (TextView) v.findViewById(C0415R.id.antivirussmalltitle);
                holder.f5657i = (TextView) v.findViewById(C0415R.id.antivirustitledesc);
                holder.f5653e = (ImageView) v.findViewById(C0415R.id.antivirus_main_item_icon);
                holder.f5654f = (ImageView) v.findViewById(C0415R.id.isNew_icon);
                v.setTag(holder);
            } else {
                v = convertView;
            }
            C1010a holder2 = (C1010a) v.getTag();
            holder2.f5655g.setText(((C1011a) DailyTools.this.f5640a.get(position)).f5661c);
            holder2.f5656h.setText(((C1011a) DailyTools.this.f5640a.get(position)).f5662d);
            holder2.f5653e.setBackgroundResource(((C1011a) DailyTools.this.f5640a.get(position)).f5664f);
            if (((C1011a) DailyTools.this.f5640a.get(position)).f5659a) {
                holder2.f5654f.setVisibility(0);
            } else {
                holder2.f5654f.setVisibility(8);
            }
            holder2.f5649a.setBackgroundResource(((C1011a) DailyTools.this.f5640a.get(position)).f5663e);
            holder2.f5650b.setVisibility(8);
            holder2.f5651c.setVisibility(8);
            holder2.f5652d.setVisibility(8);
            holder2.f5657i.setText("");
            return v;
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.systeminfo.ui.activity.DailyTools$ToolsApater$a */
        private class C1010a {

            /* JADX INFO: renamed from: a */
            ImageView f5649a;

            /* JADX INFO: renamed from: b */
            ImageView f5650b;

            /* JADX INFO: renamed from: c */
            ImageView f5651c;

            /* JADX INFO: renamed from: d */
            ImageView f5652d;

            /* JADX INFO: renamed from: e */
            ImageView f5653e;

            /* JADX INFO: renamed from: f */
            ImageView f5654f;

            /* JADX INFO: renamed from: g */
            TextView f5655g;

            /* JADX INFO: renamed from: h */
            TextView f5656h;

            /* JADX INFO: renamed from: i */
            TextView f5657i;

            private C1010a() {
            }

            /* synthetic */ C1010a(ToolsApater x0, byte b) {
                this();
            }
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.systeminfo.ui.activity.DailyTools$a */
    class C1011a {

        /* JADX INFO: renamed from: a */
        public boolean f5659a = false;

        /* JADX INFO: renamed from: c */
        private int f5661c;

        /* JADX INFO: renamed from: d */
        private int f5662d;

        /* JADX INFO: renamed from: e */
        private int f5663e;

        /* JADX INFO: renamed from: f */
        private int f5664f;

        C1011a() {
        }
    }
}
