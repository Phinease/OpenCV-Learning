#include <iostream>
#include "dataPath.hpp"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat image = imread("data/images/trump.jpg");
    Mat cartoonImage;
    Mat laplacian;

    GaussianBlur(image, laplacian, Size(3, 3), 0);
    cartoonImage = laplacian.clone();
    cvtColor(laplacian, laplacian, COLOR_BGR2GRAY);
    Laplacian(laplacian, laplacian, CV_8U, 3, 15, 0);
    normalize(laplacian, laplacian, 0, 1, NORM_MINMAX, CV_8U);

    // cout << laplacian << endl;
    vector<Mat> BGRs(3);
    imshow("image", cartoonImage);
    split(cartoonImage, BGRs);
    for (int i = 0; i < 3; ++i) {
        BGRs[i] = BGRs[i] - 255*laplacian;
        min(BGRs[i], 0);
    }
    merge(BGRs, cartoonImage);
    // cout << cartoonImage << endl;
    imshow("Laplacian", cartoonImage);
    waitKey(0);

    return 0;
}