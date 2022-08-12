#include <iostream>
#include "tinyxml2.h"
using namespace std;
using namespace tinyxml2;

void  createCodeXml()
{

	XMLDocument xml;
	//��������
	XMLDeclaration* declaration = xml.NewDeclaration();
	xml.InsertFirstChild(declaration);

	//������ڵ�
	XMLElement* rootNode = xml.NewElement("wang");
	xml.InsertEndChild(rootNode);

	//�½�һ��name�ڵ�
	XMLElement* root_1_name = xml.NewElement("name");


	//�½�name�ڵ���ı�wangqinghe
	//XMLText* text_1_name = xml.NewText("wangqinghe");
	////���ı���name�ڵ���������
	//root_1_name->InsertFirstChild(text_1_name);

	//�½�һ��age�ڵ�
	XMLElement* root_1_age = xml.NewElement("age");
	XMLText* text_1_age = xml.NewText("18");
	root_1_age->SetAttribute("age", "secret");
	root_1_age->InsertFirstChild(text_1_age);

	//����name�ڵ���ӽڵ�
	XMLElement* root_2_gender = xml.NewElement("gender");
	XMLText* text_2_gender = xml.NewText("man");
	root_2_gender->InsertFirstChild(text_2_gender);

	//��gender�ڵ��Ϊname�ڵ���ӽڵ�
	root_1_name->InsertEndChild(root_2_gender);


	//����name�ڵ�����ڵ�
	rootNode->InsertEndChild(root_1_name);
	rootNode->InsertEndChild(root_1_age);
	xml.SaveFile("wang.xml");
}

void decodeXml()
{
	//����
	XMLDocument xml;

	//����xml�ļ�
	if (xml.LoadFile("wang.xml") != XML_SUCCESS)
	{
		return;
	}

	//�ж�ͷ�ļ��Ƿ�Ϊ��
	XMLElement* rootNode = xml.RootElement();
	if (rootNode == NULL)
	{
		return;
	}
	
	//��ȡ��һ����Ϣ
	XMLElement* root_1_name = rootNode->FirstChildElement("name");
	//��ȡ�ڶ�����Ϣ
	XMLElement* root_2_gender = root_1_name->FirstChildElement("gender");
	//��Ϣ���
	string text_gender = root_2_gender->GetText();
	cout << "gender: "<<text_gender << endl;

	//��ȡ��һ����Ϣ
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