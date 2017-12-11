#include <iostream>
#include <stdio.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, const char **argv)
{
	std::cout << "Hello world!" << std::endl;
	const char* fName = argv[1];
	int cols = 1280, rows = 480;
	int framesize = cols * rows;

	FILE *pFile;
	char *imagedata;
	
	pFile = fopen(fName, "rb");
	// Memory allocation for bayer image data buffer.
	imagedata = (char*)malloc(sizeof(char) * framesize);

	// Read image data and store in buffer.
	fread(imagedata, sizeof(char), framesize, pFile);
	
	Mat img(rows, cols, CV_8U, imagedata);
	if (img.empty())
	{
		std::cout << "Could not open or find the image" << std::endl;
		cin.get();
		return -1;
	}

	imshow("Window", img);
	waitKey(0);
	destroyWindow("Window");

	return 0;
}
