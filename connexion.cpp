#include "connexion.h"
#include <QtSql/QSqlDatabase>

connexion::connexion()
{

}
bool connexion::ouvrirconnection()
{
    bool test=false;
  db=QSqlDatabase::addDatabase("QODBC");
  db.setDatabaseName("SmartCinema2A12");

  db.setUserName("roukaia");
  db.setPassword("roukaia");

    if(db.open())
    test=true;

    return test;
}

void connexion::fermerconnection(){

    db.close();
}
