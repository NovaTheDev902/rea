package ledroid.root.internal;

import android.content.Context;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import ledroid.root.ICommandTransport;
import ledroid.root.ShellTerminalController;

/* JADX INFO: loaded from: classes.dex */
public class ShellTransport implements ICommandTransport {

    /* JADX INFO: renamed from: a */
    private Context f6341a;

    /* JADX INFO: renamed from: b */
    private Process f6342b = null;

    /* JADX INFO: renamed from: c */
    private DataOutputStream f6343c = null;

    /* JADX INFO: renamed from: d */
    private BufferedReader f6344d = null;

    public ShellTransport(Context ctx) {
        this.f6341a = ctx;
    }

    protected void finalize() throws Throwable {
        super.finalize();
    }

    @Override // ledroid.root.ICommandTransport
    public String readLine() throws IOException {
        if (this.f6344d == null) {
            return null;
        }
        return this.f6344d.readLine();
    }

    @Override // ledroid.root.ICommandTransport
    public void write(String cmd) throws IOException {
        if (this.f6343c != null) {
            this.f6343c.writeBytes(cmd);
        }
    }

    @Override // ledroid.root.ICommandTransport
    public void flush() throws IOException {
        if (this.f6343c != null) {
            this.f6343c.flush();
        }
    }

    protected boolean resetTransportProcess(String cmd) throws IOException {
        destory();
        this.f6342b = new ProcessBuilder(new String[0]).command(cmd).redirectErrorStream(true).start();
        this.f6343c = new DataOutputStream(this.f6342b.getOutputStream());
        this.f6344d = new BufferedReader(new InputStreamReader(this.f6342b.getInputStream()));
        return true;
    }

    @Override // ledroid.root.ICommandTransport
    public boolean prepare() {
        try {
            resetTransportProcess("sh");
            return true;
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
    }

    @Override // ledroid.root.ICommandTransport
    public boolean onlyAsScriptBatchExec() {
        return false;
    }

    @Override // ledroid.root.ICommandTransport
    public Context getContext() {
        return this.f6341a;
    }

    @Override // ledroid.root.ICommandTransport
    public String getDesc() {
        return "ShellTransport";
    }

    @Override // ledroid.root.ICommandTransport
    public boolean isRootTransport() {
        return false;
    }

    @Override // ledroid.root.ICommandTransport
    public void onBeforeExec() {
    }

    @Override // ledroid.root.ICommandTransport
    public void onAfterExec() {
    }

    @Override // ledroid.root.ICommandTransport
    public void destory() {
        if (this.f6342b != null) {
            this.f6342b.destroy();
            this.f6342b = null;
        }
        this.f6343c = null;
        this.f6344d = null;
    }

    @Override // ledroid.root.ICommandTransport
    public ShellTerminalController.TransportType getType() {
        return ShellTerminalController.TransportType.NORMAL_TRANSPORT;
    }
}
