#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mTestDebugObject = new TestDebug;
    mTestDebugObject->showData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Debugging called" << endl;
}

void MainWindow::on_pushButton_2_clicked()
{
    qInfo() << "info called" << endl;
}

void MainWindow::on_pushButton_3_clicked()
{
    qWarning() << "Warning called" << endl;
}

void MainWindow::on_pushButton_4_clicked()
{
    qCritical() << "Critical called" << endl;
}
