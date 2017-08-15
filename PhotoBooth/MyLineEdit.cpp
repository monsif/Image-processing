#include "MyLineEdit.h"


MyLineEdit::MyLineEdit(QWidget *parent)
	: QLineEdit(parent)
{}

MyLineEdit::~MyLineEdit()
{}

void MyLineEdit::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) {
		emit(focussed(true));
	}
}