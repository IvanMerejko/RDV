#include "MainWindow.h"
#include <algorithm>
#include <QDebug>
#include <boost/range/algorithm.hpp>

namespace PDV
{

namespace
{
    constexpr auto MainWindowStr = "mainWindow";
}

MainWindow::MainWindow(std::string_view fileName)
{
    load(fileName.data());

    initializeWindowPtr();
}

void MainWindow::initializeWindowPtr()
{
    auto roots = rootObjects();
    auto windowObject = boost::range::find_if(roots, [&](const auto* object)
    {
        return  object->objectName() == MainWindowStr;
    });

    if(windowObject != roots.end())
    {
        m_mainWindow = MakeQObjectUP(*windowObject);
    }
    else
    {
       qDebug() << "Cannot initialize MainWindow ptr";
    }
}

}
