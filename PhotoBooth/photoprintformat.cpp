#include "photoprintformat.h"

PhotoPrintFormat::PhotoPrintFormat(json conf,QWidget *parent)
	:AbstractView(parent)
{
	ui.setupUi(this);
	
	connect(ui.multiple, &QPushButton::clicked, this, &PhotoPrintFormat::handleButton);
	connect(ui.single, &QPushButton::clicked, this, &PhotoPrintFormat::handleButton);
	
	int id = QFontDatabase::addApplicationFont("C:\\projects\\PhotoBooth\\photobooth_data\\font.ttf");
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);
	
	int weight = conf["photo_text"]["weight"].get<int>();
	int point_size = conf["photo_text"]["point_size"].get<int>();
	bool italic = conf["photo_text"]["italic"].get<bool>();
	std::string text = conf["photo_text"]["value"].get<std::string>();
	
	QFont monospace(family, point_size,weight, italic);
	
	ui.label->setProperty("class", "photoText");
	ui.label->setText(QString::fromStdString(text));
	ui.label->setFont(monospace);
	
	ui.label_2->setProperty("class", "photoText");
	ui.label_2->setText(QString::fromStdString(text));
	ui.label_2->setFont(monospace);
	
}

void PhotoPrintFormat::handleButton()
{
	emit(next("PhotoPrintFormatView"));
}

PhotoPrintFormat::~PhotoPrintFormat()
{

}
