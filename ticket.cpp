#include "ticket.h"
#include <QSqlQueryModel>
#include <QSqlQuery>

bool Ticket:: ajouter_ticket()
{
    QSqlQuery query;
   // query.prepare("INSERT INTO FILM (ID_TICKET,ID_FILM,PRIX_TICKET,NUM_SALLE)"
     //              "VALUES (:ID_TICKET,:ID_FILM,:PRIX_TICKET,:NUM_SALLE)");

    query.prepare("INSERT INTO TICKET VALUES (:ID_TICKET,:ID_FILM,:PRIX_TICKET,:NUM_SALLE,:TYPE_PAIMENT)");


    query.bindValue(":ID_TICKET",this->getid_ticket());
    query.bindValue(":ID_FILM",this->getid_film());
    query.bindValue(":PRIX_TICKET",this->getprix());
    query.bindValue(":NUM_SALLE",this->getsalle());
    query.bindValue(":TYPE_PAIMENT",this->getType_paiment());


    return query.exec();
}

QSqlQueryModel * Ticket:: afficher_ticket()
{
    QSqlQueryModel *model=new QSqlQueryModel();


    model->setQuery(" select * from ticket ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_TICKET"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_FILM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_TICKET"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NUM_SALLE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TYPE_PAIMENT"));

    return model;
}

bool Ticket::supprimer_ticket()
{
    QSqlQuery query;
    query.prepare("DELETE FROM ticket WHERE ID_TICKET=?");

         query.addBindValue(this->getid_ticket());

     return query.exec();
}



bool Ticket::modifier_ticket()
{
    QSqlQuery  query ;
    query.prepare("UPDATE ticket set ID_FILM=? , PRIX_TICKET=? , NUM_SALLE=? ,TYPE_PAIMENT=? WHERE ID_TICKET=?");


        query.addBindValue(this->getid_film());
        query.addBindValue(this->getprix());
        query.addBindValue(this->getsalle());
        query.addBindValue(this->getType_paiment());
        query.addBindValue(this->getid_ticket());

    return query.exec();
}


