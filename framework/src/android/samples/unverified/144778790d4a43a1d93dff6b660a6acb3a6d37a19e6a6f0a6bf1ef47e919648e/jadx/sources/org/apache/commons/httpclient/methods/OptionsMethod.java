package org.apache.commons.httpclient.methods;

import java.util.Enumeration;
import java.util.StringTokenizer;
import java.util.Vector;
import org.apache.commons.httpclient.Header;
import org.apache.commons.httpclient.HttpConnection;
import org.apache.commons.httpclient.HttpMethodBase;
import org.apache.commons.httpclient.HttpState;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class OptionsMethod extends HttpMethodBase {

    /* JADX INFO: renamed from: a */
    static Class f6694a;

    /* JADX INFO: renamed from: c */
    private static final Log f6695c;

    /* JADX INFO: renamed from: d */
    private Vector f6696d;

    static {
        Class clsM2827a;
        if (f6694a == null) {
            clsM2827a = m2827a("org.apache.commons.httpclient.methods.OptionsMethod");
            f6694a = clsM2827a;
        } else {
            clsM2827a = f6694a;
        }
        f6695c = LogFactory.getLog(clsM2827a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2827a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public OptionsMethod() {
        this.f6696d = new Vector();
    }

    public OptionsMethod(String uri) {
        super(uri);
        this.f6696d = new Vector();
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase, org.apache.commons.httpclient.HttpMethod
    public String getName() {
        return "OPTIONS";
    }

    public boolean isAllowed(String method) {
        checkUsed();
        return this.f6696d.contains(method);
    }

    public Enumeration getAllowedMethods() {
        checkUsed();
        return this.f6696d.elements();
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase
    protected void processResponseHeaders(HttpState state, HttpConnection conn) {
        f6695c.trace("enter OptionsMethod.processResponseHeaders(HttpState, HttpConnection)");
        Header allowHeader = getResponseHeader("allow");
        if (allowHeader != null) {
            String allowHeaderValue = allowHeader.getValue();
            StringTokenizer tokenizer = new StringTokenizer(allowHeaderValue, ",");
            while (tokenizer.hasMoreElements()) {
                String methodAllowed = tokenizer.nextToken().trim().toUpperCase();
                this.f6696d.addElement(methodAllowed);
            }
        }
    }

    public boolean needContentLength() {
        return false;
    }
}
