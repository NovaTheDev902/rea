package com.lenovo.safecenter.utils.httpApi;

import android.content.Context;
import android.os.AsyncTask;
import android.util.Log;
import com.lenovo.safecenter.AppsManager.DownApkManager;
import com.lenovo.safecenter.utils.WflUtils;
import java.io.IOException;
import org.apache.commons.httpclient.params.HttpConnectionParams;
import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;

/* JADX INFO: loaded from: classes.dex */
public class HttpApiAsyncTask extends AsyncTask<Void, Void, Object> {
    public static final int BUSSINESS_ERROR = 610;
    public static final int TIMEOUT_ERROR = 600;

    /* JADX INFO: renamed from: a */
    private Context f5828a;

    /* JADX INFO: renamed from: b */
    private int f5829b;

    /* JADX INFO: renamed from: c */
    private ApiRequestListener f5830c;

    /* JADX INFO: renamed from: d */
    private Object f5831d;

    /* JADX INFO: renamed from: e */
    private DefaultHttpClient f5832e = new DefaultHttpClient();

    public interface ApiRequestListener {
        void onError(int i, int i2);

        void onSuccess(int i, Object obj);
    }

    public HttpApiAsyncTask(Context context, int action, ApiRequestListener listener, Object params) {
        this.f5828a = context;
        this.f5829b = action;
        this.f5830c = listener;
        this.f5831d = params;
        this.f5832e.getParams().setParameter(HttpConnectionParams.CONNECTION_TIMEOUT, 5000);
        this.f5832e.getParams().setParameter("http.socket.timeout", 5000);
    }

    /* JADX INFO: Access modifiers changed from: protected */
    @Override // android.os.AsyncTask
    public Object doInBackground(Void... params) {
        Object result;
        if (!WflUtils.isNetworkAvailable(this.f5828a)) {
            Log.i("wu0wu", "<<<HttpApiAsyncTask doInBackground no net can used...>>>");
            return null;
        }
        if (this.f5829b == 999) {
            DownApkManager.parseNewApk(this.f5828a);
            DownApkManager.praseTop100(this.f5828a);
            return Integer.valueOf(this.f5829b);
        }
        Log.i("wu0wu", "<<<HttpApiAsyncTask doInBackground >>> mRequestAction=" + this.f5829b);
        String requestUrl = LeSafeAPI.API_URLS[this.f5829b];
        HttpEntity requestEntity = ApiRequestFactory.getRequestEntity(this.f5828a, this.f5829b, this.f5831d);
        HttpGet request = ApiRequestFactory.getRequest(requestUrl, this.f5829b, requestEntity, this.f5831d);
        try {
            Log.i("wu0wu", "<<<HttpApiAsyncTask doInBackground >>> start mClient.execute ");
            HttpResponse response = this.f5832e.execute(request);
            int statusCode = response.getStatusLine().getStatusCode();
            Log.i("wu0wu", "<<<HttpApiAsyncTask doInBackground >>> requestUrl " + requestUrl + " statusCode: " + statusCode);
            if (200 != statusCode) {
                result = Integer.valueOf(statusCode);
            } else {
                result = ApiResponseFactory.getResponse(this.f5828a, this.f5829b, response);
            }
            return result;
        } catch (ClientProtocolException e) {
            e.printStackTrace();
            return 600;
        } catch (IOException e2) {
            e2.printStackTrace();
            return 600;
        }
    }

    @Override // android.os.AsyncTask
    protected void onPostExecute(Object result) {
        if (this.f5830c != null) {
            if (result == null) {
                this.f5830c.onError(this.f5829b, BUSSINESS_ERROR);
                return;
            }
            if (result instanceof Integer) {
                Integer statusCode = (Integer) result;
                if (this.f5829b == 0) {
                    if (statusCode.intValue() != 304) {
                        this.f5830c.onError(this.f5829b, statusCode.intValue());
                        return;
                    }
                } else if (statusCode.intValue() != 200) {
                    this.f5830c.onError(this.f5829b, statusCode.intValue());
                    return;
                }
            }
            this.f5830c.onSuccess(this.f5829b, result);
            super.onPostExecute(result);
        }
    }
}
