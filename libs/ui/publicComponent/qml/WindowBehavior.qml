import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Item {
    id: windowBehavior
    property var window

    function minimize() {
        if (windowBehavior.window) {
            windowBehavior.window.showMinimized()
        }
    }

    function maximize() {
        if (windowBehavior.window) {
            windowBehavior.window.visibility = windowBehavior.window.visibility === Window.Maximized ? Window.Windowed : Window.Maximized
        }
    }

    function close() {
        if (windowBehavior.window) {
            windowBehavior.window.close()
        }
    }
}
