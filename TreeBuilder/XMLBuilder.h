#pragma once
#include <string_view>
#include "Types.h"
namespace PDV::TreeBuilder
{

class XMLBuilder
{
public:
    static NodePtr Parse(const QString& fileName);
};

}
