package com.tencent.tmsecure.module.update;

/* JADX INFO: loaded from: classes.dex */
public interface ICheckListener {

    public static final class Proxy implements ICheckListener {

        /* JADX INFO: renamed from: a */
        private ICheckListener f6235a;

        public Proxy(ICheckListener iCheckListener) {
            this.f6235a = iCheckListener;
        }

        @Override // com.tencent.tmsecure.module.update.ICheckListener
        public final void onCheckCanceled() {
            if (this.f6235a != null) {
                this.f6235a.onCheckCanceled();
            }
        }

        @Override // com.tencent.tmsecure.module.update.ICheckListener
        public final void onCheckEvent(int i) {
            if (this.f6235a != null) {
                this.f6235a.onCheckEvent(i);
            }
        }

        @Override // com.tencent.tmsecure.module.update.ICheckListener
        public final void onCheckFinished(CheckResult checkResult) {
            if (this.f6235a != null) {
                this.f6235a.onCheckFinished(checkResult);
            }
        }

        @Override // com.tencent.tmsecure.module.update.ICheckListener
        public final void onCheckStarted() {
            if (this.f6235a != null) {
                this.f6235a.onCheckStarted();
            }
        }
    }

    void onCheckCanceled();

    void onCheckEvent(int i);

    void onCheckFinished(CheckResult checkResult);

    void onCheckStarted();
}
