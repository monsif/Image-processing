#include "Gui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QGui w;
	w.show();
	return a.exec();
}
