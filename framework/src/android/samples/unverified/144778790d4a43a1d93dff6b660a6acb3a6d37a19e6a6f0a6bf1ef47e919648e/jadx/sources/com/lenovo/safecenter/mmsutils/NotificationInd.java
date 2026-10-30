package com.lenovo.safecenter.mmsutils;

/* JADX INFO: loaded from: classes.dex */
public class NotificationInd extends GenericPdu {
    public NotificationInd() throws InvalidHeaderValueException {
        setMessageType(130);
    }

    NotificationInd(TyuMMSHeaders headers) {
        super(headers);
    }

    public int getContentClass() {
        return this.f4297a.getOctet(TyuMMSHeaders.CONTENT_CLASS);
    }

    public void setContentClass(int value) throws InvalidHeaderValueException {
        this.f4297a.setOctet(value, TyuMMSHeaders.CONTENT_CLASS);
    }

    public byte[] getContentLocation() {
        return this.f4297a.getTextString(131);
    }

    public void setContentLocation(byte[] value) {
        this.f4297a.setTextString(value, 131);
    }

    public long getExpiry() {
        return this.f4297a.getLongInteger(136);
    }

    public void setExpiry(long value) {
        this.f4297a.setLongInteger(value, 136);
    }

    @Override // com.lenovo.safecenter.mmsutils.GenericPdu
    public TyuEncodedStringValue getFrom() {
        return this.f4297a.getEncodedStringValue(137);
    }

    @Override // com.lenovo.safecenter.mmsutils.GenericPdu
    public void setFrom(TyuEncodedStringValue value) {
        this.f4297a.setEncodedStringValue(value, 137);
    }

    public byte[] getMessageClass() {
        return this.f4297a.getTextString(138);
    }

    public void setMessageClass(byte[] value) {
        this.f4297a.setTextString(value, 138);
    }

    public long getMessageSize() {
        return this.f4297a.getLongInteger(142);
    }

    public void setMessageSize(long value) {
        this.f4297a.setLongInteger(value, 142);
    }

    public TyuEncodedStringValue getSubject() {
        return this.f4297a.getEncodedStringValue(150);
    }

    public void setSubject(TyuEncodedStringValue value) {
        this.f4297a.setEncodedStringValue(value, 150);
    }

    public byte[] getTransactionId() {
        return this.f4297a.getTextString(152);
    }

    public void setTransactionId(byte[] value) {
        this.f4297a.setTextString(value, 152);
    }

    public int getDeliveryReport() {
        return this.f4297a.getOctet(134);
    }

    public void setDeliveryReport(int value) throws InvalidHeaderValueException {
        this.f4297a.setOctet(value, 134);
    }
}
