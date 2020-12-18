#include "connexion.h"
#include <QtSql/QSqlDatabase>

connexion::connexion()
{

}
bool connexion::ouvrirconnection()
{
    bool test=false;
  db=QSqlDatabase::addDatabase("QODBC");
  db.setDatabaseName("Salle_Reservation");

  db.setUserName("roukaia");
  db.setPassword("roukaia");

    if(db.open())
    test=true;

    return test;
}

void connexion::fermerconnection(){

    db.close();
}
