package hjs.zhi.com.ndk;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    JniUtils jniUtils;
    JNI jni;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        jniUtils = new JniUtils();
        jni = new JNI();
        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
        tv.setText(jniUtils.helloFromC());
//        tv.setText(JniUtils.add(3, 2));
        Log.e(MainActivity.class.getName(), jniUtils.add(3, 2) + "");
        Log.e(MainActivity.class.getName(), jniUtils.sayHello("I am from java"));

        int i[] = {1, 2, 3, 4, 5};
        jni.intcreaseArray(i);
        for (int j = 0; j < i.length; j++) {
            Log.e(MainActivity.class.getName(), "i[" + j + "]====" + i[j]);
        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
