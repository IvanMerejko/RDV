#include "XMLManager.h"
#include "XMLBuilder.h"
namespace PDV::TreeBuilder
{
void XMLManager::ParseFile(std::string_view fileName)
{
    m_root = XMLBuilder::Parse(fileName);
}

}
