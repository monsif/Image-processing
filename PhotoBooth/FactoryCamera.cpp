/*******************************************************************************
* FactoryCamera.cpp : le fichier header de la classe CFactoryCamera
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
*  Class       : CFactoryCamera
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

#include "FactoryCamera.h"

// -----------------------------------------------------------------------------
using namespace std;


CListe* CFactoryCamera::m_pListeCamera = NULL;
// -----------------------------------------------------------------------------
// CFactoryCamera::CFactoryCamera
/** \brief Le constructeur de la classe abstraite CFactoryCamera.
*
* @param[char* ]
* @exception
* @return
*
* @details Traitement :
* Le constructeur de la classe CFactoryCamera, est appelé par la template
* TFactoryCamera.
* Il stock une reference vers l'objet créer dans une liste.
*
*/
// -----------------------------------------------------------------------------
CFactoryCamera::CFactoryCamera(char *pNameCamera)
{
	if(m_pListeCamera == NULL)
		m_pListeCamera = new CListe();
	strncpy_s(m_szNameFactory, MAX_SIZE_STRING, pNameCamera,
		MAX_SIZE_STRING);
	m_pListeCamera->PushFIFO(this);
}

// -----------------------------------------------------------------------------
// CFactoryCamera::~CFactoryCamera
/** \brief Le destructeur de la classe abstraite CFactoryCamera.
*
* @param[ ]
* @exception
* @return
*
* @details Traitement :
* Le destructeur de la classe CFactoryCamera
*
*/
// -----------------------------------------------------------------------------

CFactoryCamera::~CFactoryCamera(void)
{
	/* if(pListeFact_m)
	{
	pListeFact_m->RemoveAll();
	delete pListeFact_m;
	pListeFact_m = NULL;

	} */
}

// -----------------------------------------------------------------------------
// CFactoryCamera::CreateInstance
/** \brief Cette m'éthode retourne un pointeur sur un objet .
*
* @param[const char* ]
* @exception
* @return CCarteExtension*
*
* @details Traitement :
* Cette méthode recherche  un objet portant le nom pNameCamera
* et fait appele à sa méthode NewInstance() qui retourne un pointeur sur
* un objet, du type passé à la template TFactoryCamera
* et la méthode CreateInstance() le retounrne
*/
// -----------------------------------------------------------------------------
CCamera* CFactoryCamera::CreateInstance(const char *pNameCamera)
{
	CCamera		   *pCamera = NULL;
	CFactoryCamera *pFactCamera = NULL;
	int					iIndex = 0;

	if(m_pListeCamera)
	{
		for(iIndex = 0; iIndex < m_pListeCamera->CountElements(); iIndex++)
		{
			pFactCamera =
				(CFactoryCamera*)m_pListeCamera->PopIndex(iIndex);
			if(pFactCamera && strncmp(pNameCamera,
				pFactCamera->GetFactoryName(), MAX_SIZE_STRING) == NULL)
			{
				pCamera = pFactCamera->NewInstance();
				break;
			}
		}
	}
	return pCamera;
}

// -----------------------------------------------------------------------------
// CFactoryCamera::GetFactoryName
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

char* CFactoryCamera::GetFactoryName(void)
{
	return m_szNameFactory;
}

