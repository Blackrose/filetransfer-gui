#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#include "ui_logindialog.h"
#include <QDialog>

namespace Ui {
    class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = 0);
    ~loginDialog();
    int display();

private:
    Ui::loginDialog *ui;


private slots:
    void on_loginBtn_clicked();
};

#endif // LOGINDIALOG_H
