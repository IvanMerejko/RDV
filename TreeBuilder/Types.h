#pragma once
#include <memory>
#include <vector>
#include <deque>

namespace PDV::TreeBuilder
{
class Node;
using NodePtr = std::shared_ptr<Node>;
using Nodes = std::deque<NodePtr>;

using Attribute = std::pair<std::string, std::string>;
using Attributes = std::vector<Attribute>;
}
