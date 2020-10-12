import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.0
import "componentCreation.js" as MyScript

Window
{
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Button
    {
        x: 39
        y: 49
        text: "add "
        font.family: "Arial"
        autoRepeat: false
        onClicked:
        {
            MyScript.createSpriteObjects("Block.qml");
        }
    }
//    Button
//    {
//        x: 39
//        y: 49
//        text: "load "
//        font.family: "Arial"
//        autoRepeat: false
//        onClicked:
//        {
//            MyScript.createSpriteObjects("FileLoader.qml");
//        }
//    }

}
