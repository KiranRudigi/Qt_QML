#ifndef UIWIDGET_H
#define UIWIDGET_H

#include "linkedl.h"
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QPainter>
#include "Paint_Area.h"

class UIWidget : public QWidget
{
    Q_OBJECT
public:
    UIWidget(QWidget *parent = 0);
    ~UIWidget();

    void paintEvent(QPaintEvent *event);

    linkedL<int> llist;

    QLabel *title;

    QPushButton *ins;
    QPushButton *del;
    QPushButton *dis;
    QPushButton *empty;

    QLineEdit *le;
    QComboBox *com;
    QComboBox *com2;

    QVBoxLayout *but;
    QVBoxLayout *ed;
    QHBoxLayout *lyt;
    QHBoxLayout *ledit;
    QHBoxLayout *box;

    Paint_Area *p;

public slots:
    void insClicked();
    void delClicked();
    void disClicked();
};

#endif // UIWIDGET_H
