package org.apache.commons.httpclient.methods;

/* JADX INFO: loaded from: classes.dex */
public class PutMethod extends EntityEnclosingMethod {
    public PutMethod() {
    }

    public PutMethod(String uri) {
        super(uri);
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase, org.apache.commons.httpclient.HttpMethod
    public String getName() {
        return "PUT";
    }
}
