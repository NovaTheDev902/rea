package tms;

import QQPIM.ConfInfo;
import QQPIM.VirusClientInfo;
import android.content.Context;
import android.net.Uri;
import android.os.Environment;
import com.lenovo.lps.sus.p003a.p004a.p005a.InterfaceC0079b;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.safecenter.mmsutils.CharacterSets;
import com.lenovo.safecenter.mmsutils.ContentType;
import com.p012qq.jce.wup.UniAttribute;
import com.tencent.tccdb.RuleFileHeader;
import com.tencent.tccdb.SmsChecker;
import com.tencent.tccdb.TccCryptor;
import com.tencent.tmsecure.common.ErrorCode;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.module.qscanner.AmScanner;
import com.tencent.tmsecure.module.update.UpdateConfig;
import com.tencent.tmsecure.utils.Log;
import com.tencent.tmsecure.utils.ScriptHelper;
import com.tencent.tmsecure.utils.UpdateUtil;
import java.io.BufferedInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.atomic.AtomicReference;
import org.apache.commons.httpclient.cookie.CookieSpec;
import org.apache.commons.httpclient.methods.multipart.FilePart;

/* JADX INFO: renamed from: tms.v */
/* JADX INFO: loaded from: classes.dex */
public final class C1336v {

    /* JADX INFO: renamed from: a */
    private static boolean f7477a;

    /* JADX INFO: renamed from: b */
    private static final String[][] f7478b = {new String[]{"3gp", ContentType.VIDEO_3GPP}, new String[]{"apk", "application/vnd.android.package-archive"}, new String[]{"asf", "video/x-ms-asf"}, new String[]{"avi", "video/x-msvideo"}, new String[]{"bin", FilePart.DEFAULT_CONTENT_TYPE}, new String[]{"bmp", "image/bmp"}, new String[]{"c", "text/plain"}, new String[]{"class", FilePart.DEFAULT_CONTENT_TYPE}, new String[]{"conf", "text/plain"}, new String[]{"cpp", "text/plain"}, new String[]{"doc", "application/msword"}, new String[]{"docx", "application/msword"}, new String[]{"exe", FilePart.DEFAULT_CONTENT_TYPE}, new String[]{"gif", ContentType.IMAGE_GIF}, new String[]{"gtar", "application/x-gtar"}, new String[]{"gz", "application/x-gzip"}, new String[]{"h", "text/plain"}, new String[]{"htm", ContentType.TEXT_HTML}, new String[]{"html", ContentType.TEXT_HTML}, new String[]{"jar", "application/java-archive"}, new String[]{"java", "text/plain"}, new String[]{"jpeg", ContentType.IMAGE_JPEG}, new String[]{"jpg", ContentType.IMAGE_JPEG}, new String[]{"js", "application/x-javascript"}, new String[]{"log", "text/plain"}, new String[]{"m3u", "audio/x-mpegurl"}, new String[]{"m4a", "audio/mp4a-latm"}, new String[]{"m4b", "audio/mp4a-latm"}, new String[]{"m4p", "audio/mp4a-latm"}, new String[]{"m4u", "video/vnd.mpegurl"}, new String[]{"m4v", "video/x-m4v"}, new String[]{"mov", "video/quicktime"}, new String[]{"mp2", ContentType.AUDIO_X_MPEG}, new String[]{"mp3", ContentType.AUDIO_X_MPEG}, new String[]{"mp4", ContentType.VIDEO_MP4}, new String[]{"mpc", "application/vnd.mpohn.certificate"}, new String[]{"mpe", "video/mpeg"}, new String[]{"mpeg", "video/mpeg"}, new String[]{"mpg", "video/mpeg"}, new String[]{"mpg4", ContentType.VIDEO_MP4}, new String[]{"mpga", ContentType.AUDIO_MPEG}, new String[]{"msg", "application/vnd.ms-outlook"}, new String[]{"ogg", "audio/ogg"}, new String[]{"pdf", "application/pdf"}, new String[]{"png", ContentType.IMAGE_PNG}, new String[]{"pps", "application/vnd.ms-powerpoint"}, new String[]{"ppsx", "application/vnd.ms-powerpoint"}, new String[]{"ppt", "application/vnd.ms-powerpoint"}, new String[]{"pptx", "application/vnd.ms-powerpoint"}, new String[]{"xls", "application/vnd.ms-excel"}, new String[]{"xlsx", "application/vnd.ms-excel"}, new String[]{"prop", "text/plain"}, new String[]{"rar", "application/x-rar-compressed"}, new String[]{"rc", "text/plain"}, new String[]{"rmvb", "audio/x-pn-realaudio"}, new String[]{"rtf", "application/rtf"}, new String[]{"sh", "text/plain"}, new String[]{"tar", "application/x-tar"}, new String[]{"tgz", "application/x-compressed"}, new String[]{"txt", "text/plain"}, new String[]{"wav", "audio/x-wav"}, new String[]{"wma", "audio/x-ms-wma"}, new String[]{"wmv", "audio/x-ms-wmv"}, new String[]{"wps", "application/vnd.ms-works"}, new String[]{"xml", "text/plain"}, new String[]{"z", "application/x-compress"}, new String[]{"zip", "application/zip"}, new String[]{"epub", "application/epub+zip"}, new String[]{"", "*/*"}};

    /* JADX WARN: Code duplicated, block: B:65:0x0072 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX INFO: renamed from: a */
    public static int m3575a(Context context, Object obj, String str, String str2) throws Throwable {
        Throwable th;
        IOException iOException;
        FileNotFoundException fileNotFoundException;
        FileOutputStream fileOutputStream = null;
        FileOutputStream fileOutputStream2 = null;
        int i = -2;
        if (obj == null || str == null || str2 == null) {
            return -57;
        }
        try {
            try {
                try {
                    FileOutputStream fileOutputStreamOpenFileOutput = context.openFileOutput(str2, 0);
                    try {
                        UniAttribute uniAttribute = new UniAttribute();
                        uniAttribute.setEncodeName(InterfaceC0079b.f1213a);
                        uniAttribute.put(str, obj);
                        byte[] bArrEncrypt = TccCryptor.encrypt(context, uniAttribute.encode(), (byte[]) null);
                        if (bArrEncrypt != null) {
                            fileOutputStreamOpenFileOutput.write(bArrEncrypt);
                            i = 0;
                        }
                        if (fileOutputStreamOpenFileOutput == null) {
                            return i;
                        }
                        try {
                            fileOutputStreamOpenFileOutput.close();
                            return i;
                        } catch (IOException e) {
                            e.printStackTrace();
                            return i;
                        }
                    } catch (FileNotFoundException e2) {
                        fileOutputStream2 = fileOutputStreamOpenFileOutput;
                        fileNotFoundException = e2;
                        i = -1;
                        fileNotFoundException.printStackTrace();
                        if (fileOutputStream2 != null) {
                            try {
                                fileOutputStream2.close();
                            } catch (IOException e3) {
                                e3.printStackTrace();
                            }
                        }
                        return i;
                    } catch (IOException e4) {
                        fileOutputStream2 = fileOutputStreamOpenFileOutput;
                        iOException = e4;
                        i = ErrorCode.ERR_FILE_OP;
                        iOException.printStackTrace();
                        if (fileOutputStream2 != null) {
                            try {
                                fileOutputStream2.close();
                            } catch (IOException e5) {
                                e5.printStackTrace();
                            }
                        }
                        return i;
                    } catch (Throwable th2) {
                        fileOutputStream2 = fileOutputStreamOpenFileOutput;
                        th = th2;
                        th.printStackTrace();
                        if (fileOutputStream2 != null) {
                            try {
                                fileOutputStream2.close();
                            } catch (IOException e6) {
                                e6.printStackTrace();
                            }
                        }
                        return i;
                    }
                } catch (Throwable th3) {
                    th = th3;
                    fileOutputStream = fileOutputStream2;
                    if (fileOutputStream != null) {
                        try {
                            fileOutputStream.close();
                        } catch (IOException e7) {
                            e7.printStackTrace();
                        }
                    }
                    throw th;
                }
            } catch (Throwable th4) {
                th = th4;
                if (fileOutputStream != null) {
                    fileOutputStream.close();
                }
                throw th;
            }
        } catch (FileNotFoundException e8) {
            fileOutputStream2 = null;
            fileNotFoundException = e8;
        } catch (IOException e9) {
            fileOutputStream2 = null;
            iOException = e9;
        } catch (Throwable th5) {
            fileOutputStream2 = null;
            th = th5;
        }
    }

    /* JADX INFO: renamed from: a */
    public static long m3576a(Context context) {
        AtomicReference atomicReference = new AtomicReference();
        String strM3577a = m3577a(context, UpdateConfig.SMS_CHECKER_NAME, (String) null);
        if (strM3577a == null) {
            return 0L;
        }
        SmsChecker.getRuleFileHeader(context, atomicReference, strM3577a);
        RuleFileHeader ruleFileHeader = (RuleFileHeader) atomicReference.get();
        if (ruleFileHeader != null) {
            return ruleFileHeader.time;
        }
        return -1L;
    }

    /* JADX WARN: Code duplicated, block: B:108:? A[Catch: all -> 0x00cc, SYNTHETIC, TRY_ENTER, TRY_LEAVE, TryCatch #6 {, blocks: (B:5:0x0006, B:8:0x0016, B:10:0x0021, B:13:0x002a, B:48:0x00b4, B:50:0x00b9, B:40:0x00a6, B:42:0x00ab, B:57:0x00c3, B:59:0x00c8, B:60:0x00cb, B:12:0x0027, B:7:0x000e), top: B:95:0x0006 }] */
    /* JADX WARN: Code duplicated, block: B:7:0x000e A[Catch: all -> 0x00cc, TryCatch #6 {, blocks: (B:5:0x0006, B:8:0x0016, B:10:0x0021, B:13:0x002a, B:48:0x00b4, B:50:0x00b9, B:40:0x00a6, B:42:0x00ab, B:57:0x00c3, B:59:0x00c8, B:60:0x00cb, B:12:0x0027, B:7:0x000e), top: B:95:0x0006 }] */
    /* JADX WARN: Code duplicated, block: B:85:0x00c8 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:87:0x00c3 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX INFO: renamed from: a */
    public static synchronized String m3577a(Context context, String str, String str2) {
        String str3;
        InputStream inputStreamOpen;
        FileOutputStream fileOutputStream;
        InputStream inputStream;
        FileOutputStream fileOutputStream2 = null;
        synchronized (C1336v.class) {
            if (str2 == null) {
                str2 = context.getFilesDir().toString();
            } else if (str2.equals("")) {
                str2 = context.getFilesDir().toString();
            }
            File file = new File(str2);
            if (!file.exists() || !file.isDirectory()) {
                file.mkdirs();
            }
            str3 = str2 + File.separator + str;
            try {
                File file2 = new File(str3);
                if (!file2.exists() || str.equals("MToken.zip") || ((str.equals(UpdateConfig.SMS_CHECKER_NAME) && m3590b(context)) || ((str.equals(UpdateConfig.VIRUS_BASE_NAME) && m3597c(context)) || m3591b(context, str)))) {
                    m3583a(file2);
                    inputStreamOpen = context.getResources().getAssets().open(str, 1);
                    try {
                        FileOutputStream fileOutputStream3 = new FileOutputStream(file2);
                        try {
                            byte[] bArr = new byte[8192];
                            while (true) {
                                int i = inputStreamOpen.read(bArr);
                                if (i <= 0) {
                                    break;
                                }
                                fileOutputStream3.write(bArr, 0, i);
                            }
                            fileOutputStream2 = fileOutputStream3;
                        } catch (IOException e) {
                            fileOutputStream = fileOutputStream3;
                            inputStream = inputStreamOpen;
                            try {
                                Log.m2634e("getCommonFilePath", "getCommonFilePath error");
                                if (inputStream != null) {
                                    try {
                                        inputStream.close();
                                    } catch (IOException e2) {
                                    }
                                }
                                if (fileOutputStream != null) {
                                    try {
                                        fileOutputStream.close();
                                    } catch (IOException e3) {
                                    }
                                }
                                str3 = null;
                            } catch (Throwable th) {
                                inputStreamOpen = inputStream;
                                FileOutputStream fileOutputStream4 = fileOutputStream;
                                th = th;
                                fileOutputStream2 = fileOutputStream4;
                                if (inputStreamOpen != null) {
                                    try {
                                        inputStreamOpen.close();
                                    } catch (IOException e4) {
                                    }
                                }
                                if (fileOutputStream2 != null) {
                                    throw th;
                                }
                                try {
                                    fileOutputStream2.close();
                                    throw th;
                                } catch (IOException e5) {
                                    throw th;
                                }
                            }
                        } catch (Throwable th2) {
                            th = th2;
                            fileOutputStream2 = fileOutputStream3;
                            if (inputStreamOpen != null) {
                                inputStreamOpen.close();
                            }
                            if (fileOutputStream2 != null) {
                                throw th;
                            }
                            fileOutputStream2.close();
                            throw th;
                        }
                    } catch (IOException e6) {
                        fileOutputStream = null;
                        inputStream = inputStreamOpen;
                    } catch (Throwable th3) {
                        th = th3;
                    }
                } else {
                    inputStreamOpen = null;
                }
                if (inputStreamOpen != null) {
                    try {
                        inputStreamOpen.close();
                    } catch (IOException e7) {
                    }
                }
                if (fileOutputStream2 != null) {
                    try {
                        fileOutputStream2.close();
                    } catch (IOException e8) {
                    }
                }
            } catch (IOException e9) {
                fileOutputStream = null;
                inputStream = null;
            } catch (Throwable th4) {
                th = th4;
                inputStreamOpen = null;
            }
        }
        return str3;
    }

    /* JADX INFO: renamed from: a */
    public static String m3578a(String str) {
        String lowerCase = str.substring(str.lastIndexOf(".") + 1, str.length()).toLowerCase();
        for (int i = 0; i < f7478b.length; i++) {
            if (lowerCase.equals(f7478b[i][0])) {
                return f7478b[i][1];
            }
        }
        return "/*";
    }

    /* JADX WARN: Code duplicated, block: B:17:0x0032  */
    /* JADX INFO: renamed from: a */
    public static final String m3579a(String str, String str2) {
        String strSubstring;
        int iLastIndexOf;
        String strDecode = Uri.decode(str);
        if (strDecode == null) {
            strSubstring = null;
        } else {
            int iIndexOf = strDecode.indexOf(63);
            if (iIndexOf > 0) {
                strDecode = strDecode.substring(0, iIndexOf);
            }
            if (strDecode.endsWith(CookieSpec.PATH_DELIM) || (iLastIndexOf = strDecode.lastIndexOf(47) + 1) <= 0) {
                strSubstring = null;
            } else {
                strSubstring = strDecode.substring(iLastIndexOf);
            }
        }
        if (strSubstring == null) {
            strSubstring = str2;
        }
        return strSubstring == null ? "downloadfile" : strSubstring;
    }

    /* JADX INFO: renamed from: a */
    private static String m3580a(byte[] bArr) {
        char[] cArr = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        char[] cArr2 = new char[bArr.length * 2];
        for (int i = 0; i < bArr.length; i++) {
            byte b = bArr[i];
            cArr2[i * 2] = cArr[(b >>> 4) & 15];
            cArr2[(i * 2) + 1] = cArr[b & 15];
        }
        return new String(cArr2);
    }

    /* JADX INFO: renamed from: a */
    public static List<String> m3581a(File file, List<String> list) {
        return m3582a(file, list, true);
    }

    /* JADX INFO: renamed from: a */
    public static List<String> m3582a(File file, List<String> list, boolean z) {
        if (ScriptHelper.providerSupportGetAllApkFiles()) {
            return ScriptHelper.provider().m3505a(file, list);
        }
        ArrayList arrayList = new ArrayList();
        C1299fu c1299fu = new C1299fu(list, z, arrayList);
        LinkedBlockingQueue linkedBlockingQueue = new LinkedBlockingQueue();
        File[] fileArrListFiles = file.listFiles(c1299fu);
        if (fileArrListFiles != null) {
            linkedBlockingQueue.addAll(Arrays.asList(fileArrListFiles));
        }
        while (linkedBlockingQueue.size() > 0) {
            File[] fileArrListFiles2 = ((File) linkedBlockingQueue.poll()).listFiles(c1299fu);
            if (fileArrListFiles2 != null) {
                linkedBlockingQueue.addAll(Arrays.asList(fileArrListFiles2));
            }
        }
        return arrayList;
    }

    /* JADX INFO: renamed from: a */
    public static void m3583a(File file) {
        if (file.exists()) {
            file.delete();
        }
    }

    /* JADX INFO: renamed from: a */
    public static void m3584a(ArrayList<String> arrayList, File file, String[] strArr) {
        if (file.exists()) {
            if (!file.isDirectory()) {
                if (file.getName().endsWith(".apk")) {
                    arrayList.add(file.getAbsolutePath());
                    return;
                }
                return;
            }
            if (strArr != null) {
                for (String str : strArr) {
                    if (file.getName().toLowerCase().contains(str)) {
                        return;
                    }
                }
            }
            File[] fileArrListFiles = file.listFiles();
            if (fileArrListFiles != null) {
                for (File file2 : fileArrListFiles) {
                    m3584a(arrayList, file2, strArr);
                }
            }
        }
    }

    /* JADX INFO: renamed from: a */
    public static boolean m3585a() {
        return Environment.getExternalStorageState().equals("mounted");
    }

    /* JADX WARN: Multi-variable type inference failed */
    /* JADX WARN: Type inference failed for: r1v12 */
    /* JADX WARN: Type inference failed for: r1v15 */
    /* JADX WARN: Type inference failed for: r1v16 */
    /* JADX WARN: Type inference failed for: r1v17 */
    /* JADX WARN: Type inference failed for: r1v18 */
    /* JADX WARN: Type inference failed for: r1v19 */
    /* JADX WARN: Type inference failed for: r1v2, types: [boolean] */
    /* JADX WARN: Type inference failed for: r1v20 */
    /* JADX WARN: Type inference failed for: r1v3 */
    /* JADX WARN: Type inference failed for: r1v4, types: [java.io.FileInputStream] */
    /* JADX WARN: Type inference failed for: r1v7 */
    /* JADX INFO: renamed from: a */
    public static synchronized byte[] m3586a(Context context, String str) {
        FileInputStream fileInputStream;
        byte[] bArrM3550a;
        File file = new File(m3577a(TMSApplication.getApplicaionContext(), str, (String) null));
        ?? Exists = file.exists();
        try {
            if (Exists == 0) {
                bArrM3550a = new byte[0];
            } else {
                try {
                    fileInputStream = new FileInputStream(file);
                    try {
                        bArrM3550a = C1332r.m3550a(fileInputStream);
                        Exists = fileInputStream;
                        if (fileInputStream != null) {
                            try {
                                fileInputStream.close();
                                Exists = fileInputStream;
                            } catch (IOException e) {
                                e.printStackTrace();
                                Exists = e;
                            }
                        }
                    } catch (IOException e2) {
                        bArrM3550a = new byte[0];
                        Exists = fileInputStream;
                        if (fileInputStream != null) {
                            try {
                                fileInputStream.close();
                                Exists = fileInputStream;
                            } catch (IOException e3) {
                                e3.printStackTrace();
                                Exists = e3;
                            }
                        }
                    }
                } catch (IOException e4) {
                    fileInputStream = null;
                } catch (Throwable th) {
                    Exists = 0;
                    th = th;
                    if (Exists != 0) {
                        try {
                            Exists.close();
                        } catch (IOException e5) {
                            e5.printStackTrace();
                        }
                    }
                    throw th;
                }
            }
        } catch (Throwable th2) {
            th = th2;
        }
        return bArrM3550a;
    }

    /* JADX INFO: renamed from: b */
    public static Object m3587b(Context context, String str, String str2) throws Throwable {
        FileInputStream fileInputStreamOpenFileInput;
        ByteArrayOutputStream byteArrayOutputStream;
        Object obj = null;
        if (str != null) {
            try {
                if (str2 != null) {
                    try {
                        fileInputStreamOpenFileInput = context.openFileInput(str2);
                        try {
                            byteArrayOutputStream = new ByteArrayOutputStream();
                            try {
                                byte[] bArr = new byte[1024];
                                while (true) {
                                    int i = fileInputStreamOpenFileInput.read(bArr);
                                    if (i == -1) {
                                        break;
                                    }
                                    byteArrayOutputStream.write(bArr, 0, i);
                                }
                                byte[] byteArray = byteArrayOutputStream.toByteArray();
                                UniAttribute uniAttribute = new UniAttribute();
                                uniAttribute.setEncodeName(InterfaceC0079b.f1213a);
                                uniAttribute.decode(TccCryptor.decrypt(context, byteArray, null));
                                obj = uniAttribute.get(str);
                                if (fileInputStreamOpenFileInput != null) {
                                    try {
                                        fileInputStreamOpenFileInput.close();
                                    } catch (IOException e) {
                                        e.printStackTrace();
                                    }
                                }
                                try {
                                    byteArrayOutputStream.close();
                                } catch (IOException e2) {
                                    e2.printStackTrace();
                                }
                            } catch (FileNotFoundException e3) {
                                e = e3;
                                e.printStackTrace();
                                if (fileInputStreamOpenFileInput != null) {
                                    try {
                                        fileInputStreamOpenFileInput.close();
                                    } catch (IOException e4) {
                                        e4.printStackTrace();
                                    }
                                }
                                if (byteArrayOutputStream != null) {
                                    try {
                                        byteArrayOutputStream.close();
                                    } catch (IOException e5) {
                                        e5.printStackTrace();
                                    }
                                }
                            } catch (IOException e6) {
                                e = e6;
                                e.printStackTrace();
                                if (fileInputStreamOpenFileInput != null) {
                                    try {
                                        fileInputStreamOpenFileInput.close();
                                    } catch (IOException e7) {
                                        e7.printStackTrace();
                                    }
                                }
                                if (byteArrayOutputStream != null) {
                                    try {
                                        byteArrayOutputStream.close();
                                    } catch (IOException e8) {
                                        e8.printStackTrace();
                                    }
                                }
                            } catch (Throwable th) {
                                th = th;
                                th.printStackTrace();
                                if (fileInputStreamOpenFileInput != null) {
                                    try {
                                        fileInputStreamOpenFileInput.close();
                                    } catch (IOException e9) {
                                        e9.printStackTrace();
                                    }
                                }
                                if (byteArrayOutputStream != null) {
                                    try {
                                        byteArrayOutputStream.close();
                                    } catch (IOException e10) {
                                        e10.printStackTrace();
                                    }
                                }
                            }
                        } catch (FileNotFoundException e11) {
                            e = e11;
                            byteArrayOutputStream = null;
                        } catch (IOException e12) {
                            e = e12;
                            byteArrayOutputStream = null;
                        } catch (Throwable th2) {
                            th = th2;
                            if (fileInputStreamOpenFileInput != null) {
                                try {
                                    fileInputStreamOpenFileInput.close();
                                } catch (IOException e13) {
                                    e13.printStackTrace();
                                }
                            }
                            if (obj != 0) {
                                try {
                                    obj.close();
                                } catch (IOException e14) {
                                    e14.printStackTrace();
                                }
                            }
                            throw th;
                        }
                    } catch (FileNotFoundException e15) {
                        e = e15;
                        byteArrayOutputStream = null;
                        fileInputStreamOpenFileInput = null;
                    } catch (IOException e16) {
                        e = e16;
                        byteArrayOutputStream = null;
                        fileInputStreamOpenFileInput = null;
                    } catch (Throwable th3) {
                        fileInputStreamOpenFileInput = null;
                        th = th3;
                    }
                }
            } catch (Throwable th4) {
                th = th4;
            }
        }
        return obj;
    }

    /* JADX INFO: renamed from: b */
    public static String m3588b(String str) {
        String strSubstring = null;
        int iLastIndexOf = str.lastIndexOf(CookieSpec.PATH_DELIM);
        if (iLastIndexOf != -1 && iLastIndexOf + 1 < str.length()) {
            strSubstring = str.substring(iLastIndexOf + 1);
        }
        Log.m2636i("QQWebSiteService", " QQWebSiteService lastIndex " + iLastIndexOf + " fileName " + strSubstring);
        return strSubstring;
    }

    /* JADX INFO: renamed from: b */
    public static void m3589b() {
        f7477a = true;
    }

    /* JADX WARN: Code duplicated, block: B:41:0x00aa  */
    /* JADX WARN: Multi-variable type inference failed */
    /* JADX WARN: Type inference failed for: r3v10 */
    /* JADX WARN: Type inference failed for: r3v11, types: [java.io.InputStream] */
    /* JADX WARN: Type inference failed for: r3v12 */
    /* JADX WARN: Type inference failed for: r3v13, types: [java.io.InputStream] */
    /* JADX WARN: Type inference failed for: r3v15 */
    /* JADX WARN: Type inference failed for: r3v16 */
    /* JADX WARN: Type inference failed for: r3v17 */
    /* JADX WARN: Type inference failed for: r3v18 */
    /* JADX WARN: Type inference failed for: r3v19 */
    /* JADX WARN: Type inference failed for: r3v3 */
    /* JADX WARN: Type inference failed for: r3v4, types: [java.io.InputStream] */
    /* JADX WARN: Type inference failed for: r3v5 */
    /* JADX WARN: Type inference failed for: r3v6 */
    /* JADX WARN: Type inference failed for: r3v7 */
    /* JADX WARN: Type inference failed for: r3v8, types: [java.io.InputStream] */
    /* JADX WARN: Type inference failed for: r3v9 */
    /* JADX INFO: renamed from: b */
    private static boolean m3590b(Context context) {
        String str = context.getFilesDir() + File.separator + UpdateConfig.SMS_CHECKER_NAME;
        if (!new File(str).exists()) {
            return true;
        }
        ?? Open = 0;
        Open = 0;
        Open = 0;
        try {
            try {
                Open = context.getAssets().open(UpdateConfig.SMS_CHECKER_NAME);
                byte[] bArr = new byte[12];
                Open.read(bArr);
                int i = ((bArr[9] & 255) << 24) | (bArr[6] & 255) | ((bArr[7] & 255) << 8) | ((bArr[8] & 255) << 16);
                if (Open != 0) {
                    try {
                        Open.close();
                        Open = i;
                    } catch (IOException e) {
                        e.printStackTrace();
                        Open = i;
                    }
                } else {
                    Open = i;
                }
            } catch (IOException e2) {
                e2.printStackTrace();
                if (Open != 0) {
                    try {
                        Open.close();
                        Open = 0;
                    } catch (IOException e3) {
                        e3.printStackTrace();
                        Open = 0;
                    }
                } else {
                    Open = 0;
                }
            } catch (Exception e4) {
                e4.printStackTrace();
                if (Open != 0) {
                    try {
                        Open.close();
                        Open = 0;
                    } catch (IOException e5) {
                        e5.printStackTrace();
                        Open = 0;
                    }
                } else {
                    Open = 0;
                }
            }
            if (Open == 0) {
                return false;
            }
            ConfInfo smsCheckerConfInfo = UpdateUtil.getSmsCheckerConfInfo(context, str);
            return Open > (smsCheckerConfInfo != null ? smsCheckerConfInfo.getTimestamp() : 0);
        } catch (Throwable th) {
            if (Open != 0) {
                try {
                    Open.close();
                } catch (IOException e6) {
                    e6.printStackTrace();
                }
            }
            throw th;
        }
    }

    /* JADX WARN: Code duplicated, block: B:70:0x0067 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX INFO: renamed from: b */
    private static boolean m3591b(Context context, String str) throws Throwable {
        InputStream inputStreamOpen;
        int i;
        int iM3568b;
        FileInputStream fileInputStream = null;
        File file = new File(TMSApplication.getApplicaionContext().getFilesDir() + File.separator + str);
        if (!file.exists()) {
            return true;
        }
        try {
            inputStreamOpen = context.getResources().getAssets().open(str, 1);
            try {
                try {
                    int iM3568b2 = C1335u.m3572a(inputStreamOpen).m3568b();
                    if (inputStreamOpen != null) {
                        try {
                            inputStreamOpen.close();
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                        i = iM3568b2;
                    } else {
                        i = iM3568b2;
                    }
                } catch (Exception e2) {
                    e = e2;
                    e.printStackTrace();
                    if (inputStreamOpen != null) {
                        try {
                            inputStreamOpen.close();
                        } catch (IOException e3) {
                            e3.printStackTrace();
                        }
                        i = 0;
                    } else {
                        i = 0;
                    }
                }
            } catch (Throwable th) {
                th = th;
                if (inputStreamOpen != null) {
                    try {
                        inputStreamOpen.close();
                    } catch (IOException e4) {
                        e4.printStackTrace();
                    }
                }
                throw th;
            }
        } catch (Exception e5) {
            e = e5;
            inputStreamOpen = null;
        } catch (Throwable th2) {
            th = th2;
            inputStreamOpen = null;
            if (inputStreamOpen != null) {
                inputStreamOpen.close();
            }
            throw th;
        }
        if (i == 0) {
            return false;
        }
        try {
            try {
                FileInputStream fileInputStream2 = new FileInputStream(file);
                try {
                    iM3568b = C1335u.m3572a(fileInputStream2).m3568b();
                    if (fileInputStream2 != null) {
                        try {
                            fileInputStream2.close();
                        } catch (IOException e6) {
                            e6.printStackTrace();
                        }
                    }
                } catch (Exception e7) {
                    e = e7;
                    fileInputStream = fileInputStream2;
                    e.printStackTrace();
                    if (fileInputStream != null) {
                        try {
                            fileInputStream.close();
                        } catch (IOException e8) {
                            e8.printStackTrace();
                        }
                        iM3568b = 0;
                    } else {
                        iM3568b = 0;
                    }
                } catch (Throwable th3) {
                    th = th3;
                    fileInputStream = fileInputStream2;
                    if (fileInputStream != null) {
                        try {
                            fileInputStream.close();
                        } catch (IOException e9) {
                            e9.printStackTrace();
                        }
                    }
                    throw th;
                }
            } catch (Exception e10) {
                e = e10;
            }
            return i > iM3568b;
        } catch (Throwable th4) {
            th = th4;
        }
    }

    /* JADX WARN: Code duplicated, block: B:66:0x0063 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:68:0x005e A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:88:? A[SYNTHETIC] */
    /* JADX INFO: renamed from: b */
    public static boolean m3592b(String str, String str2) throws Throwable {
        FileInputStream fileInputStream;
        FileOutputStream fileOutputStream;
        FileOutputStream fileOutputStream2 = null;
        fileOutputStream2 = null;
        FileInputStream fileInputStream2 = null;
        if (str == null || str.length() == 0) {
            return false;
        }
        File file = new File(str);
        if (!file.exists() || !file.canRead()) {
            return false;
        }
        try {
            File file2 = new File(str2);
            m3583a(file2);
            fileInputStream = new FileInputStream(file);
            try {
                fileOutputStream = new FileOutputStream(file2);
                try {
                    byte[] bArr = new byte[8192];
                    while (true) {
                        int i = fileInputStream.read(bArr);
                        if (i <= 0) {
                            break;
                        }
                        fileOutputStream.write(bArr, 0, i);
                    }
                    fileOutputStream.flush();
                    try {
                        fileInputStream.close();
                    } catch (IOException e) {
                    }
                    try {
                        fileOutputStream.close();
                    } catch (IOException e2) {
                    }
                    return true;
                } catch (IOException e3) {
                    e = e3;
                    fileInputStream2 = fileInputStream;
                    try {
                        e.printStackTrace();
                        if (fileInputStream2 != null) {
                            try {
                                fileInputStream2.close();
                            } catch (IOException e4) {
                            }
                        }
                        if (fileOutputStream == null) {
                            return false;
                        }
                        try {
                            fileOutputStream.close();
                            return false;
                        } catch (IOException e5) {
                            return false;
                        }
                    } catch (Throwable th) {
                        th = th;
                        fileInputStream = fileInputStream2;
                        fileOutputStream2 = fileOutputStream;
                        if (fileInputStream != null) {
                            try {
                                fileInputStream.close();
                            } catch (IOException e6) {
                            }
                        }
                        if (fileOutputStream2 != null) {
                            throw th;
                        }
                        try {
                            fileOutputStream2.close();
                            throw th;
                        } catch (IOException e7) {
                            throw th;
                        }
                    }
                } catch (Throwable th2) {
                    th = th2;
                    fileOutputStream2 = fileOutputStream;
                    if (fileInputStream != null) {
                        fileInputStream.close();
                    }
                    if (fileOutputStream2 != null) {
                        throw th;
                    }
                    fileOutputStream2.close();
                    throw th;
                }
            } catch (IOException e8) {
                e = e8;
                fileOutputStream = null;
                fileInputStream2 = fileInputStream;
            } catch (Throwable th3) {
                th = th3;
            }
        } catch (IOException e9) {
            e = e9;
            fileOutputStream = null;
        } catch (Throwable th4) {
            th = th4;
            fileInputStream = null;
        }
    }

    /* JADX INFO: renamed from: b */
    public static String[] m3593b(File file) throws Throwable {
        BufferedInputStream bufferedInputStream;
        Throwable th;
        ByteArrayOutputStream byteArrayOutputStream;
        String[] strArrSplit = null;
        try {
            try {
                bufferedInputStream = new BufferedInputStream(new FileInputStream(file));
                try {
                    byteArrayOutputStream = new ByteArrayOutputStream();
                    try {
                        byte[] bArr = new byte[1024];
                        while (true) {
                            int i = bufferedInputStream.read(bArr);
                            if (i == -1) {
                                break;
                            }
                            byteArrayOutputStream.write(bArr, 0, i);
                        }
                        strArrSplit = new String(byteArrayOutputStream.toByteArray()).split("\\n");
                        if (bufferedInputStream != null) {
                            try {
                                bufferedInputStream.close();
                            } catch (IOException e) {
                                e.printStackTrace();
                            }
                        }
                        if (byteArrayOutputStream != null) {
                            try {
                                byteArrayOutputStream.close();
                            } catch (IOException e2) {
                                e2.printStackTrace();
                            }
                        }
                    } catch (FileNotFoundException e3) {
                        e = e3;
                        e.printStackTrace();
                        if (bufferedInputStream != null) {
                            try {
                                bufferedInputStream.close();
                            } catch (IOException e4) {
                                e4.printStackTrace();
                            }
                        }
                        if (byteArrayOutputStream != null) {
                            try {
                                byteArrayOutputStream.close();
                            } catch (IOException e5) {
                                e5.printStackTrace();
                            }
                        }
                    } catch (IOException e6) {
                        e = e6;
                        e.printStackTrace();
                        if (bufferedInputStream != null) {
                            try {
                                bufferedInputStream.close();
                            } catch (IOException e7) {
                                e7.printStackTrace();
                            }
                        }
                        if (byteArrayOutputStream != null) {
                            try {
                                byteArrayOutputStream.close();
                            } catch (IOException e8) {
                                e8.printStackTrace();
                            }
                        }
                    }
                } catch (FileNotFoundException e9) {
                    e = e9;
                    byteArrayOutputStream = null;
                } catch (IOException e10) {
                    e = e10;
                    byteArrayOutputStream = null;
                } catch (Throwable th2) {
                    th = th2;
                    if (bufferedInputStream != null) {
                        try {
                            bufferedInputStream.close();
                        } catch (IOException e11) {
                            e11.printStackTrace();
                        }
                    }
                    if (strArrSplit != 0) {
                        try {
                            strArrSplit.close();
                        } catch (IOException e12) {
                            e12.printStackTrace();
                        }
                    }
                    throw th;
                }
            } catch (Throwable th3) {
                th = th3;
            }
        } catch (FileNotFoundException e13) {
            e = e13;
            byteArrayOutputStream = null;
            bufferedInputStream = null;
        } catch (IOException e14) {
            e = e14;
            byteArrayOutputStream = null;
            bufferedInputStream = null;
        } catch (Throwable th4) {
            bufferedInputStream = null;
            th = th4;
        }
        return strArrSplit;
    }

    /* JADX INFO: renamed from: c */
    public static String m3594c() {
        return Environment.getExternalStorageState().equals("mounted") ? Environment.getExternalStorageDirectory().getPath() : "/sdcard";
    }

    /* JADX INFO: renamed from: c */
    public static String m3595c(File file) throws Throwable {
        FileInputStream fileInputStream;
        Throwable th;
        String strM3580a = null;
        f7477a = false;
        try {
            MessageDigest messageDigest = MessageDigest.getInstance("MD5");
            fileInputStream = new FileInputStream(file);
            try {
                byte[] bArr = new byte[8192];
                while (true) {
                    int i = fileInputStream.read(bArr);
                    if (i == -1) {
                        strM3580a = m3580a(messageDigest.digest());
                        try {
                            fileInputStream.close();
                            break;
                        } catch (IOException e) {
                            break;
                        }
                    }
                    if (f7477a) {
                        try {
                            fileInputStream.close();
                            break;
                        } catch (IOException e2) {
                        }
                    } else {
                        messageDigest.update(bArr, 0, i);
                    }
                }
            } catch (IOException e3) {
                if (fileInputStream != null) {
                    try {
                        fileInputStream.close();
                    } catch (IOException e4) {
                    }
                }
            } catch (NoSuchAlgorithmException e5) {
                if (fileInputStream != null) {
                    try {
                        fileInputStream.close();
                    } catch (IOException e6) {
                    }
                }
            } catch (Throwable th2) {
                th = th2;
                if (fileInputStream != null) {
                    try {
                        fileInputStream.close();
                    } catch (IOException e7) {
                    }
                }
                throw th;
            }
        } catch (IOException e8) {
            fileInputStream = null;
        } catch (NoSuchAlgorithmException e9) {
            fileInputStream = null;
        } catch (Throwable th3) {
            fileInputStream = null;
            th = th3;
        }
        return strM3580a;
    }

    /* JADX INFO: renamed from: c */
    public static String m3596c(String str) {
        String strSubstring = null;
        int iLastIndexOf = str.lastIndexOf(CookieSpec.PATH_DELIM);
        if (iLastIndexOf != -1 && iLastIndexOf + 1 < str.length()) {
            strSubstring = str.substring(0, iLastIndexOf);
        }
        Log.m2636i("QQWebSiteService", " QQWebSiteService lastIndex " + iLastIndexOf + " fileParentDir " + strSubstring);
        return strSubstring;
    }

    /* JADX WARN: Code duplicated, block: B:63:0x0104 A[PHI: r3 r4
  0x0104: PHI (r3v11 int) = (r3v10 int), (r3v12 int) binds: [B:34:0x00c8, B:26:0x00b5] A[DONT_GENERATE, DONT_INLINE]
  0x0104: PHI (r4v9 java.io.InputStream) = (r4v25 java.io.InputStream), (r4v26 java.io.InputStream) binds: [B:34:0x00c8, B:26:0x00b5] A[DONT_GENERATE, DONT_INLINE]] */
    /* JADX WARN: Code duplicated, block: B:70:0x00d9 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Multi-variable type inference failed */
    /* JADX WARN: Type inference failed for: r2v0, types: [tms.af] */
    /* JADX WARN: Type inference failed for: r3v2, types: [java.lang.String] */
    /* JADX WARN: Type inference failed for: r4v11 */
    /* JADX WARN: Type inference failed for: r4v17 */
    /* JADX WARN: Type inference failed for: r4v18 */
    /* JADX WARN: Type inference failed for: r4v19 */
    /* JADX WARN: Type inference failed for: r4v2, types: [java.lang.Object, java.lang.String] */
    /* JADX WARN: Type inference failed for: r4v20 */
    /* JADX WARN: Type inference failed for: r4v21 */
    /* JADX WARN: Type inference failed for: r4v22 */
    /* JADX WARN: Type inference failed for: r4v23 */
    /* JADX WARN: Type inference failed for: r4v24 */
    /* JADX WARN: Type inference failed for: r4v3 */
    /* JADX WARN: Type inference failed for: r4v6, types: [java.io.InputStream] */
    /* JADX WARN: Type inference failed for: r4v7 */
    /* JADX INFO: renamed from: c */
    private static boolean m3597c(Context context) throws Throwable {
        boolean z;
        InputStream inputStreamOpen;
        int i;
        int i2;
        InputStream inputStream;
        ?? c1149af = new C1149af("tms");
        ?? M2883a = c1149af.m2883a("soft_version", "");
        ?? strFromEnvMap = TMSApplication.getStrFromEnvMap(TMSApplication.CON_SOFTVERSION);
        if (M2883a.equals(strFromEnvMap)) {
            z = false;
        } else {
            c1149af.m2888a("soft_version", strFromEnvMap, true);
            z = true;
        }
        if (z) {
            return true;
        }
        String str = context.getFilesDir() + File.separator + UpdateConfig.VIRUS_BASE_NAME;
        if (!new File(str).exists()) {
            return true;
        }
        try {
            try {
                inputStreamOpen = context.getAssets().open(UpdateConfig.VIRUS_BASE_NAME);
                try {
                    byte[] bArr = new byte[28];
                    inputStreamOpen.read(bArr);
                    i = (bArr[4] & 255) | ((bArr[5] & 255) << 8) | ((bArr[6] & 255) << 16) | ((bArr[7] & 255) << 24);
                    try {
                        i2 = ((bArr[27] & 255) << 24) | (bArr[24] & 255) | ((bArr[25] & 255) << 8) | ((bArr[26] & 255) << 16);
                        strFromEnvMap = inputStreamOpen;
                        if (inputStreamOpen != null) {
                            try {
                                inputStreamOpen.close();
                                strFromEnvMap = inputStreamOpen;
                            } catch (IOException e) {
                                e.printStackTrace();
                                strFromEnvMap = e;
                            }
                        }
                    } catch (IOException e2) {
                        e = e2;
                        e.printStackTrace();
                        inputStream = inputStreamOpen;
                        if (inputStreamOpen != null) {
                            try {
                                inputStreamOpen.close();
                                i2 = 0;
                                strFromEnvMap = inputStreamOpen;
                            } catch (IOException e3) {
                                e3.printStackTrace();
                                i2 = 0;
                                strFromEnvMap = inputStreamOpen;
                            }
                        } else {
                            i2 = 0;
                            strFromEnvMap = inputStream;
                        }
                    } catch (Exception e4) {
                        e = e4;
                        e.printStackTrace();
                        inputStream = inputStreamOpen;
                        if (inputStreamOpen != null) {
                            try {
                                inputStreamOpen.close();
                                i2 = 0;
                                strFromEnvMap = inputStreamOpen;
                            } catch (IOException e5) {
                                e5.printStackTrace();
                                i2 = 0;
                                strFromEnvMap = inputStreamOpen;
                            }
                        } else {
                            i2 = 0;
                            strFromEnvMap = inputStream;
                        }
                    }
                } catch (IOException e6) {
                    e = e6;
                    i = 0;
                } catch (Exception e7) {
                    e = e7;
                    i = 0;
                }
            } catch (Throwable th) {
                th = th;
                if (strFromEnvMap != 0) {
                    try {
                        strFromEnvMap.close();
                    } catch (IOException e8) {
                        e8.printStackTrace();
                    }
                }
                throw th;
            }
        } catch (IOException e9) {
            e = e9;
            inputStreamOpen = null;
            i = 0;
        } catch (Exception e10) {
            e = e10;
            inputStreamOpen = null;
            i = 0;
        } catch (Throwable th2) {
            th = th2;
            strFromEnvMap = 0;
            if (strFromEnvMap != 0) {
                strFromEnvMap.close();
            }
            throw th;
        }
        if (i2 == 0) {
            return false;
        }
        VirusClientInfo virusClientInfoLoadAmfHeader = AmScanner.loadAmfHeader(context, str);
        if (virusClientInfoLoadAmfHeader != null) {
            return i != virusClientInfoLoadAmfHeader.getVersion() || i2 > virusClientInfoLoadAmfHeader.getTimestamp();
        }
        return true;
    }

    /* JADX INFO: renamed from: d */
    public static String m3598d(File file) throws Throwable {
        FileInputStream fileInputStream;
        Throwable th;
        String strM3580a = null;
        f7477a = false;
        try {
            MessageDigest messageDigest = MessageDigest.getInstance("SHA");
            fileInputStream = new FileInputStream(file);
            try {
                byte[] bArr = new byte[8192];
                while (true) {
                    int i = fileInputStream.read(bArr);
                    if (i == -1) {
                        strM3580a = m3580a(messageDigest.digest());
                        try {
                            fileInputStream.close();
                            break;
                        } catch (IOException e) {
                            break;
                        }
                    }
                    if (f7477a) {
                        try {
                            fileInputStream.close();
                            break;
                        } catch (IOException e2) {
                        }
                    } else {
                        messageDigest.update(bArr, 0, i);
                    }
                }
            } catch (IOException e3) {
                if (fileInputStream != null) {
                    try {
                        fileInputStream.close();
                    } catch (IOException e4) {
                    }
                }
            } catch (NoSuchAlgorithmException e5) {
                if (fileInputStream != null) {
                    try {
                        fileInputStream.close();
                    } catch (IOException e6) {
                    }
                }
            } catch (Throwable th2) {
                th = th2;
                if (fileInputStream != null) {
                    try {
                        fileInputStream.close();
                    } catch (IOException e7) {
                    }
                }
                throw th;
            }
        } catch (IOException e8) {
            fileInputStream = null;
        } catch (NoSuchAlgorithmException e9) {
            fileInputStream = null;
        } catch (Throwable th3) {
            fileInputStream = null;
            th = th3;
        }
        return strM3580a;
    }

    /* JADX INFO: renamed from: d */
    public static boolean m3599d(String str) {
        return (str.indexOf("\\") == -1 && str.indexOf(CookieSpec.PATH_DELIM) == -1 && str.indexOf(C0092c.f1283N) == -1 && str.indexOf(CharacterSets.MIMENAME_ANY_CHARSET) == -1 && str.indexOf("?") == -1 && str.indexOf(C0092c.f1282M) == -1 && str.indexOf("<") == -1 && str.indexOf(">") == -1 && str.indexOf("|") == -1) ? false : true;
    }

    /* JADX INFO: renamed from: e */
    public static boolean m3601e(String str) {
        File file = new File(str);
        if (file.exists()) {
            return file.isFile() ? m3603f(str) : m3604g(str);
        }
        return false;
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: f */
    public static boolean m3602f(File file) throws Throwable {
        DataInputStream dataInputStream;
        boolean z = false;
        DataInputStream dataInputStream2 = null;
        if (!file.isDirectory() && file.length() > 4) {
            try {
                dataInputStream = new DataInputStream(new FileInputStream(file));
                try {
                    z = dataInputStream.readInt() == 1347093252;
                    try {
                        dataInputStream.close();
                    } catch (IOException e) {
                    }
                } catch (IOException e2) {
                    if (dataInputStream != null) {
                        try {
                            dataInputStream.close();
                        } catch (IOException e3) {
                        }
                    }
                } catch (Throwable th) {
                    th = th;
                    dataInputStream2 = dataInputStream;
                    if (dataInputStream2 != null) {
                        try {
                            dataInputStream2.close();
                        } catch (IOException e4) {
                        }
                    }
                    throw th;
                }
            } catch (IOException e5) {
                dataInputStream = null;
            } catch (Throwable th2) {
                th = th2;
            }
        }
        return z;
    }

    /* JADX INFO: renamed from: f */
    public static boolean m3603f(String str) {
        try {
            return new File(str).delete();
        } catch (Exception e) {
            return false;
        }
    }

    /* JADX INFO: renamed from: g */
    public static boolean m3604g(String str) {
        if (!str.endsWith(File.separator)) {
            str = str + File.separator;
        }
        File file = new File(str);
        if (!file.exists() || !file.isDirectory()) {
            return false;
        }
        File[] fileArrListFiles = file.listFiles();
        if (fileArrListFiles == null) {
            return file.delete();
        }
        boolean zM3604g = true;
        int length = fileArrListFiles.length;
        for (int i = 0; i < length; i++) {
            if (!fileArrListFiles[i].isFile()) {
                zM3604g = m3604g(fileArrListFiles[i].getAbsolutePath());
                if (!zM3604g) {
                    break;
                }
            } else {
                zM3604g = m3603f(fileArrListFiles[i].getAbsolutePath());
                if (!zM3604g) {
                    break;
                }
            }
        }
        if (zM3604g) {
            return file.delete();
        }
        return false;
    }

    /* JADX INFO: renamed from: h */
    public static boolean m3605h(String str) {
        return new File(str).exists();
    }

    /* JADX WARN: Code duplicated, block: B:84:0x007f A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:88:0x007a A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX INFO: renamed from: i */
    public static String m3606i(String str) throws Throwable {
        ByteArrayOutputStream byteArrayOutputStream;
        BufferedInputStream bufferedInputStream;
        BufferedInputStream bufferedInputStream2 = null;
        try {
            try {
                bufferedInputStream = new BufferedInputStream(new FileInputStream(str));
                try {
                    byteArrayOutputStream = new ByteArrayOutputStream();
                    try {
                        byte[] bArr = new byte[1024];
                        while (true) {
                            int i = bufferedInputStream.read(bArr);
                            if (i == -1) {
                                break;
                            }
                            byteArrayOutputStream.write(bArr, 0, i);
                        }
                        String str2 = new String(byteArrayOutputStream.toByteArray());
                        if (byteArrayOutputStream != null) {
                            try {
                                byteArrayOutputStream.close();
                            } catch (IOException e) {
                                e.printStackTrace();
                            }
                        }
                        if (bufferedInputStream == null) {
                            return str2;
                        }
                        try {
                            bufferedInputStream.close();
                            return str2;
                        } catch (IOException e2) {
                            e2.printStackTrace();
                            return str2;
                        }
                    } catch (FileNotFoundException e3) {
                        e = e3;
                        bufferedInputStream2 = bufferedInputStream;
                        try {
                            e.printStackTrace();
                            if (byteArrayOutputStream != null) {
                                try {
                                    byteArrayOutputStream.close();
                                } catch (IOException e4) {
                                    e4.printStackTrace();
                                }
                            }
                            if (bufferedInputStream2 != null) {
                                try {
                                    bufferedInputStream2.close();
                                } catch (IOException e5) {
                                    e5.printStackTrace();
                                }
                            }
                            return "";
                        } catch (Throwable th) {
                            th = th;
                            bufferedInputStream = bufferedInputStream2;
                            if (byteArrayOutputStream != null) {
                                try {
                                    byteArrayOutputStream.close();
                                } catch (IOException e6) {
                                    e6.printStackTrace();
                                }
                            }
                            if (bufferedInputStream != null) {
                                try {
                                    bufferedInputStream.close();
                                } catch (IOException e7) {
                                    e7.printStackTrace();
                                }
                            }
                            throw th;
                        }
                    } catch (IOException e8) {
                        e = e8;
                        e.printStackTrace();
                        if (byteArrayOutputStream != null) {
                            try {
                                byteArrayOutputStream.close();
                            } catch (IOException e9) {
                                e9.printStackTrace();
                            }
                        }
                        if (bufferedInputStream != null) {
                            try {
                                bufferedInputStream.close();
                            } catch (IOException e10) {
                                e10.printStackTrace();
                            }
                        }
                        return "";
                    }
                } catch (FileNotFoundException e11) {
                    e = e11;
                    byteArrayOutputStream = null;
                    bufferedInputStream2 = bufferedInputStream;
                } catch (IOException e12) {
                    e = e12;
                    byteArrayOutputStream = null;
                } catch (Throwable th2) {
                    th = th2;
                    byteArrayOutputStream = null;
                    if (byteArrayOutputStream != null) {
                        byteArrayOutputStream.close();
                    }
                    if (bufferedInputStream != null) {
                        bufferedInputStream.close();
                    }
                    throw th;
                }
            } catch (Throwable th3) {
                th = th3;
            }
        } catch (FileNotFoundException e13) {
            e = e13;
            byteArrayOutputStream = null;
        } catch (IOException e14) {
            e = e14;
            byteArrayOutputStream = null;
            bufferedInputStream = null;
        } catch (Throwable th4) {
            th = th4;
            byteArrayOutputStream = null;
            bufferedInputStream = null;
        }
    }

    /* JADX INFO: renamed from: j */
    public static String[] m3607j(String str) throws Throwable {
        BufferedInputStream bufferedInputStream;
        Throwable th;
        ByteArrayOutputStream byteArrayOutputStream;
        String[] strArrSplit = null;
        try {
            try {
                bufferedInputStream = new BufferedInputStream(new FileInputStream(str));
                try {
                    byteArrayOutputStream = new ByteArrayOutputStream();
                    try {
                        byte[] bArr = new byte[1024];
                        while (true) {
                            int i = bufferedInputStream.read(bArr);
                            if (i == -1) {
                                break;
                            }
                            byteArrayOutputStream.write(bArr, 0, i);
                        }
                        strArrSplit = new String(byteArrayOutputStream.toByteArray()).split("\\n");
                        if (bufferedInputStream != null) {
                            try {
                                bufferedInputStream.close();
                            } catch (IOException e) {
                                e.printStackTrace();
                            }
                        }
                        if (byteArrayOutputStream != null) {
                            try {
                                byteArrayOutputStream.close();
                            } catch (IOException e2) {
                                e2.printStackTrace();
                            }
                        }
                    } catch (FileNotFoundException e3) {
                        e = e3;
                        e.printStackTrace();
                        if (bufferedInputStream != null) {
                            try {
                                bufferedInputStream.close();
                            } catch (IOException e4) {
                                e4.printStackTrace();
                            }
                        }
                        if (byteArrayOutputStream != null) {
                            try {
                                byteArrayOutputStream.close();
                            } catch (IOException e5) {
                                e5.printStackTrace();
                            }
                        }
                    } catch (IOException e6) {
                        e = e6;
                        e.printStackTrace();
                        if (bufferedInputStream != null) {
                            try {
                                bufferedInputStream.close();
                            } catch (IOException e7) {
                                e7.printStackTrace();
                            }
                        }
                        if (byteArrayOutputStream != null) {
                            try {
                                byteArrayOutputStream.close();
                            } catch (IOException e8) {
                                e8.printStackTrace();
                            }
                        }
                    }
                } catch (FileNotFoundException e9) {
                    e = e9;
                    byteArrayOutputStream = null;
                } catch (IOException e10) {
                    e = e10;
                    byteArrayOutputStream = null;
                } catch (Throwable th2) {
                    th = th2;
                    if (bufferedInputStream != null) {
                        try {
                            bufferedInputStream.close();
                        } catch (IOException e11) {
                            e11.printStackTrace();
                        }
                    }
                    if (strArrSplit != 0) {
                        try {
                            strArrSplit.close();
                        } catch (IOException e12) {
                            e12.printStackTrace();
                        }
                    }
                    throw th;
                }
            } catch (Throwable th3) {
                th = th3;
            }
        } catch (FileNotFoundException e13) {
            e = e13;
            byteArrayOutputStream = null;
            bufferedInputStream = null;
        } catch (IOException e14) {
            e = e14;
            byteArrayOutputStream = null;
            bufferedInputStream = null;
        } catch (Throwable th4) {
            bufferedInputStream = null;
            th = th4;
        }
        return strArrSplit;
    }
}
