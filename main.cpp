#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  //MainWindow w;
  //  connection c;
    MainWindow w;
   /* bool test=c.createconnect();
    if(test)
    {

        QMessageBox::information(nullptr,QObject::tr("database is open"),
                                 QObject::tr("connection successful.\n""Click cancel to exit"),QMessageBox::Cancel);

         w.show();

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                                 QObject::tr("connection failed.\n""Click cancel to exit"),QMessageBox::Cancel);
    }*/

    w.show();
    return a.exec();
}
