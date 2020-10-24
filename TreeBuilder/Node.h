#pragma once
#include "Types.h"
#include <deque>
#include "QDebug"
namespace PDV::TreeBuilder
{
struct Node
{
public:
    void SetName(const std::string& name) { m_name = name; qDebug() << name.c_str() << " " << m_name.c_str(); }
    void SetChilds(Nodes&& childs) { m_childs = std::move(childs); }
    void AddChild(NodePtr child) { m_childs.push_back(std::move(child)); }

    void SetAttributes(Attributes&& attributes) { m_attributes = std::move(attributes); }
    void AddAttribute(Attribute&& attribute) { m_attributes.push_back(std::move(attribute)); }

    constexpr const Attributes& GetAttributes() const noexcept { return m_attributes; }
    constexpr const std::string& GetName() const noexcept { return m_name; }
    constexpr const Nodes& GetChilds() const noexcept { return m_childs; }
private:
    std::string m_name;
    Nodes m_childs;
    Attributes m_attributes;
};
}
