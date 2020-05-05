#ifndef MEANTEST_H
#define MEANTEST_H

#include <QDialog>
#include <QDir>
#include <QLabel>
#include <QLineEdit>
#include <vector>
using namespace std;
namespace Ui {
class meantest;
}

class meaningtest{
public:
    QString word;
    QString mean;
    QString input;
    int check;
    int answer;
};
class meantest : public QDialog
{
    Q_OBJECT

public:
    explicit meantest(QWidget *parent = nullptr);
    ~meantest();
    int numOftest;
    int current;
    QDir qdir;
    QStringList filelist;
    void getRand();
    void removeTrash();
    void getData();
    void setTest();
    void checkAnswer();
    meaningtest a[10000];
    int numOfWord;
    vector<int> order;

signals:
 void sendData(meaningtest *a, vector<int> &order);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::meantest *ui;
};

#endif // MEANTEST_H
