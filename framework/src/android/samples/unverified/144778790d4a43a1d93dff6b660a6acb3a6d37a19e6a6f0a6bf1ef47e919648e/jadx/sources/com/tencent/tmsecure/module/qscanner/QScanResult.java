package com.tencent.tmsecure.module.qscanner;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class QScanResult extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static ApkKey f6226a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f6227b;
    public int advice;
    public ApkKey apkkey;
    public String discription;
    public String label;
    public int malwareid;
    public String name;
    public int type;
    public String url;

    static {
        f6227b = !QScanResult.class.desiredAssertionStatus();
    }

    public QScanResult() {
        this.apkkey = null;
        this.type = 0;
        this.label = "";
        this.discription = "";
        this.advice = 0;
        this.malwareid = 0;
        this.name = "";
        this.url = "";
        this.apkkey = this.apkkey;
        this.type = this.type;
        this.label = this.label;
        this.discription = this.discription;
        this.advice = this.advice;
        this.malwareid = this.malwareid;
        this.name = this.name;
        this.url = this.url;
    }

    public QScanResult(ApkKey apkKey, int i, String str, String str2, int i2, int i3, String str3, String str4) {
        this.apkkey = null;
        this.type = 0;
        this.label = "";
        this.discription = "";
        this.advice = 0;
        this.malwareid = 0;
        this.name = "";
        this.url = "";
        this.apkkey = apkKey;
        this.type = i;
        this.label = str;
        this.discription = str2;
        this.advice = i2;
        this.malwareid = i3;
        this.name = str3;
        this.url = str4;
    }

    public final String className() {
        return "QQPIM.QScanResult";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f6227b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display((JceStruct) this.apkkey, "apkkey");
        jceDisplayer.display(this.type, "type");
        jceDisplayer.display(this.label, "label");
        jceDisplayer.display(this.discription, "discription");
        jceDisplayer.display(this.advice, "advice");
        jceDisplayer.display(this.malwareid, "malwareid");
        jceDisplayer.display(this.name, "name");
        jceDisplayer.display(this.url, "url");
    }

    public final boolean equals(Object obj) {
        QScanResult qScanResult;
        return obj != null && (obj instanceof QScanResult) && (qScanResult = (QScanResult) obj) != null && JceUtil.equals(this.apkkey, qScanResult.apkkey) && JceUtil.equals(this.type, qScanResult.type) && JceUtil.equals(this.label, qScanResult.label) && JceUtil.equals(this.discription, qScanResult.discription) && JceUtil.equals(this.advice, qScanResult.advice) && JceUtil.equals(this.malwareid, qScanResult.malwareid) && JceUtil.equals(this.name, qScanResult.name) && JceUtil.equals(this.url, qScanResult.url);
    }

    public final String fullClassName() {
        return "QQPIM.QScanResult";
    }

    public final int getAdvice() {
        return this.advice;
    }

    public final ApkKey getApkkey() {
        return this.apkkey;
    }

    public final String getDiscription() {
        return this.discription;
    }

    public final String getLabel() {
        return this.label;
    }

    public final int getMalwareid() {
        return this.malwareid;
    }

    public final String getName() {
        return this.name;
    }

    public final int getType() {
        return this.type;
    }

    public final String getUrl() {
        return this.url;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void readFrom(JceInputStream jceInputStream) {
        if (f6226a == null) {
            f6226a = new ApkKey();
        }
        this.apkkey = (ApkKey) jceInputStream.read((JceStruct) f6226a, 0, true);
        this.type = jceInputStream.read(this.type, 1, true);
        this.label = jceInputStream.readString(2, false);
        this.discription = jceInputStream.readString(3, false);
        this.advice = jceInputStream.read(this.advice, 4, false);
        this.malwareid = jceInputStream.read(this.malwareid, 5, false);
        this.name = jceInputStream.readString(6, false);
        this.url = jceInputStream.readString(7, false);
    }

    public final void setAdvice(int i) {
        this.advice = i;
    }

    public final void setApkkey(ApkKey apkKey) {
        this.apkkey = apkKey;
    }

    public final void setDiscription(String str) {
        this.discription = str;
    }

    public final void setLabel(String str) {
        this.label = str;
    }

    public final void setMalwareid(int i) {
        this.malwareid = i;
    }

    public final void setName(String str) {
        this.name = str;
    }

    public final void setType(int i) {
        this.type = i;
    }

    public final void setUrl(String str) {
        this.url = str;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write((JceStruct) this.apkkey, 0);
        jceOutputStream.write(this.type, 1);
        if (this.label != null) {
            jceOutputStream.write(this.label, 2);
        }
        if (this.discription != null) {
            jceOutputStream.write(this.discription, 3);
        }
        jceOutputStream.write(this.advice, 4);
        jceOutputStream.write(this.malwareid, 5);
        if (this.name != null) {
            jceOutputStream.write(this.name, 6);
        }
        if (this.url != null) {
            jceOutputStream.write(this.url, 7);
        }
    }
}
