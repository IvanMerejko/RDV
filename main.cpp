#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "MainWindow.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    app.setOrganizationName("somename");
    app.setOrganizationDomain("somename");

    PDV::MainWindow mainWindow{"qrc:/main.qml"};

    return app.exec();
}
