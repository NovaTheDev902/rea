package com.lenovo.safecenter.shortcut;

import android.appwidget.AppWidgetManager;
import android.appwidget.AppWidgetProvider;
import android.content.Context;
import android.content.Intent;
import android.util.Log;

/* JADX INFO: loaded from: classes.dex */
public class WidgetProvider extends AppWidgetProvider {
    @Override // android.appwidget.AppWidgetProvider
    public void onEnabled(Context context) {
        super.onEnabled(context);
    }

    @Override // android.appwidget.AppWidgetProvider
    public void onUpdate(Context context, AppWidgetManager appWidgetManager, int[] appWidgetIds) {
        Log.i("Widget", "WidgetProvider onUpdate");
        context.startService(new Intent(context, (Class<?>) WidgetUpdateService.class));
    }

    @Override // android.appwidget.AppWidgetProvider, android.content.BroadcastReceiver
    public void onReceive(Context context, Intent intent) {
        super.onReceive(context, intent);
        if (intent.getAction().equals("com.lenovo.safecenter.ONEKEY_WIDGET_REFRESH")) {
            context.startService(new Intent(context, (Class<?>) WidgetUpdateService.class));
        }
    }

    @Override // android.appwidget.AppWidgetProvider
    public void onDisabled(Context context) {
        super.onDisabled(context);
        context.stopService(new Intent(context, (Class<?>) WidgetUpdateService.class));
    }

    @Override // android.appwidget.AppWidgetProvider
    public void onDeleted(Context context, int[] appWidgetIds) {
        super.onDeleted(context, appWidgetIds);
    }
}
