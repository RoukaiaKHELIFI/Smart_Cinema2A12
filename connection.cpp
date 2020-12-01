#include "connection.h"
#include <QtSql/QSqlDatabase>
connection::connection()
{

}

bool connection::createconnect()
{
    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet");
    db.setUserName("meriem");
    db.setPassword("meriem");

    if(db.open())
    test=true;

    return test;
}
