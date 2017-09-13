#include <iostream>
#include <fstream>
#include <string>
#include "Config.h"
#include <functional>
#include <sstream>
// 

// -----------------------------------------------------------------------------
// CConfig::CConfig
/////** \brief Le constructeur de la classe CConfig.
/*
* @param[char* ]
* @exception
* @return
*
* @details Traitement :
*
*
*/
// -----------------------------------------------------------------------------
CConfig::CConfig()
{
	
}

void CConfig::LoadConf(char url[])
{
	std::ifstream fichier(url);
	
	if (fichier)
	{
		fichier >> configuration;
	}
	else
	{
	 LoadDefaultConf();
	}
}

void CConfig::LoadDefaultConf() {
	//load static data
	
}

json CConfig::GetConfiguration() {
	return configuration;
}

// -----------------------------------------------------------------------------
// CConfig::~CConfig
/////** \brief Le destructeur de la classe CConfig.
/*
* @param[char* ]
* @exception
* @return
*
* @details Traitement :
*
*
*/
// -----------------------------------------------------------------------------
CConfig::~CConfig()
{
}


