/*******************************************************************************
* FactoryCamera.h : le fichier header de la classe CFactoryCamera
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

#ifndef FACTORYCAMERA_H_
#define FACTORYCAMERA_H_

// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#include "PhotoBoothHeader.h"
#include "Camera.h"
#include "Liste.h"

// -----------------------------------------------------------------------------
class CFactoryCamera
{

private:

	static CListe *m_pListeCamera;

protected:

	char m_szNameFactory[MAX_SIZE_STRING];

public:

	CFactoryCamera(char *pNameCamera);
	~CFactoryCamera(void);

	virtual CCamera* NewInstance() = 0;
	static CCamera* CreateInstance(const char *pNameCamera);
	char* GetFactoryName(void);
};

template<class TypeCamera>class TFactoryCamera :public CFactoryCamera
{

public:
	TFactoryCamera(char *pNameCamera)
		: CFactoryCamera(pNameCamera)
	{
	};

	~TFactoryCamera()
	{
	};

	CCamera* NewInstance()
	{
		return new TypeCamera;
	};

};

#define		DECLARE_CAMERA_FACTORY(type) TFactoryCamera<type> _TW##type(#type);

#endif //FACTORYCAMERA_H_


