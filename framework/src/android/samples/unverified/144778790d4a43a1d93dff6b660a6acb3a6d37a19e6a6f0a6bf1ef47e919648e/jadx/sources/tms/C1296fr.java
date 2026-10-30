package tms;

import android.webkit.WebChromeClient;
import android.webkit.WebView;
import com.tencent.tmsecure.utils.WifiUtil;

/* JADX INFO: renamed from: tms.fr */
/* JADX INFO: loaded from: classes.dex */
final class C1296fr extends WebChromeClient {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ WebView f7368a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ HandlerC1320hg f7369b;

    C1296fr(HandlerC1320hg handlerC1320hg, WebView webView) {
        this.f7369b = handlerC1320hg;
        this.f7368a = webView;
    }

    @Override // android.webkit.WebChromeClient
    public final void onReceivedTitle(WebView webView, String str) {
        if (str == null || !str.contains("百度")) {
            WifiUtil.sRedirectLocation = webView.getUrl();
            if (WifiUtil.sRedirectLocation == null || WifiUtil.sRedirectLocation.length() == 0) {
                WifiUtil.sRedirectLocation = WifiUtil.TEST_URL;
            }
            this.f7369b.f7448a.onWifiApproveCheckFinished(true, false);
        } else {
            this.f7369b.f7448a.onWifiApproveCheckFinished(false, false);
        }
        this.f7368a.setWebViewClient(null);
        this.f7368a.setWebChromeClient(null);
        this.f7368a.stopLoading();
        this.f7368a.clearCache(true);
        this.f7368a.destroy();
    }
}
