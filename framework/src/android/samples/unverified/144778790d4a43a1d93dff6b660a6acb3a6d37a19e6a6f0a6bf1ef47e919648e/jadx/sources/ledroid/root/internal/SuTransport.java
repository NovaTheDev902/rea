package ledroid.root.internal;

import android.content.Context;
import android.util.Log;
import com.lenovo.providers.querypermissions.QueryPermissions;
import java.io.IOException;
import ledroid.root.ShellCommand;
import ledroid.root.ShellTerminalController;
import ledroid.utils.FileUtils;

/* JADX INFO: loaded from: classes.dex */
public class SuTransport extends ShellTransport {
    public SuTransport(Context ctx) {
        super(ctx);
    }

    @Override // ledroid.root.internal.ShellTransport, ledroid.root.ICommandTransport
    public boolean prepare() {
        if (!FileUtils.fileExist("/system/xbin/su") && !FileUtils.fileExist("/system/bin/su")) {
            return false;
        }
        try {
            return becomeProcess("su");
        } catch (IOException e) {
            return false;
        }
    }

    protected final boolean becomeProcess(String suCmd) throws IOException {
        ShellCommand sc = new ShellCommand(this);
        C1099a response = new C1099a(this, (byte) 0);
        sc.setResponseCallBack(response);
        if (resetTransportProcess(suCmd)) {
            sc.addCommand(QueryPermissions.f1958ID).exec(1).waitResponse(1, 0L);
        }
        return response.f6346b;
    }

    @Override // ledroid.root.internal.ShellTransport, ledroid.root.ICommandTransport
    public String getDesc() {
        return "SuShellTransport";
    }

    @Override // ledroid.root.internal.ShellTransport, ledroid.root.ICommandTransport
    public boolean isRootTransport() {
        return true;
    }

    @Override // ledroid.root.internal.ShellTransport, ledroid.root.ICommandTransport
    public ShellTerminalController.TransportType getType() {
        return ShellTerminalController.TransportType.SU_TRANSPORT;
    }

    /* JADX INFO: renamed from: ledroid.root.internal.SuTransport$a */
    private class C1099a implements ShellCommand.ShellCommandResponse {

        /* JADX INFO: renamed from: b */
        private boolean f6346b;

        private C1099a() {
            this.f6346b = false;
        }

        /* synthetic */ C1099a(SuTransport x0, byte b) {
            this();
        }

        @Override // ledroid.root.ShellCommand.ShellCommandResponse
        public final void onShellCommandResponse(int exeId, String reply) {
            switch (exeId) {
                case 1:
                    if (reply.contains("not allowed to su") || reply.contains("permission denied")) {
                        this.f6346b = false;
                    } else if (reply.contains("uid=0")) {
                        this.f6346b = true;
                    }
                    break;
                default:
                    Log.w("SuShellTransport", "CommandResponse: unkown exeId=" + exeId);
                    break;
            }
        }
    }
}
