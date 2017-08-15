#ifndef PHOTOPRINTFORMAT_H
#define PHOTOPRINTFORMAT_H

#include "ui_photoprintformat.h"
#include "AbstractView.h"
#include "qpushbutton.h"

class PhotoPrintFormat : public AbstractView
{
	Q_OBJECT

public:
	PhotoPrintFormat(QWidget *parent=0);
	~PhotoPrintFormat();

private slots:
void handleButton();

private:
	Ui::PhotoPrintFormat ui;
};

#endif // PHOTOPRINTFORMAT_H
