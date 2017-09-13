// -----------------------------------------------------------------------------
#ifndef TECHNICALCONF_H_
#define TECHNICALCONF_H_
// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#include "Config.h"
#include <string>
// -----------------------------------------------------------------------------

class CTechnicalConf : public CConfig
{
private:
	std::string active_language;
	std::string camera_version;
	std::string camera_driver;
	std::string printer_version;
	std::string printer_driver;
	json form_view, format_view, print_view, take_photo_view, services, credentials, nextViews;
	void findCredentials();
	void findHardwareConf();
	void findViewsLanguage();
	void findServices();
public:
	CTechnicalConf();
	void init(char url[]);
	std::string getActiveLanguage();
	std::string getCameraVersion();
	std::string getCameraDriver();
	std::string getPrinterVersion();
	std::string getPrinterDriver();
	json getFormView();
	json getFormatView();
	json getTakePhotoView();
	json getPrintView();
	json getServices();
	json getCredentials();

	~CTechnicalConf();
};

#endif //TECHNICALCONF_H_
