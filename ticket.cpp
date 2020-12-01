#include "ticket.h"
#include <QSqlQueryModel>
#include <QSqlQuery>

bool Ticket:: ajouter_ticket()
{
    QSqlQuery query;
    query.prepare("INSERT INTO TICKET VALUES (:ID_TICKET,:ID_FILM,:PRIX_TICKET,:NUM_SALLE,:TYPE_PAIMENT,:ID_CARTE)");

    query.bindValue(":ID_TICKET",this->getid_ticket());
    query.bindValue(":ID_FILM",this->getid_film());
    query.bindValue(":PRIX_TICKET",this->getprix());
    query.bindValue(":NUM_SALLE",this->getsalle());
    query.bindValue(":TYPE_PAIMENT",this->getType_paiment());
    query.bindValue(":ID_CARTE",this->getid_carte());

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
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ID_CARTE"));
    return model;
}

bool Ticket::supprimer_ticket()
{
    QSqlQuery query;
    query.prepare("DELETE FROM ticket WHERE ID_TICKET=?");

         query.addBindValue(this->getid_ticket());

     return query.exec();
}
