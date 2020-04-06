#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addword.h"
#include "showword.h"
#include "wordtest.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
    AddWord addword;
    addword.setModal(true);
    addword.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    ShowWord showword;
    showword.setModal(true);
    showword.exec();

}

void MainWindow::on_pushButton_3_clicked()
{
    wordTest wordtest;
    wordtest.setModal(true);
    wordtest.exec();
}
