#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QPropertyAnimation>
#include <qtimer.h>
#include <QMessageBox>
#include <QFile>
#include <ViewFactory.h>
#include <TechnicalConf.h>
#include <FormWindow.h>
#include <TakePhotoWindow.h>
#include <AbstractView.h>

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	void init();
	~MainWindow();

public slots:
	void handleNextView(std::string nextView);
	void update();
private:
	Ui::MainWindow ui;
	CTechnicalConf *technicalConf;
	int yPos, hidingPoint;
	QTimer *tmr;
	ViewFactory *widgetFactory;
	AbstractView *abstractView,*nextView;
	void loadStyleSheet(QString cssFilePath);
	//handlePhotoView -> print/share photo
	//AbstractView *standByView, *printFormatView, *takePhotoView, *handlePhotoView, *waintingToPrintView;
};

#endif // MAINWINDOW_H