package com.lenovo.feedback2.agent;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;
import com.lenovo.feedback2.message.CommandAction;
import com.lenovo.providers.querypermissions.QueryPermissions;

/* JADX INFO: loaded from: classes.dex */
public class CommandReceiver extends BroadcastReceiver {

    /* JADX INFO: renamed from: a */
    private static String f928a = "FeedBackAgent";

    /* JADX INFO: renamed from: b */
    private AgentContext f929b;

    public void setAgentContext(AgentContext agentContext) {
        this.f929b = agentContext;
    }

    @Override // android.content.BroadcastReceiver
    public void onReceive(Context context, Intent intent) {
        String action = intent.getAction();
        if (action.equals(CommandAction.SERVER_START)) {
            m125a();
            return;
        }
        if (action.equals(CommandAction.SERVER_RESTART)) {
            m125a();
            return;
        }
        if (action.equals(CommandAction.SERVER_STOP)) {
            Log.i(f928a, "CommandReceiver unbind from service");
            this.f929b.getHandler().unbind();
        } else if (action.equals(CommandAction.REBIND)) {
            m125a();
        } else if (action.equals(CommandAction.GET_SCREENSHOT)) {
            long id = intent.getLongExtra(QueryPermissions.f1958ID, 0L);
            Log.i(f928a, "CommandReceiver::received screenshot command. id = " + id);
            new Thread(new ScreenShotHandler(this.f929b, id)).start();
        }
    }

    /* JADX INFO: renamed from: a */
    private void m125a() {
        Log.i(f928a, "CommandReceiver rebind to service");
        this.f929b.getHandler().unbind();
        this.f929b.getHandler().bind();
    }
}
