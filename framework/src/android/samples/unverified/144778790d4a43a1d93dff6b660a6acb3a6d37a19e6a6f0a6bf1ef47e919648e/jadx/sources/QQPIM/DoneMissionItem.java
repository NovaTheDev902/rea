package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class DoneMissionItem extends JceStruct {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f126a;
    public int missionid;

    static {
        f126a = !DoneMissionItem.class.desiredAssertionStatus();
    }

    public DoneMissionItem() {
        this.missionid = 0;
        this.missionid = this.missionid;
    }

    public DoneMissionItem(int i) {
        this.missionid = 0;
        this.missionid = i;
    }

    public final String className() {
        return "QQPIM.DoneMissionItem";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f126a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display(this.missionid, "missionid");
    }

    public final boolean equals(Object obj) {
        return JceUtil.equals(this.missionid, ((DoneMissionItem) obj).missionid);
    }

    public final int getMissionid() {
        return this.missionid;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void readFrom(JceInputStream jceInputStream) {
        this.missionid = jceInputStream.read(this.missionid, 0, true);
    }

    public final void setMissionid(int i) {
        this.missionid = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.missionid, 0);
    }
}
