/// Enter your code here
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Scalar color1 = Scalar(-1, -1, -1);
Scalar color2 = Scalar(-1, -1, -1);

Mat wall;
Mat frame;
Mat temp;
Mat lookUpTable(1, 256, CV_8U);
uchar *lut = lookUpTable.ptr();

int tolerance = 30;
int gussian = 0;
int inp = 0;
int cta = 0;


void refresh(int, void *);

void ScalarBGRA2HSV(Scalar &bgra);

void Keyring();

void ColorSelector(int action, int x, int y, int flags, void *userdata);

void interp(const float *fullRange, const float *Curve, const float *originalValue, uchar *lut_p);

int main() {
    VideoCapture video("greenscreen-demo.mp4");
    wall = imread("wall.jpg");
    // cout << wall << endl;

    if (!video.isOpened()) {
        cout << "Read Failed" << endl;
        return -1;
    }

    float originalValue[] = {0, 50, 100, 150, 200, 255};
    float gCurve[] = {0, 49, 97, 145, 190, 230};
    float fullRange[256];
    for (int i = 0; i < 256; i++) {
        fullRange[i] = (float) i;
    }
    interp(fullRange, gCurve, originalValue, lut);

    video >> frame;
    temp = frame.clone();
    imshow("Chroma Keying", temp);
    moveWindow("Chroma Keying", 100, 100);

    setMouseCallback("Chroma Keying", ColorSelector);

    createTrackbar("Tolerance", "Chroma Keying", &tolerance, 100, refresh);
    createTrackbar("GussianBlur", "Chroma Keying", &gussian, 1, refresh);
    createTrackbar("Inpaint", "Chroma Keying", &inp, 1, refresh);
    createTrackbar("Color Tone Adjustment", "Chroma Keying", &cta, 1, refresh);

    while (true) {
        video >> frame;
        temp = frame.clone();

        if (color2[0] == -1) {
            putText(temp, "Extract a deeper green color", Point(30, 100), FONT_HERSHEY_TRIPLEX, 3,
                    Scalar(255, 255, 255), 3, LINE_AA);
        } else if (color1[0] == -1) {
            putText(temp, "Extract a lighter green color", Point(30, 100), FONT_HERSHEY_TRIPLEX, 3,
                    Scalar(255, 255, 255), 3, LINE_AA);
        }

        try {
            Keyring();
        } catch (Exception &e) {
            cout << e.msg << endl;
            break;
        }
        imshow("Chroma Keying", temp);
        char c = (char) waitKey(25);
        if (c == 27)
            break;
    }

    video.release();
    return 0;
}

void refresh(int, void *) {
    temp = frame.clone();
    if (gussian) GaussianBlur(temp, temp, Size(3, 3), 5);
    Keyring();
}

void ScalarBGRA2HSV(Scalar &bgra) {
    Mat mat_bgra(1, 1, CV_8UC4, bgra);
    Mat mat_hsv;
    cvtColor(mat_bgra, mat_bgra, COLOR_BGRA2BGR);
    cvtColor(mat_bgra, mat_hsv, COLOR_BGR2HSV);
    bgra = Scalar(mat_hsv.data[0], mat_hsv.data[1], mat_hsv.data[2]);
}

void Keyring() {
    if (color1[0] == -1) return;
    Mat mask1, mask2;
    Mat hsv;

    cvtColor(temp, hsv, COLOR_BGR2HSV);
    inRange(hsv, Scalar(color1[0] - tolerance, color1[1] - tolerance, color1[2] - tolerance),
            Scalar(color1[0] + tolerance, color1[1] + tolerance, color1[2] + tolerance),
            mask1);
    if (color2[0] != -1) {
        inRange(hsv, Scalar(color2[0] - tolerance, color2[1] - tolerance, color2[2] - tolerance),
                Scalar(color2[0] + tolerance, color2[1] + tolerance, color2[2] + tolerance),
                mask2);
        mask1 = mask1 + mask2;
        max(mask1, 1);
    }

    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours(mask1, contours, hierarchy, RETR_LIST, CHAIN_APPROX_TC89_KCOS);
    Mat con = Mat::zeros(temp.size(), temp.depth());
    drawContours(con, contours, -1, Scalar(255, 255, 255), 6);


    vector<Mat> tempBGRs(3), wallBGRs(3), output(3);
    split(wall, wallBGRs);
    split(temp, tempBGRs);
    for (int i = 0; i < 3; ++i) {
        output[i] = tempBGRs[i].mul(1 - mask1) + wallBGRs[i].mul(mask1 / 255);
    }

    if (cta) {
        LUT(output[1], lookUpTable, output[1]);
        min(output[1], 255, output[1]);
        max(output[1], 0, output[1]);
    }

    merge(output, temp);

    if (inp) {
        inpaint(temp, con, temp, 1, INPAINT_NS);
    }
    imshow("Chroma Keying", temp);
}

void ColorSelector(int action, int x, int y, int flags, void *userdata) {
    if (action == EVENT_LBUTTONUP) {
        if (color1[0] == -1) {
            cout << "x: " << x << '\t' << "y: " << y << endl;
            cout << frame.size() << endl;
            color1 = mean(frame(Range(y - 10, y + 10), Range(x - 10, x + 10)));
            ScalarBGRA2HSV(color1);
            cout << "Color1 Selected: " << color1 << endl;
        } else if (color2[0] == -1) {
            cout << "x: " << x << '\t' << "y: " << y << endl;
            cout << frame.size() << endl;
            color2 = mean(frame(Range(y - 10, y + 10), Range(x - 10, x + 10)));
            ScalarBGRA2HSV(color2);
            cout << "Color2 Selected: " << color2 << endl;
        }
    } else {
        rectangle(temp, Point(x - 10, y - 10), Point(x + 10, y + 10), Scalar(255, 0, 0), 2, LINE_AA);
    }
    imshow("Chroma Keying", temp);
}

void interp(const float *fullRange, const float *Curve, const float *originalValue, uchar *lut_p) {
    int i;
    for (i = 0; i < 256; i++) {
        int j = 0;
        float a = fullRange[i];
        while (a > originalValue[j]) {
            j++;
        }
        if (a == originalValue[j]) {
            lut_p[i] = Curve[j];
            continue;
        }
        float slope = ((float) (Curve[j] - Curve[j - 1])) /
                      (originalValue[j] - originalValue[j - 1]);
        float constant = Curve[j] - slope * originalValue[j];
        lut_p[i] = slope * fullRange[i] + constant;
    }
}