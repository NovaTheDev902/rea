package com.lenovo.safecenter.antivirus.views;

import android.content.Context;
import android.content.DialogInterface;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.antivirus.domain.VirusLog;
import com.lenovo.safecenter.antivirus.support.AntiVirusDBHelper;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.utils.TrackEvent;
import java.text.SimpleDateFormat;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class LogActivity extends BaseTitleActivity {

    /* JADX INFO: renamed from: a */
    private TextView f3224a;

    /* JADX INFO: renamed from: b */
    private Button f3225b;

    /* JADX INFO: renamed from: c */
    private VirusAdapter f3226c;

    /* JADX INFO: renamed from: d */
    private ListView f3227d;

    /* JADX INFO: renamed from: e */
    private AntiVirusDBHelper f3228e;

    /* JADX INFO: renamed from: f */
    private List<VirusLog> f3229f;

    /* JADX INFO: renamed from: g */
    private Handler f3230g = new Handler() { // from class: com.lenovo.safecenter.antivirus.views.LogActivity.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    LogActivity.this.f3229f.clear();
                    LogActivity.this.f3226c.notifyDataSetChanged();
                    LogActivity.this.f3227d.invalidateViews();
                    if (LogActivity.this.f3229f.size() == 0) {
                        LogActivity.this.f3225b.setEnabled(false);
                    }
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: g */
    static /* synthetic */ void m1409g(LogActivity x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.notify).setMessage(C0415R.string.clean_logs_sure).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.LogActivity.3
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface arg0, int arg1) {
                LogActivity.this.f3228e.delLog();
                LogActivity.this.f3230g.sendEmptyMessage(1);
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.LogActivity.2
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface arg0, int arg1) {
            }
        }).show();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.antivirusmydisplaylog);
        this.f3225b = (Button) findViewById(C0415R.id.antivirusbtn_clean_logs);
        this.f3224a = (TextView) findViewById(C0415R.id.antiviruslog_txt_empty);
        this.f3227d = (ListView) findViewById(C0415R.id.antiviruslog_listview);
        this.f3227d.setDivider(null);
        this.f3228e = new AntiVirusDBHelper(this);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.antivirusscan_log, (Integer) null);
        OnBtnClick();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
        this.f3229f = this.f3228e.getLog();
        Log.i("mm", this.f3229f.size() + "=====");
        this.f3226c = new VirusAdapter(this, this.f3229f);
        this.f3227d.setAdapter((ListAdapter) this.f3226c);
        this.f3227d.setEmptyView(this.f3224a);
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    public void OnBtnClick() {
        this.f3225b.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.LogActivity.4
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                LogActivity.m1409g(LogActivity.this);
            }
        });
    }

    public String formatAllTime(String time) {
        SimpleDateFormat sdf = new SimpleDateFormat("HH:mm");
        String dateValue = sdf.format(Long.valueOf(Long.parseLong(time)));
        return dateValue;
    }

    public class VirusAdapter extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private Context f3236b;

        /* JADX INFO: renamed from: c */
        private List<VirusLog> f3237c;

        public VirusAdapter(Context context, List<VirusLog> list) {
            this.f3236b = context;
            this.f3237c = list;
        }

        @Override // android.widget.Adapter
        public int getCount() {
            return this.f3237c.size();
        }

        @Override // android.widget.Adapter
        public Object getItem(int position) {
            return this.f3237c.get(position);
        }

        @Override // android.widget.BaseAdapter, android.widget.ListAdapter
        public boolean isEnabled(int position) {
            return false;
        }

        @Override // android.widget.Adapter
        public long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            C0497a holder;
            byte b = 0;
            if (convertView == null) {
                convertView = LayoutInflater.from(this.f3236b).inflate(C0415R.layout.antivirusnew_loglist_item, (ViewGroup) null);
                holder = new C0497a(this, b);
                holder.f3238a = (LinearLayout) convertView.findViewById(C0415R.id.antiviruslog_layout);
                holder.f3239b = (TextView) convertView.findViewById(C0415R.id.antiviruslog_time);
                holder.f3240c = (TextView) convertView.findViewById(C0415R.id.antivirusevent_time);
                holder.f3241d = (TextView) convertView.findViewById(C0415R.id.antivirusevent_content);
                holder.f3243f = (ImageView) convertView.findViewById(C0415R.id.antiviruslog_icon);
                holder.f3242e = convertView.findViewById(C0415R.id.div_bg);
                convertView.setTag(holder);
            } else {
                holder = (C0497a) convertView.getTag();
            }
            VirusLog log = this.f3237c.get(position);
            if (log.logdate == null) {
                holder.f3238a.setVisibility(0);
                holder.f3241d.setText(log.eventcontent);
                holder.f3240c.setText(LogActivity.this.formatAllTime(log.eventtime));
                holder.f3239b.setVisibility(8);
                holder.f3242e.setVisibility(0);
                if (log.eventicon.equals("0")) {
                    holder.f3243f.setImageDrawable(LogActivity.this.getResources().getDrawable(C0415R.drawable.antivirusperm_grant));
                } else {
                    holder.f3243f.setImageDrawable(LogActivity.this.getResources().getDrawable(C0415R.drawable.antivirusperm_prompt));
                }
            } else {
                holder.f3239b.setVisibility(0);
                holder.f3239b.setText(log.logdate);
                holder.f3242e.setVisibility(8);
                holder.f3238a.setVisibility(8);
            }
            return convertView;
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.LogActivity$VirusAdapter$a */
        private class C0497a {

            /* JADX INFO: renamed from: a */
            LinearLayout f3238a;

            /* JADX INFO: renamed from: b */
            TextView f3239b;

            /* JADX INFO: renamed from: c */
            TextView f3240c;

            /* JADX INFO: renamed from: d */
            TextView f3241d;

            /* JADX INFO: renamed from: e */
            View f3242e;

            /* JADX INFO: renamed from: f */
            ImageView f3243f;

            private C0497a() {
            }

            /* synthetic */ C0497a(VirusAdapter x0, byte b) {
                this();
            }
        }
    }
}
