#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include "connexion.h"
#include "dialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /* MainWindow w;*/


    Connexion c;
    bool test=c.ouvrirconnection();
      Dialog w;
   // MainWindow w;
      w.show();
    if(test){

        w.show();
                QMessageBox::information(nullptr,QObject::tr("database is open"),
                                         QObject::tr("connection successful.\n""Click cancel to exit"),QMessageBox::Cancel);

            }
            else
            {
                QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                                         QObject::tr("connection failed.\n""Click cancel to exit"),QMessageBox::Cancel);

    }
    return a.exec();
}
