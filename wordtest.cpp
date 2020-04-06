#include "wordtest.h"
#include "ui_wordtest.h"
#include "showresult.h"
#include <QDebug>
#include <stdlib.h>
#include <time.h>



void wordTest::getData(){
    int len=filelist.length();
    int i=0,k=0;
    for(i=0;i<len;i++){
        QFile inputFile(filelist[i]);
        if(inputFile.open(QIODevice::ReadOnly)){
            QTextStream in(&inputFile);
            while(!in.atEnd()){
                QString line=in.readLine();
                QStringList list=line.split(" ");
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

void wordTest::getRand(){
    while(1){
    srand(time(0));
    current=rand()%numOfWord;
    if(a[current].check==0)
        order.push_back(current);
        return;
    }
}

void wordTest::setTest(){
    if(numOftest==numOfWord){
        //show result!
    }
    getRand();
    ui->label->setText(a[current].word);
    numOftest++;

}
void wordTest::removeTrash(){
    qdir.setCurrent("data");
    filelist=qdir.entryList();
    filelist.removeFirst();
    filelist.removeFirst();
}
wordTest::wordTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wordTest)
{
    removeTrash();
    getData();
    numOftest=0;
    ui->setupUi(this);
    setTest();
    //qDebug()<<numOfWord;



}

wordTest::~wordTest()
{
    delete ui;
}

void wordTest::checkAnswer(){
    QString ans=ui->lineEdit->text();
    QString answer=a[current].mean;
    a[current].input=ans;
    if(answer.contains(ans)){
        a[current].answer=1;
    }


}

void wordTest::on_pushButton_clicked()
{

    checkAnswer();
    setTest();
}

void wordTest::on_pushButton_2_clicked()
{
    showResult *showresult = new showResult;
    connect(this,SIGNAL(sendData(test)),showresult,SLOT(getData(test)));
    emit sendData(a,order);
    showresult->setModal(true);
    showresult->exec();

}
