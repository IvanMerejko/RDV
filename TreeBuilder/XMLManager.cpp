#include "XMLManager.h"
#include "XMLBuilder.h"
namespace PDV::TreeBuilder
{
void XMLManager::ParseFile(const QString& fileName)
{
    m_root = XMLBuilder::Parse(fileName);
}

}
