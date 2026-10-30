package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class Missions extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static PointsInfo f443a;

    /* JADX INFO: renamed from: b */
    static ArrayList<MissionItem> f444b;

    /* JADX INFO: renamed from: c */
    static ArrayList<CloudInfo> f445c;

    /* JADX INFO: renamed from: d */
    static final /* synthetic */ boolean f446d;
    public ArrayList<CloudInfo> cloudinfos;
    public PointsInfo hpoints;
    public ArrayList<MissionItem> missions;

    static {
        f446d = !Missions.class.desiredAssertionStatus();
    }

    public Missions() {
        this.hpoints = null;
        this.missions = null;
        this.cloudinfos = null;
        this.hpoints = this.hpoints;
        this.missions = this.missions;
        this.cloudinfos = this.cloudinfos;
    }

    public Missions(PointsInfo pointsInfo, ArrayList<MissionItem> arrayList, ArrayList<CloudInfo> arrayList2) {
        this.hpoints = null;
        this.missions = null;
        this.cloudinfos = null;
        this.hpoints = pointsInfo;
        this.missions = arrayList;
        this.cloudinfos = arrayList2;
    }

    public final String className() {
        return "QQPIM.Missions";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f446d) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display((JceStruct) this.hpoints, "hpoints");
        jceDisplayer.display((Collection) this.missions, "missions");
        jceDisplayer.display((Collection) this.cloudinfos, "cloudinfos");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        Missions missions = (Missions) obj;
        return JceUtil.equals(this.hpoints, missions.hpoints) && JceUtil.equals(this.missions, missions.missions) && JceUtil.equals(this.cloudinfos, missions.cloudinfos);
    }

    public final String fullClassName() {
        return "QQPIM.Missions";
    }

    public final ArrayList<CloudInfo> getCloudinfos() {
        return this.cloudinfos;
    }

    public final PointsInfo getHpoints() {
        return this.hpoints;
    }

    public final ArrayList<MissionItem> getMissions() {
        return this.missions;
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
        if (f443a == null) {
            f443a = new PointsInfo();
        }
        this.hpoints = (PointsInfo) jceInputStream.read((JceStruct) f443a, 0, true);
        if (f444b == null) {
            f444b = new ArrayList<>();
            f444b.add(new MissionItem());
        }
        setMissions((ArrayList) jceInputStream.read(f444b, 1, true));
        if (f445c == null) {
            f445c = new ArrayList<>();
            f445c.add(new CloudInfo());
        }
        setCloudinfos((ArrayList) jceInputStream.read(f445c, 2, true));
    }

    public final void setCloudinfos(ArrayList<CloudInfo> arrayList) {
        this.cloudinfos = arrayList;
    }

    public final void setHpoints(PointsInfo pointsInfo) {
        this.hpoints = pointsInfo;
    }

    public final void setMissions(ArrayList<MissionItem> arrayList) {
        this.missions = arrayList;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write((JceStruct) this.hpoints, 0);
        jceOutputStream.write((Collection) this.missions, 1);
        jceOutputStream.write((Collection) this.cloudinfos, 2);
    }
}
