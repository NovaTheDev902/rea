package com.lenovo.safecenter.mmsutils;

import java.util.HashMap;
import java.util.Map;
import java.util.Vector;

/* JADX INFO: loaded from: classes.dex */
public class TyuPduBody {

    /* JADX INFO: renamed from: a */
    private Vector<PduPart> f4335a;

    /* JADX INFO: renamed from: b */
    private Map<String, PduPart> f4336b;

    /* JADX INFO: renamed from: c */
    private Map<String, PduPart> f4337c;

    /* JADX INFO: renamed from: d */
    private Map<String, PduPart> f4338d;

    /* JADX INFO: renamed from: e */
    private Map<String, PduPart> f4339e;

    public TyuPduBody() {
        this.f4335a = null;
        this.f4336b = null;
        this.f4337c = null;
        this.f4338d = null;
        this.f4339e = null;
        this.f4335a = new Vector<>();
        this.f4336b = new HashMap();
        this.f4337c = new HashMap();
        this.f4338d = new HashMap();
        this.f4339e = new HashMap();
    }

    /* JADX INFO: renamed from: a */
    private void m1771a(PduPart part) {
        byte[] contentId = part.getContentId();
        if (contentId != null) {
            this.f4336b.put(new String(contentId), part);
        }
        byte[] contentLocation = part.getContentLocation();
        if (contentLocation != null) {
            String clc = new String(contentLocation);
            this.f4337c.put(clc, part);
        }
        byte[] name = part.getName();
        if (name != null) {
            String clc2 = new String(name);
            this.f4338d.put(clc2, part);
        }
        byte[] fileName = part.getFilename();
        if (fileName != null) {
            String clc3 = new String(fileName);
            this.f4339e.put(clc3, part);
        }
    }

    public boolean addPart(PduPart part) {
        if (part == null) {
            throw new NullPointerException();
        }
        m1771a(part);
        return this.f4335a.add(part);
    }

    public void addPart(int index, PduPart part) {
        if (part == null) {
            throw new NullPointerException();
        }
        m1771a(part);
        this.f4335a.add(index, part);
    }

    public PduPart removePart(int index) {
        return this.f4335a.remove(index);
    }

    public void removeAll() {
        this.f4335a.clear();
    }

    public PduPart getPart(int index) {
        return this.f4335a.get(index);
    }

    public int getPartIndex(PduPart part) {
        return this.f4335a.indexOf(part);
    }

    public int getPartsNum() {
        return this.f4335a.size();
    }

    public PduPart getPartByContentId(String cid) {
        return this.f4336b.get(cid);
    }

    public PduPart getPartByContentLocation(String contentLocation) {
        return this.f4337c.get(contentLocation);
    }

    public PduPart getPartByName(String name) {
        return this.f4338d.get(name);
    }

    public PduPart getPartByFileName(String filename) {
        return this.f4339e.get(filename);
    }
}
