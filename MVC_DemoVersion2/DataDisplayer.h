#ifndef DATADISPLAYER_H
#define DATADISPLAYER_H

#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>

class DataDisplayer : public QWidget
{
    Q_OBJECT
public:
    explicit DataDisplayer(QWidget *parent = nullptr);
    ~DataDisplayer();
signals:
    void fileSelected(QString);

public slots:
    void showData(QString);

private:
    QLabel *m_dataLabel;
    QLabel *m_dataValue;
    QPushButton *m_chooseButton;
    QFileDialog *m_fileDialog;
    QHBoxLayout *m_hLyt;
    QVBoxLayout *m_vLyt;
};

#endif // DATADISPLAYER_H
