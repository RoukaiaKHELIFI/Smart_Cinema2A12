#ifndef CONNEXION_H
#define CONNEXION_H
#include <QtSql/QSqlDatabase>

class Connexion
{

private:
    QSqlDatabase db;
public:
    Connexion();

    bool ouvrirconnection();
    void fermerconnection();
};
#endif // CONNEXION_H
