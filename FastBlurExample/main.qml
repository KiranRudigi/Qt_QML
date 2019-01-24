import QtQuick 2.12
import QtQuick.Window 2.12
import QtGraphicalEffects 1.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle{
        width: 100
        height: 100
        color: "orange"
        anchors.centerIn: parent
        Rectangle {
            id: bug
            smooth: true
            width: 100
            height: 100
            color: "black"
            visible: false
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            z: -1
        }

        FastBlur {
            anchors.fill: bug
            source: bug
            radius: 32
            z: -1
            transparentBorder: true
        }
    }
}
