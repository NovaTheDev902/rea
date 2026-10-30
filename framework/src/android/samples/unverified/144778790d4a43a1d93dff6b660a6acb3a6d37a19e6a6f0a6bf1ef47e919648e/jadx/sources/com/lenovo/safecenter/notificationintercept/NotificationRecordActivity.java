package com.lenovo.safecenter.notificationintercept;

import android.app.Activity;
import android.content.ContentValues;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseExpandableListAdapter;
import android.widget.ExpandableListView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.performancecenter.performance.ScanApplicationInfo;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.notificationintercept.support.InterceptPermission;
import com.lenovo.safecenter.notificationintercept.support.InterceptRecord;
import com.lenovo.safecenter.notificationintercept.support.PermissionDB;
import com.lenovo.safecenter.notificationintercept.support.RecordDB;
import com.lenovo.safecenter.utils.TrackEvent;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class NotificationRecordActivity extends Activity implements View.OnClickListener {

    /* JADX INFO: renamed from: a */
    private C0802b f4768a;

    /* JADX INFO: renamed from: b */
    private ExpandableListView f4769b;

    /* JADX INFO: renamed from: d */
    private PackageManager f4771d;

    /* JADX INFO: renamed from: e */
    private ImageView f4772e;

    /* JADX INFO: renamed from: f */
    private LinearLayout f4773f;

    /* JADX INFO: renamed from: g */
    private RelativeLayout f4774g;

    /* JADX INFO: renamed from: i */
    private TextView f4776i;

    /* JADX INFO: renamed from: c */
    private List<C0801a> f4770c = new ArrayList();

    /* JADX INFO: renamed from: h */
    private int f4775h = -1;

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(1);
        setContentView(C0415R.layout.notification_record);
        this.f4776i = (TextView) findViewById(C0415R.id.txt_title);
        findViewById(C0415R.id.title_back).setOnClickListener(this);
        findViewById(C0415R.id.record_clear_all).setOnClickListener(this);
        this.f4774g = (RelativeLayout) findViewById(C0415R.id.record_empty);
        this.f4773f = (LinearLayout) findViewById(C0415R.id.layout_record_clearn);
        this.f4772e = (ImageView) findViewById(C0415R.id.divide_record_clearn);
        this.f4769b = (ExpandableListView) findViewById(C0415R.id.expandListView_record);
        this.f4771d = getPackageManager();
        this.f4776i.setText(getString(C0415R.string.notification_record_intercept));
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
        m1978a();
        this.f4768a = new C0802b();
        this.f4769b.setAdapter(this.f4768a);
        this.f4769b.setGroupIndicator(null);
        this.f4769b.setOnGroupExpandListener(new ExpandableListView.OnGroupExpandListener() { // from class: com.lenovo.safecenter.notificationintercept.NotificationRecordActivity.1
            @Override // android.widget.ExpandableListView.OnGroupExpandListener
            public final void onGroupExpand(int groupPosition) {
                if (NotificationRecordActivity.this.f4775h != -1 && NotificationRecordActivity.this.f4775h != groupPosition) {
                    NotificationRecordActivity.this.f4769b.collapseGroup(NotificationRecordActivity.this.f4775h);
                }
                NotificationRecordActivity.this.f4775h = groupPosition;
                if (groupPosition == NotificationRecordActivity.this.f4770c.size() - 1) {
                    NotificationRecordActivity.this.f4769b.setTranscriptMode(2);
                } else {
                    NotificationRecordActivity.this.f4769b.setTranscriptMode(1);
                }
            }
        });
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        SharedPreferences.Editor editorEdit = PreferenceManager.getDefaultSharedPreferences(this).edit();
        editorEdit.putInt(InterceptUtils.INTERCEPT_NEW_COUNT, 0);
        editorEdit.commit();
        super.onPause();
    }

    /* JADX INFO: renamed from: a */
    private void m1978a() {
        Drawable applicationIcon;
        this.f4770c.clear();
        RecordDB recordDB = new RecordDB(this);
        List<InterceptRecord> findAll = recordDB.findAll();
        recordDB.closeDatabase();
        Log.i("yincc", " findAll.size == " + findAll.size());
        for (int i = 0; i < findAll.size(); i++) {
            InterceptRecord record = findAll.get(i);
            C0801a bean = new C0801a();
            bean.f4778a = record.timestamp;
            String pkgname = record.pkgname;
            String applicationLabel = record.applabel;
            try {
                applicationIcon = this.f4771d.getApplicationIcon(pkgname);
            } catch (PackageManager.NameNotFoundException e) {
                e.printStackTrace();
                Log.e("yincc", " NameNotFoundException !" + pkgname);
                applicationIcon = getResources().getDrawable(C0415R.drawable.icon3);
            }
            bean.f4779b = applicationIcon;
            bean.f4780c = applicationLabel;
            if ("".equals(record.notificationContent)) {
                bean.f4781d = getString(C0415R.string.intercept_record_none);
            } else {
                bean.f4781d = record.notificationContent;
            }
            bean.f4782e = record.pkgname;
            bean.f4783f = record._id;
            bean.f4784g = record.recordPermission;
            this.f4770c.add(bean);
        }
        if (this.f4770c.size() == 0) {
            this.f4774g.setVisibility(0);
            this.f4773f.setVisibility(8);
            this.f4772e.setVisibility(8);
        } else {
            this.f4774g.setVisibility(8);
            this.f4773f.setVisibility(0);
            this.f4772e.setVisibility(0);
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.notificationintercept.NotificationRecordActivity$b */
    class C0802b extends BaseExpandableListAdapter {

        /* JADX INFO: renamed from: b */
        private LayoutInflater f4787b;

        public C0802b() {
            this.f4787b = (LayoutInflater) NotificationRecordActivity.this.getSystemService("layout_inflater");
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
        public final View getChildView(int groupPosition, int childPosition, boolean isLastChild, View convertView, ViewGroup parent) {
            if (convertView == null) {
                return this.f4787b.inflate(C0415R.layout.notification_expand_child_record, (ViewGroup) null);
            }
            return convertView;
        }

        @Override // android.widget.ExpandableListAdapter
        public final int getChildrenCount(int groupPosition) {
            return 1;
        }

        @Override // android.widget.ExpandableListAdapter
        public final Object getGroup(int groupPosition) {
            return NotificationRecordActivity.this.f4770c.get(groupPosition);
        }

        @Override // android.widget.ExpandableListAdapter
        public final int getGroupCount() {
            return NotificationRecordActivity.this.f4770c.size();
        }

        @Override // android.widget.ExpandableListAdapter
        public final long getGroupId(int groupPosition) {
            return groupPosition;
        }

        @Override // android.widget.ExpandableListAdapter
        public final View getGroupView(int groupPosition, boolean isExpanded, View convertView, ViewGroup parent) {
            C0803c groupHolder;
            if (convertView == null) {
                groupHolder = NotificationRecordActivity.this.new C0803c();
                convertView = this.f4787b.inflate(C0415R.layout.notification_expand_group_record, (ViewGroup) null);
                groupHolder.f4788a = (ImageView) convertView.findViewById(C0415R.id.app_icon);
                groupHolder.f4789b = (TextView) convertView.findViewById(C0415R.id.app_label);
                groupHolder.f4790c = (TextView) convertView.findViewById(C0415R.id.notification_content_text);
                groupHolder.f4791d = (TextView) convertView.findViewById(C0415R.id.notification_intecept_time);
                groupHolder.f4792e = (TextView) convertView.findViewById(C0415R.id.notification_intecept_permission);
                convertView.setTag(groupHolder);
            } else {
                groupHolder = (C0803c) convertView.getTag();
            }
            C0801a notiBean = (C0801a) NotificationRecordActivity.this.f4770c.get(groupPosition);
            if (notiBean != null) {
                synchronized (notiBean) {
                    groupHolder.f4788a.setImageDrawable(notiBean.f4779b);
                    groupHolder.f4789b.setText(notiBean.f4780c);
                    groupHolder.f4790c.setText(notiBean.f4781d);
                    SimpleDateFormat dateFormat = new SimpleDateFormat("HH:mm MM-dd");
                    groupHolder.f4791d.setText(dateFormat.format(Long.valueOf(notiBean.f4778a)));
                    if (notiBean.f4784g == 1) {
                        groupHolder.f4792e.setText(NotificationRecordActivity.this.getString(C0415R.string.notification_record_allow));
                        groupHolder.f4792e.setTextColor(NotificationRecordActivity.this.getResources().getColor(C0415R.color.green_allow));
                    } else {
                        groupHolder.f4792e.setText(NotificationRecordActivity.this.getString(C0415R.string.notification_record_forbid));
                        groupHolder.f4792e.setTextColor(NotificationRecordActivity.this.getResources().getColor(C0415R.color.red_forbid));
                    }
                    if (NotificationRecordActivity.this.f4775h == groupPosition && NotificationRecordActivity.this.f4769b.isGroupExpanded(groupPosition)) {
                        groupHolder.f4790c.setSingleLine(false);
                    } else {
                        groupHolder.f4790c.setSingleLine(true);
                    }
                }
            }
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
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.notificationintercept.NotificationRecordActivity$a */
    class C0801a {

        /* JADX INFO: renamed from: a */
        public long f4778a;

        /* JADX INFO: renamed from: b */
        public Drawable f4779b;

        /* JADX INFO: renamed from: c */
        public CharSequence f4780c;

        /* JADX INFO: renamed from: d */
        public CharSequence f4781d;

        /* JADX INFO: renamed from: e */
        public String f4782e;

        /* JADX INFO: renamed from: f */
        public int f4783f;

        /* JADX INFO: renamed from: g */
        public int f4784g;

        C0801a() {
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.notificationintercept.NotificationRecordActivity$c */
    class C0803c {

        /* JADX INFO: renamed from: a */
        public ImageView f4788a;

        /* JADX INFO: renamed from: b */
        public TextView f4789b;

        /* JADX INFO: renamed from: c */
        public TextView f4790c;

        /* JADX INFO: renamed from: d */
        public TextView f4791d;

        /* JADX INFO: renamed from: e */
        public TextView f4792e;

        C0803c() {
        }
    }

    @Override // android.app.Activity
    public void onBackPressed() {
        super.onBackPressed();
        finish();
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.notification_slide_left /* 2131297354 */:
                PermissionDB pDB = new PermissionDB(this);
                C0801a notiBean = this.f4770c.get(this.f4775h);
                String packageName = notiBean.f4782e;
                InterceptPermission findByName = pDB.findByName(packageName);
                ContentValues values = new ContentValues();
                values.put(QueryPermissions.PACKAGENAME, packageName);
                values.put(QueryPermissions.PERMISSION, (Integer) 2);
                pDB.update(findByName._id, values);
                pDB.closeDatabase();
                this.f4769b.collapseGroup(this.f4775h);
                ScanApplicationInfo.killProcess(this, packageName);
                Toast.makeText(this, String.format(getString(C0415R.string.notification_forbid_feedback), notiBean.f4780c), 1).show();
                break;
            case C0415R.id.notification_slide_center /* 2131297355 */:
                C0801a removeBean = this.f4770c.get(this.f4775h);
                ContentValues values2 = new ContentValues();
                values2.put(QueryPermissions.PACKAGENAME, removeBean.f4782e);
                values2.put(QueryPermissions.PERMISSION, (Integer) 1);
                PermissionDB pDB2 = new PermissionDB(this);
                InterceptPermission findByName2 = pDB2.findByName(removeBean.f4782e);
                pDB2.update(findByName2._id, values2);
                pDB2.closeDatabase();
                this.f4769b.collapseGroup(this.f4775h);
                m1978a();
                this.f4768a.notifyDataSetChanged();
                Toast.makeText(this, String.format(getString(C0415R.string.notification_allow_feedback), removeBean.f4780c), 1).show();
                break;
            case C0415R.id.notification_slide_right /* 2131297356 */:
                try {
                    C0801a removeBean2 = this.f4770c.get(this.f4775h);
                    RecordDB db = new RecordDB(this);
                    db.delete(removeBean2.f4783f);
                    db.closeDatabase();
                    this.f4769b.collapseGroup(this.f4775h);
                    this.f4775h = -1;
                    m1978a();
                    this.f4768a.notifyDataSetChanged();
                    InterceptUtils.updateRecordListRemove(removeBean2.f4778a);
                } catch (Exception e) {
                    return;
                }
                break;
            case C0415R.id.record_clear_all /* 2131297387 */:
                RecordDB recordDB = new RecordDB(this);
                recordDB.deleteAll();
                recordDB.closeDatabase();
                Toast.makeText(this, getString(C0415R.string.intercept_record_clearn_all), 1).show();
                m1978a();
                this.f4768a.notifyDataSetChanged();
                break;
            case C0415R.id.title_back /* 2131297709 */:
                finish();
                break;
        }
    }
}
