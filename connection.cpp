#include "connection.h"
#include <QtSql/QSqlDatabase>
connection::connection()
{

}

bool connection::createconnect()
{
    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("ProjetQT");

    db.setUserName("sinda");
    db.setPassword("esprit18");

    if(db.open())
    test=true;

    return test;
}
