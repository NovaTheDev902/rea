package com.lenovo.safecenter.lenovoAntiSpam.utils;

import android.content.Context;
import android.util.Log;
import com.lenovo.safecenter.sdksys.DemoAresEngineFactor;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.aresengine.AresEngineManager;
import com.tencent.tmsecure.module.aresengine.IIntelligentSmsChecker;
import com.tencent.tmsecure.module.aresengine.SmsEntity;
import com.tencent.tmsecure.module.update.UpdateConfig;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import org.apache.commons.httpclient.cookie.CookieSpec;

/* JADX INFO: loaded from: classes.dex */
public class SmsCheckUtils {
    public static final int CHECK_ERROR = 0;
    public static final int CHECK_GOOD = 1;
    public static final int CHECK_SPAM = 3;
    public static final int CHECK_UNSURE = 2;

    public static void init(Context context) throws Throwable {
        InputStream is = null;
        FileOutputStream fos = null;
        try {
            try {
                is = context.getAssets().open(UpdateConfig.SMS_CHECKER_NAME);
                String rulePath = context.getFilesDir().getAbsolutePath() + CookieSpec.PATH_DELIM + UpdateConfig.SMS_CHECKER_NAME;
                File file = new File(rulePath);
                if (file.exists()) {
                    file.delete();
                }
                file.createNewFile();
                FileOutputStream fos2 = new FileOutputStream(file);
                try {
                    byte[] buf = new byte[1024];
                    while (true) {
                        int len = is.read(buf);
                        if (len == -1) {
                            break;
                        } else {
                            fos2.write(buf, 0, len);
                        }
                    }
                    if (is != null) {
                        try {
                            is.close();
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                    }
                    try {
                        fos2.close();
                    } catch (IOException e2) {
                        e2.printStackTrace();
                    }
                } catch (IOException e3) {
                    e = e3;
                    fos = fos2;
                    e.printStackTrace();
                    if (is != null) {
                        try {
                            is.close();
                        } catch (IOException e4) {
                            e4.printStackTrace();
                        }
                    }
                    if (fos != null) {
                        try {
                            fos.close();
                        } catch (IOException e5) {
                            e5.printStackTrace();
                        }
                    }
                } catch (Throwable th) {
                    th = th;
                    fos = fos2;
                    if (is != null) {
                        try {
                            is.close();
                        } catch (IOException e6) {
                            e6.printStackTrace();
                        }
                    }
                    if (fos != null) {
                        try {
                            fos.close();
                        } catch (IOException e7) {
                            e7.printStackTrace();
                        }
                    }
                    throw th;
                }
            } catch (Throwable th2) {
                th = th2;
            }
        } catch (IOException e8) {
            e = e8;
        }
    }

    public static boolean checkSmsAction(Context context, String number, String smsContent) {
        AresEngineManager mAresEnginManager = (AresEngineManager) ManagerCreator.getManager(AresEngineManager.class);
        mAresEnginManager.setAresEngineFactor(new DemoAresEngineFactor(context));
        SmsEntity sms = new SmsEntity();
        sms.name = "";
        sms.phonenum = number;
        sms.body = smsContent;
        IIntelligentSmsChecker smschecker = mAresEnginManager.getIntelligentSmsChecker();
        IIntelligentSmsChecker.CheckResult checkresult = smschecker.check(sms);
        Log.i("demo", "smschecktype=: " + checkresult.mContentType + " , " + checkresult.mSuggestion);
        return checkresult.mSuggestion == 3 || checkresult.mSuggestion == 2;
    }

    public static int ChargeChecker(Context context, String number, String smsContent) {
        return 1;
    }

    public static String getSysVersion(Context context) {
        return "";
    }

    public static String getFiletime(Context context) {
        String rulePath = context.getFilesDir().getAbsolutePath() + CookieSpec.PATH_DELIM + UpdateConfig.SMS_CHECKER_NAME;
        File file = new File(rulePath);
        long time = file.lastModified();
        return String.valueOf(time);
    }
}
