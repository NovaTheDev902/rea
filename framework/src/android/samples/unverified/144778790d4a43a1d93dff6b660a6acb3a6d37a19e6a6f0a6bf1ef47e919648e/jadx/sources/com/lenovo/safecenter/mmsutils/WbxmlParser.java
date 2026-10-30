package com.lenovo.safecenter.mmsutils;

import com.lenovo.lps.sus.p003a.p004a.p005a.InterfaceC0079b;
import com.lenovo.lps.sus.p008c.C0092c;
import com.tencent.tmsecure.module.permission.IDummyService;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.Reader;
import java.io.UnsupportedEncodingException;
import java.util.Hashtable;
import java.util.Vector;
import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserException;

/* JADX INFO: loaded from: classes.dex */
public class WbxmlParser implements XmlPullParser {
    public static final String ERR_TAG = "WbxmlParser.java";
    public static final int WAP_EXTENSION = 64;

    /* JADX INFO: renamed from: A */
    private int f4341A;

    /* JADX INFO: renamed from: B */
    private boolean f4342B;

    /* JADX INFO: renamed from: C */
    private boolean f4343C;

    /* JADX INFO: renamed from: D */
    private String f4344D;

    /* JADX INFO: renamed from: a */
    private InputStream f4345a;

    /* JADX INFO: renamed from: e */
    private String[] f4349e;

    /* JADX INFO: renamed from: f */
    private String[] f4350f;

    /* JADX INFO: renamed from: g */
    private String[] f4351g;

    /* JADX INFO: renamed from: h */
    private byte[] f4352h;

    /* JADX INFO: renamed from: j */
    private boolean f4354j;

    /* JADX INFO: renamed from: k */
    private int f4355k;

    /* JADX INFO: renamed from: o */
    private int f4359o;

    /* JADX INFO: renamed from: s */
    private int f4363s;

    /* JADX INFO: renamed from: t */
    private int f4364t;

    /* JADX INFO: renamed from: u */
    private String f4365u;

    /* JADX INFO: renamed from: v */
    private String f4366v;

    /* JADX INFO: renamed from: w */
    private String f4367w;

    /* JADX INFO: renamed from: x */
    private String f4368x;

    /* JADX INFO: renamed from: y */
    private Object f4369y;

    /* JADX INFO: renamed from: z */
    private int f4370z;

    /* JADX INFO: renamed from: b */
    private int f4346b = 0;

    /* JADX INFO: renamed from: c */
    private int f4347c = 1;

    /* JADX INFO: renamed from: d */
    private int f4348d = 2;

    /* JADX INFO: renamed from: i */
    private Hashtable f4353i = null;

    /* JADX INFO: renamed from: l */
    private String[] f4356l = new String[16];

    /* JADX INFO: renamed from: m */
    private String[] f4357m = new String[8];

    /* JADX INFO: renamed from: n */
    private int[] f4358n = new int[4];

    /* JADX INFO: renamed from: p */
    private String[] f4360p = new String[16];

    /* JADX INFO: renamed from: q */
    private int f4361q = -2;

    /* JADX INFO: renamed from: r */
    private Vector f4362r = new Vector();

    @Override // org.xmlpull.v1.XmlPullParser
    public boolean getFeature(String feature) {
        if ("http://xmlpull.org/v1/doc/features.html#process-namespaces".equals(feature)) {
            return this.f4354j;
        }
        return false;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public String getInputEncoding() {
        return this.f4344D;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public void defineEntityReplacementText(String entity, String value) throws XmlPullParserException {
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public Object getProperty(String property) {
        return null;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public int getNamespaceCount(int depth) {
        if (depth > this.f4355k) {
            throw new IndexOutOfBoundsException();
        }
        return this.f4358n[depth];
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public String getNamespacePrefix(int pos) {
        return this.f4357m[pos << 1];
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public String getNamespaceUri(int pos) {
        return this.f4357m[(pos << 1) + 1];
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public String getNamespace(String prefix) {
        if ("xml".equals(prefix)) {
            return "http://www.w3.org/XML/1998/namespace";
        }
        if ("xmlns".equals(prefix)) {
            return "http://www.w3.org/2000/xmlns/";
        }
        for (int i = (getNamespaceCount(this.f4355k) << 1) - 2; i >= 0; i -= 2) {
            if (prefix == null) {
                if (this.f4357m[i] == null) {
                    return this.f4357m[i + 1];
                }
            } else if (prefix.equals(this.f4357m[i])) {
                return this.f4357m[i + 1];
            }
        }
        return null;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public int getDepth() {
        return this.f4355k;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public String getPositionDescription() {
        StringBuffer buf = new StringBuffer(this.f4341A < TYPES.length ? TYPES[this.f4341A] : "unknown");
        buf.append(' ');
        if (this.f4341A == 2 || this.f4341A == 3) {
            if (this.f4342B) {
                buf.append("(empty) ");
            }
            buf.append('<');
            if (this.f4341A == 3) {
                buf.append('/');
            }
            if (this.f4365u != null) {
                buf.append(C0092c.f1285P + this.f4366v + C0092c.f1286Q + this.f4365u + C0092c.f1283N);
            }
            buf.append(this.f4367w);
            int cnt = this.f4359o << 2;
            for (int i = 0; i < cnt; i += 4) {
                buf.append(' ');
                if (this.f4360p[i + 1] != null) {
                    buf.append(C0092c.f1285P + this.f4360p[i] + C0092c.f1286Q + this.f4360p[i + 1] + C0092c.f1283N);
                }
                buf.append(this.f4360p[i + 2] + "='" + this.f4360p[i + 3] + "'");
            }
            buf.append('>');
        } else if (this.f4341A != 7) {
            if (this.f4341A != 4) {
                buf.append(getText());
            } else if (this.f4343C) {
                buf.append("(whitespace)");
            } else {
                String text = getText();
                if (text.length() > 16) {
                    text = text.substring(0, 16) + "...";
                }
                buf.append(text);
            }
        }
        return buf.toString();
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public int getLineNumber() {
        return -1;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public int getColumnNumber() {
        return -1;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public boolean isWhitespace() throws XmlPullParserException {
        if (this.f4341A != 4 && this.f4341A != 7 && this.f4341A != 5) {
            m1776a("Wrong event type");
        }
        return this.f4343C;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public String getText() {
        return this.f4368x;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public char[] getTextCharacters(int[] poslen) {
        if (this.f4341A >= 4) {
            poslen[0] = 0;
            poslen[1] = this.f4368x.length();
            char[] buf = new char[this.f4368x.length()];
            this.f4368x.getChars(0, this.f4368x.length(), buf, 0);
            return buf;
        }
        poslen[0] = -1;
        poslen[1] = -1;
        return null;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public String getNamespace() {
        return this.f4366v;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public String getName() {
        return this.f4367w;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public String getPrefix() {
        return this.f4365u;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public boolean isEmptyElementTag() throws XmlPullParserException {
        if (this.f4341A != 2) {
            m1776a("Wrong event type");
        }
        return this.f4342B;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public int getAttributeCount() {
        return this.f4359o;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public String getAttributeType(int index) {
        return "CDATA";
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public boolean isAttributeDefault(int index) {
        return false;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public String getAttributeNamespace(int index) {
        if (index >= this.f4359o) {
            throw new IndexOutOfBoundsException();
        }
        return this.f4360p[index << 2];
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public String getAttributeName(int index) {
        if (index >= this.f4359o) {
            throw new IndexOutOfBoundsException();
        }
        return this.f4360p[(index << 2) + 2];
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public String getAttributePrefix(int index) {
        if (index >= this.f4359o) {
            throw new IndexOutOfBoundsException();
        }
        return this.f4360p[(index << 2) + 1];
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public String getAttributeValue(int index) {
        if (index >= this.f4359o) {
            throw new IndexOutOfBoundsException();
        }
        return this.f4360p[(index << 2) + 3];
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public String getAttributeValue(String namespace, String name) {
        for (int i = (this.f4359o << 2) - 4; i >= 0; i -= 4) {
            if (this.f4360p[i + 2].equals(name) && (namespace == null || this.f4360p[i].equals(namespace))) {
                return this.f4360p[i + 3];
            }
        }
        return null;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public int getEventType() throws XmlPullParserException {
        return this.f4341A;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public int next() throws XmlPullParserException, IOException {
        this.f4343C = true;
        int minType = IDummyService.f6148m;
        while (true) {
            String save = this.f4368x;
            m1778b();
            if (this.f4341A < minType) {
                minType = this.f4341A;
            }
            if (minType <= 5) {
                if (minType >= 4) {
                    if (save != null) {
                        if (this.f4368x != null) {
                            save = save + this.f4368x;
                        }
                        this.f4368x = save;
                    }
                    switch (m1780c()) {
                        case 2:
                        case 3:
                        case 4:
                        case Wbxml.LITERAL_C /* 68 */:
                        case 131:
                        case 132:
                        case 196:
                            continue;
                    }
                }
            }
        }
        this.f4341A = minType;
        if (this.f4341A > 4) {
            this.f4341A = 4;
        }
        return this.f4341A;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public int nextToken() throws XmlPullParserException, IOException {
        this.f4343C = true;
        m1778b();
        return this.f4341A;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public int nextTag() throws XmlPullParserException, IOException {
        next();
        if (this.f4341A == 4 && this.f4343C) {
            next();
        }
        if (this.f4341A != 3 && this.f4341A != 2) {
            m1776a("unexpected type");
        }
        return this.f4341A;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public String nextText() throws XmlPullParserException, IOException {
        String result;
        if (this.f4341A != 2) {
            m1776a("precondition: START_TAG");
        }
        next();
        if (this.f4341A == 4) {
            result = getText();
            next();
        } else {
            result = "";
        }
        if (this.f4341A != 3) {
            m1776a("END_TAG expected");
        }
        return result;
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public void require(int type, String namespace, String name) throws XmlPullParserException, IOException {
        if (type != this.f4341A || ((namespace != null && !namespace.equals(getNamespace())) || (name != null && !name.equals(getName())))) {
            m1776a("expected: " + (type == 64 ? "WAP Ext." : TYPES[type] + " {" + namespace + C0092c.f1286Q + name));
        }
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public void setInput(Reader reader) throws XmlPullParserException {
        m1776a("InputStream required");
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public void setInput(InputStream in, String enc) throws XmlPullParserException {
        this.f4345a = in;
        try {
            this.f4363s = m1781d();
            this.f4364t = m1782e();
            if (this.f4364t == 0) {
                m1782e();
            }
            int charset = m1782e();
            if (enc == null) {
                switch (charset) {
                    case 4:
                        this.f4344D = "ISO-8859-1";
                        break;
                    case 106:
                        this.f4344D = InterfaceC0079b.f1213a;
                        break;
                    default:
                        throw new UnsupportedEncodingException("" + charset);
                }
            } else {
                this.f4344D = enc;
            }
            int strTabSize = m1782e();
            this.f4352h = new byte[strTabSize];
            int ok = 0;
            while (ok < strTabSize) {
                int cnt = in.read(this.f4352h, ok, strTabSize - ok);
                if (cnt > 0) {
                    ok += cnt;
                } else {
                    m1775a(0, true);
                    m1775a(0, false);
                }
            }
            m1775a(0, true);
            m1775a(0, false);
        } catch (IOException e) {
            m1776a("Illegal input format");
        }
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public void setFeature(String feature, boolean value) throws XmlPullParserException {
        if ("http://xmlpull.org/v1/doc/features.html#process-namespaces".equals(feature)) {
            this.f4354j = value;
        } else {
            m1776a("unsupported feature: " + feature);
        }
    }

    @Override // org.xmlpull.v1.XmlPullParser
    public void setProperty(String property, Object value) throws XmlPullParserException {
        throw new XmlPullParserException("unsupported property: " + property);
    }

    /* JADX INFO: renamed from: a */
    private final boolean m1777a() throws XmlPullParserException {
        String prefix;
        String attrName;
        boolean any = false;
        int i = 0;
        while (i < (this.f4359o << 2)) {
            String attrName2 = this.f4360p[i + 2];
            int cut = attrName2.indexOf(58);
            if (cut != -1) {
                prefix = attrName2.substring(0, cut);
                attrName = attrName2.substring(cut + 1);
            } else {
                if (attrName2.equals("xmlns")) {
                    prefix = attrName2;
                    attrName = null;
                }
                i += 4;
            }
            if (!prefix.equals("xmlns")) {
                any = true;
            } else {
                int[] iArr = this.f4358n;
                int i2 = this.f4355k;
                int i3 = iArr[i2];
                iArr[i2] = i3 + 1;
                int j = i3 << 1;
                this.f4357m = m1779b(this.f4357m, j + 2);
                this.f4357m[j] = attrName;
                this.f4357m[j + 1] = this.f4360p[i + 3];
                if (attrName != null && this.f4360p[i + 3].equals("")) {
                    m1776a("illegal empty namespace");
                }
                String[] strArr = this.f4360p;
                int i4 = this.f4359o - 1;
                this.f4359o = i4;
                System.arraycopy(this.f4360p, i + 4, strArr, i, (i4 << 2) - i);
                i -= 4;
            }
            i += 4;
        }
        if (any) {
            for (int i5 = (this.f4359o << 2) - 4; i5 >= 0; i5 -= 4) {
                String attrName3 = this.f4360p[i5 + 2];
                int cut2 = attrName3.indexOf(58);
                if (cut2 == 0) {
                    throw new RuntimeException("illegal attribute name: " + attrName3 + " at " + this);
                }
                if (cut2 != -1) {
                    String attrPrefix = attrName3.substring(0, cut2);
                    String attrName4 = attrName3.substring(cut2 + 1);
                    String attrNs = getNamespace(attrPrefix);
                    if (attrNs == null) {
                        throw new RuntimeException("Undefined Prefix: " + attrPrefix + " in " + this);
                    }
                    this.f4360p[i5] = attrNs;
                    this.f4360p[i5 + 1] = attrPrefix;
                    this.f4360p[i5 + 2] = attrName4;
                    for (int j2 = (this.f4359o << 2) - 4; j2 > i5; j2 -= 4) {
                        if (attrName4.equals(this.f4360p[j2 + 2]) && attrNs.equals(this.f4360p[j2])) {
                            m1776a("Duplicate Attribute: {" + attrNs + C0092c.f1286Q + attrName4);
                        }
                    }
                }
            }
        }
        int cut3 = this.f4367w.indexOf(58);
        if (cut3 == 0) {
            m1776a("illegal tag name: " + this.f4367w);
        } else if (cut3 != -1) {
            this.f4365u = this.f4367w.substring(0, cut3);
            this.f4367w = this.f4367w.substring(cut3 + 1);
        }
        this.f4366v = getNamespace(this.f4365u);
        if (this.f4366v == null) {
            if (this.f4365u != null) {
                m1776a("undefined prefix: " + this.f4365u);
            }
            this.f4366v = "";
        }
        return any;
    }

    /* JADX INFO: renamed from: a */
    private final void m1774a(int page, int type, String[] table) {
        if (this.f4352h != null) {
            throw new RuntimeException("setXxxTable must be called before setInput!");
        }
        while (this.f4362r.size() < (page * 3) + 3) {
            this.f4362r.addElement(null);
        }
        this.f4362r.setElementAt(table, (page * 3) + type);
    }

    /* JADX INFO: renamed from: a */
    private final void m1776a(String desc) throws XmlPullParserException {
        throw new XmlPullParserException(desc, this, null);
    }

    /* JADX INFO: renamed from: a */
    private void m1775a(int nr, boolean tags) throws XmlPullParserException {
        if (this.f4362r.size() != 0 || nr != 0) {
            if (nr * 3 > this.f4362r.size()) {
                m1776a("Code Page " + nr + " undefined!");
            }
            if (tags) {
                this.f4351g = (String[]) this.f4362r.elementAt((nr * 3) + this.f4346b);
            } else {
                this.f4349e = (String[]) this.f4362r.elementAt((nr * 3) + this.f4347c);
                this.f4350f = (String[]) this.f4362r.elementAt((nr * 3) + this.f4348d);
            }
        }
    }

    /* JADX INFO: renamed from: b */
    private final void m1778b() throws XmlPullParserException, IOException {
        if (this.f4341A == 3) {
            this.f4355k--;
        }
        if (this.f4342B) {
            this.f4341A = 3;
            this.f4342B = false;
            return;
        }
        this.f4368x = null;
        this.f4365u = null;
        this.f4367w = null;
        int id = m1780c();
        while (id == 0) {
            this.f4361q = -2;
            m1775a(m1781d(), true);
            id = m1780c();
        }
        this.f4361q = -2;
        switch (id) {
            case -1:
                this.f4341A = 1;
                return;
            case 1:
                int sp = (this.f4355k - 1) << 2;
                this.f4341A = 3;
                this.f4366v = this.f4356l[sp];
                this.f4365u = this.f4356l[sp + 1];
                this.f4367w = this.f4356l[sp + 2];
                return;
            case 2:
                this.f4341A = 6;
                char c = (char) m1782e();
                this.f4368x = "" + c;
                this.f4367w = "#" + ((int) c);
                return;
            case 3:
                this.f4341A = 4;
                this.f4368x = m1783f();
                return;
            case 64:
            case Wbxml.EXT_I_1 /* 65 */:
            case Wbxml.EXT_I_2 /* 66 */:
            case 128:
            case 129:
            case 130:
            case 192:
            case 193:
            case 194:
            case 195:
                this.f4341A = 64;
                this.f4370z = id;
                this.f4369y = parseWapExtension(id);
                return;
            case Wbxml.f4340PI /* 67 */:
                throw new RuntimeException("PI curr. not supp.");
            case 131:
                this.f4341A = 4;
                this.f4368x = m1784g();
                return;
            default:
                m1773a(id);
                return;
        }
    }

    public Object parseWapExtension(int id) throws XmlPullParserException, IOException {
        switch (id) {
            case 64:
            case Wbxml.EXT_I_1 /* 65 */:
            case Wbxml.EXT_I_2 /* 66 */:
                return m1783f();
            case 128:
            case 129:
            case 130:
                return new Integer(m1782e());
            case 192:
            case 193:
            case 194:
                return null;
            case 195:
                int count = m1782e();
                byte[] buf = new byte[count];
                while (count > 0) {
                    count -= this.f4345a.read(buf, buf.length - count, count);
                }
                return buf;
            default:
                m1776a("illegal id: " + id);
                return null;
        }
    }

    public void readAttr() throws XmlPullParserException, IOException {
        StringBuffer value;
        int id = m1781d();
        int i = 0;
        while (id != 1) {
            while (id == 0) {
                m1775a(m1781d(), false);
                id = m1781d();
            }
            String name = m1772a(this.f4349e, id);
            int cut = name.indexOf(61);
            if (cut == -1) {
                value = new StringBuffer();
            } else {
                value = new StringBuffer(name.substring(cut + 1));
                name = name.substring(0, cut);
            }
            id = m1781d();
            while (true) {
                if (id <= 128 && id != 0 && id != 2 && id != 3 && id != 131 && ((id < 64 || id > 66) && (id < 128 || id > 130))) {
                    break;
                }
                switch (id) {
                    case 0:
                        m1775a(m1781d(), false);
                        break;
                    case 2:
                        value.append((char) m1782e());
                        break;
                    case 3:
                        value.append(m1783f());
                        break;
                    case 64:
                    case Wbxml.EXT_I_1 /* 65 */:
                    case Wbxml.EXT_I_2 /* 66 */:
                    case 128:
                    case 129:
                    case 130:
                    case 192:
                    case 193:
                    case 194:
                    case 195:
                        value.append(resolveWapExtension(id, parseWapExtension(id)));
                        break;
                    case 131:
                        value.append(m1784g());
                        break;
                    default:
                        value.append(m1772a(this.f4350f, id));
                        break;
                }
                id = m1781d();
            }
            this.f4360p = m1779b(this.f4360p, i + 4);
            int i2 = i + 1;
            this.f4360p[i] = "";
            int i3 = i2 + 1;
            this.f4360p[i2] = null;
            int i4 = i3 + 1;
            this.f4360p[i3] = name;
            i = i4 + 1;
            this.f4360p[i4] = value.toString();
            this.f4359o++;
        }
    }

    /* JADX INFO: renamed from: c */
    private int m1780c() throws IOException {
        if (this.f4361q == -2) {
            this.f4361q = this.f4345a.read();
        }
        return this.f4361q;
    }

    protected String resolveWapExtension(int id, Object data) {
        if (!(data instanceof byte[])) {
            return "$(" + data + ")";
        }
        StringBuffer sb = new StringBuffer();
        byte[] b = (byte[]) data;
        for (int i = 0; i < b.length; i++) {
            sb.append("0123456789abcdef".charAt((b[i] >> 4) & 15));
            sb.append("0123456789abcdef".charAt(b[i] & 15));
        }
        return sb.toString();
    }

    /* JADX INFO: renamed from: a */
    private String m1772a(String[] tab, int id) throws IOException {
        int idx = (id & 127) - 5;
        if (idx == -1) {
            this.f4370z = -1;
            return m1784g();
        }
        if (idx < 0 || tab == null || idx >= tab.length || tab[idx] == null) {
            throw new IOException("id " + id + " undef.");
        }
        this.f4370z = idx + 5;
        return tab[idx];
    }

    /* JADX INFO: renamed from: a */
    private void m1773a(int id) throws XmlPullParserException, IOException {
        this.f4341A = 2;
        this.f4367w = m1772a(this.f4351g, id & 63);
        this.f4359o = 0;
        if ((id & 128) != 0) {
            readAttr();
        }
        this.f4342B = (id & 64) == 0;
        int i = this.f4355k;
        this.f4355k = i + 1;
        int sp = i << 2;
        this.f4356l = m1779b(this.f4356l, sp + 4);
        this.f4356l[sp + 3] = this.f4367w;
        if (this.f4355k >= this.f4358n.length) {
            int[] bigger = new int[this.f4355k + 4];
            System.arraycopy(this.f4358n, 0, bigger, 0, this.f4358n.length);
            this.f4358n = bigger;
        }
        this.f4358n[this.f4355k] = this.f4358n[this.f4355k - 1];
        for (int i2 = this.f4359o - 1; i2 > 0; i2--) {
            for (int j = 0; j < i2; j++) {
                if (getAttributeName(i2).equals(getAttributeName(j))) {
                    m1776a("Duplicate Attribute: " + getAttributeName(i2));
                }
            }
        }
        if (this.f4354j) {
            m1777a();
        } else {
            this.f4366v = "";
        }
        this.f4356l[sp] = this.f4366v;
        this.f4356l[sp + 1] = this.f4365u;
        this.f4356l[sp + 2] = this.f4367w;
    }

    /* JADX INFO: renamed from: b */
    private static String[] m1779b(String[] arr, int required) {
        if (arr.length < required) {
            String[] bigger = new String[required + 16];
            System.arraycopy(arr, 0, bigger, 0, arr.length);
            return bigger;
        }
        return arr;
    }

    /* JADX INFO: renamed from: d */
    private int m1781d() throws IOException {
        int i = this.f4345a.read();
        if (i == -1) {
            throw new IOException("Unexpected EOF");
        }
        return i;
    }

    /* JADX INFO: renamed from: e */
    private int m1782e() throws IOException {
        int i;
        int result = 0;
        do {
            i = m1781d();
            result = (result << 7) | (i & 127);
        } while ((i & 128) != 0);
        return result;
    }

    /* JADX INFO: renamed from: f */
    private String m1783f() throws IOException {
        ByteArrayOutputStream buf = new ByteArrayOutputStream();
        boolean wsp = true;
        while (true) {
            int i = this.f4345a.read();
            if (i != 0) {
                if (i == -1) {
                    throw new IOException("Unexpected EOF");
                }
                if (i > 32) {
                    wsp = false;
                }
                buf.write(i);
            } else {
                this.f4343C = wsp;
                String result = new String(buf.toByteArray(), this.f4344D);
                buf.close();
                return result;
            }
        }
    }

    /* JADX INFO: renamed from: g */
    private String m1784g() throws IOException {
        int pos = m1782e();
        if (this.f4353i == null) {
            this.f4353i = new Hashtable();
        }
        String forReturn = (String) this.f4353i.get(new Integer(pos));
        if (forReturn == null) {
            int end = pos;
            while (end < this.f4352h.length && this.f4352h[end] != 0) {
                end++;
            }
            String forReturn2 = new String(this.f4352h, pos, end - pos, this.f4344D);
            this.f4353i.put(new Integer(pos), forReturn2);
            return forReturn2;
        }
        return forReturn;
    }

    public void setTagTable(int page, String[] table) {
        m1774a(page, this.f4346b, table);
    }

    public void setAttrStartTable(int page, String[] table) {
        m1774a(page, this.f4347c, table);
    }

    public void setAttrValueTable(int page, String[] table) {
        m1774a(page, this.f4348d, table);
    }

    public int getWapCode() {
        return this.f4370z;
    }

    public Object getWapExtensionData() {
        return this.f4369y;
    }
}
