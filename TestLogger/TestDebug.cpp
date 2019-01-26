#include "TestDebug.h"

TestDebug::TestDebug(QObject *parent) : QObject(parent)
{

}

void TestDebug :: showData() {
    qDebug() << Q_FUNC_INFO << "Debug called in showData" << endl;
    qWarning() << Q_FUNC_INFO << "Warning called in showData" << endl;
    qCritical() << Q_FUNC_INFO << "Critical called in showData" << endl;
    qInfo()<< Q_FUNC_INFO << "Info called in showData" << endl;
//    qFatal("divide: cannot divide by zero");
}
