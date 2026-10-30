package com.lenovo.safecenter.utils.homepageUtil.item;

import android.content.Context;
import android.text.TextUtils;
import android.text.format.Formatter;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.net.cache.NetCache;
import com.lenovo.safecenter.net.support.PhoneSimInfo;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.NewFunctionNoticeManager;
import com.lenovo.safecenter.utils.WflUtils;
import com.lenovo.safecenter.utils.homepageUtil.BaseFourBox;

/* JADX INFO: loaded from: classes.dex */
public class FourBoxTrafficMonitor extends BaseFourBox {
    public FourBoxTrafficMonitor(Context context) {
        super(C0415R.drawable.img_traffic_monitor, context.getString(C0415R.string.traffic_monitor), context);
    }

    @Override // com.lenovo.safecenter.utils.homepageUtil.BaseFourBox
    public View getView(View parent) {
        String strTodayUsed;
        String strMonthFree;
        int color;
        if (NewFunctionNoticeManager.hasContentInType(this.mContext, NewFunctionNoticeManager.TYPE_TRAFFIC_MONITOR)) {
            ImageView newMark = (ImageView) parent.findViewById(C0415R.id.newmark_fourbox_item);
            newMark.setVisibility(0);
        }
        ImageView icon = (ImageView) parent.findViewById(C0415R.id.img_icon);
        TextView tvTitle = (TextView) parent.findViewById(C0415R.id.tv_title);
        ViewGroup layoutCenterAlign = (ViewGroup) parent.findViewById(C0415R.id.layout_content_twoLine_centerAlign);
        ViewGroup layoutLeftAndRightAlign = (ViewGroup) parent.findViewById(C0415R.id.layout_content_twoLine_leftAndRightAlign);
        TextView tv_LR_Line1Title = (TextView) parent.findViewById(C0415R.id.tv_leftAndRightAlign_up_title);
        TextView tv_LR_Line1Detail = (TextView) parent.findViewById(C0415R.id.tv_leftAndRightAlign_up_detail);
        TextView tv_LR_Line2Title = (TextView) parent.findViewById(C0415R.id.tv_leftAndRightAlign_down_title);
        TextView tv_LR_Line2Detail = (TextView) parent.findViewById(C0415R.id.tv_leftAndRightAlign_down_detail);
        icon.setImageResource(this.idIcon);
        tvTitle.setText(this.mTitle);
        layoutCenterAlign.setVisibility(8);
        layoutLeftAndRightAlign.setVisibility(0);
        tv_LR_Line1Title.setText(this.mContext.getString(C0415R.string.traffic_today_used));
        try {
            PhoneSimInfo phoneSimInfo = TrafficStatsService.getImsiInfo(this.mContext);
            TrafficStatsService.initNetCache(this.mContext);
            Log.i("air", "NetCache.imsi = " + NetCache.imsi);
            long monthFree = 0;
            long todayUsed = 0;
            String monthLimit = null;
            int dataPostion = TrafficStatsService.getDataCardPosition(this.mContext);
            int trafficMode = TrafficStatsService.getTrafficMode(this.mContext);
            if (dataPostion == 0) {
                if (TextUtils.isEmpty(NetCache.imsi) && NetCache.traffic_mode != 13) {
                    todayUsed = 0;
                } else {
                    todayUsed = Const.getTodayUsedTraffic();
                }
                monthFree = Const.getMonthFreeTraffic();
                Const.getProgressTrafficMonthUsed();
                monthLimit = Const.getMonthLimitTraffic();
            } else if (dataPostion == 1) {
                if (TextUtils.isEmpty(NetCache.imsi2)) {
                    todayUsed = 0;
                } else {
                    todayUsed = Const.getTodayUsedTraffic2();
                }
                monthFree = Const.getMonthFreeTraffic2();
                Const.getProgressTrafficMonthUsed2();
                monthLimit = Const.getMonthLimitTraffic2();
            }
            if (todayUsed == 0) {
                strTodayUsed = "0MB";
            } else {
                strTodayUsed = Formatter.formatShortFileSize(this.mContext, todayUsed);
            }
            if (trafficMode == 12 && TextUtils.isEmpty(phoneSimInfo.sim1IMSI) && TextUtils.isEmpty(phoneSimInfo.sim2IMSI)) {
                tv_LR_Line2Title.setText(C0415R.string.net_simcard_error4);
                tv_LR_Line2Title.setTextColor(this.mContext.getResources().getColor(C0415R.color.green2));
                WflUtils.setSpannableString(tv_LR_Line1Detail, strTodayUsed, 0, WflUtils.getCharIndexInString(strTodayUsed), this.mContext.getResources().getColor(C0415R.color.green2));
            } else if (trafficMode == 10 && TextUtils.isEmpty(phoneSimInfo.sim1IMSI)) {
                tv_LR_Line2Title.setText(C0415R.string.net_simcard_error4);
                tv_LR_Line2Title.setTextColor(this.mContext.getResources().getColor(C0415R.color.green2));
                WflUtils.setSpannableString(tv_LR_Line1Detail, strTodayUsed, 0, WflUtils.getCharIndexInString(strTodayUsed), this.mContext.getResources().getColor(C0415R.color.green2));
            } else if (monthFree < 0 && !"-1".equals(monthLimit)) {
                String strMonthFree2 = Formatter.formatShortFileSize(this.mContext, -monthFree);
                tv_LR_Line2Title.setText(this.mContext.getString(C0415R.string.traffic_month_exceed_used));
                WflUtils.setSpannableString(tv_LR_Line1Detail, strTodayUsed, 0, WflUtils.getCharIndexInString(strTodayUsed), this.mContext.getResources().getColor(C0415R.color.green2));
                WflUtils.setSpannableString(tv_LR_Line2Detail, strMonthFree2, 0, WflUtils.getCharIndexInString(strMonthFree2), this.mContext.getResources().getColor(C0415R.color.red1));
            } else if ("-1".equals(monthLimit)) {
                tv_LR_Line2Title.setText(C0415R.string.can_not_stats);
                tv_LR_Line2Title.setTextColor(this.mContext.getResources().getColor(C0415R.color.red1));
                WflUtils.setSpannableString(tv_LR_Line1Detail, strTodayUsed, 0, WflUtils.getCharIndexInString(strTodayUsed), this.mContext.getResources().getColor(C0415R.color.green2));
            } else {
                if (monthFree == 0) {
                    strMonthFree = "0MB";
                } else {
                    strMonthFree = Formatter.formatShortFileSize(this.mContext, monthFree);
                }
                tv_LR_Line2Title.setText(this.mContext.getString(C0415R.string.month_free));
                WflUtils.setSpannableString(tv_LR_Line1Detail, strTodayUsed, 0, WflUtils.getCharIndexInString(strTodayUsed), this.mContext.getResources().getColor(C0415R.color.green2));
                if ("0MB".equals(strMonthFree)) {
                    color = C0415R.color.red1;
                } else {
                    color = C0415R.color.green2;
                }
                WflUtils.setSpannableString(tv_LR_Line2Detail, strMonthFree, 0, WflUtils.getCharIndexInString(strMonthFree), this.mContext.getResources().getColor(color));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return parent;
    }

    @Override // com.lenovo.safecenter.utils.homepageUtil.BaseFourBox
    public void onClick() {
        TrafficStatsService.startIntentTraffic(this.mContext);
    }
}
