import QtQuick 2.15
import QtQuick.Controls 2.15

TextField {
    font.pixelSize: 15
    background: Rectangle {
        radius: 6
        color: parent.activeFocus ? "#f0f5ff" : "#f5f5f5"
        border.color: parent.activeFocus ? "#006eff" : "#e5e5e5"
        border.width: 1
    }
    leftPadding: 12
    rightPadding: 12
    property alias placeholderText: placeholder.text
    Text {
        id: placeholder
        anchors.left: parent.left
        anchors.leftMargin: 12
        anchors.verticalCenter: parent.verticalCenter
        color: "#999"
        visible: parent.text === ""
    }
}