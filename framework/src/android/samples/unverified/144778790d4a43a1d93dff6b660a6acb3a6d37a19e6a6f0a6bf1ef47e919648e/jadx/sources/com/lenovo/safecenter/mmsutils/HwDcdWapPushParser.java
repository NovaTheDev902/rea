package com.lenovo.safecenter.mmsutils;

import android.util.Log;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.util.Hashtable;
import org.xmlpull.v1.XmlPullParserException;

/* JADX INFO: loaded from: classes.dex */
public class HwDcdWapPushParser {
    public static final String ERR_TAG = "HwDcdWapPushParser.java";

    /* JADX INFO: renamed from: d */
    private static final String[] f4299d = {"si", "indication", "info", "item"};

    /* JADX INFO: renamed from: e */
    private static final String[] f4300e = {"action=signal-none", "action=signal-low", "action=signal-medium", "action=signal-high", "action=signal-delete", "created", "href", "href=http://", "href=http://www.", "href=https://", "href=https://www.", "si-expires", "si-id", "class"};

    /* JADX INFO: renamed from: f */
    private static final String[] f4301f = {"sl"};

    /* JADX INFO: renamed from: g */
    private static final String[] f4302g = {"action=execute-low", "action=execute-high", "action=cache", "href", "href=http://", "href=http://www.", "href=https://", "href=https://www."};

    /* JADX INFO: renamed from: h */
    private static final String[] f4303h = {".com/", ".edu/", ".net/", ".org/"};

    /* JADX INFO: renamed from: i */
    private static Hashtable<String, Integer> f4304i = new Hashtable<>(5);

    /* JADX INFO: renamed from: j */
    private static Hashtable<String, Integer> f4305j;

    /* JADX INFO: renamed from: a */
    private ByteArrayInputStream f4306a;

    /* JADX INFO: renamed from: b */
    private WbxmlParser f4307b = null;

    /* JADX INFO: renamed from: c */
    private HwDcdWapPushMsg f4308c = null;

    public HwDcdWapPushParser(byte[] pushDataStream) {
        this.f4306a = null;
        this.f4306a = new ByteArrayInputStream(pushDataStream);
    }

    public HwDcdWapPushMsg parse(int type) {
        if (this.f4306a == null) {
            Log.e("WapPushParser", "mWapPushDataStream is not set!");
            return null;
        }
        this.f4308c = new HwDcdWapPushMsg(type);
        if (HwDcdWapPushMsg.WAP_PUSH_TYPE_SI == type) {
            WbxmlParser wbxmlParser = new WbxmlParser();
            wbxmlParser.setTagTable(0, f4299d);
            wbxmlParser.setAttrStartTable(0, f4300e);
            wbxmlParser.setAttrValueTable(0, f4303h);
            this.f4307b = wbxmlParser;
        } else if (HwDcdWapPushMsg.WAP_PUSH_TYPE_SL == type) {
            WbxmlParser wbxmlParser2 = new WbxmlParser();
            wbxmlParser2.setTagTable(0, f4301f);
            wbxmlParser2.setAttrStartTable(0, f4302g);
            wbxmlParser2.setAttrValueTable(0, f4303h);
            this.f4307b = wbxmlParser2;
        } else {
            Log.e("WapPushParser", "wap push unknown type=" + type);
            return null;
        }
        try {
            this.f4307b.setInput(this.f4306a, null);
            Log.i("WapPushParser", "Document charset : " + this.f4307b.getInputEncoding());
            int eventType = this.f4307b.getEventType();
            while (eventType != 1) {
                switch (eventType) {
                    case 0:
                        Log.i("WapPushParser", "Start document");
                        break;
                    case 1:
                        Log.i("WapPushParser", "End document");
                        break;
                    case 2:
                        Log.i("WapPushParser", "Start tag = " + this.f4307b.getName());
                        m1768a(this.f4307b.getName());
                        break;
                    case 3:
                        Log.i("WapPushParser", "End tag = " + this.f4307b.getName());
                        break;
                    case 4:
                        Log.i("WapPushParser", "Text = " + this.f4307b.getText());
                        if (HwDcdWapPushMsg.WAP_PUSH_TYPE_SI == type) {
                            this.f4308c.setAttributeValue(HwDcdWapPushMsg.WAP_PUSH_PROJECTION_SI_TEXT, this.f4307b.getText());
                        }
                        break;
                    default:
                        Log.i("WapPushParser", "unknown event type =  " + eventType);
                        break;
                }
                eventType = this.f4307b.next();
            }
            return this.f4308c;
        } catch (IOException e) {
            Log.e("WapPushParser", e.toString());
            return null;
        } catch (XmlPullParserException e2) {
            Log.e("WapPushParser", e2.toString());
            return null;
        }
    }

    /* JADX INFO: renamed from: a */
    private void m1768a(String tagName) {
        int attrCount = this.f4307b.getAttributeCount();
        if (tagName.equalsIgnoreCase(f4301f[0]) || tagName.equalsIgnoreCase(f4299d[0]) || tagName.equalsIgnoreCase(f4299d[1])) {
            for (int i = 0; i < attrCount; i++) {
                String attrValue = this.f4307b.getAttributeValue(i);
                String attrName = this.f4307b.getAttributeName(i);
                Log.i("WapPushParser", "attrName = " + attrName + ", attrValue =" + attrValue);
                if (f4304i.containsKey(attrName)) {
                    int attr = f4304i.get(attrName).intValue();
                    this.f4308c.setAttributeValue(attr, attrValue);
                }
            }
            return;
        }
        Log.e("WapPushParser", "Unknown tag = " + tagName);
    }

    static {
        f4304i.put("action", Integer.valueOf(HwDcdWapPushMsg.WAP_PUSH_PROJECTION_PRIOR));
        f4304i.put("href", Integer.valueOf(HwDcdWapPushMsg.WAP_PUSH_PROJECTION_HREF));
        f4304i.put("si-expires", Integer.valueOf(HwDcdWapPushMsg.WAP_PUSH_PROJECTION_SI_EXPIRED));
        f4304i.put("created", Integer.valueOf(HwDcdWapPushMsg.WAP_PUSH_PROJECTION_SI_CREATED));
        f4304i.put("si-id", Integer.valueOf(HwDcdWapPushMsg.WAP_PUSH_PROJECTION_SI_ID));
        f4305j = new Hashtable<>(7);
        f4305j.put("signal-none", Integer.valueOf(HwDcdWapPushMsg.WAP_PUSH_PRIO_NONE));
        f4305j.put("signal-low", Integer.valueOf(HwDcdWapPushMsg.WAP_PUSH_PRIO_LOW));
        f4305j.put("signal-medium", Integer.valueOf(HwDcdWapPushMsg.WAP_PUSH_PRIO_MEDIUM));
        f4305j.put("signal-high", Integer.valueOf(HwDcdWapPushMsg.WAP_PUSH_PRIO_HIGH));
        f4305j.put("signal-delete", Integer.valueOf(HwDcdWapPushMsg.WAP_PUSH_PRIO_DELETE));
        f4305j.put("execute-low", Integer.valueOf(HwDcdWapPushMsg.WAP_PUSH_PRIO_LOW));
        f4305j.put("execute-high", Integer.valueOf(HwDcdWapPushMsg.WAP_PUSH_PRIO_HIGH));
        f4305j.put("cache", Integer.valueOf(HwDcdWapPushMsg.WAP_PUSH_PRIO_CACHE));
    }
}
