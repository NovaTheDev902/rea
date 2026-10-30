package com.lenovo.safecenter.systeminfo.entity;

/* JADX INFO: loaded from: classes.dex */
public class Category {
    public static final String COLUMN_ID = "_id";
    public static final String COLUMN_NAME = "name";
    public static final String TABLE_NAME = "category";

    /* JADX INFO: renamed from: a */
    private int f5600a;

    /* JADX INFO: renamed from: b */
    private String f5601b;

    public Category() {
    }

    public Category(int id, String name) {
        this.f5600a = id;
        this.f5601b = name;
    }

    public int getId() {
        return this.f5600a;
    }

    public void setId(int id) {
        this.f5600a = id;
    }

    public String getName() {
        return this.f5601b;
    }

    public void setName(String name) {
        this.f5601b = name;
    }

    public String toString() {
        return "Category [id=" + this.f5600a + ", name=" + this.f5601b + "]";
    }

    public int hashCode() {
        int result = this.f5600a + 31;
        return (result * 31) + (this.f5601b == null ? 0 : this.f5601b.hashCode());
    }

    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj != null && getClass() == obj.getClass()) {
            Category other = (Category) obj;
            if (this.f5600a != other.f5600a) {
                return false;
            }
            if (this.f5601b == null) {
                return other.f5601b == null;
            }
            return this.f5601b.equals(other.f5601b);
        }
        return false;
    }
}
