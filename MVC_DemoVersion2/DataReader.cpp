#include "DataReader.h"

DataReader::DataReader(QObject *parent) : QObject(parent),
    m_file(new QFile("./Data.txt")),
    m_timer(new QTimer)
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    m_timer->setInterval(3000);

    connect(m_timer,SIGNAL(timeout()),this,SLOT(readData()));

    m_timer->start();
    qDebug() << Q_FUNC_INFO << " End" << endl;
}

void DataReader::readData()
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;

    if(m_file->open(QIODevice::ReadOnly)){
        QString data = "";
        data = m_file->readAll();
        emit dataRead(data);
        m_file->close();
    }
    else{
        qWarning() << Q_FUNC_INFO << " " << m_file->errorString() << endl;
    }

    qDebug() << Q_FUNC_INFO << " End" << endl;
}

DataReader::~DataReader()
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    delete m_file;
    delete m_timer;
    qDebug() << Q_FUNC_INFO << " End" << endl;

}

void DataReader::changeFile(QString file)
{
    if(m_file){
        m_file->close();
        m_file->setFileName(file);
    }
}
