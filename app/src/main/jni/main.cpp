#include <jni.h>
#include "com_yellowdo_myapplication_MainActivity.h"

#include <opencv2/opencv.hpp>
using namespace cv;

extern "C" {

JNIEXPORT void JNICALL Java_com_yellowdo_myapplication_MainActivity_opencv_1lib_1run
    (JNIEnv *env, jobject instance, jlong matAddrInput, jlong matAddrResult){

    Mat &matInput = *(Mat *)matAddrInput;
    Mat &matResult = *(Mat *)matAddrResult;

    cvtColor(matInput, matResult, CV_RGBA2GRAY);
    Canny(matResult, matResult, 120, 200, 3);
}

}

