#pragma once
#include "Node.h"
#include "Types.h"

namespace PDV::TreeBuilder
{
class XMLManager
{
public:
    void ParseFile(std::string_view fileName);

private:
    NodePtr m_root;
};

}
