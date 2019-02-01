#include "MyWidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    m_saveButton = new QPushButton("Save");
    m_loadButton = new QPushButton("Load");
    m_text = new QLineEdit;
    m_vLyt = new QVBoxLayout;

    m_vLyt->addWidget(m_text);
    m_vLyt->addWidget(m_saveButton);
    m_vLyt->addWidget(m_loadButton);

    this->setLayout(m_vLyt);
    connect(m_saveButton,&QPushButton::clicked,this,&MyWidget::onSaveClicked,Qt::UniqueConnection);
    connect(m_loadButton,&QPushButton::clicked,this,&MyWidget::onLoadClicked,Qt::UniqueConnection);
    qDebug() << Q_FUNC_INFO << " End" << endl;
}

MyWidget::~MyWidget()
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    delete m_text;
    delete m_loadButton;
    delete m_saveButton;
    delete m_vLyt;
    qDebug() << Q_FUNC_INFO << " End" << endl;
}

void MyWidget::onSaveClicked()
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    QString val = m_text->text();
    saveSettings(KEY,val,GROUP);
    qDebug() << Q_FUNC_INFO << " End" << endl;
}

void MyWidget::onLoadClicked()
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    QString val = loadSettings(KEY,GROUP,DEFAULT_VALUE).toString();
    m_text->setText(val);
    qDebug() << Q_FUNC_INFO << " End" << endl;
}

void MyWidget::saveSettings(const QString &key, const QVariant &value, const QString &group)
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    QSettings settings;
    settings.beginGroup(group);
    settings.setValue(key, value);
    settings.endGroup();
    qDebug() << Q_FUNC_INFO << " End" << endl;
}

QVariant MyWidget::loadSettings(const QString &key, const QString &group, const QVariant &value = QVariant())
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    QSettings settings;
    settings.beginGroup(group);
    QVariant val = settings.value(key, value);
    settings.endGroup();
    qDebug() << Q_FUNC_INFO << " End" << endl;
    return val;
}
