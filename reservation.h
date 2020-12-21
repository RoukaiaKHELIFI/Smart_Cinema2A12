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

    Reservation(int,QString,int,QString,QDate,QString);
    int get_id_client();
    QString get_id_reservation();
    int get_nb_personne();
    QString get_nomfilm();


QDate get_date_r();
QString get_mail_reservation();
bool ajouter_res();
QSqlQueryModel * afficher_res();
bool supprimer_res(int);
bool update_res(int);
QSqlQueryModel * trier_res();
QSqlQueryModel *rechercher_res(QString);
QSqlQueryModel * trier_res2();
private:
int id_client,nb_personne;
QString nomfilm,id_reservation,mail_reservation;
QDate date_r;

};

#endif // RESERVATION_H
