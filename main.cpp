#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include "connexion.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    bool test=c.ouvrirconnection();
    MainWindow w;
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
    w.show();
    return a.exec();
}
