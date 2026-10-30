package com.lenovo.safecenter.antivirus;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.text.SpannableString;
import android.text.TextUtils;
import android.text.style.AbsoluteSizeSpan;
import android.text.style.ForegroundColorSpan;
import android.text.style.StyleSpan;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.MainTab.MyScrollLayout;
import com.lenovo.safecenter.MainTab.OnViewChangeListener;
import com.lenovo.safecenter.antivirus.domain.VirusLog;
import com.lenovo.safecenter.antivirus.support.AntiVirusDBHelper;
import com.lenovo.safecenter.antivirus.utils.HttpUtils;
import com.lenovo.safecenter.antivirus.views.AntiVirusSetting;
import com.lenovo.safecenter.antivirus.views.FullSystemScanActivity;
import com.lenovo.safecenter.antivirus.views.LogActivity;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.LeSafeObservable;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.updateLab.UpdateLabManager;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.update.CheckResult;
import com.tencent.tmsecure.module.update.ICheckListener;
import com.tencent.tmsecure.module.update.IUpdateListener;
import com.tencent.tmsecure.module.update.UpdateInfo;
import com.tencent.tmsecure.module.update.UpdateManager;
import java.io.File;
import java.text.SimpleDateFormat;
import java.util.List;
import java.util.Observable;
import java.util.Observer;

/* JADX INFO: loaded from: classes.dex */
public class MainActivity extends BaseTitleActivity implements OnViewChangeListener, Observer {

    /* JADX INFO: renamed from: a */
    View f2961a;

    /* JADX INFO: renamed from: b */
    MyScrollLayout f2962b;

    /* JADX INFO: renamed from: c */
    LinearLayout f2963c;

    /* JADX INFO: renamed from: d */
    int f2964d;

    /* JADX INFO: renamed from: e */
    int f2965e;

    /* JADX INFO: renamed from: f */
    private TextView f2966f;

    /* JADX INFO: renamed from: g */
    private TextView f2967g;

    /* JADX INFO: renamed from: h */
    private TextView f2968h;

    /* JADX INFO: renamed from: i */
    private TextView f2969i;

    /* JADX INFO: renamed from: j */
    private ListView f2970j;

    /* JADX INFO: renamed from: k */
    private LocalBlackApater f2971k;

    /* JADX INFO: renamed from: l */
    private AntiVirusDBHelper f2972l;

    /* JADX INFO: renamed from: m */
    private VirusLog f2973m;

    /* JADX INFO: renamed from: n */
    private LeSafeObservable f2974n;

    /* JADX INFO: renamed from: o */
    private ImageView[] f2975o;

    /* JADX INFO: renamed from: p */
    private Handler f2976p = new Handler() { // from class: com.lenovo.safecenter.antivirus.MainActivity.4
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    HttpUtils.isDowning = false;
                    MainActivity.this.f2971k.notifyDataSetChanged();
                    MainActivity.this.f2970j.invalidateViews();
                    if (HttpUtils.execService("virus_state", MainActivity.this).equals("0")) {
                        Toast.makeText(MainActivity.this, C0415R.string.antivirusserver_disconnect, 0).show();
                    } else if (HttpUtils.execService("virus_state", MainActivity.this).equals("3")) {
                        Toast.makeText(MainActivity.this, C0415R.string.antivirusversiondesc, 0).show();
                    }
                    break;
                case 2:
                    if (HttpUtils.execService("virus_state", MainActivity.this).equals("3")) {
                        Toast.makeText(MainActivity.this, C0415R.string.antivirusdownsuccess, 0).show();
                    }
                    HttpUtils.isDowning = false;
                    MainActivity.this.f2971k.notifyDataSetChanged();
                    MainActivity.this.f2970j.invalidateViews();
                    break;
                case 10:
                    MainActivity.this.setNetShow();
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: q */
    private UpdateManager f2977q = (UpdateManager) ManagerCreator.getManager(UpdateManager.class);

    /* JADX INFO: renamed from: r */
    private List<UpdateInfo> f2978r;

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.antivirusmainpage);
        HttpUtils.isOpen = true;
        this.f2970j = (ListView) findViewById(C0415R.id.antivirusmainistview);
        this.f2969i = (TextView) findViewById(C0415R.id.shwoaddnet);
        this.f2961a = findViewById(C0415R.id.antivirusmainpage_virus_status);
        if (Const.getScreenHeight() < 800) {
            this.f2961a.setBackgroundResource(C0415R.drawable.virus_status_green1);
        } else {
            this.f2961a.setBackgroundResource(C0415R.drawable.virus_status_green0);
        }
        this.f2967g = (TextView) findViewById(C0415R.id.detail_virus_home_page);
        this.f2968h = (TextView) findViewById(C0415R.id.button_virus_home_page);
        this.f2972l = new AntiVirusDBHelper(this);
        Log.i("txt", this.f2966f + "==" + findViewById(C0415R.id.antivirusmainpage_title1));
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.antivirusapp_name, Integer.valueOf(C0415R.drawable.rf_perf_title_right));
        this.f2974n = LeSafeObservable.get(getApplicationContext());
        this.f2974n.addObserver(this);
        onBtnClick();
        initscroll();
    }

    public void setNetShow() {
        this.f2969i.setVisibility(8);
    }

    @Override // com.lenovo.safecenter.MainTab.OnViewChangeListener
    public void OnViewChange(int position) {
        if (position >= 0 && position <= this.f2964d - 1 && this.f2965e != position) {
            this.f2975o[this.f2965e].setEnabled(true);
            this.f2975o[position].setEnabled(false);
            this.f2965e = position;
        }
    }

    public void initscroll() {
        this.f2962b = (MyScrollLayout) findViewById(C0415R.id.ScrollLayout);
        this.f2963c = (LinearLayout) findViewById(C0415R.id.llayout);
        if (Const.getScreenHeight() < 800) {
            findViewById(C0415R.id.bottom_layout).setVisibility(8);
            return;
        }
        this.f2962b.setVisibility(0);
        this.f2964d = this.f2962b.getChildCount();
        this.f2975o = new ImageView[this.f2964d];
        for (int i = 0; i < this.f2964d; i++) {
            this.f2975o[i] = (ImageView) this.f2963c.getChildAt(i);
            this.f2975o[i].setEnabled(true);
            this.f2975o[i].setTag(Integer.valueOf(i));
        }
        this.f2975o[this.f2965e].setEnabled(false);
        this.f2962b.SetOnViewChangeListener(this);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        } else if (v.getId() == C0415R.id.base_title_right) {
            startActivity(new Intent(this, (Class<?>) AntiVirusSetting.class));
        }
    }

    public View getS_view(int title, int message, int iconImg) {
        View view = getLayoutInflater().inflate(C0415R.layout.virusadv_item, (ViewGroup) null);
        TextView name = (TextView) view.findViewById(C0415R.id.tt1);
        TextView discription = (TextView) view.findViewById(C0415R.id.tt3);
        name.setText(title);
        discription.setTextColor(-7829368);
        discription.setText(message);
        return view;
    }

    public void initGrally() {
    }

    /* JADX WARN: Type inference failed for: r1v5, types: [com.lenovo.safecenter.antivirus.MainActivity$1] */
    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
        try {
            this.f2973m = this.f2972l.getLatestLog();
        } catch (Exception e) {
            e.printStackTrace();
        }
        setNetShow();
        this.f2971k = new LocalBlackApater(this);
        this.f2970j.setAdapter((ListAdapter) this.f2971k);
        m1298a();
        if (HttpUtils.execService("del_viruslog", this).equals("")) {
            new Thread() { // from class: com.lenovo.safecenter.antivirus.MainActivity.1
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    try {
                        MainActivity.this.f2972l.delVirus();
                        HttpUtils.UpdateConfig("del_viruslog", "done", MainActivity.this);
                    } catch (Exception e2) {
                        e2.printStackTrace();
                    }
                }
            }.start();
        }
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    public void onBtnClick() {
        this.f2970j.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.antivirus.MainActivity.2
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                if (position != 2) {
                    if (position == 0) {
                        if (!HttpUtils.isupdating && !HttpUtils.isDowning) {
                            HttpUtils.isfrom = true;
                            HttpUtils.isDowning = true;
                            Toast.makeText(MainActivity.this, C0415R.string.dialogcontent, 0).show();
                            MainActivity.this.update();
                            return;
                        }
                        Toast.makeText(MainActivity.this, C0415R.string.dialogcontent, 0).show();
                        return;
                    }
                    if (position == 1) {
                        if (MainActivity.this.f2973m != null) {
                            MainActivity.this.startActivity(new Intent(MainActivity.this, (Class<?>) LogActivity.class));
                        } else {
                            Toast.makeText(MainActivity.this, C0415R.string.antivirushasnolog, 0).show();
                        }
                    }
                }
            }
        });
        this.f2968h.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.MainActivity.3
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                MainActivity.this.startActivity(new Intent(MainActivity.this, (Class<?>) FullSystemScanActivity.class));
            }
        });
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        HttpUtils.isOpen = false;
    }

    /* JADX INFO: renamed from: a */
    private void m1298a() {
        SpannableString spannable;
        String strExecService = HttpUtils.execService("scantime", this);
        int scanInterval = (int) ((TextUtils.isEmpty(strExecService) ? 0L : System.currentTimeMillis() - Long.valueOf(strExecService).longValue()) / 86400000);
        String strExecService2 = HttpUtils.execService("viruspkgname", this);
        int virusCount = TextUtils.isEmpty(strExecService2) ? 0 : strExecService2.split(",").length;
        if (virusCount != 0) {
            if (scanInterval < 1) {
                String detail = String.format(getString(C0415R.string.detail4_has_virus_home_page), Integer.valueOf(virusCount));
                spannable = new SpannableString(detail);
                if (Const.getScreenHeight() == 480) {
                    spannable.setSpan(new AbsoluteSizeSpan(30), 0, String.valueOf(virusCount).length() + 0, 33);
                } else {
                    spannable.setSpan(new AbsoluteSizeSpan(48), 0, String.valueOf(virusCount).length() + 0, 33);
                }
                spannable.setSpan(new ForegroundColorSpan(-65536), 0, String.valueOf(virusCount).length() + 0, 0);
                spannable.setSpan(new StyleSpan(2), 0, String.valueOf(virusCount).length() + 0, 33);
            } else {
                String detail2 = String.format(getString(C0415R.string.detail5_has_virus_home_page), Integer.valueOf(virusCount));
                spannable = new SpannableString(detail2);
                if (Const.getScreenHeight() == 480) {
                    spannable.setSpan(new AbsoluteSizeSpan(30), 7, String.valueOf(virusCount).length() + 7, 33);
                } else {
                    spannable.setSpan(new AbsoluteSizeSpan(48), 7, String.valueOf(scanInterval).length() + 7, 33);
                }
                spannable.setSpan(new ForegroundColorSpan(-65536), 7, String.valueOf(virusCount).length() + 7, 0);
                spannable.setSpan(new StyleSpan(2), 7, String.valueOf(virusCount).length() + 7, 33);
            }
            this.f2967g.setText(spannable);
            this.f2968h.setText(getString(C0415R.string.button_kill_virus_home_page));
            this.f2961a.setBackgroundResource(C0415R.drawable.virus_status_red1);
            return;
        }
        if (TextUtils.isEmpty(HttpUtils.execService("scantime", this))) {
            String detail3 = String.format(getString(C0415R.string.detail_first_virus_home_page), Integer.valueOf(scanInterval));
            SpannableString spannable2 = new SpannableString(detail3);
            this.f2967g.setText(spannable2);
            this.f2968h.setText(getString(C0415R.string.button_kill_virus_home_page));
            this.f2961a.setBackgroundResource(C0415R.drawable.virus_status_green0);
            return;
        }
        if (scanInterval <= 1) {
            TextView textView = (TextView) findViewById(C0415R.id.detail_virus_home_page);
            String string = getString(C0415R.string.detail5_no_virus_home_page);
            textView.setTextColor(getResources().getColor(C0415R.color.black2));
            textView.setText(new SpannableString(string));
            findViewById(C0415R.id.antivirusmainpage_virus_status).setBackgroundResource(C0415R.drawable.virus_status_green0);
            return;
        }
        if (scanInterval <= 99) {
            String detail4 = String.format(getString(C0415R.string.detail4_no_virus_home_page), Integer.valueOf(scanInterval));
            SpannableString spannable3 = new SpannableString(detail4);
            this.f2967g.setText(spannable3);
            this.f2968h.setText(getString(C0415R.string.button_kill_virus_home_page));
            this.f2961a.setBackgroundResource(C0415R.drawable.virus_status_green0);
            return;
        }
        String detail5 = getString(C0415R.string.detail6_no_virus_home_page);
        SpannableString spannable4 = new SpannableString(detail5);
        this.f2967g.setText(spannable4);
        this.f2968h.setText(getString(C0415R.string.button_kill_virus_home_page));
        this.f2961a.setBackgroundResource(C0415R.drawable.virus_status_green0);
    }

    @Override // java.util.Observer
    public void update(Observable observable, Object data) {
        if (data instanceof Integer) {
            switch (((Integer) data).intValue()) {
                case 0:
                    this.f2970j.invalidateViews();
                    HttpUtils.isDowning = false;
                    break;
                case 1:
                    this.f2970j.invalidateViews();
                    break;
                case 17:
                    m1298a();
                    break;
                case 18:
                    m1298a();
                    break;
                case 19:
                    m1298a();
                    break;
            }
        }
    }

    public void update() {
        new Thread(new Runnable() { // from class: com.lenovo.safecenter.antivirus.MainActivity.5
            @Override // java.lang.Runnable
            public final void run() {
                try {
                    MainActivity.this.f2977q.check(14, new ICheckListener() { // from class: com.lenovo.safecenter.antivirus.MainActivity.5.1
                        @Override // com.tencent.tmsecure.module.update.ICheckListener
                        public final void onCheckCanceled() {
                        }

                        @Override // com.tencent.tmsecure.module.update.ICheckListener
                        public final void onCheckEvent(int arg0) {
                            HttpUtils.UpdateConfig("virus_state", "0", MainActivity.this);
                            MainActivity.this.f2976p.sendEmptyMessage(1);
                        }

                        @Override // com.tencent.tmsecure.module.update.ICheckListener
                        public final void onCheckFinished(CheckResult arg0) {
                            try {
                                MainActivity.this.f2978r = arg0.mUpdateInfoList;
                                if (MainActivity.this.f2978r != null && MainActivity.this.f2978r.size() > 0) {
                                    HttpUtils.UpdateConfig("virus_state", DatabaseTables.USER_MARK, MainActivity.this);
                                } else {
                                    HttpUtils.UpdateConfig("virus_state", "3", MainActivity.this);
                                    MainActivity.this.f2976p.sendEmptyMessage(1);
                                }
                            } catch (Exception e) {
                                e.printStackTrace();
                            }
                        }

                        @Override // com.tencent.tmsecure.module.update.ICheckListener
                        public final void onCheckStarted() {
                        }
                    });
                    if (MainActivity.this.f2978r != null && MainActivity.this.f2978r.size() > 0) {
                        MainActivity.this.f2977q.update(MainActivity.this.f2978r, new IUpdateListener() { // from class: com.lenovo.safecenter.antivirus.MainActivity.5.2
                            @Override // com.tencent.tmsecure.module.update.IUpdateListener
                            public final void onProgressChanged(UpdateInfo arg0, int arg1) {
                                Log.i("demo", arg0.url + "=====");
                            }

                            @Override // com.tencent.tmsecure.module.update.IUpdateListener
                            public final void onUpdateEvent(UpdateInfo arg0, int arg1) {
                                HttpUtils.UpdateConfig("virus_state", "0", MainActivity.this);
                                MainActivity.this.f2976p.sendEmptyMessage(1);
                            }

                            @Override // com.tencent.tmsecure.module.update.IUpdateListener
                            public final void onUpdateFinished() {
                                HttpUtils.UpdateConfig("virus_state", "3", MainActivity.this);
                                MainActivity.this.f2976p.sendEmptyMessage(2);
                                LeSafeObservable.get(MainActivity.this).noticeUpdatedLab();
                                UpdateLabManager.setQueryLabStatus(0, 1);
                            }

                            @Override // com.tencent.tmsecure.module.update.IUpdateListener
                            public final void onUpdateStarted() {
                            }

                            @Override // com.tencent.tmsecure.module.update.IUpdateListener
                            public final void onUpdateCanceled() {
                            }
                        });
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                    Toast.makeText(MainActivity.this, C0415R.string.antivirusserver_disconnect, 0).show();
                }
            }
        }).start();
    }

    public static String getDate(String time) {
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy.M.dd.HH.mm");
        String datatime = sdf.format(Long.valueOf(Long.parseLong(time)));
        String[] timeArray = datatime.split("\\.");
        String formatTime = timeArray[0] + "-" + timeArray[1] + "-" + timeArray[2];
        return formatTime;
    }

    public class LocalBlackApater extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private Context f2987b;

        public LocalBlackApater(Context context) {
            this.f2987b = context;
        }

        @Override // android.widget.Adapter
        public int getCount() {
            return 2;
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
            C0441a holder;
            byte b = 0;
            if (convertView == null) {
                convertView = LayoutInflater.from(this.f2987b).inflate(C0415R.layout.antivirusmainitempage, (ViewGroup) null);
                holder = new C0441a(this, b);
                holder.f2988a = (ImageView) convertView.findViewById(C0415R.id.antivirusmain_icon);
                holder.f2989b = (ImageView) convertView.findViewById(C0415R.id.antiviruslenovo);
                holder.f2990c = (ImageView) convertView.findViewById(C0415R.id.antivirusqq);
                holder.f2991d = (ImageView) convertView.findViewById(C0415R.id.antivirusidefend);
                holder.f2993f = (TextView) convertView.findViewById(C0415R.id.antivirusbigtitle);
                holder.f2994g = (TextView) convertView.findViewById(C0415R.id.antivirussmalltitle);
                holder.f2995h = (TextView) convertView.findViewById(C0415R.id.antivirustitledesc);
                holder.f2992e = (ImageView) convertView.findViewById(C0415R.id.antivirus_main_item_icon);
                convertView.setTag(holder);
            } else {
                holder = (C0441a) convertView.getTag();
            }
            if (position == 2) {
                holder.f2993f.setText(C0415R.string.antivirusdeepscan_title);
                holder.f2994g.setText(MainActivity.this.getString(C0415R.string.antivirusdeepscan_desc));
                holder.f2992e.setBackgroundResource(C0415R.drawable.deep_scan_icon);
                holder.f2988a.setVisibility(0);
                holder.f2989b.setVisibility(8);
                holder.f2990c.setVisibility(8);
                holder.f2991d.setVisibility(8);
                holder.f2995h.setText("");
            } else if (position == 0) {
                holder.f2993f.setText(C0415R.string.antivirusupdatevirus_title);
                holder.f2994g.setText(MainActivity.this.getString(C0415R.string.antiviruslatest_update_virus_database));
                try {
                    if (HttpUtils.execService("virus_state", this.f2987b).equals("0") || HttpUtils.execService("virus_state", this.f2987b).equals("")) {
                        holder.f2995h.setText(HttpUtils.getDate(String.valueOf(new File(MainActivity.this.getFilesDir() + "/qv_base.amf").lastModified())));
                    } else if (HttpUtils.execService("virus_state", this.f2987b).equals("3")) {
                        holder.f2995h.setText(C0415R.string.versiondesc);
                    } else if (HttpUtils.execService("virus_state", this.f2987b).equals(DatabaseTables.USER_MARK)) {
                        holder.f2995h.setText(C0415R.string.has_new_update_note_text);
                    } else {
                        holder.f2995h.setText("2012-11-13");
                    }
                } catch (Exception e) {
                    holder.f2995h.setText("2012-11-13");
                }
                holder.f2989b.setVisibility(8);
                holder.f2990c.setVisibility(8);
                holder.f2991d.setVisibility(8);
                holder.f2992e.setBackgroundResource(C0415R.drawable.upt_data_icon);
                holder.f2988a.setVisibility(8);
            } else if (position == 1) {
                holder.f2993f.setText(C0415R.string.antivirusscan_log);
                holder.f2994g.setText(C0415R.string.antiviruslatest_scantime);
                holder.f2989b.setVisibility(8);
                holder.f2990c.setVisibility(8);
                holder.f2991d.setVisibility(8);
                if (MainActivity.this.f2973m != null) {
                    holder.f2995h.setText(MainActivity.this.f2973m.eventcontent);
                } else {
                    holder.f2994g.setText(C0415R.string.antivirushasnolog);
                    holder.f2995h.setText("");
                }
                holder.f2988a.setVisibility(0);
                holder.f2988a.setImageResource(C0415R.drawable.arrow1);
                holder.f2992e.setBackgroundResource(C0415R.drawable.scan_log_icon);
            }
            return convertView;
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.MainActivity$LocalBlackApater$a */
        private class C0441a {

            /* JADX INFO: renamed from: a */
            ImageView f2988a;

            /* JADX INFO: renamed from: b */
            ImageView f2989b;

            /* JADX INFO: renamed from: c */
            ImageView f2990c;

            /* JADX INFO: renamed from: d */
            ImageView f2991d;

            /* JADX INFO: renamed from: e */
            ImageView f2992e;

            /* JADX INFO: renamed from: f */
            TextView f2993f;

            /* JADX INFO: renamed from: g */
            TextView f2994g;

            /* JADX INFO: renamed from: h */
            TextView f2995h;

            private C0441a() {
            }

            /* synthetic */ C0441a(LocalBlackApater x0, byte b) {
                this();
            }
        }
    }
}
