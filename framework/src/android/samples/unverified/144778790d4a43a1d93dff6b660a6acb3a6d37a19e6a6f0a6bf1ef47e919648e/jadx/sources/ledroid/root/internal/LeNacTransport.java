package ledroid.root.internal;

import QQPIM.EModelID;
import android.content.Context;
import android.net.LocalSocket;
import android.net.LocalSocketAddress;
import android.util.Log;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import ledroid.root.ICommandTransport;
import ledroid.root.ShellCommand;
import ledroid.root.ShellTerminalController;

/* JADX INFO: loaded from: classes.dex */
public final class LeNacTransport implements ICommandTransport {

    /* JADX INFO: renamed from: d */
    private static int f6325d = 0;

    /* JADX INFO: renamed from: e */
    private static LeNacTransport f6326e = new LeNacTransport();

    /* JADX INFO: renamed from: a */
    private boolean f6327a = false;

    /* JADX INFO: renamed from: b */
    private C1098a f6328b = null;

    /* JADX INFO: renamed from: c */
    private Context f6329c = null;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ boolean m2664a(LeNacTransport x0) {
        x0.f6327a = true;
        return true;
    }

    private LeNacTransport() {
    }

    public static LeNacTransport getInstance(Context ctx) {
        f6326e.f6329c = ctx;
        return f6326e;
    }

    protected final void finalize() throws Throwable {
        if (f6326e == this) {
            f6326e = null;
        }
        if (this.f6328b != null) {
            this.f6328b.m2671c();
        }
        super.finalize();
    }

    /* JADX INFO: renamed from: ledroid.root.internal.LeNacTransport$a */
    private static final class C1098a {

        /* JADX INFO: renamed from: a */
        private Socket f6332a = null;

        /* JADX INFO: renamed from: b */
        private LocalSocket f6333b;

        /* JADX INFO: renamed from: c */
        private BufferedReader f6334c;

        /* JADX INFO: renamed from: d */
        private PrintWriter f6335d;

        public C1098a() {
            this.f6333b = null;
            this.f6334c = null;
            this.f6335d = null;
            try {
                m2672d();
            } catch (Exception e) {
                try {
                    LocalSocketAddress localSocketAddress = new LocalSocketAddress("nac_server");
                    this.f6333b = new LocalSocket();
                    this.f6333b.connect(localSocketAddress);
                    this.f6335d = new PrintWriter(this.f6333b.getOutputStream(), true);
                    this.f6334c = new BufferedReader(new InputStreamReader(this.f6333b.getInputStream()));
                } catch (Exception e2) {
                }
            }
        }

        protected final void finalize() throws Throwable {
            m2671c();
            super.finalize();
        }

        /* JADX INFO: Access modifiers changed from: private */
        /* JADX INFO: renamed from: c */
        public void m2671c() {
            try {
                if (this.f6332a != null) {
                    this.f6332a.close();
                    this.f6332a = null;
                }
                if (this.f6333b != null) {
                    this.f6333b.close();
                    this.f6333b = null;
                }
                this.f6334c = null;
                this.f6335d = null;
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        /* JADX INFO: renamed from: a */
        protected final boolean m2674a() {
            boolean isConnected = this.f6332a == null ? false : this.f6332a.isConnected();
            if (!isConnected) {
                if (this.f6333b == null) {
                    return false;
                }
                return this.f6333b.isConnected();
            }
            return isConnected;
        }

        /* JADX INFO: renamed from: ledroid.root.internal.LeNacTransport$a$a */
        private final class a extends Thread {

            /* JADX INFO: renamed from: b */
            private Exception f6337b;

            private a() {
                this.f6337b = null;
            }

            /* synthetic */ a(C1098a x0, byte b) {
                this();
            }

            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    C1098a.this.f6332a = new Socket("127.0.0.1", EModelID._EMID_QQPIM_Install);
                    C1098a.this.f6334c = new BufferedReader(new InputStreamReader(C1098a.this.f6332a.getInputStream()));
                    C1098a.this.f6335d = new PrintWriter(C1098a.this.f6332a.getOutputStream(), true);
                } catch (IOException e) {
                    if (C1098a.this.f6332a != null) {
                        if (!C1098a.this.f6332a.isClosed()) {
                            try {
                                C1098a.this.f6332a.close();
                            } catch (IOException e2) {
                            }
                        }
                        C1098a.this.f6332a = null;
                    }
                    C1098a.this.f6334c = null;
                    C1098a.this.f6335d = null;
                    this.f6337b = e;
                }
            }
        }

        /* JADX INFO: renamed from: ledroid.root.internal.LeNacTransport$a$b */
        private final class b extends Thread {

            /* JADX INFO: renamed from: b */
            private String f6339b;

            private b() {
            }

            /* synthetic */ b(C1098a x0, byte b) {
                this();
            }

            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                this.f6339b = null;
                try {
                    this.f6339b = C1098a.this.f6334c.readLine();
                } catch (IOException e) {
                }
            }

            /* JADX INFO: renamed from: a */
            public final String m2677a() {
                start();
                while (true) {
                    try {
                        join(500L);
                        interrupt();
                        return this.f6339b;
                    } catch (InterruptedException e) {
                    }
                }
            }
        }

        /* JADX INFO: renamed from: d */
        private void m2672d() throws Exception {
            if (!m2674a()) {
                a thread = new a(this, (byte) 0);
                thread.start();
                while (true) {
                    try {
                        thread.join();
                        if (thread.f6337b != null) {
                            throw thread.f6337b;
                        }
                        return;
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        }

        /* JADX INFO: renamed from: a */
        public final void m2673a(String cmd) {
            this.f6335d.write(cmd);
        }

        /* JADX INFO: renamed from: b */
        public final void m2675b() {
            this.f6335d.println();
            this.f6335d.flush();
        }
    }

    /* JADX INFO: renamed from: a */
    private boolean m2663a() {
        if (this.f6328b != null && this.f6328b.m2674a()) {
            return true;
        }
        this.f6328b = null;
        return false;
    }

    @Override // ledroid.root.ICommandTransport
    public final boolean prepare() {
        if (this.f6328b == null) {
            this.f6328b = new C1098a();
        }
        final File testr = new File("/data", "testr");
        if (this.f6328b.m2674a()) {
            if (!testr.exists()) {
                ShellCommand sc = new ShellCommand(this);
                sc.setResponseCallBack(new ShellCommand.ShellCommandResponse() { // from class: ledroid.root.internal.LeNacTransport.1
                    @Override // ledroid.root.ShellCommand.ShellCommandResponse
                    public final void onShellCommandResponse(int exeId, String reply) {
                        if (exeId == 1 && testr.exists()) {
                            LeNacTransport.m2664a(LeNacTransport.this);
                        }
                    }
                });
                try {
                    sc.addCommand("echo '1' > ", testr.getAbsolutePath()).addCommand("exit").exec(1).waitResponse(1);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } else {
                this.f6327a = true;
            }
        }
        return this.f6327a;
    }

    @Override // ledroid.root.ICommandTransport
    public final synchronized String readLine() throws IOException {
        return "useless response.";
    }

    @Override // ledroid.root.ICommandTransport
    public final synchronized void write(String cmd) throws IOException {
        if (m2663a()) {
            this.f6328b.m2673a(cmd);
        }
    }

    @Override // ledroid.root.ICommandTransport
    public final synchronized void flush() throws IOException {
        if (m2663a()) {
            this.f6328b.m2675b();
        }
    }

    @Override // ledroid.root.ICommandTransport
    public final boolean onlyAsScriptBatchExec() {
        return true;
    }

    @Override // ledroid.root.ICommandTransport
    public final Context getContext() {
        return this.f6329c;
    }

    @Override // ledroid.root.ICommandTransport
    public final String getDesc() {
        return "LeNacTransport";
    }

    @Override // ledroid.root.ICommandTransport
    public final boolean isRootTransport() {
        return true;
    }

    @Override // ledroid.root.ICommandTransport
    public final void onBeforeExec() {
        if (!m2663a()) {
            prepare();
        }
    }

    @Override // ledroid.root.ICommandTransport
    public final void onAfterExec() {
        try {
            Log.d("LeNacTransport", "NAC Response: " + new C1098a.b(this.f6328b, (byte) 0).m2677a());
        } catch (IOException e) {
            e.printStackTrace();
        }
        destory();
    }

    @Override // ledroid.root.ICommandTransport
    public final void destory() {
        if (this.f6328b != null) {
            this.f6328b.m2671c();
            this.f6328b = null;
        }
    }

    @Override // ledroid.root.ICommandTransport
    public final ShellTerminalController.TransportType getType() {
        return ShellTerminalController.TransportType.NAC_TRANSPORT;
    }
}
