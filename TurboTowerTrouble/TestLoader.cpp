#include "TestLoader.h"


TestLoader::TestLoader(std::string filename):path(filename)
{
	std::string a;
	load(path,m_JSONData);
	parse(m_JSONData, a);

}
void TestLoader::load(std::string & path, std::string & jsonData)
{
	// Loads all the data in the file into a std::string.
	std::ifstream myfile(path);
	std::string line;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			jsonData.append(line);
		}
		myfile.close();
	}
	else
	{
		std::string errorMessage = "Could not open " + path + " exiting!";
		throw std::exception(errorMessage.c_str());
	}

}
void TestLoader::parse(std::string const & jsonData, std::string & data)
{
	JSONValue * value = JSON::Parse(jsonData.c_str());
	JSONObject root = value->AsObject();
	JSONObject testValues = root[L"test_values"]->AsObject();
	 std::wstring a = testValues[L"val1"]->AsString();
	 std::string b = wStringToString(a);
	 value2 = testValues[L"val2"]->AsNumber();
	 value3 = testValues[L"val3"]->AsNumber();
	 std::cout << b << std::endl;
	 std::cout << value2 << std::endl;
	 std::cout << value3 << std::endl;
}
std::string TestLoader::wStringToString(std::wstring & wstr)
{
	std::string s(wstr.begin(), wstr.end());
	return s;
}

TestLoader::~TestLoader()
{
}

