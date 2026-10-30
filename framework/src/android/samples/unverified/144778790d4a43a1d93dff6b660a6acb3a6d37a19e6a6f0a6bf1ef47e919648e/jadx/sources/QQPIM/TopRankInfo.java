package QQPIM;

import com.lenovo.performancecenter.service.object.PolicyAppInfo;
import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class TopRankInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f590a;
    public String model;

    /* JADX INFO: renamed from: os */
    public String f591os;
    public int score;
    public String user;

    static {
        f590a = !TopRankInfo.class.desiredAssertionStatus();
    }

    public TopRankInfo() {
        this.user = "";
        this.model = "";
        this.f591os = "";
        this.score = 0;
        this.user = this.user;
        this.model = this.model;
        this.f591os = this.f591os;
        this.score = this.score;
    }

    public TopRankInfo(String str, String str2, String str3, int i) {
        this.user = "";
        this.model = "";
        this.f591os = "";
        this.score = 0;
        this.user = str;
        this.model = str2;
        this.f591os = str3;
        this.score = i;
    }

    public final String className() {
        return "QQPIM.TopRankInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f590a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.user, PolicyAppInfo.APP_TYPE_USER);
        jceDisplayer.display(this.model, "model");
        jceDisplayer.display(this.f591os, "os");
        jceDisplayer.display(this.score, "score");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        TopRankInfo topRankInfo = (TopRankInfo) obj;
        return JceUtil.equals(this.user, topRankInfo.user) && JceUtil.equals(this.model, topRankInfo.model) && JceUtil.equals(this.f591os, topRankInfo.f591os) && JceUtil.equals(this.score, topRankInfo.score);
    }

    public final String fullClassName() {
        return "QQPIM.TopRankInfo";
    }

    public final String getModel() {
        return this.model;
    }

    public final String getOs() {
        return this.f591os;
    }

    public final int getScore() {
        return this.score;
    }

    public final String getUser() {
        return this.user;
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
        this.user = jceInputStream.readString(0, true);
        this.model = jceInputStream.readString(1, true);
        this.f591os = jceInputStream.readString(2, true);
        this.score = jceInputStream.read(this.score, 3, true);
    }

    public final void setModel(String str) {
        this.model = str;
    }

    public final void setOs(String str) {
        this.f591os = str;
    }

    public final void setScore(int i) {
        this.score = i;
    }

    public final void setUser(String str) {
        this.user = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.user, 0);
        jceOutputStream.write(this.model, 1);
        jceOutputStream.write(this.f591os, 2);
        jceOutputStream.write(this.score, 3);
    }
}
