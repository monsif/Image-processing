#ifndef FORMWINDOW_H_
#define FORMWINDOW_H_

#include <QWidget>
#include <ui_FormWindow.h>
#include <QMainWindow>
#include <QPushButton>
#include <QFile>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include "json.hpp"

using json = nlohmann::json;

class QFormWindow : public QWidget
{
	Q_OBJECT

public:
	QFormWindow(QWidget *parent = 0);
	~QFormWindow();
	void init(json view_conf, QString cssFilePath);
	bool validForm();
	void reset();
private slots:
	void handleButton();
	void onNameTextChanged(const QString &);
	void onJobTextChanged(const QString &);
	void onPhoneTextChanged(const QString &);
	void onEmailTextChanged(const QString &);
	void onAdressTextChanged(const QString & newValue);
private:
	void initFields();
	void initValidators();
	void loadStyleSheet(QString cssFilePath);
	void setupFieldsLineEdit(QLabel * label, QLineEdit * lineEdit, json conf);
	json view_conf;
	Ui::QFormWindow ui;
	QValidator *textOnly;
	QValidator *numericOnly;
	QValidator *emailValid;
	QPushButton *nextButton;
	QDateEdit *birthday;
	QLineEdit *nameLineEdit,*phoneLineEdit, *adressLineEdit, *jobLineEdit, *emailLineEdit;
	QLabel *nameError, *phoneError, *jobError, *adressError, *emailError, *birthdayError;
};

#endif
