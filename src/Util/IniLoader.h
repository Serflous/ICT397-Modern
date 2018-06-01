#ifndef INILOADER_H
#define INILOADER_H

#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

	/**
	* IniLoader designed to load values from an ini file.
	*/
class IniLoader
{
public:
		/**
		* Default constructor
		*/
	IniLoader();
		/**
		* Default copy constructor
		*/
	IniLoader(const IniLoader & other);
		/**
		* Destructor
		*/
	~IniLoader();

		/**
		* Loads the ini file in from the specified file path.
		* @param[in] filepath The location of the ini file.
		*/
	void LoadIniFile(const char * filepath);
		/**
		* Gets a property from the loaded ini file.
		* @param[in] The name of the property.
		* @return The property requested.
		*/
	const char * GetProperty(const char * description);
private:

private:
	std::map<std::string, std::string> m_properties;
};

#endif