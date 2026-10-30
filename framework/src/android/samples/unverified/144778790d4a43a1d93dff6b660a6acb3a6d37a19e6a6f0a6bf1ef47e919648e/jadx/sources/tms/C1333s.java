package tms;

import android.text.format.DateUtils;
import java.util.ArrayList;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: renamed from: tms.s */
/* JADX INFO: loaded from: classes.dex */
public class C1333s {
    /* JADX INFO: renamed from: a */
    public static int m3553a(List<Date> list, Date date) {
        int i = 0;
        Iterator<Date> it = list.iterator();
        while (true) {
            int i2 = i;
            if (!it.hasNext()) {
                return i2;
            }
            i = date.after(it.next()) ? i2 + 1 : i2;
        }
    }

    /* JADX INFO: renamed from: a */
    public static long m3554a(Date date) {
        GregorianCalendar gregorianCalendar = new GregorianCalendar();
        gregorianCalendar.setTime(date);
        return m3555a(gregorianCalendar).getTime().getTime();
    }

    /* JADX INFO: renamed from: a */
    public static GregorianCalendar m3555a(GregorianCalendar gregorianCalendar) {
        gregorianCalendar.clear(11);
        gregorianCalendar.clear(10);
        gregorianCalendar.clear(12);
        gregorianCalendar.clear(13);
        gregorianCalendar.clear(14);
        return gregorianCalendar;
    }

    /* JADX INFO: renamed from: a */
    public static GregorianCalendar m3556a(GregorianCalendar gregorianCalendar, int i) {
        GregorianCalendar gregorianCalendar2 = new GregorianCalendar();
        gregorianCalendar2.setTimeInMillis(gregorianCalendar.getTimeInMillis());
        if (gregorianCalendar2.get(5) != i) {
            if (gregorianCalendar2.get(5) > i) {
                gregorianCalendar2.set(5, i);
            } else {
                gregorianCalendar2.set(5, 1);
                gregorianCalendar2.add(2, -1);
                gregorianCalendar2 = m3563c(gregorianCalendar2, i);
            }
        }
        return m3555a(gregorianCalendar2);
    }

    /* JADX INFO: renamed from: a */
    public static List<GregorianCalendar> m3557a(int i) {
        GregorianCalendar gregorianCalendarM3556a = m3556a(new GregorianCalendar(), i);
        GregorianCalendar gregorianCalendarM3560b = m3560b(new GregorianCalendar(), i);
        GregorianCalendar gregorianCalendar = new GregorianCalendar();
        ArrayList arrayList = new ArrayList(35);
        while (gregorianCalendar.before(gregorianCalendarM3560b)) {
            gregorianCalendar = (GregorianCalendar) gregorianCalendarM3556a.clone();
            arrayList.add(gregorianCalendar);
            gregorianCalendarM3556a.add(5, 1);
        }
        return arrayList;
    }

    /* JADX INFO: renamed from: a */
    public static boolean m3558a(Date date, Date date2) {
        GregorianCalendar gregorianCalendar = new GregorianCalendar();
        GregorianCalendar gregorianCalendar2 = new GregorianCalendar();
        gregorianCalendar.setTime(date);
        GregorianCalendar gregorianCalendarM3555a = m3555a(gregorianCalendar);
        gregorianCalendar2.setTime(date2);
        return gregorianCalendarM3555a.getTimeInMillis() == m3555a(gregorianCalendar2).getTimeInMillis();
    }

    /* JADX INFO: renamed from: b */
    public static long m3559b(Date date) {
        GregorianCalendar gregorianCalendar = new GregorianCalendar();
        gregorianCalendar.setTime(date);
        GregorianCalendar gregorianCalendarM3555a = m3555a(gregorianCalendar);
        gregorianCalendarM3555a.set(11, 24);
        return gregorianCalendarM3555a.getTime().getTime();
    }

    /* JADX INFO: renamed from: b */
    public static GregorianCalendar m3560b(GregorianCalendar gregorianCalendar, int i) {
        GregorianCalendar gregorianCalendarM3563c;
        GregorianCalendar gregorianCalendar2 = new GregorianCalendar();
        gregorianCalendar2.setTimeInMillis(gregorianCalendar.getTimeInMillis());
        if (gregorianCalendar2.get(5) == i || gregorianCalendar2.get(5) >= i) {
            gregorianCalendar2.set(5, 1);
            gregorianCalendar2.add(2, 1);
            gregorianCalendarM3563c = m3563c(gregorianCalendar2, i);
        } else {
            gregorianCalendarM3563c = m3563c(gregorianCalendar2, i);
        }
        return m3555a(gregorianCalendarM3563c);
    }

    /* JADX INFO: renamed from: b */
    public static boolean m3561b(List<Date> list, Date date) {
        long time = list.get(0).getTime();
        long time2 = list.get(list.size() - 1).getTime();
        long time3 = date.getTime();
        return time <= time3 && time3 <= time2;
    }

    /* JADX INFO: renamed from: c */
    public static int m3562c(Date date) {
        GregorianCalendar gregorianCalendar = new GregorianCalendar();
        gregorianCalendar.setTime(date);
        return gregorianCalendar.getActualMaximum(5);
    }

    /* JADX INFO: renamed from: c */
    private static GregorianCalendar m3563c(GregorianCalendar gregorianCalendar, int i) {
        int actualMaximum = gregorianCalendar.getActualMaximum(5);
        if (actualMaximum >= i) {
            gregorianCalendar.set(5, i);
        } else {
            gregorianCalendar.set(5, actualMaximum);
        }
        return gregorianCalendar;
    }

    /* JADX INFO: renamed from: d */
    public static String m3564d(Date date) {
        return DateUtils.getRelativeTimeSpanString(date.getTime(), System.currentTimeMillis(), 60000L, 262144).toString();
    }
}
