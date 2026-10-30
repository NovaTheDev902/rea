package com.lenovo.safecenter.systeminfo.service;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import com.lenovo.safecenter.systeminfo.entity.Category;
import com.lenovo.safecenter.systeminfo.entity.CommonNumber;
import com.lenovo.safecenter.systeminfo.p010db.DBHelper;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class CommonNumberService {

    /* JADX INFO: renamed from: a */
    private static CommonNumberService f5619a = new CommonNumberService();

    private CommonNumberService() {
    }

    public static CommonNumberService getInstance() {
        return f5619a;
    }

    public List<Category> findAllCategories() {
        List<Category> categories = new ArrayList<>(12);
        SQLiteDatabase db = DBHelper.getInstance().getReadableDatabase();
        Cursor cursor = db.query(Category.TABLE_NAME, null, null, null, null, null, "_id asc ");
        if (cursor != null) {
            while (cursor.moveToNext()) {
                Category category = new Category();
                category.setId(cursor.getInt(cursor.getColumnIndex("_id")));
                category.setName(cursor.getString(cursor.getColumnIndex("name")));
                categories.add(category);
            }
        }
        if (cursor != null) {
            cursor.close();
        }
        db.close();
        return categories;
    }

    public List<CommonNumber> findCommonNumbers(Category category) {
        return findCommonNumbers(category.getId());
    }

    public HashMap<String, List<CommonNumber>> findAllCategoriesAndCommonNumber() {
        HashMap<String, List<CommonNumber>> commonNumbers = new HashMap<>();
        List<Category> categories = findAllCategories();
        for (Category category : categories) {
            List<CommonNumber> cNumbers = findCommonNumbers(category);
            commonNumbers.put(category.getName(), cNumbers);
        }
        return commonNumbers;
    }

    public List<CommonNumber> findCommonNumbers(int categoryId) {
        List<CommonNumber> commonNumbers = new ArrayList<>();
        SQLiteDatabase db = DBHelper.getInstance().getReadableDatabase();
        Cursor cursor = db.query("commonnum cn join category c on cn.c_id=c._id", new String[]{"cn._id", "cn.name", "cn.phonenum"}, "cn.c_id=?", new String[]{categoryId + ""}, null, null, "cn._id asc ");
        if (cursor != null) {
            while (cursor.moveToNext()) {
                CommonNumber commonNumber = new CommonNumber();
                commonNumber.setCategory(categoryId, "");
                commonNumber.setId(cursor.getInt(cursor.getColumnIndex("_id")));
                commonNumber.setName(cursor.getString(cursor.getColumnIndex("name")));
                commonNumber.setPhoneNumber(cursor.getString(cursor.getColumnIndex(CommonNumber.COLUMN_PHONENUMBER)));
                if (!commonNumber.getPhoneNumber().equals("10060")) {
                    commonNumbers.add(commonNumber);
                }
            }
            cursor.close();
        }
        db.close();
        return commonNumbers;
    }

    public List<CommonNumber> findCommonNumbers(String categoryName) {
        return null;
    }
}
