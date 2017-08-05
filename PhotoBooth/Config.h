#ifndef CONFIG_H_
#define CONFIG_H_

// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION
#include "json.hpp"

// -----------------------------------------------------------------------------
using json = nlohmann::json;
class CConfig
{
private:
	json configuration;
protected :
	void LoadConf(char url[]);
	void LoadDefaultConf();
public:
	CConfig();
	json GetConfiguration();
	~CConfig();
};

#endif //CONFIG_H_
