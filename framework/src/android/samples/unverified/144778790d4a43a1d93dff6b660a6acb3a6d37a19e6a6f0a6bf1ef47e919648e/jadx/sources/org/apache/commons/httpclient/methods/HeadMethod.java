package org.apache.commons.httpclient.methods;

import java.io.IOException;
import org.apache.commons.httpclient.HttpConnection;
import org.apache.commons.httpclient.HttpMethodBase;
import org.apache.commons.httpclient.HttpState;
import org.apache.commons.httpclient.ProtocolException;
import org.apache.commons.httpclient.params.HttpMethodParams;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class HeadMethod extends HttpMethodBase {

    /* JADX INFO: renamed from: a */
    static Class f6683a;

    /* JADX INFO: renamed from: c */
    private static final Log f6684c;

    static {
        Class clsM2824a;
        if (f6683a == null) {
            clsM2824a = m2824a("org.apache.commons.httpclient.methods.HeadMethod");
            f6683a = clsM2824a;
        } else {
            clsM2824a = f6683a;
        }
        f6684c = LogFactory.getLog(clsM2824a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2824a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public HeadMethod() {
        setFollowRedirects(true);
    }

    public HeadMethod(String uri) {
        super(uri);
        setFollowRedirects(true);
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase, org.apache.commons.httpclient.HttpMethod
    public String getName() {
        return "HEAD";
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase, org.apache.commons.httpclient.HttpMethod
    public void recycle() {
        super.recycle();
        setFollowRedirects(true);
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase
    protected void readResponseBody(HttpState state, HttpConnection conn) throws IOException {
        boolean responseAvailable;
        f6684c.trace("enter HeadMethod.readResponseBody(HttpState, HttpConnection)");
        int bodyCheckTimeout = getParams().getIntParameter(HttpMethodParams.HEAD_BODY_CHECK_TIMEOUT, -1);
        if (bodyCheckTimeout < 0) {
            responseBodyConsumed();
            return;
        }
        if (f6684c.isDebugEnabled()) {
            f6684c.debug(new StringBuffer().append("Check for non-compliant response body. Timeout in ").append(bodyCheckTimeout).append(" ms").toString());
        }
        try {
            responseAvailable = conn.isResponseAvailable(bodyCheckTimeout);
        } catch (IOException e) {
            f6684c.debug("An IOException occurred while testing if a response was available, we will assume one is not.", e);
            responseAvailable = false;
        }
        if (responseAvailable) {
            if (getParams().isParameterTrue(HttpMethodParams.REJECT_HEAD_BODY)) {
                throw new ProtocolException("Body content may not be sent in response to HTTP HEAD request");
            }
            f6684c.warn("Body content returned in response to HTTP HEAD");
            super.readResponseBody(state, conn);
        }
    }

    public int getBodyCheckTimeout() {
        return getParams().getIntParameter(HttpMethodParams.HEAD_BODY_CHECK_TIMEOUT, -1);
    }

    public void setBodyCheckTimeout(int timeout) {
        getParams().setIntParameter(HttpMethodParams.HEAD_BODY_CHECK_TIMEOUT, timeout);
    }
}
