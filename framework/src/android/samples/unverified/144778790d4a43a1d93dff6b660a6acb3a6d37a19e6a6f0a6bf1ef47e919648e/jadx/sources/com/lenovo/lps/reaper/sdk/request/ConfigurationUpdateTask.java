package com.lenovo.lps.reaper.sdk.request;

import com.lenovo.lps.reaper.sdk.config.Configuration;
import com.lenovo.lps.reaper.sdk.storage.ServerConfigStorage;
import com.lenovo.lps.reaper.sdk.util.Constants;
import com.lenovo.lps.reaper.sdk.util.TLog;
import com.lenovo.lps.sus.p008c.C0092c;
import java.net.URI;
import java.util.Iterator;
import org.apache.commons.httpclient.params.HttpConnectionParams;
import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.params.BasicHttpParams;
import org.apache.http.params.HttpParams;
import org.apache.http.util.EntityUtils;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

/* JADX INFO: loaded from: classes.dex */
public final class ConfigurationUpdateTask implements Runnable {

    /* JADX INFO: renamed from: a */
    private final Configuration f1138a;

    public ConfigurationUpdateTask(Configuration configuration) {
        this.f1138a = configuration;
    }

    @Override // java.lang.Runnable
    public final void run() {
        boolean z = false;
        if (this.f1138a.getServerConfigUrl() == null) {
            TLog.m245w("ConfigurationUpdateTask", "server url is null.");
        } else if (!this.f1138a.isCollectData()) {
            TLog.m243i("ConfigurationUpdateTask", "data collection setting is false.");
        } else if (!ServerConfigStorage.DispatchStrategy.readyForReport(Constants.DispatchMode.NORMAL_DISPATCH)) {
            TLog.m243i("ConfigurationUpdateTask", "network is not ok.");
        } else if (this.f1138a.checkTimestamp()) {
            z = true;
        }
        if (z) {
            HttpParams httpParams = new BasicHttpParams();
            httpParams.setParameter(HttpConnectionParams.CONNECTION_TIMEOUT, 6000);
            httpParams.setParameter("http.socket.timeout", 6000);
            HttpClient httpclient = new DefaultHttpClient();
            try {
                HttpGet httpGet = new HttpGet();
                httpGet.setURI(URI.create(String.format("%s?tk=%s%s", this.f1138a.getServerConfigUrl(), this.f1138a.getApplicationToken(), this.f1138a.getDeviceInfo())));
                httpGet.addHeader(Constants.Http.HTTP_HEADER_USER_AGENT, this.f1138a.getUserAgent());
                httpGet.addHeader(Constants.Http.HTTP_HEADER_HOST, this.f1138a.getReaperServerHost());
                httpGet.setParams(httpParams);
                HttpResponse response = httpclient.execute(httpGet);
                int code = response.getStatusLine().getStatusCode();
                if (code == 200) {
                    String result = EntityUtils.toString(response.getEntity());
                    m215a(result);
                    this.f1138a.saveUpdateTimestamp();
                    TLog.m240d("ConfigurationUpdateTask", "ConfigUpdate Success: " + result);
                } else {
                    TLog.m245w("ConfigurationUpdateTask", new StringBuilder(64).append("Get configuration fail, status code: ").append(code).toString());
                }
            } catch (Exception e) {
                TLog.m245w("ConfigurationUpdateTask", "Get configuration fail. " + e.getMessage());
            } finally {
                httpclient.getConnectionManager().shutdown();
            }
        }
    }

    /* JADX INFO: renamed from: a */
    private void m215a(String result) {
        try {
            JSONArray array = new JSONArray(result);
            int length = array.length();
            this.f1138a.clearExistPreference();
            TLog.m240d("ConfigurationUpdateTask", "Configuration Update: ");
            for (int i = 0; i < length; i++) {
                JSONObject tmpObject = array.getJSONObject(i);
                String category = tmpObject.getString("Category");
                JSONObject actionJsonObject = tmpObject.getJSONObject("Action");
                String[] actions = new String[actionJsonObject.length()];
                boolean[] values = new boolean[actionJsonObject.length()];
                int index = 0;
                Iterator<String> iterator = actionJsonObject.keys();
                while (iterator.hasNext()) {
                    String action = iterator.next();
                    actions[index] = action;
                    values[index] = actionJsonObject.getBoolean(action);
                    if (TLog.isTestMode()) {
                        TLog.m240d("ConfigurationUpdateTask", actions[index] + C0092c.f1283N + values[index]);
                    }
                    index++;
                }
                if (!this.f1138a.updatePrefrence(category, actions, values)) {
                    TLog.m241e("ConfigurationUpdateTask", "process response fail. ");
                }
            }
        } catch (JSONException e) {
            TLog.m241e("ConfigurationUpdateTask", "process response fail. " + e.getMessage());
        }
    }
}
