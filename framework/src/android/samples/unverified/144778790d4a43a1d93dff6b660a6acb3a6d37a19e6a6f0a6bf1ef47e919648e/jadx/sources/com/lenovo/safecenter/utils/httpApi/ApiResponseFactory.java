package com.lenovo.safecenter.utils.httpApi;

import android.content.Context;
import android.content.SharedPreferences;
import android.preference.PreferenceManager;
import android.util.Log;
import android.util.Xml;
import com.lenovo.lps.sus.p003a.p004a.p005a.InterfaceC0079b;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.adapter.DaoImpl;
import com.lenovo.safecenter.adapter.DbAdapter;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.notificationintercept.InterceptUtils;
import com.lenovo.safecenter.notificationintercept.UrlOptionUtils;
import com.lenovo.safecenter.utils.Const;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import org.apache.http.HttpResponse;
import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserException;

/* JADX INFO: loaded from: classes.dex */
public class ApiResponseFactory {
    public static Object getResponse(Context context, int action, HttpResponse response) {
        try {
            InputStream in = response.getEntity().getContent();
            switch (action) {
                case 0:
                    return m2453b(in);
                case 1:
                    return in;
                case 2:
                    return m2452a(in);
                case 3:
                    XmlPullParser xmlPullParserNewPullParser = Xml.newPullParser();
                    xmlPullParserNewPullParser.setInput(in, "utf-8");
                    int eventType = xmlPullParserNewPullParser.getEventType();
                    Log.i("yincc", " eventType == " + eventType);
                    boolean z = false;
                    ArrayList arrayList = new ArrayList();
                    ArrayList result = new ArrayList();
                    SharedPreferences defaultSharedPreferences = PreferenceManager.getDefaultSharedPreferences(context);
                    SharedPreferences.Editor editorEdit = defaultSharedPreferences.edit();
                    while (eventType != 1) {
                        switch (eventType) {
                            case 2:
                                if ("lastinlist".equals(xmlPullParserNewPullParser.getName())) {
                                    z = true;
                                }
                                if ("expiredlist".equals(xmlPullParserNewPullParser.getName())) {
                                    z = false;
                                }
                                if ("lastintag".equals(xmlPullParserNewPullParser.getName())) {
                                    editorEdit.putLong(Const.KEY_URL_BLACK_LAST_FLAG, Long.parseLong(xmlPullParserNewPullParser.nextText()));
                                    editorEdit.commit();
                                }
                                if ("expiredtag".equals(xmlPullParserNewPullParser.getName())) {
                                    editorEdit.putLong(Const.KEY_URL_BLACK_EXP_FLAG, Long.parseLong(xmlPullParserNewPullParser.nextText()));
                                    editorEdit.commit();
                                }
                                if ("blackurls".equals(xmlPullParserNewPullParser.getName())) {
                                    String strNextText = xmlPullParserNewPullParser.nextText();
                                    if (!"".equals(strNextText)) {
                                        String[] strArrSplit = strNextText.split(",");
                                        if (z) {
                                            for (int i = 0; i < strArrSplit.length; i++) {
                                                if (!"".equals(strArrSplit[i])) {
                                                    arrayList.add(strArrSplit[i]);
                                                }
                                            }
                                        } else {
                                            for (int i2 = 0; i2 < strArrSplit.length; i2++) {
                                                if (!"".equals(strArrSplit[i2])) {
                                                    result.add(strArrSplit[i2]);
                                                }
                                            }
                                        }
                                    }
                                }
                                break;
                        }
                        eventType = xmlPullParserNewPullParser.next();
                    }
                    Log.i("yincc", " analsys white.size == " + result.size() + " black.size == " + arrayList.size());
                    UrlOptionUtils.updateNativeUrl(result, arrayList, context);
                    if (defaultSharedPreferences.getBoolean(InterceptUtils.AD_SWITCH, false)) {
                        UrlOptionUtils.updateHostsUrl(context);
                    }
                    return result;
                case 4:
                    return m2451a(in, context);
                default:
                    return null;
            }
        } catch (Exception e) {
            Log.e("yincc", " getResponse Error === " + e);
            e.printStackTrace();
            return null;
        }
    }

    /* JADX INFO: renamed from: a */
    private static Object m2451a(InputStream in, Context context) throws XmlPullParserException, IOException {
        DaoImpl di = new DaoImpl(new DbAdapter(context));
        XmlPullParser parser = Xml.newPullParser();
        parser.setInput(in, "utf-8");
        int eventType = parser.getEventType();
        Log.i("yincc", " eventType == " + eventType);
        boolean mInsert = false;
        List<String> blackList = new ArrayList<>();
        List<String> whiteList = new ArrayList<>();
        SharedPreferences dfprefs = PreferenceManager.getDefaultSharedPreferences(context);
        SharedPreferences.Editor edit = dfprefs.edit();
        while (eventType != 1) {
            switch (eventType) {
                case 2:
                    if ("lastinlist".equals(parser.getName())) {
                        mInsert = true;
                    }
                    if ("expiredlist".equals(parser.getName())) {
                        mInsert = false;
                    }
                    if ("lastintag".equals(parser.getName())) {
                        edit.putString(Const.KEY_URL_SAFEPAY_LAST_FLAG, parser.nextText());
                        edit.commit();
                    }
                    if ("expiredtag".equals(parser.getName())) {
                        edit.putString(Const.KEY_URL_SAFEPAY_EXP_FLAG, parser.nextText());
                        edit.commit();
                    }
                    if ("oneapk".equals(parser.getName())) {
                        String appname = null;
                        String packagename = null;
                        String certmd5 = null;
                        while (parser.nextTag() != 3) {
                            if (AppDatabase.DB_APP.equals(parser.getName())) {
                                appname = parser.nextText();
                            }
                            if (AppDatabase.APP_PKG_NAME.equals(parser.getName())) {
                                packagename = parser.nextText();
                            }
                            if ("certmd5".equals(parser.getName())) {
                                certmd5 = parser.nextText();
                            }
                        }
                        if (mInsert) {
                            di.insterForNet(appname, packagename, certmd5);
                        } else {
                            di.deleByPackageNameForSafeApp(packagename);
                        }
                    }
                    break;
            }
            eventType = parser.next();
        }
        Log.i("yincc", " analsys white.size == " + whiteList.size() + " black.size == " + blackList.size());
        UrlOptionUtils.updateNativeUrl(whiteList, blackList, context);
        if (dfprefs.getBoolean(InterceptUtils.AD_SWITCH, false)) {
            UrlOptionUtils.updateHostsUrl(context);
        }
        return whiteList;
    }

    /* JADX INFO: renamed from: a */
    private static String m2452a(InputStream in) {
        String result = null;
        if (in == null) {
            return null;
        }
        byte[] buffer = new byte[1024];
        ByteArrayOutputStream ostream = new ByteArrayOutputStream();
        while (true) {
            try {
                int len = in.read(buffer);
                if (len == -1) {
                    break;
                }
                ostream.write(buffer, 0, len);
            } catch (IOException e) {
                Log.i("wu0wu", "parseSafeBrowserHomepageFlag e=" + e.toString());
                e.printStackTrace();
            }
        }
        result = ostream.toString();
        ostream.close();
        in.close();
        return result;
    }

    /* JADX INFO: renamed from: b */
    private static HashMap<String, String> m2453b(InputStream in) throws XmlPullParserException, IOException {
        HashMap<String, String> result = new HashMap<>();
        try {
            XmlPullParser parser = Xml.newPullParser();
            parser.setInput(in, InterfaceC0079b.f1213a);
            int tag = 0;
            for (int event = parser.getEventType(); event != 1; event = parser.next()) {
                switch (event) {
                    case 2:
                        if ("lastinimages".equals(parser.getName())) {
                            tag = 1;
                        }
                        if ("expiredimages".equals(parser.getName())) {
                            tag = 2;
                        }
                        if (QueryPermissions.f1958ID.equals(parser.getName())) {
                            if (tag == 1) {
                                result.put(QueryPermissions.f1958ID, parser.nextText());
                            } else if (tag == 2) {
                                result.put("expiredId", parser.nextText());
                            }
                        }
                        if ("imageurl".equals(parser.getName())) {
                            String imageurl = replaceAMP(parser.nextText());
                            result.put("imageurl", imageurl);
                            Log.i("wu0wu", "<<<parseHolidayImgSyncResult imageurl=" + imageurl);
                        }
                        if ("starttime".equals(parser.getName())) {
                            result.put("starttime", parser.nextText());
                        }
                        if ("endtime".equals(parser.getName())) {
                            result.put("endtime", parser.nextText());
                        }
                        if ("version".equals(parser.getName())) {
                            result.put("version", parser.nextText());
                        }
                        break;
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return result;
    }

    public static String replaceAMP(String source) {
        if (source.contains("amp;")) {
            return source.replace("amp;", "");
        }
        return source;
    }
}
