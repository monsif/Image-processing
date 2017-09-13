// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#include "TakePhotoWindow.h"


// -----------------------------------------------------------------------------
QTakePhotoWindow::QTakePhotoWindow(QWidget *parent) :AbstractView(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, &QPushButton::clicked, this, &QTakePhotoWindow::handleButton);
}


void QTakePhotoWindow::handleButton()
{
	emit(next("TakePhotoWindow"));
}

// -----------------------------------------------------------------------------
QTakePhotoWindow::~QTakePhotoWindow()
{

}
