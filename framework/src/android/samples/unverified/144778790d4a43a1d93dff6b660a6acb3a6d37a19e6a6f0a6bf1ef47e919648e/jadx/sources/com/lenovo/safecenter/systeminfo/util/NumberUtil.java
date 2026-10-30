package com.lenovo.safecenter.systeminfo.util;

import java.text.DecimalFormat;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/* JADX INFO: loaded from: classes.dex */
public class NumberUtil {
    public static long pickupNumber(String stringContainNumber) {
        Pattern pattern = Pattern.compile("\\d+");
        Matcher matcher = pattern.matcher(stringContainNumber);
        String numStr = "-1";
        if (matcher.find()) {
            numStr = matcher.group(0);
        }
        return Long.parseLong(numStr);
    }

    public static String format(double value, String pattern) {
        DecimalFormat df = new DecimalFormat(pattern);
        return df.format(value);
    }
}
