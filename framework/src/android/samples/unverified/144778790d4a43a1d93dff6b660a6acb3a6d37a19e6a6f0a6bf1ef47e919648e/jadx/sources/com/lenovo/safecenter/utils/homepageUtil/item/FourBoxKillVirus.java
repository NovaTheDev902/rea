package com.lenovo.safecenter.utils.homepageUtil.item;

import android.content.Context;
import android.content.Intent;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.antivirus.MainActivity;
import com.lenovo.safecenter.antivirus.utils.HttpUtils;
import com.lenovo.safecenter.antivirus.views.ScanVirusActivity;
import com.lenovo.safecenter.utils.WflUtils;
import com.lenovo.safecenter.utils.homepageUtil.BaseFourBox;
import java.io.File;
import java.text.SimpleDateFormat;
import java.util.Date;

/* JADX INFO: loaded from: classes.dex */
public class FourBoxKillVirus extends BaseFourBox {
    public FourBoxKillVirus(Context context) {
        super(C0415R.drawable.img_kill_virus, context.getString(C0415R.string.anti_virus), context);
    }

    @Override // com.lenovo.safecenter.utils.homepageUtil.BaseFourBox
    public View getView(View parent) {
        ImageView icon = (ImageView) parent.findViewById(C0415R.id.img_icon);
        TextView tvTitle = (TextView) parent.findViewById(C0415R.id.tv_title);
        View layoutCenterAlign = parent.findViewById(C0415R.id.layout_content_twoLine_centerAlign);
        View layoutLeftAndRightAlign = parent.findViewById(C0415R.id.layout_content_twoLine_leftAndRightAlign);
        TextView tv_LR_Line1Title = (TextView) parent.findViewById(C0415R.id.tv_leftAndRightAlign_up_title);
        TextView tv_LR_Line1Detail = (TextView) parent.findViewById(C0415R.id.tv_leftAndRightAlign_up_detail);
        TextView tv_LR_Line2Title = (TextView) parent.findViewById(C0415R.id.tv_leftAndRightAlign_down_title);
        icon.setImageResource(this.idIcon);
        tvTitle.setText(this.mTitle);
        String scantime = HttpUtils.execService("scantime", this.mContext);
        if (TextUtils.isEmpty(scantime)) {
            layoutLeftAndRightAlign.setVisibility(0);
            layoutCenterAlign.setVisibility(8);
            tv_LR_Line1Title.setText(this.mContext.getString(C0415R.string.nerver_scan_virus));
            m2448a(tv_LR_Line2Title);
        } else {
            layoutCenterAlign.setVisibility(8);
            layoutLeftAndRightAlign.setVisibility(0);
            int interval = m2447a();
            tv_LR_Line1Title.setText(this.mContext.getString(C0415R.string.antiviruslatest_scantime));
            if (interval <= 0) {
                if (!TextUtils.isEmpty(scantime)) {
                    SimpleDateFormat sdf = new SimpleDateFormat("HH:mm");
                    tv_LR_Line1Detail.setText(sdf.format(new Date(Long.parseLong(scantime))));
                }
            } else if (interval > 0 && interval <= 99) {
                tv_LR_Line1Detail.setText(interval + this.mContext.getString(C0415R.string.today_befor));
                tv_LR_Line1Detail.setTextColor(this.mContext.getResources().getColor(C0415R.color.red1));
            } else {
                tv_LR_Line1Detail.setText(this.mContext.getString(C0415R.string.nday_ago));
                tv_LR_Line1Detail.setTextColor(this.mContext.getResources().getColor(C0415R.color.red1));
            }
            m2448a(tv_LR_Line2Title);
        }
        return parent;
    }

    /* JADX INFO: renamed from: a */
    private void m2448a(TextView tv) {
        String virusState = HttpUtils.execService("virus_state", this.mContext);
        if ("3".equals(virusState)) {
            tv.setText(C0415R.string.virus_lab_updated_newest);
            return;
        }
        if (DatabaseTables.USER_MARK.equals(virusState)) {
            tv.setText(C0415R.string.please_update_viruslab);
            tv.setTextColor(this.mContext.getResources().getColor(C0415R.color.red1));
            return;
        }
        try {
            if (new File(this.mContext.getFilesDir() + "/qv_base.amf").exists()) {
                tv.setText(HttpUtils.getDate(String.valueOf(new File(this.mContext.getFilesDir() + "/qv_base.amf").lastModified())));
            } else {
                tv.setText("2012-11-13");
            }
        } catch (Exception e) {
            tv.setText("2012-11-13");
        }
    }

    @Override // com.lenovo.safecenter.utils.homepageUtil.BaseFourBox
    public void onClick() {
        enterKillVirus(this.mContext);
    }

    public static void enterKillVirus(Context context) {
        Intent it = new Intent(context, (Class<?>) MainActivity.class);
        String strExecService = HttpUtils.execService("viruspkgname", context);
        int length = TextUtils.isEmpty(strExecService) ? 0 : strExecService.split(",").length;
        Log.i("wu0wu", "getVirusCount=" + length);
        if (length > 0) {
            it = new Intent(context, (Class<?>) ScanVirusActivity.class);
        }
        context.startActivity(it);
    }

    /* JADX INFO: renamed from: a */
    private int m2447a() {
        try {
            return WflUtils.getDaysNumFromToday(Long.valueOf(HttpUtils.execService("scantime", this.mContext)).longValue());
        } catch (Exception e) {
            return 0;
        }
    }
}
