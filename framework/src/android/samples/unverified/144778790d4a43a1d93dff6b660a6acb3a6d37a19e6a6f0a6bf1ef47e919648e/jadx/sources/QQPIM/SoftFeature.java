package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class SoftFeature extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static FeatureKey f552a;

    /* JADX INFO: renamed from: b */
    static ArrayList<FeatureItem> f553b;

    /* JADX INFO: renamed from: c */
    static final /* synthetic */ boolean f554c;
    public int appid;
    public int category;
    public int engineVersion;
    public FeatureKey featureKey;
    public boolean isBuildIn;
    public int localSafeType;
    public int localVirusID;
    public String localVirusName;
    public int position;
    public int requestType;
    public int softDescTimestamp;
    public ArrayList<FeatureItem> vecFeatureItem;
    public int virusDescTimestamp;

    static {
        f554c = !SoftFeature.class.desiredAssertionStatus();
    }

    public SoftFeature() {
        this.featureKey = null;
        this.softDescTimestamp = 0;
        this.virusDescTimestamp = 0;
        this.vecFeatureItem = null;
        this.requestType = 0;
        this.isBuildIn = false;
        this.category = 0;
        this.position = 0;
        this.engineVersion = 0;
        this.localSafeType = 0;
        this.localVirusName = "";
        this.localVirusID = 0;
        this.appid = 0;
        this.featureKey = this.featureKey;
        this.softDescTimestamp = this.softDescTimestamp;
        this.virusDescTimestamp = this.virusDescTimestamp;
        this.vecFeatureItem = this.vecFeatureItem;
        this.requestType = this.requestType;
        this.isBuildIn = this.isBuildIn;
        this.category = this.category;
        this.position = this.position;
        this.engineVersion = this.engineVersion;
        this.localSafeType = this.localSafeType;
        this.localVirusName = this.localVirusName;
        this.localVirusID = this.localVirusID;
        this.appid = this.appid;
    }

    public SoftFeature(FeatureKey featureKey, int i, int i2, ArrayList<FeatureItem> arrayList, int i3, boolean z, int i4, int i5, int i6, int i7, String str, int i8, int i9) {
        this.featureKey = null;
        this.softDescTimestamp = 0;
        this.virusDescTimestamp = 0;
        this.vecFeatureItem = null;
        this.requestType = 0;
        this.isBuildIn = false;
        this.category = 0;
        this.position = 0;
        this.engineVersion = 0;
        this.localSafeType = 0;
        this.localVirusName = "";
        this.localVirusID = 0;
        this.appid = 0;
        this.featureKey = featureKey;
        this.softDescTimestamp = i;
        this.virusDescTimestamp = i2;
        this.vecFeatureItem = arrayList;
        this.requestType = i3;
        this.isBuildIn = z;
        this.category = i4;
        this.position = i5;
        this.engineVersion = i6;
        this.localSafeType = i7;
        this.localVirusName = str;
        this.localVirusID = i8;
        this.appid = i9;
    }

    public final String className() {
        return "QQPIM.SoftFeature";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f554c) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display((JceStruct) this.featureKey, "featureKey");
        jceDisplayer.display(this.softDescTimestamp, "softDescTimestamp");
        jceDisplayer.display(this.virusDescTimestamp, "virusDescTimestamp");
        jceDisplayer.display((Collection) this.vecFeatureItem, "vecFeatureItem");
        jceDisplayer.display(this.requestType, "requestType");
        jceDisplayer.display(this.isBuildIn, "isBuildIn");
        jceDisplayer.display(this.category, com.lenovo.safecenter.systeminfo.entity.Category.TABLE_NAME);
        jceDisplayer.display(this.position, "position");
        jceDisplayer.display(this.engineVersion, "engineVersion");
        jceDisplayer.display(this.localSafeType, "localSafeType");
        jceDisplayer.display(this.localVirusName, "localVirusName");
        jceDisplayer.display(this.localVirusID, "localVirusID");
        jceDisplayer.display(this.appid, "appid");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        SoftFeature softFeature = (SoftFeature) obj;
        return JceUtil.equals(this.featureKey, softFeature.featureKey) && JceUtil.equals(this.softDescTimestamp, softFeature.softDescTimestamp) && JceUtil.equals(this.virusDescTimestamp, softFeature.virusDescTimestamp) && JceUtil.equals(this.vecFeatureItem, softFeature.vecFeatureItem) && JceUtil.equals(this.requestType, softFeature.requestType) && JceUtil.equals(this.isBuildIn, softFeature.isBuildIn) && JceUtil.equals(this.category, softFeature.category) && JceUtil.equals(this.position, softFeature.position) && JceUtil.equals(this.engineVersion, softFeature.engineVersion) && JceUtil.equals(this.localSafeType, softFeature.localSafeType) && JceUtil.equals(this.localVirusName, softFeature.localVirusName) && JceUtil.equals(this.localVirusID, softFeature.localVirusID) && JceUtil.equals(this.appid, softFeature.appid);
    }

    public final String fullClassName() {
        return "QQPIM.SoftFeature";
    }

    public final int getAppid() {
        return this.appid;
    }

    public final int getCategory() {
        return this.category;
    }

    public final int getEngineVersion() {
        return this.engineVersion;
    }

    public final FeatureKey getFeatureKey() {
        return this.featureKey;
    }

    public final boolean getIsBuildIn() {
        return this.isBuildIn;
    }

    public final int getLocalSafeType() {
        return this.localSafeType;
    }

    public final int getLocalVirusID() {
        return this.localVirusID;
    }

    public final String getLocalVirusName() {
        return this.localVirusName;
    }

    public final int getPosition() {
        return this.position;
    }

    public final int getRequestType() {
        return this.requestType;
    }

    public final int getSoftDescTimestamp() {
        return this.softDescTimestamp;
    }

    public final ArrayList<FeatureItem> getVecFeatureItem() {
        return this.vecFeatureItem;
    }

    public final int getVirusDescTimestamp() {
        return this.virusDescTimestamp;
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
        if (f552a == null) {
            f552a = new FeatureKey();
        }
        this.featureKey = (FeatureKey) jceInputStream.read((JceStruct) f552a, 0, true);
        this.softDescTimestamp = jceInputStream.read(this.softDescTimestamp, 1, true);
        this.virusDescTimestamp = jceInputStream.read(this.virusDescTimestamp, 2, true);
        if (f553b == null) {
            f553b = new ArrayList<>();
            f553b.add(new FeatureItem());
        }
        setVecFeatureItem((ArrayList) jceInputStream.read(f553b, 3, false));
        setRequestType(jceInputStream.read(this.requestType, 4, false));
        setIsBuildIn(jceInputStream.read(this.isBuildIn, 5, false));
        setCategory(jceInputStream.read(this.category, 6, false));
        setPosition(jceInputStream.read(this.position, 7, false));
        setEngineVersion(jceInputStream.read(this.engineVersion, 8, false));
        setLocalSafeType(jceInputStream.read(this.localSafeType, 9, false));
        setLocalVirusName(jceInputStream.readString(10, false));
        setLocalVirusID(jceInputStream.read(this.localVirusID, 11, false));
        setAppid(jceInputStream.read(this.appid, 12, false));
    }

    public final void setAppid(int i) {
        this.appid = i;
    }

    public final void setCategory(int i) {
        this.category = i;
    }

    public final void setEngineVersion(int i) {
        this.engineVersion = i;
    }

    public final void setFeatureKey(FeatureKey featureKey) {
        this.featureKey = featureKey;
    }

    public final void setIsBuildIn(boolean z) {
        this.isBuildIn = z;
    }

    public final void setLocalSafeType(int i) {
        this.localSafeType = i;
    }

    public final void setLocalVirusID(int i) {
        this.localVirusID = i;
    }

    public final void setLocalVirusName(String str) {
        this.localVirusName = str;
    }

    public final void setPosition(int i) {
        this.position = i;
    }

    public final void setRequestType(int i) {
        this.requestType = i;
    }

    public final void setSoftDescTimestamp(int i) {
        this.softDescTimestamp = i;
    }

    public final void setVecFeatureItem(ArrayList<FeatureItem> arrayList) {
        this.vecFeatureItem = arrayList;
    }

    public final void setVirusDescTimestamp(int i) {
        this.virusDescTimestamp = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write((JceStruct) this.featureKey, 0);
        jceOutputStream.write(this.softDescTimestamp, 1);
        jceOutputStream.write(this.virusDescTimestamp, 2);
        if (this.vecFeatureItem != null) {
            jceOutputStream.write((Collection) this.vecFeatureItem, 3);
        }
        jceOutputStream.write(this.requestType, 4);
        jceOutputStream.write(this.isBuildIn, 5);
        jceOutputStream.write(this.category, 6);
        jceOutputStream.write(this.position, 7);
        jceOutputStream.write(this.engineVersion, 8);
        jceOutputStream.write(this.localSafeType, 9);
        if (this.localVirusName != null) {
            jceOutputStream.write(this.localVirusName, 10);
        }
        jceOutputStream.write(this.localVirusID, 11);
        jceOutputStream.write(this.appid, 12);
    }
}
