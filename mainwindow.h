#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void set_c();

private:
    Ui::MainWindow *ui;
};

// class MainWindow : public QWidget
// {
//     Q_OBJECT

// public:
//     explicit MainWindow(QWidget *parent = nullptr);

// private slots:
//     void openNewPage();

// private:
//     QStackedWidget *stackedWidget;
// };

#endif
