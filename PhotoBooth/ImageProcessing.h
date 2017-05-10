/*******************************************************************************
* ImageProcessing.h : le fichier header de la classe CImageProcessing
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
*  Class       : CImageProcessing
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

#ifndef IMAGEPROCESSING_H_
#define IMAGEPROCESSING_H_

// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION
#include "PhotoBoothHeader.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

// -----------------------------------------------------------------------------
class CImageProcessing
{
public:
	CImageProcessing();
	~CImageProcessing();

	void  SaveImageProcessing(char* szPath, cv::Mat image);
	cv::Mat   RecursFilter(char* szPathImage);
	cv::Mat   NormconvFilter(char* szPathImage);
	cv::Mat   EnhanceFilter(char* szPathImage);
	cv::Mat   SketchFilter(char* szPathImage);
	cv::Mat   SketchGrayFilter(char* szPathImage);
	cv::Mat   StylizationFilter(char* szPathImage);
	cv::Mat   GrayFilter(char* szPathImage);
};

#endif //IMAGEPROCESSING_H_
