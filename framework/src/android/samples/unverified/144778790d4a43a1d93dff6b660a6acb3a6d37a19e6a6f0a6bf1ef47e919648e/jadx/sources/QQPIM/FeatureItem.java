package QQPIM;

import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.database.AppDatabase;
import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class FeatureItem extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f410a;
    public String content;

    /* JADX INFO: renamed from: id */
    public short f411id;

    static {
        f410a = !FeatureItem.class.desiredAssertionStatus();
    }

    public FeatureItem() {
        this.f411id = (short) 0;
        this.content = "";
        this.f411id = this.f411id;
        this.content = this.content;
    }

    public FeatureItem(short s, String str) {
        this.f411id = (short) 0;
        this.content = "";
        this.f411id = s;
        this.content = str;
    }

    public final String className() {
        return "QQPIM.FeatureItem";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f410a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.f411id, QueryPermissions.f1958ID);
        jceDisplayer.display(this.content, AppDatabase.CONTENT);
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        FeatureItem featureItem = (FeatureItem) obj;
        return JceUtil.equals(this.f411id, featureItem.f411id) && JceUtil.equals(this.content, featureItem.content);
    }

    public final String fullClassName() {
        return "QQPIM.FeatureItem";
    }

    public final String getContent() {
        return this.content;
    }

    public final short getId() {
        return this.f411id;
    }

    public final int hashCode() {
        try {
            throw new Exception("Need define key first!");
        } catch (Exception e) {
            e.printStackTrace();
            return 0;
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void readFrom(JceInputStream jceInputStream) {
        this.f411id = jceInputStream.read(this.f411id, 0, true);
        this.content = jceInputStream.readString(1, true);
    }

    public final void setContent(String str) {
        this.content = str;
    }

    public final void setId(short s) {
        this.f411id = s;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.f411id, 0);
        jceOutputStream.write(this.content, 1);
    }
}
