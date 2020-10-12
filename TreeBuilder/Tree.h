#pragma once
#include "Types.h"
namespace PDV::TreeBuilder
{
    struct Node
    {
    public:
        void SetName(std::string name) { m_name = std::move(name); }
        void AddChild(NodePtr child) { m_childs.push_back(std::move(child)); }
        void AddAttribute(Attribute attribute) { m_attributes.push_back(std::move(attribute));}

        constexpr const Attributes& GetAttributes() noexcept { return m_attributes; }
        constexpr const std::string& GetName() noexcept { return m_name; }
        constexpr const std::vector<NodePtr>& GetChilds() noexcept { return m_childs; }
    private:
        std::string m_name;
        std::vector<NodePtr> m_childs;
        Attributes m_attributes;
    };

    class Tree
    {
        explicit Tree(NodePtr root);
    private:

        NodePtr m_root;
    };
    using TreePtr = std::unique_ptr<Tree>;
}
