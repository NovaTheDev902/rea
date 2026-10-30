package ledroid.utils;

import android.R;
import android.content.Context;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BlurMaskFilter;
import android.graphics.Canvas;
import android.graphics.ColorMatrix;
import android.graphics.ColorMatrixColorFilter;
import android.graphics.Paint;
import android.graphics.PaintFlagsDrawFilter;
import android.graphics.PorterDuff;
import android.graphics.Rect;
import android.graphics.TableMaskFilter;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.PaintDrawable;
import android.util.DisplayMetrics;

/* JADX INFO: loaded from: classes.dex */
public final class IconUtilities {

    /* JADX INFO: renamed from: a */
    private static float f6386a = -1.0f;

    /* JADX INFO: renamed from: b */
    private static float f6387b = -1.0f;

    /* JADX INFO: renamed from: c */
    private static int f6388c = -1;

    /* JADX INFO: renamed from: d */
    private static int f6389d = -1;

    /* JADX INFO: renamed from: e */
    private static final Paint f6390e = new Paint();

    /* JADX INFO: renamed from: f */
    private static final Paint f6391f = new Paint();

    /* JADX INFO: renamed from: g */
    private static final Paint f6392g = new Paint();

    /* JADX INFO: renamed from: h */
    private static final Paint f6393h = new Paint();

    /* JADX INFO: renamed from: i */
    private static final Rect f6394i = new Rect();

    /* JADX INFO: renamed from: j */
    private static final Canvas f6395j = new Canvas();

    static {
        f6395j.setDrawFilter(new PaintFlagsDrawFilter(4, 2));
    }

    private IconUtilities() {
    }

    public static Bitmap createIconBitmap(Bitmap icon, Context context) {
        int textureWidth = f6388c;
        int textureHeight = f6389d;
        int sourceWidth = icon.getWidth();
        int sourceHeight = icon.getHeight();
        if (sourceWidth > textureWidth && sourceHeight > textureHeight) {
            return Bitmap.createBitmap(icon, (sourceWidth - textureWidth) / 2, (sourceHeight - textureHeight) / 2, textureWidth, textureHeight);
        }
        if (sourceWidth != textureWidth || sourceHeight != textureHeight) {
            Resources resources = context.getResources();
            return createIconBitmap(new BitmapDrawable(resources, icon), context);
        }
        return icon;
    }

    public static Bitmap createIconBitmap(Drawable icon, Context context) {
        Bitmap bitmap;
        synchronized (f6395j) {
            if (f6386a == -1.0f) {
                m2691a(context);
            }
            float width = f6386a;
            float height = f6387b;
            if (icon instanceof PaintDrawable) {
                PaintDrawable painter = (PaintDrawable) icon;
                painter.setIntrinsicWidth((int) width);
                painter.setIntrinsicHeight((int) height);
            } else if (icon instanceof BitmapDrawable) {
                BitmapDrawable bitmapDrawable = (BitmapDrawable) icon;
                if (bitmapDrawable.getBitmap().getDensity() == 0) {
                    bitmapDrawable.setTargetDensity(context.getResources().getDisplayMetrics());
                }
            }
            int sourceWidth = icon.getIntrinsicWidth();
            int sourceHeight = icon.getIntrinsicHeight();
            if (sourceWidth > 0 && sourceHeight > 0) {
                if (width < sourceWidth || height < sourceHeight) {
                    float ratio = sourceWidth / sourceHeight;
                    if (sourceWidth > sourceHeight) {
                        height = (int) (width / ratio);
                    } else if (sourceHeight > sourceWidth) {
                        width = (int) (height * ratio);
                    }
                } else if (sourceWidth < width && sourceHeight < height) {
                    width = sourceWidth;
                    height = sourceHeight;
                }
            }
            int textureWidth = f6388c;
            int textureHeight = f6389d;
            bitmap = Bitmap.createBitmap(textureWidth, textureHeight, Bitmap.Config.ARGB_8888);
            Canvas canvas = f6395j;
            canvas.setBitmap(bitmap);
            int left = (textureWidth - ((int) width)) / 2;
            int top = (textureHeight - ((int) height)) / 2;
            int right = left + ((int) width);
            int bottom = top + ((int) height);
            f6394i.set(icon.getBounds());
            icon.setBounds(left, top, right, bottom);
            icon.draw(canvas);
            icon.setBounds(f6394i);
        }
        return bitmap;
    }

    public static void drawSelectedAllAppsBitmap(Canvas dest, float destWidth, float destHeight, boolean pressed, Bitmap src) {
        synchronized (f6395j) {
            if (f6386a == -1.0f) {
                throw new RuntimeException("Assertion failed: Utilities not initialized");
            }
            dest.drawColor(0, PorterDuff.Mode.CLEAR);
            int[] xy = new int[2];
            Bitmap mask = src.extractAlpha(f6390e, xy);
            float px = (destWidth - src.getWidth()) / 2.0f;
            float py = (destHeight - src.getHeight()) / 2.0f;
            dest.drawBitmap(mask, px + xy[0], py + xy[1], pressed ? f6391f : f6392g);
            mask.recycle();
        }
    }

    public static Bitmap resampleIconBitmap(Bitmap bitmap, Context context) {
        synchronized (f6395j) {
            if (f6386a == -1.0f) {
                m2691a(context);
            }
            if (bitmap.getWidth() != f6386a || bitmap.getHeight() != f6387b) {
                Resources resources = context.getResources();
                bitmap = createIconBitmap(new BitmapDrawable(resources, bitmap), context);
            }
        }
        return bitmap;
    }

    public static Bitmap drawDisabledBitmap(Bitmap bitmap, Context context) {
        Bitmap disabled;
        synchronized (f6395j) {
            if (f6386a == -1.0f) {
                m2691a(context);
            }
            disabled = Bitmap.createBitmap(bitmap.getWidth(), bitmap.getHeight(), Bitmap.Config.ARGB_8888);
            Canvas canvas = f6395j;
            canvas.setBitmap(disabled);
            canvas.drawBitmap(bitmap, 0.0f, 0.0f, f6393h);
            canvas.setBitmap(null);
        }
        return disabled;
    }

    /* JADX INFO: renamed from: a */
    private static void m2691a(Context context) {
        Resources resources = context.getResources();
        DisplayMetrics metrics = resources.getDisplayMetrics();
        float density = metrics.density;
        f6386a = resources.getDimension(R.dimen.app_icon_size);
        f6387b = f6386a;
        f6388c = (int) f6386a;
        f6389d = f6388c;
        f6390e.setMaskFilter(new BlurMaskFilter(5.0f * density, BlurMaskFilter.Blur.NORMAL));
        f6391f.setColor(-15616);
        f6391f.setMaskFilter(TableMaskFilter.CreateClipTable(0, 30));
        f6392g.setColor(-29184);
        f6392g.setMaskFilter(TableMaskFilter.CreateClipTable(0, 30));
        ColorMatrix cm = new ColorMatrix();
        cm.setSaturation(0.2f);
        f6393h.setColorFilter(new ColorMatrixColorFilter(cm));
        f6393h.setAlpha(136);
    }
}
