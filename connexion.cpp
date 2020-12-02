#include "connexion.h"
#include <QtSql/QSqlDatabase>

connexion::connexion()
{

}
bool connexion::ouvrirconnection()
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

void connexion::fermerconnection(){

    db.close();
}
