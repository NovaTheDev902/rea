package ledroid.root.internal;

import android.content.Context;
import java.io.IOException;
import ledroid.root.ICommandTransport;
import ledroid.root.ShellTerminalController;
import ledroid.root.res.SelfSuFile;
import ledroid.utils.AndroidResources;

/* JADX INFO: loaded from: classes.dex */
public class SelfRootTransport extends SuTransport {

    /* JADX INFO: renamed from: a */
    private SelfSuFile f6340a;

    public SelfRootTransport(Context ctx) {
        super(ctx);
        AndroidResources androidResources = new AndroidResources(ctx.getResources());
        this.f6340a = new SelfSuFile(ctx, androidResources.getIdentifier(ctx.getPackageName(), "raw", "su"));
    }

    @Override // ledroid.root.internal.SuTransport, ledroid.root.internal.ShellTransport, ledroid.root.ICommandTransport
    public String getDesc() {
        return "SelfRootTransport";
    }

    public static SelfRootTransport deploySelfSu(ICommandTransport deployTransport) {
        SelfRootTransport selfSu = new SelfRootTransport(deployTransport.getContext());
        if (!selfSu.prepare()) {
            try {
                if (!selfSu.f6340a.deployedSelfSuToSystem(deployTransport) || !selfSu.prepare()) {
                    return null;
                }
                return selfSu;
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            return selfSu;
        }
    }

    @Override // ledroid.root.internal.SuTransport, ledroid.root.internal.ShellTransport, ledroid.root.ICommandTransport
    public boolean prepare() {
        if (this.f6340a.deployedIsUpToData()) {
            return m2678a();
        }
        return false;
    }

    /* JADX INFO: renamed from: a */
    private boolean m2678a() {
        try {
            boolean became = becomeProcess(this.f6340a.getExecName());
            return became;
        } catch (IOException e) {
            return false;
        }
    }

    @Override // ledroid.root.internal.SuTransport, ledroid.root.internal.ShellTransport, ledroid.root.ICommandTransport
    public ShellTerminalController.TransportType getType() {
        return ShellTerminalController.TransportType.SELF_ROOT_TRANSPORT;
    }
}
