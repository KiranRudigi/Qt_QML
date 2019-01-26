#ifndef DATAREADER_H
#define DATAREADER_H

#include <QObject>
#include <QFile>
#include <QTimer>
#include <QDebug>

class DataReader : public QObject
{
    Q_OBJECT
public:
    explicit DataReader(QObject *parent = nullptr);
    ~DataReader();
signals:
    void dataRead(QString);

public slots:
    void changeFile(QString);
    void readData();
private:
    QFile *m_file;
    QTimer *m_timer;
};

#endif // DATAREADER_H
