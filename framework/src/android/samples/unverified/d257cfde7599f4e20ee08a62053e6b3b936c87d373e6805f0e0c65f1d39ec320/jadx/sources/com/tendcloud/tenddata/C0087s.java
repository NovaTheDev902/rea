package com.tendcloud.tenddata;

import android.util.Log;
import java.util.Date;

/* JADX INFO: renamed from: com.tendcloud.tenddata.s */
/* JADX INFO: loaded from: classes.dex */
public class C0087s {
    /* JADX INFO: renamed from: a */
    static void m156a(String... strArr) {
        StringBuilder sb = new StringBuilder();
        sb.append("+++++++++++++++++++++++ ").append(new Date());
        for (String str : strArr) {
            sb.append("\t");
            sb.append(str);
        }
        sb.append("\r\n---------------------- end");
        Log.d("TalkingData", sb.toString());
    }
}
