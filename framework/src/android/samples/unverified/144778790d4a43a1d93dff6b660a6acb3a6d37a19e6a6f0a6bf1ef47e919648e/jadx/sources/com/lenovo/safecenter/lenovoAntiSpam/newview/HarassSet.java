package com.lenovo.safecenter.lenovoAntiSpam.newview;

import android.app.Dialog;
import android.app.TimePickerDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.provider.Settings;
import android.text.SpannableString;
import android.text.TextUtils;
import android.text.style.ForegroundColorSpan;
import android.view.View;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.TimePicker;
import android.widget.Toast;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.lenovoAntiSpam.utils.HttpUtils;
import com.lenovo.safecenter.lenovoAntiSpam.utils.SIMReader;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class HarassSet extends BaseTitleActivity {

    /* JADX INFO: renamed from: b */
    private TextView f3899b;

    /* JADX INFO: renamed from: c */
    private TextView f3900c;

    /* JADX INFO: renamed from: d */
    private ImageView f3901d;

    /* JADX INFO: renamed from: e */
    private ImageView f3902e;

    /* JADX INFO: renamed from: f */
    private RelativeLayout f3903f;

    /* JADX INFO: renamed from: g */
    private RelativeLayout f3904g;

    /* JADX INFO: renamed from: h */
    private RelativeLayout f3905h;

    /* JADX INFO: renamed from: i */
    private RelativeLayout f3906i;

    /* JADX INFO: renamed from: j */
    private RelativeLayout f3907j;

    /* JADX INFO: renamed from: k */
    private RelativeLayout f3908k;

    /* JADX INFO: renamed from: l */
    private int f3909l;

    /* JADX INFO: renamed from: m */
    private int f3910m;

    /* JADX INFO: renamed from: n */
    private int f3911n;

    /* JADX INFO: renamed from: o */
    private int f3912o;

    /* JADX INFO: renamed from: p */
    private int f3913p;

    /* JADX INFO: renamed from: q */
    private int f3914q;

    /* JADX INFO: renamed from: r */
    private int f3915r;

    /* JADX INFO: renamed from: s */
    private int f3916s;

    /* JADX INFO: renamed from: t */
    private ImageView f3917t;

    /* JADX INFO: renamed from: u */
    private RelativeLayout f3918u;

    /* JADX INFO: renamed from: v */
    private TextView f3919v;

    /* JADX INFO: renamed from: w */
    private TextView f3920w;

    /* JADX INFO: renamed from: x */
    private TextView f3921x;

    /* JADX INFO: renamed from: y */
    private TextView f3922y;

    /* JADX INFO: renamed from: a */
    boolean f3898a = false;

    /* JADX INFO: renamed from: z */
    private TimePickerDialog.OnTimeSetListener f3923z = new TimePickerDialog.OnTimeSetListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.HarassSet.4
        @Override // android.app.TimePickerDialog.OnTimeSetListener
        public final void onTimeSet(TimePicker view, int hourOfDay, int minute) {
            HarassSet.this.f3912o = hourOfDay;
            HarassSet.this.f3914q = minute;
            Settings.System.putInt(HarassSet.this.getContentResolver(), "nightharss_BH", HarassSet.this.f3912o);
            Settings.System.putInt(HarassSet.this.getContentResolver(), "nightharss_BM", HarassSet.this.f3914q);
            HarassSet.this.m1618a(1);
        }
    };

    /* JADX INFO: renamed from: A */
    private TimePickerDialog.OnTimeSetListener f3897A = new TimePickerDialog.OnTimeSetListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.HarassSet.5
        @Override // android.app.TimePickerDialog.OnTimeSetListener
        public final void onTimeSet(TimePicker view, int hourOfDay, int minute) {
            HarassSet.this.f3913p = hourOfDay;
            HarassSet.this.f3915r = minute;
            Settings.System.putInt(HarassSet.this.getContentResolver(), "nightharss_EH", HarassSet.this.f3913p);
            Settings.System.putInt(HarassSet.this.getContentResolver(), "nightharss_EM", HarassSet.this.f3915r);
            HarassSet.this.m1618a(2);
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1619a(HarassSet x0, int x1, int x2) {
        if (x1 == x2) {
            return;
        }
        String str = null;
        int simOperator = SIMReader.getSimOperator(x0);
        if (simOperator != -1) {
            if (x1 == 0 && x2 > 0) {
                str = simOperator == 3 ? "*900" : "%23%2367%23";
            } else if (x1 > 0) {
                if (x1 == 1) {
                    str = simOperator == 3 ? "*9013641244138" : "**67*13641244138%23";
                } else if (x1 == 2) {
                    str = simOperator == 3 ? "*9013641244026" : "**67*13641244026%23";
                } else if (x1 == 3) {
                    str = simOperator == 3 ? "*9013800000000" : "**67*13800000000%23";
                }
            }
            if (str != null) {
                x0.startActivity(new Intent("android.intent.action.CALL", Uri.parse("tel:" + str)));
            }
        }
    }

    /* JADX INFO: renamed from: d */
    static /* synthetic */ void m1625d(HarassSet x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.night_harssmode).setSingleChoiceItems(C0415R.array.nightcall_harsset, Settings.System.getInt(x0.getContentResolver(), "nightharss_callmode", 0), new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.HarassSet.3
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                HarassSet.this.f3916s = which;
            }
        }).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.HarassSet.2
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                if (HarassSet.this.f3916s == 0) {
                    Settings.System.putInt(HarassSet.this.getContentResolver(), "nightharss_callmode", 0);
                    HarassSet.this.f3921x.setText(C0415R.string.night_harssmode1);
                } else {
                    Settings.System.putInt(HarassSet.this.getContentResolver(), "nightharss_callmode", 1);
                    HarassSet.this.f3921x.setText(C0415R.string.night_harssmode2);
                }
            }
        }).show();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.harassset);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.antispamsmsharss, (Integer) null);
        findViews();
        ininIconState();
        InitMode();
        InitEndMode();
        InitNONUmberMode();
        this.f3916s = Settings.System.getInt(getContentResolver(), "nightharss_callmode", 0);
        initTimes();
        onBtnClick();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
            return;
        }
        if (v.getId() == C0415R.id.harass_switch_icon) {
            if (Const.getProtectHarassSwitchState()) {
                new CustomDialog.Builder(this).setTitle(C0415R.string.info).setMessage(C0415R.string.disable_antispam_tip).setColorPositiveButton(false).setColorNegativeButton(true).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.HarassSet.9
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                        Const.setProtectHarassSwitchState(false);
                        HarassSet.this.ininIconState();
                    }
                }).setNegativeButton(C0415R.string.cancel, (DialogInterface.OnClickListener) null).show();
                return;
            } else {
                Const.setProtectHarassSwitchState(true);
                ininIconState();
                return;
            }
        }
        if (v.getId() == C0415R.id.adv_icon) {
            if (initNoNumberState() == 0) {
                new HttpUtils().UpdateConfig("getnonumber", DatabaseTables.SYSTEM_MARK, this);
                TrackEvent.reportInterceptUnknownNumbersSwitchChange(true);
            } else {
                new HttpUtils().UpdateConfig("getnonumber", "0", this);
                TrackEvent.reportInterceptUnknownNumbersSwitchChange(false);
            }
            InitNONUmberMode();
            return;
        }
        if (v.getId() == C0415R.id.harass_mode_lin) {
            new CustomDialog.Builder(this).setTitle(C0415R.string.harass_mode_title).setSingleChoiceItems(C0415R.array.antispamhandup_mode, Settings.System.getInt(getContentResolver(), "intercall_mode_type", 0), new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.HarassSet.8
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface dialog, int which) {
                    HarassSet.this.f3909l = which;
                }
            }).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.HarassSet.7
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface dialog, int which) {
                    Settings.System.putInt(HarassSet.this.getContentResolver(), "intercall_mode_type", HarassSet.this.f3909l);
                    HarassSet.this.InitMode();
                }
            }).show();
            return;
        }
        if (v.getId() == C0415R.id.endcall_lin) {
            if (SIMReader.getSimOperator(this) != -1) {
                new CustomDialog.Builder(this).setTitle(C0415R.string.endcall_mode_title).setSingleChoiceItems(C0415R.array.block_list_entries, getDefsetting(), new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.HarassSet.6
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                        HarassSet.this.f3910m = which;
                    }
                }).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.HarassSet.1
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                        HarassSet.this.f3911n = HarassSet.this.getDefsetting();
                        new HttpUtils().UpdateConfig("getendmode", String.valueOf(HarassSet.this.f3910m), HarassSet.this);
                        HarassSet.this.InitEndMode();
                        HarassSet.m1619a(HarassSet.this, HarassSet.this.f3910m, HarassSet.this.f3911n);
                        dialog.dismiss();
                    }
                }).show();
                return;
            } else {
                Toast.makeText(this, C0415R.string.no_simcard, 1).show();
                return;
            }
        }
        if (v.getId() == C0415R.id.sign_lin) {
            startActivity(new Intent(this, (Class<?>) SignActivity.class));
        } else if (v.getId() == C0415R.id.manwb_lin) {
            Intent intent = new Intent(this, (Class<?>) WhiteABlackMain.class);
            intent.putExtra("type", 1);
            startActivity(intent);
        }
    }

    public void InitNONUmberMode() {
        if (initNoNumberState() == 0) {
            this.f3902e.setImageResource(C0415R.drawable.btn_off);
        } else {
            this.f3902e.setImageResource(C0415R.drawable.btn_on);
        }
    }

    public void InitEndMode() {
        if (getDefsetting() == 0) {
            this.f3900c.setText(C0415R.string.endmode1);
            return;
        }
        if (getDefsetting() == 1) {
            this.f3900c.setText(C0415R.string.endmode2);
        } else if (getDefsetting() == 2) {
            this.f3900c.setText(C0415R.string.endmode3);
        } else if (getDefsetting() == 3) {
            this.f3900c.setText(C0415R.string.endmode4);
        }
    }

    public int getDefsetting() {
        if (TextUtils.isEmpty(HttpUtils.execService("getendmode", this)) || HttpUtils.execService("getendmode", this).equals("0")) {
            return 0;
        }
        return Integer.parseInt(HttpUtils.execService("getendmode", this));
    }

    public void InitMode() {
        this.f3909l = Settings.System.getInt(getContentResolver(), "intercall_mode_type", 0);
        if (this.f3909l == 0) {
            this.f3899b.setText(C0415R.string.antispaminter_netblacktype_endcall1);
            return;
        }
        if (this.f3909l == 1) {
            this.f3899b.setText(C0415R.string.antispaminter_netblacktype_endcall2);
        } else if (this.f3909l == 2) {
            this.f3899b.setText(C0415R.string.antispaminter_netblacktype_endcall3);
        } else if (this.f3909l == 3) {
            this.f3899b.setText(C0415R.string.antispaminter_netblacktype_endcall4);
        }
    }

    public void ininIconState() {
        if (Const.getProtectHarassSwitchState()) {
            this.f3901d.setImageResource(C0415R.drawable.btn_on);
        } else {
            this.f3901d.setImageResource(C0415R.drawable.btn_off);
        }
    }

    public int initNoNumberState() {
        return (TextUtils.isEmpty(HttpUtils.execService("getnonumber", this)) || HttpUtils.execService("getnonumber", this).equals("0")) ? 0 : 1;
    }

    public void findViews() {
        this.f3899b = (TextView) findViewById(C0415R.id.harass_mode_desc);
        this.f3901d = (ImageView) findViewById(C0415R.id.harass_switch_icon);
        this.f3902e = (ImageView) findViewById(C0415R.id.adv_icon);
        this.f3903f = (RelativeLayout) findViewById(C0415R.id.harass_mode_lin);
        this.f3908k = (RelativeLayout) findViewById(C0415R.id.endcall_lin);
        this.f3901d.setOnClickListener(this);
        this.f3902e.setOnClickListener(this);
        this.f3903f.setOnClickListener(this);
        this.f3908k.setOnClickListener(this);
        this.f3900c = (TextView) findViewById(C0415R.id.endcall_mode_desc);
        this.f3904g = (RelativeLayout) findViewById(C0415R.id.sign_lin);
        this.f3904g.setOnClickListener(this);
        this.f3905h = (RelativeLayout) findViewById(C0415R.id.manwb_lin);
        this.f3905h.setOnClickListener(this);
        this.f3917t = (ImageView) findViewById(C0415R.id.night_switch);
        this.f3907j = (RelativeLayout) findViewById(C0415R.id.begintime_lay);
        this.f3906i = (RelativeLayout) findViewById(C0415R.id.endcall_lay);
        this.f3918u = (RelativeLayout) findViewById(C0415R.id.endtime_lay);
        this.f3919v = (TextView) findViewById(C0415R.id.endtime_summary);
        this.f3920w = (TextView) findViewById(C0415R.id.begintime_summary);
        this.f3921x = (TextView) findViewById(C0415R.id.endcall_summary);
        this.f3922y = (TextView) findViewById(C0415R.id.nightswitch_desc);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        super.onResume();
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    public void initTimes() {
        this.f3912o = Settings.System.getInt(getContentResolver(), "nightharss_BH", 23);
        this.f3913p = Settings.System.getInt(getContentResolver(), "nightharss_EH", 7);
        this.f3914q = Settings.System.getInt(getContentResolver(), "nightharss_BM", 0);
        this.f3915r = Settings.System.getInt(getContentResolver(), "nightharss_EM", 30);
        m1618a(1);
        m1618a(2);
        if (Settings.System.getInt(getContentResolver(), "nightharss_callmode", 0) == 0) {
            this.f3921x.setText(C0415R.string.night_harssmode1);
        } else {
            this.f3921x.setText(C0415R.string.night_harssmode2);
        }
        if (Settings.System.getInt(getContentResolver(), "nightharss_switch", 0) == 1) {
            this.f3917t.setImageResource(C0415R.drawable.btn_on);
            this.f3922y.setText(C0415R.string.open);
        } else {
            this.f3917t.setImageResource(C0415R.drawable.btn_off);
            this.f3922y.setText(C0415R.string.close);
        }
    }

    public void onBtnClick() {
        this.f3907j.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.HarassSet.10
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                HarassSet.this.showDialog(2);
            }
        });
        this.f3918u.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.HarassSet.11
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                HarassSet.this.showDialog(3);
            }
        });
        this.f3906i.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.HarassSet.12
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                HarassSet.m1625d(HarassSet.this);
            }
        });
        this.f3917t.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.HarassSet.13
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (Settings.System.getInt(HarassSet.this.getContentResolver(), "nightharss_switch", 0) == 0) {
                    Settings.System.putInt(HarassSet.this.getContentResolver(), "nightharss_switch", 1);
                    HarassSet.this.f3917t.setImageResource(C0415R.drawable.btn_on);
                    HarassSet.this.f3922y.setText(C0415R.string.open);
                } else {
                    Settings.System.putInt(HarassSet.this.getContentResolver(), "nightharss_switch", 0);
                    HarassSet.this.f3917t.setImageResource(C0415R.drawable.btn_off);
                    HarassSet.this.f3922y.setText(C0415R.string.close);
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
    public void m1618a(int i) {
        if (i == 1) {
            this.f3920w.setText(this.f3912o + C0092c.f1283N + (this.f3914q < 10 ? "0" + this.f3914q : Integer.valueOf(this.f3914q)));
        } else if (i == 2) {
            this.f3919v.setText(this.f3913p + C0092c.f1283N + (this.f3915r < 10 ? "0" + this.f3915r : Integer.valueOf(this.f3915r)));
        }
    }

    @Override // android.app.Activity
    protected Dialog onCreateDialog(int id) {
        switch (id) {
            case 2:
                return new TimePickerDialog(this, this.f3923z, this.f3912o, this.f3914q, true);
            case 3:
                return new TimePickerDialog(this, this.f3897A, this.f3913p, this.f3915r, true);
            default:
                return null;
        }
    }

    @Override // android.app.Activity
    protected void onPrepareDialog(int id, Dialog dialog) {
        switch (id) {
            case 2:
                ((TimePickerDialog) dialog).updateTime(this.f3912o, this.f3914q);
                break;
            case 3:
                ((TimePickerDialog) dialog).updateTime(this.f3913p, this.f3915r);
                break;
        }
    }
}
