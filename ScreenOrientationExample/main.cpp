#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtGui/QScreen>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

//    const auto screens = QGuiApplication::screens();
//    for (QScreen *screen : screens)
//        screen->setOrientationUpdateMask(Qt::LandscapeOrientation | Qt::PortraitOrientation |
//                                         Qt::InvertedLandscapeOrientation | Qt::InvertedPortraitOrientation);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
