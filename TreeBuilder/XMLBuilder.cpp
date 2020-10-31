#include "XMLBuilder.h"
#include <string_view>
#include <QFile>
#include "Types.h"
#include "Node.h"
#include <QDebug>
#include <QXmlStreamReader>

namespace PDV::TreeBuilder
{
namespace
{

NodePtr parseXMLElement(QXmlStreamReader& xmlStream)
{
    NodePtr node = NodePtr::create();
    while (!xmlStream.atEnd() && !xmlStream.hasError())
    {
        auto token = xmlStream.readNext();
        if (token == QXmlStreamReader::StartDocument)
        {
            continue;
        }
        if (token == QXmlStreamReader::StartElement)
        {
            node->SetName(xmlStream.name().toString());
            Attributes attributes;
            for(const auto& attr : xmlStream.attributes())
            {
                attributes.push_back(qMakePair(attr.name().toString(),attr.value().toString()));
            }
            node->SetAttributes(attributes);
        }
        else if(token == QXmlStreamReader::Characters)
        {

            auto child = parseXMLElement(xmlStream);
            if (child && !child->GetName().isEmpty())
            {
                node->AddChild(child);
            }
        }

    }
    return node;
}

}

NodePtr XMLBuilder::Parse(const QString&)
{
    try
    {
        auto xmlFile = QFile("file.txt");
        xmlFile.open(QIODevice::ReadOnly);
        auto xmlReader = QXmlStreamReader(&xmlFile);
        auto result = parseXMLElement(xmlReader);
        return result;
    }
    catch(...)
    {
        return nullptr;
    }
}

}
