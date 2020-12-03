#ifndef PROMOTION_H
#define PROMOTION_H
#include<QString>
#include<QSqlQueryModel>

class Promotion
{

    int id;
    QString nomfilm;
     QString catfilm;
    int prixfilm;

    public:
    Promotion();
       Promotion(int,QString,QString,int);
       ~Promotion();

       int getId();
       void setId(int);
       QString getnomfilm();
       void setnomfilm(QString);
       QString getcatfilm();
       void setcatfilm(QString);
       int getprixfilm();
       void setprixfilm(int);
     QSqlQueryModel* recherche_nom(QString );
      bool verifierExnoms(QString );
       bool ajouter();
       bool supprimer(int);
       bool modifier(int,QString,QString,int);
       QSqlQueryModel* afficher();
       Promotion recherche_Id(int);

       QSqlQueryModel* trier();
       QSqlQueryModel* trier1();
       QSqlQueryModel* trier2();

       QSqlQueryModel * chercher_Promotion_par_nom(QString m);
       QSqlQueryModel * chercher_Promotion_par_capacite(QString m);

       QSqlQueryModel * chercher_sponsorisation_par_id(QString idd);
        QSqlQueryModel* Filter(int);
};

#endif // PROMOTION_H
