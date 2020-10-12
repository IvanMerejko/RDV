import QtQuick 2.12

Item
{
    id: element
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
        x: 8
        width: 36
        height: 14
        color: "white"
        anchors.top: parent.top
        anchors.topMargin: 4
        Text
        {
            anchors.fill: parent
            text: qsTr("text")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
        }
    }
}


/*##^##
Designer {
    D{i:2;anchors_height:10}
}
##^##*/
