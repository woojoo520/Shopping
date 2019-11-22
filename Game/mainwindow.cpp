#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "opendb.cpp"
#include "productshow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(!OpenDatabase())
        QMessageBox::warning(this, "Warning", "Sorry, Can't access SQL Server");
   // logon.show();
    //this->show();
    //mydialog.show();
    productshow.search();
    productshow.show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
