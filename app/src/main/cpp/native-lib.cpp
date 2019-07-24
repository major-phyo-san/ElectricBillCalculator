#include <jni.h>
#include <string>
#include "include/DomesticBillCalculator.h"
#include "include/IndustrialBillCalculator.h"

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

