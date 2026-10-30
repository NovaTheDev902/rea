package com.lenovo.safecenter.mmsutils;

/* JADX INFO: loaded from: classes.dex */
public class MultimediaMessagePdu extends GenericPdu {

    /* JADX INFO: renamed from: b */
    private TyuPduBody f4312b;

    public MultimediaMessagePdu() {
    }

    public MultimediaMessagePdu(TyuMMSHeaders header, TyuPduBody body) {
        super(header);
        this.f4312b = body;
    }

    public TyuPduBody getBody() {
        return this.f4312b;
    }

    public void setBody(TyuPduBody body) {
        this.f4312b = body;
    }

    public TyuEncodedStringValue getSubject() {
        return this.f4297a.getEncodedStringValue(150);
    }

    public void setSubject(TyuEncodedStringValue value) {
        this.f4297a.setEncodedStringValue(value, 150);
    }

    public TyuEncodedStringValue[] getTo() {
        return this.f4297a.getEncodedStringValues(151);
    }

    public void addTo(TyuEncodedStringValue value) {
        this.f4297a.appendEncodedStringValue(value, 151);
    }

    public int getPriority() {
        return this.f4297a.getOctet(143);
    }

    public void setPriority(int value) throws InvalidHeaderValueException {
        this.f4297a.setOctet(value, 143);
    }

    public long getDate() {
        return this.f4297a.getLongInteger(133);
    }

    public void setDate(long value) {
        this.f4297a.setLongInteger(value, 133);
    }
}
