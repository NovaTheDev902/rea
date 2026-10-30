package com.tencent.tmsecure.module.aresengine;

import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public interface IKeyWordDao {
    boolean contains(String str);

    ArrayList<String> getAll();

    void setAll(List<String> list);
}
