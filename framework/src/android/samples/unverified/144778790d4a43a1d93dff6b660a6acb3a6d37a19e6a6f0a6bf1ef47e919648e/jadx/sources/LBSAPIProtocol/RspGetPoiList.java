package LBSAPIProtocol;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class RspGetPoiList extends JceStruct {

    /* JADX INFO: renamed from: a */
    static GPS f48a;

    /* JADX INFO: renamed from: b */
    static ArrayList f49b;

    /* JADX INFO: renamed from: c */
    static final /* synthetic */ boolean f50c;
    public int iTotalNum;
    public GPS stUsrLoc;
    public ArrayList vPoiList;

    static {
        f50c = !RspGetPoiList.class.desiredAssertionStatus();
    }

    public RspGetPoiList() {
        this.stUsrLoc = null;
        this.iTotalNum = 0;
        this.vPoiList = null;
        this.stUsrLoc = this.stUsrLoc;
        this.iTotalNum = this.iTotalNum;
        this.vPoiList = this.vPoiList;
    }

    public RspGetPoiList(GPS gps, int i, ArrayList arrayList) {
        this.stUsrLoc = null;
        this.iTotalNum = 0;
        this.vPoiList = null;
        this.stUsrLoc = gps;
        this.iTotalNum = i;
        this.vPoiList = arrayList;
    }

    public final String className() {
        return "LBSAPIProtocol.RspGetPoiList";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f50c) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display((JceStruct) this.stUsrLoc, "stUsrLoc");
        jceDisplayer.display(this.iTotalNum, "iTotalNum");
        jceDisplayer.display((Collection) this.vPoiList, "vPoiList");
    }

    public final boolean equals(Object obj) {
        RspGetPoiList rspGetPoiList = (RspGetPoiList) obj;
        return JceUtil.equals(this.stUsrLoc, rspGetPoiList.stUsrLoc) && JceUtil.equals(this.iTotalNum, rspGetPoiList.iTotalNum) && JceUtil.equals(this.vPoiList, rspGetPoiList.vPoiList);
    }

    public final String fullClassName() {
        return "LBSAPIProtocol.RspGetPoiList";
    }

    public final int getITotalNum() {
        return this.iTotalNum;
    }

    public final GPS getStUsrLoc() {
        return this.stUsrLoc;
    }

    public final ArrayList getVPoiList() {
        return this.vPoiList;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void readFrom(JceInputStream jceInputStream) {
        if (f48a == null) {
            f48a = new GPS();
        }
        this.stUsrLoc = (GPS) jceInputStream.read((JceStruct) f48a, 0, true);
        this.iTotalNum = jceInputStream.read(this.iTotalNum, 1, true);
        if (f49b == null) {
            f49b = new ArrayList();
            f49b.add(new PoiInfo());
        }
        setVPoiList((ArrayList) jceInputStream.read(f49b, 2, true));
    }

    public final void setITotalNum(int i) {
        this.iTotalNum = i;
    }

    public final void setStUsrLoc(GPS gps) {
        this.stUsrLoc = gps;
    }

    public final void setVPoiList(ArrayList arrayList) {
        this.vPoiList = arrayList;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write((JceStruct) this.stUsrLoc, 0);
        jceOutputStream.write(this.iTotalNum, 1);
        jceOutputStream.write((Collection) this.vPoiList, 2);
    }
}
