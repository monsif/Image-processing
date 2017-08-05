// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#include "TechnicalConf.h"

// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// CTechnicalConf::CTechnicalConf
/////** \brief Le destructeur de la classe CTechnicalConf.
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
CTechnicalConf::CTechnicalConf()
{

}

void CTechnicalConf::init(char url[])
{
	LoadConf(url);
	findHardwareConf();
	findCredentials();
	findViewsLanguage();
	findServices();
}

std::string CTechnicalConf::getActiveLanguage()
{
	return active_language;
}

std::string CTechnicalConf::getCameraVersion()
{
	return camera_version;
}

std::string CTechnicalConf::getCameraDriver()
{
	return camera_driver;
}

std::string CTechnicalConf::getPrinterVersion()
{
	return printer_version;
}

std::string CTechnicalConf::getPrinterDriver()
{
	return printer_driver;
}

json CTechnicalConf::getFormView()
{
	return form_view;
}

json CTechnicalConf::getFormatView()
{
	return format_view;
}

json CTechnicalConf::getTakePhotoView()
{
	return take_photo_view;
}

json CTechnicalConf::getPrintView()
{
	return print_view;
}

json CTechnicalConf::getServices()
{
	return services;
}

json CTechnicalConf::getCredentials()
{
	return credentials;
}

void CTechnicalConf::findHardwareConf()
{
	std::string p_driver = GetConfiguration()["printer_driver"];
	printer_driver = p_driver;

	std::string p_version = GetConfiguration()["printer_version"];
	printer_version = p_version;

	std::string c_driver = GetConfiguration()["camera_driver"];
	camera_driver = c_driver;

	std::string c_version = GetConfiguration()["camera_version"];
	camera_version = c_version;

	std::string a_language = GetConfiguration()["active_language"];
	active_language = a_language;

}

void CTechnicalConf::findCredentials()
{
	credentials = GetConfiguration()["credentials"];
}

void CTechnicalConf::findViewsLanguage()
{
	json views = GetConfiguration()["languages"][active_language];
	format_view = views["format_view"];
	form_view = views["form_view"];
	print_view = views["print_view"];
	take_photo_view = views["take_photo_view"];
}

void CTechnicalConf::findServices()
{
	services = GetConfiguration()["services"];
}

// -----------------------------------------------------------------------------
// CTechnicalConf::~CTechnicalConf
/////** \brief Le destructeur de la classe CTechnicalConf.
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
CTechnicalConf::~CTechnicalConf()
{

}
