#ifndef MYSETTINGS_H
#define MYSETTINGS_H

#include <QObject>
#include <QSettings>
#include <QDebug>
#define GROUP "settings_group"
#define KEY "key_for_value"
#define DEFAULT_VALUE "when_no_key_is_found_this_value_will_be_returned"

class MySettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString checkedLanguage MEMBER checkedLanguage NOTIFY checkedLanguageChanged)
public:
    explicit MySettings(QObject *parent = nullptr);

    Q_INVOKABLE void loadSet();
    Q_INVOKABLE void saveSet();
    QString getCheckedLanguage() const;
    void setCheckedLanguage(const QString &value);

signals:
    void checkedLanguageChanged();
public slots:
private:
    void saveSettings(const QString &key,const QVariant &value,const QString &group);
    void loadSettings(const QString &key,const QString &group,const QVariant &value);
private:
    QString checkedLanguage;
};

#endif // MYSETTINGS_H
