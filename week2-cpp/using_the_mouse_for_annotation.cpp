#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <cmath>
#include <vector>

using namespace cv;
using namespace std;

// Points to store the center of the circle and a point on the circumference
Point c1;
Point c2;
Point c3;
bool sign = false;
vector<Point> centers;
// Source image
Mat source;

void action() {
    for (int i = 0; i < centers.size() / 2; ++i) {
        // Calculate radius of the circle
        Point p1 = centers.at(i * 2 + 1);
        Point p2 = centers.at(i * 2);
        double radius = sqrt(pow(p1.x - p2.x, 2) +
                             pow(p1.y - p2.y, 2));
        // Draw the circle
        // Mark the center
        circle(source, p1, 1, Scalar(255, 255, 0), 2, LINE_AA);
        circle(source, p1, (int) radius, Scalar(0, 255, 0), 2, LINE_AA);

    }
    if (sign) {
        circle(source, c1, 1, Scalar(255, 255, 0), 2, LINE_AA);
        double radius = sqrt(pow(c1.x - c3.x, 2) +
                             pow(c1.y - c3.y, 2));
        circle(source, c1, (int) radius, Scalar(0, 255, 0), 2, LINE_AA);
    }
    imshow("Window", source);
}

// Function which will be called on mouse input
void drawCircle(int action, int x, int y, int flags, void *userdata) {

    // Action to be taken when left mouse button is pressed
    if (action == EVENT_LBUTTONDOWN) {
        c1 = Point(x, y);
        c2 = c1;
        c3 = c1;
        sign = true;
    }
        // Action to be taken when left mouse button is released
    else if (action == EVENT_LBUTTONUP) {
        c2 = Point(x, y);
        auto i = centers.begin();
        i = centers.insert(i, c1);
        i = centers.insert(i, c2);
        sign = false;
    } else if (sign) {
        c3 = Point(x, y);
    }
}

int main() {
    VideoCapture cap(0);
    source = imread("sample.jpg", 1);
    // Make a dummy image, will be useful to clear the drawing
    Mat dummy = source.clone();
    namedWindow("Window");
    // highgui function called when mouse events occur
    setMouseCallback("Window", drawCircle);
    int k = 0;
    // loop until escape character is pressed
    while (k != 27) {
        cap >> source;
        action();
        putText(source, "Choose center, and drag, Press ESC to exit and c to clear",
                Point(10, 30), FONT_HERSHEY_SIMPLEX,
                0.7, Scalar(255, 255, 255), 2);
        imshow("Window", source);
        k = waitKey(20) & 0xFF;
        if (k == 99)
            // Another way of cloning
            dummy.copyTo(source);
    }
    return 0;
}