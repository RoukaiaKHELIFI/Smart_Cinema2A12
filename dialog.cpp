#include "dialog.h"
#include "ui_dialog.h"
#include "authentification.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{

    this->close();

    authentification *w=new authentification(this);
    w->show();
}

void Dialog::on_label_2_linkActivated(const QString &link)
{
    this->close();

    authentification *w=new authentification(this);
    w->show();
}
