#ifndef SQLCONNECTION_H
#define SQLCONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
public:
    Connection();
    bool createconnect();
};

#endif // SQLCONNECTION_H
