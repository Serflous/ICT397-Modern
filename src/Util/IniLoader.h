#ifndef INILOADER_H
#define INILOADER_H

#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

class IniLoader
{
public:
	IniLoader();
	IniLoader(const IniLoader & other);
	~IniLoader();

	void LoadIniFile(const char * filepath);
	const char * GetProperty(const char * description);
private:

private:
	std::map<std::string, std::string> m_properties;
};

#endif