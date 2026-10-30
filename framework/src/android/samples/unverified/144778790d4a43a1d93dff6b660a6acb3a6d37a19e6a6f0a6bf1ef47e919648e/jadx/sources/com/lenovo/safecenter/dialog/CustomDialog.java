package com.lenovo.safecenter.dialog;

import android.R;
import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;

/* JADX INFO: loaded from: classes.dex */
public class CustomDialog extends Dialog {
    public CustomDialog(Context context, int theme) {
        super(context, theme);
    }

    public CustomDialog(Context context) {
        super(context);
    }

    public static class Builder {

        /* JADX INFO: renamed from: A */
        private DialogInterface.OnClickListener f3495A;

        /* JADX INFO: renamed from: B */
        private DialogInterface.OnCancelListener f3496B;

        /* JADX INFO: renamed from: c */
        private Context f3505c;

        /* JADX INFO: renamed from: d */
        private int f3506d;

        /* JADX INFO: renamed from: e */
        private String f3507e;

        /* JADX INFO: renamed from: f */
        private String f3508f;

        /* JADX INFO: renamed from: g */
        private String f3509g;

        /* JADX INFO: renamed from: h */
        private String f3510h;

        /* JADX INFO: renamed from: i */
        private String f3511i;

        /* JADX INFO: renamed from: j */
        private TextView f3512j;

        /* JADX INFO: renamed from: k */
        private TextView f3513k;

        /* JADX INFO: renamed from: l */
        private TextView f3514l;

        /* JADX INFO: renamed from: m */
        private LinearLayout f3515m;

        /* JADX INFO: renamed from: n */
        private View f3516n;

        /* JADX INFO: renamed from: o */
        private TextView f3517o;

        /* JADX INFO: renamed from: p */
        private CustomDialog f3518p;

        /* JADX INFO: renamed from: w */
        private DialogInterface.OnClickListener f3525w;

        /* JADX INFO: renamed from: x */
        private DialogInterface.OnClickListener f3526x;

        /* JADX INFO: renamed from: y */
        private DialogInterface.OnClickListener f3527y;

        /* JADX INFO: renamed from: z */
        private DialogInterface.OnClickListener f3528z;

        /* JADX INFO: renamed from: q */
        private int f3519q = -1;

        /* JADX INFO: renamed from: r */
        private int f3520r = -1;

        /* JADX INFO: renamed from: s */
        private int f3521s = -1;

        /* JADX INFO: renamed from: t */
        private String[] f3522t = null;

        /* JADX INFO: renamed from: u */
        private int f3523u = -1;

        /* JADX INFO: renamed from: v */
        private String[] f3524v = null;

        /* JADX INFO: renamed from: C */
        private boolean f3497C = true;

        /* JADX INFO: renamed from: D */
        private boolean f3498D = true;

        /* JADX INFO: renamed from: E */
        private boolean f3499E = true;

        /* JADX INFO: renamed from: F */
        private boolean f3500F = true;

        /* JADX INFO: renamed from: G */
        private boolean f3501G = false;

        /* JADX INFO: renamed from: H */
        private boolean f3502H = false;

        /* JADX INFO: renamed from: a */
        private int f3503a = C0415R.drawable.home_page_button_healthcheckup_selector;

        /* JADX INFO: renamed from: b */
        private int f3504b = C0415R.drawable.signbtn_bg;

        public Builder setColorNeutralButton(boolean isColorNeutralButton) {
            this.f3502H = isColorNeutralButton;
            return this;
        }

        public Builder setColorNegativeButton(boolean isColorNegativeButton) {
            this.f3501G = isColorNegativeButton;
            return this;
        }

        public Builder setColorPositiveButton(boolean isColorPositiveButton) {
            this.f3500F = isColorPositiveButton;
            return this;
        }

        public Builder(Context context) {
            this.f3505c = context;
        }

        public Builder setIcon(int icon) {
            this.f3506d = icon;
            return this;
        }

        public Builder setMessage(String message) {
            this.f3508f = message;
            return this;
        }

        public Builder setMessage(int message) {
            this.f3508f = (String) this.f3505c.getText(message);
            return this;
        }

        public Builder setTitle(int title) {
            this.f3507e = (String) this.f3505c.getText(title);
            return this;
        }

        public Builder setTitle(String title) {
            this.f3507e = title;
            return this;
        }

        public Builder reSetTitle(String title) {
            this.f3507e = title;
            if (this.f3517o != null) {
                this.f3517o.setText(title);
            }
            return this;
        }

        public Builder setContentView(View v) {
            this.f3516n = v;
            return this;
        }

        public Builder setPositiveButton(int positiveButtonText, DialogInterface.OnClickListener listener) {
            this.f3509g = (String) this.f3505c.getText(positiveButtonText);
            if (listener == null) {
                this.f3525w = new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.dialog.CustomDialog.Builder.1
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                    }
                };
            } else {
                this.f3525w = listener;
            }
            return this;
        }

        public Builder setPositiveButton(String positiveButtonText, DialogInterface.OnClickListener listener) {
            this.f3509g = positiveButtonText;
            if (listener == null) {
                this.f3525w = new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.dialog.CustomDialog.Builder.11
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                    }
                };
            } else {
                this.f3525w = listener;
            }
            return this;
        }

        public Builder setPositiveButton(int positiveButtonText, DialogInterface.OnClickListener listener, boolean autoDismiss) {
            this.f3497C = autoDismiss;
            this.f3509g = (String) this.f3505c.getText(positiveButtonText);
            if (listener == null) {
                this.f3525w = new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.dialog.CustomDialog.Builder.12
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                    }
                };
            } else {
                this.f3525w = listener;
            }
            return this;
        }

        public Builder setNegativeButton(int negativeButtonText, DialogInterface.OnClickListener listener) {
            this.f3510h = (String) this.f3505c.getText(negativeButtonText);
            if (listener == null) {
                this.f3527y = new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.dialog.CustomDialog.Builder.13
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                    }
                };
            } else {
                this.f3527y = listener;
            }
            return this;
        }

        public Builder setNegativeButton(String negativeButtonText, DialogInterface.OnClickListener listener) {
            this.f3510h = negativeButtonText;
            if (listener == null) {
                this.f3527y = new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.dialog.CustomDialog.Builder.14
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                    }
                };
            } else {
                this.f3527y = listener;
            }
            return this;
        }

        public Builder setNegativeButton(int negativeButtonText, DialogInterface.OnClickListener listener, boolean autoDismiss) {
            this.f3498D = autoDismiss;
            this.f3510h = (String) this.f3505c.getText(negativeButtonText);
            if (listener == null) {
                this.f3527y = new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.dialog.CustomDialog.Builder.15
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                    }
                };
            } else {
                this.f3527y = listener;
            }
            return this;
        }

        public Builder setNeutralButton(int neutralButtonText, DialogInterface.OnClickListener listener) {
            this.f3511i = (String) this.f3505c.getText(neutralButtonText);
            if (listener == null) {
                this.f3526x = new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.dialog.CustomDialog.Builder.16
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                    }
                };
            } else {
                this.f3526x = listener;
            }
            return this;
        }

        public Builder setNeutralButton(String neutralButtonText, DialogInterface.OnClickListener listener) {
            this.f3511i = neutralButtonText;
            if (listener == null) {
                this.f3526x = new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.dialog.CustomDialog.Builder.17
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                    }
                };
            } else {
                this.f3526x = listener;
            }
            return this;
        }

        public Builder setNeutralButton(int neutralButtonText, DialogInterface.OnClickListener listener, boolean autoDismiss) {
            this.f3499E = autoDismiss;
            this.f3511i = (String) this.f3505c.getText(neutralButtonText);
            if (listener == null) {
                this.f3526x = new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.dialog.CustomDialog.Builder.18
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                    }
                };
            } else {
                this.f3526x = listener;
            }
            return this;
        }

        public Builder setItems(int itemsId, DialogInterface.OnClickListener listener) {
            this.f3519q = 2;
            this.f3523u = itemsId;
            if (listener == null) {
                this.f3495A = new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.dialog.CustomDialog.Builder.2
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                    }
                };
            } else {
                this.f3495A = listener;
            }
            return this;
        }

        public Builder setItems(String[] itemsId, DialogInterface.OnClickListener listener) {
            this.f3519q = 2;
            this.f3524v = itemsId;
            if (listener == null) {
                this.f3495A = new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.dialog.CustomDialog.Builder.3
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                    }
                };
            } else {
                this.f3495A = listener;
            }
            return this;
        }

        public Builder setSingleChoiceItems(int singleChoiceItemsId, int singleChoiceCheckedId, DialogInterface.OnClickListener listener) {
            this.f3519q = 0;
            this.f3520r = singleChoiceItemsId;
            this.f3521s = singleChoiceCheckedId;
            if (listener == null) {
                this.f3528z = new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.dialog.CustomDialog.Builder.4
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                    }
                };
            } else {
                this.f3528z = listener;
            }
            return this;
        }

        public Builder setSingleChoiceItems(String[] singleChoiceItems, int singleChoiceCheckedId, DialogInterface.OnClickListener listener) {
            this.f3519q = 0;
            this.f3522t = singleChoiceItems;
            this.f3521s = singleChoiceCheckedId;
            if (listener == null) {
                this.f3528z = new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.dialog.CustomDialog.Builder.5
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                    }
                };
            } else {
                this.f3528z = listener;
            }
            return this;
        }

        public Builder setOnCancelListener(DialogInterface.OnCancelListener onCancelListener) {
            this.f3496B = onCancelListener;
            return this;
        }

        public Builder setPositiveButtonVisible(boolean isVisible) {
            if (this.f3512j != null) {
                if (isVisible) {
                    this.f3512j.setVisibility(0);
                } else {
                    this.f3512j.setVisibility(8);
                }
            }
            return this;
        }

        public Builder setNeutralButtonVisible(boolean isVisible) {
            if (this.f3514l != null) {
                if (isVisible) {
                    this.f3514l.setVisibility(0);
                } else {
                    this.f3514l.setVisibility(8);
                }
            }
            return this;
        }

        public Builder setNegativeButtonVisible(boolean isVisible) {
            if (this.f3513k != null) {
                if (isVisible) {
                    this.f3513k.setVisibility(0);
                } else {
                    this.f3513k.setVisibility(8);
                }
            }
            return this;
        }

        public Builder setButtonVisible(boolean isVisible) {
            if (this.f3515m != null) {
                if (isVisible) {
                    this.f3515m.setVisibility(0);
                } else {
                    this.f3515m.setVisibility(8);
                }
            }
            return this;
        }

        public CustomDialog create() {
            LayoutInflater inflater = (LayoutInflater) this.f3505c.getSystemService("layout_inflater");
            final CustomDialog dialog = new CustomDialog(this.f3505c, C0415R.style.Dialog);
            View layout = inflater.inflate(C0415R.layout.dialog, (ViewGroup) null);
            dialog.addContentView(layout, new ViewGroup.LayoutParams(-1, -2));
            ImageView icon = (ImageView) layout.findViewById(C0415R.id.icon);
            if (this.f3506d != 0) {
                icon.setVisibility(0);
                icon.setImageResource(this.f3506d);
            } else {
                icon.setVisibility(8);
            }
            this.f3515m = (LinearLayout) layout.findViewById(C0415R.id.button);
            this.f3517o = (TextView) layout.findViewById(C0415R.id.title);
            this.f3517o.setText(this.f3507e);
            if (this.f3509g != null) {
                this.f3512j = (TextView) layout.findViewById(C0415R.id.positiveButton);
                this.f3512j.setText(this.f3509g);
                if (this.f3500F) {
                    this.f3512j.setBackgroundResource(this.f3503a);
                } else {
                    this.f3512j.setBackgroundResource(this.f3504b);
                }
                if (this.f3525w != null) {
                    ((TextView) layout.findViewById(C0415R.id.positiveButton)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.dialog.CustomDialog.Builder.6
                        @Override // android.view.View.OnClickListener
                        public final void onClick(View v) {
                            Builder.this.f3525w.onClick(dialog, -1);
                            if (Builder.this.f3497C) {
                                dialog.dismiss();
                            }
                        }
                    });
                }
            } else {
                layout.findViewById(C0415R.id.positiveButton).setVisibility(8);
            }
            if (this.f3511i != null) {
                this.f3514l = (TextView) layout.findViewById(C0415R.id.neutralButton);
                this.f3514l.setText(this.f3511i);
                if (this.f3502H) {
                    this.f3514l.setBackgroundResource(this.f3503a);
                } else {
                    this.f3514l.setBackgroundResource(this.f3504b);
                }
                if (this.f3526x != null) {
                    ((TextView) layout.findViewById(C0415R.id.neutralButton)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.dialog.CustomDialog.Builder.7
                        @Override // android.view.View.OnClickListener
                        public final void onClick(View v) {
                            Builder.this.f3526x.onClick(dialog, -3);
                            if (Builder.this.f3499E) {
                                dialog.dismiss();
                            }
                        }
                    });
                }
            } else {
                layout.findViewById(C0415R.id.neutralButton).setVisibility(8);
            }
            if (this.f3510h != null) {
                this.f3513k = (TextView) layout.findViewById(C0415R.id.negativeButton);
                this.f3513k.setText(this.f3510h);
                if (this.f3501G) {
                    this.f3513k.setBackgroundResource(this.f3503a);
                } else {
                    this.f3513k.setBackgroundResource(this.f3504b);
                }
                if (this.f3527y != null) {
                    ((TextView) layout.findViewById(C0415R.id.negativeButton)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.dialog.CustomDialog.Builder.8
                        @Override // android.view.View.OnClickListener
                        public final void onClick(View v) {
                            Builder.this.f3527y.onClick(dialog, -2);
                            if (Builder.this.f3498D) {
                                dialog.dismiss();
                            }
                        }
                    });
                }
            } else {
                layout.findViewById(C0415R.id.negativeButton).setVisibility(8);
            }
            if (this.f3508f != null) {
                ((TextView) layout.findViewById(C0415R.id.message)).setText(this.f3508f);
            } else if (this.f3519q == 0) {
                ArrayAdapter arrayAdapter = this.f3522t != null ? new ArrayAdapter(this.f3505c, R.layout.simple_list_item_single_choice, this.f3522t) : new ArrayAdapter(this.f3505c, R.layout.simple_list_item_single_choice, this.f3505c.getResources().getStringArray(this.f3520r));
                ListView listView = new ListView(this.f3505c);
                Log.i("wu0wu", "singleChoiceCheckedId=" + this.f3521s);
                listView.setChoiceMode(1);
                listView.setCacheColorHint(this.f3505c.getResources().getColor(C0415R.color.transparent_background));
                listView.setAdapter((ListAdapter) arrayAdapter);
                listView.setItemsCanFocus(false);
                listView.setItemChecked(this.f3521s, true);
                ((LinearLayout) layout.findViewById(C0415R.id.content)).removeAllViews();
                ((LinearLayout) layout.findViewById(C0415R.id.content)).addView(listView, new ViewGroup.LayoutParams(-1, -2));
                listView.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.dialog.CustomDialog.Builder.10
                    @Override // android.widget.AdapterView.OnItemClickListener
                    public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                        if (Builder.this.f3528z != null) {
                            Builder.this.f3528z.onClick(dialog, position);
                            Log.i("wu0wu", "singleChoiceItemsCheckListener onItemClick=" + position);
                        }
                    }
                });
            } else if (this.f3519q == 2) {
                ArrayAdapter arrayAdapter2 = new ArrayAdapter(this.f3505c, R.layout.simple_list_item_1, this.f3524v == null ? this.f3505c.getResources().getStringArray(this.f3523u) : this.f3524v);
                ListView listView2 = new ListView(this.f3505c);
                listView2.setCacheColorHint(this.f3505c.getResources().getColor(C0415R.color.transparent_background));
                listView2.setAdapter((ListAdapter) arrayAdapter2);
                ((LinearLayout) layout.findViewById(C0415R.id.button)).setVisibility(8);
                ((LinearLayout) layout.findViewById(C0415R.id.content)).removeAllViews();
                ((LinearLayout) layout.findViewById(C0415R.id.content)).addView(listView2, new ViewGroup.LayoutParams(-1, -2));
                listView2.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.dialog.CustomDialog.Builder.9
                    @Override // android.widget.AdapterView.OnItemClickListener
                    public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                        if (Builder.this.f3495A != null) {
                            Builder.this.f3495A.onClick(dialog, position);
                            Log.i("wu0wu", "noChoiceListonClickListener onItemClick=" + position);
                            dialog.dismiss();
                        }
                    }
                });
            } else if (this.f3516n != null) {
                ((LinearLayout) layout.findViewById(C0415R.id.content)).removeAllViews();
                ((LinearLayout) layout.findViewById(C0415R.id.content)).addView(this.f3516n, new ViewGroup.LayoutParams(-1, -2));
            }
            dialog.setContentView(layout);
            return dialog;
        }

        public CustomDialog getDialog() {
            return this.f3518p;
        }

        public CustomDialog show() {
            CustomDialog dialog = create();
            this.f3518p = dialog;
            dialog.setCanceledOnTouchOutside(false);
            dialog.show();
            return dialog;
        }
    }
}
