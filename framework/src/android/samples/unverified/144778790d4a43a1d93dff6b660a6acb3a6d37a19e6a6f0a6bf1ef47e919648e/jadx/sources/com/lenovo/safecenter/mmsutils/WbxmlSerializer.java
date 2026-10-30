package com.lenovo.safecenter.mmsutils;

import com.lenovo.lps.sus.p003a.p004a.p005a.InterfaceC0079b;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;
import java.io.Writer;
import java.util.Hashtable;
import java.util.Vector;
import org.xmlpull.v1.XmlSerializer;

/* JADX INFO: loaded from: classes.dex */
public class WbxmlSerializer implements XmlSerializer {
    public static final String ERR_TAG = "WbxmlSerializer.java";

    /* JADX INFO: renamed from: b */
    OutputStream f4372b;

    /* JADX INFO: renamed from: e */
    String f4375e;

    /* JADX INFO: renamed from: f */
    int f4376f;

    /* JADX INFO: renamed from: k */
    private int f4381k;

    /* JADX INFO: renamed from: l */
    private int f4382l;

    /* JADX INFO: renamed from: m */
    private String f4383m;

    /* JADX INFO: renamed from: a */
    Hashtable f4371a = new Hashtable();

    /* JADX INFO: renamed from: c */
    ByteArrayOutputStream f4373c = new ByteArrayOutputStream();

    /* JADX INFO: renamed from: d */
    ByteArrayOutputStream f4374d = new ByteArrayOutputStream();

    /* JADX INFO: renamed from: g */
    Vector f4377g = new Vector();

    /* JADX INFO: renamed from: h */
    Hashtable f4378h = new Hashtable();

    /* JADX INFO: renamed from: i */
    Hashtable f4379i = new Hashtable();

    /* JADX INFO: renamed from: j */
    Hashtable f4380j = new Hashtable();

    @Override // org.xmlpull.v1.XmlSerializer
    public XmlSerializer attribute(String namespace, String name, String value) {
        this.f4377g.addElement(name);
        this.f4377g.addElement(value);
        return this;
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public void cdsect(String cdsect) throws IOException {
        text(cdsect);
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public void comment(String comment) {
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public void docdecl(String docdecl) {
        throw new RuntimeException("Cannot write docdecl for WBXML");
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public void entityRef(String er) {
        throw new RuntimeException("EntityReference not supported for WBXML");
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public int getDepth() {
        return this.f4376f;
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public boolean getFeature(String name) {
        return false;
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public String getNamespace() {
        throw new RuntimeException("NYI");
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public String getName() {
        throw new RuntimeException("NYI");
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public String getPrefix(String nsp, boolean create) {
        throw new RuntimeException("NYI");
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public Object getProperty(String name) {
        return null;
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public void ignorableWhitespace(String sp) {
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public void endDocument() throws IOException {
        m1785a(this.f4372b, this.f4374d.size());
        this.f4372b.write(this.f4374d.toByteArray());
        this.f4372b.write(this.f4373c.toByteArray());
        this.f4372b.flush();
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public void flush() {
    }

    public void checkPending(boolean degenerated) throws IOException {
        int i;
        int i2;
        if (this.f4375e != null) {
            int len = this.f4377g.size();
            int[] idx = (int[]) this.f4380j.get(this.f4375e);
            if (idx == null) {
                ByteArrayOutputStream byteArrayOutputStream = this.f4373c;
                if (len == 0) {
                    i2 = degenerated ? 4 : 68;
                } else {
                    i2 = degenerated ? 132 : 196;
                }
                byteArrayOutputStream.write(i2);
                m1788a(this.f4375e, false);
            } else {
                if (idx[0] != this.f4382l) {
                    this.f4382l = idx[0];
                    this.f4373c.write(0);
                    this.f4373c.write(this.f4382l);
                }
                ByteArrayOutputStream byteArrayOutputStream2 = this.f4373c;
                if (len == 0) {
                    i = degenerated ? idx[1] : idx[1] | 64;
                } else {
                    i = degenerated ? idx[1] | 128 : idx[1] | 192;
                }
                byteArrayOutputStream2.write(i);
            }
            int i3 = 0;
            while (i3 < len) {
                int[] idx2 = (int[]) this.f4378h.get(this.f4377g.elementAt(i3));
                if (idx2 == null) {
                    this.f4373c.write(4);
                    m1788a((String) this.f4377g.elementAt(i3), false);
                } else {
                    if (idx2[0] != this.f4381k) {
                        this.f4381k = idx2[0];
                        this.f4373c.write(0);
                        this.f4373c.write(this.f4381k);
                    }
                    this.f4373c.write(idx2[1]);
                }
                int i4 = i3 + 1;
                int[] idx3 = (int[]) this.f4379i.get(this.f4377g.elementAt(i4));
                if (idx3 == null) {
                    m1787a((String) this.f4377g.elementAt(i4));
                } else {
                    if (idx3[0] != this.f4381k) {
                        this.f4381k = idx3[0];
                        this.f4373c.write(0);
                        this.f4373c.write(this.f4381k);
                    }
                    this.f4373c.write(idx3[1]);
                }
                i3 = i4 + 1;
            }
            if (len > 0) {
                this.f4373c.write(1);
            }
            this.f4375e = null;
            this.f4377g.removeAllElements();
        }
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public void processingInstruction(String pi) {
        throw new RuntimeException("PI NYI");
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public void setFeature(String name, boolean value) {
        throw new IllegalArgumentException("unknown feature " + name);
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public void setOutput(Writer writer) {
        throw new RuntimeException("Wbxml requires an OutputStream!");
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public void setOutput(OutputStream out, String encoding) throws IOException {
        if (encoding == null) {
            encoding = InterfaceC0079b.f1213a;
        }
        this.f4383m = encoding;
        this.f4372b = out;
        this.f4373c = new ByteArrayOutputStream();
        this.f4374d = new ByteArrayOutputStream();
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public void setPrefix(String prefix, String nsp) {
        throw new RuntimeException("NYI");
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public void setProperty(String property, Object value) {
        throw new IllegalArgumentException("unknown property " + property);
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public void startDocument(String s, Boolean b) throws IOException {
        this.f4372b.write(3);
        this.f4372b.write(1);
        if (s != null) {
            this.f4383m = s;
        }
        if (this.f4383m.toUpperCase().equals(InterfaceC0079b.f1213a)) {
            this.f4372b.write(106);
        } else {
            if (this.f4383m.toUpperCase().equals("ISO-8859-1")) {
                this.f4372b.write(4);
                return;
            }
            throw new UnsupportedEncodingException(s);
        }
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public XmlSerializer startTag(String namespace, String name) throws IOException {
        if (namespace != null && !"".equals(namespace)) {
            throw new RuntimeException("NSP NYI");
        }
        checkPending(false);
        this.f4375e = name;
        this.f4376f++;
        return this;
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public XmlSerializer text(char[] chars, int start, int len) throws IOException {
        checkPending(false);
        m1787a(new String(chars, start, len));
        return this;
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public XmlSerializer text(String text) throws IOException {
        checkPending(false);
        m1787a(text);
        return this;
    }

    /* JADX INFO: renamed from: a */
    private void m1787a(String text) throws IOException {
        int p0 = 0;
        int lastCut = 0;
        int len = text.length();
        while (p0 < len) {
            while (p0 < len && text.charAt(p0) < 'A') {
                p0++;
            }
            int p1 = p0;
            while (p1 < len && text.charAt(p1) >= 'A') {
                p1++;
            }
            if (p1 - p0 > 10) {
                if (p0 > lastCut && text.charAt(p0 - 1) == ' ' && this.f4371a.get(text.substring(p0, p1)) == null) {
                    this.f4373c.write(131);
                    m1788a(text.substring(lastCut, p1), false);
                } else {
                    if (p0 > lastCut && text.charAt(p0 - 1) == ' ') {
                        p0--;
                    }
                    if (p0 > lastCut) {
                        this.f4373c.write(131);
                        m1788a(text.substring(lastCut, p0), false);
                    }
                    this.f4373c.write(131);
                    m1788a(text.substring(p0, p1), true);
                }
                lastCut = p1;
            }
            p0 = p1;
        }
        if (lastCut < len) {
            this.f4373c.write(131);
            m1788a(text.substring(lastCut, len), false);
        }
    }

    @Override // org.xmlpull.v1.XmlSerializer
    public XmlSerializer endTag(String namespace, String name) throws IOException {
        if (this.f4375e != null) {
            checkPending(true);
        } else {
            this.f4373c.write(1);
        }
        this.f4376f--;
        return this;
    }

    public void writeWapExtension(int type, Object data) throws IOException {
        checkPending(false);
        this.f4373c.write(type);
        switch (type) {
            case 64:
            case Wbxml.EXT_I_1 /* 65 */:
            case Wbxml.EXT_I_2 /* 66 */:
                m1786a(this.f4373c, (String) data);
                return;
            case 128:
            case 129:
            case 130:
                m1788a((String) data, false);
                return;
            case 192:
            case 193:
            case 194:
                return;
            case 195:
                byte[] bytes = (byte[]) data;
                m1785a(this.f4373c, bytes.length);
                this.f4373c.write(bytes);
                return;
            default:
                throw new IllegalArgumentException();
        }
    }

    /* JADX INFO: renamed from: a */
    private static void m1785a(OutputStream out, int i) throws IOException {
        int idx;
        byte[] buf = new byte[5];
        int idx2 = 0;
        while (true) {
            idx = idx2 + 1;
            buf[idx2] = (byte) (i & 127);
            i >>= 7;
            if (i == 0) {
                break;
            } else {
                idx2 = idx;
            }
        }
        int idx3 = idx;
        while (idx3 > 1) {
            idx3--;
            out.write(buf[idx3] | 128);
        }
        out.write(buf[0]);
    }

    /* JADX INFO: renamed from: a */
    private void m1786a(OutputStream out, String s) throws IOException {
        byte[] data = s.getBytes(this.f4383m);
        out.write(data);
        out.write(0);
    }

    /* JADX INFO: renamed from: a */
    private final void m1788a(String s, boolean mayPrependSpace) throws IOException {
        Integer idx = (Integer) this.f4371a.get(s);
        if (idx != null) {
            m1785a(this.f4373c, idx.intValue());
            return;
        }
        int i = this.f4374d.size();
        if (s.charAt(0) >= '0' && mayPrependSpace) {
            s = ' ' + s;
            m1785a(this.f4373c, i + 1);
        } else {
            m1785a(this.f4373c, i);
        }
        this.f4371a.put(s, new Integer(i));
        if (s.charAt(0) == ' ') {
            this.f4371a.put(s.substring(1), new Integer(i + 1));
        }
        int j = s.lastIndexOf(32);
        if (j > 1) {
            this.f4371a.put(s.substring(j), new Integer(i + j));
            this.f4371a.put(s.substring(j + 1), new Integer(i + j + 1));
        }
        m1786a(this.f4374d, s);
        this.f4374d.flush();
    }

    public void setTagTable(int page, String[] tagTable) {
        for (int i = 0; i < tagTable.length; i++) {
            if (tagTable[i] != null) {
                int[] idx = {page, i + 5};
                this.f4380j.put(tagTable[i], idx);
            }
        }
    }

    public void setAttrStartTable(int page, String[] attrStartTable) {
        for (int i = 0; i < attrStartTable.length; i++) {
            if (attrStartTable[i] != null) {
                int[] idx = {page, i + 5};
                this.f4378h.put(attrStartTable[i], idx);
            }
        }
    }

    public void setAttrValueTable(int page, String[] attrValueTable) {
        for (int i = 0; i < attrValueTable.length; i++) {
            if (attrValueTable[i] != null) {
                int[] idx = {page, i + 133};
                this.f4379i.put(attrValueTable[i], idx);
            }
        }
    }
}
