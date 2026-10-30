package com.lenovo.safecenter.floatwindow.view;

import android.content.Context;
import android.os.Handler;
import android.os.Message;
import android.util.AttributeSet;
import android.view.View;
import android.widget.AdapterView;
import android.widget.GridView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.TextView;
import com.lenovo.performancecenter.coreui.util.RootPassage;
import com.lenovo.performancecenter.performance.ScanApplicationInfo;
import com.lenovo.performancecenter.service.object.UsedAppInfo;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.floatwindow.adapter.TaskAdapter;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

/* JADX INFO: loaded from: classes.dex */
public class ProcessRunningView extends LinearLayout {
    public static final int SWITCHER_VIEW = 200;
    public static ProcessRunningView processrunning;

    /* JADX INFO: renamed from: a */
    private GridView f3684a;

    /* JADX INFO: renamed from: b */
    private TaskAdapter f3685b;

    /* JADX INFO: renamed from: c */
    private TextView f3686c;
    public Context context;

    /* JADX INFO: renamed from: d */
    private CommonLoadingAnim f3687d;

    /* JADX INFO: renamed from: e */
    private Handler f3688e;

    /* JADX INFO: renamed from: f */
    private List<UsedAppInfo> f3689f;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ ArrayList m1558a(Context x1) {
        ArrayList arrayList = new ArrayList();
        for (Map.Entry<String, int[]> entry : ScanApplicationInfo.getRunningAppInfoJustInLauncher(x1).entrySet()) {
            if (entry.getValue()[2] == 1) {
                arrayList.add(new UsedAppInfo(entry.getKey(), entry.getValue()[1]));
            }
        }
        return arrayList;
    }

    /* JADX WARN: Type inference failed for: r0v0, types: [com.lenovo.safecenter.floatwindow.view.ProcessRunningView$2] */
    /* JADX INFO: renamed from: c */
    static /* synthetic */ void m1561c(ProcessRunningView x0) {
        new Thread() { // from class: com.lenovo.safecenter.floatwindow.view.ProcessRunningView.2
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                ProcessRunningView processRunningView = ProcessRunningView.this;
                ProcessRunningView processRunningView2 = ProcessRunningView.this;
                processRunningView.f3689f = ProcessRunningView.m1558a(ProcessRunningView.this.context);
                if (ProcessRunningView.this.f3689f.size() == 0) {
                    ProcessRunningView.this.f3688e.sendEmptyMessage(2);
                    return;
                }
                ProcessRunningView.this.f3685b = new TaskAdapter(ProcessRunningView.this.context, ProcessRunningView.this.f3689f);
                ProcessRunningView.this.f3688e.sendEmptyMessage(1);
            }
        }.start();
    }

    public ProcessRunningView(Context context, AttributeSet attrs) {
        super(context, attrs);
        this.context = context;
        this.f3689f = new ArrayList();
        this.f3688e = new HandlerC0575a(this, (byte) 0);
        inflate(this.context, C0415R.layout.assist_process_running_view, this);
        this.f3684a = (GridView) findViewById(C0415R.id.float_grid1);
        this.f3686c = (TextView) findViewById(C0415R.id.running_process_empty);
        this.f3687d = (CommonLoadingAnim) findViewById(C0415R.id.loading_anim);
        this.f3688e.sendEmptyMessage(0);
        this.f3684a.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.floatwindow.view.ProcessRunningView.1
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                RootPassage.execRootCmd(((UsedAppInfo) ProcessRunningView.this.f3689f.get(position)).packageName, " -fs ", ProcessRunningView.this.context);
                ProcessClearView.instanceClearView.updateRunningView(((UsedAppInfo) ProcessRunningView.this.f3689f.get(position)).memroy / 1024);
                ProcessRunningView.this.f3689f.remove(position);
                ProcessRunningView.this.f3685b.notifyDataSetChanged();
                if (ProcessRunningView.this.f3689f.size() == 0) {
                    ProcessRunningView.this.clear_view();
                }
            }
        });
        processrunning = this;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.floatwindow.view.ProcessRunningView$a */
    private class HandlerC0575a extends Handler {
        private HandlerC0575a() {
        }

        /* synthetic */ HandlerC0575a(ProcessRunningView x0, byte b) {
            this();
        }

        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            super.handleMessage(msg);
            switch (msg.what) {
                case 0:
                    ProcessRunningView.this.f3684a.setVisibility(8);
                    ProcessRunningView.this.f3687d.setVisibility(0);
                    ProcessRunningView.m1561c(ProcessRunningView.this);
                    break;
                case 1:
                    ProcessRunningView.this.f3687d.setVisibility(8);
                    ProcessRunningView.this.f3684a.setVisibility(0);
                    ProcessRunningView.this.f3684a.setAdapter((ListAdapter) ProcessRunningView.this.f3685b);
                    break;
                case 2:
                    ProcessRunningView.this.f3687d.setVisibility(8);
                    ProcessRunningView.this.clear_view();
                    break;
            }
        }
    }

    public void clear_view() {
        this.f3684a.setVisibility(8);
        this.f3686c.setVisibility(0);
    }
}
