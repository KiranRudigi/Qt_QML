#include "Markings.h"

Markings::Markings(QObject *parent) : QObject(parent)
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    qDebug() << Q_FUNC_INFO << " End" << endl;
}

Markings::~Markings()
{

}

int Markings::getX() const
{
    return x;
}

void Markings::setX(int value)
{
    x = value;
}

int Markings::getY() const
{
    return y;
}

void Markings::setY(int value)
{
    y = value;
}

int Markings::getWidth() const
{
    return width;
}

void Markings::setWidth(int value)
{
    width = value;
}

int Markings::getHeight() const
{
    return height;
}

void Markings::setHeight(int value)
{
    height = value;
}

int Markings::getCount() const
{
    return count;
}

void Markings::setCount(int value)
{
    count = value;
}

Markings::DRAW Markings::getShape()
{
    switch (id) {
    case CIRCLE:
        return CIRCLE;
        break;
    case RECT:
        return RECT;
        break;
    case POLYGON:
        return POLYGON;
        break;
    case CHORD:
        return CHORD;
        break;
    case LINE:
        return LINE;
        break;
    default:
        return INVALID;
    }
}

QBrush Markings::getBrush() const
{
    return brush;
}

void Markings::setBrush(const QBrush &value)
{
    brush = value;
}


int Markings::getId() const
{
    return id;
}

void Markings::setId(int value)
{
    id = value;
}

QMap<int, QBrush> Markings::getBrushMap() const
{
    return brushMap;
}

void Markings::setBrushMap(const QMap<int, QBrush> &value)
{
    brushMap = value;
}

