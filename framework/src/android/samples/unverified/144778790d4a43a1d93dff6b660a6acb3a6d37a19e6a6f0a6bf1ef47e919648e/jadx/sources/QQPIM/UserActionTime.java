package QQPIM;

import com.lenovo.safecenter.database.AppDatabase;
import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class UserActionTime extends JceStruct {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f610a;
    public int time;
    public int userAction;

    static {
        f610a = !UserActionTime.class.desiredAssertionStatus();
    }

    public UserActionTime() {
        this.userAction = 0;
        this.time = 0;
        this.userAction = this.userAction;
        this.time = this.time;
    }

    public UserActionTime(int i, int i2) {
        this.userAction = 0;
        this.time = 0;
        this.userAction = i;
        this.time = i2;
    }

    public final String className() {
        return "QQPIM.UserActionTime";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f610a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.userAction, "userAction");
        jceDisplayer.display(this.time, AppDatabase.TIME);
    }

    public final boolean equals(Object obj) {
        UserActionTime userActionTime = (UserActionTime) obj;
        return JceUtil.equals(this.userAction, userActionTime.userAction) && JceUtil.equals(this.time, userActionTime.time);
    }

    public final int getTime() {
        return this.time;
    }

    public final int getUserAction() {
        return this.userAction;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void readFrom(JceInputStream jceInputStream) {
        this.userAction = jceInputStream.read(this.userAction, 0, true);
        this.time = jceInputStream.read(this.time, 1, true);
    }

    public final void setTime(int i) {
        this.time = i;
    }

    public final void setUserAction(int i) {
        this.userAction = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.userAction, 0);
        jceOutputStream.write(this.time, 1);
    }
}
