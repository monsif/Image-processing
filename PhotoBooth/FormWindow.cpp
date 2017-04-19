/*******************************************************************************
* FormWindow.cpp : le fichier header de la classe QFormWindow
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

// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#include "FormWindow.h"

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// QFormWindow::QFormWindow
/////** \brief Le constructeur de la classe QFormWindow.
/*
* @param[char* ]
* @exception
* @return
*
* @details Traitement :
*
*
*/
// -----------------------------------------------------------------------------
QFormWindow::QFormWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

// -----------------------------------------------------------------------------
// QFormWindow::~QFormWindow
/////** \brief Le destructeur de la classe QFormWindow.
/*
* @param[char* ]
* @exception
* @return
*
* @details Traitement :
*
*
*/
// -----------------------------------------------------------------------------
QFormWindow::~QFormWindow()
{

}
