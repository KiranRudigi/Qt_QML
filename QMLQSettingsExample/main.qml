import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.2
import Settings 1.0
import Qt.labs.settings 1.0

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
                checked: settings.language === text ? true : false
//                checked: settings.checkedLanguage === text ? true : false
                onCheckedChanged:kan.checked ? settings.language = kan.text : ""
//                onCheckedChanged:kan.checked ? settings.checkedLanguage = kan.text : ""
            }
            RadioButton{
                id: hin
                text: "Hindi"
                checked: settings.language === text ? true : false
//                checked: settings.checkedLanguage === text ? true : false
                onCheckedChanged:hin.checked ? settings.language = hin.text : ""
//                onCheckedChanged:hin.checked ? settings.checkedLanguage = hin.text : ""
            }
            RadioButton{
                id: eng
                text: "English"
                checked: settings.language === text ? true : false
//                checked: settings.checkedLanguage === text ? true : false
                onCheckedChanged:eng.checked ? settings.language = eng.text : ""
//                onCheckedChanged:eng.checked ? settings.checkedLanguage = eng.text : ""
            }
        }
    }

    //    MySettings{
    //        id: settings
    //        onCheckedLanguageChanged: {
    //            console.log("Language changed to ",checkedLanguage)
    //        }
    //    }

    //    Component.onCompleted: {
    //        settings.loadSet()
    //    }

    //    Component.onDestruction: {
    //        settings.checkedLanguage = kan.checked ? kan.text :
    //                                                 hin.checked ? hin.text :
    //                                                               eng.checked ? eng.text : "NULL"
    //        settings.saveSet()
    //    }

    Settings {
        id: settings
        property string language
    }
    Component.onDestruction: {
        settings.language = kan.checked ? kan.text :
                                          hin.checked ? hin.text :
                                                        eng.checked ? eng.text : ""
    }

}
