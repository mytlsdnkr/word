#ifndef SHOWWORD_H
#define SHOWWORD_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class ShowWord;
}

class ShowWord : public QDialog
{
    Q_OBJECT

public:
    explicit ShowWord(QWidget *parent = nullptr);
    QString filename;




    ~ShowWord();

signals:
    void sendData(QString a);


private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);



    void on_pushButton_clicked();

private:
    Ui::ShowWord *ui;
};

#endif // SHOWWORD_H
