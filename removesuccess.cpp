#include "removesuccess.h"
#include "ui_removesuccess.h"
#include "showtable.h"

removesuccess::removesuccess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removesuccess)
{
    ui->setupUi(this);
}

removesuccess::~removesuccess()
{
    delete ui;
}

void removesuccess::on_pushButton_clicked()
{
    this->close();

}
