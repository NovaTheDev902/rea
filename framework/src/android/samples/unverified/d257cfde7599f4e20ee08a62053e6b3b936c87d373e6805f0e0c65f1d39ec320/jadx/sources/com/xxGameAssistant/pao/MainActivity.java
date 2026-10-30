package com.xxGameAssistant.pao;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.os.Message;
import android.view.KeyEvent;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.SpinnerAdapter;
import android.widget.TextView;
import com.tendcloud.tenddata.TCAgent;
import com.xxGameAssistant.utility.InjectHelper;
import com.xxGameAssistant.utility.JNIHelper;
import com.xxGameAssistant.utility.PackageHelper;
import java.io.BufferedOutputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.SocketTimeoutException;
import java.net.URL;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class MainActivity extends Activity {
    static int GameInjectionWatcherIntervalInMS = 1;
    static int GameLaunchWatcherIntervalInMS = 1000;
    public static final int MSG_APK_NOT_FOUND = 6;
    public static final int MSG_INSTALLER_OK = 8;
    public static final int MSG_NET_ERROR = 5;
    public static final int MSG_NEW_VERSION = 1;
    public static final int MSG_NO_NEW_VERSION = 2;
    public static final int MSG_SET_GAMEMODE_OK = 9;
    public static final int MSG_SOCKET_TIMEOUT = 0;
    public static final int MSG_TIPS_ERROR = 4;
    public static final int MSG_TIPS_OK = 3;
    public static final int MSG_VERSION_NOT_FOUND = 7;
    private EditText mBonus;
    private Context mContext;
    private JNIHelper mJNIHelper;
    private PackageHelper mPackageHelper;
    private EditText mRushDistance;
    private Spinner mSpinner = null;
    private TextView mSelectedMT = null;
    private TextView mAnnounceTextView = null;
    private Button mStartButton = null;
    private Button mCheckUpdate = null;
    private ArrayList<String> mPackageString = new ArrayList<>();
    private ArrayList<String> mChannelString = new ArrayList<>();
    private boolean mIsHasNewVersion = false;
    private boolean mIsAbortNewVewsion = false;
    private boolean mIsHasMT = false;
    private boolean mIsInstallOK = false;
    private String mAnnouncementText = null;
    private Thread checkUpdate = new Thread() { // from class: com.xxGameAssistant.pao.MainActivity.1
        @Override // java.lang.Thread, java.lang.Runnable
        public void run() {
            try {
                URL url = new URL(MTApplication.mCheckUpdateURL);
                HttpURLConnection urlConn = (HttpURLConnection) url.openConnection();
                urlConn.setDoInput(true);
                urlConn.setUseCaches(false);
                urlConn.setConnectTimeout(MTApplication.mConnectTimeout);
                urlConn.setReadTimeout(MTApplication.mReadTimeout);
                if (urlConn.getResponseCode() != 200) {
                    MainActivity.this.mHandler.sendEmptyMessage(7);
                    urlConn.disconnect();
                    return;
                }
                InputStream in = urlConn.getInputStream();
                ByteArrayOutputStream bOut = new ByteArrayOutputStream();
                byte[] buffer = new byte[4096];
                while (true) {
                    int size = in.read(buffer);
                    if (size == -1) {
                        break;
                    } else {
                        bOut.write(buffer, 0, size);
                    }
                }
                String strVersion = bOut.toString();
                urlConn.disconnect();
                bOut.close();
                PackageManager packageManager = MainActivity.this.getPackageManager();
                PackageInfo packInfo = packageManager.getPackageInfo(MainActivity.this.mContext.getPackageName(), 0);
                String vm = packInfo.versionName;
                if (strVersion.compareTo(vm) <= 0) {
                    MainActivity.this.mHandler.sendEmptyMessage(2);
                    return;
                }
                synchronized (MainActivity.this.mHandler) {
                    MainActivity.this.mHandler.sendEmptyMessage(1);
                    MainActivity.this.mHandler.wait();
                }
                if (!MainActivity.this.mIsAbortNewVewsion) {
                    URL url2 = new URL(MTApplication.mPackageURL);
                    HttpURLConnection urlConn2 = (HttpURLConnection) url2.openConnection();
                    urlConn2.setDoInput(true);
                    urlConn2.setUseCaches(false);
                    urlConn2.setConnectTimeout(MTApplication.mConnectTimeout);
                    urlConn2.setReadTimeout(MTApplication.mReadTimeout);
                    if (urlConn2.getResponseCode() != 200) {
                        MainActivity.this.mHandler.sendEmptyMessage(6);
                        urlConn2.disconnect();
                        return;
                    }
                    InputStream in2 = urlConn2.getInputStream();
                    File dir = new File(Environment.getExternalStorageDirectory(), "RhythmPlugin");
                    if (dir.exists()) {
                        dir.delete();
                    }
                    dir.mkdirs();
                    dir.setExecutable(true);
                    dir.setWritable(true);
                    dir.setReadable(true);
                    File file = new File(dir.getAbsolutePath(), "xxRhythmPlugin_android.apk");
                    if (file.exists()) {
                        file.delete();
                    }
                    file.setWritable(true);
                    file.setExecutable(true);
                    file.setReadable(true);
                    FileOutputStream out = new FileOutputStream(file);
                    BufferedOutputStream bufOut = new BufferedOutputStream(out);
                    while (true) {
                        int size2 = in2.read(buffer);
                        if (size2 != -1) {
                            bufOut.write(buffer, 0, size2);
                        } else {
                            bufOut.flush();
                            out.flush();
                            bufOut.close();
                            out.close();
                            in2.close();
                            urlConn2.disconnect();
                            Intent intent = new Intent("android.intent.action.VIEW");
                            intent.addFlags(268435456);
                            intent.setAction("android.intent.action.VIEW");
                            intent.setDataAndType(Uri.fromFile(file), "application/vnd.android.package-archive");
                            MainActivity.this.startActivity(intent);
                            MainActivity.this.finish();
                            return;
                        }
                    }
                }
            } catch (PackageManager.NameNotFoundException e) {
                e.printStackTrace();
            } catch (InterruptedException e2) {
                e2.printStackTrace();
            } catch (MalformedURLException e3) {
                e3.printStackTrace();
            } catch (SocketTimeoutException e4) {
                MainActivity.this.mHandler.sendEmptyMessage(0);
            } catch (IOException e5) {
                e5.printStackTrace();
                MainActivity.this.mHandler.sendEmptyMessage(5);
            }
        }
    };
    public Handler mHandler = new Handler() { // from class: com.xxGameAssistant.pao.MainActivity.2
        @Override // android.os.Handler
        public void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    MainActivity.this.mCheckUpdate.setText("连接超时");
                    MainActivity.this.mCheckUpdate.setEnabled(false);
                    if (MainActivity.this.mIsHasMT && MainActivity.this.mIsInstallOK && MTApplication.mIsNewestVersion) {
                        MainActivity.this.mStartButton.setEnabled(true);
                        return;
                    }
                    return;
                case 1:
                    MainActivity.this.mCheckUpdate.setText("立即更新");
                    MainActivity.this.mCheckUpdate.setEnabled(true);
                    if (MainActivity.this.mIsHasMT && MainActivity.this.mIsInstallOK && MTApplication.mIsNewestVersion) {
                        MainActivity.this.mStartButton.setEnabled(true);
                    }
                    MainActivity.this.mIsHasNewVersion = true;
                    return;
                case 2:
                    MainActivity.this.mCheckUpdate.setText("暂无更新");
                    MainActivity.this.mCheckUpdate.setEnabled(false);
                    if (MainActivity.this.mIsHasMT && MainActivity.this.mIsInstallOK && MTApplication.mIsNewestVersion) {
                        MainActivity.this.mStartButton.setEnabled(true);
                        return;
                    }
                    return;
                case 3:
                    MainActivity.this.mAnnouncementText = MTApplication.mTipsText;
                    MainActivity.this.mAnnounceTextView.setText(MainActivity.this.mAnnouncementText);
                    break;
                case 4:
                    break;
                case 5:
                    MainActivity.this.mCheckUpdate.setText("网络异常");
                    MainActivity.this.mCheckUpdate.setEnabled(false);
                    if (MainActivity.this.mIsHasMT && MainActivity.this.mIsInstallOK && MTApplication.mIsNewestVersion) {
                        MainActivity.this.mStartButton.setEnabled(true);
                        return;
                    }
                    return;
                case 6:
                    MainActivity.this.mCheckUpdate.setText("下载更新错误");
                    MainActivity.this.mCheckUpdate.setEnabled(false);
                    if (MainActivity.this.mIsHasMT && MainActivity.this.mIsInstallOK && MTApplication.mIsNewestVersion) {
                        MainActivity.this.mStartButton.setEnabled(true);
                        return;
                    }
                    return;
                case 7:
                    MainActivity.this.mCheckUpdate.setText("检查更新错误");
                    MainActivity.this.mCheckUpdate.setEnabled(false);
                    if (MainActivity.this.mIsHasMT && MainActivity.this.mIsInstallOK && MTApplication.mIsNewestVersion) {
                        MainActivity.this.mStartButton.setEnabled(true);
                        return;
                    }
                    return;
                case 8:
                    MainActivity.this.mIsInstallOK = true;
                    if (MainActivity.this.mIsHasMT && MainActivity.this.mIsInstallOK && MTApplication.mIsNewestVersion) {
                        MainActivity.this.mStartButton.setEnabled(true);
                        return;
                    }
                    return;
                default:
                    super.handleMessage(msg);
                    return;
            }
            MTApplication.mTipsText = null;
        }
    };

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        doMain();
        this.mContext = this;
        ((MTApplication) getApplication()).setHandler(this.mHandler);
        this.mPackageHelper = new PackageHelper(this);
        TCAgent.init(this);
        TCAgent.setReportUncaughtExceptions(true);
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == 4 && event.getRepeatCount() == 0) {
            finish();
        }
        return super.onKeyDown(keyCode, event);
    }

    private void doMain() {
        setContentView(C0099R.layout.activity_main);
        this.mIsInstallOK = false;
        this.mSelectedMT = (TextView) findViewById(C0099R.id.mt_selected_version);
        this.mSpinner = (Spinner) findViewById(C0099R.id.mt_spinner);
        this.mStartButton = (Button) findViewById(C0099R.id.startButton);
        this.mStartButton.setEnabled(false);
        this.mCheckUpdate = (Button) findViewById(C0099R.id.checkUpdate);
        this.mAnnounceTextView = (TextView) findViewById(C0099R.id.mt_announcement_text);
        this.mAnnounceTextView.setText(MTApplication.mDefTipsText);
        this.mBonus = (EditText) findViewById(C0099R.id.et_bonus);
        this.mRushDistance = (EditText) findViewById(C0099R.id.et_rushDistance);
        this.mStartButton.setOnClickListener(new View.OnClickListener() { // from class: com.xxGameAssistant.pao.MainActivity.3
            @Override // android.view.View.OnClickListener
            public void onClick(View v) {
                int tMTPackageNameId = (int) MainActivity.this.mSpinner.getSelectedItemId();
                ((MTApplication) MainActivity.this.getApplication()).setMTPackageName((String) MainActivity.this.mPackageString.get(tMTPackageNameId));
                MainActivity.this.mPackageHelper = new PackageHelper(MainActivity.this);
                MainActivity.this.new MyThread().start();
                synchronized (MainActivity.this.mHandler) {
                    MainActivity.this.mIsAbortNewVewsion = true;
                    MainActivity.this.mHandler.notify();
                }
                ((MTApplication) MainActivity.this.getApplication()).setHandler(null);
            }
        });
        this.mCheckUpdate.setOnClickListener(new View.OnClickListener() { // from class: com.xxGameAssistant.pao.MainActivity.4
            @Override // android.view.View.OnClickListener
            public void onClick(View arg0) {
                if (!MainActivity.this.mIsHasNewVersion) {
                    MainActivity.this.mStartButton.setEnabled(false);
                    MainActivity.this.checkUpdate.start();
                    MainActivity.this.mCheckUpdate.setText("正在检查更新中");
                    MainActivity.this.mCheckUpdate.setEnabled(false);
                    return;
                }
                MainActivity.this.mStartButton.setEnabled(false);
                MainActivity.this.mCheckUpdate.setEnabled(false);
                MainActivity.this.mIsAbortNewVewsion = false;
                MainActivity.this.mCheckUpdate.setText("正在下载更新");
                synchronized (MainActivity.this.mHandler) {
                    MainActivity.this.mHandler.notify();
                }
            }
        });
        this.mPackageString = MTApplication.mPackageString;
        this.mChannelString = MTApplication.mChannelString;
        if (!MTApplication.mIsNewestVersion) {
            this.mSelectedMT.setText("插件只支持1.0.7.0版酷跑");
            this.mStartButton.setText("请更新天天酷跑");
            this.mSpinner.setEnabled(false);
            this.mStartButton.setEnabled(false);
            return;
        }
        if (this.mPackageString != null) {
            if (this.mPackageString.isEmpty()) {
                this.mSelectedMT.setText("未安装天天酷跑");
                this.mStartButton.setEnabled(false);
                this.mIsHasMT = false;
                this.mSpinner.setEnabled(false);
                return;
            }
            this.mIsHasMT = true;
            this.mSelectedMT.setText("当前选择的游戏:");
            ArrayAdapter<String> adapter = new ArrayAdapter<>(this, C0099R.layout.a, this.mChannelString);
            adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
            this.mSpinner.setAdapter((SpinnerAdapter) adapter);
            return;
        }
        this.mSelectedMT.setText("程序发生异常，请重启");
        this.mStartButton.setEnabled(false);
        this.mIsHasMT = false;
        this.mSpinner.setEnabled(false);
    }

    class MyThread extends Thread {
        MyThread() {
        }

        @Override // java.lang.Thread, java.lang.Runnable
        public void run() {
            try {
                String targetPackageName = ((MTApplication) MainActivity.this.getApplication()).getMTPackageName();
                MainActivity.this.mPackageHelper.openApp(targetPackageName);
                while (!MainActivity.this.mPackageHelper.isAppRunning(targetPackageName).booleanValue()) {
                    Thread.sleep(MainActivity.GameInjectionWatcherIntervalInMS);
                }
                Thread.sleep(2000L);
                InjectHelper.setGameMode(String.format("%s,%s", MainActivity.this.mBonus.getText(), MainActivity.this.mRushDistance.getText()));
                InjectHelper.executeCmd(MainActivity.this, targetPackageName);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TCAgent.onResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        super.onPause();
        TCAgent.onPause(this);
    }
}
