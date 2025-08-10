import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import PublicComponet 1.0

Rectangle {
    id: loginTitleBar
    height: 40
    color: "transparent"
    anchors { top: parent.top; left: parent.left; right: parent.right;}
    property QtObject window
    WindowBehavior {
        id: windowBehavior
        window: loginTitleBar.window
    }

    Rectangle {
        id: minBtn
        width: 40; height: 40
        anchors { right: closeBtn.left; verticalCenter: parent.verticalCenter; rightMargin: 4 }
        radius: 16
        color: minArea.containsMouse ? "#1976D2" : "transparent"
        Text { anchors.centerIn: parent; text: "—"; color: "#90CAF9"; font.pixelSize: 16 }
        MouseArea {
            id: minArea
            anchors.fill: parent
            hoverEnabled: true
            onClicked: windowBehavior.minimize()
        }
    }

    Rectangle {
        id: closeBtn
        width: 40; height: 40
        anchors { right: parent.right; verticalCenter: parent.verticalCenter;}
        radius: 16
        color: closeArea.containsMouse ? "#1976D2" : "transparent"
        Text { anchors.centerIn: parent; text: "✕"; color: "#90CAF9"; font.pixelSize: 16 }
        MouseArea {
            id: closeArea
            anchors.fill: parent
            hoverEnabled: true
            onClicked: windowBehavior.close()
        }
    }
}
