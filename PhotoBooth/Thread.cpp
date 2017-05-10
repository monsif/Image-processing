/*******************************************************************************
* Thread.cpp : le fichier header de la classe CThread
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
*  Class       : CThread
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

#include "Thread.h"

// -----------------------------------------------------------------------------
using namespace std;



// -----------------------------------------------------------------------------
// Thread::CThread
/** \constructeur
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
* constructeur
*/
// -----------------------------------------------------------------------------
CThread::CThread()
{

	m_bExit = false;
	m_hThread = NULL;
	m_hRunThread = NULL;
	m_hStopThread = NULL;
	m_hStopThread = CreateEvent(NULL, TRUE, FALSE, NULL);
	m_hRunThread = CreateEvent(NULL, TRUE, FALSE, NULL);
	m_hThread = CreateMainThread(m_iParam, THREAD_PRIORITY_ABOVE_NORMAL,
		(LPTHREAD_START_ROUTINE)MainLoop,
		CREATE_SUSPENDED);
}

// -----------------------------------------------------------------------------
// CThread::~CThread
/** \destructeur
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*destructeur
*/
// -----------------------------------------------------------------------------
CThread::~CThread()
{
	if (m_bExit == TRUE)
		Stop();
}

// -----------------------------------------------------------------------------
// CThread::Run
/** \M�thode public
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  permet le lancement du Thread
*/
// -----------------------------------------------------------------------------
void CThread::Run()
{
	ResumeThread(m_hThread);
	SetEvent(m_hRunThread);
	m_bExit = FALSE;
}

// -----------------------------------------------------------------------------
// CThread::Stop
/** \ M�thode public
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  permet l�arr�t du Thread
*/
// -----------------------------------------------------------------------------
void CThread::Stop()
{
	SetEvent(m_hStopThread);
	WaitEnd();
}

// -----------------------------------------------------------------------------
// CThread::Pause
/** \ M�thode public
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  permet d attendre la fin de thread
*/
// -----------------------------------------------------------------------------
void CThread::Pause()
{

}

// -----------------------------------------------------------------------------
// CThread::WaitEnd
/** \M�thode protegee
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  Attendre la fin du thread
*/
// -----------------------------------------------------------------------------
void CThread::WaitEnd()
{
	SuspendThread(m_hThread);
}

// -----------------------------------------------------------------------------
// CThread::SetPriority
/** \ M�thode public
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  permet d attendre la fin de thread
*/
// -----------------------------------------------------------------------------
void CThread::SetPriority(int iPriority)
{
	SetThreadPriority(m_hThread, iPriority);
}

// -----------------------------------------------------------------------------
// CThread::SetBoolThread
/** \M�thode protegee
*
* @param[Bool ]
* @exception
* @return
*
* @details Traitement :
*  permet d'attribuer un bool au m_bExit
*/
// -----------------------------------------------------------------------------
void CThread::SetBoolThread(BOOL bBool)
{
	m_bExit = bBool;
}

// -----------------------------------------------------------------------------
// CThread::MainTreatement
/** \m�thode virtuelle prot�g�e
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*   repr�sente le fonctionnement de la t�che
*/
// -----------------------------------------------------------------------------
void CThread::MainTreatement()
{
	Sleep(100);
}

// -----------------------------------------------------------------------------
// CThread::CreateMainThread
/** \ M�thode prot�g�e
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  permet de cr�er le thread
*/
// -----------------------------------------------------------------------------
HANDLE CThread::CreateMainThread(LPVOID pParam, int iPriority,
	LPTHREAD_START_ROUTINE pFunction, DWORD dwCreationFlags)
{
	HANDLE hThread;
	hThread = CreateThread(NULL, 0, pFunction, this, dwCreationFlags, NULL);
	SetThreadPriority(hThread, iPriority);
	return hThread;
}

// -----------------------------------------------------------------------------
// CThread::uSleep
/** \M�thode protegee
*
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  permet de faire des attentes en �s
*/
// -----------------------------------------------------------------------------
void CThread::uSleep(int waitTime)
{
	__int64 time1 = 0, time2 = 0;

	QueryPerformanceCounter((LARGE_INTEGER *)&time1);
	do
	{
		QueryPerformanceCounter((LARGE_INTEGER *)&time2);
	} while ((time2 - time1) < waitTime);
}

// -----------------------------------------------------------------------------
// CThread::MainLoop
/** \M�thode statique priv�
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*permet d�appeler  la M�thode LoopTreatement()
*/
// -----------------------------------------------------------------------------
UINT WINAPI CThread::MainLoop(LPVOID lpParam)
{
	return ((CThread*)lpParam)->LoopTraitement();
}

// -----------------------------------------------------------------------------
// CThread::LoopTreatment
/** \M�thode priv�
*   La boucle principale du thread
* @param[in ]
* @exception
* @return
*
* @details Traitement :
*  contient une boucle permettant au thread de tourner en permanence,
la manipulation de ce thread
*/
// -----------------------------------------------------------------------------
int CThread::LoopTraitement(void)
{
	DWORD dWret = 0;

	WaitForSingleObject(m_hRunThread, INFINITE);

	while (m_bExit == FALSE)
	{
		dWret = WaitForSingleObject(m_hStopThread, 1);
		switch (dWret)
		{
		case WAIT_OBJECT_0:
		{
			m_bExit = TRUE;
			ResetEvent(m_hStopThread);
		}
		break;

		case WAIT_TIMEOUT:
		{
			MainTreatement();
		}
		break;

		default:
			Sleep(20);
			break;
		}
	}
	return 0;
}


