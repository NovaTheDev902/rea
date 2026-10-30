package ledroid.utils;

import android.content.Context;
import android.util.Log;
import com.lenovo.lps.sus.p008c.C0092c;
import java.io.BufferedReader;
import java.io.Closeable;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public final class FileUtils extends android.os.FileUtils {
    public static boolean fileExist(String path) {
        if (path == null) {
            return false;
        }
        File f = new File(path);
        return f.exists();
    }

    public static boolean isEmptryDir(File dir) {
        return dir.isDirectory() && (dir.list() == null || dir.list().length == 0);
    }

    public static long getFileSize(File f) {
        long sumSize = 0;
        if (f.isFile() || isEmptryDir(f)) {
            sumSize = f.length();
        } else if (f.isDirectory()) {
            File[] listFiles = f.listFiles();
            if (listFiles == null) {
                return 0L;
            }
            for (File file : listFiles) {
                sumSize += getFileSize(file);
            }
        }
        return sumSize;
    }

    public static void closeIOCloseable(Closeable c) {
        if (c != null) {
            try {
                c.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public static void stringToFile(String filename, String string) throws IOException {
        FileWriter out = new FileWriter(filename);
        try {
            out.write(string);
        } finally {
            out.close();
        }
    }

    public static boolean copyFileByPath(String srcPath, String destPath) {
        return copyFile(new File(srcPath), new File(destPath));
    }

    public static boolean deleteDirectory(File file) {
        File[] childFiles;
        if (file == null || !file.exists()) {
            return true;
        }
        if (file.isDirectory() && (childFiles = file.listFiles()) != null && childFiles.length > 0) {
            for (int i = 0; i < childFiles.length; i++) {
                if (!deleteDirectory(childFiles[i])) {
                    Log.w("FileUtils", "[Failed] Deleted folder: " + childFiles[i]);
                }
            }
        }
        return file.delete();
    }

    public static ArrayList<String> getShieldProcessesList(Context context, String fileName) {
        ArrayList<String> shieldProcessesList = new ArrayList<>();
        try {
            InputStream in = context.getAssets().open(fileName);
            BufferedReader reader = new BufferedReader(new InputStreamReader(in));
            while (true) {
                String line = reader.readLine();
                if (line == null) {
                    break;
                }
                String[] str = line.split(C0092c.f1284O);
                shieldProcessesList.addAll(Arrays.asList(str));
            }
            shieldProcessesList.trimToSize();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return shieldProcessesList;
    }

    public static boolean isShieldItem(String item, List<String> list) {
        if (list == null) {
            return false;
        }
        for (int i = 0; i < list.size(); i++) {
            if (item.equalsIgnoreCase(list.get(i))) {
                return true;
            }
        }
        return false;
    }
}
