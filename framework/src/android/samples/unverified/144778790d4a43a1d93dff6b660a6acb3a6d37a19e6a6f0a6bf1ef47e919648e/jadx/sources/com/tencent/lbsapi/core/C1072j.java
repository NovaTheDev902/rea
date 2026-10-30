package com.tencent.lbsapi.core;

import LBSAPIProtocol.Cell;
import LBSAPIProtocol.DeviceData;
import LBSAPIProtocol.GPS;
import LBSAPIProtocol.Measure;
import LBSAPIProtocol.ReqGetPoiList;
import LBSAPIProtocol.ReqGetPosition;
import LBSAPIProtocol.ReqHeader;
import LBSAPIProtocol.ReqSearchNearPoiList;
import LBSAPIProtocol.RspGetPoiList;
import LBSAPIProtocol.RspGetPosition;
import LBSAPIProtocol.RspHeader;
import LBSAPIProtocol.RspSearchNearPoiList;
import android.content.Context;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import com.p012qq.jce.wup.UniPacket;
import com.tencent.lbsapi.QLBSNotification;
import com.tencent.lbsapi.model.QLBSCellInfo;
import com.tencent.lbsapi.model.QLBSGPSInfo;
import com.tencent.lbsapi.p013a.C1062f;
import java.util.ArrayList;
import java.util.Iterator;

/* JADX INFO: renamed from: com.tencent.lbsapi.core.j */
/* JADX INFO: loaded from: classes.dex */
public class C1072j {

    /* JADX INFO: renamed from: a */
    private QLBSEngine f5973a;

    /* JADX INFO: renamed from: b */
    private C1062f f5974b;

    /* JADX INFO: renamed from: c */
    private QLBSNotification f5975c;

    /* JADX INFO: renamed from: d */
    private String f5976d;

    /* JADX INFO: renamed from: e */
    private String f5977e;

    /* JADX INFO: renamed from: f */
    private String f5978f;

    /* JADX INFO: renamed from: g */
    private Context f5979g;

    /* JADX INFO: renamed from: h */
    private Handler f5980h;

    public C1072j(Context context, QLBSNotification qLBSNotification, String str, String str2, String str3) {
        this.f5973a = null;
        this.f5974b = null;
        this.f5975c = null;
        this.f5976d = null;
        this.f5977e = null;
        this.f5978f = null;
        this.f5979g = null;
        this.f5980h = null;
        this.f5973a = new QLBSEngine(context, qLBSNotification);
        this.f5974b = new C1062f(new C1063a(this));
        this.f5979g = context;
        this.f5975c = qLBSNotification;
        this.f5976d = str == null ? "" : str;
        this.f5977e = str2 == null ? "" : str2;
        this.f5978f = str3 == null ? "" : str3;
        this.f5980h = new HandlerC1064b(this, qLBSNotification);
    }

    /* JADX INFO: renamed from: a */
    private void m2559a(int i, int i2, String str) {
        Message message = new Message();
        Bundle bundle = new Bundle();
        message.what = 0;
        message.setData(bundle);
        bundle.putInt(C1067e.f5960a, i);
        bundle.putInt(C1067e.f5962c, i2);
        bundle.putString(C1067e.f5963d, str);
        if (this.f5980h != null) {
            this.f5980h.sendMessage(message);
        }
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m2560a(C1072j c1072j, int i, int i2, String str) {
        if (c1072j.f5975c != null) {
            c1072j.m2559a(i, i2, str);
        }
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m2561a(C1072j c1072j, int i, byte[] bArr) {
        try {
            if (c1072j.f5975c != null) {
                UniPacket uniPacket = new UniPacket();
                uniPacket.setEncodeName("utf-8");
                try {
                    byte[] bArrM2557b = C1066d.m2557b(bArr, c1072j.f5976d, c1072j.f5977e);
                    if (bArrM2557b == null) {
                        c1072j.m2559a(i, -2, "wup回包解析异常");
                    } else {
                        uniPacket.decode(bArrM2557b);
                        RspHeader rspHeader = (RspHeader) uniPacket.get("RspHeader");
                        if (rspHeader == null) {
                            c1072j.m2559a(i, -2, "wup回包解析异常");
                        } else if (rspHeader.getEResult() != 0) {
                            switch (rspHeader.getEResult()) {
                                case 102:
                                    c1072j.m2559a(i, -4, "LBS后台系统无法根据输入定位");
                                    break;
                                case 201:
                                    c1072j.m2559a(i, -5, "LBS后台鉴权失败");
                                    break;
                                case 202:
                                    c1072j.m2559a(i, -6, "输入条件不足");
                                    break;
                                default:
                                    c1072j.m2559a(i, -3, "LBS后台系统异常");
                                    break;
                            }
                        } else if (uniPacket.getFuncName().equals("ReqGetPosition")) {
                            RspGetPosition rspGetPosition = (RspGetPosition) uniPacket.get("RspGetPosition");
                            Message message = new Message();
                            Bundle bundle = new Bundle();
                            message.setData(bundle);
                            bundle.putInt(C1067e.f5960a, i);
                            if (rspGetPosition != null) {
                                message.what = 1;
                                bundle.putByteArray("RspGetPosition", rspGetPosition.toByteArray());
                            } else {
                                message.what = 0;
                                bundle.putString(C1067e.f5963d, "wup回包解析异常");
                                bundle.putInt(C1067e.f5962c, -2);
                            }
                            c1072j.f5980h.sendMessage(message);
                        } else if (uniPacket.getFuncName().equals("ReqGetPoiList")) {
                            RspGetPoiList rspGetPoiList = (RspGetPoiList) uniPacket.get("RspGetPoiList");
                            Message message2 = new Message();
                            Bundle bundle2 = new Bundle();
                            message2.setData(bundle2);
                            bundle2.putInt(C1067e.f5960a, i);
                            if (rspGetPoiList != null) {
                                message2.what = 2;
                                bundle2.putByteArray("RspGetPoiList", rspGetPoiList.toByteArray());
                            } else {
                                message2.what = 0;
                                bundle2.putString(C1067e.f5963d, "wup回包解析异常");
                                bundle2.putInt(C1067e.f5962c, -2);
                            }
                            c1072j.f5980h.sendMessage(message2);
                        } else if (uniPacket.getFuncName().equals("ReqSearchNearPoiList")) {
                            RspSearchNearPoiList rspSearchNearPoiList = (RspSearchNearPoiList) uniPacket.get("RspSearchNearPoiList");
                            Message message3 = new Message();
                            Bundle bundle3 = new Bundle();
                            message3.setData(bundle3);
                            bundle3.putInt(C1067e.f5960a, i);
                            if (rspSearchNearPoiList != null) {
                                message3.what = 3;
                                bundle3.putByteArray("RspSearchNearPoiList", rspSearchNearPoiList.toByteArray());
                            } else {
                                message3.what = 0;
                                bundle3.putString(C1067e.f5963d, "wup回包解析异常");
                                bundle3.putInt(C1067e.f5962c, -2);
                            }
                            c1072j.f5980h.sendMessage(message3);
                        } else {
                            c1072j.m2559a(i, -2, "wup回包解析异常");
                        }
                    }
                } catch (Exception e) {
                    c1072j.m2559a(i, -2, "wup回包解析异常");
                }
            }
        } catch (Exception e2) {
            e2.printStackTrace();
            c1072j.m2559a(i, -7, e2.getMessage());
        }
    }

    /* JADX INFO: renamed from: a */
    public void m2562a() {
        this.f5979g = null;
        if (this.f5973a != null) {
            this.f5973a.m2518a();
            this.f5973a.m2526f();
            this.f5973a = null;
        }
        if (this.f5974b != null) {
            this.f5974b.m2499b();
            this.f5974b = null;
        }
        if (this.f5980h != null) {
            this.f5980h = null;
        }
    }

    /* JADX INFO: renamed from: a */
    public void m2563a(int i) {
        this.f5973a.m2520a(i);
    }

    /* JADX INFO: renamed from: a */
    public void m2564a(boolean z) {
        this.f5973a.m2519a(z);
    }

    /* JADX INFO: renamed from: a */
    public boolean m2565a(int i, String str, int i2) throws Throwable {
        if (this.f5973a.m2530j() == 0 && this.f5973a.m2533m().size() == 0) {
            return false;
        }
        ReqHeader reqHeader = new ReqHeader();
        reqHeader.setStrUin(str);
        reqHeader.setEUinType(i2);
        reqHeader.setStrAuthName(this.f5976d);
        reqHeader.setStrAuthPassword(this.f5977e);
        reqHeader.setEDeviceType(1);
        ReqGetPosition reqGetPosition = new ReqGetPosition();
        reqGetPosition.setVCells(new ArrayList());
        reqGetPosition.getVCells().add(new Cell((short) this.f5973a.m2527g(), (short) this.f5973a.m2528h(), this.f5973a.m2529i(), this.f5973a.m2530j()));
        Iterator it = this.f5973a.m2535o().iterator();
        while (it.hasNext()) {
            reqGetPosition.getVCells().add(new Cell((short) this.f5973a.m2527g(), (short) this.f5973a.m2528h(), this.f5973a.m2529i(), ((Integer) it.next()).intValue()));
        }
        reqGetPosition.setStGps(new GPS(this.f5973a.m2531k(), this.f5973a.m2532l(), -1, 0));
        reqGetPosition.setVMacs(this.f5973a.m2533m());
        ArrayList arrayListM2539s = this.f5973a.m2539s();
        if (arrayListM2539s == null) {
            arrayListM2539s = new ArrayList();
        }
        reqGetPosition.setVMeasures(arrayListM2539s);
        reqGetPosition.setStrImei(this.f5973a.m2536p());
        reqGetPosition.setStrAppUA(this.f5978f);
        UniPacket uniPacket = new UniPacket();
        uniPacket.setEncodeName("utf-8");
        uniPacket.setRequestId(i);
        uniPacket.setServantName(C1067e.f5965f);
        uniPacket.setFuncName("ReqGetPosition");
        uniPacket.put(C1067e.f5961b, reqHeader);
        uniPacket.put("ReqGetPosition", reqGetPosition);
        byte[] bArrM2555a = C1066d.m2555a(uniPacket.encode(), this.f5976d, this.f5977e);
        if (bArrM2555a != null) {
            return this.f5974b.m2498a(this.f5979g, i, this.f5976d, bArrM2555a);
        }
        return false;
    }

    /* JADX INFO: renamed from: a */
    public boolean m2566a(int i, String str, int i2, int i3, int i4, int i5, String str2, ArrayList arrayList) throws Throwable {
        if (this.f5973a.m2530j() == 0 && this.f5973a.m2533m().size() == 0) {
            return false;
        }
        ReqHeader reqHeader = new ReqHeader();
        reqHeader.setStrUin(str);
        reqHeader.setEUinType(i2);
        reqHeader.setStrAuthName(this.f5976d);
        reqHeader.setStrAuthPassword(this.f5977e);
        ReqSearchNearPoiList reqSearchNearPoiList = new ReqSearchNearPoiList();
        reqSearchNearPoiList.setVCells(new ArrayList());
        reqSearchNearPoiList.getVCells().add(new Cell((short) this.f5973a.m2527g(), (short) this.f5973a.m2528h(), this.f5973a.m2529i(), this.f5973a.m2530j()));
        Iterator it = this.f5973a.m2535o().iterator();
        while (it.hasNext()) {
            reqSearchNearPoiList.getVCells().add(new Cell((short) this.f5973a.m2527g(), (short) this.f5973a.m2528h(), this.f5973a.m2529i(), ((Integer) it.next()).intValue()));
        }
        reqSearchNearPoiList.setStGps(new GPS(this.f5973a.m2531k(), this.f5973a.m2532l(), -1, 0));
        reqSearchNearPoiList.setVMacs(this.f5973a.m2533m());
        reqSearchNearPoiList.setVTypes(new ArrayList());
        if (arrayList != null && arrayList.size() > 0) {
            reqSearchNearPoiList.getVTypes().addAll(arrayList);
        }
        reqSearchNearPoiList.setIRadius(i3);
        reqSearchNearPoiList.setIBeginPos(i4);
        reqSearchNearPoiList.setIReqNum(i5);
        reqSearchNearPoiList.setStrKeyword(str2);
        reqSearchNearPoiList.setStrImei(this.f5973a.m2536p());
        reqSearchNearPoiList.setStrAppUA(this.f5978f);
        UniPacket uniPacket = new UniPacket();
        uniPacket.setEncodeName("utf-8");
        uniPacket.setRequestId(i);
        uniPacket.setServantName(C1067e.f5965f);
        uniPacket.setFuncName("ReqSearchNearPoiList");
        uniPacket.put(C1067e.f5961b, reqHeader);
        uniPacket.put("ReqSearchNearPoiList", reqSearchNearPoiList);
        ArrayList arrayListM2539s = this.f5973a.m2539s();
        if (arrayListM2539s == null) {
            arrayListM2539s = new ArrayList();
        }
        reqSearchNearPoiList.setVMeasures(arrayListM2539s);
        byte[] bArrM2555a = C1066d.m2555a(uniPacket.encode(), this.f5976d, this.f5977e);
        if (bArrM2555a != null) {
            return this.f5974b.m2498a(this.f5979g, i, this.f5976d, bArrM2555a);
        }
        return false;
    }

    /* JADX INFO: renamed from: a */
    public boolean m2567a(int i, String str, int i2, int i3, int i4, int i5, ArrayList arrayList, int i6) throws Throwable {
        if (this.f5973a.m2530j() == 0 && this.f5973a.m2533m().size() == 0) {
            return false;
        }
        ReqHeader reqHeader = new ReqHeader();
        reqHeader.setStrUin(str);
        reqHeader.setEUinType(i2);
        reqHeader.setStrAuthName(this.f5976d);
        reqHeader.setStrAuthPassword(this.f5977e);
        ReqGetPoiList reqGetPoiList = new ReqGetPoiList();
        reqGetPoiList.setVCells(new ArrayList());
        reqGetPoiList.getVCells().add(new Cell((short) this.f5973a.m2527g(), (short) this.f5973a.m2528h(), this.f5973a.m2529i(), this.f5973a.m2530j()));
        Iterator it = this.f5973a.m2535o().iterator();
        while (it.hasNext()) {
            reqGetPoiList.getVCells().add(new Cell((short) this.f5973a.m2527g(), (short) this.f5973a.m2528h(), this.f5973a.m2529i(), ((Integer) it.next()).intValue()));
        }
        reqGetPoiList.setStGps(new GPS(this.f5973a.m2531k(), this.f5973a.m2532l(), -1, 0));
        reqGetPoiList.setVMacs(this.f5973a.m2533m());
        reqGetPoiList.setVTypes(new ArrayList());
        if (arrayList != null && arrayList.size() > 0) {
            reqGetPoiList.getVTypes().addAll(arrayList);
        }
        reqGetPoiList.setIRadius(i3);
        reqGetPoiList.setIBeginPos(i4);
        reqGetPoiList.setIReqNum(i5);
        reqGetPoiList.setESortMethod(i6);
        ArrayList arrayListM2539s = this.f5973a.m2539s();
        if (arrayListM2539s == null) {
            arrayListM2539s = new ArrayList();
        }
        reqGetPoiList.setVMeasures(arrayListM2539s);
        reqGetPoiList.setStrImei(this.f5973a.m2536p());
        reqGetPoiList.setStrAppUA(this.f5978f);
        UniPacket uniPacket = new UniPacket();
        uniPacket.setEncodeName("utf-8");
        uniPacket.setRequestId(i);
        uniPacket.setServantName(C1067e.f5965f);
        uniPacket.setFuncName("ReqGetPoiList");
        uniPacket.put(C1067e.f5961b, reqHeader);
        uniPacket.put("ReqGetPoiList", reqGetPoiList);
        byte[] bArrM2555a = C1066d.m2555a(uniPacket.encode(), this.f5976d, this.f5977e);
        if (bArrM2555a != null) {
            return this.f5974b.m2498a(this.f5979g, i, this.f5976d, bArrM2555a);
        }
        return false;
    }

    /* JADX INFO: renamed from: b */
    public void m2568b() {
        this.f5973a.m2518a();
    }

    /* JADX INFO: renamed from: b */
    public void m2569b(boolean z) {
        this.f5973a.m2521b(z);
    }

    /* JADX INFO: renamed from: c */
    public byte[] m2570c() throws Throwable {
        try {
            DeviceData deviceData = new DeviceData();
            deviceData.setStCurMeasure(new Measure());
            deviceData.getStCurMeasure().setVCells(new ArrayList());
            deviceData.getStCurMeasure().getVCells().add(new Cell((short) this.f5973a.m2527g(), (short) this.f5973a.m2528h(), this.f5973a.m2529i(), this.f5973a.m2530j()));
            Iterator it = this.f5973a.m2535o().iterator();
            while (it.hasNext()) {
                deviceData.getStCurMeasure().getVCells().add(new Cell((short) this.f5973a.m2527g(), (short) this.f5973a.m2528h(), this.f5973a.m2529i(), ((Integer) it.next()).intValue()));
            }
            deviceData.getStCurMeasure().setStGps(new GPS(this.f5973a.m2531k(), this.f5973a.m2532l(), -1, 0));
            deviceData.getStCurMeasure().setVMacs(this.f5973a.m2533m());
            deviceData.getStCurMeasure().setStrExtraInfo(this.f5973a.m2537q());
            ArrayList arrayListM2539s = this.f5973a.m2539s();
            if (arrayListM2539s == null) {
                arrayListM2539s = new ArrayList();
            }
            deviceData.setVMeasures(arrayListM2539s);
            deviceData.setStrImei(this.f5973a.m2536p());
            deviceData.setStrAppUA(this.f5978f);
            deviceData.setEDeviceType(1);
            UniPacket uniPacket = new UniPacket();
            uniPacket.setRequestId(0);
            uniPacket.setEncodeName("utf-8");
            uniPacket.setServantName(C1067e.f5965f);
            uniPacket.setFuncName("ReqGetPositionApi");
            uniPacket.put(C1067e.f5966g, this.f5976d);
            UniPacket uniPacket2 = new UniPacket();
            uniPacket2.setEncodeName("utf-8");
            uniPacket2.setServantName(C1067e.f5965f);
            uniPacket2.setFuncName(C1067e.f5967h);
            uniPacket2.put(C1067e.f5967h, deviceData);
            byte[] bArrM2555a = C1066d.m2555a(uniPacket2.encode(), this.f5976d, this.f5977e);
            if (bArrM2555a == null) {
                return null;
            }
            uniPacket.put(C1067e.f5968i, bArrM2555a);
            return uniPacket.encode();
        } catch (Exception e) {
            return null;
        }
    }

    /* JADX INFO: renamed from: d */
    public boolean m2571d() {
        if (this.f5973a != null) {
            return this.f5973a.m2522b();
        }
        return false;
    }

    /* JADX INFO: renamed from: e */
    public int m2572e() {
        if (this.f5973a != null) {
            return this.f5973a.m2523c();
        }
        return -1;
    }

    /* JADX INFO: renamed from: f */
    public QLBSCellInfo m2573f() {
        if (this.f5973a != null) {
            return new QLBSCellInfo(this.f5973a.m2528h(), this.f5973a.m2527g(), this.f5973a.m2529i(), this.f5973a.m2530j());
        }
        return null;
    }

    /* JADX INFO: renamed from: g */
    public QLBSCellInfo m2574g() {
        if (this.f5973a != null) {
            return this.f5973a.m2524d();
        }
        return null;
    }

    /* JADX INFO: renamed from: h */
    public ArrayList m2575h() {
        if (this.f5973a != null) {
            return this.f5973a.m2534n();
        }
        return null;
    }

    /* JADX INFO: renamed from: i */
    public QLBSGPSInfo m2576i() {
        if (this.f5973a != null) {
            return new QLBSGPSInfo(this.f5973a.m2531k(), this.f5973a.m2532l(), -1, 0);
        }
        return null;
    }
}
