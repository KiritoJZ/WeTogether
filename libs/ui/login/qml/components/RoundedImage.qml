import QtQuick 2.15

Rectangle {
    width: 80
    height: 80
    radius: width / 2
    clip: true
    property alias source: img.source
    Image {
        id:img
        anchors.fill: parent
        source: "avatar.png"
        fillMode: Image.PreserveAspectCrop
    }
}
