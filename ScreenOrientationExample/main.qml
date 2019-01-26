import QtQuick 2.9
import QtQuick.Window 2.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    function orientationToString(o) {
        switch (o) {
        case Qt.PrimaryOrientation:
            return "primary";
        case Qt.PortraitOrientation:
            return "portrait";
        case Qt.LandscapeOrientation:
            return "landscape";
        case Qt.InvertedPortraitOrientation:
            return "inverted portrait";
        case Qt.InvertedLandscapeOrientation:
            return "inverted landscape";
        }
        return "unknown";
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"' + " Screen orientation-> " + orientationToString(Screen.primaryOrientation)))
        }
    }

    TextEdit {
        id: textEdit
        text: qsTr("Enter some text...")
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        Rectangle {
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            border.width: 1
        }
    }
}
