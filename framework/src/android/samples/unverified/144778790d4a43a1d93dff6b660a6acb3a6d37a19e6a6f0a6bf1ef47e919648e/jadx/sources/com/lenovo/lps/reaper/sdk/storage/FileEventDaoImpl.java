package com.lenovo.lps.reaper.sdk.storage;

import com.lenovo.lps.reaper.sdk.AnalyticsTracker;
import com.lenovo.lps.reaper.sdk.api.CustomParameter;
import com.lenovo.lps.reaper.sdk.api.Event;
import com.lenovo.lps.reaper.sdk.api.EventDao;
import com.lenovo.lps.reaper.sdk.util.AnalyticsTrackerUtils;
import com.lenovo.lps.reaper.sdk.util.PlusUtil;
import com.lenovo.lps.reaper.sdk.util.TLog;
import java.io.IOException;
import java.nio.BufferOverflowException;
import java.nio.ByteBuffer;
import java.security.SecureRandom;
import java.util.Random;

/* JADX INFO: loaded from: classes.dex */
public class FileEventDaoImpl implements EventDao {

    /* JADX INFO: renamed from: a */
    private FileStorage f1154a;

    /* JADX INFO: renamed from: b */
    private FileStorageMeta f1155b;

    /* JADX INFO: renamed from: c */
    private ByteBuffer f1156c = ByteBuffer.allocate(4096);

    /* JADX INFO: renamed from: d */
    private Random f1157d = new Random(System.currentTimeMillis());

    @Override // com.lenovo.lps.reaper.sdk.api.EventDao
    public void activeSession() {
        try {
            this.f1154a.initialize();
            ByteBuffer metaBuffer = ByteBuffer.allocate(4096);
            this.f1154a.readRecord(metaBuffer);
            long currentTime = System.currentTimeMillis();
            synchronized (this.f1154a) {
                try {
                    if (this.f1155b.load(metaBuffer)) {
                        TLog.m244v("FileEventDaoImpl", "DB load success (in activeSession())");
                        TLog.m244v("FileEventDaoImpl", "sessionID=" + this.f1155b.getSessionId());
                        this.f1155b.setPreviousView(this.f1155b.getCurrentTime());
                        this.f1155b.setCurrentTime(currentTime);
                        this.f1155b.setSessionCounter(this.f1155b.getSessionCounter() + 1);
                    } else {
                        TLog.m244v("FileEventDaoImpl", "DB load false (in activeSession())");
                        this.f1155b.setCurrentTime(currentTime);
                        this.f1155b.setFirstView(currentTime);
                        this.f1155b.setPreviousView(currentTime);
                        this.f1155b.setSessionId(new SecureRandom().nextInt() & Integer.MAX_VALUE);
                        this.f1155b.setSessionCounter(1);
                    }
                    flushMeta();
                } catch (Throwable th) {
                    throw th;
                }
            }
        } catch (Exception e) {
            TLog.m241e("FileEventDaoImpl", "Error when initialize file storage. " + e.getMessage());
        }
    }

    @Override // com.lenovo.lps.reaper.sdk.api.EventDao
    public Event[] getEvents() {
        return getEvents(200);
    }

    @Override // com.lenovo.lps.reaper.sdk.api.EventDao
    public Event[] getEvents(int eventNum) {
        Event[] events;
        try {
            synchronized (this.f1154a) {
                int eveNum = eventNum;
                if (eventNum > this.f1155b.size()) {
                    eveNum = this.f1155b.size();
                }
                events = new Event[eveNum];
                int index = this.f1155b.tail();
                for (int i = 0; i < eveNum; i++) {
                    this.f1154a.position(Long.valueOf((((long) index) * 4096) + 4096));
                    this.f1154a.readRecord(this.f1156c);
                    long id = this.f1156c.getLong();
                    int sessionId = this.f1156c.getInt();
                    String account = m221a(this.f1156c);
                    int randomVal = this.f1156c.getInt();
                    long timestampFirst = this.f1156c.getLong();
                    long timestampPre = this.f1156c.getLong();
                    long timestampCur = this.f1156c.getLong();
                    long timestampEvent = this.f1156c.getLong();
                    int visits = this.f1156c.getInt();
                    String category = m221a(this.f1156c);
                    String action = m221a(this.f1156c);
                    String label = m221a(this.f1156c);
                    int value = this.f1156c.getInt();
                    int networkStatus = this.f1156c.getInt();
                    String userId = m221a(this.f1156c);
                    String userIdClass = m221a(this.f1156c);
                    Event event = new Event(id, sessionId, account, randomVal, timestampFirst, timestampPre, timestampCur, timestampEvent, visits, category, action, label, value, networkStatus, userId, userIdClass);
                    readCustomParameters(this.f1156c, event);
                    index = this.f1155b.next(index);
                    events[i] = event;
                }
                if (TLog.isTestMode()) {
                    TLog.m243i("SendingEvent", "Sending......");
                    for (Event event2 : events) {
                        TLog.m244v("SendingEvent", " ");
                        TLog.m244v("SendingEvent", event2.toStringFull());
                        if (event2.getCustomParameters() != null) {
                            CustomParameter[] arr$ = event2.getCustomParameters();
                            for (CustomParameter param : arr$) {
                                TLog.m240d("SendingEvent", "The Event Param:  [Index]" + param.getIndex() + " [Name]" + param.getName() + " [Value]" + param.getValue());
                            }
                        }
                    }
                }
            }
            return events;
        } catch (Exception ex) {
            TLog.m241e("FileEventDaoImpl", "Error when fetch Event object from storage. " + ex.getMessage());
            return null;
        }
    }

    protected void readCustomParameters(ByteBuffer buf, Event event) {
        int paramNum = buf.getInt();
        if (paramNum > 0 && paramNum <= 5) {
            CustomParameter[] params = new CustomParameter[paramNum];
            for (int i = 0; i < paramNum; i++) {
                params[i] = new CustomParameter(buf.getInt(), m221a(buf), m221a(buf), buf.getInt());
            }
            event.setCustomParameters(params);
        }
    }

    @Override // com.lenovo.lps.reaper.sdk.api.EventDao
    public void saveEvent(Event event) {
        TLog.m244v("FileEventDaoImpl", "SavingEvent.");
        try {
            synchronized (this.f1154a) {
                try {
                    if (this.f1155b.full()) {
                        int tailIndex = this.f1155b.pull();
                        TLog.m240d("FileEventDaoImpl", "Index of " + tailIndex + " has been deleted");
                    }
                    int index = this.f1155b.head();
                    this.f1154a.position(Long.valueOf((((long) index) * 4096) + 4096));
                    this.f1156c.clear();
                    this.f1156c.putLong(this.f1155b.nextId()).putInt(this.f1155b.getSessionId());
                    m222a(this.f1156c, event.getAccount());
                    this.f1156c.putInt(Integer.valueOf(this.f1157d.nextInt(Integer.MAX_VALUE)).intValue()).putLong(this.f1155b.getFirstView()).putLong(this.f1155b.getPreviousView()).putLong(this.f1155b.getCurrentTime()).putLong(event.getTimestampEvent()).putInt(this.f1155b.getSessionCounter());
                    m222a(this.f1156c, event.getCategory());
                    m222a(this.f1156c, event.getAction());
                    m222a(this.f1156c, event.getLabel());
                    this.f1156c.putInt(event.getValue());
                    this.f1156c.putInt(PlusUtil.NetworkStatus.getNetworkStatus());
                    m222a(this.f1156c, AnalyticsTracker.getInstance().getUserId());
                    m222a(this.f1156c, AnalyticsTracker.getInstance().getUserIdClass());
                    m223a(this.f1156c, event.getCustomParameters());
                    this.f1156c.flip();
                    this.f1154a.writeRecord(this.f1156c);
                    this.f1155b.offer();
                    flushMeta();
                } catch (Throwable th) {
                    throw th;
                }
            }
        } catch (BufferOverflowException e) {
            TLog.m241e("FileEventDaoImpl", "Event Infomation is Too Long Than " + this.f1156c.capacity());
        } catch (Exception ex) {
            TLog.m241e("FileEventDaoImpl", "Error when save Event object to storage. " + ex.getClass() + ", " + ex.getMessage());
        }
    }

    /* JADX INFO: renamed from: a */
    private static void m223a(ByteBuffer buf, CustomParameter[] customParameters) {
        if (customParameters != null && customParameters.length > 0) {
            buf.putInt(customParameters.length);
            for (CustomParameter param : customParameters) {
                buf.putInt(param.getIndex());
                m222a(buf, param.getName());
                m222a(buf, param.getValue());
                buf.putInt(param.getScope());
            }
            return;
        }
        buf.putInt(0);
    }

    protected void flushMeta() throws IOException {
        this.f1154a.position(0L);
        ByteBuffer metaBuffer = this.f1155b.byteBuffer();
        this.f1154a.writeRecord(metaBuffer);
        this.f1154a.flush();
    }

    /* JADX INFO: renamed from: a */
    private static void m222a(ByteBuffer buf, String str) {
        if (str == null) {
            buf.putInt(-1);
            return;
        }
        byte[] bytes = str.getBytes();
        buf.putInt(bytes.length);
        buf.put(bytes);
    }

    /* JADX INFO: renamed from: a */
    private static String m221a(ByteBuffer buf) {
        int size = buf.getInt();
        if (size == -1 || size > 4096) {
            return null;
        }
        byte[] bytes = new byte[size];
        buf.get(bytes);
        return new String(bytes);
    }

    @Override // com.lenovo.lps.reaper.sdk.api.EventDao
    public int countEvent() {
        return this.f1155b.size();
    }

    @Override // com.lenovo.lps.reaper.sdk.api.EventDao
    public boolean deleteEvents(Event[] events) {
        AnalyticsTrackerUtils.push("deleteEvents");
        try {
            synchronized (this.f1154a) {
                if (events != null) {
                    for (int i = 0; i < events.length; i++) {
                        try {
                            this.f1155b.pull();
                        } catch (Throwable th) {
                            throw th;
                        }
                    }
                }
                flushMeta();
            }
            return true;
        } catch (IOException e) {
            TLog.m241e("FileEventDaoImpl", "Error when delete events. " + e.getMessage());
            return false;
        } finally {
            AnalyticsTrackerUtils.pop();
        }
    }

    public void setFileStorage(FileStorage fileStorage) {
        this.f1154a = fileStorage;
    }

    public void setMeta(FileStorageMeta meta) {
        this.f1155b = meta;
    }

    @Override // com.lenovo.lps.reaper.sdk.api.EventDao
    public void truncate(long size) {
        try {
            this.f1154a.truncate(size);
        } catch (IOException e) {
            TLog.m241e("FileEventDaoImpl", "Error when truncate storage file. " + e.getMessage());
        }
    }
}
