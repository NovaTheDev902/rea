package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class MySoftSimpleInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static SoftSimpleInfo f454a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f455b;
    public int official;
    public int reportFeature;
    public SoftSimpleInfo softSimpleInfo;
    public int update;

    static {
        f455b = !MySoftSimpleInfo.class.desiredAssertionStatus();
    }

    public MySoftSimpleInfo() {
        this.softSimpleInfo = null;
        this.reportFeature = 0;
        this.official = 0;
        this.update = 0;
        this.softSimpleInfo = this.softSimpleInfo;
        this.reportFeature = this.reportFeature;
        this.official = this.official;
        this.update = this.update;
    }

    public MySoftSimpleInfo(SoftSimpleInfo softSimpleInfo, int i, int i2, int i3) {
        this.softSimpleInfo = null;
        this.reportFeature = 0;
        this.official = 0;
        this.update = 0;
        this.softSimpleInfo = softSimpleInfo;
        this.reportFeature = i;
        this.official = i2;
        this.update = i3;
    }

    public final String className() {
        return "QQPIM.MySoftSimpleInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f455b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display((JceStruct) this.softSimpleInfo, "softSimpleInfo");
        jceDisplayer.display(this.reportFeature, "reportFeature");
        jceDisplayer.display(this.official, "official");
        jceDisplayer.display(this.update, "update");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        MySoftSimpleInfo mySoftSimpleInfo = (MySoftSimpleInfo) obj;
        return JceUtil.equals(this.softSimpleInfo, mySoftSimpleInfo.softSimpleInfo) && JceUtil.equals(this.reportFeature, mySoftSimpleInfo.reportFeature) && JceUtil.equals(this.official, mySoftSimpleInfo.official) && JceUtil.equals(this.update, mySoftSimpleInfo.update);
    }

    public final String fullClassName() {
        return "QQPIM.MySoftSimpleInfo";
    }

    public final int getOfficial() {
        return this.official;
    }

    public final int getReportFeature() {
        return this.reportFeature;
    }

    public final SoftSimpleInfo getSoftSimpleInfo() {
        return this.softSimpleInfo;
    }

    public final int getUpdate() {
        return this.update;
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
        if (f454a == null) {
            f454a = new SoftSimpleInfo();
        }
        this.softSimpleInfo = (SoftSimpleInfo) jceInputStream.read((JceStruct) f454a, 0, true);
        this.reportFeature = jceInputStream.read(this.reportFeature, 1, false);
        this.official = jceInputStream.read(this.official, 2, false);
        this.update = jceInputStream.read(this.update, 3, false);
    }

    public final void setOfficial(int i) {
        this.official = i;
    }

    public final void setReportFeature(int i) {
        this.reportFeature = i;
    }

    public final void setSoftSimpleInfo(SoftSimpleInfo softSimpleInfo) {
        this.softSimpleInfo = softSimpleInfo;
    }

    public final void setUpdate(int i) {
        this.update = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write((JceStruct) this.softSimpleInfo, 0);
        jceOutputStream.write(this.reportFeature, 1);
        jceOutputStream.write(this.official, 2);
        jceOutputStream.write(this.update, 3);
    }
}
