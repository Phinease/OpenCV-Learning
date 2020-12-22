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


int main () {
    string name = "musk";
    namedWindow(name, WINDOW_AUTOSIZE);
    moveWindow(name, 0, 0);

    Mat img = imread(DATA_PATH + "images/" + name + ".jpg");
    Mat imgChannels[3];
    split(img, imgChannels);

    // cout << img << endl;
    cout << "image size = " << img.size() << endl;
    cout << "image channels = " << img.channels() << endl;

    for (auto & imgChannel : imgChannels) {
        cout << "image size = " << imgChannel.size() << endl;
        cout << "image channels = " << imgChannel.channels() << endl;
    }

    imshow(name, img);
    for (int i = 0; i < 3; ++i) {
        string name_new = name + to_string(i);
        imshow(name_new, imgChannels[i]);
        moveWindow(name_new, img.cols*(i+1), 0);
        if (!imwrite("./results/" + name_new + ".jpg", imgChannels[i])) {
            printf("SAVE FAILED.\n");
        }
    }

    if (!imwrite("./results/" + name + ".jpg", img)) {
        printf("SAVE FAILED.\n");
    }

    waitKey(0);
    destroyAllWindows();

    return 0;
}
