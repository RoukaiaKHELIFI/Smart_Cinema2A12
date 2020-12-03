#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "gestsponso.h"
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_tn_connecter_clicked()
{
    QString username = ui->username->text();
        QString password = ui->password->text();

        if(username ==  "haroun" && password == "haroun") {
            QMessageBox::information(this, "Login", "Username and password is correct");

            gestsponso *w=new gestsponso();
            w->show();
            this->hide();

        }
        else {
            QMessageBox::warning(this,"Login", "Username and password is not correct");
        }
}
