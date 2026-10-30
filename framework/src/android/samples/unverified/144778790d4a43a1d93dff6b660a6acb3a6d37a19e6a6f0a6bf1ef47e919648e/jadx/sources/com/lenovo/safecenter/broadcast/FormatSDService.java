package com.lenovo.safecenter.broadcast;

import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.os.Environment;
import android.os.IBinder;
import android.os.RemoteException;
import android.os.ServiceManager;
import android.os.storage.IMountService;
import android.util.Log;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class FormatSDService extends Service {

    /* JADX INFO: renamed from: a */
    private IMountService f3396a;

    /* JADX INFO: renamed from: b */
    private boolean f3397b = false;

    /* JADX INFO: renamed from: c */
    private Method f3398c;

    @Override // android.app.Service
    public IBinder onBind(Intent intent) {
        return null;
    }

    /* JADX WARN: Type inference failed for: r0v3, types: [com.lenovo.safecenter.broadcast.FormatSDService$1] */
    @Override // android.app.Service
    public void onStart(Intent intent, int startId) {
        super.onStart(intent, startId);
        this.f3397b = true;
        Log.e("ydp", "in FormatSDService");
        this.f3396a = m1450b();
        new Thread() { // from class: com.lenovo.safecenter.broadcast.FormatSDService.1
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() throws Throwable {
                FormatSDService.this.formatSDcard(FormatSDService.this.getApplicationContext());
            }
        }.start();
    }

    /* JADX WARN: Code duplicated, block: B:15:0x007b A[Catch: RemoteException -> 0x00a2, TRY_LEAVE, TryCatch #0 {RemoteException -> 0x00a2, blocks: (B:13:0x0074, B:15:0x007b), top: B:24:0x0074 }] */
    public void formatSDcard(Context context) throws Throwable {
        ArrayList<String> extendStorageList = m1448a();
        String extraExtendStorage = null;
        String innerExtendStorage = null;
        if (extendStorageList.size() == 2) {
            if (extendStorageList.get(0).equals(Environment.getExternalStorageDirectory().getPath())) {
                innerExtendStorage = Environment.getExternalStorageDirectory().getPath();
                extraExtendStorage = extendStorageList.get(1);
            } else {
                innerExtendStorage = Environment.getExternalStorageDirectory().getPath();
                extraExtendStorage = extendStorageList.get(0);
            }
        } else if (extendStorageList.size() == 1) {
            innerExtendStorage = Environment.getExternalStorageDirectory().getPath();
        }
        Log.i("ydp", "format sdcard");
        Log.i("ydp", "extraExtendStorage sdcard : " + extraExtendStorage);
        Log.i("ydp", "innerExtendStorage sdcard : " + innerExtendStorage);
        if (extraExtendStorage != null) {
            m1449a(extraExtendStorage);
        }
        if (innerExtendStorage != null) {
            m1449a(innerExtendStorage);
        }
        if (innerExtendStorage != null) {
            try {
                this.f3396a.mountVolume(innerExtendStorage);
                if (extraExtendStorage != null) {
                    this.f3396a.mountVolume(extraExtendStorage);
                }
            } catch (RemoteException e) {
                Log.e("ydp", "mount error:" + e);
                e.printStackTrace();
            }
        } else if (extraExtendStorage != null) {
            this.f3396a.mountVolume(extraExtendStorage);
        }
        stopSelf();
    }

    /* JADX WARN: Code duplicated, block: B:31:0x007a A[Catch: IOException -> 0x008e, TRY_LEAVE, TryCatch #8 {IOException -> 0x008e, blocks: (B:29:0x0075, B:31:0x007a), top: B:63:0x0075 }] */
    /* JADX WARN: Code duplicated, block: B:43:0x009b A[Catch: IOException -> 0x009f, TRY_LEAVE, TryCatch #7 {IOException -> 0x009f, blocks: (B:41:0x0096, B:43:0x009b), top: B:61:0x0096 }] */
    /* JADX INFO: renamed from: a */
    private static ArrayList<String> m1448a() throws Throwable {
        ArrayList<String> extendStorageList = new ArrayList<>();
        FileInputStream fis = null;
        BufferedReader localBufferedReader = null;
        try {
            try {
                FileInputStream fis2 = new FileInputStream(new File("/proc/mounts"));
                try {
                    BufferedReader localBufferedReader2 = new BufferedReader(new InputStreamReader(fis2));
                    while (true) {
                        try {
                            String buffer = localBufferedReader2.readLine();
                            if (buffer != null) {
                                if (buffer.contains("uid=1000") || buffer.contains("user_id=1023")) {
                                    if (buffer.contains("gid=1015") || buffer.contains("gid=1023") || buffer.contains("group_id=1023")) {
                                        if (!buffer.contains("asec")) {
                                            String[] arrayOfString = buffer.split(" ");
                                            if (arrayOfString.length >= 4 && !extendStorageList.contains(arrayOfString[1])) {
                                                extendStorageList.add(arrayOfString[1]);
                                            }
                                        }
                                    }
                                }
                            } else {
                                try {
                                    break;
                                } catch (IOException e) {
                                    e.printStackTrace();
                                    localBufferedReader = localBufferedReader2;
                                    fis = fis2;
                                }
                            }
                        } catch (Exception e2) {
                            e = e2;
                            localBufferedReader = localBufferedReader2;
                            fis = fis2;
                            e.printStackTrace();
                            if (fis != null) {
                                try {
                                    fis.close();
                                    if (localBufferedReader != null) {
                                        localBufferedReader.close();
                                    }
                                } catch (IOException e3) {
                                    e3.printStackTrace();
                                }
                            } else if (localBufferedReader != null) {
                                localBufferedReader.close();
                            }
                        } catch (Throwable th) {
                            th = th;
                            localBufferedReader = localBufferedReader2;
                            fis = fis2;
                            if (fis != null) {
                                try {
                                    fis.close();
                                    if (localBufferedReader != null) {
                                        localBufferedReader.close();
                                    }
                                } catch (IOException e4) {
                                    e4.printStackTrace();
                                    throw th;
                                }
                            } else if (localBufferedReader != null) {
                                localBufferedReader.close();
                            }
                            throw th;
                        }
                    }
                    fis2.close();
                    localBufferedReader2.close();
                    localBufferedReader = localBufferedReader2;
                    fis = fis2;
                } catch (Exception e5) {
                    e = e5;
                    fis = fis2;
                } catch (Throwable th2) {
                    th = th2;
                    fis = fis2;
                }
            } catch (Throwable th3) {
                th = th3;
            }
        } catch (Exception e6) {
            e = e6;
        }
        return extendStorageList;
    }

    /* JADX INFO: renamed from: a */
    private void m1449a(String path) {
        File f = new File(path);
        try {
            this.f3398c = this.f3396a.getClass().getMethod("unmountVolume", String.class, Boolean.TYPE, Boolean.TYPE);
        } catch (NoSuchMethodException e) {
            try {
                this.f3398c = this.f3396a.getClass().getMethod("unmountVolume", String.class, Boolean.TYPE);
            } catch (NoSuchMethodException e2) {
                e2.printStackTrace();
            }
        }
        try {
            if (f.exists() && !this.f3396a.getVolumeState(path).equals("removed")) {
                Log.i("ydp", "extra_sd:" + path + "   state:" + this.f3396a.getVolumeState(path));
                Log.i("ydp", "method:" + this.f3398c);
                if (this.f3398c.getParameterTypes().length == 3) {
                    this.f3398c.invoke(this.f3396a, path, false, false);
                    Log.i("ydp", "unmountVolume:  3");
                } else {
                    this.f3398c.invoke(this.f3396a, path, false);
                    Log.i("ydp", "unmountVolume:  2");
                }
                int count = 0;
                while (this.f3397b && !this.f3396a.getVolumeState(path).equals("unmounted")) {
                    Thread.sleep(1000L);
                    if (count > 30) {
                        Log.i("ydp", "unmountVolume time out break " + path);
                        break;
                    }
                    count++;
                }
                this.f3396a.formatVolume(path);
                Log.e("ydp", "format " + path + " over-----------");
                return;
            }
            Log.i("ydp", path + " no found");
        } catch (RemoteException e3) {
            e3.printStackTrace();
        } catch (IllegalAccessException e4) {
            e4.printStackTrace();
        } catch (IllegalArgumentException e5) {
            e5.printStackTrace();
        } catch (InterruptedException e6) {
            e6.printStackTrace();
        } catch (InvocationTargetException e7) {
            e7.printStackTrace();
        }
    }

    /* JADX INFO: renamed from: b */
    private synchronized IMountService m1450b() {
        if (this.f3396a == null) {
            IBinder service = ServiceManager.getService("mount");
            if (service != null) {
                this.f3396a = IMountService.Stub.asInterface(service);
            } else {
                Log.e("ydp", "Can't get mount service");
            }
        }
        return this.f3396a;
    }
}
