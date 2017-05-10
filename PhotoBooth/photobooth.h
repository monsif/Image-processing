#ifndef PHOTOBOOTH_H
#define PHOTOBOOTH_H

#include <QtWidgets/QMainWindow>
#include "ui_photobooth.h"

class PhotoBooth : public QMainWindow
{
	Q_OBJECT

public:
	PhotoBooth(QWidget *parent = 0);
	~PhotoBooth();

private:
	Ui::PhotoBoothClass ui;
};

#endif // PHOTOBOOTH_H
