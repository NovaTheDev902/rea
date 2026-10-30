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
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.adapter.whiteSmsAdapter;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.support.Contract;
import com.lenovo.safecenter.support.HttpUtils;
import com.lenovo.safecenter.utils.Constant;
import com.lenovo.safecenter.utils.ContractHelpUtils;
import com.lenovo.safecenter.utils.DataHelpUtils;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class WhiteSms extends Activity {

    /* JADX INFO: renamed from: a */
    NotificationManager f5289a;

    /* JADX INFO: renamed from: b */
    private List<Contract> f5290b;

    /* JADX INFO: renamed from: c */
    private AppDatabase f5291c;

    /* JADX INFO: renamed from: d */
    private int f5292d;

    /* JADX INFO: renamed from: e */
    private ListView f5293e;

    /* JADX INFO: renamed from: f */
    private TextView f5294f;

    /* JADX INFO: renamed from: g */
    private Button f5295g;

    /* JADX INFO: renamed from: h */
    private whiteSmsAdapter f5296h;

    /* JADX INFO: renamed from: i */
    private ContractHelpUtils f5297i;

    /* JADX INFO: renamed from: j */
    private boolean f5298j = false;
    public Handler hand = new Handler() { // from class: com.lenovo.safecenter.safemode.WhiteSms.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    WhiteSms.this.initData();
                    SofeModeMain activity = (SofeModeMain) DataHelpUtils.getActivityByName("SofeModeMain");
                    activity.hand.sendEmptyMessage(1);
                    WhiteSms.this.f5289a.cancel(Constant.SMS_NOTI_ID);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m2175a(WhiteSms x0, final Contract x1) {
        String[] strArr = {x0.getString(C0415R.string.replay_sms), x0.getString(C0415R.string.safemode_callto), x0.getString(C0415R.string.del_safesms)};
        String name = x1.getName();
        if (x1.getName() == null) {
            name = x1.getPhoneNumber();
        }
        new CustomDialog.Builder(x0).setTitle(name).setItems(strArr, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteSms.7
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                switch (which) {
                    case 0:
                        try {
                            Intent smsIntent = new Intent(WhiteSms.this, (Class<?>) WhiteSmsShowByNumber.class);
                            smsIntent.putExtra(AppDatabase.NUMBER, x1.getPhoneNumber());
                            WhiteSms.this.startActivity(smsIntent);
                        } catch (Exception e) {
                            e.printStackTrace();
                            Toast.makeText(WhiteSms.this, C0415R.string.opensms_error, 0).show();
                            return;
                        }
                        break;
                    case 1:
                        try {
                            Intent callIntent = new Intent("android.intent.action.CALL", Uri.parse("tel:" + x1.getPhoneNumber()));
                            WhiteSms.this.startActivity(callIntent);
                        } catch (Exception e2) {
                            Toast.makeText(WhiteSms.this, C0415R.string.opensms_error, 0).show();
                            e2.printStackTrace();
                            return;
                        }
                        break;
                    case 2:
                        WhiteSms.this.f5291c.deleteSms(x1.getPhoneNumber());
                        WhiteSms.this.f5290b.remove(WhiteSms.this.f5292d);
                        WhiteSms.this.f5296h.notifyDataSetChanged();
                        WhiteSms.this.f5293e.invalidateViews();
                        break;
                }
            }
        }).create().show();
    }

    /* JADX INFO: renamed from: c */
    static /* synthetic */ void m2177c(WhiteSms x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.notify).setMessage(C0415R.string.del_record).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteSms.6
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface arg0, int arg1) {
                WhiteSms.this.f5291c.deleteSms(-1);
                WhiteSms.this.f5290b.clear();
                WhiteSms.this.f5296h.notifyDataSetChanged();
                WhiteSms.this.f5293e.invalidateViews();
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteSms.5
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
        this.f5293e = (ListView) findViewById(C0415R.id.safemode_log_list);
        this.f5294f = (TextView) findViewById(C0415R.id.safemode_empty_textview);
        findViewById(C0415R.id.whitecall_del).setVisibility(0);
        findViewById(C0415R.id.safemode_lin_operate).setVisibility(0);
        findViewById(C0415R.id.lin_operateinner).setVisibility(8);
        this.f5295g = (Button) findViewById(C0415R.id.del_whitecall);
        this.f5291c = new AppDatabase(this);
        this.f5297i = new ContractHelpUtils();
        DataHelpUtils.allActivity.add(this);
        this.f5294f.setText(C0415R.string.pri_nosms);
        onBtnClick();
        this.f5289a = (NotificationManager) getSystemService(DatabaseTables.LOG_NOTIFICATION);
        this.f5289a.cancel(Constant.SMS_NOTI_ID);
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        initData();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    public void onBtnClick() {
        Log.i("txtEmpty", this.f5293e + "");
        this.f5293e.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteSms.2
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                HttpUtils.private_isOpenSec = true;
                Contract con = (Contract) WhiteSms.this.f5293e.getItemAtPosition(position);
                Intent intent_number = new Intent(WhiteSms.this, (Class<?>) WhiteSmsShowByNumber.class);
                intent_number.putExtra(AppDatabase.NUMBER, con.getPhoneNumber());
                WhiteSms.this.startActivity(intent_number);
            }
        });
        this.f5293e.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteSms.3
            @Override // android.widget.AdapterView.OnItemLongClickListener
            public final boolean onItemLongClick(AdapterView<?> arg0, View arg1, int arg2, long arg3) {
                WhiteSms.this.f5292d = arg2;
                Contract con = (Contract) WhiteSms.this.f5293e.getItemAtPosition(arg2);
                WhiteSms.m2175a(WhiteSms.this, con);
                return true;
            }
        });
        this.f5295g.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteSms.4
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (WhiteSms.this.f5290b.size() > 0) {
                    try {
                        WhiteSms.m2177c(WhiteSms.this);
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            }
        });
    }

    public void initData() {
        if (!this.f5298j) {
            try {
                this.f5298j = true;
                this.f5290b = this.f5291c.getwhiteSms();
                this.f5290b = this.f5297i.getWhiteSMS(this.f5290b);
                Log.i("txtEmpty", this.f5294f + "==list" + this.f5293e);
                if (this.f5294f != null) {
                    this.f5293e.setEmptyView(this.f5294f);
                }
                if (this.f5290b != null) {
                    this.f5296h = new whiteSmsAdapter(this, this.f5290b);
                    this.f5293e.setAdapter((ListAdapter) this.f5296h);
                }
                this.f5298j = false;
            } catch (Exception e) {
                e.printStackTrace();
                this.f5298j = false;
            }
        }
    }

    @Override // android.app.Activity
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case 0:
                HttpUtils.private_isOpenSec = true;
                Intent intent_del = new Intent(this, (Class<?>) ManWhiteSms.class);
                intent_del.putExtra("type", 0);
                startActivity(intent_del);
                break;
            case 1:
                HttpUtils.private_isOpenSec = true;
                Intent intent_recover = new Intent(this, (Class<?>) ManWhiteSms.class);
                intent_recover.putExtra("type", 1);
                startActivity(intent_recover);
                break;
            case 2:
                this.f5291c.updateSmsStatus(0);
                Log.i("Parent", getParent() + "");
                if (DataHelpUtils.getActivityByName("SofeModeMain") != null) {
                    SofeModeMain activity = (SofeModeMain) DataHelpUtils.getActivityByName("SofeModeMain");
                    activity.hand.sendEmptyMessage(1);
                }
                break;
        }
        return super.onOptionsItemSelected(item);
    }
}
