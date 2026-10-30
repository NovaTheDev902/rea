package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class NetInterfaceTypeInfoList extends JceStruct {

    /* JADX INFO: renamed from: a */
    static ArrayList<NetInterfaceTypeInfo> f458a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f459b;
    public ArrayList<NetInterfaceTypeInfo> vctInterfaceInfos;

    static {
        f459b = !NetInterfaceTypeInfoList.class.desiredAssertionStatus();
    }

    public NetInterfaceTypeInfoList() {
        this.vctInterfaceInfos = null;
        this.vctInterfaceInfos = this.vctInterfaceInfos;
    }

    public NetInterfaceTypeInfoList(ArrayList<NetInterfaceTypeInfo> arrayList) {
        this.vctInterfaceInfos = null;
        this.vctInterfaceInfos = arrayList;
    }

    public final String className() {
        return "QQPIM.NetInterfaceTypeInfoList";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f459b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        new JceDisplayer(sb, i).display((Collection) this.vctInterfaceInfos, "vctInterfaceInfos");
    }

    public final boolean equals(Object obj) {
        return JceUtil.equals(this.vctInterfaceInfos, ((NetInterfaceTypeInfoList) obj).vctInterfaceInfos);
    }

    public final ArrayList<NetInterfaceTypeInfo> getVctInterfaceInfos() {
        return this.vctInterfaceInfos;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void readFrom(JceInputStream jceInputStream) {
        if (f458a == null) {
            f458a = new ArrayList<>();
            f458a.add(new NetInterfaceTypeInfo());
        }
        setVctInterfaceInfos((ArrayList) jceInputStream.read(f458a, 0, true));
    }

    public final void setVctInterfaceInfos(ArrayList<NetInterfaceTypeInfo> arrayList) {
        this.vctInterfaceInfos = arrayList;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write((Collection) this.vctInterfaceInfos, 0);
    }
}
