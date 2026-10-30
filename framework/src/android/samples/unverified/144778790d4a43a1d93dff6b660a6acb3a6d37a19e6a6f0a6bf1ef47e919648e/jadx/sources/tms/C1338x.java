package tms;

import android.os.Bundle;
import org.apache.http.HttpHost;
import org.apache.http.client.HttpClient;
import org.apache.http.client.params.HttpClientParams;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.params.BasicHttpParams;
import org.apache.http.params.HttpConnectionParams;
import org.apache.http.params.HttpParams;

/* JADX INFO: renamed from: tms.x */
/* JADX INFO: loaded from: classes.dex */
public class C1338x {

    /* JADX INFO: renamed from: a */
    protected static final String f7488a = "HttpBase";

    /* JADX INFO: renamed from: b */
    protected static final int f7489b = 10000;

    /* JADX INFO: renamed from: c */
    protected static final int f7490c = 20000;

    /* JADX INFO: renamed from: d */
    protected static final int f7491d = 4096;

    /* JADX INFO: renamed from: e */
    public static final String f7492e = "key_errcode";

    /* JADX INFO: renamed from: f */
    public static final String f7493f = "key_total";

    /* JADX INFO: renamed from: g */
    public static final String f7494g = "key_completed";

    /* JADX INFO: renamed from: i */
    protected static final int f7495i = 1;

    /* JADX INFO: renamed from: j */
    protected static final int f7496j = 2;

    /* JADX INFO: renamed from: h */
    protected HttpParams f7497h = null;

    /* JADX INFO: renamed from: l */
    private boolean f7499l = false;

    /* JADX INFO: renamed from: m */
    private String f7500m = null;

    /* JADX INFO: renamed from: n */
    private int f7501n = 0;

    /* JADX INFO: renamed from: k */
    protected a f7498k = null;

    /* JADX INFO: renamed from: tms.x$a */
    public interface a {
        /* JADX INFO: renamed from: a */
        void mo3343a(Bundle bundle);

        /* JADX INFO: renamed from: b */
        void mo3344b(Bundle bundle);
    }

    /* JADX INFO: renamed from: a */
    protected HttpClient m3618a() {
        if (this.f7497h == null) {
            this.f7497h = new BasicHttpParams();
        }
        HttpConnectionParams.setConnectionTimeout(this.f7497h, 10000);
        HttpConnectionParams.setSoTimeout(this.f7497h, 20000);
        HttpConnectionParams.setSocketBufferSize(this.f7497h, 4096);
        HttpClientParams.setRedirecting(this.f7497h, true);
        DefaultHttpClient defaultHttpClient = new DefaultHttpClient(this.f7497h);
        if (this.f7499l) {
            defaultHttpClient.getParams().setParameter("http.route.default-proxy", new HttpHost(this.f7500m, this.f7501n));
        }
        return defaultHttpClient;
    }

    /* JADX INFO: renamed from: a */
    protected void m3619a(int i, Bundle bundle) {
        if (this.f7498k != null) {
            if (i == 1) {
                this.f7498k.mo3343a(bundle);
            } else if (i == 2) {
                this.f7498k.mo3344b(bundle);
            }
        }
    }

    /* JADX INFO: renamed from: a */
    public void m3620a(String str, int i) {
        this.f7500m = str;
        this.f7501n = i;
    }

    /* JADX INFO: renamed from: a */
    public void m3621a(a aVar) {
        this.f7498k = aVar;
    }

    /* JADX INFO: renamed from: a */
    public void m3622a(boolean z) {
        this.f7499l = z;
    }
}
