#include "qvideoview.h"

QVideoView::QVideoView(json conf,QWidget *parent)
	: AbstractView(parent)
{
	
	ui.setupUi(this);
	video = new QVideoWidget(this);
	video->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

	QPalette p = palette();
	p.setColor(QPalette::Window, Qt::black);
	video->setPalette(p);

	video->setAttribute(Qt::WA_OpaquePaintEvent);
	//video->setFullScreen(true);

	connect(this, &QVideoView::mouseClicked, this, &QVideoView::handleNextButton);
	ui.videoLayout->addWidget(video);
	
	player = new QMediaPlayer(this);
	// owned by PlaylistModel
	//playlist = new QMediaPlaylist(player);
	//player->setPlaylist(playlist);
	player->setVideoOutput(video);

	//const QString path = QString::fromStdString();
	//QFile file("C:/projects/PhotoBooth/PhotoBooth/Resources/nespresso.mp4");
	std::string path = conf["video_path"].get<std::string>();
	player->setMedia(QUrl::fromLocalFile(QString::fromStdString(path)));
	video->show();
	player->play();
}

void QVideoView::handleNextButton()
{
	
	emit(next("WelcomeWindow"));

}

QVideoView::~QVideoView()
{

}

void QVideoView::keyPressEvent(QKeyEvent * event)
{
}

void QVideoView::mouseDoubleClickEvent(QMouseEvent * event)
{
}

void QVideoView::mousePressEvent(QMouseEvent * event)
{
	QWidget::mousePressEvent(event);
	emit(mouseClicked());
}
