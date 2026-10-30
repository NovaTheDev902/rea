package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class STCloudOrderReq extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static ArrayList<STQueryInfo> f503a;

    /* JADX INFO: renamed from: b */
    static STQueryInfo f504b;

    /* JADX INFO: renamed from: c */
    static ArrayList<Integer> f505c;

    /* JADX INFO: renamed from: d */
    static final /* synthetic */ boolean f506d;
    public boolean block;
    public int nFrequency;
    public STQueryInfo stCodeNow;
    public String strCity;
    public String strHardInfo;
    public String strMonthBalance;
    public String strProvince;
    public String strTaocan;
    public String strTime;
    public String strsimtype;
    public ArrayList<STQueryInfo> vecCodeMuilty;
    public ArrayList<Integer> vecFail;

    static {
        f506d = !STCloudOrderReq.class.desiredAssertionStatus();
    }

    public STCloudOrderReq() {
        this.block = true;
        this.strProvince = "";
        this.strCity = "";
        this.strsimtype = "";
        this.strTaocan = "";
        this.vecCodeMuilty = null;
        this.stCodeNow = null;
        this.nFrequency = 0;
        this.strTime = "";
        this.strHardInfo = "";
        this.strMonthBalance = "";
        this.vecFail = null;
        this.block = this.block;
        this.strProvince = this.strProvince;
        this.strCity = this.strCity;
        this.strsimtype = this.strsimtype;
        this.strTaocan = this.strTaocan;
        this.vecCodeMuilty = this.vecCodeMuilty;
        this.stCodeNow = this.stCodeNow;
        this.nFrequency = this.nFrequency;
        this.strTime = this.strTime;
        this.strHardInfo = this.strHardInfo;
        this.strMonthBalance = this.strMonthBalance;
        this.vecFail = this.vecFail;
    }

    public STCloudOrderReq(boolean z, String str, String str2, String str3, String str4, ArrayList<STQueryInfo> arrayList, STQueryInfo sTQueryInfo, int i, String str5, String str6, String str7, ArrayList<Integer> arrayList2) {
        this.block = true;
        this.strProvince = "";
        this.strCity = "";
        this.strsimtype = "";
        this.strTaocan = "";
        this.vecCodeMuilty = null;
        this.stCodeNow = null;
        this.nFrequency = 0;
        this.strTime = "";
        this.strHardInfo = "";
        this.strMonthBalance = "";
        this.vecFail = null;
        this.block = z;
        this.strProvince = str;
        this.strCity = str2;
        this.strsimtype = str3;
        this.strTaocan = str4;
        this.vecCodeMuilty = arrayList;
        this.stCodeNow = sTQueryInfo;
        this.nFrequency = i;
        this.strTime = str5;
        this.strHardInfo = str6;
        this.strMonthBalance = str7;
        this.vecFail = arrayList2;
    }

    public final String className() {
        return "QQPIM.STCloudOrderReq";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f506d) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.block, "block");
        jceDisplayer.display(this.strProvince, "strProvince");
        jceDisplayer.display(this.strCity, "strCity");
        jceDisplayer.display(this.strsimtype, "strsimtype");
        jceDisplayer.display(this.strTaocan, "strTaocan");
        jceDisplayer.display((Collection) this.vecCodeMuilty, "vecCodeMuilty");
        jceDisplayer.display((JceStruct) this.stCodeNow, "stCodeNow");
        jceDisplayer.display(this.nFrequency, "nFrequency");
        jceDisplayer.display(this.strTime, "strTime");
        jceDisplayer.display(this.strHardInfo, "strHardInfo");
        jceDisplayer.display(this.strMonthBalance, "strMonthBalance");
        jceDisplayer.display((Collection) this.vecFail, "vecFail");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        STCloudOrderReq sTCloudOrderReq = (STCloudOrderReq) obj;
        return JceUtil.equals(this.block, sTCloudOrderReq.block) && JceUtil.equals(this.strProvince, sTCloudOrderReq.strProvince) && JceUtil.equals(this.strCity, sTCloudOrderReq.strCity) && JceUtil.equals(this.strsimtype, sTCloudOrderReq.strsimtype) && JceUtil.equals(this.strTaocan, sTCloudOrderReq.strTaocan) && JceUtil.equals(this.vecCodeMuilty, sTCloudOrderReq.vecCodeMuilty) && JceUtil.equals(this.stCodeNow, sTCloudOrderReq.stCodeNow) && JceUtil.equals(this.nFrequency, sTCloudOrderReq.nFrequency) && JceUtil.equals(this.strTime, sTCloudOrderReq.strTime) && JceUtil.equals(this.strHardInfo, sTCloudOrderReq.strHardInfo) && JceUtil.equals(this.strMonthBalance, sTCloudOrderReq.strMonthBalance) && JceUtil.equals(this.vecFail, sTCloudOrderReq.vecFail);
    }

    public final String fullClassName() {
        return "QQPIM.STCloudOrderReq";
    }

    public final boolean getBlock() {
        return this.block;
    }

    public final int getNFrequency() {
        return this.nFrequency;
    }

    public final STQueryInfo getStCodeNow() {
        return this.stCodeNow;
    }

    public final String getStrCity() {
        return this.strCity;
    }

    public final String getStrHardInfo() {
        return this.strHardInfo;
    }

    public final String getStrMonthBalance() {
        return this.strMonthBalance;
    }

    public final String getStrProvince() {
        return this.strProvince;
    }

    public final String getStrTaocan() {
        return this.strTaocan;
    }

    public final String getStrTime() {
        return this.strTime;
    }

    public final String getStrsimtype() {
        return this.strsimtype;
    }

    public final ArrayList<STQueryInfo> getVecCodeMuilty() {
        return this.vecCodeMuilty;
    }

    public final ArrayList<Integer> getVecFail() {
        return this.vecFail;
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
        this.block = jceInputStream.read(this.block, 0, false);
        this.strProvince = jceInputStream.readString(1, false);
        this.strCity = jceInputStream.readString(2, false);
        this.strsimtype = jceInputStream.readString(3, false);
        this.strTaocan = jceInputStream.readString(4, false);
        if (f503a == null) {
            f503a = new ArrayList<>();
            f503a.add(new STQueryInfo());
        }
        setVecCodeMuilty((ArrayList) jceInputStream.read(f503a, 5, false));
        if (f504b == null) {
            f504b = new STQueryInfo();
        }
        setStCodeNow((STQueryInfo) jceInputStream.read((JceStruct) f504b, 6, false));
        setNFrequency(jceInputStream.read(this.nFrequency, 7, false));
        setStrTime(jceInputStream.readString(8, false));
        setStrHardInfo(jceInputStream.readString(9, false));
        setStrMonthBalance(jceInputStream.readString(10, false));
        if (f505c == null) {
            f505c = new ArrayList<>();
            f505c.add(0);
        }
        setVecFail((ArrayList) jceInputStream.read(f505c, 11, false));
    }

    public final void setBlock(boolean z) {
        this.block = z;
    }

    public final void setNFrequency(int i) {
        this.nFrequency = i;
    }

    public final void setStCodeNow(STQueryInfo sTQueryInfo) {
        this.stCodeNow = sTQueryInfo;
    }

    public final void setStrCity(String str) {
        this.strCity = str;
    }

    public final void setStrHardInfo(String str) {
        this.strHardInfo = str;
    }

    public final void setStrMonthBalance(String str) {
        this.strMonthBalance = str;
    }

    public final void setStrProvince(String str) {
        this.strProvince = str;
    }

    public final void setStrTaocan(String str) {
        this.strTaocan = str;
    }

    public final void setStrTime(String str) {
        this.strTime = str;
    }

    public final void setStrsimtype(String str) {
        this.strsimtype = str;
    }

    public final void setVecCodeMuilty(ArrayList<STQueryInfo> arrayList) {
        this.vecCodeMuilty = arrayList;
    }

    public final void setVecFail(ArrayList<Integer> arrayList) {
        this.vecFail = arrayList;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.block, 0);
        if (this.strProvince != null) {
            jceOutputStream.write(this.strProvince, 1);
        }
        if (this.strCity != null) {
            jceOutputStream.write(this.strCity, 2);
        }
        if (this.strsimtype != null) {
            jceOutputStream.write(this.strsimtype, 3);
        }
        if (this.strTaocan != null) {
            jceOutputStream.write(this.strTaocan, 4);
        }
        if (this.vecCodeMuilty != null) {
            jceOutputStream.write((Collection) this.vecCodeMuilty, 5);
        }
        if (this.stCodeNow != null) {
            jceOutputStream.write((JceStruct) this.stCodeNow, 6);
        }
        jceOutputStream.write(this.nFrequency, 7);
        if (this.strTime != null) {
            jceOutputStream.write(this.strTime, 8);
        }
        if (this.strHardInfo != null) {
            jceOutputStream.write(this.strHardInfo, 9);
        }
        if (this.strMonthBalance != null) {
            jceOutputStream.write(this.strMonthBalance, 10);
        }
        if (this.vecFail != null) {
            jceOutputStream.write((Collection) this.vecFail, 11);
        }
    }
}
