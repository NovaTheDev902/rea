package com.lenovo.safecenter.mmsutils;

/* JADX INFO: loaded from: classes.dex */
public class AcknowledgeInd extends GenericPdu {
    public static final String ERR_TAG = "AcknowledgeInd.java";

    public AcknowledgeInd(int mmsVersion, byte[] transactionId) throws InvalidHeaderValueException {
        setMessageType(133);
        setMmsVersion(mmsVersion);
        setTransactionId(transactionId);
    }

    AcknowledgeInd(TyuMMSHeaders headers) {
        super(headers);
    }

    public int getReportAllowed() {
        return this.f4297a.getOctet(145);
    }

    public void setReportAllowed(int value) throws InvalidHeaderValueException {
        this.f4297a.setOctet(value, 145);
    }

    public byte[] getTransactionId() {
        return this.f4297a.getTextString(152);
    }

    public final void setTransactionId(byte[] value) {
        this.f4297a.setTextString(value, 152);
    }
}
