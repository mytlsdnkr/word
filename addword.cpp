#include "addword.h"
#include "ui_addword.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "addsuccess.h"


using namespace std;

void changeDirectory(QString path){
        QDir dir(path);
        if(!dir.exists())
            dir.mkdir(path);


    dir.setCurrent(path);
}
AddWord::AddWord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWord)
{
    ui->setupUi(this);

}

AddWord::~AddWord()
{
    delete ui;
}


QString createFile(){

     changeDirectory("data");
    struct tm *date;
    time_t t=time(NULL);
    date=localtime(&t);
    QString filename;
    QString month=QString::number(date->tm_mon+1);
    QString day=QString::number(date->tm_mday);

    if(date->tm_mon+1<10){
        month="0"+QString::number(date->tm_mon+1);
    }

    if(date->tm_mday+1<10){
        day="0"+QString::number(date->tm_mday);
    }

    filename=QString("%1-%2").arg(month,day);

    return filename;
}

void inputContents(QString filename, QString line){
    QFile file(filename);

    file.open(QFile::WriteOnly|QFile::Append|QFile::Text);
    QTextStream out(&file);
    out<<line;
    file.flush();
    file.close();


}
void AddWord::on_pushButton_2_clicked()
{
    QString word;
    word=ui->lineEdit->text();
    QString mean;
    mean=ui->lineEdit_2->text();
    QString line;
    line=QString("%1 %2\n").arg(word,mean);

    QString filename=createFile();

    inputContents(filename,line);

    AddSuccess addsuccess;
    addsuccess.setModal(true);
    addsuccess.exec();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();






   // qDebug()<<date->tm_mon+1<<date->tm_mday;




}
