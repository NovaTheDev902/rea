package com.tencent.tmsecure.module.update;

/* JADX INFO: loaded from: classes.dex */
public interface IUpdateListener {

    public static final class UpdateListener implements IUpdateListener {

        /* JADX INFO: renamed from: a */
        private IUpdateListener f6236a;

        public UpdateListener(IUpdateListener iUpdateListener) {
            this.f6236a = iUpdateListener;
        }

        @Override // com.tencent.tmsecure.module.update.IUpdateListener
        public final void onProgressChanged(UpdateInfo updateInfo, int i) {
            if (this.f6236a != null) {
                this.f6236a.onProgressChanged(updateInfo, i);
            }
        }

        @Override // com.tencent.tmsecure.module.update.IUpdateListener
        public final void onUpdateCanceled() {
            if (this.f6236a != null) {
                this.f6236a.onUpdateCanceled();
            }
        }

        @Override // com.tencent.tmsecure.module.update.IUpdateListener
        public final void onUpdateEvent(UpdateInfo updateInfo, int i) {
            if (this.f6236a != null) {
                this.f6236a.onUpdateEvent(updateInfo, i);
            }
        }

        @Override // com.tencent.tmsecure.module.update.IUpdateListener
        public final void onUpdateFinished() {
            if (this.f6236a != null) {
                this.f6236a.onUpdateFinished();
            }
        }

        @Override // com.tencent.tmsecure.module.update.IUpdateListener
        public final void onUpdateStarted() {
            if (this.f6236a != null) {
                this.f6236a.onUpdateStarted();
            }
        }
    }

    void onProgressChanged(UpdateInfo updateInfo, int i);

    void onUpdateCanceled();

    void onUpdateEvent(UpdateInfo updateInfo, int i);

    void onUpdateFinished();

    void onUpdateStarted();
}
