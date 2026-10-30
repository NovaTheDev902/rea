package com.lenovo.safecenter.mmsutils;

/* JADX INFO: loaded from: classes.dex */
public class GenericPdu {

    /* JADX INFO: renamed from: a */
    TyuMMSHeaders f4297a;

    public GenericPdu() {
        this.f4297a = null;
        this.f4297a = new TyuMMSHeaders();
    }

    GenericPdu(TyuMMSHeaders headers) {
        this.f4297a = null;
        this.f4297a = headers;
    }

    public int getMessageType() {
        return this.f4297a.getOctet(140);
    }

    public void setMessageType(int value) throws InvalidHeaderValueException {
        this.f4297a.setOctet(value, 140);
    }

    public int getMmsVersion() {
        return this.f4297a.getOctet(141);
    }

    public void setMmsVersion(int value) throws InvalidHeaderValueException {
        this.f4297a.setOctet(value, 141);
    }

    public TyuEncodedStringValue getFrom() {
        return this.f4297a.getEncodedStringValue(137);
    }

    public void setFrom(TyuEncodedStringValue value) {
        this.f4297a.setEncodedStringValue(value, 137);
    }
}
