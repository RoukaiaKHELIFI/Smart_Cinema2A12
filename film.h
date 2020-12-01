#ifndef FILM_H
#define FILM_H
#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QDate>

class Film
{

private:
    int id_film;
    QString nom_film;
    QString realisateur;
    QString nationalite;
    QDate date_sortie;
    QDate disponibilite;
    QString categories;


public:
    Film(){
             this->id_film=0;
             this->nom_film="";
             this->realisateur="";
             this->nationalite="";
             this->categories="";


        }
    Film(int id_film,QString nom_film,QString realisateur,QString nationalite ,QDate date_sortie,QDate disponibilite,QString categories)
    {
             this->id_film=id_film;
             this->nom_film=nom_film;
             this->realisateur=realisateur;
             this->nationalite=nationalite;
             this->date_sortie=date_sortie;
             this->disponibilite=disponibilite;
             this->categories=categories;


        }



    int getid_film()
    {
        return id_film;
    }
    void setid_film(int id_film)
    {
        this->id_film=id_film;
    }

    QString getnom_film()
    {
        return nom_film;
    }
    void setnom_film(QString nom_film)
    {
        this->nom_film=nom_film;
    }

    QString getrealisateur()
    {
        return realisateur;
    }
    void setrealisateur(QString realisateur)
    {
        this->realisateur=realisateur;
    }

    QString getnationalite()
    {
        return nationalite;
    }
    void setnationalite(QString nationalite)
    {
        this->nationalite=nationalite;
    }

    QDate getdate_sortie()
    {
        return date_sortie;
    }
    void setdate_sortie(QDate date_sortie)
    {
        this->date_sortie=date_sortie;
    }
    QDate getdisponibilite()
    {
        return  disponibilite;
    }
    void setdisponibilite(QDate  disponibilite)
    {
        this->disponibilite= disponibilite;
    }

    QString getcategories()
    {
        return categories;
    }
    void setcategories(QString categories)
    {
        this->categories=categories;
    }

    bool ajouter_film();
    QSqlQueryModel * afficher_film();
    bool supprimer_film();
    bool modifier_film();



};
#endif // FILM_H
