package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;
import java.util.ArrayList;
import java.util.Collection;

/* JADX INFO: loaded from: classes.dex */
public final class QQInfo extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static ArrayList<ClientVersionInfo> f480a;

    /* JADX INFO: renamed from: b */
    static ServerCmdInfo f481b;

    /* JADX INFO: renamed from: c */
    static final /* synthetic */ boolean f482c;
    public ServerCmdInfo cmdinfo;
    public String loginkey;
    public String username;
    public ArrayList<ClientVersionInfo> vecclient;

    static {
        f482c = !QQInfo.class.desiredAssertionStatus();
    }

    public QQInfo() {
        this.username = "";
        this.loginkey = "";
        this.vecclient = null;
        this.cmdinfo = null;
        this.username = this.username;
        this.loginkey = this.loginkey;
        this.vecclient = this.vecclient;
        this.cmdinfo = this.cmdinfo;
    }

    public QQInfo(String str, String str2, ArrayList<ClientVersionInfo> arrayList, ServerCmdInfo serverCmdInfo) {
        this.username = "";
        this.loginkey = "";
        this.vecclient = null;
        this.cmdinfo = null;
        this.username = str;
        this.loginkey = str2;
        this.vecclient = arrayList;
        this.cmdinfo = serverCmdInfo;
    }

    public final String className() {
        return "QQPIM.QQInfo";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f482c) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.username, "username");
        jceDisplayer.display(this.loginkey, "loginkey");
        jceDisplayer.display((Collection) this.vecclient, "vecclient");
        jceDisplayer.display((JceStruct) this.cmdinfo, "cmdinfo");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        QQInfo qQInfo = (QQInfo) obj;
        return JceUtil.equals(this.username, qQInfo.username) && JceUtil.equals(this.loginkey, qQInfo.loginkey) && JceUtil.equals(this.vecclient, qQInfo.vecclient) && JceUtil.equals(this.cmdinfo, qQInfo.cmdinfo);
    }

    public final String fullClassName() {
        return "QQPIM.QQInfo";
    }

    public final ServerCmdInfo getCmdinfo() {
        return this.cmdinfo;
    }

    public final String getLoginkey() {
        return this.loginkey;
    }

    public final String getUsername() {
        return this.username;
    }

    public final ArrayList<ClientVersionInfo> getVecclient() {
        return this.vecclient;
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
        this.username = jceInputStream.readString(0, true);
        this.loginkey = jceInputStream.readString(1, true);
        if (f480a == null) {
            f480a = new ArrayList<>();
            f480a.add(new ClientVersionInfo());
        }
        setVecclient((ArrayList) jceInputStream.read(f480a, 2, false));
        if (f481b == null) {
            f481b = new ServerCmdInfo();
        }
        setCmdinfo((ServerCmdInfo) jceInputStream.read((JceStruct) f481b, 3, false));
    }

    public final void setCmdinfo(ServerCmdInfo serverCmdInfo) {
        this.cmdinfo = serverCmdInfo;
    }

    public final void setLoginkey(String str) {
        this.loginkey = str;
    }

    public final void setUsername(String str) {
        this.username = str;
    }

    public final void setVecclient(ArrayList<ClientVersionInfo> arrayList) {
        this.vecclient = arrayList;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.username, 0);
        jceOutputStream.write(this.loginkey, 1);
        if (this.vecclient != null) {
            jceOutputStream.write((Collection) this.vecclient, 2);
        }
        if (this.cmdinfo != null) {
            jceOutputStream.write((JceStruct) this.cmdinfo, 3);
        }
    }
}
