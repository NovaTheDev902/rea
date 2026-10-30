package com.lenovo.safecenter.mmsutils;

/* JADX INFO: loaded from: classes.dex */
public class DeliveryInd extends GenericPdu {
    public DeliveryInd() throws InvalidHeaderValueException {
        setMessageType(134);
    }

    DeliveryInd(TyuMMSHeaders headers) {
        super(headers);
    }

    public long getDate() {
        return this.f4297a.getLongInteger(133);
    }

    public void setDate(long value) {
        this.f4297a.setLongInteger(value, 133);
    }

    public byte[] getMessageId() {
        return this.f4297a.getTextString(139);
    }

    public void setMessageId(byte[] value) {
        this.f4297a.setTextString(value, 139);
    }

    public int getStatus() {
        return this.f4297a.getOctet(149);
    }

    public void setStatus(int value) throws InvalidHeaderValueException {
        this.f4297a.setOctet(value, 149);
    }

    public TyuEncodedStringValue[] getTo() {
        return this.f4297a.getEncodedStringValues(151);
    }

    public void setTo(TyuEncodedStringValue[] value) {
        this.f4297a.setEncodedStringValues(value, 151);
    }
}
