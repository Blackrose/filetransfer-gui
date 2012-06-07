#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "logindialog.h"

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


private:
    Ui::Widget *ui;
    loginDialog ld;
    bool login;
    QString command;

    bool isLogin();
    void setLogin(bool value);
    void setCommand(QString c);
    QString getCommand();

private slots:
    void on_quitBtn_clicked();
    void on_commandBtn_clicked();
    void on_comboBox_activated(QString cmd);
    void on_connectBtn_clicked();

};

#endif // WIDGET_H
