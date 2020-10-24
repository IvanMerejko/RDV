#pragma once
#include <memory>
#include <QObject>

namespace PDV
{

struct QObjectDeleter
{
    void operator()(QObject *object)
    {
        object->deleteLater();
    }
};

template<typename ...Args>
constexpr auto MakeQObjectUP(Args&&... value)
{
    QObjectDeleter deleter;
    return std::unique_ptr<QObject, decltype(deleter)>(std::forward<Args>(value)..., deleter);
}

struct Context
{
    using QObjectPtr = std::unique_ptr<QObject, QObjectDeleter>;
    QObjectPtr m_mainWindow;
};

}
