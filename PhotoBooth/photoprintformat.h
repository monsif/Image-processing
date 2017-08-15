#ifndef PHOTOPRINTFORMAT_H
#define PHOTOPRINTFORMAT_H

#include "ui_photoprintformat.h"

class PhotoPrintFormat : public QWidget
{
	Q_OBJECT

public:
	PhotoPrintFormat(QWidget *parent=0);
	~PhotoPrintFormat();

private:
	Ui::PhotoPrintFormat ui;
};

#endif // PHOTOPRINTFORMAT_H
