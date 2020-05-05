#include "meantest.h"
#include "ui_meantest.h"
#include <QDebug>
#include "showmeanresult.h"
#include <stdlib.h>
#include <time.h>

void meantest::getData(){
    int len=filelist.length();
    int i=0,k=0;
    for(i=0;i<len;i++){
        QFile inputFile(filelist[i]);
        if(inputFile.open(QIODevice::ReadOnly)){
            QTextStream in(&inputFile);
            while(!in.atEnd()){
                QString line=in.readLine();
                QStringList list=line.split("=");
                a[k].word=list[0];
                a[k].mean=list[1];
                a[k].check=0;
                a[k].answer=0;
                k++;
            }
    }
        inputFile.flush();
        inputFile.close();

}
     numOfWord=k;

}

void meantest::getRand(){
    while(1){
    srand(time(0));
    current=rand()%numOfWord;
    if(a[current].check==0){
        a[current].check=1;
        order.push_back(current);
        return;
    }
}
}

void meantest::setTest(){
    if(numOftest==numOfWord){
        showmeanresult *showresult = new showmeanresult;
        connect(this,&meantest::sendData,showresult,&showmeanresult::getData);
        emit sendData(a,order);
        showresult->setModal(true);
        showresult->exec();
        this->close();
        return;
    }
    getRand();
    ui->label->setText(a[current].mean);
    ui->lineEdit->clear();
    numOftest++;

}
void meantest::removeTrash(){
    qdir.setCurrent("data");
    filelist=qdir.entryList();
    filelist.removeFirst();
    filelist.removeFirst();
}
void meantest::checkAnswer(){
    QString ans=ui->lineEdit->text();
    QString answer=a[current].word;
    a[current].input=ans;
    if(answer.contains(ans)){
        a[current].answer=1;
    }


}

void meantest::on_pushButton_clicked()
{

    checkAnswer();
    setTest();
}

void meantest::on_pushButton_2_clicked()
{
    showmeanresult *showresult = new showmeanresult;
    connect(this,&meantest::sendData,showresult,&showmeanresult::getData);
    emit sendData(a,order);
    showresult->setModal(true);
    showresult->exec();

}

void meantest::on_pushButton_3_clicked()
{
    this->close();
}

meantest::meantest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::meantest)
{
    removeTrash();
    getData();
    numOftest=0;
    ui->setupUi(this);
    setTest();
    //qDebug()<<numOfWord;
}

meantest::~meantest()
{
    delete ui;
}
