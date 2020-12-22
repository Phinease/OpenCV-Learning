#include <opencv2/videoio.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace cv;

void put_text(int signal, Mat *frame);

int main(void) {
    // Open webcam
    VideoCapture cap(0);
    Mat frame;
    int k = 0;
    // Detect if webcam is working properly
    if (!cap.isOpened()) {
        cout << "Unable to detect webcam " << "\n";
        return 0;
    } else {
        while (1) {
            // Capture frame
            cap >> frame;
            if (k == 27)
                break;
            // Identify if 'e' or 'E' is pressed
            // Identify if 'z' or 'Z' is pressed or not
            put_text(k, &frame);
            imshow("Image", frame);
            // Waitkey is increased so that the display is shown
            int q = waitKey(1) & 0xFF;
            if (q != 255) {
                k = q;
            }
        }
    }
    cap.release();
    destroyAllWindows();

}

void put_text(int signal, Mat *frame) {
    switch (signal) {
        case 0:
            return;
        case 101:
        case 69:
            putText(*frame, "E is pressed, press Z or ESC", Point(100, 180), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0),
                    3);
            break;
        case 90:
        case 122:
            putText(*frame, "Z is pressed", Point(100, 180), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 3);
            break;
        default:
            return;
    }
}
