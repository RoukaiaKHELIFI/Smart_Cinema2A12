#include "connexion.h"
#include <QtSql/QSqlDatabase>

connexion::connexion()
{

}
bool connexion::ouvrirconnection()
{
    bool test=false;
  db=QSqlDatabase::addDatabase("QODBC");
  db.setDatabaseName("base");

  db.setUserName("sinda");
  db.setPassword("sinda");

    if(db.open())
    test=true;

    return test;
}

void connexion::fermerconnection(){

    db.close();
}
