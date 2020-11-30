#include "connexion.h"
#include <QtSql/QSqlDatabase>

Connexion::Connexion()
{

}
bool Connexion::ouvrirconnection()
{
    bool test=false;
  db=QSqlDatabase::addDatabase("QODBC");
  db.setDatabaseName("ProjetQT");

  db.setUserName("sinda");
  db.setPassword("esprit18");

    if(db.open())
    test=true;

    return test;
}

void Connexion::fermerconnection(){

    db.close();
}
