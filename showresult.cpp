#include "showresult.h"
#include "ui_showresult.h"
#include <QTableWidget>
#include <QListWidgetItem>
#include <QDebug>
#include <QColor>


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
    int count=0;
    float score=0.0;


    for(i=0;i<order.size();i++){
    QColor color;
    color.setRed(255);
    color.setGreen(255);
    color.setBlue(255);

      if(QString::compare(a[i].mean,a[i].input)){
          color.setRed(255);
          color.setGreen(0);
          color.setBlue(0);
        }else{
          count++;
      }


        ui->tableWidget->setItem(i,0,new QTableWidgetItem(a[i].word));
        ui->tableWidget->item(i,0)->setBackgroundColor(color);

        ui->tableWidget->setItem(i,1,new QTableWidgetItem(a[i].mean));
             ui->tableWidget->item(i,1)->setBackgroundColor(color);

        ui->tableWidget->setItem(i,2,new QTableWidgetItem(a[i].input));
                  ui->tableWidget->item(i,2)->setBackgroundColor(color);

    }

    score=((float)count/(float)order.size())*100;

    ui->label->setNum(score);







}

void showResult::getData(test *a,vector<int> &order){
   // qDebug()<<a[0].mean;
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(order.size());

            QStringList label;

           // label.append("no");
            label.append("word");
            label.append("mean");
            label.append("input");


            ui->tableWidget->setHorizontalHeaderLabels(label);
            ui->tableWidget->setColumnWidth(0,200);
            ui->tableWidget->setColumnWidth(1,200);
            ui->tableWidget->setColumnWidth(2,400);

            fillTable(a,order);






}

void showResult::on_pushButton_clicked()
{
    this->close();
}
