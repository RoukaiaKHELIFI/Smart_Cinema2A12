#include "salle.h"

Salle::Salle()
{
    num_salle=0;
    nb_chaise=0;
    nb_baffles=0;
   nb_ecrans=0;
   dispo ="";

}
Salle::Salle(int num_salle,int nb_chaise,int nb_baffles,int nb_ecrans,QString dispo){
    this->num_salle=num_salle;
    this->nb_chaise=nb_baffles;
    this->nb_baffles=nb_chaise;
    this->nb_ecrans=nb_ecrans;
    this->dispo=dispo;
   }
int Salle::get_num_salle(){return num_salle;}
int Salle::get_nb_ecrans(){return nb_ecrans;}
int Salle::get_nb_baffles(){return nb_baffles;}
int Salle::get_nb_chaise(){return nb_chaise;}
QString Salle::get_dispo(){return dispo;}
bool Salle::ajouter(){
    QSqlQuery query;
    QString res=QString::number(num_salle);
    query.prepare("INSERT INTO salle(NumSalle,NbChaise,NbBaffles,NbEcrans)"
                  "Values (:nm_salle_ajout,:nb_chaise_ajout,:nb_baffles_ajout,:nb_ecrans_ajout)");

query.bindValue(":nm_salle_ajout",num_salle);
query.bindValue(":nb_chaise_ajout",nb_chaise);
query.bindValue(":nb_baffles_ajout",nb_baffles);
query.bindValue(":nb_ecrans_ajout",nb_ecrans);

return query.exec();
}
QSqlQueryModel * Salle ::afficher(){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from salle");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numero Salle"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB Chaise"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NB Baffles"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NB Ecrans"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Disponibilite"));
    return model;

}
bool Salle::supprimer(int num_salle){
QSqlQuery query;
QString res = QString::number(num_salle);
query.prepare("Delete from salle where numsalle=:num_salle");
query.bindValue(":num_salle",res);
return query.exec();

}
bool Salle::Update(int num_salle){

    QSqlQuery query ;
    query.prepare("update salle set numsalle= :num_salle ,nbchaise= :nb_chaise,nbbaffles= :nb_baffles  , nbecrans= :nb_ecrans, dispo=:dispo where numsalle= :num_salle");
    query.bindValue(":nb_chaise",nb_chaise);
    query.bindValue(":nb_baffles",nb_baffles);
    query.bindValue(":nb_ecrans",nb_ecrans);

     query.bindValue(":num_salle",num_salle);
query.bindValue(":dispo",dispo);


return query.exec();
}

QSqlQueryModel * Salle ::trier(){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from salle order by nbchaise asc,numsalle asc,dispo asc");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numero Salle"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB Chaise"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NB Baffles"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NB Ecrans"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Disponibilite"));
    return model;

}

QSqlQueryModel* Salle::rechercher(QString numsalle){
 QSqlQueryModel *model = new QSqlQueryModel();
 QSqlQuery query;
 query.bindValue(":numsalle",numsalle);

  model->setQuery("select * from salle where numsalle like '%'||'"+numsalle+"'||'%' or dispo like '%'||'"+numsalle+"'||'%' or nbchaise like '%'||'"+numsalle+"'||'%' ");
//model->setQuery("select * from salle where numsalle=?");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numero Salle"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB Chaise"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NB Baffles"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NB Ecrans"));

return model;
}

