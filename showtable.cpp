#include "showtable.h"
#include "ui_showtable.h"
#include "removesuccess.h"
#include <QDir>
#include <QDebug>
#include <QFile>
#include <QTextCodec>
#include <algorithm>

void ShowTable::addList(QStringList list, int row){

    QTableWidgetItem *checkBoxItem=new QTableWidgetItem();
    checkBoxItem->setCheckState(Qt::Unchecked);
    checkBoxItem->setTextAlignment(Qt::AlignCenter);


   ui->tableWidget->setItem(row,1,new QTableWidgetItem(list[0]));
   ui->tableWidget->setItem(row,2,new QTableWidgetItem(list[1]));
   ui->tableWidget->setItem(row,0,checkBoxItem);

}


void ShowTable::onFileRead(QString file,int remove){



    int i=0;
    QFile inputFile(file);
    if(remove==0){
    if(inputFile.open(QIODevice::ReadOnly)){
        QTextStream in(&inputFile);
        while(!in.atEnd()){
            QString line=in.readLine();
            QStringList list=line.split(" ");
            this->addList(list,i);
          i++;
        }
    }
    inputFile.flush();
    inputFile.close();
    }else{
        QFile outputFile(file+"_bak");
        outputFile.open(QFile::WriteOnly|QFile::Append|QFile::Text);
        QTextStream out(&outputFile);
        if(inputFile.open(QIODevice::ReadOnly)){
            QTextStream in(&inputFile);
            while(!in.atEnd()){
                QString line=in.readLine();
                if(this->removeNum[0]==i+1){
                    this->removeNum.removeFirst();
                    if(this->removeNum.empty())
                        break;
                    qDebug()<<this->removeNum;
                   qDebug()<<"delete:"+line;

                   i++;
                    continue;
                }
                out<<line+'\n';
                qDebug()<<"non delete:"+line;
                i++;
           }

        }
        inputFile.flush();
        inputFile.close();
        outputFile.flush();
        outputFile.close();
        inputFile.remove();
        qDebug()<<outputFile.rename(filename);
    }



}



void ShowTable::getData(QString filename){

    ui->setupUi(this);

        this->filename=filename;



    QDir dir;
    dir.setCurrent("data");


    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(50);

    QStringList label;

    label.append("no");
    label.append("word");
    label.append("mean");


    ui->tableWidget->setHorizontalHeaderLabels(label);
    ui->tableWidget->setColumnWidth(0,1);
    ui->tableWidget->setColumnWidth(1,200);
    ui->tableWidget->setColumnWidth(2,400);




    onFileRead(filename,0);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


}



ShowTable::ShowTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowTable)
{
    //ui->setupUi(this);

}


ShowTable::~ShowTable()
{
    delete ui;
}

void ShowTable::on_pushButton_clicked()
{
    this->close();

}

void ShowTable::setRemoveWord(QString data){
    this->removeWord=data;
}

void ShowTable::addData(int num){
    this->removeNum.append(num);

}
void ShowTable::deleteData(int num){
     this->removeNum.removeOne(num);
}
void ShowTable::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
        //qDebug()<<"Hi!!!";
    if(item->checkState()==Qt::Checked){
        this->addData(item->row()+1);
    }else{
        this->deleteData(item->row()+1);
    }


}

void ShowTable::on_pushButton_2_clicked(){


    std::sort(this->removeNum.begin(),this->removeNum.end());
       qDebug()<<this->removeNum;
    this->onFileRead(filename,1);
    this->close();





}
