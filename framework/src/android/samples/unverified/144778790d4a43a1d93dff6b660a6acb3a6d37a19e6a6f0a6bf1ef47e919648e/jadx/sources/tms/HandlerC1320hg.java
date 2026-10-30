package tms;

import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.webkit.WebSettings;
import android.webkit.WebView;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.utils.WifiUtil;

/* JADX INFO: renamed from: tms.hg */
/* JADX INFO: loaded from: classes.dex */
public final class HandlerC1320hg extends Handler {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ WifiUtil.IWifiApproveCheckCallBack f7448a;

    /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
    public HandlerC1320hg(Looper looper, WifiUtil.IWifiApproveCheckCallBack iWifiApproveCheckCallBack) {
        super(looper);
        this.f7448a = iWifiApproveCheckCallBack;
    }

    @Override // android.os.Handler
    public final void handleMessage(Message message) {
        WebView webView = new WebView(TMSApplication.getApplicaionContext());
        WebSettings settings = webView.getSettings();
        settings.setJavaScriptEnabled(true);
        settings.setPluginsEnabled(true);
        webView.loadUrl(WifiUtil.TEST_URL);
        webView.setWebViewClient(new C1295fq(this, webView));
        webView.setWebChromeClient(new C1296fr(this, webView));
    }
}
