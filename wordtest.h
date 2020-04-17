#ifndef WORDTEST_H
#define WORDTEST_H

#include <QDialog>
#include <QDir>
#include <QLabel>
#include <QLineEdit>
#include <vector>
using namespace std;


namespace Ui {
class wordTest;
}

class test{
public:
    QString word;
    QString mean;
    QString input;
    int check;
    int answer;
};


class wordTest : public QDialog
{
    Q_OBJECT

public:
    explicit wordTest(QWidget *parent = nullptr);
    ~wordTest();
    int numOftest;
    int current;
    QDir qdir;
    QStringList filelist;
    void getRand();
    void removeTrash();
    void getData();
    void setTest();
    void checkAnswer();
    test a[10000];
    int numOfWord;
    vector<int> order;




    signals:
     void sendData(test *a, vector<int> &order);

private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::wordTest *ui;
};

#endif // WORDTEST_H
