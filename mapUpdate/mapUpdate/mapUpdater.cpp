#include "mapUpdater.h"
#include "tinyxml.h"
#include <iostream>
#include <sstream>

/*mapUpdater::mapUpdater(const std::string &dlmDir)
{
	dlmDir_ = dlmDir;
}*/

mapUpdater::mapUpdater() {}
mapUpdater::~mapUpdater() {}



template <class Type>
Type mapUpdater::stringToNum(const std::string& str)
{
	std::istringstream iss(str);
	Type num;
	iss >> num;
	return num;
}

/*TiXmlNode* mapUpdater::getMapRoot()
{
	xmlFile_.LoadFile(dlmDir_.c_str());
	TiXmlNode* root = xmlFile_.FirstChild("journal");
	return root;
}*/

void mapUpdater::getMaxLandmarkID(TiXmlNode* node)
{
	for (node = node->FirstChild(); node; node = node->NextSibling())
	{
		if (node->FirstChildElement("dlmId"))
		{
			text_ = node->FirstChildElement("dlmId")->GetText();
			if (text_)
			{
				std::string text2Str(text_);
				tempLandmarkID_ = stringToNum<int>(text2Str);
				if (tempLandmarkID_ > maxLandmarkID_) maxLandmarkID_ = tempLandmarkID_;
			}
		}
		//else if (node->FirstChild())
		getMaxLandmarkID(node);
	}

}

void mapUpdater::getDlmDir(std::string& dlmDir) 
{
	dlmDir = dlmDir_;
}

void mapUpdater::iterateNode(TiXmlNode* node)
{
	for (node = node->FirstChild(); node; node = node->NextSibling())
	{
		const char* text;

		if ( !(node->ToElement()) ) 
			continue;
		else
		{
			text = node->ToElement()->GetText();
			iterateNode(node);

			if ( !text)
				continue;
			else
			{
				std::string s(text);
				std::cout << s << std::endl;
			}
		}
		
	}
}

void mapUpdater::createNewLandmarkElement(TiXmlElement& newLandmarkElement)
{
	//TiXmlNode* root = getMapRoot(); //point to "meta"
	TiXmlElement UpperLeft("UpperLeft");
	TiXmlElement UpperRightLowerLeft("UpperRightLowerLeft");
	TiXmlElement LowerRight("LowerRight");
	TiXmlElement StartCovariance("StartCovariance");
	TiXmlElement centerPosition("centerPosition");
	TiXmlElement simpleMarking("simpleMarking");
	TiXmlElement dlmId("dlmId");
	TiXmlElement landmark("landmark");

	// fill in
	streamObj_.str("");
	streamObj_ << 0.0001;
	TiXmlText UpperLeftText(streamObj_.str().c_str());

	streamObj_.str("");
	streamObj_ << 0.0;
	TiXmlText UpperRightLowerLeftText(streamObj_.str().c_str());

	streamObj_.str("");
	streamObj_ << 0.0001;
	TiXmlText LowerRightText(streamObj_.str().c_str());

	streamObj_.str("");
	streamObj_ << "POINT ( 10.7519708884093 52.42416937096715 )";
	TiXmlText centerPositionText(streamObj_.str().c_str());

	simpleMarking.SetAttribute("isLineStringWidth", "false");
	simpleMarking.SetAttribute("myRadius", "-100");

	streamObj_.str("");
	maxLandmarkID_++;
	streamObj_ << maxLandmarkID_;
	TiXmlText dlmIdText(streamObj_.str().c_str());

	landmark.SetAttribute("type", "POLE");
	landmark.SetAttribute("valid", "true");

	// link 
	UpperLeft.InsertEndChild(UpperLeftText);
	UpperRightLowerLeft.InsertEndChild(UpperRightLowerLeftText);
	LowerRight.InsertEndChild(LowerRightText);

	StartCovariance.InsertEndChild(UpperLeft);
	StartCovariance.InsertEndChild(UpperRightLowerLeft);
	StartCovariance.InsertEndChild(LowerRight);

	centerPosition.InsertEndChild(centerPositionText);

	simpleMarking.InsertEndChild(centerPosition);
	simpleMarking.InsertEndChild(StartCovariance);

	dlmId.InsertEndChild(dlmIdText);

	landmark.InsertEndChild(dlmId);
	landmark.InsertEndChild(simpleMarking);

	newLandmarkElement = landmark;
}


