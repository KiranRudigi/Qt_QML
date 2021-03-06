#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLoggingCategory>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_debugButton_clicked();
    void on_infoButton_clicked();
    void on_warningButton_clicked();
    void on_criticalButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
