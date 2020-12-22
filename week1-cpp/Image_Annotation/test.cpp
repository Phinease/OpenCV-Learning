//
// Created by Shuangrui CHEN on 20/09/2020.
//
#include <iostream>
#include "dataPath.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

string type2str(int type) {
    string r;

    uchar depth = type & CV_MAT_DEPTH_MASK;
    uchar chans = 1 + (type >> CV_CN_SHIFT);

    switch ( depth ) {
        case CV_8U:  r = "8U"; break;
        case CV_8S:  r = "8S"; break;
        case CV_16U: r = "16U"; break;
        case CV_16S: r = "16S"; break;
        case CV_32S: r = "32S"; break;
        case CV_32F: r = "32F"; break;
        case CV_64F: r = "64F"; break;
        default:     r = "User"; break;
    }

    r += "C";
    r += (chans+'0');

    return r;
}

int main() {
    string imgPath = DATA_PATH + "/images/IDCard-Satya.png";
    Mat img = imread(imgPath, -1);

    imshow("IDCard", img);

    cout << img.size().height << " " << img.size().width << endl;

    Mat bbox, rectifiedImage;
    QRCodeDetector qrDecoder = QRCodeDetector();
    string opencvData = qrDecoder.detectAndDecode(img, bbox);

    cout << opencvData << endl;
    cout << bbox << endl;
    cout << "bbox: " << type2str(bbox.type()) << endl;

    if(opencvData.length()>0)
        cout << "QR Code Detected" << endl;
    else
        cout << "QR Code NOT Detected" << endl;

    cout << bbox.rows << endl;

    rectifiedImage = img.clone();
    Point pointTopLeft = Point(bbox.at<float>(0), bbox.at<float>(1));
    Point pointBottomRight = Point(bbox.at<float>(4), bbox.at<float>(5));

    cout << pointTopLeft << endl << pointBottomRight << endl;
    rectangle(rectifiedImage, pointTopLeft, pointBottomRight,
              Scalar(255, 0, 0), 5, LINE_8);

    imshow("rectifiedImage", rectifiedImage);

    waitKey(0);
    destroyAllWindows();

    return 0;
}