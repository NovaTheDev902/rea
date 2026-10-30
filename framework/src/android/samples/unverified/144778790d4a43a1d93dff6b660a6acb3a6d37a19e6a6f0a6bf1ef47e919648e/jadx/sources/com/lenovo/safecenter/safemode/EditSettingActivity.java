package com.lenovo.safecenter.safemode;

import android.content.Context;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.utils.DataHelpUtils;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/* JADX INFO: loaded from: classes.dex */
public class EditSettingActivity extends BaseTitleActivity {

    /* JADX INFO: renamed from: a */
    private TextView f5089a;

    /* JADX INFO: renamed from: b */
    private TextView f5090b;

    /* JADX INFO: renamed from: c */
    private TextView f5091c;

    /* JADX INFO: renamed from: d */
    private EditText f5092d;

    /* JADX INFO: renamed from: e */
    private ListView f5093e;

    /* JADX INFO: renamed from: f */
    private Button f5094f;

    /* JADX INFO: renamed from: g */
    private List<Map<String, Object>> f5095g;

    /* JADX INFO: renamed from: h */
    private int f5096h;

    /* JADX INFO: renamed from: i */
    private int f5097i;

    /* JADX INFO: renamed from: j */
    private MyAdapter f5098j;

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.editset);
        findView();
        this.f5097i = getIntent().getIntExtra(DatabaseTables.APPLICATIONS_FLAG, 1);
        defultPos();
        this.f5095g = m2104a();
        initData();
        this.f5093e.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.safemode.EditSettingActivity.1
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                EditSettingActivity.this.f5096h = position;
                EditSettingActivity.this.f5095g = EditSettingActivity.this.m2104a();
                EditSettingActivity.this.f5093e.invalidateViews();
            }
        });
    }

    public void initData() {
        if (this.f5097i == 1) {
            setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.changename_title, (Integer) null);
            this.f5090b.setVisibility(0);
            this.f5089a.setText(C0415R.string.p_name);
            this.f5091c.setText(C0415R.string.p_icon);
        } else if (this.f5097i == 2) {
            setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.callnotify, (Integer) null);
            this.f5089a.setText(C0415R.string.p_stitle);
            this.f5091c.setText(C0415R.string.smsimg_notify);
        } else {
            setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.callnotify, (Integer) null);
            this.f5089a.setText(C0415R.string.p_ctitle);
            this.f5091c.setText(C0415R.string.callimg_notify);
        }
        this.f5098j = new MyAdapter(this);
        this.f5093e.setAdapter((ListAdapter) this.f5098j);
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public List<Map<String, Object>> m2104a() {
        List<Map<String, Object>> list = new ArrayList<>();
        Map<String, Object> map = new HashMap<>();
        if (this.f5096h == 0) {
            map.put("imgon", Integer.valueOf(C0415R.drawable.btn_radio_on));
        } else {
            map.put("imgon", Integer.valueOf(C0415R.drawable.btn_radio_off));
        }
        if (this.f5097i == 1) {
            map.put("img", Integer.valueOf(C0415R.drawable.home_page_drawer_privacy_safe));
        } else if (this.f5097i == 2) {
            map.put("img", Integer.valueOf(C0415R.drawable.smsnotify_show_black));
        } else if (this.f5097i == 3) {
            map.put("img", Integer.valueOf(C0415R.drawable.callnotify_show_black));
        }
        list.add(map);
        Map<String, Object> map2 = new HashMap<>();
        if (this.f5096h == 1) {
            map2.put("imgon", Integer.valueOf(C0415R.drawable.btn_radio_on));
        } else {
            map2.put("imgon", Integer.valueOf(C0415R.drawable.btn_radio_off));
        }
        if (this.f5097i == 1) {
            map2.put("img", Integer.valueOf(C0415R.drawable.safemode_hide));
        } else if (this.f5097i == 2 || this.f5097i == 3) {
            map2.put("img", Integer.valueOf(C0415R.drawable.notify_hide_black));
        }
        list.add(map2);
        return list;
    }

    public void defultPos() {
        if (this.f5097i == 1) {
            if (DataHelpUtils.execService("changeimg", this).equals("") || DataHelpUtils.execService("changeimg", this).equals("0")) {
                this.f5096h = 0;
            } else {
                this.f5096h = 1;
            }
            if (DataHelpUtils.execService("changeNametitle", this).equals("")) {
                this.f5092d.setText(C0415R.string.privacy_safe);
                return;
            } else {
                this.f5092d.setText(DataHelpUtils.execService("changeNametitle", this));
                return;
            }
        }
        if (this.f5097i == 2) {
            if (DataHelpUtils.execService("changesmsimg", this).equals("") || DataHelpUtils.execService("changesmsimg", this).equals("0")) {
                this.f5096h = 0;
            } else {
                this.f5096h = 1;
            }
            if (DataHelpUtils.execService("smsnotifytitle", this).equals("")) {
                this.f5092d.setText(C0415R.string.newsms);
                return;
            } else {
                this.f5092d.setText(DataHelpUtils.execService("smsnotifytitle", this));
                return;
            }
        }
        if (this.f5097i == 3) {
            if (DataHelpUtils.execService("changecallimg", this).equals("") || DataHelpUtils.execService("changecallimg", this).equals("0")) {
                this.f5096h = 0;
            } else {
                this.f5096h = 1;
            }
            if (DataHelpUtils.execService("callnotifytitle", this).equals("")) {
                this.f5092d.setText(C0415R.string.newsms);
            } else {
                this.f5092d.setText(DataHelpUtils.execService("callnotifytitle", this));
            }
        }
    }

    public final class ViewHolder {
        public ImageView img;
        public ImageView imgon;

        public ViewHolder() {
        }
    }

    public class MyAdapter extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private LayoutInflater f5101b;

        public MyAdapter(Context context) {
            this.f5101b = LayoutInflater.from(context);
        }

        @Override // android.widget.Adapter
        public int getCount() {
            return 2;
        }

        @Override // android.widget.Adapter
        public Object getItem(int arg0) {
            return null;
        }

        @Override // android.widget.Adapter
        public long getItemId(int arg0) {
            return 0L;
        }

        @Override // android.widget.Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            ViewHolder holder;
            if (convertView == null) {
                holder = EditSettingActivity.this.new ViewHolder();
                convertView = this.f5101b.inflate(C0415R.layout.vlist2, (ViewGroup) null);
                holder.img = (ImageView) convertView.findViewById(C0415R.id.changeimg_img);
                holder.imgon = (ImageView) convertView.findViewById(C0415R.id.changeimg_on);
                convertView.setTag(holder);
            } else {
                holder = (ViewHolder) convertView.getTag();
            }
            holder.img.setBackgroundResource(((Integer) ((Map) EditSettingActivity.this.f5095g.get(position)).get("img")).intValue());
            holder.imgon.setBackgroundResource(((Integer) ((Map) EditSettingActivity.this.f5095g.get(position)).get("imgon")).intValue());
            return convertView;
        }
    }

    public void findView() {
        this.f5091c = (TextView) findViewById(C0415R.id.e_icon);
        this.f5089a = (TextView) findViewById(C0415R.id.etitle);
        this.f5090b = (TextView) findViewById(C0415R.id.etitle_desc);
        this.f5092d = (EditText) findViewById(C0415R.id.e_edit);
        this.f5093e = (ListView) findViewById(C0415R.id.elist);
        this.f5094f = (Button) findViewById(C0415R.id.esumbit);
        this.f5094f.setOnClickListener(this);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
            return;
        }
        if (v.getId() == C0415R.id.esumbit) {
            if (!TextUtils.isEmpty(this.f5092d.getText().toString().trim())) {
                if (this.f5097i == 1) {
                    if (getWordCount(this.f5092d.getText().toString()) <= 8) {
                        DataHelpUtils.UpdateConfig("changeimg", String.valueOf(this.f5096h), this);
                        DataHelpUtils.UpdateConfig("changeNametitle", this.f5092d.getText().toString(), this);
                        Toast.makeText(this, C0415R.string.setting_pwdok, 0).show();
                        finish();
                        return;
                    }
                    Toast.makeText(this, C0415R.string.long_whire, 0).show();
                    return;
                }
                if (this.f5097i == 2) {
                    DataHelpUtils.UpdateConfig("changesmsimg", String.valueOf(this.f5096h), this);
                    DataHelpUtils.UpdateConfig("smsnotifytitle", this.f5092d.getText().toString(), this);
                    Toast.makeText(this, C0415R.string.setting_pwdok, 0).show();
                    finish();
                    return;
                }
                if (this.f5097i == 3) {
                    DataHelpUtils.UpdateConfig("changecallimg", String.valueOf(this.f5096h), this);
                    DataHelpUtils.UpdateConfig("callnotifytitle", this.f5092d.getText().toString(), this);
                    Toast.makeText(this, C0415R.string.setting_pwdok, 0).show();
                    finish();
                    return;
                }
                return;
            }
            Toast.makeText(this, C0415R.string.setting_pwdfail, 0).show();
        }
    }

    public int getWordCount(String s) {
        int length = 0;
        for (int i = 0; i < s.length(); i++) {
            int ascii = Character.codePointAt(s, i);
            if (ascii >= 0 && ascii <= 255) {
                length++;
            } else {
                length += 2;
            }
        }
        return length;
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        super.onResume();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
    }
}
