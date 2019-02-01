#include "MyWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    a.setApplicationName("Settings Example");
    a.setOrganizationName("Kiran");
    a.setOrganizationDomain("http://kiran.com");
    w.show();

    return a.exec();
}
