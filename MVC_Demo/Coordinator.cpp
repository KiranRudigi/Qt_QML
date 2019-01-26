#include "Coordinator.h"

Coordinator::Coordinator(QWidget *parent)
    : QWidget(parent),
      m_dataReader(new DataReader),
      m_dataHolder(new DataHolder),
      m_dataDisplayer(new DataDisplayer)
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;

    m_dataDisplayer->show();
    connect(m_dataReader,SIGNAL(dataRead(QString)),m_dataHolder,SLOT(holdData(QString)),Qt::UniqueConnection);
    connect(m_dataHolder,SIGNAL(dataHold(QString)),m_dataDisplayer,SLOT(showData(QString)),Qt::UniqueConnection);
    qDebug() << Q_FUNC_INFO << " End" << endl;
}

Coordinator::~Coordinator()
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;

    delete m_dataDisplayer;
    delete m_dataHolder;
    delete m_dataReader;

    qDebug() << Q_FUNC_INFO << " End" << endl;
}
