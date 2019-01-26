#include "DataHolder.h"

DataHolder::DataHolder(QObject *parent) : QObject(parent)
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;

    qDebug() << Q_FUNC_INFO << " End" << endl;
}

void DataHolder::holdData(QString data)
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    m_data = data;
    emit dataHold(m_data);
    qDebug() << Q_FUNC_INFO << " End" << endl;
}

DataHolder::~DataHolder()
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;

    qDebug() << Q_FUNC_INFO << " End" << endl;
}
