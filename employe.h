#ifndef EMPLOYE_H
#define EMPLOYE_H


#include "QString"

class employe
{

public:
    int id;
    QString login;
    QString password;



    //constructeur par defaut(initialisation)
    employe(){
             this->id=0;
             this->login="";
             this->password="";
     }
    //constructeur
    employe(int id,QString login,QString password)
    {
             this->id=id;
             this->login=login;
             this->password=password;


        }
    int getID()
    {
        return id;
    }
    void setId(int id)
    {
        this->id=id;
    }


    QString getLogin()
    {
        return login;
    }
    void setLogin(QString login)
    {
        this->login=login;
    }

    QString getPassword()
    {
        return password;
    }
    void setPassword(QString password)
    {
        this->password=password;
    }

    bool existe();
};
#endif // EMPLOYE_H
