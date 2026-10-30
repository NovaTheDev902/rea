package QQPIM;

import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.database.AppDatabase;
import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class SUI extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static ArrayList<Integer> f520a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f521b;
    public String desc;

    /* JADX INFO: renamed from: id */
    public int f522id;
    public ArrayList<Integer> ivalues;
    public String paramvalues;
    public int time;

    static {
        f521b = !SUI.class.desiredAssertionStatus();
    }

    public SUI() {
        this.f522id = 0;
        this.time = 0;
        this.desc = "";
        this.ivalues = null;
        this.paramvalues = "";
        this.f522id = this.f522id;
        this.time = this.time;
        this.desc = this.desc;
        this.ivalues = this.ivalues;
        this.paramvalues = this.paramvalues;
    }

    public SUI(int i, int i2, String str, ArrayList<Integer> arrayList, String str2) {
        this.f522id = 0;
        this.time = 0;
        this.desc = "";
        this.ivalues = null;
        this.paramvalues = "";
        this.f522id = i;
        this.time = i2;
        this.desc = str;
        this.ivalues = arrayList;
        this.paramvalues = str2;
    }

    public final String className() {
        return "QQPIM.SUI";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f521b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.f522id, QueryPermissions.f1958ID);
        jceDisplayer.display(this.time, AppDatabase.TIME);
        jceDisplayer.display(this.desc, "desc");
        jceDisplayer.display((Collection) this.ivalues, "ivalues");
        jceDisplayer.display(this.paramvalues, "paramvalues");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        SUI sui = (SUI) obj;
        return JceUtil.equals(this.f522id, sui.f522id) && JceUtil.equals(this.time, sui.time) && JceUtil.equals(this.desc, sui.desc) && JceUtil.equals(this.ivalues, sui.ivalues) && JceUtil.equals(this.paramvalues, sui.paramvalues);
    }

    public final String fullClassName() {
        return "QQPIM.SUI";
    }

    public final String getDesc() {
        return this.desc;
    }

    public final int getId() {
        return this.f522id;
    }

    public final ArrayList<Integer> getIvalues() {
        return this.ivalues;
    }

    public final String getParamvalues() {
        return this.paramvalues;
    }

    public final int getTime() {
        return this.time;
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
        this.f522id = jceInputStream.read(this.f522id, 0, true);
        this.time = jceInputStream.read(this.time, 1, true);
        this.desc = jceInputStream.readString(2, true);
        if (f520a == null) {
            f520a = new ArrayList<>();
            f520a.add(0);
        }
        setIvalues((ArrayList) jceInputStream.read(f520a, 3, false));
        setParamvalues(jceInputStream.readString(4, false));
    }

    public final void setDesc(String str) {
        this.desc = str;
    }

    public final void setId(int i) {
        this.f522id = i;
    }

    public final void setIvalues(ArrayList<Integer> arrayList) {
        this.ivalues = arrayList;
    }

    public final void setParamvalues(String str) {
        this.paramvalues = str;
    }

    public final void setTime(int i) {
        this.time = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.f522id, 0);
        jceOutputStream.write(this.time, 1);
        jceOutputStream.write(this.desc, 2);
        if (this.ivalues != null) {
            jceOutputStream.write((Collection) this.ivalues, 3);
        }
        if (this.paramvalues != null) {
            jceOutputStream.write(this.paramvalues, 4);
        }
    }
}
