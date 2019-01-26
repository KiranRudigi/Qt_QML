#ifndef PAINT_H
#define PAINT_H

#include <QWidget>

class paint : public QWidget
{
    Q_OBJECT
public:
    paint();
    void paintEvent(QPaintEvent *event);
    void init(linkedL<int> *li);

    linkedL<int> *l;

signals:

public slots:
};

#endif // PAINT_H
