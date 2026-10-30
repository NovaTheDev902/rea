package com.tencent.tmsecure.module.permission;

import android.content.Context;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.utils.Log;
import java.util.List;
import tms.C1270es;

/* JADX INFO: loaded from: classes.dex */
public final class PermissionManager extends BaseManager {
    public static final int VERSION_CODE = 8;

    /* JADX INFO: renamed from: a */
    private C1270es f6170a;

    /* JADX INFO: renamed from: b */
    private PermissionControlConfig f6171b;

    public interface IInitStepObserver {
        public static final int STEP_ASK_REBOOT = 2;
        public static final int STEP_CHECK_HAD_REG = 3;
        public static final int STEP_FINISH = 6;
        public static final int STEP_GET_SERVICE_BINDER = 4;
        public static final int STEP_HAD_BEEN_ROOT = 1;
        public static final int STEP_IMPORT_DATA = 5;
        public static final int STEP_OS_ARCH_CHECK = 0;

        boolean onReached(int i, boolean z);
    }

    /* JADX INFO: renamed from: a */
    private static Object[] m2618a(int i) {
        Log.m2636i(QueryPermissions.PERMISSION, "process: " + i);
        return C1270es.m3254a(i);
    }

    public final void addPermissionTableItem(PermissionTableItem permissionTableItem) {
        if (isExpired()) {
            return;
        }
        this.f6170a.m3262a(permissionTableItem);
    }

    public final boolean canStartService() {
        if (isExpired()) {
            return false;
        }
        return this.f6170a.m3268d();
    }

    public final PermissionControlConfig getPermissionTable() {
        return isExpired() ? this.f6171b : this.f6170a.m3258a();
    }

    public final int[] getRidByPermission(List<String> list) {
        return C1270es.m3252a(list);
    }

    public final void init(IInitStepObserver iInitStepObserver, PermissionControlConfig permissionControlConfig) {
        if (isExpired()) {
            this.f6171b = permissionControlConfig;
        } else {
            this.f6170a.m3261a(iInitStepObserver, permissionControlConfig);
        }
    }

    public final boolean isEnable() {
        if (isExpired()) {
            return false;
        }
        return this.f6170a.m3265b();
    }

    public final boolean isFinishInit() {
        if (isExpired()) {
            return false;
        }
        return this.f6170a.m3267c();
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6170a = new C1270es();
        this.f6170a.onCreate(context);
        setImpl(this.f6170a);
    }

    public final void removePermissionTableItem(PermissionTableItem permissionTableItem) {
        if (isExpired()) {
            return;
        }
        this.f6170a.m3264b(permissionTableItem);
    }

    public final void setCallback(AbsDummyServiceCallback absDummyServiceCallback) {
        if (isExpired()) {
            return;
        }
        this.f6170a.m3260a(absDummyServiceCallback);
    }

    public final void setEnable(boolean z) {
        if (isExpired()) {
            return;
        }
        this.f6170a.m3263a(z);
    }

    public final void updatePermissionTable(int i, int i2, int i3) {
        if (isExpired()) {
            return;
        }
        this.f6170a.m3259a(i, i2, i3);
    }

    public final void updatePermissionTable(PermissionTableItem permissionTableItem) {
        if (isExpired()) {
            return;
        }
        this.f6170a.m3266c(permissionTableItem);
    }
}
