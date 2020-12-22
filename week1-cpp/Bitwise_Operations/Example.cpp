#include <iostream>
#include "dataPath.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

string type2str(int type);

int main(){
	// Load the Face Image
	string faceImagePath = DATA_PATH + "/images/musk.jpg";
	Mat faceImage = imread(faceImagePath);
	faceImage(Range(10,90),Range(40,80)).setTo(Scalar(255,255,255));
	imshow("faceImage", faceImage);
	
	// Make a copy
	Mat faceWithGlassesBitwise = faceImage.clone();
	
	// Load the Sunglass image with Alpha channel
	string glassimagePath = DATA_PATH + "/images/sunglass.png";
	// Read the image
	Mat glassPNG = imread(glassimagePath,-1);
	// Resize the image to fit over the eye region
	resize(glassPNG,glassPNG, Size(300,100));
	cout << "image Dimension = " << glassPNG.size() << endl;
	
	// Separate the Color and alpha channels
	Mat glassRGBAChannels[4];
	Mat glassRGBChannels[3];
	split(glassPNG, glassRGBAChannels);
	for (int i = 0; i < 3; i++){
	    // Copy R,G,B channel from RGBA to RGB
	    glassRGBChannels[i] = glassRGBAChannels[i];
	}
	Mat glassBGR, glassMask1;
	// Prepare BGR Image
	merge(glassRGBChannels,3,glassBGR);
	// Alpha channel is the 4th channel in RGBA Image
	glassMask1 = glassRGBAChannels[3];
	imwrite("../results/sunglassRGB.png",glassBGR);
	imwrite("../results/sunglassAlpha.png",glassMask1);

	//imshow("Sunglass Color Channels", glassBGR);
	//imshow("Sunglass Alpha Channel", glassMask1);
	//waitKey(0);
	
	// Get the eye region from the face image
	Mat eyeROI = faceWithGlassesBitwise(Range(150,250),Range(140,440));

	// Make the dimensions of the mask same as the input image.
	// Since Face Image is a 3-channel image, we create a 3 channel image for the mask
	Mat glassMask;
	Mat glassMaskChannels[] = {glassMask1,glassMask1,glassMask1};
	merge(glassMaskChannels,3,glassMask);
	
	// Use the mask to create the masked eye region
	Mat eye;
	Mat glassMaskNOT;

	cout << type2str(glassMask1.type()) << endl;

	bitwise_not(glassMask1, glassMaskNOT);

	Mat eyeChannels[3];
	Mat eyeROIChannels[3];
	Mat maskedGlass;
	Mat eyeRoiFinal;
	
	split(eyeROI,eyeROIChannels);
	
	for (int i = 0; i < 3; i++)
	{
	    bitwise_and(eyeROIChannels[i], glassMaskNOT, eyeChannels[i]);
	}
	
	merge(eyeChannels,3,eye);
	
	imwrite("../results/glassMaskNOT.png",glassMaskNOT);
	
	Mat glassMaskNOTChannels[] = {glassMaskNOT,glassMaskNOT,glassMaskNOT};
	Mat glassMaskNOTMerged;
	merge(glassMaskNOTChannels,3,glassMaskNOTMerged);
	
	bitwise_and(eyeROI, glassMaskNOTMerged, eye);

	// Use the mask to create the masked sunglass region
	Mat sunglass;
	Mat sunglassChannels[3];
	Mat glassBGRChannels[3];
	
	split(glassBGR,glassBGRChannels);
    imshow("glassMask1", glassMask1);
	cout << glassMask1 << endl;
	for (int i=0; i < 3; i++)
	    bitwise_and(glassBGRChannels[i], glassMask1, sunglassChannels[i]);
	
	merge(sunglassChannels,3,sunglass);
    imshow("sunglass", sunglass);
    waitKey(0);
    destroyAllWindows();
	multiply(glassBGR, glassMask, maskedGlass);
	
	// Combine the Sunglass in the Eye Region to get the augmented image
	bitwise_or(eye, sunglass, eyeRoiFinal);

	imwrite("../results/maskedEyeRegionBitwise.png",eye);
	imwrite("../results/maskedSunglassRegionBitwise.png",sunglass);
	imwrite("../results/augmentedEyeAndSunglassBitwise.png",eyeRoiFinal);

	//imshow("Masked Eye Region",eye);
	//imshow("Masked Sunglass Region",sunglass);
	//imshow("Augmented Eye and Sunglass",eyeRoiFinal);
	//waitKey(0);
	
	// Replace the eye ROI with the output from the previous section
	eyeRoiFinal.copyTo(eyeROI);

	imwrite("../results/withSunglassesBitwise.png",faceWithGlassesBitwise);

	//imshow("With Sunglasses",faceWithGlassesBitwise);
	//waitKey(0);
	
	return 0;
}


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
