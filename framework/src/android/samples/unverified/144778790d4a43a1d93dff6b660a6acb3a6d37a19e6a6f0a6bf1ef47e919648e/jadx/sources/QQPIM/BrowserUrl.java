package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class BrowserUrl extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f82a;
    public int fileSize;
    public String headMd5;
    public String url;

    static {
        f82a = !BrowserUrl.class.desiredAssertionStatus();
    }

    public BrowserUrl() {
        this.url = "";
        this.headMd5 = "";
        this.fileSize = 0;
        this.url = this.url;
        this.headMd5 = this.headMd5;
        this.fileSize = this.fileSize;
    }

    public BrowserUrl(String str, String str2, int i) {
        this.url = "";
        this.headMd5 = "";
        this.fileSize = 0;
        this.url = str;
        this.headMd5 = str2;
        this.fileSize = i;
    }

    public final String className() {
        return "QQPIM.BrowserUrl";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f82a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.url, "url");
        jceDisplayer.display(this.headMd5, "headMd5");
        jceDisplayer.display(this.fileSize, "fileSize");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        BrowserUrl browserUrl = (BrowserUrl) obj;
        return JceUtil.equals(this.url, browserUrl.url) && JceUtil.equals(this.headMd5, browserUrl.headMd5) && JceUtil.equals(this.fileSize, browserUrl.fileSize);
    }

    public final String fullClassName() {
        return "QQPIM.BrowserUrl";
    }

    public final int getFileSize() {
        return this.fileSize;
    }

    public final String getHeadMd5() {
        return this.headMd5;
    }

    public final String getUrl() {
        return this.url;
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
        this.url = jceInputStream.readString(0, true);
        this.headMd5 = jceInputStream.readString(1, true);
        this.fileSize = jceInputStream.read(this.fileSize, 2, false);
    }

    public final void setFileSize(int i) {
        this.fileSize = i;
    }

    public final void setHeadMd5(String str) {
        this.headMd5 = str;
    }

    public final void setUrl(String str) {
        this.url = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.url, 0);
        jceOutputStream.write(this.headMd5, 1);
        jceOutputStream.write(this.fileSize, 2);
    }
}
