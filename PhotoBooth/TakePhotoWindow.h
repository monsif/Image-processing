#ifndef TAKEPHOTOWINDOW_H_
#define TAKEPHOTOWINDOW_H_
// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION


#include "ui_TakePhotoWindow.h"
#include <AbstractView.h>
// -----------------------------------------------------------------------------

class QTakePhotoWindow : public AbstractView
{
	Q_OBJECT

public:
	QTakePhotoWindow(QWidget *parent);
	~QTakePhotoWindow();

signals:
	void next(std::string next);

private:
	Ui::QTakePhotoWindow ui;
};

#endif // TAKEPHOTOWINDOW_H_
