#ifndef FCONNECTION_H
#define FCONNECTION_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


class dbutilistaeur
{
public:
    dbutilistaeur();
    bool utilisateurF1(QString utilistateurs);
    bool mdpF1(QString mdp);
};
#endif // FCONNECTION_H
