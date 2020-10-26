#pragma once
#include <memory>
#include <QObject>
#include "TreeBuilder/XMLManager.h"
#include "Types.h"

namespace PDV
{

template<typename ...Args>
constexpr auto MakeQObjectUP(Args&&... value)
{
    QObjectDeleter deleter;
    return std::unique_ptr<QObject, decltype(deleter)>(std::forward<Args>(value)..., deleter);
}

struct Context
{
    QObjectPtr m_mainWindow;
    QObjectPtr m_loadFileButton;
    TreeBuilder::XMLManager m_xmlManager;
};

}
