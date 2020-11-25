#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "sqlconnection.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
    QString dbtest;


    bool test=c.createconnect();
    if(test)
    {
    w.show();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is closed"),QObject::tr("connection failed.\n" "click to exit"),QMessageBox::Cancel);
    }

    return a.exec();

}
