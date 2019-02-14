#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>
#include <QList>
#include "ImageArea.h"

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();

public slots:

private:
    QSlider *m_slider;
    QVBoxLayout *m_vLyt;
    ImageArea *m_imgArea;
};

#endif // MYWIDGET_H
