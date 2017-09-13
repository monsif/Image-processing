#ifndef STARTWINDOW_H_
#define STARTWINDOW_H_
// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#include <QWidget>
#include "ui_StartWindow.h"

// -----------------------------------------------------------------------------
class QStartWindow : public QWidget
{
	Q_OBJECT

public:
	QStartWindow(QWidget *parent = 0);
	~QStartWindow();

private:
	Ui::QStartWindow ui;
};

#endif // STARTWINDOW_H_
