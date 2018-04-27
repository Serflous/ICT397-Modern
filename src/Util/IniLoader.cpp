#include "IniLoader.h"

IniLoader::IniLoader()
{

}

IniLoader::IniLoader(const IniLoader & other)
{
	m_properties = other.m_properties;
}

IniLoader::~IniLoader()
{

}

void IniLoader::LoadIniFile(const char * filepath)
{
	std::ifstream fileStream(filepath);
	if (!fileStream.is_open())
	{
		std::cout << "Error opening config file." << std::endl;
		return;
	}
	std::string line;
	std::string currentCategory = "";
	while (std::getline(fileStream, line))
	{
		// Is Comment
		if (line[0] == ';')
		{
			continue;
		}
		// Is Category
		else if (line[0] == '[')
		{
			currentCategory = std::string(line.begin() + 1, line.end() - 1) + '/';
		}

		else
		{
			std::stringstream stringStream(line);
			std::string prop, value;
			std::getline(stringStream, prop, '=');
			std::getline(stringStream, value);
			prop = currentCategory + prop;
			if (m_properties.count(prop.c_str()) == 0)
			{
				std::cout << "Added property " << prop.c_str() << std::endl;
				m_properties.emplace(std::make_pair(prop, value));
			}
		}
	}
}

const char * IniLoader::GetProperty(const char * description)
{
	std::map<std::string, std::string>::iterator mapIter = m_properties.find(description);
	if (mapIter == m_properties.end())
	{
		return "Invalid Property";
	}
	else
	{
		return mapIter->second.c_str();
	}
}