#include "MyWidget.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator trans;
    trans.load("G:/PthinkS/June/TestLinguist/Kannada.qm");
    a.installTranslator(&trans);
    MyWidget w;
    w.show();

    return a.exec();
}
