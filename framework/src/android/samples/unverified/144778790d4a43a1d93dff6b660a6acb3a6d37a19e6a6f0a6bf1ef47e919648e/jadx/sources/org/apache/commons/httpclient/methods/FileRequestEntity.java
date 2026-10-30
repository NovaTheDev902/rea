package org.apache.commons.httpclient.methods;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

/* JADX INFO: loaded from: classes.dex */
public class FileRequestEntity implements RequestEntity {

    /* JADX INFO: renamed from: a */
    final File f6679a;

    /* JADX INFO: renamed from: b */
    final String f6680b;

    public FileRequestEntity(File file, String contentType) {
        if (file == null) {
            throw new IllegalArgumentException("File may not be null");
        }
        this.f6679a = file;
        this.f6680b = contentType;
    }

    @Override // org.apache.commons.httpclient.methods.RequestEntity
    public long getContentLength() {
        return this.f6679a.length();
    }

    @Override // org.apache.commons.httpclient.methods.RequestEntity
    public String getContentType() {
        return this.f6680b;
    }

    @Override // org.apache.commons.httpclient.methods.RequestEntity
    public boolean isRepeatable() {
        return true;
    }

    @Override // org.apache.commons.httpclient.methods.RequestEntity
    public void writeRequest(OutputStream out) throws IOException {
        byte[] tmp = new byte[4096];
        InputStream instream = new FileInputStream(this.f6679a);
        while (true) {
            try {
                int i = instream.read(tmp);
                if (i >= 0) {
                    out.write(tmp, 0, i);
                } else {
                    instream.close();
                    return;
                }
            } catch (Throwable th) {
                instream.close();
                throw th;
            }
        }
    }
}
