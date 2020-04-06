#include "addsuccess.h"
#include "ui_addsuccess.h"

AddSuccess::AddSuccess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSuccess)
{
    ui->setupUi(this);
}

AddSuccess::~AddSuccess()
{
    delete ui;
}

void AddSuccess::on_pushButton_clicked()
{
    this->close();
}
