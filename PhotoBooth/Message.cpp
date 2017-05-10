/*******************************************************************************
* Message.cpp : le fichier header de la classe CMessage
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
*  Class       : CMessage
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
// FICHIERS D'INCLUSION


#include "Message.h"
// -----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
//CMessage::CMessage
/** \ Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*
*/
//----------------------------------------------------------------------------

CMessage::CMessage(void)
{
}

//-----------------------------------------------------------------------------
// CMessage::~CMessage
/** \ Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*
*/
//----------------------------------------------------------------------------
CMessage::~CMessage(void)
{


}

//-----------------------------------------------------------------------------
// CMessage::CMessage
/** \ Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*
*/
//----------------------------------------------------------------------------
CMessage::CMessage(const char* pType, const char* pMessage)
{

	sprintf(m_szType, "%s", pType);
	sprintf(m_szData, "%s", pMessage);
	GetCurrentDate();

}
//-----------------------------------------------------------------------------
// CMessage::GetCurrentDate
/** \ Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*
*/
//----------------------------------------------------------------------------
void CMessage::GetCurrentDate()
{
	time_t     now = time(0);
	struct tm  tstruct;
	localtime_s(&tstruct, &now);
	strftime(m_szDate, sizeof(m_szDate), "%Y/%m/%d | %H:%M:%S", &tstruct);

}
//-----------------------------------------------------------------------------
// CMessage::GetDate
/** \ Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*
*/
//----------------------------------------------------------------------------
char* CMessage::GetDate(void)
{
	return m_szDate;
}
//-----------------------------------------------------------------------------
// CMessage::GetData
/** \ Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*
*/
//----------------------------------------------------------------------------
char* CMessage::GetData(void)
{
	return m_szData;
}
//-----------------------------------------------------------------------------
// CMessage::GetType
/** \ Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*
*/
//----------------------------------------------------------------------------
char* CMessage::GetType(void)
{
	return m_szType;
}
