#ifndef ADDWORD_H
#define ADDWORD_H

#include <QDialog>

namespace Ui {
class AddWord;
}

class AddWord : public QDialog
{
    Q_OBJECT

public:
    explicit AddWord(QWidget *parent = nullptr);
    ~AddWord();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::AddWord *ui;
};

#endif // ADDWORD_H
