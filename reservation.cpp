#include "reservation.h"

Reservation::Reservation()
{
id_client=0;
id_reservation=0;
nb_personne=0;
nomfilm="";
date_r.currentDate();

}

Reservation::Reservation(int id_client,int id_reservation,int nb_personne,QString nomfilm,QDate date_r){
   this->id_client = id_client;
    this->id_reservation = id_reservation;
    this->nb_personne = nb_personne;
    this->nomfilm=nomfilm;

    this->date_r=date_r;

}
int Reservation::get_id_client(){return id_client;}
int Reservation::get_id_reservation(){return id_reservation;}
int Reservation::get_nb_personne(){return nb_personne;}
QString Reservation::get_nomfilm(){return nomfilm;}

QDate Reservation::get_date_r(){return date_r;}

bool Reservation::ajouter_res(){
    QSqlQuery query;
    QString res=QString::number(id_client);
    query.prepare("INSERT INTO reservation(id_client,id_reservation,nb_personne,nom_film,date_res)"
                  "Values (:id_client,:id_reservation,:nb_personne,:nomfilm,:date_r)");

query.bindValue(":id_client",id_client);
query.bindValue(":id_reservation",id_reservation);
query.bindValue(":nb_personne",nb_personne);

query.bindValue(":nomfilm",nomfilm);
query.bindValue(":date_r",date_r);


return query.exec();
}
QSqlQueryModel * Reservation ::afficher_res(){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from reservation");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Client"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID Reservation"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NB Personne"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Nom Film"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));



    return model;

}
bool Reservation::supprimer_res(int id_client){
QSqlQuery query;
QString res = QString::number(id_client);
query.prepare("Delete from reservation where id_client=:id_client");
query.bindValue(":id_client",res);
return query.exec();

}

bool Reservation::update_res(int id_client){
    QSqlQuery query;
    query.prepare("Update reservation set nb_personne=:nb_personne,nom_film=:nomfilm,date_res=:date_r where id_client=:id_client");
    query.bindValue(":id_client",id_client);

    query.bindValue(":nb_personne",nb_personne);
    query.bindValue(":nomfilm",nomfilm);
query.bindValue(":date_r",date_r);
   return query.exec();

}

QSqlQueryModel *Reservation::trier_res(){


    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from reservation order by date_res asc,nb_personne asc,nom_film asc");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Client"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID Reservation"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NB Personne"));

    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Nom Film"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));

    return model;
}



QSqlQueryModel *Reservation::rechercher_res(QString f){
   QSqlQueryModel *model = new QSqlQueryModel();
model->setQuery("select * from reservation where id_client like '%'||'"+f+"'||'%' or id_reservation like '%'||'"+f+"'||'%' or date_res like '%'||'"+f+"'||'%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Client"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID Reservation"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("NB Personne"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("Nom Film"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date Reservation"));

   return model;


}
