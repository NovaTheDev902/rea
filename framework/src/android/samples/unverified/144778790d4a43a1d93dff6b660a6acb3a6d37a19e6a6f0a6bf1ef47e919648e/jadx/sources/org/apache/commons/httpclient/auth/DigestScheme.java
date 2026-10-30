package org.apache.commons.httpclient.auth;

import com.lenovo.lps.sus.p008c.C0092c;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import org.apache.commons.httpclient.Credentials;
import org.apache.commons.httpclient.HttpClientError;
import org.apache.commons.httpclient.HttpMethod;
import org.apache.commons.httpclient.NameValuePair;
import org.apache.commons.httpclient.UsernamePasswordCredentials;
import org.apache.commons.httpclient.util.EncodingUtil;
import org.apache.commons.httpclient.util.ParameterFormatter;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class DigestScheme extends RFC2617Scheme {

    /* JADX INFO: renamed from: a */
    static Class f6596a;

    /* JADX INFO: renamed from: b */
    private static final Log f6597b;

    /* JADX INFO: renamed from: c */
    private static final char[] f6598c;

    /* JADX INFO: renamed from: d */
    private boolean f6599d;

    /* JADX INFO: renamed from: e */
    private int f6600e;

    /* JADX INFO: renamed from: f */
    private String f6601f;

    /* JADX INFO: renamed from: g */
    private final ParameterFormatter f6602g;

    static {
        Class clsM2765a;
        if (f6596a == null) {
            clsM2765a = m2765a("org.apache.commons.httpclient.auth.DigestScheme");
            f6596a = clsM2765a;
        } else {
            clsM2765a = f6596a;
        }
        f6597b = LogFactory.getLog(clsM2765a);
        f6598c = new char[]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    }

    /* JADX INFO: renamed from: a */
    private static Class m2765a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public DigestScheme() {
        this.f6600e = 0;
        this.f6599d = false;
        this.f6602g = new ParameterFormatter();
    }

    @Override // org.apache.commons.httpclient.auth.RFC2617Scheme, org.apache.commons.httpclient.auth.AuthScheme
    public String getID() {
        String id = getRealm();
        String nonce = getParameter("nonce");
        if (nonce != null) {
            return new StringBuffer().append(id).append("-").append(nonce).toString();
        }
        return id;
    }

    public DigestScheme(String challenge) throws MalformedChallengeException {
        this();
        processChallenge(challenge);
    }

    @Override // org.apache.commons.httpclient.auth.RFC2617Scheme, org.apache.commons.httpclient.auth.AuthScheme
    public void processChallenge(String challenge) throws MalformedChallengeException {
        super.processChallenge(challenge);
        if (getParameter("realm") == null) {
            throw new MalformedChallengeException("missing realm in challange");
        }
        if (getParameter("nonce") == null) {
            throw new MalformedChallengeException("missing nonce in challange");
        }
        boolean unsupportedQop = false;
        String qop = getParameter("qop");
        if (qop != null) {
            StringTokenizer tok = new StringTokenizer(qop, ",");
            while (tok.hasMoreTokens()) {
                String variant = tok.nextToken().trim();
                if (variant.equals("auth")) {
                    this.f6600e = 2;
                    break;
                } else if (variant.equals("auth-int")) {
                    this.f6600e = 1;
                } else {
                    unsupportedQop = true;
                    f6597b.warn(new StringBuffer().append("Unsupported qop detected: ").append(variant).toString());
                }
            }
        }
        if (unsupportedQop && this.f6600e == 0) {
            throw new MalformedChallengeException("None of the qop methods is supported");
        }
        this.f6601f = createCnonce();
        this.f6599d = true;
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public boolean isComplete() {
        String s = getParameter("stale");
        if ("true".equalsIgnoreCase(s)) {
            return false;
        }
        return this.f6599d;
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public String getSchemeName() {
        return "digest";
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public boolean isConnectionBased() {
        return false;
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public String authenticate(Credentials credentials, String method, String uri) throws AuthenticationException {
        f6597b.trace("enter DigestScheme.authenticate(Credentials, String, String)");
        try {
            UsernamePasswordCredentials usernamepassword = (UsernamePasswordCredentials) credentials;
            getParameters().put("methodname", method);
            getParameters().put("uri", uri);
            String digest = m2767a(usernamepassword.getUserName(), usernamepassword.getPassword());
            return new StringBuffer().append("Digest ").append(m2769b(usernamepassword.getUserName(), digest)).toString();
        } catch (ClassCastException e) {
            throw new InvalidCredentialsException(new StringBuffer().append("Credentials cannot be used for digest authentication: ").append(credentials.getClass().getName()).toString());
        }
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public String authenticate(Credentials credentials, HttpMethod method) throws AuthenticationException {
        f6597b.trace("enter DigestScheme.authenticate(Credentials, HttpMethod)");
        try {
            UsernamePasswordCredentials usernamepassword = (UsernamePasswordCredentials) credentials;
            getParameters().put("methodname", method.getName());
            StringBuffer buffer = new StringBuffer(method.getPath());
            String query = method.getQueryString();
            if (query != null) {
                if (query.indexOf("?") != 0) {
                    buffer.append("?");
                }
                buffer.append(method.getQueryString());
            }
            getParameters().put("uri", buffer.toString());
            String charset = getParameter("charset");
            if (charset == null) {
                getParameters().put("charset", method.getParams().getCredentialCharset());
            }
            String digest = m2767a(usernamepassword.getUserName(), usernamepassword.getPassword());
            return new StringBuffer().append("Digest ").append(m2769b(usernamepassword.getUserName(), digest)).toString();
        } catch (ClassCastException e) {
            throw new InvalidCredentialsException(new StringBuffer().append("Credentials cannot be used for digest authentication: ").append(credentials.getClass().getName()).toString());
        }
    }

    /* JADX INFO: renamed from: a */
    private String m2767a(String uname, String pwd) throws AuthenticationException {
        String serverDigestValue;
        f6597b.trace("enter DigestScheme.createDigest(String, String, Map)");
        String uri = getParameter("uri");
        String realm = getParameter("realm");
        String nonce = getParameter("nonce");
        String qop = getParameter("qop");
        String method = getParameter("methodname");
        String algorithm = getParameter("algorithm");
        if (algorithm == null) {
            algorithm = "MD5";
        }
        String charset = getParameter("charset");
        if (charset == null) {
            charset = "ISO-8859-1";
        }
        if (this.f6600e == 1) {
            f6597b.warn("qop=auth-int is not supported");
            throw new AuthenticationException("Unsupported qop in HTTP Digest authentication");
        }
        try {
            MessageDigest md5Helper = MessageDigest.getInstance("MD5");
            StringBuffer tmp = new StringBuffer(uname.length() + realm.length() + pwd.length() + 2);
            tmp.append(uname);
            tmp.append(':');
            tmp.append(realm);
            tmp.append(':');
            tmp.append(pwd);
            String a1 = tmp.toString();
            if (algorithm.equals("MD5-sess")) {
                String tmp2 = m2768a(md5Helper.digest(EncodingUtil.getBytes(a1, charset)));
                StringBuffer tmp3 = new StringBuffer(tmp2.length() + nonce.length() + this.f6601f.length() + 2);
                tmp3.append(tmp2);
                tmp3.append(':');
                tmp3.append(nonce);
                tmp3.append(':');
                tmp3.append(this.f6601f);
                a1 = tmp3.toString();
            } else if (!algorithm.equals("MD5")) {
                f6597b.warn(new StringBuffer().append("Unhandled algorithm ").append(algorithm).append(" requested").toString());
            }
            String md5a1 = m2768a(md5Helper.digest(EncodingUtil.getBytes(a1, charset)));
            String a2 = null;
            if (this.f6600e == 1) {
                f6597b.error("Unhandled qop auth-int");
            } else {
                a2 = new StringBuffer().append(method).append(C0092c.f1283N).append(uri).toString();
            }
            String md5a2 = m2768a(md5Helper.digest(EncodingUtil.getAsciiBytes(a2)));
            if (this.f6600e == 0) {
                f6597b.debug("Using null qop method");
                StringBuffer tmp4 = new StringBuffer(md5a1.length() + nonce.length() + md5a2.length());
                tmp4.append(md5a1);
                tmp4.append(':');
                tmp4.append(nonce);
                tmp4.append(':');
                tmp4.append(md5a2);
                serverDigestValue = tmp4.toString();
            } else {
                if (f6597b.isDebugEnabled()) {
                    f6597b.debug(new StringBuffer().append("Using qop method ").append(qop).toString());
                }
                String qopOption = m2766a();
                StringBuffer tmp5 = new StringBuffer(md5a1.length() + nonce.length() + "00000001".length() + this.f6601f.length() + qopOption.length() + md5a2.length() + 5);
                tmp5.append(md5a1);
                tmp5.append(':');
                tmp5.append(nonce);
                tmp5.append(':');
                tmp5.append("00000001");
                tmp5.append(':');
                tmp5.append(this.f6601f);
                tmp5.append(':');
                tmp5.append(qopOption);
                tmp5.append(':');
                tmp5.append(md5a2);
                serverDigestValue = tmp5.toString();
            }
            String serverDigest = m2768a(md5Helper.digest(EncodingUtil.getAsciiBytes(serverDigestValue)));
            return serverDigest;
        } catch (Exception e) {
            throw new AuthenticationException("Unsupported algorithm in HTTP Digest authentication: MD5");
        }
    }

    /* JADX INFO: renamed from: b */
    private String m2769b(String uname, String digest) throws AuthenticationException {
        f6597b.trace("enter DigestScheme.createDigestHeader(String, Map, String)");
        String uri = getParameter("uri");
        String realm = getParameter("realm");
        String nonce = getParameter("nonce");
        String opaque = getParameter("opaque");
        String algorithm = getParameter("algorithm");
        List params = new ArrayList(20);
        params.add(new NameValuePair("username", uname));
        params.add(new NameValuePair("realm", realm));
        params.add(new NameValuePair("nonce", nonce));
        params.add(new NameValuePair("uri", uri));
        params.add(new NameValuePair("response", digest));
        if (this.f6600e != 0) {
            params.add(new NameValuePair("qop", m2766a()));
            params.add(new NameValuePair("nc", "00000001"));
            params.add(new NameValuePair("cnonce", this.f6601f));
        }
        if (algorithm != null) {
            params.add(new NameValuePair("algorithm", algorithm));
        }
        if (opaque != null) {
            params.add(new NameValuePair("opaque", opaque));
        }
        StringBuffer buffer = new StringBuffer();
        for (int i = 0; i < params.size(); i++) {
            NameValuePair param = (NameValuePair) params.get(i);
            if (i > 0) {
                buffer.append(", ");
            }
            boolean noQuotes = "nc".equals(param.getName()) || "qop".equals(param.getName());
            this.f6602g.setAlwaysUseQuotes(!noQuotes);
            this.f6602g.format(buffer, param);
        }
        return buffer.toString();
    }

    /* JADX INFO: renamed from: a */
    private String m2766a() {
        if (this.f6600e == 1) {
            return "auth-int";
        }
        return "auth";
    }

    /* JADX INFO: renamed from: a */
    private static String m2768a(byte[] binaryData) {
        f6597b.trace("enter DigestScheme.encode(byte[])");
        if (binaryData.length != 16) {
            return null;
        }
        char[] buffer = new char[32];
        for (int i = 0; i < 16; i++) {
            int low = binaryData[i] & 15;
            int high = (binaryData[i] & 240) >> 4;
            buffer[i * 2] = f6598c[high];
            buffer[(i * 2) + 1] = f6598c[low];
        }
        return new String(buffer);
    }

    public static String createCnonce() {
        f6597b.trace("enter DigestScheme.createCnonce()");
        try {
            MessageDigest md5Helper = MessageDigest.getInstance("MD5");
            String cnonce = Long.toString(System.currentTimeMillis());
            return m2768a(md5Helper.digest(EncodingUtil.getAsciiBytes(cnonce)));
        } catch (NoSuchAlgorithmException e) {
            throw new HttpClientError("Unsupported algorithm in HTTP Digest authentication: MD5");
        }
    }
}
