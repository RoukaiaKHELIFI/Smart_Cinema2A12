#include "sqlconnection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
    QSqlDatabase db= QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet");
    db.setUserName("hamza");
    db.setPassword("hamza");

    if(db.open())
    {
    test=true;}

    return test;
}
