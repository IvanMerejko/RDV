#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "TreeBuilder/XMLBuilder.h"
#include "MainWindow.h"
#include <iostream>

int main(int argc, char *argv[])
{
    PDV::TreeBuilder::XMLBuilder::Parse("file.xml");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    app.setOrganizationName("somename");
    app.setOrganizationDomain("somename");

    PDV::MainWindow mainWindow{"qrc:/main.qml"};



    return app.exec();
}
