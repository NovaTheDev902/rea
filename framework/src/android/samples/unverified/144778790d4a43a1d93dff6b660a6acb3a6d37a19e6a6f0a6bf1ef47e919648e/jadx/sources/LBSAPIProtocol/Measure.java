package LBSAPIProtocol;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class Measure extends JceStruct {

    /* JADX INFO: renamed from: a */
    static GPS f13a;

    /* JADX INFO: renamed from: b */
    static ArrayList f14b;

    /* JADX INFO: renamed from: c */
    static ArrayList f15c;

    /* JADX INFO: renamed from: d */
    static final /* synthetic */ boolean f16d;
    public long lTime;
    public GPS stGps;
    public String strExtraInfo;
    public ArrayList vCells;
    public ArrayList vMacs;

    static {
        f16d = !Measure.class.desiredAssertionStatus();
    }

    public Measure() {
        this.stGps = null;
        this.vMacs = null;
        this.vCells = null;
        this.lTime = 0L;
        this.strExtraInfo = "";
        this.stGps = this.stGps;
        this.vMacs = this.vMacs;
        this.vCells = this.vCells;
        this.lTime = this.lTime;
        this.strExtraInfo = this.strExtraInfo;
    }

    public Measure(GPS gps, ArrayList arrayList, ArrayList arrayList2, long j, String str) {
        this.stGps = null;
        this.vMacs = null;
        this.vCells = null;
        this.lTime = 0L;
        this.strExtraInfo = "";
        this.stGps = gps;
        this.vMacs = arrayList;
        this.vCells = arrayList2;
        this.lTime = j;
        this.strExtraInfo = str;
    }

    public final String className() {
        return "LBSAPIProtocol.Measure";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f16d) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display((JceStruct) this.stGps, "stGps");
        jceDisplayer.display((Collection) this.vMacs, "vMacs");
        jceDisplayer.display((Collection) this.vCells, "vCells");
        jceDisplayer.display(this.lTime, "lTime");
        jceDisplayer.display(this.strExtraInfo, "strExtraInfo");
    }

    public final boolean equals(Object obj) {
        Measure measure = (Measure) obj;
        return JceUtil.equals(this.stGps, measure.stGps) && JceUtil.equals(this.vMacs, measure.vMacs) && JceUtil.equals(this.vCells, measure.vCells) && JceUtil.equals(this.lTime, measure.lTime) && JceUtil.equals(this.strExtraInfo, measure.strExtraInfo);
    }

    public final long getLTime() {
        return this.lTime;
    }

    public final GPS getStGps() {
        return this.stGps;
    }

    public final String getStrExtraInfo() {
        return this.strExtraInfo;
    }

    public final ArrayList getVCells() {
        return this.vCells;
    }

    public final ArrayList getVMacs() {
        return this.vMacs;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void readFrom(JceInputStream jceInputStream) {
        if (f13a == null) {
            f13a = new GPS();
        }
        this.stGps = (GPS) jceInputStream.read((JceStruct) f13a, 0, true);
        if (f14b == null) {
            f14b = new ArrayList();
            f14b.add(0L);
        }
        setVMacs((ArrayList) jceInputStream.read(f14b, 1, true));
        if (f15c == null) {
            f15c = new ArrayList();
            f15c.add(new Cell());
        }
        setVCells((ArrayList) jceInputStream.read(f15c, 2, true));
        setLTime(jceInputStream.read(this.lTime, 3, true));
        setStrExtraInfo(jceInputStream.readString(4, false));
    }

    public final void setLTime(long j) {
        this.lTime = j;
    }

    public final void setStGps(GPS gps) {
        this.stGps = gps;
    }

    public final void setStrExtraInfo(String str) {
        this.strExtraInfo = str;
    }

    public final void setVCells(ArrayList arrayList) {
        this.vCells = arrayList;
    }

    public final void setVMacs(ArrayList arrayList) {
        this.vMacs = arrayList;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write((JceStruct) this.stGps, 0);
        jceOutputStream.write((Collection) this.vMacs, 1);
        jceOutputStream.write((Collection) this.vCells, 2);
        jceOutputStream.write(this.lTime, 3);
        if (this.strExtraInfo != null) {
            jceOutputStream.write(this.strExtraInfo, 4);
        }
    }
}
