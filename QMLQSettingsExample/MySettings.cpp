#include "MySettings.h"

MySettings::MySettings(QObject *parent) : QObject(parent)
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    qDebug() << Q_FUNC_INFO << " End" << endl;
}

void MySettings::loadSet()
{
    this->loadSettings(KEY,GROUP,DEFAULT_VALUE);
}

void MySettings::saveSet()
{
    this->saveSettings(KEY,checkedLanguage,GROUP);
}

void MySettings::saveSettings(const QString &key, const QVariant &value, const QString &group)
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    QSettings settings;
    qDebug() << Q_FUNC_INFO << settings.fileName() << endl;
    settings.beginGroup(group);
    settings.setValue(key, value);
    settings.endGroup();
    qDebug() << Q_FUNC_INFO << " End" << endl;
}

void MySettings::loadSettings(const QString &key, const QString &group, const QVariant &value)
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    QSettings settings;
    qDebug() << Q_FUNC_INFO << settings.fileName() << endl;
    settings.beginGroup(group);
    checkedLanguage = settings.value(key, value).toString();
    checkedLanguageChanged();
    settings.endGroup();
    qDebug() << Q_FUNC_INFO << " End" << endl;
}

QString MySettings::getCheckedLanguage() const
{
    return checkedLanguage;
}

void MySettings::setCheckedLanguage(const QString &value)
{
    checkedLanguage = value;
}
