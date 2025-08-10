import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import PublicComponet 1.0

Rectangle {
    id: mainTitleBar
    height: 36
    color: "#1b1f23"
    anchors { top: parent.top; left: parent.left; right: parent.right }
    property QtObject window

    WindowBehavior {
        id: windowBehavior
        window: mainTitleBar.window  // 外层传入的 ApplicationWindow 实例
    }

    RowLayout {
        anchors.fill: parent; anchors.margins: 4
        Label {
            text: "主界面"
            color: "#fff"
            font.pixelSize: 14
        }
        Item { Layout.fillWidth: true }
        ToolButton {
            Layout.preferredWidth: 32
            Layout.preferredHeight: 32
            contentItem: Text { text: "🗕"; color: "#bbb"; font.pixelSize: 12 }
            onClicked: windowBehavior.minimize()
        }
        ToolButton {
            Layout.preferredWidth: 32
            Layout.preferredHeight: 32
            contentItem: Text { text: windowBehavior.window.visibility === Window.Maximized ? "🗗" : "🗖"; color: "#bbb"; font.pixelSize: 12 }
            onClicked: windowBehavior.maximize()
        }
        ToolButton {
            Layout.preferredWidth: 32
            Layout.preferredHeight: 32
            contentItem: Text { text: "✕"; color: "#bbb"; font.pixelSize: 12 }
            onClicked: windowBehavior.close()
        }
    }
}
