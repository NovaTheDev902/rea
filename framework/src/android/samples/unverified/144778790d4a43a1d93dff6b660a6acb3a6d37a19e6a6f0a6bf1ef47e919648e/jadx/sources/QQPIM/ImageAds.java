package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class ImageAds extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f421a;
    public String linkurl;
    public int location;
    public String picurl;
    public int showtime;
    public String title;

    static {
        f421a = !ImageAds.class.desiredAssertionStatus();
    }

    public ImageAds() {
        this.picurl = "";
        this.linkurl = "";
        this.location = 0;
        this.showtime = 0;
        this.title = "";
        this.picurl = this.picurl;
        this.linkurl = this.linkurl;
        this.location = this.location;
        this.showtime = this.showtime;
        this.title = this.title;
    }

    public ImageAds(String str, String str2, int i, int i2, String str3) {
        this.picurl = "";
        this.linkurl = "";
        this.location = 0;
        this.showtime = 0;
        this.title = "";
        this.picurl = str;
        this.linkurl = str2;
        this.location = i;
        this.showtime = i2;
        this.title = str3;
    }

    public final String className() {
        return "QQPIM.ImageAds";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f421a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.picurl, "picurl");
        jceDisplayer.display(this.linkurl, "linkurl");
        jceDisplayer.display(this.location, "location");
        jceDisplayer.display(this.showtime, "showtime");
        jceDisplayer.display(this.title, "title");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        ImageAds imageAds = (ImageAds) obj;
        return JceUtil.equals(this.picurl, imageAds.picurl) && JceUtil.equals(this.linkurl, imageAds.linkurl) && JceUtil.equals(this.location, imageAds.location) && JceUtil.equals(this.showtime, imageAds.showtime) && JceUtil.equals(this.title, imageAds.title);
    }

    public final String fullClassName() {
        return "QQPIM.ImageAds";
    }

    public final String getLinkurl() {
        return this.linkurl;
    }

    public final int getLocation() {
        return this.location;
    }

    public final String getPicurl() {
        return this.picurl;
    }

    public final int getShowtime() {
        return this.showtime;
    }

    public final String getTitle() {
        return this.title;
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
        this.picurl = jceInputStream.readString(0, true);
        this.linkurl = jceInputStream.readString(1, true);
        this.location = jceInputStream.read(this.location, 2, false);
        this.showtime = jceInputStream.read(this.showtime, 3, false);
        this.title = jceInputStream.readString(4, false);
    }

    public final void setLinkurl(String str) {
        this.linkurl = str;
    }

    public final void setLocation(int i) {
        this.location = i;
    }

    public final void setPicurl(String str) {
        this.picurl = str;
    }

    public final void setShowtime(int i) {
        this.showtime = i;
    }

    public final void setTitle(String str) {
        this.title = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.picurl, 0);
        jceOutputStream.write(this.linkurl, 1);
        jceOutputStream.write(this.location, 2);
        jceOutputStream.write(this.showtime, 3);
        if (this.title != null) {
            jceOutputStream.write(this.title, 4);
        }
    }
}
