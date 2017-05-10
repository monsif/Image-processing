/*******************************************************************************
* ImageProcessing.cpp : le fichier header de la classe CImageProcessing
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

// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#include "ImageProcessing.h"

// -----------------------------------------------------------------------------
using namespace cv;
using namespace std;



// -----------------------------------------------------------------------------
// CImageProcessing::CImageProcessing
/////** \brief Le constructeur de la classe CImageProcessing.
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
CImageProcessing::CImageProcessing()
{
}

// -----------------------------------------------------------------------------
// CImageProcessing::~CImageProcessing
/////** \brief Le destructeur de la classe CImageProcessing.
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
CImageProcessing::~CImageProcessing()
{

}

// -----------------------------------------------------------------------------
// CImageProcessing::SaveImageProcessing
/////** \brief.
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
void   CImageProcessing::SaveImageProcessing(char* szPath, Mat image)
{
	imwrite(szPath, image);
}

// -----------------------------------------------------------------------------
// CImageProcessing::RecursFilter
/////** \brief.
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
Mat CImageProcessing::RecursFilter(char* szPathImage)
{
	Mat imageIn;
	Mat imageOut;
	imageIn = imread(szPathImage);
	if (imageIn.data)
	{
		edgePreservingFilter(imageIn, imageOut, RECURS_FILTER);
	}
	return imageOut;
}

// -----------------------------------------------------------------------------
// CImageProcessing::NormconvFilter
/////** \brief.
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
Mat CImageProcessing::NormconvFilter(char* szPathImage)
{
	Mat imageIn;
	Mat imageOut;
	imageIn = imread(szPathImage);
	if (imageIn.data)
	{
		edgePreservingFilter(imageIn, imageOut, NORMCONV_FILTER);
	}
	return imageOut;
}

// -----------------------------------------------------------------------------
// CImageProcessing::EnhanceFilter
/////** \brief.
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
Mat CImageProcessing::EnhanceFilter(char* szPathImage)
{
	Mat imageIn;
	Mat imageOut;
	imageIn = imread(szPathImage);
	if (imageIn.data)
	{
		detailEnhance(imageIn, imageOut);
	}

	return imageOut;
}

// -----------------------------------------------------------------------------
// CImageProcessing::SketchFilter
/////** \brief.
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
Mat CImageProcessing::SketchFilter(char* szPathImage)
{
	Mat imageIn;
	Mat imageOut;
	Mat imageTmp;
	imageIn = imread(szPathImage);
	if (imageIn.data)
	{
		pencilSketch(imageIn, imageTmp, imageOut);
	}
	return imageOut;
}

// -----------------------------------------------------------------------------
// CImageProcessing::SketchGrayFilter
/////** \brief.
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
Mat CImageProcessing::SketchGrayFilter(char* szPathImage)
{
	Mat imageIn;
	Mat imageOut;
	Mat imageTmp;
	imageIn = imread(szPathImage);
	if (imageIn.data)
	{
		pencilSketch(imageIn, imageOut, imageTmp);
	}
	return imageOut;
}

// -----------------------------------------------------------------------------
// CImageProcessing::StylizationFilter
/////** \brief.
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
Mat CImageProcessing::StylizationFilter(char* szPathImage)
{
	Mat imageIn;
	Mat imageOut;
	imageIn = imread(szPathImage);
	if (imageIn.data)
	{
		stylization(imageIn, imageOut);
	}
	return imageOut;
}

// -----------------------------------------------------------------------------
// CImageProcessing::GrayFilter
/////** \brief.
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
Mat CImageProcessing::GrayFilter(char* szPathImage)
{
	Mat imageIn;
	Mat imageOut;
	imageIn = imread(szPathImage);
	if (imageIn.data)
	{
		cvtColor(imageIn, imageOut, CV_BGR2GRAY);
	}
	return imageOut;
}

