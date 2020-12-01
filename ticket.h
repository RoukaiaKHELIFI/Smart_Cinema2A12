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
    int id_carte;
    QString id_film;
    QString prix;
    QString salle;
    QString Type_paiment;


public:
    Ticket(){
             this->id_ticket=0;
             this->id_film="";
             this->prix="";
             this->salle="";
             this->Type_paiment="";


        }
    Ticket(int id_ticket,QString id_film,QString prix,QString salle,QString Type_paiment , int id_carte)
    {
             this->id_ticket=id_ticket;
             this->id_carte=id_carte;
             this->id_film=id_film;
             this->prix=prix;
             this->salle=salle;
             this->Type_paiment=Type_paiment;

        }



    int getid_ticket()
    {
        return id_ticket;
    }
    void setid_ticket(int id_ticket)
    {
        this->id_ticket=id_ticket;
    }
    int getid_carte()
    {
        return id_carte;
    }
    void setid_carte(int id_carte)
    {
        this->id_carte=id_carte;
    }

    QString getid_film()
    {
        return id_film;
    }
    void setnom_film(QString id_film)
    {
        this->id_film=id_film;
    }

    QString getprix()
    {
        return prix;
    }
    void setprix(QString prix)
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



    bool ajouter_ticket();
    QSqlQueryModel * afficher_ticket();
    bool supprimer_ticket();


};

#endif // TICKET_H
