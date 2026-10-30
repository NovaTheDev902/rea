package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import org.apache.commons.httpclient.cookie.Cookie2;

/* JADX INFO: loaded from: classes.dex */
public final class CommentInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static SoftKey f112a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f113b;
    public String comment;
    public int score;
    public SoftKey softkey;

    static {
        f113b = !CommentInfo.class.desiredAssertionStatus();
    }

    public CommentInfo() {
        this.softkey = null;
        this.score = 0;
        this.comment = "";
        this.softkey = this.softkey;
        this.score = this.score;
        this.comment = this.comment;
    }

    public CommentInfo(SoftKey softKey, int i, String str) {
        this.softkey = null;
        this.score = 0;
        this.comment = "";
        this.softkey = softKey;
        this.score = i;
        this.comment = str;
    }

    public final String className() {
        return "QQPIM.CommentInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f113b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display((JceStruct) this.softkey, "softkey");
        jceDisplayer.display(this.score, "score");
        jceDisplayer.display(this.comment, Cookie2.COMMENT);
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        CommentInfo commentInfo = (CommentInfo) obj;
        return JceUtil.equals(this.softkey, commentInfo.softkey) && JceUtil.equals(this.score, commentInfo.score) && JceUtil.equals(this.comment, commentInfo.comment);
    }

    public final String fullClassName() {
        return "QQPIM.CommentInfo";
    }

    public final String getComment() {
        return this.comment;
    }

    public final int getScore() {
        return this.score;
    }

    public final SoftKey getSoftkey() {
        return this.softkey;
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
        if (f112a == null) {
            f112a = new SoftKey();
        }
        this.softkey = (SoftKey) jceInputStream.read((JceStruct) f112a, 0, true);
        this.score = jceInputStream.read(this.score, 1, false);
        this.comment = jceInputStream.readString(2, false);
    }

    public final void setComment(String str) {
        this.comment = str;
    }

    public final void setScore(int i) {
        this.score = i;
    }

    public final void setSoftkey(SoftKey softKey) {
        this.softkey = softKey;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write((JceStruct) this.softkey, 0);
        jceOutputStream.write(this.score, 1);
        if (this.comment != null) {
            jceOutputStream.write(this.comment, 2);
        }
    }
}
