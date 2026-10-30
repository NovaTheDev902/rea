package com.lenovo.safecenter.floatwindow.view;

import android.bluetooth.BluetoothAdapter;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.os.Handler;
import android.os.Message;
import android.telephony.TelephonyManager;
import android.util.AttributeSet;
import android.view.View;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import android.widget.FrameLayout;
import android.widget.TextView;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.floatwindow.util.Constants;
import com.lenovo.safecenter.floatwindow.util.MultiSIMUtils;
import com.lenovo.safecenter.floatwindow.util.SettingUtil;
import com.lenovo.safecenter.net.support.TrafficStatsService;

/* JADX INFO: loaded from: classes.dex */
public class SwitcherContainerView extends FrameLayout implements View.OnClickListener {
    public static C0580b receiver = null;
    public static boolean screenWindowDel = true;

    /* JADX INFO: renamed from: z */
    private static Context f3703z;

    /* JADX INFO: renamed from: A */
    private Animation f3704A;

    /* JADX INFO: renamed from: B */
    private C0579a f3705B;

    /* JADX INFO: renamed from: C */
    private boolean f3706C;

    /* JADX INFO: renamed from: D */
    private boolean f3707D;

    /* JADX INFO: renamed from: E */
    private boolean f3708E;

    /* JADX INFO: renamed from: F */
    private SharedPreferences f3709F;

    /* JADX INFO: renamed from: G */
    private Handler f3710G;

    /* JADX INFO: renamed from: a */
    private SwitcherItemView f3711a;

    /* JADX INFO: renamed from: b */
    private SwitcherItemView f3712b;

    /* JADX INFO: renamed from: c */
    private SwitcherItemView f3713c;

    /* JADX INFO: renamed from: d */
    private SwitcherItemView f3714d;

    /* JADX INFO: renamed from: e */
    private SwitcherItemView f3715e;

    /* JADX INFO: renamed from: f */
    private SwitcherItemView f3716f;

    /* JADX INFO: renamed from: g */
    private SwitcherItemView f3717g;

    /* JADX INFO: renamed from: h */
    private SwitcherItemView f3718h;

    /* JADX INFO: renamed from: i */
    private SwitcherItemView f3719i;

    /* JADX INFO: renamed from: j */
    private SwitcherItemView f3720j;

    /* JADX INFO: renamed from: k */
    private SwitcherItemView f3721k;

    /* JADX INFO: renamed from: l */
    private SwitcherItemView f3722l;

    /* JADX INFO: renamed from: m */
    private TextView f3723m;

    /* JADX INFO: renamed from: n */
    private SettingUtil f3724n;

    /* JADX INFO: renamed from: o */
    private final int f3725o;

    /* JADX INFO: renamed from: p */
    private final int f3726p;

    /* JADX INFO: renamed from: q */
    private final int f3727q;

    /* JADX INFO: renamed from: r */
    private final int f3728r;

    /* JADX INFO: renamed from: s */
    private final int f3729s;

    /* JADX INFO: renamed from: t */
    private final int f3730t;

    /* JADX INFO: renamed from: u */
    private final int f3731u;

    /* JADX INFO: renamed from: v */
    private final int f3732v;

    /* JADX INFO: renamed from: w */
    private final int f3733w;

    /* JADX INFO: renamed from: x */
    private final int f3734x;

    /* JADX INFO: renamed from: y */
    private final int f3735y;

    /* JADX INFO: renamed from: k */
    static /* synthetic */ boolean m1593k(SwitcherContainerView x0) {
        x0.f3706C = false;
        return false;
    }

    public SwitcherContainerView(Context context) {
        super(context);
        this.f3725o = 1;
        this.f3726p = 2;
        this.f3727q = 3;
        this.f3728r = 4;
        this.f3729s = 5;
        this.f3730t = 6;
        this.f3731u = 7;
        this.f3732v = 9;
        this.f3733w = 10;
        this.f3734x = 11;
        this.f3735y = 12;
        this.f3706C = false;
        this.f3707D = false;
        this.f3708E = true;
        this.f3710G = new Handler() { // from class: com.lenovo.safecenter.floatwindow.view.SwitcherContainerView.1
            @Override // android.os.Handler
            public final void handleMessage(Message msg) {
                switch (msg.what) {
                    case 0:
                        if (!SwitcherContainerView.this.f3708E) {
                            switch (msg.arg1) {
                                case 0:
                                    SwitcherContainerView.this.f3711a.setImage(C0415R.drawable.assist_switcher_wifi_off);
                                    SwitcherContainerView.this.f3711a.setLabelColor(SwitcherContainerView.this.getResources().getColor(C0415R.color.text_switcher_item_off));
                                    SwitcherContainerView.this.m1569a(1, 0, true);
                                    break;
                                case 1:
                                    SwitcherContainerView.this.f3711a.setImage(C0415R.drawable.assist_switcher_wifi_off);
                                    SwitcherContainerView.this.f3711a.setLabelColor(SwitcherContainerView.this.getResources().getColor(C0415R.color.text_switcher_item_off));
                                    SwitcherContainerView.this.m1569a(1, 0, false);
                                    break;
                                case 2:
                                    SwitcherContainerView.this.f3711a.setImage(C0415R.drawable.assist_switcher_wifi_on);
                                    SwitcherContainerView.this.f3711a.setLabelColor(SwitcherContainerView.this.getResources().getColor(C0415R.color.text_switcher_item_on));
                                    SwitcherContainerView.this.m1569a(1, 1, true);
                                    break;
                                case 3:
                                    SwitcherContainerView.this.f3711a.setImage(C0415R.drawable.assist_switcher_wifi_on);
                                    SwitcherContainerView.this.f3711a.setLabelColor(SwitcherContainerView.this.getResources().getColor(C0415R.color.text_switcher_item_on));
                                    SwitcherContainerView.this.m1569a(1, 1, false);
                                    break;
                            }
                        }
                        break;
                    case 1:
                    case 3:
                    case 4:
                    default:
                    case 2:
                        SwitcherContainerView.this.f3723m.setBackgroundDrawable(null);
                        SwitcherContainerView.this.f3723m.setText(SwitcherContainerView.f3703z.getString(C0415R.string.switcher_hint_default));
                        SwitcherContainerView.this.f3723m.setTextColor(SwitcherContainerView.this.getResources().getColor(C0415R.color.text_switcher_hint_off));
                        return;
                    case 5:
                        break;
                }
                switch (msg.arg1) {
                    case 10:
                    case 12:
                        SwitcherContainerView.this.m1588g(true);
                        SwitcherContainerView.this.f3707D = false;
                        break;
                    case 11:
                        SwitcherContainerView.this.f3707D = true;
                        SwitcherContainerView.this.f3721k.setImage(C0415R.drawable.assist_switcher_bluetooth_on);
                        SwitcherContainerView.this.m1569a(11, 1, true);
                        break;
                    case 13:
                        SwitcherContainerView.this.f3707D = true;
                        SwitcherContainerView.this.f3721k.setImage(C0415R.drawable.assist_switcher_bluetooth_on);
                        SwitcherContainerView.this.m1569a(11, 0, true);
                        break;
                }
            }
        };
    }

    /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
    public SwitcherContainerView(Context paramContext, AttributeSet paramAttributeSet) {
        super(paramContext, paramAttributeSet);
        byte b = 0;
        this.f3725o = 1;
        this.f3726p = 2;
        this.f3727q = 3;
        this.f3728r = 4;
        this.f3729s = 5;
        this.f3730t = 6;
        this.f3731u = 7;
        this.f3732v = 9;
        this.f3733w = 10;
        this.f3734x = 11;
        this.f3735y = 12;
        this.f3706C = false;
        this.f3707D = false;
        this.f3708E = true;
        this.f3710G = new Handler() { // from class: com.lenovo.safecenter.floatwindow.view.SwitcherContainerView.1
            @Override // android.os.Handler
            public final void handleMessage(Message msg) {
                switch (msg.what) {
                    case 0:
                        if (!SwitcherContainerView.this.f3708E) {
                            switch (msg.arg1) {
                                case 0:
                                    SwitcherContainerView.this.f3711a.setImage(C0415R.drawable.assist_switcher_wifi_off);
                                    SwitcherContainerView.this.f3711a.setLabelColor(SwitcherContainerView.this.getResources().getColor(C0415R.color.text_switcher_item_off));
                                    SwitcherContainerView.this.m1569a(1, 0, true);
                                    break;
                                case 1:
                                    SwitcherContainerView.this.f3711a.setImage(C0415R.drawable.assist_switcher_wifi_off);
                                    SwitcherContainerView.this.f3711a.setLabelColor(SwitcherContainerView.this.getResources().getColor(C0415R.color.text_switcher_item_off));
                                    SwitcherContainerView.this.m1569a(1, 0, false);
                                    break;
                                case 2:
                                    SwitcherContainerView.this.f3711a.setImage(C0415R.drawable.assist_switcher_wifi_on);
                                    SwitcherContainerView.this.f3711a.setLabelColor(SwitcherContainerView.this.getResources().getColor(C0415R.color.text_switcher_item_on));
                                    SwitcherContainerView.this.m1569a(1, 1, true);
                                    break;
                                case 3:
                                    SwitcherContainerView.this.f3711a.setImage(C0415R.drawable.assist_switcher_wifi_on);
                                    SwitcherContainerView.this.f3711a.setLabelColor(SwitcherContainerView.this.getResources().getColor(C0415R.color.text_switcher_item_on));
                                    SwitcherContainerView.this.m1569a(1, 1, false);
                                    break;
                            }
                        }
                        break;
                    case 1:
                    case 3:
                    case 4:
                    default:
                    case 2:
                        SwitcherContainerView.this.f3723m.setBackgroundDrawable(null);
                        SwitcherContainerView.this.f3723m.setText(SwitcherContainerView.f3703z.getString(C0415R.string.switcher_hint_default));
                        SwitcherContainerView.this.f3723m.setTextColor(SwitcherContainerView.this.getResources().getColor(C0415R.color.text_switcher_hint_off));
                        return;
                    case 5:
                        break;
                }
                switch (msg.arg1) {
                    case 10:
                    case 12:
                        SwitcherContainerView.this.m1588g(true);
                        SwitcherContainerView.this.f3707D = false;
                        break;
                    case 11:
                        SwitcherContainerView.this.f3707D = true;
                        SwitcherContainerView.this.f3721k.setImage(C0415R.drawable.assist_switcher_bluetooth_on);
                        SwitcherContainerView.this.m1569a(11, 1, true);
                        break;
                    case 13:
                        SwitcherContainerView.this.f3707D = true;
                        SwitcherContainerView.this.f3721k.setImage(C0415R.drawable.assist_switcher_bluetooth_on);
                        SwitcherContainerView.this.m1569a(11, 0, true);
                        break;
                }
            }
        };
        f3703z = paramContext;
        if (this.f3724n == null) {
            this.f3724n = new SettingUtil(paramContext);
            if (this.f3724n.isMultiSim()) {
                long mSimId = this.f3724n.getDataSimId();
                SharedPreferences smart_prefs = paramContext.getSharedPreferences(Constants.DATASUBSCRIBERID, 32768);
                SharedPreferences.Editor edit = smart_prefs.edit();
                edit.putLong(Constants.DATASUBSCRIBERID, mSimId);
                edit.commit();
            }
        }
        inflate(paramContext, C0415R.layout.assist_switcher_container, this);
        this.f3723m = (TextView) findViewById(C0415R.id.msg_hint);
        this.f3711a = (SwitcherItemView) findViewById(C0415R.id.switch_wifi);
        this.f3712b = (SwitcherItemView) findViewById(C0415R.id.switch_mobile_data);
        this.f3713c = (SwitcherItemView) findViewById(C0415R.id.switch_ringtone);
        this.f3714d = (SwitcherItemView) findViewById(C0415R.id.switch_vibrate);
        this.f3715e = (SwitcherItemView) findViewById(C0415R.id.switch_light);
        this.f3717g = (SwitcherItemView) findViewById(C0415R.id.switch_timeout);
        this.f3720j = (SwitcherItemView) findViewById(C0415R.id.switch_guest_mode);
        this.f3719i = (SwitcherItemView) findViewById(C0415R.id.switch_children_desktop);
        this.f3718h = (SwitcherItemView) findViewById(C0415R.id.switch_traffic_monitor);
        this.f3721k = (SwitcherItemView) findViewById(C0415R.id.switch_bluetooth);
        this.f3722l = (SwitcherItemView) findViewById(C0415R.id.switch_airplane_mode);
        this.f3716f = (SwitcherItemView) findViewById(C0415R.id.switch_rotation);
        if (m1566a(1) == 0) {
            this.f3711a.setImage(C0415R.drawable.assist_switcher_wifi_off);
            this.f3711a.setLabelColor(getResources().getColor(C0415R.color.text_switcher_item_off));
        } else {
            this.f3711a.setImage(C0415R.drawable.assist_switcher_wifi_on);
            this.f3711a.setLabelColor(getResources().getColor(C0415R.color.text_switcher_item_on));
        }
        m1571a(false);
        m1576b(false);
        m1580c(false);
        m1582d(false);
        m1584e(false);
        m1586f(false);
        if (!this.f3707D) {
            m1588g(false);
        }
        m1590h(false);
        m1579c();
        m1574b();
        this.f3711a.setOnClickListener(this);
        this.f3712b.setOnClickListener(this);
        this.f3713c.setOnClickListener(this);
        this.f3714d.setOnClickListener(this);
        this.f3715e.setOnClickListener(this);
        this.f3717g.setOnClickListener(this);
        this.f3720j.setOnClickListener(this);
        this.f3719i.setOnClickListener(this);
        this.f3718h.setOnClickListener(this);
        this.f3721k.setOnClickListener(this);
        this.f3722l.setOnClickListener(this);
        this.f3716f.setOnClickListener(this);
        IntentFilter intentFilter = new IntentFilter();
        if (receiver != null) {
            receiver = null;
        }
        receiver = new C0580b(this, b);
        intentFilter.addAction("android.net.wifi.WIFI_STATE_CHANGED");
        intentFilter.addAction("android.bluetooth.adapter.action.STATE_CHANGED");
        intentFilter.addAction("android.location.PROVIDERS_CHANGED");
        intentFilter.addAction("com.safecenter.broadcast.openGuestMode");
        intentFilter.addAction("com.safecenter.broadcast.openChildMode");
        intentFilter.addAction("com.lenovo.safecenter.lightChanges");
        intentFilter.addAction("android.net.conn.CONNECTIVITY_CHANGE");
        f3703z.registerReceiver(receiver, intentFilter);
    }

    public static void unregisterReceiver() {
        if (receiver != null) {
            f3703z.unregisterReceiver(receiver);
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public void m1571a(boolean isFromClick) {
        int currentData = m1566a(2);
        if (currentData == 0) {
            this.f3712b.setImage(C0415R.drawable.assist_switcher_mobile_data_off);
            this.f3712b.setLabelColor(getResources().getColor(C0415R.color.text_switcher_item_off));
        } else {
            this.f3712b.setImage(C0415R.drawable.assist_switcher_mobile_data_on);
            this.f3712b.setLabelColor(getResources().getColor(C0415R.color.text_switcher_item_on));
        }
        if (isFromClick) {
            m1569a(2, currentData, false);
        }
    }

    /* JADX INFO: renamed from: b */
    private void m1576b(boolean isFromClick) {
        int ringtone = m1566a(3);
        if (ringtone == 1) {
            this.f3713c.setImage(C0415R.drawable.assist_switcher_ringtone_on);
            this.f3713c.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_on));
        } else {
            this.f3713c.setImage(C0415R.drawable.assist_switcher_ringtone_off);
            this.f3713c.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_off));
        }
        if (isFromClick) {
            m1569a(3, ringtone, false);
        }
    }

    /* JADX INFO: renamed from: c */
    private void m1580c(boolean isFromClick) {
        int vibrate = m1566a(4);
        if (vibrate == 1) {
            this.f3714d.setImage(C0415R.drawable.assist_switcher_vibrate_on);
            this.f3714d.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_on));
        } else {
            this.f3714d.setImage(C0415R.drawable.assist_switcher_vibrate_off);
            this.f3714d.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_off));
        }
        if (isFromClick) {
            m1569a(4, vibrate, false);
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: d */
    public void m1582d(boolean isFromClick) {
        int brightness = m1566a(5);
        if (brightness == 1) {
            this.f3715e.setImage(C0415R.drawable.assist_switcher_light_25percent);
            this.f3715e.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_off));
        } else if (brightness == 2) {
            this.f3715e.setImage(C0415R.drawable.assist_switcher_light_50percent);
            this.f3715e.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_on));
        } else if (brightness == 3) {
            this.f3715e.setImage(C0415R.drawable.assist_switcher_light_75percent);
            this.f3715e.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_on));
        } else if (brightness == 4) {
            this.f3715e.setImage(C0415R.drawable.assist_switcher_light_100percent);
            this.f3715e.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_on));
        } else if (brightness == 5) {
            this.f3715e.setImage(C0415R.drawable.assist_switcher_light_auto);
            this.f3715e.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_on));
        }
        if (isFromClick) {
            m1569a(5, brightness, false);
        }
    }

    /* JADX INFO: renamed from: e */
    private void m1584e(boolean isFromClick) {
        int rotate = m1566a(6);
        if (rotate == 1) {
            this.f3716f.setImage(C0415R.drawable.assist_switcher_rotation_on);
            this.f3716f.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_on));
        } else {
            this.f3716f.setImage(C0415R.drawable.assist_switcher_rotation_off);
            this.f3716f.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_off));
        }
        if (isFromClick) {
            m1569a(6, rotate, false);
        }
    }

    /* JADX INFO: renamed from: f */
    private void m1586f(boolean isFromClick) {
        int timeout = m1566a(7);
        if (timeout == 1) {
            this.f3717g.setImage(C0415R.drawable.assist_switcher_timeout_30s);
        } else if (timeout == 2) {
            this.f3717g.setImage(C0415R.drawable.assist_switcher_timeout_1m);
        } else if (timeout == 3) {
            this.f3717g.setImage(C0415R.drawable.assist_switcher_timeout_2m);
        } else if (timeout == 4) {
            this.f3717g.setImage(C0415R.drawable.assist_switcher_timeout_10m);
        }
        this.f3717g.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_on));
        if (isFromClick) {
            m1569a(7, timeout, false);
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: b */
    public void m1574b() {
        int childMode = m1566a(9);
        if (childMode == 0) {
            this.f3719i.setImage(C0415R.drawable.assist_switcher_children_desktop_off);
            this.f3719i.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_off));
        } else {
            this.f3719i.setImage(C0415R.drawable.assist_switcher_children_desktop_on);
            this.f3719i.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_on));
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: c */
    public void m1579c() {
        int guestMode = m1566a(10);
        if (guestMode == 0) {
            this.f3720j.setImage(C0415R.drawable.assist_switcher_visitor_mode_off);
            this.f3720j.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_off));
        } else {
            this.f3720j.setImage(C0415R.drawable.assist_switcher_visitor_mode_on);
            this.f3720j.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_on));
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: g */
    public void m1588g(boolean isFromClick) {
        int bluetooth = m1566a(11);
        if (bluetooth == 1) {
            this.f3721k.setImage(C0415R.drawable.assist_switcher_bluetooth_on);
            this.f3721k.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_on));
        } else {
            this.f3721k.setImage(C0415R.drawable.assist_switcher_bluetooth_off);
            this.f3721k.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_off));
        }
        if (isFromClick) {
            m1569a(11, bluetooth, false);
        }
    }

    /* JADX INFO: renamed from: h */
    private void m1590h(boolean isFromClick) {
        int flightmode = m1566a(12);
        if (flightmode == 1) {
            this.f3722l.setImage(C0415R.drawable.assist_switcher_airplane_mode_on);
            this.f3722l.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_on));
            this.f3712b.setClickable(false);
            this.f3721k.setClickable(false);
            this.f3712b.setEnabled(false);
            this.f3721k.setEnabled(false);
        } else if (flightmode == 0) {
            this.f3722l.setImage(C0415R.drawable.assist_switcher_airplane_mode_off);
            this.f3722l.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_off));
            this.f3712b.setClickable(true);
            this.f3721k.setClickable(true);
            this.f3712b.setEnabled(true);
            this.f3721k.setEnabled(true);
        }
        if (isFromClick) {
            m1569a(12, flightmode, false);
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public void m1569a(int item, int value, boolean IsOpening) {
        String prompt;
        if (item == 20) {
            prompt = f3703z.getString(C0415R.string.plz_close_airplane_mode_or_insert_sim_card);
        } else if (IsOpening) {
            prompt = generatePrompting(item, value);
        } else if (item == 9 || item == 10) {
            prompt = getResources().getString(C0415R.string.not_support);
        } else {
            prompt = generatePrompt(item, value);
        }
        this.f3723m.setText(prompt);
        this.f3723m.setTextColor(getResources().getColor(C0415R.color.white));
        this.f3723m.setBackgroundResource(C0415R.drawable.assist_switcher_container_hint);
        if (this.f3704A != null) {
            this.f3704A.cancel();
            this.f3704A = null;
        }
        this.f3704A = new AlphaAnimation(1.0f, 0.0f);
        this.f3704A.setDuration(1600L);
        this.f3723m.setAnimation(this.f3704A);
        this.f3704A.start();
        this.f3705B = new C0579a();
        this.f3705B.start();
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.floatwindow.view.SwitcherContainerView$a */
    class C0579a extends Thread {
        C0579a() {
        }

        @Override // java.lang.Thread, java.lang.Runnable
        public final void run() {
            try {
                Thread.sleep(1600L);
                SwitcherContainerView.this.f3710G.sendEmptyMessage(2);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public String generatePrompting(int item, int value) {
        String verb = "";
        String name = "";
        switch (value) {
            case 0:
                verb = f3703z.getString(C0415R.string.exam_repair_closing);
                break;
            case 1:
                verb = f3703z.getString(C0415R.string.exam_repair_opening);
                break;
        }
        switch (item) {
            case 1:
                name = f3703z.getString(C0415R.string.switcher_wifi);
                break;
            case 2:
                name = f3703z.getString(C0415R.string.switcher_mobile_data);
                break;
            case 11:
                name = f3703z.getString(C0415R.string.switcher_bluetooth);
                break;
        }
        String prompt = verb + name;
        return prompt;
    }

    public String generatePrompt(int item, int value) {
        if (item == 5) {
            switch (value) {
                case 1:
                    String prompt = String.format(f3703z.getString(C0415R.string.switcher_hint_light_percent), 25);
                    return prompt;
                case 2:
                    String prompt2 = String.format(f3703z.getString(C0415R.string.switcher_hint_light_percent), 50);
                    return prompt2;
                case 3:
                    String prompt3 = String.format(f3703z.getString(C0415R.string.switcher_hint_light_percent), 75);
                    return prompt3;
                case 4:
                    String prompt4 = String.format(f3703z.getString(C0415R.string.switcher_hint_light_percent), 100);
                    return prompt4;
                case 5:
                    String prompt5 = f3703z.getString(C0415R.string.switcher_hint_light_auto);
                    return prompt5;
                default:
                    return "";
            }
        }
        if (item == 7) {
            String second_timeout = f3703z.getString(C0415R.string.switcher_hint_timeout_second);
            String minute_timeout = f3703z.getString(C0415R.string.switcher_hint_timeout_minute);
            switch (value) {
                case 1:
                    String prompt6 = String.format(second_timeout, "30");
                    return prompt6;
                case 2:
                    String prompt7 = String.format(minute_timeout, DatabaseTables.SYSTEM_MARK);
                    return prompt7;
                case 3:
                    String prompt8 = String.format(minute_timeout, DatabaseTables.USER_MARK);
                    return prompt8;
                case 4:
                    String prompt9 = String.format(minute_timeout, "10");
                    return prompt9;
                default:
                    return "";
            }
        }
        String name = "";
        String verb = "";
        String ALREADY = f3703z.getString(C0415R.string.prompt_already);
        switch (item) {
            case 1:
                name = f3703z.getString(C0415R.string.switcher_wifi);
                break;
            case 2:
                name = f3703z.getString(C0415R.string.switcher_mobile_data);
                break;
            case 3:
                name = f3703z.getString(C0415R.string.switcher_ringtone);
                break;
            case 4:
                name = f3703z.getString(C0415R.string.switcher_vibrate);
                break;
            case 6:
                name = f3703z.getString(C0415R.string.switcher_rotation);
                break;
            case 11:
                name = f3703z.getString(C0415R.string.switcher_bluetooth);
                break;
            case 12:
                name = f3703z.getString(C0415R.string.switcher_airplane_mode);
                break;
        }
        switch (value) {
            case 0:
                verb = f3703z.getString(C0415R.string.security_action_off);
                break;
            case 1:
                verb = f3703z.getString(C0415R.string.security_action_on);
                break;
        }
        String prompt10 = ALREADY + verb + name;
        return prompt10;
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: com.lenovo.safecenter.floatwindow.view.SwitcherContainerView$b */
    class C0580b extends BroadcastReceiver {
        private C0580b() {
        }

        /* synthetic */ C0580b(SwitcherContainerView x0, byte b) {
            this();
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            String action = intent.getAction();
            if ("android.net.wifi.WIFI_STATE_CHANGED".equals(action)) {
                int intExtra = intent.getIntExtra("wifi_state", 0);
                Message msg = new Message();
                msg.what = 0;
                msg.arg1 = intExtra;
                SwitcherContainerView.this.f3710G.sendMessage(msg);
            }
            if ("android.bluetooth.adapter.action.STATE_CHANGED".equals(action)) {
                BluetoothAdapter bluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
                int state = bluetoothAdapter.getState();
                Message msg2 = new Message();
                msg2.what = 5;
                msg2.arg1 = state;
                SwitcherContainerView.this.f3710G.sendMessage(msg2);
            }
            "android.location.PROVIDERS_CHANGED".equals(action);
            if ("com.safecenter.broadcast.openChildMode".equals(action)) {
                SwitcherContainerView.this.m1574b();
            }
            if ("com.safecenter.broadcast.openGuestMode".equals(action)) {
                SwitcherContainerView.this.m1579c();
            }
            if ("com.lenovo.safecenter.lightChanges".equals(action)) {
                SwitcherContainerView.this.m1582d(true);
            }
            if ("android.net.conn.CONNECTIVITY_CHANGE".equals(action)) {
                SwitcherContainerView.this.m1571a(false);
            }
        }
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.switch_wifi /* 2131296829 */:
                this.f3708E = false;
                int wifiCur = m1566a(1);
                int wifi = m1573b(wifiCur);
                this.f3724n.setStatus(SettingUtil.WIFI, wifi);
                break;
            case C0415R.id.switch_mobile_data /* 2131296830 */:
                if (1 == m1566a(12)) {
                    m1569a(20, 0, false);
                } else {
                    if (SettingUtil.isMultiSim) {
                        MultiSIMUtils utils = new MultiSIMUtils(f3703z);
                        if (utils.getSimState(0) != 5 && utils.getSimState(1) != 5) {
                            m1569a(20, 0, false);
                        }
                    } else {
                        TelephonyManager telephonyManager = (TelephonyManager) f3703z.getSystemService("phone");
                        if (telephonyManager.getSimState() != 5) {
                            m1569a(20, 0, false);
                        }
                    }
                    if (!this.f3706C) {
                        int dataCur = m1566a(2);
                        int data = m1573b(dataCur);
                        this.f3724n.setStatus(SettingUtil.DATA, data);
                        this.f3712b.setImage(C0415R.drawable.assist_switcher_mobile_data_on);
                        this.f3706C = true;
                        m1569a(2, data, true);
                        Handler handlerData = new Handler();
                        handlerData.postDelayed(new Runnable() { // from class: com.lenovo.safecenter.floatwindow.view.SwitcherContainerView.2
                            @Override // java.lang.Runnable
                            public final void run() {
                                if (SwitcherContainerView.this.f3706C) {
                                    SwitcherContainerView.m1593k(SwitcherContainerView.this);
                                    SwitcherContainerView.this.m1571a(true);
                                }
                            }
                        }, 6000L);
                    }
                }
                break;
            case C0415R.id.switch_ringtone /* 2131296831 */:
                int ringtoneCur = m1566a(3);
                int ringtone = m1573b(ringtoneCur);
                this.f3724n.setStatus(SettingUtil.RINGTONE, ringtone);
                m1576b(true);
                break;
            case C0415R.id.switch_vibrate /* 2131296832 */:
                int vibrateCur = m1566a(4);
                int vibrate = m1573b(vibrateCur);
                this.f3724n.setStatus(SettingUtil.VIBRATE, vibrate);
                m1580c(true);
                break;
            case C0415R.id.switch_light /* 2131296833 */:
                screenWindowDel = false;
                int brightness = 0;
                int brightnessCur = m1566a(5);
                if (brightnessCur < 5) {
                    brightness = brightnessCur + 1;
                } else if (brightnessCur == 5) {
                    brightness = 1;
                }
                this.f3724n.setStatus(SettingUtil.BRIGHTNESS, brightness);
                break;
            case C0415R.id.switch_rotation /* 2131296834 */:
                int rotateCur = m1566a(6);
                int rotate = m1573b(rotateCur);
                this.f3724n.setStatus(SettingUtil.AUTOROTATE, rotate);
                m1584e(true);
                break;
            case C0415R.id.switch_timeout /* 2131296835 */:
                int timeout = 0;
                int timeoutCur = m1566a(7);
                if (timeoutCur < 4) {
                    timeout = timeoutCur + 1;
                } else if (timeoutCur == 4) {
                    timeout = 1;
                }
                this.f3724n.setStatus(SettingUtil.TIMEOUT, timeout);
                m1586f(true);
                break;
            case C0415R.id.switch_bluetooth /* 2131296836 */:
                if (!this.f3707D) {
                    int bluetoothCur = m1566a(11);
                    int bluetooth = m1573b(bluetoothCur);
                    this.f3724n.setStatus(SettingUtil.BLUETOOTH, bluetooth);
                }
                break;
            case C0415R.id.switch_traffic_monitor /* 2131296837 */:
                FloatWindow.instanceFloatWindow.delFloatWindow();
                TrafficStatsService.startIntentTraffic(f3703z);
                break;
            case C0415R.id.switch_children_desktop /* 2131296838 */:
                if (TrafficStatsService.nacServerIsExist()) {
                    int childMode = m1566a(9);
                    int childModeOr = m1573b(childMode);
                    this.f3724n.setStatus(SettingUtil.CHILD_MODE, childModeOr);
                    m1574b();
                } else {
                    this.f3719i.setImage(C0415R.drawable.assist_switcher_children_desktop_off);
                    this.f3719i.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_off));
                    m1569a(9, 0, false);
                }
                break;
            case C0415R.id.switch_guest_mode /* 2131296839 */:
                if (TrafficStatsService.nacServerIsExist()) {
                    int visitorMode = m1566a(10);
                    int visitorModeOr = m1573b(visitorMode);
                    this.f3724n.setStatus(SettingUtil.GUEST_MODE, visitorModeOr);
                    m1579c();
                } else {
                    this.f3720j.setImage(C0415R.drawable.assist_switcher_visitor_mode_off);
                    this.f3720j.setLabelColor(f3703z.getResources().getColor(C0415R.color.text_switcher_item_off));
                    m1569a(10, 0, false);
                }
                break;
            case C0415R.id.switch_airplane_mode /* 2131296840 */:
                int radioCur = m1566a(12);
                int radio = m1573b(radioCur);
                this.f3709F = f3703z.getSharedPreferences(Constants.FLIGHT_STATUS, 0);
                if (radio == 1) {
                    this.f3709F.edit().putInt("wifi_status", m1566a(1)).putInt("data_status", m1566a(2)).putInt("bluetooth_status", m1566a(11)).commit();
                    this.f3724n.setStatus(SettingUtil.WIFI, 0);
                    this.f3711a.setImage(C0415R.drawable.assist_switcher_wifi_off);
                    this.f3711a.setLabelColor(getResources().getColor(C0415R.color.text_switcher_item_off));
                    this.f3724n.setStatus(SettingUtil.DATA, 0);
                    this.f3712b.setImage(C0415R.drawable.assist_switcher_mobile_data_off);
                    this.f3712b.setLabelColor(getResources().getColor(C0415R.color.text_switcher_item_off));
                    this.f3724n.setStatus(SettingUtil.BLUETOOTH, 0);
                    this.f3712b.setEnabled(false);
                    this.f3721k.setEnabled(false);
                } else {
                    this.f3712b.setEnabled(true);
                    this.f3721k.setEnabled(true);
                    int wifiFlag = this.f3709F.getInt("wifi_status", 0);
                    int dataFlag = this.f3709F.getInt("data_status", 0);
                    int bluetoothFlag = this.f3709F.getInt("bluetooth_status", 0);
                    if (wifiFlag == 1) {
                        this.f3724n.setStatus(SettingUtil.WIFI, 1);
                        this.f3711a.setImage(C0415R.drawable.assist_switcher_wifi_on);
                        this.f3711a.setLabelColor(getResources().getColor(C0415R.color.text_switcher_item_on));
                    }
                    if (dataFlag == 1) {
                        this.f3724n.setStatus(SettingUtil.DATA, 1);
                        this.f3712b.setImage(C0415R.drawable.assist_switcher_mobile_data_on);
                        this.f3712b.setLabelColor(getResources().getColor(C0415R.color.text_switcher_item_on));
                    }
                    if (bluetoothFlag == 1) {
                        this.f3724n.setStatus(SettingUtil.BLUETOOTH, 1);
                    }
                }
                this.f3724n.setStatus(SettingUtil.AIRPLANE, radio);
                m1590h(true);
                break;
        }
    }

    /* JADX INFO: renamed from: a */
    private int m1566a(int item) {
        switch (item) {
            case 1:
                int status = this.f3724n.getStatus(SettingUtil.WIFI);
                return status;
            case 2:
                int status2 = this.f3724n.getStatus(SettingUtil.DATA);
                return status2;
            case 3:
                int status3 = this.f3724n.getStatus(SettingUtil.RINGTONE);
                return status3;
            case 4:
                int status4 = this.f3724n.getStatus(SettingUtil.VIBRATE);
                return status4;
            case 5:
                int status5 = this.f3724n.getStatus(SettingUtil.BRIGHTNESS);
                return status5;
            case 6:
                int status6 = this.f3724n.getStatus(SettingUtil.AUTOROTATE);
                return status6;
            case 7:
                int status7 = this.f3724n.getStatus(SettingUtil.TIMEOUT);
                return status7;
            case 8:
            default:
                return 0;
            case 9:
                int status8 = this.f3724n.getStatus(SettingUtil.CHILD_MODE);
                return status8;
            case 10:
                int status9 = this.f3724n.getStatus(SettingUtil.GUEST_MODE);
                return status9;
            case 11:
                int status10 = this.f3724n.getStatus(SettingUtil.BLUETOOTH);
                return status10;
            case 12:
                int status11 = this.f3724n.getStatus(SettingUtil.AIRPLANE);
                return status11;
        }
    }

    /* JADX INFO: renamed from: b */
    private static int m1573b(int a) {
        switch (a) {
            case 0:
                return 1;
            case 1:
                return 0;
            default:
                return 0;
        }
    }
}
