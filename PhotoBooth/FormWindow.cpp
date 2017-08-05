#include "FormWindow.h"
#include <qdebug.h> 

QFormWindow::QFormWindow(QWidget *parent): QWidget(parent)
{
	
}

QFormWindow::~QFormWindow()
{

}

void QFormWindow::init(json view_conf, QString cssFilePath)
{
	QFormWindow::view_conf = view_conf;
	ui.setupUi(this);
	initFields();
	initValidators();
	loadStyleSheet(cssFilePath);
	connect(nextButton, SIGNAL(released()), this, SLOT(handleButton()));
	connect(nameLineEdit, &QLineEdit::textEdited, this, &QFormWindow::onNameTextChanged);
	connect(phoneLineEdit, &QLineEdit::textEdited, this, &QFormWindow::onPhoneTextChanged);
	connect(jobLineEdit, &QLineEdit::textEdited, this, &QFormWindow::onJobTextChanged);
	connect(emailLineEdit, &QLineEdit::textEdited, this, &QFormWindow::onEmailTextChanged);
	connect(adressLineEdit, &QLineEdit::textEdited, this, &QFormWindow::onAdressTextChanged);

}

bool QFormWindow::validForm()
{
	return false;
}

void QFormWindow::reset()
{
}

void QFormWindow::initFields()
{
	///////INPUT TEXTS///////
	nameLineEdit = new QLineEdit(this);
	emailLineEdit = new QLineEdit(this);
	adressLineEdit = new QLineEdit(this);
	jobLineEdit = new QLineEdit(this);
	jobLineEdit->setText("Change this to Drop down list");
	birthday = new QDateEdit(this);
	phoneLineEdit = new QLineEdit(this);
	phoneLineEdit->setInputMethodHints(Qt::ImhDigitsOnly);

	//////////ERROR LABELS////////////
	nameError = new QLabel(this);
	emailError = new QLabel(this);
	phoneError = new QLabel(this);
	adressError = new QLabel(this);
	jobError = new QLabel(this);
	birthdayError = new QLabel(this);

	/////////////LOAD FIELD PROPERTIES//////////
	setupFieldsLineEdit(nameError, nameLineEdit, view_conf["input_name"]);
	setupFieldsLineEdit(emailError, emailLineEdit, view_conf["input_email"]);
	setupFieldsLineEdit(phoneError, phoneLineEdit, view_conf["input_phone"]);
	setupFieldsLineEdit(adressError, adressLineEdit, view_conf["input_adress"]);
	setupFieldsLineEdit(jobError, jobLineEdit, view_conf["input_job"]);

	/////////////DATE FIELDS///////////
	std::string label = view_conf["input_age"]["error"].get<std::string>();
	birthdayError->setText(QString::fromStdString(label));
	birthdayError->setVisible(false);
	ui.verticalLayout->addWidget(birthday);

	bool enabled = view_conf["input_age"]["enabled"].get<bool>();
	birthday->setVisible(enabled);
	ui.verticalLayout->addWidget(birthdayError);

	/////////////PUSH BUTTONS///////////
	nextButton = new QPushButton(this);
	nextButton->setText("NEXT");
	ui.verticalLayout->addWidget(nextButton);
}

void QFormWindow::initValidators()
{
	QRegularExpression re("^\\p{L}+(?: \\p{L}+)*$");
	textOnly = new QRegularExpressionValidator(re,0);

	QRegularExpression num("^0[1-9]{9}$");
	numericOnly = new QRegularExpressionValidator(num, 0);

	QRegularExpression email("^[A-z0-9_.+-]+@[A-z]{1,}+\\.[A-z]{2,3}+$");
	emailValid = new QRegularExpressionValidator(email, 0);
}

void QFormWindow::loadStyleSheet(QString cssFilePath)
{
	QFile styleFile(cssFilePath);
	styleFile.open(QFile::ReadOnly);
	QString style(styleFile.readAll());
	setStyleSheet(style);
	
}


void QFormWindow::setupFieldsLineEdit(QLabel* label, QLineEdit * lineEdit, json conf)
{

	std::string error = conf["error"].get<std::string>();
	label->setText(QString::fromStdString(error));

	std::string placeholder = conf["placeholder"].get<std::string>();
	lineEdit->setPlaceholderText(QString::fromStdString(placeholder));

	bool enabled = conf["enabled"].get<bool>();
	label->setVisible(false);
	lineEdit->setVisible(enabled);

	ui.verticalLayout->addWidget(lineEdit);
	ui.verticalLayout->addWidget(label);
}

/////////////////SLOTS/////////////////

void QFormWindow::handleButton()
{
	//TODO check mandatory field are set, the store data or send it to server.
}

void QFormWindow::onNameTextChanged(const QString &newValue)
{
	int pos = 0;
	QString value = newValue;
	value = value.remove(" ");
	QValidator::State s = textOnly->validate(value, pos);
	if (QValidator::Acceptable == s || value.size() == 0) {
		nameError->setVisible(false);
	}
	else {
		nameError->setVisible(true);
	}
	
}

void QFormWindow::onJobTextChanged(const QString &newValue)
{
	int pos = 0;
	QString value = newValue;
	value = value.remove(" ");
	QValidator::State s = textOnly->validate(value, pos);
	if (QValidator::Acceptable == s || value.size() == 0) {
		jobError->setVisible(false);
	}
	else {
		jobError->setVisible(true);
	}
}

void QFormWindow::onPhoneTextChanged(const QString &newValue)
{
	int pos = 0;
	QString value = newValue;
	QValidator::State s = numericOnly->validate(value, pos);
	if (QValidator::Acceptable == s || value.size() == 0) {
		phoneError->setVisible(false);
	}
	else {
		phoneError->setVisible(true);
	}

}

void QFormWindow::onEmailTextChanged(const QString &newValue)
{
	int pos = 0;
	QString value = newValue;
	value = value.remove(" ");
	QValidator::State s = emailValid->validate(value, pos);
	if (QValidator::Acceptable == s || value.size() == 0) {
		emailError->setVisible(false);
	}
	else {
		emailError->setVisible(true);
	}
}

void QFormWindow::onAdressTextChanged(const QString &newValue)
{
}
