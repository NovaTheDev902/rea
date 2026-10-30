package tms;

import android.app.Activity;
import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.Signature;
import android.content.res.AssetManager;
import android.content.res.Resources;
import android.view.ContextThemeWrapper;
import android.view.LayoutInflater;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.module.plugin.AbsPluginControler;
import com.tencent.tmsecure.module.plugin.AbsPluginDatabaseFactor;
import com.tencent.tmsecure.module.plugin.IContext;
import com.tencent.tmsecure.module.plugin.IPluginDatabase;
import com.tencent.tmsecure.module.plugin.IPluginInterface;
import com.tencent.tmsecure.module.plugin.PluginEntity;
import dalvik.system.DexClassLoader;
import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.IOException;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.security.cert.CertificateException;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

/* JADX INFO: renamed from: tms.fo */
/* JADX INFO: loaded from: classes.dex */
public final class C1293fo extends BaseManager {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f7337a;

    /* JADX INFO: renamed from: i */
    private static final HashMap<String, Constructor<?>> f7338i;

    /* JADX INFO: renamed from: b */
    private Context f7339b;

    /* JADX INFO: renamed from: c */
    private PackageManager f7340c;

    /* JADX INFO: renamed from: d */
    private String f7341d;

    /* JADX INFO: renamed from: e */
    private IContext f7342e;

    /* JADX INFO: renamed from: f */
    private AbsPluginControler f7343f;

    /* JADX INFO: renamed from: g */
    private ClassLoader f7344g = IPluginInterface.class.getClassLoader();

    /* JADX INFO: renamed from: h */
    private final Map<String, PluginEntity> f7345h = new HashMap();

    /* JADX INFO: renamed from: j */
    private boolean f7346j;

    /* JADX INFO: renamed from: tms.fo$a */
    final class a implements IContext {

        /* JADX INFO: renamed from: b */
        private IContext.ILayoutInflater f7348b;

        /* JADX INFO: renamed from: c */
        private AssetManager f7349c;

        /* JADX INFO: renamed from: d */
        private Resources f7350d;

        public a() {
            this.f7348b = new C1257ef(this, C1293fo.this);
            this.f7349c = C1293fo.this.f7339b.getAssets();
            this.f7350d = C1293fo.this.f7339b.getResources();
        }

        @Override // com.tencent.tmsecure.module.plugin.IContext
        public final AssetManager getAssertManager() {
            return this.f7349c;
        }

        @Override // com.tencent.tmsecure.module.plugin.IContext
        public final Context getContext() {
            return C1293fo.this.f7339b.getApplicationContext();
        }

        @Override // com.tencent.tmsecure.module.plugin.IContext
        public final IContext.ILayoutInflater getLayoutInflater() {
            return this.f7348b;
        }

        @Override // com.tencent.tmsecure.module.plugin.IContext
        public final Resources getResources() {
            return this.f7350d;
        }
    }

    /* JADX INFO: renamed from: tms.fo$b */
    final class b implements IContext {

        /* JADX INFO: renamed from: a */
        final /* synthetic */ C1293fo f7351a;

        /* JADX INFO: renamed from: b */
        private IContext.ILayoutInflater f7352b;

        /* JADX INFO: renamed from: c */
        private AssetManager f7353c;

        /* JADX INFO: renamed from: d */
        private Resources f7354d;

        /* JADX INFO: renamed from: e */
        private Resources.Theme f7355e;

        /* JADX INFO: renamed from: f */
        private c f7356f;

        /* JADX INFO: renamed from: g */
        private LayoutInflater.Factory f7357g = new LayoutInflaterFactoryC1258eg(this);

        public b(C1293fo c1293fo, String str) {
            byte b = 0;
            this.f7351a = c1293fo;
            try {
                this.f7353c = (AssetManager) AssetManager.class.newInstance();
                Method declaredMethod = AssetManager.class.getDeclaredMethod("addAssetPath", String.class);
                declaredMethod.setAccessible(true);
                declaredMethod.invoke(this.f7353c, str);
            } catch (IllegalAccessException e) {
                e.printStackTrace();
            } catch (IllegalArgumentException e2) {
                e2.printStackTrace();
            } catch (InstantiationException e3) {
                e3.printStackTrace();
            } catch (NoSuchMethodException e4) {
                e4.printStackTrace();
            } catch (SecurityException e5) {
                e5.printStackTrace();
            } catch (InvocationTargetException e6) {
                e6.printStackTrace();
            } catch (Exception e7) {
                e7.printStackTrace();
            }
            this.f7356f = new c(b);
            this.f7354d = new Resources(this.f7353c, c1293fo.f7339b.getResources().getDisplayMetrics(), c1293fo.f7339b.getResources().getConfiguration());
            this.f7355e = this.f7354d.newTheme();
            this.f7355e.applyStyle(c.f7358a, true);
            this.f7352b = new C1264em(this, c1293fo);
        }

        @Override // com.tencent.tmsecure.module.plugin.IContext
        public final AssetManager getAssertManager() {
            return this.f7353c;
        }

        @Override // com.tencent.tmsecure.module.plugin.IContext
        public final Context getContext() {
            return this.f7351a.f7339b.getApplicationContext();
        }

        @Override // com.tencent.tmsecure.module.plugin.IContext
        public final IContext.ILayoutInflater getLayoutInflater() {
            return this.f7352b;
        }

        @Override // com.tencent.tmsecure.module.plugin.IContext
        public final Resources getResources() {
            return this.f7354d;
        }
    }

    /* JADX INFO: renamed from: tms.fo$c */
    static final class c {

        /* JADX INFO: renamed from: a */
        static int f7358a;

        /* JADX INFO: renamed from: b */
        private static Field f7359b;

        /* JADX INFO: renamed from: c */
        private Activity f7360c;

        /* JADX INFO: renamed from: d */
        private Resources.Theme f7361d;

        static {
            try {
                f7358a = Class.forName("com.android.internal.R$style").getDeclaredField("Theme").getInt(null);
                f7359b = ContextThemeWrapper.class.getDeclaredField("mTheme");
                f7359b.setAccessible(true);
            } catch (ClassNotFoundException e) {
                e.printStackTrace();
            } catch (IllegalAccessException e2) {
                e2.printStackTrace();
            } catch (IllegalArgumentException e3) {
                e3.printStackTrace();
            } catch (NoSuchFieldException e4) {
                e4.printStackTrace();
            } catch (SecurityException e5) {
                e5.printStackTrace();
            }
        }

        private c() {
        }

        /* synthetic */ c(byte b) {
            this();
        }

        /* JADX INFO: renamed from: a */
        public final void m3341a() {
            synchronized (this) {
                if (f7359b == null || this.f7361d == null) {
                    this.f7360c = null;
                    this.f7361d = null;
                } else {
                    try {
                        f7359b.set(this.f7360c, this.f7361d);
                    } catch (IllegalAccessException e) {
                        e.printStackTrace();
                    } catch (IllegalArgumentException e2) {
                        e2.printStackTrace();
                    }
                    this.f7360c = null;
                    this.f7361d = null;
                }
                throw th;
            }
        }

        /* JADX INFO: renamed from: a */
        public final void m3342a(Activity activity, Resources.Theme theme) {
            synchronized (this) {
                if (f7359b != null) {
                    try {
                        this.f7360c = activity;
                        this.f7361d = (Resources.Theme) f7359b.get(this.f7360c);
                        f7359b.set(this.f7360c, theme);
                    } catch (IllegalAccessException e) {
                        e.printStackTrace();
                    } catch (IllegalArgumentException e2) {
                        e2.printStackTrace();
                    }
                }
            }
        }
    }

    static {
        f7337a = !C1293fo.class.desiredAssertionStatus();
        f7338i = new HashMap<>();
    }

    /* JADX INFO: renamed from: a */
    private PluginEntity m3326a(String str) {
        PluginEntity pluginEntity;
        InstantiationException instantiationException;
        IllegalAccessException illegalAccessException;
        ClassNotFoundException classNotFoundException;
        String absolutePath = this.f7339b.getDir("plugins_dex", 0).getAbsolutePath();
        if (new File(str).exists()) {
            PackageInfo packageArchiveInfo = this.f7340c.getPackageArchiveInfo(str, 64);
            if (packageArchiveInfo == null) {
                return null;
            }
            b bVar = new b(this, str);
            String str2 = packageArchiveInfo.packageName;
            String strM3328a = m3328a(bVar, "plugin_class", str2);
            String strM3328a2 = m3328a(bVar, "plugin_name", str2);
            String strM3328a3 = m3328a(bVar, "plugin_version", str2);
            try {
                IPluginInterface iPluginInterface = (IPluginInterface) new DexClassLoader(str, absolutePath, null, this.f7344g).loadClass(strM3328a).newInstance();
                iPluginInterface.onCreate(this.f7342e, bVar, this.f7343f);
                PluginEntity pluginEntity2 = new PluginEntity();
                try {
                    pluginEntity2.mPluginPkgName = str2;
                    pluginEntity2.mPluginFilePath = str.substring(0, str.length() - 4);
                    pluginEntity2.mPluginName = strM3328a2;
                    pluginEntity2.mPluginVerion = Integer.valueOf(strM3328a3).intValue();
                    pluginEntity2.mPluginInterface = iPluginInterface;
                    pluginEntity = pluginEntity2;
                } catch (ClassNotFoundException e) {
                    pluginEntity = pluginEntity2;
                    classNotFoundException = e;
                    classNotFoundException.printStackTrace();
                } catch (IllegalAccessException e2) {
                    pluginEntity = pluginEntity2;
                    illegalAccessException = e2;
                    illegalAccessException.printStackTrace();
                } catch (InstantiationException e3) {
                    pluginEntity = pluginEntity2;
                    instantiationException = e3;
                    instantiationException.printStackTrace();
                }
            } catch (ClassNotFoundException e4) {
                classNotFoundException = e4;
                pluginEntity = null;
            } catch (IllegalAccessException e5) {
                illegalAccessException = e5;
                pluginEntity = null;
            } catch (InstantiationException e6) {
                instantiationException = e6;
                pluginEntity = null;
            }
        } else {
            pluginEntity = null;
        }
        return pluginEntity;
    }

    /* JADX WARN: Code duplicated, block: B:43:0x0040 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX INFO: renamed from: a */
    private static String m3327a(Signature signature) throws Throwable {
        ByteArrayInputStream byteArrayInputStream;
        String strM2878c;
        try {
            try {
                byteArrayInputStream = new ByteArrayInputStream(signature.toByteArray());
                try {
                    strM2878c = C1148ae.m2878c(((X509Certificate) CertificateFactory.getInstance("X.509").generateCertificate(byteArrayInputStream)).getEncoded());
                    if (byteArrayInputStream != null) {
                        try {
                            byteArrayInputStream.close();
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                    }
                } catch (CertificateException e2) {
                    e = e2;
                    e.printStackTrace();
                    if (byteArrayInputStream != null) {
                        try {
                            byteArrayInputStream.close();
                        } catch (IOException e3) {
                            e3.printStackTrace();
                        }
                    }
                    strM2878c = null;
                } catch (Exception e4) {
                    e = e4;
                    e.printStackTrace();
                    if (byteArrayInputStream != null) {
                        try {
                            byteArrayInputStream.close();
                        } catch (IOException e5) {
                            e5.printStackTrace();
                        }
                    }
                    strM2878c = null;
                }
            } catch (Throwable th) {
                th = th;
                if (byteArrayInputStream != null) {
                    try {
                        byteArrayInputStream.close();
                    } catch (IOException e6) {
                        e6.printStackTrace();
                    }
                }
                throw th;
            }
        } catch (CertificateException e7) {
            e = e7;
            byteArrayInputStream = null;
        } catch (Exception e8) {
            e = e8;
            byteArrayInputStream = null;
        } catch (Throwable th2) {
            th = th2;
            byteArrayInputStream = null;
            if (byteArrayInputStream != null) {
                byteArrayInputStream.close();
            }
            throw th;
        }
        return strM2878c;
    }

    /* JADX INFO: renamed from: a */
    private static String m3328a(IContext iContext, String str, String str2) {
        Resources resources = iContext.getResources();
        int identifier = resources.getIdentifier(str, "string", str2);
        if (identifier != 0) {
            return resources.getString(identifier);
        }
        return null;
    }

    /* JADX INFO: renamed from: a */
    public final AbsPluginControler m3332a() {
        return this.f7343f;
    }

    /* JADX INFO: renamed from: a */
    public final IPluginDatabase m3333a(AbsPluginDatabaseFactor absPluginDatabaseFactor) {
        return new C1250dz(this.f7339b, absPluginDatabaseFactor);
    }

    /* JADX INFO: renamed from: a */
    public final PluginEntity m3334a(int i) {
        PluginEntity next;
        synchronized (this.f7345h) {
            Iterator<PluginEntity> it = this.f7345h.values().iterator();
            while (it.hasNext()) {
                next = it.next();
                if (next.getKey() == i) {
                }
            }
            next = null;
        }
        return next;
    }

    /* JADX INFO: renamed from: a */
    public final void m3335a(AbsPluginControler absPluginControler) {
        this.f7343f = absPluginControler;
    }

    /* JADX INFO: renamed from: b */
    public final synchronized List<PluginEntity> m3336b() {
        File[] fileArrListFiles;
        if (!this.f7346j) {
            synchronized (this.f7345h) {
                File file = new File(TMSApplication.getStrFromEnvMap(TMSApplication.CON_PLUGIN_DIR));
                if (file.exists() && (fileArrListFiles = file.listFiles(new C1256ee(this))) != null && fileArrListFiles.length > 0) {
                    for (File file2 : fileArrListFiles) {
                        File file3 = new File(file2.getAbsolutePath() + ".apk");
                        file2.renameTo(file3);
                        PluginEntity pluginEntityM3326a = m3326a(file3.getAbsolutePath());
                        file3.renameTo(file2);
                        if (pluginEntityM3326a != null) {
                            this.f7345h.put(file2.getAbsolutePath(), pluginEntityM3326a);
                        }
                    }
                }
            }
            this.f7346j = true;
        }
        return new ArrayList(this.f7345h.values());
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final int getSingletonType() {
        return 1;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f7339b = context;
        this.f7340c = this.f7339b.getPackageManager();
        this.f7342e = new a();
        try {
            this.f7341d = m3327a(this.f7340c.getPackageInfo(this.f7339b.getPackageName(), 64).signatures[0]);
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        if (!f7337a && this.f7341d == null) {
            throw new AssertionError();
        }
    }
}
