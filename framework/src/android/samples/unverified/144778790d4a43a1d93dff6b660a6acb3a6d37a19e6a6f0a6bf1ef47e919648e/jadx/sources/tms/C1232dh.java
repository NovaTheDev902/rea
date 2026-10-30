package tms;

import QQPIM.ADInfo;
import QQPIM.AnalyseInfo;
import QQPIM.AndroidCategoryExpand;
import QQPIM.AndroidSimpleInfoExpand;
import QQPIM.Category;
import QQPIM.CommentInfo;
import QQPIM.HotWordReqInfo;
import QQPIM.HotWordResInfo;
import QQPIM.MySoftSimpleInfo;
import QQPIM.SoftFeature;
import QQPIM.SoftInfo;
import QQPIM.SoftKey;
import QQPIM.SoftServerInfo;
import QQPIM.SoftSimpleInfo;
import android.content.Context;
import com.lenovo.lps.sus.p003a.p004a.p005a.InterfaceC0079b;
import com.p012qq.jce.wup.UniAttribute;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.common.ErrorCode;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.market.CategoryEx;
import com.tencent.tmsecure.module.market.IFetchHotWordListener;
import com.tencent.tmsecure.module.market.IFetchSpecialCategoryListener;
import com.tencent.tmsecure.module.market.IMarketManagerListener;
import com.tencent.tmsecure.module.market.MarketManager;
import com.tencent.tmsecure.module.market.RequestInfo;
import com.tencent.tmsecure.module.market.ResponseInfo;
import com.tencent.tmsecure.module.market.SoftSimpleInfoEx;
import com.tencent.tmsecure.module.market.SpecialCategory;
import com.tencent.tmsecure.module.wupsession.WupSessionManager;
import com.tencent.tmsecure.utils.Log;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicReference;

/* JADX INFO: renamed from: tms.dh */
/* JADX INFO: loaded from: classes.dex */
public final class C1232dh extends BaseManager {

    /* JADX INFO: renamed from: a */
    private WupSessionManager f7109a;

    /* JADX INFO: renamed from: a */
    private static void m3118a(List<SoftSimpleInfo> list) {
        for (SoftSimpleInfo softSimpleInfo : list) {
            String nick_name = softSimpleInfo.getNick_name();
            if (nick_name != null && !nick_name.equals("")) {
                softSimpleInfo.getSoftkey().setName(nick_name);
            }
        }
    }

    /* JADX INFO: renamed from: b */
    private static void m3119b(List<AnalyseInfo> list) {
        String nick_name;
        for (AnalyseInfo analyseInfo : list) {
            SoftInfo softInfo = analyseInfo.getSoftInfo();
            if (softInfo != null && (nick_name = softInfo.getNick_name()) != null && !nick_name.equals("")) {
                analyseInfo.getFeatureKey().setSoftName(nick_name);
            }
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m3120a(HotWordReqInfo hotWordReqInfo, IFetchHotWordListener iFetchHotWordListener) {
        ResponseInfo responseInfo = new ResponseInfo();
        HotWordResInfo hotWordResInfo = new HotWordResInfo();
        AtomicReference<HotWordResInfo> atomicReference = new AtomicReference<>();
        int hotWord = this.f7109a.getHotWord(hotWordReqInfo, atomicReference);
        if (hotWord == 0) {
            responseInfo.type = 0;
            responseInfo.code = hotWord;
            hotWordResInfo = atomicReference.get();
        } else if (ErrorCode.judgeErrorCode(hotWord) == 0) {
            responseInfo.type = 2;
            responseInfo.code = hotWord;
            Log.m2634e("MarketManager", "network error");
        } else {
            responseInfo.type = 1;
            responseInfo.code = hotWord;
            Log.m2634e("MarketManager", "runtime error");
        }
        if (iFetchHotWordListener != null) {
            iFetchHotWordListener.onReceive(responseInfo, hotWordResInfo);
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m3121a(SoftKey softKey, int i, IMarketManagerListener<ResponseInfo, Void> iMarketManagerListener) {
        ResponseInfo responseInfo = new ResponseInfo();
        CommentInfo commentInfo = new CommentInfo();
        commentInfo.setSoftkey(softKey);
        commentInfo.setScore(i);
        ArrayList<CommentInfo> arrayList = new ArrayList<>();
        arrayList.add(commentInfo);
        int iReportUserComment = this.f7109a.reportUserComment(arrayList);
        if (iReportUserComment == 0) {
            responseInfo.type = 0;
            responseInfo.code = iReportUserComment;
        } else if (ErrorCode.judgeErrorCode(iReportUserComment) == 0) {
            responseInfo.type = 2;
            responseInfo.code = iReportUserComment;
            Log.m2634e("MarketManager", "network error");
        } else {
            responseInfo.type = 1;
            responseInfo.code = iReportUserComment;
            Log.m2634e("MarketManager", "runtime error");
        }
        if (iMarketManagerListener != null) {
            iMarketManagerListener.onReceive(responseInfo, null);
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m3122a(IMarketManagerListener<ResponseInfo, ADInfo> iMarketManagerListener) {
        ResponseInfo responseInfo = new ResponseInfo();
        ArrayList<ADInfo> arrayList = new ArrayList<>();
        int aDs = this.f7109a.getADs(arrayList);
        if (aDs == 0) {
            responseInfo.type = 0;
            responseInfo.code = aDs;
        } else if (ErrorCode.judgeErrorCode(aDs) == 0) {
            responseInfo.type = 2;
            responseInfo.code = aDs;
            Log.m2634e("MarketManager", "network error");
        } else {
            responseInfo.type = 1;
            responseInfo.code = aDs;
            Log.m2634e("MarketManager", "runtime error");
        }
        if (iMarketManagerListener != null) {
            iMarketManagerListener.onReceive(responseInfo, arrayList);
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m3123a(RequestInfo requestInfo, IFetchSpecialCategoryListener iFetchSpecialCategoryListener) {
        ResponseInfo responseInfo = new ResponseInfo();
        String requestCommand = requestInfo != null ? requestInfo.getRequestCommand() : "";
        AtomicReference<SoftServerInfo> atomicReference = new AtomicReference<>();
        ArrayList<SoftSimpleInfo> arrayList = new ArrayList<>();
        int softList = this.f7109a.getSoftList(requestCommand, atomicReference, arrayList);
        m3118a(arrayList);
        SpecialCategory specialCategory = new SpecialCategory();
        if (softList == 0) {
            responseInfo.type = 0;
            responseInfo.code = softList;
            UniAttribute uniAttribute = new UniAttribute();
            uniAttribute.setEncodeName(InterfaceC0079b.f1213a);
            SoftServerInfo softServerInfo = atomicReference.get();
            if (softServerInfo != null && softServerInfo.getExpand() != null) {
                CategoryEx categoryEx = new CategoryEx();
                uniAttribute.clearCacheData();
                uniAttribute.decode(softServerInfo.getExpand());
                Category category = (Category) uniAttribute.getByClass(MarketManager.JCE_EXPAND_KEY, new Category());
                categoryEx.setCategory(category);
                if (category != null && category.getExpand() != null) {
                    uniAttribute.clearCacheData();
                    uniAttribute.decode(category.getExpand());
                    categoryEx.setExpand((AndroidCategoryExpand) uniAttribute.getByClass(MarketManager.JCE_EXPAND_KEY, new AndroidCategoryExpand()));
                }
                specialCategory.setCategoryEx(categoryEx);
            }
            ArrayList<SoftSimpleInfoEx> arrayList2 = new ArrayList<>();
            for (SoftSimpleInfo softSimpleInfo : arrayList) {
                SoftSimpleInfoEx softSimpleInfoEx = new SoftSimpleInfoEx();
                softSimpleInfoEx.setSoftSimpleInfo(softSimpleInfo);
                if (softSimpleInfo.getExpand() != null) {
                    uniAttribute.clearCacheData();
                    uniAttribute.decode(softSimpleInfo.getExpand());
                    softSimpleInfoEx.setExpand((AndroidSimpleInfoExpand) uniAttribute.getByClass(MarketManager.JCE_EXPAND_KEY, new AndroidSimpleInfoExpand()));
                }
                arrayList2.add(softSimpleInfoEx);
            }
            specialCategory.setSoftSimpleInfoExList(arrayList2);
        } else if (ErrorCode.judgeErrorCode(softList) == 0) {
            responseInfo.type = 2;
            responseInfo.code = softList;
            Log.m2634e("MarketManager", "network error");
        } else {
            responseInfo.type = 1;
            responseInfo.code = softList;
            Log.m2634e("MarketManager", "runtime error");
        }
        if (iFetchSpecialCategoryListener != null) {
            iFetchSpecialCategoryListener.onReceive(responseInfo, specialCategory);
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m3124a(RequestInfo requestInfo, IMarketManagerListener<ResponseInfo, CategoryEx> iMarketManagerListener) {
        ResponseInfo responseInfo = new ResponseInfo();
        String requestCommand = requestInfo != null ? requestInfo.getRequestCommand() : "";
        ArrayList<CategoryEx> arrayList = new ArrayList<>();
        AtomicReference<SoftServerInfo> atomicReference = new AtomicReference<>();
        ArrayList<Category> arrayList2 = new ArrayList<>();
        int categoryList = this.f7109a.getCategoryList(requestCommand, atomicReference, arrayList2);
        if (categoryList == 0) {
            responseInfo.type = 0;
            responseInfo.code = categoryList;
            UniAttribute uniAttribute = new UniAttribute();
            uniAttribute.setEncodeName(InterfaceC0079b.f1213a);
            for (Category category : arrayList2) {
                CategoryEx categoryEx = new CategoryEx();
                categoryEx.setCategory(category);
                if (category != null && category.getExpand() != null) {
                    uniAttribute.clearCacheData();
                    uniAttribute.decode(category.getExpand());
                    categoryEx.setExpand((AndroidCategoryExpand) uniAttribute.getByClass(MarketManager.JCE_EXPAND_KEY, new AndroidCategoryExpand()));
                }
                arrayList.add(categoryEx);
            }
        } else if (ErrorCode.judgeErrorCode(categoryList) == 0) {
            responseInfo.type = 2;
            responseInfo.code = categoryList;
            Log.m2634e("MarketManager", "network error");
        } else {
            responseInfo.type = 1;
            responseInfo.code = categoryList;
            Log.m2634e("MarketManager", "runtime error");
        }
        if (iMarketManagerListener != null) {
            iMarketManagerListener.onReceive(responseInfo, arrayList);
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m3125a(RequestInfo requestInfo, List<SoftFeature> list, IMarketManagerListener<ResponseInfo, AnalyseInfo> iMarketManagerListener) {
        ResponseInfo responseInfo = new ResponseInfo();
        ArrayList<AnalyseInfo> arrayList = new ArrayList<>();
        int analyseInfo = this.f7109a.getAnalyseInfo(list, arrayList);
        if (analyseInfo == 0) {
            responseInfo.type = 0;
            responseInfo.code = analyseInfo;
        } else if (ErrorCode.judgeErrorCode(analyseInfo) == 0) {
            responseInfo.type = 2;
            responseInfo.code = analyseInfo;
            Log.m2634e("MarketManager", "network error");
        } else {
            responseInfo.type = 1;
            responseInfo.code = analyseInfo;
            Log.m2634e("MarketManager", "runtime error");
        }
        if (iMarketManagerListener != null) {
            m3119b(arrayList);
            iMarketManagerListener.onReceive(responseInfo, arrayList);
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m3126a(List<SoftFeature> list, IMarketManagerListener<ResponseInfo, Void> iMarketManagerListener) {
        ResponseInfo responseInfo = new ResponseInfo();
        int iReportSoftFeature = this.f7109a.reportSoftFeature(list);
        if (iReportSoftFeature == 0) {
            responseInfo.type = 0;
            responseInfo.code = iReportSoftFeature;
        } else if (ErrorCode.judgeErrorCode(iReportSoftFeature) == 0) {
            responseInfo.type = 2;
            responseInfo.code = iReportSoftFeature;
            Log.m2634e("MarketManager", "network error");
        } else {
            responseInfo.type = 1;
            responseInfo.code = iReportSoftFeature;
            Log.m2634e("MarketManager", "runtime error");
        }
        if (iMarketManagerListener != null) {
            iMarketManagerListener.onReceive(responseInfo, null);
        }
    }

    /* JADX INFO: renamed from: a */
    public final boolean m3127a() {
        return false;
    }

    /* JADX INFO: renamed from: b */
    public final void m3128b(RequestInfo requestInfo, IMarketManagerListener<ResponseInfo, SoftSimpleInfoEx> iMarketManagerListener) {
        ResponseInfo responseInfo = new ResponseInfo();
        String requestCommand = requestInfo != null ? requestInfo.getRequestCommand() : "";
        ArrayList<SoftSimpleInfoEx> arrayList = new ArrayList<>();
        AtomicReference<SoftServerInfo> atomicReference = new AtomicReference<>();
        ArrayList<SoftSimpleInfo> arrayList2 = new ArrayList<>();
        int softList = this.f7109a.getSoftList(requestCommand, atomicReference, arrayList2);
        if (softList == 0) {
            responseInfo.type = 0;
            responseInfo.code = softList;
            UniAttribute uniAttribute = new UniAttribute();
            uniAttribute.setEncodeName(InterfaceC0079b.f1213a);
            for (SoftSimpleInfo softSimpleInfo : arrayList2) {
                SoftSimpleInfoEx softSimpleInfoEx = new SoftSimpleInfoEx();
                softSimpleInfoEx.setSoftSimpleInfo(softSimpleInfo);
                if (softSimpleInfo.getExpand() != null) {
                    uniAttribute.clearCacheData();
                    uniAttribute.decode(softSimpleInfo.getExpand());
                    softSimpleInfoEx.setExpand((AndroidSimpleInfoExpand) uniAttribute.getByClass(MarketManager.JCE_EXPAND_KEY, new AndroidSimpleInfoExpand()));
                }
                arrayList.add(softSimpleInfoEx);
            }
        } else if (ErrorCode.judgeErrorCode(softList) == 0) {
            responseInfo.type = 2;
            responseInfo.code = softList;
            Log.m2634e("MarketManager", "network error");
        } else {
            responseInfo.type = 1;
            responseInfo.code = softList;
            Log.m2634e("MarketManager", "runtime error");
        }
        if (iMarketManagerListener != null) {
            m3118a(arrayList2);
            iMarketManagerListener.onReceive(responseInfo, arrayList);
        }
    }

    /* JADX INFO: renamed from: b */
    public final void m3129b(RequestInfo requestInfo, List<SoftKey> list, IMarketManagerListener<ResponseInfo, MySoftSimpleInfo> iMarketManagerListener) {
        ResponseInfo responseInfo = new ResponseInfo();
        AtomicReference<SoftServerInfo> atomicReference = new AtomicReference<>();
        ArrayList<MySoftSimpleInfo> arrayList = new ArrayList<>();
        int mySoftList = this.f7109a.getMySoftList(list, atomicReference, arrayList);
        if (mySoftList == 0) {
            responseInfo.type = 0;
            responseInfo.code = mySoftList;
        } else if (ErrorCode.judgeErrorCode(mySoftList) == 0) {
            responseInfo.type = 2;
            responseInfo.code = mySoftList;
            Log.m2634e("MarketManager", "network error");
        } else {
            responseInfo.type = 1;
            responseInfo.code = mySoftList;
            Log.m2634e("MarketManager", "runtime error");
        }
        if (iMarketManagerListener != null) {
            iMarketManagerListener.onReceive(responseInfo, arrayList);
        }
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final int getSingletonType() {
        return 2;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f7109a = (WupSessionManager) ManagerCreator.getManager(WupSessionManager.class);
    }
}
