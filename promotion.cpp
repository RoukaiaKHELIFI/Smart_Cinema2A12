#include "promotion.h"
#include <QPrinter>
#include <QSqlQuery>
Promotion::Promotion(int id,QString nomfilm,QString catfilm,int prixfilm)
{
    this->id=id;
    this->nomfilm=nomfilm;
     this->catfilm=catfilm;
    this->prixfilm=prixfilm;
}
Promotion::~Promotion()
{

}
 Promotion::Promotion()
 {
     id=0;
     nomfilm="";
      catfilm="";
      prixfilm=0;
 }

QString Promotion::getnomfilm(){
    return nomfilm;
}
void Promotion::setnomfilm(QString nomfilm){
    this->nomfilm=nomfilm;
}

int Promotion::getId(){
    return id;
}
void Promotion::setId(int id){
    this->id=id;
}
QString Promotion::getcatfilm(){
    return catfilm;
}
void Promotion::setcatfilm(QString catfilm){
    this->catfilm=catfilm;
}
int Promotion::getprixfilm(){
    return prixfilm;
}
void Promotion::setprixfilm(int prixfilm){
    this->prixfilm=prixfilm;
}





bool Promotion::ajouter(){
    QSqlQuery query;
    query.prepare("insert into Promotion (id,nomfilm,catfilm,prixfilm) values (:id,:nomfilm,:catfilm,:prixfilm)");
    query.bindValue(":id",id);
    query.bindValue(":nomfilm",nomfilm);
    query.bindValue(":catfilm",catfilm);
    query.bindValue(":prixfilm",prixfilm);

    return query.exec();
}

bool Promotion::supprimer(int id){
    QSqlQuery q;
    q.prepare("select * from Promotion where id=:id");
    q.bindValue(":id",id);
    q.exec();
    int total=0; //mch mawjoud mayfasakhch
    while(q.next()){
        total++;
    }
    if(total==1){
        QSqlQuery query;
        query.prepare("delete from Promotion where id=:id");
        query.bindValue(":id",id);

        return query.exec();
    }
    else{
        return false;
    }


}

bool Promotion::modifier(int idc,QString nomfilm,QString catfilm,int prixfilm){
    QSqlQuery query;
    query.prepare("update Promotion set nomfilm=:nomfilm,catfilm=:catfilm,prixfilm=:prixfilm where id=:idc");
    query.bindValue(":id",id);

    query.bindValue(":nomfilm",nomfilm);
    query.bindValue(":catfilm",catfilm);
    query.bindValue(":prixfilm",prixfilm);
    query.bindValue(":idc",idc);

    return query.exec();
}

QSqlQueryModel * Promotion::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Promotion");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMFILM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATFILM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIXFILM"));

    return model;
}


QSqlQueryModel * Promotion::chercher_Promotion_par_nom(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Promotion WHERE NOMFILM like '"+m+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMFILM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATFILM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIXFILM"));
        return model ;
    }

 }


QSqlQueryModel * Promotion::chercher_Promotion_par_capacite(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Promotion WHERE nomfilm like '"+m+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMFILM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATFILM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIXFILM"));
        return model ;
    }

 }

QSqlQueryModel* Promotion:: trier()
{
 //order by extract (year from date_naissance)
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Promotion order by id DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMFILM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATFILM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIXFILM"));

    return model;
}

QSqlQueryModel* Promotion:: trier1()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Promotion order by id desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMFILM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATFILM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIXFILM"));

    return model;
}
QSqlQueryModel* Promotion::recherche_nom(QString nom){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Promotion WHERE NOMFILM like '"+nom+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMFILM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATFILM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIXFILM"));
    return model ;
}


 bool Promotion::verifierExnoms(QString nom){
 int i=0;

 QSqlQuery query;
 query.prepare("select * from Promotion where nomfilm= ? ");
query.addBindValue(nom);
 if(query.exec())
 {while(query.next())
     {i++;}}

 if(i!=0)
     return true ;
 else
     return false;}

