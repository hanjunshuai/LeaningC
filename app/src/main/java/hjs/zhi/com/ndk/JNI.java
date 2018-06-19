package hjs.zhi.com.ndk;

public class JNI {
    static {
        System.loadLibrary("Test");
    }

    public native int[] intcreaseArray(int[] intArray);

    public native int checkPwd(String pwd);
}
