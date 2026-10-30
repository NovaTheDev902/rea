package org.apache.commons.httpclient.protocol;

import java.io.IOException;
import java.net.InetAddress;
import java.net.Socket;
import org.apache.commons.httpclient.ConnectTimeoutException;
import org.apache.commons.httpclient.util.TimeoutController;

/* JADX INFO: loaded from: classes.dex */
public final class ControllerThreadSocketFactory {
    private ControllerThreadSocketFactory() {
    }

    public static Socket createSocket(ProtocolSocketFactory socketfactory, String host, int port, InetAddress localAddress, int localPort, int timeout) throws IOException {
        SocketTask task = new C1134a(socketfactory, host, port, localAddress, localPort);
        try {
            TimeoutController.execute(task, timeout);
            Socket socket = task.getSocket();
            if (SocketTask.m2837a(task) != null) {
                throw SocketTask.m2837a(task);
            }
            return socket;
        } catch (TimeoutController.TimeoutException e) {
            throw new ConnectTimeoutException(new StringBuffer().append("The host did not accept the connection within timeout of ").append(timeout).append(" ms").toString());
        }
    }

    public static Socket createSocket(SocketTask task, int timeout) throws IOException {
        try {
            TimeoutController.execute(task, timeout);
            Socket socket = task.getSocket();
            if (SocketTask.m2837a(task) != null) {
                throw SocketTask.m2837a(task);
            }
            return socket;
        } catch (TimeoutController.TimeoutException e) {
            throw new ConnectTimeoutException(new StringBuffer().append("The host did not accept the connection within timeout of ").append(timeout).append(" ms").toString());
        }
    }

    public static abstract class SocketTask implements Runnable {

        /* JADX INFO: renamed from: a */
        private Socket f6739a;

        /* JADX INFO: renamed from: b */
        private IOException f6740b;

        public abstract void doit() throws IOException;

        /* JADX INFO: renamed from: a */
        static IOException m2837a(SocketTask x0) {
            return x0.f6740b;
        }

        protected void setSocket(Socket newSocket) {
            this.f6739a = newSocket;
        }

        protected Socket getSocket() {
            return this.f6739a;
        }

        @Override // java.lang.Runnable
        public void run() {
            try {
                doit();
            } catch (IOException e) {
                this.f6740b = e;
            }
        }
    }
}
