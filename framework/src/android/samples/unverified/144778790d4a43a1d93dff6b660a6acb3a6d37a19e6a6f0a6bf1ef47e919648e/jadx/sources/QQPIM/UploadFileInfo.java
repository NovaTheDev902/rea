package QQPIM;

import com.lenovo.providers.querypermissions.QueryPermissions;
import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class UploadFileInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static ArrayList<UploadFile> f600a;

    /* JADX INFO: renamed from: b */
    static final /* synthetic */ boolean f601b;

    /* JADX INFO: renamed from: id */
    public String f602id;
    public ArrayList<UploadFile> vecUploadFile;

    static {
        f601b = !UploadFileInfo.class.desiredAssertionStatus();
    }

    public UploadFileInfo() {
        this.f602id = "";
        this.vecUploadFile = null;
        this.f602id = this.f602id;
        this.vecUploadFile = this.vecUploadFile;
    }

    public UploadFileInfo(String str, ArrayList<UploadFile> arrayList) {
        this.f602id = "";
        this.vecUploadFile = null;
        this.f602id = str;
        this.vecUploadFile = arrayList;
    }

    public final String className() {
        return "QQPIM.UploadFileInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f601b) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.f602id, QueryPermissions.f1958ID);
        jceDisplayer.display((Collection) this.vecUploadFile, "vecUploadFile");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        UploadFileInfo uploadFileInfo = (UploadFileInfo) obj;
        return JceUtil.equals(this.f602id, uploadFileInfo.f602id) && JceUtil.equals(this.vecUploadFile, uploadFileInfo.vecUploadFile);
    }

    public final String fullClassName() {
        return "QQPIM.UploadFileInfo";
    }

    public final String getId() {
        return this.f602id;
    }

    public final ArrayList<UploadFile> getVecUploadFile() {
        return this.vecUploadFile;
    }

    public final int hashCode() {
        try {
            throw new Exception("Need define key first!");
        } catch (Exception e) {
            e.printStackTrace();
            return 0;
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void readFrom(JceInputStream jceInputStream) {
        this.f602id = jceInputStream.readString(0, true);
        if (f600a == null) {
            f600a = new ArrayList<>();
            f600a.add(new UploadFile());
        }
        setVecUploadFile((ArrayList) jceInputStream.read(f600a, 1, true));
    }

    public final void setId(String str) {
        this.f602id = str;
    }

    public final void setVecUploadFile(ArrayList<UploadFile> arrayList) {
        this.vecUploadFile = arrayList;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.f602id, 0);
        jceOutputStream.write((Collection) this.vecUploadFile, 1);
    }
}
