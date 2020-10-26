#pragma once
#include <memory>
#include <vector>
#include <deque>
#include <QSharedPointer>

namespace PDV::TreeBuilder
{
class Node;
using NodePtr = QSharedPointer<Node>;
using Nodes = std::deque<NodePtr>;

using Attribute = std::pair<std::string, std::string>;
using Attributes = std::vector<Attribute>;
}
