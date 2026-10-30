package com.lenovo.safecenter.mmsutils;

import android.util.Log;
import com.lenovo.lps.sus.p008c.C0092c;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class TyuEncodedStringValue implements Cloneable {

    /* JADX INFO: renamed from: a */
    private int f4322a;

    /* JADX INFO: renamed from: b */
    private byte[] f4323b;

    public TyuEncodedStringValue(int charset, byte[] data) {
        if (data == null) {
            throw new NullPointerException("EncodedStringValue: Text-string is null.");
        }
        this.f4322a = charset;
        this.f4323b = new byte[data.length];
        System.arraycopy(data, 0, this.f4323b, 0, data.length);
    }

    public TyuEncodedStringValue(byte[] data) {
        this(106, data);
    }

    public TyuEncodedStringValue(String data) {
        try {
            this.f4323b = data.getBytes("utf-8");
            this.f4322a = 106;
        } catch (UnsupportedEncodingException e) {
            Log.e("EncodedStringValue", "Default encoding must be supported.", e);
        }
    }

    public int getCharacterSet() {
        return this.f4322a;
    }

    public void setCharacterSet(int charset) {
        this.f4322a = charset;
    }

    public byte[] getTextString() {
        byte[] byteArray = new byte[this.f4323b.length];
        System.arraycopy(this.f4323b, 0, byteArray, 0, this.f4323b.length);
        return byteArray;
    }

    public void setTextString(byte[] textString) {
        if (textString == null) {
            throw new NullPointerException("EncodedStringValue: Text-string is null.");
        }
        this.f4323b = new byte[textString.length];
        System.arraycopy(textString, 0, this.f4323b, 0, textString.length);
    }

    public String getString() {
        if (this.f4322a == 0) {
            return new String(this.f4323b);
        }
        try {
            String name = CharacterSets.getMimeName(this.f4322a);
            return new String(this.f4323b, name);
        } catch (UnsupportedEncodingException e) {
            try {
                return new String(this.f4323b, CharacterSets.MIMENAME_ISO_8859_1);
            } catch (UnsupportedEncodingException e2) {
                return new String(this.f4323b);
            }
        }
    }

    public void appendTextString(byte[] textString) {
        if (textString == null) {
            throw new NullPointerException("Text-string is null.");
        }
        if (this.f4323b == null) {
            this.f4323b = new byte[textString.length];
            System.arraycopy(textString, 0, this.f4323b, 0, textString.length);
            return;
        }
        ByteArrayOutputStream newTextString = new ByteArrayOutputStream();
        try {
            newTextString.write(this.f4323b);
            newTextString.write(textString);
            this.f4323b = newTextString.toByteArray();
        } catch (IOException e) {
            e.printStackTrace();
            throw new NullPointerException("appendTextString: failed when write a new Text-string");
        }
    }

    public Object clone() throws CloneNotSupportedException {
        super.clone();
        int len = this.f4323b.length;
        byte[] dstBytes = new byte[len];
        System.arraycopy(this.f4323b, 0, dstBytes, 0, len);
        try {
            return new TyuEncodedStringValue(this.f4322a, dstBytes);
        } catch (Exception e) {
            Log.e("EncodedStringValue", "failed to clone an EncodedStringValue: " + this);
            e.printStackTrace();
            throw new CloneNotSupportedException(e.getMessage());
        }
    }

    public TyuEncodedStringValue[] split(String pattern) {
        String[] temp = getString().split(pattern);
        TyuEncodedStringValue[] ret = new TyuEncodedStringValue[temp.length];
        for (int i = 0; i < ret.length; i++) {
            try {
                ret[i] = new TyuEncodedStringValue(this.f4322a, temp[i].getBytes());
            } catch (NullPointerException e) {
                return null;
            }
        }
        return ret;
    }

    public static TyuEncodedStringValue[] extract(String src) {
        String[] values = src.split(C0092c.f1284O);
        ArrayList<TyuEncodedStringValue> list = new ArrayList<>();
        for (int i = 0; i < values.length; i++) {
            if (values[i].length() > 0) {
                list.add(new TyuEncodedStringValue(values[i]));
            }
        }
        int len = list.size();
        if (len > 0) {
            return (TyuEncodedStringValue[]) list.toArray(new TyuEncodedStringValue[len]);
        }
        return null;
    }

    public static String concat(TyuEncodedStringValue[] addr) {
        StringBuilder sb = new StringBuilder();
        int maxIndex = addr.length - 1;
        for (int i = 0; i <= maxIndex; i++) {
            sb.append(addr[i].getString());
            if (i < maxIndex) {
                sb.append(C0092c.f1284O);
            }
        }
        return sb.toString();
    }

    public static TyuEncodedStringValue copy(TyuEncodedStringValue value) {
        if (value == null) {
            return null;
        }
        return new TyuEncodedStringValue(value.f4322a, value.f4323b);
    }

    public static TyuEncodedStringValue[] encodeStrings(String[] array) {
        int count = array.length;
        if (count > 0) {
            TyuEncodedStringValue[] encodedArray = new TyuEncodedStringValue[count];
            for (int i = 0; i < count; i++) {
                encodedArray[i] = new TyuEncodedStringValue(array[i]);
            }
            return encodedArray;
        }
        return null;
    }
}
