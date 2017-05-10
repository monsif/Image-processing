
#include "ImageProcessing.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;



Mat CImageProcessing::BlackAndWhiteFilter(char * imageSrc)
{
	Mat src = imread(imageSrc, 1);
	Mat gray_image;
	cvtColor(src, gray_image, CV_BGR2GRAY);
	return gray_image;
}

CImageProcessing::CImageProcessing()
{
}


CImageProcessing::~CImageProcessing()
{
}



