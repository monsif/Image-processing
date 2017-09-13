// -----------------------------------------------------------------------------

#ifndef LOCALSTORAGE_H_
#define LOCALSTORAGE_H_

// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#include "Thread.h"

// -----------------------------------------------------------------------------

class CLocalStorage :
	public CThread
{
public:
	CLocalStorage();
	~CLocalStorage();
};

#endif //LOCALSTORAGE_H_
