package com.lenovo.safecenter.HealthCheck.util;

import android.content.Context;
import com.lenovo.safecenter.C0415R;
import java.util.HashMap;

/* JADX INFO: loaded from: classes.dex */
public class HealthViewType {
    public static final int VIEW_TYPE_CAN_OPTIMIZATION_ITEM = 2;
    public static final int VIEW_TYPE_DANGER_ITEM = 1;
    public static final int VIEW_TYPE_HAS_OPTIMIZATION_ITEM = 4;
    public static final int VIEW_TYPE_MANUAL_ITEM = 3;
    public static final int VIEW_TYPE_SAFE_ITEM = 5;
    public static final int VIEW_TYPE_TITLE = 0;

    public static HashMap<Integer, String> getViewTypes(Context context) {
        HashMap<Integer, String> list = new HashMap<>();
        list.put(1, context.getString(C0415R.string.danger_item));
        list.put(2, context.getString(C0415R.string.can_optimization_item));
        list.put(3, context.getString(C0415R.string.manual_item));
        list.put(4, context.getString(C0415R.string.has_optimization_item));
        list.put(5, context.getString(C0415R.string.safe_item));
        return list;
    }
}
