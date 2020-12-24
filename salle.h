#ifndef SALLE_H
#define SALLE_H
#include<QSqlQuery>
#include <QSqlQueryModel>
#include<QString>
#include "ticket.h"
class Salle
{
public:
    Salle();
    Salle(int,int,int,int,QString);
    int get_num_salle();
    int get_nb_chaise();
    int get_nb_baffles();
    int get_nb_ecrans();
    QString get_dispo();
bool ajouter();
QSqlQueryModel * afficher();
bool supprimer(int);
bool Update(int);
QString disponibilite();

QSqlQueryModel * trier();
QSqlQueryModel* rechercher(QString num_salle);
private:
int num_salle,nb_chaise,nb_baffles,nb_ecrans;
QString dispo;
};

#endif // SALLE_H
