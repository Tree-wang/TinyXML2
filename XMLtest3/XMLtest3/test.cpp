#include <iostream>
#include "tinyxml2.h"
using namespace std;
using namespace tinyxml2;

void  createCodeXml()
{

	XMLDocument xml;
	//插入声明
	XMLDeclaration* declaration = xml.NewDeclaration();
	xml.InsertFirstChild(declaration);

	//插入根节点
	XMLElement* rootNode = xml.NewElement("wang");
	xml.InsertEndChild(rootNode);

	//新建一个name节点
	XMLElement* root_1_name = xml.NewElement("name");


	//新建name节点的文本wangqinghe
	//XMLText* text_1_name = xml.NewText("wangqinghe");
	////把文本与name节点链接起来
	//root_1_name->InsertFirstChild(text_1_name);

	//新建一个age节点
	XMLElement* root_1_age = xml.NewElement("age");
	XMLText* text_1_age = xml.NewText("18");
	root_1_age->SetAttribute("age", "secret");
	root_1_age->InsertFirstChild(text_1_age);

	//创建name节点的子节点
	XMLElement* root_2_gender = xml.NewElement("gender");
	XMLText* text_2_gender = xml.NewText("man");
	root_2_gender->InsertFirstChild(text_2_gender);

	//将gender节点变为name节点的子节点
	root_1_name->InsertEndChild(root_2_gender);


	//链接name节点与根节点
	rootNode->InsertEndChild(root_1_name);
	rootNode->InsertEndChild(root_1_age);
	xml.SaveFile("wang.xml");
}

void decodeXml()
{
	//声明
	XMLDocument xml;

	//导入xml文件
	if (xml.LoadFile("wang.xml") != XML_SUCCESS)
	{
		return;
	}

	//判断头文件是否为空
	XMLElement* rootNode = xml.RootElement();
	if (rootNode == NULL)
	{
		return;
	}
	
	//读取第一层信息
	XMLElement* root_1_name = rootNode->FirstChildElement("name");
	//读取第二层信息
	XMLElement* root_2_gender = root_1_name->FirstChildElement("gender");
	//信息输出
	string text_gender = root_2_gender->GetText();
	cout << "gender: "<<text_gender << endl;

	//读取第一层信息
	XMLElement* root_1_age = rootNode->FirstChildElement("age");
	const XMLAttribute* att_1_age = root_1_age->FirstAttribute();
	cout << att_1_age->Name() << ":" << att_1_age->Value() << endl;

	string text_age = root_1_age->GetText();
	cout << "age: " << text_age << endl;
}
int main()
{
	createCodeXml();
	decodeXml();
	return 0;
}