package com.lenovo.safecenter.net.doublemode;

import android.app.Activity;
import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.provider.MultiSIMUtils;
import android.text.TextUtils;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.net.LowLevelNetFilter;
import com.lenovo.safecenter.net.NetFilter;
import com.lenovo.safecenter.net.TrafficStatistics;
import com.lenovo.safecenter.net.support.PhoneSimInfo;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;

/* JADX INFO: loaded from: classes.dex */
public class DoubleCardUtil {
    public static final int SET_DAILY_NOTICE = 1;
    public static final int SET_MONTH_CHECK = 4;
    public static final int SET_MONTH_FREE_NOTICE = 5;
    public static final int SET_MONTH_NOTICE = 2;
    public static final int SET_MONTH_PACKAGE = 3;

    public interface SettingFloatNumberDialogListener {
        void onSettingFloatNumberDialogCancel(int i, Float[] fArr);

        void onSettingFloatNumberDialogOK(int i, Float[] fArr);
    }

    public interface SettingNumberDialogListener1 {
        void onSettingNumberDialogCancel(int i);

        void onSettingNumberDialogOK(int i, int i2, int i3);
    }

    public interface SettingNumberDialogListener2 {
        void onSettingNumberDialogCancel(int[] iArr, int i);

        void onSettingNumberDialogOK(int[] iArr, int i);
    }

    public static void createSettingNumberDialog(Context context, final SettingNumberDialogListener2 listener, final int flag) {
        PhoneSimInfo info = TrafficStatsService.getImsiInfo(context);
        int mode = TrafficStatsService.getTrafficMode(context);
        Log.i("trafficmode", "mode =" + mode);
        if (mode == 12) {
            if (TextUtils.isEmpty(info.sim1IMSI) && TextUtils.isEmpty(info.sim2IMSI)) {
                Toast.makeText(context, C0415R.string.net_simcard_error2, 1).show();
                return;
            }
        } else if (mode == 10 && TextUtils.isEmpty(WflUtils.getActiveSubscriberId(context))) {
            Toast.makeText(context, C0415R.string.net_simcard_error2, 1).show();
            return;
        }
        View view = LayoutInflater.from(context).inflate(C0415R.layout.net_traffic_package_set, (ViewGroup) null);
        LinearLayout layoutSim2 = (LinearLayout) view.findViewById(C0415R.id.net_card_flag);
        LinearLayout layoutSim1 = (LinearLayout) view.findViewById(C0415R.id.net_card1_flag);
        if (mode != 12) {
            layoutSim2.setVisibility(8);
            TextView textView = (TextView) view.findViewById(C0415R.id.net_card3_id);
            textView.setTextSize(18.0f);
            textView.setText(context.getString(C0415R.string.net_traffic_package_limit) + C0092c.f1283N);
        } else {
            if (TextUtils.isEmpty(info.sim1IMSI)) {
                layoutSim1.setVisibility(8);
            }
            if (TextUtils.isEmpty(info.sim2IMSI)) {
                layoutSim2.setVisibility(8);
            }
        }
        final EditText editText = (EditText) view.findViewById(C0415R.id.net_set_card1_package);
        final EditText editText2 = (EditText) view.findViewById(C0415R.id.net_set_card2_package);
        String limit = Const.getMonthLimitTraffic();
        String limit2 = Const.getMonthLimitTraffic2();
        if (!"-1".equals(limit)) {
            editText.setText(limit);
        }
        if (!"-1".equals(limit2)) {
            editText2.setText(limit2);
        }
        TrackEvent.reportSetTrafficLimit();
        CustomDialog.Builder builder = new CustomDialog.Builder(context);
        builder.setTitle(C0415R.string.net_traffic_package_limit);
        builder.setContentView(view);
        builder.setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.DoubleCardUtil.1
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                String number = editText.getText().toString();
                String number2 = editText2.getText().toString();
                if (TextUtils.isEmpty(number) || Integer.parseInt(number) == 0) {
                    number = "-1";
                }
                if (TextUtils.isEmpty(number2) || Integer.parseInt(number2) == 0) {
                    number2 = "-1";
                }
                int[] number3 = {Integer.valueOf(number).intValue(), Integer.valueOf(number2).intValue()};
                listener.onSettingNumberDialogOK(number3, flag);
            }
        });
        builder.setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.DoubleCardUtil.8
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                int[] number3 = new int[0];
                listener.onSettingNumberDialogCancel(number3, flag);
            }
        });
        builder.show();
    }

    public static void createSettingNumberDialog2(final Activity context, final SettingNumberDialogListener1 listener, final int id, final String card) {
        context.getString(C0415R.string.net_card1);
        View view = LayoutInflater.from(context).inflate(C0415R.layout.net_traffic_edittext_single, (ViewGroup) null);
        final EditText editText = (EditText) view.findViewById(C0415R.id.net_set_card1_package);
        TextView mTextView = (TextView) view.findViewById(C0415R.id.net_singline_edit_desc);
        String mString = null;
        String title = null;
        switch (id) {
            case 1:
                mString = String.valueOf(Const.getNetEverydayLimit());
                title = context.getString(C0415R.string.net_daily_notice_number_desc2);
                mTextView.setText(C0415R.string.net_daily_notice_number_desc);
                break;
            case 2:
                String mString1 = context.getString(C0415R.string.net_month_notice_number_desc);
                mTextView.setText(String.format(mString1, card));
                title = card + context.getString(C0415R.string.net_traffic_package_limit);
                break;
        }
        if (!"-1".equals(mString)) {
            editText.setText(mString);
        } else {
            editText.setText("");
        }
        CustomDialog.Builder builder = new CustomDialog.Builder(context);
        builder.setTitle(title);
        builder.setContentView(view);
        builder.setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.DoubleCardUtil.9
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                int cardPostion = 0;
                if (context.getString(C0415R.string.net_card1).equals(card)) {
                    cardPostion = 1;
                }
                if (context.getString(C0415R.string.net_card2).equals(card)) {
                    cardPostion = 2;
                }
                String number = editText.getText().toString();
                if (TextUtils.isEmpty(number)) {
                    if (id == 1) {
                        listener.onSettingNumberDialogOK(Integer.valueOf("-1").intValue(), id, cardPostion);
                        return;
                    } else {
                        Toast.makeText(context, context.getString(C0415R.string.no_null_limit_input_num_text), 1).show();
                        return;
                    }
                }
                if (Integer.parseInt(number) == 0) {
                    if (id == 1) {
                        listener.onSettingNumberDialogOK(Integer.valueOf("-1").intValue(), id, cardPostion);
                        return;
                    } else {
                        Toast.makeText(context, context.getString(C0415R.string.no_zero_limit_input_num_text), 1).show();
                        return;
                    }
                }
                Log.i("doublecard", "id = " + id + ",cardpostion = " + cardPostion);
                listener.onSettingNumberDialogOK(Integer.valueOf(number).intValue(), id, cardPostion);
            }
        });
        builder.setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.DoubleCardUtil.10
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        });
        builder.show();
    }

    public static void createSettingCheckBoxDialog(final Activity context, final SettingNumberDialogListener1 listener, int id) {
        PhoneSimInfo info = TrafficStatsService.getImsiInfo(context);
        int mode = TrafficStatsService.getTrafficMode(context);
        if (mode == 12) {
            if (TextUtils.isEmpty(info.sim1IMSI) && TextUtils.isEmpty(info.sim2IMSI)) {
                Toast.makeText(context, C0415R.string.net_simcard_error2, 1).show();
                return;
            }
        } else if (TextUtils.isEmpty(WflUtils.getActiveSubscriberId(context))) {
            Toast.makeText(context, C0415R.string.net_simcard_error2, 1).show();
            return;
        }
        View view = LayoutInflater.from(context).inflate(C0415R.layout.net_checkbox_dailog, (ViewGroup) null);
        RelativeLayout sim1View = (RelativeLayout) view.findViewById(C0415R.id.net_sim1_notice);
        RelativeLayout sim2View = (RelativeLayout) view.findViewById(C0415R.id.net_sim2_notice);
        if (TextUtils.isEmpty(info.sim1IMSI)) {
            sim1View.setVisibility(8);
        }
        if (TextUtils.isEmpty(info.sim2IMSI)) {
            sim2View.setVisibility(8);
        }
        final CheckBox mCheckBox1 = (CheckBox) view.findViewById(C0415R.id.net_card1_notice_checkbox);
        final CheckBox mCheckBox2 = (CheckBox) view.findViewById(C0415R.id.net_card2_notice_checkbox);
        final String limit = Const.getMonthLimitTraffic();
        final String limit2 = Const.getMonthLimitTraffic2();
        if (!"-1".equals(limit)) {
            mCheckBox1.setChecked(Const.getIsNetMonthFreeNoticeOn1());
        } else {
            mCheckBox1.setChecked(false);
        }
        if (!"-1".equals(limit2)) {
            mCheckBox2.setChecked(Const.getIsNetMonthFreeNoticeOn2());
        } else {
            mCheckBox2.setChecked(false);
        }
        CustomDialog.Builder builder = new CustomDialog.Builder(context);
        builder.setTitle(C0415R.string.net_month_notice_title2);
        builder.setContentView(view);
        builder.setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.DoubleCardUtil.11
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        });
        builder.setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.DoubleCardUtil.12
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                boolean checked1 = mCheckBox1.isChecked();
                boolean checked2 = mCheckBox2.isChecked();
                if (checked2 && "-1".equals(limit2)) {
                    DoubleCardUtil.createSettingNumberDialog2(context, listener, 2, context.getString(C0415R.string.net_card2));
                }
                if (checked1 && "-1".equals(limit)) {
                    DoubleCardUtil.createSettingNumberDialog2(context, listener, 2, context.getString(C0415R.string.net_card1));
                }
                Const.setIsNetMonthFreeNoticeOn1(checked1);
                Const.setIsNetMonthFreeNoticeOn2(checked2);
                listener.onSettingNumberDialogOK(-1, 5, -1);
            }
        });
        builder.show();
    }

    public static void createSettingFloatDialog(final Activity context, final SettingFloatNumberDialogListener listener, final int id) {
        PhoneSimInfo info = TrafficStatsService.getImsiInfo(context);
        int mode = TrafficStatsService.getTrafficMode(context);
        if (mode == 12) {
            if (TextUtils.isEmpty(info.sim1IMSI) && TextUtils.isEmpty(info.sim2IMSI)) {
                Toast.makeText(context, C0415R.string.net_simcard_error2, 1).show();
                return;
            }
        } else if (mode == 10 && TextUtils.isEmpty(WflUtils.getActiveSubscriberId(context))) {
            Toast.makeText(context, C0415R.string.net_simcard_error2, 1).show();
            return;
        }
        View view = LayoutInflater.from(context).inflate(C0415R.layout.net_traffic_check_set, (ViewGroup) null);
        LinearLayout layout2 = (LinearLayout) view.findViewById(C0415R.id.net_card_flag);
        LinearLayout layout1 = (LinearLayout) view.findViewById(C0415R.id.net_card1_flag);
        TextView textView = (TextView) view.findViewById(C0415R.id.net_set_title_summary);
        TextView mText = (TextView) view.findViewById(C0415R.id.net_card3_id);
        TextView mText2 = (TextView) view.findViewById(C0415R.id.net_text_desc2);
        final EditText editText = (EditText) view.findViewById(C0415R.id.net_set_card1_package);
        final EditText editText2 = (EditText) view.findViewById(C0415R.id.net_set_card2_package);
        if (mode != 12) {
            layout2.setVisibility(8);
            textView.setVisibility(8);
        } else if (mode == 12) {
            MultiSIMUtils multiSIMUtils = MultiSIMUtils.getDefault(context);
            if (TextUtils.isEmpty(multiSIMUtils.getSubscriberId(0))) {
                layout1.setVisibility(8);
            }
            if (TextUtils.isEmpty(multiSIMUtils.getSubscriberId(1))) {
                layout2.setVisibility(8);
            }
        }
        switch (id) {
            case 4:
                if (mode == 12) {
                    mText.setText(context.getString(C0415R.string.net_card1) + context.getString(C0415R.string.net_traffice_used));
                } else {
                    mText.setText(context.getString(C0415R.string.net_traffice_used));
                }
                mText2.setText(context.getString(C0415R.string.net_card2) + context.getString(C0415R.string.net_traffice_used));
                break;
        }
        CustomDialog.Builder builder = new CustomDialog.Builder(context);
        builder.setTitle(C0415R.string.month_used_Traffic_Check);
        builder.setContentView(view);
        builder.setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.DoubleCardUtil.13
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                String number = editText.getText().toString();
                String number2 = editText2.getText().toString();
                if (TextUtils.isEmpty(number) && TextUtils.isEmpty(number2)) {
                    Toast.makeText(context, C0415R.string.no_null_limit_input_num_text, 1).show();
                    return;
                }
                try {
                    if (TextUtils.isEmpty(number)) {
                        number = "-1";
                    }
                    if (TextUtils.isEmpty(number2)) {
                        number2 = "-1";
                    }
                    Float[] number3 = {Float.valueOf(number), Float.valueOf(number2)};
                    listener.onSettingFloatNumberDialogOK(id, number3);
                } catch (NumberFormatException e) {
                    e.printStackTrace();
                    Toast.makeText(context, C0415R.string.check_traffic_input_num_error, 1).show();
                }
            }
        });
        builder.setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.DoubleCardUtil.14
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        });
        builder.show();
    }

    public static void checkTraffic(Float number, TrafficStatsService mAppDatabase, Context context, int postion) {
        long sysMonthUsedTraffic;
        String simSubscriberId;
        long checkMonthUsedTraffic = (long) (number.floatValue() * 1024.0f * 1024.0f);
        int mode = TrafficStatsService.getTrafficMode(context);
        if (mode == 12 || mode == 10) {
            sysMonthUsedTraffic = TrafficStatsService.statsSystemMonthTraffic(context, postion);
        } else {
            sysMonthUsedTraffic = TrafficStatsService.statsSettingUiMonthTrafficLowLevel(context);
        }
        Log.i("checkTraffic", "sysMonthUsedTraffic =" + sysMonthUsedTraffic + ",checkMonthUsedTraffic =" + checkMonthUsedTraffic);
        long inaccuracyTraffic = checkMonthUsedTraffic - sysMonthUsedTraffic;
        if (mode == 12) {
            simSubscriberId = MultiSIMUtils.getDefault(context).getSubscriberId(postion);
        } else if (mode == 10) {
            simSubscriberId = WflUtils.getActiveSubscriberId(context);
        } else {
            simSubscriberId = "dev";
        }
        Log.i("testtrafficbug", "checkTraffic float inaccuracy= " + inaccuracyTraffic + ",simSubscriberId =" + simSubscriberId);
        mAppDatabase.updateTrafficCheck(simSubscriberId, String.valueOf(inaccuracyTraffic));
        TrafficStatsService.statsTrafficMobile(context);
    }

    public static void checkTraffic(long number, TrafficStatsService mAppDatabase, Context context, int postion) {
        long sysMonthUsedTraffic;
        String simSubscriberId;
        int mode = TrafficStatsService.getTrafficMode(context);
        if (mode == 12 || mode == 10) {
            sysMonthUsedTraffic = TrafficStatsService.statsSystemMonthTraffic(context, postion);
        } else {
            sysMonthUsedTraffic = TrafficStatsService.statsSettingUiMonthTrafficLowLevel(context);
        }
        long inaccuracyTraffic = number - sysMonthUsedTraffic;
        if (mode == 12) {
            simSubscriberId = MultiSIMUtils.getDefault(context).getSubscriberId(postion);
        } else if (mode == 10) {
            simSubscriberId = WflUtils.getActiveSubscriberId(context);
        } else {
            simSubscriberId = "dev";
        }
        Log.i("testtrafficbug", "checkTraffic long inaccuracy= " + inaccuracyTraffic + ",simSubscriberId =" + simSubscriberId);
        mAppDatabase.updateTrafficCheck(simSubscriberId, String.valueOf(inaccuracyTraffic));
        TrafficStatsService.statsTrafficMobile(context);
    }

    public static void showTariffOutLimitNotification(Context context, String title, String content, int id) {
        Intent intent;
        NotificationManager manager = (NotificationManager) context.getSystemService(DatabaseTables.LOG_NOTIFICATION);
        Notification notification = new Notification();
        notification.flags = 16;
        notification.when = System.currentTimeMillis();
        notification.icon = C0415R.drawable.net_traffic_warn_;
        notification.defaults = 1;
        int trafficMod = TrafficStatsService.getTrafficMode(context);
        switch (id) {
            case 9:
                intent = trafficMod == 13 ? new Intent(context, (Class<?>) LowLevelNetFilter.class) : new Intent(context, (Class<?>) NetFilter.class);
                break;
            case 22:
                intent = trafficMod == 12 ? new Intent(context, (Class<?>) TrafficStatisticsDoubleMode.class) : new Intent(context, (Class<?>) TrafficStatistics.class);
                break;
            case 24:
                intent = trafficMod == 13 ? new Intent(context, (Class<?>) LowLevelNetFilter.class) : new Intent(context, (Class<?>) NetFilter.class);
                break;
            default:
                intent = new Intent();
                if (Const.SDK_VERSION >= 14) {
                    intent.setAction("android.settings.SETTINGS");
                } else {
                    intent.setAction("android.settings.WIRELESS_SETTINGS");
                }
                break;
        }
        PendingIntent pendingIntent = PendingIntent.getActivity(context, 0, intent, 0);
        notification.setLatestEventInfo(context, title, content, pendingIntent);
        manager.notify(id, notification);
    }

    public static void showDailog(final Activity context, final int cardPostion, final SettingNumberDialogListener1 listener, final int viewId) {
        View view = LayoutInflater.from(context).inflate(C0415R.layout.net_traffic_package_set, (ViewGroup) null);
        LinearLayout layout = (LinearLayout) view.findViewById(C0415R.id.net_card_flag);
        TextView textView = (TextView) view.findViewById(C0415R.id.net_card3_id);
        layout.setVisibility(8);
        final EditText editText = (EditText) view.findViewById(C0415R.id.net_set_card1_package);
        String limit = cardPostion == 0 ? Const.getMonthLimitTraffic() : Const.getMonthLimitTraffic2();
        textView.setText(cardPostion == 0 ? C0415R.string.net_card3 : C0415R.string.net_card4);
        if (!"-1".equals(limit)) {
            editText.setText(limit);
        }
        CustomDialog.Builder builder = new CustomDialog.Builder(context);
        builder.setTitle(C0415R.string.net_traffic_package_limit);
        builder.setContentView(view);
        builder.setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.DoubleCardUtil.15
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                String number = editText.getText().toString();
                if (TextUtils.isEmpty(number)) {
                    number = "-1";
                } else if (Integer.parseInt(number) == 0) {
                    Toast.makeText(context, context.getString(C0415R.string.no_zero_limit_input_num_text), 1).show();
                    number = "-1";
                }
                listener.onSettingNumberDialogOK(Integer.valueOf(number).intValue(), viewId, cardPostion);
            }
        });
        builder.setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.DoubleCardUtil.2
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        });
        builder.show();
    }

    public static void showCorrectDialog(final Context context) {
        if (TrafficStatsService.IsAirModeOn(context)) {
            Toast.makeText(context, context.getString(C0415R.string.net_traffic_correct_air), 1).show();
            return;
        }
        final PhoneSimInfo info = TrafficStatsService.getImsiInfo(context);
        CustomDialog.Builder builder = new CustomDialog.Builder(context);
        builder.setColorNegativeButton(false);
        builder.setColorNeutralButton(false);
        builder.setColorPositiveButton(false);
        builder.setTitle(C0415R.string.month_used_Traffic_Check);
        builder.setMessage(C0415R.string.net_correct_message);
        if (!TextUtils.isEmpty(info.sim1IMSI)) {
            builder.setNeutralButton(C0415R.string.net_sim1_correct, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.DoubleCardUtil.3
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface dialog, int which) {
                    if (info.sim1IMSI == null) {
                        Toast.makeText(context, "SIM1" + context.getString(C0415R.string.net_simcard_error), 1).show();
                    } else if ("-1".equals(Const.getMonthLimitTraffic())) {
                        Toast.makeText(context, context.getString(C0415R.string.net_need_set_traffic), 1).show();
                    } else {
                        TrafficStatsService.startIntent2TrafficCorrect(0, context, 0);
                    }
                }
            });
        }
        if (!TextUtils.isEmpty(info.sim2IMSI)) {
            builder.setPositiveButton(C0415R.string.net_sim2_correct, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.DoubleCardUtil.4
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface dialog, int which) {
                    if (info.sim2IMSI == null) {
                        Toast.makeText(context, "SIM2" + context.getString(C0415R.string.net_simcard_error), 1).show();
                    } else if ("-1".equals(Const.getMonthLimitTraffic2())) {
                        Toast.makeText(context, context.getString(C0415R.string.net_need_set_traffic), 1).show();
                    } else {
                        TrafficStatsService.startIntent2TrafficCorrect(1, context, 0);
                    }
                }
            });
        }
        builder.setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.DoubleCardUtil.5
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        });
        builder.show();
    }

    public static void showSetNetWorkDialog(final Context context) {
        CustomDialog.Builder builder = new CustomDialog.Builder(context);
        builder.setTitle(C0415R.string.set_net_text);
        builder.setMessage(C0415R.string.net_traffic_not_on2);
        builder.setPositiveButton(C0415R.string.set_net_text, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.DoubleCardUtil.6
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                WflUtils.startWirelessSettingsActivity(context);
            }
        });
        builder.setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.DoubleCardUtil.7
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        });
        builder.show();
    }
}
