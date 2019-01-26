#ifndef TESTDEBUG_H
#define TESTDEBUG_H

#include <QObject>
#include <QDebug>

class TestDebug : public QObject
{
    Q_OBJECT
public:
    explicit TestDebug(QObject *parent = nullptr);

    void showData();
signals:

public slots:
};

#endif // TESTDEBUG_H
