#include "showresult.h"
#include "ui_showresult.h"
#include <QTableWidget>
#include <QListWidgetItem>
#include <QDebug>


showResult::showResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showResult)
{
   // ui->setupUi(this);
}

showResult::~showResult()
{
    delete ui;
}
void showResult::fillTable(test *a,vector<int> &order){
    int i=0;

    for(i=0;i<order.size();i++){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(a[i].word));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(a[i].mean));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(a[i].input));
                  ui->tableWidget->setItem(i,3,new QTableWidgetItem(a[i].answer));
        //ui->tableWidget->setItem(row,0,checkBoxItem);

    }




}

void showResult::getData(test *a,vector<int> &order){
   // qDebug()<<a[0].mean;
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(order.size());

            QStringList label;

           // label.append("no");
            label.append("word");
            label.append("mean");
            label.append("answer");
            label.append("result");


            ui->tableWidget->setHorizontalHeaderLabels(label);
            ui->tableWidget->setColumnWidth(0,200);
            ui->tableWidget->setColumnWidth(1,200);
            ui->tableWidget->setColumnWidth(2,400);
            ui->tableWidget->setColumnWidth(3,400);
         //   ui->tableWidget->setColumnWidth(4,1);
            fillTable(a,order);






}
