package org.apache.commons.httpclient;

import java.io.Serializable;
import org.apache.commons.httpclient.util.LangUtils;

/* JADX INFO: loaded from: classes.dex */
public class NameValuePair implements Serializable {

    /* JADX INFO: renamed from: a */
    private String f6548a;

    /* JADX INFO: renamed from: b */
    private String f6549b;

    public NameValuePair() {
        this(null, null);
    }

    public NameValuePair(String name, String value) {
        this.f6548a = null;
        this.f6549b = null;
        this.f6548a = name;
        this.f6549b = value;
    }

    public void setName(String name) {
        this.f6548a = name;
    }

    public String getName() {
        return this.f6548a;
    }

    public void setValue(String value) {
        this.f6549b = value;
    }

    public String getValue() {
        return this.f6549b;
    }

    public String toString() {
        return new StringBuffer().append("name=").append(this.f6548a).append(", ").append("value=").append(this.f6549b).toString();
    }

    public boolean equals(Object object) {
        if (object == null) {
            return false;
        }
        if (this == object) {
            return true;
        }
        if (!(object instanceof NameValuePair)) {
            return false;
        }
        NameValuePair that = (NameValuePair) object;
        return LangUtils.equals(this.f6548a, that.f6548a) && LangUtils.equals(this.f6549b, that.f6549b);
    }

    public int hashCode() {
        int hash = LangUtils.hashCode(17, this.f6548a);
        return LangUtils.hashCode(hash, this.f6549b);
    }
}
