package com.lenovo.safecenter.mmsutils;

import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class ContentType {
    public static final String APP_DRM_CONTENT = "application/vnd.oma.drm.content";
    public static final String APP_DRM_MESSAGE = "application/vnd.oma.drm.message";
    public static final String APP_SMIL = "application/smil";
    public static final String APP_WAP_XHTML = "application/vnd.wap.xhtml+xml";
    public static final String APP_XHTML = "application/xhtml+xml";
    public static final String AUDIO_3GPP = "audio/3gpp";
    public static final String AUDIO_AAC = "audio/aac";
    public static final String AUDIO_AMR = "audio/amr";
    public static final String AUDIO_IMELODY = "audio/imelody";
    public static final String AUDIO_MID = "audio/mid";
    public static final String AUDIO_MIDI = "audio/midi";
    public static final String AUDIO_MP3 = "audio/mp3";
    public static final String AUDIO_MP4 = "audio/mp4";
    public static final String AUDIO_MPEG = "audio/mpeg";
    public static final String AUDIO_MPEG3 = "audio/mpeg3";
    public static final String AUDIO_MPG = "audio/mpg";
    public static final String AUDIO_OGG = "application/ogg";
    public static final String AUDIO_UNSPECIFIED = "audio/*";
    public static final String AUDIO_X_MID = "audio/x-mid";
    public static final String AUDIO_X_MIDI = "audio/x-midi";
    public static final String AUDIO_X_MP3 = "audio/x-mp3";
    public static final String AUDIO_X_MPEG = "audio/x-mpeg";
    public static final String AUDIO_X_MPEG3 = "audio/x-mpeg3";
    public static final String AUDIO_X_MPG = "audio/x-mpg";
    public static final String IMAGE_GIF = "image/gif";
    public static final String IMAGE_JPEG = "image/jpeg";
    public static final String IMAGE_JPG = "image/jpg";
    public static final String IMAGE_PNG = "image/png";
    public static final String IMAGE_UNSPECIFIED = "image/*";
    public static final String IMAGE_WBMP = "image/vnd.wap.wbmp";
    public static final String MMS_GENERIC = "application/vnd.wap.mms-generic";
    public static final String MMS_MESSAGE = "application/vnd.wap.mms-message";
    public static final String MULTIPART_ALTERNATIVE = "application/vnd.wap.multipart.alternative";
    public static final String MULTIPART_MIXED = "application/vnd.wap.multipart.mixed";
    public static final String MULTIPART_RELATED = "application/vnd.wap.multipart.related";
    public static final String TEXT_HTML = "text/html";
    public static final String TEXT_PLAIN = "text/plain";
    public static final String TEXT_VCALENDAR = "text/x-vCalendar";
    public static final String TEXT_VCARD = "text/x-vCard";
    public static final String VIDEO_3G2 = "video/3gpp2";
    public static final String VIDEO_3GPP = "video/3gpp";
    public static final String VIDEO_H263 = "video/h263";
    public static final String VIDEO_MP4 = "video/mp4";
    public static final String VIDEO_UNSPECIFIED = "video/*";

    /* JADX INFO: renamed from: a */
    private static final ArrayList<String> f4293a = new ArrayList<>();

    /* JADX INFO: renamed from: b */
    private static final ArrayList<String> f4294b = new ArrayList<>();

    /* JADX INFO: renamed from: c */
    private static final ArrayList<String> f4295c = new ArrayList<>();

    /* JADX INFO: renamed from: d */
    private static final ArrayList<String> f4296d = new ArrayList<>();

    static {
        f4293a.add("text/plain");
        f4293a.add(TEXT_HTML);
        f4293a.add(TEXT_VCALENDAR);
        f4293a.add(TEXT_VCARD);
        f4293a.add(IMAGE_JPEG);
        f4293a.add(IMAGE_GIF);
        f4293a.add(IMAGE_WBMP);
        f4293a.add(IMAGE_PNG);
        f4293a.add(IMAGE_JPG);
        f4293a.add(AUDIO_AAC);
        f4293a.add(AUDIO_AMR);
        f4293a.add(AUDIO_IMELODY);
        f4293a.add(AUDIO_MID);
        f4293a.add(AUDIO_MIDI);
        f4293a.add(AUDIO_MP3);
        f4293a.add(AUDIO_MPEG3);
        f4293a.add(AUDIO_MPEG);
        f4293a.add(AUDIO_MPG);
        f4293a.add(AUDIO_X_MID);
        f4293a.add(AUDIO_X_MIDI);
        f4293a.add(AUDIO_X_MP3);
        f4293a.add(AUDIO_X_MPEG3);
        f4293a.add(AUDIO_X_MPEG);
        f4293a.add(AUDIO_X_MPG);
        f4293a.add(AUDIO_3GPP);
        f4293a.add(AUDIO_OGG);
        f4293a.add(VIDEO_3GPP);
        f4293a.add(VIDEO_3G2);
        f4293a.add(VIDEO_H263);
        f4293a.add(VIDEO_MP4);
        f4293a.add(APP_SMIL);
        f4293a.add(APP_WAP_XHTML);
        f4293a.add(APP_XHTML);
        f4293a.add(APP_DRM_CONTENT);
        f4293a.add(APP_DRM_MESSAGE);
        f4294b.add(IMAGE_JPEG);
        f4294b.add(IMAGE_GIF);
        f4294b.add(IMAGE_WBMP);
        f4294b.add(IMAGE_PNG);
        f4294b.add(IMAGE_JPG);
        f4295c.add(AUDIO_AAC);
        f4295c.add(AUDIO_AMR);
        f4295c.add(AUDIO_IMELODY);
        f4295c.add(AUDIO_MID);
        f4295c.add(AUDIO_MIDI);
        f4295c.add(AUDIO_MP3);
        f4295c.add(AUDIO_MPEG3);
        f4295c.add(AUDIO_MPEG);
        f4295c.add(AUDIO_MPG);
        f4295c.add(AUDIO_MP4);
        f4295c.add(AUDIO_X_MID);
        f4295c.add(AUDIO_X_MIDI);
        f4295c.add(AUDIO_X_MP3);
        f4295c.add(AUDIO_X_MPEG3);
        f4295c.add(AUDIO_X_MPEG);
        f4295c.add(AUDIO_X_MPG);
        f4295c.add(AUDIO_3GPP);
        f4295c.add(AUDIO_OGG);
        f4296d.add(VIDEO_3GPP);
        f4296d.add(VIDEO_3G2);
        f4296d.add(VIDEO_H263);
        f4296d.add(VIDEO_MP4);
    }

    private ContentType() {
    }

    public static boolean isSupportedType(String contentType) {
        return contentType != null && f4293a.contains(contentType);
    }

    public static boolean isSupportedImageType(String contentType) {
        return isImageType(contentType) && isSupportedType(contentType);
    }

    public static boolean isSupportedAudioType(String contentType) {
        return isAudioType(contentType) && isSupportedType(contentType);
    }

    public static boolean isSupportedVideoType(String contentType) {
        return isVideoType(contentType) && isSupportedType(contentType);
    }

    public static boolean isTextType(String contentType) {
        return contentType != null && contentType.startsWith("text/");
    }

    public static boolean isImageType(String contentType) {
        return contentType != null && contentType.startsWith("image/");
    }

    public static boolean isAudioType(String contentType) {
        return contentType != null && contentType.startsWith("audio/");
    }

    public static boolean isVideoType(String contentType) {
        return contentType != null && contentType.startsWith("video/");
    }

    public static boolean isDrmType(String contentType) {
        return contentType != null && (contentType.equals(APP_DRM_CONTENT) || contentType.equals(APP_DRM_MESSAGE));
    }

    public static boolean isUnspecified(String contentType) {
        return contentType != null && contentType.endsWith(CharacterSets.MIMENAME_ANY_CHARSET);
    }

    public static ArrayList<String> getImageTypes() {
        return (ArrayList) f4294b.clone();
    }

    public static ArrayList<String> getAudioTypes() {
        return (ArrayList) f4295c.clone();
    }

    public static ArrayList<String> getVideoTypes() {
        return (ArrayList) f4296d.clone();
    }

    public static ArrayList<String> getSupportedTypes() {
        return (ArrayList) f4293a.clone();
    }
}
