package ledroid.root;

import android.content.Context;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;

/* JADX INFO: loaded from: classes.dex */
public final class ShellCommand {

    /* JADX INFO: renamed from: a */
    private ICommandTransport f6313a;

    /* JADX INFO: renamed from: b */
    private ArrayList<String> f6314b;

    /* JADX INFO: renamed from: c */
    private ShellCommandResponse f6315c;

    /* JADX INFO: renamed from: d */
    private ArrayList<File> f6316d;

    public interface ShellCommandResponse {
        void onShellCommandResponse(int i, String str);
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m2658a(ShellCommand x0, int x1, String x2) {
        x0.f6315c.onShellCommandResponse(x1, x2);
    }

    public ShellCommand(ICommandTransport transport) {
        this.f6313a = null;
        this.f6314b = new ArrayList<>();
        this.f6315c = null;
        this.f6316d = new ArrayList<>();
        this.f6313a = transport;
    }

    public ShellCommand(ICommandTransport transport, String... command) {
        this(transport);
        addCommand(command);
    }

    protected final void finalize() throws Throwable {
        Iterator<File> iterator = this.f6316d.iterator();
        while (iterator.hasNext()) {
            iterator.next().delete();
        }
        this.f6316d.clear();
        super.finalize();
    }

    public final synchronized ShellCommand addCommand(String... command) {
        ArrayList<String> cmds = new ArrayList<>(Arrays.asList(command));
        Iterator<String> iterator = cmds.iterator();
        StringBuffer sb = new StringBuffer();
        while (iterator.hasNext()) {
            sb.append(iterator.next());
            sb.append(' ');
        }
        sb.append('\n');
        this.f6314b.add(sb.toString());
        cmds.clear();
        return this;
    }

    public final synchronized void setResponseCallBack(ShellCommandResponse callback) {
        if (callback != null) {
            this.f6315c = callback;
        }
    }

    public final synchronized ShellCommand exec() throws IOException {
        return exec(-1);
    }

    public final synchronized ShellCommand exec(int exeId) throws IOException {
        ShellCommand shellCommand;
        if (this.f6314b == null || this.f6313a == null) {
            shellCommand = null;
        } else {
            this.f6313a.onBeforeExec();
            if (this.f6313a.onlyAsScriptBatchExec()) {
                m2657a();
            } else {
                boolean z = false;
                for (String str : this.f6314b) {
                    if (str.startsWith("exit")) {
                        z = true;
                    }
                    this.f6313a.write(str);
                }
                if (!z) {
                    this.f6313a.write("echo \"SHELL COMMAND END\" \n");
                }
            }
            this.f6313a.flush();
            this.f6313a.onAfterExec();
            this.f6314b.clear();
            shellCommand = this;
        }
        return shellCommand;
    }

    /* JADX INFO: renamed from: a */
    private synchronized ShellCommand m2657a() throws IOException {
        ShellCommand shellCommand;
        if (this.f6314b == null || this.f6313a == null) {
            shellCommand = null;
        } else {
            Context context = this.f6313a.getContext();
            File tempFile = File.createTempFile("ledroid", ".cmds", context.getCacheDir());
            tempFile.setExecutable(true, false);
            tempFile.setReadable(true, false);
            BufferedWriter shellBW = null;
            try {
                BufferedWriter shellBW2 = new BufferedWriter(new FileWriter(tempFile));
                try {
                    boolean exit = false;
                    for (String cmd : this.f6314b) {
                        if (cmd.startsWith("exit")) {
                            exit = true;
                        }
                        shellBW2.write(cmd);
                    }
                    if (exit) {
                        shellBW2.write("echo \"SHELL COMMAND END\" \n");
                    }
                    shellBW2.flush();
                    shellBW2.close();
                    this.f6313a.write(tempFile.getAbsolutePath() + " & \n");
                    this.f6316d.add(tempFile);
                    shellCommand = this;
                } catch (Throwable th) {
                    th = th;
                    shellBW = shellBW2;
                    if (shellBW != null) {
                        shellBW.flush();
                        shellBW.close();
                    }
                    throw th;
                }
            } catch (Throwable th2) {
                th = th2;
            }
        }
        return shellCommand;
    }

    public final void waitResponse() {
        waitResponse(-1);
    }

    public final void waitResponse(long millis) {
        waitResponse(-1, millis);
    }

    public final void waitResponse(int exeId) {
        waitResponse(exeId, 500L);
    }

    public final void waitResponse(int exeId, long millis) {
        if (this.f6315c != null) {
            Thread relayThread = new Thread(new RunnableC1095a(this, exeId));
            relayThread.setDaemon(true);
            relayThread.setName(this.f6315c.getClass().getName() + "_Relay");
            relayThread.start();
            Thread.yield();
            System.currentTimeMillis();
            while (true) {
                try {
                    if (millis == 0) {
                        relayThread.join();
                    } else {
                        relayThread.join(millis);
                    }
                    break;
                } catch (InterruptedException e) {
                }
            }
            if (millis > 0) {
                System.currentTimeMillis();
                return;
            }
            return;
        }
        if (millis < 0) {
            return;
        }
        while (true) {
            try {
                wait(millis);
                return;
            } catch (InterruptedException e2) {
            }
        }
    }

    /* JADX INFO: renamed from: ledroid.root.ShellCommand$a */
    private class RunnableC1095a implements Runnable {

        /* JADX INFO: renamed from: b */
        private ShellCommand f6318b;

        /* JADX INFO: renamed from: c */
        private int f6319c;

        public RunnableC1095a(ShellCommand shellCmd, int exeId) {
            this.f6318b = shellCmd;
            this.f6319c = exeId;
        }

        @Override // java.lang.Runnable
        public final void run() {
            if (ShellCommand.this.f6315c != null && ShellCommand.this.f6313a != null && this.f6318b != null) {
                do {
                    try {
                        String line = ShellCommand.this.f6313a.readLine();
                        if (line == null || "SHELL COMMAND END".equals(line)) {
                            break;
                        } else {
                            ShellCommand.m2658a(this.f6318b, this.f6319c, line);
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                        return;
                    }
                } while (!ShellCommand.this.f6313a.onlyAsScriptBatchExec());
                this.f6318b = null;
            }
        }
    }
}
