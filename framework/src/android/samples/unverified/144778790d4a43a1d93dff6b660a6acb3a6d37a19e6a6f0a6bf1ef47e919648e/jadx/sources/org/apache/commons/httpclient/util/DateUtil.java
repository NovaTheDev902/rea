package org.apache.commons.httpclient.util;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Collection;
import java.util.Date;
import java.util.Locale;
import java.util.TimeZone;

/* JADX INFO: loaded from: classes.dex */
public class DateUtil {
    public static final String PATTERN_ASCTIME = "EEE MMM d HH:mm:ss yyyy";
    public static final String PATTERN_RFC1036 = "EEEE, dd-MMM-yy HH:mm:ss zzz";
    public static final String PATTERN_RFC1123 = "EEE, dd MMM yyyy HH:mm:ss zzz";

    /* JADX INFO: renamed from: a */
    private static final Collection f6761a = Arrays.asList("EEE MMM d HH:mm:ss yyyy", "EEEE, dd-MMM-yy HH:mm:ss zzz", "EEE, dd MMM yyyy HH:mm:ss zzz");

    /* JADX INFO: renamed from: b */
    private static final Date f6762b;

    /* JADX INFO: renamed from: c */
    private static final TimeZone f6763c;

    static {
        Calendar calendar = Calendar.getInstance();
        calendar.set(2000, 0, 1, 0, 0);
        f6762b = calendar.getTime();
        f6763c = TimeZone.getTimeZone("GMT");
    }

    public static Date parseDate(String dateValue) throws DateParseException {
        return parseDate(dateValue, null, null);
    }

    public static Date parseDate(String dateValue, Collection dateFormats) throws DateParseException {
        return parseDate(dateValue, dateFormats, null);
    }

    public static Date parseDate(String dateValue, Collection dateFormats, Date startDate) throws DateParseException {
        if (dateValue == null) {
            throw new IllegalArgumentException("dateValue is null");
        }
        if (dateFormats == null) {
            dateFormats = f6761a;
        }
        if (startDate == null) {
            startDate = f6762b;
        }
        if (dateValue.length() > 1 && dateValue.startsWith("'") && dateValue.endsWith("'")) {
            dateValue = dateValue.substring(1, dateValue.length() - 1);
        }
        SimpleDateFormat dateParser = null;
        for (String format : dateFormats) {
            if (dateParser == null) {
                dateParser = new SimpleDateFormat(format, Locale.US);
                dateParser.setTimeZone(TimeZone.getTimeZone("GMT"));
                dateParser.set2DigitYearStart(startDate);
            } else {
                dateParser.applyPattern(format);
            }
            try {
                continue;
                return dateParser.parse(dateValue);
            } catch (ParseException e) {
            }
        }
        throw new DateParseException(new StringBuffer().append("Unable to parse the date ").append(dateValue).toString());
    }

    public static String formatDate(Date date) {
        return formatDate(date, "EEE, dd MMM yyyy HH:mm:ss zzz");
    }

    public static String formatDate(Date date, String pattern) {
        if (date == null) {
            throw new IllegalArgumentException("date is null");
        }
        if (pattern == null) {
            throw new IllegalArgumentException("pattern is null");
        }
        SimpleDateFormat formatter = new SimpleDateFormat(pattern, Locale.US);
        formatter.setTimeZone(f6763c);
        return formatter.format(date);
    }

    private DateUtil() {
    }
}
