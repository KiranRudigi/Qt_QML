#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QSettings>
#include <QVBoxLayout>
#include <QDebug>

#define GROUP "settings_group"
#define KEY "key_for_value"
#define DEFAULT_VALUE "when_no_key_is_found_this_value_will_be_returned"

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();

public slots:
    void onSaveClicked();
    void onLoadClicked();
private:
    void saveSettings(const QString &key,const QVariant &value,const QString &group);
    QVariant loadSettings(const QString &key,const QString &group,const QVariant &value);

private:
    QPushButton *m_saveButton,*m_loadButton;
    QLineEdit *m_text;
    QVBoxLayout *m_vLyt;
};

#endif // MYWIDGET_H
