import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.4
import Settings 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Item{
        anchors.fill: parent

        Column{
            width: parent.width * 0.5
            anchors.centerIn: parent

            RadioButton{
                id: kan
                text: "Kannada"
                checked: settings.checkedLanguage === text ? true : false
                onCheckedChanged:kan.checked ? settings.checkedLanguage = kan.text : ""
            }
            RadioButton{
                id: hin
                text: "Hindi"
                checked: settings.checkedLanguage === text ? true : false
                onCheckedChanged:hin.checked ? settings.checkedLanguage = hin.text : ""
            }
            RadioButton{
                id: eng
                text: "English"
                checked: settings.checkedLanguage === text ? true : false
                onCheckedChanged:eng.checked ? settings.checkedLanguage = eng.text : ""
            }
        }
    }

    MySettings{
        id: settings
        onCheckedLanguageChanged: {
            console.log("Language changed to ",checkedLanguage)
        }
    }

    Component.onCompleted: {
        settings.loadSet()
    }

    Component.onDestruction: {
        settings.checkedLanguage = kan.checked ? kan.text :
                                                 hin.checked ? hin.text :
                                                               eng.checked ? eng.text : "NULL"
        settings.saveSet()
    }

}
