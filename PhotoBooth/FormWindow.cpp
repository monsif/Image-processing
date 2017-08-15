#include "FormWindow.h"

QFormWindow::QFormWindow(json conf,QWidget *parent):AbstractView(parent)
{
	init(conf);
	ui.setupUi(this);
}

QFormWindow::~QFormWindow()
{

}

void QFormWindow::init(json view_conf)
{
	QFormWindow::view_conf = view_conf;
	ui.setupUi(this);
	initFields();
	initValidators();
	QWidget::connect(nextButton, &QPushButton::released, this, &QFormWindow::handleButton);
	QWidget::connect(nameLineEdit, &QLineEdit::textEdited, this, &QFormWindow::onNameTextChanged);
	QWidget::connect(phoneLineEdit, &QLineEdit::textEdited, this, &QFormWindow::onPhoneTextChanged);
	QWidget::connect(emailLineEdit, &QLineEdit::textEdited, this, &QFormWindow::onEmailTextChanged);
	QWidget::connect(adressLineEdit, &QLineEdit::textEdited, this, &QFormWindow::onAdressTextChanged);
	QWidget::connect(lineEdit, &MyLineEdit::focussed, this, &QFormWindow::handleMyLineEdit);
	QWidget::connect(day, &QLineEdit::textChanged, this, &QFormWindow::handleDayEdit);
	QWidget::connect(month, &QLineEdit::textChanged, this, &QFormWindow::handleMonthEdit);
	QWidget::connect(year, &QLineEdit::textChanged, this, &QFormWindow::handleYearEdit);
	QWidget::connect(nextButton, &QPushButton::pressed, this, &QFormWindow::handleNextButton);

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
	day = new MyLineEdit(this);
	day->setMaxLength(2);
	day->setInputMethodHints(Qt::ImhDigitsOnly);
	month = new MyLineEdit(this);
	month->setMaxLength(2);
	month->setInputMethodHints(Qt::ImhDigitsOnly);
	year = new MyLineEdit(this);
	year->setMaxLength(4);
	year->setInputMethodHints(Qt::ImhDigitsOnly);
	phoneLineEdit = new QLineEdit(this);
	phoneLineEdit->setInputMethodHints(Qt::ImhDigitsOnly);


	//////////ERROR LABELS////////////
	nameError = new QLabel(this);
	nameError->setProperty("class", "error_label");
	emailError = new QLabel(this);
	emailError->setProperty("class", "error_label");
	phoneError = new QLabel(this);
	phoneError->setProperty("class", "error_label");
	adressError = new QLabel(this);
	adressError->setProperty("class", "error_label");
	jobError = new QLabel(this);
	jobError->setProperty("class", "error_label");
	birthdayError = new QLabel(this);
	birthdayError->setProperty("class", "error_label");
	birthdayLabel = new QLabel(this);
	job = new QComboBox(this);
	lineEdit = new MyLineEdit(this);
	birthdayLayout = new QHBoxLayout(this);

	/////////////LOAD FIELD PROPERTIES//////////
	setupFieldsLineEdit(nameError, nameLineEdit, "input_name");
	setupFieldsLineEdit(emailError, emailLineEdit, "input_email");
	setupFieldsLineEdit(phoneError, phoneLineEdit, "input_phone");
	setupFieldsLineEdit(adressError, adressLineEdit, "input_adress");
	//////////////ComboBox Jobs List////////////
	bool job_enabled = view_conf["fields"]["input_job"]["enabled"].get<bool>();
	std::string job_p = view_conf["input_job"]["placeholder"].get<std::string>();
	std::string job_error = view_conf["input_job"]["error"].get<std::string>();
	jobError->setVisible(false);
	jobError->setText(QString::fromStdString(job_error));
	std::unordered_set<std::string> jobs = view_conf["input_job"]["jobs"].get<std::unordered_set<std::string>>();
	for (auto& element:jobs) 
	{
		job->addItem(QString::fromStdString(element));
	}
	job->setEditable(true);
	job->setLineEdit(lineEdit);
	job->lineEdit()->setText(QString::fromStdString(job_p));
	job->lineEdit()->setReadOnly(true);
	job->setVisible(job_enabled);
	ui.verticalLayout_3->addWidget(job);
	ui.verticalLayout_3->addWidget(jobError);
	/////////////DATE FIELDS///////////
	//setupFieldsLineEdit(birthdayError, birthday, view_conf["input_age"]);
	std::string error_age = view_conf["input_age"]["error"].get<std::string>();
	birthdayError->setText(QString::fromStdString(error_age));

	std::string placeholder_day = view_conf["input_age"]["placeholder_day"].get<std::string>();
	std::string placeholder_month = view_conf["input_age"]["placeholder_month"].get<std::string>();
	std::string placeholder_year = view_conf["input_age"]["placeholder_year"].get<std::string>();
	day->setPlaceholderText(QString::fromStdString(placeholder_day));
	month->setPlaceholderText(QString::fromStdString(placeholder_month));
	year->setPlaceholderText(QString::fromStdString(placeholder_year));

	bool age_enabled = view_conf["fields"]["input_age"]["enabled"].get<bool>();
	day->setVisible(age_enabled);
	month->setVisible(age_enabled);
	year->setVisible(age_enabled);
	birthdayLabel->setVisible(age_enabled);
	birthdayError->setVisible(false);

	std::string label_age = view_conf["input_age"]["label"].get<std::string>();
	birthdayLabel->setText(QString::fromStdString(label_age));
	birthdayLabel->setProperty("class","birthday_label");

	birthdayLayout->addWidget(birthdayLabel);
	birthdayLayout->addWidget(day);
	birthdayLayout->addWidget(month);
	birthdayLayout->addWidget(year);
	ui.verticalLayout_3->addLayout(birthdayLayout);
	ui.verticalLayout_3->addWidget(birthdayError);
	/////////////PUSH BUTTONS///////////
	std::string label_b = view_conf["button_next"]["label"].get<std::string>();
	nextButton = new QPushButton(this);
	nextButton->setText(QString::fromStdString(label_b));
	ui.verticalLayout_3->addWidget(nextButton);

	////////////Mandatory fields///////////
	email_ = view_conf["fields"]["input_email"]["mandatory"].get<bool>();
	job_= view_conf["fields"]["input_job"]["mandatory"].get<bool>();
	birthday_= view_conf["fields"]["input_age"]["mandatory"].get<bool>();
	adress_= view_conf["fields"]["input_adress"]["mandatory"].get<bool>();
	name_= view_conf["fields"]["input_name"]["mandatory"].get<bool>();
	phone_= view_conf["fields"]["input_phone"]["mandatory"].get<bool>();
}

void QFormWindow::initValidators()
{
	QRegularExpression re("^\\p{L}+(?: \\p{L}+)*$");
	textOnly = new QRegularExpressionValidator(re,0);

	QRegularExpression phone("^0[1-9]{9}$");
	phoneValid = new QRegularExpressionValidator(phone, 0);

	QRegularExpression num("[0-9]*");
	numericOnly = new QRegularExpressionValidator(num, 0);

	QRegularExpression email("^[A-z0-9_.+-]+@[A-z]{1,}+\\.[A-z]{2,3}+$");
	emailValid = new QRegularExpressionValidator(email, 0);
}


void QFormWindow::setupFieldsLineEdit(QLabel* label, QLineEdit * lineEdit, std::string confName)
{

	std::string error = view_conf[confName]["error"].get<std::string>();
	label->setText(QString::fromStdString(error));

	std::string placeholder = view_conf[confName]["placeholder"].get<std::string>();
	lineEdit->setPlaceholderText(QString::fromStdString(placeholder));

	bool enabled = view_conf["fields"][confName]["enabled"].get<bool>();
	label->setVisible(false);
	lineEdit->setVisible(enabled);

	ui.verticalLayout_3->addWidget(lineEdit);
	ui.verticalLayout_3->addWidget(label);
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
		if(name_)
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
		if(job_)
		jobError->setVisible(true);
	}
}

void QFormWindow::onPhoneTextChanged(const QString &newValue)
{
	int pos = 0;
	QString value = newValue;
	QValidator::State s = phoneValid->validate(value, pos);
	if (QValidator::Acceptable == s || value.size() == 0) {
		phoneError->setVisible(false);
	}
	else {
		if(phone_)
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
		if(email_)
		emailError->setVisible(true);
	}
}

void QFormWindow::onAdressTextChanged(const QString &newValue)
{
}

void QFormWindow::handleMyLineEdit(bool hasfocus)
{
	
	if (hasfocus)
	{	
		job->showPopup();
	}

}

void QFormWindow::handleDayEdit(const QString & value_)
{
	int pos = 0;
	QString value = value_;
	QValidator::State s = numericOnly->validate(value, pos);
	
	if (QValidator::Acceptable != s)
		day->setText("");
	
	if (birthday_) {
		if (day->text().length() + month->text().length() + year->text().length() < 8) {
			birthdayError->setVisible(true);
		}
		else {
			birthdayError->setVisible(false);
		}
	}

	if (day->text().length() == 2)
		month->setFocus();

}

void QFormWindow::handleMonthEdit(const QString & value_)
{
	int pos = 0;
	QString value = value_;
	QValidator::State s = numericOnly->validate(value, pos);
	if (QValidator::Acceptable != s)
		month->setText("");
	
	if (birthday_) {
		if (day->text().length() + month->text().length() + year->text().length() < 8) {
			birthdayError->setVisible(true);
		}
		else {
			birthdayError->setVisible(false);
		}
	}

	if (month->text().length() == 2)
		year->setFocus();
	
}

void QFormWindow::handleYearEdit(const QString & value_)
{
	int pos = 0;
	QString value = value_;
	QValidator::State s = numericOnly->validate(value, pos);
	if (QValidator::Acceptable != s)
		year->setText("");

	if (value.length() == 4) {
		if (birthday_) {
			if (day->text().length() + month->text().length() + year->text().length() < 8) {
				birthdayError->setVisible(true);
			}
			else {
				birthdayError->setVisible(false);
			}
		}
	}
}

void QFormWindow::handleNextButton()
{
	QLabel *labels[6] = { nameError, phoneError, jobError, adressError, emailError, birthdayError };
	for (auto& label_ : labels) 
	{
		if (label_->isVisible()) 
		{
			nextButton->setEnabled(false);
			break;
		}
	}

	if (nextButton->isEnabled()) 
	{
		emit(next("FormWindow"));
	}
}