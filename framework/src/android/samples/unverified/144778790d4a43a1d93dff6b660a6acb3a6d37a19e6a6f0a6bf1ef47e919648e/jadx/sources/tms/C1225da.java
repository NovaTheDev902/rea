package tms;

import com.tencent.tmsecure.module.network.INetworkInfoDao;
import com.tencent.tmsecure.module.network.NetDataEntity;
import com.tencent.tmsecure.module.network.NetDataEntityFactory;
import java.io.File;

/* JADX INFO: renamed from: tms.da */
/* JADX INFO: loaded from: classes.dex */
final class C1225da extends C1223cz {

    /* JADX INFO: renamed from: tms.da$a */
    static final class a implements NetDataEntityFactory {

        /* JADX INFO: renamed from: a */
        private C1226db f7063a;

        /* JADX INFO: renamed from: b */
        private String f7064b = C1244dt.m3176a();

        public a(C1226db c1226db) {
            this.f7063a = c1226db;
        }

        @Override // com.tencent.tmsecure.module.network.NetDataEntityFactory
        public final NetDataEntity getNetDataEntity() throws Throwable {
            NetDataEntity netDataEntity = new NetDataEntity();
            long[] jArr = {0, 0, 0, 0};
            String[] strArrM3593b = C1336v.m3593b(new File(this.f7064b));
            if (strArrM3593b != null) {
                synchronized (strArrM3593b) {
                    for (String str : strArrM3593b) {
                        String[] strArrSplit = str.trim().split("[: ]+");
                        if (this.f7063a.m3095b(strArrSplit[0].trim().toLowerCase())) {
                            jArr[0] = jArr[0] + Long.parseLong(strArrSplit[1]);
                            jArr[1] = jArr[1] + Long.parseLong(strArrSplit[2]);
                            jArr[2] = jArr[2] + Long.parseLong(strArrSplit[9]);
                            jArr[3] = jArr[3] + Long.parseLong(strArrSplit[10]);
                        }
                    }
                }
            }
            netDataEntity.mReceiver = jArr[0];
            netDataEntity.mReceiverPks = jArr[1];
            netDataEntity.mTranslate = jArr[2];
            netDataEntity.mTranslatePks = jArr[3];
            return netDataEntity;
        }
    }

    public C1225da(INetworkInfoDao iNetworkInfoDao, C1226db c1226db) {
        super(new a(c1226db), iNetworkInfoDao);
    }
}
