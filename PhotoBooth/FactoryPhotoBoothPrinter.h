/*******************************************************************************
* FactoryPhotoBoothPrinter.h : le fichier header de la classe CFactoryPhotoBoothPrinter
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

#ifndef FACTORYPRINTER_H_
#define FACTORYPRINTER_H_

// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION
#include "PhotoBoothHeader.h"
#include "PhotoBoothPrinter.h"
#include "Liste.h"

// -----------------------------------------------------------------------------
class CFactoryPhotoBoothPrinter
{

private:

	static CListe *m_pListePhotoBoothPrinter;

protected:

	char m_szNameFactory[MAX_SIZE_STRING];

public:

	CFactoryPhotoBoothPrinter(char *pNamePhotoBoothPrinter);
	~CFactoryPhotoBoothPrinter(void);

	virtual CPhotoBoothPrinter* NewInstance() = 0;
	static CPhotoBoothPrinter* CreateInstance(const char *pNamePhotoBoothPrinter);
	char* GetFactoryName(void);
};

template<class TypePhotoBoothPrinter>class TFactoryPhotoBoothPrinter :public CFactoryPhotoBoothPrinter
{

public:
	TFactoryPhotoBoothPrinter(char *pNamePhotoBoothPrinter)
		: CFactoryPhotoBoothPrinter(pNamePhotoBoothPrinter)
	{
	};

	~TFactoryPhotoBoothPrinter()
	{
	};

	CPhotoBoothPrinter* NewInstance()
	{
		return new TypePhotoBoothPrinter;
	};

};

#define		DECLARE_PHOTOBOOTHPRINTER_FACTORY(type) TFactoryPhotoBoothPrinter<type> _TW##type(#type);

#endif //FACTORYPRINTER_H_

