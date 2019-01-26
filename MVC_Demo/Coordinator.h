#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

#include "DataReader.h"
#include "DataHolder.h"
#include "DataDisplayer.h"

class Coordinator : public QWidget
{
    Q_OBJECT

public:
    Coordinator(QWidget *parent = 0);
    ~Coordinator();

private:
    DataReader *m_dataReader;
    DataHolder *m_dataHolder;
    DataDisplayer *m_dataDisplayer;
};

#endif // MAINWIDGET_H
