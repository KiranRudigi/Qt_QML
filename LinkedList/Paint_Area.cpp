#include "Paint_Area.h"

Paint_Area::Paint_Area(QWidget *parent) : QWidget(parent)
{

}

void Paint_Area::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    paint.setBrush(QColor(110,130,138));
    paint.setPen(Qt::LinearGradientPattern);
    QRect r = this->rect();
    paint.drawRect(r);
    paint.setPen(Qt::white);
    paint.setPen(Qt::black);
    int x = 110;
    int y = 210;
    int z = 0;
    int j = 0;
    if(l->count >= 1)
    {
        for(int i=0;i<l->count;i++)
        {
            if(i%9 == 0 && i>0)
            {
                if(j == 0)
                {
                    x -= 140;
                    y -=140;
                }
                j++;
                z += 70;
            }
            //arrow for next line // right side
            if(i%9 == 0 && i>0 && j%2!=0)
            {
                z-=70;
                paint.setPen(Qt::black);
                paint.drawLine(y,38+z,y+39,38+z);
                paint.drawLine(y+39,38+z,y+39,108+z);
                paint.drawLine(y+39,108+z,y,108+z);
                z+=70;
            }
            //arrow for next line // left side
            if(i%9 == 0 && i>0 && j%2==0)
            {
                y-=140;
                z-=70;
                paint.setPen(Qt::black);
                paint.drawLine(y,38+z,y+39,38+z);
                paint.drawLine(y,38+z,y,108+z);
                paint.drawLine(y+39,108+z,y,108+z);
                paint.drawLine(y+30,99+z,y+39,108+z);
                paint.drawLine(y+30,117+z,y+39,108+z);
                z+=70;
                y+=140;
            }
            //arrow right side
            if(i != l->count-1 && j%2==0 && l->count<100)
            {
                if(i>7)
                {
                    paint.setPen(Qt::black);
                    y-=280;
                    paint.drawRect(y,38+z,39,0);
                    paint.drawLine(y+30,29+z,y+39,38+z);
                    paint.drawLine(y+30,47+z,y+39,38+z);
                    y+=280;
                }
                paint.setPen(Qt::LinearGradientPattern);
                paint.drawRect(y,38+z,39,0);
                paint.drawLine(y+30,29+z,y+39,38+z);
                paint.drawLine(y+30,47+z,y+39,38+z);
            }
            //arrow left side
            if(i != l->count && j%2!=0)
            {
                paint.setPen(Qt::LinearGradientPattern);
                paint.drawRect(y,38+z,39,0);
                paint.drawLine(y+9,29+z,y,38+z);
                paint.drawLine(y+9,47+z,y,38+z);
            }
            QRect r3(x,15+z,50,45);
            paint.setBrush(QColor(55,73,85));
            paint.setPen(Qt::LinearGradientPattern);
            paint.drawRect(r3);
            QRect r4(50+x,15+z,50,45);
            paint.setBrush(QColor(246,42,102));
            paint.setPen(Qt::LinearGradientPattern);
            paint.drawRect(r4);
            paint.setPen(Qt::white);
            void *p = (l->getAdOf(i));
            void *q = (l->getAdOf(i+1));
            void **p2 = &p;
            void **q2 = &q;
            //address of next node
            QString s = QString::number((int)*q2,16);
            if(s.length()>4 && s.length()<8)
                paint.drawText(54+x,40+z, s);
            else
            {
                if(s == "0")
                    s = "     NULL";
                //            QString x = QString::pointer(p);
                //            qDebug() << "D1" << *(int *)p2 ;
                paint.drawText(50+x,40+z, s);
            }
            //address of current node
            paint.setPen(Qt::black);
            if(sizeof(p2) > 4 && sizeof(p2) < 8)
                paint.drawText(28+x,70+z, QString::number((int)*p2,16));
            else
            paint.drawText(22+x,70+z, QString::number((int)*p2,16));
            paint.setPen(Qt::white);
            paint.drawText(20+x,40+z,QString::number(l->getValueAt(i)));
            if(i == 17 || i == 35 || i == 53 || i == 71 || i == 89)
            {
                y+=140;
                x+= 140;
            }
            if(i == 26 || i == 44 || i == 62 || i == 80 || i == 108)
            {
                y-=140;
                x-= 140;
            }
            if(j%2 != 0)
            {
                x -= 140;
                y -= 140;
            }
            else
            {
                x += 140;
                y += 140;
            }
            //            std::cout << "count " << l->count << "i " << i << endl;
        }
    }
}

void Paint_Area::init(linkedL<int> *li)
{
    l = li;
}
