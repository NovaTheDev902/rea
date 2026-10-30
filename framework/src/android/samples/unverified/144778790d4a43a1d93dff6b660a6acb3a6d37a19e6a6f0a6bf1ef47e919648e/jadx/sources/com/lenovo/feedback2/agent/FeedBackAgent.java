package com.lenovo.feedback2.agent;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.os.Process;
import android.os.RemoteException;
import android.util.Log;
import com.lenovo.feedback2.message.CommandAction;
import com.lenovo.feedback2.message.Message;
import com.lenovo.feedback2.service.IFeedBackService;

/* JADX INFO: loaded from: classes.dex */
public class FeedBackAgent {

    /* JADX INFO: renamed from: b */
    private static FeedBackAgent f934b;

    /* JADX INFO: renamed from: e */
    private Context f937e;

    /* JADX INFO: renamed from: g */
    private ServiceConnection f939g;

    /* JADX INFO: renamed from: h */
    private CommandReceiver f940h;

    /* JADX INFO: renamed from: i */
    private IMessageListener f941i;

    /* JADX INFO: renamed from: a */
    private static String f933a = "FeedBackAgent";

    /* JADX INFO: renamed from: c */
    private static Object f935c = new Object();

    /* JADX INFO: renamed from: d */
    private final BinderC0044a f936d = new BinderC0044a(this, 0);

    /* JADX INFO: renamed from: f */
    private final AgentContext f938f = new AgentContext();

    public static void init(Context context) {
        if (context == null) {
            Log.e(f933a, "FeedBackAgent::init null context!");
            return;
        }
        synchronized (f935c) {
            if (f934b == null) {
                f934b = new FeedBackAgent(context);
            }
        }
    }

    private FeedBackAgent(Context context) {
        this.f937e = context;
        Log.i(f933a, "FeedBackAgent create new instance");
        ApplicationInfo info = ApplicationInfoCollector.collectAppInfo(context);
        this.f938f.setContext(context);
        this.f938f.setApplicationInfo(info);
        this.f938f.setHandler(new AgentHandler());
        this.f940h = new CommandReceiver();
        this.f940h.setAgentContext(this.f938f);
        IntentFilter filter = new IntentFilter();
        filter.addAction(CommandAction.SERVER_START);
        filter.addAction(CommandAction.SERVER_RESTART);
        filter.addAction(CommandAction.SERVER_STOP);
        filter.addAction(CommandAction.GET_SCREENSHOT);
        filter.addAction(CommandAction.REBIND);
        context.registerReceiver(this.f940h, filter);
        m128b();
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: b */
    public void m128b() {
        if (this.f939g == null) {
            Log.i(f933a, "FeedBackAgent::bind create new connection");
            this.f939g = new ServiceConnectionC0045b(this, (byte) 0);
            Intent intent = new Intent();
            intent.setClassName("com.lenovo.feedback2", "com.lenovo.feedback2.service.FeedBackService");
            this.f937e.bindService(intent, this.f939g, 1);
            return;
        }
        Log.i(f933a, "FeedBackAgent::bind has bound to service");
    }

    /* JADX INFO: renamed from: b */
    static /* synthetic */ void m129b(FeedBackAgent feedBackAgent) {
        if (feedBackAgent.f937e != null && feedBackAgent.f939g != null) {
            Log.i(f933a, "FeedBackAgent::unbind ");
            feedBackAgent.f937e.unbindService(feedBackAgent.f939g);
        }
        feedBackAgent.f939g = null;
    }

    public static void setMessageListener(IMessageListener messageListener) {
        if (f934b != null) {
            f934b.f941i = messageListener;
        }
    }

    public class AgentHandler {
        public AgentHandler() {
        }

        public void bind() {
            FeedBackAgent.this.m128b();
        }

        public void unbind() {
            FeedBackAgent.m129b(FeedBackAgent.this);
        }
    }

    /* JADX INFO: renamed from: com.lenovo.feedback2.agent.FeedBackAgent$b */
    private class ServiceConnectionC0045b implements ServiceConnection {
        private ServiceConnectionC0045b() {
        }

        /* synthetic */ ServiceConnectionC0045b(FeedBackAgent feedBackAgent, byte b) {
            this();
        }

        @Override // android.content.ServiceConnection
        public final void onServiceConnected(ComponentName name, IBinder service) {
            IFeedBackService feedBackService = IFeedBackService.Stub.asInterface(service);
            if (feedBackService == null) {
                Log.e(FeedBackAgent.f933a, "FeedBackAgent::onServiceConnected null service binder");
                return;
            }
            try {
                feedBackService.setAgentCallBack(Process.myPid(), FeedBackAgent.this.f938f.getApplicationInfo().getPackageName(), FeedBackAgent.this.f936d);
                FeedBackAgent.this.f938f.setFeedBackService(feedBackService);
                new CrashHandler(FeedBackAgent.this.f938f, FeedBackAgent.this.new AgentHandler());
            } catch (RemoteException e) {
            }
        }

        @Override // android.content.ServiceConnection
        public final void onServiceDisconnected(ComponentName name) {
        }
    }

    /* JADX INFO: renamed from: com.lenovo.feedback2.agent.FeedBackAgent$a */
    private class BinderC0044a extends IFeedBackAgent.Stub {
        private BinderC0044a() {
        }

        /* synthetic */ BinderC0044a(FeedBackAgent feedBackAgent, byte b) {
            this();
        }

        @Override // com.lenovo.feedback2.agent.IFeedBackAgent
        public final Message received(Message message) throws RemoteException {
            Log.i(FeedBackAgent.f933a, "AgentCallBack::received " + message.getHeader());
            if (FeedBackAgent.this.f941i != null) {
                FeedBackAgent.this.f941i.onReceivedMessage(message);
                return null;
            }
            return null;
        }
    }
}
