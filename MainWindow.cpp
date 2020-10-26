#include "MainWindow.h"
#include <algorithm>
#include <QDebug>
#include <boost/range/algorithm.hpp>
#include "TreeBuilder/XMLBuilder.h"
#include "TreeBuilder/Types.h"

namespace PDV
{

namespace
{
    constexpr auto MainWindowStr = "mainWindow";
    constexpr auto LoadButtonStr = "loadButton";
}

MainWindow::MainWindow(std::string_view fileName)
{
    load(fileName.data());

    initializeWindowPtr();
    initializeContext();
    createConnectionWithQmlObjects();

    m_xmlManager.ParseFile("file.xml");
}

void MainWindow::createConnectionWithQmlObjects()
{

#define connectIfInitialize(signalObject, signalMethod, slotObject, slotMethod)\
    if ( !(signalObject) ) \
    { \
        qDebug() << "Error: " << #signalObject; \
    }\
    else\
    {\
        connect(signalObject.get(), SIGNAL(signalMethod()), slotObject, SLOT(slotMethod())); \
    }

    connectIfInitialize(m_loadFileButton, clicked, this, loadNewXMLFile);
}

void MainWindow::loadNewXMLFile()
{
    qDebug() << "loadNewXMLFile";
    connect(this, SIGNAL(displayXMLFile(const QString&, const QVariant&)), m_mainWindow.get(), SIGNAL(displayRoot(const QString&, const QVariant&)));
    emit displayXMLFile(m_xmlManager.GetRoot()->GetName(), QVariant{m_xmlManager.GetRoot()->GetAttributes()});
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

void MainWindow::initializeContext()
{
    qRegisterMetaType<TreeBuilder::NodePtr>("NodePtr");
    qmlRegisterType<TreeBuilder::Node>("Node", 1, 0, "Node");
    m_loadFileButton = getPointerForElementByName(LoadButtonStr);
}

QObjectPtr MainWindow::getPointerForElementByName(std::string_view name)
{
   return MakeQObjectUP(m_mainWindow->findChild<QObject *>(name.data()));
}

}
