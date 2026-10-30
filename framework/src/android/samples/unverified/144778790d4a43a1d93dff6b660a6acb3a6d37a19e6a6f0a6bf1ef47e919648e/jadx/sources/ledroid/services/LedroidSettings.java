package ledroid.services;

import android.content.Context;
import android.os.RemoteException;
import ledroid.root.RootPermissionException;

/* JADX INFO: loaded from: classes.dex */
public final class LedroidSettings extends LedroidSupport {

    /* JADX INFO: renamed from: a */
    private LedroidSettingsSystem f6364a;

    /* JADX INFO: renamed from: b */
    private LedroidSettingsSecure f6365b;

    public LedroidSettings(Context ctx) {
        super(ctx);
    }

    public final LedroidSettingsSystem getLedroidSettingsSystem() {
        if (this.f6364a == null) {
            this.f6364a = new LedroidSettingsSystem(this, (byte) 0);
        }
        return this.f6364a;
    }

    public final LedroidSettingsSecure getLedroidSettingsSecure() {
        if (this.f6365b == null) {
            this.f6365b = new LedroidSettingsSecure(this, (byte) 0);
        }
        return this.f6365b;
    }

    public final class LedroidSettingsSystem extends BaseSettings {
        /* synthetic */ LedroidSettingsSystem(LedroidSettings x0, byte b) {
            this();
        }

        private LedroidSettingsSystem() {
            super();
        }

        @Override // ledroid.services.LedroidSettings.BaseSettings
        public final String getString(String name, String def) throws RootPermissionException {
            try {
                String def2 = LedroidSettings.this.getLenovoManager().getSettingsSystemString(name);
                return def2;
            } catch (RemoteException e) {
                e.printStackTrace();
                return def;
            }
        }

        @Override // ledroid.services.LedroidSettings.BaseSettings
        public final boolean putString(String name, String value) throws RootPermissionException {
            try {
                return LedroidSettings.this.getLenovoManager().putSettingsSystemString(name, value);
            } catch (RemoteException e) {
                e.printStackTrace();
                return false;
            }
        }
    }

    public final class LedroidSettingsSecure extends BaseSettings {
        public static final String BIOMETRIC_WEAK_EVER_CHOSEN_KEY = "lockscreen.biometricweakeverchosen";
        public static final String DISABLE_LOCKSCREEN_KEY = "lockscreen.disabled";
        public static final String LOCKOUT_ATTEMPT_DEADLINE = "lockscreen.lockoutattemptdeadline";
        public static final String LOCKOUT_PERMANENT_KEY = "lockscreen.lockedoutpermanently";
        public static final String LOCKSCREEN_BIOMETRIC_WEAK_FALLBACK = "lockscreen.biometric_weak_fallback";
        public static final String LOCKSCREEN_OPTIONS = "lockscreen.options";
        public static final String LOCKSCREEN_POWER_BUTTON_INSTANTLY_LOCKS = "lockscreen.power_button_instantly_locks";
        public static final String LOCK_PASSWORD_SALT_KEY = "lockscreen.password_salt";
        public static final String PASSWORD_HISTORY_KEY = "lockscreen.passwordhistory";
        public static final String PASSWORD_TYPE_ALTERNATE_KEY = "lockscreen.password_type_alternate";
        public static final String PASSWORD_TYPE_KEY = "lockscreen.password_type";
        public static final String PATTERN_EVER_CHOSEN_KEY = "lockscreen.patterneverchosen";

        /* synthetic */ LedroidSettingsSecure(LedroidSettings x0, byte b) {
            this();
        }

        private LedroidSettingsSecure() {
            super();
        }

        @Override // ledroid.services.LedroidSettings.BaseSettings
        public final String getString(String name, String def) throws RootPermissionException {
            try {
                String def2 = LedroidSettings.this.getLenovoManager().getSettingsSecureString(name);
                return def2;
            } catch (RemoteException e) {
                e.printStackTrace();
                return def;
            }
        }

        @Override // ledroid.services.LedroidSettings.BaseSettings
        public final boolean putString(String name, String value) throws RootPermissionException {
            try {
                return LedroidSettings.this.getLenovoManager().putSettingsSecureString(name, value);
            } catch (RemoteException e) {
                e.printStackTrace();
                return false;
            }
        }
    }

    public abstract class BaseSettings {
        public abstract String getString(String str, String str2) throws RootPermissionException;

        public abstract boolean putString(String str, String str2) throws RootPermissionException;

        public BaseSettings() {
        }

        public String getString(String name) throws RootPermissionException {
            return getString(name, null);
        }

        public int getInt(String name, int def) throws RootPermissionException {
            String v = getString(name);
            if (v != null) {
                try {
                    return Integer.parseInt(v);
                } catch (NumberFormatException e) {
                    return def;
                }
            }
            return def;
        }

        public boolean putInt(String name, int value) throws RootPermissionException {
            return putString(name, Integer.toString(value));
        }

        public long getLong(String name, long def) throws RootPermissionException {
            String valString = getString(name);
            if (valString == null) {
                return def;
            }
            try {
                long value = Long.parseLong(valString);
                return value;
            } catch (NumberFormatException e) {
                return def;
            }
        }

        public boolean putLong(String name, long value) throws RootPermissionException {
            return putString(name, Long.toString(value));
        }

        public float getFloat(String name, float def) throws RootPermissionException {
            String v = getString(name);
            if (v != null) {
                try {
                    return Float.parseFloat(v);
                } catch (NumberFormatException e) {
                    return def;
                }
            }
            return def;
        }

        public boolean putFloat(String name, float value) throws RootPermissionException {
            return putString(name, Float.toString(value));
        }
    }
}
