#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "MySettings.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<MySettings>("Settings",1,0,"MySettings");
    app.setApplicationName("Settings Example");
    app.setOrganizationName("Kiran");
    app.setOrganizationDomain("http://kiran.com");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
