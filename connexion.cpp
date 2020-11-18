#include "connexion.h"

Connexion::Connexion()
{

}
bool Connexion::ouvrirconnection()
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

void Connexion::fermerconnection(){

    db.close();
}
