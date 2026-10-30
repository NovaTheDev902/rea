package com.lenovo.safecenter.systeminfo.p011ui.activity;

import android.content.ContentResolver;
import android.content.ContentUris;
import android.content.ContentValues;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.provider.ContactsContract;
import android.view.View;
import android.widget.BaseExpandableListAdapter;
import android.widget.ExpandableListView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.systeminfo.adapter.DialCommonPhoneExAdapter;
import com.lenovo.safecenter.systeminfo.entity.CommonNumber;
import com.lenovo.safecenter.systeminfo.service.CommonNumberService;
import com.lenovo.safecenter.utils.Const;
import java.util.HashMap;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class CommonNumberActivity extends BaseTitleActivity {
    protected static final String TAG = CommonNumberActivity.class.getSimpleName();

    /* JADX INFO: renamed from: a */
    private ExpandableListView f5635a;

    /* JADX INFO: renamed from: b */
    private DialCommonPhoneExAdapter f5636b;

    /* JADX INFO: renamed from: c */
    private HashMap<String, List<CommonNumber>> f5637c;

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.common_number);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.number_space, (Integer) null);
        this.f5635a = (ExpandableListView) findViewById(C0415R.id.dialphone_exList);
        this.f5635a.setGroupIndicator(null);
        this.f5635a.setDivider(getResources().getDrawable(C0415R.drawable.list_line));
        this.f5635a.setChildDivider(getResources().getDrawable(C0415R.drawable.list_line));
        this.f5637c = CommonNumberService.getInstance().findAllCategoriesAndCommonNumber();
        this.f5636b = new DialCommonPhoneExAdapter(this, this.f5637c);
        this.f5635a.setAdapter(this.f5636b);
        this.f5635a.setOnCreateContextMenuListener(this);
        this.f5635a.setOnGroupClickListener(new ExpandableListView.OnGroupClickListener() { // from class: com.lenovo.safecenter.systeminfo.ui.activity.CommonNumberActivity.1
            @Override // android.widget.ExpandableListView.OnGroupClickListener
            public final boolean onGroupClick(ExpandableListView parent, View v, int groupPosition, long id) {
                BaseExpandableListAdapter adapter = (BaseExpandableListAdapter) parent.getExpandableListAdapter();
                for (int i = 0; i < adapter.getGroupCount(); i++) {
                    if (i != groupPosition) {
                        CommonNumberActivity.this.f5635a.collapseGroup(i);
                    }
                }
                if (CommonNumberActivity.this.f5635a.isGroupExpanded(groupPosition)) {
                    CommonNumberActivity.this.f5635a.collapseGroup(groupPosition);
                    return true;
                }
                CommonNumberActivity.this.f5635a.expandGroup(groupPosition);
                CommonNumberActivity.this.f5635a.setSelectedGroup(groupPosition);
                return true;
            }
        });
        this.f5635a.setOnChildClickListener(new ExpandableListView.OnChildClickListener() { // from class: com.lenovo.safecenter.systeminfo.ui.activity.CommonNumberActivity.2
            @Override // android.widget.ExpandableListView.OnChildClickListener
            public final boolean onChildClick(ExpandableListView parent, View v, int groupPosition, int childPosition, long id) {
                String phoneNumber = ((CommonNumber) parent.getExpandableListAdapter().getChild(groupPosition, childPosition)).getPhoneNumber();
                Intent localIntent = new Intent("android.intent.action.DIAL", Uri.parse("tel:" + phoneNumber));
                localIntent.setFlags(268435456);
                Const.mContext.startActivity(localIntent);
                return true;
            }
        });
    }

    public void addContact(String displayName, String phoneNumber) {
        Uri uri = ContactsContract.RawContacts.CONTENT_URI;
        ContentResolver cResolver = getContentResolver();
        ContentValues values = new ContentValues();
        Uri insertedUri = cResolver.insert(uri, values);
        long insertedContactId = ContentUris.parseId(insertedUri);
        ContentValues nameValues = new ContentValues();
        nameValues.put("raw_contact_id", Long.valueOf(insertedContactId));
        nameValues.put("mimetype", "vnd.android.cursor.item/name");
        nameValues.put("data2", displayName);
        getContentResolver().insert(ContactsContract.Data.CONTENT_URI, nameValues);
        ContentValues phoneValues = new ContentValues();
        phoneValues.put("raw_contact_id", Long.valueOf(insertedContactId));
        phoneValues.put("mimetype", "vnd.android.cursor.item/phone_v2");
        phoneValues.put("data1", phoneNumber);
        phoneValues.put("data2", (Integer) 2);
        getContentResolver().insert(ContactsContract.Data.CONTENT_URI, phoneValues);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        super.onClick(v);
        switch (v.getId()) {
            case C0415R.id.base_title_left /* 2131297465 */:
                finish();
                break;
        }
    }
}
