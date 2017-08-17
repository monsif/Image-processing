#include "mainwindow.h"
#include <TechnicalConf.h>

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
{
	
}

void MainWindow::init()
{
	ui.setupUi(this);
	ui.frame->setProperty("class", "main");
	technicalConf = new CTechnicalConf();
	technicalConf->init("C:\\projects\\PhotoBooth\\photobooth_data\\technical.json");
	
	loadStyleSheet("C:\\projects\\PhotoBooth\\photobooth_data\\style-coffee.qss");
	
	std::string firstView=technicalConf->GetConfiguration()["FirstView"].get<std::string>();
	if (firstView.compare("Video") == 0) {
		abstractView = new QVideoView(technicalConf->GetConfiguration(),this);
	}
	
	connect(abstractView, &AbstractView::next, this, &MainWindow::handleNextView);
	
	ui.mainFrameLayout->addWidget(abstractView);

	eff = new QGraphicsOpacityEffect(this);
	eff->setOpacity(1.0);
	anim = new QPropertyAnimation(eff, "opacity");
	anim->setDuration(700);
	anim->setStartValue(1);
	anim->setEndValue(0);
	anim->setEasingCurve(QEasingCurve::OutBack);
	abstractView->setGraphicsEffect(eff);
	connect(anim, SIGNAL(finished()), this, SLOT(update()));
	//tmr = new QTimer();
	//connect(tmr, SIGNAL(timeout()), this, SLOT(update()));
}

void MainWindow::loadStyleSheet(QString cssFilePath)
{
	QFile styleFile(cssFilePath);
	styleFile.open(QFile::ReadOnly);
	QString style(styleFile.readAll());
	setStyleSheet(style);
}

void MainWindow::handleNextView(std::string nextView)
{	
	//yPos = abstractView->x() - 1;
	//hidingPoint = 0 - yPos - abstractView->size().height() + 1;
	MainWindow::nextView = getNextView(nextView);
	//tmr->start();
	anim->start();
}

AbstractView* MainWindow::getNextView(std::string nextView)
{
	nextView = technicalConf->GetConfiguration()["next"][nextView].get<std::string>();

	if (nextView.compare("TakePhotoWindow") == 0) {
		return new QTakePhotoWindow(this);
	}

	if (nextView.compare("FormWindow") == 0) {
		return new QFormWindow(technicalConf->getFormView(),this);
	}

	if (nextView.compare("PhotoPrintFormatView") == 0) {
		return new PhotoPrintFormat(technicalConf->GetConfiguration(), this);
	}

	if (nextView.compare("WelcomeWindow") == 0) {
		return new QVideoView(technicalConf->GetConfiguration(), this);
	}
}

void MainWindow::update()
{
	//if (yPos > hidingPoint)
	//{
	//	abstractView->move(yPos, abstractView->y());
	//	yPos = yPos-20;
	//}
	//else
	//{
	//	abstractView->hide();
	//	ui.right_layout->addWidget(nextView);
	//	abstractView = nextView;
	//	nextView = nullptr;
	//	connect(abstractView, &AbstractView::next, this, &MainWindow::handleNextView);
	//	abstractView->setGraphicsEffect(eff);
	//	tmr->stop();
	//}
	abstractView->hide();
	//delete abstractView;
	abstractView = nextView;
	nextView = nullptr;
	ui.mainFrameLayout->addWidget(abstractView);
	connect(abstractView, &AbstractView::next, this, &MainWindow::handleNextView);
	abstractView->setGraphicsEffect(eff);
	eff->setOpacity(1.0);
}

MainWindow::~MainWindow()
{

}