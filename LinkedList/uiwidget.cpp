#include "uiwidget.h"

UIWidget::UIWidget(QWidget *parent)
    : QWidget(parent)
{

    title = new QLabel;
    title->setFixedHeight(35);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font-size: 20pt; color: #f73859");
    title->setText("Linked List");

    ins = new QPushButton("Insert");
    ins->setStyleSheet("QPushButton{border-radius: 20px; background-color: #33cccc; color: white; font-size: 15pt}QPushButton:pressed {border-radius: 10px; background-color: #ffffff; color: black; font-size: 18pt}QPushButton:released { background-color: #33cccc; color: white; font-size: 20pt}");

    del = new QPushButton("Delete");
    del->setStyleSheet("QPushButton{border-radius: 20px; background-color: #33cccc; color: white; font-size: 15pt}QPushButton:pressed {border-radius: 10px; background-color: #ffffff; color: black; font-size: 18pt}QPushButton:released { background-color: #33cccc; color: white; font-size: 20pt}");

    dis = new QPushButton();
    dis->setFlat(1);



    ins->setFixedHeight(90);
    del->setFixedHeight(90);
    dis->setFixedSize(40,40);

    le = new QLineEdit;
    le->setAlignment(Qt::AlignCenter);
    le->setStyleSheet("background-color: #f7f7f7; font-size: 11pt; text-align: justify");
    le->setFixedSize(50,35);

    empty = new QPushButton;
    empty->setFlat(1);
    empty->setFixedSize(0,0);

    ledit = new QHBoxLayout;
    ledit->addWidget(le);

    com = new QComboBox;
    com->setFixedSize(50,35);
    com->setStyleSheet("background-color: #f7f7f7; font-size: 11pt; text-align: justify");
    com2 = new QComboBox;
    com2->setStyleSheet("background-color: #cffdf8");
    com2->setFixedHeight(30);
    com2->addItem("Singly Linked List");

    box = new QHBoxLayout;
    box->addWidget(empty);
    box->addWidget(com);
    box->setAlignment(Qt::AlignCenter);


    ed = new QVBoxLayout;

    lyt = new QHBoxLayout;

    p = new Paint_Area;

    but = new QVBoxLayout;
    but->addSpacing(100);
    but->addWidget(com2);
    but->addSpacing(20);
    but->addLayout(ledit);
    but->addSpacing(10);
    but->addWidget(ins);
    but->addSpacing(80);
    but->addLayout(box);
    but->addSpacing(10);
    but->addWidget(del);
    but->addWidget(dis);

    but->setAlignment(Qt::AlignHCenter);
    but->setAlignment(Qt::AlignTop);

    lyt->addLayout(but);
    lyt->addWidget(p,20);

    ed->addWidget(title);
    ed->addLayout(lyt);

    this->setStyleSheet("background-color: #283149");

    this->setLayout(ed);

    p->init(&llist);

    QObject::connect(ins,SIGNAL(clicked()),this,SLOT(insClicked()));
    QObject::connect(del,SIGNAL(clicked()),this,SLOT(delClicked()));
    QObject::connect(dis,SIGNAL(clicked()),this,SLOT(disClicked()));
}

UIWidget::~UIWidget()
{

}

void UIWidget::paintEvent(QPaintEvent *event)
{
        QPainter paint(this);
        paint.setPen(QColor(169,168,168));
        paint.drawLine(25,394,110,394);
        paint.drawLine(20,395,115,395);
        paint.drawLine(20,395,115,395);
        paint.setPen(QColor(169,168,168));
        paint.drawLine(25,396,110,396);
}

void UIWidget::insClicked()
{

    int it = le->text().toInt();

    if(it==0)
    {
        std::cout<<"Empty"<<std::endl;
    }
    else
    {
        llist.head = llist.insert(it);
        com->addItem(QString::number(it));
    }


    if(llist.count <= 99)
        p->update();

    le->clear();

}

void UIWidget::delClicked()
{
    int x = com->currentText().toInt();

    llist.head = llist.del(x);

    int y = com->currentIndex();

    com->removeItem(y);

    p->update();
}

void UIWidget::disClicked()
{
    llist.display();
}
