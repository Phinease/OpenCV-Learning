//Include opencv header files
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {

    VideoCapture cap("chaplin.mp4");
    // Check if camera opened successfully and read a frame from the object cap
    if (!cap.isOpened()) {
        cout << "Error opening video stream or file" << endl;
        return -1;
    }

    cout << cap.get(CAP_PROP_FRAME_HEIGHT) << endl;
    cout << cap.get(CAP_PROP_FRAME_WIDTH) << endl;
    cout << cap.get(CAP_PROP_FRAME_COUNT) << endl;

    // Set position of video to 2.5 seconds
    cap.set(CAP_PROP_POS_MSEC, 3000);

    // Width
    cap.set(CAP_PROP_FRAME_WIDTH, 600);

    // Height
    cap.set(CAP_PROP_FRAME_HEIGHT, 600);

    Mat frame;
    cap >> frame;

    imshow("Frame", frame);
    waitKey(0);
/*
  while(1){

    Mat frame;
    // Capture frame-by-frame
    cap >> frame;

    // If the frame is empty, break immediately
    if (frame.empty())
      break;

    // Display the resulting frame
    imshow( "Frame", frame );

    // Press ESC on keyboard to exit
    char c = (char)waitKey(25);
    if (c == 27)
      break;
  }
*/

    // When everything done, release the video capture object
    cap.release();

    // Closes all the frames
    destroyAllWindows();

    return 0;
}
