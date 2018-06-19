//
// Created by Administrator on 2018/6/19.
//
#include <jni.h>
#include "hjs_zhi_com_ndk_JniUtils.h"

jstring Java_hjs_zhi_com_ndk_JniUtils_helloFromC
        (JNIEnv *env, jclass obj) {
    return env->NewStringUTF("This just a test for Android Studio NDK JNI developer!");
}
