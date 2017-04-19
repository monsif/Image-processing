/*******************************************************************************
* StandbyWindow.h : le fichier header de la classe QStandbyWindow
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
*  Class       : QStandbyWindow
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

#ifndef STANDBYWINDOW_H_
#define STANDBYWINDOW_H_
// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#include <QWidget>
#include "ui_StandbyWindow.h"

// -----------------------------------------------------------------------------

class QStandbyWindow : public QWidget
{
	Q_OBJECT

public:
	QStandbyWindow(QWidget *parent = 0);
	~QStandbyWindow();

private:
	Ui::QStandbyWindow ui;
};

#endif // STANDBYWINDOW_H_
