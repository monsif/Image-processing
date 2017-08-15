#include "mainwindow.h"
#include <TechnicalConf.h>

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
{
	
}

void MainWindow::init()
{
	ui.setupUi(this);
	ui.MYFrame->setProperty("class", "main");
	technicalConf = new CTechnicalConf();
	technicalConf->init("C:\\projects\\PhotoBooth\\photobooth_data\\technical.json");
	
	loadStyleSheet("C:\\projects\\PhotoBooth\\photobooth_data\\style-coffee.qss");
	
	//setStyleSheet("MainWindow{background-image: url(C:/projects/PhotoBooth/PhotoBooth/Resources/335309.png);}");

	abstractView = new QFormWindow(technicalConf->getFormView(),this);
	
	connect(abstractView, &AbstractView::next, this, &MainWindow::handleNextView);
	
	ui.verticalLayout->addWidget(abstractView);

	yPos = abstractView->x() - 1;
	hidingPoint = 0 - yPos - abstractView->size().height() + 1;
	tmr = new QTimer();
	connect(tmr, SIGNAL(timeout()), this, SLOT(update()));
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
	nextView = technicalConf->GetConfiguration()["next"][nextView].get<std::string>();
	
	if (nextView.compare("TakePhotoWindow")==0) {
		MainWindow::nextView = new QTakePhotoWindow(this);
	}
	
	if (nextView.compare("FormWindow")==0) {
	////	MainWindow::nextView = formView;
	}
	
	if (nextView.compare("PhotoPrintFormat")==0) {
		//MainWindow::nextView = new PhotoPrintFormat();
	}
	
	tmr->start();
}

void MainWindow::update()
{
	if (yPos > hidingPoint)
	{
		abstractView->move(yPos, abstractView->y());
		yPos = yPos-20;
	}
	else
	{
		abstractView->hide();
	//	formView = nextView;
		ui.verticalLayout->addWidget(nextView);
		tmr->stop();
	}
}

MainWindow::~MainWindow()
{

}