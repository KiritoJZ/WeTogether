import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Item {
    id: mainView
    Layout.fillWidth: true
    Layout.fillHeight: true

    property var window: null  // 外层传入的 ApplicationWindow 实例

    MainTitleBar {
        id: mainTitleBar
        window: mainView.window  // 传入外层的 ApplicationWindow 实例
    }

    /* 三列布局容器 */
    RowLayout {
        anchors.fill: parent

        /* 1️ 左侧导航栏 */
        Rectangle {
            id: navBar
            Layout.preferredWidth: 70
            Layout.fillHeight: true
            color: "#1e2228"

            Column {
                anchors.centerIn: parent
                spacing: 20
                Repeater {
                    model: ["最近聊天", "好友", "群聊"]
                    Rectangle {
                        width: 46; height: 46; radius: 23
                        color: index === root.currentTab ? "#0078d4" : "transparent"
                        Text {
                            anchors.centerIn: parent
                            text: ["💬", "👥", "🗂️"][index]
                            font.pixelSize: 20
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: root.currentTab = index
                        }
                    }
                }
            }
        }

        /* 2️ 中间导航页 */
        StackView {
            id: navPage
            Layout.preferredWidth: 240
            Layout.fillHeight: true
            initialItem: Rectangle {
                color: "#252a30"
                Text {
                    anchors.centerIn: parent
                    text: root.currentTab === 0 ? "最近聊天列表"
                         : root.currentTab === 1 ? "好友列表"
                         : "群聊列表"
                    color: "#aaa"; font.pixelSize: 14
                }
            }
        }

        /* 3️ 右侧主内容区 */
        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#20242a"

            ColumnLayout {
                anchors.fill: parent
                spacing: 0

                /* 主内容区标题栏 */
                Rectangle {
                    id: contentTitleBar
                    Layout.preferredHeight: 36
                    Layout.fillWidth: true
                    color: "#1b1f23"

                    RowLayout {
                        anchors.fill: parent; anchors.margins: 4
                        Label {
                            text: root.currentTab === 0 ? "最近聊天"
                                 : root.currentTab === 1 ? "好友" : "群聊"
                            color: "#fff"; font.pixelSize: 14
                        }
                        Item { Layout.fillWidth: true }
                        /* 最小化 / 最大化 / 关闭 */
                        ToolButton {
                            Layout.preferredWidth: 32; Layout.preferredHeight: 32
                            contentItem: Text { text: "🗕"; color: "#bbb"; font.pixelSize: 12 }
                            onClicked: root.showMinimized()
                        }
                        ToolButton {
                            Layout.preferredWidth: 32; Layout.preferredHeight: 32
                            contentItem: Text { text: root.visibility === Window.Maximized ? "🗗" : "🗖"; color: "#bbb"; font.pixelSize: 12 }
                            onClicked: root.visibility = root.visibility === Window.Maximized ? Window.Windowed : Window.Maximized
                        }
                        ToolButton {
                            Layout.preferredWidth: 32; Layout.preferredHeight: 32
                            contentItem: Text { text: "✕"; color: "#bbb"; font.pixelSize: 12 }
                            onClicked: root.close()
                        }
                    }
                }

                /* ---------- 聊天窗口主体 ---------- */
                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    color: "#2b2e37"

                    ColumnLayout {
                        spacing: 0
                        anchors.fill: parent

                        /* 1️ 会话标题 */
                        Rectangle {
                            Layout.preferredHeight: 50
                            Layout.fillWidth: true
                            color: "#343740"
                            RowLayout {
                                anchors.centerIn: parent
                                spacing: 8
                                Image {
                                    Layout.preferredWidth: 36
                                    Layout.preferredHeight: 36
                                    source: root.loginData.avatar || "qrc:/img/default.png"
                                    fillMode: Image.PreserveAspectFit
                                    layer.smooth: true
                                    layer.mipmap: true
                                    Rectangle {
                                        anchors.fill: parent
                                        radius: 18
                                        color: "transparent"
                                        border.width: 1
                                        border.color: "#555"
                                    }
                                }
                                ColumnLayout {
                                    Layout.fillWidth: true
                                    Label {
                                        text: root.loginData.nick || "对方昵称"
                                        color: "#fff"
                                        font.pixelSize: 14
                                        font.bold: true
                                    }
                                    Label {
                                        text: "在线"
                                        color: "#8a8f99"
                                        font.pixelSize: 11
                                    }
                                }
                            }
                        }

                        /* 2️ 消息气泡区域 */
                        ListView {
                            id: msgList
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            clip: true
                            spacing: 8
                            model: ListModel {
                                ListElement { isMe: false; avatar: ""; text: "你好呀！" }
                                ListElement { isMe: true;  avatar: "";    text: "嗨，在的~" }
                            }
                            delegate: RowLayout {
                                width: msgList.width
                                spacing: 6
                                LayoutMirroring.enabled: model.isMe
                                LayoutMirroring.childrenInherit: true

                                Image {
                                    Layout.preferredWidth: 36
                                    Layout.preferredHeight: 36
                                    source: model.avatar
                                    fillMode: Image.PreserveAspectFit
                                    Rectangle {
                                        anchors.fill: parent
                                        radius: 18
                                        color: "transparent"
                                        border.width: 1
                                        border.color: "#555"
                                    }
                                }

                                Rectangle {
                                    Layout.maximumWidth: msgList.width * 0.65
                                    color: model.isMe ? "#1989fa" : "#4c4f57"
                                    radius: 12
                                    Label {
                                        anchors.fill: parent
                                        anchors.margins: 10
                                        text: model.text
                                        color: "#fff"
                                        wrapMode: Text.Wrap
                                    }
                                }
                                Item { Layout.fillWidth: true }   // 撑开空白
                            }
                            ScrollBar.vertical: ScrollBar {}
                        }

                        /* 3️ 输入栏 */
                        Rectangle {
                            Layout.preferredHeight: 56
                            Layout.fillWidth: true
                            color: "#343740"
                            RowLayout {
                                spacing: 6
                                anchors { fill: parent; margins: 8 }

                                ToolButton {
                                    Layout.preferredWidth: 32
                                    Layout.preferredHeight: 32
                                    icon.source: "qrc:/icons/emoji.svg"
                                }

                                TextArea {
                                    id: inputArea
                                    Layout.fillWidth: true
                                    Layout.fillHeight: true
                                    placeholderText: "输入消息..."
                                    font.pixelSize: 13
                                    color: "#fff"
                                    background: Rectangle { radius: 6; color: "#2b2e37"; border.color: "#555" }
                                }

                                Button {
                                    Layout.preferredWidth: 60
                                    Layout.fillHeight: true
                                    text: "发送"
                                    font.pixelSize: 13
                                    background: Rectangle { radius: 6; color: "#1989fa" }
                                    onClicked: {
                                        if (inputArea.text.trim() === "") return;
                                        msgList.model.append({
                                            isMe: true,
                                            avatar: root.loginData.avatar,
                                            text: inputArea.text.trim()
                                        });
                                        inputArea.clear();
                                        msgList.positionViewAtEnd();
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    /* 当前激活的导航页索引 */
    property int currentTab: 0
}
