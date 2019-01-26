#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();

private:
    QPushButton *m_Button1,*m_Button2,*m_Button3,*m_Button4;
    QGridLayout *m_grid;
};

#endif // MYWIDGET_H
