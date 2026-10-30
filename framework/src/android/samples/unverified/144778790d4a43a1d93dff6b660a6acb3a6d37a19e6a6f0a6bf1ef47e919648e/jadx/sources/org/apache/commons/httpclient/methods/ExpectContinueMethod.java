package org.apache.commons.httpclient.methods;

import java.io.IOException;
import org.apache.commons.httpclient.HttpConnection;
import org.apache.commons.httpclient.HttpMethodBase;
import org.apache.commons.httpclient.HttpState;
import org.apache.commons.httpclient.HttpVersion;
import org.apache.commons.httpclient.params.HttpMethodParams;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public abstract class ExpectContinueMethod extends HttpMethodBase {

    /* JADX INFO: renamed from: a */
    private static final Log f6677a;

    /* JADX INFO: renamed from: c */
    static Class f6678c;

    protected abstract boolean hasRequestContent();

    static {
        Class clsM2822a;
        if (f6678c == null) {
            clsM2822a = m2822a("org.apache.commons.httpclient.methods.ExpectContinueMethod");
            f6678c = clsM2822a;
        } else {
            clsM2822a = f6678c;
        }
        f6677a = LogFactory.getLog(clsM2822a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2822a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public ExpectContinueMethod() {
    }

    public ExpectContinueMethod(String uri) {
        super(uri);
    }

    public boolean getUseExpectHeader() {
        return getParams().getBooleanParameter(HttpMethodParams.USE_EXPECT_CONTINUE, false);
    }

    public void setUseExpectHeader(boolean value) {
        getParams().setBooleanParameter(HttpMethodParams.USE_EXPECT_CONTINUE, value);
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase
    protected void addRequestHeaders(HttpState state, HttpConnection conn) throws IOException {
        f6677a.trace("enter ExpectContinueMethod.addRequestHeaders(HttpState, HttpConnection)");
        super.addRequestHeaders(state, conn);
        boolean headerPresent = getRequestHeader("Expect") != null;
        if (getParams().isParameterTrue(HttpMethodParams.USE_EXPECT_CONTINUE) && getEffectiveVersion().greaterEquals(HttpVersion.HTTP_1_1) && hasRequestContent()) {
            if (!headerPresent) {
                setRequestHeader("Expect", "100-continue");
            }
        } else if (headerPresent) {
            removeRequestHeader("Expect");
        }
    }
}
