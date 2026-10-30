package com.lenovo.feedback2.message;

import android.util.Log;
import com.lenovo.feedback2.message.protocol.HeaderNames;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.util.HashMap;
import java.util.Map;
import org.json.JSONException;
import org.json.JSONStringer;

/* JADX INFO: loaded from: classes.dex */
public class BasicMessageBuilder {

    /* JADX INFO: renamed from: a */
    private static String f956a = "FeedBackService";

    /* JADX INFO: renamed from: b */
    private int f957b;

    /* JADX INFO: renamed from: c */
    private Map<String, byte[]> f958c = new HashMap();

    public BasicMessageBuilder(int protocolVersion) {
        this.f957b = -1;
        this.f957b = protocolVersion;
    }

    public BasicMessageBuilder addString(Enum<? extends HeaderNames> tag, String line) {
        addString(tag, line, "utf-8");
        return this;
    }

    public BasicMessageBuilder addString(Enum<? extends HeaderNames> tag, String line, String charsetName) {
        try {
            byte[] data = line.getBytes(charsetName);
            this.f958c.put(tag.name(), data);
        } catch (UnsupportedEncodingException e) {
            Log.i(f956a, "BasicMessageBuilder::addString encoding fail", e);
        }
        return this;
    }

    public BasicMessageBuilder addBinary(Enum<? extends HeaderNames> tag, byte[] binaryData) {
        this.f958c.put(tag.name(), binaryData);
        return this;
    }

    public Message build() {
        C0049a headerBuilder = new C0049a(this, (byte) 0);
        ByteArrayOutputStream dataStream = new ByteArrayOutputStream();
        int offset = 0;
        for (Map.Entry<String, byte[]> entry : this.f958c.entrySet()) {
            String key = entry.getKey();
            byte[] data = entry.getValue();
            try {
                headerBuilder.m139a(key, data.length, offset);
                dataStream.write(data);
                offset += data.length;
            } catch (IOException e) {
                Log.e(f956a, "BasicMessageBuilder::build write data to stream err", e);
                try {
                    dataStream.close();
                    return null;
                } catch (IOException e2) {
                    return null;
                }
            } catch (JSONException e3) {
                Log.e(f956a, "BasicMessageBuilder::build write key to json err", e3);
                try {
                    dataStream.close();
                    return null;
                } catch (IOException e4) {
                    return null;
                }
            }
        }
        try {
            String header = headerBuilder.m140a();
            Message message = new Message();
            message.setVersion(this.f957b);
            message.setHeader(header);
            message.setData(dataStream.toByteArray());
            return message;
        } catch (JSONException e5) {
            Log.e(f956a, "BasicMessageBuilder::build make json header fail", e5);
            return null;
        }
    }

    /* JADX INFO: renamed from: com.lenovo.feedback2.message.BasicMessageBuilder$a */
    private class C0049a {

        /* JADX INFO: renamed from: b */
        private JSONStringer f960b;

        private C0049a() {
        }

        /* synthetic */ C0049a(BasicMessageBuilder basicMessageBuilder, byte b) {
            this();
        }

        /* JADX INFO: renamed from: a */
        public final C0049a m139a(String tag, long dataLength, int dataOffset) throws JSONException {
            if (this.f960b == null) {
                this.f960b = new JSONStringer();
                this.f960b.object();
            }
            this.f960b.key(tag).array().value(dataLength).value(dataOffset).endArray();
            return this;
        }

        /* JADX INFO: renamed from: a */
        public final String m140a() throws JSONException {
            return this.f960b.endObject().toString();
        }
    }
}
