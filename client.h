#ifndef CLIENT_H
#define CLIENT_H


#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QDate>
#include <QSqlQuery>
#include <QSystemTrayIcon>

#include <string>
using namespace std;
class client
{

private://declaration
    int id;
    int cin;
    QString nom;
    QString prenom;
    QDate date_naissance;
    int numTel;
    QString fonction;
    QString adresse;
    QDate date_creation;
    QString mail_client;
    QString genre;
    QString etat_civil;

public:
    //constructeur par defaut(initialisation)
    client(){
             this->cin=0;
             this->nom="";
             this->prenom="";
             this->numTel=0;
             this->fonction="";
             this->adresse="";
             this->mail_client="";
             this->genre="";
             this->etat_civil="";

        }
    //constructeur
    client(int cin,QString nom,QString prenom,QDate date_naissance,int numTel,QString fonction,QString adresse,QDate date_creation,QString mail_client, QString genre, QString etat_civil)
    {
             this->cin=cin;
             this->nom=nom;
             this->prenom=prenom;
             this->date_naissance=date_naissance;
             this->numTel=numTel;
             this->fonction=fonction;
             this->adresse=adresse;
             this->date_creation=date_creation;
             this->mail_client=mail_client;
             this->genre=genre;
             this->etat_civil=etat_civil;

        }
    int getID()
    {
        return id;
    }
    void setId(int id)
    {
        this->id=id;
    }


    int getCin()
    {
        return cin;
    }
    void setCin(int cin)
    {
        this->cin=cin;
    }
    QString getNom()
    {
        return nom;
    }
    void setNom(QString nom)
    {
        this->nom=nom;
    }
    QString getPrenom()
    {
        return prenom;
    }
    void setPrenom(QString prenom)
    {
        this->prenom=prenom;
    }
    QDate getDate_naissance()
    {
        return date_naissance;
    }
    void setDate_naissance(QDate date_naissance)
    {
        this->date_naissance=date_naissance;
    }

    int getNumTel()
    {
        return numTel;
    }
    void setNumTel(int numTel)
    {
        this->numTel=numTel;
    }
    QString getFonction()
    {
        return fonction;
    }
    void setFonction(QString fonction)
    {
        this->fonction=fonction;
    }
    QString getAdresse()
    {
        return adresse;
    }
    void setAdresse(QString adresse)
    {
        this->adresse=adresse;
    }
    QDate getDate_creation()
    {
        return date_creation;
    }
    void setDate_creation(QDate date_creation)
    {
        this->date_creation=date_creation;
    }
    QString getMail_client()
    {
        return mail_client;
    }
    void setMail_client(QString mail_client)
    {
        this->mail_client=mail_client;
    }
    QString getGenre()
    {
        return genre;
    }
    void setGenre(QString genre)
    {
        this->genre=genre;
    }
    QString getEtat_civil()
    {
        return etat_civil;
    }
    void setEtat_civil(QString etat_civil)
    {
        this->etat_civil=etat_civil;
    }

    //declaration des fonction
    bool ajouter_client();
    QSqlQueryModel * afficher_client();
    bool supprimer_client();
    bool modifier_client();
    bool existe_client_cin();
    bool existe_client_tel();
    QString controle_saisie();
    QSqlQueryModel * rechercher_existe(QString num);
    QSqlQueryModel * filtre(QString genre,QString fonction ,QString etat);
    void  notifier_ajouter();


};
#endif // CLIENT_H
