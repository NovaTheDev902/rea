package org.apache.commons.httpclient.methods;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;
import org.apache.commons.httpclient.HttpConnection;
import org.apache.commons.httpclient.HttpState;
import org.apache.commons.httpclient.methods.multipart.FilePart;
import org.apache.commons.httpclient.methods.multipart.Part;
import org.apache.commons.httpclient.methods.multipart.StringPart;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class MultipartPostMethod extends ExpectContinueMethod {
    public static final String MULTIPART_FORM_CONTENT_TYPE = "multipart/form-data";

    /* JADX INFO: renamed from: a */
    static Class f6691a;

    /* JADX INFO: renamed from: d */
    private static final Log f6692d;

    /* JADX INFO: renamed from: e */
    private final List f6693e;

    static {
        Class clsM2826a;
        if (f6691a == null) {
            clsM2826a = m2826a("org.apache.commons.httpclient.methods.MultipartPostMethod");
            f6691a = clsM2826a;
        } else {
            clsM2826a = f6691a;
        }
        f6692d = LogFactory.getLog(clsM2826a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2826a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public MultipartPostMethod() {
        this.f6693e = new ArrayList();
    }

    public MultipartPostMethod(String uri) {
        super(uri);
        this.f6693e = new ArrayList();
    }

    @Override // org.apache.commons.httpclient.methods.ExpectContinueMethod
    protected boolean hasRequestContent() {
        return true;
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase, org.apache.commons.httpclient.HttpMethod
    public String getName() {
        return "POST";
    }

    public void addParameter(String parameterName, String parameterValue) {
        f6692d.trace("enter addParameter(String parameterName, String parameterValue)");
        this.f6693e.add(new StringPart(parameterName, parameterValue));
    }

    public void addParameter(String parameterName, File parameterFile) throws FileNotFoundException {
        f6692d.trace("enter MultipartPostMethod.addParameter(String parameterName, File parameterFile)");
        this.f6693e.add(new FilePart(parameterName, parameterFile));
    }

    public void addParameter(String parameterName, String fileName, File parameterFile) throws FileNotFoundException {
        f6692d.trace("enter MultipartPostMethod.addParameter(String parameterName, String fileName, File parameterFile)");
        this.f6693e.add(new FilePart(parameterName, fileName, parameterFile));
    }

    public void addPart(Part part) {
        f6692d.trace("enter addPart(Part part)");
        this.f6693e.add(part);
    }

    public Part[] getParts() {
        return (Part[]) this.f6693e.toArray(new Part[this.f6693e.size()]);
    }

    protected void addContentLengthRequestHeader(HttpState state, HttpConnection conn) throws IOException {
        f6692d.trace("enter EntityEnclosingMethod.addContentLengthRequestHeader(HttpState, HttpConnection)");
        if (getRequestHeader("Content-Length") == null) {
            long len = getRequestContentLength();
            addRequestHeader("Content-Length", String.valueOf(len));
        }
        removeRequestHeader("Transfer-Encoding");
    }

    protected void addContentTypeRequestHeader(HttpState state, HttpConnection conn) throws IOException {
        f6692d.trace("enter EntityEnclosingMethod.addContentTypeRequestHeader(HttpState, HttpConnection)");
        if (!this.f6693e.isEmpty()) {
            StringBuffer buffer = new StringBuffer(MULTIPART_FORM_CONTENT_TYPE);
            if (Part.getBoundary() != null) {
                buffer.append("; boundary=");
                buffer.append(Part.getBoundary());
            }
            setRequestHeader("Content-Type", buffer.toString());
        }
    }

    @Override // org.apache.commons.httpclient.methods.ExpectContinueMethod, org.apache.commons.httpclient.HttpMethodBase
    protected void addRequestHeaders(HttpState state, HttpConnection conn) throws IOException {
        f6692d.trace("enter MultipartPostMethod.addRequestHeaders(HttpState state, HttpConnection conn)");
        super.addRequestHeaders(state, conn);
        addContentLengthRequestHeader(state, conn);
        addContentTypeRequestHeader(state, conn);
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase
    protected boolean writeRequestBody(HttpState state, HttpConnection conn) throws IOException {
        f6692d.trace("enter MultipartPostMethod.writeRequestBody(HttpState state, HttpConnection conn)");
        OutputStream out = conn.getRequestOutputStream();
        Part.sendParts(out, getParts());
        return true;
    }

    protected long getRequestContentLength() throws IOException {
        f6692d.trace("enter MultipartPostMethod.getRequestContentLength()");
        return Part.getLengthOfParts(getParts());
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase, org.apache.commons.httpclient.HttpMethod
    public void recycle() {
        f6692d.trace("enter MultipartPostMethod.recycle()");
        super.recycle();
        this.f6693e.clear();
    }
}
