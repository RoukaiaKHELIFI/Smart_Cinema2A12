#include "fconnection.h"
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>

dbutilistaeur::dbutilistaeur(){

}

bool dbutilistaeur::utilisateurF1(QString utilisateurs){

    bool trouver=false;

    QSqlQuery query;
    query.exec("SELECT NOMP_GR FROM GR_IDENT WHERE NOMP_GR='"+utilisateurs+"'");
    while(query.next())
    {
        trouver=true;
    }
    return trouver;
}

bool dbutilistaeur::mdpF1(QString mdp){

    bool trouver=false;

    QSqlQuery query;
    query.exec("SELECT NOMP_GR FROM GR_IDENT WHERE PASS_GR='"+mdp+"'");
    while(query.next())
    {
        trouver=true;
    }
    return trouver;
}



