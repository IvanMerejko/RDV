#pragma once
#include "Types.h"
namespace PDV::TreeBuilder
{
    struct Node
    {
        std::vector<Types::NodePtr> m_childs;
        Types::Attributes m_attributes;
    };

    class Tree
    {
    private:

    };
    using TreePtr = std::unique_ptr<Tree>;
}
