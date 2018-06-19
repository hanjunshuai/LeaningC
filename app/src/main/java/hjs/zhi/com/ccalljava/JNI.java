package hjs.zhi.com.ccalljava;

import android.util.Log;

public class JNI {
    static {
        System.loadLibrary("Test");
    }

    public native void callBackAdd();

    public native void callBackHelloFromJava();

    public native void callBackPrintString();

    public native void callBackSayHello();

    public int add(int x, int y) {
        Log.e(JNI.class.getName(), "add x = " + x + " Y = " + y);
        return x + y;
    }

    public void helloFromJava() {
        Log.e(JNI.class.getName(), " helloFromJava()");
    }

    public void printStrint(String str) {
        Log.e(JNI.class.getName(), " C中输入：" + str);
    }

    public void sayHello(String str) {
        Log.e(JNI.class.getName(), "java中的 sayHello()；被C 调用" + str);
    }


}
