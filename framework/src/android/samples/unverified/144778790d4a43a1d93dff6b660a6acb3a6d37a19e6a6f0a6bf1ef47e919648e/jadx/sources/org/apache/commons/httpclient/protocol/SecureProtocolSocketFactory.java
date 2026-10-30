package org.apache.commons.httpclient.protocol;

import java.io.IOException;
import java.net.Socket;

/* JADX INFO: loaded from: classes.dex */
public interface SecureProtocolSocketFactory extends ProtocolSocketFactory {
    Socket createSocket(Socket socket, String str, int i, boolean z) throws IOException;
}
