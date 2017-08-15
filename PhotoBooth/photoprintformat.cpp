#include "photoprintformat.h"

PhotoPrintFormat::PhotoPrintFormat(QWidget *parent)
	:AbstractView(parent)
{
	ui.setupUi(this);
	connect(ui.multiple, &QPushButton::clicked, this, &PhotoPrintFormat::handleButton);
	connect(ui.single, &QPushButton::clicked, this, &PhotoPrintFormat::handleButton);
}

void PhotoPrintFormat::handleButton()
{
	emit(next("PhotoPrintFormatView"));
}

PhotoPrintFormat::~PhotoPrintFormat()
{

}
