#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "TreeBuilder/XMLBuilder.h"
#include <iostream>

int main(int argc, char *argv[])
{
    PDV::TreeBuilder::XMLBuilder::Parse("file.xml");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    app.setOrganizationName("somename");
    app.setOrganizationDomain("somename");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);



    return app.exec();
}
