package com.lenovo.safecenter.safemode;

import android.app.Activity;
import android.os.Bundle;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.adapter.whiteSmsAdapter;
import com.lenovo.safecenter.support.Contract;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class ErrorWhiteSms extends Activity {

    /* JADX INFO: renamed from: a */
    private List<Contract> f5148a;

    /* JADX INFO: renamed from: b */
    private ListView f5149b;

    /* JADX INFO: renamed from: c */
    private TextView f5150c;

    /* JADX INFO: renamed from: d */
    private TextView f5151d;

    /* JADX INFO: renamed from: e */
    private whiteSmsAdapter f5152e;

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.whitesmsshowlist);
        this.f5149b = (ListView) findViewById(C0415R.id.safemode_log_list);
        this.f5150c = (TextView) findViewById(C0415R.id.safemode_empty_textview);
        this.f5151d = (TextView) findViewById(C0415R.id.txtdesc);
        this.f5151d.setVisibility(8);
        this.f5150c.setText(C0415R.string.pri_nosms);
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

    public void initData() {
        this.f5148a = new ArrayList();
        if (this.f5150c != null) {
            this.f5150c.setText(C0415R.string.no_record);
            this.f5149b.setEmptyView(this.f5150c);
        }
        this.f5152e = new whiteSmsAdapter(this, this.f5148a);
        this.f5149b.setAdapter((ListAdapter) this.f5152e);
    }
}
