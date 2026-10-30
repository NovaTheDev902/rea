package com.lenovo.feedback2.agent;

import android.util.Log;
import com.lenovo.feedback2.message.BasicMessageBuilder;
import com.lenovo.feedback2.message.Message;
import com.lenovo.feedback2.message.protocol.V_1;
import com.lenovo.feedback2.service.IFeedBackService;
import java.io.PrintWriter;
import java.io.StringWriter;

/* JADX INFO: loaded from: classes.dex */
public class CrashHandler implements Thread.UncaughtExceptionHandler {

    /* JADX INFO: renamed from: a */
    private AgentContext f930a;

    /* JADX INFO: renamed from: b */
    private FeedBackAgent.AgentHandler f931b;

    /* JADX INFO: renamed from: c */
    private Thread.UncaughtExceptionHandler f932c = Thread.getDefaultUncaughtExceptionHandler();

    public CrashHandler(AgentContext context, FeedBackAgent.AgentHandler handler) {
        this.f930a = context;
        this.f931b = handler;
        Thread.setDefaultUncaughtExceptionHandler(this);
        Log.i("FeedBackAgent", "CrashHandler start");
    }

    @Override // java.lang.Thread.UncaughtExceptionHandler
    public void uncaughtException(Thread thread, Throwable ex) {
        try {
            IFeedBackService service = this.f930a.getFeedBackService();
            if (service == null) {
                Log.e("FeedBackAgent", "CrashHandler::uncaughtException null service");
                return;
            }
            ApplicationInfo info = this.f930a.getApplicationInfo();
            if (info == null) {
                Log.e("FeedBackAgent", "CrashHandler::uncaughtException null application info");
                return;
            }
            StringWriter stringWriter = new StringWriter();
            PrintWriter printWriter = new PrintWriter(stringWriter);
            for (Throwable cause = ex; cause != null; cause = cause.getCause()) {
                cause.printStackTrace(printWriter);
            }
            String stacktraceAsString = stringWriter.toString();
            printWriter.close();
            Log.i("FeedBackAgent", "CrashHandler::uncaughtException getStackTrace");
            BasicMessageBuilder builder = new BasicMessageBuilder(1);
            Message message = builder.addString(V_1.StackTrace, stacktraceAsString).addString(V_1.AppName, info.getAppName()).addString(V_1.PackageName, info.getPackageName()).addString(V_1.VersionCode, new StringBuilder().append(info.getVersionCode()).toString()).addString(V_1.VersionName, info.getVersionName()).build();
            Log.i("FeedBackAgent", "CrashHandler::uncaughtException send stack trace message to service");
            service.send(message);
            if (this.f931b != null) {
                this.f931b.unbind();
            }
            if (this.f932c != null) {
                this.f932c.uncaughtException(thread, ex);
            }
        } catch (Exception e) {
            Log.e("FeedBackAgent", "CrashHandler catch exception ", e);
        }
    }
}
