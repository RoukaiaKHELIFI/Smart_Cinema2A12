#ifndef CARTE_FIDELITE_H
#define CARTE_FIDELITE_H
//ici c'est la gestion de l'entité carte fidelite

#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QDate>


class carte_fidelite
{
private:
    int id_carte;
    int id_client;
    QDate date_creation_carte;
    int nb_point;
    int nb_film;

public:
    carte_fidelite()
    {
        this->id_carte=0;
        this->id_client=0;
        this->nb_point=0;
        this->nb_film=0;
    }

    carte_fidelite(int id_client,QDate date_creation_carte,int nb_point,int nb_film)
    {
        this->id_client=id_client;
        this->date_creation_carte=date_creation_carte;
        this->nb_point=nb_point;
        this->nb_film=nb_film;
     }
    carte_fidelite(int id_client ,int nb_point,int nb_film)
    {
        this->id_client=id_client;

        this->nb_point=nb_point;
        this->nb_film=nb_film;
     }


        int getId_carte()
        {
            return id_carte;
        }
        void setId_carte(int id_carte)
        {
            this->id_carte=id_carte;
        }

        int getId_client()
        {
            return id_client;
        }
        void setId_client(int id_client)
        {
            this->id_client=id_client;
        }
        QDate getDate_creation_carte()
        {
            return date_creation_carte;
        }
        void setDate_creation_carte(QDate date_creation_carte )
        {
            this->date_creation_carte=date_creation_carte;
        }
        int getNb_point()
        {
            return nb_point;
        }
        void setNb_point(int nb_point)
        {
            this->nb_point=nb_point;
        }

        int getNb_film()
        {
            return nb_film;
        }
        void setNb_film(int nb_film)
        {
            this->nb_film=nb_film;
        }
        //declaration des fonction
        bool ajouter_cartefidelite();
        QSqlQueryModel * afficher_cartefidelite();
        bool supprimer_cartefidelite();
        bool modifier_cartefidelite();
        bool existe_carte();
        int  recupere_nbfilm(int id);
        int  recupere_nbpoint(int id);



};

#endif // CARTE_FIDELITE_H
