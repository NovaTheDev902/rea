package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class ReportMission extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static QQInfo f486a;

    /* JADX INFO: renamed from: b */
    static ArrayList<MissionItem> f487b;

    /* JADX INFO: renamed from: c */
    static final /* synthetic */ boolean f488c;
    public ArrayList<MissionItem> missions;

    /* JADX INFO: renamed from: qq */
    public QQInfo f489qq;

    static {
        f488c = !ReportMission.class.desiredAssertionStatus();
    }

    public ReportMission() {
        this.f489qq = null;
        this.missions = null;
        this.f489qq = this.f489qq;
        this.missions = this.missions;
    }

    public ReportMission(QQInfo qQInfo, ArrayList<MissionItem> arrayList) {
        this.f489qq = null;
        this.missions = null;
        this.f489qq = qQInfo;
        this.missions = arrayList;
    }

    public final String className() {
        return "QQPIM.ReportMission";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f488c) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display((JceStruct) this.f489qq, "qq");
        jceDisplayer.display((Collection) this.missions, "missions");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        ReportMission reportMission = (ReportMission) obj;
        return JceUtil.equals(this.f489qq, reportMission.f489qq) && JceUtil.equals(this.missions, reportMission.missions);
    }

    public final String fullClassName() {
        return "QQPIM.ReportMission";
    }

    public final ArrayList<MissionItem> getMissions() {
        return this.missions;
    }

    public final QQInfo getQq() {
        return this.f489qq;
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
        if (f486a == null) {
            f486a = new QQInfo();
        }
        this.f489qq = (QQInfo) jceInputStream.read((JceStruct) f486a, 0, true);
        if (f487b == null) {
            f487b = new ArrayList<>();
            f487b.add(new MissionItem());
        }
        setMissions((ArrayList) jceInputStream.read(f487b, 1, true));
    }

    public final void setMissions(ArrayList<MissionItem> arrayList) {
        this.missions = arrayList;
    }

    public final void setQq(QQInfo qQInfo) {
        this.f489qq = qQInfo;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write((JceStruct) this.f489qq, 0);
        jceOutputStream.write((Collection) this.missions, 1);
    }
}
