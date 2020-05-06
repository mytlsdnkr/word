#include "showword.h"
#include "ui_showword.h"
#include "showtable.h"
#include <QDebug>
#include <QDir>
#include <QFile>



ShowWord::ShowWord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowWord)
{


    int i=0;
    QDir dir;
    dir.setCurrent("data");
    QStringList fileList=dir.entryList();
    int len=fileList.length();

    ui->setupUi(this);
    for(i=2;i<len;i++){
        int nameLen=fileList[i].length();
        ui->listWidget->addItem(fileList[i]);
    }



}


ShowWord::~ShowWord()
{
    delete ui;
}






void ShowWord::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ShowTable *showtable = new ShowTable;
    connect(this,SIGNAL(sendData(QString)),showtable,SLOT(getData(QString)));
    emit sendData(item->text());

    showtable->setModal(true);
    showtable->exec();


    //ShowTable *showtable = new ShowTable;

    //showtable->setFilename(item->text());
    //showtable->setModal(true);
    //showtable->exec();

}

void ShowWord::on_pushButton_clicked()
{
    this->close();

}

void ShowWord::on_pushButton_2_clicked()
{
    QFile file;
    file.remove(this->filename);
    this->close();

}

void ShowWord::on_listWidget_itemClicked(QListWidgetItem *item)
{
    this->filename=item->text();

}
