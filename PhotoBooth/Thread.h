/*******************************************************************************
* Thread.h : le fichier header de la classe CThread
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
#ifndef THREAD_H_
#define THREAD_H_
// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#include "windows.h"
// -----------------------------------------------------------------------------

class CThread
{
protected:

	HANDLE m_hThread;
	HANDLE m_hStopThread;
	HANDLE m_hRunThread;
	LPVOID m_iParam;
	int    m_iPriority_m;
	BOOL   m_bExit;

public:

	CThread();
	virtual ~CThread();

	virtual void Run();
	virtual void Stop();
	virtual void Pause();
	virtual void WaitEnd();
	virtual void SetPriority(int iPriority);
	virtual void SetBoolThread(BOOL bBool);

protected:

	virtual void MainTreatement();
	HANDLE CreateMainThread(LPVOID pParam, int iPriority,
		LPTHREAD_START_ROUTINE pFunction, DWORD dwCreationFlags);
	void uSleep(int waitTime);

private:

	static UINT WINAPI MainLoop(LPVOID lpParam);
	int LoopTraitement(void);

};

#endif //THREAD_H_

