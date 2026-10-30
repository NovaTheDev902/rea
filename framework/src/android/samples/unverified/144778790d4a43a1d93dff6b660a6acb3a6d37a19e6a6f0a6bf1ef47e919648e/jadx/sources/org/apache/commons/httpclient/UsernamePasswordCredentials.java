package org.apache.commons.httpclient;

import com.lenovo.lps.sus.p008c.C0092c;
import org.apache.commons.httpclient.util.LangUtils;

/* JADX INFO: loaded from: classes.dex */
public class UsernamePasswordCredentials implements Credentials {

    /* JADX INFO: renamed from: a */
    private String f6570a;

    /* JADX INFO: renamed from: b */
    private String f6571b;

    public UsernamePasswordCredentials() {
    }

    public UsernamePasswordCredentials(String usernamePassword) {
        if (usernamePassword == null) {
            throw new IllegalArgumentException("Username:password string may not be null");
        }
        int atColon = usernamePassword.indexOf(58);
        if (atColon >= 0) {
            this.f6570a = usernamePassword.substring(0, atColon);
            this.f6571b = usernamePassword.substring(atColon + 1);
        } else {
            this.f6570a = usernamePassword;
        }
    }

    public UsernamePasswordCredentials(String userName, String password) {
        if (userName == null) {
            throw new IllegalArgumentException("Username may not be null");
        }
        this.f6570a = userName;
        this.f6571b = password;
    }

    public void setUserName(String userName) {
        if (userName == null) {
            throw new IllegalArgumentException("Username may not be null");
        }
        this.f6570a = userName;
    }

    public String getUserName() {
        return this.f6570a;
    }

    public void setPassword(String password) {
        this.f6571b = password;
    }

    public String getPassword() {
        return this.f6571b;
    }

    public String toString() {
        StringBuffer result = new StringBuffer();
        result.append(this.f6570a);
        result.append(C0092c.f1283N);
        result.append(this.f6571b == null ? "null" : this.f6571b);
        return result.toString();
    }

    public int hashCode() {
        int hash = LangUtils.hashCode(17, this.f6570a);
        return LangUtils.hashCode(hash, this.f6571b);
    }

    public boolean equals(Object o) {
        if (o == null) {
            return false;
        }
        if (this == o) {
            return true;
        }
        if (!getClass().equals(o.getClass())) {
            return false;
        }
        UsernamePasswordCredentials that = (UsernamePasswordCredentials) o;
        return LangUtils.equals(this.f6570a, that.f6570a) && LangUtils.equals(this.f6571b, that.f6571b);
    }
}
