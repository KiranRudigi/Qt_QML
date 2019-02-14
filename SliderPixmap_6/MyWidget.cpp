#include "MyWidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    m_imgArea = new ImageArea;
    m_slider = new QSlider(Qt::Horizontal);
    m_imgArea->setPixmap(0);
    m_vLyt = new QVBoxLayout;

    m_slider->setMaximum(m_imgArea->size()-1);

    m_vLyt->addWidget(m_imgArea);
    m_vLyt->addWidget(m_slider);


    this->setLayout(m_vLyt);

    this->showMaximized();


    connect(m_slider,SIGNAL(valueChanged(int)),m_imgArea,SLOT(setPixmap(int)),Qt::UniqueConnection);
    qDebug() << Q_FUNC_INFO << " End" << endl;
}

MyWidget::~MyWidget()
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;

    delete m_imgArea;
    delete m_slider;
    delete m_vLyt;

    qDebug() << Q_FUNC_INFO << " End" << endl;
}

