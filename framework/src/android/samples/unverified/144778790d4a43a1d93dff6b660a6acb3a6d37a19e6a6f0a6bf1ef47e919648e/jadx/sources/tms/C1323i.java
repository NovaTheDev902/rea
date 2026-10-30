package tms;

import com.tencent.lbsapi.QLBSNotification;
import com.tencent.lbsapi.model.QLBSPoiInfoBatch;
import com.tencent.lbsapi.model.QLBSPosition;
import com.tencent.tmsecure.utils.PhoneInfoUtil;
import com.tencent.tmsecure.utils.SMSUtil;
import java.text.DecimalFormat;

/* JADX INFO: renamed from: tms.i */
/* JADX INFO: loaded from: classes.dex */
final class C1323i implements QLBSNotification {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ String f7449a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ C1155al f7450b;

    C1323i(C1155al c1155al, String str) {
        this.f7450b = c1155al;
        this.f7449a = str;
    }

    @Override // com.tencent.lbsapi.QLBSNotification
    public final void onLocationNotification(int i) {
        if (i == 1) {
            this.f7450b.f6838d.requestGetCurrentPosition(101, PhoneInfoUtil.getIMEI(this.f7450b.f6835a), 3);
        } else {
            SMSUtil.sendSMS(this.f7449a, this.f7450b.f6836b.tips4LocateFaild(), this.f7450b.f6835a);
            C1155al.m2926c(this.f7450b);
        }
    }

    @Override // com.tencent.lbsapi.QLBSNotification
    public final void onResponseError(int i, int i2, String str) {
        SMSUtil.sendSMS(this.f7449a, this.f7450b.f6836b.tips4LocateFaild(), this.f7450b.f6835a);
        C1155al.m2926c(this.f7450b);
    }

    @Override // com.tencent.lbsapi.QLBSNotification
    public final void onResponseGetCurPosition(int i, QLBSPosition qLBSPosition) {
        if (qLBSPosition != null) {
            DecimalFormat decimalFormat = new DecimalFormat("#.00");
            String str = decimalFormat.format(qLBSPosition.getGps().getLat());
            String str2 = decimalFormat.format(qLBSPosition.getGps().getLon());
            SMSUtil.sendSMS(this.f7449a, this.f7450b.f6836b.tips4LocateSuccess() + ("http://msm.qq.com/1?" + str + "," + str2 + " \n" + qLBSPosition.getCity() + qLBSPosition.getDistrict() + qLBSPosition.getRoad() + "（纬度：" + str + ", 经度：" + str2 + "）"), this.f7450b.f6835a);
        } else {
            SMSUtil.sendSMS(this.f7449a, this.f7450b.f6836b.tips4LocateFaild(), this.f7450b.f6835a);
        }
        C1155al.m2926c(this.f7450b);
    }

    @Override // com.tencent.lbsapi.QLBSNotification
    public final void onResponseGetNearPoiList(int i, QLBSPoiInfoBatch qLBSPoiInfoBatch) {
    }

    @Override // com.tencent.lbsapi.QLBSNotification
    public final void onResponseSearchNearPoiList(int i, QLBSPoiInfoBatch qLBSPoiInfoBatch) {
    }
}
