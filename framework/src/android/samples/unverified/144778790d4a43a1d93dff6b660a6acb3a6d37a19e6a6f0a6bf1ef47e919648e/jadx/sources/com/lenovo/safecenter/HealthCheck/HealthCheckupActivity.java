package com.lenovo.safecenter.HealthCheck;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.text.SpannableString;
import android.text.TextUtils;
import android.text.style.AbsoluteSizeSpan;
import android.text.style.ForegroundColorSpan;
import android.util.Log;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.HealthCheck.util.HealthStatus;
import com.lenovo.safecenter.HealthCheck.util.HealthViewType;
import com.lenovo.safecenter.HealthCheck.util.ListOrderedMap;
import com.lenovo.safecenter.MainTab.RotateScanHealthScoreView;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import java.util.HashMap;

/* JADX INFO: loaded from: classes.dex */
public class HealthCheckupActivity extends Activity implements View.OnClickListener {
    public static final int HANDLER_INIT_PROGRESS_BAR = 9;
    public static final int HANDLER_REFRESH_HEALTH_DETAIL = 2;
    public static final int HANDLER_REFRESH_HEALTH_INDETERMINATE_PROGRESS = 6;
    public static final int HANDLER_REFRESH_HEALTH_PROGRESS = 3;
    public static final int HANDLER_REFRESH_HEALTH_SCORE = 0;
    public static final int HANDLER_REFRESH_HEALTH_STATE = 1;
    public static final int HANDLER_SAVE_CHECKTIME = 7;
    public static final int HANDLER_SET_STATE = 8;
    public static final int HANDLER_SHOW_TOAST = 5;
    public static final int HANDLER_STATE_CHANGE = 4;

    /* JADX INFO: renamed from: a */
    private Context f2367a;

    /* JADX INFO: renamed from: b */
    private ListView f2368b;

    /* JADX INFO: renamed from: c */
    private HealthCheckupAdapter f2369c;

    /* JADX INFO: renamed from: e */
    private ProgressBar f2371e;

    /* JADX INFO: renamed from: f */
    private HealthManager f2372f;

    /* JADX INFO: renamed from: g */
    private int f2373g;

    /* JADX INFO: renamed from: h */
    private int f2374h;

    /* JADX INFO: renamed from: i */
    private int f2375i;

    /* JADX INFO: renamed from: j */
    private int f2376j;

    /* JADX INFO: renamed from: d */
    private Handler f2370d = new Handler() { // from class: com.lenovo.safecenter.HealthCheck.HealthCheckupActivity.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    HealthCheckupActivity.m1014c(HealthCheckupActivity.this);
                    break;
                case 1:
                    TextView healthState = (TextView) HealthCheckupActivity.this.findViewById(C0415R.id.health_state);
                    healthState.setText(String.valueOf(msg.obj));
                    break;
                case 2:
                    HealthCheckupActivity.m1007a(HealthCheckupActivity.this, String.valueOf(msg.obj));
                    break;
                case 3:
                    HealthCheckupActivity.m1019e(HealthCheckupActivity.this);
                    break;
                case 4:
                    HealthCheckupActivity.m1014c(HealthCheckupActivity.this);
                    HealthCheckupActivity.m1022g(HealthCheckupActivity.this);
                    HealthCheckupActivity.m1023h(HealthCheckupActivity.this);
                    HealthCheckupActivity.this.f2369c.refresh();
                    break;
                case 5:
                    Toast.makeText(HealthCheckupActivity.this.getApplicationContext(), (String) msg.obj, 1).show();
                    break;
                case 6:
                    HealthCheckupActivity.this.m1016d();
                    break;
                case 7:
                    HealthCheckupActivity.this.m1020f();
                    break;
                case 9:
                    HealthCheckupActivity.this.f2371e.setMax(HealthCheckupActivity.this.f2376j);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: k */
    private HashMap<Integer, String> f2377k = null;

    /* JADX INFO: renamed from: l */
    private HashMap<Integer, String> f2378l = null;

    /* JADX INFO: renamed from: m */
    private HealthCheckCallback f2379m = new HealthCheckCallback() { // from class: com.lenovo.safecenter.HealthCheck.HealthCheckupActivity.2
        @Override // com.lenovo.safecenter.HealthCheck.HealthCheckCallback
        public final void setProgressBarIndeterminate(boolean isIndeterminate) {
            if (isIndeterminate) {
                HealthCheckupActivity healthCheckupActivity = HealthCheckupActivity.this;
                HealthCheckupActivity.m1005a(6, null, HealthCheckupActivity.this.f2370d);
            } else {
                HealthCheckupActivity healthCheckupActivity2 = HealthCheckupActivity.this;
                HealthCheckupActivity.m1005a(3, null, HealthCheckupActivity.this.f2370d);
            }
        }

        @Override // com.lenovo.safecenter.HealthCheck.HealthCheckCallback
        public final void onProgressChanged(int progress) {
            HealthCheckupActivity.this.f2375i = progress;
            HealthCheckupActivity healthCheckupActivity = HealthCheckupActivity.this;
            HealthCheckupActivity.m1005a(3, null, HealthCheckupActivity.this.f2370d);
        }

        @Override // com.lenovo.safecenter.HealthCheck.HealthCheckCallback
        public final void onScoreChanged(int score) {
            HealthCheckupActivity.this.f2374h = score;
            HealthCheckupActivity healthCheckupActivity = HealthCheckupActivity.this;
            HealthCheckupActivity.m1005a(0, null, HealthCheckupActivity.this.f2370d);
        }

        @Override // com.lenovo.safecenter.HealthCheck.HealthCheckCallback
        public final void onStatusChanged(int statusId) {
            HealthCheckupActivity.this.f2373g = statusId;
            HealthCheckupActivity healthCheckupActivity = HealthCheckupActivity.this;
            HealthCheckupActivity.m1005a(4, null, HealthCheckupActivity.this.f2370d);
        }

        @Override // com.lenovo.safecenter.HealthCheck.HealthCheckCallback
        public final void onStarted(int maxProgress, int action) {
            Log.i("wu0wu", "onStarted action=" + action);
            HealthCheckupActivity.this.f2376j = maxProgress;
            HealthCheckupActivity healthCheckupActivity = HealthCheckupActivity.this;
            HealthCheckupActivity.m1005a(9, null, HealthCheckupActivity.this.f2370d);
        }

        @Override // com.lenovo.safecenter.HealthCheck.HealthCheckCallback
        public final void onOneItemProcess(HealthItemResult result) {
            if (result != null) {
                if (!TextUtils.isEmpty(result.title)) {
                    HealthCheckupActivity healthCheckupActivity = HealthCheckupActivity.this;
                    HealthCheckupActivity.m1005a(1, result.title, HealthCheckupActivity.this.f2370d);
                }
                if (!TextUtils.isEmpty(result.title_detail)) {
                    HealthCheckupActivity healthCheckupActivity2 = HealthCheckupActivity.this;
                    HealthCheckupActivity.m1005a(2, result.title_detail, HealthCheckupActivity.this.f2370d);
                }
            }
        }

        @Override // com.lenovo.safecenter.HealthCheck.HealthCheckCallback
        public final void onResult(HealthItemResult result) {
            if (result != null) {
                HealthCheckupActivity.this.f2369c.addData(result);
            }
        }

        @Override // com.lenovo.safecenter.HealthCheck.HealthCheckCallback
        public final void onFinished(int action) {
            Log.i("wu0wu", "onScanFinished action=" + action);
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1005a(int x1, Object x2, Handler x3) {
        if (x3 == null) {
            return;
        }
        Message message = new Message();
        message.what = x1;
        message.obj = x2;
        x3.sendMessage(message);
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1007a(HealthCheckupActivity x0, String x1) {
        TextView textView = (TextView) x0.findViewById(C0415R.id.health_detail);
        textView.setVisibility(0);
        textView.setText(x1);
    }

    /* JADX INFO: renamed from: c */
    static /* synthetic */ void m1014c(HealthCheckupActivity x0) {
        ((RotateScanHealthScoreView) x0.findViewById(C0415R.id.health_score_ring)).refreshHealthScore(x0.f2374h);
    }

    /* JADX INFO: renamed from: e */
    static /* synthetic */ void m1019e(HealthCheckupActivity x0) {
        TextView textView = (TextView) x0.findViewById(C0415R.id.percent_progress);
        switch (x0.f2373g) {
            case 0:
            case 4:
                x0.f2371e.setIndeterminate(false);
                x0.f2371e.setProgress(x0.f2375i);
                int i = (x0.f2375i * 100) / x0.f2376j;
                WflUtils.Log("d", "wu0wu", "mScanProgress=" + x0.f2375i + ",MAX_PROGRESS=" + x0.f2376j);
                textView.setText((i <= 100 ? i : 100) + "%");
                break;
            case 2:
                x0.m1016d();
                break;
        }
    }

    /* JADX INFO: renamed from: g */
    static /* synthetic */ void m1022g(HealthCheckupActivity x0) {
        View viewFindViewById = x0.findViewById(C0415R.id.scaning_progress_layout);
        View viewFindViewById2 = x0.findViewById(C0415R.id.can_Optimization_layout);
        View viewFindViewById3 = x0.findViewById(C0415R.id.pause_layout);
        View viewFindViewById4 = x0.findViewById(C0415R.id.button_done);
        switch (x0.f2373g) {
            case 0:
                viewFindViewById.setVisibility(0);
                viewFindViewById2.setVisibility(8);
                viewFindViewById4.setVisibility(8);
                viewFindViewById3.setVisibility(8);
                break;
            case 1:
                viewFindViewById.setVisibility(8);
                viewFindViewById2.setVisibility(0);
                viewFindViewById4.setVisibility(8);
                viewFindViewById3.setVisibility(8);
                break;
            case 2:
                viewFindViewById.setVisibility(0);
                viewFindViewById2.setVisibility(8);
                viewFindViewById4.setVisibility(8);
                viewFindViewById3.setVisibility(8);
                break;
            case 3:
                viewFindViewById.setVisibility(8);
                viewFindViewById2.setVisibility(8);
                viewFindViewById4.setVisibility(0);
                viewFindViewById3.setVisibility(8);
                break;
            case 4:
                viewFindViewById.setVisibility(8);
                viewFindViewById2.setVisibility(8);
                viewFindViewById4.setVisibility(8);
                viewFindViewById3.setVisibility(0);
                break;
        }
    }

    /* JADX INFO: renamed from: h */
    static /* synthetic */ void m1023h(HealthCheckupActivity x0) {
        TextView textView = (TextView) x0.findViewById(C0415R.id.health_state);
        switch (x0.f2373g) {
            case 0:
                textView.setText(x0.f2377k.get(0));
                x0.m1004a();
                break;
            case 1:
                x0.m1011b();
                x0.m1013c();
                break;
            case 2:
                x0.m1004a();
                textView.setText(x0.f2377k.get(2));
                break;
            case 3:
                x0.m1020f();
                x0.m1013c();
                x0.m1011b();
                break;
            case 4:
                x0.m1011b();
                textView.setText(x0.f2377k.get(4));
                break;
        }
    }

    /* JADX INFO: renamed from: k */
    static /* synthetic */ void m1026k(HealthCheckupActivity x0) {
        x0.f2372f.exit();
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.i("wu0wu", "HealthCheckupActivity onCreate...");
        this.f2367a = this;
        setContentView(C0415R.layout.activity_health_checkup_layout);
        ((TextView) findViewById(C0415R.id.txt_title)).setText(C0415R.string.health_checkup);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.HealthCheck.HealthCheckupActivity.3
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                HealthCheckupActivity.m1026k(HealthCheckupActivity.this);
                HealthCheckupActivity.this.finish();
            }
        });
        this.f2377k = HealthStatus.getStatus(this.f2367a);
        this.f2378l = HealthViewType.getViewTypes(this.f2367a);
        Const.isHealthCheckNoOptimiza(true);
        if (WflUtils.isRoot()) {
            TrackEvent.reportRootEnable();
        }
        this.f2372f = new HealthManager(this.f2367a, false);
        this.f2368b = (ListView) findViewById(C0415R.id.health_scan_list);
        this.f2369c = new HealthCheckupAdapter(this);
        this.f2368b.setDivider(null);
        this.f2368b.setAdapter((ListAdapter) this.f2369c);
        TextView textView = (TextView) findViewById(C0415R.id.button_Optimization);
        TextView textView2 = (TextView) findViewById(C0415R.id.button_back_from_pause);
        TextView textView3 = (TextView) findViewById(C0415R.id.button_done);
        TextView textView4 = (TextView) findViewById(C0415R.id.button_cancel);
        TextView textView5 = (TextView) findViewById(C0415R.id.button_continue_Optimization);
        textView.setOnClickListener(this);
        textView2.setOnClickListener(this);
        textView3.setOnClickListener(this);
        textView4.setOnClickListener(this);
        textView5.setOnClickListener(this);
        this.f2371e = (ProgressBar) findViewById(C0415R.id.scan_progressBar);
        this.f2372f.scan(this.f2379m);
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        this.f2372f.setItemsManual();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (4 != keyCode) {
            return super.onKeyDown(keyCode, event);
        }
        this.f2372f.exit();
        if (!isFinishing()) {
            finish();
        }
        return true;
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.button_cancel /* 2131296326 */:
                if (this.f2373g == 2) {
                    this.f2372f.setStatus(4);
                } else if (this.f2373g == 0) {
                    TrackEvent.reportUserActionCancelHealthCheck();
                    this.f2372f.exit();
                    finish();
                }
                break;
            case C0415R.id.button_Optimization /* 2131296328 */:
                m1018e();
                TrackEvent.reportUserActionHealthOptimizeImmediately();
                break;
            case C0415R.id.button_continue_Optimization /* 2131296330 */:
                m1018e();
                break;
            case C0415R.id.button_back_from_pause /* 2131296331 */:
            case C0415R.id.button_done /* 2131296332 */:
                this.f2372f.exit();
                finish();
                break;
        }
    }

    /* JADX INFO: renamed from: a */
    private void m1004a() {
        RotateScanHealthScoreView mHealthScoreRing = (RotateScanHealthScoreView) findViewById(C0415R.id.health_score_ring);
        mHealthScoreRing.beginAnim();
    }

    /* JADX INFO: renamed from: b */
    private void m1011b() {
        RotateScanHealthScoreView mHealthScoreRing = (RotateScanHealthScoreView) findViewById(C0415R.id.health_score_ring);
        mHealthScoreRing.stopAnim();
    }

    /* JADX INFO: renamed from: c */
    private void m1013c() {
        SpannableString spannable = null;
        if (this.f2373g != 3) {
            int canOptimizationItemNum = this.f2372f.getNumCanOptimizationItem() + this.f2372f.getNumDangerItem();
            String detail = String.format(getString(C0415R.string.optimization_datail_num_item), Integer.valueOf(canOptimizationItemNum));
            spannable = new SpannableString(detail);
            spannable.setSpan(new AbsoluteSizeSpan(20, true), 0, String.valueOf(canOptimizationItemNum).length() + 0, 33);
            spannable.setSpan(new ForegroundColorSpan(-65536), 0, String.valueOf(canOptimizationItemNum).length() + 0, 0);
        }
        if (this.f2374h >= 100) {
            m1008a(getString(C0415R.string.optimization_datail_all_safe_item));
            ((TextView) findViewById(C0415R.id.health_detail)).setVisibility(8);
            return;
        }
        if (this.f2374h >= 76 && this.f2374h <= 99) {
            m1008a(getString(C0415R.string.can_optimization76_99));
            m1006a(spannable);
        } else if (this.f2374h >= 60 && this.f2374h <= 75) {
            m1008a(getString(C0415R.string.can_optimization60_75));
            m1006a(spannable);
        } else {
            m1008a(getString(C0415R.string.can_optimization59));
            m1006a(spannable);
        }
    }

    /* JADX INFO: renamed from: a */
    private void m1008a(String datail) {
        TextView healthState = (TextView) findViewById(C0415R.id.health_state);
        healthState.setText(datail);
    }

    /* JADX INFO: renamed from: a */
    private void m1006a(SpannableString datail) {
        TextView healthDetail = (TextView) findViewById(C0415R.id.health_detail);
        healthDetail.setVisibility(0);
        healthDetail.setText(datail);
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: d */
    public void m1016d() {
        TextView percent = (TextView) findViewById(C0415R.id.percent_progress);
        percent.setVisibility(8);
        this.f2371e.setIndeterminate(true);
    }

    /* JADX INFO: renamed from: e */
    private void m1018e() {
        this.f2372f.optimize(null);
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: f */
    public void m1020f() {
        Const.isHealthCheckNoOptimiza(false);
        WflUtils.Log("i", "wu0wu", "HealthCheckup saveHealthScoreAndCheckupTime...");
        int score = this.f2374h;
        if (this.f2374h > 100) {
            score = 100;
        } else if (this.f2374h < 0) {
            score = 0;
        }
        Const.setHealthCheckupScore(score);
        Const.setHealthCheckupTime(System.currentTimeMillis());
        if (Const.isFirstHealthCheckup()) {
            Const.setFirstHealthCheckup();
        }
    }

    public class HealthCheckupAdapter extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private ListOrderedMap f2384b;

        /* JADX INFO: renamed from: c */
        private LayoutInflater f2385c;

        /* JADX INFO: renamed from: d */
        private Handler f2386d = new Handler() { // from class: com.lenovo.safecenter.HealthCheck.HealthCheckupActivity.HealthCheckupAdapter.1
            @Override // android.os.Handler
            public final void handleMessage(Message msg) {
                switch (msg.what) {
                    case 0:
                        HealthCheckupAdapter.this.notifyDataSetChanged();
                        break;
                    case 1:
                        HealthItemResult pushItem = (HealthItemResult) msg.obj;
                        HealthCheckupAdapter.this.f2384b.put(pushItem.key, pushItem);
                        if (pushItem.view_type != 0) {
                            HealthCheckupAdapter.m1033b(HealthCheckupAdapter.this);
                        }
                        HealthCheckupAdapter.this.notifyDataSetChanged();
                        break;
                    case 2:
                        HealthCheckupAdapter.this.f2384b.remove(((Integer) msg.obj).intValue());
                        HealthCheckupAdapter.this.notifyDataSetChanged();
                        break;
                }
            }
        };

        /* JADX INFO: renamed from: b */
        static /* synthetic */ void m1033b(HealthCheckupAdapter x0) {
            int numDangerItem = HealthCheckupActivity.this.f2372f.getNumDangerItem();
            int numManualItem = HealthCheckupActivity.this.f2372f.getNumManualItem();
            int numCanOptimizationItem = HealthCheckupActivity.this.f2372f.getNumCanOptimizationItem();
            int numSafeItem = HealthCheckupActivity.this.f2372f.getNumSafeItem();
            int numHasOptimizationItem = HealthCheckupActivity.this.f2372f.getNumHasOptimizationItem();
            if (numDangerItem == 0) {
                x0.m1031a(2, (Object) 22);
            } else {
                HealthItemResult healthItemResult = new HealthItemResult();
                healthItemResult.view_type = 0;
                healthItemResult.weight = 0;
                healthItemResult.key = 22;
                healthItemResult.content = ((String) HealthCheckupActivity.this.f2378l.get(1)) + "(" + numDangerItem + ")";
                x0.m1031a(1, healthItemResult);
            }
            if (numManualItem == 0) {
                x0.m1031a(2, (Object) 23);
            } else {
                HealthItemResult healthItemResult2 = new HealthItemResult();
                healthItemResult2.view_type = 0;
                healthItemResult2.weight = 4;
                healthItemResult2.key = 23;
                healthItemResult2.content = ((String) HealthCheckupActivity.this.f2378l.get(3)) + "(" + numManualItem + ")";
                x0.m1031a(1, healthItemResult2);
            }
            if (numCanOptimizationItem == 0) {
                x0.m1031a(2, (Object) 24);
            } else {
                HealthItemResult healthItemResult3 = new HealthItemResult();
                healthItemResult3.view_type = 0;
                healthItemResult3.weight = 2;
                healthItemResult3.key = 24;
                healthItemResult3.content = ((String) HealthCheckupActivity.this.f2378l.get(2)) + "(" + numCanOptimizationItem + ")";
                x0.m1031a(1, healthItemResult3);
            }
            if (numHasOptimizationItem == 0) {
                x0.m1031a(2, (Object) 25);
            } else {
                HealthItemResult healthItemResult4 = new HealthItemResult();
                healthItemResult4.view_type = 0;
                healthItemResult4.weight = 6;
                healthItemResult4.key = 25;
                healthItemResult4.content = ((String) HealthCheckupActivity.this.f2378l.get(4)) + "(" + numHasOptimizationItem + ")";
                x0.m1031a(1, healthItemResult4);
            }
            if (numSafeItem == 0) {
                x0.m1031a(2, (Object) 26);
                return;
            }
            HealthItemResult healthItemResult5 = new HealthItemResult();
            healthItemResult5.view_type = 0;
            healthItemResult5.weight = 8;
            healthItemResult5.key = 26;
            healthItemResult5.content = ((String) HealthCheckupActivity.this.f2378l.get(5)) + "(" + numSafeItem + ")";
            x0.m1031a(1, healthItemResult5);
        }

        public HealthCheckupAdapter(Context context) {
            this.f2385c = (LayoutInflater) context.getSystemService("layout_inflater");
            if (this.f2384b == null) {
                this.f2384b = new ListOrderedMap();
            }
        }

        public void refresh() {
            this.f2386d.sendEmptyMessage(0);
        }

        @Override // android.widget.Adapter
        public int getCount() {
            if (this.f2384b == null) {
                return 0;
            }
            return this.f2384b.size();
        }

        @Override // android.widget.Adapter
        public Object getItem(int position) {
            if (this.f2384b == null || position >= getCount()) {
                return null;
            }
            return this.f2384b.getValueByIndex(position);
        }

        @Override // android.widget.Adapter
        public long getItemId(int position) {
            return position;
        }

        public void addData(HealthItemResult newData) {
            if (newData != null) {
                m1031a(1, newData);
            }
        }

        /* JADX INFO: renamed from: a */
        private void m1031a(int what, Object obj) {
            Message msg = new Message();
            msg.what = what;
            msg.obj = obj;
            this.f2386d.sendMessage(msg);
        }

        @Override // android.widget.BaseAdapter, android.widget.ListAdapter
        public boolean isEnabled(int position) {
            return false;
        }

        @Override // android.widget.BaseAdapter, android.widget.Adapter
        public int getItemViewType(int position) {
            HealthItemResult item = this.f2384b.getValueByIndex(position);
            if (item.view_type == 0) {
                return 1;
            }
            if (item.view_type == 3) {
                return 2;
            }
            return 0;
        }

        @Override // android.widget.BaseAdapter, android.widget.Adapter
        public int getViewTypeCount() {
            return 3;
        }

        /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
        @Override // android.widget.Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            View v;
            View[] viewArr;
            int viewType = this.f2384b.getValueByIndex(position).view_type;
            if (convertView == null) {
                if (viewType == 0) {
                    v = this.f2385c.inflate(C0415R.layout.health_list_title, parent, false);
                    viewArr = new View[]{v.findViewById(C0415R.id.title)};
                } else if (viewType == 3) {
                    v = this.f2385c.inflate(C0415R.layout.health_list_item_wide, parent, false);
                    viewArr = new View[]{v.findViewById(C0415R.id.name), v.findViewById(C0415R.id.state), v.findViewById(C0415R.id.detail), v.findViewById(C0415R.id.only_item_tv)};
                } else {
                    v = this.f2385c.inflate(C0415R.layout.health_list_item, parent, false);
                    viewArr = new View[]{v.findViewById(C0415R.id.name), v.findViewById(C0415R.id.state), v.findViewById(C0415R.id.detail), v.findViewById(C0415R.id.only_item_tv)};
                }
                v.setTag(viewArr);
            } else {
                v = convertView;
            }
            final HealthItemResult valueByIndex = this.f2384b.getValueByIndex(position);
            if (valueByIndex != null) {
                View[] viewArr2 = (View[]) v.getTag();
                if (viewType != 0) {
                    ((TextView) viewArr2[0]).setText(valueByIndex.content);
                    LinearLayout linearLayout = (LinearLayout) viewArr2[1];
                    ((LinearLayout) viewArr2[2]).setVisibility(8);
                    switch (valueByIndex.weight) {
                        case 1:
                            m1032a(linearLayout, C0415R.drawable.health_state_red);
                            break;
                        case 3:
                            m1032a(linearLayout, C0415R.drawable.health_state_yellow);
                            break;
                        case 5:
                            if (HealthCheckupActivity.this.f2373g != 0) {
                                String str = valueByIndex.action_description;
                                TextView textView = (TextView) linearLayout.findViewById(C0415R.id.state_text);
                                TextView textView2 = (TextView) linearLayout.findViewById(C0415R.id.state_btn);
                                textView.setVisibility(8);
                                textView2.setVisibility(0);
                                textView2.setText(str);
                                textView2.setBackgroundResource(C0415R.drawable.signbtn_bg);
                                linearLayout.findViewById(C0415R.id.state_btn).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.HealthCheck.HealthCheckupActivity.HealthCheckupAdapter.2
                                    @Override // android.view.View.OnClickListener
                                    public final void onClick(View v2) {
                                        HealthCheckupActivity.this.f2372f.getHealthCheckItemByKey(valueByIndex.key).click();
                                    }
                                });
                            }
                            if (HealthCheckupActivity.this.f2373g == 2) {
                                linearLayout.findViewById(C0415R.id.state_btn).setClickable(false);
                            }
                            break;
                        case 7:
                        case 9:
                            m1032a(linearLayout, C0415R.drawable.health_state_ok);
                            break;
                    }
                } else {
                    TextView textView3 = (TextView) viewArr2[0];
                    if (valueByIndex.weight == 0) {
                        textView3.setTextColor(HealthCheckupActivity.this.getResources().getColor(C0415R.color.red1));
                    } else if (valueByIndex.weight == 8 || valueByIndex.weight == 6) {
                        textView3.setTextColor(HealthCheckupActivity.this.getResources().getColor(C0415R.color.green4));
                    } else if (valueByIndex.weight == 4) {
                        textView3.setTextColor(HealthCheckupActivity.this.getResources().getColor(C0415R.color.blue1));
                    } else {
                        textView3.setTextColor(HealthCheckupActivity.this.getResources().getColor(C0415R.color.orange1));
                    }
                    ((TextView) viewArr2[0]).setText(valueByIndex.content);
                }
            }
            return v;
        }

        /* JADX INFO: renamed from: a */
        private static void m1032a(View view, int resId) {
            TextView text = (TextView) view.findViewById(C0415R.id.state_text);
            TextView buttonText = (TextView) view.findViewById(C0415R.id.state_btn);
            text.setBackgroundResource(resId);
            buttonText.setVisibility(8);
        }
    }
}
