package org.apache.commons.httpclient.methods;

import org.apache.commons.httpclient.HttpMethodBase;

/* JADX INFO: loaded from: classes.dex */
public class TraceMethod extends HttpMethodBase {
    public TraceMethod(String uri) {
        super(uri);
        setFollowRedirects(false);
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase, org.apache.commons.httpclient.HttpMethod
    public String getName() {
        return "TRACE";
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase, org.apache.commons.httpclient.HttpMethod
    public void recycle() {
        super.recycle();
        setFollowRedirects(false);
    }
}
