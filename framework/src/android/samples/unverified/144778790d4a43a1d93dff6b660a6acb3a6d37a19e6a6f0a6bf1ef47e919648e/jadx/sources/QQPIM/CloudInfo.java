package QQPIM;

import com.lenovo.safecenter.database.AppDatabase;
import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class CloudInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static BaseInfo f101a;

    /* JADX INFO: renamed from: b */
    static TimeCtrl f102b;

    /* JADX INFO: renamed from: c */
    static TipsInfo f103c;

    /* JADX INFO: renamed from: d */
    static ArrayList<CloudCmd> f104d;

    /* JADX INFO: renamed from: e */
    static final /* synthetic */ boolean f105e;
    public BaseInfo base;
    public ArrayList<CloudCmd> cloudcmds;
    public TimeCtrl time;
    public TipsInfo tips;

    static {
        f105e = !CloudInfo.class.desiredAssertionStatus();
    }

    public CloudInfo() {
        this.base = null;
        this.time = null;
        this.tips = null;
        this.cloudcmds = null;
        this.base = this.base;
        this.time = this.time;
        this.tips = this.tips;
        this.cloudcmds = this.cloudcmds;
    }

    public CloudInfo(BaseInfo baseInfo, TimeCtrl timeCtrl, TipsInfo tipsInfo, ArrayList<CloudCmd> arrayList) {
        this.base = null;
        this.time = null;
        this.tips = null;
        this.cloudcmds = null;
        this.base = baseInfo;
        this.time = timeCtrl;
        this.tips = tipsInfo;
        this.cloudcmds = arrayList;
    }

    public final String className() {
        return "QQPIM.CloudInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f105e) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display((JceStruct) this.base, "base");
        jceDisplayer.display((JceStruct) this.time, AppDatabase.TIME);
        jceDisplayer.display((JceStruct) this.tips, "tips");
        jceDisplayer.display((Collection) this.cloudcmds, "cloudcmds");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        CloudInfo cloudInfo = (CloudInfo) obj;
        return JceUtil.equals(this.base, cloudInfo.base) && JceUtil.equals(this.time, cloudInfo.time) && JceUtil.equals(this.tips, cloudInfo.tips) && JceUtil.equals(this.cloudcmds, cloudInfo.cloudcmds);
    }

    public final String fullClassName() {
        return "QQPIM.CloudInfo";
    }

    public final BaseInfo getBase() {
        return this.base;
    }

    public final ArrayList<CloudCmd> getCloudcmds() {
        return this.cloudcmds;
    }

    public final TimeCtrl getTime() {
        return this.time;
    }

    public final TipsInfo getTips() {
        return this.tips;
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
        if (f101a == null) {
            f101a = new BaseInfo();
        }
        this.base = (BaseInfo) jceInputStream.read((JceStruct) f101a, 0, true);
        if (f102b == null) {
            f102b = new TimeCtrl();
        }
        this.time = (TimeCtrl) jceInputStream.read((JceStruct) f102b, 1, true);
        if (f103c == null) {
            f103c = new TipsInfo();
        }
        this.tips = (TipsInfo) jceInputStream.read((JceStruct) f103c, 2, false);
        if (f104d == null) {
            f104d = new ArrayList<>();
            f104d.add(new CloudCmd());
        }
        setCloudcmds((ArrayList) jceInputStream.read(f104d, 3, false));
    }

    public final void setBase(BaseInfo baseInfo) {
        this.base = baseInfo;
    }

    public final void setCloudcmds(ArrayList<CloudCmd> arrayList) {
        this.cloudcmds = arrayList;
    }

    public final void setTime(TimeCtrl timeCtrl) {
        this.time = timeCtrl;
    }

    public final void setTips(TipsInfo tipsInfo) {
        this.tips = tipsInfo;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write((JceStruct) this.base, 0);
        jceOutputStream.write((JceStruct) this.time, 1);
        if (this.tips != null) {
            jceOutputStream.write((JceStruct) this.tips, 2);
        }
        if (this.cloudcmds != null) {
            jceOutputStream.write((Collection) this.cloudcmds, 3);
        }
    }
}
