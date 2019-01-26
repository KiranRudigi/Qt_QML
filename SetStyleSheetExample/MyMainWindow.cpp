#include "MyMainWindow.h"

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//    QString style = "QPushButton {"
//"            border: 2px solid #8f8f91;"
//"            border-radius: 6px;"
//"            background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
//"                                              stop: 0 #f6f7fa, stop: 1 #dadbde);"
//"            min-width: 80px;"
//"        }"

//"        QPushButton:pressed {"
//"            background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
//"                                              stop: 0 #dadbde, stop: 1 #f6f7fa);"
//"        }"

//"        QPushButton:flat {"
//"            border: none; /* no border for a flat push button */"
//"        }"

//"        QPushButton:default {"
//"            border-color: navy; /* make the default button prominent */"
//"        }";

    m_button1 = new QPushButton("Button_1");
    m_button1->setObjectName("button1");
    m_button2 = new QPushButton("Button_2");
    m_button2->setObjectName("button2");

//    m_button1->setStyleSheet(style);

    m_label = new QLabel("Label");

    m_checkBox1 = new QCheckBox("1");
    m_checkBox2 = new QCheckBox("2");
    m_checkBox3 = new QCheckBox("3");

    m_radioButton1 = new QRadioButton("1");
    m_radioButton2 = new QRadioButton("2");
    m_radioButton3 = new QRadioButton("3");

    m_lineEdit = new QLineEdit;

    m_comboBox = new QComboBox;

    QList<QString> list;
    list << "Item1" << "Item2" << "Item3" << "Item4" << "Item5" ;

    m_comboBox->addItems(list);

    m_hlyt1 = new QHBoxLayout;
    m_hlyt1->addWidget(m_label);
    m_hlyt1->addWidget(m_button1);
    m_hlyt1->addWidget(m_button2);
    m_hlyt1->addWidget(m_lineEdit);
    m_hlyt1->addWidget(m_comboBox);

    m_vlyt1 = new QVBoxLayout;
    m_vlyt1->addWidget(m_checkBox1);
    m_vlyt1->addWidget(m_checkBox2);
    m_vlyt1->addWidget(m_checkBox3);

    m_vlyt2= new QVBoxLayout;
    m_vlyt2->addWidget(m_radioButton1);
    m_vlyt2->addWidget(m_radioButton2);
    m_vlyt2->addWidget(m_radioButton3);

    m_hlyt2 = new QHBoxLayout;
    m_hlyt2->addLayout(m_vlyt1);
    m_hlyt2->addLayout(m_vlyt2);

    m_vlyt3 = new QVBoxLayout;
    m_vlyt3->addLayout(m_hlyt1);
    m_vlyt3->addLayout(m_hlyt2);

    widget = new QWidget;
    widget->setLayout(m_vlyt3);
    this->setCentralWidget(widget);
}

MyMainWindow::~MyMainWindow()
{

}
