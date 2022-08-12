#include <iostream>  
#include"tinyxml2.h"  
using namespace std;
using namespace tinyxml2;
void example2()
{
    XMLDocument doc;
    doc.LoadFile("test.xml");
    XMLElement* scene = doc.RootElement();
    XMLElement* surface = scene->FirstChildElement("node");
    while (surface)
    {
        XMLElement* surfaceChild = surface->FirstChildElement();
        const char* content;
        const XMLAttribute* attributeOfSurface = surface->FirstAttribute();
        cout << attributeOfSurface->Name() << ":" << attributeOfSurface->Value() << endl;
        while (surfaceChild)
        {
            content = surfaceChild->GetText();
            surfaceChild = surfaceChild->NextSiblingElement();
            cout << content << endl;
        }
        surface = surface->NextSiblingElement();
    }
}
int main()
{
    example2();
    return 0;
}