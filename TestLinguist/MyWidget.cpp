#include "MyWidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    m_Button1 = new QPushButton(tr("Button_1"));
    m_Button2 = new QPushButton(tr("Button_2"));
    m_Button3 = new QPushButton(tr("Button_3"));
    m_Button4 = new QPushButton(tr("Button_4"));

    m_grid = new QGridLayout;

    m_grid->addWidget(m_Button1,0,0,1,1);
    m_grid->addWidget(m_Button2,0,1,1,1);
    m_grid->addWidget(m_Button3,1,0,1,1);
    m_grid->addWidget(m_Button4,1,1,1,1);

    this->setLayout(m_grid);
}

MyWidget::~MyWidget()
{

}
