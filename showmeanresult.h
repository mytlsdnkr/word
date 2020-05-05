#ifndef SHOWMEANRESULT_H
#define SHOWMEANRESULT_H

#include <QDialog>
#include <vector>
#include <meantest.h>
#include <QTableWidget>
#include <QListWidgetItem>
#include <QTableWidget>
#include <QListWidgetItem>
#include <QDebug>
#include <QColor>


namespace Ui {
class showmeanresult;
}

class showmeanresult : public QDialog
{
    Q_OBJECT

public:
    explicit showmeanresult(QWidget *parent = nullptr);
     void fillTable(meaningtest *a,vector<int> &order);
    ~showmeanresult();
public slots:
     void getData(meaningtest *a,vector<int> &order);
private slots:
    void on_pushButton_clicked();


private:
    Ui::showmeanresult *ui;
};

#endif // SHOWMEANRESULT_H
