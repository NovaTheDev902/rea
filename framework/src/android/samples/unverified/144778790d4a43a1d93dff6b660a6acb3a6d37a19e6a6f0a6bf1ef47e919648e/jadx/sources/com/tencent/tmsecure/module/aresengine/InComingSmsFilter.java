package com.tencent.tmsecure.module.aresengine;

/* JADX INFO: loaded from: classes.dex */
public abstract class InComingSmsFilter extends DataFilter<SmsEntity> {
    public static final int BLACK_LIST = 4;
    public static final int INTELLIGENT_CHECKING = 64;
    public static final int KEY_WORKDS = 32;
    public static final int LAST_CALLS = 16;
    public static final int MATCH_NULL = -1;
    public static final int REMOVE_PRIVATE_SMS = 1;
    public static final int STRANGER_SMS = 128;
    public static final int SYS_CONTACT = 8;
    public static final int WHITE_LIST = 2;

    /* JADX INFO: renamed from: a */
    static final int f6090a = 0;

    /* JADX INFO: renamed from: b */
    static final int f6091b = 1;

    /* JADX INFO: renamed from: c */
    static final int f6092c = 2;

    public abstract void setBlacklistDao(IContactDao<? extends ContactEntity> iContactDao);

    public abstract void setEntityConvertor(IEntityConverter iEntityConverter);

    public abstract void setIntelligentSmsHandler(IntelligentSmsHandler intelligentSmsHandler);

    public abstract void setKeywordDao(IKeyWordDao iKeyWordDao);

    public abstract void setLastCallLogDao(ILastCallLogDao iLastCallLogDao);

    public abstract void setPhoneDeviceController(IPhoneDeviceController iPhoneDeviceController);

    public abstract void setPrivateSmsDao(ISmsDao<? extends SmsEntity> iSmsDao);

    public abstract void setPrivatelistDao(IContactDao<? extends ContactEntity> iContactDao);

    public abstract void setSmsDao(ISmsDao<? extends SmsEntity> iSmsDao);

    public abstract void setSysDao(AbsSysDao absSysDao);

    public abstract void setWhitelistDao(IContactDao<? extends ContactEntity> iContactDao);
}
