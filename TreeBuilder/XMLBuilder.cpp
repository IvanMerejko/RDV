#include "XMLBuilder.h"
#include <string_view>
#include <QFile>
#include "Types.h"
#include "Node.h"
#include <QDebug>
#include <QXmlStreamReader>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

namespace PDV::TreeBuilder
{
namespace
{
constexpr auto XMLAttribute = "<xmlattr>";
static const boost::property_tree::ptree emptyPtree{};
Attributes ParseAttributtes(const boost::property_tree::ptree& tree)
{
   Attributes attributes;
   const auto& XMLAttributes = tree.get_child(XMLAttribute, emptyPtree);
   for(const auto& [name, childs] : XMLAttributes)
   {
       const auto& value = XMLAttributes.get<std::string>(name);
       attributes.emplace_back(name, value);
   }
   return attributes;
}

NodePtr ParseXMLElement(const boost::property_tree::ptree& tree)
{
    auto node = std::make_shared<Node>();
    for(const auto& [name, childs] : tree)
    {
        if (name == XMLAttribute)
        {
            node->SetAttributes(ParseAttributtes(tree));
        }
        else
        {
            node->SetName(name);
            node->AddChild(ParseXMLElement(childs));
        }
    }
    return node;
}

}

NodePtr XMLBuilder::Parse(std::string_view)
{
    try
    {
        boost::property_tree::ptree tree;
        boost::property_tree::read_xml("/home/ivanm/PDV/file.xml", tree);
        auto result = ParseXMLElement(tree);
        return result;
    }
    catch(...)
    {
        return nullptr;
    }
}

}
