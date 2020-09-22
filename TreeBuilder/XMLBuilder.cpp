#include "XMLBuilder.h"
#include "Tree.h"
#include <string_view>
#include <QFile>
#include <QDebug>
#include <QXmlStreamReader>
namespace PDV::TreeBuilder
{

TreePtr XMLBuilder::Parse(std::string_view fileName)
{
    QFile file(fileName.data());
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Cannot read file" << file.errorString();
        return nullptr;
    }

    QXmlStreamReader xml(&file);
    while(!xml.atEnd() && !xml.hasError())
    {
        if(xml.readNext() == QXmlStreamReader::StartDocument)
        {
            continue;
        }
        qDebug() << "Name = " << xml.name() << " Value = " << xml.text();
        qDebug() << "attributes";
        for(const auto& attribute : xml.attributes())
        {
            qDebug() << "Name = " << attribute.name() << " Value = " << attribute.value().toString();
        }
    }
    return nullptr;
}

}
