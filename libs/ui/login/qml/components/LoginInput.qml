import QtQuick 2.15
import QtQuick.Controls 2.15

TextField {
    id: control
    placeholderTextColor: "#8e8e8e"
    color: "#111"
    font.pixelSize: 14
    background: Rectangle {
        color: "#f3f3f3"
        radius: 6
        border.color: control.activeFocus ? "#12b7f5" : "#e0e0e0"
        border.width: 1
    }
}
