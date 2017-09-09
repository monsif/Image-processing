// -----------------------------------------------------------------------------
#ifndef MESSAGEH
#define MESSAGEH
// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#include "PhotoBoothHeader.h"
// -----------------------------------------------------------------------------

class CMessage
{

private:

	char		m_szData[MAX_SIZE_MSG_LOG];
	char		m_szType[MAX_SIZE_STRING];
	char		m_szDate[MAX_SIZE_STRING];

public:
	CMessage(void);
	~CMessage(void);
	CMessage(const char* pType, const char* pMessage);
	void		GetCurrentDate(void);
	char*		GetData(void);
	char*		GetDate(void);
	char*		GetType(void);
};

#endif //MESSAGEH

