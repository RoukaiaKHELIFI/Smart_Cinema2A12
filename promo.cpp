#include "sponsorisation.h"
#include <QSqlQuery>

sponsorisation::sponsorisation(int id,QString nomfilm,QString catfilm,int prixfilm)
{
    this->id=id;
    this->nomfilm=nomfilm;
     this->catfilm=catfilm;
    this->prixfilm=prixfilm;
}
sponsorisation::~sponsorisation()
{

}


QString sponsorisation::getnomfilm(){
    return nomfilm;
}
void sponsorisation::setnomfilm(QString nomfilm){
    this->nomfilm=nomfilm;
}

int sponsorisation::getId(){
    return id;
}
void sponsorisation::setId(int id){
    this->id=id;
}
QString sponsorisation::getcatfilm(){
    return catfilm;
}
void sponsorisation::setcatfilm(QString catfilm){
    this->catfilm=catfilm;
}
int sponsorisation::getprixfilm(){
    return prixfilm;
}
void sponsorisation::setprixfilm(int prixfilm){
    this->prixfilm=prixfilm;
}





bool sponsorisation::ajouter(){
    QSqlQuery query;
    query.prepare("insert into sponsorisation (id,nomfilm,catfilm,prixfilm) values (:id,:nomfilm,:catfilm,:prixfilm)");
    query.bindValue(":id",id);
    query.bindValue(":nomfilm",nomfilm);
    query.bindValue(":catfilm",catfilm);
    query.bindValue(":prixfilm",prixfilm);

    return query.exec();
}

bool sponsorisation::supprimer(int id){
    QSqlQuery q;
    q.prepare("select * from sponsorisation where id=:id");
    q.bindValue(":id",id);
    q.exec();
    int total=0; //mch mawjoud mayfasakhch
    while(q.next()){
        total++;
    }
    if(total==1){
        QSqlQuery query;
        query.prepare("delete from sponsorisation where id=:id");
        query.bindValue(":id",id);

        return query.exec();
    }
    else{
        return false;
    }


}

bool sponsorisation::modifier(int idc,QString nomfilm,QString catfilm,int prixfilm){
    QSqlQuery query;
    query.prepare("update sponsorisation set nomfilm=:nomfilm,catfilm=:catfilm,prixfilm=:prixfilm where id=:idc");
    query.bindValue(":id",id);

    query.bindValue(":nomfilm",nomfilm);
    query.bindValue(":catfilm",catfilm);
    query.bindValue(":prixfilm",prixfilm);
    query.bindValue(":idc",idc);

    return query.exec();
}

QSqlQueryModel * sponsorisation::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from sponsorisation");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMFILM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATFILM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIXFILM"));

    return model;
}


QSqlQueryModel * sponsorisation::chercher_sponsorisation_par_nom(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM sponsorisation WHERE NOMFILM like '"+m+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMFILM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATFILM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIXFILM"));
        return model ;
    }

 }

QSqlQueryModel *sponsorisation::chercher_sponsorisation_par_id(QString idd)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM sponsorisation WHERE ID like '"+idd+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMFILM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATFILM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIXFILM"));
        return model ;
    }
}
QSqlQueryModel * sponsorisation::chercher_sponsorisation_par_capacite(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM sponsorisation WHERE nomfilm like '"+m+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMFILM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATFILM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIXFILM"));
        return model ;
    }

 }

QSqlQueryModel* sponsorisation:: trier()
{
 //order by extract (year from date_naissance)
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from sponsorisation order by id DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMFILM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATFILM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIXFILM"));

    return model;
}

QSqlQueryModel* sponsorisation:: trier1()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from sponsorisation order by nomfilm ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMFILM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATFILM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIXFILM"));

    return model;
}

