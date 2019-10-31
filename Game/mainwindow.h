#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logon.h"
#include "mydialog.h"
#include "productshow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    LogOn logon;
    MyDialog mydialog;
    productShow productshow;
};

#endif // MAINWINDOW_H
