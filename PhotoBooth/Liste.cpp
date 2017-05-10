/*******************************************************************************
* Liste.cpp : le fichier header de la classe CListe
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

// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#include "Liste.h"

// -----------------------------------------------------------------------------
using namespace std;



// -----------------------------------------------------------------------------
// CListe::CListe
/** \constructeur
* @param[in ]
* @exception
* @return
*
* @details Traitement :
* constructeur
*/
// -----------------------------------------------------------------------------
CListe::CListe()
{
	m_iSize = 0;
	m_iNumber = 0;
	m_pTableau = NULL;
	m_pFirst = NULL;
	m_pLast = NULL;
}

// -----------------------------------------------------------------------------
// CListe::CListe
/** \constructeur d'initilisation de la taille
* @param[in ]
* @exception
* @return
*
* @details Traitement :
* constructeur d'initilisation de la taille du tableau
* qui contient les adresses des éléments
*/
// -----------------------------------------------------------------------------
CListe::CListe(int iSize)
{
	m_iSize = iSize;
	m_iNumber = 0;
	m_pFirst = NULL;
	m_pLast = NULL;
	m_pTableau = (void**)malloc(m_iSize);

	memset(m_pTableau, NULL, m_iSize);
	if (m_pTableau == NULL)
		exit(0);
}

// -----------------------------------------------------------------------------
// CListe::~CListe
/** \destructeur
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
* destructeur
*/
// -----------------------------------------------------------------------------
CListe::~CListe()
{
	if (m_pTableau)
		free(m_pTableau);
	m_pTableau = NULL;

	if (m_pFirst == m_pLast)
	{
		if (m_pFirst)
			delete m_pFirst;
		m_pFirst = NULL;
		m_pLast = NULL;
	}
	else
	{
		if (m_pFirst)
			delete m_pFirst;
		m_pFirst = NULL;
		if (m_pLast)
			delete m_pLast;
		m_pLast = NULL;
	}

}

// -----------------------------------------------------------------------------
// CListe::PushLIFO
/** \Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*   Inserer au début de la liste
*/
// -----------------------------------------------------------------------------
int CListe::PushLIFO(void* pElementInsert)
{
	T_Cellule *pNode = (T_Cellule*)malloc(sizeof(T_Cellule));

	if (pNode != NULL)
	{
		pNode->pDATA = pElementInsert;
		pNode->pPrev = NULL;

		if (m_pFirst == NULL) // premier element de la liste
		{
			pNode->pNext = NULL;
			m_pFirst = pNode;
			m_pLast = pNode;
			m_iNumber++;
			return PB_OK;
		}

		else
		{
			m_pFirst->pPrev = pNode;
			pNode->pNext = m_pFirst;
			m_pFirst = pNode;
			m_iNumber++;
			return PB_OK;
		}
	}
	return ERR;
}

// -----------------------------------------------------------------------------
// CListe::PushFIFO
/** \Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*   Inserer à la fin de la liste
*/
// -----------------------------------------------------------------------------
int CListe::PushFIFO(void* pElementInsert)
{
	T_Cellule *pNode = new T_Cellule;

	if (pNode != NULL)
	{
		pNode->pDATA = pElementInsert;
		pNode->pNext = NULL;

		if (m_pLast == NULL) // premier element de la liste
		{
			pNode->pPrev = NULL;
			m_pFirst = pNode;
			m_pLast = pNode;
			m_iNumber++;
			return PB_OK;
		}

		else
		{
			m_pLast->pNext = pNode;
			pNode->pPrev = m_pLast;
			m_pLast = pNode;
			m_iNumber++;
			return PB_OK;
		}

	}
	return ERR;
}

// -----------------------------------------------------------------------------
// CListe::PushIndex
/** \Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  permet d’insérer un élément à l’emplacement iIndex et incrémente m_iNumber
*/
// -----------------------------------------------------------------------------
int CListe::PushElement(void* pElementInsert, int iIndex)
{
	if (PushFIFO(pElementInsert) != ERR && m_pTableau)
	{
		m_pTableau[iIndex] = pElementInsert;
		return PB_OK;
	}
	return ERR;
}

// -----------------------------------------------------------------------------
// CListe::PushIndex
/** \Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  permet d’insérer un élément à l’emplacement dans un tableau indexé
*/
// -----------------------------------------------------------------------------
int	CListe::InsertToList(void* pElementInsert, int iIndex)
{
	if (m_pTableau)
	{
		m_pTableau[iIndex] = pElementInsert;
		m_iNumber++;
		return PB_OK;
	}
	return ERR;
}

// -----------------------------------------------------------------------------
// CListe::PushIndex
/** \Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  permet d'Extraire l'élément de la liste
*/
// -----------------------------------------------------------------------------
void* CListe::PopFromList(int iIndex)
{
	void *pElement = m_pTableau[iIndex];
	m_pTableau[iIndex] = NULL;

	return pElement;
}
// -----------------------------------------------------------------------------
// CListe::PopFront
/** \Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  Extraire le premier élément de la liste.
*/
// -----------------------------------------------------------------------------
void* CListe::Pop(void)
{
	T_Cellule *pNode = NULL;
	T_Cellule *pTemp = NULL;

	if (m_pFirst != NULL)
	{
		pNode = m_pFirst;

		if (m_pFirst->pNext != NULL)
		{
			pTemp = m_pFirst->pNext;
			pTemp->pPrev = NULL;
		}
		m_pFirst = pNode->pNext;
		pNode->pNext = NULL;
		m_iNumber--;
	}
	if (m_iNumber == 0)
	{
		m_pFirst = NULL;
		m_pLast = NULL;
	}
	if (pNode)
	{
		void *pDataNode = (void *)pNode->pDATA;
		delete pNode;
		pNode = NULL;
		return pDataNode;
	}

	return NULL;
}

// -----------------------------------------------------------------------------
// CListe::PopIndex
/** \Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  retourner les élements suivant l'index
*/
// -----------------------------------------------------------------------------
void* CListe::PopIndex(int iIndex)
{
	int iNumber = 0;
	T_Cellule *pNode = m_pFirst;

	while (pNode != NULL)
	{
		if (iNumber == iIndex)
			break;
		else
		{
			iNumber++;
			pNode = pNode->pNext;
		}
	}
	if (pNode)
		return pNode->pDATA;
	else
		return NULL;
}

// -----------------------------------------------------------------------------
// CListe::GetElement
/** \Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  retourne élément à l’emplacement iIndex sans le retirer de la liste
*/
// -----------------------------------------------------------------------------
void* CListe::GetElement(int iIndex)
{
	return m_pTableau[iIndex];
}

// -----------------------------------------------------------------------------
// CListe::CountElements
/** \Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  permet de compter le nombre des élément de la liste.
*/
// -----------------------------------------------------------------------------
int CListe::CountElements(void)
{
	return m_iNumber;
}

// -----------------------------------------------------------------------------
// CListe::IsEmpty
/** \Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  Vérifie si La Liste est vide .
*/
// -----------------------------------------------------------------------------
bool CListe::IsEmpty(void)
{
	if (m_iNumber)
		return false;

	return true;
}

// -----------------------------------------------------------------------------
// CListe::DeletElement
/** \ Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  permet de supprimer élément à l’emplacement iIndex de la liste.
*/
// -----------------------------------------------------------------------------
int CListe::DeletElement(int iIndex)
{
	int iNumber = 0;
	void* pData = NULL;
	T_Cellule *pNode = m_pFirst;

	while (pNode != NULL)
	{
		if (iNumber == iIndex)
		{
			if (pNode->pPrev == NULL && pNode->pNext == NULL)
			{
				m_pFirst = NULL;
				m_pLast = NULL;
				pData = pNode->pDATA;
				if (pData)
					delete pData;
				pData = NULL;
				delete pNode;
				pNode = NULL;
			}
			else if (pNode->pPrev == NULL && pNode->pNext)
			{
				m_pFirst = pNode->pNext;
				pNode->pNext->pPrev = NULL;
				if (pData)
					delete pData;
				pData = NULL;
				delete pNode;
				pNode = NULL;
			}
			else if (pNode->pPrev && pNode->pNext == NULL)
			{
				m_pLast = pNode->pPrev;
				pNode->pPrev->pNext = NULL;
				if (pData)
					delete pData;
				pData = NULL;
				delete pNode;
				pNode = NULL;
			}
			else if (pNode->pPrev && pNode->pNext)
			{
				pNode->pPrev->pNext = pNode->pNext;
				pNode->pNext->pPrev = pNode->pPrev;
				if (pData)
					delete pData;
				pData = NULL;
				delete pNode;
				pNode = NULL;
			}
			m_iNumber--;
			return PB_OK;
		}
		else
		{
			iNumber++;
			pNode = pNode->pNext;
		}
	}

	return ERR;
}

// -----------------------------------------------------------------------------
// CListe::GetSize
/** \ Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  retourner la taille de tableau.
*/
// -----------------------------------------------------------------------------
int CListe::GetSizeTab()
{
	return m_iSize;
}

// -----------------------------------------------------------------------------
// CListe::DeletElementList
/** \ Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  permet de supprimer tous les éléments la liste.
*/
// -----------------------------------------------------------------------------
int CListe::DeletElementList(void)
{
	T_Cellule *pNode = NULL;
	int iIndexNumber = m_iNumber;
	int iIndex = 0;

	while (m_pFirst != NULL)
	{
		pNode = m_pFirst;
		m_pFirst = pNode->pNext;
		pNode->pDATA = NULL;
		pNode->pNext = NULL;
		if (pNode)
		{
			delete pNode;
			pNode = NULL;
			m_iNumber--;
			iIndex++;
		}
	}

	if (iIndex == iIndexNumber)
		return PB_OK;

	return ERR;
}

// -----------------------------------------------------------------------------
// CListe::DeletByIndex
/** \ Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  permet de supprimer les éléments la liste par index.
*/
// -----------------------------------------------------------------------------
void* CListe::DeletByIndex(int iIndex)
{
	int iNumber = 0;
	void* pData = NULL;
	T_Cellule *pNode = m_pFirst;

	while (pNode != NULL)
	{
		if (iNumber == iIndex)
		{
			if (pNode->pPrev == NULL && pNode->pNext == NULL)
			{
				m_pFirst = NULL;
				m_pLast = NULL;
				pData = pNode->pDATA;
				delete pNode;
				pNode = NULL;
				m_iNumber--;
				return pData;
			}
			else if (pNode->pPrev == NULL && pNode->pNext)
			{
				m_pFirst = pNode->pNext;
				pNode->pNext->pPrev = NULL;
				pData = pNode->pDATA;
				delete pNode;
				pNode = NULL;
				m_iNumber--;
				return pData;
			}
			else if (pNode->pPrev && pNode->pNext == NULL)
			{
				m_pLast = pNode->pPrev;
				pNode->pPrev->pNext = NULL;
				pData = pNode->pDATA;
				delete pNode;
				pNode = NULL;
				m_iNumber--;
				return pData;
			}
			else if (pNode->pPrev && pNode->pNext)
			{
				pNode->pPrev->pNext = pNode->pNext;
				pNode->pNext->pPrev = pNode->pPrev;
				pData = pNode->pDATA;
				delete pNode;
				pNode = NULL;
				m_iNumber--;
				return pData;
			}
		}
		else
		{
			iNumber++;
			pNode = pNode->pNext;
		}
	}

	return pData;
}
