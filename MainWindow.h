#pragma once

#include <QQmlApplicationEngine>
#include "Context.h"

namespace PDV
{
class MainWindow : public QQmlApplicationEngine, public Context
{
    Q_OBJECT
public:
    explicit MainWindow(std::string_view fileName);

private:
    void initializeWindowPtr();
};

}
