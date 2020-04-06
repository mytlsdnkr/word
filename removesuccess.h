#ifndef REMOVESUCCESS_H
#define REMOVESUCCESS_H

#include <QDialog>

namespace Ui {
class removesuccess;
}

class removesuccess : public QDialog
{
    Q_OBJECT

public:
    explicit removesuccess(QWidget *parent = nullptr);
    ~removesuccess();

private slots:
    void on_pushButton_clicked();

private:
    Ui::removesuccess *ui;
};

#endif // REMOVESUCCESS_H
