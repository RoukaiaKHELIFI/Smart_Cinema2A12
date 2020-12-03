#ifndef SPONSORISATION_H
#define SPONSORISATION_H

#include <QSqlQueryModel>
#include<QString>
class Sponsorisation
{

    int num;
    QString type;
     QString nom;
    QString methode;

    public:
   Sponsorisation();
       Sponsorisation(int,QString,QString,QString);
       ~Sponsorisation();

       int getnum();
       void setnum(int);
       QString getnom();
       void setnom(QString);
       QString getmethode();
       void setmethode(QString);
       QString gettype();
       void settype(QString);
       QSqlQueryModel* recherche_nom(QString );
        bool verifierExnoms(QString );
       bool ajouter();
       bool supprimer(int);
       bool modifier(int,QString,QString,QString);
       QSqlQueryModel* afficher();
      Sponsorisation recherche_Id(int);

       QSqlQueryModel* trier();
       QSqlQueryModel* trier1();
       QSqlQueryModel* trier2();

       QSqlQueryModel * chercher_Sponsorisation_par_nom(QString m);
       QSqlQueryModel * chercher_Sponsorisation_par_capacite(QString m);

       QSqlQueryModel * chercher_sponsorisation_par_id(QString idd);

};

#endif // SPONSORISATION_H
