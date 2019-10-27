#pragma once
#include <string>
#include <tinyxml.h>
#include <sstream>

class mapUpdater
{
private:

	int tempLandmarkID_;
	const char* text_ = "";
	std::ostringstream streamObj_;



	//TiXmlDocument xmlFile_;


public:
	//mapUpdater(const std::string& dlmDir);
	mapUpdater();
	~mapUpdater();

	int maxLandmarkID_ = 0;
	std::string dlmDir_;

	template <class Type>
	Type stringToNum(const std::string& str);

	/*TiXmlNode* getMapRoot();*/

	void getMaxLandmarkID(TiXmlNode* node);
	void getDlmDir(std::string& dlmDir);
	void iterateNode(TiXmlNode* node);
	void createNewLandmarkElement(TiXmlElement& newLandmarkElement);
};

