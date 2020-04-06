#ifndef SHOWTABLE_H
#define SHOWTABLE_H

#include <QDialog>
#include <QTableWidget>


namespace Ui {
class ShowTable;
}

class ShowTable : public QDialog
{

    Q_OBJECT

public:
    explicit ShowTable(QWidget *parent = nullptr);
     void onFileRead(QString filename, int remove);
     void addList(QStringList line,int row);
     void setData();
     void setRemoveWord(QString data);
     void addData(int);
     void deleteData(int);



    ~ShowTable();
private slots:
     void getData(QString filename);

     void on_pushButton_clicked();

     void on_tableWidget_itemClicked(QTableWidgetItem *item);

     void on_pushButton_2_clicked();

private:
    Ui::ShowTable *ui;
    QString filename;
    QList<int> removeNum;
    QString removeWord;



};

#endif // SHOWTABLE_H
