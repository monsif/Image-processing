/*******************************************************************************
* Log.cpp : le fichier header de la classe CLog
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


// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#include "Log.h"

// -----------------------------------------------------------------------------
using namespace std;

//-----------------------------------------------------------------------------
// CLog::CLog
/** \ Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  constructeur par defaut
*/
//---------------------------------------------------------------------------
CLog::CLog(void)
{
	m_pMessageListe = NULL;
}

//-----------------------------------------------------------------------------
// CLog::CLog
/** \ Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  pconstructeur d'initialisation
*/
//---------------------------------------------------------------------------

CLog::CLog(char* pPath, char* pFileName, bool bStatus)
{
	m_bStatus = bStatus;
	if (m_bStatus)
	{
		GetCurrentDate(m_szDate);
		int iRet = _mkdir(pPath);
		m_pMessageListe = new CListe;
		sprintf(m_szFileName, "%s", pFileName);
		sprintf(m_szPath, "%s\\%s_%s.log", pPath, pFileName, m_szDate);
		m_pFichier = fopen(m_szPath, "w+");
		SetEntete();
	}
}

//-----------------------------------------------------------------------------
// CLog::~CLog
/** \ Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  destructeur de la classe CLog
*/
//---------------------------------------------------------------------------
CLog::~CLog(void)
{

	fclose(m_pFichier);
}

//-----------------------------------------------------------------------------
// CLog::PutMessage
/** \ Méthode publique  generique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  permet d'ajouter les message de traces
*/
//---------------------------------------------------------------------------
void CLog::PutMessage(const char* pType, const char* pMessage)
{
	if (m_bStatus)
	{
		CMessage *pMsg = new CMessage(pType, pMessage);

		if (m_pMessageListe)
			m_pMessageListe->PushFIFO(pMsg);
	}
}

//-----------------------------------------------------------------------------
// CLog::PutMessageInfo
/** \ Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  permet d'ajouter message d'information
*/
//---------------------------------------------------------------------------
void CLog::PutMessageInfo(const char* pMessage)
{
	if (m_bStatus)
	{
		CMessage *pMsg = new CMessage("Info       ", pMessage);
		if (m_pMessageListe)
			m_pMessageListe->PushFIFO(pMsg);
	}
}

//-----------------------------------------------------------------------------
// CLog::PutMessageError
/** \ Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  permet d'ajouter un mesage d'erreur
*/
//---------------------------------------------------------------------------
void CLog::PutMessageError(const char* pMessage)
{
	if (m_bStatus)
	{
		CMessage *pMsg = new CMessage("Error      ", pMessage);
		if (m_pMessageListe)
			m_pMessageListe->PushFIFO(pMsg);
	}
}

//-----------------------------------------------------------------------------
// CLog::PutMessageDebug
/** \ Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  permet d'ajouter  message  de debug
*/
//---------------------------------------------------------------------------
void CLog::PutMessageWarning(const char* pMessage)
{
	if (m_bStatus)
	{
		CMessage *pMsg = new CMessage("Warning    ", pMessage);
		if (m_pMessageListe)
			m_pMessageListe->PushFIFO(pMsg);
	}
}


//-----------------------------------------------------------------------------
// CLog::GetCurrentDate
/** \ Méthode publique
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
* methode du temps
*/
//---------------------------------------------------------------------------
void CLog::GetCurrentDate(char* pDate)
{
	time_t     now = time(0);
	struct tm  tstruct;

	localtime_s(&tstruct, &now);
	strftime(pDate, MAX_SIZE_STRING, "%Y-%m-%d__%H-%M-%S", &tstruct);

}

//-----------------------------------------------------------------------------
// CLog::MainTreatement
/** \ Méthode vertuelle publique surchargée
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  c'est lecoeur du traitement de la classe CLog
*/
//---------------------------------------------------------------------------
void CLog::MainTreatement(void)
{
	if (m_pMessageListe)
	{
		while (m_pMessageListe->CountElements() > 0)
		{


			CMessage *pMsg = (CMessage *)m_pMessageListe->Pop();

			if (pMsg)
			{

				fprintf(m_pFichier, "| %s | ", pMsg->GetDate());
				fprintf(m_pFichier, " %s |", pMsg->GetType());
				fprintf(m_pFichier, " %s ", pMsg->GetData());
				fprintf(m_pFichier, "------------------------------------------------------------------------------------------------------------------------------------------");
				delete pMsg;
				pMsg = NULL;
			}


		}


	}
	else
	{

		Sleep(20);
	}



}







void CLog::SetEntete()
{

	fprintf(m_pFichier, "******************************************************************************");
	fprintf(m_pFichier, "* %s _ %s.log : fichier log  du  FyLoSoFCore    *", m_szFileName, m_szDate);
	fprintf(m_pFichier, "******************************************************************************");
	fprintf(m_pFichier, "------------------------------------------------------------------------------------------------------------------------------------------");
	fprintf(m_pFichier, "|   Date    |  time    |     Type    | Message																							  ");
	fprintf(m_pFichier, "------------------------------------------------------------------------------------------------------------------------------------------");

}
