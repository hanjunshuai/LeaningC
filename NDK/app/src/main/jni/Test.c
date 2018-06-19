//
// Created by Administrator on 2018/6/19.
//
#include <malloc.h>
#include <string.h>
#include "hjs_zhi_com_ndk_JNI.h"

char *_JString2CStr(JNIEnv *env, jstring jstr) {
    char *pStr = NULL;

    jclass jstrObj = (*env)->FindClass(env, "java/lang/String");
    jstring encode = (*env)->NewStringUTF(env, "utf-8");
    jmethodID methodId = (*env)->GetMethodID(env, jstrObj, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray byteArray = (jbyteArray) (*env)->CallObjectMethod(env, jstr, methodId, encode);
    jsize strLen = (*env)->GetArrayLength(env, byteArray);
    jbyte *jBuf = (*env)->GetByteArrayElements(env, byteArray, JNI_FALSE);

    if (jBuf > 0) {
        pStr = (char *) malloc(strLen + 1);

        if (!pStr) {
            return NULL;
        }

        memcpy(pStr, jBuf, strLen);

        pStr[strLen] = 0;
    }

    (*env)->ReleaseByteArrayElements(env, byteArray, jBuf, 0);
    return pStr;
}

/**
 * 每个元素 加  10
 * @param env
 * @param obj
 * @param array
 * @return
 */
jintArray Java_hjs_zhi_com_ndk_JNI_intcreaseArray
        (JNIEnv *env, jobject obj, jintArray array) {

    // 1、得到数组长度
    // jsize       (*GetArrayLength)(JNIEnv*, jarray);
    int size = (*env)->GetArrayLength(env, array);
    // 2、得到数组元素
    //jint*       (*GetIntArrayElements)(JNIEnv*, jintArray, jboolean*);
    jint *intArray = (*env)->GetIntArrayElements(env, array, JNI_FALSE);
    //3、遍历数组  每个元素加10
    for (int i = 0; i < size; i++) {
        *(intArray + i) += 10;
    }
    return array;
};


jint Java_hjs_zhi_com_ndk_JNI_checkPwd
        (JNIEnv *env, jobject obj, jstring jstr) {

    // 密码为123
    char *origin = "123";
    char *fromUser = _JString2CStr(env, jstr);

    //比较
    int code = strcmp(origin, fromUser);

    if (code == 0) {
        return 200;
    } else {
        return 404;
    }
};


