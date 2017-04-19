/*******************************************************************************
* FormWindow.h : le fichier header de la classe QFormWindow
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
*  Class       : QFormWindow
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

#ifndef FORMWINDOW_H_
#define FORMWINDOW_H_

// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#include <QWidget>
#include "ui_FormWindow.h"

// -----------------------------------------------------------------------------

class QFormWindow : public QWidget
{
	Q_OBJECT

public:
	QFormWindow(QWidget *parent = 0);
	~QFormWindow();

private:
	Ui::QFormWindow ui;
};

#endif // FORMWINDOW_H_
