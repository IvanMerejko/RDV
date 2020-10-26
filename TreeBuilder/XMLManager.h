#pragma once
#include "Node.h"
#include "Types.h"

namespace PDV::TreeBuilder
{
class XMLManager
{
public:
    void ParseFile(std::string_view fileName);

    const NodePtr& GetRoot() const noexcept { return m_root; }

private:
    NodePtr m_root;
};

}
