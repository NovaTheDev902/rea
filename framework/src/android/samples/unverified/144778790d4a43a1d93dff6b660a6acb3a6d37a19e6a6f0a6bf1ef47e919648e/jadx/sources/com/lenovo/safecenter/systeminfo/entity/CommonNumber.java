package com.lenovo.safecenter.systeminfo.entity;

/* JADX INFO: loaded from: classes.dex */
public class CommonNumber {
    public static final String COLUMN_CATEGORY_ID = "c_id";
    public static final String COLUMN_ID = "_id";
    public static final String COLUMN_NAME = "name";
    public static final String COLUMN_PHONENUMBER = "phonenum";
    public static final String TABLE_NAME = "commonnum";

    /* JADX INFO: renamed from: a */
    private int f5602a;

    /* JADX INFO: renamed from: b */
    private String f5603b;

    /* JADX INFO: renamed from: c */
    private String f5604c;

    /* JADX INFO: renamed from: d */
    private Category f5605d;

    public CommonNumber() {
    }

    public CommonNumber(int id, String name, String phoneNumber, int categoryId, String categoryName) {
        this(id, name, phoneNumber);
        this.f5605d = new Category(categoryId, categoryName);
    }

    public CommonNumber(int id, String name, String phoneNumber, Category category) {
        this(id, name, phoneNumber);
        this.f5605d = category;
    }

    public CommonNumber(int id, String name, String phoneNumber) {
        this.f5602a = id;
        this.f5603b = name;
        this.f5604c = phoneNumber;
    }

    public int getId() {
        return this.f5602a;
    }

    public void setId(int id) {
        this.f5602a = id;
    }

    public String getName() {
        return this.f5603b;
    }

    public void setName(String name) {
        this.f5603b = name;
    }

    public String getPhoneNumber() {
        return this.f5604c;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.f5604c = phoneNumber;
    }

    public Category getCategory() {
        return this.f5605d;
    }

    public void setCategory(Category category) {
        this.f5605d = category;
    }

    public void setCategory(int categoryId, String categoryName) {
        this.f5605d = new Category(categoryId, categoryName);
    }

    public String toString() {
        return "CommonNumber [id=" + this.f5602a + ", name=" + this.f5603b + ", phoneNumber=" + this.f5604c + ", category=" + this.f5605d + "]";
    }

    public int hashCode() {
        int result = this.f5602a + 31;
        return (result * 31) + (this.f5604c == null ? 0 : this.f5604c.hashCode());
    }

    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj != null && getClass() == obj.getClass()) {
            CommonNumber other = (CommonNumber) obj;
            if (this.f5602a != other.f5602a) {
                return false;
            }
            if (this.f5604c == null) {
                return other.f5604c == null;
            }
            return this.f5604c.equals(other.f5604c);
        }
        return false;
    }
}
