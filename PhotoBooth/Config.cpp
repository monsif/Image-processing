/*******************************************************************************
* Config.cpp : le fichier header de la classe CConfig
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
*  Class       : CConfig
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

bool CConfig::LoadConf(char url[])
{
	std::ifstream fichier(url);
	
	if (fichier)
	{
		fichier >> configuration;
		return true;
	}
	else
	{
		return LoadDefaultConf();
	}
}

bool CConfig::LoadDefaultConf() {
	//load static data
	return false;
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


