package org.apache.commons.httpclient.auth;

import org.apache.commons.httpclient.Credentials;

/* JADX INFO: loaded from: classes.dex */
public interface CredentialsProvider {
    public static final String PROVIDER = "http.authentication.credential-provider";

    Credentials getCredentials(AuthScheme authScheme, String str, int i, boolean z) throws CredentialsNotAvailableException;
}
