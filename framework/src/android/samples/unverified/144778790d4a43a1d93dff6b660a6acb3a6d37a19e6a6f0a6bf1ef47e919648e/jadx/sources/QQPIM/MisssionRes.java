package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class MisssionRes extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static ResCode f447a;

    /* JADX INFO: renamed from: b */
    static Missions f448b;

    /* JADX INFO: renamed from: c */
    static final /* synthetic */ boolean f449c;
    public Missions missions;
    public ResCode rescode;

    static {
        f449c = !MisssionRes.class.desiredAssertionStatus();
    }

    public MisssionRes() {
        this.rescode = null;
        this.missions = null;
        this.rescode = this.rescode;
        this.missions = this.missions;
    }

    public MisssionRes(ResCode resCode, Missions missions) {
        this.rescode = null;
        this.missions = null;
        this.rescode = resCode;
        this.missions = missions;
    }

    public final String className() {
        return "QQPIM.MisssionRes";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f449c) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display((JceStruct) this.rescode, "rescode");
        jceDisplayer.display((JceStruct) this.missions, "missions");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        MisssionRes misssionRes = (MisssionRes) obj;
        return JceUtil.equals(this.rescode, misssionRes.rescode) && JceUtil.equals(this.missions, misssionRes.missions);
    }

    public final String fullClassName() {
        return "QQPIM.MisssionRes";
    }

    public final Missions getMissions() {
        return this.missions;
    }

    public final ResCode getRescode() {
        return this.rescode;
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
        if (f447a == null) {
            f447a = new ResCode();
        }
        this.rescode = (ResCode) jceInputStream.read((JceStruct) f447a, 0, true);
        if (f448b == null) {
            f448b = new Missions();
        }
        this.missions = (Missions) jceInputStream.read((JceStruct) f448b, 1, true);
    }

    public final void setMissions(Missions missions) {
        this.missions = missions;
    }

    public final void setRescode(ResCode resCode) {
        this.rescode = resCode;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write((JceStruct) this.rescode, 0);
        jceOutputStream.write((JceStruct) this.missions, 1);
    }
}
