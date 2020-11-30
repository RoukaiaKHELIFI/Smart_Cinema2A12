#include "authentification.h"
#include "ui_authentification.h"
#include "employe.h"
#include "mainwindow.h"
#include "QMessageBox"


authentification::authentification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authentification)
{
    ui->setupUi(this);
}

authentification::~authentification()
{
    delete ui;
}

void authentification::on_AjouterClient_2_clicked()
{
    employe c;
    c.setLogin(ui->lineEdit->text());
    c.setPassword(ui->lineEdit_2->text());

    if (c.existe())
    {


            this->close();

            MainWindow *w=new MainWindow(this);
            w->show();
    }
    else
    {
    QMessageBox::information(this,"non existe"," id n'existe pas");
    }

}
