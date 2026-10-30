package com.lenovo.lps.reaper.sdk.request;

import com.lenovo.lps.reaper.sdk.util.TLog;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.RejectedExecutionException;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

/* JADX INFO: loaded from: classes.dex */
public class TaskHandler {

    /* JADX INFO: renamed from: b */
    private static TaskHandler f1146b = new TaskHandler();

    /* JADX INFO: renamed from: a */
    private final ThreadPoolExecutor f1147a = new ThreadPoolExecutor(10, 10, 0, TimeUnit.SECONDS, new LinkedBlockingQueue(1000));

    public static TaskHandler getInstance() {
        return f1146b;
    }

    public void addTask(Runnable task) {
        try {
            this.f1147a.submit(task);
        } catch (RejectedExecutionException e) {
            TLog.m241e("TaskHandler", "Too Many Task At a Time. Please Wait...");
        } catch (Exception e2) {
            TLog.m242e("TaskHandler", e2.getMessage(), e2);
        }
    }
}
