#pragma once
#include <QObject>
#include <memory>
namespace PDV
{
struct QObjectDeleter
{
    void operator()(QObject *object)
    {
        object->deleteLater();
    }
};
using QObjectPtr = std::unique_ptr<QObject, QObjectDeleter>;
}
