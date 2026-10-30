package ledroid.utils;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

/* JADX INFO: loaded from: classes.dex */
public final class MountPoint {

    /* JADX INFO: renamed from: a */
    private static HashMap<String, String> f6396a = new HashMap<>(5);

    private MountPoint() {
    }

    public static String getDeviceName(String mountPoint) throws Throwable {
        if (mountPoint == null) {
            return null;
        }
        if (f6396a.containsKey(mountPoint)) {
            return f6396a.get(mountPoint);
        }
        String deviceName = null;
        BufferedReader mountPointReader = null;
        try {
            BufferedReader mountPointReader2 = new BufferedReader(new InputStreamReader(new FileInputStream(new File("/proc/mounts"))));
            while (true) {
                try {
                    String buffer = mountPointReader2.readLine();
                    if (buffer == null) {
                        break;
                    }
                    if (buffer.contains(mountPoint)) {
                        deviceName = buffer.split(" ")[0];
                        f6396a.put(mountPoint, deviceName);
                        break;
                    }
                } catch (IOException e) {
                    mountPointReader = mountPointReader2;
                    FileUtils.closeIOCloseable(mountPointReader);
                } catch (Throwable th) {
                    th = th;
                    mountPointReader = mountPointReader2;
                    FileUtils.closeIOCloseable(mountPointReader);
                    throw th;
                }
            }
            FileUtils.closeIOCloseable(mountPointReader2);
        } catch (IOException e2) {
        } catch (Throwable th2) {
            th = th2;
        }
        return deviceName;
    }
}
