//
// Created by Shuangrui CHEN on 20/09/2020.
//

#include <iostream>
#include "dataPath.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main() {
    Mat allzero = Mat::zeros(3, 3, CV_8UC1);
    Mat somenum = Mat::zeros(3, 3, CV_8UC1);
    Mat res = Mat::zeros(3, 3, CV_8UC1);
    somenum.at<uchar>(0) = 1;
    somenum.at<uchar>(1) = 222;
    somenum.at<uchar>(2) = 255;
    somenum.at<uchar>(3) = 255;
    cout << somenum << endl;

    bitwise_and(allzero, somenum, res);
    cout << res << endl;

    bitwise_or(allzero, somenum, res);
    cout << res << endl;

    bitwise_xor(allzero, somenum, res);
    cout << res << endl;

    bitwise_not(somenum, res);
    cout << res << endl;
    return 0;
}