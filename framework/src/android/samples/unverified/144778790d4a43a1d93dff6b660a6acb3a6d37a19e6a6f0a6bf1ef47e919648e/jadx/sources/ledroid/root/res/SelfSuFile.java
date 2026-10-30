package ledroid.root.res;

import android.content.Context;
import android.util.Log;
import java.io.File;
import java.io.IOException;
import ledroid.root.ICommandTransport;
import ledroid.root.ShellCommand;
import ledroid.utils.AndroidResourceFile;
import ledroid.utils.FileUtils;
import ledroid.utils.MountPoint;

/* JADX INFO: loaded from: classes.dex */
public final class SelfSuFile {

    /* JADX INFO: renamed from: a */
    private Context f6352a;

    /* JADX INFO: renamed from: b */
    private AndroidResourceFile f6353b;

    /* JADX INFO: renamed from: c */
    private File f6354c;

    public SelfSuFile(Context ctx, int resid) {
        this.f6352a = null;
        this.f6353b = null;
        this.f6354c = null;
        this.f6352a = ctx;
        this.f6353b = new AndroidResourceFile(this.f6352a.getResources(), resid);
        this.f6354c = new File("/system/bin/cmcc_ps");
    }

    public final String getExecName() {
        return "/system/bin/cmcc_ps";
    }

    public final String getAbsolutePath() {
        return this.f6354c.getAbsolutePath();
    }

    public final boolean hadDeployed() {
        if (this.f6354c == null) {
            return false;
        }
        return this.f6354c.exists();
    }

    public final boolean deployedIsUpToData() {
        if (!hadDeployed() || this.f6354c.length() != this.f6353b.getLength()) {
            return false;
        }
        return true;
    }

    public final boolean deployedSelfSuToSystem(ICommandTransport cmdTransport) throws IOException {
        File locSuFile = new File(this.f6352a.getFilesDir() + "/suser");
        try {
            if (this.f6353b.writeTo(locSuFile)) {
                String absolutePath = locSuFile.getAbsolutePath();
                ShellCommand shellCommand = new ShellCommand(cmdTransport);
                shellCommand.setResponseCallBack(new ShellCommand.ShellCommandResponse() { // from class: ledroid.root.res.SelfSuFile.1
                    @Override // ledroid.root.ShellCommand.ShellCommandResponse
                    public final void onShellCommandResponse(int exeId, String reply) {
                        Log.i("SelfRoot", "Self Su Response: " + reply);
                    }
                });
                String absolutePath2 = this.f6354c.getAbsolutePath();
                shellCommand.addCommand("mount -oremount,rw", MountPoint.getDeviceName("/system"), "/system").addCommand("mount -oremount,rw /system /system");
                if (FileUtils.fileExist("/system/bin/busybox")) {
                    shellCommand.addCommand("busybox cp -v", absolutePath, absolutePath2);
                } else {
                    shellCommand.addCommand("cat", absolutePath, ">", absolutePath2);
                }
                shellCommand.addCommand("chown", "0:0", absolutePath2).addCommand("chmod", "6777", absolutePath2).addCommand("mount -oremount,ro", MountPoint.getDeviceName("/system"), "/system").addCommand("mount -oremount,ro /system /system").addCommand("ls", absolutePath2).exec().waitResponse(500L);
            }
            return hadDeployed();
        } finally {
            if (locSuFile.exists()) {
                locSuFile.delete();
            }
        }
    }

    public final void setToBad() {
        try {
            FileUtils.stringToFile(this.f6352a.getCacheDir() + "/suf", "bad");
        } catch (IOException e1) {
            e1.printStackTrace();
        }
    }

    public final boolean isBadSelfSu() {
        File f = new File(this.f6352a.getCacheDir() + "/suf");
        return f.exists();
    }
}
