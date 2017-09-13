#ifndef FORMWINDOW_H_
#define FORMWINDOW_H_

#include <ui_FormWindow.h>
#include <QPushButton>
#include <QFile>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QComboBox>
#include <set>
#include <unordered_set>
#include "MyLineEdit.h"
#include "json.hpp"
#include <AbstractView.h>

using json = nlohmann::json;

class QFormWindow : public AbstractView
{
	Q_OBJECT

public:
	QFormWindow(json conf,QWidget *parent);
	~QFormWindow();
	void init(json view_conf);
	bool validForm();
	void reset();
	QPushButton *nextButton;

private slots:
	void handleButton();
	void onNameTextChanged(const QString &);
	void onJobTextChanged(const QString &);
	void onPhoneTextChanged(const QString &);
	void onEmailTextChanged(const QString &);
	void onAdressTextChanged(const QString & newValue);
	void handleMyLineEdit(bool hasfocus);
	void handleDayEdit(const QString & value);
	void handleMonthEdit(const QString & value);
	void handleYearEdit(const QString & value);
	void handleNextButton();

private:
	void initFields();
	void initValidators();
	void setupFieldsLineEdit(QLabel * label, QLineEdit * lineEdit,std::string confName);
	json view_conf;
	Ui::QFormWindow ui;
	QValidator *textOnly;
	QValidator *numericOnly;
	QValidator *phoneValid;
	QValidator *emailValid;
	QComboBox *job;
	MyLineEdit *lineEdit ,*day, *month, *year;
	QHBoxLayout *birthdayLayout;
	QLineEdit *nameLineEdit,*phoneLineEdit, *adressLineEdit, *emailLineEdit;
	bool email_, job_, birthday_, adress_, name_, phone_;
	QLabel *nameError, *phoneError, *jobError, *adressError, *emailError, *birthdayError, *birthdayLabel;
};

#endif
