package com.lenovo.safecenter.safemode;

import android.app.Activity;
import android.app.NotificationManager;
import android.content.DialogInterface;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.KeyEvent;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.adapter.ManwhiteSmsAdapter;
import com.lenovo.safecenter.adapter.whiteSmsAdapter;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.support.Contract;
import com.lenovo.safecenter.utils.Constant;
import com.lenovo.safecenter.utils.DataHelpUtils;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class WhiteCall extends Activity {

    /* JADX INFO: renamed from: a */
    NotificationManager f5219a;

    /* JADX INFO: renamed from: b */
    private List<Contract> f5220b;

    /* JADX INFO: renamed from: c */
    private AppDatabase f5221c;

    /* JADX INFO: renamed from: d */
    private ListView f5222d;

    /* JADX INFO: renamed from: e */
    private TextView f5223e;

    /* JADX INFO: renamed from: f */
    private LinearLayout f5224f;

    /* JADX INFO: renamed from: g */
    private LinearLayout f5225g;

    /* JADX INFO: renamed from: h */
    private LinearLayout f5226h;

    /* JADX INFO: renamed from: i */
    private BaseAdapter f5227i;

    /* JADX INFO: renamed from: k */
    private int f5229k;

    /* JADX INFO: renamed from: l */
    private Button f5230l;

    /* JADX INFO: renamed from: j */
    private int f5228j = 0;
    public Handler hand = new Handler() { // from class: com.lenovo.safecenter.safemode.WhiteCall.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    SofeModeMain activity = (SofeModeMain) DataHelpUtils.getActivityByName("SofeModeMain");
                    activity.hand.sendEmptyMessage(2);
                    WhiteCall.this.f5219a.cancel(Constant.CALL_NOTI_ID);
                    WhiteCall.this.initData();
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m2156a(WhiteCall x0, final Contract x1) {
        String[] strArr = {x0.getString(C0415R.string.replay_sms), x0.getString(C0415R.string.safemode_callto), x0.getString(C0415R.string.delete_sms)};
        String name = x1.getName();
        if (x1.getName() == null) {
            name = x1.getPhoneNumber();
        }
        new CustomDialog.Builder(x0).setTitle(name).setItems(strArr, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteCall.6
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                switch (which) {
                    case 0:
                        try {
                            Intent smsIntent = new Intent(WhiteCall.this, (Class<?>) WhiteSmsShowByNumber.class);
                            smsIntent.putExtra(AppDatabase.NUMBER, x1.getPhoneNumber());
                            WhiteCall.this.startActivity(smsIntent);
                        } catch (Exception e) {
                            e.printStackTrace();
                            Toast.makeText(WhiteCall.this, C0415R.string.opensms_error, 0).show();
                            return;
                        }
                        break;
                    case 1:
                        try {
                            Intent callIntent = new Intent("android.intent.action.CALL", Uri.parse("tel:" + x1.getPhoneNumber()));
                            WhiteCall.this.startActivity(callIntent);
                        } catch (Exception e2) {
                            Toast.makeText(WhiteCall.this, C0415R.string.opensms_error, 0).show();
                            e2.printStackTrace();
                            return;
                        }
                        break;
                    case 2:
                        WhiteCall.this.f5221c.deleteCall(x1.getId());
                        WhiteCall.this.f5220b.remove(WhiteCall.this.f5229k);
                        WhiteCall.this.f5227i.notifyDataSetChanged();
                        WhiteCall.this.f5222d.invalidateViews();
                        break;
                }
            }
        }).create().show();
    }

    /* JADX INFO: renamed from: e */
    static /* synthetic */ void m2160e(WhiteCall x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.notify).setMessage(C0415R.string.del_record).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteCall.5
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface arg0, int arg1) {
                WhiteCall.this.f5221c.deleteAllCall();
                WhiteCall.this.f5220b.clear();
                WhiteCall.this.f5227i.notifyDataSetChanged();
                WhiteCall.this.f5222d.invalidateViews();
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteCall.4
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface arg0, int arg1) {
            }
        }).show();
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.whitesmsshowlist);
        ((TextView) findViewById(C0415R.id.txt_title)).setText(C0415R.string.privacy_safe);
        this.f5226h = (LinearLayout) findViewById(C0415R.id.lin_operateinner);
        this.f5224f = (LinearLayout) findViewById(C0415R.id.whitecall_del);
        this.f5225g = (LinearLayout) findViewById(C0415R.id.safemode_lin_operate);
        this.f5224f.setVisibility(0);
        this.f5225g.setVisibility(0);
        this.f5226h.setVisibility(8);
        this.f5222d = (ListView) findViewById(C0415R.id.safemode_log_list);
        this.f5223e = (TextView) findViewById(C0415R.id.safemode_empty_textview);
        this.f5230l = (Button) findViewById(C0415R.id.del_whitecall);
        this.f5230l.setText(C0415R.string.record_button_clear);
        this.f5223e.setText(C0415R.string.pri_nocall);
        this.f5221c = new AppDatabase(this);
        this.f5219a = (NotificationManager) getSystemService(DatabaseTables.LOG_NOTIFICATION);
        DataHelpUtils.allActivity.add(this);
        onClick();
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        initData();
        NotificationManager nmanager = (NotificationManager) getSystemService(DatabaseTables.LOG_NOTIFICATION);
        nmanager.cancel(Constant.CALL_NOTI_ID);
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        super.onPause();
        this.f5221c.updateCall();
        if (DataHelpUtils.getActivityByName("SofeModeMain") != null) {
            SofeModeMain activity = (SofeModeMain) DataHelpUtils.getActivityByName("SofeModeMain");
            activity.hand.sendEmptyMessage(2);
        }
        TrackEvent.trackPause(this);
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode != 4 || this.f5228j != 1) {
            return false;
        }
        for (Contract con : this.f5220b) {
            con.setSelect(false);
        }
        this.f5228j = 0;
        this.f5227i = new whiteSmsAdapter(this, this.f5220b);
        this.f5222d.setAdapter((ListAdapter) this.f5227i);
        return true;
    }

    public void onClick() {
        this.f5222d.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteCall.2
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Contract con = (Contract) WhiteCall.this.f5222d.getItemAtPosition(position);
                if (WhiteCall.this.f5228j == 0) {
                    WhiteCall.this.f5229k = position;
                    WhiteCall.m2156a(WhiteCall.this, con);
                    WhiteCall.this.f5221c.updateCall(con.getId());
                    con.setIsRead(0);
                    WhiteCall.this.f5222d.invalidateViews();
                }
                if (WhiteCall.this.f5228j == 1) {
                    if (con.isSelect()) {
                        con.setSelect(false);
                    } else {
                        con.setSelect(true);
                    }
                    WhiteCall.this.f5222d.invalidateViews();
                }
            }
        });
        this.f5230l.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteCall.3
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (WhiteCall.this.f5220b.size() > 0) {
                    try {
                        WhiteCall.m2160e(WhiteCall.this);
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            }
        });
    }

    public void initData() {
        this.f5220b = this.f5221c.getAllCall();
        Log.i("txtEmpty", this.f5223e + "==list" + this.f5220b);
        if (this.f5223e != null) {
            this.f5222d.setEmptyView(this.f5223e);
        }
        if (this.f5228j == 0) {
            this.f5227i = new whiteSmsAdapter(this, this.f5220b);
        } else if (this.f5228j == 1) {
            this.f5227i = new ManwhiteSmsAdapter(this, this.f5220b);
        }
        this.f5222d.setAdapter((ListAdapter) this.f5227i);
    }

    @Override // android.app.Activity
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case 0:
                List<Contract> select_list = new ArrayList<>();
                for (int i = this.f5220b.size() - 1; i >= 0; i--) {
                    if (this.f5220b.get(i).isSelect()) {
                        select_list.add(this.f5220b.get(i));
                        this.f5220b.remove(i);
                    }
                }
                if (select_list.size() > 0) {
                    this.f5221c.deleteCall(select_list);
                    this.f5228j = 0;
                    this.f5227i = new whiteSmsAdapter(this, this.f5220b);
                    this.f5222d.setAdapter((ListAdapter) this.f5227i);
                    SofeModeMain activity = (SofeModeMain) DataHelpUtils.getActivityByName("SofeModeMain");
                    activity.hand.sendEmptyMessage(2);
                }
                break;
            case 4:
                this.f5228j = 1;
                this.f5227i = new ManwhiteSmsAdapter(this, this.f5220b);
                this.f5222d.setAdapter((ListAdapter) this.f5227i);
                break;
            case 5:
                for (Contract con : this.f5220b) {
                    con.setSelect(true);
                }
                this.f5222d.invalidateViews();
                break;
            case 6:
                for (Contract con2 : this.f5220b) {
                    con2.setSelect(false);
                }
                this.f5222d.invalidateViews();
                break;
        }
        return super.onOptionsItemSelected(item);
    }
}
