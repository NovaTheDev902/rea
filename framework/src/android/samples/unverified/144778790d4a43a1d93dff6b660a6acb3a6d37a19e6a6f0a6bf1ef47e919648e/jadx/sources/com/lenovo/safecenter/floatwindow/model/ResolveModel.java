package com.lenovo.safecenter.floatwindow.model;

import android.graphics.drawable.Drawable;

/* JADX INFO: loaded from: classes.dex */
public class ResolveModel {
    public Drawable drawable;
    public String mainname;
    public int memsize;
    public String name;
    public String packagename;

    public Drawable getDrawable() {
        return this.drawable;
    }

    public void setDrawable(Drawable drawable) {
        this.drawable = drawable;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPackagename() {
        return this.packagename;
    }

    public void setPackagename(String packagename) {
        this.packagename = packagename;
    }

    public String getMainname() {
        return this.mainname;
    }

    public void setMainname(String mainname) {
        this.mainname = mainname;
    }

    public int getMemzise() {
        return this.memsize;
    }

    public void setMemzise(int memsize) {
        this.memsize = memsize;
    }
}
