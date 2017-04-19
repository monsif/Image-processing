/*******************************************************************************
* TakePhotoWindow.h : le fichier header de la classe QTakePhotoWindow
*******************************************************************************
*
*
*
*******************************************************************************
* author	: Amine ELKHARROUBI
* date		:
* version	:
*******************************************************************************
*  LISTE DES CLASSES DU MODULE :
*
*  Class       : QTakePhotoWindow
*  Description :
*
*  LISTE DES FONCTIONS DU MODULE :
*
*******************************************************************************
* MODIFICATIONS
* -----------------------------------------------------------------------------
* Date			: Ver	: Auteur	: Ident		: Commentaires
* -----------------------------------------------------------------------------
* 	            : 	    : 	       :	        :
**************************************************************************** */
// -----------------------------------------------------------------------------
#ifndef TAKEPHOTOWINDOW_H_
#define TAKEPHOTOWINDOW_H_
// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#include <QWidget>
#include "ui_TakePhotoWindow.h"

// -----------------------------------------------------------------------------

class QTakePhotoWindow : public QWidget
{
	Q_OBJECT

public:
	QTakePhotoWindow(QWidget *parent = 0);
	~QTakePhotoWindow();

private:
	Ui::QTakePhotoWindow ui;
};

#endif // TAKEPHOTOWINDOW_H_
