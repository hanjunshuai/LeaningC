//
// Created by Administrator on 2018/6/19.
//
#include "hjs_zhi_com_ndk_JNI.h"

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

};


