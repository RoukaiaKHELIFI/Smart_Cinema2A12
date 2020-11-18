#ifndef RESERVATION_H
#define RESERVATION_H
#include<QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
class Reservation
{
public:
    Reservation();

    Reservation(int,int,int,QString,QString);
    int get_id_client();
    int get_id_reservation();
    int get_nb_personne();
    QString get_nom_film();
    QString get_date_res();
bool ajouter_res();
QSqlQueryModel * afficher_res();
bool supprimer_res(int);
bool Update_res(int,int);
private:
int id_client,id_reservation,nb_personne;
QString nom_film,date_res;

};

#endif // RESERVATION_H
