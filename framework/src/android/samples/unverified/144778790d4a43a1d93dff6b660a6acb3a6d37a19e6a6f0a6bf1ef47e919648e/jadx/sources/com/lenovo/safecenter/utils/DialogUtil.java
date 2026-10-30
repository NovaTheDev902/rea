package com.lenovo.safecenter.utils;

import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.text.TextUtils;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.MainTab.FirstUsePasswordSettingActivity;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.safemode.SofeModeMain;
import com.lenovo.safecenter.utils.updateLab.AutoUpdateLabManager;

/* JADX INFO: loaded from: classes.dex */
public class DialogUtil {
    public static final int ID_MANUAL_OPTIMIZATION_PROTECT_THIEF = 0;
    public static final int ID_NO_ACTION = 2;
    public static final int NOTICE_DIALOG_DOWNLOAD_LECLOUD = 3;
    public static final int NOTICE_DIALOG_KILL_VIRUS = 1;

    /* JADX INFO: renamed from: a */
    private static CustomDialog f5725a;

    /* JADX INFO: renamed from: b */
    private static CustomDialog f5726b = null;

    /* JADX INFO: renamed from: c */
    private static int f5727c = 0;

    public interface ModifyPasswordDialogListener {
        void onModifyPasswordCancel(int i);

        void onModifyPasswordOk(int i, String str);
    }

    public interface SettingFloatNumberDialogListener {
        void onSettingFloatNumberDialogCancel(int i, Float f);

        void onSettingFloatNumberDialogOK(int i, Float f);
    }

    public interface SettingNumberDialogListener {
        void onSettingNumberDialogCancel(int i, int i2);

        void onSettingNumberDialogOK(int i, int i2);
    }

    public interface WarnDialogListener {
        void onWarnDialogCancel(int i);

        void onWarnDialogOk(int i);
    }

    public static void dismissShowPwdDialog() {
        if (f5725a != null) {
            f5725a.dismiss();
        }
    }

    public static void showPwdDialog(final String action, final Context context) {
        dismissShowPwdDialog();
        if (PwdUtil.hasPassword(context)) {
            View view = LayoutInflater.from(context).inflate(C0415R.layout.input_password_content, (ViewGroup) null);
            final TextView message = (TextView) view.findViewById(C0415R.id.txt_message);
            message.setText(C0415R.string.input_privacy_pwd);
            final EditText edit = (EditText) view.findViewById(C0415R.id.edt_input_pwd);
            f5725a = new CustomDialog.Builder(context).setTitle(C0415R.string.input_pwd).setContentView(view).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.utils.DialogUtil.9
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface dialog, int which) {
                    String newPwd = edit.getText().toString();
                    if (PwdUtil.checkPassword(context, newPwd)) {
                        if (action.equals(Const.ACTION_MODIFY_PASSWORD_USE_PRE_PASSWORD)) {
                            WflUtils.startSettingPasswordActivity(context, Const.ACTION_MODIFY_PASSWORD_USE_PRE_PASSWORD);
                            DialogUtil.f5725a.dismiss();
                            return;
                        }
                        Intent i = new Intent(action);
                        if (action.equals(Const.ACTION_JUMP_RPIVACY_SAFE)) {
                            WflUtils.jumpPrivatezoneOrDownloadpage(context);
                            DialogUtil.f5725a.dismiss();
                            return;
                        } else if (action.equals(Const.ACTION_JUMP_APP_LOCK)) {
                            WflUtils.jumpAppLockOrDownloadpage(context);
                            DialogUtil.f5725a.dismiss();
                            return;
                        } else if (action.equals(Const.ACTION_JUMP_KID_MODE)) {
                            WflUtils.jumpKidModeOrDownloadpage(context);
                            DialogUtil.f5725a.dismiss();
                            return;
                        } else {
                            context.startActivity(i);
                            DialogUtil.f5725a.dismiss();
                            return;
                        }
                    }
                    if (newPwd.length() == 0) {
                        message.setText(C0415R.string.error_tips_null);
                        Animation shake = AnimationUtils.loadAnimation(context, C0415R.anim.shake);
                        edit.startAnimation(shake);
                    } else {
                        if (action.equals(Const.ACTION_JUMP_RPIVACY_SAFE) && DataHelpUtils.execService("pwd", context).equals(newPwd)) {
                            Intent i2 = new Intent(context, (Class<?>) SofeModeMain.class);
                            i2.putExtra("pwd", newPwd);
                            i2.addFlags(8388608);
                            context.startActivity(i2);
                            DialogUtil.f5725a.dismiss();
                            return;
                        }
                        Animation shake2 = AnimationUtils.loadAnimation(context, C0415R.anim.shake);
                        edit.startAnimation(shake2);
                        edit.setText("");
                        message.setText(C0415R.string.pwd_error_tips);
                    }
                }
            }, false).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.utils.DialogUtil.1
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface dialog, int which) {
                    DialogUtil.f5725a.dismiss();
                }
            }).show();
        }
    }

    public static void showPasswordQuestionDialog(final Context context, final int id, String question, String answer) {
        View view = LayoutInflater.from(context).inflate(C0415R.layout.dialog_retrieve_password, (ViewGroup) null);
        TextView questionTv = (TextView) view.findViewById(C0415R.id.tv_retrieve_question);
        final EditText answerEt = (EditText) view.findViewById(C0415R.id.et_retrieve_answer);
        String title = null;
        switch (id) {
            case 1:
                title = context.getString(C0415R.string.retrieve_password_text);
                break;
        }
        questionTv.setText(question);
        f5726b = new CustomDialog.Builder(context).setTitle(title).setContentView(view).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.utils.DialogUtil.11
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                DialogUtil.f5726b.dismiss();
            }
        }).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.utils.DialogUtil.10
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                String newAnser = answerEt.getText() == null ? null : answerEt.getText().toString();
                if (TextUtils.isEmpty(newAnser)) {
                    Toast.makeText(context, C0415R.string.password_answer_no_null_text, 0).show();
                    Animation shake = AnimationUtils.loadAnimation(context, C0415R.anim.shake);
                    answerEt.startAnimation(shake);
                } else if (!PwdUtil.checkPasswordAnswer(context, newAnser)) {
                    Toast.makeText(context, C0415R.string.input_password_answer_error, 0).show();
                    Animation shake2 = AnimationUtils.loadAnimation(context, C0415R.anim.shake);
                    answerEt.startAnimation(shake2);
                } else {
                    switch (id) {
                        case 1:
                            WflUtils.startSettingPasswordActivity(context, Const.ACTION_MODIFY_PASSWORD_USE_ANSWER);
                            DialogUtil.f5726b.dismiss();
                            break;
                    }
                }
            }
        }, false).show();
    }

    public static Dialog createManualUpdateDialog(final Context context, final int id, final WarnDialogListener listener) {
        View view = LayoutInflater.from(context).inflate(C0415R.layout.dialog_manual_update, (ViewGroup) null);
        TextView note1 = (TextView) view.findViewById(C0415R.id.note1_manual_update);
        switch (id) {
            case 2:
                note1.setText(C0415R.string.update_note_text);
                TextView note2 = (TextView) view.findViewById(C0415R.id.note2_manual_update);
                note2.setVisibility(0);
                return new CustomDialog.Builder(context).setTitle(C0415R.string.update_lab_notice_text).setContentView(view).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.utils.DialogUtil.16
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                        listener.onWarnDialogOk(id);
                    }
                }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.utils.DialogUtil.15
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                    }
                }).show();
            case 3:
                note1.setText(C0415R.string.all_update_lab_is_new_text);
                return new CustomDialog.Builder(context).setTitle(C0415R.string.update_lab_notice_text).setContentView(view).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.utils.DialogUtil.14
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                    }
                }).show();
            case 4:
                note1.setText(C0415R.string.no_net_update_failure);
                return new CustomDialog.Builder(context).setTitle(C0415R.string.update_lab_notice_text).setContentView(view).setPositiveButton(C0415R.string.set_net_text, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.utils.DialogUtil.13
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                        WflUtils.startWirelessSettingsActivity(context);
                    }
                }).setNeutralButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.utils.DialogUtil.12
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                    }
                }).show();
            default:
                return null;
        }
    }

    public static Dialog createAutoUpdateRatechoice(Context context, final int id, final SettingNumberDialogListener listener) {
        return new CustomDialog.Builder(context).setTitle(C0415R.string.title_auto_update).setSingleChoiceItems(AutoUpdateLabManager.getUpdateModeStringArray(context), AutoUpdateLabManager.getAutoUpdateMode(context), new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.utils.DialogUtil.3
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int whichButton) {
                int unused = DialogUtil.f5727c = whichButton;
            }
        }).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.utils.DialogUtil.2
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int whichButton) {
                listener.onSettingNumberDialogOK(id, DialogUtil.f5727c);
            }
        }).show();
    }

    public static Dialog NoticeDialog(final Context context, final int id, String title, String content, String positiveText, final WarnDialogListener listener) {
        return new CustomDialog.Builder(context).setTitle(title).setMessage(content).setPositiveButton(positiveText, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.utils.DialogUtil.5
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                switch (id) {
                    case 0:
                        Intent intent = new Intent(context, (Class<?>) FirstUsePasswordSettingActivity.class);
                        intent.setAction(Const.ACTION_JUMP_PROTECT_THIEF);
                        intent.setFlags(268435456);
                        context.startActivity(intent);
                        break;
                    case 3:
                        listener.onWarnDialogOk(3);
                        break;
                }
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.utils.DialogUtil.4
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }

    public static Dialog NoticePositiveDialog(Context context, final int id, String title, String content, final WarnDialogListener listener) {
        return new CustomDialog.Builder(context).setTitle(title).setMessage(content).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.utils.DialogUtil.6
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                switch (id) {
                    case 1:
                        listener.onWarnDialogOk(1);
                        break;
                }
            }
        }).show();
    }

    public static Dialog createSettingNumberDialog(final Context context, final int id, final SettingNumberDialogListener listener) {
        View view = LayoutInflater.from(context).inflate(C0415R.layout.dialog_setting_number, (ViewGroup) null);
        TextView note1 = (TextView) view.findViewById(C0415R.id.note1_input_number);
        switch (id) {
            case 2:
                note1.setText(C0415R.string.input_sms_month_num_text);
                break;
        }
        final EditText editText = (EditText) view.findViewById(C0415R.id.et_setting_number_comment);
        int sms = Const.getMonthLimitSMS();
        if (sms != 0) {
            editText.setText("" + sms);
        }
        return new CustomDialog.Builder(context).setTitle(C0415R.string.input_notice_text).setContentView(view).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.utils.DialogUtil.8
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                String number = editText.getText().toString();
                if (TextUtils.isEmpty(number)) {
                    Toast.makeText(context, context.getString(C0415R.string.no_null_limit_input_num_text), 1).show();
                } else if (Integer.parseInt(number) == 0) {
                    Toast.makeText(context, context.getString(C0415R.string.no_zero_limit_input_num_text), 1).show();
                } else {
                    listener.onSettingNumberDialogOK(id, Integer.valueOf(number).intValue());
                }
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.utils.DialogUtil.7
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }
}
