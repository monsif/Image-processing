/*******************************************************************************
* FactoryPhotoBoothPrinter.cpp : le header de la classe CFactoryPhotoBoothPrinter
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
*  Class       : CFactoryPhotoBoothPrinter
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

#include "FactoryPhotoBoothPrinter.h"

// -----------------------------------------------------------------------------
using namespace std;


CListe* CFactoryPhotoBoothPrinter::m_pListePhotoBoothPrinter = NULL;
// -----------------------------------------------------------------------------
// CFactoryPhotoBoothPrinter::CFactoryPhotoBoothPrinter
/** \brief Le constructeur de la classe abstraite CFactoryPhotoBoothPrinter.
*
* @param[char* ]
* @exception
* @return
*
* @details Traitement :
* Le constructeur de la classe CFactoryPhotoBoothPrinter, est appelé par la template
* TFactoryPhotoBoothPrinter.
* Il stock une reference vers l'objet créer dans une liste.
*
*/
// -----------------------------------------------------------------------------
CFactoryPhotoBoothPrinter::CFactoryPhotoBoothPrinter(char *pNamePhotoBoothPrinter)
{
	if (m_pListePhotoBoothPrinter == NULL)
		m_pListePhotoBoothPrinter = new CListe();
	strncpy_s(m_szNameFactory, MAX_SIZE_STRING, pNamePhotoBoothPrinter,
		MAX_SIZE_STRING);
	m_pListePhotoBoothPrinter->PushFIFO(this);
}

// -----------------------------------------------------------------------------
// CFactoryPhotoBoothPrinter::~CFactoryPhotoBoothPrinter
/** \brief Le destructeur de la classe abstraite CFactoryPhotoBoothPrinter.
*
* @param[ ]
* @exception
* @return
*
* @details Traitement :
* Le destructeur de la classe CFactoryPhotoBoothPrinter
*
*/
// -----------------------------------------------------------------------------

CFactoryPhotoBoothPrinter::~CFactoryPhotoBoothPrinter(void)
{
	/* if(pListeFact_m)
	{
	pListeFact_m->RemoveAll();
	delete pListeFact_m;
	pListeFact_m = NULL;

	} */
}

// -----------------------------------------------------------------------------
// CFactoryPhotoBoothPrinter::CreateInstance
/** \brief Cette m'éthode retourne un pointeur sur un objet .
*
* @param[const char* ]
* @exception
* @return CCarteExtension*
*
* @details Traitement :
* Cette méthode recherche  un objet portant le nom pNamePhotoBoothPrinter
* et fait appele à sa méthode NewInstance() qui retourne un pointeur sur
* un objet, du type passé à la template TFactoryPhotoBoothPrinter
* et la méthode CreateInstance() le retounrne
*/
// -----------------------------------------------------------------------------
CPhotoBoothPrinter* CFactoryPhotoBoothPrinter::CreateInstance(const char *pNamePhotoBoothPrinter)
{
	CPhotoBoothPrinter		   *pPhotoBoothPrinter = NULL;
	CFactoryPhotoBoothPrinter *pFactPhotoBoothPrinter = NULL;
	int					iIndex = 0;

	if (m_pListePhotoBoothPrinter)
	{
		for (iIndex = 0; iIndex < m_pListePhotoBoothPrinter->CountElements(); iIndex++)
		{
			pFactPhotoBoothPrinter =
				(CFactoryPhotoBoothPrinter*)m_pListePhotoBoothPrinter->PopIndex(iIndex);
			if (pFactPhotoBoothPrinter && strncmp(pNamePhotoBoothPrinter,
				pFactPhotoBoothPrinter->GetFactoryName(), MAX_SIZE_STRING) == NULL)
			{
				pPhotoBoothPrinter = pFactPhotoBoothPrinter->NewInstance();
				break;
			}
		}
	}
	return pPhotoBoothPrinter;
}

// -----------------------------------------------------------------------------
// CFactoryPhotoBoothPrinter::GetFactoryName
/** \brief Cette m'éthode .
*
* @param[void ]
* @exception
* @return char*
*
* @details Traitement :
* Cette méthode permet de consulter le contenue du membre m_szNameFactory.
*
*/
// -----------------------------------------------------------------------------

char* CFactoryPhotoBoothPrinter::GetFactoryName(void)
{
	return m_szNameFactory;
}

