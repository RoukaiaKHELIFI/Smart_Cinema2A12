#ifndef RESERVATION_H
#define RESERVATION_H
#include<QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QDate>
class Reservation
{
public:
    Reservation();

    Reservation(int,int,int,QString,QDate);
    int get_id_client();
    int get_id_reservation();
    int get_nb_personne();
    QString get_nomfilm();
QDate get_date_r();

bool ajouter_res();
QSqlQueryModel * afficher_res();
bool supprimer_res(int);
bool update_res(int);
QSqlQueryModel * trier_res();
QSqlQueryModel *rechercher_res(QString);
private:
int id_client,id_reservation,nb_personne;
QString nomfilm;
QDate date_r;

};

#endif // RESERVATION_H
