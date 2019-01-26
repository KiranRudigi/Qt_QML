#include "DataDisplayer.h"

DataDisplayer::DataDisplayer(QWidget *parent) : QWidget(parent),
    m_dataLabel(new QLabel("Value : ")),
    m_dataValue(new QLabel(NULL)),
    m_hLyt(new QHBoxLayout)
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    m_hLyt->addWidget(m_dataLabel);
    m_hLyt->addWidget(m_dataValue);
    this->setLayout(m_hLyt);
    qDebug() << Q_FUNC_INFO << " End" << endl;
}


void DataDisplayer::showData(QString data)
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    if(m_dataValue){
        m_dataValue->setText(data);
    }

    qDebug() << Q_FUNC_INFO << " End" << endl;
}

DataDisplayer::~DataDisplayer()
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    delete m_dataLabel;
    delete m_dataValue;
    delete m_hLyt;
    qDebug() << Q_FUNC_INFO << " End" << endl;
}
