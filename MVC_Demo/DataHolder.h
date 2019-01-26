#ifndef DATAHOLDER_H
#define DATAHOLDER_H

#include <QObject>
#include <QDebug>

class DataHolder : public QObject
{
    Q_OBJECT
public:
    explicit DataHolder(QObject *parent = nullptr);
    ~DataHolder();
signals:
    void dataHold(QString);

public slots:
    void holdData(QString);

private:
    QString m_data = "";
};

#endif // DATAHOLDER_H
