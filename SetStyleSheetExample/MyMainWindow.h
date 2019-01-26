#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include <QRadioButton>
#include <QLineEdit>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QList>

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();

private:
    QWidget      *widget;
    QPushButton  *m_button1,*m_button2;
    QLabel       *m_label;
    QCheckBox    *m_checkBox1,*m_checkBox2,*m_checkBox3;
    QRadioButton *m_radioButton1,*m_radioButton2,*m_radioButton3;
    QLineEdit    *m_lineEdit;
    QComboBox    *m_comboBox;
    QHBoxLayout  *m_hlyt1,*m_hlyt2;
    QVBoxLayout  *m_vlyt1,*m_vlyt2,*m_vlyt3;
};

#endif // MYMAINWINDOW_H
