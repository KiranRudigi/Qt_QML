#ifndef PAINT_AREA_H
#define PAINT_AREA_H

#include <QWidget>
#include "linkedl.h"
#include <QPainter>
#include <QRect>
#include <QDebug>

class Paint_Area : public QWidget
{
    Q_OBJECT
public:
    explicit Paint_Area(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void init(linkedL<int> *li);

    linkedL<int> *l;

signals:

public slots:
};

#endif // PAINT_AREA_H
