package tms;

import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.provider.Settings;
import com.tencent.lbsapi.QLBSService;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.antitheft.AntitheftCommand;
import com.tencent.tmsecure.module.antitheft.IAntitheftTips;
import com.tencent.tmsecure.module.netsetting.NetSettingManager;
import com.tencent.tmsecure.utils.Log;
import com.tencent.tmsecure.utils.SMSUtil;

/* JADX INFO: renamed from: tms.al */
/* JADX INFO: loaded from: classes.dex */
public final class C1155al extends BaseManager {

    /* JADX INFO: renamed from: a */
    private Context f6835a;

    /* JADX INFO: renamed from: b */
    private IAntitheftTips f6836b;

    /* JADX INFO: renamed from: c */
    private C1158ao f6837c;

    /* JADX INFO: renamed from: d */
    private QLBSService f6838d;

    /* JADX INFO: renamed from: b */
    private boolean m2925b() {
        String string = Settings.Secure.getString(this.f6835a.getContentResolver(), "location_providers_allowed");
        if (string != null && string.contains("gps")) {
            return true;
        }
        Intent intent = new Intent();
        intent.setClassName("com.android.settings", "com.android.settings.widget.SettingsAppWidgetProvider");
        intent.addCategory("android.intent.category.ALTERNATIVE");
        intent.setData(Uri.parse("custom:3"));
        try {
            PendingIntent.getBroadcast(this.f6835a, 0, intent, 0).send();
            return true;
        } catch (PendingIntent.CanceledException e) {
            Log.m2636i("AntitheftManagerImpl", e.getMessage());
            return false;
        }
    }

    /* JADX INFO: renamed from: c */
    static /* synthetic */ void m2926c(C1155al c1155al) {
        c1155al.f6838d.release();
        c1155al.f6838d = null;
    }

    /* JADX INFO: renamed from: a */
    public final C1158ao m2928a() {
        return this.f6837c;
    }

    /* JADX WARN: Code duplicated, block: B:51:0x0163  */
    /* JADX INFO: renamed from: a */
    public final boolean m2929a(IAntitheftTips iAntitheftTips, String str, String str2) {
        byte b;
        byte b2 = 3;
        if (iAntitheftTips == null || str == null || str2 == null || this.f6837c.m2932a(true) == null || this.f6837c.m2931a() == null) {
            return false;
        }
        this.f6836b = iAntitheftTips;
        StringBuilder sb = new StringBuilder(str2);
        int iIndexOf = sb.indexOf("#", 1);
        if (iIndexOf > 0) {
            String strSubstring = sb.substring(0, iIndexOf + 1);
            if (strSubstring.equalsIgnoreCase(AntitheftCommand.CMD_DELETE_DATA)) {
                sb.delete(0, AntitheftCommand.CMD_DELETE_DATA.length());
                b = 0;
            } else if (strSubstring.equalsIgnoreCase(AntitheftCommand.CMD_GET_LOCATE)) {
                sb.delete(0, AntitheftCommand.CMD_GET_LOCATE.length());
                b = 2;
            } else if (strSubstring.equalsIgnoreCase(AntitheftCommand.CMD_LOCK_PHONE)) {
                sb.delete(0, AntitheftCommand.CMD_LOCK_PHONE.length());
                b = 1;
            } else if (strSubstring.equalsIgnoreCase(AntitheftCommand.CMD_FIND_PASSWORD)) {
                sb.delete(0, AntitheftCommand.CMD_FIND_PASSWORD.length());
                b = 3;
            } else {
                b = -1;
            }
        } else {
            b = -1;
        }
        if (b == -1) {
            b2 = -1;
        } else if (b == 3) {
            String strM2931a = this.f6837c.m2931a();
            if (strM2931a == null || !sb.toString().equals(strM2931a)) {
                b2 = 5;
            }
        } else {
            b2 = (sb.toString().equals(this.f6837c.m2932a(true)) || sb.toString().equals(this.f6837c.m2932a(false))) ? b : (byte) 4;
        }
        if (b2 == -1) {
            return false;
        }
        switch (b2) {
            case 0:
                SMSUtil.sendSMS(str, this.f6836b.tips4DeletingData(), this.f6835a);
                new Thread(new RunnableC1251e(this, str)).start();
                break;
            case 1:
                Intent lockPhoneIntent = this.f6836b.getLockPhoneIntent();
                lockPhoneIntent.setFlags(lockPhoneIntent.getFlags() | 268435456);
                this.f6835a.startActivity(lockPhoneIntent);
                SMSUtil.sendSMS(str, this.f6836b.tips4LockPhoneSuccess(), this.f6835a);
                break;
            case 2:
                SMSUtil.sendSMS(str, this.f6836b.tips4Locating(), this.f6835a);
                m2925b();
                NetSettingManager netSettingManager = (NetSettingManager) ManagerCreator.getManager(NetSettingManager.class);
                if (!netSettingManager.getMobileDataConnectivity()) {
                    netSettingManager.setMobileDataConnectivity(true);
                }
                this.f6838d = new QLBSService(this.f6835a, new C1323i(this, str), "B1_msecure_android", "C7tLv_Yaf", "msecure_sdk_1.1");
                this.f6838d.setGpsEnabled(true);
                this.f6838d.startLocation(30);
                break;
            case 3:
                SMSUtil.sendSMS(str, this.f6836b.tips4GetPasswordSuccess(), this.f6835a);
                break;
            case 4:
                SMSUtil.sendSMS(str, this.f6836b.tips4PasswordError(), this.f6835a);
                break;
            case 5:
                SMSUtil.sendSMS(str, this.f6836b.tips4GetPasswordFailed(), this.f6835a);
                break;
        }
        return true;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final int getSingletonType() {
        return 1;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6835a = context;
        this.f6837c = new C1158ao();
    }
}
