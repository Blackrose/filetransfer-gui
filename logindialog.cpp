#include <QtGui>
#include "logindialog.h"

extern "C"{
#include "ftpclient.h"
}
bool flag=false;
loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
    ui->pwdlineEdit->setEchoMode(QLineEdit::Password);

}

loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::on_loginBtn_clicked()
{

    char *un = NULL;
    char *pw = NULL;
    char *port = NULL;
    char *addr = NULL;


    port = ui->portlineEdit->text().toLatin1().data();
    addr = ui->addrlineEdit->text().toLatin1().data();
    test(addr);
    connect_to_server(port, addr);

    un = ui->usrlineEdit->text().toLatin1().data();
    pw = ui->pwdlineEdit->text().toLatin1().data();
    if(login(un, pw) == 0){


        accept();
        flag = true;
        ui->usrlineEdit->clear();
        ui->pwdlineEdit->clear();
        this->close();

    }else{
        flag = false;
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);
        ui->usrlineEdit->clear();
        ui->pwdlineEdit->clear();

    }
}

int loginDialog::display()
{

    if(flag == true){
        return 1;
    }else{
        return 0;
    }
}
