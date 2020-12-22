//
// Created by Shuangrui CHEN on 30/10/2020.
//

#include <iostream>
#include "dataPath.hpp"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat img = imread("../data/images/trump.jpg", IMREAD_GRAYSCALE);
    // img = Mat(img, Range(140,240), Range(140, 220));
    Mat laplacian;
    Laplacian(img, laplacian, CV_8U, 3, 5,0);
    normalize(laplacian, laplacian, 0, 1, NORM_MINMAX, CV_8U);

    // cvtColor(laplacian, laplacian, COLOR_GRAY2BGR);
    threshold(laplacian, laplacian, 0, 1, THRESH_BINARY_INV);
    // cout << laplacian << endl;
    min(laplacian, 0);
    imshow("Laplacian",laplacian*255);
    waitKey(0);
    return 0;
}