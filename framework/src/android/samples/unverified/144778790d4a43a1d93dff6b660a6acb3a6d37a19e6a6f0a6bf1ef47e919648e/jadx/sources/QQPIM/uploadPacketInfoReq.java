package QQPIM;

import com.p012qq.taf.jce.JceDisplayer;
import com.p012qq.taf.jce.JceInputStream;
import com.p012qq.taf.jce.JceOutputStream;
import com.p012qq.taf.jce.JceStruct;
import com.p012qq.taf.jce.JceUtil;

/* JADX INFO: loaded from: classes.dex */
public final class uploadPacketInfoReq extends JceStruct {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f629a;
    public String checksum_type;
    public int checksun_len;
    public long packet_pos;
    public int packet_size;
    public String software_id;
    public int zip_type;

    static {
        f629a = !uploadPacketInfoReq.class.desiredAssertionStatus();
    }

    public uploadPacketInfoReq() {
        this.software_id = "";
        this.packet_pos = 0L;
        this.packet_size = 0;
        this.checksum_type = "";
        this.checksun_len = 0;
        this.zip_type = 0;
        this.software_id = this.software_id;
        this.packet_pos = this.packet_pos;
        this.packet_size = this.packet_size;
        this.checksum_type = this.checksum_type;
        this.checksun_len = this.checksun_len;
        this.zip_type = this.zip_type;
    }

    public uploadPacketInfoReq(String str, long j, int i, String str2, int i2, int i3) {
        this.software_id = "";
        this.packet_pos = 0L;
        this.packet_size = 0;
        this.checksum_type = "";
        this.checksun_len = 0;
        this.zip_type = 0;
        this.software_id = str;
        this.packet_pos = j;
        this.packet_size = i;
        this.checksum_type = str2;
        this.checksun_len = i2;
        this.zip_type = i3;
    }

    public final String className() {
        return "QQPIM.uploadPacketInfoReq";
    }

    public final Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            if (f629a) {
                return null;
            }
            throw new AssertionError();
        }
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void display(StringBuilder sb, int i) {
        JceDisplayer jceDisplayer = new JceDisplayer(sb, i);
        jceDisplayer.display(this.software_id, "software_id");
        jceDisplayer.display(this.packet_pos, "packet_pos");
        jceDisplayer.display(this.packet_size, "packet_size");
        jceDisplayer.display(this.checksum_type, "checksum_type");
        jceDisplayer.display(this.checksun_len, "checksun_len");
        jceDisplayer.display(this.zip_type, "zip_type");
    }

    public final boolean equals(Object obj) {
        uploadPacketInfoReq uploadpacketinforeq = (uploadPacketInfoReq) obj;
        return JceUtil.equals(this.software_id, uploadpacketinforeq.software_id) && JceUtil.equals(this.packet_pos, uploadpacketinforeq.packet_pos) && JceUtil.equals(this.packet_size, uploadpacketinforeq.packet_size) && JceUtil.equals(this.checksum_type, uploadpacketinforeq.checksum_type) && JceUtil.equals(this.checksun_len, uploadpacketinforeq.checksun_len) && JceUtil.equals(this.zip_type, uploadpacketinforeq.zip_type);
    }

    public final String getChecksum_type() {
        return this.checksum_type;
    }

    public final int getChecksun_len() {
        return this.checksun_len;
    }

    public final long getPacket_pos() {
        return this.packet_pos;
    }

    public final int getPacket_size() {
        return this.packet_size;
    }

    public final String getSoftware_id() {
        return this.software_id;
    }

    public final int getZip_type() {
        return this.zip_type;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void readFrom(JceInputStream jceInputStream) {
        this.software_id = jceInputStream.readString(0, true);
        this.packet_pos = jceInputStream.read(this.packet_pos, 1, true);
        this.packet_size = jceInputStream.read(this.packet_size, 2, true);
        this.checksum_type = jceInputStream.readString(3, true);
        this.checksun_len = jceInputStream.read(this.checksun_len, 4, true);
        this.zip_type = jceInputStream.read(this.zip_type, 5, false);
    }

    public final void setChecksum_type(String str) {
        this.checksum_type = str;
    }

    public final void setChecksun_len(int i) {
        this.checksun_len = i;
    }

    public final void setPacket_pos(long j) {
        this.packet_pos = j;
    }

    public final void setPacket_size(int i) {
        this.packet_size = i;
    }

    public final void setSoftware_id(String str) {
        this.software_id = str;
    }

    public final void setZip_type(int i) {
        this.zip_type = i;
    }

    @Override // com.p012qq.taf.jce.JceStruct
    public final void writeTo(JceOutputStream jceOutputStream) {
        jceOutputStream.write(this.software_id, 0);
        jceOutputStream.write(this.packet_pos, 1);
        jceOutputStream.write(this.packet_size, 2);
        jceOutputStream.write(this.checksum_type, 3);
        jceOutputStream.write(this.checksun_len, 4);
        jceOutputStream.write(this.zip_type, 5);
    }
}
