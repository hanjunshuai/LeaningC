//
// Created by Administrator on 2018/6/19.
//
#include "hjs.zhi.com.ccalljava.JNI"

/**
 * 让 C 代码带用 Java
 * @param env
 * @param obj
 */
void Java_hjs_zhi_com_ccalljava_JNI_callBackAdd
        (JNIEnv *env, jobject obj) {
    //1、得到字节码    (*FindClass)(JNIEnv*, const char*);
    jclass jclazz = (*env)->FindClass(env, "hjs/zhi/com/ccalljava/JNI");
    //2、得到方法       jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    // 最后一个是方法签名
    jmethodID jmethodIDs = (*env)->GetMethodID(env, jclazz, "add", "(II)I");
    //3、实例化该类    jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject jobject = (*env)->AllocObject(env, jclazz);
    //4、调用方法        jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
    (*env)->CallIntMethod(env, jobject, jmethodIDs, 99, 1);
};
