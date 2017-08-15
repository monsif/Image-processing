
#ifndef GUI_H_
#define GUI_H_

// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#include <QtWidgets/QMainWindow>
#include "ui_photobooth.h"

// -----------------------------------------------------------------------------

class QGui : public QMainWindow
{
	Q_OBJECT

public:
	QGui(QWidget *parent = 0);
	~QGui();

private:
	Ui::PhotoBoothClass ui;
};

#endif // GUI_H_
