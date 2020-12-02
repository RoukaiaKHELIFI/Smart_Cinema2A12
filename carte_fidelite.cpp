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

    model->setQuery("SELECT cf.* ,c.nom ,c.prenom FROM carte_fidelite cf INNER JOIN client c on cf.id_client = c.id_client");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CARTE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_CLIENT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_CREATION_CARTE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NB_POINT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("NB_FILM"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Prenom"));
    return model;
}

bool carte_fidelite::supprimer_cartefidelite()
{
    QSqlQuery query;
    query.prepare("DELETE FROM carte_fidelite WHERE id_carte=:id_carte");
    query.bindValue(":id_carte",this->getId_carte());

     return query.exec();
}
bool carte_fidelite::supprimer_cartefidelite_id_client()
{
    QSqlQuery query;
    query.prepare("DELETE FROM carte_fidelite WHERE id_client=:id_client");
    query.bindValue(":id_client",this->getId_client());

     return query.exec();
}


bool carte_fidelite::modifier_cartefidelite()
{

    this->setNb_film(this->recupere_nbfilm(this->getId_carte())+1);
    this->setNb_point(this->recupere_nbpoint(this->getId_carte())+30);


    QSqlQuery  query ;
     query.prepare("UPDATE carte_fidelite set  NB_POINT=:NB_POINT , NB_FILM=:NB_FILM WHERE ID_CARTE=:ID_CARTE");
     query.bindValue(":NB_POINT",this->getNb_point());
     query.bindValue(":NB_FILM",this->getNb_film());
     query.bindValue(":ID_CARTE",this->getId_carte());


    return query.exec();
}

bool carte_fidelite::modifier()
{
    QSqlQuery  query ;
     query.prepare("UPDATE carte_fidelite set  NB_POINT=:NB_POINT WHERE ID_CARTE=:ID_CARTE");
     query.bindValue(":NB_POINT",2002);
     query.bindValue(":ID_CARTE",31);


    return query.exec();

}

int  carte_fidelite::recupere_nbfilm(int id)
{
        QSqlQuery  *query  = new QSqlQuery();
        query->prepare("select NB_FILM from carte_fidelite where ID_CARTE=:ID_CARTE" );
        query->bindValue(":ID_CARTE",id);

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
        query->prepare("select NB_POINT from carte_fidelite where ID_CARTE=:ID_CARTE" );
        query->bindValue(":ID_CARTE",id);

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
        query->prepare("select * from carte_fidelite where ID_CLIENT=:ID_CLIENT" );
        query->bindValue(":ID_CLIENT",this->getId_client());
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





QSqlQueryModel * carte_fidelite::rechercher_existe(QString num){

       QSqlQueryModel *model=new QSqlQueryModel();

       model->setQuery(" select * from carte_fidelite c where ID_CARTE like '%'||'"+num+"'||'%' or ID_CLIENT like '%'||'"+num+"'||'%' or DATE_CREATION_CARTE like '%'||'"+num+"'||'%' or NB_POINT like '%'||'"+num+"'||'%'  or NB_FILM like '%'||'"+num+"'||'%'");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CARTE"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_CLIENT"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_CREATION_CARTE"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("NB_POINT"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("NB_FILM"));
       return model;

}
