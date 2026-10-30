package com.lenovo.safecenter.net.correct;

import android.R;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.Spinner;
import android.widget.SpinnerAdapter;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.net.cache.NetCache;
import com.lenovo.safecenter.net.support.SIMDetailInfo;
import com.lenovo.safecenter.net.support.Utils;
import com.lenovo.safecenter.platform.MyMultiSIMUtils;
import com.lenovo.safecenter.support.SecurityService;
import com.lenovo.safecenter.utils.WflUtils;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.aresengine.SmsEntity;
import com.tencent.tmsecure.module.network.CodeName;
import com.tencent.tmsecure.module.network.CorrectionDataInfo;
import com.tencent.tmsecure.module.network.TrafficCorrectionConfig;
import com.tencent.tmsecure.module.network.TrafficCorrectionManager;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class TrafficCorrectSetting extends Activity implements View.OnClickListener {
    public static final String CORRECT = "correct";
    public static final String NEW_VERSION_INITPOSTION_KEY = "new_version_initpostion_key";
    public static final long TIME = 120000;
    public static boolean canCorrect = true;
    public static int cardPostion;
    public static TrafficCorrectionManager mTcMgr;

    /* JADX INFO: renamed from: a */
    private ImageView f4536a;

    /* JADX INFO: renamed from: b */
    private ImageView f4537b;

    /* JADX INFO: renamed from: c */
    private TextView f4538c;

    /* JADX INFO: renamed from: d */
    private TextView f4539d;

    /* JADX INFO: renamed from: e */
    private TextView f4540e;

    /* JADX INFO: renamed from: f */
    private Spinner f4541f;

    /* JADX INFO: renamed from: g */
    private Spinner f4542g;

    /* JADX INFO: renamed from: h */
    private Spinner f4543h;

    /* JADX INFO: renamed from: i */
    private Spinner f4544i;

    /* JADX INFO: renamed from: j */
    private SIMDetailInfo f4545j;

    /* JADX INFO: renamed from: l */
    private Context f4547l;

    /* JADX INFO: renamed from: m */
    private int[] f4548m;

    /* JADX INFO: renamed from: n */
    private int f4549n;

    /* JADX INFO: renamed from: q */
    private String f4552q;

    /* JADX INFO: renamed from: r */
    private String f4553r;

    /* JADX INFO: renamed from: s */
    private SharedPreferences f4554s;

    /* JADX INFO: renamed from: k */
    private ArrayList<String> f4546k = null;

    /* JADX INFO: renamed from: o */
    private boolean f4550o = true;

    /* JADX INFO: renamed from: p */
    private final Handler f4551p = new Handler() { // from class: com.lenovo.safecenter.net.correct.TrafficCorrectSetting.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    Utils.setCanCorrectFlag(TrafficCorrectSetting.this.f4547l, true);
                    Log.i(SecurityService.TAG, "touch here and cancorrect = " + Utils.getCanCorrectFlag(TrafficCorrectSetting.this.f4547l));
                    break;
                case 1:
                    TrafficCorrectSetting.this.finish();
                    break;
            }
        }
    };

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        byte b = 0;
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.net_traffic_correct_settings);
        Intent intent = getIntent();
        cardPostion = intent.getIntExtra("card", 0);
        this.f4549n = intent.getIntExtra("correct_type", 0);
        this.f4547l = this;
        mTcMgr = (TrafficCorrectionManager) ManagerCreator.getManager(TrafficCorrectionManager.class);
        this.f4548m = Utils.initPostion(cardPostion, this);
        this.f4552q = getString(C0415R.string.net_selsect);
        this.f4553r = getString(C0415R.string.net_first_select_provice);
        this.f4536a = (ImageView) findViewById(C0415R.id.title_back);
        this.f4537b = (ImageView) findViewById(C0415R.id.title_set);
        this.f4537b.setVisibility(8);
        this.f4536a.setOnClickListener(this);
        this.f4538c = (TextView) findViewById(C0415R.id.txt_title);
        if (cardPostion == 0) {
            if (this.f4549n == 0) {
                if (Build.VERSION.SDK_INT < 14 || !MyMultiSIMUtils.isMultiSim(this)) {
                    this.f4538c.setText(getString(C0415R.string.net_title3));
                } else {
                    this.f4538c.setText("SIM1" + getString(C0415R.string.net_title3));
                }
            } else if (Build.VERSION.SDK_INT < 14 || !MyMultiSIMUtils.isMultiSim(this)) {
                this.f4538c.setText(getString(C0415R.string.net_title4));
            } else {
                this.f4538c.setText(C0415R.string.net_title1);
            }
        } else if (this.f4549n == 0) {
            if (Build.VERSION.SDK_INT < 14 || !MyMultiSIMUtils.isMultiSim(this)) {
                this.f4538c.setText(getString(C0415R.string.net_title3));
            } else {
                this.f4538c.setText("SIM2" + getString(C0415R.string.net_title3));
            }
        } else if (Build.VERSION.SDK_INT < 14 || !MyMultiSIMUtils.isMultiSim(this)) {
            this.f4538c.setText(getString(C0415R.string.net_title4));
        } else {
            this.f4538c.setText(C0415R.string.net_title2);
        }
        this.f4540e = (TextView) findViewById(C0415R.id.net_cancel);
        this.f4540e.setOnClickListener(this);
        this.f4541f = (Spinner) findViewById(C0415R.id.net_correct_set_provice_editext);
        this.f4542g = (Spinner) findViewById(C0415R.id.net_correct_set_city_editext);
        this.f4543h = (Spinner) findViewById(C0415R.id.net_correct_set_Operators_editext);
        this.f4544i = (Spinner) findViewById(C0415R.id.net_correct_set_Brand_editext);
        this.f4539d = (TextView) findViewById(C0415R.id.net_traffic_correct);
        if (this.f4549n == 0) {
            this.f4539d.setText(C0415R.string.net_start_correct);
        } else {
            this.f4539d.setText(C0415R.string.net_ok);
        }
        this.f4539d.setOnClickListener(this);
        this.f4546k = new ArrayList<>();
        this.f4546k.add(0, getString(C0415R.string.net_operators_m));
        this.f4546k.add(1, getString(C0415R.string.net_operators_u));
        this.f4546k.add(2, getString(C0415R.string.net_operators_cdma));
        ArrayList<String> arrayListM1876a = m1876a(mTcMgr.getAllProvinces());
        arrayListM1876a.add(0, this.f4552q);
        ArrayAdapter arrayAdapter = new ArrayAdapter(this, C0415R.layout.simple_spinner_item, arrayListM1876a);
        arrayAdapter.setDropDownViewResource(R.layout.simple_spinner_dropdown_item);
        this.f4541f.setAdapter((SpinnerAdapter) arrayAdapter);
        this.f4541f.setSelection(m1878b(this.f4548m[0], arrayListM1876a), true);
        this.f4541f.setOnItemSelectedListener(new C0748c());
        TextView textView = (TextView) this.f4541f.getSelectedView();
        ArrayList<String> arrayListM1876a2 = m1876a(mTcMgr.getCities(m1880b(textView.getText().toString())));
        Log.i("testcorrect", "size = " + arrayListM1876a2.size());
        String string = textView.getText().toString();
        if (arrayListM1876a2.size() == 0) {
            arrayListM1876a2.add(string);
        } else if (arrayListM1876a2.size() == 1 && this.f4552q.equals(string)) {
            arrayListM1876a2.set(0, this.f4553r);
        }
        ArrayAdapter arrayAdapter2 = new ArrayAdapter(this.f4547l, C0415R.layout.simple_spinner_item, arrayListM1876a2);
        arrayAdapter2.setDropDownViewResource(R.layout.simple_spinner_dropdown_item);
        this.f4542g.setAdapter((SpinnerAdapter) arrayAdapter2);
        this.f4542g.setSelection(m1878b(this.f4548m[1], arrayListM1876a2), true);
        this.f4542g.setOnItemSelectedListener(new C0746a(this, b));
        ArrayAdapter arrayAdapter3 = new ArrayAdapter(this, C0415R.layout.simple_spinner_item, this.f4546k);
        arrayAdapter3.setDropDownViewResource(R.layout.simple_spinner_dropdown_item);
        this.f4543h.setAdapter((SpinnerAdapter) arrayAdapter3);
        this.f4543h.setSelection(m1878b(this.f4548m[2], this.f4546k));
        this.f4543h.setOnItemSelectedListener(new C0747b());
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.net.correct.TrafficCorrectSetting$c */
    private final class C0748c implements AdapterView.OnItemSelectedListener {

        /* JADX INFO: renamed from: b */
        private int f4561b = 0;

        public C0748c() {
        }

        @Override // android.widget.AdapterView.OnItemSelectedListener
        public final void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
            TextView province = (TextView) view;
            String proviceString = province.getText().toString();
            TrafficCorrectionManager trafficCorrectionManager = TrafficCorrectSetting.mTcMgr;
            TrafficCorrectSetting trafficCorrectSetting = TrafficCorrectSetting.this;
            ArrayList<CodeName> cityLists = trafficCorrectionManager.getCities(TrafficCorrectSetting.m1880b(province.getText().toString()));
            ArrayList<String> cityList = TrafficCorrectSetting.this.m1876a(cityLists);
            if (cityList.size() != 0) {
                if (TrafficCorrectSetting.this.f4552q.equals(proviceString)) {
                    cityList.set(0, TrafficCorrectSetting.this.f4553r);
                    Log.i("testcorrect", "~~~size = " + cityList.size());
                }
            } else {
                cityList.add(proviceString);
            }
            ArrayAdapter<String> cityAdapter = new ArrayAdapter<>(TrafficCorrectSetting.this.f4547l, C0415R.layout.simple_spinner_item, cityList);
            cityAdapter.setDropDownViewResource(R.layout.simple_spinner_dropdown_item);
            if (this.f4561b == 0) {
                TrafficCorrectSetting.this.f4542g.setAdapter((SpinnerAdapter) cityAdapter);
                TrafficCorrectSetting.this.f4542g.setSelection(0, true);
            }
        }

        @Override // android.widget.AdapterView.OnItemSelectedListener
        public final void onNothingSelected(AdapterView<?> parent) {
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.net.correct.TrafficCorrectSetting$a */
    private final class C0746a implements AdapterView.OnItemSelectedListener {
        private C0746a() {
        }

        /* synthetic */ C0746a(TrafficCorrectSetting x0, byte b) {
            this();
        }

        @Override // android.widget.AdapterView.OnItemSelectedListener
        public final void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
        }

        @Override // android.widget.AdapterView.OnItemSelectedListener
        public final void onNothingSelected(AdapterView<?> parent) {
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.net.correct.TrafficCorrectSetting$b */
    private final class C0747b implements AdapterView.OnItemSelectedListener {

        /* JADX INFO: renamed from: b */
        private int f4559b = 0;

        public C0747b() {
        }

        @Override // android.widget.AdapterView.OnItemSelectedListener
        public final void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
            ArrayList<String> list = new ArrayList<>();
            TextView operator = (TextView) view;
            String operatorString = operator.getText().toString();
            if (operatorString.equals(TrafficCorrectSetting.this.getString(C0415R.string.net_operators_m))) {
                list.add(0, TrafficCorrectSetting.this.f4547l.getString(C0415R.string.net_operators_m_1));
                list.add(1, TrafficCorrectSetting.this.f4547l.getString(C0415R.string.net_operators_m_2));
                list.add(2, TrafficCorrectSetting.this.f4547l.getString(C0415R.string.net_operators_m_3));
                list.add(0, TrafficCorrectSetting.this.f4552q);
            } else if (operatorString.equals(TrafficCorrectSetting.this.getString(C0415R.string.net_operators_u))) {
                list.add(0, TrafficCorrectSetting.this.f4547l.getString(C0415R.string.net_operators_u_1));
                list.add(1, TrafficCorrectSetting.this.f4547l.getString(C0415R.string.net_operators_u_2));
                list.add(0, TrafficCorrectSetting.this.f4552q);
            } else {
                list.add(TrafficCorrectSetting.this.getString(C0415R.string.net_operators_cdma));
            }
            ArrayAdapter<String> adapter2 = new ArrayAdapter<>(TrafficCorrectSetting.this.f4547l, C0415R.layout.simple_spinner_item, list);
            adapter2.setDropDownViewResource(R.layout.simple_spinner_dropdown_item);
            if (this.f4559b == 0) {
                TrafficCorrectSetting.this.f4544i.setAdapter((SpinnerAdapter) adapter2);
                Spinner spinner = TrafficCorrectSetting.this.f4544i;
                TrafficCorrectSetting trafficCorrectSetting = TrafficCorrectSetting.this;
                spinner.setSelection(TrafficCorrectSetting.m1878b(TrafficCorrectSetting.this.f4548m[3], list), true);
            }
        }

        @Override // android.widget.AdapterView.OnItemSelectedListener
        public final void onNothingSelected(AdapterView<?> parent) {
        }
    }

    /* JADX WARN: Code duplicated, block: B:14:0x0043  */
    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        boolean z;
        switch (v.getId()) {
            case C0415R.id.net_cancel /* 2131297330 */:
                finish();
                break;
            case C0415R.id.net_traffic_correct /* 2131297331 */:
                if (this.f4549n == 0) {
                    if (Utils.getCanCorrectFlag(this)) {
                        canCorrect = false;
                        Utils.setCanCorrectFlag(this, canCorrect);
                        m1877a(this.f4549n);
                        Utils.setCorrectPostion(this, cardPostion);
                        this.f4551p.sendMessageDelayed(this.f4551p.obtainMessage(0), TIME);
                    } else {
                        long jCurrentTimeMillis = System.currentTimeMillis() - Utils.getLastCorrectTime(this);
                        Log.i(SecurityService.TAG, "tmp = " + jCurrentTimeMillis);
                        if (jCurrentTimeMillis >= TIME) {
                            z = true;
                        } else {
                            if (jCurrentTimeMillis <= 0) {
                                Utils.setLastCorrectTime(this);
                            }
                            z = false;
                        }
                        if (z) {
                            canCorrect = false;
                            Utils.setCanCorrectFlag(this, canCorrect);
                            m1877a(this.f4549n);
                            Utils.setCorrectPostion(this, cardPostion);
                            this.f4551p.sendMessageDelayed(this.f4551p.obtainMessage(0), TIME);
                        } else {
                            Toast.makeText(this.f4547l, C0415R.string.net_traffic_correct_notice, 1).show();
                        }
                    }
                } else {
                    m1877a(this.f4549n);
                }
                if (this.f4550o) {
                    finish();
                }
                this.f4550o = true;
                break;
            case C0415R.id.title_back /* 2131297709 */:
                finish();
                break;
        }
    }

    /* JADX WARN: Type inference failed for: r5v40, types: [com.lenovo.safecenter.net.correct.TrafficCorrectSetting$2] */
    /* JADX INFO: renamed from: a */
    private void m1877a(int type) {
        String str;
        this.f4545j = new SIMDetailInfo();
        TextView provice = (TextView) this.f4541f.getSelectedView();
        TextView city = (TextView) this.f4542g.getSelectedView();
        TextView op = (TextView) this.f4543h.getSelectedView();
        TextView b = (TextView) this.f4544i.getSelectedView();
        this.f4545j.proviceDesc = provice.getText().toString();
        this.f4545j.cityDesc = city.getText().toString();
        this.f4545j.operatorsDesc = op.getText().toString();
        this.f4545j.brandDesc = b.getText().toString();
        this.f4545j.provice = m1880b(provice.getText().toString());
        SIMDetailInfo sIMDetailInfo = this.f4545j;
        String str2 = this.f4545j.provice;
        String string = city.getText().toString();
        ArrayList<CodeName> cities = mTcMgr.getCities(str2);
        if (cities != null) {
            str = null;
            for (CodeName codeName : cities) {
                str = string.equals(codeName.mName) ? codeName.mCode : str;
            }
        } else {
            str = null;
        }
        sIMDetailInfo.city = str;
        SIMDetailInfo sIMDetailInfo2 = this.f4545j;
        String string2 = op.getText().toString();
        String str3 = null;
        for (CodeName codeName2 : mTcMgr.getCarries()) {
            str3 = string2.equals(codeName2.mName) ? codeName2.mCode : str3;
        }
        sIMDetailInfo2.operators = str3;
        SIMDetailInfo sIMDetailInfo3 = this.f4545j;
        String str4 = this.f4545j.operators;
        String string3 = b.getText().toString();
        String str5 = null;
        for (CodeName codeName3 : mTcMgr.getBrands(str4)) {
            str5 = string3.equals(codeName3.mName) ? codeName3.mCode : str5;
        }
        sIMDetailInfo3.brand = str5;
        this.f4545j.proviceSelected = this.f4541f.getSelectedItemPosition();
        this.f4545j.citySelected = this.f4542g.getSelectedItemPosition();
        this.f4545j.operatorsSelected = this.f4543h.getSelectedItemPosition();
        this.f4545j.brandSelected = this.f4544i.getSelectedItemPosition();
        Log.i(SecurityService.TAG, "proviceDesc = " + this.f4545j.proviceDesc + ",cityDesc = " + this.f4545j.cityDesc);
        Log.i(SecurityService.TAG, "type = " + type);
        Log.i(SecurityService.TAG, "pro id = " + this.f4545j.provice + "   , city id =" + this.f4545j.city + ", oper id = " + this.f4545j.operators + ",brand id =" + this.f4545j.brand + ",,card =" + cardPostion);
        Log.i(SecurityService.TAG, "pro po = " + this.f4545j.proviceSelected + "   , city id =" + this.f4545j.citySelected + ", oper id = " + this.f4545j.operatorsSelected + ",brand id =" + this.f4545j.brandSelected + ",,card =" + cardPostion);
        if (this.f4552q.equals(this.f4545j.proviceDesc) || this.f4552q.equals(this.f4545j.cityDesc) || this.f4553r.equals(this.f4545j.cityDesc) || this.f4552q.equals(this.f4545j.brandDesc)) {
            this.f4550o = false;
            Toast.makeText(this.f4547l, C0415R.string.net_first_set_notice, 1).show();
            return;
        }
        Utils.setConfig2Preference(this.f4545j, cardPostion, this);
        if (type == 1) {
            if (!WflUtils.isNetworkAvailable(this.f4547l)) {
                Toast.makeText(this.f4547l, C0415R.string.net_no_able, 0).show();
            } else {
                Toast.makeText(this.f4547l, C0415R.string.net_correct_update_config_progress, 0).show();
            }
        }
        new Thread() { // from class: com.lenovo.safecenter.net.correct.TrafficCorrectSetting.2
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                Message msg = new Message();
                SmsEntity se = new SmsEntity();
                msg.what = C0415R.string.net_correct_update_config;
                se.f6027id = TrafficCorrectSetting.cardPostion;
                if (!WflUtils.isNetworkAvailable(TrafficCorrectSetting.this.f4547l)) {
                    se.body = "";
                    se.phonenum = "";
                } else {
                    if (TrafficCorrectSetting.cardPostion == 0) {
                        TrafficCorrectSetting.this.f4554s = TrafficCorrectSetting.this.getSharedPreferences(Utils.SIM1_PROPERTIES, 0);
                    } else {
                        TrafficCorrectSetting.this.f4554s = TrafficCorrectSetting.this.getSharedPreferences(Utils.SIM2_PROPERTIES, 0);
                    }
                    TrafficCorrectionConfig config = new TrafficCorrectionConfig(TrafficCorrectSetting.this.f4545j.provice, TrafficCorrectSetting.this.f4545j.city, TrafficCorrectSetting.this.f4545j.operators, TrafficCorrectSetting.this.f4545j.brand);
                    TrafficCorrectionManager mTcMgr2 = (TrafficCorrectionManager) ManagerCreator.getManager(TrafficCorrectionManager.class);
                    mTcMgr2.setConfig(config);
                    ArrayList<CorrectionDataInfo> infoList = new ArrayList<>();
                    mTcMgr2.startCorrection(infoList);
                    if (infoList.size() > 0) {
                        CorrectionDataInfo di = infoList.get(0);
                        TrafficCorrectSetting.this.f4554s.edit().putString(Utils.SMS_MESSAGE, di.getMessage()).commit();
                        TrafficCorrectSetting.this.f4554s.edit().putString(Utils.SMS_ADDRESS, di.getAddress()).commit();
                        se.body = di.getMessage();
                        se.phonenum = di.getAddress();
                    }
                }
                msg.obj = se;
                if (NetCache.getNetSettingHandler() != null) {
                    NetCache.getNetSettingHandler().sendMessage(msg);
                }
                TrafficCorrectSetting.this.f4551p.sendEmptyMessage(1);
            }
        }.start();
        if (type == 0) {
            Toast.makeText(this.f4547l, C0415R.string.net_traffic_correct_first_notice, 1).show();
            Log.i(SecurityService.TAG, "touch toast short");
            SecurityService.config = new TrafficCorrectionConfig(this.f4545j.provice, this.f4545j.city, this.f4545j.operators, this.f4545j.brand);
            Utils.setLastCorrectTime(this);
            Intent i = new Intent(this, (Class<?>) SecurityService.class);
            i.putExtra(CORRECT, true);
            startService(i);
        }
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        this.f4545j = null;
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: b */
    public static String m1880b(String name) {
        String mCode = null;
        ArrayList<CodeName> provinces = mTcMgr.getAllProvinces();
        for (CodeName codeName : provinces) {
            if (name.equals(codeName.mName)) {
                mCode = codeName.mCode;
            }
        }
        return mCode;
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public ArrayList<String> m1876a(ArrayList<CodeName> lists) {
        ArrayList<String> list = new ArrayList<>();
        if (lists == null) {
            list.add(this.f4552q);
        } else {
            for (CodeName codeName : lists) {
                list.add(codeName.mName);
            }
        }
        return list;
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: b */
    public static int m1878b(int pos, List<String> list) {
        if (pos >= list.size() - 1) {
            return list.size() - 1;
        }
        return pos;
    }
}
