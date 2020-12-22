#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Point pointTopLeft;
Point pointBottomRight;
bool sign = false;
Mat original;
Mat source;


void drawRectangle(int action, int x, int y, int flags, void *userdata) {
    if (action == EVENT_LBUTTONDOWN) {
        pointTopLeft = Point(x, y);
        sign = true;
    } else if (action == EVENT_LBUTTONUP) {
        source = original.clone();
        pointBottomRight = Point(x, y);
        rectangle(source, pointTopLeft, pointBottomRight, Scalar(255,0,0),
                  2, LINE_AA);
        sign = false;

        putText(source, "Press Esc to save or redraw the rectangle.", Point(10, 30),
                FONT_HERSHEY_SIMPLEX, 0.6, Scalar(255, 255, 255), 2);
        putText(original, "Press Esc to save or redraw the rectangle.", Point(10, 30),
                 FONT_HERSHEY_SIMPLEX, 0.6, Scalar(255, 255, 255), 2);
    } else if (sign) {
        source = original.clone();
        Point pointActual = Point(x, y);
        rectangle(source, pointTopLeft, pointActual, Scalar(255,0,0),
                  2, LINE_AA);
    }

}


int main() {

    original = imread("sample.jpg", IMREAD_UNCHANGED);
    source = original.clone();
    namedWindow("Homework", WINDOW_AUTOSIZE);

    setMouseCallback("Homework", drawRectangle);

    int k = 0;
    while (k != 27) {
        imshow("Homework", source);
        k = waitKey(20) & 0xFF;
    }

    Mat res = imread("sample.jpg", IMREAD_UNCHANGED);
    try {
        res = res(Range(pointTopLeft.y, pointBottomRight.y),
                  Range(pointTopLeft.x, pointBottomRight.x));
        imwrite("face.png", res);
    } catch (Exception &e) {
        cout << "Draw dirction reversed: " << endl
        << e.err << endl << "TRY DRAW FROM TOP-LEFT TO BOTTOM-RIGHT" << endl;
    }
    destroyAllWindows();
    return 0;

}
