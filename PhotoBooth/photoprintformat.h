#ifndef PHOTOPRINTFORMAT_H
#define PHOTOPRINTFORMAT_H

#include "ui_photoprintformat.h"
#include "AbstractView.h"
#include "qpushbutton.h"
#include <QFontDatabase>
#include "json.hpp"
using json = nlohmann::json;

class PhotoPrintFormat : public AbstractView
{
	Q_OBJECT

public:
	PhotoPrintFormat(json conf, QWidget *parent=0);
	~PhotoPrintFormat();

private slots:
void handleButton();

private:
	Ui::PhotoPrintFormat ui;
};

#endif // PHOTOPRINTFORMAT_H
