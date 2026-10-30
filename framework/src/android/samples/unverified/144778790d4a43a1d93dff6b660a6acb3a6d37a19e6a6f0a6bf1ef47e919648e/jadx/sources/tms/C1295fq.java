package tms;

import android.webkit.WebView;
import android.webkit.WebViewClient;
import com.tencent.tmsecure.utils.WifiUtil;

/* JADX INFO: renamed from: tms.fq */
/* JADX INFO: loaded from: classes.dex */
final class C1295fq extends WebViewClient {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ WebView f7366a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ HandlerC1320hg f7367b;

    C1295fq(HandlerC1320hg handlerC1320hg, WebView webView) {
        this.f7367b = handlerC1320hg;
        this.f7366a = webView;
    }

    @Override // android.webkit.WebViewClient
    public final void onReceivedError(WebView webView, int i, String str, String str2) {
        super.onReceivedError(webView, i, str, str2);
        WifiUtil.sRedirectLocation = WifiUtil.TEST_URL;
        this.f7367b.f7448a.onWifiApproveCheckFinished(false, true);
        this.f7366a.setWebViewClient(null);
        this.f7366a.setWebChromeClient(null);
        this.f7366a.stopLoading();
        this.f7366a.clearCache(true);
        this.f7366a.destroy();
    }

    @Override // android.webkit.WebViewClient
    public final boolean shouldOverrideUrlLoading(WebView webView, String str) {
        if (str.contains(".baidu.")) {
            this.f7367b.f7448a.onWifiApproveCheckFinished(false, false);
        } else {
            WifiUtil.sRedirectLocation = str;
            this.f7367b.f7448a.onWifiApproveCheckFinished(true, false);
        }
        this.f7366a.setWebViewClient(null);
        this.f7366a.setWebChromeClient(null);
        this.f7366a.stopLoading();
        this.f7366a.clearCache(true);
        this.f7366a.destroy();
        return true;
    }
}
