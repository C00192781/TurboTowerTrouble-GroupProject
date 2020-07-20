#pragma once
#include "JSON.h"
#include <fstream>
#include <string>
#include "stdafx.h"
class TestLoader
{
private:
	std::string m_JSONData;
	std::string path;
	
	std::string * value1;
	double  value2;
	double  value3;

	std::string jsonData;
public:
	TestLoader(std::string filename);


	void load(std::string & path, std::string & jsonData);
	void parse(std::string const & jsonData, std::string & data);
	std::string wStringToString(std::wstring & wstr);
	~TestLoader();
};

