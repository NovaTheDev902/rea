package org.apache.commons.httpclient;

import com.lenovo.safecenter.utils.Untils;
import java.util.ArrayList;
import java.util.List;
import org.apache.commons.httpclient.util.ParameterParser;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class HeaderElement extends NameValuePair {

    /* JADX INFO: renamed from: a */
    static Class f6444a;

    /* JADX INFO: renamed from: b */
    private static final Log f6445b;

    /* JADX INFO: renamed from: c */
    private NameValuePair[] f6446c;

    public HeaderElement() {
        this((String) null, (String) null, (NameValuePair[]) null);
    }

    public HeaderElement(String name, String value) {
        this(name, value, (NameValuePair[]) null);
    }

    public HeaderElement(String name, String value, NameValuePair[] parameters) {
        super(name, value);
        this.f6446c = null;
        this.f6446c = parameters;
    }

    public HeaderElement(char[] chars, int offset, int length) {
        this();
        if (chars != null) {
            ParameterParser parser = new ParameterParser();
            List params = parser.parse(chars, offset, length, Untils.WAIT);
            if (params.size() > 0) {
                NameValuePair element = (NameValuePair) params.remove(0);
                setName(element.getName());
                setValue(element.getValue());
                if (params.size() > 0) {
                    this.f6446c = (NameValuePair[]) params.toArray(new NameValuePair[params.size()]);
                }
            }
        }
    }

    public HeaderElement(char[] chars) {
        this(chars, 0, chars.length);
    }

    static {
        Class clsM2704a;
        if (f6444a == null) {
            clsM2704a = m2704a("org.apache.commons.httpclient.HeaderElement");
            f6444a = clsM2704a;
        } else {
            clsM2704a = f6444a;
        }
        f6445b = LogFactory.getLog(clsM2704a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2704a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public NameValuePair[] getParameters() {
        return this.f6446c;
    }

    public static final HeaderElement[] parseElements(char[] headerValue) {
        f6445b.trace("enter HeaderElement.parseElements(char[])");
        if (headerValue == null) {
            return new HeaderElement[0];
        }
        List elements = new ArrayList();
        int from = 0;
        int len = headerValue.length;
        boolean qouted = false;
        for (int i = 0; i < len; i++) {
            char ch = headerValue[i];
            if (ch == '\"') {
                qouted = !qouted;
            }
            HeaderElement element = null;
            if (!qouted && ch == ',') {
                element = new HeaderElement(headerValue, from, i);
                from = i + 1;
            } else if (i == len - 1) {
                element = new HeaderElement(headerValue, from, len);
            }
            if (element != null && element.getName() != null) {
                elements.add(element);
            }
        }
        return (HeaderElement[]) elements.toArray(new HeaderElement[elements.size()]);
    }

    public static final HeaderElement[] parseElements(String headerValue) {
        f6445b.trace("enter HeaderElement.parseElements(String)");
        return headerValue == null ? new HeaderElement[0] : parseElements(headerValue.toCharArray());
    }

    public static final HeaderElement[] parse(String headerValue) throws HttpException {
        f6445b.trace("enter HeaderElement.parse(String)");
        return headerValue == null ? new HeaderElement[0] : parseElements(headerValue.toCharArray());
    }

    public NameValuePair getParameterByName(String name) {
        f6445b.trace("enter HeaderElement.getParameterByName(String)");
        if (name == null) {
            throw new IllegalArgumentException("Name may not be null");
        }
        NameValuePair[] parameters = getParameters();
        if (parameters == null) {
            return null;
        }
        for (NameValuePair current : parameters) {
            if (current.getName().equalsIgnoreCase(name)) {
                return current;
            }
        }
        return null;
    }
}
