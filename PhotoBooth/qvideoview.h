#ifndef QVIDEOVIEW_H
#define QVIDEOVIEW_H

#include <QWidget>
#include <AbstractView.h>
#include <QVideoWidget>
#include <QMouseEvent>
#include <QSizePolicy>
#include <QPalette>
#include <QKeyEvent>
#include "ui_qvideoview.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFile>
#include <QUrl>
#include <QString>
#include "json.hpp"
#include <unordered_set>

using json = nlohmann::json;

class QVideoView : public AbstractView
{
	Q_OBJECT

public:
	QVideoView(json conf,QWidget *parent = 0);
	~QVideoView();
protected:
	void keyPressEvent(QKeyEvent *event) override;
	void mouseDoubleClickEvent(QMouseEvent *event) override;
	void mousePressEvent(QMouseEvent *event) override;
private slots:
void handleNextButton();
signals:
void mouseClicked();
private:
	Ui::QVideoView ui;
	QVideoWidget *video;
	QMediaPlayer *player;
	QMediaPlaylist *playlist;
};

#endif // QVIDEOVIEW_H
