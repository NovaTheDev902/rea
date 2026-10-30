package com.lenovo.feedback2.agent;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Rect;
import android.os.RemoteException;
import android.util.Log;
import android.view.View;
import com.lenovo.feedback2.message.BasicMessageBuilder;
import com.lenovo.feedback2.message.Message;
import com.lenovo.feedback2.message.protocol.V_1;
import com.lenovo.feedback2.service.IFeedBackService;
import java.io.ByteArrayOutputStream;

/* JADX INFO: loaded from: classes.dex */
public class ScreenShotHandler implements Runnable {

    /* JADX INFO: renamed from: a */
    private static String f946a = "FeedBackAgent";

    /* JADX INFO: renamed from: b */
    private C0048a f947b = new C0048a();

    /* JADX INFO: renamed from: c */
    private AgentContext f948c;

    /* JADX INFO: renamed from: d */
    private long f949d;

    public ScreenShotHandler(AgentContext agentContext, long id) {
        this.f948c = agentContext;
        this.f949d = id;
    }

    @Override // java.lang.Runnable
    public void run() {
        try {
            Context context = this.f948c.getContext();
            if (context == null) {
                Log.e(f946a, "ScreenShotHandler::run null context");
                return;
            }
            IFeedBackService feedbackService = this.f948c.getFeedBackService();
            if (feedbackService == null) {
                Log.e(f946a, "ScreenShotHandler::run null feedbackService");
                return;
            }
            String packageName = context.getApplicationInfo().packageName;
            Thread.sleep(500L);
            int count = 0;
            while (true) {
                C0048a c0048a = this.f947b;
                View decorView = C0048a.m137a(this.f947b.m138a());
                if (decorView != null) {
                    Log.i(f946a, "get a decorView in " + packageName);
                    RunnableC0047a handler = new RunnableC0047a(decorView, packageName, context);
                    decorView.post(handler);
                    return;
                } else if (count > 1) {
                    Log.i(f946a, "null decorView in " + packageName);
                    return;
                } else {
                    Thread.sleep(1000L);
                    count++;
                }
            }
        } catch (Exception e) {
            Log.e(f946a, "ScreenShotHandler::run catch exception", e);
        }
    }

    /* JADX INFO: renamed from: com.lenovo.feedback2.agent.ScreenShotHandler$a */
    private class RunnableC0047a implements Runnable {

        /* JADX INFO: renamed from: b */
        private View f951b;

        /* JADX INFO: renamed from: c */
        private String f952c;

        /* JADX INFO: renamed from: d */
        private Context f953d;

        public RunnableC0047a(View view, String packageName, Context context) {
            this.f951b = view;
            this.f952c = packageName;
            this.f953d = context;
        }

        @Override // java.lang.Runnable
        public final void run() {
            try {
                View view = this.f951b;
                String str = this.f952c;
                Log.i(ScreenShotHandler.f946a, "ViewCacheHandler take screen shot");
                view.destroyDrawingCache();
                view.buildDrawingCache(false);
                try {
                    Bitmap drawingCache = this.f951b.getDrawingCache();
                    int width = drawingCache.getWidth();
                    int height = drawingCache.getHeight();
                    int width2 = this.f951b.getWidth();
                    int height2 = this.f951b.getHeight();
                    if (height >= height2 && width >= width2) {
                        Rect rect = new Rect();
                        this.f951b.getWindowVisibleDisplayFrame(rect);
                        int i = rect.top;
                        drawingCache = Bitmap.createBitmap(drawingCache, 0, i, width2, height2 - i);
                    }
                    Log.i(ScreenShotHandler.f946a, "ViewCacheHandler compress begin");
                    ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
                    if (drawingCache.compress(Bitmap.CompressFormat.PNG, 100, byteArrayOutputStream)) {
                        byte[] byteArray = byteArrayOutputStream.toByteArray();
                        ApplicationInfo applicationInfoCollectAppInfo = ApplicationInfoCollector.collectAppInfo(this.f953d);
                        Message messageBuild = new BasicMessageBuilder(1).addString(V_1.BroadCastId, new StringBuilder().append(ScreenShotHandler.this.f949d).toString()).addString(V_1.AppName, applicationInfoCollectAppInfo.getAppName()).addString(V_1.PackageName, applicationInfoCollectAppInfo.getPackageName()).addString(V_1.VersionCode, new StringBuilder().append(applicationInfoCollectAppInfo.getVersionCode()).toString()).addString(V_1.VersionName, applicationInfoCollectAppInfo.getVersionName()).addBinary(V_1.Pic, byteArray).build();
                        Log.i(ScreenShotHandler.f946a, "ViewCacheHandler build message : id = " + ScreenShotHandler.this.f949d + " appname = " + applicationInfoCollectAppInfo.getAppName());
                        try {
                            Log.i(ScreenShotHandler.f946a, "ViewCacheHandler send pic message");
                            IFeedBackService feedBackService = ScreenShotHandler.this.f948c.getFeedBackService();
                            if (feedBackService != null) {
                                feedBackService.send(messageBuild);
                            } else {
                                Log.e(ScreenShotHandler.f946a, "ViewCacheHandler null service");
                            }
                            view.destroyDrawingCache();
                            return;
                        } catch (RemoteException e) {
                            Log.e(ScreenShotHandler.f946a, "ViewCacheHandler::takeScreenShot 传送图片至FeedBackService失败", e);
                            m136a("传送图片至FeedBackService失败");
                            view.destroyDrawingCache();
                            return;
                        }
                    }
                    m136a("截图压缩成PNG图片时失败");
                    view.destroyDrawingCache();
                } catch (Throwable th) {
                    view.destroyDrawingCache();
                    throw th;
                }
            } catch (Exception e2) {
                Log.e(ScreenShotHandler.f946a, "ViewCacheHandler exception", e2);
            }
        }

        /* JADX INFO: renamed from: a */
        private static void m136a(String description) {
            Log.i(ScreenShotHandler.f946a, "ViewCacheHandler catch err : " + description);
        }
    }
}
