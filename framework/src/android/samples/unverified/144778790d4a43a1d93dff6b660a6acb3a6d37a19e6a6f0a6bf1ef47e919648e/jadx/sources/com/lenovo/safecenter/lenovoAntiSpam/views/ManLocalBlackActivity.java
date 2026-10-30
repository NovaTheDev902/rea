package com.lenovo.safecenter.lenovoAntiSpam.views;

import android.app.Activity;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.provider.Settings;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseExpandableListAdapter;
import android.widget.Button;
import android.widget.ExpandableListView;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase;
import com.lenovo.safecenter.lenovoAntiSpam.domain.BlackInfo;
import com.lenovo.safecenter.lenovoAntiSpam.domain.ContractHelpUtils;
import com.lenovo.safecenter.lenovoAntiSpam.utils.SafeCenter;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class ManLocalBlackActivity extends Activity {

    /* JADX INFO: renamed from: a */
    Button f4082a;

    /* JADX INFO: renamed from: b */
    AppDatabase f4083b;

    /* JADX INFO: renamed from: c */
    private ExpandableListView f4084c;

    /* JADX INFO: renamed from: d */
    private List<BlackInfo> f4085d;

    /* JADX INFO: renamed from: e */
    private int f4086e;

    /* JADX INFO: renamed from: f */
    private TextView f4087f;

    /* JADX INFO: renamed from: g */
    private C0672a f4088g;

    /* JADX INFO: renamed from: h */
    private ProgressDialog f4089h;

    /* JADX INFO: renamed from: i */
    private Handler f4090i = new HandlerC0673b(this, 0);

    /* JADX INFO: renamed from: j */
    private int f4091j;

    /* JADX INFO: renamed from: i */
    static /* synthetic */ void m1705i(ManLocalBlackActivity x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.notify).setColorPositiveButton(true).setColorNegativeButton(false).setMessage(C0415R.string.del_blackinfo).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackActivity.7
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                ManLocalBlackActivity.this.deleteBlack();
                Toast.makeText(ManLocalBlackActivity.this, C0415R.string.del_sucess, 0).show();
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackActivity.6
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackActivity$b */
    private class HandlerC0673b extends Handler {
        private HandlerC0673b() {
        }

        /* synthetic */ HandlerC0673b(ManLocalBlackActivity x0, byte b) {
            this();
        }

        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    Log.i("handler", "progress.dismiss()1;");
                    ContractHelpUtils.sendBraodcast(ManLocalBlackActivity.this, "com.lenovo.antispam.blackperson.change");
                    if (ManLocalBlackActivity.this.f4085d.size() != 0) {
                        ManLocalBlackActivity.this.f4088g.notifyDataSetChanged();
                        ManLocalBlackActivity.this.f4084c.invalidateViews();
                    } else {
                        ManLocalBlackActivity.this.initViewSys();
                    }
                    break;
                case 2:
                    if (ManLocalBlackActivity.this.f4089h != null) {
                        try {
                            ManLocalBlackActivity.this.f4089h.dismiss();
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                    Log.i("handler", "progress.dismiss()2;");
                    int str = msg.getData().getInt(QueryPermissions.f1958ID);
                    int result = msg.getData().getInt(QueryPermissions.RECOMMENDEDACTION);
                    if (result == 2) {
                        ManLocalBlackActivity.this.f4083b.updateLocalBlack(str);
                        Toast.makeText(ManLocalBlackActivity.this, C0415R.string.antispamlocalblack_successNotice, 0).show();
                        ((BlackInfo) ManLocalBlackActivity.this.f4085d.get(ManLocalBlackActivity.this.f4091j)).setIsUpload(1);
                        ManLocalBlackActivity.this.f4088g.notifyDataSetChanged();
                        ManLocalBlackActivity.this.f4084c.invalidateViews();
                    } else if (result == 1) {
                        Toast.makeText(ManLocalBlackActivity.this, C0415R.string.antispamnetdesc, 0).show();
                    } else {
                        Toast.makeText(ManLocalBlackActivity.this, C0415R.string.antispamserver_disconnect, 0).show();
                    }
                    break;
                case 5:
                    Log.i("handler", "progress.dismiss()5;");
                    if (ManLocalBlackActivity.this.f4089h != null) {
                        try {
                            ManLocalBlackActivity.this.f4089h.dismiss();
                        } catch (Exception e2) {
                            e2.printStackTrace();
                        }
                    }
                    if (ManLocalBlackActivity.this.f4085d != null) {
                        ManLocalBlackActivity.this.f4087f.setVisibility(8);
                        ManLocalBlackActivity.this.f4088g = ManLocalBlackActivity.this.new C0672a(ManLocalBlackActivity.this);
                        ManLocalBlackActivity.this.f4084c.setAdapter(ManLocalBlackActivity.this.f4088g);
                        ManLocalBlackActivity.this.f4084c.setVisibility(0);
                    } else {
                        ManLocalBlackActivity.this.f4087f.setVisibility(0);
                        ManLocalBlackActivity.this.f4084c.setVisibility(8);
                    }
                    break;
                case 6:
                    ManLocalBlackActivity.this.f4084c.invalidateViews();
                    break;
            }
        }
    }

    @Override // android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        this.f4086e = getIntent().getExtras().getInt("type");
        this.f4083b = new AppDatabase(this);
        setContentView(C0415R.layout.antispamlocalblack_view);
        this.f4084c = (ExpandableListView) findViewById(C0415R.id.addblacklist);
        this.f4084c.setDivider(getResources().getDrawable(C0415R.drawable.space_line));
        this.f4084c.setGroupIndicator(null);
        this.f4082a = (Button) findViewById(C0415R.id.sigleadd_btn);
        this.f4087f = (TextView) findViewById(C0415R.id.antispamcallempty);
        this.f4084c.setEmptyView(this.f4087f);
        if (Settings.System.getInt(getContentResolver(), "guest_mode_on", 0) == 1) {
            this.f4082a.setEnabled(false);
        }
        setOnClick();
    }

    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        }
    }

    public void initDate() {
        this.f4085d = this.f4083b.getLocalBlackList(this.f4086e);
        if (Settings.System.getInt(getContentResolver(), "guest_mode_on", 0) == 1) {
            this.f4085d = new ArrayList();
        }
        this.f4088g = new C0672a(this);
        this.f4084c.setAdapter(this.f4088g);
    }

    public void initViewSys() {
        initDate();
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        initViewSys();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    public void setOnClick() {
        this.f4084c.setOnGroupExpandListener(new ExpandableListView.OnGroupExpandListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackActivity.1
            @Override // android.widget.ExpandableListView.OnGroupExpandListener
            public final void onGroupExpand(int groupPosition) {
                ManLocalBlackActivity.this.f4091j = groupPosition;
                if (groupPosition == ManLocalBlackActivity.this.f4085d.size() - 1) {
                    ManLocalBlackActivity.this.f4084c.setTranscriptMode(2);
                } else {
                    ManLocalBlackActivity.this.f4084c.setTranscriptMode(1);
                }
                for (int i = 0; i < ManLocalBlackActivity.this.f4088g.getGroupCount(); i++) {
                    if (groupPosition != i) {
                        ManLocalBlackActivity.this.f4084c.collapseGroup(i);
                    }
                }
            }
        });
        this.f4082a.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackActivity.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                AppDatabase db_help = new AppDatabase(ManLocalBlackActivity.this);
                int count = db_help.getBlackListcount(ManLocalBlackActivity.this.f4086e);
                if (count >= 500) {
                    Toast.makeText(ManLocalBlackActivity.this, C0415R.string.antispamdata_limit1, 0).show();
                } else {
                    ManLocalBlackActivity.this.showDialog(1);
                }
            }
        });
    }

    @Override // android.app.Activity
    public Dialog onCreateDialog(int id, Bundle args) {
        switch (id) {
            case 1:
                return new CustomDialog.Builder(this).setTitle(getString(C0415R.string.antispamquick_operation)).setItems(C0415R.array.quick_add, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackActivity.3
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                        switch (which) {
                            case 0:
                                Intent intent = new Intent(ManLocalBlackActivity.this, (Class<?>) ManLocalBlackAddActivity.class);
                                intent.putExtra("type", 1);
                                ManLocalBlackActivity.this.startActivity(intent);
                                break;
                            case 1:
                                Intent intentSMS = new Intent(ManLocalBlackActivity.this, (Class<?>) ManLocalBlackAddActivity.class);
                                intentSMS.putExtra("type", 0);
                                ManLocalBlackActivity.this.startActivity(intentSMS);
                                break;
                            case 2:
                                Intent intentContract = new Intent(ManLocalBlackActivity.this, (Class<?>) ManLocalBlackAddActivity.class);
                                intentContract.putExtra("type", 4);
                                ManLocalBlackActivity.this.startActivity(intentContract);
                                break;
                            case 3:
                                Intent intentHand = new Intent(ManLocalBlackActivity.this, (Class<?>) HandBlackActivity.class);
                                intentHand.putExtra("type", ManLocalBlackActivity.this.f4086e);
                                intentHand.putExtra("method", "add");
                                ManLocalBlackActivity.this.startActivity(intentHand);
                                break;
                        }
                    }
                }).create();
            default:
                return null;
        }
    }

    public void showReportDialog() {
        new CustomDialog.Builder(this).setTitle(C0415R.string.notify).setMessage(C0415R.string.report_tonet).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackActivity.5
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                ManLocalBlackActivity.this.report(((BlackInfo) ManLocalBlackActivity.this.f4085d.get(ManLocalBlackActivity.this.f4091j)).getPhoneNumber(), ((BlackInfo) ManLocalBlackActivity.this.f4085d.get(ManLocalBlackActivity.this.f4091j)).getId());
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackActivity.4
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }

    public void deleteBlack() {
        this.f4083b.deleteLocalBlack(this.f4085d.get(this.f4091j).getId());
        this.f4085d.remove(this.f4091j);
        this.f4088g.notifyDataSetChanged();
        if (this.f4091j < this.f4085d.size()) {
            this.f4084c.collapseGroup(this.f4091j);
        }
        ContractHelpUtils.sendBraodcast(this, "com.lenovo.antispam.blackperson.change");
    }

    /* JADX WARN: Type inference failed for: r0v5, types: [com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackActivity$8] */
    public void report(final String numbers, final int sb_id) {
        this.f4089h = new ProgressDialog(this);
        this.f4089h.setProgressStyle(0);
        this.f4089h.setCanceledOnTouchOutside(false);
        this.f4089h.setMessage(getResources().getString(C0415R.string.antispamupload_state));
        this.f4089h.show();
        new Thread() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackActivity.8
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    int result = SafeCenter.upBlackToNet(ManLocalBlackActivity.this, numbers, 1);
                    Message mes = new Message();
                    mes.what = 2;
                    mes.getData().putInt(QueryPermissions.RECOMMENDEDACTION, result);
                    mes.getData().putInt(QueryPermissions.f1958ID, sb_id);
                    ManLocalBlackActivity.this.f4090i.sendMessage(mes);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    public void transteToEdit() {
        Intent intent = new Intent(this, (Class<?>) HandBlackActivity.class);
        intent.putExtra("method", "modify");
        intent.putExtra(QueryPermissions.f1958ID, this.f4085d.get(this.f4091j).getId());
        startActivity(intent);
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackActivity$a */
    class C0672a extends BaseExpandableListAdapter {

        /* JADX INFO: renamed from: a */
        Context f4102a;

        /* JADX INFO: renamed from: b */
        b f4103b;

        /* JADX INFO: renamed from: c */
        a f4104c;

        /* JADX INFO: renamed from: e */
        private LayoutInflater f4106e;

        public C0672a(Context context) {
            this.f4106e = LayoutInflater.from(context);
            this.f4102a = context;
        }

        @Override // android.widget.ExpandableListAdapter
        public final Object getChild(int groupPosition, int childPosition) {
            return null;
        }

        @Override // android.widget.ExpandableListAdapter
        public final long getChildId(int groupPosition, int childPosition) {
            return childPosition;
        }

        @Override // android.widget.ExpandableListAdapter
        public final int getChildrenCount(int groupPosition) {
            return 1;
        }

        @Override // android.widget.ExpandableListAdapter
        public final View getChildView(int groupPosition, int childPosition, boolean isLastChild, View convertView, ViewGroup parent) {
            if (convertView == null) {
                convertView = this.f4106e.inflate(C0415R.layout.dealitemequal, (ViewGroup) null);
                this.f4104c = new a();
                this.f4104c.f4110a = (TextView) convertView.findViewById(C0415R.id.deal1);
                this.f4104c.f4111b = (TextView) convertView.findViewById(C0415R.id.deal2);
                this.f4104c.f4112c = (TextView) convertView.findViewById(C0415R.id.deal3);
                convertView.setTag(this.f4104c);
            } else {
                this.f4104c = (a) convertView.getTag();
            }
            this.f4104c.f4110a.setText(C0415R.string.send_off_report);
            this.f4104c.f4111b.setText(C0415R.string.mutil_edit);
            this.f4104c.f4112c.setText(C0415R.string.delete);
            this.f4104c.f4110a.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackActivity.a.1
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    if (((BlackInfo) ManLocalBlackActivity.this.f4085d.get(ManLocalBlackActivity.this.f4091j)).getIsUpload() == 0) {
                        ManLocalBlackActivity.this.showReportDialog();
                    } else {
                        Toast.makeText(ManLocalBlackActivity.this, C0415R.string.havedup, 0).show();
                    }
                }
            });
            this.f4104c.f4111b.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackActivity.a.2
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    ManLocalBlackActivity.this.transteToEdit();
                }
            });
            this.f4104c.f4112c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackActivity.a.3
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    ManLocalBlackActivity.m1705i(ManLocalBlackActivity.this);
                }
            });
            return convertView;
        }

        @Override // android.widget.ExpandableListAdapter
        public final Object getGroup(int groupPosition) {
            return ManLocalBlackActivity.this.f4085d.get(groupPosition);
        }

        @Override // android.widget.ExpandableListAdapter
        public final int getGroupCount() {
            return ManLocalBlackActivity.this.f4085d.size();
        }

        @Override // android.widget.ExpandableListAdapter
        public final long getGroupId(int groupPosition) {
            return groupPosition;
        }

        @Override // android.widget.ExpandableListAdapter
        public final View getGroupView(int groupPosition, boolean isExpanded, View convertView, ViewGroup parent) {
            if (convertView == null) {
                convertView = LayoutInflater.from(this.f4102a).inflate(C0415R.layout.antispamblackinfo_item1, (ViewGroup) null);
                this.f4103b = new b();
                this.f4103b.f4114a = (ImageView) convertView.findViewById(C0415R.id.antispamblack_image);
                this.f4103b.f4117d = (TextView) convertView.findViewById(C0415R.id.antispamlocalblack_name);
                this.f4103b.f4118e = (TextView) convertView.findViewById(C0415R.id.antispamlocalblack_number);
                this.f4103b.f4116c = (ImageView) convertView.findViewById(C0415R.id.antispamisupload);
                this.f4103b.f4115b = (ImageView) convertView.findViewById(C0415R.id.antispamblack_check);
                convertView.setTag(this.f4103b);
            } else {
                this.f4103b = (b) convertView.getTag();
            }
            BlackInfo info = (BlackInfo) ManLocalBlackActivity.this.f4085d.get(groupPosition);
            this.f4103b.f4115b.setVisibility(8);
            if (info.getIsUpload() == 0) {
                this.f4103b.f4116c.setVisibility(8);
            } else if (info.getIsUpload() == 1) {
                this.f4103b.f4116c.setVisibility(0);
            }
            this.f4103b.f4118e.setText(info.getPhoneNumber());
            if (info.getName() == null || info.getName().equals("")) {
                this.f4103b.f4117d.setText(m1706a(info.getType()));
            } else {
                this.f4103b.f4117d.setText(info.getName() + m1706a(info.getType()));
            }
            this.f4103b.f4114a.setImageResource(C0415R.drawable.antispamblack);
            return convertView;
        }

        @Override // android.widget.ExpandableListAdapter
        public final boolean hasStableIds() {
            return false;
        }

        @Override // android.widget.ExpandableListAdapter
        public final boolean isChildSelectable(int groupPosition, int childPosition) {
            return false;
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackActivity$a$b */
        class b {

            /* JADX INFO: renamed from: a */
            ImageView f4114a;

            /* JADX INFO: renamed from: b */
            ImageView f4115b;

            /* JADX INFO: renamed from: c */
            ImageView f4116c;

            /* JADX INFO: renamed from: d */
            TextView f4117d;

            /* JADX INFO: renamed from: e */
            TextView f4118e;

            b() {
            }
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackActivity$a$a */
        class a {

            /* JADX INFO: renamed from: a */
            TextView f4110a;

            /* JADX INFO: renamed from: b */
            TextView f4111b;

            /* JADX INFO: renamed from: c */
            TextView f4112c;

            a() {
            }
        }

        /* JADX INFO: renamed from: a */
        private String m1706a(int type) {
            if (type == 2) {
                return this.f4102a.getResources().getString(C0415R.string.harss_method1);
            }
            if (type == 1) {
                return this.f4102a.getResources().getString(C0415R.string.harss_method2);
            }
            if (type == 0) {
                return this.f4102a.getResources().getString(C0415R.string.harss_method3);
            }
            return this.f4102a.getResources().getString(C0415R.string.harss_method4);
        }
    }
}
