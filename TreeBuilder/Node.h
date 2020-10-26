#pragma once
#include "Types.h"
#include <deque>
#include "QDebug"
#include <QObject>
namespace PDV::TreeBuilder
{
struct Node : public QObject
{
    Q_OBJECT
public:
    Node() = default;

    Q_INVOKABLE void SetName(const QString& name) { m_name = name; }
    Q_INVOKABLE void AddChild(NodePtr child) { m_childs.push_back(std::move(child)); }

    Q_INVOKABLE void SetAttributes(const Attributes& attributes) { m_attributes = attributes; }
    Q_INVOKABLE void AddAttribute(const Attribute& attribute) { m_attributes.push_back(attribute); }

    Q_INVOKABLE constexpr const Attributes& GetAttributes() const noexcept { return m_attributes; }
    Q_INVOKABLE constexpr const QString& GetName() const noexcept { return m_name; }
    Q_INVOKABLE constexpr const Nodes& GetChilds() const noexcept { return m_childs; }
private:
    QString m_name;
    Nodes m_childs;
    Attributes m_attributes;
};
}
