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
#include <string>
using namespace cv;
using namespace std;
//using json = nlohmann::json;

int main(int argc, char** argv)
{
	Mat imageOut;
	CImageProcessing *pImageProcessing = NULL;

	pImageProcessing = new CImageProcessing();
	imageOut = pImageProcessing->EnhanceFilter("C:\\Image_Test\\Lenna.png");
	pImageProcessing->SaveImageProcessing("C:\\Image_out\\charlize-theron_filter1.png", imageOut);
	imageOut = pImageProcessing->StylizationFilter("C:\\Image_Test\\Lenna.png");
	pImageProcessing->SaveImageProcessing("C:\\\Image_out\\charlize-theron_filter2.png", imageOut);
	imageOut = pImageProcessing->NormconvFilter("C:\\Image_Test\\Lenna.png");
	pImageProcessing->SaveImageProcessing("C:\\\Image_out\\charlize-theron_filter3.png", imageOut);
	imageOut = pImageProcessing->SketchFilter("C:\\Image_Test\\Lenna.png");
	pImageProcessing->SaveImageProcessing("C:\\\Image_out\\charlize-theron_filter4.png", imageOut);
	imageOut = pImageProcessing->SketchGrayFilter("C:\\Image_Test\\Lenna.png");
	pImageProcessing->SaveImageProcessing("C:\\\Image_out\\charlize-theron_filter5.png", imageOut);
	imageOut = pImageProcessing->RecursFilter("C:\\Image_Test\\Lenna.png");
	pImageProcessing->SaveImageProcessing("C:\\\Image_out\\charlize-theron_filter6.png", imageOut);
	imageOut = pImageProcessing->GrayFilter("C:\\Image_Test\\Lenna.png");
	pImageProcessing->SaveImageProcessing("C:\\\Image_out\\charlize-theron_filter7.png", imageOut);
	/*if (imageOut.data)
	{
		namedWindow("Display window", CV_WINDOW_AUTOSIZE);
		imshow("Display window", imageOut);
	}*/


	

	/*AllocConsole();
	freopen("conin$", "w", stdout);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);*/
	
	//use argv to get configuration urls
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
//#include "FormWindow.h"
//#include <mainwindow.h>
//int main(int argc, char *argv[])
//{
//	QApplication app(argc, argv);
//	MainWindow *w_main = new MainWindow();
//	////QFormWindow w;
//	////CTechnicalConf *technicalConf = new CTechnicalConf();
//	////technicalConf->init("C:\\projects\\PhotoBooth\\photobooth_data\\technical.json");
//	////w.init(technicalConf->getFormView(), "C:\\projects\\PhotoBooth\\photobooth_data\\style-coffee.qss");
//	////w.show();
//	w_main->init();
//	w_main->show();
//	//QMediaPlaylist *playlist = new QMediaPlaylist();
//	//playlist->addMedia(QUrl("C:/projects/PhotoBooth/PhotoBooth/Resources/nespresso.mp4"));
//	////playlist->addMedia(QUrl("http://example.com/movie2.mp4"));
//	////playlist->addMedia(QUrl("http://example.com/movie3.mp4"));
//	//playlist->setCurrentIndex(1);
//	//
//	//QMediaPlayer *player = new QMediaPlayer();
//	//player->setPlaylist(playlist);
//	//
//	//QVideoWidget *videoWidget = new QVideoWidget();
//	//player->setVideoOutput(videoWidget);
//	//videoWidget->show();
//	//
//	//player->play();
//	return app.exec();
//}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// Fin Test QT   ///////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//#include <QtGui>
//#include <QDate>
//#include <QApplication>
//#include "DatePopup.h"
//#include <iostream>
//
//int main(int argc, char *argv[])
//{
//	QApplication a(argc, argv);
//
//	DatePopup popup;
//
//	int result = popup.exec();
//	if (result == QDialog::Accepted) {
//		QDate date = popup.selectedDate();
//		std::cout << date.year() << std::endl;
//		std::cout << date.month() << std::endl;
//		std::cout << date.day() << std::endl;
//	}
//
//	return a.exec();
//}