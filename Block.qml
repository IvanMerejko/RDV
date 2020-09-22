import QtQuick 2.12

Item
{
    height: 100
    width: 100
    Rectangle
    {
        anchors.fill: parent
        anchors.topMargin: 10
        border.color: "black"
        border.width: 2
        height: parent.height * 0.9
        width: parent.width
    }

    Rectangle
    {
        height: parent.height * 0.1
        anchors.top: parent.top
        anchors.leftMargin: 10
        width: 20
        color: "white"
        Text
        {
            anchors.fill: parent
            text: qsTr("text")
        }
    }
}

