package org.apache.commons.httpclient.auth;

/* JADX INFO: loaded from: classes.dex */
public class HttpAuthRealm extends AuthScope {
    public HttpAuthRealm(String domain, String realm) {
        super(domain, -1, realm, ANY_SCHEME);
    }
}
