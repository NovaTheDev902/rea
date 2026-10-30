package org.apache.commons.httpclient;

/* JADX INFO: loaded from: classes.dex */
public class HttpStatus {
    public static final int SC_ACCEPTED = 202;
    public static final int SC_BAD_GATEWAY = 502;
    public static final int SC_BAD_REQUEST = 400;
    public static final int SC_CONFLICT = 409;
    public static final int SC_CONTINUE = 100;
    public static final int SC_CREATED = 201;
    public static final int SC_EXPECTATION_FAILED = 417;
    public static final int SC_FAILED_DEPENDENCY = 424;
    public static final int SC_FORBIDDEN = 403;
    public static final int SC_GATEWAY_TIMEOUT = 504;
    public static final int SC_GONE = 410;
    public static final int SC_HTTP_VERSION_NOT_SUPPORTED = 505;
    public static final int SC_INSUFFICIENT_SPACE_ON_RESOURCE = 419;
    public static final int SC_INSUFFICIENT_STORAGE = 507;
    public static final int SC_INTERNAL_SERVER_ERROR = 500;
    public static final int SC_LENGTH_REQUIRED = 411;
    public static final int SC_LOCKED = 423;
    public static final int SC_METHOD_FAILURE = 420;
    public static final int SC_METHOD_NOT_ALLOWED = 405;
    public static final int SC_MOVED_PERMANENTLY = 301;
    public static final int SC_MOVED_TEMPORARILY = 302;
    public static final int SC_MULTIPLE_CHOICES = 300;
    public static final int SC_MULTI_STATUS = 207;
    public static final int SC_NON_AUTHORITATIVE_INFORMATION = 203;
    public static final int SC_NOT_ACCEPTABLE = 406;
    public static final int SC_NOT_FOUND = 404;
    public static final int SC_NOT_IMPLEMENTED = 501;
    public static final int SC_NOT_MODIFIED = 304;
    public static final int SC_NO_CONTENT = 204;
    public static final int SC_OK = 200;
    public static final int SC_PARTIAL_CONTENT = 206;
    public static final int SC_PAYMENT_REQUIRED = 402;
    public static final int SC_PRECONDITION_FAILED = 412;
    public static final int SC_PROCESSING = 102;
    public static final int SC_PROXY_AUTHENTICATION_REQUIRED = 407;
    public static final int SC_REQUESTED_RANGE_NOT_SATISFIABLE = 416;
    public static final int SC_REQUEST_TIMEOUT = 408;
    public static final int SC_REQUEST_TOO_LONG = 413;
    public static final int SC_REQUEST_URI_TOO_LONG = 414;
    public static final int SC_RESET_CONTENT = 205;
    public static final int SC_SEE_OTHER = 303;
    public static final int SC_SERVICE_UNAVAILABLE = 503;
    public static final int SC_SWITCHING_PROTOCOLS = 101;
    public static final int SC_TEMPORARY_REDIRECT = 307;
    public static final int SC_UNAUTHORIZED = 401;
    public static final int SC_UNPROCESSABLE_ENTITY = 422;
    public static final int SC_UNSUPPORTED_MEDIA_TYPE = 415;
    public static final int SC_USE_PROXY = 305;

    /* JADX INFO: renamed from: a */
    private static final String[][] f6515a = {new String[0], new String[3], new String[8], new String[8], new String[25], new String[8]};

    static {
        m2721a(200, "OK");
        m2721a(201, "Created");
        m2721a(202, "Accepted");
        m2721a(204, "No Content");
        m2721a(301, "Moved Permanently");
        m2721a(302, "Moved Temporarily");
        m2721a(304, "Not Modified");
        m2721a(400, "Bad Request");
        m2721a(401, "Unauthorized");
        m2721a(SC_FORBIDDEN, "Forbidden");
        m2721a(SC_NOT_FOUND, "Not Found");
        m2721a(500, "Internal Server Error");
        m2721a(501, "Not Implemented");
        m2721a(SC_BAD_GATEWAY, "Bad Gateway");
        m2721a(SC_SERVICE_UNAVAILABLE, "Service Unavailable");
        m2721a(100, "Continue");
        m2721a(307, "Temporary Redirect");
        m2721a(SC_METHOD_NOT_ALLOWED, "Method Not Allowed");
        m2721a(SC_CONFLICT, "Conflict");
        m2721a(412, "Precondition Failed");
        m2721a(SC_REQUEST_TOO_LONG, "Request Too Long");
        m2721a(SC_REQUEST_URI_TOO_LONG, "Request-URI Too Long");
        m2721a(SC_UNSUPPORTED_MEDIA_TYPE, "Unsupported Media Type");
        m2721a(300, "Multiple Choices");
        m2721a(303, "See Other");
        m2721a(305, "Use Proxy");
        m2721a(402, "Payment Required");
        m2721a(406, "Not Acceptable");
        m2721a(SC_PROXY_AUTHENTICATION_REQUIRED, "Proxy Authentication Required");
        m2721a(SC_REQUEST_TIMEOUT, "Request Timeout");
        m2721a(101, "Switching Protocols");
        m2721a(203, "Non Authoritative Information");
        m2721a(SC_RESET_CONTENT, "Reset Content");
        m2721a(SC_PARTIAL_CONTENT, "Partial Content");
        m2721a(SC_GATEWAY_TIMEOUT, "Gateway Timeout");
        m2721a(SC_HTTP_VERSION_NOT_SUPPORTED, "Http Version Not Supported");
        m2721a(SC_GONE, "Gone");
        m2721a(411, "Length Required");
        m2721a(SC_REQUESTED_RANGE_NOT_SATISFIABLE, "Requested Range Not Satisfiable");
        m2721a(SC_EXPECTATION_FAILED, "Expectation Failed");
        m2721a(102, "Processing");
        m2721a(SC_MULTI_STATUS, "Multi-Status");
        m2721a(SC_UNPROCESSABLE_ENTITY, "Unprocessable Entity");
        m2721a(SC_INSUFFICIENT_SPACE_ON_RESOURCE, "Insufficient Space On Resource");
        m2721a(SC_METHOD_FAILURE, "Method Failure");
        m2721a(SC_LOCKED, "Locked");
        m2721a(SC_INSUFFICIENT_STORAGE, "Insufficient Storage");
        m2721a(SC_FAILED_DEPENDENCY, "Failed Dependency");
    }

    public static String getStatusText(int statusCode) {
        if (statusCode < 0) {
            throw new IllegalArgumentException("status code may not be negative");
        }
        int classIndex = statusCode / 100;
        int codeIndex = statusCode - (classIndex * 100);
        if (classIndex < 1 || classIndex > f6515a.length - 1 || codeIndex < 0 || codeIndex > f6515a[classIndex].length - 1) {
            return null;
        }
        return f6515a[classIndex][codeIndex];
    }

    /* JADX INFO: renamed from: a */
    private static void m2721a(int statusCode, String reasonPhrase) {
        int classIndex = statusCode / 100;
        f6515a[classIndex][statusCode - (classIndex * 100)] = reasonPhrase;
    }
}
