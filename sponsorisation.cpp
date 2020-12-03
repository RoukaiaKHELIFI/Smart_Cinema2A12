#include "sponsorisation.h"

#include <QPrinter>
#include <QSqlQuery>
Sponsorisation::Sponsorisation(int num,QString nom,QString type,QString methode)
{
    this->num=num;
    this->nom=nom;
     this->type=type;
    this->methode=methode;
}
Sponsorisation::~Sponsorisation()
{

}
 Sponsorisation::Sponsorisation()
 {
     num=0;
     nom="";
      type="";
      methode="";
 }

QString Sponsorisation::getnom(){
    return nom;
}
void Sponsorisation::setnom(QString nom){
    this->nom=nom;
}

int Sponsorisation::getnum(){
    return num;
}
void Sponsorisation::setnum(int num){
    this->num=num;
}
QString Sponsorisation::gettype(){
    return type;
}
void Sponsorisation::settype(QString type){
    this->type=type;
}
QString Sponsorisation::getmethode(){
    return methode;
}
void Sponsorisation::setmethode(QString methode){
    this->methode=methode;
}





bool Sponsorisation::ajouter(){
    QSqlQuery query;
    query.prepare("insert into Sponsorisation (num,nom,type,methode) values (:num,:nom,:type,:methode)");
    query.bindValue(":num",num);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);
    query.bindValue(":methode",methode);

    return query.exec();
}

bool Sponsorisation::supprimer(int num){
    QSqlQuery q;
    q.prepare("select * from Sponsorisation where num=:num");
    q.bindValue(":num",num);
    q.exec();
    int total=0; //mch mawjoud mayfasakhch
    while(q.next()){
        total++;
    }
    if(total==1){
        QSqlQuery query;
        query.prepare("delete from Sponsorisation where num=:num");
        query.bindValue(":id",num);

        return query.exec();
    }
    else{
        return false;
    }


}

bool Sponsorisation::modifier(int idc,QString nom,QString type,QString methode){
    QSqlQuery query;
    query.prepare("update Sponsorisation set nom=:nom,type=:type,methode=:methode where num=:idc");
    query.bindValue(":num",num);

    query.bindValue(":nom",nom);
    query.bindValue(":type",type);
    query.bindValue(":methode",methode);
    query.bindValue(":idc",idc);

    return query.exec();
}

QSqlQueryModel * Sponsorisation::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Sponsorisation");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("METHODE"));

    return model;
}


QSqlQueryModel * Sponsorisation::chercher_Sponsorisation_par_nom(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Sponsorisation WHERE NOM like '"+m+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("METHODE"));
        return model ;
    }

 }


QSqlQueryModel * Sponsorisation::chercher_Sponsorisation_par_capacite(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Sponsorisation WHERE nom like '"+m+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("METHODE"));
        return model ;
    }

 }

QSqlQueryModel* Sponsorisation:: trier()
{
 //order by extract (year from date_naissance)
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Sponsorisation order by nom ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("METHODE"));

    return model;
}

QSqlQueryModel* Sponsorisation:: trier1()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Sponsorisation order by num desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("METHODE"));

    return model;
}
QSqlQueryModel* Sponsorisation::recherche_nom(QString nom){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Sponsorisation WHERE NOM like '"+nom+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("METHODE"));
    return model ;
}


 bool Sponsorisation::verifierExnoms(QString nom){
 int i=0;

 QSqlQuery query;
 query.prepare("select * from Sponsorisation where nom= ? ");
query.addBindValue(nom);
 if(query.exec())
 {while(query.next())
     {i++;}}

 if(i!=0)
     return true ;
 else
     return false;}


