/// Enter your code here
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

Mat img = imread("blemish.png");

Mat FindBestPatch(int x, int y) {
    double max = 0;
    int index1 = 0, index2 = 0;
    int pos[3] = {-1, 0, 1};
    for (int i : pos) {
        for (int j : pos) {
            try {
                Mat temp1, temp2;
                Mat cut = img(Range(x - 15 + (i * 30), x - 15 + (i + 1) * 30),
                              Range(y - 15 + (j * 30), y - 15 + (j + 1) * 30));
                Scharr(cut, temp1, CV_32F, 1, 0);
                Scharr(cut, temp2, CV_32F, 0, 1);
                temp1 = abs(temp1);
                temp2 = abs(temp2);
                double temp_sum = 1. / sum(temp1 + temp2)[0];
                if (temp_sum > max) {
                    max = temp_sum;
                    index1 = i;
                    index2 = j;
                }
            } catch (Exception &e) {
                e.formatMessage();
            }
        }
    }
    cout << "Found Direction: [" << index1 << ", " << index2 << "]" << endl;
    return img(Range(x - 15 + (index1 * 30), x - 15 + (index1 + 1) * 30),
               Range(y - 15 + (index2 * 30), y - 15 + (index2 + 1) * 30));
}

static void onMouse(int event, int x, int y, int flags, void *) {
    Mat display = img.clone();
    if (event == EVENT_LBUTTONUP) {
        Mat temp = FindBestPatch(x, y);
        Mat mask = Mat::zeros(30, 30, img.depth());
        circle(mask, Point(15, 15), 15, Scalar(255, 255, 255), -1, 8, 0);
        seamlessClone(temp, img, mask, Point(x, y), img, NORMAL_CLONE);
        display = img.clone();
    } else {
        circle(display, Point(x, y), 15, Scalar(255, 0, 0), 2, LINE_AA, 0);
    }
    imshow("Blemish", display);
}

int main() {
    imshow("Blemish", img);
    setMouseCallback("Blemish", onMouse, nullptr);
    waitKey(0);
    return 0;
}