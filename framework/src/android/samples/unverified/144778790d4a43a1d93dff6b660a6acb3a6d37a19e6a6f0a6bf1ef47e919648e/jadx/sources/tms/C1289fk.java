package tms;

import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.module.phoneservice.UsefulNumberEntity;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import org.apache.http.util.EncodingUtils;

/* JADX INFO: renamed from: tms.fk */
/* JADX INFO: loaded from: classes.dex */
public final class C1289fk extends BaseManager {

    /* JADX INFO: renamed from: a */
    private Context f7330a;

    /* JADX INFO: renamed from: b */
    private HashMap<String, ArrayList<UsefulNumberEntity>> f7331b = new HashMap<>();

    /* JADX INFO: renamed from: c */
    private String m3323c() {
        try {
            InputStream inputStreamOpen = this.f7330a.getResources().getAssets().open("yellowpage.db");
            byte[] bArr = new byte[inputStreamOpen.available()];
            inputStreamOpen.read(bArr);
            inputStreamOpen.close();
            return EncodingUtils.getString(bArr, "utf-8");
        } catch (Exception e) {
            e.printStackTrace();
            return "";
        }
    }

    /* JADX INFO: renamed from: a */
    public final List<UsefulNumberEntity> m3324a() {
        ArrayList arrayList = new ArrayList();
        Iterator<ArrayList<UsefulNumberEntity>> it = this.f7331b.values().iterator();
        while (it.hasNext()) {
            arrayList.addAll(it.next());
        }
        return arrayList;
    }

    /* JADX INFO: renamed from: b */
    public final HashMap<String, ArrayList<UsefulNumberEntity>> m3325b() {
        return this.f7331b;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final int getSingletonType() {
        return 2;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f7330a = context;
        ArrayList<UsefulNumberEntity> arrayList = null;
        for (String str : m3323c().trim().split("\\n")) {
            String strTrim = str.trim();
            if (strTrim.contains("@")) {
                arrayList = new ArrayList<>();
                this.f7331b.put(strTrim.replace("@", ""), arrayList);
            } else if (arrayList != null) {
                int iIndexOf = strTrim.indexOf(36);
                String strSubstring = strTrim.substring(0, iIndexOf);
                String strSubstring2 = strTrim.substring(iIndexOf + 1, strTrim.length());
                UsefulNumberEntity usefulNumberEntity = new UsefulNumberEntity();
                usefulNumberEntity.setNumber(strSubstring);
                usefulNumberEntity.setName(strSubstring2);
                arrayList.add(usefulNumberEntity);
            }
        }
    }
}
