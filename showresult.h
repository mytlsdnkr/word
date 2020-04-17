#ifndef SHOWRESULT_H
#define SHOWRESULT_H

#include <QDialog>
#include "wordtest.h"
#include <vector>
#include <QTableWidget>
#include <QListWidgetItem>

using namespace std;

namespace Ui {
class showResult;
}

class showResult : public QDialog
{
    Q_OBJECT

public:
    explicit showResult(QWidget *parent = nullptr);
    void fillTable(test *a,vector<int> &order);


    ~showResult();

public slots:
     void getData(test *a,vector<int> &order);




private slots:
     void on_pushButton_clicked();

private:
    Ui::showResult *ui;
};

#endif // SHOWRESULT_H
