#pragma once

#include <QQmlApplicationEngine>
#include "Context.h"
#include "Types.h"
#include "TreeBuilder/Types.h"

namespace PDV
{
class MainWindow : public QQmlApplicationEngine, public Context
{
    Q_OBJECT
public:
    explicit MainWindow(std::string_view fileName);

signals:
    void displayXMLFile(const QString&, const QVariant&);

public slots:
    void loadNewXMLFile();

private:
    void initializeWindowPtr();
    void initializeContext();
    QObjectPtr getPointerForElementByName(std::string_view name);

    void createConnectionWithQmlObjects();
};

}
