//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////   Test CImageProcessing         ////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "ImageProcessing.h"
#include "FunctionalConf.h"
#include "TechnicalConf.h"
#include "json.hpp"
using namespace cv;
using namespace std;
using json = Json::json;

int main(int argc, char** argv)
{
	Mat imageOut;
	CImageProcessing *pImageProcessing = NULL;

	pImageProcessing = new CImageProcessing();

	//imageOut = pImageProcessing->EnhanceFilter("C:\\Image_Test\\charlize-theron.jpg");
	//imageOut = pImageProcessing->StylizationFilter("C:\\Image_Test\\charlize-theron.jpg");
	//imageOut = pImageProcessing->NormconvFilter("C:\\Image_Test\\charlize-theron.jpg");
	//imageOut = pImageProcessing->SketchFilter("C:\\Image_Test\\charlize-theron.jpg");
	//imageOut = pImageProcessing->SketchGrayFilter("C:\\Image_Test\\charlize-theron.jpg");
	//imageOut = pImageProcessing->RecursFilter("C:\\Image_Test\\charlize-theron.jpg");
	  imageOut = pImageProcessing->GrayFilter("C:\\Image_Test\\Lenna.jpg");
	
//	if (imageOut.data)
//	{
//		namedWindow("Display window", CV_WINDOW_AUTOSIZE);
//		imshow("Display window", imageOut);
//	}
//
//
//	pImageProcessing->SaveImageProcessing("C:\\Image_Test\\charlize-theron_filter.jpg", imageOut);

	AllocConsole();
	freopen("coinin$", "w", stdout);
	
	//use argv to get configuration urls
	CFunctionalConf *functionalConf = new CFunctionalConf();
	functionalConf->LoadConf("C:\\projects\\PhotoBooth\\photobooth_data\\functional.json");
	json result = functionalConf->GetConfiguration();
	
	std::string s = result.dump(2);
	printf("Functional Properties : %s",s);
	
	getchar();
	waitKey(0);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////  Fin Test CImageProcessing      ////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////  Test QT      ///////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "Gui.h"
//#include <QtWidgets/QApplication>
//
//int main(int argc, char *argv[])
//{
//	QApplication a(argc, argv);
//	QGui w;
//	w.show();
//	return a.exec();
//}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// Fin Test QT   ///////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
