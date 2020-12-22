//
// Created by Shuangrui CHEN on 09/10/2020.
//

#include <iostream>
#include "dataPath.hpp"
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

Mat convertBGRtoHSV(Mat image){
    ///
    Mat BGRchannels[3];
    Mat result = image.clone();
    split(image, BGRchannels);

    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            double B =  BGRchannels[0].at<uchar>(i,j)/255.;
            double G =  BGRchannels[1].at<uchar>(i,j)/255.;
            double R =  BGRchannels[2].at<uchar>(i,j)/255.;

            double Cmax = max(max(B, G), R);
            double Cmin = min(min(B, G), R);
            double delta = Cmax - Cmin;

            int H;
            double S,V;

            if (delta == 0) {
                H = 0;
            } else if (Cmax-R < 0.001) {
                H = 60*((int)((G-B)/delta) % 6);
            } else if (Cmax-G < 0.001) {
                H = 60*((int)((B-R)/delta) + 2);
            } else if (Cmax-B < 0.001) {
                H = 60*((int)((R-G)/delta) + 4);
            } else {
                H = 0;
                cout << "Error: Cmax - " << Cmax << "\tR - " << R << "\tG - " << G << "\tB - " << B << endl;
            }

            if (Cmax == 0) {
                S = 0;
            } else {
                S = (delta / Cmax);
            }

            V = Cmax;

            result.at<Vec3b>(i,j) = Vec3b(H, S, V);
            // cout << "x";
        }
    }
    return result;
    ///
}

int main() {
    Mat img = imread("Unknown.png", -1);
    cvtColor(img,img,COLOR_BGRA2BGR);
    Mat hsv = convertBGRtoHSV(img);

    imshow("Test", hsv);
    Mat result[3];
    split(hsv, result);
    imshow("Test1", result[0]);
    imshow("Test2", result[1]);
    imshow("Test3", result[2]);

    Mat h;
    Mat answer[3];
    cvtColor(img, h, COLOR_BGR2HSV);
    split(h, answer);
    imshow("Test4", answer[0]);
    imshow("Test5", answer[1]);
    imshow("Test6", answer[2]);
    waitKey(0);
    return 0;
}