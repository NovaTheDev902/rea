package org.apache.commons.httpclient.methods;

import java.util.Iterator;
import java.util.Vector;
import org.apache.commons.httpclient.NameValuePair;
import org.apache.commons.httpclient.util.EncodingUtil;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class PostMethod extends EntityEnclosingMethod {
    public static final String FORM_URL_ENCODED_CONTENT_TYPE = "application/x-www-form-urlencoded";

    /* JADX INFO: renamed from: d */
    static Class f6697d;

    /* JADX INFO: renamed from: e */
    private static final Log f6698e;

    /* JADX INFO: renamed from: f */
    private Vector f6699f;

    static {
        Class clsM2828a;
        if (f6697d == null) {
            clsM2828a = m2828a("org.apache.commons.httpclient.methods.PostMethod");
            f6697d = clsM2828a;
        } else {
            clsM2828a = f6697d;
        }
        f6698e = LogFactory.getLog(clsM2828a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2828a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public PostMethod() {
        this.f6699f = new Vector();
    }

    public PostMethod(String uri) {
        super(uri);
        this.f6699f = new Vector();
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase, org.apache.commons.httpclient.HttpMethod
    public String getName() {
        return "POST";
    }

    @Override // org.apache.commons.httpclient.methods.EntityEnclosingMethod, org.apache.commons.httpclient.methods.ExpectContinueMethod
    protected boolean hasRequestContent() {
        f6698e.trace("enter PostMethod.hasRequestContent()");
        if (this.f6699f.isEmpty()) {
            return super.hasRequestContent();
        }
        return true;
    }

    @Override // org.apache.commons.httpclient.methods.EntityEnclosingMethod
    protected void clearRequestBody() {
        f6698e.trace("enter PostMethod.clearRequestBody()");
        this.f6699f.clear();
        super.clearRequestBody();
    }

    @Override // org.apache.commons.httpclient.methods.EntityEnclosingMethod
    protected RequestEntity generateRequestEntity() {
        if (this.f6699f.isEmpty()) {
            return super.generateRequestEntity();
        }
        String content = EncodingUtil.formUrlEncode(getParameters(), getRequestCharSet());
        return new ByteArrayRequestEntity(EncodingUtil.getAsciiBytes(content), FORM_URL_ENCODED_CONTENT_TYPE);
    }

    public void setParameter(String parameterName, String parameterValue) {
        f6698e.trace("enter PostMethod.setParameter(String, String)");
        removeParameter(parameterName);
        addParameter(parameterName, parameterValue);
    }

    public NameValuePair getParameter(String paramName) {
        f6698e.trace("enter PostMethod.getParameter(String)");
        if (paramName == null) {
            return null;
        }
        for (NameValuePair parameter : this.f6699f) {
            if (paramName.equals(parameter.getName())) {
                return parameter;
            }
        }
        return null;
    }

    public NameValuePair[] getParameters() {
        f6698e.trace("enter PostMethod.getParameters()");
        int numPairs = this.f6699f.size();
        Object[] objectArr = this.f6699f.toArray();
        NameValuePair[] nvPairArr = new NameValuePair[numPairs];
        for (int i = 0; i < numPairs; i++) {
            nvPairArr[i] = (NameValuePair) objectArr[i];
        }
        return nvPairArr;
    }

    public void addParameter(String paramName, String paramValue) throws IllegalArgumentException {
        f6698e.trace("enter PostMethod.addParameter(String, String)");
        if (paramName == null || paramValue == null) {
            throw new IllegalArgumentException("Arguments to addParameter(String, String) cannot be null");
        }
        super.clearRequestBody();
        this.f6699f.add(new NameValuePair(paramName, paramValue));
    }

    public void addParameter(NameValuePair param) throws IllegalArgumentException {
        f6698e.trace("enter PostMethod.addParameter(NameValuePair)");
        if (param == null) {
            throw new IllegalArgumentException("NameValuePair may not be null");
        }
        addParameter(param.getName(), param.getValue());
    }

    public void addParameters(NameValuePair[] parameters) {
        f6698e.trace("enter PostMethod.addParameters(NameValuePair[])");
        if (parameters == null) {
            f6698e.warn("Attempt to addParameters(null) ignored");
            return;
        }
        super.clearRequestBody();
        for (NameValuePair nameValuePair : parameters) {
            this.f6699f.add(nameValuePair);
        }
    }

    public boolean removeParameter(String paramName) throws IllegalArgumentException {
        f6698e.trace("enter PostMethod.removeParameter(String)");
        if (paramName == null) {
            throw new IllegalArgumentException("Argument passed to removeParameter(String) cannot be null");
        }
        boolean removed = false;
        Iterator iter = this.f6699f.iterator();
        while (iter.hasNext()) {
            NameValuePair pair = (NameValuePair) iter.next();
            if (paramName.equals(pair.getName())) {
                iter.remove();
                removed = true;
            }
        }
        return removed;
    }

    public boolean removeParameter(String paramName, String paramValue) throws IllegalArgumentException {
        f6698e.trace("enter PostMethod.removeParameter(String, String)");
        if (paramName == null) {
            throw new IllegalArgumentException("Parameter name may not be null");
        }
        if (paramValue == null) {
            throw new IllegalArgumentException("Parameter value may not be null");
        }
        Iterator iter = this.f6699f.iterator();
        while (iter.hasNext()) {
            NameValuePair pair = (NameValuePair) iter.next();
            if (paramName.equals(pair.getName()) && paramValue.equals(pair.getValue())) {
                iter.remove();
                return true;
            }
        }
        return false;
    }

    public void setRequestBody(NameValuePair[] parametersBody) throws IllegalArgumentException {
        f6698e.trace("enter PostMethod.setRequestBody(NameValuePair[])");
        if (parametersBody == null) {
            throw new IllegalArgumentException("Array of parameters may not be null");
        }
        clearRequestBody();
        addParameters(parametersBody);
    }
}
