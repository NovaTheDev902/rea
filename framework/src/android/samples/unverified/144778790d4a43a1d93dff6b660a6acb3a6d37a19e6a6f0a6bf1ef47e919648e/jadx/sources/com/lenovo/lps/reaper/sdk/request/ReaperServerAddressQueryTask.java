package com.lenovo.lps.reaper.sdk.request;

import android.os.Handler;
import android.util.Xml;
import com.lenovo.lps.reaper.sdk.config.Configuration;
import com.lenovo.lps.reaper.sdk.storage.ServerConfigStorage;
import com.lenovo.lps.reaper.sdk.util.Constants;
import com.lenovo.lps.reaper.sdk.util.TLog;
import java.util.ArrayList;
import java.util.List;
import org.apache.commons.httpclient.params.HttpConnectionParams;
import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.params.BasicHttpParams;
import org.apache.http.params.HttpParams;
import org.apache.http.util.EntityUtils;
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

/* JADX INFO: loaded from: classes.dex */
public final class ReaperServerAddressQueryTask implements Runnable {

    /* JADX INFO: renamed from: a */
    private final Configuration f1140a;

    public ReaperServerAddressQueryTask(Configuration configuration, Handler handler) {
        this.f1140a = configuration;
    }

    public ReaperServerAddressQueryTask(Configuration configuration) {
        this.f1140a = configuration;
    }

    @Override // java.lang.Runnable
    public final void run() {
        boolean z = false;
        if (this.f1140a.getCustomReaperServer() != null && this.f1140a.getCustomReaperServer().length() > 0) {
            TLog.m240d("ReaperServerAddressQueryTask", "Using Custom ReaperServerAddress.");
        } else if (!this.f1140a.isCollectData()) {
            TLog.m243i("ReaperServerAddressQueryTask", "data collection setting is false.");
            this.f1140a.initReportAndConfigurationUrl("http://fsr.lenovomm.com");
        } else if (!ServerConfigStorage.DispatchStrategy.readyForReport(Constants.DispatchMode.NORMAL_DISPATCH)) {
            TLog.m243i("ReaperServerAddressQueryTask", "network is not ok.");
            this.f1140a.initReportAndConfigurationUrl("http://fsr.lenovomm.com");
        } else if (this.f1140a.checkTimestamp()) {
            z = true;
        } else {
            String serverUrlFromFile = this.f1140a.getServerUrlFromFile();
            if (serverUrlFromFile == null || serverUrlFromFile.length() <= 0) {
                TLog.m243i("ReaperServerAddressQueryTask", "CheckTimestamp is not pass, use default ReaperServerAddress.");
                this.f1140a.initReportAndConfigurationUrl("http://fsr.lenovomm.com");
            } else {
                TLog.m243i("ReaperServerAddressQueryTask", "Load ReaperServerAddress From SharedPreference. : " + serverUrlFromFile);
                this.f1140a.initReportAndConfigurationUrl(serverUrlFromFile);
            }
        }
        if (z) {
            HttpParams httpParams = new BasicHttpParams();
            httpParams.setParameter(HttpConnectionParams.CONNECTION_TIMEOUT, 6000);
            httpParams.setParameter("http.socket.timeout", 6000);
            HttpGet httpGet = new HttpGet("http://lds.lenovomm.com/addr/1.0/query?sid=rfsr001&didt=1");
            httpGet.setParams(httpParams);
            boolean queryResult = false;
            HttpClient httpclient = new DefaultHttpClient();
            try {
                HttpResponse response = httpclient.execute(httpGet);
                int code = response.getStatusLine().getStatusCode();
                if (code == 200) {
                    String result = EntityUtils.toString(response.getEntity());
                    queryResult = m217a(result);
                } else {
                    TLog.m245w("ReaperServerAddressQueryTask", new StringBuilder(64).append("query reaper server address fail, status code: ").append(code).toString());
                }
                TLog.m240d("ReaperServerAddressQueryTask", "ServerAddress Query Success: " + queryResult);
            } catch (Exception e) {
                TLog.m241e("ReaperServerAddressQueryTask", "query reaper server address fail. " + e.getMessage());
            } finally {
                httpclient.getConnectionManager().shutdown();
            }
            if (!queryResult) {
                this.f1140a.initReportAndConfigurationUrl("http://fsr.lenovomm.com");
            }
        }
    }

    /* JADX INFO: renamed from: a */
    private boolean m217a(String result) {
        C0075a ldsResponseHandler = new C0075a();
        try {
            Xml.parse(result, ldsResponseHandler);
            TLog.m243i("ReaperServerAddressQueryTask", String.valueOf(ldsResponseHandler.m219b()));
            TLog.m243i("ReaperServerAddressQueryTask", ldsResponseHandler.m218a().toString());
            ldsResponseHandler.m219b();
            List<String> listM218a = ldsResponseHandler.m218a();
            if (listM218a != null) {
                if (listM218a.size() == 1) {
                    this.f1140a.initReportAndConfigurationUrl(listM218a.get(0));
                    this.f1140a.saveServerUrlToFile(listM218a.get(0));
                    return true;
                }
                if (listM218a.size() > 1) {
                    int size = (int) (((double) listM218a.size()) * Math.random());
                    this.f1140a.initReportAndConfigurationUrl(listM218a.get(size));
                    this.f1140a.saveServerUrlToFile(listM218a.get(size));
                    return true;
                }
                TLog.m245w("ReaperServerAddressQueryTask", "don't get reaper server url from lds.");
            }
            return false;
        } catch (Exception e) {
            TLog.m241e("ReaperServerAddressQueryTask", "processResponseResult fail. " + e.getMessage());
            return false;
        }
    }

    /* JADX INFO: renamed from: com.lenovo.lps.reaper.sdk.request.ReaperServerAddressQueryTask$a */
    class C0075a extends DefaultHandler {

        /* JADX INFO: renamed from: b */
        private List<String> f1142b;

        /* JADX INFO: renamed from: c */
        private long f1143c;

        /* JADX INFO: renamed from: d */
        private StringBuilder f1144d;

        C0075a() {
        }

        /* JADX INFO: renamed from: a */
        public final List<String> m218a() {
            return this.f1142b;
        }

        /* JADX INFO: renamed from: b */
        public final long m219b() {
            return this.f1143c;
        }

        @Override // org.xml.sax.helpers.DefaultHandler, org.xml.sax.ContentHandler
        public final void characters(char[] ch, int start, int length) throws SAXException {
            super.characters(ch, start, length);
            this.f1144d.append(ch, start, length);
        }

        @Override // org.xml.sax.helpers.DefaultHandler, org.xml.sax.ContentHandler
        public final void endElement(String uri, String localName, String name) throws SAXException {
            super.endElement(uri, localName, name);
            if (localName.equalsIgnoreCase("Address")) {
                this.f1142b.add(this.f1144d.toString());
            } else if (localName.equalsIgnoreCase("TTL")) {
                this.f1143c = Long.parseLong(this.f1144d.toString());
            }
            this.f1144d.setLength(0);
        }

        @Override // org.xml.sax.helpers.DefaultHandler, org.xml.sax.ContentHandler
        public final void startDocument() throws SAXException {
            super.startDocument();
            this.f1142b = new ArrayList(1);
            this.f1144d = new StringBuilder();
        }

        @Override // org.xml.sax.helpers.DefaultHandler, org.xml.sax.ContentHandler
        public final void startElement(String uri, String localName, String name, Attributes attributes) throws SAXException {
            super.startElement(uri, localName, name, attributes);
        }
    }
}
