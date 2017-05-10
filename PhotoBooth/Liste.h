/*******************************************************************************
* Liste.h : le fichier header de la classe CListe
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
*  Class       : CListe
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

#ifndef LISTE_H_
#define LISTE_H_

// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#include "PhotoBoothHeader.h"
// -----------------------------------------------------------------------------

class CListe
{
private:

	int        m_iNumber;
	int        m_iSize;
	void	 **m_pTableau;
	T_Cellule *m_pFirst;
	T_Cellule *m_pLast;

public:

	CListe();
	CListe(int iSize);
	~CListe();

	int		PushLIFO(void* pElementInsert);
	int		PushFIFO(void* pElementInsert);
	int		PushElement(void* pElementInsert, int iIndex);
	int		InsertToList(void* pElementInsert, int iIndex);
	void*   PopFromList(int iIndex);
	void*	Pop(void);
	void*	PopIndex(int iIndex);/* Le premier élément à l'index 0*/
	void*	GetElement(int iIndex);
	int		CountElements(void);
	bool	IsEmpty(void);
	int		DeletElement(int iIndex);
	int		GetSizeTab();
	int		DeletElementList();
	void*	DeletByIndex(int iIndex);
};

#endif //LISTE_H_

