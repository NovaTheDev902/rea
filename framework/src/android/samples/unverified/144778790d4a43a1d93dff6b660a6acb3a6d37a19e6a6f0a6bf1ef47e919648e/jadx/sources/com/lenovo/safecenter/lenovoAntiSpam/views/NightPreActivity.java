package com.lenovo.safecenter.lenovoAntiSpam.views;

import android.app.Dialog;
import android.app.TimePickerDialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.provider.Settings;
import android.text.SpannableString;
import android.text.style.ForegroundColorSpan;
import android.view.View;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.TimePicker;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.utils.TrackEvent;
import java.text.SimpleDateFormat;
import java.util.Date;

/* JADX INFO: loaded from: classes.dex */
public class NightPreActivity extends BaseTitleActivity {

    /* JADX INFO: renamed from: a */
    private int f4250a;

    /* JADX INFO: renamed from: b */
    private int f4251b;

    /* JADX INFO: renamed from: c */
    private int f4252c;

    /* JADX INFO: renamed from: d */
    private int f4253d;

    /* JADX INFO: renamed from: e */
    private int f4254e;

    /* JADX INFO: renamed from: f */
    private ImageView f4255f;

    /* JADX INFO: renamed from: g */
    private LinearLayout f4256g;

    /* JADX INFO: renamed from: h */
    private LinearLayout f4257h;

    /* JADX INFO: renamed from: i */
    private LinearLayout f4258i;

    /* JADX INFO: renamed from: j */
    private TextView f4259j;

    /* JADX INFO: renamed from: k */
    private TextView f4260k;

    /* JADX INFO: renamed from: l */
    private TextView f4261l;

    /* JADX INFO: renamed from: m */
    private TextView f4262m;

    /* JADX INFO: renamed from: n */
    private TimePickerDialog.OnTimeSetListener f4263n = new TimePickerDialog.OnTimeSetListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.NightPreActivity.8
        @Override // android.app.TimePickerDialog.OnTimeSetListener
        public final void onTimeSet(TimePicker view, int hourOfDay, int minute) {
            NightPreActivity.this.f4250a = hourOfDay;
            NightPreActivity.this.f4252c = minute;
            Settings.System.putInt(NightPreActivity.this.getContentResolver(), "nightharss_BH", NightPreActivity.this.f4250a);
            Settings.System.putInt(NightPreActivity.this.getContentResolver(), "nightharss_BM", NightPreActivity.this.f4252c);
            NightPreActivity.this.m1751a(1);
        }
    };

    /* JADX INFO: renamed from: o */
    private TimePickerDialog.OnTimeSetListener f4264o = new TimePickerDialog.OnTimeSetListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.NightPreActivity.9
        @Override // android.app.TimePickerDialog.OnTimeSetListener
        public final void onTimeSet(TimePicker view, int hourOfDay, int minute) {
            NightPreActivity.this.f4251b = hourOfDay;
            NightPreActivity.this.f4253d = minute;
            Settings.System.putInt(NightPreActivity.this.getContentResolver(), "nightharss_EH", NightPreActivity.this.f4251b);
            Settings.System.putInt(NightPreActivity.this.getContentResolver(), "nightharss_EM", NightPreActivity.this.f4253d);
            NightPreActivity.this.m1751a(2);
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1752a(NightPreActivity x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.night_harssmode).setSingleChoiceItems(C0415R.array.nightcall_harsset, Settings.System.getInt(x0.getContentResolver(), "nightharss_callmode", 0), new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.NightPreActivity.7
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                NightPreActivity.this.f4254e = which;
            }
        }).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.NightPreActivity.6
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                if (NightPreActivity.this.f4254e == 0) {
                    Settings.System.putInt(NightPreActivity.this.getContentResolver(), "nightharss_callmode", 0);
                    NightPreActivity.this.f4261l.setText(NightPreActivity.this.getSpan(C0415R.string.night_harssmode1));
                } else {
                    Settings.System.putInt(NightPreActivity.this.getContentResolver(), "nightharss_callmode", 1);
                    NightPreActivity.this.f4261l.setText(NightPreActivity.this.getSpan(C0415R.string.night_harssmode2));
                }
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.NightPreActivity.5
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.night_haraset);
        findViews();
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.night_harsstitle, (Integer) null);
        this.f4254e = Settings.System.getInt(getContentResolver(), "nightharss_callmode", 0);
        initTimes();
        onBtnClick();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    public void findViews() {
        this.f4255f = (ImageView) findViewById(C0415R.id.night_switch);
        this.f4257h = (LinearLayout) findViewById(C0415R.id.begintime_lay);
        this.f4256g = (LinearLayout) findViewById(C0415R.id.endcall_lay);
        this.f4258i = (LinearLayout) findViewById(C0415R.id.endtime_lay);
        this.f4259j = (TextView) findViewById(C0415R.id.endtime_summary);
        this.f4260k = (TextView) findViewById(C0415R.id.begintime_summary);
        this.f4261l = (TextView) findViewById(C0415R.id.endcall_summary);
        this.f4262m = (TextView) findViewById(C0415R.id.nightswitch_desc);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        }
    }

    public void initTimes() {
        this.f4250a = Settings.System.getInt(getContentResolver(), "nightharss_BH", 23);
        this.f4251b = Settings.System.getInt(getContentResolver(), "nightharss_EH", 7);
        this.f4252c = Settings.System.getInt(getContentResolver(), "nightharss_BM", 0);
        this.f4253d = Settings.System.getInt(getContentResolver(), "nightharss_EM", 30);
        m1751a(1);
        m1751a(2);
        if (Settings.System.getInt(getContentResolver(), "nightharss_callmode", 0) == 0) {
            this.f4261l.setText(getSpan(C0415R.string.night_harssmode1));
        } else {
            this.f4261l.setText(getSpan(C0415R.string.night_harssmode2));
        }
        if (Settings.System.getInt(getContentResolver(), "nightharss_switch", 0) == 1) {
            this.f4255f.setImageResource(C0415R.drawable.btn_on);
            this.f4262m.setText(C0415R.string.open);
        } else {
            this.f4255f.setImageResource(C0415R.drawable.btn_off);
            this.f4262m.setText(C0415R.string.close);
        }
    }

    public void onBtnClick() {
        this.f4257h.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.NightPreActivity.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                NightPreActivity.this.showDialog(2);
            }
        });
        this.f4258i.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.NightPreActivity.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                NightPreActivity.this.showDialog(3);
            }
        });
        this.f4256g.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.NightPreActivity.3
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                NightPreActivity.m1752a(NightPreActivity.this);
            }
        });
        this.f4255f.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.NightPreActivity.4
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (Settings.System.getInt(NightPreActivity.this.getContentResolver(), "nightharss_switch", 0) == 0) {
                    Settings.System.putInt(NightPreActivity.this.getContentResolver(), "nightharss_switch", 1);
                    NightPreActivity.this.f4255f.setImageResource(C0415R.drawable.btn_on);
                    NightPreActivity.this.f4262m.setText(C0415R.string.open);
                } else {
                    Settings.System.putInt(NightPreActivity.this.getContentResolver(), "nightharss_switch", 0);
                    NightPreActivity.this.f4255f.setImageResource(C0415R.drawable.btn_off);
                    NightPreActivity.this.f4262m.setText(C0415R.string.close);
                }
            }
        });
    }

    public SpannableString getSpan(int resID) {
        SpannableString spannable = new SpannableString(getString(resID));
        spannable.setSpan(new ForegroundColorSpan(getResources().getColor(C0415R.color.gray2)), 0, getString(resID).length(), 0);
        return spannable;
    }

    public SpannableString getSpan_title(int resID) {
        SpannableString spannable = new SpannableString(getString(resID));
        spannable.setSpan(new ForegroundColorSpan(getResources().getColor(C0415R.color.black2)), 0, getString(resID).length(), 0);
        return spannable;
    }

    public SpannableString getSpan_str(String res) {
        SpannableString spannable = new SpannableString(res);
        spannable.setSpan(new ForegroundColorSpan(getResources().getColor(C0415R.color.gray2)), 0, res.length(), 0);
        return spannable;
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public void m1751a(int i) {
        if (i == 1) {
            this.f4260k.setText(getSpan_str(this.f4250a + C0092c.f1283N + (this.f4252c < 10 ? "0" + this.f4252c : Integer.valueOf(this.f4252c))));
        } else if (i == 2) {
            this.f4259j.setText(getSpan_str(this.f4251b + C0092c.f1283N + (this.f4253d < 10 ? "0" + this.f4253d : Integer.valueOf(this.f4253d))));
        }
    }

    @Override // android.app.Activity
    protected Dialog onCreateDialog(int id) {
        switch (id) {
            case 2:
                return new TimePickerDialog(this, this.f4263n, this.f4250a, this.f4252c, true);
            case 3:
                return new TimePickerDialog(this, this.f4264o, this.f4251b, this.f4253d, true);
            default:
                return null;
        }
    }

    @Override // android.app.Activity
    protected void onPrepareDialog(int id, Dialog dialog) {
        switch (id) {
            case 2:
                ((TimePickerDialog) dialog).updateTime(this.f4250a, this.f4252c);
                break;
            case 3:
                ((TimePickerDialog) dialog).updateTime(this.f4251b, this.f4253d);
                break;
        }
    }

    public static boolean Judge(int bh, int bm, int eh, int em) {
        SimpleDateFormat df = new SimpleDateFormat("HH:mm");
        Date date = new Date(Long.parseLong(String.valueOf(System.currentTimeMillis())));
        String[] times = df.format(date).split(C0092c.f1283N);
        int curH = Integer.parseInt(times[0]);
        int curM = Integer.parseInt(times[1]);
        if (bh > eh) {
            if (curH > bh || curH < eh) {
                return true;
            }
            if (curH == bh && curM >= bm) {
                return true;
            }
            if (curH == eh && curM <= em) {
                return true;
            }
        } else if (bh < eh) {
            if (curH > bh && eh > curH) {
                return true;
            }
            if (curH == bh && curM >= bm) {
                return true;
            }
            if (curH == eh && curM <= em) {
                return true;
            }
        } else if (bh == eh && curH == bh && bm < curM && em > curM) {
            return true;
        }
        return false;
    }

    public boolean judgeNightHarass() {
        if (Settings.System.getInt(getContentResolver(), "nightharss_switch", 0) != 0) {
            this.f4250a = Settings.System.getInt(getContentResolver(), "nightharss_BH", 23);
            this.f4251b = Settings.System.getInt(getContentResolver(), "nightharss_EH", 6);
            this.f4252c = Settings.System.getInt(getContentResolver(), "nightharss_BM", 0);
            this.f4253d = Settings.System.getInt(getContentResolver(), "nightharss_EM", 0);
            Judge(this.f4250a, this.f4252c, this.f4251b, this.f4253d);
        }
        return false;
    }
}
