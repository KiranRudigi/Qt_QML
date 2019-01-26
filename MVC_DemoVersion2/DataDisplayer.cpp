#include "DataDisplayer.h"

DataDisplayer::DataDisplayer(QWidget *parent) : QWidget(parent),
    m_dataLabel(new QLabel("Value : ")),
    m_dataValue(new QLabel(NULL)),
    m_chooseButton(new QPushButton("Chose File")),
    m_fileDialog(new QFileDialog),
    m_hLyt(new QHBoxLayout),
    m_vLyt(new QVBoxLayout)
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;

    m_fileDialog->setNameFilter(tr("TextFiles (*.txt)"));


    m_hLyt->addWidget(m_dataLabel);
    m_hLyt->addWidget(m_dataValue);

    m_vLyt->addWidget(m_chooseButton);
    m_vLyt->addLayout(m_hLyt);
    this->setLayout(m_vLyt);

    connect(m_chooseButton,SIGNAL(clicked()),m_fileDialog,SLOT(open()));
    connect(m_fileDialog,SIGNAL(fileSelected(QString)),this,SIGNAL(fileSelected(QString)));
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
    delete m_chooseButton;
    delete m_fileDialog;
    delete m_vLyt;
//    delete m_hLyt;
    m_hLyt->deleteLater();
    qDebug() << Q_FUNC_INFO << " End" << endl;
}
