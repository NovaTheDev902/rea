package org.apache.commons.httpclient.methods.multipart;

import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;

/* JADX INFO: loaded from: classes.dex */
public class FilePartSource implements PartSource {

    /* JADX INFO: renamed from: a */
    private File f6709a;

    /* JADX INFO: renamed from: b */
    private String f6710b;

    public FilePartSource(File file) throws FileNotFoundException {
        this.f6709a = null;
        this.f6710b = null;
        this.f6709a = file;
        if (file != null) {
            if (!file.isFile()) {
                throw new FileNotFoundException("File is not a normal file.");
            }
            if (!file.canRead()) {
                throw new FileNotFoundException("File is not readable.");
            }
            this.f6710b = file.getName();
        }
    }

    public FilePartSource(String fileName, File file) throws FileNotFoundException {
        this(file);
        if (fileName != null) {
            this.f6710b = fileName;
        }
    }

    @Override // org.apache.commons.httpclient.methods.multipart.PartSource
    public long getLength() {
        if (this.f6709a != null) {
            return this.f6709a.length();
        }
        return 0L;
    }

    @Override // org.apache.commons.httpclient.methods.multipart.PartSource
    public String getFileName() {
        return this.f6710b == null ? "noname" : this.f6710b;
    }

    @Override // org.apache.commons.httpclient.methods.multipart.PartSource
    public InputStream createInputStream() throws IOException {
        return this.f6709a != null ? new FileInputStream(this.f6709a) : new ByteArrayInputStream(new byte[0]);
    }
}
