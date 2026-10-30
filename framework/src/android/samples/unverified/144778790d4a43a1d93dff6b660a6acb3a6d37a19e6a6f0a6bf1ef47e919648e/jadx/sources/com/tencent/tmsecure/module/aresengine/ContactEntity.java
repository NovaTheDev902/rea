package com.tencent.tmsecure.module.aresengine;

/* JADX INFO: loaded from: classes.dex */
public class ContactEntity extends TelephonyEntity {

    /* JADX INFO: renamed from: a */
    private static final long f6075a = 1;
    public boolean enableForCalling;
    public boolean enableForSMS;
    public boolean isSimContact;

    public ContactEntity() {
    }

    public ContactEntity(ContactEntity contactEntity) {
        super(contactEntity);
        this.isSimContact = contactEntity.isSimContact;
        this.enableForCalling = contactEntity.enableForCalling;
        this.enableForSMS = contactEntity.enableForSMS;
    }
}
