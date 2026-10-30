package org.apache.commons.httpclient.methods;

import org.apache.commons.httpclient.HttpMethodBase;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class GetMethod extends HttpMethodBase {

    /* JADX INFO: renamed from: a */
    static Class f6681a;

    /* JADX INFO: renamed from: c */
    private static final Log f6682c;

    static {
        Class clsM2823a;
        if (f6681a == null) {
            clsM2823a = m2823a("org.apache.commons.httpclient.methods.GetMethod");
            f6681a = clsM2823a;
        } else {
            clsM2823a = f6681a;
        }
        f6682c = LogFactory.getLog(clsM2823a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2823a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public GetMethod() {
        setFollowRedirects(true);
    }

    public GetMethod(String uri) {
        super(uri);
        f6682c.trace("enter GetMethod(String)");
        setFollowRedirects(true);
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase, org.apache.commons.httpclient.HttpMethod
    public String getName() {
        return "GET";
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase, org.apache.commons.httpclient.HttpMethod
    public void recycle() {
        f6682c.trace("enter GetMethod.recycle()");
        super.recycle();
        setFollowRedirects(true);
    }
}
