#pragma once
#include <QSharedPointer>
#include <qqueue.h>

namespace PDV::TreeBuilder
{
class Node;
using NodePtr = QSharedPointer<Node>;
using Nodes = QQueue<NodePtr>;

using Attribute = QPair<QString, QString>;
using Attributes = QVector<Attribute>;
}
