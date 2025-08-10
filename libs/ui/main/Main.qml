import QtQuick 2.15
import QtQuick.Controls 2.15
import Login 1.0
import MainWindow 1.0

ApplicationWindow {
    id: appWindow
    visible: true
    width: 400
    height: 600
    minimumWidth: 400
    minimumHeight: 600
    title: "We Together"
    color: "transparent"
    flags: Qt.FramelessWindowHint | Qt.Window

    StackView {
        id: stack
        anchors.fill: parent
        initialItem: loginComp
    }

    Component {
        id: loginComp
        LoginView {
            window: appWindow  // 传入外层的 ApplicationWindow 实例
            onLoginSuccess: function(data) {
                window.loginData = data
                stack.replace(mainComp)
                window.width = 1200
                window.height = 700
            }
        }
    }

    Component {
        id: mainComp
        MainView {
            window: appWindow  // 传入外层的 ApplicationWindow 实例
        }
    }
}
