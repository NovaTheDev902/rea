package ledroid.root;

import android.content.Context;
import java.io.IOException;

/* JADX INFO: loaded from: classes.dex */
public interface ICommandTransport {
    void destory();

    void flush() throws IOException;

    Context getContext();

    String getDesc();

    ShellTerminalController.TransportType getType();

    boolean isRootTransport();

    void onAfterExec();

    void onBeforeExec();

    boolean onlyAsScriptBatchExec();

    boolean prepare();

    String readLine() throws IOException;

    void write(String str) throws IOException;
}
