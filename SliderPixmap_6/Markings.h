#ifndef MARKINGS_H
#define MARKINGS_H

#include <QObject>
#include <QDebug>
#include <QBrush>

#define ID int

class Markings : public QObject
{
    Q_OBJECT
public:
    enum DRAW{
        INVALID = -1,
        CIRCLE=1,
        RECT,
        POLYGON,
        CHORD,
        LINE
    };

    explicit Markings(QObject *parent = nullptr);
    ~Markings();

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    int getWidth() const;
    void setWidth(int value);

    int getHeight() const;
    void setHeight(int value);

    int getCount() const;
    void setCount(int value);

    DRAW getShape();

    QBrush getBrush() const;
    void setBrush(const QBrush &value);

    int getId() const;
    void setId(int value);

    QMap<int, QBrush> getBrushMap() const;
    void setBrushMap(const QMap<int, QBrush> &value);


signals:

public slots:

private:
    int x;
    int y;
    int count;
    int width;
    int height;
    int id;
    QBrush brush;
    QMap<ID,QBrush> brushMap;
};

#endif // MARKINGS_H
