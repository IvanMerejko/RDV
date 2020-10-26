import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.0

Item
{
    property string nodeName: ""
    property int possibleNodeNameLength: (element.width  - textField.x * 2 ) / 10
    property variant attributes: ({})

    id: element
    height: 200
    width: 200
    Rectangle
    {
        anchors.fill: parent
        anchors.topMargin: textField.height / 2
        border.color: "black"
        border.width: 2
        height: parent.height - textField.height / 2
        width: parent.width
    }
    TextField
    {
        id: textField
        x: 10
        anchors.top: parent.top
        anchors.topMargin: 4
        text: nodeName
        width: getWidthForElementName()
        height: 30
        onTextChanged:
        {
            element.nodeName = textField.text
        }
        font.pixelSize: 15
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
    }


    function canDisplayAllText(textToDisplay)
    {
        return textToDisplay.length < element.possibleNodeNameLength
    }

    function getWidthForElementName()
    {
        return canDisplayAllText(element.nodeName) ? element.nodeName.length * 10 : element.width  - textField.x * 2;
    }

    property var childs: []
}

