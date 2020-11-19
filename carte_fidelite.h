#ifndef CARTE_FIDELITE_H
#define CARTE_FIDELITE_H
#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QDate>


class carte_fidelite
{
private:
    int id_carte;
    int cin_client;
    QDate date_creation_carte;
    int nb_point;
    int nb_film;

public:
    carte_fidelite()
    {
        this->id_carte=0;
        this->cin_client=0;
        this->nb_point=0;
        this->nb_film=0;
    }

    carte_fidelite(int id_carte,int cin_client,QDate date_creation_carte,int nb_point,int nb_film)
    {
        this->id_carte=id_carte;
        this->cin_client=cin_client;
        this->date_creation_carte=date_creation_carte;
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

        int getCin_client()
        {
            return cin_client;
        }
        void setCin_client(int cin_client)
        {
            this->cin_client=cin_client;
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


};

#endif // CARTE_FIDELITE_H
