import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.0
import "componentCreation.js" as MyScript

Window
{
    signal displayRoot(string nodeName, variant attributes)
    id: mainWindow
    objectName: "mainWindow"
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Button
    {
        objectName: "loadButton"
        x: 5
        y: 5
        text: "add "
    }
    onDisplayRoot: MyScript.createSpriteObjects("Block.qml", nodeName)
}
