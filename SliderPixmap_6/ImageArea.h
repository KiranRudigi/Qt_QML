#ifndef IMAGEAREA_H
#define IMAGEAREA_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QDir>
#include <QList>
#include <QDebug>
#include <QMouseEvent>
#include <QRect>
#include <QMap>
#include <QBrush>
#include <QPolygon>
#include "Markings.h"

#define ID int


class ImageArea : public QWidget
{
    Q_OBJECT

    enum{CIRCLE=1,RECT,POLYGON,CHORD,LINE,NUMBER_OF_CLICKS};
    enum{LINE_MOVE,CHORD_MOVE,POLYGON_MOVE,RECT_MOVE,CIRCLE_MOVE};
public:
    explicit ImageArea(QWidget *parent = nullptr);
    ~ImageArea();

    int size() const;

    void drawRectangle(QPainter &painter,Markings* marking);
    void drawCircle(QPainter &painter, Markings *marking);
    void drawPolygon(QPainter &painter, Markings* marking);
    void drawChord(QPainter &painter, Markings *marking);
    void drawLine(QPainter &painter, Markings* marking);

    void move(Markings* mark,QMouseEvent* event);

signals:

protected:
     void mousePressEvent(QMouseEvent* event) override;
     void mouseMoveEvent(QMouseEvent* event) override;
     void mouseReleaseEvent(QMouseEvent* event) override;
     void paintEvent(QPaintEvent* event) override;

public slots:
    void setPixmap(int index);

private:
    QStringList m_listOfFiles;
    QList<QPixmap*> m_pixmapList;
    QPixmap *m_pixMap;
    int x = 0,y = 0;
    int m_size,m_sliderValue=0;

    QMap<int,Markings*> m_map;
    int m_count = 0;
    QBrush m_brush;
    int activeID=0;
//    QRect m_rect;
};

#endif // IMAGEAREA_H
