//
// Created by Shuangrui CHEN on 28/10/2020.
//

#include <iostream>
#include "dataPath.hpp"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat img = imread("../data/images/sample.jpg", IMREAD_GRAYSCALE);
    Mat laplacian1;
    Mat laplacian2;

    Mat l1 = (Mat_<int>(3,3) << 0, 0, 0, -1, 2, -1, 0, 0, 0);
    Mat l2 = (Mat_<int>(3,3) << 0, -1, 0, 0, 2, 0, 0, -1, 0);
    filter2D(img, laplacian1, -1, l1);
    filter2D(img, laplacian2, -1, l2);

    laplacian1 = abs(laplacian1);
    laplacian2 = abs(laplacian2);
    Mat ml = laplacian1 + laplacian2;

    double res = 0;
    for (int i = 0; i < ml.cols; ++i) {
        for (int j = 0; j < ml.rows; ++j) {
            res += ml.at<uchar>(i, j);
        }
    }

    cout << endl << endl << res << endl;
    return 0;
}