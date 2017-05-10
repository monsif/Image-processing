/*******************************************************************************
* Log.h : le fichier header de la classe CLog
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
*  Class       : CLog
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

#ifndef LOG_H_
#define LOG_H_

// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#include "PhotoBoothHeader.h"
#include "Thread.h"
#include "Message.h"
#include "Liste.h"

// -----------------------------------------------------------------------------

class CLog : public CThread
{
private:
	CListe*			m_pMessageListe;
	char 			m_szFileName[SIZE_NAME_FILE];
	char			m_szPath[SIZE_PATH_FILE];
	char			m_szDate[SIZE_PATH_FILE];
	bool           m_bStatus;

	//	std::ofstream  fichier;
	FILE  *m_pFichier;


public:
	CLog(void);
	CLog(char* pPath, char* pFileName, bool bStatus);
	~CLog(void);

	void		   PutMessage(const char* pType, const char* pMessage);
	void		   PutMessageInfo(const char* pMessage);
	void           PutMessageError(const char* pMessage);
	void           PutMessageWarning(const char* pMessage);
	void           GetCurrentDate(char* pDate);
	void 	       MainTreatement(void);
	void		   SetEntete();
};

#endif //LOG_H_

