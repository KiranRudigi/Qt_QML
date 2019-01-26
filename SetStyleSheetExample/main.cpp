#include "MyMainWindow.h"
#include <QApplication>
#include <QFile>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyMainWindow w;
    QString filePath = ":/StyleSheet.qss";
    QFile f(filePath);
    f.open(QIODevice::ReadOnly);
    QString data = f.readAll();

    a.setStyleSheet(data);

    w.show();

    return a.exec();
}
