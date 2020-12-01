#include "carte_fidelite.h"
#include <QSqlQuery>
#include <string>

bool carte_fidelite:: ajouter_cartefidelite( )
{
    QSqlQuery query;
    query.prepare("INSERT INTO carte_fidelite (ID_CARTE,ID_CLIENT,DATE_CREATION_CARTE,NB_POINT,NB_FILM)"
                   "VALUES (ID_CARTE.nextval,:ID_CLIENT,:DATE_CREATION_CARTE,:NB_POINT,:NB_FILM)");
    query.bindValue(":ID_CLIENT",this->getId_client());
    query.bindValue(":DATE_CREATION_CARTE",this->getDate_creation_carte());
    query.bindValue(":NB_POINT",this->getNb_point());
    query.bindValue(":NB_FILM",this->getNb_film());
    return query.exec();
}

QSqlQueryModel * carte_fidelite::afficher_cartefidelite()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery(" select * from carte_fidelite ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CARTE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_CLIENT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_CREATION_CARTE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NB_POINT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("NB_FILM"));
    return model;
}

bool carte_fidelite::supprimer_cartefidelite()
{
    QSqlQuery query;
    query.prepare("DELETE FROM carte_fidelite WHERE id_carte=?");

         query.addBindValue(this->getId_carte());

     return query.exec();
}


bool carte_fidelite::modifier_cartefidelite()
{

   // this->setNb_film(200);
    //this->setNb_point(300);

    QSqlQuery  query ;
    query.prepare("UPDATE carte_fidelite set  NB_POINT=5000 WHERE ID_CARTE=34");

   // query.addBindValue(1200);
   // query.addBindValue(1200);
    //query.addBindValue(34);
    return query.exec();

}



int  carte_fidelite::recupere_nbfilm(int id)
{
        QSqlQuery  *query  = new QSqlQuery();
        query->prepare("select NB_FILM from carte_fidelite where ID_CARTE=?" );
        query->addBindValue(id);
        query->exec();
        int nbfilm=0;
        while(query->next())//tchouf el ligne elli mbaedha
        {

         nbfilm = query->value(0).toString().toInt();
        }


        return nbfilm;

}
int  carte_fidelite::recupere_nbpoint(int id)
{
        QSqlQuery  *query  = new QSqlQuery();
        query->prepare("select NB_POINT from carte_fidelite where ID_CARTE=?" );
        query->addBindValue(id);
        query->exec();

        int nbfilm=0;
        while(query->next())//tchouf el ligne elli mbaedha
        {

         nbfilm = query->value(0).toString().toInt();
        }


        return nbfilm;

}

bool  carte_fidelite::existe_carte()
{
        QSqlQuery  *query  = new QSqlQuery();
        query->prepare("select * from carte_fidelite where ID_CLIENT=?" );
        query->addBindValue(this->getId_client());
        query->exec();
        int count=0;
        while(query->next())//tchouf el ligne elli mbaedha
        {
         count++;
        }


       if (count == 0 )
       {
          return false;
       }
       else  {return true;}

}


