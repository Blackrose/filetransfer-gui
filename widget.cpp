#include "widget.h"
#include "ui_widget.h"
extern "C"{
#include "ftpclient.h"
}


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    this->setLogin(false);
    ui->comboBox->setEnabled(false);
    ui->commandBtn->setEnabled(false);

}

Widget::~Widget()
{
    delete ui;
}

bool Widget::isLogin()
{
    return login;
}

void Widget::setLogin(bool value){
    login = value;
}

void Widget::setCommand(QString c)
{
    command = c;
}

QString Widget::getCommand()
{
    return command;
}
void Widget::on_connectBtn_clicked()
{
    QFont font("wenquanyi",12,QFont::Bold);

    ld.show();
    ld.setFont(font);
    if(ld.exec() == QDialog::Accepted && this->isLogin() == false){

        this->setLogin(true);
        ui->connectBtn->setText("Logout");
        ui->comboBox->setEnabled(true);
        ui->commandBtn->setEnabled(true);
        ui->connectBtn->setEnabled(false);
        this->setWindowState(Qt::WindowActive);
    }
#if 0
    else if(this->isLogin() == true){
        QString quit="quit";

            //command = quit.toLatin1().data();
            //handle_user_input(command);
            handle_user_input(quit.toLatin1().data());
        //this->setLogin(false);
    }
#endif
}

void Widget::on_comboBox_activated(QString cmd)
{
    this->setCommand(cmd);
}

void Widget::on_commandBtn_clicked()
{
    char *cmd = NULL;
    cmd = this->getCommand().toLatin1().data();

    test(cmd);
    handle_user_input(cmd);

    QString content;

    char *str;
    str = handle_server_ack();

    content = QString(QLatin1String(str)) ;
    ui->textBrowser->setText(content);
}


void Widget::on_quitBtn_clicked()
{
    QString quit="quit";
    if(this->isLogin() == true){
        command = quit.toLatin1().data();

        //handle_user_input(command);
        handle_user_input(quit.toLatin1().data());
        this->close();
    }else{
        this->close();
    }


}
