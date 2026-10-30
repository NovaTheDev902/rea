package com.xxGameAssistant.pao;

import android.app.Application;
import android.os.Handler;
import com.xxGameAssistant.utility.NativeFileInstaller;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class MTApplication extends Application {
    public static final String mDefTipsText = "各位叉烧，\n\t\t感谢使用叉叉游戏助手，天天酷跑插件核心功能：\n\t\t\t1.无限冲刺:自定义4百至100万米飞行距离，免道具，做到真正的一飞冲天！\n\t\t\t2.bonus奖励加倍:用户自由选择得分加成倍数，得分多多！\n\t\t说明：本插件目前只支持微信渠道的1.0.6.0版天天酷跑。\n\t\t希望叉烧们持续关注叉叉，建议、bug随时反馈，叉叉的成长需要各位叉烧的帮助，做最好的游戏插件。\n\t\t新浪微博：@叉叉游戏助手\n\t\tBUG反馈QQ：1068071192\n\t\t官方网站：www.xxzhushou.com \n\t\t使用插件一定要授予root权限\n";

    /* JADX INFO: renamed from: me */
    public static MTApplication f224me;
    private volatile Handler mHandler = null;
    private String mtPackageName_chs = "com.tencent.lian";
    public static ArrayList<String> mPackageString = null;
    public static ArrayList<String> mChannelString = null;
    public static String mTipsText = null;
    public static String mCheckUpdateURL = "      .";
    public static String mTipsURL = "  .";
    public static String mPackageURL = "           .";
    public static int mConnectTimeout = 10000;
    public static int mReadTimeout = 10000;
    public static boolean mIsNewestVersion = false;
    public static boolean mIsRoot = false;
    public static boolean mIsInstallerOk = false;

    public MTApplication() {
        mIsNewestVersion = false;
        f224me = this;
    }

    public void setMTPackageName(String MTPackageName) {
        this.mtPackageName_chs = MTPackageName;
    }

    public String getMTPackageName() {
        return this.mtPackageName_chs;
    }

    public static MTApplication unique() {
        return f224me;
    }

    public void setHandler(Handler handler) {
        this.mHandler = handler;
    }

    public Thread getThread() {
        new InstallerThread().start();
        return new MyThread();
    }

    class InstallerThread extends Thread {
        InstallerThread() {
        }

        @Override // java.lang.Thread, java.lang.Runnable
        public void run() {
            NativeFileInstaller.install(MTApplication.this);
            MTApplication.mIsRoot = NativeFileInstaller.isRoot();
            MTApplication.mIsInstallerOk = NativeFileInstaller.test();
            while (MTApplication.this.mHandler == null) {
                try {
                    Thread.sleep(100L);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            MTApplication.this.mHandler.sendEmptyMessage(8);
        }
    }

    class MyThread extends Thread {
        MyThread() {
        }

        @Override // java.lang.Thread, java.lang.Runnable
        public void run() throws Throwable {
            MTApplication.this.mHandler = null;
            int status = 4;
            HttpURLConnection urlConn = null;
            try {
                try {
                    URL url = new URL(MTApplication.mTipsURL);
                    try {
                        HttpURLConnection urlConn2 = (HttpURLConnection) url.openConnection();
                        urlConn2.setDoInput(true);
                        urlConn2.setConnectTimeout(MTApplication.mConnectTimeout);
                        urlConn2.setReadTimeout(MTApplication.mReadTimeout);
                        urlConn2.setUseCaches(false);
                        if (urlConn2.getResponseCode() != 200) {
                            MTApplication.mTipsText = null;
                            while (MTApplication.this.mHandler == null) {
                                try {
                                    Thread.sleep(100L);
                                } catch (InterruptedException e) {
                                    e.printStackTrace();
                                }
                            }
                            if (MTApplication.this.mHandler != null) {
                                MTApplication.this.mHandler.sendEmptyMessage(4);
                            }
                        } else {
                            InputStream in = urlConn2.getInputStream();
                            ByteArrayOutputStream bufStr = new ByteArrayOutputStream();
                            byte[] buffer = new byte[4096];
                            while (true) {
                                int size = in.read(buffer);
                                if (size == -1) {
                                    break;
                                } else {
                                    bufStr.write(buffer, 0, size);
                                }
                            }
                            MTApplication.mTipsText = new String(bufStr.toByteArray());
                            in.close();
                            urlConn2.disconnect();
                            bufStr.close();
                            if (MTApplication.mTipsText.compareTo("0") != 0 && MTApplication.mTipsText == null) {
                                status = 3;
                            }
                            while (MTApplication.this.mHandler == null) {
                                try {
                                    Thread.sleep(100L);
                                } catch (InterruptedException e2) {
                                    e2.printStackTrace();
                                }
                            }
                            if (MTApplication.this.mHandler != null) {
                                MTApplication.this.mHandler.sendEmptyMessage(status);
                            }
                        }
                    } catch (MalformedURLException e3) {
                        e = e3;
                        e.printStackTrace();
                        while (MTApplication.this.mHandler == null) {
                            try {
                                Thread.sleep(100L);
                            } catch (InterruptedException e4) {
                                e4.printStackTrace();
                            }
                        }
                        if (MTApplication.this.mHandler != null) {
                            MTApplication.this.mHandler.sendEmptyMessage(4);
                        }
                    } catch (IOException e5) {
                        e = e5;
                        urlConn.disconnect();
                        e.printStackTrace();
                        while (MTApplication.this.mHandler == null) {
                            try {
                                Thread.sleep(100L);
                            } catch (InterruptedException e6) {
                                e6.printStackTrace();
                            }
                        }
                        if (MTApplication.this.mHandler != null) {
                            MTApplication.this.mHandler.sendEmptyMessage(4);
                        }
                    } catch (Throwable th) {
                        th = th;
                        while (MTApplication.this.mHandler == null) {
                            try {
                                Thread.sleep(100L);
                            } catch (InterruptedException e7) {
                                e7.printStackTrace();
                            }
                        }
                        if (MTApplication.this.mHandler != null) {
                            MTApplication.this.mHandler.sendEmptyMessage(status);
                        }
                        throw th;
                    }
                } catch (Throwable th2) {
                    th = th2;
                }
            } catch (MalformedURLException e8) {
                e = e8;
            } catch (IOException e9) {
                e = e9;
            }
        }
    }
}
