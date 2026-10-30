package com.lenovo.safecenter.mmsutils;

/* JADX INFO: loaded from: classes.dex */
public class ReadOrigInd extends GenericPdu {
    public ReadOrigInd() throws InvalidHeaderValueException {
        setMessageType(136);
    }

    ReadOrigInd(TyuMMSHeaders headers) {
        super(headers);
    }

    public long getDate() {
        return this.f4297a.getLongInteger(133);
    }

    public void setDate(long value) {
        this.f4297a.setLongInteger(value, 133);
    }

    @Override // com.lenovo.safecenter.mmsutils.GenericPdu
    public TyuEncodedStringValue getFrom() {
        return this.f4297a.getEncodedStringValue(137);
    }

    @Override // com.lenovo.safecenter.mmsutils.GenericPdu
    public void setFrom(TyuEncodedStringValue value) {
        this.f4297a.setEncodedStringValue(value, 137);
    }

    public byte[] getMessageId() {
        return this.f4297a.getTextString(139);
    }

    public void setMessageId(byte[] value) {
        this.f4297a.setTextString(value, 139);
    }

    public int getReadStatus() {
        return this.f4297a.getOctet(155);
    }

    public void setReadStatus(int value) throws InvalidHeaderValueException {
        this.f4297a.setOctet(value, 155);
    }

    public TyuEncodedStringValue[] getTo() {
        return this.f4297a.getEncodedStringValues(151);
    }

    public void setTo(TyuEncodedStringValue[] value) {
        this.f4297a.setEncodedStringValues(value, 151);
    }
}
