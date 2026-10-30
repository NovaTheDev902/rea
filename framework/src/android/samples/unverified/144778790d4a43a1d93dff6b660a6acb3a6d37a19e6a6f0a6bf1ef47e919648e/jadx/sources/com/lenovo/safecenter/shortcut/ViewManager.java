package com.lenovo.safecenter.shortcut;

import android.content.Context;
import android.graphics.Rect;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.WindowManager;
import android.widget.AbsoluteLayout;
import com.lenovo.safecenter.C0415R;

/* JADX INFO: loaded from: classes.dex */
public final class ViewManager {
    public static WindowManager.LayoutParams wLayoutParams = new WindowManager.LayoutParams();

    /* JADX INFO: renamed from: a */
    private static WindowManager f5377a = null;

    /* JADX INFO: renamed from: b */
    private static View f5378b = null;

    public static void addView(Context paramContext, Rect paramRect, View paramView) {
        if (f5378b == null) {
            LayoutInflater.from(paramContext);
            AbsoluteLayout localAbsoluteLayout1 = (AbsoluteLayout) paramView.getParent();
            f5377a = (WindowManager) paramContext.getApplicationContext().getSystemService("window");
            Log.i("TAG", "localAbsoluteLayout1 == null? " + (localAbsoluteLayout1 == null));
            if (localAbsoluteLayout1 == null) {
                Log.i("TAG", " localAbsoluteLayout1 != null");
                AbsoluteLayout localAbsoluteLayout2 = new AbsoluteLayout(paramContext);
                localAbsoluteLayout2.addView(paramView);
                paramView.post(new RunnableC0971a(paramContext, paramRect, paramView));
                wLayoutParams.type = 2003;
                wLayoutParams.flags = 40;
                wLayoutParams.format = -3;
                wLayoutParams.width = -1;
                wLayoutParams.height = -1;
                wLayoutParams.gravity = 51;
                AbsoluteLayout.LayoutParams layoutParams = (AbsoluteLayout.LayoutParams) paramView.getLayoutParams();
                Log.i("TAG", " x = " + layoutParams.x + " y = " + layoutParams.y);
                wLayoutParams.x = layoutParams.x;
                wLayoutParams.y = layoutParams.y;
                f5378b = localAbsoluteLayout2;
            } else {
                f5378b = localAbsoluteLayout1;
            }
            f5377a.addView(f5378b, wLayoutParams);
        }
    }

    public static void removeView(Context paramContext, View paramView) {
        if (paramView != null && paramView.getParent() != null) {
            View localView = (View) paramView.getParent();
            if (f5377a != null) {
                try {
                    f5377a.removeView(localView);
                    f5377a.removeView(f5378b);
                } catch (Exception e) {
                    Log.e("TAG", " Ex + " + e);
                }
                f5378b = null;
            }
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.shortcut.ViewManager$a */
    public static final class RunnableC0971a implements Runnable {

        /* JADX INFO: renamed from: a */
        private final Rect f5379a;

        /* JADX INFO: renamed from: b */
        private final View f5380b;

        /* JADX INFO: renamed from: c */
        private final Context f5381c;

        RunnableC0971a(Context paramContext, Rect paramRect, View paramView) {
            this.f5381c = paramContext;
            this.f5379a = paramRect;
            this.f5380b = paramView;
        }

        @Override // java.lang.Runnable
        public final void run() {
            Rect localRect = new Rect();
            this.f5380b.getWindowVisibleDisplayFrame(localRect);
            int i = this.f5379a.centerX() - (this.f5380b.getWidth() / 2);
            int j = (this.f5379a.centerY() - (this.f5380b.getHeight() / 2)) - localRect.top;
            Log.i("TAG", " Run x = " + i + " y = " + j + " Height/2=" + (this.f5380b.getHeight() / 2) + " top = " + localRect.top);
            AbsoluteLayout.LayoutParams localLayoutParams = (AbsoluteLayout.LayoutParams) this.f5380b.getLayoutParams();
            localLayoutParams.x = i;
            localLayoutParams.y = (int) (j - this.f5381c.getResources().getDimension(C0415R.dimen.popup_vertical_offset));
            this.f5380b.setLayoutParams(localLayoutParams);
        }
    }
}
