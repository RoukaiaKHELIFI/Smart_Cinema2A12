#include "ui1.h"
#include "ui_ui1.h"
#include "sqlconnection.h"
#include <QApplication>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

ui1::ui1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ui1)
{
    ui->setupUi(this);
}

ui1::~ui1()
{
    delete ui;
}
