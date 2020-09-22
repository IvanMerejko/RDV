#pragma once
#include <string_view>
#include "Tree.h"
namespace PDV::TreeBuilder
{

class XMLBuilder
{
public:
    static TreePtr Parse(std::string_view fileName);
};

}
