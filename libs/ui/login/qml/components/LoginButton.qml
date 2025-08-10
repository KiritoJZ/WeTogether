import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    id: control
    font.pixelSize: 15
    font.bold: true
    palette.buttonText: "white"
    background: Rectangle {
        color: control.down ? "#0e9cdd" : "#12b7f5"
        radius: 6
    }
}