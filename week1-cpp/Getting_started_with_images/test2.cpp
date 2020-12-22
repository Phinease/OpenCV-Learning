//
// Created by Shuangrui CHEN on 18/09/2020.
//
#include <iostream>
#include<string>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "dataPath.hpp"

using namespace std;
using namespace cv;

int main() {
    string name = "number_zero";
    namedWindow(name, WINDOW_AUTOSIZE);
    moveWindow(name, 0, 0);

    Mat img = imread(DATA_PATH + "images/" + name + ".jpg");
    imshow(name, img);

    Vec3b colors[3] = {Vec3b(0,255,255),
                       Vec3b(255,255,0),
                       Vec3b(255,0,255)};

    for (int i = 0; i < 3; ++i) {
        cout << img.at<Vec3b>(i, i);
        img.at<Vec3b>(i, i) = colors[i];
        string new_name = name + to_string((i+1));
        imshow(new_name, img);
        moveWindow(new_name, 600*(i+1), 0);
    }

    Scalar scalars[3] = {
            Scalar (255, 0, 0),
            Scalar (0, 255, 0),
            Scalar (0, 0, 255),
    };

    for (int i = 0; i < 3; ++i) {
        img.colRange(0, 3).rowRange(i*3, (i+1)*3).setTo(scalars[i]);
        string new_name = name + "_1_" + to_string((i+1));
        imshow(new_name, img);
        moveWindow(new_name, 600*(i+1), 200);
    }

    waitKey(0);
    destroyAllWindows();

    return 0;
}
