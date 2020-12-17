#include "film.h"
#include <QSqlQuery>
#include <string>


bool Film:: ajouter_film( )
{
    QSqlQuery query;
    query.prepare("INSERT INTO FILM (ID_FILM,NOM_FILM,REALISATEUR,NATIONALITE,DATE_SORTIE,DISPONIBILITE,CATEGORIES)"
                   "VALUES (:ID_FILM,:NOM_FILM,:REALISATEUR,:NATIONALITE,:DATE_SORTIE,:DISPONIBILITE,:CATEGORIES)");

    query.bindValue(":ID_FILM",this->getid_film());
    query.bindValue(":NOM_FILM",this->getnom_film());
    query.bindValue(":REALISATEUR",this->getrealisateur());
    query.bindValue(":NATIONALITE",this->getnationalite());
    query.bindValue(":DATE_SORTIE",this->getdate_sortie());
    query.bindValue(":DISPONIBILITE",this->getdisponibilite());
    query.bindValue(":CATEGORIES",this->getcategories());

    return query.exec();
}

QSqlQueryModel * Film::afficher_film()
{
    QSqlQueryModel *model=new QSqlQueryModel();


    model->setQuery(" select * from film ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_FILM"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_FILM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("REALISATEUR"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NATIONALITE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_SORTIE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("DISPONIBILITE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("CATEGORIES"));
    return model;
}

bool Film::supprimer_film()
{
    QSqlQuery query;
    query.prepare("DELETE FROM film WHERE ID_FILM=?");

         query.addBindValue(this->getid_film());

     return query.exec();
}

bool Film::modifier_film()
{
    QSqlQuery  query ;

    query.prepare("UPDATE film set NOM_FILM=? , REALISATEUR=? , NATIONALITE=? ,DATE_SORTIE=? ,DISPONIBILITE=?,CATEGORIES=? WHERE ID_FILM=?");


    query.addBindValue(this->getnom_film());
    query.addBindValue(this->getrealisateur());
    query.addBindValue(this->getnationalite());
    query.addBindValue(this->getdate_sortie());
    query.addBindValue(this->getdisponibilite());
    query.addBindValue(this->getcategories());
    query.addBindValue(this->getid_film());
    return query.exec();
}

QSqlQueryModel *Film::trier_film(){

    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("select * from film order by nom_film ");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_FILM"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_FILM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("REALISATEUR"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NATIONALITE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_SORTIE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("DISPONIBILITE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("CATEGORIES"));

    return model;
}


QSqlQueryModel * Film::rechercher_film(QString num){

       QSqlQueryModel *model=new QSqlQueryModel();

       model->setQuery(" select * from film  where ID_FILM like '%'||'"+num+"'||'%' or NOM_FILM like '%'||'"+num+"'||'%' or REALISATEUR like '%'||'"+num+"'||'%' or NATIONALITE like '%'||'"+num+"'||'%' or CATEGORIES like '%'||'"+num+"'||'%'");

       model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_FILM"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_FILM"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("REALISATEUR"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("NATIONALITE"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_SORTIE"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("DISPONIBILITE"));
       model->setHeaderData(6,Qt::Horizontal,QObject::tr("CATEGORIES"));

       return model;

}



QSqlQueryModel *Film::trier_film_r(){

    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("select * from film order by realisateur ");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_FILM"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_FILM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("REALISATEUR"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NATIONALITE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_SORTIE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("DISPONIBILITE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("CATEGORIES"));

    return model;
}


QSqlQueryModel *Film::trier_film_n(){

    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("select * from film order by nationalite ");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_FILM"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_FILM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("REALISATEUR"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NATIONALITE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_SORTIE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("DISPONIBILITE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("CATEGORIES"));

    return model;
}

QSqlQueryModel *Film::trier_film_c(){

    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("select * from film order by categories ");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_FILM"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_FILM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("REALISATEUR"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NATIONALITE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_SORTIE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("DISPONIBILITE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("CATEGORIES"));

    return model;
}


