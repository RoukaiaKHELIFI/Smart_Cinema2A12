#ifndef TICKET_H
#define TICKET_H
#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QDate>

class Ticket
{

private:
    int id_ticket;
    QString id_film;
   int prix;
    QString salle;
    QString Type_paiment;
    QString nom_film;
    int id_client;




public:
    Ticket(){
             this->id_ticket=0;
             this->id_film="";
             this->prix=0;
             this->salle="";
             this->Type_paiment="";
             this->nom_film="";
             this->id_client=0;

        }
    Ticket(int id_ticket,QString id_film,int prix,QString salle,QString Type_paiment , QString nom_film ,  int id_client)
    {
             this->id_ticket=id_ticket;
             this->id_film=id_film;
             this->prix=prix;
             this->salle=salle;
             this->Type_paiment=Type_paiment;
             this->nom_film=nom_film;
             this->id_client=id_client;

        }



    int getid_ticket()
    {
        return id_ticket;
    }
    void setid_ticket(int id_ticket)
    {
        this->id_ticket=id_ticket;
    }

    QString getid_film()
    {
        return id_film;
    }
    void setid_film(QString id_film)
    {
        this->id_film=id_film;
    }

    int getprix()
    {
        return prix;
    }
    void setprix(int prix)
    {
        this->prix=prix;
    }

    QString getsalle()
    {
        return salle;
    }
    void setsalle(QString salle)
    {
        this->salle=salle;
    }

    QString getType_paiment()
    {
        return Type_paiment;
    }
    void settype_paiment(QString Type_paiment)
    {
        this->Type_paiment=Type_paiment;
    }

    QString getnom_film()
    {
        return nom_film;
    }
    void setnom_film(QString nom_film)
    {
        this->nom_film=nom_film;
    }
    int getid_client()
    {
        return id_client;
    }
    void setid_client(int id_client)
    {
        this->id_client=id_client;
    }
    int somme_ticket(int);

    bool ajouter_ticket();
    QSqlQueryModel * afficher_ticket();
    bool supprimer_ticket();
    bool modifier_ticket();
    QSqlQueryModel * rechercher_ticket(QString num);


};


#endif // TICKET_H

