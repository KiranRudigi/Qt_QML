#ifndef DATADISPLAYER_H
#define DATADISPLAYER_H

#include <QObject>
#include <QLabel>
#include <QHBoxLayout>
#include <QDebug>

class DataDisplayer : public QWidget
{
    Q_OBJECT
public:
    explicit DataDisplayer(QWidget *parent = nullptr);
    ~DataDisplayer();
signals:

public slots:
    void showData(QString);

private:
    QLabel *m_dataLabel,*m_dataValue;
    QHBoxLayout *m_hLyt;
};

#endif // DATADISPLAYER_H
