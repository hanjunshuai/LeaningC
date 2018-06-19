//
// Created by Administrator on 2018/6/19.
//
#include <jni.h>
#include <cstring>
#include <cstdlib>
#include "hjs_zhi_com_ndk_JniUtils.h"

char *_JString2CStr(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("GB2312");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid, strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    return rtn;
}

jstring Java_hjs_zhi_com_ndk_JniUtils_helloFromC
        (JNIEnv *env, jclass obj) {

    return env->NewStringUTF("This just a test for Android Studio NDK JNI developer!");
}

jint Java_hjs_zhi_com_ndk_JniUtils_add(JNIEnv *env, jclass type, jint x, jint y) {
    int result = x + y;
    return result;
}

jstring Java_hjs_zhi_com_ndk_JniUtils_sayHello
        (JNIEnv *env, jclass obj, jstring str) {
    char *fromJava = _JString2CStr(env, str);  //得到的结果  I am from  java add I am from C
    //C:
    char *fromC = " add I am from C";
    strcat(fromJava, fromC);// 把拼接的结果放在第一个参数里面
    return env->NewStringUTF(fromJava);
};

