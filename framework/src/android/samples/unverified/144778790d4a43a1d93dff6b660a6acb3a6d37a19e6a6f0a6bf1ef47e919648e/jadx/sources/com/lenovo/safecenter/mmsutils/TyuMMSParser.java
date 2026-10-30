package com.lenovo.safecenter.mmsutils;

import android.util.Log;
import com.lenovo.lps.sus.p008c.C0092c;
import com.tencent.tmsecure.module.wupsession.WupConfig;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;
import java.util.HashMap;
import org.apache.commons.httpclient.cookie.CookieSpec;

/* JADX INFO: loaded from: classes.dex */
public class TyuMMSParser {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f4329a;

    /* JADX INFO: renamed from: e */
    private static byte[] f4330e;

    /* JADX INFO: renamed from: f */
    private static byte[] f4331f;

    /* JADX INFO: renamed from: b */
    private ByteArrayInputStream f4332b;

    /* JADX INFO: renamed from: c */
    private TyuMMSHeaders f4333c = null;

    /* JADX INFO: renamed from: d */
    private TyuPduBody f4334d = null;

    static {
        f4329a = !TyuMMSParser.class.desiredAssertionStatus();
        f4330e = null;
        f4331f = null;
    }

    public TyuMMSParser(byte[] pduDataStream) {
        this.f4332b = null;
        this.f4332b = new ByteArrayInputStream(pduDataStream);
    }

    public GenericPdu parse() {
        if (this.f4332b == null) {
            return null;
        }
        this.f4333c = m1769a(this.f4332b);
        if (this.f4333c == null) {
            return null;
        }
        int messageType = this.f4333c.getOctet(140);
        if (!checkMandatoryHeader(this.f4333c)) {
            return null;
        }
        if (128 == messageType || 132 == messageType) {
            this.f4334d = parseParts(this.f4332b);
            if (this.f4334d == null) {
                return null;
            }
        }
        switch (messageType) {
            case 128:
                return new SendReq(this.f4333c, this.f4334d);
            case 129:
                SendConf sendConf = new SendConf(this.f4333c);
                return sendConf;
            case 130:
                NotificationInd notificationInd = new NotificationInd(this.f4333c);
                return notificationInd;
            case 131:
                NotifyRespInd notifyRespInd = new NotifyRespInd(this.f4333c);
                return notifyRespInd;
            case 132:
                RetrieveConf retrieveConf = new RetrieveConf(this.f4333c, this.f4334d);
                byte[] contentType = retrieveConf.getContentType();
                if (contentType == null) {
                    return null;
                }
                String ctTypeStr = new String(contentType);
                if (ctTypeStr.equals(ContentType.MULTIPART_MIXED) || ctTypeStr.equals(ContentType.MULTIPART_RELATED) || ctTypeStr.equals(ContentType.MULTIPART_ALTERNATIVE)) {
                    return retrieveConf;
                }
                return null;
            case 133:
                AcknowledgeInd acknowledgeInd = new AcknowledgeInd(this.f4333c);
                return acknowledgeInd;
            case 134:
                DeliveryInd deliveryInd = new DeliveryInd(this.f4333c);
                return deliveryInd;
            case 135:
                ReadRecInd readRecInd = new ReadRecInd(this.f4333c);
                return readRecInd;
            case 136:
                ReadOrigInd readOrigInd = new ReadOrigInd(this.f4333c);
                return readOrigInd;
            default:
                return null;
        }
    }

    /* JADX INFO: renamed from: a */
    private static TyuMMSHeaders m1769a(ByteArrayInputStream pduDataStream) {
        TyuEncodedStringValue from;
        byte[] address;
        if (pduDataStream == null) {
            return null;
        }
        boolean keepParsing = true;
        TyuMMSHeaders headers = new TyuMMSHeaders();
        while (keepParsing && pduDataStream.available() > 0) {
            pduDataStream.mark(1);
            int headerField = extractByteValue(pduDataStream);
            if (headerField >= 32 && headerField <= 127) {
                pduDataStream.reset();
                parseWapString(pduDataStream, 0);
            } else {
                switch (headerField) {
                    case 129:
                    case 130:
                    case 151:
                        TyuEncodedStringValue value = m1770b(pduDataStream);
                        if (value == null) {
                            continue;
                        } else {
                            byte[] address2 = value.getTextString();
                            if (address2 != null) {
                                String str = new String(address2);
                                int endIndex = str.indexOf(CookieSpec.PATH_DELIM);
                                if (endIndex > 0) {
                                    str = str.substring(0, endIndex);
                                }
                                try {
                                    value.setTextString(str.getBytes());
                                } catch (NullPointerException e) {
                                    return null;
                                }
                            }
                            try {
                                headers.appendEncodedStringValue(value, headerField);
                            } catch (NullPointerException e2) {
                            } catch (RuntimeException e3) {
                                String str2 = headerField + "is not Encoded-String-Value header field!";
                                return null;
                            }
                        }
                        break;
                    case 131:
                    case 139:
                    case 152:
                    case TyuMMSHeaders.REPLY_CHARGING_ID /* 158 */:
                    case TyuMMSHeaders.APPLIC_ID /* 183 */:
                    case TyuMMSHeaders.REPLY_APPLIC_ID /* 184 */:
                    case TyuMMSHeaders.AUX_APPLIC_ID /* 185 */:
                    case TyuMMSHeaders.REPLACE_ID /* 189 */:
                    case 190:
                        byte[] value2 = parseWapString(pduDataStream, 0);
                        if (value2 != null) {
                            try {
                                headers.setTextString(value2, headerField);
                            } catch (NullPointerException e4) {
                            } catch (RuntimeException e5) {
                                String str3 = headerField + "is not Text-String header field!";
                                return null;
                            }
                        }
                        break;
                    case 132:
                        HashMap<Integer, Object> map = new HashMap<>();
                        byte[] contentType = parseContentType(pduDataStream, map);
                        if (contentType != null) {
                            try {
                                headers.setTextString(contentType, 132);
                                break;
                            } catch (NullPointerException e6) {
                            } catch (RuntimeException e7) {
                                String str4 = headerField + "is not Text-String header field!";
                                return null;
                            }
                        }
                        f4331f = (byte[]) map.get(153);
                        f4330e = (byte[]) map.get(131);
                        keepParsing = false;
                        break;
                    case 133:
                    case 142:
                    case TyuMMSHeaders.REPLY_CHARGING_SIZE /* 159 */:
                        try {
                            headers.setLongInteger(parseLongInteger(pduDataStream), headerField);
                        } catch (RuntimeException e8) {
                            String str5 = headerField + "is not Long-Integer header field!";
                            return null;
                        }
                        break;
                    case 134:
                    case 143:
                    case 144:
                    case 145:
                    case 146:
                    case 148:
                    case 149:
                    case 153:
                    case 155:
                    case 156:
                    case TyuMMSHeaders.STORE /* 162 */:
                    case TyuMMSHeaders.MM_STATE /* 163 */:
                    case TyuMMSHeaders.STORE_STATUS /* 165 */:
                    case TyuMMSHeaders.STORED /* 167 */:
                    case TyuMMSHeaders.TOTALS /* 169 */:
                    case TyuMMSHeaders.QUOTAS /* 171 */:
                    case TyuMMSHeaders.DISTRIBUTION_INDICATOR /* 177 */:
                    case TyuMMSHeaders.RECOMMENDED_RETRIEVAL_MODE /* 180 */:
                    case TyuMMSHeaders.CONTENT_CLASS /* 186 */:
                    case TyuMMSHeaders.DRM_CONTENT /* 187 */:
                    case TyuMMSHeaders.ADAPTATION_ALLOWED /* 188 */:
                    case 191:
                        int value3 = extractByteValue(pduDataStream);
                        try {
                            headers.setOctet(value3, headerField);
                        } catch (InvalidHeaderValueException e9) {
                            String str6 = "Set invalid Octet value: " + value3 + " into the header filed: " + headerField;
                            return null;
                        } catch (RuntimeException e10) {
                            String str7 = headerField + "is not Octet header field!";
                            return null;
                        }
                        break;
                    case 135:
                    case 136:
                    case 157:
                        parseValueLength(pduDataStream);
                        int token = extractByteValue(pduDataStream);
                        try {
                            long timeValue = parseLongInteger(pduDataStream);
                            if (129 == token) {
                                timeValue += System.currentTimeMillis() / 1000;
                            }
                            try {
                                headers.setLongInteger(timeValue, headerField);
                            } catch (RuntimeException e11) {
                                String str8 = headerField + "is not Long-Integer header field!";
                                return null;
                            }
                        } catch (RuntimeException e12) {
                            String str9 = headerField + "is not Long-Integer header field!";
                            return null;
                        }
                        break;
                    case 137:
                        parseValueLength(pduDataStream);
                        int fromToken = extractByteValue(pduDataStream);
                        if (128 == fromToken) {
                            from = m1770b(pduDataStream);
                            if (from != null && (address = from.getTextString()) != null) {
                                String str10 = new String(address);
                                int endIndex2 = str10.indexOf(CookieSpec.PATH_DELIM);
                                if (endIndex2 > 0) {
                                    str10 = str10.substring(0, endIndex2);
                                }
                                try {
                                    from.setTextString(str10.getBytes());
                                } catch (NullPointerException e13) {
                                    return null;
                                }
                            }
                        } else {
                            try {
                                from = new TyuEncodedStringValue(TyuMMSHeaders.FROM_INSERT_ADDRESS_TOKEN_STR.getBytes());
                            } catch (NullPointerException e14) {
                                String str11 = headerField + "is not Encoded-String-Value header field!";
                                return null;
                            }
                        }
                        try {
                            headers.setEncodedStringValue(from, 137);
                        } catch (NullPointerException e15) {
                        } catch (RuntimeException e16) {
                            String str12 = headerField + "is not Encoded-String-Value header field!";
                            return null;
                        }
                        break;
                    case 138:
                        pduDataStream.mark(1);
                        int messageClass = extractByteValue(pduDataStream);
                        if (messageClass >= 128) {
                            if (128 == messageClass) {
                                try {
                                    headers.setTextString(TyuMMSHeaders.MESSAGE_CLASS_PERSONAL_STR.getBytes(), 138);
                                } catch (NullPointerException e17) {
                                } catch (RuntimeException e18) {
                                    String str13 = headerField + "is not Text-String header field!";
                                    return null;
                                }
                            } else if (129 == messageClass) {
                                headers.setTextString(TyuMMSHeaders.MESSAGE_CLASS_ADVERTISEMENT_STR.getBytes(), 138);
                            } else if (130 == messageClass) {
                                headers.setTextString(TyuMMSHeaders.MESSAGE_CLASS_INFORMATIONAL_STR.getBytes(), 138);
                            } else if (131 == messageClass) {
                                headers.setTextString(TyuMMSHeaders.MESSAGE_CLASS_AUTO_STR.getBytes(), 138);
                            }
                        } else {
                            pduDataStream.reset();
                            byte[] messageClassString = parseWapString(pduDataStream, 0);
                            if (messageClassString != null) {
                                try {
                                    headers.setTextString(messageClassString, 138);
                                } catch (NullPointerException e19) {
                                } catch (RuntimeException e20) {
                                    String str14 = headerField + "is not Text-String header field!";
                                    return null;
                                }
                            }
                        }
                        break;
                    case 140:
                        int messageType = extractByteValue(pduDataStream);
                        switch (messageType) {
                            case 137:
                            case 138:
                            case 139:
                            case 140:
                            case 141:
                            case 142:
                            case 143:
                            case 144:
                            case 145:
                            case 146:
                            case 147:
                            case 148:
                            case 149:
                            case 150:
                            case 151:
                                return null;
                            default:
                                try {
                                    headers.setOctet(messageType, headerField);
                                } catch (InvalidHeaderValueException e21) {
                                    String str15 = "Set invalid Octet value: " + messageType + " into the header filed: " + headerField;
                                    return null;
                                } catch (RuntimeException e22) {
                                    String str16 = headerField + "is not Octet header field!";
                                    return null;
                                }
                                break;
                        }
                        break;
                    case 141:
                        int version = parseShortInteger(pduDataStream);
                        try {
                            headers.setOctet(version, 141);
                        } catch (InvalidHeaderValueException e23) {
                            String str17 = "Set invalid Octet value: " + version + " into the header filed: " + headerField;
                            return null;
                        } catch (RuntimeException e24) {
                            String str18 = headerField + "is not Octet header field!";
                            return null;
                        }
                        break;
                    case 147:
                    case 150:
                    case 154:
                    case TyuMMSHeaders.STORE_STATUS_TEXT /* 166 */:
                    case TyuMMSHeaders.RECOMMENDED_RETRIEVAL_MODE_TEXT /* 181 */:
                    case TyuMMSHeaders.STATUS_TEXT /* 182 */:
                        TyuEncodedStringValue value4 = m1770b(pduDataStream);
                        if (value4 != null) {
                            try {
                                headers.setEncodedStringValue(value4, headerField);
                            } catch (NullPointerException e25) {
                            } catch (RuntimeException e26) {
                                String str19 = headerField + "is not Encoded-String-Value header field!";
                                return null;
                            }
                        }
                        break;
                    case TyuMMSHeaders.PREVIOUSLY_SENT_BY /* 160 */:
                        parseValueLength(pduDataStream);
                        try {
                            parseIntegerValue(pduDataStream);
                            TyuEncodedStringValue previouslySentBy = m1770b(pduDataStream);
                            if (previouslySentBy != null) {
                                try {
                                    headers.setEncodedStringValue(previouslySentBy, TyuMMSHeaders.PREVIOUSLY_SENT_BY);
                                } catch (NullPointerException e27) {
                                } catch (RuntimeException e28) {
                                    String str20 = headerField + "is not Encoded-String-Value header field!";
                                    return null;
                                }
                            }
                        } catch (RuntimeException e29) {
                            String str21 = headerField + " is not Integer-Value";
                            return null;
                        }
                        break;
                    case TyuMMSHeaders.PREVIOUSLY_SENT_DATE /* 161 */:
                        parseValueLength(pduDataStream);
                        try {
                            parseIntegerValue(pduDataStream);
                            try {
                                long perviouslySentDate = parseLongInteger(pduDataStream);
                                headers.setLongInteger(perviouslySentDate, TyuMMSHeaders.PREVIOUSLY_SENT_DATE);
                            } catch (RuntimeException e30) {
                                String str22 = headerField + "is not Long-Integer header field!";
                                return null;
                            }
                        } catch (RuntimeException e31) {
                            String str23 = headerField + " is not Integer-Value";
                            return null;
                        }
                        break;
                    case TyuMMSHeaders.MM_FLAGS /* 164 */:
                        parseValueLength(pduDataStream);
                        extractByteValue(pduDataStream);
                        m1770b(pduDataStream);
                        break;
                    case 170:
                    case TyuMMSHeaders.MBOX_QUOTAS /* 172 */:
                        parseValueLength(pduDataStream);
                        extractByteValue(pduDataStream);
                        try {
                            parseIntegerValue(pduDataStream);
                        } catch (RuntimeException e32) {
                            String str24 = headerField + " is not Integer-Value";
                            return null;
                        }
                        break;
                    case TyuMMSHeaders.MESSAGE_COUNT /* 173 */:
                    case TyuMMSHeaders.START /* 175 */:
                    case TyuMMSHeaders.LIMIT /* 179 */:
                        try {
                            headers.setLongInteger(parseIntegerValue(pduDataStream), headerField);
                        } catch (RuntimeException e33) {
                            String str25 = headerField + "is not Long-Integer header field!";
                            return null;
                        }
                        break;
                    case TyuMMSHeaders.ELEMENT_DESCRIPTOR /* 178 */:
                        parseContentType(pduDataStream, null);
                        break;
                }
            }
        }
        return headers;
    }

    protected static byte[] parseContentType(ByteArrayInputStream pduDataStream, HashMap<Integer, Object> map) {
        byte[] contentType;
        if (!f4329a && pduDataStream == null) {
            throw new AssertionError();
        }
        pduDataStream.mark(1);
        int temp = pduDataStream.read();
        if (!f4329a && -1 == temp) {
            throw new AssertionError();
        }
        pduDataStream.reset();
        int cur = temp & 255;
        if (cur < 32) {
            int length = parseValueLength(pduDataStream);
            int startPos = pduDataStream.available();
            pduDataStream.mark(1);
            int temp2 = pduDataStream.read();
            if (!f4329a && -1 == temp2) {
                throw new AssertionError();
            }
            pduDataStream.reset();
            int first = temp2 & 255;
            if (first >= 32 && first <= 127) {
                contentType = parseWapString(pduDataStream, 0);
            } else if (first > 127) {
                int index = parseShortInteger(pduDataStream);
                if (index < PduContentTypes.f4313a.length) {
                    contentType = PduContentTypes.f4313a[index].getBytes();
                } else {
                    pduDataStream.reset();
                    contentType = parseWapString(pduDataStream, 0);
                }
            } else {
                Log.e("PduParser", "Corrupt content-type");
                byte[] contentType2 = PduContentTypes.f4313a[0].getBytes();
                return contentType2;
            }
            int endPos = pduDataStream.available();
            int parameterLen = length - (startPos - endPos);
            if (parameterLen > 0) {
                parseContentTypeParams(pduDataStream, map, Integer.valueOf(parameterLen));
            }
            if (parameterLen < 0) {
                Log.e("PduParser", "Corrupt MMS message");
                byte[] contentType3 = PduContentTypes.f4313a[0].getBytes();
                return contentType3;
            }
            return contentType;
        }
        if (cur <= 127) {
            byte[] contentType4 = parseWapString(pduDataStream, 0);
            return contentType4;
        }
        byte[] contentType5 = PduContentTypes.f4313a[parseShortInteger(pduDataStream)].getBytes();
        return contentType5;
    }

    protected static void parseContentTypeParams(ByteArrayInputStream pduDataStream, HashMap<Integer, Object> map, Integer length) {
        if (!f4329a && pduDataStream == null) {
            throw new AssertionError();
        }
        if (!f4329a && length.intValue() <= 0) {
            throw new AssertionError();
        }
        int startPos = pduDataStream.available();
        int lastLen = length.intValue();
        while (lastLen > 0) {
            int param = pduDataStream.read();
            if (!f4329a && -1 == param) {
                throw new AssertionError();
            }
            lastLen--;
            switch (param) {
                case 129:
                    pduDataStream.mark(1);
                    int firstValue = extractByteValue(pduDataStream);
                    pduDataStream.reset();
                    if ((firstValue > 32 && firstValue < 127) || firstValue == 0) {
                        byte[] charsetStr = parseWapString(pduDataStream, 0);
                        try {
                            int charsetInt = CharacterSets.getMibEnumValue(new String(charsetStr));
                            map.put(129, Integer.valueOf(charsetInt));
                        } catch (UnsupportedEncodingException e) {
                            Log.e("PduParser", Arrays.toString(charsetStr), e);
                            map.put(129, 0);
                        }
                    } else {
                        int charset = (int) parseIntegerValue(pduDataStream);
                        if (map != null) {
                            map.put(129, Integer.valueOf(charset));
                        }
                    }
                    int tempPos = pduDataStream.available();
                    lastLen = length.intValue() - (startPos - tempPos);
                    break;
                case 131:
                case 137:
                    pduDataStream.mark(1);
                    int first = extractByteValue(pduDataStream);
                    pduDataStream.reset();
                    if (first > 127) {
                        int index = parseShortInteger(pduDataStream);
                        if (index < PduContentTypes.f4313a.length) {
                            map.put(131, PduContentTypes.f4313a[index].getBytes());
                        }
                    } else {
                        byte[] type = parseWapString(pduDataStream, 0);
                        if (type != null && map != null) {
                            map.put(131, type);
                        }
                    }
                    int tempPos2 = pduDataStream.available();
                    lastLen = length.intValue() - (startPos - tempPos2);
                    break;
                case 133:
                case 151:
                    byte[] name = parseWapString(pduDataStream, 0);
                    if (name != null && map != null) {
                        map.put(151, name);
                    }
                    int tempPos3 = pduDataStream.available();
                    lastLen = length.intValue() - (startPos - tempPos3);
                    break;
                case 138:
                case 153:
                    byte[] start = parseWapString(pduDataStream, 0);
                    if (start != null && map != null) {
                        map.put(153, start);
                    }
                    int tempPos4 = pduDataStream.available();
                    lastLen = length.intValue() - (startPos - tempPos4);
                    break;
                default:
                    if (-1 == skipWapValue(pduDataStream, lastLen)) {
                        Log.e("PduParser", "Corrupt Content-Type");
                    } else {
                        lastLen = 0;
                    }
                    break;
            }
        }
        if (lastLen != 0) {
            Log.e("PduParser", "Corrupt Content-Type");
        }
    }

    protected static int skipWapValue(ByteArrayInputStream pduDataStream, int length) {
        if (!f4329a && pduDataStream == null) {
            throw new AssertionError();
        }
        byte[] area = new byte[length];
        int readLen = pduDataStream.read(area, 0, length);
        if (readLen < length) {
            return -1;
        }
        return readLen;
    }

    protected static int parseShortInteger(ByteArrayInputStream pduDataStream) {
        if (!f4329a && pduDataStream == null) {
            throw new AssertionError();
        }
        int temp = pduDataStream.read();
        if (f4329a || -1 != temp) {
            return temp & 127;
        }
        throw new AssertionError();
    }

    protected static int parseValueLength(ByteArrayInputStream pduDataStream) {
        if (!f4329a && pduDataStream == null) {
            throw new AssertionError();
        }
        int temp = pduDataStream.read();
        if (!f4329a && -1 == temp) {
            throw new AssertionError();
        }
        int first = temp & 255;
        if (first > 30) {
            if (first == 31) {
                return parseUnsignedInt(pduDataStream);
            }
            throw new RuntimeException("Value length > LENGTH_QUOTE!");
        }
        return first;
    }

    protected static int parseUnsignedInt(ByteArrayInputStream pduDataStream) {
        if (!f4329a && pduDataStream == null) {
            throw new AssertionError();
        }
        int result = 0;
        int temp = pduDataStream.read();
        if (temp == -1) {
            return temp;
        }
        while ((temp & 128) != 0) {
            result = (result << 7) | (temp & 127);
            temp = pduDataStream.read();
            if (temp == -1) {
                return temp;
            }
        }
        return (result << 7) | (temp & 127);
    }

    /* JADX INFO: renamed from: b */
    private static TyuEncodedStringValue m1770b(ByteArrayInputStream pduDataStream) {
        TyuEncodedStringValue returnValue;
        if (!f4329a && pduDataStream == null) {
            throw new AssertionError();
        }
        pduDataStream.mark(1);
        int charset = 0;
        int temp = pduDataStream.read();
        if (!f4329a && -1 == temp) {
            throw new AssertionError();
        }
        int first = temp & 255;
        pduDataStream.reset();
        if (first < 32) {
            parseValueLength(pduDataStream);
            charset = parseShortInteger(pduDataStream);
        }
        byte[] textString = parseWapString(pduDataStream, 0);
        try {
            if (charset != 0) {
                TyuEncodedStringValue returnValue2 = new TyuEncodedStringValue(charset, textString);
                returnValue = returnValue2;
            } else {
                TyuEncodedStringValue returnValue3 = new TyuEncodedStringValue(textString);
                returnValue = returnValue3;
            }
            return returnValue;
        } catch (Exception e) {
            return null;
        }
    }

    protected static long parseIntegerValue(ByteArrayInputStream pduDataStream) {
        if (!f4329a && pduDataStream == null) {
            throw new AssertionError();
        }
        pduDataStream.mark(1);
        int temp = pduDataStream.read();
        if (!f4329a && -1 == temp) {
            throw new AssertionError();
        }
        pduDataStream.reset();
        return temp > 127 ? parseShortInteger(pduDataStream) : parseLongInteger(pduDataStream);
    }

    protected static long parseLongInteger(ByteArrayInputStream pduDataStream) {
        if (!f4329a && pduDataStream == null) {
            throw new AssertionError();
        }
        int temp = pduDataStream.read();
        if (!f4329a && -1 == temp) {
            throw new AssertionError();
        }
        int count = temp & 255;
        if (count > 8) {
            throw new RuntimeException("Octet count greater than 8 and I can't represent that!");
        }
        long result = 0;
        for (int i = 0; i < count; i++) {
            int temp2 = pduDataStream.read();
            if (!f4329a && -1 == temp2) {
                throw new AssertionError();
            }
            result = (result << 8) + ((long) (temp2 & 255));
        }
        return result;
    }

    protected static byte[] parseWapString(ByteArrayInputStream pduDataStream, int stringType) {
        if (!f4329a && pduDataStream == null) {
            throw new AssertionError();
        }
        pduDataStream.mark(1);
        int temp = pduDataStream.read();
        if (!f4329a && -1 == temp) {
            throw new AssertionError();
        }
        if (1 == stringType && 34 == temp) {
            pduDataStream.mark(1);
        } else if (stringType == 0 && 127 == temp) {
            pduDataStream.mark(1);
        } else {
            pduDataStream.reset();
        }
        return getWapString(pduDataStream, stringType);
    }

    protected static byte[] getWapString(ByteArrayInputStream pduDataStream, int stringType) {
        if (!f4329a && pduDataStream == null) {
            throw new AssertionError();
        }
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        int temp = pduDataStream.read();
        if (!f4329a && -1 == temp) {
            throw new AssertionError();
        }
        while (-1 != temp && temp != 0) {
            if (stringType == 2) {
                if (isTokenCharacter(temp)) {
                    out.write(temp);
                }
            } else if (isText(temp)) {
                out.write(temp);
            }
            temp = pduDataStream.read();
            if (!f4329a && -1 == temp) {
                throw new AssertionError();
            }
        }
        if (out.size() > 0) {
            return out.toByteArray();
        }
        return null;
    }

    protected static boolean isText(int ch) {
        if (ch >= 32 && ch <= 126) {
            return true;
        }
        if (ch >= 128 && ch <= 255) {
            return true;
        }
        switch (ch) {
            case 9:
            case 10:
            case 13:
                return true;
            case 11:
            case 12:
            default:
                return false;
        }
    }

    protected static boolean isTokenCharacter(int ch) {
        if (ch < 33 || ch > 126) {
            return false;
        }
        switch (ch) {
            case WupConfig.RQ_GET_TRAFFIC_CMD /* 34 */:
            case WupConfig.RQ_GET_MARK /* 40 */:
            case 41:
            case 44:
            case 47:
            case 58:
            case 59:
            case 60:
            case 61:
            case 62:
            case 63:
            case 64:
            case 91:
            case 92:
            case C0092c.f1303aG /* 93 */:
            case 123:
            case 125:
                return false;
            default:
                return true;
        }
    }

    protected static int extractByteValue(ByteArrayInputStream pduDataStream) {
        if (!f4329a && pduDataStream == null) {
            throw new AssertionError();
        }
        int temp = pduDataStream.read();
        if (f4329a || -1 != temp) {
            return temp & 255;
        }
        throw new AssertionError();
    }

    protected static TyuPduBody parseParts(ByteArrayInputStream pduDataStream) {
        boolean z;
        byte[] contentType;
        byte[] contentId;
        if (pduDataStream == null) {
            return null;
        }
        int count = parseUnsignedInt(pduDataStream);
        TyuPduBody body = new TyuPduBody();
        for (int i = 0; i < count; i++) {
            int headerLength = parseUnsignedInt(pduDataStream);
            int dataLength = parseUnsignedInt(pduDataStream);
            PduPart part = new PduPart();
            int startPos = pduDataStream.available();
            if (startPos <= 0) {
                return null;
            }
            HashMap<Integer, Object> map = new HashMap<>();
            byte[] contentType2 = parseContentType(pduDataStream, map);
            if (contentType2 != null) {
                part.setContentType(contentType2);
            } else {
                part.setContentType(PduContentTypes.f4313a[0].getBytes());
            }
            byte[] name = (byte[]) map.get(151);
            if (name != null) {
                part.setName(name);
            }
            Integer charset = (Integer) map.get(129);
            if (charset != null) {
                part.setCharset(charset.intValue());
            }
            int endPos = pduDataStream.available();
            int partHeaderLen = headerLength - (startPos - endPos);
            if (partHeaderLen > 0) {
                if (!parsePartHeaders(pduDataStream, part, partHeaderLen)) {
                    return null;
                }
            } else if (partHeaderLen < 0) {
                return null;
            }
            if (part.getContentLocation() == null && part.getName() == null && part.getFilename() == null && part.getContentId() == null) {
                part.setContentLocation(Long.toOctalString(System.currentTimeMillis()).getBytes());
            }
            if (dataLength > 0) {
                byte[] partData = new byte[dataLength];
                String partContentType = new String(part.getContentType());
                pduDataStream.read(partData, 0, dataLength);
                if (partContentType.equalsIgnoreCase(ContentType.MULTIPART_ALTERNATIVE)) {
                    TyuPduBody childBody = parseParts(new ByteArrayInputStream(partData));
                    part = childBody.getPart(0);
                } else {
                    byte[] partDataEncoding = part.getContentTransferEncoding();
                    if (partDataEncoding != null) {
                        String encoding = new String(partDataEncoding);
                        if (encoding.equalsIgnoreCase(PduPart.P_BASE64)) {
                            partData = Base64.decodeBase64(partData);
                        } else if (encoding.equalsIgnoreCase(PduPart.P_QUOTED_PRINTABLE)) {
                            partData = QuotedPrintable.decodeQuotedPrintable(partData);
                        }
                    }
                    if (partData == null) {
                        return null;
                    }
                    part.setData(partData);
                }
            }
            if (!f4329a && part == null) {
                throw new AssertionError();
            }
            if (f4330e == null && f4331f == null) {
                z = true;
            } else if (f4331f == null || (contentId = part.getContentId()) == null || true != Arrays.equals(f4331f, contentId)) {
                z = f4330e == null || (contentType = part.getContentType()) == null || true != Arrays.equals(f4330e, contentType);
            } else {
                z = false;
            }
            if (!z) {
                body.addPart(0, part);
            } else {
                body.addPart(part);
            }
        }
        return body;
    }

    protected static boolean parsePartHeaders(ByteArrayInputStream pduDataStream, PduPart part, int length) {
        if (!f4329a && pduDataStream == null) {
            throw new AssertionError();
        }
        if (!f4329a && part == null) {
            throw new AssertionError();
        }
        if (!f4329a && length <= 0) {
            throw new AssertionError();
        }
        int startPos = pduDataStream.available();
        int lastLen = length;
        while (lastLen > 0) {
            int header = pduDataStream.read();
            if (!f4329a && -1 == header) {
                throw new AssertionError();
            }
            int lastLen2 = lastLen - 1;
            if (header > 127) {
                switch (header) {
                    case 142:
                        byte[] contentLocation = parseWapString(pduDataStream, 0);
                        if (contentLocation != null) {
                            part.setContentLocation(contentLocation);
                        }
                        int tempPos = pduDataStream.available();
                        lastLen = length - (startPos - tempPos);
                        break;
                    case 174:
                    case PduPart.P_CONTENT_DISPOSITION /* 197 */:
                        int len = parseValueLength(pduDataStream);
                        pduDataStream.mark(1);
                        int thisStartPos = pduDataStream.available();
                        int value = pduDataStream.read();
                        if (value == 128) {
                            part.setContentDisposition(PduPart.f4314a);
                        } else if (value == 129) {
                            part.setContentDisposition(PduPart.f4315b);
                        } else if (value == 130) {
                            part.setContentDisposition(PduPart.f4316c);
                        } else {
                            pduDataStream.reset();
                            part.setContentDisposition(parseWapString(pduDataStream, 0));
                        }
                        if (thisStartPos - pduDataStream.available() < len) {
                            if (pduDataStream.read() == 152) {
                                part.setFilename(parseWapString(pduDataStream, 0));
                            }
                            int thisEndPos = pduDataStream.available();
                            if (thisStartPos - thisEndPos < len) {
                                int last = len - (thisStartPos - thisEndPos);
                                byte[] temp = new byte[last];
                                pduDataStream.read(temp, 0, last);
                            }
                        }
                        int tempPos2 = pduDataStream.available();
                        lastLen = length - (startPos - tempPos2);
                        break;
                    case 192:
                        byte[] contentId = parseWapString(pduDataStream, 1);
                        if (contentId != null) {
                            part.setContentId(contentId);
                        }
                        int tempPos3 = pduDataStream.available();
                        lastLen = length - (startPos - tempPos3);
                        break;
                    default:
                        if (-1 == skipWapValue(pduDataStream, lastLen2)) {
                            Log.e("PduParser", "Corrupt Part headers");
                            return false;
                        }
                        lastLen = 0;
                        break;
                        break;
                }
            } else if (header >= 32 && header <= 127) {
                byte[] tempHeader = parseWapString(pduDataStream, 0);
                byte[] tempValue = parseWapString(pduDataStream, 0);
                if (true == PduPart.CONTENT_TRANSFER_ENCODING.equalsIgnoreCase(new String(tempHeader))) {
                    part.setContentTransferEncoding(tempValue);
                }
                int tempPos4 = pduDataStream.available();
                lastLen = length - (startPos - tempPos4);
            } else {
                if (-1 == skipWapValue(pduDataStream, lastLen2)) {
                    Log.e("PduParser", "Corrupt Part headers");
                    return false;
                }
                lastLen = 0;
            }
        }
        if (lastLen != 0) {
            Log.e("PduParser", "Corrupt Part headers");
            return false;
        }
        return true;
    }

    /* JADX WARN: Code duplicated, block: B:94:0x01f2 A[RETURN, SYNTHETIC] */
    protected static boolean checkMandatoryHeader(TyuMMSHeaders headers) {
        if (headers == null) {
            return false;
        }
        int messageType = headers.getOctet(140);
        int mmsVersion = headers.getOctet(141);
        if (mmsVersion == 0) {
            return false;
        }
        switch (messageType) {
            case 128:
                byte[] srContentType = headers.getTextString(132);
                if (srContentType == null) {
                    return false;
                }
                TyuEncodedStringValue srFrom = headers.getEncodedStringValue(137);
                if (srFrom == null) {
                    return false;
                }
                byte[] srTransactionId = headers.getTextString(152);
                if (srTransactionId == null) {
                    return false;
                }
                return true;
            case 129:
                int scResponseStatus = headers.getOctet(146);
                if (scResponseStatus == 0) {
                    return false;
                }
                byte[] scTransactionId = headers.getTextString(152);
                if (scTransactionId == null) {
                    return false;
                }
                return true;
            case 130:
                byte[] niContentLocation = headers.getTextString(131);
                if (niContentLocation == null) {
                    return false;
                }
                long niExpiry = headers.getLongInteger(136);
                if (-1 == niExpiry) {
                    return false;
                }
                byte[] niMessageClass = headers.getTextString(138);
                if (niMessageClass == null) {
                    return false;
                }
                long niMessageSize = headers.getLongInteger(142);
                if (-1 == niMessageSize) {
                    return false;
                }
                byte[] niTransactionId = headers.getTextString(152);
                if (niTransactionId == null) {
                    return false;
                }
                return true;
            case 131:
                int nriStatus = headers.getOctet(149);
                if (nriStatus == 0) {
                    return false;
                }
                byte[] nriTransactionId = headers.getTextString(152);
                if (nriTransactionId == null) {
                    return false;
                }
                return true;
            case 132:
                byte[] rcContentType = headers.getTextString(132);
                if (rcContentType == null) {
                    return false;
                }
                long rcDate = headers.getLongInteger(133);
                if (-1 == rcDate) {
                    return false;
                }
                return true;
            case 133:
                byte[] aiTransactionId = headers.getTextString(152);
                if (aiTransactionId == null) {
                    return false;
                }
                return true;
            case 134:
                long diDate = headers.getLongInteger(133);
                if (-1 == diDate) {
                    return false;
                }
                byte[] diMessageId = headers.getTextString(139);
                if (diMessageId == null) {
                    return false;
                }
                int diStatus = headers.getOctet(149);
                if (diStatus == 0) {
                    return false;
                }
                TyuEncodedStringValue[] diTo = headers.getEncodedStringValues(151);
                if (diTo == null) {
                    return false;
                }
                return true;
            case 135:
                TyuEncodedStringValue rrFrom = headers.getEncodedStringValue(137);
                if (rrFrom == null) {
                    return false;
                }
                byte[] rrMessageId = headers.getTextString(139);
                if (rrMessageId == null) {
                    return false;
                }
                int rrReadStatus = headers.getOctet(155);
                if (rrReadStatus == 0) {
                    return false;
                }
                TyuEncodedStringValue[] rrTo = headers.getEncodedStringValues(151);
                if (rrTo == null) {
                    return false;
                }
                return true;
            case 136:
                long roDate = headers.getLongInteger(133);
                if (-1 == roDate) {
                    return false;
                }
                TyuEncodedStringValue roFrom = headers.getEncodedStringValue(137);
                if (roFrom == null) {
                    return false;
                }
                byte[] roMessageId = headers.getTextString(139);
                if (roMessageId == null) {
                    return false;
                }
                int roReadStatus = headers.getOctet(155);
                if (roReadStatus == 0) {
                    return false;
                }
                TyuEncodedStringValue[] roTo = headers.getEncodedStringValues(151);
                if (roTo == null) {
                    return false;
                }
                return true;
            default:
                return false;
        }
    }
}
