package com.lenovo.feedback2.agent;

import android.content.Context;
import com.lenovo.feedback2.service.IFeedBackService;

/* JADX INFO: loaded from: classes.dex */
public class AgentContext {

    /* JADX INFO: renamed from: a */
    private Context f919a;

    /* JADX INFO: renamed from: b */
    private IFeedBackService f920b;

    /* JADX INFO: renamed from: c */
    private ApplicationInfo f921c;

    /* JADX INFO: renamed from: d */
    private FeedBackAgent.AgentHandler f922d;

    public Context getContext() {
        return this.f919a;
    }

    public void setContext(Context context) {
        this.f919a = context;
    }

    public IFeedBackService getFeedBackService() {
        return this.f920b;
    }

    public void setFeedBackService(IFeedBackService feedBackService) {
        this.f920b = feedBackService;
    }

    public ApplicationInfo getApplicationInfo() {
        return this.f921c;
    }

    public void setApplicationInfo(ApplicationInfo applicationInfo) {
        this.f921c = applicationInfo;
    }

    public FeedBackAgent.AgentHandler getHandler() {
        return this.f922d;
    }

    public void setHandler(FeedBackAgent.AgentHandler handler) {
        this.f922d = handler;
    }
}
