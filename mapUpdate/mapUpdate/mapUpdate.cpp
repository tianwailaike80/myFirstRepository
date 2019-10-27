// mapUpdate.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "mapUpdater.h"

int main()
{
	//mapUpdater updater("C:/C++/mapdata/mapdata_China_Testarea_Dummy.xml");


	TiXmlDocument xmlFile;
	xmlFile.LoadFile("C:/C++/mapdata/mapdata_DLMv3-XML_sample-ComplexCrossing.xml");
	TiXmlNode* root = xmlFile.FirstChild("journal");

	mapUpdater updater;
	updater.getMaxLandmarkID(root);
    std::cout << updater.maxLandmarkID_ << "Hello World!\n";


	// test insert
	//TiXmlNode* insertPlace;
	//insertPlace = xmlFile.FirstChild("journal")->FirstChild("insert")->FirstChild("laneSeparatorGroup");
	//updater.insertLandmark(insertPlace);
	//xmlFile.SaveFile("C:/C++/mapdata/inserted.xml");

	TiXmlElement newLandmarkElement("");
	updater.createNewLandmarkElement(newLandmarkElement);
	
	TiXmlNode* node1;
	node1 = xmlFile.FirstChild("journal")->FirstChild("insert");
	TiXmlNode* node2;
	node2 = xmlFile.FirstChild("journal")->FirstChild("insert")->LastChild("laneGroupRelation");
	//node->InsertEndChild(newLandmarkElement);
	node1->InsertBeforeChild(node2, newLandmarkElement);
	xmlFile.SaveFile("C:/C++/mapdata/inserted.xml");


}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
