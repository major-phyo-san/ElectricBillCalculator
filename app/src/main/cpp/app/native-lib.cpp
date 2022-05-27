//
// Created by Techman (MajorSan) on 23/07/2019.
// Updated by Techman (MajorSan) on 19/04/2020.
// Refactored by Techman (MajorSan) on 25/05/2022.
//

#include "include/domesticbillcalculator.h"
#include "include/industrialbillcalculator.h"

#include <jni.h>
#include <string>

using namespace std;

extern "C"
{
    JNIEXPORT jstring JNICALL
    Java_com_majorsan_electricbillcalculator_MainActivity_stringFromJNI(
            JNIEnv *env,
            jobject /* this */) {
        string hello = "Hello from C++";
        return env->NewStringUTF(hello.c_str());
    }

    JNIEXPORT jstring JNICALL
    Java_com_majorsan_electricbillcalculator_MainActivity_domesticBillResults(JNIEnv *env, jobject obj, jdouble inputUnit)
    {
        string billResults = calculateDomesticBill(inputUnit);
        return env->NewStringUTF(billResults.c_str());
    }

    JNIEXPORT jstring JNICALL
    Java_com_majorsan_electricbillcalculator_MainActivity_industrialBillResults(JNIEnv *env, jobject obj, jdouble inputUnit)
    {
        string billResults = calculateIndustryBill(inputUnit);
        return env->NewStringUTF(billResults.c_str());

    }

}