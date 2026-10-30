package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class ActionItem extends JceStruct implements Cloneable {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f68a;
    public int count;
    public String desc;
    public int level;
    public int type;

    static {
        f68a = !ActionItem.class.desiredAssertionStatus();
    }

    public ActionItem() {
        this.type = 0;
        this.desc = "";
        this.level = 0;
        this.count = 0;
        this.type = this.type;
        this.desc = this.desc;
        this.level = this.level;
        this.count = this.count;
    }

    public ActionItem(int i, String str, int i2, int i3) {
        this.type = 0;
        this.desc = "";
        this.level = 0;
        this.count = 0;
        this.type = i;
        this.desc = str;
        this.level = i2;
        this.count = i3;
    }

    public final String className() {
        return "QQPIM.ActionItem";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f68a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.type, "type");
        jceDisplayer.display(this.desc, "desc");
        jceDisplayer.display(this.level, "level");
        jceDisplayer.display(this.count, "count");
    }

    public final boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        ActionItem actionItem = (ActionItem) obj;
        return JceUtil.equals(this.type, actionItem.type) && JceUtil.equals(this.desc, actionItem.desc) && JceUtil.equals(this.level, actionItem.level) && JceUtil.equals(this.count, actionItem.count);
    }

    public final String fullClassName() {
        return "QQPIM.ActionItem";
    }

    public final int getCount() {
        return this.count;
    }

    public final String getDesc() {
        return this.desc;
    }

    public final int getLevel() {
        return this.level;
    }

    public final int getType() {
        return this.type;
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
        this.type = jceInputStream.read(this.type, 0, true);
        this.desc = jceInputStream.readString(1, true);
        this.level = jceInputStream.read(this.level, 2, true);
        this.count = jceInputStream.read(this.count, 3, false);
    }

    public final void setCount(int i) {
        this.count = i;
    }

    public final void setDesc(String str) {
        this.desc = str;
    }

    public final void setLevel(int i) {
        this.level = i;
    }

    public final void setType(int i) {
        this.type = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.type, 0);
        jceOutputStream.write(this.desc, 1);
        jceOutputStream.write(this.level, 2);
        jceOutputStream.write(this.count, 3);
    }
}
