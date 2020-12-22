// Include libraries
#include <iostream>
#include "dataPath.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;

int main(void){

    // Path to the image we are going to read
    // This can be an absolute or relative path
    // Here we are using a relative path

    string imageName = DATA_PATH+"images/boy.jpg";

    // Load the image
    Mat image;
    image = imread(imageName, IMREAD_COLOR);

	// Put text on image
	Mat imageText = image.clone();
	string text = "I am studying";
	double fontScale = 1.5;
	int fontFace = FONT_HERSHEY_COMPLEX;
	Scalar fontColor = Scalar(250, 10, 10);
	int fontThickness = 2;

	putText(imageText, text, Point(20, 350), fontFace, fontScale, fontColor, fontThickness, LINE_AA);

	imwrite("../results/text.jpg",imageText);
	imshow("Drawing text on image", imageText);
	moveWindow("Drawing text on image", 0, 0);

	int pixelHeight = 20;

	// Calculate the fontScale
	fontScale = getFontScaleFromHeight(fontFace, pixelHeight, fontThickness);
	cout << "fontScale = " << fontScale << endl;
	
	Mat imageTextFontScale;
	imageTextFontScale = image.clone();
	putText(imageTextFontScale, text, Point(20, 350), fontFace, fontScale, fontColor, fontThickness, LINE_AA);

	imwrite("../results/text2.jpg",imageTextFontScale);
	imshow("Text written using fontScale",imageTextFontScale);
    moveWindow("Text written using fontScale", imageText.size().width, 0);

	Mat imageGetTextSize;
	imageGetTextSize = image.clone();
	int imageHeight = imageGetTextSize.rows;
	int imageWidth = imageGetTextSize.cols;

	// Get the text box height and width and also the baseLine
	int baseLine = 0;
	Size textSize = getTextSize(text,fontFace,fontScale,fontThickness, &baseLine);
	int textWidth = textSize.width;
	int textHeight = textSize.height;

	cout << "TextWidth = " << textWidth << ", TextHeight = " << textHeight << ", baseLine = " << baseLine << endl;

	// Get the coordinates of text box bottom left corner
	// The xccordinate will be such that the text is centered
	int xcoordinate = (imageWidth - textWidth)/2;
	// The y coordinate will be such that the entire box is just 10 pixels above the bottom of image
	int ycoordinate = (imageHeight - baseLine - 10);

	cout << "TextBox Bottom Left = (" << xcoordinate << "," << ycoordinate << ")" << endl;

	// Draw the Canvas using a filled rectangle
	Scalar canvasColor = Scalar(255, 255, 255);
	Point canvasBottomLeft (xcoordinate,ycoordinate+baseLine);
	Point canvasTopRight (xcoordinate+textWidth, ycoordinate-textHeight);
	
	rectangle(imageGetTextSize, canvasBottomLeft, canvasTopRight, canvasColor, -1);

	cout << "Canvas Bottom Left = " << canvasBottomLeft << ", Top Right = " << canvasTopRight << endl;

	// Now draw the baseline ( just for reference )
	int lineThickness = 2;
	Point lineLeft (xcoordinate, ycoordinate);
	Point lineRight (xcoordinate+textWidth, ycoordinate);
	Scalar lineColor = Scalar(0,255,0);

	line(imageGetTextSize, lineLeft, lineRight, lineColor, lineThickness, LINE_AA);

	// Finally Draw the text
	putText(imageGetTextSize, text, Point(xcoordinate,ycoordinate), fontFace, fontScale, fontColor, fontThickness, LINE_AA);

	imwrite("../results/text3.jpg",imageGetTextSize);

	imshow("Write image using calculated text size",imageGetTextSize);
    moveWindow("Write image using calculated text size", 0, imageText.rows+100);

    Mat grey_image;
    cvtColor(imageGetTextSize, grey_image, COLOR_BGR2GRAY);
    imshow("Grey", grey_image);
    moveWindow("Grey", imageWidth, imageHeight+100);

	Mat HSVs[3];
	Mat HSV;
    cvtColor(imageGetTextSize, HSV, COLOR_BGR2HSV);
    split(HSV, HSVs);

    for (int i = 0; i < 3; ++i) {
        imshow("HSV"+to_string(i),HSVs[i]);
        moveWindow("HSV"+to_string(i), imageWidth*i, imageHeight);
    }
    waitKey(0);
	destroyAllWindows();
	return 0;
}
