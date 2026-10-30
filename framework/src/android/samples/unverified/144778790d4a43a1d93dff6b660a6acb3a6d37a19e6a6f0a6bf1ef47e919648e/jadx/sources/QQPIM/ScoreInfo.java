package QQPIM;

import com.lenovo.performancecenter.service.object.PolicyAppInfo;
import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class ScoreInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f535a;
    public int score;
    public String scoredetail;
    public String user;

    static {
        f535a = !ScoreInfo.class.desiredAssertionStatus();
    }

    public ScoreInfo() {
        this.user = "";
        this.score = 0;
        this.scoredetail = "";
        this.user = this.user;
        this.score = this.score;
        this.scoredetail = this.scoredetail;
    }

    public ScoreInfo(String str, int i, String str2) {
        this.user = "";
        this.score = 0;
        this.scoredetail = "";
        this.user = str;
        this.score = i;
        this.scoredetail = str2;
    }

    public final String className() {
        return "QQPIM.ScoreInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f535a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.user, PolicyAppInfo.APP_TYPE_USER);
        jceDisplayer.display(this.score, "score");
        jceDisplayer.display(this.scoredetail, "scoredetail");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        ScoreInfo scoreInfo = (ScoreInfo) obj;
        return JceUtil.equals(this.user, scoreInfo.user) && JceUtil.equals(this.score, scoreInfo.score) && JceUtil.equals(this.scoredetail, scoreInfo.scoredetail);
    }

    public final String fullClassName() {
        return "QQPIM.ScoreInfo";
    }

    public final int getScore() {
        return this.score;
    }

    public final String getScoredetail() {
        return this.scoredetail;
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
        this.score = jceInputStream.read(this.score, 1, true);
        this.scoredetail = jceInputStream.readString(2, true);
    }

    public final void setScore(int i) {
        this.score = i;
    }

    public final void setScoredetail(String str) {
        this.scoredetail = str;
    }

    public final void setUser(String str) {
        this.user = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.user, 0);
        jceOutputStream.write(this.score, 1);
        jceOutputStream.write(this.scoredetail, 2);
    }
}
