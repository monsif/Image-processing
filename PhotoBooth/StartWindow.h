/*******************************************************************************
* StartWindow.h : le fichier header de la classe QStartWindow
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
*  Class       : QStartWindow
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
#ifndef STARTWINDOW_H_
#define STARTWINDOW_H_
// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#include <QWidget>
#include "ui_StartWindow.h"

// -----------------------------------------------------------------------------
class QStartWindow : public QWidget
{
	Q_OBJECT

public:
	QStartWindow(QWidget *parent = 0);
	~QStartWindow();

private:
	Ui::QStartWindow ui;
};

#endif // STARTWINDOW_H_
