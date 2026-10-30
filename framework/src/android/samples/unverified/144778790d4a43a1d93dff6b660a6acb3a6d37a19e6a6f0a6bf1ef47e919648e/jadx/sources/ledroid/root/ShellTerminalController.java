package ledroid.root;

import android.content.Context;
import ledroid.root.internal.LeNacTransport;
import ledroid.root.internal.SelfRootTransport;
import ledroid.root.internal.ShellTransport;
import ledroid.root.internal.SuTransport;

/* JADX INFO: loaded from: classes.dex */
public final class ShellTerminalController {

    /* JADX INFO: renamed from: b */
    private static int f6320b = 0;

    /* JADX INFO: renamed from: c */
    private static TransportType f6321c = null;

    /* JADX INFO: renamed from: a */
    private Context f6322a;

    public enum TransportType {
        NORMAL_TRANSPORT,
        NAC_TRANSPORT,
        SU_TRANSPORT,
        SELF_ROOT_TRANSPORT
    }

    public ShellTerminalController(Context ctx) {
        this.f6322a = ctx;
    }

    public final ICommandTransport getRootTransport() {
        ICommandTransport selfSuTransport;
        if (m2661a()) {
            if (m2662b()) {
                return getTransport(this.f6322a, f6321c);
            }
            return null;
        }
        ICommandTransport st = getTransport(this.f6322a, TransportType.SELF_ROOT_TRANSPORT);
        if (st == null) {
            st = getTransport(this.f6322a, TransportType.SU_TRANSPORT);
            if (st == null) {
                st = getTransport(this.f6322a, TransportType.NAC_TRANSPORT);
            }
            if (st != null && (selfSuTransport = SelfRootTransport.deploySelfSu(st)) != null) {
                st.destory();
                st = selfSuTransport;
            }
        }
        if (st != null) {
            m2660a(1, st.getType());
            return st;
        }
        m2660a(-1, null);
        return st;
    }

    public final ICommandTransport getTransport(Context ctx, TransportType type) {
        ICommandTransport st = null;
        switch (type) {
            case NAC_TRANSPORT:
                st = LeNacTransport.getInstance(ctx);
                break;
            case SELF_ROOT_TRANSPORT:
                st = new SelfRootTransport(ctx);
                break;
            case SU_TRANSPORT:
                st = new SuTransport(ctx);
                break;
            case NORMAL_TRANSPORT:
                st = new ShellTransport(ctx);
                break;
        }
        if (st == null || !st.prepare()) {
            return null;
        }
        return st;
    }

    public final boolean hasRootPermission() {
        if (m2661a()) {
            return m2662b();
        }
        ICommandTransport rootTransport = getRootTransport();
        if (rootTransport != null && rootTransport.isRootTransport()) {
            return true;
        }
        return false;
    }

    /* JADX INFO: renamed from: a */
    private static boolean m2661a() {
        return f6320b != 0;
    }

    /* JADX INFO: renamed from: b */
    private static boolean m2662b() {
        return f6320b == 1;
    }

    /* JADX INFO: renamed from: a */
    private static void m2660a(int status, TransportType usableType) {
        f6320b = status;
        f6321c = usableType;
    }
}
