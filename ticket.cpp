#include "ticket.h"
#include <QSqlQueryModel>
#include <QSqlQuery>

bool Ticket:: ajouter_ticket()
{
    QSqlQuery query;
    query.prepare("INSERT INTO TICKET VALUES (:ID_TICKET,:ID_FILM,:PRIX_TICKET,:NUMSALLE,:TYPE_PAIMENT,:NOM_FILM,:ID_CLIENT)");

    query.bindValue(":ID_TICKET",this->getid_ticket());
    query.bindValue(":ID_FILM",this->getid_film());
    query.bindValue(":PRIX_TICKET",this->getprix());
    query.bindValue(":NUMSALLE",this->getsalle());
    query.bindValue(":TYPE_PAIMENT",this->getType_paiment());
    query.bindValue(":NOM_FILM",this->getnom_film());
    query.bindValue(":ID_CLIENT",this->getid_client());

    return query.exec();
}

QSqlQueryModel * Ticket:: afficher_ticket()
{
    QSqlQueryModel *model=new QSqlQueryModel();


    model->setQuery(" select * from ticket ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID TICKET"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID FILM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX TICKET"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NUM SALLE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TYPE PAIMENT"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NOM FILM"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID CLIENT"));

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
    query.prepare("UPDATE ticket set ID_FILM=? , PRIX_TICKET=? , NUM_SALLE=? ,TYPE_PAIMENT=? , NOM_FILM=? , ID_CLIENT=?   WHERE ID_TICKET=?");


        query.addBindValue(this->getid_film());
        query.addBindValue(this->getprix());
        query.addBindValue(this->getsalle());
        query.addBindValue(this->getType_paiment());
        query.addBindValue(this->getnom_film());
        query.addBindValue(this->getid_client());
        query.addBindValue(this->getid_ticket());


    return query.exec();
}



QSqlQueryModel * Ticket::rechercher_ticket(QString num)
{

       QSqlQueryModel *model=new QSqlQueryModel();

       model->setQuery(" select * from ticket  where ID_TICKET like '%'||'"+num+"'||'%' or ID_FILM like '%'||'"+num+"'||'%' or PRIX_TICKET like '%'||'"+num+"'||'%' or NUM_SALLE like '%'||'"+num+"'||'%' or TYPE_PAIMENT like '%'||'"+num+"'||'%'   or NOM_FILM like '%'||'"+num+"'||'%'  or ID_CLIENT like '%'||'"+num+"'||'%' ");

       model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID TICKET"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID FILM"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX TICKET"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("NUM SALLE"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("TYPE PAIMENT"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("NOM FILM"));
       model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID CLIENT"));

       return model;

}
int Ticket::somme_ticket(int num_salle){
    QSqlQuery  query;
           query.prepare("select id_ticket from ticket where num_salle=:num_salle" );
query.bindValue(":num_salle",num_salle);
           query.exec();
           int count=0;
           while(query.next())
           {
            count++;
           }
   return count;

}
