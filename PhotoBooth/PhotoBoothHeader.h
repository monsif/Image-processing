// ------------------------------------------------------------------------------
#ifndef HEADERH
#define HEADERH
// ------------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#undef UNICODE

#include <string>
#include <stdlib.h>
#include <iostream>
#include <winsock2.h>

#include <ws2tcpip.h>
#include <windows.h>
#include <Windef.h>
#include <fstream>
#include <direct.h>
#include <stdio.h>
#include <atlstr.h>
#include <cstring>
#include <ctime>
#include <assert.h>
#include <sys/timeb.h>

// -----------------------------------------------------------------------------

#define    PB_OK                 1
#define    ERR                  -1
#define    unknown               0

#define    SIZE_NAME_FILE        60
#define    SIZE_PATH_FILE        512

#define    MAX_SIZE_MSG_LOG      512
#define    MAX_SIZE_CARACT       100
#define    MAX_SIZE_STRING       100

///////////////////////////////// struct List //////////////////////////////////

typedef struct _T_Cellule
{
	void			  *pDATA;
	struct _T_Cellule *pNext;
	struct _T_Cellule *pPrev;

}T_Cellule;


#endif  //HEADERH