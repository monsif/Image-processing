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
	player->setVideoOutput(video);
	playlist = new QMediaPlaylist();

	std::unordered_set<std::string> videos = conf["videos"].get<std::unordered_set<std::string>>();
	for (auto& element : videos)
	{
	playlist->addMedia(QUrl::fromLocalFile(QString::fromStdString(element)));
	}
	playlist->setPlaybackMode(QMediaPlaylist::Loop);
	
	player->setPlaylist(playlist);
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
