#include "connection.h"
#include<QSqlDatabase>
connection::connection()
{

}
bool connection::createConnect()
{
    bool test =false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("projet2a");
        db.setUserName("haroun");
        db.setPassword("haroun");

        if(db.open()) test = true;

        return test;
}
