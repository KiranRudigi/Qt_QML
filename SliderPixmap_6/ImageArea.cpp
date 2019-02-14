#include "ImageArea.h"

ImageArea::ImageArea(QWidget *parent) : QWidget(parent)
{
    qDebug() << Q_FUNC_INFO << " start" << endl;

//    QDir dir("./images");
    QDir dir(":/images");

    QStringList lst;
    lst << "*.JPG" << "*.jpg";
    dir.setNameFilters(lst);

    QStringList list = dir.entryList();
    qDebug() << " STRLIST: " << list.size();

    for(int i=0 ; i<list.count() ; i++){
        QPixmap* pixmap = new QPixmap(dir.absoluteFilePath(list.at(i)));
        m_pixmapList.append(pixmap);
        m_size++;
    }

    m_brush = Qt::blue;

    qDebug() << Q_FUNC_INFO << " end" << endl;
}

ImageArea::~ImageArea()
{
    qDebug() << Q_FUNC_INFO << " start" << endl;

    m_pixmapList.clear();

    QMapIterator<int,Markings*> mapItr(m_map);
    while (mapItr.hasNext()) {
        mapItr.next();
        delete mapItr.value();
    }
    m_map.clear();

    delete m_pixMap;


    qDebug() << Q_FUNC_INFO << " end" << endl;
}

void ImageArea::paintEvent(QPaintEvent *event)
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    Q_UNUSED(event)
    QPainter painter(this);

    if(m_pixMap!=NULL)
        painter.drawPixmap(0,0,this->width(),this->height(),*m_pixMap);

    QList<Markings*> list = m_map.values(m_sliderValue);

    if(x!=0 && y!=0){
        for(int i=0 ; i<list.count() ; i++){

            switch (list.at(i)->getShape()) {
            case CIRCLE:{
                drawCircle(painter,list.at(i));
                break;
            }

            case RECT:{
                drawRectangle(painter,list.at(i));
                break;
            }

            case POLYGON:{
                drawPolygon(painter,list.at(i));
                break;
            }

            case CHORD:{
                drawChord(painter,list.at(i));
                break;
            }

            case LINE:{
                drawLine(painter,list.at(i));
                break;
            }
            default:
                break;
            }
        }

    }

    qDebug() << Q_FUNC_INFO << " End" << endl;
}

void ImageArea::mousePressEvent(QMouseEvent *event)
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;


    m_count++;
    QMap<ID,QBrush> map;
    if(m_count<NUMBER_OF_CLICKS){
        x=event->x();
        y=event->y();
        Markings *marking = new Markings;
        marking->setX(x);
        marking->setY(y);
        marking->setCount(m_count);
        marking->setWidth(this->width()/20);
        marking->setHeight(this->width()/20);
        marking->setId(m_count);
        marking->setBrush(m_brush);

        map.insert(marking->getId(),marking->getBrush());

        marking->setBrushMap(map);

        m_map.insertMulti(m_sliderValue,marking);

        qDebug() << " Mouse Press Event X : " << marking->getX() << endl;
        qDebug() << " Mouse Press Event Y : " << marking->getY() << endl;
        this->update();
    }
    else{
        QRect rect;
        QList<Markings*> marking = m_map.values(m_sliderValue);

        for(Markings* mark : marking){
            qDebug() << "Markings : " << mark->getX() << endl;
            rect.setRect(mark->getX(),mark->getY(),mark->getWidth(),mark->getHeight());
            if(rect.contains(event->pos()) && mark->getShape()==Markings::CIRCLE){
                qDebug() << "Within Circle Clicked" << endl;
                m_brush = Qt::red;
                activeID = CIRCLE;
                map.insert(mark->getId(),m_brush);
                mark->setBrushMap(map);
                update();
                break;
            }
            else if(rect.contains(event->pos()) && mark->getShape()==Markings::RECT){
                qDebug() << "Within Rectangle Clicked" << endl;
                m_brush = Qt::red;
                map.insert(mark->getId(),m_brush);
                mark->setBrushMap(map);
                activeID = RECT;
                update();
                break;
            }
            else if(rect.contains(event->pos()) && mark->getShape()==Markings::CHORD){
                qDebug() << "Within Chord Clicked" << endl;
                m_brush = Qt::red;
                map.insert(mark->getId(),m_brush);
                mark->setBrushMap(map);
                activeID = CHORD;
                update();
                break;
            }
            else if(mark->getShape()==Markings::POLYGON){
                QVector<QPoint> points;
                points.append(QPoint(mark->getX(), mark->getY()));
                points.append(QPoint(mark->getX()+30, mark->getY()+10));
                points.append(QPoint(mark->getX()+30, mark->getY()+40));
                points.append(QPoint(mark->getX()-30, mark->getY()+40));
                points.append(QPoint(mark->getX()-30, mark->getY()+10));

                QPolygon poly(points);
                if(poly.containsPoint(event->pos(),Qt::WindingFill)){
                    qDebug() << "Within Polygon Clicked" << endl;
                    m_brush = Qt::red;
                    map.insert(mark->getId(),m_brush);
                    mark->setBrushMap(map);
                    activeID = POLYGON;
                    update();
                    break;
                }
            }
            else{
                activeID = LINE;
            }
        }
    }

    qDebug() << Q_FUNC_INFO << " End" << endl;
}

void ImageArea::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    QList<Markings*> mark = m_map.values(m_sliderValue);
    if(!mark.isEmpty()){
        switch (activeID) {
        case CIRCLE:{
            move(mark.at(CIRCLE_MOVE),event);
            break;
        }
        case RECT:{
            move(mark.at(RECT_MOVE),event);
            break;
        }
        case CHORD:{
            move(mark.at(CHORD_MOVE),event);
            break;
        }
        case POLYGON:{
            move(mark.at(POLYGON_MOVE),event);
            break;
        }

        default:{
            move(mark.at(LINE_MOVE),event);
            break;
        }

        }
    }

    qDebug() << Q_FUNC_INFO << " End" << endl;
}

void ImageArea::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;

    qDebug() << Q_FUNC_INFO << " End" << endl;
}

void ImageArea::setPixmap(int index)
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    m_pixMap = m_pixmapList.at(index);
    m_sliderValue = index;

    if(!m_map.isEmpty()){
        qDebug() << "Map is not Empty" << endl;
        if(!(m_map.value(m_sliderValue)==NULL)){
            qDebug() << "Map Value is not Empty" << endl;
            x = m_map.value(m_sliderValue)->getX();
            y = m_map.value(m_sliderValue)->getY();
            m_count = m_map.value(m_sliderValue)->getCount();
            m_brush = m_map.value(m_sliderValue)->getBrushMap().value(m_map.value(m_sliderValue)->getId());
        }
        else {
            qDebug() << "Map Value is Empty" << endl;
            x=0;
            y=0;
            m_count=0;
            m_brush = Qt::blue;
        }
    }
    else{
        qDebug() << "Map is empty" << endl;
    }

    this->update();
    qDebug() << Q_FUNC_INFO << " End" << endl;
}

int ImageArea::size() const
{
    return m_size;
}

void ImageArea::drawRectangle(QPainter &painter, Markings *marking)
{
    painter.setBrush(marking->getBrushMap().value(marking->getId()));
    painter.setPen(Qt::SolidLine);
    painter.drawRect(QRect(marking->getX(), marking->getY(),marking->getWidth(),marking->getHeight()));
}

void ImageArea::drawCircle(QPainter &painter,Markings* marking)
{
    painter.setBrush(marking->getBrushMap().value(marking->getId()));
    painter.setPen(Qt::SolidLine);
    painter.drawEllipse(QRect(marking->getX(), marking->getY(),marking->getWidth(),marking->getHeight()));
}

void ImageArea::drawPolygon(QPainter &painter, Markings *marking)
{
    QPoint points[5] = {
        QPoint(marking->getX(), marking->getY()),
        QPoint(marking->getX()+30, marking->getY()+10),
        QPoint(marking->getX()+30, marking->getY()+40),
        QPoint(marking->getX()-30, marking->getY()+40),
        QPoint(marking->getX()-30, marking->getY()+10)
    };
    painter.setBrush(marking->getBrushMap().value(marking->getId()));
    painter.setPen(Qt::SolidLine);
    painter.drawPolygon(points, 5);
}

void ImageArea::drawChord(QPainter &painter,Markings* marking)
{
    int startAngle = 30 * 16;
    int spanAngle = 120 * 16;
    painter.setBrush(marking->getBrushMap().value(marking->getId()));
    painter.setPen(Qt::SolidLine);
    painter.drawChord(QRect(marking->getX(), marking->getY(),marking->getWidth(),marking->getHeight()), startAngle, spanAngle);
}

void ImageArea::drawLine(QPainter &painter, Markings *marking)
{
    QLine line(marking->getX(), marking->getY(),
               marking->getX(), marking->getY()+50);

    painter.setBrush(marking->getBrushMap().value(marking->getId()));
    painter.setPen(Qt::SolidLine);
    painter.drawLine(line);
}

void ImageArea::move(Markings *mark, QMouseEvent *event)
{
    x=event->x();
    y=event->y();
    mark->setX(x);
    mark->setY(y);
    update();
}

