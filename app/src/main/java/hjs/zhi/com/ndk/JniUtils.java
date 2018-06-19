package hjs.zhi.com.ndk;

public class JniUtils {
    static {
        System.loadLibrary("Hello");
    }

    public static native String helloFromC();

    public static native int add(int x, int y);

    public  native String sayHello(String str);
}
