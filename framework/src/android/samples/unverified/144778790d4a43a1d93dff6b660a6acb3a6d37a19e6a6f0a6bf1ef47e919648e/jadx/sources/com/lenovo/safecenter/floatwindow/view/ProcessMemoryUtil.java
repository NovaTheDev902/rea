package com.lenovo.safecenter.floatwindow.view;

import android.util.Log;
import com.lenovo.performancecenter.framework.DatabaseTables;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class ProcessMemoryUtil {

    /* JADX INFO: renamed from: a */
    private List<String[]> f3683a = null;

    public ProcessMemoryUtil() {
        initPMUtil();
    }

    /* JADX INFO: renamed from: a */
    private static String m1555a() {
        Log.i("fetch_process_info", "start. . . . ");
        CMDExecute cmdexe = new CMDExecute();
        try {
            String[] args = {"/system/bin/top", "-n", DatabaseTables.SYSTEM_MARK};
            String result = cmdexe.run(args, "/system/bin/");
            return result;
        } catch (IOException ex) {
            Log.i("fetch_process_info", "ex=" + ex.toString());
            return null;
        }
    }

    /* JADX INFO: renamed from: a */
    private int m1554a(String infoString) {
        boolean bIsProcInfo = false;
        String[] rows = infoString.split("[\n]+");
        Log.d("yhh", "rows" + rows.length);
        for (String tempString : rows) {
            if (tempString.indexOf("PID") == -1) {
                if (bIsProcInfo) {
                    String[] columns = tempString.trim().split("[ ]+");
                    if (columns.length == 9) {
                        this.f3683a.add(columns);
                    }
                }
            } else {
                bIsProcInfo = true;
            }
        }
        return this.f3683a.size();
    }

    public void initPMUtil() {
        this.f3683a = new ArrayList();
        String resultString = m1555a();
        m1554a(resultString);
    }

    public String getMemInfoByName(String procName) {
        initPMUtil();
        String result = "";
        for (String[] item : this.f3683a) {
            String tempString = item[8];
            if (tempString != null && tempString.equals(procName)) {
                result = "CPU:" + item[1] + "  Mem:" + item[5];
                break;
            }
        }
        Log.d("yhh", "memoryresult" + result);
        return result;
    }

    public String getMemInfoByPid(int pid) {
        int count = this.f3683a.size();
        for (int i = 0; i < count; i++) {
            String[] item = this.f3683a.get(i);
            String tempPidString = item[0];
            if (tempPidString != null) {
                int tempPid = Integer.parseInt(tempPidString);
                if (tempPid == pid) {
                    String result = "CPU:" + item[1] + "  Mem:" + item[5];
                    return result;
                }
            }
        }
        return "";
    }
}
