package com.lenovo.safecenter.mmsutils;

/* JADX INFO: loaded from: classes.dex */
public class SendConf extends GenericPdu {
    public SendConf() throws InvalidHeaderValueException {
        setMessageType(129);
    }

    SendConf(TyuMMSHeaders headers) {
        super(headers);
    }

    public byte[] getMessageId() {
        return this.f4297a.getTextString(139);
    }

    public void setMessageId(byte[] value) {
        this.f4297a.setTextString(value, 139);
    }

    public int getResponseStatus() {
        return this.f4297a.getOctet(146);
    }

    public void setResponseStatus(int value) throws InvalidHeaderValueException {
        this.f4297a.setOctet(value, 146);
    }

    public byte[] getTransactionId() {
        return this.f4297a.getTextString(152);
    }

    public void setTransactionId(byte[] value) {
        this.f4297a.setTextString(value, 152);
    }
}
