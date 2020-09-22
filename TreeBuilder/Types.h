#include <memory>
#include <vector>

namespace PDV::TreeBuilder::Types
{
class Node;
using NodePtr = std::shared_ptr<Node>;

using Attribute = std::pair<std::string, std::string>;
using Attributes = std::vector<Attribute>;
}
