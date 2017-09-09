#include <QLineEdit>
#include <QMouseEvent>
class MyLineEdit : public QLineEdit
{
	Q_OBJECT

public:
	MyLineEdit(QWidget *parent = 0);
	~MyLineEdit();

signals:
	void focussed(bool hasFocus);

protected:
 void mouseReleaseEvent(QMouseEvent *event) override;
};