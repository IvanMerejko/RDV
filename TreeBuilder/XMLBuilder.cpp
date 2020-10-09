#include "XMLBuilder.h"
#include "Tree.h"
#include <string_view>
#include <QFile>
#include "Types.h"
#include <QDebug>
#include <QXmlStreamReader>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

namespace PDV::TreeBuilder
{
namespace
{
constexpr auto XMLAttribute = "<xmlattr>";
const boost::property_tree::ptree& emptyPtree()
{
    static boost::property_tree::ptree t;
    return t;
}

void ParseAttributtes(const boost::property_tree::ptree& tree)
{
   const auto& attributes = tree.get_child(XMLAttribute, emptyPtree());
   for(const auto& [name, childs] : attributes)
   {
       const auto& value = attributes.get<std::string>(name);
       qDebug() << name.c_str() << " " << value.c_str();
   }
}

void ParseXMLElement(const boost::property_tree::ptree& tree)
{
    for(const auto& [name, childs] : tree)
    {
        if(name == XMLAttribute)
        {
            ParseAttributtes(tree);
            continue;
        }
        qDebug() << name.c_str();
        for(const auto &[childName, childTree] : childs)
        {
            if(childName == XMLAttribute)
            {
                ParseAttributtes(childs);
                continue;
            }
            qDebug() << childName.c_str();
            ParseXMLElement(childTree);
        }
    }
}

}

TreePtr XMLBuilder::Parse(std::string_view)
{
    boost::property_tree::ptree tree;
    boost::property_tree::read_xml("/home/ivanm/PDV/file.xml", tree);
    ParseXMLElement(tree);
    return nullptr;
}

}
