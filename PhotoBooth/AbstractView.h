#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H
#include <qwidget.h>
class AbstractView : public QWidget
{
	Q_OBJECT

public:
	AbstractView(QWidget *parent=0);
	~AbstractView();

signals:
	void next(std::string next);
};
#endif
