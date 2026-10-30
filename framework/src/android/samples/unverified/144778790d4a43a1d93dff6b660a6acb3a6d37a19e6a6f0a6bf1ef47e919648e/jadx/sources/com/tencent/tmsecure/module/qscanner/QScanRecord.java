package com.tencent.tmsecure.module.qscanner;

import com.lenovo.providers.querypermissions.QueryPermissions;
import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class QScanRecord extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static QScanResult f6220a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f6221b;

    /* JADX INFO: renamed from: id */
    public long f6222id;
    public QScanResult result;
    public int state;

    static {
        f6221b = !QScanRecord.class.desiredAssertionStatus();
    }

    public QScanRecord() {
        this.f6222id = 0L;
        this.result = null;
        this.state = 0;
        this.f6222id = this.f6222id;
        this.result = this.result;
        this.state = this.state;
    }

    public QScanRecord(long j, QScanResult qScanResult, int i) {
        this.f6222id = 0L;
        this.result = null;
        this.state = 0;
        this.f6222id = j;
        this.result = qScanResult;
        this.state = i;
    }

    public final String className() {
        return "QQPIM.QScanRecord";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f6221b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.f6222id, QueryPermissions.f1958ID);
        jceDisplayer.display((JceStruct) this.result, QueryPermissions.RECOMMENDEDACTION);
        jceDisplayer.display(this.state, "state");
    }

    public final boolean equals(Object obj) {
        QScanRecord qScanRecord;
        return obj != null && (obj instanceof QScanRecord) && (qScanRecord = (QScanRecord) obj) != null && JceUtil.equals(this.f6222id, qScanRecord.f6222id) && JceUtil.equals(this.result, qScanRecord.result) && JceUtil.equals(this.state, qScanRecord.state);
    }

    public final String fullClassName() {
        return "QQPIM.QScanRecord";
    }

    public final long getId() {
        return this.f6222id;
    }

    public final QScanResult getResult() {
        return this.result;
    }

    public final int getState() {
        return this.state;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void readFrom(JceInputStream jceInputStream) {
        this.f6222id = jceInputStream.read(this.f6222id, 0, true);
        if (f6220a == null) {
            f6220a = new QScanResult();
        }
        this.result = (QScanResult) jceInputStream.read((JceStruct) f6220a, 1, true);
        this.state = jceInputStream.read(this.state, 2, false);
    }

    public final void setId(long j) {
        this.f6222id = j;
    }

    public final void setResult(QScanResult qScanResult) {
        this.result = qScanResult;
    }

    public final void setState(int i) {
        this.state = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.f6222id, 0);
        jceOutputStream.write((JceStruct) this.result, 1);
        jceOutputStream.write(this.state, 2);
    }
}
