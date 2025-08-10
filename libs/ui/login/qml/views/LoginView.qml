import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Login 1.0

Rectangle {
    id: loginView
    color: "#ffffff"
    radius: 16
    clip: true
    Layout.fillWidth: true
    Layout.fillHeight: true
    border.color: "#dcdcdc"
    border.width: 1
    property var window

    /* 1. 拖拽层：只覆盖空白区域 + 标题栏 */
    Rectangle {
       id: dragArea
       anchors {
           top: parent.top
           left: parent.left
           right: parent.right
           bottom: inputColumn.top
       }
       color: "transparent"

       MouseArea {
           anchors.fill: parent
           acceptedButtons: Qt.LeftButton
           onPressed: mouse => {
               if (mouse.button === Qt.LeftButton)
                   loginView.window.startSystemMove()
           }
       }
    }


    /* 2. 标题栏 */
    LoginTitleBar {
        id: loginTitleBar
        window: loginView.window
    }

    /* 3. 头像 */
    RoundedImage {
        id: avatar
        anchors {
            top: parent.top
            topMargin: 90
            horizontalCenter: parent.horizontalCenter
        }
        width: 120
        height: 120
        source: "qrc:/images/default-avatar.png"
    }

    /* 4. 输入区 & 按钮 */
    ColumnLayout {
        id: inputColumn
        anchors {
            top: avatar.bottom
            topMargin: 100
            horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
        }
        spacing: 16

        /* 手机 / 邮箱输入框 */
        LoginInput {
            id: userInput
            Layout.preferredWidth: 300
            Layout.preferredHeight: 44
            placeholderText: "手机 / 邮箱"
        }

        /* 密码输入框 */
        LoginInput {
            id: pwdInput
            Layout.preferredWidth: 300
            Layout.preferredHeight: 44
            placeholderText: "密码"
            echoMode: TextInput.Password
        }

        /* “忘记密码 / 注册” 行 */
        RowLayout {
            Layout.preferredWidth: 300
            Label {
                text: "<a href='forget'>忘记密码?</a>"
                color: "#0078D4"; font.pixelSize: 13
                onLinkActivated: Qt.openUrlExternally("https://aq.qq.com/cn2/findpsw/pc/pc_proxy_login")
            }
            Item { Layout.fillWidth: true }
            Label {
                text: "<a href='register'>注册新账号</a>"
                color: "#0078D4"; font.pixelSize: 13
                onLinkActivated: Qt.openUrlExternally("https://zc.qq.com")
            }
        }

        /* 登录按钮 */
        LoginButton {
            id: loginBtn
            Layout.preferredWidth: 300
            Layout.preferredHeight: 40
            text: "登录"
            onClicked: {
                const ok = ctrl.checkInput(userInput.text, pwdInput.text)
                if (!ok) {
                    errorLabel.text = "账号或密码格式不正确"
                    return
                }
                errorLabel.text = ""
                ctrl.login(userInput.text, pwdInput.text)
            }
        }

        /* 错误提示 */
        Label {
            id: errorLabel
            Layout.topMargin: 12
            Layout.alignment: Qt.AlignHCenter
            color: "red"
            text: ""
        }
    }

    /* 回车登录 */
    focus: true
    Keys.enabled: true
    Keys.onReturnPressed: {
        if (userInput.text && pwdInput.text)
            loginBtn.clicked()
    }

    /* 数据与控制器 */
    UserModel { id: user }
    LoginController { id: ctrl }
    signal loginSuccess(var data)
    Connections {
        target: ctrl
        function onSuccess(dataObj) {
            loginView.loginSuccess(dataObj)
        }
        function onError(msg) { errorLabel.text = msg }
    }
}
