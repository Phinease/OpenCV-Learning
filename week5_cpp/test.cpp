//
// Created by Shuangrui CHEN on 28/10/2020.
//
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int rho = 1;
int nbtheta = 60;
int threshlod = 10;
int minLength = 10;
int maxLineGap = 5;

Mat dst, cdst, cdstP;
Mat src = imread("data/images/scanned-form.jpg");
vector<Vec4i> linesP;

void apply(int, void *) {
    HoughLinesP(dst, linesP, rho, CV_PI/nbtheta, threshlod, minLength, maxLineGap);

    if(rho <= 0) {
        rho = 1;
    }

    cdstP = cdst.clone();
    for(auto l : linesP) {
        line( cdstP, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, LINE_AA);
    }

    imshow("HoughLinesP", cdstP);
}

int main(int argc, char** argv)
{
    // Edge detection
    Canny(src, dst, 50, 400, 3);
    cvtColor(dst, cdst, COLOR_GRAY2BGR);
    cdstP = cdst.clone();

    HoughLinesP(dst, linesP, 1, CV_PI/1000, 50, 30, 10 ); // runs the actual detection

    // Draw the lines
    for(auto l : linesP) {
        line( cdstP, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, LINE_AA);
    }
    // Show results
    imshow("HoughLinesP", cdstP);

    createTrackbar("rho", "HoughLinesP", &rho, 20, apply);
    createTrackbar("nbtheta", "HoughLinesP", &nbtheta, 1000, apply);
    createTrackbar("Threshold", "HoughLinesP", &threshlod, 3000, apply);
    createTrackbar("minLength", "HoughLinesP", &minLength, 500, apply);
    createTrackbar("maxLineGap", "HoughLinesP", &maxLineGap, 100, apply);

    waitKey();
    return 0;
}