// -----------------------------------------------------------------------------
#ifndef FUNCTIONALCONF_H_
#define FUNCTIONALCONF_H_

// -----------------------------------------------------------------------------
// FICHIERS D'INCLUSION

#include "Config.h"
#include <list>
// -----------------------------------------------------------------------------

class CFunctionalConf : public CConfig
{
private :
	std::list<char> language;
public:
	CFunctionalConf();
	void init(char url[]);
	~CFunctionalConf();
};

#endif // FUNCTIONALCONF_H_